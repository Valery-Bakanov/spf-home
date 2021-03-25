//
// ��������� Advanced Compiler: - Pentium, Word
//
#define DEBUG 0 // ����� stackDump ��� �������, ���� DEBUG ���������� true
#define HOOK_COUNT 3 // ���� ������� ������������ luaHook
//#define METHOD_OF_CALC_COUNT_OPS // �� ������ ������ ��������� ����� ���������� (�������� ������� ����)
//
#include <vcl.h>
#include <vcl/dstring.h> // ��� ������ � ANSI-��������
// #include <vcl/StrUtils.hpp> // ��� ������ � ANSI-�������� ( AnsiReplaceStr )
#include <cstddef.h>
//
#include "stdio.h"
#include "fcntl.h"
#include "/sys/stat.h"
#include "io.h"
#include "stdlib.h"
#include "string.h"
#include <time.h>
#include <sys\timeb.h>
#include "cstring.h"
#include "SysUtils.hpp"
#include <System.hpp>

#include <shellapi.h>

#include <time.h>
#include <alloc.h>
#include <math.h>
#include <excpt.h>
#include <sysdefs.h>
#include <sysopen.h>
#include "windows.h"
//#include <graphics.h>
//
#include <setjmp.h> // ��� ���������� ������������ ��������
jmp_buf env_StopSessionLua; // � env_StopSessionLua ����������� ��������� � ����� ������ setjmp
short i_env_StopSessionLua = -1; // ��� ���������� setjmp (����� longjmp ��������� ������ ��� i_env_StopSessionLua >= 0)
//
#include <Clipbrd.hpp>
#include <IniFiles.hpp>
//#include <shellapi.h>
#include "SysUtils.hpp"
//
#include <mmsystem.hpp> // ��� PlaySount
#include "vcl/dstring.h" // ��� �������� Length
//
#include <clocale> // ��� setlocale()
//
#define strNcpy(d,s) strncpy(d,s,sizeof(d)) // ���������� �������
//
using namespace std; // ����������� ������������ ���
//
#define do_tStart_fStop \
{ F1->SB_StopScript->Enabled  = FALSE;  /* �������������� ������ StopScript */ \
  F1->SB_StartScript->Enabled = TRUE; } /* ������������ ������ StartScript */
//
#define do_fStart_tStop \
{ F1->SB_StopScript->Enabled  = TRUE;    /* ������������ ������ StopScript */ \
  F1->SB_StartScript->Enabled = FALSE; } /* �E������������ ������ StartScript */
//
#define do_HandRule_Enabled \
{ F1->LoadAndPutIGA->Enabled  = TRUE;    /* ������������ �������� "������� ����������" � ������� ���� */ \
  F1->CreateUpperSPF->Enabled = TRUE; \
  F1->CreateLowerSPF->Enabled = TRUE; \
  F1->CreateTimeLiveData->Enabled = TRUE; \
  F1->CreateParamsByOp->Enabled = TRUE; }
//
#define do_HandRule_Disabled \
{ F1->LoadAndPutIGA->Enabled  = FALSE; /* �������������� �������� "������� ����������" � ������� ���� */ \
  F1->CreateUpperSPF->Enabled = FALSE; \
  F1->CreateLowerSPF->Enabled = FALSE; \
  F1->CreateTimeLiveData->Enabled = FALSE; \
  F1->CreateParamsByOp->Enabled = FALSE; }
//
#pragma hdrstop
//
#pragma warn -8057 // ��������� ��������� E8057 Parameter 'Sender' is never used
//
#include "Unit1c.h"
#include "Unit2c.h" // ����� ��� ������ � F2 (����� ������ ������������ ������)
//
//------------------------------------------------------------------------------
#pragma package(smart_init)
//
#include <LMDSedGotoLineDialog.hpp>
#include <LMDSedColorSchemeDialog.hpp>
//#include <LMDSedSyntaxSchemeDialog.hpp>
//#include <LMDSedKeyBindingsDialog.hpp>
//
#pragma link "LMDSedView"
#pragma link "LMDSedDocument"
#pragma link "LMDPrintPageDialog"
#pragma link "LMDCustomComponent"
#pragma link "LMDPrinter"
#pragma link "LMDSedDialogs"
#pragma resource "*.dfm"
//
TF1 *F1;
//
TStringList *TLD; // ������ ����� ��� ������ ����������� � ������� ����� ������ ������ ���
// TLD - ������; �������� � TF1::TF1(), ����������� ������� � c_CreateAndOutputDataLiveDiagrByTiers()
//
//#include "pcre.h" // ���������� ���������� ��������� �� Borland C++ RTL
//
#define REAL  float  // ��� ������������ ����� ��������� ������� ��� �����������
#define DREAL double // ��� ������������ ����� ������� �������� ��� �����������
//
#define INT  long // ��� ����� �� ������ ( 32 ���� = 4 �����; �������� +/- 2'147'483'647 )
#define UINT long // ��� ����� �� ������ ( 32 ���� = 4 �����; �������� +/- 2'147'483'647 )
//
#define ULI unsigned long int // ������� ����� ��� �����
#define UI  unsigned int // ����� ��� �����
//
#define _IN  " \xAB%d" // \xab=<< ������� ����, ��� � ��������� ��� ��������  ��� (��� �������� ������)
#define _OUT " %d\xBB" // \xbb=>> ������� ����, ��� � ��������� ��� ��������� ��� (��� ��������� ���������)
//
#define _128   128 // ����������� �������� ��� ���� ���������
#define _256   256
#define _512   512
#define _1024  1024
#define _2048  2048
#define _4096  4096
#define _8192  8192
#define _16384 16384
#define _32�768 32768
//
#define maxRet 1000000000 // ������������ ������������ ����� (�� ����� 2^32... � �������!)
//
// ----- ���� ������ (���� �������� �������) -----------------------------------
#define ERR_NOT_MASSIVE_EDGES -666 // ��� ������� Mem_Edges[], ��� ������� ������������ ��������
#define ERR_NOT_MASSIVE_TIERS -777 // ��� ������� Tiers[][], ��� ������� ������������ ��������
#define ERR_IN_DATA -888 // ������������ ������� ������
#define ERR_RANGE_IN -1313 // ������ ��������� ������� ���������� �������
#define ERR_NOT_MEMORY -133 // �������� ������ ��� Mem_Edges[] �/��� Tiers[][]
#define ERR_TRANSFORM -131313 // ������ �������������� ��������� ��������� �� sscanf
// #define ERR_LIMITS_OP_CALC -131331 // �������� � c_canExecOpCalc(INT Op, INT Calc)
#define ERR_METRIC -666.777 // ���������� ����� ������� ������� (���������) ��� ����
#define ERR_CALC   -777.666 // ��� ������ ������� ���������� (��������� Calc...)
#define ERR_COMMON -123456789 // ��� ������ �����
#define ERR_UNCERTAIN -1 // ��� ������ ����������
//#define nDef -134 // ��������� ������ ���������� �� "=Def:^"
////////////////////////////////////////////////////////////////////////////////
//#define NOT_LIMITS_OPS 1111111 // ��� ����������� �� ���������� ���������
//#define NOT_LIMITS_CALCS 2222222 // ��� ����������� �� ���������� �����������
//
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
//
////////////////////////////////////////////////////////////////////////////////
//==============================================================================
////////////////////////////////////////////////////////////////////////////////
extern "C" // Lua - �������� ������ �� "������ �"
{
#include "./lua/src/lua.h"
#include "./lua/src/lauxlib.h"
#include "./lua/src/lualib.h"
}
#include "./lua/src/lua_src.c" // ��� �-��������� Lua...
lua_State *L = NULL; // ���������� ��������� - ��������� �� ��������� Lua !!!!!!
//
void  __fastcall stackDump (lua_State *L, char *s); // ����� ���������� ����� Lua
int   __fastcall lua_pcall_Debug( lua_State* L, int args, int results ); // ������ ���������� Lua � ��������
static void LuaHook( lua_State *L, lua_Debug *ar); // ������� ����������� ���������� ����� Lua
static int  errorHandler( lua_State* L ); // ������� - ���������� ������
static int  luaPanic( lua_State* L ); // ������� ������ Lua
////////////////////////////////////////////////////////////////////////////////
//==============================================================================
////////////////////////////////////////////////////////////////////////////////
//
char *spf_pt0  = "=\\d{1,}/\\d{1,}:", // =12/155: // ������� ��� ���������� ���������
     *spf_pt00 = "-[a-zA-Z�-��-�]{1}[_a-zA-Z�-��-�0-9]{0,}", // -param_1
     *spf_pt01 = "-[a-zA-Z]{1}[_a-zA-Z0-9]{0,}\\s{1,}[+-]{0,1}\\d{0,}\\.{0,1}\\d{0,}", // -par_1 m1
     *spf_pt02 = "-[a-zA-Z]{1}[_a-zA-Z0-9]{0,}\\s{1,}[+-]{0,1}\\d{0,}\\.{0,1}\\d{0,}\\s{1,}[+-]{0,1}\\d{0,}\\.{0,1}\\d{0,}", // -parr_2 m1 m2
     *spf_pt03 = "-[a-zA-Z]{1}[_a-zA-Z0-9]{0,}(\\s{1,}[+-]{0,1}\\d{0,}\\.{0,1}\\d{0,}){2}"; // -parr_2 m1 m2
//
#define strcat(dest,src) strncat(dest,src,sizeof(dest)-strlen(dest)-5) // ���������� ���������� src � dest
// !!!!! ��� >=5 �� ���������, ��� <5 ����� ������� � metametod "__newindex" ������ 274 OpsCalcs[subTiers][mCalc]=iOp
//
#define GetRand(a,b) ( rand() % ( (b)-(a)+1)+(a) ) // ��������� ����� �� a �� b (������������)
//
char Ident[] = "Bakanov Valery Mikhailovich, Moscow, Russia, 2009-2021\n \
����� ������������ �������� ������� ������� �� �������� ���� ����������� ��������-���������������� ���������������� \
(������ ������ ����� ����� ����� ���������!) � ������� ������� ����� ���� �� ���������� ���\n \
The author of the software Valery Bakanov is not an ardent supporter of Object-Oriented Programming \
(Linus Torvalds definitely sits inside the author!) and therefore most of the code does not use OOP";
//
struct {
INT nOpMinIn,  nEdgesMinIn,  // # ����. � MIN �������� ��� � ����� ���� ��� (����� nInput)
    nOpMaxIn,  nEdgesMaxIn,  // # ����. � MAX �������� ��� � ����� ���� ��� (����� nInput)
    nOpMinOut, nEdgesMinOut, // # ����. � MIN ��������� ��� � ����� ���� ��� (����� nOutput)
    nOpMaxOut, nEdgesMaxOut; // # ����. � MAX ��������� ��� � ����� ���� ��� (����� nOutput)
REAL AveIn, AveOut; // ������� ����� ������ � �������
} PG; // ��������� ��� �������� ��������� ����������� �������� � ��������� ��� �� ����������
// PG ParGraph; // ���������� PG ���� ParGraph
//
long color_BackGround = clWhite; // ���� ���� ���� ��������������
//
// ----- ����� ��� ��������� ��������� �����. ���������� �� ������ ��� ( DrawDiagrSPF, DrawDiagrTLD )
long brush_draw_color_TIERS = clBlack, // ���� ����� ������� ��� ������� ��� (������)
//     brush_draw_color_TLD   = RGB(0,64,0), // ���� ����� ��� ������ ������� ����� ������ (����-������)
     brush_draw_color_TLD   = clBlack, // ���� ����� ��� ������ ������� ����� ������ (����-������)
     brush_draw_color_MIN   = clRed, // ���� ����� �������
     brush_draw_color_MAX   = clFuchsia, // ���� ����� ��������
     pen_draw_b_average     = clWhite, // ���� ����� �������� �����
     contour_draw_color     = clWhite; // ���� ����� ��������������
// ----- ����� ��� ������� ��������� �����. ���������� �� ������ ��� ( ClearDiagrSPF )
long clear_brush_draw_color = RGB(255,255,255); // clWhite; // ���� ����� ������� (���� ����)

////////////////////////////////////////////////////////////////////////////////
//
#define _nOpMinIn    (GetParGraph().nOpMinIn) // ������ ��������� ���� �� ������ - ��������!!!
#define _nEdgesMinIn (GetParGraph().nEdgesMinIn) // !!!
#define SB0 F1->SB->Panels->Items[0] // ������ ������ ������� (����� ����� �����)
#define TEV0 F1->LMD_EV0 // TLMDEditView (LMD SyntaxEdit SingleLicense)
#define TED0 F1->LMD_ED0 // TLMDEditDocument (LMD SyntaxEdit SingleLicense)
#define TM0_stdout F1->M0_stdout // TMemo ������ ���������� ���������� �������� ( stdout )
#define TM1  F2->M1 // TMemo ������ ������� �� F2
#define TIM1 F2->IM1 // ������� ������ ������� (TImage) �� F2
//
#define c_AddLineToFileProtocol(s) \
 { if (fptr_protocol) fprintf(fptr_protocol,s); } // ����� ������ s � ���� ���������
//
#define c_AddLineToStderr(s) \
 {if (fptr_stderr) fprintf(fptr_stderr,s); } // ����� ������ s � stderr
//
void /*__fastcall*/ t_printf(char *fmt, ...); // ��������� ����� � ��������� ����
void /*__fastcall*/ p_printf(char *fmt, ...); // ��������� ����� � ���� ���������
void /*__fastcall*/ e_printf(char *fmt, ...); // ��������� ����� � ���� stderr
void /*__fastcall*/ tp_printf(char *fmt, ...); // ��������� ����� � ��������� ���� � � ���� ���������
void /*__fastcall*/ tpe_printf(char *fmt, ...); // ��������� ����� � ��������� ����, � ���� ��������� � � stderr
void /*__fastcall*/ sp_printf(char *fmt, ...); // ��������� ����� �� StatusBar � � � ���� ���������
void /*__fastcall*/ safe_printf(int rule, char *fmt, ...); // ��������� ����� � �������� rule �������
//
////////////////////////////////////////////////////////////////////////////////
//
#define MAX_EDGES 10000000 // ������������ ������ ���� ��� ��������������� ����� 10^7 // �� �����������
// �������� ��������� ������ ���� ��������������� ����� ���������
struct me {
 INT From, To; // ������������ ���� ���� "������ -> ����"
 char Operators[_512]; // ��������� �������� ����������, ������������ ����
 bool flag_From, flag_To; // ����� ��� ��������������� �������� � ������
} M__E, *Mem_Edges=NULL;
ULI Max_Edges = _128, // �������������� ������ (����� �������������� � c_ReadEdges)
    Really_Edges = 0; // ������� ��������
#define Edges(i,j)   ( !i ? Mem_Edges[j].From      : Mem_Edges[j].To ) // "������/����" ���������� ���� ���
#define Edges_f(i,j) ( !i ? Mem_Edges[j].flag_From : Mem_Edges[j].flag_To ) // ����� "������/����" ���������� ���� ���
// Edges(0,j) - ����� ���������, �� �������� ������� ���� ("From");
// Edges(1,j) - ����� ���������, � �������� "��������" ���� ("To")
// ���������� �� j �������� � 1 (��� ������������ � ��������� ���������� � Lua)
//
#define MAX_EVENTS 1000000 // ������������ ������ ������ ������� 10^6 // �� �����������
struct ev {
 INT start_Ticks, // ������ ������ �������
     d_Ticks, // �������� ��������
     ev_Ticks; // ��� ������� ������ �������
 char CommandLine[_256]; // ����� Lua-������
} E_V, *Mem_EV=NULL;
INT max_Events = _128, // �������������� ������
    i_Events = 0; // ������ ���������� �������� �������� � ������� Mem_EV
//
////////////////////////////////////////////////////////////////////////////////
INT _maxTiers     = 100, // max ����� ������ � ����� (���� 1 - �������� ������)  ( ���������� !!! )
    _maxTiersPrim = 100; // ...��� ��������������� �������������
INT _maxOpsOnTier     = 100, // max ����� �������� �� �����  ( ���������� !!! )
    _maxOpsOnTierPrim = 100; // ...��� ��������������� �������������
INT *pTiers  = NULL, // ��������� �� (�������) ������ Tiers
    *npTiers = NULL; // ��������� �� ��������� ������
// 2D-������ Tiers[][] �������������� �� ������� � ���������� ������ � ������ ��������� pTiers
// ����� i - ����� ����� (������� � 0), j - ����� ��������� �� ����� (j �������� � 1) 
#define Tiers(i,j) pTiers[(i)*(_maxOpsOnTier+1)+(j)] // ��������� � 2D-������� Tiers ��� � ��������
////////////////////////////////////////////////////////////////////////////////
#define stockMem 1.667 // �������� "������" ��� ���������� ��������
////////////////////////////////////////////////////////////////////////////////
INT nEdges, // ����� ����� ��� � �����
    nOpsInput, // ������� ���������� � ����� (�������� ������)
    nOpsOutput, // �������� ���������� � ����� (������������ ������)
    nOps, // ����� ���������� � ����� ��� ������� (�� � ���������)
    nTiers, // �������������� ����� ������ � ��� �����
    nMoves = 0; // ���������� ���������� ��� �������� �������� ����������� ���������� ����� �������
////////////////////////////////////////////////////////////////////////////////
bool isTiers = false, // ����������� �� ������ Tiers[][] (����� ������� ���������� ��� - FALSE)
     isEdges = false; // ����������� �� Mem_Edges[]
char messNotTiers[] = "������ ������ �� �����������", // ��������� �� �������
     messNotEdges[] = "������ ��� �� �����������",
     messParams1[]  = "����������� �������� ����������(1)",
     messParams2[]  = "����������� �������� ����������(2)",
     messParams3[]  = "����������� �������� ����������(3)";
//
char TitleF2[_256] = " ��������� ������������� ����������"; // ��������� F2
//
// ����� ������ ����� ������������ �������
struct { // ReadWriteConfig (����� ������ ���� ������������ �������)
char *Sect1, *Sect1_Var1,*Sect1_Var2,*Sect1_Var3,*Sect1_Var4,*Sect1_Var5,*Sect1_Var6,*Sect1_Var7,*Sect1_Var8,*Sect1_Var9,
     *Sect2, *Sect2_Var1,*Sect2_Var2,*Sect2_Var3,*Sect2_Var4,*Sect2_Var5,
     *Sect3, *Sect3_Var1,*Sect3_Var2,*Sect3_Var3,*Sect3_Var4,*Sect3_Var5,*Sect3_Var6,
     *Sect4, *Sect4_Var1,
     *Sect5, *Sect5_Var1,*Sect5_Var2,*Sect5_Var3,*Sect5_Var4,*Sect5_Var5,*Sect5_Var6,*Sect5_Var7,*Sect5_Var8,
     *Sect6, *Sect6_Var1 ;
} RWC = {
 "Font", // [1] ���� ���� �������������� Lua-��������
  "Name","Size","Color","Charset","Pitch","Bold","Italic","Underline","StrikeOut",
 "Pos_F1", // [2] ��������� ����� �������� ����
  "Top","Left","Width","Height","partheightStdout",
 "Pos_F2", // [3] �������� ����� ��������� ����
  "Top","Left","Width","Height","PutParamsTiersOnTextFrame","PutParamsDataLiveOnTextFrame",
 "LastScript", // [4] ��������� ���� �������
  "ScriptFileName",
 "LMD_EditViewColors", // [5] ����� ���� �������������� Lua
  "Gutter->LinesBarBg","Gutter->LinesBarTextColor","Gutter->FoldsBarBg","Gutter->FoldsBarLineColor","Gutter->CustomBarBg","SelectionBg","SelectionColor","Color",
 "Tick_Interval", // [6] �������� �������� ������� (����)
  "Interval"
} ; // [ReadWriteConfig] ����� ������ ����� ������������
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char ScriptFileName[_256]  = "noname.lua", // ������� ��� ����� Lua-�������
     stdinFileName[_256], // ��������� ���� Lua-������� ( stdin )
     stdoutFileName[_256], // stdout...
     stderrFileName[_256], // stderr...
     FileNameProtocol[_256], // ���� ���������
     FileNameEdges[_256]  = "no_name.gv", // ������� ���� ��� ����� (�������� �����)
     GraphName[_256]      = "no_name", // ��� ����� (������ �� gv-�����)
     _FileNameEdges[_256] = "EdgesData", // ������������� ��� ����� ������ ��� (���������� - ��. ����)
     FileNameINI[_256],   // ���� � ����� ������������
     NameSubDirOutData[] = "Out!Data", // ��� ����������� ��� ������ ������������ ������
     NameSubDirInData[]  = "In!Data",  // ��� ����������� ��� �������� ������ ������
     PathToSubDirOutData[_256], // ������ ���� � ����������� ������ ������������ ������
     PathToSubDirInData[_256], // ������ ���� � ����������� �������� ������ ������
     MySite[] = "http://vbakanov.ru", // ����� ����� �����
//
     extGv[]    = "gv",   // ���������� ����� ����� ��� ����� ��� �����
     extEdges[] = "edg",  // ���������� ����� ����� ��� ����� ��� ������
     extVizu[]  = "_vz", // ���������� � ���������� ����� ����� ��� Visu (�����/����, ".")
     extTiers[] = "trs", // ���������� ����� ����� ��� (�����, ��� ".")
     extTld[]   = "tld"; // ���������� ����� ����� ������� ����� ������  (�����, ��� ".")
////////////////////////////////////////////////////////////////////////////////
FILE *fptr_stdout, *fptr_stderr, *fptr_protocol; // ��������������� �������� ���������
#define DELAY_PUT_PROTOCOL 0 // ����� ����������� ��� ������ ���������
char uniqueStr[_512] = "\0"; // ���������� ������ ��� ���� ������ ( ���� + ����� �� ���� )
////////////////////////////////////////////////////////////////////////////////
bool flagCommandLine = FALSE; // ���� THUE - ������ � ������ ��������� ������
////////////////////////////////////////////////////////////////////////////////
bool flagHook = FALSE; // ���� ������������ "�������" (Hook)
//
INT ticks = 0; // ���������� ������� �����
//
bool flag_Busy = FALSE; // ���� TRUE - ����� Lua �� Events ����������
char busy_CommandLine[_256]; // ������������� � ������ ������ Lua-������
//
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall RunLuaScript(); // ��������� Lua-�������
bool  __fastcall IncreaseOpsOnTier(INT Tier, INT newSize, INT flag); // ����������� #���������� �� ������ Tiers[][] �� newSize
char* __fastcall PutDateTimeToString(INT flag); // ������ ������� ���� � ������� � ������ � ���������������
bool  __fastcall CloseAndRenameFileProtocol(); // ���� ������������� ��� ����� ���������
void  __fastcall PutScriptFileName(); // ����� ��� ����� ������� �� �����
void  __fastcall DisplayMessage(char* Level, char* funcName, char* Text, INT Err); // ������ ��������� Text ������ Level
void  __fastcall IndicateColRowNumberOfEV0(); // ����� ������ � ����� ������� � ������� �������
char* __fastcall ReplManySpacesOne( char *pszStr ); // �������� ������� ������� �� ������������
void  __fastcall DelSpacesTabsAround( char *str ); // ������� ������� � Tabs ����� � ������ ������ str
void  __fastcall DelAllSpaces(char *str); // ������� ��� ������� � ������ str
void  __fastcall Read_Config(); // ������ � ���������� ���� ������������
void  __fastcall Write_Config();
bool  __fastcall StartByCommandLine( char *s ); // ������ ������ � ������ ��������� ������
bool  __fastcall c_CreateTiersByEdges( char* FileName ); // ������ (�� ������ ��� �� ������� FileName ��� � "�������" ������������ �����
bool  __fastcall c_CreateTiersByEdges_Bottom( char* FileName ); // ������ (�� ������ ��� �� ����� FileName ��� � "������" ������������ �����
void  __fastcall GetFileFromServer( char FileName[] ); // �������� ���� � �������
void  __fastcall Copy_Stdout_To_Memo(); // ��� ������ stdout � M0_stdout
//
void  __fastcall ShowBreakpoint( char *str ); // �������� ����� �������� (Breakpoint) � ��������� ��������� Lua
//
void  __fastcall stdoutToMemo(); // ����� stdout � M0_stdout
//
void Set_FileNames_All_Protocols(); // ����������� ����� ���� ������ ���������� (��� Out!Data)
////////////////////////////////////////////////////////////////////////////////
// ������ ��� �������� ���������� ������������ � ���������� --------------------
char *sCalcs = NULL, // ������� ������ ��� ��������  ���������� ������������
     *sOps   = NULL, // ...����������
     *sEdg   = NULL, // ...������ ���
     *sVrt   = NULL, // ...������ ������
     *sWork  = NULL; // ������� ������
const char // ����� ������ ���������� �� ��������� -----------------------------
     DefFileNameParamsCalcs[]    = "calculators.cls", // ���� ���������� ������������
     DefFileNameParamsOps[]      = "operators.ops",   // ���� ���������� ����������
     DefFileNameParamsEdges[]    = "edges.med",     // ���� ������ ��� ���
     DefFileNameParamsVertices[] = "vertices.mvr";  // ���� ������ ������ ���
char // �� �� ����� ������, �� ������� (�������)--------------------------------
     FileNameParamsCalcs[_256], // �������� ��� �����... (��. ����)
     FileNameParamsOps[_256], // ...
     FileNameParamsEdges[_256], // ...
     FileNameParamsVertices[_256]; // ...
char sDef[] = "=Def:\0"; // ������ ��� ������ � ���������
////////////////////////////////////////////////////////////////////////////////
WideString ActiveColorScheme  = "defColorScheme", // "������� ������" ��� ����������� LMD
           ActiveSyntaxScheme = "defSyntaxScheme";
char extSchemes[] = "xml"; // ���������� ������ ���� ������ � ���������� ( ��� ����� )
////////////////////////////////////////////////////////////////////////////////
bool PutParamsTiersOnTextFrame = FALSE, // ���� ������ �������� ������ ������� ������ (������� � INI-�����)
     PutParamsDataLiveOnTextFrame = FALSE; // �������� �� ������ � ������� ����� � ���� F2
// ��� TRUE ��������� � ��������� ���� �� �� �����, ��� � ������ ����� ���������� ���� ������
////////////////////////////////////////////////////////////////////////////////
bool luaExecute = FALSE; // ���� ������� ���������� Lua (��� ����������� TRUE, ����� FALSE)
//
//#define strcat(dest,src) strncat(dest,src,sizeof(dest))-strlen(dest)-5) // ���������� ���������� src � dest
//
char first_F1[] = "-- %s: ������ �� ����� Lua ver.5.3.0 rel.on 06 Jan 2015\n--\n", // ��������� ������ ��� Lua
     first_F2[] = "-I- %s: ������ ���������� ��������� �� ����� Lua ver.5.3.0 rel.on 06 Jan 2015 -I-\n"; // ��������� ������ ������ ������ Lua
//
#include "API_c.cpp" // �-����� ������� API (���������� � "c_")
#include "API_lua.cpp" // �������� �� � ������� Lua
#include "LMD_c.cpp" // �������� �� � ������� LMD
//
const int minW_F1=900, minH_F1=600; // ����������� ������� ������� ����� F1
extern const int minW_F2, minH_F2; // ����������� ������ �������� ����� F2
////////////////////////////////////////////////////////////////////////////////
//int outGlobal = 0; // ������ ��� �����������, �� ������ MenuItem ������ CD0 (���������� � LMD_c.cpp)
////////////////////////////////////////////////////////////////////////////////
REAL partHeightStdout[3] = {0.2, 0.1, 0.5}; // ���� ������ ���� stdout (�������, min, ���)
////////////////////////////////////////////////////////////////////////////////
int FileSizeFromServer; // ������ ����� ��� �������� � �������
////////////////////////////////////////////////////////////////////////////////
//
__fastcall TF1::TF1(TComponent* Owner) : TForm(Owner) // ����������� � ������ �����..!
{
//
 F1->Position = poDefault; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
 time_t t;
//
 DecimalSeparator = '.'; // ����������� ����� � ���������� ������ - �����
//
 strNcpy( FileNameINI, ChangeFileExt(ParamStr(0), ".ini").c_str()); // INI-���� � ������� ��������
//
 pTiers = (INT*) calloc( (_maxTiers+1)*(_maxOpsOnTier+1), sizeof(INT) );
//
// ����������� ������ ��� ������ ���������� ������������, ����������, ������ ��� � ������
 sCalcs = (char*) calloc( _16384, sizeof(char) ); // ��� ���������� ������������...
 sOps   = (char*) calloc( _16384, sizeof(char) ); // ��� ���������� ����������...
 sEdg   = (char*) calloc( _16384, sizeof(char) ); // ��� ������ ���...
 sVrt   = (char*) calloc( _16384, sizeof(char) ); // ��� ������ ������...
 sWork  = (char*) calloc( _16384, sizeof(char) ); // ������� ������ ������...
//
 Mem_EV = (ev*)   calloc( i_Events, sizeof(ev) ); // ������ �������
// ����������� ����� ������ ----------------------------------------------------
 strNcpy( _FileNameEdges, ChangeFileExt( _FileNameEdges, extEdges ).c_str() ); // ���������� - extEdges
//
////////////////////////////////////////////////////////////////////////////////
//
 LMD_ED0->ActiveColorScheme  = ActiveColorScheme ; // ����������� ��� �������� ����
 LMD_ED0->ActiveSyntaxScheme = ActiveSyntaxScheme ;
//
// Copy_Stdout_To_Memo(); // ���������� stdout �� Memo
//
 TLD = new TStringList; // ����� ����� ��� ���������� ���������� �� ������� ����� ������
//
} // --- ����� TF1 -------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void t_printf(char *fmt, ...)  // ����� ������ � ��������� ����
{  // �� ����� ������ ������������� ��������� !
 int lenBuff = _256; // ��������� ����� ������ ������
 char* buff = (char*) malloc( lenBuff ); // ����� ��������������� ������-������ ��� ���������� ������
 va_list args;  // ���������� �������� ������ � ��������� ( ...  )
 va_start( args, fmt );  // ������ ������ ���������� � ���������
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // ����������� ����� ������ ��� ������������ ������ ������
 if( new_lenBuff > lenBuff ) // ���������� ��������� �����..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // ����������� ����� (� ������ '\0' � �����)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // ������ ������� � (�����������) ����� buff
 }
 va_end(args);  // ����� ������ ���������� � ���������
//
 c_AddLineToTextFrame( buff ); // ���������� � ��������� ����  (������������ '\n')
} // ---- ����� t_printf -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void p_printf(char *fmt, ...) // ����� ������ � fptr_prot
{  // �� ����� ������ ������������� ��������� !
 int lenBuff = _256; // ��������� ����� ������ ������
 char* buff = (char*) malloc( lenBuff ); // ����� ��������������� ������-������ ��� ���������� ������
 va_list args;  // ���������� �������� ������ � ��������� ( ...  )
 va_start( args, fmt );  // ������ ������ ���������� � ���������
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // ����������� ����� ������ ��� ������������ ������ ������
 if( new_lenBuff > lenBuff ) // ���������� ��������� �����..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // ����������� ����� (� ������ '\0' � �����)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // ������ ������� � (�����������) ����� buff
 }
 va_end(args);  // ����� ������ ���������� � ���������
//
 c_AddLineToFileProtocol( buff ); // �������� � ���� ���������
} // ---- ����� p_printf -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void e_printf(char *fmt, ...) // ����� ������ � stderr
{  // �� ����� ������ ������������� ��������� !
 int lenBuff = _256; // ��������� ����� ������ ������
 char* buff = (char*) malloc( lenBuff ); // ����� ��������������� ������-������ ��� ���������� ������
 va_list args;  // ���������� �������� ������ � ��������� ( ...  )
 va_start( args, fmt );  // ������ ������ ���������� � ���������
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // ����������� ����� ������ ��� ������������ ������ ������
 if( new_lenBuff > lenBuff ) // ���������� ��������� �����..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // ����������� ����� (� ������ '\0' � �����)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // ������ ������� � (�����������) ����� buff
 }
 va_end(args);  // ����� ������ ���������� � ���������
//
 c_AddLineToStderr( buff ); // �������� � stderr
} // ---- ����� e_printf -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void tp_printf(char *fmt, ...)
{  // �� ����� ������ ������������� ��������� !
 int lenBuff = _256; // ��������� ����� ������ ������
 char* buff = (char*) malloc( lenBuff ); // ����� ��������������� ������-������ ��� ���������� ������
 va_list args;  // ���������� �������� ������ � ��������� ( ...  )
 va_start( args, fmt );  // ������ ������ ���������� � ���������
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // ����������� ����� ������ ��� ������������ ������ ������
 if( new_lenBuff > lenBuff ) // ���������� ��������� �����..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // ����������� ����� (� ������ '\0' � �����)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // ������ ������� � (�����������) ����� buff
 }
 va_end(args);  // ����� ������ ���������� � ���������
//
 c_AddLineToFileProtocol( buff ); // �������� � ���� ���������
 c_AddLineToTextFrame( buff ); // ���������� � ��������� ����
} // ---- ����� tp_printf ------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void tpe_printf(char *fmt, ...)
{  // �� ����� ������ ������������� ��������� !
 int lenBuff = _256; // ��������� ����� ������ ������
 char* buff = (char*) malloc( lenBuff ); // ����� ��������������� ������-������ ��� ���������� ������
 va_list args;  // ���������� �������� ������ � ��������� ( ...  )
 va_start( args, fmt );  // ������ ������ ���������� � ���������
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // ����������� ����� ������ ��� ������������ ������ ������
 if( new_lenBuff > lenBuff ) // ���������� ��������� �����..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // ����������� ����� (� ������ '\0' � �����)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // ������ ������� � (�����������) ����� buff
 }
 va_end(args);  // ����� ������ ���������� � ���������
//
 c_AddLineToFileProtocol( buff ); // �������� � ���� ���������
 c_AddLineToTextFrame( buff ); // ���������� � ��������� ����
 c_AddLineToStderr( buff ); // �������� � stderr
} // ---- ����� tpe_printf ------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void sp_printf(char *fmt, ...)
{  // �� ����� ������ ������������� ��������� !
 int lenBuff = _256; // ��������� ����� ������ ������
 char* buff = (char*) malloc( lenBuff ); // ����� ��������������� ������-������ ��� ���������� ������
 va_list args;  // ���������� �������� ������ � ��������� ( ...  )
 va_start( args, fmt );  // ������ ������ ���������� � ���������
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // ����������� ����� ������ ��� ������������ ������ ������
 if( new_lenBuff > lenBuff ) // ���������� ��������� �����..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // ����������� ����� (� ������ '\0' � �����)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // ������ ������� � (�����������) ����� buff
 }
 va_end(args);  // ����� ������ ���������� � ���������
//
 SB0->Text = buff;
 if( DELAY_PUT_PROTOCOL )
  F1->SB->Repaint(); // ����������...
 Delay( DELAY_PUT_PROTOCOL ); // �����... ��� �� �����!..
//
 p_printf( "%s %s\n", PutDateTimeToString(0), buff ); // �������� � ���� ���������
} // ---- ����� sp_printf ------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void safe_printf(int rule, char *fmt, ...)
{  // �� ����� ������ ������������� ��������� !
 int lenBuff = _256; // ��������� ����� ������ ������
 char* buff = (char*) malloc( lenBuff ); // ����� ��������������� ������-������ ��� ���������� ������
 va_list args;  // ���������� �������� ������ � ��������� ( ...  )
 va_start( args, fmt );  // ������ ������ ���������� � ���������
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // ����������� ����� ������ ��� ������������ ������ ������
 if( new_lenBuff > lenBuff ) // ���������� ��������� �����..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // ����������� ����� (� ������ '\0' � �����)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // ������ ������� � (�����������) ����� buff
 }
 va_end(args);  // ����� ������ ���������� � ���������
//
 switch( rule ) // ����� � ����������� �� �������� rule
 {
  case 1: c_AddLineToTextFrame( buff ); // �������� ������ �� ��������� �����
          break;
  case 2: c_AddLineToFileProtocol( buff ); // �������� ������ � ���� ���������
          break;
  case 3: c_AddLineToTextFrame( buff ); // �������� ������ �� ��������� �����
          c_AddLineToFileProtocol( buff ); // �������� ������ � ���� ���������
          break;
  case 4:
          break;
  default:
          break;
 } // ����� switch
} // ---- ����� safe_printf ----------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall DelAllSpaces(char *str)
{ // ������� ��� ������� � ������ str
//
// ��� ������������� AnsiReplaceStr ytj,[jlbvj #include <vcl/StrUtils.hpp>
// str = ( AnsiReplaceStr( str, " ", "" ) ).c_str(); // �������� ���� ��������
//
// �������������� ����� � http://www.quizful.net/interview/cpp/VbW07kq70NCY
 for (int i=0,j=0; str[i]; (str[j++]=str[i]!=' '?str[i]:(j--,str[j]),i++,(!str[i]?(str[j]=0):0)));
//
} // ------ ����� DelAllSpaces -------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall DelSpacesTabsAround(char *str)
{ // ������� ������� � Tabs ����� � ������ ������ str
// Trim, TrimLeft, TrimRight �������� ������ � AnsiString
// strNcpy(str, Trim(AnsiString(str)).c_str());
//
// ������� ������� � Tabs � ������ ������
 int i=0, j;
//
 while((str[i] == ' ') || (str[i] == '\t'))
  i++;
//
 if(i>0)
 {
  for(j=0;j<strlen(str);j++)
   str[j]=str[j+i];
  str[j]='\0';
 }
// ������� ������� � Tabs � ����� ������
 i=strlen(str)-1;
 while((str[i] == ' ') || (str[i] == '\t'))
  i--;
//
 if(i<(strlen(str)-1))
  str[i+1]='\0';
//
} // --- ����� ������� trim ----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall ReplManySpacesOne( char *pszStr )
{ // �������� ��������� �������� �����-������������
 char *pszOld = pszStr,
      *pszCur = pszStr;
//
 if( pszStr )
 {
  for( ; *pszCur; pszCur++ )
  {
   if( pszCur[1] != ' ' || pszCur[0] != ' ' )
    *pszStr++ = *pszCur;
  }
//
  *pszStr = *pszCur; // ����������� \0
 } // ����� if( pszStr )
//
   return pszOld;
} // --- ����� ������� ReplManySpacesOne -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall stackDump (lua_State *L, char *s)
{ // ����� ���������� Lua-����� ���������� L (� ������������ ������� s)
//
 if( !DEBUG ) // ������ �� ������...
  return;
//
 char str[_512];
 const char *w;
 size_t l;
 int top = lua_gettop(L); // ������� �����
//
 t_printf( "\n%s ������� ����� %d", s, top );
//
 if( !top ) // ������� ����� 0... ������  ��������!..
  return;
//
 for (int i = 1; i <= top; i++) // ��������� ��� ������� ������ �����
 {
//
  int len, tp = lua_type(L,i); // ����� ��� ������� �� ������ i �����
  switch (tp)
  {
   case LUA_TSTRING:  // ���� ��� ������...
        w = lua_tolstring( L, tp, &l ); // ???????????????????????????????????
        t_printf( "%s %d (�� %d) -> %s %s [%d]", s,i,top,lua_typename(L,tp), w, strlen(w) );
        break;
   case LUA_TBOOLEAN:  // ���� ��� ������ ����������
        t_printf( "%s %d (�� %d) -> %s %s", s,i,top,lua_typename(L,tp), lua_toboolean(L,tp) ? "true" : "false" );
        break;
   case LUA_TNUMBER:  // ���� ��� �����...
        t_printf( "%s %d (�� %d) -> %d %f", s,i,top,lua_typename(L,tp), lua_tonumber(L,tp) ) ;
        break;
   case LUA_TNONE: // ������ ������
        t_printf( "%s %d (�� %d) -> %s 'none'", s,i,top,lua_typename(L,tp) ) ;
        break;
   case LUA_TNIL: // ������
        t_printf( "%s %d (�� %d) -> %s 'nil'", s,i,top,lua_typename(L,tp) ) ;
        break;
   case LUA_TTABLE: // �������
        t_printf( "%s %d (�� %d) -> %s %x", s,i,top,lua_typename(L,tp), lua_topointer(L,tp) ) ;
        break;
   case LUA_TFUNCTION: // �������
        t_printf( "%s %d (�� %d) -> %s %x", s,i,top,lua_typename(L,tp), lua_topointer(L,tp) ) ;
        break;
   case LUA_TUSERDATA: // ���������������� ������
        t_printf( "%s %d (�� %d) -> %s %x", s,i,top,lua_typename(L,tp), lua_touserdata(L,tp) ) ;
        break;
   case LUA_TLIGHTUSERDATA: // ����� ���������������� ������
        t_printf( "%s %d (�� %d) -> %s %s", s,i,top,lua_typename(L,tp), lua_touserdata(L,tp) ) ;
        break;
   case LUA_TTHREAD: // �����
        t_printf( "%s %d (�� %d) -> %s %x", s,i,top,lua_typename(L,tp), lua_tothread(L,tp) ) ;
        break;
//
   default:  // ���-�� ����...
        t_printf( "%s %d (�� %d) -> %s", s,i,top,lua_typename(L,tp) );
        break;
  } // ����� switch
//
 } // ����� for
//
} // --- ����� stackDump -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnClose_F1(TObject *Sender, TCloseAction &Action)
{// ������� �������� ����������
 switch(MessageBox(0, "�� � ����� ���� ������ ��������� ������ ?",
                       "��������������",
                        MB_YESNO | MB_ICONWARNING | MB_TOPMOST))
 {case IDYES: fclose( fptr_protocol ); // ������� ���� ��������� ���������� �������
              Write_Config(); // ��������� ���� ���������
//
              StopLuaScript( Sender ); // ���������� ���������� �������
//
              if( L )
               lua_close( L ); // ������� Lua
//
              if( pTiers )
               free ( pTiers ); // �� ������ ������ ����� ������ �������
//
              if( Mem_Edges )
               free ( Mem_Edges ); // ...
//
              F2->Close(); // ������� F2 - ����� ������ ������
              Action=caFree; // ������ ������ Yes
              break;
  case IDNO:  Action=caNone; // ������ ������ No
              break;
 } //����� ����� SWITCH
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall IncreaseOpsOnTier(INT Tier, INT newSize, INT flag)
{
// --- ����������� ����� ���������� �� ������ � ������� Tiers[][] �� newSize
// --- �� "������" ������� ������ � "�����" ����������� ��� ������ ������ 1-Tier
 char str[_1024], w[_256];
 INT oldOpsOnTier = _maxOpsOnTier; // ��������� "������" �������� _maxOpsOnTier
//
 _maxOpsOnTier = newSize; // _maxOpsOnTier - ���������� (�����) !
//
////////////////////////////////////////////////////////////////////////////////
//
// ����������� (�� newSize) _maxOpsOnTier, � ����� ������ ��������� ��� �� �����
 npTiers = (INT*) calloc( (_maxTiers+1)*(_maxOpsOnTier+1), sizeof(INT) ); // npTiers - ����������!
//
 if( npTiers == NULL ) // ������ ����� - ������ � "����" �����������
  {
   snprintf(str,sizeof(str), "�������� ������ ��� ���������� ������� Tiers[][] (2). ����������� %d x %d = %d ���������...",
                _maxTiers+1, _maxOpsOnTier+1, (_maxTiers+1) * (_maxOpsOnTier+1));
   isTiers = FALSE ; // ������ Tiers[][] �� ������...
   DisplayMessage( "E", __FUNC__, str, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
   MessageBeep( MB_ICONEXCLAMATION ); // �������� ��������������...
   MessageBox(0, str, "��������������", MB_OK | MB_ICONWARNING | MB_TOPMOST);
   return ERR_NOT_MASSIVE_TIERS ;
  }
//
 t_printf( "\n-I- ������ ������ (%d) �������������� �� %d x %d = %d ��������� -I-",
                  flag, _maxTiers+1, _maxOpsOnTier+1, (_maxTiers+1) * (_maxOpsOnTier+1));
//
// --- ���������� (��-�� ������������ ��������� � 1D-������� ��� � 2D-�������) ���������� ������
 for(INT i=0; i<=Tier; i++) // �������� �� ������� � �������� ������� Tiers[][]
  for(INT j=0; j<=oldOpsOnTier; j++) // oldOpsOnTier - "������" _maxOpsOnTier
   npTiers[i*(_maxOpsOnTier+1)+j] = pTiers[i*(oldOpsOnTier+1)+j]; // _maxOpsOnTier - "�����"
//
// --- ������� ��� ר���� ���� - ��������� npEdges � (������������) pEdges...
 free( pTiers ); // ���������� "������" ������ �� ��������� pTiers
 pTiers = npTiers; // ������ pTiers ��������� �� "�����" ������ (������ npTiers)
 npTiers = NULL;
//
 return ( TRUE ); // ��� - ������� ������� ��������..!
//
} //---- ����� IncreaseOpsOnTier------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SaveScriptToCurrentFile(TObject *Sender)
{ // ��������� ������ � ������� ���� ��� ��������
 TED0->SaveToFile( ScriptFileName );
 Write_Config(); // ��������� ���� ������������
} //-------SaveScriptDirect-----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::CloseSpfAtHome(TObject *Sender)
{ // ������� ������� ����
 F1->Close();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall CloseAndRenameFileProtocol()
{
 char newFNP[_512];  // ����� ���������� (��� ����������) ��� ����� ���������
//
 fclose( fptr_protocol ); // ������� ���� ��������� ���������� �������
//
 snprintf(newFNP,sizeof(newFNP), "%s%s%s!%s%s", PathToSubDirOutData, "protocol!",
                                   ExtractFileName(ScriptFileName),
                                   uniqueStr,     ".txt");
 return RenameFile( FileNameProtocol, newFNP ); // ������������� ���� ���������
} // ----- ����� RenameFileNameProtocol ----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::CreateNewScript(TObject *Sender) 
{ // ������ ������ ����� ������
 char str[_1024];
//
// ���� � TR0 ���� ���� ���-�� - �������� � ������������� ���������� ��� ������ ������ �������
 if( TED0->Lines->Count != 0 ) // ���� ��������� �����
  {
   switch(MessageBox(0, "������� ������������ �����. ��������� ���?",
                        "��������������",
                         MB_YESNO | MB_ICONWARNING | MB_TOPMOST))
   {case IDYES: // ������ ������ Yes
//              SD1->InitialDir = ExtractFilePath ( ParamStr(0) ); // ��������� � ������� �������
              SD0->InitialDir = ExtractFilePath ( Application->ExeName ); // ��������� � ������� �������
              if( SD0->Execute() ) // ���� ���-�� �������...
               {
                TED0->SaveToFile( SD0->FileName ); // ��������� ����
// ��������..!  TMS->HistoryList->Add( SD1->FileName ); // ��������� ��� ����� � ������
               }
              break;
    case IDNO:  // ������ ������ No
              break;
   } //����� ����� SWITCH
  } // ����� if
//
 TED0->Clear(); // �������� R0               snprintf(str,sizeof(str), first_F1, PutDateTimeToString(0)); // ��������� ������ Lua
 TED0->Lines->Add( str ); // �������� ������ (� RichEdit �������� '\n')

 IndicateColRowNumberOfEV0(); // ������� ����� ������ � ������� ��� ��������
//
} //----����� CreaneNewScript --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SaveScriptToFile(TObject *Sender)
{ // ��������� ������ � ����
 SD0->InitialDir = ExtractFilePath ( Application->ExeName ); // ��������� � ������� �������
//
 if( SD0->Execute() ) // ���� ���-�� �������...
 {
  TED0->SaveToFile( SD0->FileName ); // ��������� ���������� TED0
  strNcpy( ScriptFileName, SD0->FileName.c_str() ); // ��������� ��� �����
  PutScriptFileName(); // ����� �� �����
 }
//
} //--- ����� SaveFileScript ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OpenFileScript(TObject *Sender)
{ // ��������� ������ �� �����
 OD_Lua->InitialDir = ExtractFilePath ( Application->ExeName ); // ��������� �� �������� ��������
//
 OD_Lua->Files->Clear(); // ������ �������
//
 if( OD_Lua->Execute() ) // ���� ���-�� �������...
 {
  TED0->LoadFromFile( OD_Lua->FileName ); // ��������� ����
  strNcpy( ScriptFileName, OD_Lua->FileName.c_str() ); // ��������� ��� ����� �������
  PutScriptFileName(); // ����� �� �����
  TEV0->SetFocus(); // ����� - �� ���� ��������������
  IndicateColRowNumberOfEV0(); // ������� ����� ������ � ������� ��� ��������
 }
//
} //--- ����� OpenFileScript----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall PutScriptFileName()
{ // ������� ��� ����� ������� �� ������� ����� ��� ����� �������������� �������
 char str[_512];
 snprintf( str,sizeof(str), "���� �������: %s", ScriptFileName );
 F1->L_FNS->Caption = str; // ����� �� �����
} // --- ����� PutScriptFileName -----------------------------------------------


void __fastcall TF1::MouseDown(TObject *Sender, TMouseButton Button,
                               TShiftState Shift, int X, int Y)
{ // ������� ���� �� EV0
 if( TEV0->Focused() ) // ���� EV0 � ������...
  IndicateColRowNumberOfEV0(); // ������� ����� ������ � ������� ��� ��������
}
//--- ����� TF1::MouseDown -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall IndicateColRowNumberOfEV0()
{ // --- ��������� ����� ������ � ����� ������� � ���� ������ � ������� �������
//
 if( !TEV0->Focused() ) // ���� EV0 �� � ������ - ������ �� ������...
  return;
//
 TPoint XYPoint;
 char str[_128];
//
 XYPoint = TEV0->CursorPos; // ������� ��������� �������
//
// --- ��������� "#������/#�������" (��� ���������� � 1) -----------------------
 snprintf(str,sizeof(str), "������:%d �������:%d", XYPoint.y+1, XYPoint.x+1 ); // ���������� �������
 F1->L_RC->Caption = str;
//
} // --- ����� IndicateColRowNumberOfEV0 ---------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall PutDateTimeToString(INT flag)
{ // ������ ������� ���� � ������� � ������ � ���������������
 char str[_512];
//
 if( flag == 0 ) // ������������ ��� ����� ( ������ ':' ���������� )
  strNcpy( str, TDateTime::CurrentDateTime().FormatString("dd.mm.yyyy'/'hh:nn:ss:zzz").c_str() );
 else // ���������� ��� ����� ( ������ ':' ���������� )
  strNcpy( str, TDateTime::CurrentDateTime().FormatString("dd-mm-yyyy'_'hh-nn-ss-zzz").c_str() );
//
 return str ;
} // ����� PutDateTimeToString -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::CopyToNotepad(TObject *Sender)
{ // ���� ����� ��������� � Notepad
 char FileName[_256];
 strNcpy( FileName, ChangeFileExt( ScriptFileName, ".txt" ).c_str() );
//
 TED0->SaveToFile( FileName ); // ������ ��� ������ �� ED0 � ���� FileName
 ShellExecute( F1->Handle, NULL, FileName, NULL, NULL, SW_SHOWNORMAL ); // ������� ���� FileName
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::AboutLua(TObject *Sender)
{ // � ����� Lua � InterNet'�
 ShellExecute( F1->Handle, NULL, "http://ru.wikipedia.org/wiki/Lua", NULL, NULL, SW_SHOWNORMAL );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::AboutLuaDetail(TObject *Sender)
{ // � ����� Lua � InterNet'� ������� ���������
 ShellExecute( F1->Handle, NULL, "http://www.lua.ru/doc/", NULL, NULL, SW_SHOWNORMAL );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::AboutLua53(TObject *Sender)
{ // � ����� Lua ver 5.3 � InterNet'�
 ShellExecute( F1->Handle, NULL, "http://www.lua.org/manual/5.3/", NULL, NULL, SW_SHOWNORMAL );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::GetWebPage(TObject *Sender)
{ // WEB-�������� � ������� SPF@home
 ShellExecute( F1->Handle, NULL, "http://vbakanov.ru/spf@home/spf@home.htm", NULL, NULL, SW_SHOWNORMAL );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::GetUserAPI(TObject *Sender)
{ // �������� ���������� � �������� ����������������� API
 ShellExecute( F1->Handle, NULL, "API_User.pdf", NULL, NULL, SW_SHOWNORMAL );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::AboutAlgoWiki(TObject *Sender)
{ // WEB-�������� ����� AlgoWiki
 ShellExecute( F1->Handle, NULL, "https://algowiki-project.org/ru/", NULL, NULL, SW_SHOWNORMAL );
}
//---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall DisplayMessage( char* Level, char* funcName, char* Text, INT Err )
{ // ���������� ���������
//
 Err ? t_printf( "\n-%s- %s(): %s [err: %d] -%s-", Level, funcName, Text, Err, Level ) :
       t_printf( "\n-%s- %s(): %s -%s-", Level, funcName, Text, Level ) ; 
} // --- ����� DisplayMessage---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Read_Config()
{ // ��������������� ������ � ���� ������������
//
 TIniFile* tINI = new TIniFile(FileNameINI); // ������� ������ ���� TIniIFile
//
 F1->FD0->Font->Name    = tINI->ReadString(RWC.Sect1,  RWC.Sect1_Var1, "Arial"); // ��� �����
 F1->FD0->Font->Size    = tINI->ReadInteger(RWC.Sect1, RWC.Sect1_Var2,      12); // ������ ��������
 F1->FD0->Font->Color   = tINI->ReadInteger(RWC.Sect1, RWC.Sect1_Var3,       0); // ���� ��������
//
 F1->FD0->Font->Charset = tINI->ReadInteger(RWC.Sect1, RWC.Sect1_Var4, 204); // ������� ��������
 F1->FD0->Font->Pitch   = tINI->ReadInteger(RWC.Sect1, RWC.Sect1_Var5,   0); // ����
//
 if( tINI->ReadBool(RWC.Sect1, RWC.Sect1_Var6, 0) == 1 ) // ��������
  F1->FD0->Font->Style = TFontStyles() << fsBold;
//
 if( tINI->ReadBool(RWC.Sect1, RWC.Sect1_Var7, 0) == 1 ) // ������
  F1->FD0->Font->Style = TFontStyles() << fsItalic;
//
 if( tINI->ReadBool(RWC.Sect1, RWC.Sect1_Var8, 0) == 1 ) // �������������
  F1->FD0->Font->Style = TFontStyles() << fsUnderline;
//
 if( tINI->ReadBool(RWC.Sect1, RWC.Sect1_Var9, 0) == 1 ) // ��������������
  F1->FD0->Font->Style = TFontStyles() << fsStrikeOut;
//
 TEV0->Font = F1->FD0->Font; // ��������� ���� RechEdit ��� �������� !!!!!!!!!!!!
//
 F1->Top    = tINI->ReadInteger(RWC.Sect2, RWC.Sect2_Var1,   20); // ��������� � ������� ������� �����
 F1->Left   = tINI->ReadInteger(RWC.Sect2, RWC.Sect2_Var2,   20);
 F1->Width  = tINI->ReadInteger(RWC.Sect2, RWC.Sect2_Var3, minW_F1);
 F1->Height = tINI->ReadInteger(RWC.Sect2, RWC.Sect2_Var4, minH_F1);
//
 partHeightStdout[0] = StrToFloat(tINI->ReadString(RWC.Sect2, RWC.Sect2_Var5, "0.2")); // ������������� ������ ���� stdout
// partHeightStdout[0] = (partHeightStdout[0] > partHeightStdout[2]) ? partHeightStdout[2] : partHeightStdout[0];
// partHeightStdout[0] = (partHeightStdout[0] < partHeightStdout[1]) ? partHeightStdout[1] : partHeightStdout[0];
// ����������� �������� partHeightStdout[0] ����� ������� - � TF1::OnResize_F1 ----
// F1->M0_stdout->Height = F1->PN0->Height * partHeightStdout[0]; // �������� ������ ���� stdout
//
 F2->Top    = tINI->ReadInteger(RWC.Sect3, RWC.Sect3_Var1,      10); // ��������� � ������� �������� �����
 F2->Left   = tINI->ReadInteger(RWC.Sect3, RWC.Sect3_Var2,      10);
 F2->Width  = tINI->ReadInteger(RWC.Sect3, RWC.Sect3_Var3, minW_F2);
 F2->Height = tINI->ReadInteger(RWC.Sect3, RWC.Sect2_Var4, minH_F2);
//
 strNcpy( ScriptFileName, tINI->ReadString(RWC.Sect4, RWC.Sect4_Var1, "noname.lua").c_str()); // ��� ����� �������
//
 TEV0->Gutter->LinesBarBg        = tINI->ReadInteger(RWC.Sect5, RWC.Sect5_Var1, clAqua);
 TEV0->Gutter->LinesBarTextColor = tINI->ReadInteger(RWC.Sect5, RWC.Sect5_Var2, clNavy);
 TEV0->Gutter->FoldsBarBg        = tINI->ReadInteger(RWC.Sect5, RWC.Sect5_Var3, clWhite);
 TEV0->Gutter->FoldsBarLineColor = tINI->ReadInteger(RWC.Sect5, RWC.Sect5_Var4, clBlack);
 TEV0->Gutter->CustomBarBg       = tINI->ReadInteger(RWC.Sect5, RWC.Sect5_Var5, clWhite);
 TEV0->SelectionBg               = tINI->ReadInteger(RWC.Sect5, RWC.Sect5_Var6, clNavy);
 TEV0->SelectionColor            = tINI->ReadInteger(RWC.Sect5, RWC.Sect5_Var7, clYellow);
 TEV0->Color                     = tINI->ReadInteger(RWC.Sect5, RWC.Sect5_Var8, clWhite);
//
 PutParamsTiersOnTextFrame       = tINI->ReadInteger(RWC.Sect3, RWC.Sect3_Var5, 0); // �������� �� ��������� ��� � ��������� �����
 PutParamsDataLiveOnTextFrame    = tINI->ReadInteger(RWC.Sect3, RWC.Sect3_Var6, 0); // �������� �� ��������� ������� ����� ������ � F2
//
 F1->Master_Timer->Interval      = tINI->ReadInteger(RWC.Sect6, RWC.Sect6_Var1, 10); // ������� �������� ������� (����)
//
 delete tINI; // ���������� ������ - ����� �� ����� !...
//
 TEV0->SetFocus(); // ����� - �� ���� ��������������
//
////////////////////////////////////////////////////////////////////////////////
// === �������� ���� ������ � ���������� =======================================
////////////////////////////////////////////////////////////////////////////////
//
// --- ��������� �������� � �������-����� �� �������� �������� -----------------
 if( FileExists( ExtractFileDir(Application->ExeName) + "\\" + AnsiString(ActiveColorScheme) + "." + extSchemes ) ) // ���� ���� �������� ����� ������ ����������...
  TED0->ColorSchemes ->LoadFromDirectory( ExtractFileDir( Application->ExeName ), extSchemes ); // ��������� ��� �����
//
 if( FileExists( ExtractFileDir(Application->ExeName) + "\\" + AnsiString(ActiveColorScheme) + "." + extSchemes ) ) // ���� ���� �������� ����� ���������� ����������...
  TED0->SyntaxSchemes->LoadFromDirectory( ExtractFileDir( Application->ExeName ), extSchemes );  // ��������� ��� �����
//
// F2->L_GraphParams->Caption = ExtractFileDir(Application->ExeName) + "\\" + AnsiString(ActiveColorScheme) + "." + extSchemes ;
// Delay( 5000 );
// F2->L_GraphParams->Caption = ExtractFileDir(Application->ExeName) + "\\" + AnsiString(ActiveSyntaxScheme) + "." + extSchemes ;
//
// --- ������������ ������ ������� ---------------------------------------------
 F1->mnuColorScheme ->Caption = Format("�������� �����: %s[.%s]",   OPENARRAY(TVarRec, (AnsiString(ActiveColorScheme),  extSchemes) ) );
 F1->mnuSyntaxScheme->Caption = Format("C���� ����������: %s[.%s]", OPENARRAY(TVarRec, (AnsiString(ActiveSyntaxScheme), extSchemes) ) );
//
} // ----- ����� Read_Config ----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Write_Config()
{ // ��������� ������ � ���� ������������
//
 TIniFile* tINI = new TIniFile(FileNameINI); // ������� ������ ���� TIniIFile
//
 tINI->WriteString(RWC.Sect1,  RWC.Sect1_Var1, F1->FD0->Font->Name); // ��� �����
 tINI->WriteInteger(RWC.Sect1, RWC.Sect1_Var2, F1->FD0->Font->Size); // ������
 tINI->WriteInteger(RWC.Sect1, RWC.Sect1_Var3, F1->FD0->Font->Color); // ����
//
 tINI->WriteInteger(RWC.Sect1, RWC.Sect1_Var4, F1->FD0->Font->Charset); // ������� ��������
 tINI->WriteInteger(RWC.Sect1, RWC.Sect1_Var5, F1->FD0->Font->Pitch); // ����
//
 tINI->WriteBool(RWC.Sect1, RWC.Sect1_Var6, F1->FD0->Font->Style.Contains(fsBold)); // ��������
 tINI->WriteBool(RWC.Sect1, RWC.Sect1_Var7, F1->FD0->Font->Style.Contains(fsItalic)); // ������
 tINI->WriteBool(RWC.Sect1, RWC.Sect1_Var8, F1->FD0->Font->Style.Contains(fsUnderline)); // �������������
 tINI->WriteBool(RWC.Sect1, RWC.Sect1_Var9, F1->FD0->Font->Style.Contains(fsStrikeOut)); // ��������������
//
 tINI->WriteInteger(RWC.Sect2, RWC.Sect2_Var1, F1->Top); // ��������� ����� �������� ����
 tINI->WriteInteger(RWC.Sect2, RWC.Sect2_Var2, F1->Left);
 tINI->WriteInteger(RWC.Sect2, RWC.Sect2_Var3, F1->Width);
 tINI->WriteInteger(RWC.Sect2, RWC.Sect2_Var4, F1->Height);
//
 DecimalSeparator = '.'; // ����������� ����� � ���������� ������ - �����
 tINI->WriteString(RWC.Sect2, RWC.Sect2_Var5, Format("%1.3f", OPENARRAY(TVarRec, (partHeightStdout[0])) ) );
//
 tINI->WriteInteger(RWC.Sect3, RWC.Sect3_Var1,    F2->Top); // ��������� ����� ��������� ����
 tINI->WriteInteger(RWC.Sect3, RWC.Sect3_Var2,   F2->Left);
 tINI->WriteInteger(RWC.Sect3, RWC.Sect3_Var3,  F2->Width);
 tINI->WriteInteger(RWC.Sect3, RWC.Sect3_Var4, F2->Height);
//
// --- ���� ���� � Lua-����� = �������� ��������, ���� �� ����� (������ ��� �����)
// if( !strcmp( ExtractFileDir(ScriptFileName).c_str(),ExtractFileDir(ParamStr(0)).c_str() ) )
//  strNcpy( ScriptFileName,ExtractFileName(ScriptFileName).c_str() );
//
 tINI->WriteString(RWC.Sect4, RWC.Sect4_Var1, ScriptFileName); // ��� ����� �������
//
// tINI->WriteInteger(RWC.Sect5, "HeigthEd", TEV0->Heigth); // ������ ���� ���������
//
 tINI->WriteInteger(RWC.Sect5, RWC.Sect5_Var1, TEV0->Gutter->LinesBarBg);
 tINI->WriteInteger(RWC.Sect5, RWC.Sect5_Var2, TEV0->Gutter->LinesBarTextColor);
 tINI->WriteInteger(RWC.Sect5, RWC.Sect5_Var3, TEV0->Gutter->FoldsBarBg);
 tINI->WriteInteger(RWC.Sect5, RWC.Sect5_Var4, TEV0->Gutter->FoldsBarLineColor);
 tINI->WriteInteger(RWC.Sect5, RWC.Sect5_Var5, TEV0->Gutter->CustomBarBg);
 tINI->WriteInteger(RWC.Sect5, RWC.Sect5_Var6, TEV0->SelectionBg);
 tINI->WriteInteger(RWC.Sect5, RWC.Sect5_Var7, TEV0->SelectionColor);
 tINI->WriteInteger(RWC.Sect5, RWC.Sect5_Var8, TEV0->Color);
//
 delete tINI; // ���������� ������ - ����� �� ����� !...
//
 MessageBeep( MB_OK ); // �������� ��������������...
//
} // ----- ����� Write_Config -----------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnResize_F1(TObject *Sender)
{ // ����������� ��� ������ ��������� ������� �������� ����
//
// ������ ����� ���������� ������� �������� ���� �����������
 F1->Width  = max( F1->Width,  minW_F1 ); // ����� ������ �������� ���� F1
 F1->Height = max( F1->Height, minH_F1 );
//
// ���������� ���������� ���� F1
//
 PN0->Width  = F1->Width  -  24 ; // ����-��������� ��������� �������
 PN0->Height = F1->Height - 137 ;
//
 PN->Width = PN0->Width; // ������� ����������� ������
//
 M0_stdout->Height = PN0->Height * partHeightStdout[0]; // �������� ������ ���� stdout
//
} //--- ����� OnResize_F1 ------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnCreate_F1(TObject *Sender)
{
 FSearchOptions.Searches.set_length(0);
 FSearchOptions.Options.Clear();
 FSearchOptions.Options << soConfirmReplace;
 FSearchOptions.Direction = sdForward;
 FSearchOptions.ReplaceAllBounds = rbAllText;
 FSearchOptions.Start = ssCursor;
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SelectFont(TObject *Sender)
{ // ����� ������� ������ �����
//
 if( FD0->Execute() )
  {
   TEV0->Font = FD0->Font; // ���� ��������������
   M0_stdout->Font = FD0->Font; // ���� ���� ������ stdout
   F2->M1->Font = FD0->Font; // ���� ���� ���������� ������
// F2->M1->Font->Assign(FD0->Font); // ���� ���� ���������� ������
   TEV0->SetFocus(); // ����� - �� ���� ��������������
   IndicateColRowNumberOfEV0(); // ������� ����� ������ � ������� ��� ��������
   Write_Config(); // ��������� ���������...
  }
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{ // ���������� ��� ������� ������� Key
//
 if( !TEV0->Focused() ) // ���� EV0 �� � ������ - ������ �� ������...
  return;
//
 IndicateColRowNumberOfEV0(); // ������� ����� ������ � ������� ��� ��������
//
} //-----����� TF1::OnKeyUp-----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SelectColorBackGround(TObject *Sender)
{ // ����� ����� ���� ���� �������������� Lua-��������
 CD0->Color = color_BackGround; // �������� ���������� ��������
 if( CD0->Execute() )
 {
  color_BackGround = CD0->Color; // ����� ���� ����
  TEV0->Color = color_BackGround;
  Write_Config(); // ��������...
 }
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::LMD_RD0_Show(TObject *Sender)
{ // ��������� ���� ������� RD1
 SetWindowText( LMD_ERD0->Handle, "��������� ������ � ������ ������ � ��������� Lua");
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::LMD_ERD0_Show(TObject *Sender)
{ // ��������� ���� ������� PD1
 SetWindowText( LMD_ERD0->Handle, "������ ������ �� ��������� Lua");
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::FD0_Show(TObject *Sender)
{ // ��������� ���� ������� FD1 (����� ����� ���� �������������� ������)
 SetWindowText( FD0->Handle, "������� ��������� ������ ����������� ��������� Lua");
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall StartByCommandLine( char* DefScriptFileName )
{ // ������ ���������� � ����������� ��������� ������
 char FileNameProject[_256], // ��� ����� �������
      str[6][_256], w[_256]; // ������� ������
 FILE *fptr; // ��������� �� ����
//
// --- ������� ���� ��������� --------------------------------------------------
 fptr_protocol = fopen( FileNameProtocol, "wt" ); // ��������� � ������ ������ + �����
//
// --- ����������� ���������� ��������� ������ (������������ ��������) ---------
 strNcpy( FileNameProject, ParamStr( 1 ).c_str() ); // ��� ����� ������������
 snprintf( w,sizeof(w), "\n-I- ����� ����� ������ � ��������� �������... -I-\n-I- ��� ����� �������: |%s| -I-",
             FileNameProject );
 tp_printf( w );
//
// --- ����� ������ ������ � ����� ������� -------------------------------------
 if(!(fptr = fopen( FileNameProject, "r")) ) // ������� ��� ������
  {
   tp_printf( "\n-E- ���������� ��������� ���� ������� %s -E-\n-I- ��������� ������ %s -I-\n",
                 FileNameProject, DefScriptFileName );
//
   MessageBeep( MB_OK ); // �������� ��������������...
   Delay( -1 ); // ��� 1 ���
//
   return FALSE;
  }
//
 for( int i=0; i<6; i++ ) // �� ���� 6 ������� FileNameProject
 {
  fgets( str[i], sizeof(str[i]), fptr ); // ������ � ������ str[i]
//
  str[ i ][ strchr(str[i],'\n') - str[i] ] = '\0'; // �������� �� "����� ������" '\0'
//
  t_printf( str[i] );
//
  snprintf ( w,sizeof(w), "\n%s", str[i] );
  p_printf( w ); // ��������� ���� ���������
//
  if( strchr(str[i],';' ) ) // ���� � ������ str[i] ������� ';'
   str[ i ][ strchr(str[i],';') - str[i] ] = '\0'; // �������� ';' "����� ������" '\0'
//
  ReplManySpacesOne( str[i] ); // ������� ������� �������� ������
  DelSpacesTabsAround ( str[i] ); // ������� ������� �������
//
 } // ����� �� 6-�� ������� ������  FileNameProject
//
 fclose( fptr ); // ������� ����
//
 tp_printf( "-I- ����� ����������� ����� ������� %s -I-", FileNameProject );
//
// --- �������� � ������ ��������� ������ Lua-������� --------------------------
 strNcpy( ScriptFileName, str[0] );

 if( !FileExists( ScriptFileName ) ) // ���� �� ����������...
 {
  tp_printf( "\n-E- ��������� � ������� ����� |%s| �� ���������� -E-\n",
              ScriptFileName );
  return FALSE;
 }
//
// --- ������ ���� ��� ��������� ����� -----------------------------------------
 strNcpy( FileNameEdges, str[1] ); // ��������� ��� �����...
//
 if( !FileExists( FileNameEdges ) ) // ���� �� ����������...
 {
  tp_printf( "\n-E- ��������� � ������� ����� |%s| �� ���������� -E-\n",
               FileNameEdges  );
  return FALSE;
 }
//
 c_ReadEdges( FileNameEdges ); // �������� ��������� ���� ���
//
// --- ������ ���� ���������� ���������� ---------------------------------------
 strNcpy( FileNameParamsOps, str[2] );
 c_LoadFileNameParamsOps( FileNameParamsOps );
//
// --- ������ ���� ���������� ������������ -------------------------------------
 strNcpy( FileNameParamsCalcs, str[3] );
 c_LoadFileNameParamsCalcs( FileNameParamsCalcs );
//
// --- ������ ���� ���������� (���) ������ -------------------------------------
 strNcpy( FileNameParamsVertices, str[4] );
 c_LoadFileNameParamsVertices( FileNameParamsVertices );
//
// --- ������ ���� ���������� (���) ��� ----------------------------------------
 strNcpy( FileNameParamsEdges, str[5] );
 c_LoadFileNameParamsEdges( FileNameParamsEdges );
//
 fclose( fptr_protocol ); // ������� ���� ���������... ����� ����� �������!...
//
 return TRUE;
//
} //--- ����� StartByCommandLine -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnShow_F1(TObject *Sender)
{ // ���������� ��� ������ ������� �����
 char str[_512];
//
// -----------------------------------------------------------------------------
 F2->Show(); // �������� ���� ����� F2 � ����������� ������
 F2->L_TMM->Caption = TitleF2; // ��������� ����
// -----------------------------------------------------------------------------
 Read_Config(); // ������ ���� ������.(��������� ����� � ����. ����� Lua-�������)
//
 strNcpy( str, ScriptFileName ); // ��������� ��� ����� ������� �� Config'�
//
// --- ������ ��������� ������ -------------------------------------------------
 if( ParamCount() == 1 ) // �� 1 �������� � ��������� c����� (�� ������ ������� ���� � �����)
 {
  flagCommandLine = StartByCommandLine( str ); //  ������������ ���� �� ��������� str
//
//  flag = TRUE; // ������������� ���������� Lua-������
//
  if( FileExists( ScriptFileName ) ) // ���� ���� ������� ����������...
  {
   PutScriptFileName(); // ����� �� �����
   TED0->LoadFromFile( ScriptFileName );// ��������� � TR0
  } // ����� if FileExists..
 } // ����� if ParamCount...
//
 else
//
 if( FileExists( str ) ) // ���� ���� �� Config'� ����������...
 {
  strNcpy( ScriptFileName, str ); // ������������ ��� ����� �������
  PutScriptFileName(); // ����� �� �����
  TED0->LoadFromFile( ScriptFileName );// ��������� � TR0
 }
 else
 {
  TED0->Clear(); // �������� TR0
  snprintf(str,sizeof(str), first_F1, PutDateTimeToString(0)); // ��������� ������ ���� Lua
  TED0->Lines->Add( str ); // �������� ������
 }
//
 c_ClearDiagrArea(); // �������� ���� ��������� �������
//
 IndicateColRowNumberOfEV0(); // ������� ����� ������ � ������� ��� ��������
////////////////////////////////////////////////////////////////////////////////
//
// --- �������� ���������� ��������� -------------------------------------------
 if( flagCommandLine ) // ������������� ���������� Lua-������
 {
  StartLuaScript( NULL );
//
////////////////////////////////////////////////////////////////////////////////
  fclose( fptr_protocol ); // ������� ���� ��������� ���������� �������
//
  DeleteFile( stdinFileName );  // ��������� ���� Lua-������� ( stdin )
   fclose( fptr_stdout );
  DeleteFile( stdoutFileName ); // stdout
   fclose( fptr_stderr );
  DeleteFile( stderrFileName ); // stderr
//
// --- ����� ��� ������ ���� �������������� ------------------------------------
  F2->Close(); // ������� F2 - ����� ������ ������
//
  F1->OnClose = OnClose_1_F1; // "��������"���������� ������� OnClose_F1 (�������� ����� F1)
//
  F1->Close(); // ���������� F1 - ������� ����
 }
//
} //--- ����� OnShow_F1 --------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnClose_1_F1(TObject *Sender, TCloseAction &Action)
{
 Action = caFree; // ������� ����� F1 ��� ��������
} // ---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::M0_stdout_KeyDown(TObject *Sender, WORD &Key,
                                       TShiftState Shift)
{ // ������� Ctrl+A �� M0_stdout - ��������� ����� ����������� F1->M0_stdout
//
 if( !TM0_stdout->Focused() ) // ����� �� F1->M0_stdout ?
  return;
//
 if( Shift.Contains(ssCtrl) && Key == 0x41 ) // Ctrl+A (���)
  TM0_stdout->SelectAll();
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SelectSColorSheme(TObject *Sender)
{ // ����� �������� �����
 LMD_ECSD0->ColorScheme = ActiveColorScheme ; // ����������� ������ �� ������ � �������� �������� ������
 LMD_ECSD0->Title = Format("�������� �����: %s[.%s]", OPENARRAY(TVarRec, (AnsiString(ActiveColorScheme),extSchemes) ) );
 if( LMD_ECSD0->Execute() ) // ����������� ������ ������ � ������
  {}
 Beep();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SelectSyntaxSheme(TObject *Sender)
{ // �������������� ������� (����� ����������)
 LMD_ESSD0->SyntaxScheme = ActiveSyntaxScheme ; // ����������� ������ �� ������ � �������� ������ ����������
 LMD_ESSD0->Title = Format("����� ����������: %s[.%s]", OPENARRAY(TVarRec, (AnsiString(ActiveSyntaxScheme),extSchemes) ) );
 if( LMD_ESSD0->Execute() ) // ����������� ������ ������ � �����������
  {}
 Beep();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::GotoLineN(TObject *Sender)
{ // ������� � ������ �� ������
 int Line = -1;
 int res = LMDEditAskGoToLine(LMD_EV0->Document->LinesCount, Line);
 if (res == mrOk)
  LMD_EV0->GotoPhysLine(Line);
//
 Beep();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::About_AW(TObject *Sender)
{ // ������� �� ���� AlgoWiki
// ShellExecute(0, NULL, "https://algowiki-project.org/ru/%D0%9E%D1%82%D0%BA%D1%80%D1%8B%D1%82%D0%B0%D1%8F_%D1%8D%D0%BD%D1%86%D0%B8%D0%BA%D0%BB%D0%BE%D0%BF%D0%B5%D0%B4%D0%B8%D1%8F_%D1%81%D0%B2%D0%BE%D0%B9%D1%81%D1%82%D0%B2_%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D0%BE%D0%B2", NULL, NULL,SW_SHOWNORMAL);
 ShellExecute(0, NULL, "https://algowiki-project.org/ru/", NULL, NULL,SW_SHOWNORMAL);
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SPL0Moved(TObject *Sender)
{ // ���������� ��� ����������� ���������
 partHeightStdout[0] = 1.0 * M0_stdout->Height / F1->PN0->Height ; // ���� ������ ���� stdout
//
 if( partHeightStdout[0] > partHeightStdout[2] ) // ������������ ������
 {
  partHeightStdout[0] = partHeightStdout[2];
  M0_stdout->Height = PN0->Height * partHeightStdout[0];
  Beep();
 }
//
 if( partHeightStdout[0] < partHeightStdout[1] ) // ������������ �����
 {
  partHeightStdout[0] = partHeightStdout[1];
  M0_stdout->Height = PN0->Height * partHeightStdout[0];
  Beep();
 }
//
} //----------------------------------------------------------------------------


void __fastcall TF1::OnClickGetLua_01(TObject *Sender)
{ // �������� ���� Lua_01 � �������
 GetFileFromServer( "GeteroCalcs.lua" );
} //----------------------------------------------------------------------------


void __fastcall TF1::OnClickGetEdg_01(TObject *Sender)
{  // �������� ���� Edg_01 � �������
 GetFileFromServer( "e17039_o9853_t199.gv" );
} //----------------------------------------------------------------------------


void __fastcall TF1::OnClickGetEdg_02(TObject *Sender)
{ // �������� ���� Edg_02 � �������
 GetFileFromServer( "e2367_o1397_t137.gv" );
} //----------------------------------------------------------------------------


void __fastcall TF1::OnClickGetRar_01(TObject *Sender)
{ // �������� ��������� ������ SPF@home ( SPF@home.rar )
 GetFileFromServer( "install_spf.exe" );
} //----------------------------------------------------------------------------


void __fastcall GetFileFromServer( char FileName[] )
{ // �������� ���� � HTTP-������� ( FileNameInServer - ������ ��� ����� �� �������,
 char FileNameOnServer[_512], FileNameOnClient[_512]; // ������ ����� ����� �� ������� � �������
//
 TMemoryStream *UnLoadStream = new TMemoryStream;  // ������ ����� ��� ���������� ������������ �� ���� �����
//
// --- ������ ���� � �������� �������� ������ (������� ���� � �����)
 snprintf( PathToSubDirInData,sizeof(PathToSubDirInData), "%s%s\\", ExtractFilePath ( Application->ExeName ), NameSubDirInData);
 if( !DirectoryExists( PathToSubDirInData ) ) // ���� �� ���������� ����� ��������...
  if( !CreateDir( PathToSubDirInData ) ) // ���� �� ������� �������...
   strNcpy( PathToSubDirInData, '\0' ); // �������� ���� � ����������� PathToSubDirOutData
//
 snprintf( FileNameOnClient,sizeof(FileNameOnClient), "%s%s", PathToSubDirInData, FileName ); // ���� ��������� �� ������� (+++)
 snprintf( FileNameOnServer,sizeof(FileNameOnServer), "%s/spf@home/content/%s", MySite, FileName ); // ������ ��� ����� �� ������� (+++)
//
// ShowMessageFmt( "Client: |%s|\n\nServer: |%s|", OPENARRAY(TVarRec, (FileNameOnClient,FileNameOnServer) ) );
//
 F1->INC0->Get( FileNameOnServer, UnLoadStream ); // ����� Get ��������� ���� ����������� ������ UnLoadStream
 UnLoadStream->SaveToFile( FileNameOnClient ); // ��������� ������ � ���� �� �������
//
 delete UnLoadStream; // ����� ����� �� �����...
//
 F1->INC0->Disconnect(); // ��������� ���������e � ��������
//
} //----------------------------------------------------------------------------

void __fastcall TF1::INC0_OnConnected(TObject *Sender)
{ // ���������� ��� ���������� � ��������
 SB0->Text = " ���������� � �������� �����������";
 Delay( 500 );
} //----------------------------------------------------------------------------

void __fastcall TF1::INC0_Disconnected(TObject *Sender)
{ // ���������� ��� ������� ���������� � ��������
 SB0->Text = " ���������� � �������� ���������";
 Delay( 500 );
} //----------------------------------------------------------------------------

void __fastcall TF1::INC0_OnWork(TObject *Sender, TWorkMode AWorkMode, const int AWorkCount)
{ // ���������� ��� �������� ������ � ������� �� ������
 SB0->Text = Format(" %.0f%% (�� %d ����) ������ �������� � �������", OPENARRAY(TVarRec, (100.0*AWorkCount/FileSizeFromServer, int(FileSizeFromServer)) ) );
 Delay( 500 );
} //----------------------------------------------------------------------------

void __fastcall TF1::INC0_OnWorkEnd(TObject *Sender, TWorkMode AWorkMode)
{ // ���������� � ����� �������� ������ � ������� �� ������
 Delay( 500 );
 SB0->Text = Format(" %d ���� �������� � �������", OPENARRAY(TVarRec, (int(FileSizeFromServer)) ) );
} //----------------------------------------------------------------------------

void __fastcall TF1::INC0_OnWorkBegin(TObject *Sender, TWorkMode AWorkMode,
                                      const int AWorkCountMax)
{
 FileSizeFromServer = AWorkCountMax; // ���������
 SB0->Text = Format(" %d ���� ��������� ��� ��������� � �������", OPENARRAY(TVarRec, (AWorkCountMax) ) );
 Delay( 500 );
} //----------------------------------------------------------------------------

void __fastcall TF1::INC0_OnStatus(TObject *axSender,
                                   const TIdStatus axStatus, const AnsiString asStatusText)
{
  switch( axStatus )
  {
   case hsResolving:     //SB0->Text = " A host name is being resolved for an IP address...";
                         SB0->Text = " �������� ��� ������� ��������� � IP-�����...";
        break;
   case hsConnecting:    //SB0->Text = " A connection is being opened...";
                         SB0->Text = " ���������� ���������������...";
        break;
//   case hsConnected:     //SB0->Text = " A connection has been made...";
//                         SB0->Text = " ���������� ������� �����������...";
//        break;
   case hsDisconnecting: //SB0->Text = " The connection is being closed...";
                         SB0->Text = " ���������� �����������...";
        break;
//   case hsDisconnected:  //SB0->Text = " The connection has been closed...";
//                         SB0->Text = " ���������� ���������...";
//        break;
//   case hsText:          //SB0->Text = asStatusText;
//                         SB0->Text = asStatusText;
//        break;
//   default:                //SB0->Text = asStatusText;
//                           SB0->Text = asStatusText;
  }

 Delay( 500 );

} //----------------------------------------------------------------------------

void __fastcall TF1::EndedUploadFile(TObject *Sender)
{ // ������ ���������� � ��������
 F1->INC0->Disconnect(); // ��������� ���������� � ��������
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::CreateUpperSpfBySelectedIgaFile(TObject *Sender)
{ // ��������� ��������� ��� �� �������� ���������� �����
 OD_Edg->InitialDir = ExtractFilePath ( Application->ExeName ); // ��������� �� �������� ��������
//
 OD_Edg->Files->Clear(); // ������ �������
//
 if( !OD_Edg->Execute() ) // ���� ����� ����� �� ��� ������...
 {
  isEdges = FALSE;
  isTiers = FALSE;
  return; // ...�����!
 }
 else
  strNcpy( FileNameEdges, OD_Edg->FileName.c_str() ); // ����� ��� ����� �������� ��������������� �����
//
 if ( c_ReadEdges( FileNameEdges ) == FALSE ) // ���� �� ������� ��������� ������ ��������������� ����� � ������ Mem_Edges[]...
 {
  t_printf( "\n-!- %s(): ���� �������� ��������������� ����� %s ��������� �� ������� -!-", UpperCase(FileNameEdges), __FUNC__ );
  MessageBeep( MB_OK ); // �������� ��������������...
  isEdges = FALSE;
  isTiers = FALSE;
  return ;
 }
//
// ---- ��-��... �� OK.........................................................
//
  c_CreateTiersByEdges( FileNameEdges ); // ���������� ��� � "�������" ������������ ����� � ���� ��������� ������
  c_ClearDiagrArea(); // �������� ����������� ������������� �
  c_DrawDiagrTiers(); // ������ ��� � ����������� ����
//
  c_PutTiersToTextFrame(); // ����� ��� � "�������" ������������ ����� � ���� ��������� ������
  c_PutParamsTiers(); // ����� ���������� ����� � ��� ��� �� ������� ����� � � ���� ���������
//
  isEdges = TRUE;
  isTiers = TRUE;
} //---����� CreateUpperSpfBySelectedIgaFile -----------------------------------

 ////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::CreateBottomSPFClick(TObject *Sender)
{ // ��������� ��������� ��� �� �������� ���������� �����
 OD_Edg->InitialDir = ExtractFilePath ( Application->ExeName ); // ��������� �� �������� ��������
//
 OD_Edg->Files->Clear(); // ������ �������
//
 if( !OD_Edg->Execute() ) // ���� ����� ����� �� ��� ������...
 {
  isEdges = FALSE;
  isTiers = FALSE;
  return; // ...�����!
 }
 else
  strNcpy( FileNameEdges, OD_Edg->FileName.c_str() ); // ����� ��� ����� �������� ��������������� �����
//
 if ( c_ReadEdges( FileNameEdges ) == FALSE ) // ���� �� ������� ��������� ������ ��������������� ����� � ������ Edges[][]...
 {
  t_printf( "\n-!- %s(): ���� �������� ��������������� ����� %s ��������� �� ������� -!-", UpperCase(FileNameEdges), __FUNC__ );
  MessageBeep( MB_OK ); // �������� ��������������...
  isEdges = FALSE;
  isTiers = FALSE;
  return ;
 }
//
// ---- ��-��... �� ����������� ������ �� OK...................................
//
  c_CreateTiersByEdges( FileNameEdges ); // ���������� ��� � "�������" ������������ ����� � ���� ��������� ������
  c_ClearDiagrArea(); // �������� ����������� �������������
  c_DrawDiagrTiers(); // ������ ��� � ����������� ����
//
//==============================================================================
//
  c_CreateTiersByEdges_Bottom( FileNameEdges ); // ���������� ��� � "������" ������������ ����� � ���� ��������� ������
//
  c_ClearDiagrArea(); // �������� ����������� �������������
  c_DrawDiagrTiers(); // ������ ��� � ����������� ����
//
  c_PutTiersToTextFrame(); // ����� ��� � "������" ������������ ����� � ���� ��������� ������
  c_PutParamsTiers(); // ����� ���������� ����� � ��� ��� �� ������� ����� � � ���� ���������
//
  isEdges = TRUE;
  isTiers = TRUE;
//
} //---����� CreateLowerSpfBySelectedIgaFile -----------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::ReadEdgesFileAndPutToTextFrame(TObject *Sender)
{ // �������� ���-����, ������ ��� � Mem_Edges[] � ������� � ��������� ����� ------
 OD_Edg->InitialDir = ExtractFilePath ( Application->ExeName ); // ��������� �� �������� ��������
//
 OD_Edg->Files->Clear(); // ������ �������
//
 if( !OD_Edg->Execute() ) // ���� ����� ����� �� ��� ������...
 {
  isEdges = FALSE;
  isTiers = FALSE;
  return; // ...�����!
 }
 else
  strNcpy( FileNameEdges, OD_Edg->FileName.c_str() ); // ����� ��� ����� �������� ��������������� �����
//
 if ( !c_ReadEdges( FileNameEdges ) ) // ���� �� ������� ��������� ������ ��������������� ����� � ������ Mem_Edges[]...
 {
  t_printf( "\n-!- %s(): ���� �������� ��������������� ����� %s ��������� �� ������� -!-", UpperCase(FileNameEdges), __FUNC__ );
  MessageBeep( MB_OK ); // �������� ��������������...
  isEdges = FALSE;
  isTiers = FALSE;
  return ;
 }
//
 c_PutEdgesToTextFrame(); // ������� ��� � ��������� ���� ----------------------
//
 isEdges = TRUE;
 isTiers = FALSE;
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_CreateTiersByEdges( char* FileName )
{ // ������ (�� ������ ��� �� ����� FileName �������������� (� "�������" �����)
// - ������-������������ ����� (���) ����� � ������� Tiers[][]
// - � ��������� ����� ���������� ���������� � �������������� ����� ���������
 INT iOp, fromOp, toOp, i;
 char str[_2048], w[_256];
//
 if( !c_ReadEdges( FileName ) ) // ������ ���-���� � ������ Mem_Edges[]
 {
  isEdges = FALSE;
  isTiers = FALSE;
//
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 _maxTiers     = _maxTiersPrim; // ������� �������� - ��� Prim
 _maxOpsOnTier = _maxOpsOnTierPrim;
//
 pTiers = (INT*) realloc( pTiers, (_maxTiersPrim+1) * (_maxOpsOnTierPrim+1) * sizeof(INT) ); // �������������� ������ ��� Tiers[][]...
//
 if( pTiers == NULL ) // ������ ����� - ������ � "����" �����������
 {
  snprintf(str,sizeof(str), "�������� ������ ��� ���������� ������� Tiers[][] (Prim). ����������� %d x %d = %d ���������...",
                _maxTiersPrim+1, _maxOpsOnTierPrim+1, (_maxTiersPrim+1) * (_maxOpsOnTierPrim+1));
  isTiers = FALSE ; // ������ Tiers[][] �� ������...
  DisplayMessage( "E", __FUNC__, str, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  MessageBeep( MB_ICONEXCLAMATION ); // �������� ��������������...
  MessageBox(0, str, "��������������", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 snprintf(str,sizeof(str), "������ Tiers[][] (Prim) �������������� �� %d x %d = %d ���������",
               _maxTiersPrim+1, _maxOpsOnTierPrim+1, (_maxTiersPrim+1) * (_maxOpsOnTierPrim+1));
 DisplayMessage( "I", __FUNC__, str, 0 ); // ������ ���������
//
////////////////////////////////////////////////////////////////////////////////
//==============================================================================
////////////////////////////////////////////////////////////////////////////////

// --- � Tiers[0][*] �������� ��������� �������� (��������) ����� --------------
// --- ��� ���������, �� ������� ������ (������ ������) ------------------------
 Tiers(0,0) = 0; // ����� ���������� �������� (��������) �����
//
 for(INT iEdges=1; iEdges<=nEdges; iEdges++) // �� ���� �����
  for(i=0; i<=1; i++) // �� �������� � ��������� ���������� ������ ����
  {
   iOp = Edges(i,iEdges); // ����� ����� ���������
   if( !c_GetCountInEdgesByOp( iOp )  &&  // ���� �������� �� ����� �������� ��� "�"
       !c_IsOpExistOnTier( iOp, 0 ) ) // iOp �� ������������ �� ����� iTier
   {
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( ( Tiers(0,0) + 3 ) >= _maxOpsOnTier ) // �� ��, �� � ������� �������
  if( IncreaseOpsOnTier( 0, _maxOpsOnTier * stockMem, 1 ) == FALSE ) // ������� ����������������� ������
  {
   isTiers = FALSE ; // ������ Tiers[][] �� ������...
   DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
   return ERR_NOT_MASSIVE_TIERS ;
  }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
    Tiers(0,0) ++ ; // ��������� �� 1 ����� ���������� �� ������� (�������) ������
    Tiers(0, Tiers(0,0)) = Edges(i,iEdges); // ��������� ��� � ������� Tiers(0,j)

   } // ����� if
  } // ����� ����� �� i
// ����� ����� �� iEdges -------------------------------------------------------
//
////////////////////////////////////////////////////////////////////////////////
// --- �������� �������� ��������� �� ������ ������� � iTier=1 �� ??? ----------
 for(INT iTier=1; iTier<=_maxTiers; iTier++) // ���� �� �����, ������� ����� ������...
 {
  Tiers(iTier,0) = 0; // (���������) ����� ���������� �� ����� iTier
// �� ����� iTier ����������� ���������, ��������� �� ����� �� ���������� ��
// ����� iTier-1; ���� ���������� ����� Tiers[iTier-1][0] ����
  for(INT j=1; j<=Tiers(iTier-1,0); j++) // �� from-���������� �� ����� iTier-1
  {
   fromOp = Tiers(iTier-1,j); // ����� fromOp ("�� ��������" ����)
// --- ���� � ������ ��� to-��������, �� ���� ��������������� from-��������� ---
   for(INT i=1; i<=nEdges; i++) // �� ���� ����� (������ ����������)
   {
    if( Edges(0,i) == fromOp ) // ������� ���� c from-����������, ��������������� �������
    {
// --- ������� �� toOp=Mem_Edges[i] ��� �� ����� ���� ����������, �� �����������
// --- �� ������ 1 - iTier ? ���� ������� - ����� ��� �� �������� !!!
     toOp = Edges(1,i); // ��� �� ����� ������� fromOp !..
// --- ��� ����� �������� �������� toOp ����� ���� �������� �� ���� iTier ??????
     if( c_IsOpDependOnlyAboveTiers( toOp, iTier ) && /// ���� toOp ������� ������
                 // �� ���������� �� ����������� ������ (����. ������ iTier) "�"
        !c_IsOpExistOnTier( toOp, iTier ) ) // Op �� ������������ �� ����� iTier
     {
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( ( Tiers(iTier,0)+1 ) >= _maxOpsOnTier ) // �� ���������� � _maxOpsOnTier...
  if( IncreaseOpsOnTier( iTier, _maxOpsOnTier * stockMem, 11 ) == FALSE ) // ������� ����������������� ������
  {
   isTiers = FALSE ; // ������ Tiers[][] �� ������...
   DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
   return ERR_NOT_MASSIVE_TIERS ;
  }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// --- �� ����������� - ����� ���������� �������� ��� � ����� pTiers ----------
      Tiers(iTier,0) ++ ; // �� ������, ����� ����������� �� 1 ����� ���������� �� ����� iTier...
      Tiers(iTier, Tiers(iTier,0) ) = toOp; // � Tiers[iTier][*] ��������������� toOp
     } // ����� if (  Is... / Is... )
    } // ����� if( Mem_Edges[0][i] == fromOp )
   } // ����� ����� �� i (������ ���)
// -----------------------------------------------------------------------------
  } // ����� ����� �� j (����� ���������� �� ����� iTier-1)
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// --- �����������, ����������� �� ����� ��� -----------------------------------
  if( ( Tiers(iTier,0) != 0 ) && // ���� �� ����� iTier ���� ���������...
      ( (iTier+1) >= _maxTiers ) ) // � ������ ������� Tiers[][] �������������...
  {
// --- ����������� _maxTiers, � _maxOpsInTier ��������� ��� �� ����� -----------
// --- � ���� ������ ����� ������������ realloc, �������������� ����������� ������
   _maxTiers *= stockMem; // ����� ����� ����� � ������� stockMem
//
   pTiers = (INT*) realloc( pTiers,  (_maxTiers+1) * (_maxOpsOnTier+1) * sizeof(INT) ); // ������ ������ ��� ����� ������
//
   if( pTiers == NULL ) // ������ ����� - ������ � "����" �����������
   {
    snprintf(str,sizeof(str), "�������� ������ ��� ���������� ������� Tiers[][] (2). ����������� %d x %d = %d ���������...",
                 _maxTiers+1, _maxOpsOnTier+1, (_maxTiers+1) * (_maxOpsOnTier+1));
    isTiers = FALSE ; // ������ Tiers[][] �� ������...
    DisplayMessage( "E", __FUNC__, str, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
    MessageBeep( MB_ICONEXCLAMATION ); // �������� ��������������...
    MessageBox(0, str, "��������������", MB_OK | MB_ICONWARNING | MB_TOPMOST);
    return ERR_NOT_MASSIVE_TIERS ;
   } // ����� if ( npTiers == NULL )
//
   snprintf(str,sizeof(str), "������ Tiers[][] (2) �������������� �� %d x %d = %d ���������",
                 _maxTiers+1, _maxOpsOnTier+1, (_maxTiers+1) * (_maxOpsOnTier+1));
   DisplayMessage( "E", __FUNC__, str, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  }  // ����� if ( Tiers(iTier,0) != 0 && ...
//
// --- �� ����������� - ����� ���������� �������� ��� � ����� pTiers ----------
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
  if( Tiers(iTier,0) == 0 ) // �� ������� �� ������ to-��������� �� ����� iTier
  {
   nTiers = iTier - 1 ; // ��������� ����� ������
   break; // �� ���� ����� ��� to-����������... ����� ���������... ������������� �� �����!
  } // ��������� iTier-1
////////////////////////////////////////////////////////////////////////////////
//
 } // ����� ����� �� iTier (������ ���) ========================================
//
////////////////////////////////////////////////////////////////////////////////
  nOps = 0; // ����� ����� ���������� ��� ������� (����������)
// --- ��������� c�������� ���������� ���������� (��������� �� ������ ���) -----
 for(INT iTier=1; iTier<=nTiers; iTier++) // �� ����� ������ ��� ����� �������� (��������)
  nOps += Tiers(iTier,0);
//
////////////////////////////////////////////////////////////////////////////////
//
 isTiers = TRUE ; // ������� ����, ��� ��� ���������
//
 TestExistInOutAtAllOps(); // ������������ ������ � �������
//
 nOpsInput  = Tiers( 0, 0 ); // ����� ������� ������ (����������)
 nOpsOutput = Tiers( nTiers, 0 ); // ����� �������� ������ (����������)
//
 t_printf( "\n-I- %s(): ��� ����� � \"�������\" ������������ ����� �� ����� %s ������� ��������� -I-", __FUNC__, FileNameEdges );
//
 isTiers = TRUE ; // ������ Tiers[][] �����������..!
//
 return TRUE ; // �� ��������� - ������ Tiers[][] � "�������" ������������ ����� ��������
//
} // --- ����� c_CreateTiersByEdges---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_CreateTiersByEdges_Bottom( char* FileName )
{ // ������ (�� ������ ��� �� ����� FileName  �������������� (� "������" ������������ �����)
// - ������-������������ ����� (���) ����� � ������� Tiers[][]
// - ��������� ����� ���������� ���������� � �������������� ����� ���������
// - ������������ ������������ "������" ����� ��� (������� ������������� �������� ���� ���������� "�����")
 UINT iTier, jOp, Op, errCount=0;
//
////////////////////////////////////////////////////////////////////////////////
//
 if( !c_CreateTiersByEdges( FileName ) ) // ������ ���-���� � ������ ��� � "�������" ������������ �����
  return FALSE ; // �� �������..!
//
 for( iTier=nTiers; iTier>=1; iTier-- ) // �� ������ ��� ����� �����
  for( jOp=Tiers( iTier,0 ); jOp>=1; jOp--) // �� ���������� �� ����� iTier ������ ������
  {
   Op = c_GetOpByNumbOnTier( jOp, iTier ); // ���������� ����� ���������
   c_MoveOpTierToTier( Op, c_GetMaxTierMaybeOp( Op ) ); // ��������� �������� Op "����" �� ���������..!
  }
//
 t_printf( "-I- %s(): ��� ����� � \"������\" ����� �� \"�������\" ����� ���� �� ����� ������� ��������� -I-", __FUNC__ );
//
// --- ����������� "������" ����� ��� ------------------------------------------
//
 for( iTier=1; iTier<=nTiers; iTier++ ) // �� ������ ��� ������ ����
  for( jOp=1; jOp<=Tiers( iTier,0 ); jOp++) // �� ���������� �� ����� iTier ����� �������
   {
    Op = c_GetOpByNumbOnTier( jOp, iTier ); // ���������� ����� ���������
    if( iTier != c_GetMaxTierMaybeOp( Op ) ) // �������� Op �� �� ����� ������ �����..!
     errCount ++; // ����� ���������������
   }
//
 if( !errCount ) // ��� ���������������...
  t_printf( "\n-I- %s(): ��� ����� � \"������\" ����� ������� �������������� -I-", __FUNC__ );
 else // ���-�� �� ��..!
  t_printf( "\n-E- %s(): ��� ����� � \"������\" ����� �� ������ ������������� [%d] -E-", __FUNC__ , errCount );
//
 isTiers = TRUE ; // ������ Tiers[][] �����������..!
//
 return TRUE ; // �� ��������� - ������ Tiers[][] � "������" ������������ ����� ��������
//
} // --- ����� c_CreateTiersByEdges_Bottom--------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::PutParamsByOp(TObject *Sender)
{ // ������ � ��������� ���� ��������� ��������� ���������
 char str[_1024], tmp[_256];
 INT Op, i, Tier;
 bool flag;
//
 if( !isTiers ) // ��� ������� Tiers[][]
 {
  MessageBeep( MB_ICONASTERISK );
  return;
 }
//
retry:
//
 strNcpy( str, IntToStr(c_GetOpByNumbOnTier(1,1)).c_str() ); // ���������: 1-� �������� 1-�� �����
 AnsiString defStr = AnsiString( str ); // ��� ������� ��������� InputQuery ���� ���� AnsiString..!
//
 flag = InputQuery( "��������� ������ �� ���������", "������� ����� ��������� � ������ ���", defStr );
//
 if( !flag ) // �� ���� ������ Ok...
 {
  MessageBeep( MB_ICONASTERISK );
  return;
 }
//
 if( sscanf( defStr.c_str(), "%d", &Op ) != 1 ) // ���� ������������ �������������� ������ � �����...
 {
  MessageBeep( MB_ICONASTERISK );
  goto retry;
 }
//
 if( c_GetTierByOp(Op) == ERR_COMMON ) // ��������� � ����� ������� � ��� �� ����������..!
 {
  MessageBeep( MB_ICONHAND );
  goto retry;
 }
//
 Tier = c_GetTierByOp(Op); // �������� Op ��������� �� ����� Tier
 t_printf( "\n��������� ��������� %d/%d (#����/#����) ��� ������ ���:", Op, Tier );
////////////////////////////////////////////////////////////////////////////////
 strNcpy( str, "" ); // ������� ������
 for( i=1; i<=c_GetCountInEdgesByOp(Op); i++ ) // ���� �� ���� �������� ����� ������� ���������
 {
  snprintf( tmp,sizeof(str), " %d/%d", c_GetNumbInEdgeByOp(i,Op), c_GetTierByOp(c_GetNumbInEdgeByOp(i,Op)) ); // ��������/����
  strcat( str, tmp ); // ��������� �� ������� ��������� ���������..
 }
//
 if( !Tier ) // ������� (�������) ����
  t_printf( "1. �������� %d ����������� �������� (��������) �����", Op );
 else
  t_printf( "1. �������� %d ������� �� %d ���������/��: %s", Op, c_GetCountInEdgesByOp(Op), str );
////////////////////////////////////////////////////////////////////////////////
 strNcpy( str, "" ); // ������� ������
 for( i=1; i<=c_GetCountOutEdgesByOp(Op); i++ ) // ���� �� ���� ��������� ����� ������� ���������
 {
  snprintf( tmp,sizeof(str), " %d/%d", c_GetNumbOutEdgeByOp(i,Op), c_GetTierByOp(c_GetNumbOutEdgeByOp(i,Op)) ); // ��������/����
  strcat( str, tmp ); // ��������� �� ������� ���������� ���������..
 }
//
 if( Tier == nTiers ) // �������� ����
  t_printf( "2. �������� %d ����������� ��������� �����", Op );
 else
  t_printf( "2. �� ��������� %d ������� %d ��������/��: %s", Op, c_GetCountOutEdgesByOp(Op), str );
////////////////////////////////////////////////////////////////////////////////
 if( !Tier ) // ������� (�������) ����
  t_printf( "3. �������� %d ����� ������������� ������ �� ������� (�������) �����", Op);
 else
  t_printf( "3. �������� %d ����� ������������� �� ������ �� %d �� %d (������������)", Op, c_GetMinTierMaybeOp(Op), c_GetMaxTierMaybeOp(Op) );
//
 for( i=1; i<=nEdges; i++ ) // �� ���� ����� ��� (���������� ��� ���������� � 1)
  if( Edges(0,i) == Op ) // ���� ��������� ������� ���� ����� Op...
  {
   strcpy( str,Mem_Edges[ i ].Operators ); // ����������� � str ������ �� ������ ��� ���
   break;
  }
//
 if( !Tier ) // ������� (�������) ����
  t_printf( "4. �����������(*): %s", str );
 else
  t_printf( "4. �����������(*): %s\n", str );
//
} // ----- PutPatamsByOp -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::StartLuaScript(TObject *Sender)
{ // ������ ���������� Lua-������� �� LMD_EV0
//
 Set_FileNames_All_Protocols(); // ����������� ����� ���� ������ ���������� (��� Out!Data)
//
 TED0->SaveToFile(ScriptFileName); // ��������� ������ � ������� ���� ��� �������� (��� ������� ����...)
//
 ticks = 0; // �������� ���������� ������� �����
//
 max_Events = _128; // ��������� ������ ������� Mem_EV
 Mem_EV = (ev*) realloc( Mem_EV, max_Events*sizeof(ev) ); // ������ �������
 i_Events = -1; // ������ ��������� � ������� ������� (������ ��������� ����� ����� ����������� ������ � ������ Mem_EV[])
 Master_Timer-> Enabled = TRUE; // ��������� Master_Timer
 flag_Busy = FALSE; // ����� Lua �� ������� ��������
//
 Write_Config(); // ��������� ���� ������������
//
 if( luaExecute ) // Lua � ������ ������ ��� ����������� !!!!!!!!!!!!!!!!!!!!!!!
  return;
//
 luaExecute = TRUE; // ������ Lua ����������� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
 c_ClearTextFrame(); // �������� ��������� �����
 c_ClearDiagrArea(); // �������� �������
//
 F2->L_GP->Caption = ""; // �������� ������ ���������� �����
 SetActiveWindow( F2->Handle ); // �������� ���� F2 ��������� �� �������� ����
//
 t_printf( first_F2, PutDateTimeToString(0) ); // ������ � ��������� �����
 MessageBeep( MB_ICONASTERISK );
//
// =============================================================================
 flagHook = FALSE; // "�������" ���������
////////////////////////////////////////////////////////////////////////////////
//*
 RunLuaScript(); // ������ Lua-������� �� ���������� � �������� ������
//
// Copy_Stdout_To_Memo(); // ���������� stdout �� Memo
//
 return;
//
} //----����� StartLuaScript----------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::StopLuaScript(TObject *Sender)
{ // ���������� ���������� �������
//
 if( !luaExecute ) // � ������ ������ Lua �� �����������
  return;
 else
 {
  flagHook = TRUE; // "������" ���� ��� ��� ������������ �������
//  t_printf( "\n--->%d %d [%d] (%s)", luaExecute, flagHook, lua_gethookcount(L), __FUNc__);
 }
//
} //----����� StopLuaScript-----------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
static void LuaHook( lua_State *L, lua_Debug *ar )
{ // ������� ��������� ���������� � Lua
//
// F1->L_RC->Font->Color = clNavy;
// F1->L_RC->Repaint();
// Delay( 1 );
// F1->L_RC->Font->Color = clBlack;
// t_printf( "\n===>%d %d [%d] (%s)", luaExecute, flagHook, lua_gethookcount(L), __FUNc__);
// F2->L_OM->Caption = "|";
// F2->L_OM->Repaint();
// F2->L_OM->Caption = "=";
// F2->L_OM->Repaint();
//
 if( !luaExecute || !flagHook ) // Lua �� ����������� ��� ���� Hook �������....
  return;
//
 char str[_512];
 snprintf( str,sizeof(str), "\n%s: - ����� ������ �� ������� ���������� ������� (%s) -",
                PutDateTimeToString(0), __FUNC__ );
 tp_printf( str ); // ������ ������ � ��������� ���� � � ���� ���������
//
// ---- ����� luaL_error �� �������� � ����������� �������� ���������� Lua-�������,
// ---- ����� ����������� ����� 2 �������� �� pcall ����� ��������� ���������� �������
 luaL_error( L, "���������� Lua ����������� �������������..." ); // ����� ������...
//
 do_tStart_fStop // �������������� ������ Stop, ������������ ������ Start
 do_HandRule_Enabled // ������������ �������� "������� ����������" � ������� ����
//
 flagHook = FALSE;
//
 return;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
/* ----- �� ���������� ���� ----------------------------------------------------
  tp_printf( "\n-!- ���������� Lua ����������� ������������� (%s) -!-\n", __FUNC__ );
//
////////////////////////////////////////////////////////////////////////////////
  t_printf( "event = %d\n", ar->event );
//
  switch( ar->event )
  {
   case LUA_HOOKCALL: // ���� ����� ����������� �� ����� �������
   case LUA_HOOKRET:
   case LUA_HOOKLINE:
   case LUA_HOOKCOUNT:
//
        lua_getinfo( L, "n", ar );
        t_printf( "name: |%s|", ar->name );
        t_printf( "namewhat: |%s|", ar->namewhat );
//
        lua_getinfo( L, ">S", ar );
        t_printf( "what: |%s|", ar->what );
        t_printf( "source: |%s|", ar->source );
        t_printf( "linedefined: |%d|", ar->linedefined );
        t_printf( "lastlinedefined: |%d|", ar->lastlinedefined );
        t_printf( "short_src: |%s|", ar->short_src );
//
        lua_getinfo( L, "l", ar );
        t_printf( "currentline: |%d|", ar->currentline );
//
        lua_getinfo( L, "u", ar );
        t_printf( "nups: |%d|", ar->nups );
        t_printf( "nparams: |%d|", ar->nparams );
        t_printf( "isvararg: |%d|", ar->isvararg );
//
        lua_getinfo( L, "t", ar );
        t_printf( "istailcall: |%d|", ar->istailcall );
//
        break;

   default: break;
  } // ����� switch
//
  t_printf( "\nLua: ������� � ������ %s(): ������: %s: ��� �������: |%s| |%s|",
                    ar->name, ar->short_src, ar->namewhat, ar->what );
//
  flagHook = FALSE; // ��������� "�������" -------------------------------------
//
//  FinishLuaSession(); // ��������� Lua-������ ����� ���������� -----------------
//
  do_tStart_fStop // �������������� ������ Stop, ������������ ������ Start
  do_HandRule_Enabled // ������������ �������� "������� ����������" � ������� ����
//
  MessageBeep( MB_ICONASTERISK );
//
  return;
*/
} // ------ ����� LuaHook-������� ----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall RunLuaScript()
{ // ��������� Lua-������� -----------------------------------------------------
 char *sf = "\n�������� � %s. ���������� �������� ������� Lua �����������... (%s)\n��������� ������������ ����� ��������� ������ Lua...";
 char str[_512], sError[_512];
 int error1=0, error2=0;
//
 if( !L ) // ���� ����������� ���������� Lua ��� �� �������...
 {
  if( !(L = luaL_newstate() ) ) // ������� �������� ���������� Lua
  {
   tpe_printf( sf, "luaL_newstate()", __FUNC__ );
   goto label_StopSessionLua;
  }
  luaL_openlibs( L ); // ��������� ����������� ����������
  RegisterFunctions( L ); // ������������ �-������� � Lua � ���������� L
 }
//
 lua_gc( L, LUA_GCCOLLECT, 0 ); // ������� ������
//
 luaExecute = TRUE; // ������ Lua �����������...
//
 F1->actBreakDeleteAllExecute( 0 ); // �������� ��� ����� Breakpoints
//
// lua_atpanic( L, luaPanic ); // ��������� luaPanic ��� ������� ������ ��� ������ L
// t_printf( "-->%d", out ); // �������� � ���� ���������
// lua_sethook( L, LuaHook, 0, 0 ); // ����� �������-"�������"
 lua_sethook( L, LuaHook, LUA_MASKCALL | LUA_MASKRET | LUA_MASKLINE | LUA_MASKCOUNT, HOOK_COUNT ); // ��������� �������-"�������" �� hookCount ������� ���������� Lua
//
 do_fStart_tStop // �������������� ������ Start, ������������ ������ Stop
 do_HandRule_Disabled // �������������� �������� "������� ����������" � ������� ����
//
////////////////////////////////////////////////////////////////////////////////
 F1->M0_stdout->Lines->Clear(); // �������� TM0_Bot
//==============================================================================
 fptr_protocol = fopen( FileNameProtocol, "wt" ); // ��������� � ������ ��������, ������, �����
// if( fptr_protocol )
//  setbuf( fptr_protocol, NULL ); // ������ ������������
//
 fptr_stdout = fopen( stdoutFileName, "wt" ); // stdout ��������������� ��������� (_IOLBF)
// if( fptr_stdout )
//  setbuf( fptr_stdout, NULL );
//
 fptr_stderr = fopen( stderrFileName, "wt" ); // stderr ������� �� ��������������� (_IONBF)
// if( fptr_stderr )
//  setbuf( fptr_stderr, NULL );
//
 freopen( stdoutFileName, "wt", stdout ); // ������������� stdout � ���� stdoutFileName
 freopen( stderrFileName, "wt", stderr ); // ������������� stderr � ���� stderrFileName
//==============================================================================
// --- ������� ������ �� ��������� Lua � ���� stdinFileName --------------------
 TED0->SaveToFile( stdinFileName );
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
 i_env_StopSessionLua = setjmp( env_StopSessionLua ); // ���������� ����� �������� !!!!!!!!!!!
 if( i_env_StopSessionLua ) // �� ���� - ������, ���� ��� ������ !!!!!!!!!!!!!!!!!!!!!!
  goto label_StopSessionLua;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// LuaStackGuard stackGuard( L );
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// error1 = luaL_loadfile( L, stdinFileName ); // ��������� Lua-���� � �������������
 try
 {
  error1 = luaL_loadfile( L, ScriptFileName ); // ��������� Lua-���� � �������������
 } // ����� try
 catch( ... )
 {
  tpe_printf( sf, "luaL_loadfile()", __FUNC__ );
  goto label_StopSessionLua;
 } // ����� cath( ... )
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
 stackDump( L , "\nstackDump (��������� ����� 1): " );
//==============================================================================
 try
 {
  error2 = lua_pcall_Debug( L, 0, 0 ); // lua_pcall + debug
 } // ����� try
 catch( ... ) // ����� ����� ����������
 {
  tpe_printf( sf, "lua_pcall_Debug()", __FUNC__ );
  goto label_StopSessionLua;
 } // ����� cath( ... )
//==============================================================================
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
 stackDump( L , "\nstackDump (��������� ����� 2): " );
////////////////////////////////////////////////////////////////////////////////
//
 luaExecute = FALSE; // Lua �������� ���������� (� �������� �� ��� - ��� �������)
//
 stackDump( L , "\nstackDump (��������� ����� 3): " );
// ----- �������, ��������� ���� ������� �� ����������, ��� �������� ����
// ----- ������ ������ ���������� ������ pcall (���������� lua_pcall_Debug)
 if( error1 || error2 ) // ������ luaL_dofile(L,InLuaFileName) = lua_loadfile + lua_pcall
 {
  strNcpy( sError, lua_tostring(L,-1) ); // ����������� ����� ������ �� ����� Lua
  lua_pop( L, 1 ); // ������� ��������� �� ������ �� �����
//
  snprintf( str,sizeof(str), "\n%s: ���������� Lua-������� ����������� [err: %d|%d] (%s):\n",
                 PutDateTimeToString(0), error1, error2, __FUNC__ );
//
  tpe_printf( str ); // ������� � ��������� ����, � ���� ��������� � stderr
//
  MessageBeep( MB_ICONEXCLAMATION ); // �������� ��������������...
//
 } // ����� ��������� if error1 || error2 ======================================
//
label_StopSessionLua: // ���� ��������� �� longjmp --------------------------------
//
 F1->Master_Timer->Enabled = FALSE; // ���������� Master_Timer
////////////////////////////////////////////////////////////////////////////////
 luaExecute = FALSE; // Lua �������� ���������� (� �������� �� ��� - ��� �������)
////////////////////////////////////////////////////////////////////////////////
 lua_sethook( L, LuaHook, 0, 0 ); // ��������� hook
////////////////////////////////////////////////////////////////////////////////
//
 do_tStart_fStop // �������������� ������ Stop, ������������ ������ Start
 do_HandRule_Enabled // ������������ �������� "������� ����������" � ������� ����
//
////////////////////////////////////////////////////////////////////////////////
//
 fclose( fptr_stdout ); // ������� stdout
 fclose( fptr_stderr ); // ������� stderr
//
// --- ������ stdout - � ��������� ���� � � ���� ��������� ---------------------
 p_printf( "\n===> ������ stdout ���������� ������� %s ===>\n", ScriptFileName ); // �������� � ���� ���������
//------------------------------------------------------------------------------
//
 TM0_stdout->Clear(); // �������� TM0_stdout
//
// stdoutToMemo();
//
 fptr_stdout = fopen( stdoutFileName, "rt" ); // ������� ��� ������...
//
 TM0_stdout->Lines->BeginUpdate(); // ������ ��������� (Update) TM0_stdout ��� ������������
//
 while( 1 ) // ...������ �� ��������� ������...
 {
  if( fgets( str, sizeof(str), fptr_stdout ) != NULL ) // ���� ���� ��� ������ � stdout
  {
   TM0_stdout->Lines->Add( str ); // �������� � ���� stdout (��������� TM0_stdout)
   p_printf( str ); // �������� � ���� ���������
  }
  else
   break;
 } // ����� while( 1 )
//
 TM0_stdout->Lines->EndUpdate(); // ��������� ����� ��������� (Update) TM0_stdout ��� ������������
 SendMessage(TM0_stdout->Handle,EM_LINESCROLL,0,TM0_stdout->Lines->Count); // ���������� ������ �� ��������� ������
//
 fclose( fptr_stdout ); // ������� ���� stdout
//
 p_printf( "<=== �����  stdout ���������� ������� %s <===\n", ScriptFileName ); // �������� � ���� ���������
//------------------------------------------------------------------------------
 p_printf( "\n===> ������ stderr ���������� ������� %s ===>\n", ScriptFileName ); // �������� � ���� ���������
//------------------------------------------------------------------------------
//
 fptr_stderr = fopen( stderrFileName, "rt" ); // ������� ��� ������...
 while( 1 ) // ...������ �� ��������� ������...
 {
  if( fgets( str, sizeof(str), fptr_stderr ) != NULL ) // ���� ���� ��� ������ � stderr
   p_printf( str ); // �������� � ���� ���������
  else
   break;
 } // ����� while( 1 )
 fclose( fptr_stderr ); // ������� ���� stdout
//
 p_printf( "<=== �����  stderr ���������� ������� %s <===\n", ScriptFileName ); // �������� � ���� ���������
////////////////////////////////////////////////////////////////////////////////
//
 CloseAndRenameFileProtocol(); // ������������� ��� ����� ���������
//
////////////////////////////////////////////////////////////////////////////////
//
 lua_close( L ); // ���� �� ���������, ����� 1-�� ������������ errorHandler
 L = NULL; // HOOK-������� ����� �� ����������� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
////////////////////////////////////////////////////////////////////////////////
 return TRUE ; // �� ���������...
//
} //===== ����� RunLuaScript ===================================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
static int errorHandler(lua_State* L)
{ // ������� - ���������� ������ ������� ������ debug.traceback
  char str[_1024];
//
  lua_getglobal(L, "debug"); // stack: err, debug
  lua_getfield(L, -1, "traceback"); // stack: err, debug, debug.traceback
//
  if( lua_pcall(L, 0, 1, 0) ) // debug.traceback() ���������� ���� ��������
   snprintf( str,sizeof(str), "\n%s: (%s):\nError in debug.traceback() call: %s\n",
            PutDateTimeToString(0), __FUNC__, lua_tostring(L, -1) );
  else // ���������� ����������� �����
   snprintf( str,sizeof(str), "\n%s: (%s):\nC++ stack traceback: %s\n",
            PutDateTimeToString(0), __FUNC__, lua_tostring(L, -1) );
//
  tp_printf( str ); // �������� � ��������� ���� � � ��������
//
// ����� ����� �������� � ��������� ��������� Lua !! �� ���������� (str ��������!) !!
  ShowBreakpoint( str );
//
  longjmp( env_StopSessionLua, 1 ); // ����������� ������� � ����� setjmp !!!!!!!!!!!!!!
//
// ----- ��� RETURN ���������� Lua ������������ --------------------------------
//
} // --- ����� errorHandler ----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int __fastcall lua_pcall_Debug( lua_State* L, int args, int results )
{ // ���������� ������� Lua ( args - ����� ������� ����������, results - �������� )
// in start: stack: func, arg1, arg2, ,,, argn (func �������� �� ���� luaL_loadfile)
  lua_pushcfunction( L, errorHandler ); // stack: func, arg1, arg2, ,,, argn, errorHandler
//
  int errorHandlerIndex = - ( args + 2 );
//
  lua_insert( L, errorHandlerIndex ); // stack: errorHandler, func, arg1, arg2, ,,, argn
//
  stackDump( L , "\nstackDump (��������� ����� 3): " );
//
  int res = lua_pcall( L, args, results, errorHandlerIndex );
//
  if( res )
   results = 1; // if error, only one result is placed on stack (instead of N results)
//
  lua_remove( L, -results - 1 ); // remove function errorHandler from stack
//
  return res ;
//
} // ----- ����� pcall_lua_Debug -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall ShowBreakpoint( char *err )
{ // �������� ����� �������� (Breakpoint) � ��������� ��������� Lua
 int line = -13;
//
 char *p = strstr( err, ScriptFileName ); // � str ���� ������ ��������� ScriptFileName
 if( p ) // ���� ����� ��������� ScriptFileName...
 {
  *p = NULL; // ��������� �� ������� ������
  p += strlen( ScriptFileName ); // ������ p ��������� �� ������ ������ � stackTrace ����� ��������� ScriptFileName
  if( sscanf( p, ":%d:", &line ) == 1 ) // ���� ������� ��������� ��������� ����� ������...
  {
   F1->LMD_EV0->GotoPhysLine( line-1 ); // ������� � ������ �� � ������ (��������� � 0 ��� 1)
   IndicateColRowNumberOfEV0(); // ������������ ��������� ������� � ������� ����� ���� �������������� ��������
   F1->actBreakSetExecute( 0 ); // � ��������� ���� ������� ����� �������� (BreakPoint)
   Beep();
  } // ����� if( sscanf...
//
 } // ����� if( p )
} // ----- ����� ShowBreakpoint ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall stdoutToMemo()
{
  SECURITY_ATTRIBUTES sa;
  ZeroMemory(&sa,sizeof(SECURITY_ATTRIBUTES));
  sa.nLength=sizeof(SECURITY_ATTRIBUTES);
  sa.bInheritHandle=true;
  sa.lpSecurityDescriptor=NULL;
  HANDLE ReadPipeHandle;
  HANDLE WritePipeHandle;       // not used here
  if( !CreatePipe(&ReadPipeHandle,&WritePipeHandle,&sa,0) ) //create pipe for the console stdout
   RaiseLastWin32Error();
//
  STARTUPINFO si;
  ZeroMemory(&si,sizeof(STARTUPINFO));
  si.cb=sizeof(STARTUPINFO);
  si.dwFlags=STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;
  si.wShowWindow=SW_HIDE;
  si.hStdOutput=WritePipeHandle;
  si.hStdError=WritePipeHandle;
//
  PROCESS_INFORMATION pi;
  ZeroMemory(&pi,sizeof(PROCESS_INFORMATION));
  if( !CreateProcess("spf_client.exe",NULL,NULL,NULL,true,0,NULL,NULL,&si,&pi) ) // create a console
   RaiseLastWin32Error();
//
  char Data[1024];
  for (;;) // read from pipe
  {
   DWORD BytesRead;
   DWORD TotalBytes;
   DWORD BytesLeft;
//
   if(!PeekNamedPipe(ReadPipeHandle,Data,sizeof(Data),&BytesRead, // check for the presence of data in the pipe
                     &TotalBytes,&BytesLeft))RaiseLastWin32Error();
//
   if(BytesRead) // if there is bytes, read them
   {
    if(!ReadFile(ReadPipeHandle,Data,sizeof(Data)-1,&BytesRead,NULL))
      RaiseLastWin32Error();
    Data[BytesRead]='\0';
    F1->M0_stdout->Lines->Add(AnsiString(Data));
   }
   else // is the console app terminated?
   if(WaitForSingleObject(pi.hProcess,0)==WAIT_OBJECT_0)
    break;
//
  } // ����� for(;;)
//
  CloseHandle(pi.hThread);
  CloseHandle(pi.hProcess);
  CloseHandle(ReadPipeHandle);
  CloseHandle(WritePipeHandle);
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int luaPanic( lua_State* L )
{  // ������� ������ Lua
 Beep();
 tp_printf( "\n\n\n\n\n|%s|%s|\n\n\n\n\n", lua_tostring( L,-1 ), __FUNC__ );
 Beep();
//
 char str[_256];
 strNcpy( str, lua_tostring( L,-1 ) );
 ShowBreakpoint( str ); // ������� ������ ��������
//
 longjmp( env_StopSessionLua, 1 ); // ����������� ������� � ����� setjmp !!!!!!!
//
// ----- ��� RETURN ����������� exit(EXIT_FAILURE) (��� ��������� �������������)
//
} // ----- ����� luaPanic ------------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Set_FileNames_All_Protocols()
{ // ���������� ����� ���� ������ ���������� �������� (� ����������� Out!Data)
// ������� ���������� ������ Data-Time -----------------------------------------
 strNcpy( uniqueStr, PutDateTimeToString(1) ); // ���������� ������ ( ���� + ����� �� ���� )
// --- ������ ���� � �������� ������ ������������ ������ (������� ���� � �����)
 snprintf( PathToSubDirOutData,sizeof(PathToSubDirOutData), "%s%s\\", ExtractFilePath(Application->ExeName), NameSubDirOutData );
///
 if( !DirectoryExists( PathToSubDirOutData ) ) // ���� �� ���������� ����� ��������...
  if( !CreateDir( PathToSubDirOutData ) ) // ���� �� ������� �������...
   strNcpy( PathToSubDirOutData, '\0' ); // �������� ���� � ����������� PathToSubDirOutData
// ����� ������� ���������� ����� ������ ��� ������� ������������ ������� ------
 char tmp[_512], cnst[_512];
 sprintf( cnst, "!%s!%s.txt", ExtractFileName(ScriptFileName), uniqueStr ); // ���������� ����� �����
//
 snprintf( tmp, sizeof(tmp), "%s%s%s", PathToSubDirOutData, "stdin",  cnst ); // ������ ���� � stdin
  snprintf( stdinFileName, sizeof(stdinFileName), "%s", tmp );
//
 snprintf( tmp, sizeof(tmp), "%s%s%s", PathToSubDirOutData, "stdout", cnst ); // ������ ���� � stdout
  snprintf( stdoutFileName, sizeof(stdoutFileName), "%s", tmp );
//
 snprintf( tmp, sizeof(tmp), "%s%s%s", PathToSubDirOutData, "stderr", cnst ); // ������ ���� � stderr
  snprintf( stderrFileName, sizeof(stderrFileName), "%s", tmp );
//
 snprintf( tmp, sizeof(tmp), "%s%s%s", PathToSubDirOutData, "protocol", cnst ); // ������ ���� � protocol
  snprintf( FileNameProtocol, sizeof(FileNameProtocol), "%s", tmp );
//
} // --- ����� Set_FileNames_All_Protocols -------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::PutTimeLiveDataToTextFrame_Menu(TObject *Sender)
{ // F6 - ��������� � ������ � ��������� ���� ��������� ����� ������ ------------
 c_CreateAndOutputDataLiveDiagrByTiers( 0, "" ); // ������� � ������ � ��������� ���� ��������� ������� ����� ������ �� �����e�� Tiers[][]
} //----------------------------------------------------------------------------


