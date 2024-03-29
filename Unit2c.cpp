//---------------------------------------------------------------------------
//
#include <vcl.h>
#include "stdio.h"
//
#include <Clipbrd.hpp>
#include <IniFiles.hpp>
#include <SysUtils.hpp> // ��� DeleteFile
#include <io.h> // ��� chmod
#include <dos.h> // FA_RDONLY + sleep
#include <share.h> // SH_COMPAT
//
#pragma hdrstop
//
#include "Unit1c.h" // ����� ��� ������ � F1 (�������� ���� ������ � Lua)
#include "Unit2c.h"
//
// ����������� �������� ��� ���� ���������
#define _32    32
#define _64    64
#define _128   128
#define _256   256
#define _512   512
#define _1024  1024
#define _2048  2048
#define _4096  4096
#define _8192  8192
#define _16384 16384
#define _32768 32768
//
//------------------------------------------------------------------------------
//
#pragma package(smart_init)
#pragma resource "*.dfm"
TF2 *F2;
//
#define REAL float // ��� ������������ ����� ��� ����������� (32 ���)
#define INT  signed long int // ��� ����� (32 ���)
//
#define ULI unsigned long int // ������� ����� ��� ����� (32 ���)
#define UI  unsigned int // ����� ��� ����� (32 ���)
//
#define _minINT -1073741824 // ������� -(2^30) � �������� 2^30 int_32
#define _maxINT  1073741824
//
////////////////////////////////////////////////////////////////////////////////
extern const int minW_F2=850, minH_F2=600; // ����������� ������ �������� ����� F2
extern char FileNameEdges[]; // ��� ����� ��� (���������� � Unit1.cpp)
extern void __fastcall PutParamsAboutSelectOp( INT Op ); // ���������� � Unit1.cpp
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
__fastcall TF2::TF2(TComponent* Owner): TForm(Owner)
{
 F2->Position = poDefault; // ����� �� ������ ����������������...
/*
 SetWindowLong(Handle, GWL_STYLE, // ������� ���� ��� ���������
               GetWindowLong( Handle, GWL_STYLE ) && (! WS_CAPTION));
 ClientHeight=Height;
*/
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF2::M1_PM_ClearAll(TObject *Sender)
{ // �������� M1
 M1->Clear(); // ��������� �������� M1 (TMemo)
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF2::M1_PM_CopyAll(TObject *Sender)
{ // ���������� � Clipboard �� �� M1 (TMemo)
// Clipboard->AsText = M1->Text.
 M1->SelectAll(); // �������� ���� ����� � M1
 M1->CopyToClipboard(); // ���������� �� �� M1 � Clipboard
 M1->SelLength = 0; // ����� ���������
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF2::M1_PM_CopyToNotepad(TObject *Sender)
{ // ���������� � NotePad �� �� M1 (TMemo)
 char tmpFileName[_256];
 strcpy( tmpFileName, ChangeFileExt( FileNameEdges, ".txt" ).c_str()); // ��� ������� + "txt"
 M1->Lines->SaveToFile( tmpFileName ); // ������ ��� ������ �� M1 � ���� tmpFileName
 ShellExecute( Handle, "open", tmpFileName, NULL, NULL, SW_RESTORE ); // ������� ���� tmpFileName
//
 sleep( 1 ); // #include <dos.h>
//
 DeleteFile( tmpFileName ); // ���������� (���������) ����
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF2::CopyPictureToClipboard(TObject *Sender)
{ // �������� �������� � Clipboard
//
 try
 {
  Clipboard()->Assign(IM1->Picture); // ���������� ��� � Clipboard
// IM1->Picture->SaveToFile("pict_01.bmp"); // ��������� � ����
  MessageBeep(MB_OK); // it's OK...
 }
 catch(...)
 {
  MessageBeep(MB_ICONEXCLAMATION); // it's no OK...
 }
//
} //---- ����� CopyPictureToClipboard ------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF2::OnResize_F2(TObject *Sender)
{ // ���������� ��� ��������� �������� F2
 int W = F2->Width, // ����� ������� ������ �������� ���� ���������
     H = F2->Height;
// MessageBeep(MB_OK);
//
 if( W < minW_F2 ) // ���� �� ����� ���� ����� minW_F2 * minH_F2
  W = minW_F2;
//
 if( H < minH_F2 ) // ...
  H = minH_F2;
//
// ������ ����� ���������� ������� �������� ���� � ���� �������
//
 F2->Width  = W; // ����� ������ ���� ���������
 F2->Height = H;
//
// ���������� ���������� ���� F2
//
 PN1->Left   = F2->Width  - PN1->Width - 20 ; // ������-��������� ������������ ������
 PN1->Height = F2->Height - PN1->Top   - 102 ;
//
 M1->Width  = PN1->Left - M1->Left - 3; // ���� ���������� ������ (����� ������)
 M1->Height = PN1->Height; // ������ �������  ���������� � PN1
//
 L_GP->Top   = F2->Height - 99; // ����� ����� �����
 L_GP->Width = IM_Logo->Left - L_GP->Left - 5 ; // ������ ����� ������
//
// L_OM->Left = PN1->Left ; // ����� ������ c����� *********************
 L_OM->Left = F2->Width - L_OM->Width - 22; // ����.������� �� 22 px ����� F2->Width
//
 IM_Logo->Left = PN1->Left + PN1->Width - IM_Logo->Width ;  // ������� - ��������������
 IM_Logo->Top  = PN1->Top  + PN1->Height + 3 ;
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF2::M1_OneClick(TObject *Sender)
{ // ��������� ������ ����� �� ���� M1
 int Col = M1->CaretPos.x, // ����� ������� � ������, ����� ������ (������� � 1)
     Row = M1->CaretPos.y; // ������������ ���������� ����� ������� ����� ������� �������
//
 char symb;
 char tmp[_32] = "\0";
 INT n0,n1,n2;
//
 n0 = strlen( M1->Lines->Strings[Row].c_str() ); // ����� ��������� ������ ��� ��������� ������ � M1
 char *str = (char*)malloc( n0+10 ); // �������� ������ ��� ��������� ������ (� �������)
//
 strcpy(str, M1->Lines->Strings[Row].c_str() ) ; // �������� ������, �� ������� �������� �����
//
 symb = str[Col]; // ������ ������ �� ����� ������ ����
//
 if( !isdigit( symb ) && // ���� symb '�� �����' �
      isdigit( str[Col-1] ) ) // ����� ��������� ����� ...
 {
  Col -- ; // ����� ���� ������� ������� ������ �� �����... ���������� ����� �� �������..!
  symb = str[Col];
 }
//
// ������ �������� �� ����� ��������� � ������
 if( !isdigit( symb ) || // ������ - �� �����...
      sscanf( str, "%d|%d:", &n1,&n2 ) != 2 ) // � ������ ��� ��������� 'n1|n2:'
  goto end;
//
 n0 = strchr( str, ':' ) - str ; // ����� ������� ':' � ������ str (������� � 0)
//
 if( Col <= n0 ) // ������ ������ �� ������ ���� ����� ��� ��������� � ':'
  goto end;
//
// ���� ����� ������� ����� (������ ��������� �� ����� ���)
 for( INT i=Col-1; i>n0; i-- ) // ������ ������ �� ����� ������ ������� ����
  if( !isdigit( str[i] ) ) // ����� �� �����
  {
   n1 = i+1; // ����� ������� ��������� � n1
   break;
  }
//
// ���� ������ ������� ����� (������ ��������� �� ����� ���
 n2 = strlen( str ); // ...����� ������ ����� � ������ � ������ ��� ������� '�� �����'
//
 for( INT i=Col; str[i]!='\0'; i++ ) // ����� ������� �� ����� ������ ������� ���� �� ����� ������
  if( !isdigit( str[i] ) ) // ����� �� ����� ���
  {
   n2 = i-1; // ����� ������� ��������� � n1
   break;
  }
//
 for( INT i=n1; i<=n2; i++ )
  tmp[i-n1] = str[i] ; // ������� �� n1 �� n2 �������� �� ������ str � ������ tmp
 strcat( tmp, "\0" ); // ������������ ����
//
 if( sscanf( tmp, "%d", &n0 ) != 1 ) // �������������� �������� �������������� ������ � �����
  goto end;
//
 PutParamsAboutSelectOp( n0 ); // ������ � ��������� ���� ��������� ��������� Op
//
 free( str ); // ������������ ������ ��� ��������� ������
 return; // ����� �������� ���������
//
end: // ����� ��������� ���������
//
 L_GP->Caption = "";
 MessageBeep( MB_ICONEXCLAMATION ); // �������� ��������������...
 free( str ); // ������������ ������ ��� ��������� ������
//
} //----------------------------------------------------------------------------





