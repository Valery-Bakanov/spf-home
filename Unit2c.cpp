//---------------------------------------------------------------------------
//
#include <vcl.h>
#include "stdio.h"
//
#include <Clipbrd.hpp>
#include <IniFiles.hpp>
#include <SysUtils.hpp> // дл€ DeleteFile
#include <io.h> // дл€ chmod
#include <dos.h> // FA_RDONLY + sleep
#include <share.h> // SH_COMPAT
//
#pragma hdrstop
//
#include "Unit2c.h"
#include "Unit1c.h" // чтобы был доступ к F1 (форма работы с Lua)
//
//------------------------------------------------------------------------------
//
#pragma package(smart_init)
#pragma resource "*.dfm"
TF2 *F2;
//
////////////////////////////////////////////////////////////////////////////////
extern const int minW_F2=850, minH_F2=600; // минимальный размер дочерной формы F2
////////////////////////////////////////////////////////////////////////////////
extern char FileNameEdges[]; // им€ файла »√ј
////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
__fastcall TF2::TF2(TComponent* Owner): TForm(Owner)
{
 F2->Position = poDefault; // чтобы не мешала позиционированию...
/*
 SetWindowLong(Handle, GWL_STYLE, // создать окно без заголовка
               GetWindowLong( Handle, GWL_STYLE ) && (! WS_CAPTION));
 ClientHeight=Height;
*/
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF2::M1_PM_ClearAll(TObject *Sender)
{ // очистить M1
 M1->Clear(); // полностью очистить M1 (TMemo)
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF2::M1_PM_CopyAll(TObject *Sender)
{ // копировать в Clipboard всЄ из M1 (TMemo)
// Clipboard->AsText = M1->Text.
 M1->SelectAll(); // выделить весь текст в M1
 M1->CopyToClipboard(); // копировать всЄ из M1 в Clipboard
 M1->SelLength = 0; // сн€ть выделение
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF2::M1_PM_CopyToNotepad(TObject *Sender)
{ // копировать в NotePad всЄ из M1 (TMemo)
 char FileName[256];
 strcpy( FileName, ChangeFileExt( FileNameEdges, ".txt" ).c_str()); // им€ пректа + "txt"
 M1->Lines->SaveToFile( FileName ); // выдать все строки из M1 в файл FileName
 ShellExecute( Handle, "open", FileName, NULL, NULL, SW_RESTORE ); // открыть файл FileName
//
 sleep( 1 ); // #include <dos.h>
//
 DeleteFile( FileName ); // уничтожить (временный) файл
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF2::CopyPictureToClipboard(TObject *Sender)
{ // копирует картинку в Clipboard
//
 try
 {
  Clipboard()->Assign(IM1->Picture); // копировать это в Clipboard
// IM1->Picture->SaveToFile("pict_01.bmp"); // сохранить в файл
  MessageBeep(MB_OK); // it's OK...
 }
 catch(...)
 {
  MessageBeep(MB_ICONEXCLAMATION); // it's no OK...
 }
//
} //---- конец CopyPictureToClipboard ------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF2::OnResize_F2(TObject *Sender)
{ // вызываетс€ при изменени€ размеров F2
 int W = F2->Width, // вз€ли текущий размер главного окна программы
     H = F2->Height;
// MessageBeep(MB_OK);

 if( W < minW_F2 ) // окно не может быть менее minW_F2 * minH_F2
  W = minW_F2;

 if( H < minH_F2 ) // ...
  H = minH_F2;

// теперь можем установить размеры главного окна и всех подокон

 F2->Width  = W; // новый размер окна программы
 F2->Height = H;

// внутренние компоненты окна F2

 PN1->Left   = F2->Width  - PN1->Width - 20 ; // панель-контейнер графического вывода
 PN1->Height = F2->Height - PN1->Top   - 102 ;

 M1->Width  = PN1->Left - M1->Left - 3; // окно текстового вывода (слева сверху)
 M1->Height = PN1->Height; // нижн€€ граница  одинакова€ с PN1

 L_GP->Top   = F2->Height - 99; // текст внизу слева
 L_GP->Width = IM_Logo->Left - L_GP->Left - 5 ; // ширина этого текста

 L_OM->Left = PN1->Left ; // текст вверху cправа

 IM_Logo->Left = PN1->Left + PN1->Width - IM_Logo->Width ;  // логотип - √–ј‘ќ¬џ∆»ћаЋ ј
 IM_Logo->Top  = PN1->Top  + PN1->Height + 3 ;

} //----------------------------------------------------------------------------








