//
// настройка Advanced Compiler: - Pentium, Word
//
#define DEBUG 0 // вызов stackDump для отладки, если DEBUG # 0
#define HOOK_COUNT 3 // чиcло вызовов срабатывания luaHook
//
#define APM Application->ProcessMessages(); // дать поработать Windows ---------
//
#include <vcl.h>
#include <vcl/dstring.h> // для работы с ANSI-строками
#include <vcl/StrUtils.hpp> // для работы с ANSI-строками ( AnsiReplaceStr )
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
#include <DateUtils.hpp> // для DayOf, WeekOf, MonthOf и др.
#include <System.hpp>
//
#include <shellapi.h>
//
#include <time.h>
#include <alloc.h>
#include <math.h>
#include <excpt.h>
#include <sysdefs.h>
#include <sysopen.h>
#include "windows.h"
//
#include <setjmp.h> // для реализации нелокального перехода
jmp_buf env_StopSessionLua; // в env_StopSessionLua сохраняется состояние в точке вызова setjmp
short i_env_StopSessionLua = -1; // что возвращает setjmp (вызов longjmp корректен только при i_env_StopSessionLua >= 0)
//
#include <Clipbrd.hpp>
#include <IniFiles.hpp>
//#include <shellapi.h>
#include "SysUtils.hpp"
//
#include <mmsystem.hpp> // для PlaySount
#include "vcl/dstring.h" // для описания Length
//
#include <clocale> // для setlocale()
//
#define strNcpy(d,s) strncpy(d,s,sizeof(d)) // безопасный вариант
//
using namespace std; // стандартное пространство имён
//
#define do_tStart_fStop \
{ F1->SB_StopScript->Enabled  = false;  /* ДЕактивировали кнопку StopScript */ \
  F1->SB_StartScript->Enabled = true; } /* активировали кнопку StartScript */
//
#define do_fStart_tStop \
{ F1->SB_StopScript->Enabled  = true;    /* активировали кнопку StopScript */ \
  F1->SB_StartScript->Enabled = false; } /* ДEактивировали кнопку StartScript */
//
#define do_HandRule_Enabled \
{ F1->LoadAndPutIGA->Enabled  = true;    /* активировать варианты "ручного управления" в главном меню */ \
  F1->CreateUpperSPF->Enabled = true; \
  F1->CreateLowerSPF->Enabled = true; \
  F1->CreateTimeLiveData->Enabled = true; \
  F1->CreateParamsByOp->Enabled = true; }
//
#define do_HandRule_Disabled \
{ F1->LoadAndPutIGA->Enabled  = false; /* деактивировать варианты "ручного управления" в главном меню */ \
  F1->CreateUpperSPF->Enabled = false; \
  F1->CreateLowerSPF->Enabled = false; \
  F1->CreateTimeLiveData->Enabled = false; \
  F1->CreateParamsByOp->Enabled = false; }
//
#pragma hdrstop
//
#pragma warn -8057 // отключили сообщения E8057 Parameter 'Sender' is never used
//
#include "Unit1c.h"
#include "Unit2c.h" // чтобы был доступ к F2 (форма вывода рассчитанных данных)
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
TStringList *paramsTLD = new( TStringList ) ;
//
//#include "pcre.h" // библиотека регулярных выражений от Borland C++ RTL
//
#define REAL double // тип вещественных чисел при вычислениях (64 бит)
#define INT  signed long int // тип целых (32 бит)
//
#define ULI unsigned long int // длинное целое без знака (32 бит)
#define UI  unsigned int // целое без знака (32 бит)
//
#define _minINT -1073741824 // минимум -(2^30) и максимум 2^30 int_32
#define _maxINT  1073741824
//
// определение констант
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
#define maxRet 1000000000 // максимальное возвращаемое число (не более 2^32... с запАсом!)
//
// ----- коды ошибок (коды возврата функций) -----------------------------------
#define ERR_NOT_MASSIVE_EDGES -666 // нет массива Mem_Edges[][], над которым производится действие
#define ERR_NOT_MASSIVE_OPS   -667 // не определено число операторов в графе
#define ERR_NOT_MASSIVE_TIERS -777 // нет массива Tiers[][], над которым производится действие
#define ERR_IN_DATA -888 // некорректные входные данные
#define ERR_RANGE_IN -1313 // ошибка диапазона входных параметров функции
#define ERR_NOT_MEMORY -133 // нехватка памяти для Mem_Edges[][] и/или Tiers[][]
#define ERR_TRANSFORM -131313 // ошибка преобразования числового параметра по sscanf
// #define ERR_LIMITS_OP_CALC -131331 // проблемы в c_canExecOpCalc(INT Op, INT Calc)
#define ERR_METRIC -666.777 // невозможно найти метрику вершины (оператора) или дуги
#define ERR_CALC   -777.666 // код ошибок функций вычислений (семейство Calc...)
#define ERR_COMMON -123456789 // код ошибки общий
#define ERR_UNCERTAIN -1 // код ошибки непонятный
//#define nDef -134 // фиктивные номера операторов по "=Def:^"
#define RETURN_OK 0 // успех выполнения 
////////////////////////////////////////////////////////////////////////////////
//#define NOT_LIMITS_OPS 1111111 // нет ограничений по параметрам ОПЕРАТОРА
//#define NOT_LIMITS_CALCS 2222222 // нет ограничений по параметрам ВЫЧИСЛИТЕЛЯ
//
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
//
////////////////////////////////////////////////////////////////////////////////
//==============================================================================
////////////////////////////////////////////////////////////////////////////////
extern "C" // Lua - исходные тексты на "чистом С"
{
#include "./lua-5.3.0/src/lua.h"
#include "./lua-5.3.0/src/lauxlib.h"
#include "./lua-5.3.0/src/lualib.h"
}
#include "./lua-5.3.0/src/lua_src.c" // все С-исходники Lua...
lua_State *L = NULL; // глобАльный указатель - указывает на экземпляр Lua !!!!!!
//
void  __fastcall stackDump( lua_State *L, char *s ); // выдаёт содержимое стека Lua
int   __fastcall lua_pcall_Debug( lua_State* L, int args, int results ); // начало исполнения Lua с отладкой
//
static void LuaHook( lua_State *L, lua_Debug *ar); // функция перехватчик выполнения строк Lua
static int  errorHandler( lua_State* L ); // функция - обработчик ошибок
static int  luaPanic( lua_State* L ); // функция паники Lua
////////////////////////////////////////////////////////////////////////////////
//==============================================================================
////////////////////////////////////////////////////////////////////////////////
//
char
pattern_01[] = "[=][0-9]{1,}[/][0-9]{1,}[:]" // =n1/n2: -name1 Val1 -name2 Val2 ...
               "([ ][-][A-za-x0-9_]{1,}[ ][.,0-9]{1,}){0,}" // повтор всего до бесконечности
               ;
char
pattern_02[] = "[=][0-9]{1,}[/][0-9]{1,}[:]" // =n1/n2: -name1 minVal1 maxval1 -name2 minVal2 maxVal2 ...
               "([ ][-][A-za-x0-9_]{1,}[ ][.,0-9]{1,}[ ][.,0-9]{1,}){0,}" // повтор всего до бесконечности
               ;
//
#define strcat(dest,src) strncat(dest,src,sizeof(dest)-strlen(dest)-5) // безопасное добавление src к dest
// !!!!! при >=5 всё нормально, при <5 имеем останов в metametod "__newindex" строка 274 OpsCalcs[subTiers][mCalc]=iOp
//
#define GetRand(a,b) ( rand() % ( (b)-(a)+1)+(a) ) // случайное число от a до b (включительно)
//
char Ident[] = "Bakanov Valery Mikhailovich, http://vbakanov.ru/left_1.htm , Moscow, Russia, 2009-2023\n \
Автор программного продукта Валерий Баканов не является ярым сторонником Объектно-Ориентированного Программирования \
(внутри автора точно сидит Линус Торвальдс!) и поэтому большая часть кода не использует ООП\n \
The author of the software Valery Bakanov is not an ardent supporter of Object-Oriented Programming \
(Linus Torvalds definitely sits inside the author!) and therefore most of the code does not use OOP";
//
struct {
INT nOpMinIn,  nEdgesMinIn,  // # опер. с MIN входящих дуг и число этих дуг (кроме nInput)
    nOpMaxIn,  nEdgesMaxIn,  // # опер. с MAX входящих дуг и число этих дуг (кроме nInput)
    nOpMinOut, nEdgesMinOut, // # опер. с MIN выходящих дуг и число этих дуг (кроме nOutput)
    nOpMaxOut, nEdgesMaxOut; // # опер. с MAX выходящих дуг и число этих дуг (кроме nOutput)
REAL AveIn, AveOut; // среднее число входов и выходов
} PG; // структура для хранения найденных экстремумов входящих и выходящих дуг из операторов
// PG ParGraph; // реализация PG есть ParGraph
//
long color_BackGround = clWhite; // цвет фона окна редактирования
//
// ----- цвета для отрисовки диаграммы распр. операторов по ярусам ЯПФ ( DrawDiagrSPF, DrawDiagrTLD )
long brush_draw_color_TIERS = clBlack, // цвет кисти обычный для графика ЯПФ (чёрный)
     brush_draw_color_TLD   = RGB(0,64,0), // цвет кисти для вывода времени жизни данных (тёмно-зелёный)
     brush_draw_color_MIN   = clRed, // цвет кисти МИНИМУМ
     brush_draw_color_MAX   = clFuchsia, // цвет кисти МАКСИМУМ
     pen_draw_b_average     = clWhite, // цвет линии среднего числа
     contour_draw_color     = clWhite; // цвет рамки прямоугольника
// ----- цвета для очистки диаграммы распр. операторов по ярусам ЯПФ ( ClearDiagrSPF )
long clear_brush_draw_color = RGB(255,255,255); // clWhite; // цвет кисти обычный (цвет фона)

////////////////////////////////////////////////////////////////////////////////
//
#define _nOpMinIn    (GetParGraph().nOpMinIn) // такого вхождЕния быть не должно - работает!!!
#define _nEdgesMinIn (GetParGraph().nEdgesMinIn) // !!!
#define SB0 F1->SB->Panels->Items[0] // нижняя панель статуса (самая левая часть)
#define TEV0 F1->LMD_EV0 // TLMDEditView (LMD SyntaxEdit SingleLicense)
#define TED0 F1->LMD_ED0 // TLMDEditDocument (LMD SyntaxEdit SingleLicense)
#define TM0_stdout F1->M0_stdout // TMemo вывода результата выполнения скриптов ( stdout )
#define TM1  F2->M1 // TMemo вывода текстов на F2
#define TIM1 F2->IM1 // область вывода графики (TImage) на F2
//
#define c_AddLineToFileProtocol(s) \
 { if (fptr_protocol) fprintf(fptr_protocol,s); } // пишем строку s в файл протокола
//
#define c_AddLineToStderr(s) \
 {if (fptr_stderr) fprintf(fptr_stderr,s); } // пишем строку s в stderr
//
void /*__fastcall*/ t_printf(char *fmt, ...); // форматный вывод в ТЕКСТОВОЕ ОКНО
void /*__fastcall*/ p_printf(char *fmt, ...); // форматный вывод в ФАЙЛ ПРОТОКОЛА
void /*__fastcall*/ e_printf(char *fmt, ...); // форматный вывод в ФАЙЛ stderr
void /*__fastcall*/ tp_printf(char *fmt, ...); // форматный вывод в ТЕКСТОВОЕ ОКНО и в ФАЙЛ ПРОТОКОЛА
void /*__fastcall*/ tpe_printf(char *fmt, ...); // форматный вывод в ТЕКСТОВОЕ ОКНО, в ФАЙЛ ПРОТОКОЛА и в stderr
void /*__fastcall*/ sp_printf(char *fmt, ...); // форматный вывод на StatusBar и в в ФАЙЛ ПРОТОКОЛА
void /*__fastcall*/ safe_printf(int rule, char *fmt, ...); // форматный вывод в заданный rule приёмник
//
////////////////////////////////////////////////////////////////////////////////
//
#define MAX_EDGES 10000000 // максимальный размер пула дуг информационного графа 10^7 // не учитывается
// описание структуры каждой дуги информационного графа алгоритма
struct me {
 INT From, To; // определяющие дугу узлы "откуда -> куда"
 char Operators[_512]; // текстовое описание операторов, составляющих дугу
 bool flag_From, flag_To; // флаги для вспомогательных действий с дугами
} M__E, *Mem_Edges=NULL;
ULI Max_Edges = _128, // первоначальный захват (будет переопределено в c_ReadEdges)
    Really_Edges = 0; // текущее значение
#define Edges(i,j)   ( !i ? Mem_Edges[j].From      : Mem_Edges[j].To ) // "откуда/куда" направлена дуга ИГА
#define Edges_f(i,j) ( !i ? Mem_Edges[j].flag_From : Mem_Edges[j].flag_To ) // флаги "откуда/куда" направлена дуга ИГА
// Edges(0,j) - номер оператора, от которого отходит дуга ("From");
// Edges(1,j) - номер оператора, к которому "приходит" дуга ("To")
// индексацию по j начинаем с 1 (для согласования с правилами индексации в Lua)
//
#define MAX_EVENTS 1000000 // максимальный размер буфера событий 10^6 // не учитывается
struct ev {
 INT start_Ticks, // момент начала отсчёта
     d_Ticks, // заданная задержка
     ev_Ticks; // тик момента вызова события
 char CommandLine[_256]; // текст Lua-вызова
} E_V, *Mem_EV=NULL;
INT max_Events = _128, // первоначальный захват
    i_Events = 0; // индекс последнего занятого элемента в массиве Mem_EV
//
////////////////////////////////////////////////////////////////////////////////
INT _maxTiers     = 100, // max числа ярусов в графе (ярус 1 - исходные данные)  ( ИЗМЕНЯЕМОЕ !!! )
    _maxTiersPrim = 100; // ...для первоначального аллокирования
INT _maxOpsOnTier     = 100, // max число операций на ярусе  ( ИЗМЕНЯЕМОЕ !!! )
    _maxOpsOnTierPrim = 100; // ...для первоначального аллокирования
INT *pTiers  = NULL, // указатель на (плоский) массив Tiers
    *npTiers = NULL; // указатель на временный массив
// 2D-массив Tiers[][] раскладывается по СТРОКАМ в одномерный массив с адреса указателя pTiers
// здесь i - номер яруса (начиная с 0), j - номер оператора на ярусе (j начинаем с 1)
#define Tiers(i,j) pTiers[(i)*(_maxOpsOnTier+1)+(j)] // обращение к 2D-массиву Tiers как к плоскому
////////////////////////////////////////////////////////////////////////////////
#define stockMem 1.667 // величина "запаса" при увеличении массивов
////////////////////////////////////////////////////////////////////////////////
struct {
REAL averWidth, // среднеарифметичесая ширина ЯПФ (кроме 0-го уровня)
     sumSqWidth, // сумма квадратов невязок
     SD,//  СКО (Standard Deviation)
     CV, // коэфиициент корреляции числа операторов по ярусам ЯПФ
     IC, // коэффициент неравномерности (max/min)
     ICL, // коэффициент неравномерности (по кривой Лоренца)
     AAL, // среднеарифметическая длина дуги (Average Arc Length)
     MinOpsByTiers, // мин. число операторов по ярусам (исключая нулевой)
     MaxOpsByTiers, // макс. -.-.-.-.
     averCOP, // ср.арифм. совсестного параллелизма операторов (Cooperative Operators Parallelism)
     DC; // плотность кода (DensityCode)
} StatTiers; // структура параметров статистики SPF
////////////////////////////////////////////////////////////////////////////////
INT nEdges, // всего число дуг в графе (включая нулевой ярус)
    nOpsInput, // входных операторов в графе (исходные данные)
    nOpsOutput, // выходных операторов в графе (рассчитанные данные)
    nOps, // число операторов в графе без входных (но с выходными)
    nTiers, // действительное число ярусов в ЯПФ графа (с нулевым ярусом)
    nMoves = 0; // глобальная переменная для подсчёта успешных перемещений операторов между ярусами
////////////////////////////////////////////////////////////////////////////////
bool flagExistsTiers = false , // сформирован ли массив Tiers[][] (после каждого считывания ИГА - false)
     flagExistsEdges = false , // сформирован ли Mem_Edges[][]
     flagExistsOps   = false , // число операторов (вершин графа) не определено
     flagCalcTLD     = false ; // вычислен ли paramsTLD по Tiers[][]
char messNotTiers[] = "массив ЯРУСОВ не сформирован", // сообщения об ошибках
     messNotEdges[] = "массив ДУГ не сформирован",
     messNotOps[]   = "число ОПЕРАТОРОВ не определено",
     messParams1[]  = "некорректен диапазон параметров(1)",
     messParams2[]  = "некорректен диапазон параметров(2)",
     messParams3[]  = "некорректен диапазон параметров(3)";
//
char TitleF2[_256] = " Текстовое представление информации"; // заголовок F2
//
// имена секций файла конфигурации системы
struct { // ReadWriteConfig (имена секций фала конфигурации системы)
char *Sect1, *Sect1_Var1,*Sect1_Var2,*Sect1_Var3,*Sect1_Var4,*Sect1_Var5,*Sect1_Var6,*Sect1_Var7,*Sect1_Var8,*Sect1_Var9,
     *Sect2, *Sect2_Var1,*Sect2_Var2,*Sect2_Var3,*Sect2_Var4,*Sect2_Var5,
     *Sect3, *Sect3_Var1,*Sect3_Var2,*Sect3_Var3,*Sect3_Var4,*Sect3_Var5,*Sect3_Var6,
     *Sect4, *Sect4_Var1,
     *Sect5, *Sect5_Var1,*Sect5_Var2,*Sect5_Var3,*Sect5_Var4,*Sect5_Var5,*Sect5_Var6,*Sect5_Var7,*Sect5_Var8,
     *Sect6, *Sect6_Var1,
     *Sect7, *Sect7_Var1 ;
} RWC = {
 "Font", // [1] фонт окна редактирования Lua-скриптов
  "Name","Size","Color","Charset","Pitch","Bold","Italic","Underline","StrikeOut",
 "Pos_F1", // [2] положение формы главного окна
  "Top","Left","Width","Height","partheightStdout",
 "Pos_F2", // [3] оложение формы дочернего окна
  "Top","Left","Width","Height","PutParamsTiersOnTextFrame","PutParamsTLDOnTextFrame",
 "LastScript", // [4] последний файл скрипта
  "FileNameLua",
 "LMD_EditViewColors", // [5] цвета окна редактирования Lua
  "Gutter->LinesBarBg","Gutter->LinesBarTextColor","Gutter->FoldsBarBg","Gutter->FoldsBarLineColor","Gutter->CustomBarBg","SelectionBg","SelectionColor","Color",
 "Tick_Interval", // [6] интервал главного таймера (мсек)
  "Interval",
 "OutOpsPutBottom", // [7] переносить ли принудительно вызодные операторы на самый нижний ярус ( 1/0 )
   "OutOpsPutOnBottomTier"
} ; // [ReadWriteConfig] имена секций файла конфигурации
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char FileNameLua[_256]  = "spf_client.lua", // текущее имя файла Lua-скрипта
     stdinFileName[_256], // временный файл Lua-скрипта ( stdin )
     stdoutFileName[_256], // stdout...
     stderrFileName[_256], // stderr...
     FileNameProtocol[_256], // файл протокола
     FileNameEdges[_256]  = "no_name.gv", // текущий файл дуг графа (описание графа)
     GraphName[_256]      = "no_name", // имя графа (берётся из gv-файла)
     _FileNameEdges[_256] = "EdgesData", // фиксированное имя файла списка дуг (расширение - см. ниже)
     FileNameINI[_256],   // путь к файлу конфигурации
     NameSubDirOutData[] = "Out!Data", // имя подкаталога для сброса рассчитанных данных
     NameSubDirInData[]  = "In!Data",  // имя подкаталога для исходных дынных данных
     PathToSubDirOutData[_256], // полный путь к подкаталогу сброса рассчитанных данных
     PathToSubDirInData[_256], // полный путь к подкаталогу исходных данных данных
     MySite[] = "http://vbakanov.ru", // адрес моего сайта
//
     extGv[]    = "gv",   // расширение имени файла дуг графа для ввода
     extVizu[]  = "_vz", // дополнение к расширению имени файла для Vizu (вывод/ввод, ".")
     extTiers[] = "trs", // расширение имени файла ЯПФ (вывод, без ".")
     extIno[]   = "ino", // расширение имени файла ЯПФ (вывод, без ".")
     extPrm[]   = "prm", // расширение файла параметров ЯПФ (вывод, без ".")
     extTld[]   = "tld"; // расширение имени файла времени жизни данных  (вывод, без ".")
////////////////////////////////////////////////////////////////////////////////
FILE *fptr_stdout, *fptr_stderr, *fptr_protocol; // соответствующие файловые структуры
#define DELAY_PUT_PROTOCOL 0 // ждать миллисекунд при выдаче протокола
char uniqueStr[_512] = "\0"; // уникальная строка для имен файлов ( дата + время до мсек )
////////////////////////////////////////////////////////////////////////////////
bool flagCommandLine = false; // если THUE - запуск в режиме командной строки
////////////////////////////////////////////////////////////////////////////////
bool flagHook = false; // флаг срабатывания "ловушки" (Hook)
//
INT ticks = 0; // глобальный счётчик тиков
//
bool flag_Busy = false; // если true - вызов Lua по Events невозможен
char busy_CommandLine[_256]; // выполняющаяся в данный момент Lua-строка
//
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall RunLuaScript(); // выполняет Lua-скрипты в 'rptvgkzht Lua ( L, глобал )
bool  __fastcall IncreaseOpsOnTier(INT Tier, INT newSize, INT flag); // увеличивает #операторов на ярусах Tiers[][] до newSize
char* __fastcall PutDateTimeToString(INT flag); // выдача текущих даты и времени в строку с форматированием
bool  __fastcall CloseAndRenameFileProtocol(); // дать окончательное имя файла протокола
void  __fastcall PutFileNameLua(); // выдаёт имя файла скрипта на форму
void  __fastcall DisplayMessage(char* Level, char* funcName, char* Text, INT Err); // выдать сообщение Text уровня Level
void  __fastcall IndicateColRowNumberOfEV0(); // номер строки и номер символа в позиции курсора
char* __fastcall ReplaceManySpacesOne( char* pszStr ); // заменяет кратные пробелы на единственным
void  __fastcall DeleteSpacesTabsAround( char* str ); // удаляет пробелы и Tabs слева и справа строки str
char* __fastcall DeleteAllSpaces(char* str); // удаляет ВСЕ пробелы в строке str
void  __fastcall ReplaceEqualLengthSubstring( char* String, char* OldSubstring, char* NewSubstring );
char* __fastcall DeleteSymbolAll( char str[], char symb ); // уничтожает символ symb по все строке ыек
//
void  __fastcall Read_Config(); // читать и записывать файл конфигурации
void  __fastcall Write_Config();
bool  __fastcall StartByCommandLine( char* s ); // начало работы в режиме командной строки
bool  __fastcall c_CreateTiersByEdges( char* FileName ); // создаёт (на основе ИГА из массива FileName ЯПФ в "верхней" форме
bool  __fastcall c_CreateTiersByEdges_Bottom( char* FileName ); // создаёт (на основе ИГа из файла FileName ЯПФ в "нижней" форме
void  __fastcall GetFileFromServer( char FileName[] ); // получить файл с сервера
void  __fastcall Copy_Stdout_To_Memo(); // для вывода stdout в M0_stdout
void  __fastcall SaveLuaScript( char* FileName ); // сохранить скрипт в файл без вопросов
//
void  __fastcall ShowBreakpoint( char* str ); // показать точку проверки (Breakpoint) в текстовом редакторе Lua
//
void  __fastcall stdoutToMemo(); // вывод stdout в M0_stdout
//
void  __fastcall CopyStdoutToTextProtocol(); // копировать stdout текстовое подокно TM0_stdout и в файл протокола
void  __fastcall CopyStderrToProtocol(); // копировать stderr в файл протокола
//
void  __fastcall GetFileFromServer(  char* FileNameSource, char* FileNameDestination, bool Replace  ); // взять файл с сервера
void  __fastcall PutFileToServer(  char* FileNameSource, char* FileNameDestination, bool Replace  ); // вЫгрузить файл на сервер
void  __fastcall Unload_Install(); // загрузить с сервера инсталляционную версию продукта
void  __fastcall Upload_Data( int Rule ); // вЫгрузить файлы на сервер (в зависимости от pyfxtybz Rule )
void  __fastcall Work_LogInOut( int Rule); // сообщить о начале/конце работы программы SPF_CLIENT.EXE
void  __fastcall PutParamsAboutSelectOp( INT Op ); // выдать параметры оператора Op
void  __fastcall Set_FileNames_All_Protocols(); // настраиваем имена всех файлов протоколов (для Out!Data)
void  __fastcall OutOpsMoveLowerTier(); // все выходные операторы перенести на самый нижний ярус
//
////////////////////////////////////////////////////////////////////////////////
// строки для хранения параметров ВЫЧИСЛИТЕЛЕЙ и ОПЕРАТОРОВ --------------------
char *sCalcs = NULL, // длинные строки для хранения  параметров ВЫЧИСЛИТЕЛЕЙ
     *sOps   = NULL, // ...ОПЕРАТОРОВ
     *sEdg   = NULL, // ...метрик ДУГ
     *sVrt   = NULL, // ...метрик ВЕРШИН
     *sWork  = NULL; // рабочая строка
const char // имена файлов параметров ПО УМОЛЧАНИЮ -----------------------------
     DefFileNameParamsCalcs[]    = "calculators.cls", // файл параметров ВЫЧИСЛИТЕЛЕЙ
     DefFileNameParamsOps[]      = "operators.ops",   // файл параметров ОПЕРАТОРОВ
     DefFileNameParamsEdges[]    = "edges.med",     // файл метрик ДУГ ИГА
     DefFileNameParamsVertices[] = "vertices.mvr";  // файл метрик ВЕРШИН ИГА
char // те же имена файлов, но РАБОЧИЕ (глобалы)--------------------------------
     FileNameParamsCalcs[_256], // реальное имя файла... (см. выше)
     FileNameParamsOps[_256], // ...
     FileNameParamsEdges[_256], // ...
     FileNameParamsVertices[_256]; // ...
char sDef[] = "=Def:\0"; // строка для поиска и сравнения
//
__int64 SessionStartTime = 0L; // время начала сессии исследований (глобал)
//
////////////////////////////////////////////////////////////////////////////////
WideString ActiveColorScheme  = "defColorScheme", // "широкие строки" для компонентов LMD
           ActiveSyntaxScheme = "defSyntaxScheme";
char extSchemes[] = "xml"; // расширение файлов схем цветов и синтаксиса ( БЕЗ ТОЧКИ )
////////////////////////////////////////////////////////////////////////////////
bool PutParamsTiersOnTextFrame = false, // если трудно осмыслить быстро бегущие данные (задаётся в INI-файле)
     PutParamsTLDOnTextFrame   = false; // выводить ли данные о времени жиэни в окно F2 (так же)
// при true выводится в текстовое окно то же самое, что в нижней части текстового окна вывода
////////////////////////////////////////////////////////////////////////////////
bool luaExecute = false; // флаг времени выполнения Lua (при выполнеЕнии true, иначе false)
//
//#define strcat(dest,src) strncat(dest,src,sizeof(dest))-strlen(dest)-5) // безопасное добавление src к dest
//
char first_F1[] = "-- %s: скрипт на языке Lua ver.5.3.0 rel. on 06 Jan 2015\n--\n", // начальная строка для Lua
     first_F2[] = "-I- %s: начало выполнения программы на языке Lua ver.5.3.0 rel. on 06 Jan 2015 -I-\n"; // начальная строка вывода данных Lua
//char first_F1[] = "-- %s: скрипт на языке Lua ver.5.4.4 rel. on 13 Jan 2022\n--\n", // начальная строка для Lua
//     first_F2[] = "-I- %s: начало выполнения программы на языке Lua ver.5.4.4 rel. on 13 Jan 2022 -I-\n"; // на
//
#include "API_c.cpp" // С-ишные функции API (начинаются с "c_")
#include "API_lua.cpp" // описание на С вызовов Lua
#include "LMD_c.cpp" // описание на С пакетов LMD
//
const int minW_F1=900, minH_F1=600; // минимальные размеры главной формы F1
extern const int minW_F2, minH_F2; // минимальный размер дочерной формы F2 (определены в Unit2.cpp)
////////////////////////////////////////////////////////////////////////////////
//int outGlobal = 0; // глобал для запоминания, из какого MenuItem вызван CD0 (перенесено в LMD_c.cpp)
////////////////////////////////////////////////////////////////////////////////
REAL partHeightStdout[3] = {0.2, 0.1, 0.5}; // доля высоты окна stdout (текущая, min, мах)
////////////////////////////////////////////////////////////////////////////////
INT FileSizeFromServer = 0; // размер файла при выгрузке с сервера
////////////////////////////////////////////////////////////////////////////////
//
//
__fastcall TF1::TF1(TComponent* Owner) : TForm(Owner) // выполняется в начале всего..!
{
//
 F1->Position = poDefault; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
 time_t t;
//
 DecimalSeparator = '.'; // разделитель целой и десятичной частей - точка
//
 strNcpy( FileNameINI, ChangeFileExt(ParamStr(0), ".ini").c_str()); // INI-файл в текущем каталоге
//
 pTiers = (INT*) calloc( (_maxTiers+1)*(_maxOpsOnTier+1), sizeof(INT) );
//
// захватываем память под строки параметров ВЫЧИСЛИТЕЛЕЙ, ОПЕРАТОРОВ, мЕтрик ДУГ и ВЕРШИН
 sCalcs = (char*) calloc( _16384, sizeof(char) ); // для параметров ВЫЧИСЛИТЕЛЕЙ...
 sOps   = (char*) calloc( _16384, sizeof(char) ); // для параметров ОПЕРАТОРОВ...
 sEdg   = (char*) calloc( _16384, sizeof(char) ); // для метрик ДУГ...
 sVrt   = (char*) calloc( _16384, sizeof(char) ); // для метрик ВЕРШИН...
 sWork  = (char*) calloc( _16384, sizeof(char) ); // рабочий ВООБЩЕ массив...
//
 Mem_EV = (ev*)   calloc( i_Events, sizeof(ev) ); // массив событий
// стандартные имена файлов ----------------------------------------------------
 strNcpy( _FileNameEdges, ChangeFileExt( _FileNameEdges, extGv ).c_str() ); // расширение - extGv
//
////////////////////////////////////////////////////////////////////////////////
//
 LMD_ED0->ActiveColorScheme  = ActiveColorScheme ; // настраиваем имя активных схем
 LMD_ED0->ActiveSyntaxScheme = ActiveSyntaxScheme ;
//
// Copy_Stdout_To_Memo(); // копировать stdout на Memo
//
 paramsTLD->Clear(); // очистим на всякий случай
//
} // --- конец TF1 -------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void t_printf(char *fmt, ...)  // вывод строки в текстовое окно
{  // не менее одного обязательного аргумента !
 int lenBuff = _256; // начальная длина буфера вывода
 char* buff = (char*) malloc( lenBuff ); // заказ первоначального буфера-строки для форматного вывода
 va_list args;  // определяем сущность СПИСОК в эллипсисе ( ...  )
 va_start( args, fmt );  // начало списка аргументов в эллипсисе
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // необходимая длина буфера для полноценного вывода строки
 if( new_lenBuff > lenBuff ) // необходимо увеличить буфер..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // увеличиваем буфер (с учётом '\0' в конце)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // заново выводим в (расширенный) буфер buff
 }
 va_end(args);  // конец списка аргументов в эллипсисе
//
 c_AddLineToTextFrame( buff ); // добавление в текстовое окно  (учитываеются '\n')
//
 APM // дать поработать Windows
//
} // ---- конец t_printf -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void p_printf(char *fmt, ...) // вывод строки в fptr_prot
{  // не менее одного обязательного аргумента !
 int lenBuff = _256; // начальная длина буфера вывода
 char* buff = (char*) malloc( lenBuff ); // заказ первоначального буфера-строки для форматного вывода
 va_list args;  // определяем сущность СПИСОК в эллипсисе ( ...  )
 va_start( args, fmt );  // начало списка аргументов в эллипсисе
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // необходимая длина буфера для полноценного вывода строки
 if( new_lenBuff > lenBuff ) // необходимо увеличить буфер..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // увеличиваем буфер (с учётом '\0' в конце)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // заново выводим в (расширенный) буфер buff
 }
 va_end(args);  // конец списка аргументов в эллипсисе
//
 c_AddLineToFileProtocol( buff ); // добавили в файл протокола
//
 APM // дать поработать Windows
//
} // ---- конец p_printf -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void e_printf(char *fmt, ...) // вывод строки в stderr
{  // не менее одного обязательного аргумента !
 int lenBuff = _256; // начальная длина буфера вывода
 char* buff = (char*) malloc( lenBuff ); // заказ первоначального буфера-строки для форматного вывода
 va_list args;  // определяем сущность СПИСОК в эллипсисе ( ...  )
 va_start( args, fmt );  // начало списка аргументов в эллипсисе
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // необходимая длина буфера для полноценного вывода строки
 if( new_lenBuff > lenBuff ) // необходимо увеличить буфер..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // увеличиваем буфер (с учётом '\0' в конце)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // заново выводим в (расширенный) буфер buff
 }
 va_end(args);  // конец списка аргументов в эллипсисе
//
 c_AddLineToStderr( buff ); // добавили в stderr
//
 APM // дать поработать Windows
//
} // ---- конец e_printf -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void tp_printf(char *fmt, ...)
{  // не менее одного обязательного аргумента !
 int lenBuff = _256; // начальная длина буфера вывода
 char* buff = (char*) malloc( lenBuff ); // заказ первоначального буфера-строки для форматного вывода
 va_list args;  // определяем сущность СПИСОК в эллипсисе ( ...  )
 va_start( args, fmt );  // начало списка аргументов в эллипсисе
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // необходимая длина буфера для полноценного вывода строки
 if( new_lenBuff > lenBuff ) // необходимо увеличить буфер..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // увеличиваем буфер (с учётом '\0' в конце)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // заново выводим в (расширенный) буфер buff
 }
 va_end(args);  // конец списка аргументов в эллипсисе
//
 c_AddLineToFileProtocol( buff ); // добавили в файл протокола
 c_AddLineToTextFrame( buff ); // добавление в текстовое окно
//
 APM // дать поработать Windows
//
} // ---- конец tp_printf ------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void tpe_printf(char *fmt, ...)
{  // не менее одного обязательного аргумента !
 int lenBuff = _256; // начальная длина буфера вывода
 char* buff = (char*) malloc( lenBuff ); // заказ первоначального буфера-строки для форматного вывода
 va_list args;  // определяем сущность СПИСОК в эллипсисе ( ...  )
 va_start( args, fmt );  // начало списка аргументов в эллипсисе
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // необходимая длина буфера для полноценного вывода строки
 if( new_lenBuff > lenBuff ) // необходимо увеличить буфер..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // увеличиваем буфер (с учётом '\0' в конце)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // заново выводим в (расширенный) буфер buff
 }
 va_end(args);  // конец списка аргументов в эллипсисе
//
 c_AddLineToFileProtocol( buff ); // добавили в файл протокола
 c_AddLineToTextFrame( buff ); // добавление в текстовое окно
 c_AddLineToStderr( buff ); // добавили в stderr
//
 APM // дать поработать Windows
//
} // ---- конец tpe_printf ------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void sp_printf(char *fmt, ...)
{  // не менее одного обязательного аргумента !
 int lenBuff = _256; // начальная длина буфера вывода
 char* buff = (char*) malloc( lenBuff ); // заказ первоначального буфера-строки для форматного вывода
 va_list args;  // определяем сущность СПИСОК в эллипсисе ( ...  )
 va_start( args, fmt );  // начало списка аргументов в эллипсисе
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // необходимая длина буфера для полноценного вывода строки
 if( new_lenBuff > lenBuff ) // необходимо увеличить буфер..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // увеличиваем буфер (с учётом '\0' в конце)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // заново выводим в (расширенный) буфер buff
 }
 va_end(args);  // конец списка аргументов в эллипсисе
//
 SB0->Text = buff;
 if( DELAY_PUT_PROTOCOL )
  F1->SB->Repaint(); // перерисУем...
 Delay( DELAY_PUT_PROTOCOL ); // ждать... или не ждать!..
//
 p_printf( "%s %s\n", PutDateTimeToString(0), buff ); // добавили в файл протокола
//
 APM // дать поработать Windows
//
} // ---- конец sp_printf ------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void safe_printf(int rule, char *fmt, ...)
{  // не менее одного обязательного аргумента !
 int lenBuff = _256; // начальная длина буфера вывода
 char* buff = (char*) malloc( lenBuff ); // заказ первоначального буфера-строки для форматного вывода
 va_list args;  // определяем сущность СПИСОК в эллипсисе ( ...  )
 va_start( args, fmt );  // начало списка аргументов в эллипсисе
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // необходимая длина буфера для полноценного вывода строки
 if( new_lenBuff > lenBuff ) // необходимо увеличить буфер..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // увеличиваем буфер (с учётом '\0' в конце)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // заново выводим в (расширенный) буфер buff
 }
 va_end(args);  // конец списка аргументов в эллипсисе
//
 switch( rule ) // вывод в зависимости от значения rule
 {
  case 1: c_AddLineToTextFrame( buff ); // добавили строку на текстовый экран
          break;
  case 2: c_AddLineToFileProtocol( buff ); // добавили строку в файл протокола
          break;
  case 3: c_AddLineToTextFrame( buff ); // добавили строку на текстовый экран
          c_AddLineToFileProtocol( buff ); // добавили строку в файл протокола
          break;
  case 4:
          break;
  default:
          break;
 } // конец switch
//
 APM // дать поработать Windows
//
} // ---- конец safe_printf ----------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall DeleteAllSpaces( char *str )
{ // удаляет ВСЕ пробелы в строке str
//
// для использования AnsiReplaceStr ytj,[jlbvj #include <vcl/StrUtils.hpp>
// str = ( AnsiReplaceStr( str, " ", "" ) ).c_str(); // удаление всех пробелов
//
// нижеприведённое взято с http://www.quizful.net/interview/cpp/VbW07kq70NCY
 for ( register INT i=0,j=0; str[i]; (str[j++]=str[i]!=' '?str[i]:(j--,str[j]),i++,(!str[i]?(str[j]=0):0)) );
//
 return str;
//
} // ------ конец DeleteAllSpaces ----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall DeleteSpacesTabsAround( char *str )
{ // удаляет пробелы и Tabs слева и справа строки str
// Trim, TrimLeft, TrimRight работают только с AnsiString
// strNcpy(str, Trim(AnsiString(str)).c_str());
//
// удаляем пробелы и Tabs с начала строки
 register INT i=0, j;
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
// удаляем пробелы и Tabs с конца строки
 i=strlen(str)-1;
 while((str[i] == ' ') || (str[i] == '\t'))
  i--;
//
 if(i<(strlen(str)-1))
  str[i+1]='\0';
//
} // --- конец функции DeleteSpacesTabsAround ----------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall ReplaceManySpacesOne( char *pszStr )
{ // заменяет множество пробелов одним-единственным
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
  *pszStr = *pszCur; // скопировать \0
 } // конец if( pszStr )
//
   return pszOld;
} // --- конец функции ReplaceManySpacesOne ------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall ReplaceEqualLengthSubstring( char *String, char *OldSubstring, char *NewSubstring )
// в строке Strint заменяет подстроки OldSubstring на NewSubstring ОДИНАКОВОЙ ДЛИНЫ
{
 INT lenOldSubstring = strlen( OldSubstring ),
     lenNewSubstring = strlen( NewSubstring ) ;
 char *p ;
//
 if( lenOldSubstring != lenNewSubstring )
  return ;
//
 do // делать, пока p != NULL
  if( p = strstr( String, OldSubstring ) ) // в строке String нашли подстроку OldSubstring
   memcpy( p,NewSubstring,lenOldSubstring ); // копируем NewSubstring начиная с p
 while( p ) ;
//
} // --- конец функции ReplaceEqualLegthSubstring ------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall DeleteSymbolAll( char str[], char symb )
{ // удаляет все вхождения заданного символа
 register INT i, j;
//
 for ( i=j=0; str[i]!='\0'; i++ )
  if (str[i] != symb )
   str[j++] = str[i];
//
 str[j] = '\0';
//
 return str;
//
} // ----- конец DeleteSymbolAll -----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnClose_F1(TObject *Sender, TCloseAction &Action)
{// попытка закрытия приложения
 switch(MessageBox(0, "Вы в самом деле хотите закончить работу ?",
                       "Предупреждение",
                        MB_YESNO | MB_ICONWARNING | MB_TOPMOST))
 {case IDYES: fclose( fptr_protocol ); // закрыли файл протокола исполнения скрипта
              Write_Config(); // сохранили файл протокола
//
              StopLuaScript( Sender ); // остановить выполнение скрипта
//
              if( L )
               lua_close( L ); // закрыть Lua
//
              if( pTiers )
               free ( pTiers ); // на всякий случай отдаём память системе
//
              if( Mem_Edges )
               free ( Mem_Edges ); // ...
//
              Work_LogInOut( 1 ); // сообщить о конце работы программы SPF_CLIENT.EXE
//
              F2->Close(); // закрыли F2 - форма выдачи данных
              Action=caFree; // нажата кнопка Yes
              break;
//
  case IDNO:  Action=caNone; // нажата кнопка No
              break;
 } //конец блока SWITCH
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall IncreaseOpsOnTier(INT Tier, INT newSize, INT flag)
{
// --- увеличивает число операторов на ярусах в массиве Tiers[][] до newSize
// --- из "старой" области памяти в "новую" переносятся все данные ярусов 1-Tier
 char str[_1024], w[_256];
 INT oldOpsOnTier = _maxOpsOnTier; // запомнили "старое" значение _maxOpsOnTier
//
 _maxOpsOnTier = newSize; // _maxOpsOnTier - глобальное (новое) !
//
////////////////////////////////////////////////////////////////////////////////
//
// увеличиваем (до newSize) _maxOpsOnTier, а число ярусов оставляем тем же самым
 npTiers = (INT*) calloc( (_maxTiers+1)*(_maxOpsOnTier+1), sizeof(INT) ); // npTiers - глобальное!
//
 if( npTiers == NULL ) // совсем плохо - память в "куче" закончилась
  {
   snprintf(str,sizeof(str), "нехватка памяти для размещения массива Tiers[][] (2). Затребовано %d x %d = %d элементов...",
                _maxTiers+1, _maxOpsOnTier+1, (_maxTiers+1) * (_maxOpsOnTier+1));
   flagExistsTiers = false ; // массив Tiers[][] не создан...
   DisplayMessage( "E", __FUNC__, str, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
   MessageBeep( MB_ICONEXCLAMATION ); // звуковое предупреждение...
   MessageBox(0, str, "Предупреждение", MB_OK | MB_ICONWARNING | MB_TOPMOST);
   return ERR_NOT_MASSIVE_TIERS ;
  }
//
 t_printf( "\n-I- Массив ЯРУСОВ (%d) перераспределён на %d x %d = %d элементов -I-",
                  flag, _maxTiers+1, _maxOpsOnTier+1, (_maxTiers+1) * (_maxOpsOnTier+1));
//
// --- приходится (из-за особенностей обращения к 1D-массиву как к 2D-массиву) копировать данные
 for(INT i=0; i<=Tier; i++) // копируем по строкам и столбцам матрицу Tiers[][]
  for(INT j=0; j<=oldOpsOnTier; j++) // oldOpsOnTier - "старое" _maxOpsOnTier
   npTiers[i*(_maxOpsOnTier+1)+j] = pTiers[i*(oldOpsOnTier+1)+j]; // _maxOpsOnTier - "новое"
//
// --- сделали своё ЧЁРНОЕ ДЕЛО - переносим npEdges в (традиционное) pEdges...
 free( pTiers ); // уничтожили "старый" массив по указателю pTiers
 pTiers = npTiers; // теперь pTiers указывает на "новый" массив (бывший npTiers)
 npTiers = NULL;
//
 return ( true ); // УРА - УДАЛоСЬ сделать ПРОСиМОЕ..!
//
} //---- конец IncreaseOpsOnTier------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SaveScriptToCurrentFile(TObject *Sender)
{ // сохранить скрипт в текущий файл без вопросов
 SaveLuaScript( FileNameLua );
 Write_Config(); // сохранить файл конфигурации
} //-------SaveScriptDirect-----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::CloseSpfAtHome(TObject *Sender)
{ // попытка закрыть окно
 F1->Close();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall CloseAndRenameFileProtocol()
{
 char newFNP[_512];  // новое постоянное (для сохранения) имя файла протокола
 fclose( fptr_protocol ); // закрыли файл протокола исполнения скрипта
 snprintf(newFNP,sizeof(newFNP), "%s%s%s!%s%s", PathToSubDirOutData, "protocol!",
                                   ExtractFileName(FileNameLua),
                                   uniqueStr,     ".txt");
 return RenameFile( FileNameProtocol, newFNP ); // переименовали файл протокола
} // ----- конец CloseFileNameProtocol -----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::CreateNewScript(TObject *Sender) 
{ // начать писать новый скрипт
 char str[_1024];
//
// если в TR0 есть хоть что-то - спросить о необходимости сохранения или отмене нового скрипта
 if( TED0->Lines->Count != 0 ) // есть несколько строк
  {
   switch(MessageBox(0, "Имеется несохранённый текст. Сохранить его?",
                        "Предупреждение",
                         MB_YESNO | MB_ICONWARNING | MB_TOPMOST))
   {case IDYES: // нажата кнопка Yes
//              SD1->InitialDir = ExtractFilePath ( ParamStr(0) ); // сохраняем в текущий каталог
              SD0->InitialDir = ExtractFilePath ( Application->ExeName ); // сохраняем в текущий каталог
              if( SD0->Execute() ) // если что-то выбрали...
               {
                SaveLuaScript( SD0->FileName.c_str() ); // сохранили d файл
// устарело..!  TMS->HistoryList->Add( SD1->FileName ); // запомнили имя файла в списке
               }
              break;
    case IDNO:  // нажата кнопка No
              break;
   } //конец блока SWITCH
  } // конец if
//
 TED0->Clear(); // очистить TED0
 snprintf(str,sizeof(str), first_F1, PutDateTimeToString(0)); // начальная строка Lua !!!!!
 TED0->Lines->Add( str ); // добавить строку
//
 IndicateColRowNumberOfEV0(); // выводим номер строки и столбца под курсором
//
} //----конец CreaneNewScript --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SaveScriptToFile(TObject *Sender)
{ // сохранить скрипт в файл
 SD0->InitialDir = ExtractFilePath ( Application->ExeName ); // сохраняем в текущий каталог
//
 if( SD0->Execute() ) // если что-то выбрали...
 {
  SaveLuaScript( SD0->FileName.c_str() ); // сохранили в файл содержимой TED0
  strNcpy( FileNameLua, SD0->FileName.c_str() ); // запомнили имя файла
  PutFileNameLua(); // вывод на форму
 }
//
} //--- конец SaveFileScript ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OpenFileScript(TObject *Sender)
{ // загрузить скрипт из файла
 OD_Lua->InitialDir = ExtractFilePath ( Application->ExeName ); // считываем из текущего каталога
//
 OD_Lua->Files->Clear(); // чистим историю
//
 if( OD_Lua->Execute() ) // если что-то выбрали...
 {
  TED0->LoadFromFile( OD_Lua->FileName ); // загрузили файл
  strNcpy( FileNameLua, OD_Lua->FileName.c_str() ); // запомнили имя файла скрипта
  PutFileNameLua(); // вывод на форму
  TEV0->SetFocus(); // фокус - на окно редактирования
  IndicateColRowNumberOfEV0(); // выводим номер строки и столбца под курсором
 }
//
} //--- конец OpenFileScript----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall PutFileNameLua()
{ // выводит имя файла скрипта на главную форму над окном редактирования скрипта
 char str[_512];
 snprintf( str,sizeof(str), "Файл скрипта: %s", FileNameLua );
 F1->L_FNS->Caption = str; // вывод на форму
} // --- конец PutFileNameLua -----------------------------------------------


void __fastcall TF1::MouseDown(TObject *Sender, TMouseButton Button,
                               TShiftState Shift, int X, int Y)
{ // нажатие мыши на EV0
 if( TEV0->Focused() ) // если EV0 в фокусе...
  IndicateColRowNumberOfEV0(); // выводим номер строки и столбца под курсором
}
//--- конец TF1::MouseDown -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall IndicateColRowNumberOfEV0()
{ // --- вычисляем номер строки и номер символа в этой строке в позиции курсора
//
 if( !TEV0->Focused() ) // если EV0 не в фокусе - ничего не делаем...
  return;
//
 TPoint XYPoint;
 char str[_128];
//
 XYPoint = TEV0->CursorPos; // текущее положение курсора
//
// --- добавляем "#строка/#столбец" (оба начинаются с 1) -----------------------
 snprintf(str,sizeof(str), "строка:%d столбец:%d", XYPoint.y+1, XYPoint.x+1 ); // координаты курсОра
 F1->L_RC->Caption = str;
//
} // --- конец IndicateColRowNumberOfEV0 ---------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall PutDateTimeToString(INT flag)
{ // выдача текущих даты и времени в строку с форматированием
 char str[_512];
//
 if( flag == 0 ) // некорректное имя файла ( символ ':' недопустИм )
  strNcpy( str, TDateTime::CurrentDateTime().FormatString("dd.mm.yyyy'/'hh:nn:ss:zzz").c_str() );
 else // корректное имя файла ( символ ':' недопустим )
  strNcpy( str, TDateTime::CurrentDateTime().FormatString("dd-mm-yyyy'_'hh-nn-ss-zzz").c_str() );
//
 return str ;
} // конец PutDateTimeToString -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::CopyToNotepad(TObject *Sender)
{ // весь текст передаётся в Notepad
 char FileName[_256];
 strNcpy( FileName, ChangeFileExt( FileNameLua, ".txt" ).c_str() );
//
 SaveLuaScript( FileName ); // сохранили в файл содержимой TED0
 ShellExecute( F1->Handle, NULL, FileName, NULL, NULL, SW_SHOWNORMAL ); // открыть файл FileName
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::AboutLua(TObject *Sender)
{ // о языке Lua в InterNet'е
 ShellExecute( F1->Handle, NULL, "http://ru.wikipedia.org/wiki/Lua", NULL, NULL, SW_SHOWNORMAL );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::AboutLuaDetail(TObject *Sender)
{ // о языке Lua в InterNet'е малость подробнее
 ShellExecute( F1->Handle, NULL, "http://www.lua.ru/doc/", NULL, NULL, SW_SHOWNORMAL );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::AboutLua53(TObject *Sender)
{ // о языке Lua ver 5.3 в InterNet'е
 ShellExecute( F1->Handle, NULL, "http://www.lua.org/manual/5.3/", NULL, NULL, SW_SHOWNORMAL );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::GetWebPage(TObject *Sender)
{ // WEB-страница о проекте SPF@home
 ShellExecute( F1->Handle, NULL, "http://vbakanov.ru/spf@home/spf@home.htm", NULL, NULL, SW_SHOWNORMAL );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::GetUserAPI(TObject *Sender)
{ // получить информацию о функциях пользовательского API
 ShellExecute( F1->Handle, NULL, "API_User.pdf", NULL, NULL, SW_SHOWNORMAL );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::AboutAlgoWiki(TObject *Sender)
{ // WEB-страница сайта AlgoWiki
 ShellExecute( F1->Handle, NULL, "https://algowiki-project.org/ru/", NULL, NULL, SW_SHOWNORMAL );
}
//---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall DisplayMessage( char* Level, char* funcName, char* Text, INT Err )
{ // показывает сообщение
//
// Err ? t_printf( "\n-%s- %s(): %s [err: %d] -%s-", Level, funcName, Text, Err, Level ) :
//       t_printf( "\n-%s- %s(): %s -%s-", Level, funcName, Text, Level ) ;
} // --- конец DisplayMessage---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Read_Config()
{ // восстанавливает данные в файл конфигурации
//
 TIniFile* tINI = new TIniFile(FileNameINI); // создали объект типа TIniFile
//
 F1->FD0->Font->Name    = tINI->ReadString(RWC.Sect1,  RWC.Sect1_Var1, "Arial"); // имя фонта
 F1->FD0->Font->Size    = tINI->ReadInteger(RWC.Sect1, RWC.Sect1_Var2,      12); // размер символов
 F1->FD0->Font->Color   = tINI->ReadInteger(RWC.Sect1, RWC.Sect1_Var3,       0); // цвет символов
//
 F1->FD0->Font->Charset = tINI->ReadInteger(RWC.Sect1, RWC.Sect1_Var4, 204); // кодовая страница
 F1->FD0->Font->Pitch   = tINI->ReadInteger(RWC.Sect1, RWC.Sect1_Var5,   0); // питч
//
 if( tINI->ReadBool(RWC.Sect1, RWC.Sect1_Var6, 0) == 1 ) // жирность
  F1->FD0->Font->Style = TFontStyles() << fsBold;
//
 if( tINI->ReadBool(RWC.Sect1, RWC.Sect1_Var7, 0) == 1 ) // наклон
  F1->FD0->Font->Style = TFontStyles() << fsItalic;
//
 if( tINI->ReadBool(RWC.Sect1, RWC.Sect1_Var8, 0) == 1 ) // подчёркивание
  F1->FD0->Font->Style = TFontStyles() << fsUnderline;
//
 if( tINI->ReadBool(RWC.Sect1, RWC.Sect1_Var9, 0) == 1 ) // перечёркивание
  F1->FD0->Font->Style = TFontStyles() << fsStrikeOut;
//
 TEV0->Font = F1->FD0->Font; // настроили окно RechEdit при загрузке !!!!!!!!!!!!
//
 F1->Top    = tINI->ReadInteger(RWC.Sect2, RWC.Sect2_Var1,   20); // положение и размеры главной формы
 F1->Left   = tINI->ReadInteger(RWC.Sect2, RWC.Sect2_Var2,   20);
 F1->Width  = tINI->ReadInteger(RWC.Sect2, RWC.Sect2_Var3, minW_F1);
 F1->Height = tINI->ReadInteger(RWC.Sect2, RWC.Sect2_Var4, minH_F1);
//
 partHeightStdout[0] = StrToFloat(tINI->ReadString(RWC.Sect2, RWC.Sect2_Var5, "0.2")); // относительная высота окна stdout
// partHeightStdout[0] = (partHeightStdout[0] > partHeightStdout[2]) ? partHeightStdout[2] : partHeightStdout[0];
// partHeightStdout[0] = (partHeightStdout[0] < partHeightStdout[1]) ? partHeightStdout[1] : partHeightStdout[0];
// применяться значение partHeightStdout[0] будет позднее - в TF1::OnResize_F1 ----
// F1->M0_stdout->Height = F1->PN0->Height * partHeightStdout[0]; // реальная высота окна stdout
//
 F2->Top    = tINI->ReadInteger(RWC.Sect3, RWC.Sect3_Var1,      10); // положение и размеры дочерней формы
 F2->Left   = tINI->ReadInteger(RWC.Sect3, RWC.Sect3_Var2,      10);
 F2->Width  = tINI->ReadInteger(RWC.Sect3, RWC.Sect3_Var3, minW_F2);
 F2->Height = tINI->ReadInteger(RWC.Sect3, RWC.Sect2_Var4, minH_F2);
//
 strNcpy( FileNameLua, tINI->ReadString(RWC.Sect4, RWC.Sect4_Var1, "noname.lua").c_str()); // имя файла скрипта
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
 PutParamsTiersOnTextFrame       = tINI->ReadInteger(RWC.Sect3, RWC.Sect3_Var5, 0); // выводить ли параметры ЯПФ в текстовый фрейм
 PutParamsTLDOnTextFrame         = tINI->ReadInteger(RWC.Sect3, RWC.Sect3_Var6, 0); // выводить ли параметры времени жизни данных в F2
//
 F1->Master_Timer->Interval      = tINI->ReadInteger(RWC.Sect6, RWC.Sect6_Var1, 10); // интевал главного таймера (мсек)
//
 F1->N5->Checked                 = tINI->ReadBool(RWC.Sect7, RWC.Sect7_Var1, false); // переносить ли принудительно вызодные операторы на самый нижний ярус ( 1/0 )
//
 delete tINI; // уничтожили объект - более не нужен !...
//
 TEV0->SetFocus(); // фокус - на окно редактирования
//
////////////////////////////////////////////////////////////////////////////////
// === загрузка схем цветов и синтексиса =======================================
////////////////////////////////////////////////////////////////////////////////
//
// --- загружаем цветовые и синтакс-схемы из текущего каталога -----------------
 if( FileExists( ExtractFileDir(Application->ExeName) + "\\" + AnsiString(ActiveColorScheme) + "." + extSchemes ) ) // если файл АКТИВНОЙ схемы ЦВЕТОВ существует...
  TED0->ColorSchemes ->LoadFromDirectory( ExtractFileDir( Application->ExeName ), extSchemes ); // загружаем ВСЕ СХЕМЫ
//
 if( FileExists( ExtractFileDir(Application->ExeName) + "\\" + AnsiString(ActiveColorScheme) + "." + extSchemes ) ) // если файл АКТИВНОЙ схемы СИНТАКСИСА существует...
  TED0->SyntaxSchemes->LoadFromDirectory( ExtractFileDir( Application->ExeName ), extSchemes );  // загружаем ВСЕ СХЕМЫ
//
// F2->L_GraphParams->Caption = ExtractFileDir(Application->ExeName) + "\\" + AnsiString(ActiveColorScheme) + "." + extSchemes ;
// Delay( 5000 );
// F2->L_GraphParams->Caption = ExtractFileDir(Application->ExeName) + "\\" + AnsiString(ActiveSyntaxScheme) + "." + extSchemes ;
//
// --- модифицируем строки подменю ---------------------------------------------
 F1->mnuColorScheme ->Caption = Format("Цветовая схема: %s[.%s]",   OPENARRAY(TVarRec, (AnsiString(ActiveColorScheme),  extSchemes) ) );
 F1->mnuSyntaxScheme->Caption = Format("Cхема синтаксиса: %s[.%s]", OPENARRAY(TVarRec, (AnsiString(ActiveSyntaxScheme), extSchemes) ) );
//
} // ----- конец Read_Config ----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Write_Config()
{ // сохраняет данные в файл конфигурации
//
 TIniFile* tINI = new TIniFile(FileNameINI); // создали объект типа TIniFile
//
 tINI->WriteString(RWC.Sect1,  RWC.Sect1_Var1, F1->FD0->Font->Name); // имя фонта
 tINI->WriteInteger(RWC.Sect1, RWC.Sect1_Var2, F1->FD0->Font->Size); // размер
 tINI->WriteInteger(RWC.Sect1, RWC.Sect1_Var3, F1->FD0->Font->Color); // цвет
//
 tINI->WriteInteger(RWC.Sect1, RWC.Sect1_Var4, F1->FD0->Font->Charset); // кодовая страница
 tINI->WriteInteger(RWC.Sect1, RWC.Sect1_Var5, F1->FD0->Font->Pitch); // питч
//
 tINI->WriteBool(RWC.Sect1, RWC.Sect1_Var6, F1->FD0->Font->Style.Contains(fsBold)); // жирность
 tINI->WriteBool(RWC.Sect1, RWC.Sect1_Var7, F1->FD0->Font->Style.Contains(fsItalic)); // курсив
 tINI->WriteBool(RWC.Sect1, RWC.Sect1_Var8, F1->FD0->Font->Style.Contains(fsUnderline)); // подчёркивание
 tINI->WriteBool(RWC.Sect1, RWC.Sect1_Var9, F1->FD0->Font->Style.Contains(fsStrikeOut)); // перечёркивание
//
 tINI->WriteInteger(RWC.Sect2, RWC.Sect2_Var1, F1->Top); // положение формы главного окна
 tINI->WriteInteger(RWC.Sect2, RWC.Sect2_Var2, F1->Left);
 tINI->WriteInteger(RWC.Sect2, RWC.Sect2_Var3, F1->Width);
 tINI->WriteInteger(RWC.Sect2, RWC.Sect2_Var4, F1->Height);
//
 DecimalSeparator = '.'; // разделитель целой и десятичной частей - точка
 tINI->WriteString(RWC.Sect2, RWC.Sect2_Var5, Format("%1.3f", OPENARRAY(TVarRec, (partHeightStdout[0])) ) );
//
 tINI->WriteInteger(RWC.Sect3, RWC.Sect3_Var1,    F2->Top); // положение формы дочернего окна
 tINI->WriteInteger(RWC.Sect3, RWC.Sect3_Var2,   F2->Left);
 tINI->WriteInteger(RWC.Sect3, RWC.Sect3_Var3,  F2->Width);
 tINI->WriteInteger(RWC.Sect3, RWC.Sect3_Var4, F2->Height);
//
// --- если путь к Lua-файлу = текущему каталогу, путь не пишем (только имя файла)
 if( !strcmp( ExtractFileDir(FileNameLua).c_str(),ExtractFileDir(ParamStr(0)).c_str() ) )
  strNcpy( FileNameLua,ExtractFileName(FileNameLua).c_str() );
//
 tINI->WriteString(RWC.Sect4, RWC.Sect4_Var1, FileNameLua); // имя файла скрипта
//
// tINI->WriteInteger(RWC.Sect5, "HeigthEd", TEV0->Heigth); // высота окна редактора
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
 tINI->WriteBool(RWC.Sect7, RWC.Sect7_Var1, F1->N5->Checked); // переносить ли принудительно вызодные операторы на самый нижний ярус ( 1/0 )
//
 delete tINI; // уничтожили объект - более не нужен !...
//
 MessageBeep( MB_OK ); // звуковое предупреждение...
//
} // ----- конец Write_Config -----------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnResize_F1(TObject *Sender)
{ // выполняется при каждом изменении размера главного окна
//
// теперь можем установить размеры главного окна проиложения
 F1->Width  = max( F1->Width,  minW_F1 ); // новый размер главного окна F1
 F1->Height = max( F1->Height, minH_F1 );
//
// внутренние компоненты окна F1
//
 PN0->Width  = F1->Width  -  24 ; // окно-контейнер текстовых фреймов
 PN0->Height = F1->Height - 137 ;
//
 PN->Width = PN0->Width; // полоска управляющих кнопок
//
 M0_stdout->Height = PN0->Height * partHeightStdout[0]; // реальная высота окна stdout
//
} //--- конец OnResize_F1 ------------------------------------------------------

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
{ // старт диалога выбора фонта
//
 if( FD0->Execute() )
  {
   TEV0->Font = FD0->Font; // окно редактирования
   M0_stdout->Font = FD0->Font; // фонт окна вывода stdout
   F2->M1->Font = FD0->Font; // фонт окна текстового вывода
// F2->M1->Font->Assign(FD0->Font); // фонт окна текстового вывода
   TEV0->SetFocus(); // фокус - на окно редактирования
   IndicateColRowNumberOfEV0(); // выводим номер строки и столбца под курсором
   Write_Config(); // сохранить настройки...
  }
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{ // вызывается при нажатии клавиши Key
//
 if( !TEV0->Focused() ) // если EV0 не в фокусе - ничего не делаем...
  return;
//
 IndicateColRowNumberOfEV0(); // выводим номер строки и столбца под курсором
//
} //-----конец TF1::OnKeyUp-----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SelectColorBackGround(TObject *Sender)
{ // выбор цвета фона окна редактирования Lua-скриптов
 CD0->Color = color_BackGround; // настроим предыдущее значение
 if( CD0->Execute() )
 {
  color_BackGround = CD0->Color; // новый цвет фона
  TEV0->Color = color_BackGround;
  Write_Config(); // запомним...
 }
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::LMD_RD0_Show(TObject *Sender)
{ // отрисовка окна диалога RD1
 SetWindowText( LMD_ERD0->Handle, "Параметры поиска и замены текста в редакторе Lua");
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::LMD_ERD0_Show(TObject *Sender)
{ // отрисовка окна диалога PD1
 SetWindowText( LMD_ERD0->Handle, "Печать текста из редактора Lua");
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::FD0_Show(TObject *Sender)
{ // отрисовка окна диалога FD1 (выбор фонта окна редактирования текста)
 SetWindowText( FD0->Handle, "Выбрать параметры шрифта встроенного редактора Lua");
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall StartByCommandLine( char* DefFileNameLua )
{ // начало выполнения с параметрами командной строки
 char FileNameProject[_256], // имя файла проекта
      str[6][_256], w[_256]; // рабочая строка
 FILE *fptr; // указатель на файл
//
// --- откроем файл протокола --------------------------------------------------
 fptr_protocol = fopen( FileNameProtocol, "wt" ); // открываем в режиме ЗАПИСИ + ТЕКСТ
//
// --- обрабатывем содержимое командной строки (единственный параметр) ---------
 strNcpy( FileNameProject, ParamStr( 1 ).c_str() ); // имя файла конфигурации
 snprintf( w,sizeof(w), "\n-I- Задан режим работы с командной строкой... -I-\n-I- Имя файла проекта: |%s| -I-",
             FileNameProject );
 tp_printf( w );
//
// --- вывод списка файлов в файле проекта -------------------------------------
 if(!(fptr = fopen( FileNameProject, "r")) ) // открыли для чтения
  {
   tp_printf( "\n-E- Невозможно прочитать файл проекта %s -E-\n-I- Загружаем скрипт %s -I-\n",
                 FileNameProject, DefFileNameLua );
//
   MessageBeep( MB_OK ); // звуковое предупреждение...
   Delay( -1 ); // ждём 1 сек
//
   return false;
  }
//
 for( int i=0; i<6; i++ ) // по всем 6 строкам FileNameProject
 {
  fgets( str[i], sizeof(str[i]), fptr ); // читаем в строку str[i]
//
  str[ i ][ strchr(str[i],'\n') - str[i] ] = '\0'; // заменяем ПС "конец строки" '\0'
//
  t_printf( str[i] );
//
  snprintf ( w,sizeof(w), "\n%s", str[i] );
  p_printf( w ); // допОлнили файл протокола
//
  if( strchr(str[i],';' ) ) // если в строке str[i] имеется ';'
   str[ i ][ strchr(str[i],';') - str[i] ] = '\0'; // заменяем ';' "конец строки" '\0'
//
  ReplaceManySpacesOne( str[i] ); // удаляем повторы пробелов внутри
  DeleteSpacesTabsAround ( str[i] ); // удаляем внешние пробелы
//
 } // конец по 6-ти строкам внутри  FileNameProject
//
 fclose( fptr ); // закрыть файл
//
 tp_printf( "-I- Конец содержимого файла проекта %s -I-", FileNameProject );
//
// --- работаем с файлом исходного текста Lua-скрипта --------------------------
 strNcpy( FileNameLua, str[0] );

 if( !FileExists( FileNameLua ) ) // файл не существует...
 {
  tp_printf( "\n-E- Заданного в проекте файла |%s| не существует -E-\n",
              FileNameLua );
  return false;
 }
//
// --- читаем файл дуг исходного графа -----------------------------------------
 strNcpy( FileNameEdges, str[1] ); // запомнили имя файла...
//
 if( !FileExists( FileNameEdges ) ) // файл не существует...
 {
  tp_printf( "\n-E- Заданного в проекте файла |%s| не существует -E-\n",
               FileNameEdges  );
  return false;
 }
//
 c_ReadEdges( FileNameEdges ); // пытаемся загрузить файл ИГА
//
// --- читаем файл параметров ОПЕРАТОРОВ ---------------------------------------
 strNcpy( FileNameParamsOps, str[2] );
 c_LoadFileNameParamsOps( FileNameParamsOps );
//
// --- читаем файл параметров ВЫЧИСЛИТЕЛЕЙ -------------------------------------
 strNcpy( FileNameParamsCalcs, str[3] );
 c_LoadFileNameParamsCalcs( FileNameParamsCalcs );
//
// --- читаем файл параметров (мер) ВЕРШИН -------------------------------------
 strNcpy( FileNameParamsVertices, str[4] );
 c_LoadFileNameParamsVertices( FileNameParamsVertices );
//
// --- читаем файл параметров (мер) ДУГ ----------------------------------------
 strNcpy( FileNameParamsEdges, str[5] );
 c_LoadFileNameParamsEdges( FileNameParamsEdges );
//
 fclose( fptr_protocol ); // закрыли файл протокола... потом снова откроем!...
//
 return true;
//
} //--- конец StartByCommandLine -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnShow_F1(TObject *Sender)
{ // вызывается при показе главной формы
 char str[_512] = "\0";
//
// -----------------------------------------------------------------------------
 F2->Show(); // показать окно формы F2 в НЕМОДАЛЬНОМ РЕЖИМЕ
 F2->L_TMM->Caption = TitleF2; // заголовок окна
// -----------------------------------------------------------------------------
 Read_Config(); // читать файл конфиг.(параметры фонта и посл. файла Lua-скпипта)
//
 strNcpy( str, FileNameLua ); // запомнили имя файла скрипта из Config'а
//
// --- читаем командную строку -------------------------------------------------
 if( ParamCount() == 1 ) // не 1 параметр в командной cтроке (не считая полного пути к файлу)
 {
  flagCommandLine = StartByCommandLine( str ); //  обрабатываем файл по умолчанию str
//
//  flag = true; // автоматически стартовать Lua-скрипт
//
  if( FileExists( FileNameLua ) ) // если файл скрипта существует...
  {
   PutFileNameLua(); // вывод на форму
   TED0->LoadFromFile( FileNameLua );// загрузить в TR0
  } // конец if FileExists..
 } // конец if ParamCount...
//
 else
//
 if( FileExists( str ) ) // если файл из Config'а существует...
 {
  strNcpy( FileNameLua, str ); // восстановили имя файла скрипта
  PutFileNameLua(); // вывод на форму
  TED0->LoadFromFile( FileNameLua );// загрузить в TR0
 }
 else
 {
  TED0->Clear(); // очистить TR0
  snprintf(str,sizeof(str), first_F1, PutDateTimeToString(0)); // начальная строка для Lua
  TED0->Lines->Add( str ); // добавить строку
 }
//
 c_ClearDiagrArea(); // очистить поле отрисовки графика
//
 IndicateColRowNumberOfEV0(); // выводим номер строки и столбца под курсором
////////////////////////////////////////////////////////////////////////////////
//
// --- начинаем выполнение программы -------------------------------------------
 if( flagCommandLine ) // автоматически стартовать Lua-скрипт
 {
  StartLuaScript( NULL );
//
////////////////////////////////////////////////////////////////////////////////
  fclose( fptr_protocol ); // закрыли файл протокола исполнения скрипта
//
  DeleteFile( stdinFileName );  // временный файл Lua-скрипта ( stdin )
   fclose( fptr_stdout );
  DeleteFile( stdoutFileName ); // stdout
   fclose( fptr_stderr );
  DeleteFile( stderrFileName ); // stderr
//
// --- конец без показа окна редактирования ------------------------------------
  F2->Close(); // закрыли F2 - форму выдачи данных
//
  F1->OnClose = OnClose_1_F1; // "подмЕним"обработчик события OnClose_F1 (закрытие формы F1)
//
  F1->Close(); // уничтожили F1 - главное окно
 }
//
  SessionStartTime = (__int64) ( ((double)TDateTime::CurrentDateTime()-365.0*100) * 365.0*24*60*60*1000 ); // отняли 100*365 дней (результат в мсек)...
  Work_LogInOut( 0 ); // сообщить о начале работы программы SPF_CLIENT.EXE (сообщение "LogIn")
//
} //--- конец OnShow_F1 --------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnClose_1_F1(TObject *Sender, TCloseAction &Action)
{
 Action = caFree; // закрыть форму F1 без вопросов
} // ---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::M0_stdout_KeyDown(TObject *Sender, WORD &Key,
                                       TShiftState Shift)
{ // нажатие Ctrl+A на M0_stdout - выделение всего содержимого F1->M0_stdout
//
 if( !TM0_stdout->Focused() ) // фокус на F1->M0_stdout ?
  return;
//
 if( Shift.Contains(ssCtrl) && Key == 0x41 ) // Ctrl+A (лат)
  TM0_stdout->SelectAll();
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SelectSColorSheme(TObject *Sender)
{ // выбор цветовой схемы
 LMD_ECSD0->ColorScheme = ActiveColorScheme ; // настраиваем диалог на работу с активной цветовой схемой
 LMD_ECSD0->Title = Format("Цветовая схема: %s[.%s]", OPENARRAY(TVarRec, (AnsiString(ActiveColorScheme),extSchemes) ) );
 if( LMD_ECSD0->Execute() ) // стандартный диалог работы с цветом
  {}
 Beep();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SelectSyntaxSheme(TObject *Sender)
{ // синтаксические правила (схема ситтаксиса)
 LMD_ESSD0->SyntaxScheme = ActiveSyntaxScheme ; // настраиваем диалог на работу с активной схемой синтаксиса
 LMD_ESSD0->Title = Format("Схема синтаксиса: %s[.%s]", OPENARRAY(TVarRec, (AnsiString(ActiveSyntaxScheme),extSchemes) ) );
 if( LMD_ESSD0->Execute() ) // стандартный диалог работы с синтаксисом
  {}
 Beep();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::GotoLineN(TObject *Sender)
{ // переход к строке по номеру
 int Line = -1;
 int res = LMDEditAskGoToLine(LMD_EV0->Document->LinesCount, Line);
 if (res == mrOk)
  LMD_EV0->GotoPhysLine(Line);
//
 Beep();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SPL0Moved(TObject *Sender)
{ // вызывается при перемещении сплиттера
 partHeightStdout[0] = 1.0 * M0_stdout->Height / F1->PN0->Height ; // доля высоты окна stdout
//
 if( partHeightStdout[0] > partHeightStdout[2] ) // ограничиваем сверху
 {
  partHeightStdout[0] = partHeightStdout[2];
  M0_stdout->Height = PN0->Height * partHeightStdout[0];
  Beep();
 }
//
 if( partHeightStdout[0] < partHeightStdout[1] ) // ограничиваем снизу
 {
  partHeightStdout[0] = partHeightStdout[1];
  M0_stdout->Height = PN0->Height * partHeightStdout[0];
  Beep();
 }
//
} //----------------------------------------------------------------------------


void __fastcall TF1::OnClickGetLua_01(TObject *Sender)
{ // получить файл Lua_01 с сервера
 GetFileFromServer( "spf@home\\content\\Test_Lua_API.lua" ); // не забывать "\\"
} //----------------------------------------------------------------------------


void __fastcall TF1::OnClickGetEdg_01(TObject *Sender)
{  // получить файл Edg_01 с сервера
 GetFileFromServer( "spf@home\\content\\e17039_o9853_t199.gv" );  // не забывать "\\"
} //----------------------------------------------------------------------------


void __fastcall TF1::OnClickGetEdg_02(TObject *Sender)
{ // получить файл Edg_02 с сервера
 GetFileFromServer( "spf@home\\content\\e2367_o1397_t137.gv" );  // не забывать "\\"
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::CreateUpperSPFAndPutToTextFrame(TObject *Sender)
{ // построить первичную ЯПФ по диалогом выбранному файлу
 OD_Edg->InitialDir = ExtractFilePath ( Application->ExeName ); // считываем из текущего каталога
//
 OD_Edg->Files->Clear(); // чистим историю
//
 if( !OD_Edg->Execute() ) // если выбор файла не был сделан...
 {
  flagExistsEdges = false;
  flagExistsTiers = false;
  return; // ...плохо!
 }
 else
  strNcpy( FileNameEdges, OD_Edg->FileName.c_str() ); // новое имя файла описания информационного графа
//
 if ( c_ReadEdges( FileNameEdges ) == false ) // если не удалось прочитать данные информационного графа в массив Mem_Edges[][]...
 {
  t_printf( "\n-!- %s(): файл описания информационного графа %s прочитать не удалось -!-", UpperCase(FileNameEdges), __FUNC__ );
  MessageBeep( MB_OK ); // звуковое предупреждение...
  flagExistsEdges = false;
  flagExistsTiers = false;
  return ;
 }
//
  c_CreateTiersByEdges( FileNameEdges ); // вычисление ЯПФ в "верхней" форме в окно текстовых данных
//
  c_ClearDiagrArea(); // очистить графическое представление Я
  c_DrawDiagrTiers(); // выдать ЯПФ в графическом виде
//
  c_PutTiersToTextFrame(); // вывод ЯПФ в "верхней" форме в окно текстовых данных
  c_PutParamsTiers(); // вывод параметров графа и его ЯПФ на главную форму и в файл протокола
//
  flagExistsEdges = true;
  flagExistsTiers = true;
//
} //---конец CreateUpperSpfBySelectedIgaFile -----------------------------------

 ////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::CreateBottomSPFAndPutToTextFrame(TObject *Sender)
{ // построить первичную ЯПФ по диалогом выбранному файлу
 OD_Edg->InitialDir = ExtractFilePath ( Application->ExeName ); // считываем из текущего каталога
//
 OD_Edg->Files->Clear(); // чистим историю
//
 if( !OD_Edg->Execute() ) // если выбор файла не был сделан...
 {
  flagExistsEdges = false;
  flagExistsTiers = false;
  return; // ...плохо!
 }
 else
  strNcpy( FileNameEdges, OD_Edg->FileName.c_str() ); // новое имя файла описания информационного графа
//
 if ( c_ReadEdges( FileNameEdges ) == false ) // если не удалось прочитать данные информационного графа в массив Edges[][]...
 {
  t_printf( "\n-!- %s(): файл описания информационного графа %s прочитать не удалось -!-", UpperCase(FileNameEdges), __FUNC__ );
  MessageBeep( MB_OK ); // звуковое предупреждение...
  flagExistsEdges = false;
  flagExistsTiers = false;
  return ;
 }
//
// ---- ур-ря... со считыванием данных всё OK...................................
//
  c_CreateTiersByEdges( FileNameEdges ); // вычисление ЯПФ в "верхней" форме в окно текстовых данных
  c_ClearDiagrArea(); // очистить графическое представление
  c_DrawDiagrTiers(); // выдать ЯПФ в графическом виде
//
//==============================================================================
//
  c_CreateTiersByEdges_Bottom( FileNameEdges ); // вычисление ЯПФ в "нижней" форме в окно текстовых данных
//
  c_ClearDiagrArea(); // очистить графическое представление
  c_DrawDiagrTiers(); // выдать ЯПФ в графическом виде
//
  c_PutTiersToTextFrame(); // вывод ЯПФ в "нижней" форме в окно текстовых данных
  c_PutParamsTiers(); // вывод параметров графа и его ЯПФ на главную форму и в файл протокола
//
  flagExistsEdges = true;
  flagExistsTiers = true;
//
} //---конец CreateLowerSpfBySelectedIgaFile -----------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::ReadEdgesFileAndPutToTextFrame(TObject *Sender)
{ // выбирает ИГА-файл, читает его в Mem_Edges[][] и выводит в текстовый фрейм ------
//
 OD_Edg->InitialDir = ExtractFilePath ( Application->ExeName ); // считываем из текущего каталога
//
 OD_Edg->Files->Clear(); // чистим историю
//
 if( !OD_Edg->Execute() ) // если выбор файла не был сделан...
 {
  flagExistsEdges = false;
  flagExistsTiers = false;
  return; // ...плохо!
 }
 else
  strNcpy( FileNameEdges, OD_Edg->FileName.c_str() ); // новое имя файла описания информационного графа
//
 if ( !c_ReadEdges( FileNameEdges ) ) // если не удалось прочитать данные информационного графа в массив Mem_Edges[][]...
 {
  t_printf( "\n-!- %s(): файл описания информационного графа %s прочитать не удалось -!-", UpperCase(FileNameEdges), __FUNC__ );
  MessageBeep( MB_OK ); // звуковое предупреждение...
  flagExistsEdges = false;
  flagExistsTiers = false;
  return ;
 }
//
 c_PutEdgesToTextFrame(); // вывести ИГА в текстовое окно ----------------------
//
 flagExistsEdges =
 flagExistsTiers = false;
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_CreateTiersByEdges( char* FileName )
{ // создаёт (на основе ИГА из файла FileName первоначальную (в "верхней" форме)
// - ярусно-параллельную форму (ЯПФ) графа в массиве Tiers[][]
// - и вычисляет общее количество операторов в информационном графе алгоритма
 INT iOp, fromOp, toOp, i;
 char str[_2048], w[_256];
//
 INT old_nMoves = nMoves; // запомнили значение счётчика перемещений операторов с яруса на ярус ЯПФ
//
 if( !c_ReadEdges( FileName ) ) // читаем ИГА-файл в массив Mem_Edges[][]
 {
  flagExistsEdges =
  flagExistsTiers = false;
//
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 _maxTiers     = _maxTiersPrim; // текущие значения - без Prim
 _maxOpsOnTier = _maxOpsOnTierPrim;
//
 pTiers = (INT*) realloc( pTiers, (_maxTiersPrim+1) * (_maxOpsOnTierPrim+1) * sizeof(INT) ); // реаллокировали память под Tiers[][]...
//
 if( pTiers == NULL ) // совсем плохо - память в "куче" закончилась
 {
  snprintf(str,sizeof(str), "нехватка памяти для размещения массива Tiers[][] (Prim). Затребовано %d x %d = %d элементов...",
                _maxTiersPrim+1, _maxOpsOnTierPrim+1, (_maxTiersPrim+1) * (_maxOpsOnTierPrim+1));
  flagExistsTiers = false ; // массив Tiers[][] не создан...
  DisplayMessage( "E", __FUNC__, str, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  MessageBeep( MB_ICONEXCLAMATION ); // звуковое предупреждение...
  MessageBox(0, str, "Предупреждение", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 snprintf(str,sizeof(str), "массив Tiers[][] (Prim) перераспределён на %d x %d = %d элементов",
               _maxTiersPrim+1, _maxOpsOnTierPrim+1, (_maxTiersPrim+1) * (_maxOpsOnTierPrim+1));
 DisplayMessage( "I", __FUNC__, str, 0 ); // выдать сообщение
//
////////////////////////////////////////////////////////////////////////////////
//==============================================================================
////////////////////////////////////////////////////////////////////////////////
//
// --- в Tiers[0][*] помещаем операторы ВХОДНОГО (нулевого) яруса --------------
// --- это операторы, НЕ ИМЕЮЩИЕ ВХОДОВ (только выходы) ------------------------
 Tiers(0,0) = 0; // число операторов ВХОДНОГО (нулевого) яруса
//
 for(INT iEdges=1; iEdges<=nEdges; iEdges++) // по всем дугам
  for(i=0; i<=1; i++) // по ВХОДЯЩИМ и ВЫХОДЯЩИМ операторам данной дуги
  {
   iOp = Edges(i,iEdges); // взяли номер оператора
   if( !c_GetCountInEdgesByOp( iOp )  &&  // этот оператор не имеет ВХОДЯЩИХ дуг "И"
       !c_IsOpExistOnTier( iOp, 0 ) ) // iOp НЕ ПРИСУТСТВУЕТ на ярусе iTier
   {
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( ( Tiers(0,0) + 3 ) >= _maxOpsOnTier ) // то же, но с БоЛЬШИМ запасом
  if( IncreaseOpsOnTier( 0, _maxOpsOnTier * stockMem, 1 ) == false ) // неудача перераспределения памяти
  {
   flagExistsTiers = false ; // массив Tiers[][] не создан...
   DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
   return ERR_NOT_MASSIVE_TIERS ;
  }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
    Tiers(0,0) ++ ; // увеличили на 1 число операторов на ВХОДНОМ (нулевом) уровне
    Tiers(0, Tiers(0,0)) = Edges(i,iEdges); // запомнили его в столбце Tiers(0,j)
//
   } // конец if
  } // конец цикла по i
// конец цикла по iEdges -------------------------------------------------------
//
////////////////////////////////////////////////////////////////////////////////
// --- начинаем выбирать операторы по ярусам начиная с iTier=1 до ??? ----------
 for(INT iTier=1; iTier<=_maxTiers; iTier++) // пока не знаем, сколько будет ярусов...
 {
  Tiers(iTier,0) = 0; // (начальное) число операторов на ярусе iTier
// на ярусе iTier располагаем операторы, завИсимые по дугам от операторов на
// ярусе iTier-1; этих операторов ровно Tiers[iTier-1][0] штук
  for(INT j=1; j<=Tiers(iTier-1,0); j++) // по from-операторам на ярусе iTier-1
  {
   fromOp = Tiers(iTier-1,j); // номер fromOp ("от которого" дуга)
// --- ищем в списке дуг to-оператор, по дуге соответствующий from-оператору ---
   for(INT i=1; i<=nEdges; i++) // по всем дугам (связям операторов)
   {
    if( Edges(0,i) == fromOp ) // найдена дуга c from-оператором, соответствующим данному
    {
// --- зависит ли toOp=Mem_Edges[i] ещё от каких либо операторов, НЕ НАХОДЯЩИХСЯ
// --- НА ЯРУСАХ 1 - iTier ? Если зависит - ТАКОЙ НАМ НЕ ПОДХОДИТ !!!
     toOp = Edges(1,i); // вот от этого зависит fromOp !..
// --- при каких условиях оператор toOp может быть добавлен на ярус iTier ??????
     if( c_IsOpDependOnlyAboveTiers( toOp, iTier ) && /// если toOp зависит ТОЛЬКО
                 // от операторов на ВЫШЕЛЕЖАЩИХ ярусах (искл. данный iTier) "И"
        !c_IsOpExistOnTier( toOp, iTier ) ) // Op НЕ ПРИСУТСТВУЕТ на ярусе iTier
     {
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( ( Tiers(iTier,0)+1 ) >= _maxOpsOnTier ) // не помещаемся в _maxOpsOnTier...
  if( IncreaseOpsOnTier( iTier, _maxOpsOnTier * stockMem, 11 ) == false ) // неудача перераспределения памяти
  {
   flagExistsTiers = false ; // массив Tiers[][] не создан...
   DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
   return ERR_NOT_MASSIVE_TIERS ;
  }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// --- всё скопировано - можно продолжать работать уже с новым pTiers ----------
      Tiers(iTier,0) ++ ; // всё хорошо, можно увеличивать на 1 число операторов на ярусе iTier...
      Tiers(iTier, Tiers(iTier,0) ) = toOp; // в Tiers[iTier][*] соответствующий toOp
     } // конец if (  Is... / Is... )
    } // конец if( Mem_Edges[0][i] == fromOp )
   } // конец цикла по i (списку дуг)
// -----------------------------------------------------------------------------
  } // конец цикла по j (числу операторов на ярусе iTier-1)
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// --- анализируем, закончились ли ярусы ЯПФ -----------------------------------
  if( ( Tiers(iTier,0) != 0 ) && // если на ярусе iTier есть операторы...
      ( (iTier+1) >= _maxTiers ) ) // а строки массива Tiers[][] заканчиваются...
  {
// --- увеличиваем _maxTiers, а _maxOpsInTier оставляем тем же самым -----------
// --- в этом случае можно использовать realloc, обеспечивающий сохранность данных
   _maxTiers *= stockMem; // новое число строк с запасом stockMem
//
   pTiers = (INT*) realloc( pTiers,  (_maxTiers+1) * (_maxOpsOnTier+1) * sizeof(INT) ); // захват памяти под новый массив
//
   if( pTiers == NULL ) // совсем плохо - память в "куче" закончилась
   {
    snprintf(str,sizeof(str), "Нехватка памяти для размещения массива Tiers[][] (2). Затребовано %d x %d = %d элементов...",
                 _maxTiers+1, _maxOpsOnTier+1, (_maxTiers+1) * (_maxOpsOnTier+1));
    flagExistsTiers = false ; // массив Tiers[][] не создан...
    DisplayMessage( "E", __FUNC__, str, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
    MessageBeep( MB_ICONEXCLAMATION ); // звуковое предупреждение...
    MessageBox(0, str, "Предупреждение", MB_OK | MB_ICONWARNING | MB_TOPMOST);
    return ERR_NOT_MASSIVE_TIERS ;
   } // конец if ( npTiers == NULL )
//
   snprintf(str,sizeof(str), "массив Tiers[][] (2) перераспределён на %d x %d = %d элементов",
                 _maxTiers+1, _maxOpsOnTier+1, (_maxTiers+1) * (_maxOpsOnTier+1));
   DisplayMessage( "E", __FUNC__, str, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  }  // конец if ( Tiers(iTier,0) != 0 && ...
//
// --- всё скопировано - можно продолжать работать уже с новым pTiers ----------
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
  if( Tiers(iTier,0) == 0 ) // не найдено ни одного to-оператора на ярусе iTier
  {
   nTiers = iTier - 1 ; // запомнили число ярусов
   break; // на этом ярусе нет to-операторов... ярусы кончились... выбрасываемся из цикла!
  } // заполнено iTier-1
////////////////////////////////////////////////////////////////////////////////
//
 } // конец цикла по iTier (ярусам ЯПФ) ========================================
//
////////////////////////////////////////////////////////////////////////////////
  nOps = 0; // общее число операторов БЕЗ ВХОДНЫХ (глобальное)
// --- вычисляем cуммарное количество операторов (суммируем по ярусам ЯПФ) -----
 for(INT iTier=1; iTier<=nTiers; iTier++) // по числу ярусов ЯПФ кроме ВХОДНОГО (нулевого)
  nOps += Tiers(iTier,0);
//
////////////////////////////////////////////////////////////////////////////////
//
 flagExistsTiers = true ; // признак того, что ЯПФ построена
//
 TestExistInOutAtAllOps(); // тестирование входов и выходов
//
 nOpsInput  = Tiers( 0, 0 ); // число ВХОДНЫХ вершин (операторов)
 nOpsOutput = Tiers( nTiers, 0 ); // число ВЫХОДНЫХ вершин (операторов)
//
 t_printf( "\n-I- %s(): ЯПФ графа в \"верхней\" форме по файлу [%s] успешно построена -I-", __FUNC__, FileNameEdges );
//
 flagExistsTiers = true ; // массив Tiers[][] сформирован..!
//
 flagCalcTLD = false ; // paramsTLD не соответствует Tiers[][]
//
 if( F1->N5->Checked ) // если включён режим "приземления" всех всех выходных операторов...
  OutOpsMoveLowerTier(); // все выходные операторы перенести на самый нижний ярус
//
 nMoves = old_nMoves; // восстановили значение счётчика перемещений операторов с яруса на ярус ЯПФ
//
 return true ; // всё нормально - массив Tiers[][] в "верхней" форме построен
//
} // --- конец c_CreateTiersByEdges---------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_CreateTiersByEdges_Bottom( char* FileName )
{ // создаёт (на основе ИГА из файла FileName  первоначальную (в "нижней" форме)
// - ярусно-параллельную форму (ЯПФ) графа в массиве Tiers[][]
// - вычисляет общее количество операторов в информационном графе алгоритма
// - верифицирует корректность "нижней" формы ЯПФ (условие невозможности перенОса ВСЕХ операторов "вверх")
 UINT iTier, jOp, Op, errCount=0;
//
 INT old_nMoves = nMoves; // запомнили значение счётчика перемещений операторов с яруса на ярус ЯПФ
//
 if( !c_CreateTiersByEdges( FileName ) ) // читает ИГА-файл и создаёт ЯПФ в "верхней" форме
  return false ; // не удалось..!
//
 for( iTier=nTiers; iTier>=1; iTier-- ) // по ярусам ЯПФ снизу вверх
  for( jOp=Tiers( iTier,0 ); jOp>=1; jOp--) // по операторам на ярусе iTier справа налево
  {
   Op = c_GetOpByNumbOnTier( jOp, iTier ); // глобальный номер оператора
   c_MoveOpTierToTier( Op, c_GetMaxTierMaybeOp( Op ) ); // переносим оператор Op "вниз" ПО МАКСИМУМУ..!
  }
//
 t_printf( "-I- %s(): ЯПФ графа в \"нижней\" форме по \"верхней\" форме того же графа успешно построена -I-", __FUNC__ );
//
// --- верификация "нижней" формы ЯПФ ------------------------------------------
//
 for( iTier=1; iTier<=nTiers; iTier++ ) // по ярусам ЯПФ сверху вниз
  for( jOp=1; jOp<=Tiers( iTier,0 ); jOp++) // по операторам на ярусе iTier слева направо
   {
    Op = c_GetOpByNumbOnTier( jOp, iTier ); // глобальный номер оператора
    if( iTier != c_GetMaxTierMaybeOp( Op ) ) // оператор Op НЕ НА САМОМ НИЖНЕМ ЯРУСЕ..!
     errCount ++; // число некорректностей
   }
//
 if( !errCount ) // нет некорректностей...
  t_printf( "\n-I- %s(): ЯПФ графа в \"нижней\" форме успешно верифицирована -I-", __FUNC__ );
 else // что-то не то..!
  t_printf( "\n-E- %s(): ЯПФ графа в \"нижней\" форме не прошла верифицикацию [%d] -E-", __FUNC__ , errCount );
//
 flagExistsTiers = true ; // массив Tiers[][] сформирован..!
//
 flagCalcTLD = false ; // paramsTLD не соответствует Tiers[][]
//
 nMoves = old_nMoves; // восстановили значение счётчика перемещений операторов с яруса на ярус ЯПФ
//
 return true ; // всё нормально - массив Tiers[][] в "нижней" форме построен
//
} // --- конец c_CreateTiersByEdges_Bottom--------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::PutParAboutOp(TObject *Sender)
{ // выдать в текстовое окно параметры заданного оператора
 char str[_1024], tmp[_256];
 INT Tier,Op,i;
 bool flag;
//
 if( !flagExistsTiers ) // нет массива Tiers[][]
 {
  MessageBeep( MB_ICONASTERISK );
  return;
 }
//
////////////////////////////////////////////////////////////////////////////////
retry:
////////////////////////////////////////////////////////////////////////////////
//
 strNcpy( str, IntToStr(c_GetOpByNumbOnTier(1,1)).c_str() ); // умолчание: 1-й оператор 1-го яруса
 AnsiString defStr = AnsiString( str ); // все входные параметры InputQuery суть типа AnsiString..!
////////////////////////////////////////////////////////////////////////////////
 flag = InputQuery( "Получение данных об операторе", "Введите номер оператора в данной ЯПФ", defStr );
////////////////////////////////////////////////////////////////////////////////
 if( !flag ) // не была нажата Ok...
 {
  MessageBeep( MB_ICONASTERISK );
  return;
 }
//
 if( sscanf( defStr.c_str(), "%d", &Op ) != 1 ) // если НЕнормальное преобразование строки в число...
 {
  MessageBeep( MB_ICONASTERISK );
  goto retry;
 }
////////////////////////////////////////////////////////////////////////////////
 if( c_GetTierByOp(Op) == ERR_COMMON ) // оператора с таким номером в ЯПФ не существует..!
 {
  MessageBeep( MB_ICONHAND );
  goto retry;
 }
//
 PutParamsAboutSelectOp( Op ); // выдать в текстовое окно параметры оператора Op
//
} // ----- PutParAboutOp -------------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall PutParamsAboutSelectOp( INT Op )
{ // выдать в текстовое окно параметры заданного оператора Op
 char str[_1024], tmp[_256];
 INT i, Tier;
 bool flag;
//
 Tier = c_GetTierByOp(Op); // оператор Op находится на ярусе Tier
 t_printf( "\nПАРАМЕТРЫ ОПЕРАТОРА %d/%d (#опер/#ярус) для данной ЯПФ:", Op, Tier );
////////////////////////////////////////////////////////////////////////////////
 strNcpy( str, "" ); // очистка строки
 for( i=1; i<=c_GetCountInEdgesByOp(Op); i++ ) // цикл по всем ВХОДяЩИМ дугам данного оператора
 {
  snprintf( tmp,sizeof(str), " %d/%d", c_GetNumbInEdgeByOp(i,Op), c_GetTierByOp(c_GetNumbInEdgeByOp(i,Op)) ); // оператор/ярус
  strcat( str, tmp ); // добавляем по каждому ВХОДЯЩЕМУ оператору..
 }
//
 if( !Tier ) // входной (нулевой) ярус
  t_printf( "1. Оператор %d принадлежит входному (нулевому) ярусу", Op );
 else
  t_printf( "1. Оператор %d зависит от %d оператора/ов: %s", Op, c_GetCountInEdgesByOp(Op), str );
////////////////////////////////////////////////////////////////////////////////
 strNcpy( str, "" ); // очистка строки
 for( i=1; i<=c_GetCountOutEdgesByOp(Op); i++ ) // цикл по всем ВЫХОДяЩИМ дугам данного оператора
 {
  snprintf( tmp,sizeof(str), " %d/%d", c_GetNumbOutEdgeByOp(i,Op), c_GetTierByOp(c_GetNumbOutEdgeByOp(i,Op)) ); // оператор/ярус
  strcat( str, tmp ); // добавляем по каждому ВЫХОДЯЩЕМУ оператору..
 }
//
 if( Tier == nTiers ) // выходной ярус
  t_printf( "2. Оператор %d принадлежит выходному ярусу", Op );
 else
  t_printf( "2. От оператора %d зависят %d оператор/ов: %s", Op, c_GetCountOutEdgesByOp(Op), str );
////////////////////////////////////////////////////////////////////////////////
 if( !Tier ) // входной (нулевой) ярус
  t_printf( "3. Оператор %d может располагаться только на входном (нулевом) ярусе", Op);
 else
  t_printf( "3. Оператор %d может располагаться на ярусах от %d до %d (включительно)", Op, c_GetMinTierMaybeOp(Op), c_GetMaxTierMaybeOp(Op) );
//
 for( i=1; i<=nEdges; i++ ) // по всем дугам ИГА (индексация дуг начинается с 1)
  if( Edges(0,i) == Op ) // если исходящая вершина дуги равна Op...
  {
   strcpy( str,Mem_Edges[ i ].Operators ); // скопировали в str строку из списка дуг ИГА
   break;
  }
//
 if( !Tier ) // входной (нулевой) ярус
  t_printf( "4. Комментарий(*): %s", str );
 else
  t_printf( "4. Комментарий(*): %s\n", str );
//
} // ----- PutParamsAboutSelectOp ----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::StartLuaScript(TObject *Sender)
{ // начать выполнение Lua-скрипта из LMD_EV0
//
 Set_FileNames_All_Protocols(); // подготовили имена всех файлов протоколов (для Out!Data)
//
 SaveLuaScript( FileNameLua ); // сохранили в файл содержимое TED0
//
 ticks = 0; // обнуляем глобальный счётчик тиков
//
 max_Events = _128; // начальный размер массива Mem_EV
 Mem_EV = (ev*) realloc( Mem_EV, max_Events*sizeof(ev) ); // массив событий
 i_Events = -1; // занято элементов в массиве событий (первый инкремент будет ПЕРЕД добавлением данных в массив Mem_EV[])
 Master_Timer-> Enabled = true; // запустили Master_Timer
 flag_Busy = false; // вызов Lua по таймеру разрешён
//
 Write_Config(); // сохранить файл конфигурации
//
 if( luaExecute ) // Lua в данный момент уже выполняется !!!!!!!!!!!!!!!!!!!!!!!
  return;
//
 luaExecute = true; // теперь Lua выполняется !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
 c_ClearTextFrame(); // очистить текстовый фрейм
 c_ClearDiagrArea(); // очистить графику
//
 F2->L_GP->Caption = ""; // очистить строки параметров графа
 SetActiveWindow( F2->Handle ); // дочернее окно F2 выдвинуть на передний план
//
 t_printf( first_F2, PutDateTimeToString(0) ); // выдача в текстовый фрейм
 MessageBeep( MB_ICONASTERISK );
//
// =============================================================================
 flagHook = false; // "ловушка" отключена
////////////////////////////////////////////////////////////////////////////////
//
 Upload_Data( 0 ); // выгрузить LUA-файл на сервер ( Rule == 0 )
//
 RunLuaScript(); // запуск Lua-скрипта на выполнение в основном потоке
//
 Upload_Data( 1 ); // выгрузить PRO-файл на сервер ( Rule == 1 )
//
 return;
//
} //----конец StartLuaScript----------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::StopLuaScript(TObject *Sender)
{ // остановить выполнение скрипта
//
 if( !luaExecute ) // в данный момент Lua не выполняется
  return;
 else
 {
  flagHook = true; // "взвелИ" флаг для для срабатывания ловушки
//  t_printf( "\n--->%d %d [%d] (%s)", luaExecute, flagHook, lua_gethookcount(L), __FUNc__);
 }
//
} //----конец StopLuaScript-----------------------------------------------------


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
  } // конец for(;;)
//
  CloseHandle(pi.hThread);
  CloseHandle(pi.hProcess);
  CloseHandle(ReadPipeHandle);
  CloseHandle(WritePipeHandle);
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int luaPanic( lua_State* L )
{  // функция паники Lua
 Beep();
 tp_printf( "\n\n\n\n\n|%s|%s|\n\n\n\n\n", lua_tostring( L,-1 ), __FUNC__ );
 Beep();
//
 char str[_256];
 strNcpy( str, lua_tostring( L,-1 ) );
 ShowBreakpoint( str ); // покажем строку останова
//
 longjmp( env_StopSessionLua, 1 ); // нелокальный переход к точке setjmp !!!!!!!
//
// ----- при RETURN выполняется exit(EXIT_FAILURE - вся программа заканчивается)
//
} // ----- конец luaPanic ------------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Set_FileNames_All_Protocols()
{ // определяет имена всех файлов протоколов расчётов (в подкаталоге Out!Data)
// генерим уникальную строку Data-Time -----------------------------------------
 strNcpy( uniqueStr, PutDateTimeToString(1) ); // уникальная строка ( дата + время до мсек )
// --- полный путь к каталогу сброса рассчитанных данных (включая слэш в конце)
 snprintf( PathToSubDirOutData,sizeof(PathToSubDirOutData), "%s%s\\", ExtractFilePath(Application->ExeName), NameSubDirOutData );
///
 if( !DirectoryExists( PathToSubDirOutData ) ) // если не существует этого каталога...
  if( !CreateDir( PathToSubDirOutData ) ) // если не удалось создать...
   strNcpy( PathToSubDirOutData, '\0' ); // обнуляем путь к подкаталогу PathToSubDirOutData
// далее генерИм уникальные имена файлов для данного конкректного расчёта ------
 char tmp[_512], cnst[_512];
//
 sprintf( cnst, "!%s!%s.txt", ExtractFileName(FileNameLua), uniqueStr ); // постоянная часть имени
//
 snprintf( tmp, sizeof(tmp), "%s%s%s", PathToSubDirOutData, "stdin",  cnst ); // полный путь к stdin
  snprintf( stdinFileName, sizeof(stdinFileName), "%s", tmp );
//
 snprintf( tmp, sizeof(tmp), "%s%s%s", PathToSubDirOutData, "stdout", cnst ); // полный путь к stdout
  snprintf( stdoutFileName, sizeof(stdoutFileName), "%s", tmp );
//
 snprintf( tmp, sizeof(tmp), "%s%s%s", PathToSubDirOutData, "stderr", cnst ); // полный путь к stderr
  snprintf( stderrFileName, sizeof(stderrFileName), "%s", tmp );
//
 snprintf( tmp, sizeof(tmp), "%s%s%s", PathToSubDirOutData, "protocol", cnst ); // полный путь к protocol
  snprintf( FileNameProtocol, sizeof(FileNameProtocol), "%s", tmp );
//
} // --- конец Set_FileNames_All_Protocols -------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::PutTLDToTextFrameAndDiagr(TObject *Sender)
{ // F6 - построить и выдать в текстовое окно диаграмму жизни данных (TLD) -----
//
 c_CalcParamsTLD() ; // подготовили TLD-данные в ParamsTLD
//
 c_PutTLDToTextFrame() ; // вывод в текстовый фрейм
//
 c_ClearDiagrArea() ; // очищаем место под линейчатый график
//
 c_DrawDiagrTLD() ; // выводим TLD-данные в форме линейчатого графика
//
} // ----- TF1::PutTLDToTextFrameAndDiagr --------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall SaveLuaScript( char *FileName ) // сохраняем файл Lua-скрипта в файл без вопросов
{
//
 try // обработка возможной ошибки при вызове TED0->SaveToFile( FileName )
 {
  TED0->SaveToFile( FileName ); // сохранить скрипт в текущий файл без вопросов (без полного пути...)
 } // конец try
 catch( ... )
 {
  char str[_256];
  sprintf( str, "Проблемы с сохранением Lua-программы в файл %s (функция %s())", FileName, __FUNC__ );
  MessageBeep( MB_ICONEXCLAMATION ); // звуковое предупреждение...
  tpe_printf( "\n-W- %s -W-\n", str );
  MessageBox(0, str, "Предупреждение", MB_OK | MB_ICONWARNING | MB_TOPMOST);
//
  longjmp( env_StopSessionLua, 1 ); // нелокальный переход к точке setjmp !!!!!!
//
 } // конец cath( ... )
//
} // ----- конец SaveLuaScript ------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall stackDump(lua_State *L, char *s)
{ // выдаёт содержимое Lua-стека экземпляра L (с предварЯющей строкой s)
//
 if( !DEBUG ) // ничего не делаем...
  return;
//
 char str[_512];
 const char *w;
 size_t l;
 int top = lua_gettop(L); // глубина стэка
//
 t_printf( "\n%s(): %s глубина стека= %d", __FUNC__, s, top );
//
 if( !top ) // глубина стека 0... нЕчего  выводить!..
  return;
//
 for (int i=1; i<=top; i++) // повторять для каждого уровня стэка
 {
//
  int tp=lua_type(L,i);
  t_printf( "------ %d %d %d", i,top,tp );
//
  switch( tp )  // взять тип данного на уровне i стэка
  {
   case LUA_TSTRING:  // если это строка...
        w = lua_tolstring( L, tp, &l );
        t_printf( "%s %d (из %d) -> %s %s [%d]", s,i,top,lua_typename(L,tp), w, strlen(w) );
        break;
   case LUA_TBOOLEAN:  // если это булева переменная
        t_printf( "%s %d (из %d) -> %s %s", s,i,top,lua_typename(L,tp), lua_toboolean(L,tp) ? "true" : "false" );
        break;
   case LUA_TNUMBER:  // если это число...
        t_printf( "%s %d (из %d) -> %d %f", s,i,top,lua_typename(L,tp), lua_tonumber(L,tp) ) ;
        break;
   case LUA_TNONE: // пустая ячейка
        t_printf( "%s %d (из %d) -> %s 'none'", s,i,top,lua_typename(L,tp) ) ;
        break;
   case LUA_TNIL: // ничего
        t_printf( "%s %d (из %d) -> %s 'nil'", s,i,top,lua_typename(L,tp) ) ;
        break;
   case LUA_TTABLE: // таблица
        t_printf( "%s %d (из %d) -> %s %x", s,i,top,lua_typename(L,tp), lua_topointer(L,tp) ) ;
        break;
   case LUA_TFUNCTION: // функция
        t_printf( "%s %d (из %d) -> %s %x", s,i,top,lua_typename(L,tp), lua_topointer(L,tp) ) ;
        break;
   case LUA_TUSERDATA: // пользовательские данные
        t_printf( "%s %d (из %d) -> %s %x", s,i,top,lua_typename(L,tp), lua_touserdata(L,tp) ) ;
        break;
   case LUA_TLIGHTUSERDATA: // лёгкие пользовательские данные
        t_printf( "%s %d (из %d) -> %s %s", s,i,top,lua_typename(L,tp), lua_touserdata(L,tp) ) ;
        break;
   case LUA_TTHREAD: // поток
        t_printf( "%s %d (из %d) -> %s %x", s,i,top,lua_typename(L,tp), lua_tothread(L,tp) ) ;
        break;
   default: // что-то иное...
        t_printf( "%s %d (из %d) -> %s", s,i,top,lua_typename(L,tp) );
        break;
  } // конец switch
//
 }
//
  t_printf( "\n-I- Содержимое стека показано... -I-\n" );
//
} // --- конец stackDump -------------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
static void LuaHook( lua_State *L, lua_Debug *ar )
{ // функция перехвата управления в Lua
//
 if( !luaExecute || !flagHook ) // Lua не выполняется ИЛИ флаг Hook сбрОшен....
  return;
//
 char str[_512];
 snprintf( str,sizeof(str), "\n%s: - Выдан запрос на останов выполнения скрипта (%s) -",
                PutDateTimeToString(0), __FUNC__ );
 tp_printf( str ); // выдать строку в текстовое окно и в файл протокола
//
// ---- вброс luaL_error не приводит к мгновенному останову выполнения Lua-скрипта,
// ---- вброс фиксируется кодом 2 возврата из pcall после окончания выполнения скрипта
 luaL_error( L, "Выполнение Lua остановлено пользователем..." ); // вброс ошибки...
//
 do_tStart_fStop // деактивировать кнопку Stop, активировать кнонку Start
 do_HandRule_Enabled // активировать варианты "ручного управления" в главном меню
//
 flagHook = false;
//
 return;
//
} // ------ конец LuaHook-функции ----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall CopyStdoutToTextProtocol()
{ // добавляет stdout в текстовое подокно (ТМ0_stdout) окно и файл протокола
 char str[_1024]; // строка для временных данных
//
// --- строки stdout - в текстовое окно и в файл протокола ---------------------
 p_printf( "\n===> начало stdout выполнения скрипта %s ===>\n", FileNameLua ); // добавили в файл протокола
//------------------------------------------------------------------------------
//
 TM0_stdout->Clear(); // очистили TM0_stdout
//
 fptr_stdout = fopen( stdoutFileName, "rt" ); // открыли для чтения...
//
 TM0_stdout->Lines->BeginUpdate(); // начали изменение (Update) TM0_stdout без визуализации
//
 while( 1 ) // ...читать до последней строки...
 {
  if( fgets( str, sizeof(str), fptr_stdout ) != NULL ) // пока есть ещё строки в stdout
  {
   TM0_stdout->Lines->Add( str ); // добавили в окно stdout (компонент TM0_stdout)
   p_printf( str ); // добавили в файл протокола
  }
  else
   break;
 } // конец while( 1 )
//
 TM0_stdout->Lines->EndUpdate(); // закончили режим изменения (Update) TM0_stdout без визуализации
 SendMessage(TM0_stdout->Handle,EM_LINESCROLL,0,TM0_stdout->Lines->Count); // установить курсор на последнюю строку
//
 fclose( fptr_stdout ); // закрыли файл stdout
//
 p_printf( "<=== конец  stdout выполнения скрипта %s <===\n", FileNameLua ); // добавили в файл протокола
//
} // ----- конец CopyStdoutToTextProtocol ------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall CopyStderrToProtocol()
{ // добавляет strerr в файл протокола
 char str[_1024]; // строка для временных данных
//
 p_printf( "\n===> начало stderr выполнения скрипта %s ===>\n", FileNameLua );
//
 fptr_stderr = fopen( stderrFileName, "rt" ); // открыли для чтения...
//
 while( 1 ) // ...читать до последней строки...
 {
  if( fgets( str, sizeof(str), fptr_stderr ) != NULL ) // пока есть ещё строки в stderr
   p_printf( str ); // добавили в файл протокола
  else
   break;
 } // конец while( 1 )
//
 fclose( fptr_stderr ); // закрыли файл stdout
//
 p_printf( "<=== конец  stderr выполнения скрипта %s <===\n", FileNameLua ); // добавили в файл протокола
//
} // ----- конец CopyStderrToProtocol ------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall ShowBreakpoint( char *err )
{ // показать точку проверки (Breakpoint) в текстовом редакторе Lua
 int line = -13;
//
 char *p = strstr( err, FileNameLua ); // в str ищем первое вхождение FileNameLua
 if( p ) // если нашли вхождение FileNameLua...
 {
  *p = NULL; // указывает на нулевой символ
  p += strlen( FileNameLua ); // теперь p указывает на первый символ в stackTrace после вхождения FileNameLua
  if( sscanf( p, ":%d:", &line ) == 1 ) // если удалось корректно прочитать номер строки...
  {
   F1->LMD_EV0->GotoPhysLine( line-1 ); // переход к строке по её номеру (нумерация с 0 или 1)
   IndicateColRowNumberOfEV0(); // индицировать положение курсора в верхней части окна редактирования скриптов
   F1->actBreakSetExecute( 0 ); // в текстовом окне покажем точку проверки (BreakPoint)
   Beep();
  } // конец if( sscanf...
//
 } // конец if( p )
} // ----- конец ShowBreakpoint ------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int __fastcall lua_pcall_Debug( lua_State* L, int args, int results )
{ // выполнение скрипта Lua ( args - число входных параметров, results - выходных )
// in start: stack: func, arg1, arg2, ,,, argn (func помещено на стек luaL_loadfile)
  lua_pushcfunction( L, errorHandler ); // stack: func, arg1, arg2, ,,, argn, errorHandler
//
  int errorHandlerIndex = - ( args + 2 );
//
  lua_insert( L, errorHandlerIndex ); // stack: errorHandler, func, arg1, arg2, ,,, argn
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
} // ----- конец pcall_lua_Debug -----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall RunLuaScript()
{ // выполняет Lua-скрипты -----------------------------------------------------
 char *sf = "\nПроблемы с %s. Выполнение текущего скрипта Lua остановлено... (%s)\nПроверьте корректность файла исходного текста Lua...";
 char str[_512], sError[_512];
 int error1=0, error2=0;
//
 if( !L ) // если глобального экземпляра Lua ещё не создано...
 {
  if( !( L=luaL_newstate() ) ) // неудача создания экземпляра Lua
  {
   tpe_printf( "\nОшибка ""luaL_newstate()"" в функции %s()\n", __FUNC__ );
   goto label_StopSessionLua; // неудача...
  }
//
 luaL_openlibs( L ); // открываем стандартные библиотеки в L
//
 RegisterFunctions( L ); // регистрируем С-функции в L
//
 } // конец if( !L )
//
 lua_gc( L, LUA_GCCOLLECT, 200 ); // закладываем полный цикл уборки мусора
//
 luaExecute = true; // установИМ флаг "Lua выполняется"...
//
 F1->actBreakDeleteAllExecute( 0 ); // сбросить все точки Breakpoints
//
// lua_atpanic( L, luaPanic ); // установим luaPanic как функцию паники для стейта L
// t_printf( "-->%d", out ); // добавили в файл протокола
// lua_sethook( L, LuaHook, 0, 0 ); // сброс функции-"ловушки"
//
 lua_sethook( L, LuaHook, LUA_MASKCALL | LUA_MASKRET | LUA_MASKLINE | LUA_MASKCOUNT, HOOK_COUNT ); // установим функцию-"ловушку" на hookCount события выполнения Lua
//
 do_fStart_tStop // деактивировать кнопку Start, активировать кнонку Stop
 do_HandRule_Disabled // деактивировать варианты "ручного управления" в главном меню
//
////////////////////////////////////////////////////////////////////////////////
 F1->M0_stdout->Lines->Clear(); // очистили TM0_Bot
//==============================================================================
 fptr_protocol = fopen( FileNameProtocol, "wt" ); // открываем в режиме СОЗДАНИЕ, ЗАПИСЬ, ТЕКСТ
// if( fptr_protocol )
//  setbuf( fptr_protocol, NULL ); // отмена буфферизации
 fptr_stdout = fopen( stdoutFileName, "wt" ); // stdout буфферизируется построчно (_IOLBF)
// if( fptr_stdout )
//  setbuf( fptr_stdout, NULL );
 fptr_stderr = fopen( stderrFileName, "wt" ); // stderr никогда не буфферизируется (_IONBF)
// if( fptr_stderr )
//  setbuf( fptr_stderr, NULL );
 freopen( stdoutFileName, "wt", stdout ); // перенаправили stdout в файл stdoutFileName
 freopen( stderrFileName, "wt", stderr ); // перенаправили stderr в файл stderrFileName
//==============================================================================
// --- выведем строки из редактора Lua в файл stdinFileName --------------------
 SaveLuaScript( stdinFileName );
////////////////////////////////////////////////////////////////////////////////
 i_env_StopSessionLua = setjmp( env_StopSessionLua ); // установили точку перехода !!!!!!!!!!!
 if( i_env_StopSessionLua ) // не ноль - значит, сюда был прыжок !!!!!!!!!!!!!!!!!!!!!!
  goto label_StopSessionLua;
////////////////////////////////////////////////////////////////////////////////
// error1 = luaL_loadfile( L, stdinFileName ); // загружаем Lua-файл в интерпретатор
 try
 {
  error1 = luaL_loadfile( L, FileNameLua ); // загружаем Lua-файл в интерпретатор
 } // конец try
 catch( ... )
 {
  tpe_printf( sf, "luaL_loadfile()", __FUNC__ );
  goto label_StopSessionLua;
 } // конец cath( ... )
////////////////////////////////////////////////////////////////////////////////
//==============================================================================
 try
 {
  error2 = lua_pcall_Debug( L, 0, 0 ); // lua_pcall + debug
 } // конец try
 catch( ... ) // ловим любое исключение
 {
  tpe_printf( sf, "lua_pcall_Debug()", __FUNC__ );
  goto label_StopSessionLua;
 } // конец cath( ... )
//==============================================================================
//
 luaExecute = false; // Lua закончил выполнЕние (с ошибками ль без - тут неважно)
//
// ----- пожалуй, следующий блок НИКОГДА НЕ ВЫПОЛНИТСЯ, ибо перехват всех
// ----- ошибок теперь происходит внутри pcall (используем lua_pcall_Debug)
 if( error1 || error2 ) // макрос luaL_dofile(L,InLuaFileName) = lua_loadfile + lua_pcall
 {
  strNcpy( sError, lua_tostring(L,-1) ); // скопировали текст ошибки со стека Lua
  lua_pop( L, 1 ); // снимаем сообщение об ошибке со стека
//
  snprintf( str,sizeof(str), "\n%s: Выполнение Lua-скрипта остановлено [err: %d|%d] (%s):\n",
            PutDateTimeToString(0), error1, error2, __FUNC__ );
//
  tpe_printf( str ); // выводим в текстовое окно, в файл протокола и stderr
//
 } // конец обработки if error1 || error2 ======================================
//
////////////////////////////////////////////////////////////////////////////////
label_StopSessionLua: // сюда переходим по longjmp -----------------------------
//
 lua_sethook( L, LuaHook, 0, 0 ); // сброс функции-"ловушки"
//
 F1->Master_Timer->Enabled = false; // остановили Master_Timer
//
 luaExecute = false; // Lua закончил выполнЕние (с ошибками ль без - тут неважно)
//
 MessageBeep( MB_ICONEXCLAMATION ); // звуковое предупреждение...
//
 fclose( fptr_stdout ); // закрыли stdout
 fclose( fptr_stderr ); // закрыли stderr
//
 Delay( 1000 );
//
 try
 {
  lua_close( L ); // закрыть экземпляр Lua
  L = NULL;
//
  tpe_printf( "\n-I- %s: Выполнение скрипта [%s] завершено. Виртуальная Lua-машина остановлена... -I-\n",
              PutDateTimeToString(0), FileNameLua );
 }
 catch( ... )
 {
  tpe_printf( "\n-E- %s: Выполнение скрипта [%s] завершено с проблемами... -E-\n",
              PutDateTimeToString(0), FileNameLua );
//
  MessageBox(0, "Внутренняя ошибка системы. Возможен сбой приложения...",
                "Предупреждение",
                 MB_OK | MB_ICONWARNING | MB_TOPMOST) ;
 }
//
// F2->FormStyle = fsStayOnTop; // окно F2 выдвинуть на передний план
//
 do_tStart_fStop // деактивировать кнопку Stop, активировать кнонку Start
 do_HandRule_Enabled // активировать варианты "ручного управления" в главном меню
//
 CopyStdoutToTextProtocol(); // stdout добавили в текстовое подокно TM0_stdout и в файл протокола
//
 CopyStderrToProtocol(); // stderr добавили в файл протокола
//
 CloseAndRenameFileProtocol(); // окончательное имя файла протокола
//
////////////////////////////////////////////////////////////////////////////////
 return true ; // всё нормально...
//
} //===== конец RunLuaScript ===================================================


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
static int errorHandler(lua_State* L)
{ // функция - обработчик ошибок методом вызова debug.traceback
  char str[_512];
//
  lua_getglobal( L, "debug" ); // stack: err, debug
  lua_getfield( L, -1, "traceback" ); // stack: err, debug, debug.traceback
//
  if( lua_pcall( L,0,1,0 ) ) // debug.traceback() возвращает одно значение
   snprintf( str,sizeof(str), "\n%s [1]: (%s):\nError in debug.traceback() call: %s\n",
             PutDateTimeToString(0), __FUNC__, lua_tostring( L,-1 ) );
  else // трассировка стэка не дала точки останова
   snprintf( str,sizeof(str), "\n%s [2]: (%s):\nC++ stack traceback: %s\n",
             PutDateTimeToString(0), __FUNC__, lua_tostring( L,-1 ) );
//
  tp_printf( str ); // добавили в текстовое окно и в протокол
//
  ShowBreakpoint( str ); // покАз точки останОва в текстовом редакторе Lua !! не перенОсить (str пОртится!) !!
//
// lua_Debug *ar;
//  switch( ar->event )
//  {
//   case LUA_HOOKCALL:
//  lua_getinfo( L, ">n", ar ); t_printf( "\n%s %s %s\n", ar->name, ar->namewhat, ar->source );
//  lua_getinfo( L, ">S", ar ); t_printf( "\n%d-%d\n", ar->linedefined, ar->lastlinedefined );
//        break;
//
//  default: break;
//
//  } // конец switch
//
  stackDump( L , "РаскрУтка стека внутри errorHandler: " );
//
  longjmp( env_StopSessionLua, 1 ); // нелокальный переход к точке setjmp !!!!!!
//
} // --- конец errorHandler ----------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall GetFileFromServer( char FileNameServer[] )
{ // получить файл с HTTP-сервера ( FileNameInServer - полное имя файла на сервере,
 char FileNameOnServer[_512], // полное имя файла на сервере
      FileNameOnClient[_512]; // полное имя файла на клиенте
//
 TMemoryStream *fs = new TMemoryStream();  // создаём поток для сохранения вЫгруженного из Сети файла
//
// --- полный путь к каталогу исходных данных (включая слэш в конце)
 snprintf( PathToSubDirInData,sizeof(PathToSubDirInData), "%s%s\\", ExtractFilePath ( Application->ExeName ), NameSubDirInData);
 if( !DirectoryExists( PathToSubDirInData ) ) // если не существует этого каталога...
  if( !CreateDir( PathToSubDirInData ) ) // если не удалось создать...
   strcpy( PathToSubDirInData, '\0' ); // обнуляем путь к подкаталогу PathToSubDirOutData
//
 snprintf( FileNameOnServer,sizeof(FileNameOnServer), "%s/%s", MySite, FileNameServer ); // полное имя файла на сервере (+++)
 snprintf( FileNameOnClient,sizeof(FileNameOnClient), "%s%s", PathToSubDirInData, ExtractFileName(FileNameServer) ); // куда сохранять на клиенте (+++)
//
 try
 {
  F1->FTP_Get->Get( FileNameOnServer, fs ); // метод Get выгружает файл в поток fs
 }
 catch(const EIdException& E) // ловим исключение Indy-компонента
 {
//  SBM0->Text = Format(" Ошибка: %s", OPENARRAY(TVarRec, (E.Message) ) );
  ShowMessage(" Ошибка: " + E.Message);
 };
//
 fs->SaveToFile( FileNameOnClient ); // сохраняем данные в файл на клиенте
//
 delete fs; // поток более не нужен...
//
 F1->FTP_Get->Disconnect(); // разрываем соединениe с сервером
} //----------------------------------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::N5_OutOpsDown(TObject *Sender)
{ // выходные операторы принудительно помещать на выходной ярус (самый нижний) или нет ( 1/0 соответственно )
//
 F1->N5->Checked = !F1->N5->Checked ; // изменим состояние на противоположное
//
 Write_Config(); // запись Sect7.Sect7_Var1
//
 MessageBeep( MB_ICONEXCLAMATION ); // звуковое предупреждение...
//
} //----------------------------------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall OutOpsMoveLowerTier()
{ // все выходные операторы перенести на самый нижний ярус
//
 INT nOp;
//
 for( INT iTier=1; iTier<=c_GetCountTiers()-1; iTier++  ) // по всем ярусам с 1 по nTiers-1
  for( INT jOp=1; jOp<=c_GetCountOpsOnTier(iTier); jOp++ ) // по всем операторам яруса iTiers
  {
   nOp = c_GetOpByNumbOnTier( jOp,iTier ); // номер оператора #jOp на ярусе iTier
   if( !c_GetCountOutEdgesByOp( nOp ) ) // если  у оператора nOp число выходящих дуг нулевое...
    c_MoveOpTierToTier( nOp,c_GetCountTiers() ); // перемещаем оператор nOp на самый нижний ярус ЯПФ
  }
//
} //----------------------------------------------------------------------------


//
#include "FTP_GetPost_SPF.cpp" // обмен с сервером vbakanov.ru по FTP (Indy 8.0.25)
//
