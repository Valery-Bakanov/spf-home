
#include "Unit1.h"
#include "Unit2.h" // чтобы был доступ к F2 (форма вывода графика интенсивности вычислений)
#include "Unit3.h" // чтобы был доступ к F3 (форма вывода графика Ганнта)
//
#include <vcl.h>
#pragma hdrstop
#include <IniFiles.hpp>
#include <System.hpp>
#include <shellapi.h>
//
#include "SysUtils.hpp"
#include <Clipbrd.hpp>
#include <dos.h> // sleep
//
#include <iostream.h>
#include <typeinfo.h>
//
#include "stdio.h"
#include <string.h>
#include "math.h"
#include "Math.hpp"
#include <time.h>
#include <stdlib.h>
// #include <setjmp.h> // для setjmp() и longjmp()
#include <IniFiles.hpp>
#include <sys\timeb.h>
#include <SysUtils.hpp>
#include <ctype.h> // isdigit()
#include <vcl/dstring.h>
//
using namespace std;
//
#include "parser.h"
//
#define  TParser ::TParser // !!! будет действовать в этом модуле и в #include "parser.cpp" !!!
#include "parser.cpp" // Written by Chaos Master, 11-th of Febrary, 2000
//------------------------------------------------------------------------------
#pragma package(smart_init)
// // #pragma link "TProcTimer"
#pragma resource "*.dfm"
#pragma warn -8057 // отключили сообщения E8057 Parameter 'Sender' is never used
#pragma warn -8080
#pragma warn -8059
#pragma warn -8012
//
TF1 *F1; // главное окно
//
//#include "pcre.h" // библиотека регулярных выражений от Borland C++ RTL
//
TParser parser; // перед TParser добавлено :: для обеспечения отдельной области видимости
//
//==============================================================================
#define APM Application->ProcessMessages(); // дать поработать Windows
//
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
//
char *pt0  = "=\\d{1,}/\\d{1,}:", // =12/155: // шаблоны для регулярных выражений
     *pt00 = "-[a-zA-Zа-яА-Я]{1}[_a-zA-Zа-яА-Я0-9]{0,}", // -param_1
     *pt01 = "-[a-zA-Z]{1}[_a-zA-Z0-9]{0,}\\s{1,}[+-]{0,1}\\d{0,}\\.{0,1}\\d{0,}", // -par_1 m1
     *pt02 = "-[a-zA-Z]{1}[_a-zA-Z0-9]{0,}\\s{1,}[+-]{0,1}\\d{0,}\\.{0,1}\\d{0,}\\s{1,}[+-]{0,1}\\d{0,}\\.{0,1}\\d{0,}", // -parr_2 m1 m2
     *pt03 = "-[a-zA-Z]{1}[_a-zA-Z0-9]{0,}(\\s{1,}[+-]{0,1}\\d{0,}\\.{0,1}\\d{0,}){2}"; // -parr_2 m1 m2
//
#define strcat(dest,src) (strncat(dest,src,sizeof(dest)-strlen(dest)-5)) // безопасное добавление src к dest
// !!!!! здесь 5 - просто дополнительная защита ("на всякий случай") !!!!!!!!!!!
//
char Ident[] = "Bakanov Valery Mikhailovich, Moscow, Russia, 2009-2020\n \
Автор программного продукта Валерий Баканов не является ярым сторонником Объектно-Ориентированного Программирования \
(внутри автора точно сидит Линус Торвальдс!) и поэтому большая часть кода не использует ООП\n \
The author of the software Valery Bakanov is not an ardent supporter of Object-Oriented Programming \
(Linus Torvalds definitely sits inside the author!) and therefore most of the code does not use OOP";
//
char trueLowerCase[]  = "true",  trueUpperCase[] ="TRUE",
     falseLowerCase[] = "false", falseUpperCase[]="FALSE",
     notDefined[]     ="? ? ?",
     startComments[] = ";\0", // символ начала комментария в строке ";"
     symbolNot_1 = '!', symbolNot_2 = '~', // символы логического отрицания ! или ~
     SET[]       = "SET"; // имя инструкции SET
//
#define is_SET(Set) ( !strcmp( Set, SET ) ) // это инструкция SET
#define is_PredicatOrSET(Set) ( is_Predicat( Set ) || !strcmp( Set, SET ) )
//
#define strNcpy(d,s) strncpy(d,s,sizeof(d)) // безопасный вариант
//------------------------------------------------------------------------------
#define GetRand(a,b) (rand()%((b)-(a)+1)+(a)) // сгенерировать случайное число от a до b (включительно)
//------------------------------------------------------------------------------
#define ERR_ALTERNAT -13.4567 // признак деления на 0 при вычислении альтернативности
//------------------------------------------------------------------------------
#define REAL double // тип вещественных чисел при вычислениях
#define INT  long   // тип целых
//
#define ULI unsigned long int // длинное целое без знака
#define UI  unsigned int // целое без знака
//------------------------------------------------------------------------------
#define sleep_for_vizu_buffer Delay_Vizu_Buffer(); // время для визуализации буфера
//------------------------------------------------------------------------------
#define _128   128 // определение констант для всей программы
#define _256   256
#define _512   512
#define _1024  1024
#define _2048  2048
#define _4096  4096
#define _8192  8192
#define _16384 16384
//------------------------------------------------------------------------------
#define ACC_REAL 3 // число знаков после зап.при выводе "плавающих" по E-формату
//==============================================================================
#define _SET_LEN 4  // длина строки мнемоники инструкции (3 символа + "\0")
#define _ID_LEN  33 // 33 // длина строки имени переменной (32 символа + "\0")
//------------------------------------------------------------------------------
char uniqueStr[_512] = "\0"; // уникальная строка для имен файлов ( дата + время до мсек )
//
void   __fastcall Read_Config();
void   __fastcall Write_Config();
void   __fastcall Delay(long mSecs);  // ждать mSecs миллисекунд (с возможность поработать WINDOWS)
void   __fastcall RunExternal(char* CommandLine, byte RuleParent, byte Priority, bool RuleMessage);
bool   __fastcall Read_Instructions(); // читает инструкции из файла FileNameSet в массив структур Mem_Instruction[]
//
bool   __fastcall Vizu_Sets(); // визуализация инструкций в SG_Set  из массива структур Mem_Instruction[]
void   __fastcall Vizu_Data(); // визуализация данных в SG_Data из массива структур Mem_Data[]
void   __fastcall Vizu_Buffer(); // визуализация данных в SG_Buffer из массива структур Mem_Buffer[]
//
char*  __fastcall Vizu_Flags(int i_Set); // визуализация флагов инструкции Mem_Sets[i_Set]
//
void   __fastcall Primary_Init_Data(); // первоначальное присваивание данных ячейкам памяти etc etc
void   __fastcall ExecuteInstructions_ExceptSET(int i_Set); // выполняет все (кроме SET) инструкции номер i_Set
void   __fastcall Install_All_Flags(); // очищаем ВСЕ ФЛАГИ в Mem_Sets[]
void   __fastcall Calc_Stat_Proc();  // вычисляется статистика использования АИУ
void   __fastcall Test_ReadyForExec_and_AddToBuffer(int i_Set); // тестирует инструкцию i_Set на готовность
//
float  __fastcall Calc_Param(int i_Set); // вычисляется ПОЛЕЗНОСТЬ инструкции i_Set
float  __fastcall Calc_Priority(float Param); // по значению Param (ПОЛЕЗНОСТЬ) определяется
// ПРИОРИТЕТ данной инструкции при ее запуске на свободном АИУ
// условие ГКВ (Готовность К Выполнению) и при успехе добавляет ее в буфер Mem_Buffer[]
bool   __fastcall Test_aResult_Eq_aOperand(int i_Set); // тест на совпадение
// адреса результата с адресами одного или обоих операндов
//
char*  __fastcall Get_Time_asLine(); // вернуть время (в тактах начиная с 0) в строке
//
void   __fastcall AttemptExecMaxInstructions_fromBuffer(); // пытается выбрать из буфера и выполнить максимум ГКВ-инструкций
void   __fastcall Vizu_Flow_Exec(); // визуализировать процент выполнения программы
void   __fastcall Start_DataFlow_Process(int Mode); // начали счет (в заданном Mode режиме)
//
int    __fastcall Get_CountOperandsByInstruction(char *Set); // возвращает число операндов инструкции Set
char*  __fastcall GetSubString(char *Str, int n1, int n2); // вернуть подстроку из Str от n1 до n2 символов включительно
char*  __fastcall Line_Set(int i_Set, int Rule); // возвращает текст инструкции из Mem_Sets[i]
void   __fastcall Add_toData(int i_Set, char* aResult, REAL Data); // добавляет в Mem_Data[] число по адресу (строка!) Addr
void   __fastcall Add_toBuffer(int i_Set); // добавляет в буфер команд строку с ГКВ-инструкцией i_Set
int    __fastcall Get_TicksByInstruction(char *Set); // возвращает из Set_Params->Time время выполнения инструкции Set(char *Set);
int    __fastcall Get_Free_Proc(); // возвращает число свободных АИУ
REAL   __fastcall Get_Data(char *Addr); // возвращает из Mem_Data[] число по адресу (строка!) Addr
void   __fastcall Display_Error(char *str); // информация об арифметической ошибке
void   __fastcall Test_Visu_Buffer_Fill(); // тестирование индикация заполненности буфера
int    __fastcall Select_Instruction_fromBuffer(); // возвращает номер инструкции из буфера по условию мах ПРИОРИТЕТА
void   __fastcall Calc_Level_Buffer_Fill(); // вычисляет наполненность буфера в %% в глобале Level_Buffer_Fill
//
float  __fastcall Calc_01_Param_Instruction(int i_Set); // вычиcляет ПОЛЕЗНОСТЬ инструкции i_Set по 01-му методу
float  __fastcall Calc_02_Param_Instruction(int i_Set); // вычиcляет ПОЛЕЗНОСТЬ инструкции i_Set по 02-му методу
float  __fastcall Calc_03_Param_Instruction(int i_Set); // вычиcляет ПОЛЕЗНОСТЬ инструкции i_Set по 03-му методу
//
int    __fastcall Work_TimeSets_Protocol_IC();  // работаем с данными интенсивности вычислений
int    __fastcall Work_TimeSets_Protocol_AIU(); // работаем с загруженностью АИУ (диаграмма Гантта)
////////////////////////////////////////////////////////////////////////////////
void   __fastcall Finalize_Only_SET(int i_Set); // вызывается для завершения выполнения инструкции SET номер i_Set
void   __fastcall Finalize_Except_SET(int i_Proc); // вызывается для завершения выполнения инструкции на АИУ i_Proc
void   __fastcall Delay_Vizu_Buffer(); // ждет Delay_Buffer миллисек для визуализации буфера
////////////////////////////////////////////////////////////////////////////////
REAL   __fastcall Calc_ConnectedIndex(int Rule); // вычисление характеристик информационного графа программы
REAL   __fastcall StrToReal(char * str, int i_Set); // конвертация строки в REAL с проверкой при выполнении инструкции номер i_Set
//
void   __fastcall GetFileFromServer( char FileName[] ); // получить файл с сервера
//
bool   __fastcall Test_All_Operands(); // тестирует потенциальное существование операндов для всех операторов (останов при ошибке)
//
int    __fastcall RunPreProcessor(); // препроцессор обработки макросов
int    __fastcall PreProcRow_For1(int iRow, char* c, int iCycle); // расширитель iRow строки тела макроса одномерного массива
//int    __fastcall FindAndReplaceSubString(char* Source, int Start, int Len, char* Old, char* New);
char*  __fastcall ParseAndCalculateIndex(char* Expression); // разбор и вычисление выражения (без параметров) exp
// int    __fastcall CalculateIndexes(char* str); // окончательное вычисление значения индекса (без параметров) строки str
void   __fastcall Out_Data_SBM1(); // вывод текста в среднюю часть StatusBar
char*  __fastcall strReplace( char* dest, int num, const char* source, const char* orig, const char* rep ); // замена подстроки в строке
////////////////////////////////////////////////////////////////////////////////
bool   __fastcall is_ResultIsPredicat(char* str); // возвращает TRUE, если str - флаг предикатора
bool   __fastcall is_Predicat(char* Set); // возвращает TRUE, если оператор Set суть предикатор
//
void   __fastcall Draw_ReadyOperands(); // выделяем ячейки таблицы инструкций цветом в динамике
void   __fastcall Clear_AllCells(); // очистим цвет всех ячеек таблицы инструкций
void   __fastcall StopCalculations(int Rule); // останов программыпо причинам в Rule
//
int Delay_Buffer = 0; // ждать (в миллисек) для визуализации буфера
//
void   __fastcall DelSpacesTabsAround(char *str); // удаляет пробелы слева и справа строки str
//
void  __fastcall Save_Protocol_Master(); // сохранение ГЛАВНОГО-ПРОТОКОЛА выполнения задания (*.pro)
void  __fastcall Save_Protocol_AIU(); // сохранение ПРОТОКОЛА_ИСПОЛЬЗОВАНИЯ_АИУ_ПО_ВРЕМЕНИ (*.tpr)
void  __fastcall Save_Protocol_Data(); // сохранение ПРОТОКОЛА_ПАМЯТИ (*.dat)
void  __fastcall Save_Protocol_ExecInstructions(); // сохранение ПРОТОКОЛА_ВЫПОЛНЕНИЯ_ИНСТРУКЦИЙ_ПО_ВРЕМЕНИ (*.tst)
void  __fastcall Save_Protocol_ConnectedGraph(); // сохранение ПРОТОКОЛА_CDZPYJCNB_UHFAF (*.coi)
//
void  __fastcall Save_All_Protocols_To_Out_Dir(); // сохранить все протоколы в подкаталог Out!Data
//
bool  __fastcall AddLineToProtocol(char *str); // добавить строку в текстовый файл протокола
//
void /*__fastcall*/ t_printf(char *fmt, ...); // форматный вывод в ОКНО ПРОТОКОЛА
//
void  __fastcall Save_IGA(); // сохраняем граф в виде списка дуг (формат *.GV)
void  __fastcall Extended_Save_IGA(); // сохраняем данные о времени выполнения операторов (формат *.MVR)
char* __fastcall PutDateTimeToString(INT flag); // выдача текущих даты и времени в строку с форматированием
//
struct timeb t0, t1; // момент начала выборки инструкций
void   ftime(struct timeb *buf);
//
INT all_maxProcs, // всего участвующих в вычислениях АИУ
    simult_maxProcs, // max число ОДНОВРЕМЕННО участвующих в вычислениях АИУ
    serial_Ticks,   // сумма времен работы АИУ (фактически время ПОСЛЕДОВАТЕЛЬНОГО выполнения, такты)
    parallel_Ticks; // время выполнения параллельной программы, такты
//
//==============================================================================
#define mR F1->M1  // доступ к M1
#define mB F1->SG_Buffer // доступ к массиву ячеек визуализации буфера команд
#define mP F1->PB_1      // доступ к указателюзаполненности буфера команд
#define mI F1->SG_Set    // доступ к массиву ячеек  инструкций
#define mD F1->SG_Data   // доступ к массиву ячеек данных
#define mTpr F1->Tpr // доступ к F1->Tpr
#define mPM  F1->PM // доступ к F1->PM

//------------------------------------------------------------------------------
#define SBM0 F1->StatusBarMain->Panels->Items[0] // для вывода в Panels[0]
#define SBM1 F1->StatusBarMain->Panels->Items[1] // для вывода в Panels[1]
#define SBM2 F1->StatusBarMain->Panels->Items[2] // для вывода в Panels[2]
//
#define MI_aOp1(i) ( !strcmp(Mem_Instruction[i].aOp1,aResult) ) // проверка совпадения с aResult 1-го имени операнда i-той инструкции
#define MI_aOp2(i) ( !strcmp(Mem_Instruction[i].aOp2,aResult) ) // ... 2-го операнда i-той инструкции
//
#define MI_fOp1(i) ( Mem_Instruction[i].fOp1 ) // обращение к флагу готовности 1-го операнда i-той инструкции
#define MI_fOp2(i) ( Mem_Instruction[i].fOp2 ) // ... 2-го операнда i-той инструкции
//
//------------------------------------------------------------------------------
//
struct { // DrawColorTest (выделение ячеек цветом при тестировании без выполнения программы)
 TColor clOperandOperation, // RGB(255,185,185) розовый цвет ячейки в SG_Set по признаку "Операнды<->Операции"
        clNonExecuted, // RGB(255,185,255) фиолетовый цвет по признаку "Неисполненные ячейки"
        clNonUsedResult, // RGB(255,192,0) коричневый цвет по признаку "Неиспользованные результаты"
        clNonDefOperands; // RGB(0,255,255) голубой цвет по признаку "Неопределенные операнды"
} DCT; // [DrawColorTest] выделение цветом при тестировании без выполнения программы
//
struct { // DrawColorExec (выделение ячеек цветом при выполнении программы)
 bool needDrawColors;
 TColor clReadyOperand, // RGB(255,153,255) цвет ячейки ОПЕРАНДЫ_ГОТОВы
        clTruePredicat, // RGB(255,153,255) ...ПРЕДИКАТ=TRUE (светло-фиолетовый)
        clExecSet; // RGB(255,51,153) ...ИНСТРУКЦИЯ_ВЫПОЛНИЛАСЬ (светло-красный)
} DCE; // [DrawColorExec] выделение цветом в динамике выполнения
//
struct { // DrawGraph (отрисовка графмка интенсивности вычислений)
 TColor clGraphStart, // начало и конец тела графика интенсивности вычислений RGB(255,0,0)->RGB(0,255,0)
        clGraphEnd;
} DGR; // [DrawGraph] цвет тела графика интенсивности вычислений
//
struct { // ReadWriteConfig (имена секций и значений файла конфигурации системы)
 char *Sect1,  *Sect1_Var1,*Sect1_Var2,*Sect1_Var3,*Sect1_Var4,
      *Sect2, // список инструкций - выполняется автоматически
      *Sect3,  *Sect3_Var1,*Sect3_Var2,
      *Sect4,  *Sect4_Var1,*Sect4_Var2,
      *Sect5,  *Sect5_Var1,
      *Sect6,  *Sect6_Var1,
      *Sect7,  *Sect7_Var1,
      *Sect8,  *Sect8_Var1,*Sect8_Var2,*Sect8_Var3,*Sect8_Var4,
      *Sect9,  *Sect9_Var1,
      *Sect10, *Sect10_Var1,
      *Sect11, *Sect11_Var1,
      *Sect12, *Sect12_Var1,
      *Sect13, *Sect13_Var1,*Sect13_Var2,*Sect13_Var3,*Sect13_Var4,
      *Sect14, *Sect14_Var1,*Sect14_Var2,*Sect14_Var3,*Sect14_Var4,
      *Sect15, *Sect15_Var1,*Sect15_Var2,
      *Sect16, *Sect16_Var1;
} RWC = {
 "Max_Lengths", // [1] значения параметров
  "Max_Instruction","Max_Data","Max_Proc","Max_Buffer",
 "Times", // [2] секция времён выполнения инструкций
 "Editor_File", // [3] секция имени текстового редактора
  "File","Mode",
 "Strategy", // [4] стратегия порядка выбора инструкций из буфера
  "How_Calc_Param","How_Calc_Prior",
 "Delay_Vizu_Buffer", // [5] время визуализации буфера (при #0 ВРЕМЯ ВЫПОЛНЕНИЯ ПРОГРАММЫ будет завЫшено)
  "Delay",
 "Graph", // [6] управление режимами вывода графика интенсивности вычислений
  "tick_Scan",
 "Tick_Interval", // [7] // время тика в миллисекундах
  "Interval",
 "Pos_F1", // [8] положение и размеры главной формы
  "Top","Left","Width","Height",
 "LastFileNameSet", // [9] имя файла программы
  "FileNameSet",
 "RuleVarData", // [10] символы - указатели имен переменных с возможностью перезаписи их значений
  "attrVar",
 "Auto_Graph", // [11] отрисовывать ли график иннтенсивности вычислений сразу по сле окончания выполнения программы
  "NeedAutoGraph",
 "WaitNextInstruction", // [12] через сколько тиков после конца выполнения инструкции можно считать, что программа закончеа
  "WaitTicks",
 "DrawColorExec", // [13] цвета ячеек при исполнении программы
  "needDrawColors","clReadyOperand","clTruePredicat","clExecSet",
 "DrawColorTest", // [14] цвета ячеек при тестировании программы
  "clOperandOperation","clNonExecuted","clNonUsedResult","clNonDefOperands",
 "DrawColorGraph", // [15] начало и конец тела графика интенсивности вычислений
  "clGraphStart","clGraphEnd",
 "StartNumbOps", // [16] начальны йномер операторов
  "StartNumb"
} ; // [ReadWriteConfig] имена секций и значений файла конфигурации
//
int outGlobal; // тэг варианта меню, из которого вызвана функция выбора цвета
//
#define color_Graph clRed  // цвет графика интенсивности вычислений
//------------------------------------------------------------------------------
#define BUFFER_EMPTY (-1313) // буфер пуст
//==============================================================================
//
char FileNameINI[_512]    = "data_flow.ini", // имя файла настроек
     FileNameSet[_512]    = "data_flow.set", // имя файла списка инструкций для задачи
     FileNameSetPrP[_512], // имя файла инструкций после препроцессора
     ExtPrP[]             = ".set_PrP", // расширение имени файла инструкций после препроцессора
     ExtIGA[]             = ".gv", // расширение имени файла при экспорте ИГА-файлов
     ExtMVR[]             = ".mvr", // расширение файлов при экспорте файлов с данными о времени выполнения операций
     FileNameEditor[_512] = "notepad.exe"; // файл текстового редактора
FILE *fptrIn, *fptrOut; // указатели на рабочие массивы
//
bool modeEdit  = FALSE, // режим вызова текстового редактора
     modeGraph = TRUE; // режим отрисовки графика интенсивности вычислений
//
int Regim = 1; // при Regim = 1 вычисления начинаются
               // при Regim = 0 вычисления остановлены пользователем
               // при Regim = 2 вычиcления самостоятельно завершились
//
int Code_Error = 1; // Code_Error = -1  -.- попытка деления на 0
                    // Code_Error = -2  -.- попытка вычисления квадратного корня из отрицательного числа
                    // Code_Error = -3  -.- ошибка вычисления тангенса
                    // Code_Error = -4  -.- ошибка возведения в степень (x**y)
                    // Code_Error = -5  -.- ошибка натурального логарифма
                    // Code_Error = -13 -.- адрес результата совпадает с одним (или обоими) входными операндами
////////////////////////////////////////////////////////////////////////////////
//
#define MAX_PROC 1000000 // максимальное число АИУ 10^6
struct mp {
 bool Busy; // занятость АИУ (если 0=FALSE - свободен, иначе - занят)
 int i_Set; // номер инструкции (из пула инструкций)
 char aOp1[_ID_LEN], // адрес (строка!) первого операнда
      aOp2[_ID_LEN], // адрес (строка!) второго операнда
   aResult[_ID_LEN]; // адрес (строка!) результата
 REAL Op1, Op2, Result; // значения данных по адресам aOp1,aOp2,aResult (для проверки)
// double t_Start; // момент времени начала выполнения инструкции
 ULI tick_Start; // момент (тик, такт) старта выполнения инструкции
} M_P, *Mem_Proc=NULL;
ULI Max_Proc = _128, // первоначальный захват
    Free_Proc; // текущее число свободных АИУ
//
////////////////////////////////////////////////////////////////////////////////
#define MAX_INSTRUCTION 1000000 // максимальный размер пула инструкций 10^6
// описание структуры машинных инструкций
struct mi {
 char Set[_SET_LEN], // мнемоника инструкции
      aOp1[_ID_LEN],  // адрес (строка!) первого операнда
      aOp2[_ID_LEN],  // ...то же второго операнда
      aResult[_ID_LEN], // адрес (строка!) результата операции
      aPredicat[_ID_LEN]; // адрес (строка) флага предиката операции
 bool fOp1,fOp2, // признак готовности 1-го и 2-го операндов
      fPredicat, // существование флага предиката ( true/false или переменная )
      fPredicatTRUE; // TRUE - истинность предиктора (инструкцию можно добавлять в буфер команд)
 bool fExec,       // признак того (TRUE), что эта инструкция В ДАННЫЙ МОМЕНТ выполнятся
      fExecOut,    // признак исполнения инструкции (TRUE - исполнялась один раз)
      fAddBuffer;  // признак того, что инструкция добавлена в буффер
 char Comment[_256];  // комментарий к инструкции
} M_I, *Mem_Instruction=NULL;
ULI Max_Instruction = _128,   // первоначальный захват
    Really_Set = 0,   // текущее значение
    Already_Exec = 0; // уже выполнено
//
////////////////////////////////////////////////////////////////////////////////
// #define MAX_SEL 1000000 // мах число выделенных цветом ячеек в SG_Set (всегда <= NAX_SET)
// описание массива структур выделенных цветом ячеек
struct sc {
 int Row, Col; // номер строки и колонки в SC_Set
 TColor clBackground, clSymbol; // цвета фона ячейки и символов при раскрашивании
} S_C, *Sel_Cell=NULL;
ULI Really_Select = 0; // текущее значение
//
/////////////////////////////////////////////////////////////////////////////
#define MAX_DATA 1000000 // максимальный размер пула данных 10^6
// описание структуры ячеек памяти данных
struct md {
 char Addr[_ID_LEN]; // адрес ячейки (строка!)
 REAL Data; // содержимое ячейки
 ULI i_Set; // номер инструкции, в результате котрой было вычислено это значеник
} M_D, *Mem_Data=NULL;
ULI Max_Data = _128,  // первоначальный захват
    Really_Data = 0; // текущее значение
//
////////////////////////////////////////////////////////////////////////////////
#define MAX_BUFFER 1000000 // максимальный размер буфера ГКВ-инструкций 10^6
// описание структуры буфера ГКВ-инструкций
struct mb {
 ULI i_Set; // номер ГКВ-инструкции из пула инструкций
 float Param, // параметр для определения ПОЛЕЗНОСТИ
       Priority; // собственно ПРИОРИТЕТ (чем больше - тем раньше инструкция запускается на исполнение)
} M_B, *Mem_Buffer=NULL;
ULI Max_Buffer = _128,  // первоначальный захват
    Really_Buffer = 0, // текущая длина
    Really_Buffer_Old; // то же до последнего изменения
bool buffer_Fill = FALSE; // если TRUE - буфер заполнен
float Level_Buffer_Fill = 0.0; // заполненность буфера в %% [0 - 100]
//
////////////////////////////////////////////////////////////////////////////////
int tick_ScanForGraph = 10; // время сканир.при выводе графика интенс.выч.(тактов)
//
INT StartNumb = 100; // начальный номер операторов для вывода в виде ИГА
////////////////////////////////////////////////////////////////////////////////
//
// описание параметров каждой инструкции
struct ip {
 char Set[_SET_LEN]; // мнемоника инструкции (3 символа + терминирующий "0")
 int nInputOperands, // число ВХОДНЫХ операндов инструкции
     Time; // время выполнения инструкции (в тИках)
} I_P, Set_Params[] = {
 {"SET", 1,    0},
 {"ADD", 2,   20}, // мнемоника инструкции, число ВХОДНЫХ операндов, время выполнения в тиках
 {"SUB", 2,   20},
 {"MUL", 2,  200},
 {"DIV", 2,  200}, // 5
 {"DQU", 2,  200},
 {"DRE", 2,  200},
 {"SQR", 1,  500},
 {"SIN", 1, 1000},
 {"COS", 1, 1000}, // 10
 {"TAN", 1, 1000},
 {"LOG", 1, 1000},
 {"POW", 2, 1000},
 {"ASN", 1, 1000},
 {"ACN", 1, 1000}, //15
 {"ATN", 1, 1000},
 {"EXP", 1, 1000},
 {"SNH", 1, 1000},
 {"CNH", 1, 1000},
 {"TNH", 1, 1000}, // 20
 {"CPY", 1,  100},
 {"ABS", 1,    2},
 {"SGN", 1,    2},
 {"NEG", 1,    2},
 {"FLR", 1,    2}, // 25
 {"CEL", 1,    2},
 {"RND", 2,  100},
//
 {"PGE", 2,    1}, // сравнение двух чисел
 {"PLE", 2,    1},
 {"PEQ", 2,    1}, //30
 {"PNE", 2,    1},
 {"PGT", 2,    1},
 {"PLT", 2,    1},
//
 {"PNT", 1,    1},
 {"POR", 2,    2}, // 35
 {"PAN", 2,    2},
 {"PIM", 2,    2},
 {"PEV", 2,    2}, // 38
//
 {"PAP", 2,    2},
 {"PHS", 2,    2},
 {"PRM", 2,    2}, // 41
 {"PXR", 2,    2},
} ;
int Count_Sets = sizeof(Set_Params) / sizeof(ip); // РЕАЛЬНОЕ число пар в массиве Instruction_Params[]
////////////////////////////////////////////////////////////////////////////////
//
#define MAX_FLOAT 1.0e+300 // максимальное число с плавающей запятой ...........
#define MIN_FLOAT 1.0e-300 // минимальное число с плавающей запятой
#define EPS       1.0e-300 // минимальная точность вычислений ------------------
// M_PI_2 = pi/2 определено в math.h
//
////////////////////////////////////////////////////////////////////////////////
ULI localTick = 0,  // общее число тиков (происшедших тактов) по счётчику MasterTimer
    localTickOfEndLastExecuteSet, // тиков с конца последней выполненной инструкции
    waitAboveOfEndLastExecuteSet = 1000; // через сколько тиков закнчивать программу
int tick_Interval = 10; // цена деления тика таймера в миллисекундах (умолчание)
////////////////////////////////////////////////////////////////////////////////
const int minW_F1 = 1024, minH_F1 = 600; // минимальный размер окна главной формы (F1)
////////////////////////////////////////////////////////////////////////////////
ULI  FileSizeFromServer; // размер файла для выгрузки с сервера
char NameSubDirOutData[] = "Out!Data", // имя подкаталога для сброса рассчитанных данных
     PathToSubDirOutData[_256], // полный путь к подкаталогу сброса рассчитанных данных
     NameSubDirInData[]  = "In!Data", // имя подкаталога для исходных дынных данных
     PathToSubDirInData[_256], // полный путь к подкаталогу исходных данных данных
     MySite[] = "http://vbakanov.ru"; // адрес моего сайта
////////////////////////////////////////////////////////////////////////////////
// Определение стратегии порядка выбора инструкций из буфера
////////////////////////////////////////////////////////////////////////////////
int How_Calc_Prior = 0, // вычисление приоритета (0 - прямо пропорц. Parameter, 1 - обратно
    How_Calc_Param = 0; // вычисление параметра (0 - одинаковый,
                        // 1 - время выполнения инструкции,
                        // 2 - случайное число,
                        // 3 - число иных инструкций, для которых результаты данной является одним
                        // (любым или обоими) из входных операндов
////////////////////////////////////////////////////////////////////////////////
char attrVar[6]  = "$\0", // до 5 символов в начале переменных, говорящие возможности МНОГОКРАТНОГО ИЗМЕНЕНИЯ этой переменной
     startPos[2] = "?\0"; // начальная позиция в строке при выводе расширенных строк макроса
// =============================================================================
// управление выдачей сообщений о переполнении Mem_Data[] и Mem_Buffer[] и проблемах с парсером
bool flagAlarmData   = TRUE,
     flagAlarmBuffer = TRUE,
     flagAlarmParser = TRUE;
//
ULI dummy_Ticks = 1 ; // число пропущенных тиков для выполнения инструкции длиной 0 тиков
//
//==============================================================================
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
__fastcall TF1::TF1(TComponent* Owner) : TForm(Owner)
{ // выполняется при создании главной формы (конструктор)
 time_t t;
 srand((unsigned) time(&t));
//
 Master_Timer->Enabled = FALSE; // выключили главный таймер
//
////////////////////////////////////////////////////////////////////////////////
//
 Mem_Instruction = ( mi* ) malloc( Max_Instruction      * sizeof( mi ) ); // первоначальный захват памяти под динамические массивы
 Sel_Cell        = ( sc* ) malloc( 10 * Max_Instruction * sizeof( sc ) );
 Mem_Proc        = ( mp* ) malloc( Max_Proc             * sizeof( mp ) );
 Mem_Data        = ( md* ) malloc( Max_Data             * sizeof( md ) );
 Mem_Buffer      = ( mb* ) malloc( Max_Buffer           * sizeof( mb ) );
//
////////////////////////////////////////////////////////////////////////////////
 Tpr = new TStringList(); // создать набор строк для анализа загруженности АИУ
////////////////////////////////////////////////////////////////////////////////
 strcpy(FileNameINI, ChangeFileExt(ParamStr(0), ".ini").c_str()); // путь к INI-файлу
//
 Read_Config(); // читаем файл конфигурации (и перераспределяем память динамических массивов)
//
////////////////////////////////////////////////////////////////////////////////
//
 mB->Cells[0][0] = " #/Мнемоника"; // буфер инструкци (команд)
 mB->ColWidths[0]= 100;
//
 mB->Cells[1][0] = " Парам./Приор.";
 mB->ColWidths[1]= 115;
//
////////////////////////////////////////////////////////////////////////////////
//
 mI->Cells[0][0]  = " # п/п"; // таблица команд (инструкицй)
 mI->ColWidths[0] = 55;
//
 mI->Cells[1][0]  = " Мнемоника";
 mI->ColWidths[1] = 90;
//
 mI->Cells[2][0]  = " Операнд-1";
 mI->ColWidths[2] = 115;
//
 mI->Cells[3][0]  = " Операнд-2";
 mI->ColWidths[3] = 115;
//
 mI->Cells[5][0]  = " Предикат"; ///////////////////////////////////////////////
 mI->ColWidths[4] = 115;
//
 mI->Cells[4][0]  = " Результат";
 mI->ColWidths[5] = 115;
//
 mI->Cells[6][0]  = " Флаги";
 mI->ColWidths[6] = 90;
//
 mI->Cells[7][0]  = " Комментарий";
//
 mI->ColWidths[7] = sizeof(M_I.Comment); // длина поля комментария
//
////////////////////////////////////////////////////////////////////////////////
//
 mD->Cells[0][0] = " Адрес";  // таблица данных
 mD->ColWidths[0]= 90;
//
 mD->Cells[1][0] = " Значение";
 mD->ColWidths[1]= 100;
//
////////////////////////////////////////////////////////////////////////////////
//
 F1_OnResize( NULL ); // перерисуем главное окно
//
////////////////////////////////////////////////////////////////////////////////
//
 DecimalSeparator = '.'; // разделитель целой и десятичной частей - точка
//
 if( Read_Instructions() ) // читает инструкции из файла FileNameSet в массив структур Mem_Instruction[]
 {
  SBM0->Text = " Начните работу с нажатия кнопки ВЫПОЛНЕНИЕ..."; // вывод текста в StatusBarMain
//
  Install_All_Flags(); // очистить все флаги операторов
//
  Vizu_Sets(); // визуализация инструкций в SG_Set из массива структур Mem_Instruction[]
 }
 else // не удалось прочитать
 {
  BitBtn_Run->Enabled = FALSE; // "выключили" ВЫПОЛНЕНИЕ
  SBM0->Text = " Выберите файл программы для выполнения..."; // вывод текста в StatusBarMain
  MessageBeep( MB_ICONASTERISK ); // предупреждение...
  Delay( 1000 ); // ждать 1000 мсек
 }
//
} // конец F1 ------------------------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void t_printf(char *fmt, ...)
{  // не менее одного обязательного аргумента !
 int lenBuff = _256; // начальная длина буфера вывода
//
 char* buff = (char*) malloc( lenBuff ); // заказ первоначального буфера-строки для форматного вывода
 va_list args;  // определяем сущность СПИСОК в эллипсисе ( ...  )
 va_start( args, fmt );  // начало списка аргументов в эллипсисе
//
 int new_lenBuff = vsnprintf( buff, lenBuff, fmt, args ); // необходимая длина буфера для полноценного вывода строки
//
 if( new_lenBuff > lenBuff ) // необходимо увеличить буфер..!
 {
  buff = (char*) realloc( buff, new_lenBuff+1 ); // увеличиваем буфер (с учётом '\0' в конце)...
  vsnprintf( buff, new_lenBuff+1, fmt, args ); // заново выводим в (расширенный) буфер buff
 }
//
 va_end(args);  // конец списка аргументов в эллипсисе
//
 AddLineToProtocol( buff ); // добавление в Nemo_Run ( учитываются "\n" )
//
// free( buff );
} // ---- конец t_printf -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // удаляет пробелы и Tabs слева и справа строки str
DelSpacesTabsAround(char *str)
{  // Trim, TrimLeft, TrimRight работают только с AnsiString
// strcpy(str, Trim(AnsiString(str)).c_str());

// удаляем пробелы и Tabs с начала строки
 int i=0, j;

 while((str[i] == ' ') || (str[i] == '\t'))
  i++;

 if(i>0)
 {
  for(j=0;j<strlen(str);j++)
   str[j]=str[j+i];
//
 str[j]='\0';
 }

// удаляем пробелы и Tabs с конца строки
 i=strlen(str)-1;

 while((str[i] == ' ') || (str[i] == '\t'))
  i--;

 if(i<(strlen(str)-1))
  str[i+1]='\0';

} // --- конец функции DelSpacesTabsAround -------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall
RunExternal(char* CommandLine, byte RuleParent, byte Priority, bool RuleMessage)
// пытается стартовать процесс-потомок согласно командной строкe CommandLine
// при RuleParent=0 процесс-родитель ждет окончания работы потомка (при этом
// позволяя работать другим WINDOWS-приложениям через вызовы ProcessMessages)
// при RuleParent=1 процесс-родитель не ждет окончания работы потомка
// при всех других значениях RuleParent процесс-родитель
// после запуска процесса-потомка завершается.
//-----------------------------------------------------------------------
// Priority=0/1/2/3 соответствует приоритетам запускаемого приложения
//           REALTIME/HIGH/NORMAL/IDLE соответственно (для 16-бит не используется)
//          (все другие значения Priority соответствуют IDLE)
//-----------------------------------------------------------------------
//  При RuleMessage=TRUE выдается сообщение об ошибках }
{
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  DWORD dwCreationFlag,dwExitCode;
  bool out;
//
// все поля структуры si (кроме поля cb) должны быть обнулены
// т.к. этих полей много, присвоение нуля каждому писать лень...
// ниже приведен метод заполнения структуры нулями (используется FillChar)
  memset( &si, 0, sizeof(STARTUPINFO) );
  si.cb = sizeof(STARTUPINFO);  // заполним поле cb
//
  switch (Priority)  // настройка приоритета процесса-потомка
  {
   case 0: dwCreationFlag=REALTIME_PRIORITY_CLASS;
           break;
   case 1: dwCreationFlag=HIGH_PRIORITY_CLASS;
           break;
   case 2: dwCreationFlag=NORMAL_PRIORITY_CLASS;
           break;
   default:
           dwCreationFlag=IDLE_PRIORITY_CLASS;
  }
//
  out=CreateProcess(NULL,CommandLine,NULL,NULL,FALSE,
                    dwCreationFlag,NULL,NULL,&si,&pi);
//
  if (!out) // если старт неудачен... out=FALSE
  {
   if (RuleMessage)  // если задан режим выдачи сообщений об ошибках
    MessageDlg("Извините, выполнение\n\r\n\r" +
                AnsiUpperCase(CommandLine)  +
               "\n\r\n\rневозможно...  (ошибка " +
                IntToStr(GetLastError()) + ")",
                mtError,
                TMsgDlgButtons() << mbYes, 0);
   return;
  } // конец IF out = FALSE
//
  if (out) // если старт удачен... out = TRUE
  {
   if (RuleParent == 0) // если родитель должен ждать окончания работы потомка
   {
    CloseHandle(pi.hThread); // хэндл потока не нужен - удаляем
    if (WaitForSingleObject(pi.hProcess, INFINITE) != WAIT_FAILED) // бесконечный цикл ожидания
    {
     GetExitCodeProcess(pi.hProcess, &dwExitCode); // если ошибка функции ожидания...
     if (RuleMessage) // если задан режим выдачи сообщений об ошибках
      if (dwExitCode != WAIT_OBJECT_0) // WAIT_OBJECT_0 = естественное завершение процесса
       MessageDlg("Извините, процесс\n\r\n\r" +
                   AnsiUpperCase(CommandLine) +
                  "\n\r\n\rзакончен с ошибкой " +
                   IntToStr(dwExitCode) + "\n\r",
                   mtError,
                   TMsgDlgButtons() << mbOK, 0);
     CloseHandle(pi.hProcess); // освобождаем хэндл процесса
    } // конец IF WaitForSingleObject...
   } // конец IF RuleParent = 0
//
   if (RuleParent == 1) // родитель не должен ждать окончания работы потомка
    return; // выход - ничего не делая
//
   if ((RuleParent != 0) && // родитель завершается
       (RuleParent != 1))
    Application->Terminate(); // закончить родительский процесс
//
 } // конец IF out=TRUE
//
} // конец RunExternal ---------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall
TF1::SG_Sets_Edit(TObject *Sender) // вызов редактора файла инструкций
{
//
 if( !modeEdit ) // немодальный вызов
  ShellExecute(0, NULL, FileNameEditor, FileNameSet, NULL, SW_SHOWNORMAL);
//
 else // модальный вызов
 {
  char tmp[_256];
  snprintf( tmp,sizeof(tmp), "%s %s", FileNameEditor, FileNameSet );
  RunExternal(tmp, 0, 2, TRUE); // стартовать с ожиданием окончания
  Rewrite_Files( Sender ); // перечитать файл
 }
//
} // конец SG_Sets_Edit --------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::INI_Edit(TObject *Sender)
{ // вызов редактора файла настроек
//
 if( !modeEdit ) // немодальный вызов
  ShellExecute(0, NULL, FileNameEditor, FileNameINI, NULL, SW_SHOWNORMAL);
//
 else // модальный вызов
 {
  char tmp[_256];
  snprintf(tmp,sizeof(tmp), "%s %s", FileNameEditor, FileNameINI);
  RunExternal(tmp, 0, 2, TRUE); // стартовать с ожиданием окончания
  Rewrite_Files( Sender ); // перечитать файл
 }
//
 MessageBeep( MB_OK ); // звуковое предупреждение...
//
} // конец INI_Edit ------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // конец работы
TF1::On_Close_Main_Form(TObject *Sender)
{
 F1->Close();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // реакция на изменение положения лев.верхн. угла SG_Data
TF1::SG_Data_TopLeftChanged(TObject *Sender)
{
 SG_Data->LeftCol = 0;
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall  // реакция на изменение положения лев.верхн. угла SG_Buffer
TF1::SG_Buffer_TopLeftChanged(TObject *Sender)
{
 SG_Buffer->LeftCol = 0;
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::About_Cluster(TObject *Sender)
{ // информация об авторе
 ShellExecute(0, NULL, "http://vbakanov.ru/hist_clu/", NULL, NULL,SW_SHOWNORMAL);
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::About_Cuda(TObject *Sender)
{  // информация об авторе
 ShellExecute(0, NULL, "http://vbakanov.ru/cuda/", NULL, NULL,SW_SHOWNORMAL);
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::About_AW(TObject *Sender)
{  // об AlgoWiki
// ShellExecute(0, NULL, "https://algowiki-project.org/ru/%D0%9E%D1%82%D0%BA%D1%80%D1%8B%D1%82%D0%B0%D1%8F_%D1%8D%D0%BD%D1%86%D0%B8%D0%BA%D0%BB%D0%BE%D0%BF%D0%B5%D0%B4%D0%B8%D1%8F_%D1%81%D0%B2%D0%BE%D0%B9%D1%81%D1%82%D0%B2_%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D0%BE%D0%B2", NULL, NULL,SW_SHOWNORMAL);
 ShellExecute(0, NULL, "https://algowiki-project.org/ru/", NULL, NULL,SW_SHOWNORMAL);
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::About_Poems(TObject *Sender)
{ // информация о cтихотворном творчестве автора
 ShellExecute(0, NULL, "http://vbakanov.ru/poems_04.htm#dataflow", NULL, NULL,SW_SHOWNORMAL);
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::About_SPF(TObject *Sender)
{ // о проекте SPF@home
 ShellExecute(0, NULL, "http://vbakanov.ru/spf@home", NULL, NULL,SW_SHOWNORMAL);
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // перечитать все файлы
TF1::Rewrite_Files(TObject *Sender)
{
 Read_Config(); // читаем файл конфигурации
//
 Read_Instructions(); // читаем FileNameSet в Mem_Instruction[]
//
 mR->Clear(); // очистили Memo_Run .............................................
//
 Install_All_Flags(); // очистили все флаги в Mem_Sets[]
//
 Vizu_Sets(); // визуализировали инструкции в ОКНЕ_ИНСТРУКЦИЙ
//
 Really_Data = 0; // очистили пул данных
 Vizu_Data();  // визуализировали данные в ОКНЕ_ДАННЫХ
//
 Really_Buffer = 0; // очистили буфер
 Vizu_Buffer();  // визуализировали данные в буфере
//
 Clear_AllCells(); // очистим цвета всех ячеек таблицы инструкций
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::Show_Chema(TObject *Sender)
{ // показать схему DATA-FLOW вычислителя в PDF
 ShellExecute(0, NULL, "chema.pdf", NULL, NULL,SW_SHOWNORMAL);
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::N12Click(TObject *Sender)
{  // показать описание DATA-FLOW вычислителя в PDF
 ShellExecute(0, NULL, "base.pdf", NULL, NULL,SW_SHOWNORMAL);
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // ждать mSecs миллисекунд (с возможностью поработать WINDOWS)
Delay(long mSecs)
{
 // при mSecs<0 время ожидания измеряется уже в секундах
 unsigned long t,
          FirstTick = ::GetTickCount(); // запомнили начало отсчета
 t=(mSecs>=0 ? mSecs : -1e3*mSecs);
 while( ::GetTickCount()-FirstTick < t ) // работать, пока заданный интервал времени не истёк...
  Application->ProcessMessages(); // дать поработать WINDOWS
}
// --- конец Delay -------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Read_Config()
{// восстанавливает данные из файла конфигурации
//
 TIniFile *tINI = new TIniFile(ExpandFileName(FileNameINI)); // создали объект типа TIniIFile
//------------------------------------------------------------------------------
//
 Max_Instruction  = tINI->ReadInteger(RWC.Sect1, RWC.Sect1_Var1, MAX_INSTRUCTION); // число строк пула команд
  Max_Instruction = (Max_Instruction >  MAX_INSTRUCTION) ? MAX_INSTRUCTION : Max_Instruction;
  Max_Instruction = (Max_Instruction <= 0) ? 1 : Max_Instruction;
//
 Max_Data  = tINI->ReadInteger(RWC.Sect1, RWC.Sect1_Var2, MAX_DATA); // число строк пула данных
  Max_Data = (Max_Data >  MAX_DATA) ? MAX_DATA : Max_Data;
  Max_Data = (Max_Data <= 0) ? 1 : Max_Data;
//
 Max_Proc  = tINI->ReadInteger(RWC.Sect1, RWC.Sect1_Var3, MAX_PROC); // число задействованных АИУ
  Max_Proc = (Max_Proc >  MAX_PROC) ? MAX_PROC : Max_Proc;
  Max_Proc = (Max_Proc <= 0) ? 1 : Max_Proc;
//
 F1->E_AIU->Text = Max_Proc; // вывели в E_AIU =================================
//
 Max_Buffer  = tINI->ReadInteger(RWC.Sect1, RWC.Sect1_Var4, MAX_BUFFER); // число строк буфера инструкций
  Max_Buffer = (Max_Buffer >  MAX_BUFFER) ? MAX_BUFFER : Max_Buffer;
  Max_Buffer = (Max_Buffer <= 0) ? 1 : Max_Buffer;
//
////////////////////////////////////////////////////////////////////////////////
//
 Mem_Instruction = ( mi* ) realloc( Mem_Instruction, Max_Instruction * sizeof( mi ) ); // переопределяем память под динамические массивы
 Sel_Cell        = ( sc* ) realloc( Sel_Cell,   10 * Max_Instruction * sizeof( sc ) ); // если "старый" указатель=NULL, то аналог malloc()
 Mem_Proc        = ( mp* ) realloc( Mem_Proc,   Max_Proc   * sizeof( mp ) );
 Mem_Data        = ( md* ) realloc( Mem_Data,   Max_Data   * sizeof( md ) );
 Mem_Buffer      = ( mb* ) realloc( Mem_Buffer, Max_Buffer * sizeof( mb ) );
//
////////////////////////////////////////////////////////////////////////////////
//
 How_Calc_Param = tINI->ReadInteger(RWC.Sect4, RWC.Sect4_Var1, 0); // как вычислять параметр
 How_Calc_Prior = tINI->ReadInteger(RWC.Sect4, RWC.Sect4_Var2, 0); // как вычислять приоритет
//
 Delay_Buffer = abs (tINI->ReadInteger(RWC.Sect5, RWC.Sect5_Var1, 0)); // задержка визуализации буфера (миллисек)
//
 tick_ScanForGraph = tINI->ReadInteger(RWC.Sect6, RWC.Sect6_Var1, 1); // период вывода данных (тактов)
//
 tick_Interval = tINI->ReadInteger(RWC.Sect7, RWC.Sect7_Var1, 10); // период тика (миллисекунд)
 F1->Master_Timer->Interval = tick_Interval;
//
 Out_Data_SBM1(); // вывод данных в среднюю часть StatusBar -------------------
//
 F1->Top    = tINI->ReadInteger(RWC.Sect8, RWC.Sect8_Var1,      20); // // положение и размеры главной формы
 F1->Left   = tINI->ReadInteger(RWC.Sect8, RWC.Sect8_Var2,      20);
 F1->Width  = tINI->ReadInteger(RWC.Sect8, RWC.Sect8_Var3, minW_F1);
 F1->Height = tINI->ReadInteger(RWC.Sect8, RWC.Sect8_Var4, minH_F1);
//
 strcpy( FileNameSet, tINI->ReadString(RWC.Sect9, RWC.Sect9_Var1, "DataFlow.set").c_str()); // имя файла программы
//
//------------------------------------------------------------------------------
//
 for(int i=0; i<Count_Sets; i++) // по списку инструкций
  Set_Params[i].Time = tINI->ReadInteger(RWC.Sect2, Set_Params[i].Set, Set_Params[i].Time);
//
 strcpy(FileNameEditor, tINI->ReadString(RWC.Sect3, RWC.Sect3_Var1, "notepad.exe").c_str()); // файл текстового редактора
 modeEdit = tINI->ReadBool(RWC.Sect3, RWC.Sect3_Var2, FALSE); // режим вызова текстового редактора
//
//------------------------------------------------------------------------------
 strcpy( attrVar, tINI->ReadString(RWC.Sect10, RWC.Sect10_Var1, "$\0").c_str() );
// первый символ для переменных, не подчиняюшихся ПРАВИЛУ ЕДИНОКРАТНОГО ПРИСВАИВАНИЯ
//------------------------------------------------------------------------------
 modeGraph = tINI->ReadBool(RWC.Sect11, RWC.Sect11_Var1, TRUE); // режим отрисовки графика интенсивности вычислений
//-----------------------------------------------------------------------------
 waitAboveOfEndLastExecuteSet = tINI->ReadInteger(RWC.Sect12, RWC.Sect12_Var1, 1000); // cколько тиков ждать очередной инструкции
//
 DCE.needDrawColors    = tINI->ReadBool(RWC.Sect13,    RWC.Sect13_Var1, TRUE);  // надо ли выделять цветом ячейки при выполнении
 DCE.clReadyOperand    = tINI->ReadInteger(RWC.Sect13, RWC.Sect13_Var2, RGB(255,153,255)); // цвет готовности операндов
 DCE.clTruePredicat    = tINI->ReadInteger(RWC.Sect13, RWC.Sect13_Var3, RGB(255,153,255)); // цвет состояния TRUE флага предиктора
 DCE.clExecSet         = tINI->ReadInteger(RWC.Sect13, RWC.Sect13_Var4, RGB(255, 51,153)); // цвет выполнения  инструкции
//
 DCT.clOperandOperation = tINI->ReadInteger(RWC.Sect14, RWC.Sect14_Var1, RGB(255,185,185)); // связь ОПЕРАНДЫ<->ОПЕРАЦИИ
 DCT.clNonExecuted      = tINI->ReadInteger(RWC.Sect14, RWC.Sect14_Var2, RGB(255,185,255)); // неисполненные инструкции
 DCT.clNonUsedResult    = tINI->ReadInteger(RWC.Sect14, RWC.Sect14_Var3, RGB(255,192,0)); // неиспользованные результаты
 DCT.clNonDefOperands   = tINI->ReadInteger(RWC.Sect14, RWC.Sect14_Var4, RGB(0,255,255)); // неопределённые операнды
//
 DGR.clGraphStart = tINI->ReadInteger(RWC.Sect15, RWC.Sect15_Var1, RGB(255,0,0)); // начало тела графика интенсивности вычислений
 DGR.clGraphEnd   = tINI->ReadInteger(RWC.Sect15, RWC.Sect15_Var2, RGB(0,255,0)); // конец тела графика интенсивности вычислений
//
 StartNumb        = tINI->ReadInteger(RWC.Sect16, RWC.Sect16_Var1, 100); // начальный номер операторов
//
 delete tINI; // уничтожили объект - более не нужен !...
//
} // --- конец Read_Config -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Write_Config()  // сохраняет данные в файл конфигурации
{
//
 TIniFile* tINI = new TIniFile(FileNameINI); // создали объект типа TIniIFile
//
 tINI->WriteInteger(RWC.Sect4, RWC.Sect4_Var1, How_Calc_Param); // как вычислять параметр приоритета
 tINI->WriteInteger(RWC.Sect4, RWC.Sect4_Var2, How_Calc_Prior); // как вычислять приоритет
 tINI->WriteInteger(RWC.Sect1, RWC.Sect1_Var3, StrToInt(F1->E_AIU->Text)); //Max_Proc); // число задействованных АИУ
//
 tINI->WriteInteger(RWC.Sect8, RWC.Sect8_Var1, F1->Top); // // положение и размеры главной формы
 tINI->WriteInteger(RWC.Sect8, RWC.Sect8_Var2, F1->Left);
 tINI->WriteInteger(RWC.Sect8, RWC.Sect8_Var3, F1->Width);
 tINI->WriteInteger(RWC.Sect8, RWC.Sect8_Var4, F1->Height);
//
// --- если путь к Set-фaйлу = текущему каталогу, путь не пишем (только имя файла)
 if( !strcmp( ExtractFileDir(FileNameSet).c_str(),ExtractFileDir(ParamStr(0)).c_str() ) )
  strcpy( FileNameSet,ExtractFileName(FileNameSet).c_str() );
//
 tINI->WriteString(RWC.Sect9, RWC.Sect9_Var1, FileNameSet); // имя файла скрипта
//
 tINI->WriteString(RWC.Sect10, RWC.Sect10_Var1, attrVar);
// первый символ для переменных, не подчиняюшихся ПРАВИЛУ ЕДИНОКРАТНОГО ПРИСВАИВАНИЯ
//
 tINI->WriteBool(RWC.Sect13,    RWC.Sect13_Var1, DCE.needDrawColors); // надо ли выделять цветом ячейки при выполнении
 tINI->WriteInteger(RWC.Sect13, RWC.Sect13_Var2, DCE.clReadyOperand); // цвет готовности операндов
 tINI->WriteInteger(RWC.Sect13, RWC.Sect13_Var3, DCE.clTruePredicat); // цвет состояния TRUE флага предиктора
 tINI->WriteInteger(RWC.Sect13, RWC.Sect13_Var4, DCE.clExecSet); // цвет выполнения  инструкции
//
 tINI->WriteInteger(RWC.Sect14, RWC.Sect14_Var1, DCT.clOperandOperation); // связь ОПЕРАНДЫ<->ОПЕРАЦИИ
 tINI->WriteInteger(RWC.Sect14, RWC.Sect14_Var2, DCT.clNonExecuted); // неисполненные инструкции
 tINI->WriteInteger(RWC.Sect14, RWC.Sect14_Var3, DCT.clNonUsedResult); // неиспользованные результаты
 tINI->WriteInteger(RWC.Sect14, RWC.Sect14_Var4, DCT.clNonDefOperands); // неопределённые операнды
//
 tINI->WriteInteger(RWC.Sect15, RWC.Sect15_Var1, DGR.clGraphStart); // начало тела графика интенсивности вычислений
 tINI->WriteInteger(RWC.Sect15, RWC.Sect15_Var2, DGR.clGraphEnd); // конец тела графика интенсивности вычислений
//
 MessageBeep( MB_OK ); // звуковое предупреждение...
//
 delete tINI; // уничтожили объект - более не нужен !...
//
} // --- конец Write_Config ----------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall // визуализация инструкций в SG_Set из массива структур Mem_Instruction[]
Vizu_Sets()
{
 char Set[_SET_LEN], // мнемоника инструкции
      tmp[_512];
//
 if( !Really_Set )
 {
  mI->RowCount = Really_Set + 2; // настроили число строк в визуализируемом объекте
  for(int j=0; j<9; j++) // чистим строку с номером 1 (вторую сверху)
   mI->Cells[j][1] = "";
  return TRUE;
 }

 mI->RowCount = Really_Set + 1; // настроили число строк в визуализируемом объекте

 for(UI i=0; i<Really_Set; i++) // теперь ВИЗУАЛИЗИРУЕМ инструкции (вывод в SG_Set)...
  {
   for(int j=0; j<7; j++) // по всем колонкам строки i
    mI->Cells[j][i+1] = ""; // очистили !

////////////////////////////////////////////////////////////////////////////////
   mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции

// нулевой столбец /////////////////////////////////////////////////////////////
   snprintf(tmp,sizeof(tmp), "%7d", i); // число 'прижато' к правому краю (умолчание)
   mI->Cells[0][i+1] = tmp; // номер инструкции

// первый столбец - мнемоника инструкции ///////////////////////////////////////
   strcpy(Set, Mem_Instruction[i].Set); // в Set - мнемоника инструкции (так легче работать...)

   snprintf(tmp,sizeof(tmp), "  %s", Set); // два пробела перед мнемоникой
   mI->Cells[1][i+1] = tmp; // мнемоника инструкции

////////////////////////////////////////////////////////////////////////////////
   switch( Get_CountOperandsByInstruction(Set) ) // ... число входных операндов инструкции Set
   {
    case 1: mI->Cells[2][i+1] = Mem_Instruction[i].aOp1; // адрес первого (и единственного) операнда
            mI->Cells[3][i+1] = "";
            mI->Cells[5][i+1] = Mem_Instruction[i].aPredicat; // адрес предиката
            mI->Cells[4][i+1] = Mem_Instruction[i].aResult; // адрес результата
            mI->Cells[7][i+1] = Mem_Instruction[i].Comment; // комментарий

            break;

    case 2: mI->Cells[2][i+1] = Mem_Instruction[i].aOp1; // адрес первого операнда
            mI->Cells[3][i+1] = Mem_Instruction[i].aOp2; // адрес второго операнда
            mI->Cells[5][i+1] = Mem_Instruction[i].aPredicat; // адрес предиката
            mI->Cells[4][i+1] = Mem_Instruction[i].aResult; // адрес результата
            mI->Cells[7][i+1] = Mem_Instruction[i].Comment; // комментарии

            break;

   default: break;

   } // конец switch
//
   if( is_PredicatOrSET( Set ) ) // это SET или ПРЕДИКТОР (поле флага предиктора ПУСТОЕ)
    mI->Cells[5][i+1] = ""; // ... поле ПРЕДИКАТА - ПУСТОЕ..!
//
  } // конец цикла по i=0, Really_Set
//
  return TRUE;
//
} // --- конец Vizu_Sets -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // визуализация инструкций в SG_Data из массива структур Mem_Data[]
Vizu_Data()
{
 char tmp[_512];
//
// mD->Cells->BeginUpdate(); // у TStringGrid НЕТУ BeginUpdate и EndUpdate
 mD->DoubleBuffered = TRUE; // двойная буфферизация - чтобы не мигало..!
//
 if(!Really_Data)
 {
  mD->RowCount = Really_Data + 2; // настроили число строк в визуализируемом объекте
  for(int j=0; j<2; j++) // чистим строку с номером 1 (вторую сверху)
   mD->Cells[j][1] = " ";
  return;
 }
//
 mD->RowCount = Really_Data + 1; // настроили число строк в визуализируемом объекте
//
 for(UI i=0; i<Really_Data; i++) // теперь ВИЗУАЛИЗИРУЕМ инструкции (вывод в SG_Set)...
  {
   mD->Cells[0][i+1] = Mem_Data[i].Addr; // значение адреса
   snprintf(tmp,sizeof(tmp), "%.*e", ACC_REAL, Mem_Data[i].Data); // значение числа по данному адресу
   mD->Cells[1][i+1] = tmp;
// вывод значений логических предикатов ========================================
//
 if( is_ResultIsPredicat( Mem_Data[i].Addr ) ) // это имя флага предиктора?
  mD->Cells[1][i+1] = Mem_Data[i].Data ? trueLowerCase : falseLowerCase;
//
 } // конец if(UI i=0; ...

////////////////////////////////////////////////////////////////////////////////

// mD->Repaint(); // принудительно перерисовали

} // --- конец Vizu_Data -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall
Vizu_Buffer() // визуализация данных в SG_Buffer из массива структур Mem_Buffer[]
{
 char tmp[_512];
// mB->Cells->BeginUpdate(); // у TStringGrid НЕТУ BeginUpdate и EndUpdate
 mB->DoubleBuffered = TRUE; // двойная буфферизация - чтобы не мигало..!

 if(!Really_Buffer)
 {
  mB->RowCount = Really_Buffer + 2; // настроили число строк в визуализируемом объекте
  for(int j=0; j<2; j++) // чистим строку с номером 1 (вторую сверху)
   mB->Cells[j][1] = " ";
  return;
 }

 mB->RowCount = Really_Buffer + 1; // настроили число строк в визуализируемом объекте

 for(UI i=0; i<Really_Buffer; i++) // теперь ВИЗУАЛИЗИРУЕМ инструкции (вывод в SG_Buffer)...
  {
   snprintf(tmp,sizeof(tmp), "%7d / %s",  // номер инструкции и ее мнемоника как строка
                             Mem_Buffer[i].i_Set, Mem_Instruction[Mem_Buffer[i].i_Set].Set);
   mB->Cells[0][i+1] = tmp;

   snprintf(tmp,sizeof(tmp), "%.3f / %.3f", // готовим строку вмда "Param / Priority"
                             Mem_Buffer[i].Param,
                             Mem_Buffer[i].Priority);
   mB->Cells[1][i+1] = tmp;
  }

// mB->Repaint(); // принудительно перерисовали

} // конец Vizu_Buffer ---------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // читаем файл конфигурации
TF1::Main_Form_OnCreate(TObject *Sender)
{
// ReadConfig();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // попытка закрытия приложения
TF1::F1_OnClose(TObject *Sender, TCloseAction &Action)
{
 Write_Config(); // сохранение файла конфигурации

 if(ParamCount() == 4) // берем нужное число параметров командной строки (не считая нулевого)
 {
  Action=caFree; // закрываем приложение без вопросов
  return;
 }
//
 switch(MessageBox(0, "Вы в самом деле хотите закончить работу ?",
                       "Предупреждение",
                        MB_YESNO | MB_ICONWARNING | MB_TOPMOST))
 {case IDYES: Action=caFree; // нажата кнопка Yes
              Regim = 0; // конец работы программы
//
              if( F2 )
               F2->Close(); // окно графика интенсивности вычислений закрыли
//
              if( F3 )
               F3->Close(); // окно графика интенсивности вычислений закрыли
//
              Delay(100); // ждем-c
              break;
//
  case IDNO:  Action=caNone; // нажата кнопка No
              break;
 }
} // ---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // нажатие кнопки СТОП
TF1::Stop_Calculations(TObject *Sender)
{
 StopCalculations( 0 ); // выполнение остановлено пользователем
} // конец Stop_Calculations ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall
StopCalculations( int Rule )
{ // при Rule==0 "Выполнение остановлено пользователем",
  // при Rule==1 "Программа завершена по выполнению всех ГКВ-операторов"
  // при Rule==2 "Выполнение программы остановлено"
 char tmp[_512];
 INT countSets = 0;
//
 F1->Master_Timer->Enabled = FALSE; // ещё раз на всякий случай..!
//
 Regim = 0; // останов счета пользователем
//
 switch( Rule )
 {
  case 0:
    strcpy(tmp, "\n-I- Выполнение программы завершено по требованию пользователя -I-");
    SBM0->Text = tmp; // вывод текста в StatusBarMain
    AddLineToProtocol( tmp );
    break;
//
  case 1:
    for( INT i=0; i<Really_Set; i++ ) // по всем инструкциям данной программы
     if( strcmp( Mem_Instruction[i].Set,"SET" ) ) // если это не SET...
      countSets++;
//
    snprintf(tmp,sizeof(tmp), "\n-W- Программа завершена: в течение %d (задано) тактов не выявлено ни одной ГКВ-инструкции (выполнено/всего инструкий: %d/%d исключая SET) -W-",
             waitAboveOfEndLastExecuteSet, mTpr->Count, countSets );
    SBM0->Text = tmp; // вывод текста в StatusBarMain
    AddLineToProtocol( tmp );
    break;
//
  case 2:
    snprintf(tmp,sizeof(tmp), "-I- Выпонение программы остановлено... -I-");
    SBM0->Text = tmp; // вывод текста в StatusBarMain
    AddLineToProtocol( tmp ); // вывод текста в подокно протокола выполнения
    break;
//
  default:
    break;
 } // конец switch
//
 F1->OnOf_Execute( 0 ); // "выключили" визуальную индикацию режима СЧЁТ
//
 MessageBeep( MB_OK ); // звуковое предупреждение...
//
 if( Rule != 0 ) // при останове по кнопке не надо вычислять статистику выполнения программы
  Calc_Stat_Proc(); // вычисление статистики использования АИУ -----------------
//
 Regim = 2; // режим естественного конца выполнения программы - надо ДО вызова Show_Graph()
//
 if( modeGraph & Rule != 0 ) // если FALSE, то только по F6
  F1->Show_Graph( NULL ); // показать график интенсивности вычислений
//
} // конец Stop_Calculations ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
REAL __fastcall // возвращает из Mem_Data[] число по адресу (имени) Addr
Get_Data(char *Addr)
{ // если строка 'Addr / Dаta' не существует - выдается предупреждение и результат = 1.0e0
// char tmp[_512];
//
 for(UI i=0; i<Really_Data; i++) // ищем путём простого последовательного перебора массива Mem_Data[]
  if(!strcmp(Mem_Data[i].Addr, Addr))
   return (Mem_Data[i].Data);
//
// не нашли... информируем об этом !!! /////////////////////////////////////////
 t_printf( "-W- %s() не нашёл в Mem_Data[] значения по адресу %s. Принято 1.0e0 -W-",
            __FUNC__,Addr);
//
  return 1.0 ;
} // ---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall // возвращает текст инструкции из Mem_Sets[i]
Line_Set(int i_Set, int Rule)
{ // при Rule = 0 содержимое aResult не выдается (выдается "?")
  // при Rule = 1 содержимое aResult возвращается
  // при Rule = -1 возвращается только строка инструкции
 char Set[_SET_LEN], tmp1[_512];
 char tmp[_512];

 strcpy(Set, Mem_Instruction[i_Set].Set); // мнемоника инструкции... далее такъ проще работать !

 switch( Rule ) // выбор по значению Rule
 {
////////////////////////////////////////////////////////////////////////////////
  case 0: strcpy(tmp1, "?");
//
          if( is_SET( Set )) // это SET ........................................
           snprintf(tmp,sizeof(tmp), "%s {%.*e}, %s {%s} %s %s",
                        Mem_Instruction[i_Set].Set,
                        ACC_REAL, atof(Mem_Instruction[i_Set].aOp1),
                        Mem_Instruction[i_Set].aResult, tmp1,
                        startComments,
                        Mem_Instruction[i_Set].Comment);

          break; // break case 0;
//
////////////////////////////////////////////////////////////////////////////////
  case 1: snprintf(tmp1,sizeof(tmp1), "%.*e", ACC_REAL, Get_Data(Mem_Instruction[i_Set].aResult)); // содержимое по адресу (строка!) aResult
//
          if( is_SET(  Set ) ) // это SET ......................................
           snprintf(tmp,sizeof(tmp), "%s {%.*e}, %s {%s} %s %s",
                         Mem_Instruction[i_Set].Set,
                         ACC_REAL, atof(Mem_Instruction[i_Set].aOp1),
                         Mem_Instruction[i_Set].aResult, tmp1,
                         startComments,
                         Mem_Instruction[i_Set].Comment);
//
          else
//==============================================================================
          switch( Get_CountOperandsByInstruction(Set) )
           { // ... по числу входных операндов инструкции Set
            case 1: snprintf(tmp,sizeof(tmp), "%s %s {%.*e}, %s {%s} %s %s",
                                   Mem_Instruction[i_Set].Set,
                                   Mem_Instruction[i_Set].aOp1,
                                   ACC_REAL, Get_Data(Mem_Instruction[i_Set].aOp1),
                                   Mem_Instruction[i_Set].aResult, tmp1,
                                   startComments,
                                   Mem_Instruction[i_Set].Comment);
                    break;
            case 2: snprintf(tmp,sizeof(tmp), "%s %s {%.*e}, %s {%.*e}, %s {%s} %s %s",
                                   Mem_Instruction[i_Set].Set,
                                   Mem_Instruction[i_Set].aOp1,
                                   ACC_REAL, Get_Data(Mem_Instruction[i_Set].aOp1),
                                   Mem_Instruction[i_Set].aOp2,
                                   ACC_REAL, Get_Data(Mem_Instruction[i_Set].aOp2),
                                   Mem_Instruction[i_Set].aResult, tmp1,
                                   startComments,
                                   Mem_Instruction[i_Set].Comment);
                    break;
           default: break;
//
           } // конец switch(Get_CountOperandsByInstruction(Set))
//==============================================================================

          break; // break case 1;

////////////////////////////////////////////////////////////////////////////////
  case -1:if( is_SET( Set ) ) // это SET .......................................
           snprintf(tmp,sizeof(tmp), "%s {%.*e}, %s %s %s",
                         Mem_Instruction[i_Set].Set,
                         ACC_REAL, atof(Mem_Instruction[i_Set].aOp1),
                         Mem_Instruction[i_Set].aResult,
                         startComments,
                         Mem_Instruction[i_Set].Comment);

          else
//==============================================================================
          switch( Get_CountOperandsByInstruction(Set) )
           { // ... по числу входных операндов инструкции Set
            case 1: snprintf(tmp,sizeof(tmp), "%s %s, %s %s %s",
                                  Mem_Instruction[i_Set].Set,
                                  Mem_Instruction[i_Set].aOp1,
                                  Mem_Instruction[i_Set].aResult,
                                  startComments,
                                  Mem_Instruction[i_Set].Comment);
                    break;
            case 2: snprintf(tmp,sizeof(tmp), "%s %s, %s, %s %s %s",
                                  Mem_Instruction[i_Set].Set,
                                  Mem_Instruction[i_Set].aOp1,
                                  Mem_Instruction[i_Set].aOp2,
                                  Mem_Instruction[i_Set].aResult,
                                  startComments,
                                  Mem_Instruction[i_Set].Comment);
                    break;
           default: break;
//
           } // конец switch(Get_CountOperandsByInstruction(Set))
//==============================================================================
//
          break; // break case -1;
//
  default: break;
//
 } // конец switch( Rule )
//
////////////////////////////////////////////////////////////////////////////////
//
 DelSpacesTabsAround(tmp); // обрезаем пробелы спереди и сзади
//
 return tmp;
//
} // ------ конец Line_Set -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // добавляет в Mem_Data[] число Data по адресу (имени) Addr
Add_toData(int i_Set, char* aResult, REAL Data)
{
// i_Set - номер инструкции, в результате котрой было вычислено это значениe
// aResult - имя ячейки (переменной), Data - значение переменной
// если строка 'Addr / ***' существует - переписывается поле Data, выдается
// предупреждение и пул данных визуализируетсяЯ; если не существует - добавим
// (включая ВИЗУАЛИЗАЦИЮ)
 char tmp[_512], tmp1[_1024];
//
// не нарушен ли ПРИНЦИП ЕДИНОКРаТНОГО ПРИСВАИВАНИЯ (т.е. нет ли данных с идентификатором Addr ?)
//
 for(ULI i=0; i<Really_Data; i++) // ищем путем тупого последовательного перебора
//
  if( !strcmp( Mem_Data[i].Addr, aResult ) ) // данные с адресом (именем) aResult в массиве Mem_Data[].Attr УЖЕ ЕСТЬ !!!
  {
//
   if( !memcmp( aResult, attrVar, strlen(attrVar) ) ) // если первые символы aResult есть attVar - можно переписывать данные...
   {
    Mem_Data[i].Data = Data; // переписАли данные по заданному адресу...
    return;
   } // конец if( !memcmp( Addr,attrVar,strlen(attrVar) )
//
   if( Data == Mem_Data[i].Data ) // если записываемое значение равно уже существующему...
   {
    t_printf( "-\n-W- %s(): Обнаружена ситуация попытки переписи элемента данных %s тем же значением %.*e (%s)... -W-\n-",
              __FUNC__, Mem_Data[i].Addr, Data, Get_Time_asLine());
//    MessageBeep( MB_ICONASTERISK ); // предупреждение...
    return;
   }  // конец if( Data == Mem_Data[i].Data )
//
   F1->Master_Timer->Enabled = FALSE; // выключили таймер
//
   strcpy(tmp, "Результат {%.*e} выполнения инструкция #%d должен быть записан по адресу %s, однако там уже находятся данные {%.*e}. ");
   strcat(tmp, "Налицо явное нарушение ПРИНЦИПА ОДНОКРАТНОГО ПРИСВАИВАНИЯ, вследствие чего КОНЕЧНЫЙ результат выполнения программы может быть непредсказуем !");
   strcat(tmp, "\n\nПереписать данные / оставить прежние значения / завершить выполнение программы ?\n");
   snprintf(tmp1,sizeof(tmp1), tmp, ACC_REAL, Data, i_Set, aResult, ACC_REAL, Mem_Data[i].Data);
//
   int out = MessageDlg(tmp1, mtWarning, TMsgDlgButtons() << mbOK << mbCancel << mbAbort, 0); // выдали окно выбора дальнейших действий
//
   switch (out) // принЯтие решения по коду возврАта из MessageDlg()...
   {
    case mrOk: // переписАть данные по этому адресу
               snprintf(tmp,sizeof(tmp), "%.*e", ACC_REAL, Data);
               mD->Cells[1][i+1] = tmp; // вЫвели в ОКНО_ДАННЫХ
               t_printf( "-W- %s(): нарушение ПРИНЦИПА ОДНОКРАТНОГО ПРИСВАИВАНИЯ: результат {%.*e} выполнения инструкция #%d должен быть записан по адресу %s, но там уже находятся данные {%.*e}. Данные перезапИсаны... -W-",
                          __FUNC__, ACC_REAL, Data, i_Set, aResult, ACC_REAL, Mem_Data[i].Data );
               Mem_Data[i].Data = Data; // переписАли данные по заданному адресу...
//
               F1->Master_Timer->Enabled = TRUE; // вновь включили таймер... а тамъ БУДЪ ЧТО БуДЕТ !..
//
               return;
//
    case mrCancel: // отказаться от пЕреписи и сохранить предыдУщие значения
               t_printf( "-W- %s(): нарушение ПРИНЦИПА ОДНОКРАТНОГО ПРИСВАИВАНИЯ: результат {%.*e} выполнения инструкция #%d должен быть записан по адресу %s, но там уже находятся данные {%.*e}. Данные НЕ перезапИсаны... -W-",
                          __FUNC__, ACC_REAL, Data, i_Set, aResult, ACC_REAL, Mem_Data[i].Data );
//
               F1->Master_Timer->Enabled = TRUE; // вновь включили таймер... а тамъ БУДЪ ЧТО БуДЕТ !..
//
               return;
//
    case mrAbort: // закончить выполнение программы...
               F1->Stop_Calculations(NULL);
//
               F1->Master_Timer->Enabled = FALSE; // выключили таймер...
//
               return;
//
   } // конец выбора по switch (случай нарушЕния концепции ЕДИНОКРАТНОГО ПРИВАИВАНИЯ)
//
  } // конец if(!strcmp(Mem_Data[i].Addr, Addr))
//
// такой строки не существует... УРА!!! Можно добавлять ........................
//
 if( Really_Data > 0.5*Max_Data ) // информировать об опасности заполненности массива..!
 {
  snprintf( tmp,sizeof(tmp), "Данные (%d%)", int( 1e2*Really_Data/Max_Data) );
  F1->Label_Data->Caption = tmp; // число адресов (имён) данных
  F1->Label_Data->Repaint();
 }
//
 if( Really_Data >= Max_Data-1 ) // опасность превышЕния размеры пула данных
 {
  if( flagAlarmData ) // надо выдавать сообщения...
  {
   t_printf( "-\n-W- %s(): память данных (%d) исчерпана, возможна потеря информации (%s)... -W-\n-",
              __FUNC__, Max_Data, Get_Time_asLine());
   ShowMessage( "Память данных исчерпана, при дальнейшей работе возможна потеря информации..." );
   MessageBeep( MB_ICONASTERISK ); // предупреждение...
//
   flagAlarmData = FALSE;
  } // после первого раза сообшения не выдаётся...
//  StopCalculations( 2 ); // выполнение программы невозможно
//
   return;
//
 } // конец if( Really_Data >= Max_Data )
//
 strcpy( Mem_Data[Really_Data].Addr, aResult ); // добавили в ПУЛ_ДАННЫХ имя переменной
 Mem_Data[Really_Data].Data  = Data; // значение переменной
 Mem_Data[Really_Data].i_Set = i_Set; // номер оператора, который это вычислил
//
// успешно добавлено ...........................................................
 t_printf( "-I- %s(): данные {%.*e} (результат выполнения инструкции #%d) по адресу %s успешно добавлены в память данных (%s) -I-",
           __FUNC__, ACC_REAL, Data, i_Set, aResult, Get_Time_asLine());
//
 mD->RowCount = Really_Data + 2; // обязательно 2 (чтобы при Really_Data=0 было 2, а не 1)
 snprintf(tmp,sizeof(tmp), "%.*e", ACC_REAL, Data);
 mD->Cells[0][Really_Data+1] = aResult;
 mD->Cells[1][Really_Data+1] = tmp; // вывели в ОКНО_ДАННЫХ
//
 Really_Data ++ ;
} // ----- конец Add_toData ----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall  // перемешивает инструции в Mem_Sets[] и в ОКНЕ_ИНСТРУКЦИЙ
TF1::Mixed_Sets(TObject *Sender)
{
 ULI i1,i2; // номера перемешиваемых инструкций в Mem_Sets[]
 time_t t;

 Really_Data = 0; // очистили ОКНО_ДАННЫХ
 Vizu_Data();

 Really_Buffer = 0; // очистили буфер
 Vizu_Buffer();  // визуализировали данные в буфере

////////////////////////////////////////////////////////////////////////////////
 BitBtn_Run->Enabled = FALSE; // "выключили" вариант меню ПЕРЕМЕШАТЬ_ИНСТРУКЦИИ

 srand((unsigned) time(&t)); // инициализации датчика случайных чисел текущим временем

 SBM0->Text = " Происходит случайное перемешивание инструкций..."; // вывод текста в StatusBarMain

 for(ULI i=0; i<Really_Set; i++) // перемешиваем Really_Sets раз
 {
  i1 = random(Really_Set), // "старый" номер инструкции (счет начинаем с нуля)
  i2 = random(Really_Set); // "новый" номер инструкции

  if(i1 == i2) // нечего менять местами...
   continue;

  M_I = Mem_Instruction[i1]; // запомнили "старое"
  Mem_Instruction[i1] = Mem_Instruction[i2]; // #i2 -> #i1
  Mem_Instruction[i2] = M_I; // #i1 -> #i2

  if(!(Really_Set % 10)) // каждый десятый раз
  {
   Vizu_Sets(); // визуализировать таблицу
   Delay(10);
  }

 } // конец по Mem_Instruction[i]

 Vizu_Sets(); // визуализировать таблицу

 SBM0->Text = " Инструкции перемешаны случайным образом"; // вывод текста в StatusBarMain

////////////////////////////////////////////////////////////////////////////////
 BitBtn_Run->Enabled = TRUE; // "включили" вариант меню ПЕРЕМЕШАТЬ_ИНСТРУКЦИИ
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // очищаем ВСЕ ФЛАГИ в Mem_Sets[]
Install_All_Flags()
{
 for(UI i=0; i<Really_Set; i++) // по всем инструкциям ... не все ОБНУЛЯЕМ !
 {
  MI_fOp1(i) = FALSE;
  MI_fOp1(i) = FALSE;
//
  Mem_Instruction[i].fPredicat     = FALSE;
  Mem_Instruction[i].fPredicatTRUE = FALSE;
//
  Mem_Instruction[i].fExec      = FALSE;
  Mem_Instruction[i].fExecOut   = FALSE;
  Mem_Instruction[i].fAddBuffer = FALSE;
 }
} // -----  Install_All_Flags --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::Load_Sets(TObject *Sender)
{ // открыть файл программы (файл *.set)

 Read_Config(); // перечитать файл конфигурации

 OD_1->Files->Clear(); // чистим историю

 if(OD_1->Execute()) // если что-то выбрали...
  {
   strcpy( FileNameSet, OD_1->FileName.c_str() ); // выбранный файл инструкций копируем в FileNameSet

   Write_Config(); // переписать файл конфигурации (в основном касается поля FileNameSet)
//
   Read_Instructions(); // читаем файл в Mem_Sets[]

   mR->Clear(); // очистили Memo_Run ...........................................

   Install_All_Flags(); // очистили все флаги в Mem_Sets[] !!!!!!!!!!!!!!!!!!!!!!!

   Vizu_Sets(); // визуализировали инструкции в ОКНЕ_ИНСТРУКЦИЙ

   Really_Data = 0; // очистили пул данных
   Vizu_Data();  // визуализировали данные в ОКНЕ_ДАННЫХ

   Really_Buffer = 0; // очистили буффер
   Vizu_Buffer();  // визуализировали буфер

   Clear_AllCells(); // очистим цвета всех ячеек таблицы инструкций

   SBM0->Text = " Начните работу с нажатия кнопки ВЫПОЛНЕНИЕ..."; // вывод текста в StatusBarMain
   BitBtn_Run->Enabled = TRUE; // "включили" кнопку ВЫПОЛНИТЬ

//   REAL index = Calc_ConnectedIndex( 1 ); // подсчет ИНДЕКСОВ СВЯЗНОСТИ c сохранением в файл
  }
} //------конец Load_Sets-------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall // возвращается подстрока строки Str от символа n1 до n2 (начиная с 1 !!! )
GetSubString(char *Str, int n1, int n2)
{
 char tmp[_1024] = "\0"; // рабочая строка
 int j = -1;
//
// strcpy(tmp, "\0"); // обнулили строку
//
 for(int i=0; i<strlen(Str); i++)
  if( ((i+1) >= n1) &&
      ((i+1) <= n2))
  {
   tmp[++j] = Str[i];
   tmp[j+1] = (char)'\0';
  }
//
 strcat(tmp, "\0");
//
 return tmp ;
} // ---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall  // вычисляется статистика использования АИУ
Calc_Stat_Proc()
{
 if( Regim == 2 ) // ошибка...
  return;
//
 char Set[_SET_LEN], tmp[_1024], tmp1[_1024], w[_512];;
 INT n_Sets, // число выполнений каждой инструкции
     sum_tProc; // время работы каждого из АИУ
//
// SBM0->Text = " Финальная обработка данных..."; // вывод текста в StatusBarMain (секция 0)
//
 F1->Label_Data->Font->Color   = clBlack;
 F1->Label_Buffer->Font->Color = clBlack;
//
 all_maxProcs   = 0; // реально используемое в расчетах число АИУ
 serial_Ticks   = 0; // сумма времен работы АИУ (фактически время ПОСЛЕДОВАТЕЛЬНОГО выполнения)
 parallel_Ticks = 0; // время выполнения параллельной программы
//
 ftime(&t1); // взяли момент времени окончания выполнения программы
//
// обрабатываем статистику загрузки АИУ по данным из Tpr -----------------------
 for(ULI i=0; i<mTpr->Count; i++)
 {
  APM // дать поработать  Windows ----------------------------------------------
//
  if( !(i % 100 ) ) // если i кратно 100
  {
   sprintf( w, " Предварительная обработка данных (%.0f%%)...", 1e2*i/mTpr->Count);
   SBM0->Text = w;
  }
//
  strcpy(tmp, mTpr->Strings[i].c_str()); // запомнили строку из Tpr в tmp
//
  serial_Ticks += atoi(GetSubString(tmp, 31,40)); // суммируем по всем исполненным инструкциям
//
  strcpy(tmp1, GetSubString(tmp, 1,10)); // номер задействованныого АИУ
  if( atoi(tmp1) > all_maxProcs ) // ищем максимальное значение номера АИУ
   all_maxProcs = atoi(tmp1);
 } // конец по строкам в Tpr
//
 all_maxProcs ++ ; // ибо счет с нуля !
//
////////////////////////////////////////////////////////////////////////////////
 strcpy(tmp, mTpr->Strings[0].c_str()); // момент начала выполнения первой инструкции
 parallel_Ticks = atoi(GetSubString(tmp, 11,20));
//..............................................................................
 strcpy(tmp, mTpr->Strings[mTpr->Count-1].c_str()); // момент конца выполнения последней инструкции
 parallel_Ticks = atoi(GetSubString(tmp, 21,30)) - parallel_Ticks; // получили разницу в абсолютном времени
//
// ----- проверка parallel_Ticks на "больше нуля" (ибо на неё делми) -----------
 if( parallel_Ticks <= 0 )
 {
  t_printf( "\n-E- Общее время выполнения программы НЕ ПОЛОЖИТЕЛЬНО - статистика не рассчитывалась... -E-" );
  Regim = 2; // не отрисовывать график интенсивности вычислений
  return;
 }
//
////////////////////////////////////////////////////////////////////////////////
 simult_maxProcs = Work_TimeSets_Protocol_IC(); // max ОДНОВРЕМЕННО работающих АИУ
////////////////////////////////////////////////////////////////////////////////
//
 SBM0->Text = " Обработка завершена..."; // вывод текста в StatusBarMain (секция 0)
 F1->StatusBarMain->Repaint(); // перерисовать принудительно
//
// вывод данных для визуализации ...............................................
//
 t_printf( "\nВремя выполнения программы:" );
//
 t_printf( "===========================" );
//
// char format[] = "\nВремя выполнения программы:\n===========================\nпараллельное = %ld тактов (%.3f сек), использовано %d (мах %d одновременно) АИУ из %d доступных";
//
 t_printf( "параллельное = %d тактов (%.3f сек), использовано %d (мах %d одновременно) штук/и АИУ из %d доступных",
                   parallel_Ticks,
                   (t1.time + 1.0e-3*t1.millitm) - (t0.time + 1.0e-3*t0.millitm),
                   all_maxProcs, // всего АИУ было использовано
                   simult_maxProcs, // max ОДНОВРЕМЕННО работающих АИУ
                   Max_Proc ); // всего в системе задано
//
 t_printf( "последовательное = %ld тактов", serial_Ticks );
//
 t_printf( "ускорение (убыстрение) вычислений = %.*e\n", ACC_REAL, 1.0*serial_Ticks / parallel_Ticks);
//
 REAL index = Calc_ConnectedIndex( 0 );  // подсчет ИНДЕКСОВ СВЯЗНОСТИ без сохранения в файл
//
 if (index != ERR_ALTERNAT) // реально вычислен, а не БЕСКОНЕЧНОСТЬ!!!
 {
  t_printf( "показатель альтернативности графа программы = %.3f \n",
                   index); // подсчет ИНДЕКСОВ СВЯЗНОСТИ без сохранения в
 }
//
 t_printf( "всего выполнилось %d инструкций (не учитывая SET)\n", mTpr->Count);
//
// теперь вычисляем вес каждой из выполненных инструкций .......................
 for(int j=0; j<Count_Sets; j++) // по списку инструкций
 {
   sprintf( w, " Окончательная обработка данных (%.0f%%)...", 1e2*j/ Count_Sets);
   SBM0->Text = w;
//
  strcpy(Set, Set_Params[j].Set); // запомнили для удобства работы
//
  n_Sets = 0; // счетчик числа выполнений инструкции Set
//
  for(ULI i=0; i<mTpr->Count; i++) // по списку Tpr
  {
   APM // дать поработать  Windows ---------------------------------------------
//
   strcpy(tmp,  mTpr->Strings[i].c_str()); // запомнили строку из Tpr в tmp
   strcpy(tmp1, GetSubString(tmp, 41,50));  // номер инструкции в виде строки tmp1
//
   if(!strcmp(Set, Mem_Instruction[atoi(tmp1)].Set)) // если совпадение ...
    n_Sets ++ ;
  } // конец цикла по строкам Tpr
//
  if(n_Sets) // только если выполнилась хотя бы раз...
   t_printf( "инструкция %s выполнилась %d раз ( %5.1f% )", Set, n_Sets, 100.0 * n_Sets / mTpr->Count);
//
 } // конец цикла по списку инструкций в Set_Params[]
//
// теперь вычисляем процент (по времени) использования каждого из АИУ
 for(int i=0; i<all_maxProcs; i++) // по числу АИУ...
 {
  sum_tProc = 0.0; // обнуляем сумму времен работы каждого АИУ
//
  for(ULI j=0; j<mTpr->Count; j++) // по списку выполненных инструкций...
  {
   strcpy(tmp,  mTpr->Strings[j].c_str()); // запомнили строку из Tpr в tmp
   strcpy(tmp1, GetSubString(tmp, 1,10)); // номер АИУ в виде строки tmp1
//
   if(i == atoi(tmp1)) // нашли в Tpr номер АИУ i
   {
    strcpy(tmp1, GetSubString(tmp, 31,40)); // время выполнения любой инструкции на i-том АИУ
    sum_tProc += atoi(tmp1);
   }
  } // конец цикла по списку инструкций
//
// Внимание ! Сумма всех (sum_tProc/parallel_time) может быть > 100% (а по отношению к serial_time = 100%)
// snprintf(tmp,sizeof(tmp), "арифм.исполн.у-во (АИУ) номер %d работало %ld тактов ( %5.1f% )",
//               i, sum_tProc, 100.0 * sum_tProc / parallel_Ticks);
 t_printf( "арифм.исполн.у-во (АИУ) номер %d работало %ld тактов ( %5.1f% )",
                  i, sum_tProc, 100.0 * sum_tProc / parallel_Ticks);
//
 } // конец цикла про АИУ
//
 F1->OnOf_Execute( 0 ); // "выключили" визуальную индикацию режима СЧЁТ
//
 Save_All_Protocols_To_Out_Dir(); // сохранение протоколов в Out!Data
//
} // ----- конец Calc_Stat_Proc ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall // визуализация флагов инструкции Mem_Sets[] номер i_Set
Vizu_Flags(int i_Set)
{
 char Set[_SET_LEN],
      Delimeter[] = "|", // символ разделителя битовых флагов
      Indiff[]    = "x", // символ 'безразлично'
      tmp[_512];
//
 strcpy(Set, Mem_Instruction[i_Set].Set); // запомнили мнемонику инструкции (так удобнее)
//
////////////////////////////////////////////////////////////////////////////////
 if( is_SET( Set ) ) // это инструкция SET......................................
  snprintf(tmp,sizeof(tmp), " %1s%1s%1s%1s%1s%1s%1s%1s%1s%1s%1s%1d%1s",
               Delimeter, Indiff,
               Delimeter, Indiff,
               Delimeter, Indiff,
               Delimeter, Indiff,
               Delimeter, Indiff,
               Delimeter, Mem_Instruction[i_Set].fExecOut,
               Delimeter);
//
 else
////////////////////////////////////////////////////////////////////////////////
 switch( Get_CountOperandsByInstruction(Set) ) // ... число входных операндов инструкции Set
 {
  case 1: snprintf(tmp,sizeof(tmp), " %1s%1d%1s%1s%1s%1d%1s%1d%1s%1d%1s%1d%1s", // в этой инструкции 1 операнд
                       Delimeter, Mem_Instruction[i_Set].fOp1,
                       Delimeter, Indiff,
                       Delimeter, Mem_Instruction[i_Set].fPredicatTRUE,
                       Delimeter, Mem_Instruction[i_Set].fAddBuffer,
                       Delimeter, Mem_Instruction[i_Set].fExec,
                       Delimeter, Mem_Instruction[i_Set].fExecOut,
                       Delimeter);
          break;
//
  case 2: snprintf(tmp,sizeof(tmp), " %1s%1d%1s%1d%1s%1d%1s%1d%1s%1d%1s%1d%1s", // в этой инструкции 2 операнда
                       Delimeter, Mem_Instruction[i_Set].fOp1,
                       Delimeter, Mem_Instruction[i_Set].fOp2,
                       Delimeter, Mem_Instruction[i_Set].fPredicatTRUE,
                       Delimeter, Mem_Instruction[i_Set].fAddBuffer,
                       Delimeter, Mem_Instruction[i_Set].fExec,
                       Delimeter, Mem_Instruction[i_Set].fExecOut,
                       Delimeter);
          break;
//
 default: strcpy( tmp, notDefined );
          break;
//
 } // конец switch
//
 return (tmp);
//
} // ----- конец Vizu_Flags ----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // информация об арифметической ошибке
Display_Error(char *str)
{
// MessageDlg(str, mtError, TMsgDlgButtons() << mbOK, 0);
 F1->Master_Timer->Enabled = FALSE; // остановили главный таймер
//
 F1->OnOf_Execute( 0 ); // "выключили" визуальную индикацию режима СЧЁТ
//
 MessageBox( 0, str, "Проблемы с арифметикой", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL );
//
} // ---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall
Vizu_Flow_Exec() // визуализировать процент выполнения программы
{
 char tmp[_512];
//
 snprintf(tmp,sizeof(tmp), " АИУ: %d/%d | буфер %.1f%% | выполнено %.1f%% (%d/%d) инструкций",
                Max_Proc - Free_Proc, Max_Proc,
                1.0e2 * Really_Buffer / Max_Buffer,
                1.0e2 * Already_Exec  / Really_Set,
                Already_Exec, Really_Set);
 SBM0->Text = tmp; // вывод текста в StatusBarMain (секция 0)
// SBM0->Canvas->Repaint(); // перерисовать принудительно
 F1->StatusBarMain->Repaint(); // перерисовать принудительно
//
} // конец Vizu_Flow_Exec ------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // начали вычисления (нажатие кнопки СЧЕТ)
TF1::Run_Calculations(TObject *Sender)
{
// flagGraph = TRUE; // управление отрисовкой графика функции интенсивности вычислений
//
// --- полный путь к каталогу сброса рассчитанных данных (включая слэш в конце)
 snprintf( PathToSubDirOutData,sizeof(PathToSubDirOutData), "%s%s\\", ExtractFilePath ( Application->ExeName ), NameSubDirOutData);
///
 if( !DirectoryExists( PathToSubDirOutData ) ) // если не существует этого каталога...
  if( !CreateDir( PathToSubDirOutData ) ) // если не удалось создать...
   strNcpy( PathToSubDirOutData, '\0' ); // обнуляем путь к подкаталогу PathToSubDirOutData
//
// генерим уникальные имена файлов ---------------------------------------------
 strNcpy( uniqueStr, PutDateTimeToString(1) ); // уникальная строка ( дата + время до мсек )
//
 randomize(); // инициализация функции rand() при выполнении инструкции RND
//
 Master_Timer->Enabled = TRUE; // включили главный таймер
 localTick, // начало выполнения программы (глобал)
 localTickOfEndLastExecuteSet = 0; // момент последнего тика выполнения последней инструкции (глобал)
//
// для единокраной выдачи сообщений о переполнении Mem_Data[] и Mem_Buffer и проблемах с парсером (глобальные)
 flagAlarmData = flagAlarmBuffer = flagAlarmParser = TRUE;
//
 Label_Data->Font->Color   = clBlack;
 Label_Buffer->Font->Color = clBlack;
//
 if( F2 )
  F2->Close(); // окно графика интенсивности вычислений закрыли
//
 if( F3 )
  F3->Close(); // окно графика интенсивности вычислений закрыли
//
// Label_AIU->Caption = E_AIU->Text;
//
 ULI Max_Proc_New = StrToInt( E_AIU->Text ); // взяли число АИУ (параллельных вычислителей)
//
 Max_Proc = (Max_Proc >  MAX_PROC) ? MAX_PROC : Max_Proc;
 Max_Proc = (Max_Proc <=        0) ? 1        : Max_Proc;
 E_AIU->Text = Max_Proc_New;
 E_AIU->Repaint(); // принудительно перерисуем...
//
 if( Max_Proc_New != Max_Proc ) // заказали иное число АИУ, чем было
 {
  Max_Proc = Max_Proc_New; // заменили...
//
  Write_Config(); // запомнили это число в файле настроек
//
  Mem_Proc = ( mp* ) realloc( Mem_Proc, Max_Proc * sizeof( mp ) ); // перераспределили ТОЛЬКО память под АИУ
 } // конец  if( Max_Proc_New != Max_Proc )
//
  mR->Clear(); // очистили Memo_Run .............................................
//
  Install_All_Flags(); // очистили все флаги в Mem_Sets[]
  Vizu_Sets(); // визуализировали все инструкции в ОКНЕ_ИНСТРУКЦИЙ
//
  Really_Data = 0; // очистили пул данных
  Vizu_Data();  // визуализировали данные в ОКНЕ_ДАННЫХ
//
  Really_Buffer = 0; // очистили буфер команд
  Vizu_Buffer();  // визуализировали инструкции в БУФЕРЕ_ИНСТРУКЦИЙ
//
  Out_Data_SBM1(); // вывод данных в среднюю часть StatusBar -------------------
//
//  Rewrite_Files( Sender ); // перечитать файл программы !!!!!!!!!!!!!!!!!!!!!!
//
 Clear_AllCells(); // очистили все ячейки
//
 Start_DataFlow_Process( 0 ); // начинаем счет по кнопке ВЫПОЛНИТЬ
//
} // конец F1:Run_Calculations(TObject *Sender) --------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // начали счет (в заданном Mode режиме)
Start_DataFlow_Process(int Mode)
{
// Mode = 0 соответствует нажатию кнопки ВЫПОЛНИТЬ
// Mode = 1 -,-,-,-,- "Перемешать инструкции и выполнить"
//
 F1->OnOf_Execute( 1 ); // "включили" визуальную индикацию режима СЧЁТ
//
 Regim = 1;  // начать выполнение программы
//
 for(UI i=0; i<Max_Proc; i++) // все АИУ...
  Mem_Proc[i].Busy = FALSE; // "СВОБОДНЫ"
//
 Free_Proc = Max_Proc; // пока все АИУ свободны
//
 mR->Clear(); // очистили Memo_Run
//
 Read_Instructions(); // перечитать программу
 Vizu_Sets(); // визуализировали инструкции в ОКНЕ_ИНСТРУКЦИЙ
//
 Really_Data = 0; // очистили пул данных
 Vizu_Data();  // визуализировали данные в ОКНЕ_ДАННЫХ
//
 Really_Buffer = 0; // очистили буфер
 Vizu_Buffer();  // визуализировали данные в буфере
//
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 if( Mode == 1 ) // перемешать инструкции в ПАМЯТИ_ИНСТРУКЦИЙ
  F1->Mixed_Sets( NULL );
////////////////////////////////////////////////////////////////////////////////
 mTpr->Clear(); // очистить список строк данных для анализа работы всех АИУ
////////////////////////////////////////////////////////////////////////////////
//
 Already_Exec = 0; // уже инструкций выполнено
//
 Install_All_Flags(); // очистить все флаги
//
////////////////////////////////////////////////////////////////////////////////
 ftime(&t0);  // взяли момент времени начала выполнения программы
 localTick = 0; // такты начали считать с нуля !
////////////////////////////////////////////////////////////////////////////////
//
// это обязательно ПЕРЕД  Primary_Init_Data() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
 if( !Test_All_Operands() ) // выполнение продолжить нельзя..!
 {
  F1->OnOf_Execute( 0 ); // "выключили" визуальную индикацию режима СЧЁТ
  return; // заканчиваем выполнение программы
 }
//
 Primary_Init_Data(); // инициализация данных посредством SET etc etc
////////////////////////////////////////////////////////////////////////////////
 sleep_for_vizu_buffer // ждем-с для визуализации буфера
////////////////////////////////////////////////////////////////////////////////
// AttemptExecMaxInstructions_fromBuffer(); // пытаемся выполнить максимум ГКВ-инструкций из буфера
// для фактического выполнения инструкций из AttemptExecMaxInstructions_fromBuffer()
// вызывается ExecuteInstructions_ExceptSET( i_Set )
// !!!!! вызов AttemptExecMaxInstructions_fromBuffer() перенесён в конец FinalizeOnlySET_ ...
////////////////////////////////////////////////////////////////////////////////
 sleep_for_vizu_buffer // ждем-с для визуализации буфера
////////////////////////////////////////////////////////////////////////////////
} // ----- конец Start_DataFlow_Process (int Mode) -----------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // цикл выборки и исполнения инструкций
Primary_Init_Data()
{///////////////////////////////////////////////////////////////////////////////
// цель этапа - присвоить всем ячейкам в Mem_Data[] исходные для расчета значения
// фактически это значит, что надо выполнить только ВСЕ инструкции SET
////////////////////////////////////////////////////////////////////////////////
//
 for( ULI i=0; i<Really_Set; i++ ) // цикл по всем инструкциям в Mem_Instruction .......
  {
   if( is_SET( Mem_Instruction[i].Set ) ) // это "безАдресный" SET......................
    Finalize_Only_SET( i ); // обрабатывается не АИУ, а ВХОДНЫМ КОММУНИКАТОРОМ
//
// вызов Finalize_Only_SET выполняет инструкцию i_Set (добавляет соотв. строку в
// Mem_Data, устанавливает флаг "выполнено" у данной инструкции, сканирует Mem_Instruction
// по всем инструкциям на наличие в списке операндов тольо что внесенного в Mem_Data)
//
  } // конец цикла по пулу инструкций
//
// ЗАВЕРШИЛИ ПЕРВОНАЧАЛЬНУЮ ИНИЦИАЛИЗАЦИЮ ДАННАХ (закончили выполнение всех SET)
//
} // конец Primary_Init_Data ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall ExecuteInstructions_ExceptSET(int i_Set) // выполнение инструкции номер i_Set
{ // кроме инструкции ЫУЕ
 REAL Op1, Op2, Result, Predicate;
 char aOp1[_ID_LEN], aOp2[_ID_LEN], aResult[_ID_LEN], aPredicate[_ID_LEN];
 ULI  i_Proc; // номер свободного АИУ
 __int64 Divident, Devider; // Quotient, Remainder; // числитель/знаменатель//частное/остаток (целые 64 бит)
 char Set[_SET_LEN],
      tmp[_1024];
// bool ExecSet = TRUE; // при FALSE инсрукция не выполняется по условию предикации
//
 if( !Regim ) // не выполнять - закончить счет ---------------------------------
  return;
//
 if( is_SET( Mem_Instruction[i_Set].Set ) ) // инструкцию SET не обрабатываем здесь !!!
  return;
//
// ----- здесь проверок не надо, ибо НЕГОТОВЫЕ инстnрукции не попадают даже в БУФЕР КОМАНД !!!
//
////////////////////////////////////////////////////////////////////////////////
// ищем свободное АИУ для исполнения инструкции номер i_Set ....................
 for(i_Proc=0; i_Proc<Max_Proc; i_Proc++) // по всем АИУ .......................
  if(!Mem_Proc[i_Proc].Busy) // процессор (АИУ) i_Proc свободен ................
   goto find_free_proc;
//
 t_printf( "-W- %s(): нет свободных АИУ! Ни одна инструкция не может быть выполнена... -W-", __FUNC__ );
//
 return;
//
// УРА !!! Есть свободные АИУ !!! ==============================================
//
 find_free_proc: // на свободном АИУ i_Proc выполняем инструкцию i_Set =========
//
////////////////////////////////////////////////////////////////////////////////
 Mem_Proc[i_Proc].Busy = TRUE; // 'захватили' АИУ ..............................
//
////////////////////////////////////////////////////////////////////////////////
 Free_Proc -- ; // число свободных АИУ уменьшили на единицу
////////////////////////////////////////////////////////////////////////////////

 Mem_Instruction[i_Set].fExec  = TRUE; // установили флаг 'выполнение' для данной инструкции
 mI->Cells[6][i_Set+1] = Vizu_Flags(i_Set); // визуализировали ФЛАГИ данной инструкции

// обрабатываем параметры команды для выполнения на этоm АИУ ///////////////////
 strcpy( Set, Mem_Instruction[i_Set].Set ); // имя (мнемоника) команды
 strcpy( aResult, Mem_Instruction[i_Set].aResult ); // адрес результата (ДЛЯ ВСЕХ ОПЕРАЦИЙ)
//
////////////////////////////////////////////////////////////////////////////////
 switch( Get_CountOperandsByInstruction(Set) ) // ... число входных операндов инструкции Set
 {
  case 1: strcpy( aOp1, Mem_Instruction[i_Set].aOp1 ); // адрес (строка!) ПЕРВОГО ОПЕРАНДА
          Op1 = Get_Data(aOp1); // значение ПЕРВОГО ОПЕРАНДА
//
          break;

  case 2: strcpy(aOp1, Mem_Instruction[i_Set].aOp1); // адрес (строка!) ПЕРВОГО ОПЕРАНДА
          strcpy(aOp2, Mem_Instruction[i_Set].aOp2); // ... ВТОРОГО ОПЕРАНДА
          Op1 = Get_Data(aOp1); // значение ПЕРВОГО ОПЕРАНДА
          Op2 = Get_Data(aOp2); // значение ВТОРОГО ОПЕРАНДА
//
          break;
//
 default: break;

 } // конец switch

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// запомним момент времени (в тиках) начала выполнения данной инструкции
   Mem_Proc[i_Proc].tick_Start = localTick; // номер тика начала выполнения.........

////////////////////////////////////////////////////////////////////////////////
 if(!strcmp(Set, "ADD")) // это инструкция ADD
 {
  Result = Op1 + Op2; // результат операции
 }
// конец выполнения инструкции ADD .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "SUB")) // это инструкция SUB
 {
  Result = Op1 - Op2; // результат операции
 }
// конец выполнения инструкции SUB .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "MUL")) // это инструкция MUL
 {
  Result = Op1 * Op2; // результат операции
 }
// конец выполнения инструкции MUL .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "DIV")) // это инструкция DIV
 {
  if( fabs (Op2) <= MIN_FLOAT) // нельзя делить на ОЧЕНЬ МАЛЕНЬКОЕ ЧИСЛО...
   {
    snprintf(tmp,sizeof(tmp), "-E- %s(): инструкция %s (#%d) не может быть выполнена (делитель = {%.*e}). Выборка инструкций остановлена... -E-",
                  __FUNC__, Set, i_Set, ACC_REAL, Op2);
    AddLineToProtocol(tmp);
    Display_Error(tmp);
    Code_Error = -1; // попытка делить на 0.0
    return;
   }
  else
   Result = Op1 / Op2; // результат операции DIV
 }
// конец выполнения инструкции DIV .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "DQU")) // это инструкция DQU (получение ЦЕЛОГО ЧАСТНОГО от деления)
 {
  Divident = Op1; // делимое как __int64
  Devider  = Op2; // делитель как __int64

  if( !Devider ) // если 0...
  {
   snprintf(tmp,sizeof(tmp), "-E- %s(): инструкция %s не может быть выполнена (делитель НУЛЕВОЙ). Выборка инструкций остановлена... -E-",
                 __FUNC__, Set);
   AddLineToProtocol(tmp);
   Display_Error(tmp);
   Code_Error = -1; // попытка делить на 0
   return;
   }
  else
   Result = REAL ( Divident / Devider ); // результат операции DQU
 }
// конец выполнения инструкции DQU .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "RND")) // это инструкция RND (выдаёт случайное число из заданного операндами диапазона
 {
  Result = Op1 + ( Op2 - Op1 ) * REAL(rand()) / REAL(RAND_MAX);
 }
// конец выполнения инструкции RND .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "DRE")) // это инструкция DQU (получение ЦЕЛОГО ОСТАТКА от деления)
 {
  Divident = Op1; // делимое как __int64
  Devider  = Op2; // делитель как __int64

  if( !Devider ) // если 0...
  {
   snprintf(tmp,sizeof(tmp), "-E- %s(): инструкция %s не может быть выполнена (делитель НУЛЕВОЙ). Выборка инструкций остановлена... -E-",
                 __FUNC__, Set);
   AddLineToProtocol(tmp);
   Display_Error(tmp);
   Code_Error = -1; // попытка делить на 0
   return;
  }
  else
   Result = REAL ( Divident % Devider ); // результат операции DRE
 }
// конец выполнения инструкции RND .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "SQR")) // это инструкция SQR
 {
  if(Op1 < 0.0) // нельзя вычислять квадратный корень из отрицательного числа...
  {
   snprintf(tmp,sizeof(tmp), "-E- %s(): инструкция %s (#%d) не может быть выполнена над отрицательным числом {%.*e}. Выборка инструкций остановлена... -E-",
                 __FUNC__, Set, i_Set, ACC_REAL, Op1);
   AddLineToProtocol(tmp);
   Display_Error(tmp);
   Code_Error = -2; // индикация попытки деления на 0 ---
   return;
  }
  else
   Result = sqrt ( Op1 );
 }
// конец выполнения инструкции SQR .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "SIN")) // это инструкция SIN
 {
  Result = sin ( Op1 );
 }
// конец выполнения инструкции SIN .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "COS")) // это инструкция COS
 {
  Result = cos ( Op1 );
 }
// конец выполнения инструкции COS .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "ASN")) // это инструкция ASN

  if( fabs ( Op1 ) <= 1.0 )
   Result = asin ( Op1 );
  else
  {
   snprintf(tmp,sizeof(tmp), "-E- %s(): инструкция %s (#%d) не может быть выполнена при аргументе {%.*e}. Выборка инструкций остановлена... -E-",
                 __FUNC__, Set, i_Set, ACC_REAL, Op1);
   AddLineToProtocol(tmp);
   Display_Error(tmp);
   Code_Error = -6; // индикация ошибки вычисления arcSIN ---
   return;
  }
// конец выполнения инструкции ASN .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "ACN")) // это инструкция ACN
//
  if( fabs ( Op1 ) <= 1.0 )
   Result = acos ( Op1 );
//
  else
  {
   snprintf(tmp,sizeof(tmp), "-E- %s(): инструкция %s (#%d) не может быть выполнена при аргументе {%.*e}. Выборка инструкций остановлена... -E-",
                 __FUNC__, Set, i_Set, ACC_REAL, Op1);
   AddLineToProtocol(tmp);
   Display_Error(tmp);
   Code_Error = -7; // индикация ошибки вычисления arcCOS ---
   return;
  }
// конец выполнения инструкции ACN .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "TAN")) // это инструкция TAN... какъ писАать частицу НЕ
// в нашей солнечной стране? Фазиль Искандер, однако !..
  {
   if( fabs ( Op1 ) > M_PI_2 - MIN_FLOAT ) // MIN_FLOAT ) // избегаем машинной бесконечности
   {
    snprintf(tmp,sizeof(tmp), "-W- %s(): инструкция %s (#%d) не может быть корректно выполнена при аргументе {%.*e}. Принято MAX значение... -W-",
                  __FUNC__, Set,Set, i_Set, ACC_REAL, Op1);
    AddLineToProtocol(tmp);
    Display_Error(tmp);
//
    Result = ( Op1 > 0.0 ) ? MAX_FLOAT: -MAX_FLOAT; // (+) или (-) машинная бесконечность...
   }
   else
    Result = tan ( Op1 ); // использована стандартная функция
  }
// конец выполнения инструкции TAN .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "ATN")) // это инструкция ATN... какъ писаить частицу НЕ
// в нашей солнечной стране? Фазиль Искандер, однако !..
  {
   Result = atan ( Op1 ); // используеи стандартную ф-ю
  }
// конец выполнения инструкции ATN .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "LOG")) // это инструкция LOG
 {
  if( Op1 < EPS ) // ошибка вычисления логарифма...
  {
   snprintf(tmp,sizeof(tmp), "-E- %s(): инструкция %s (#%d) не может быть выполнена при аргументеа {%.*e}. Выборка инструкций остановлена... -E-",
                 __FUNC__, Set, i_Set, ACC_REAL, Op1);
   AddLineToProtocol(tmp);
   Display_Error(tmp);
   Code_Error = -5; // индикация ошибки вычисления логарифма ---
   return;
  }
  else
   Result = log ( Op1 );
 }
// конец выполнения инструкции LOG .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "POW")) // это инструкция POW
 {
  int int_L,int_R,int_Op2; // целые для (возможного) округления Op2
  bool f_Op2 = FALSE; // при TRUE величина Op2 очень близка к целому и принимается i_Op2
//
// насколько Op2 близко к целому ? .............................................
  int_L = Floor( Op2 ); // округление до целого 'вниз'
  int_R = Ceil ( Op2 ); // округление до целого 'вверх'
//
  if( fabs ( (REAL)int_L - Op2 ) < EPS )
  {
   int_Op2 = int_L; // это целое Op2
   f_Op2 = TRUE;
  }
  else
  if( fabs ( (REAL)int_R - Op2 ) < EPS )
  {
   int_Op2 = int_R; // это целое Op2
   f_Op2 - TRUE;
  }
// итак, при f_Op2=TRUE можно считать Op2 целым и вместо него использовать iOp2
// при f_Op2=FALSE величину Op2 следует считать вещественной ...................
//
// обработка случая Op1 < 0.0 ..................................................
  if( Op1 < 0.0 )
   if( f_Op2 ) // величина Op2 - целое
   {
    if( int_Op2 > 0 ) // Op2 - целое и положительное
    {
     Result = 1.0;
     for(int i=1; i<=int_Op2; i++)
     Result *= Op1;
    }
    else
    if( int_Op2 < 0 ) // Op2 - целое и отрицательное
    {
     Result = 1.0;
     for(int i=1; i<=int_Op2; i++)
     Result /= Op1;
    }
    else
     Result = 1.0 ; // int_op2 = Op2 = 0
   } // конец if( f_Op2 )
   else // величина Op2 - нецелое
   {
    snprintf(tmp,sizeof(tmp), "-E- %s(): инструкция %s (#%d) не может быть выполнена. Отрицательное число {%.*e} не может быть возведено в нецелую степень {%.*e}. Выборка инструкций остановлена... -E-",
                  __FUNC__, Set, i_Set, ACC_REAL, Op1, ACC_REAL, Op2);
    AddLineToProtocol(tmp);
    Display_Error(tmp);
    Code_Error = -4; // индикация ошибки вычисления (x**y) ---
    return;
   }
// конец обработки случая Op1 < 0.0 ............................................

//.............................................................................
// обработка случая Op1 = 0.0 'и' Op2 = 0.0 ....................................
   if( ( Op1 == 0.0 ) && ( Op2 == 0.0 ) ) // ноль в степени ноль - не определено
   {
    snprintf(tmp,sizeof(tmp), "-E- %s(): инструкция %s (#%d) не может быть выполнена. Ноль {%.*e} невозможно возвести в нулевую степень {%.*e}. Выборка инструкций остановлена... -E-",
                  __FUNC__, Set, i_Set, ACC_REAL, Op1, ACC_REAL, Op2);
    AddLineToProtocol(tmp);
    Display_Error(tmp);
    Code_Error = -4; // индикация ошибки вычисления (x**y) ---
    return;
   }
//
//..............................................................................
// обработка случая Op1 == 0.0 'и' Op2 # 0.0 ...................................
   if( ( Op1 == 0.0 ) && ( Op2 != 0.0 ) ) // ноль в любой степени равно нулю
    Result = 0.0 ;
//
//..............................................................................
// обработка случая Op1 # 0.0 'и' Op2 == 0.0 ...................................
   if( ( Op1 != 0.0 ) && ( Op2 == 0.0 ) ) // любое число в нулевой степени = 1
    Result = 1.0 ;
//
//..............................................................................
// обработка случая Op1 > 0.0 ..................................................
  if ( fabs ( Op1 ) > EPS ) // чтобы под логарифмом не было <= 0.0 ...
   Result = pow ( Op1, Op2 );   // = exp ( Op2 * log ( Op1 ) );
//..............................................................................
  else
  {
   snprintf(tmp,sizeof(tmp), "-E- %s(): инструкция %s (#%d) не может быть выполнена при аргументах {%.*e} / {%.*e}. Выборка инструкций остановлена... -E-",
                 __FUNC__, Set, i_Set, ACC_REAL, Op1, ACC_REAL, Op2);
   AddLineToProtocol(tmp);
   Display_Error(tmp);
   Code_Error = -4; // индикация ошибки вычисления (x**y) ---
   return;
  }
//
 }
// конец выполнения инструкции POW .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "EXP")) // это инструкция EXP
 {
  Result = exp ( Op1 ); // используеи стандартную ф-ю
 }
// конец выполнения инструкции EXP .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "SNH")) // это инструкция SNH
 {
  Result = sinh ( Op1 ); // используеи стандартную ф-ю
 }
// конец выполнения инструкции SNH .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "CNH")) // это инструкция CNH
 {
  Result = cosh ( Op1 );
 }
// конец выполнения инструкции CNH .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "TNH")) // это инструкция TNH
 {
  Result = tanh ( Op1 ); // используеи стандартную ф-ю
 }
// конец выполнения инструкции TNH .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "CPY")) // это инструкция CPY ( Result <= Operand_1 )
 {
  Result =  Op1;
 }
// конец выполнения инструкции CPY .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "ABS")) // это инструкция ABS ( Result = abs ( Operand_1 ) )
 {
  Result = fabs ( Op1 );  // используеи стандартную ф-ю
 }
// конец выполнения инструкции ABS .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "SGN")) // это инструкция SGN ( Result <= знак (signum) Operand_1 )
 {
  Result = ( Op1 >= 0.0) ? (1.0) : (-1.0) ;
 }
// конец выполнения инструкции ABS .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "NEG")) // это инструкция NEG ( Result = - Operand_1 )
 {
  Result = - Op1;
 }
// конец выполнения инструкции NEG .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "FLR")) // это инструкция FLR ( Result = floor( Operand_1 ) )
 {
  Result = floor( Op1 );
 }
// конец выполнения инструкции FLR .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "CEL")) // это инструкция CEL ( Result = ceil( Operand_1 ) )
 {
  Result = ceil( Op1 );
 }
// конец выполнения инструкции CEL .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PGE")) // это инструкция PGE
 {
  Result = ( Op1 >= Op2 ) ? 1.0 : 0.0 ;
 }
// конец выполнения инструкции PGE .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PLE")) // это инструкция PLE
 {
  Result = ( Op1 <= Op2 ) ? 1.0 : 0.0 ;
 }
// конец выполнения инструкции PLE .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PEQ")) // это инструкция PEQ
 {
  Result = ( Op1 == Op2 ) ? 1.0 : 0.0 ;
 }
// конец выполнения инструкции PEQ .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PNE")) // это инструкция PNE
 {
  Result = ( Op1 != Op2 ) ? 1.0 : 0.0 ;
 }
// конец выполнения инструкции PNE .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PGT")) // это инструкция PGT
 {
  Result = ( Op1 > Op2 ) ? 1.0 : 0.0 ;
 }
// конец выполнения инструкции PGT .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PLT")) // это инструкция PLT
 {
  Result = ( Op1 < Op2 ) ? 1.0 : 0.0 ;
 }
// конец выполнения инструкции PLT .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PNT")) // это инструкция PNT (отрицание - NOT)
 {
  Result = ( Op1 == 0.0 ) ? 1.0 : 0.0 ; // отрицание - NOT
 }
// конец выполнения инструкции PNT .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PAN")) // это инструкция PAN
 {
  Result = ( Op1 && Op2 ) ? 1.0 : 0.0 ; // логическое "И" (AND)
 }
// конец выполнения инструкции PAN .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "POR")) // это инструкция POR
 {
  Result = ( Op1 || Op2 ) ? 1.0 : 0.0 ; // логическое "ИЛИ" (OR)
 }
// конец выполнения инструкции POR .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PIM")) // это инструкция PIM (импликация, слЕдование)
 {
  Result = ( ( Op1 != 0.0 ) && ( Op2 == 0.0 ) ) ? 0.0 : 1.0 ; // импликация (слЕдование)
 }
// конец выполнения инструкции PIM .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PRM")) // это инструкция PRM (обратная импликация)
 {
  Result = ( ( Op1 == 0.0 ) && ( Op2 != 0.0 ) ) ? 0.0 : 1.0 ; // обратная импликация
 }
// конец выполнения инструкции PRN .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PEV")) // это инструкция PEV (эквиваленция)
 {
  Result = ( ( ( Op1 != 0.0 ) && ( Op2 != 0.0 ) ) ||
             ( ( Op1 == 0.0 ) && ( Op2 == 0.0 ) )
           ) ? 1.0 : 0.0 ; // эквивалентность
 }
// конец выполнения инструкции PEV .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PAP")) // это инструкция PAP (стрелка Пирса, ИЛИ-НЕ)
 {
  Result = ( ( Op1 == 0.0 ) && ( Op2 == 0.0 ) ) ? 1.0 : 0.0 ; // стрелка Пирса, ИЛИ-НЕ
 }
// конец выполнения инструкции PAP .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PHS")) // это инструкция PHS (штрих Шеффера, И-НЕ)
 {
  Result = ( ( Op1 != 0.0 ) && ( Op2 != 0.0 ) ) ? 0.0 : 1.0 ; // штрих Шеффера, И-НЕ
 }
// конец выполнения инструкции PHS .............................................

////////////////////////////////////////////////////////////////////////////////
 else
 if(!strcmp(Set, "PXR")) // это инструкция PXR (строгая дизъюнкция, исключающее ИЛИ)
 {
  Result = ( ( ( Op1 == 0.0 ) && ( Op2 == 0.0 ) ) ||
             ( ( Op1 == 1.0 ) && ( Op2 == 1.0 ) )
           ) ? 0.0 : 1.0 ; // строгая дизъюнкция, исключающее ИЛИ
 }
// конец выполнения инструкции PXR .............................................

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
////////////////////////////////////////////////////////////////////////////////
// конец по всем инструкциям в наборе команд....................................
////////////////////////////////////////////////////////////////////////////////
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//
// запомнили в данных АИУ информацию об адресах операндов и результате операции
   Mem_Proc[i_Proc].i_Set = i_Set; // номер инструкции из Mem_Sets[]
   strcpy( Mem_Proc[i_Proc].aOp1,    Mem_Instruction[i_Set].aOp1 );
   strcpy( Mem_Proc[i_Proc].aOp2,    Mem_Instruction[i_Set].aOp2 );
   strcpy( Mem_Proc[i_Proc].aResult, Mem_Instruction[i_Set].aResult );
//
// запомнили в данных АИУ информацию об операндах и результате операции --------
   Mem_Proc[i_Proc].Op1    = Op1; // запомнили ПЕРВЫЙ операнд
   Mem_Proc[i_Proc].Op2    = Op2; // запомнили ВТОРОЙ операнд
   Mem_Proc[i_Proc].Result = Result; // запомнили результат операции
//
   t_printf( "-I- %s(): для выполнения инструкции #%d [%s] выбрано АИУ номер %d -I-",
                     __FUNC__, i_Set, Line_Set(i_Set, -1), i_Proc);
//
} // конец ExecuteInstructions_ExceptSET ---------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall
Test_ReadyForExec_and_AddToBuffer(int i_Set) // тестирует инструкцию i_Set на
{ // соответствие условию ГКВ (Готовность К Выполнению) и при успехе добавляет
  // ее в буфер Mem_Buffer[] и визуалиазирует содержимое буфера SG_Buffer

 if( is_SET( Mem_Instruction[i_Set].Set ) ) // если это SET, то ничего делать не надо (здесь SET не обрабатывается)...
  return;

 switch( Get_CountOperandsByInstruction(Mem_Instruction[i_Set].Set) ) // по числу операндов
  {
   case 1: if( Mem_Instruction[i_Set].fOp1 &&   // первый операнд ГОТОВ "и"
//
               Mem_Instruction[i_Set].fPredicat && // готовность предиката
//
              !Mem_Instruction[i_Set].fExecOut) // ...инструкция еще не исполнялась
               Add_toBuffer(i_Set); // добавим эту инструкцию в буфер Mem_Buffer[]
//
             break;
//
   case 2: if( Mem_Instruction[i_Set].fOp1 &&   // первый операнд ГОТОВ "и"
               Mem_Instruction[i_Set].fOp2 &&  // ...второй операнд ГОТОВ "и"
//
               Mem_Instruction[i_Set].fPredicat && // готовность предиката
//
              !Mem_Instruction[i_Set].fExecOut) // ...инструкция еще не исполнялась
               Add_toBuffer(i_Set);  // добавим эту инструкцию в буфер Mem_Buffer[]
//
             break;
//
   default: break;;
  }
//
} // конец Test_ReadyForExec_and_AddToBuffer -----------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void   __fastcall
Add_toBuffer(int i_Set) // добавляет в буфер команд Mem_Buffer[] строку номер i_Set с ГКВ-инструкцией
// добавляется не сама строка, а ее номер из Mem_Instruction[] в поле Mem_Buffer[].i_Set
// в Mem_Buffer[]->(float)Param заносится ПАРАМЕТР "ПОЛЕЗНОСТИ" (для последующего ранжирования)
// если команда уже добавленв буффер (установлен флаг Mem_Instruction[].fAddBuffer) - не добавляется
// после добавления флаг Mem_Instruction[].fAddBuffer устанавливается
{
 char tmp[_512];
 static bool flagColor = TRUE; // флаг предупреждения о переполнении Mem_Buffer[]
//
 if(Really_Buffer >= Max_Buffer) // буфер полон
 {
  if( flagAlarmBuffer ) // один раз выведем сообщение
  {
   t_printf( "->\n-E- %s(): инструкция #%d [%s] не добавлена в буфер, ибо он полон (%s) -E-\n->",
                     __FUNC__, i_Set, Line_Set(i_Set, -1), Get_Time_asLine() );
//
   flagAlarmBuffer = FALSE;
  }
//
  if( flagColor ) // мигание цветом надписи Label_Buffer
   F1->Label_Buffer->Font->Color = clRed;
  else
   F1->Label_Buffer->Font->Color = clBlack;
//
  F1->Label_Buffer->Refresh(); // перерисуем...
//
  flagColor = !flagColor;
//
  return;
 } // конец if(Really_Buffer >= 0.99*Max_Buffer)
////////////////////////////////////////////////////////////////////////////////
//
 if(Mem_Instruction[i_Set].fAddBuffer) // инструкция уже была добавлена в буфер ========
  return;
//
 Mem_Buffer[Really_Buffer].i_Set = i_Set; // ссылка на номер инструкции
 Mem_Buffer[Really_Buffer].Param = Calc_Param(i_Set); // значение параметра ПОЛЕЗНОСТИ инструкции i_Set
 Mem_Buffer[Really_Buffer].Priority = Calc_Priority(Mem_Buffer[Really_Buffer].Param); // значение ПРИОРИТЕТА
//
////////////////////////////////////////////////////////////////////////////////
 t_printf( "-I- %s(): инструкция #%d [%s] добавлена в буфер (%s) -I-",
                  __FUNC__, i_Set, Line_Set(i_Set, -1), Get_Time_asLine());
////////////////////////////////////////////////////////////////////////////////
 Mem_Instruction[i_Set].fAddBuffer = TRUE; // флаг добавления инструкции в буфер =======
 mI->Cells[6][i_Set+1] = Vizu_Flags(i_Set); // визуализировали ФЛАГИ данной инструкции =
////////////////////////////////////////////////////////////////////////////////
//
 Really_Buffer_Old = Really_Buffer; // запомнили предудущее значение
 Really_Buffer ++ ; // прибавили единицу - указатель на следующий элемент массива
//
//==============================================================================
 Calc_Level_Buffer_Fill(); // вычисление наполненности буфера
//
 Test_Visu_Buffer_Fill(); // тестирование индикация заполненности буфера
//
 Vizu_Buffer(); // визуализация буфера команд
//
////////////////////////////////////////////////////////////////////////////////
//
 if(Really_Buffer == Max_Buffer) // буфер полный
 {
  t_printf( "-W- %s(): буфер полон, больше инструкций добавлять нельзя (%s) -W-",
                    __FUNC__, Get_Time_asLine());
//
  buffer_Fill = TRUE; // буфер полон
//
  return;
 }
//
} // ----- конец Add_toBuffer -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
float __fastcall
Calc_Priority(float Param) // по значению Param (ПОЛЕЗНОСТЬ) определяется
// ПРИОРИТЕТ данной инструкции при ее запуске на свободном АИУ
{
//
 if(!How_Calc_Prior) // если НОЛЬ - прямо пропорционально
  return (Param);
//
 else // если НЕ НОЛЬ - обратно пропорционально
  {
   if(!Param) // чтобы не делить на нуль
    Param += 1.0e-9;
   return (1.0 / Param);
  }
//
} // конец Calc_Priority -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
float __fastcall
Calc_Param(int i_Set) // для инструкции i_Set определяется ее параметр ПОЛЕЗНОСТИ
{
// char Set[_SET_LEN];
 float Param = 1.0; // умолчание
//
 if(!How_Calc_Param) // если НОЛЬ - все одинаковые
  Param = 1.0;
//
 else
 if(How_Calc_Param == 1) // если ЕДИНИЦА - случайное число =====================
  Param = rand() % 1000;
//
 else  // если ДВОЙКА - пропорционально времени выполнения инструкции ==========
 if(How_Calc_Param == 2)
  Param = 1.0 * Get_TicksByInstruction(Mem_Instruction[i_Set].Set);
//
 else  // если ТРОЙКА - общее число иных инструкций, для кот.результат данной совпадает ХОТЬ С ОДНИМ вх.операндов
 if(How_Calc_Param == 3)
  Param = Calc_01_Param_Instruction(i_Set);
//
 else  // если ЧЕТВЕРКА - общее число операндов иных инструкций, совпадающих по адресу с результатом данной
 if(How_Calc_Param == 4)
  Param = Calc_02_Param_Instruction(i_Set);
//
 else  // если ПЯТЕРКА - с УЧЕТОМ ВЕСоВ при совпадении НЕГОТОВЫХ входн.операндов с рез.выполнения данной
 if(How_Calc_Param == 5)
  Param = Calc_03_Param_Instruction(i_Set);
//
 return Param; // вернули значение полезности
//
} // конец Calc_Param ----------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall
Test_Visu_Buffer_Fill() // тестирует и индицирует наполнение буфера интструкций (в динамике)
{
 char tmp[_512];
 float level[]={0.25, 0,50, 0,75, 0,90}, // уровни тестрирвания
       now,old; // текущее и предыдущее заполнение буфера инструкций
//
 now = Really_Buffer / Max_Buffer;
 old = Really_Buffer_Old / Max_Buffer;
///
 F1->PB_1->Position = (F1->PB_1->Max - F1->PB_1->Min) *
                       Really_Buffer / Max_Buffer; // положение ползунка
//
 for(int i=0; i<3; i++) // по уровням level
  {
   if(now >= level[i] && old < level[i]) // движение  ВВЕРХ через levels[i]
    {
     t_printf( "-I- %s(): буфер заполнен более чем на %.0f %%  (%s) -I-",
                      __FUNC__, 1.0e2*level[i], Get_Time_asLine());
    }
//
   else
   if(now <= level[i] && old > level[i]) // движение  ВНИЗ через levels[i]
    {
     t_printf( "-I- %s(): буфер заполнен менее чем на %.0f %% (%s) -I-",
                      __FUNC__, 1.0e2*level[i], Get_Time_asLine());
    }
//
  } // конец по level
//
} // конец Test_Visu_Buffer_Fill -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int __fastcall
Select_Set_fromBuffer() // возвращает номер инструкции из буфера по условию мах ПРИОРИТЕТА
{ // сдвигает остальные инструкции в буфере и корректирует Really_Buffer
// struct timeb t1; // структура системного времени
 float Prior = -1.0e20;
 int i_Set_Prior_Max, i_Buffer;
 char tmp[_512];
//
 if(!Really_Buffer)
  {
   t_printf( "-W- %s(): буфер пуст ! (%s) -W-", __FUNC__, Get_Time_asLine());
   return BUFFER_EMPTY;
  }
//------------------------------------------------------------------------------
//
 for(int i=(Really_Buffer-1); i>=0; i--) // по всему буферу СВЕРХУ ВНИЗ (чтобы выбрать ПЕРВУЮ с начала)
// for(int i=0; i<Really_Buffer; i++) // по всему буферу СНИЗУ ВВЕРХ (чтобы выбрать ПОСЛЕДНЮЮ с начала)
  if(Mem_Buffer[i].Priority >= Prior) // ищем max (Mem_Buffer[i].Priority)...
   {
    i_Set_Prior_Max = Mem_Buffer[i].i_Set; // запомнили номер инструкци в Mem_Instruction[]
    i_Buffer = i; // запомнили номер инструкции в буфере Mem_Buffer[]
    Prior = Mem_Buffer[i].Priority;
   }
//
// итак, i_Set_Prior_Max - инструкция с максимальном приоритетом ///////////////
//
 t_printf( "-I- %s(): инструкция #%d/%d [%s] (приор. = %.4f) выбрана из буфера для исполнения (%s) -I-",
                  __FUNC__, i_Set_Prior_Max, i_Buffer,
                  Line_Set(i_Set_Prior_Max, -1), Mem_Buffer[i_Buffer].Priority,
                  Get_Time_asLine());
//
// теперь уберем инструкцию i_Set_Prior_Max из буфера
//
 if(! i_Buffer) // это первая в буфере инструкция
  for(UI i=1;  i<Really_Buffer; i++) // по всем инструкция в буфере
   {
    M_B = Mem_Buffer[i]; // сдвиг на 1 к началу буфера...
    Mem_Buffer[i-1] = M_B;
   }
//
 else
 if(i_Buffer == (Really_Buffer-1)) // это последняя в буфере инструкция
  ; // ничего не делаем - ниже уменьшаем Really_Buffer на 1
//
 else // остальные случаи
  for(UI i=i_Buffer; i<Really_Buffer; i++) // по инструкциям >= i_Save в буфере
   {
    M_B = Mem_Buffer[i+1]; // сдвиг на 1 к началу буфера...
    Mem_Buffer[i] = M_B;
   }
//
////////////////////////////////////////////////////////////////////////////////
//
 Really_Buffer -- ;
//
////////////////////////////////////////////////////////////////////////////////
//
 Calc_Level_Buffer_Fill(); // вычисление наполненности буфера
//
 Test_Visu_Buffer_Fill(); // показ размера буфера
//
 Vizu_Buffer(); // визуализация буфера команд
//
 return( i_Set_Prior_Max ); // вернули номер в Mem_Instruction инструкции с наибольшим приоритетом
//
} // конец Select_Set_fromBuffer -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall
Calc_Level_Buffer_Fill() // вычисляет наполненность буфера в %% в глобале Level_Buffer_Fill
{
 char tmp[_512];

 Level_Buffer_Fill = (100.0 * Really_Buffer) / Max_Buffer;

 snprintf(tmp,sizeof(tmp), "Выборка из буфера ( %d / %d = %.3f%% )",
              Really_Buffer,Max_Buffer,Level_Buffer_Fill);
// F1->BitBtn_Select_fromBuffer->Caption = tmp;

} // конец Calc_Level_Buffer_Fill ----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall
Test_aResult_Eq_aOperand(int i_Set) // не совпадает ли в инструкции i_Set
{ // адрес aResult с адресами входных операндов (попытка модификации -
  // нарушение ПРИНЦИПА ЕДИНОКРАТНОГО ПРИСВАИВАНИЯ) ?
 char tmp[_512];
////////////////////////////////////////////////////////////////////////////////
//
// if( Mem_Instruction[i_Set].aResult[0] == attrVar[0] ) // если первый символ aResult суть attrVal,
 if( !memcmp( Mem_Instruction[i_Set].aResult,attrVar,strlen(attrVar) ) ) // сравнение по strlen(attrVar) символам
  return FALSE; // на aResult не распространяется правило ЕДИНОКРАТНОГО ПРИСВАИВАНИЯ
//
////////////////////////////////////////////////////////////////////////////////
 switch( Get_CountOperandsByInstruction(Mem_Instruction[i_Set].Set) ) // число входных операндов инструкции Set
 {
  case 1: if( !strcmp( Mem_Instruction[i_Set].aResult, Mem_Instruction[i_Set].aOp1 ) ) // совпадают ?
           {
            t_printf( "-W- %s(): в инструкции #%d [%s] адрес результата совпадает с адресом входного операнда. Нарушен ПРИНЦИП ОДНОКРАТНОГО ПРИСВАИВАНИЯ... -W-",
                             __FUNC__, i_Set, Line_Set(i_Set, -1));
            return TRUE; // ДА - есть совпадение !!!
           }
          else
           return FALSE;
          break;
//
  case 2: if( !strcmp( Mem_Instruction[i_Set].aResult, Mem_Instruction[i_Set].aOp1 ) || // или...
              !strcmp( Mem_Instruction[i_Set].aResult, Mem_Instruction[i_Set].aOp2 ) ) // совпадают ?
           {
            t_printf( "-W- %s(): в инструкции #%d [%s] адрес результата совпадает с адресом одного из входных операндов. Нарушен ПРИНЦИП ОДНОКРАТНОГО ПРИСВАИВАНИЯ... -W-",
                             __FUNC__, i_Set, Line_Set(i_Set, -1));
            return TRUE; // ДА - есть совпадение !!!
           }
          else
           return FALSE;
          break;
//
 default: break;
//
 } // конец switch
//
} // --- конец Test_aResult_Equal_aOperand -------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall
Get_Time_asLine() // вернуть вр емя (в тактах начиная с 0) в строке
{
 static // чтобы данные не "забивались" другими на стэке
        char tmp[_512];
//
 snprintf(tmp,sizeof(tmp), "текущий момент: %d тактов", localTick);
 return tmp;
//
} // конец Get_Time_asLine -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int  __fastcall
Get_Free_Proc() // возвращает число свободных АИУ
{
 int Free_Proc = 0; // число свободных АИУ
//
 for(UI i=0; i<Max_Proc; i++) // по списку АИУ
  if( !Mem_Proc[i].Busy ) // если АИУ номер i свободно...
   Free_Proc ++ ;
//
 return Free_Proc; // число свободных АИУ
//
} // конец Get_Free_Proc -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall
AttemptExecMaxInstructions_fromBuffer()
{ // пытается выбрать из буфера и выполнить максимум ГКВ-инструкций ------------
// итак, имеем в буфере Really_Buffer команд и Free_Proc свободных АИУ ---------
// int Possible_Exec_Set;
//
 if(!Really_Buffer || !Free_Proc) // крайний случай...
  return;
//
 int Possible_Exec_Set = min(Really_Buffer, Free_Proc); // ограничения...
//
 for(int i=1; i<=Possible_Exec_Set; i++)
  {
   int i_Set = Select_Set_fromBuffer(); // выбрать инструкцию с максимальным приоритетом из буфера
//   if(i_Set != BUFFER_EMPTY) // если буфер не пуст...
   ExecuteInstructions_ExceptSET(i_Set); // выполнить инструкцию i_Set ( кроме SET )
  }
//
} // конец AttemptExecMaxInstructions_fromBuffer -------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
float __fastcall
Calc_01_Param_Instruction(int i_Set) // вычиcляет ПОЛЕЗНОСТЬ инструкции i_Set по 01-му методу
{ // ПОЛЕЗНОСТЬ равна числу иных инструкций, для которых результат данной является
// ХОТЯ БЫ ОДНИМ из входных операндов (неважно, из скольких всего имеющихся)
// при этом ФЛАГИ ГОТОВНОСТИ входных операндов не анализируются !
 char aResult[_ID_LEN];
 float Param = 0; // значение полезности
//
// strcpy(Set, Mem_Instruction[i_Set].Set); // мнемонику i_Set запомнили в Set...
 strcpy(aResult, Mem_Instruction[i_Set].aResult); // адрес результата выполнения i_Set
//
 for(UI i=0; i<Really_Set; i++) // по всем инструкциям...
  {
   if(i == i_Set) // саму с собой инструкции не сравниваем ---------------------
    continue;
//
   switch(Get_CountOperandsByInstruction(Mem_Instruction[i].Set)) // по числу операндов инструкции i
    {
     case 1: if(!strcmp(aResult, Mem_Instruction[i].aOp1)) // aResult[i_Set] == aOp1[i]
               Param ++;
             break;
//
     case 2: if(!strcmp(aResult, Mem_Instruction[i].aOp1) || // aResult[i_Set] == aOp1[i] "или"
                !strcmp(aResult, Mem_Instruction[i].aOp2))   // aResult[i_Set] == aOp2[i]
               Param ++;
             break;
    } // конец swith(Get_CountOperandsByInstruction(Set))
//
  } // конец по for()  всем инструкция
//
 return Param;  // значение полезности
//
} // конец Calc_01_Param_Instruction -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
float __fastcall
Calc_02_Param_Instruction(int i_Set) // вычиcляет ПОЛЕЗНОСТЬ инструкции i_Set по 02-му методу
{ // ПОЛЕЗНОСТЬ равна числу входных операндов иных инструкций, для которых результат
// данной является входным операндом (неважно из скольких всего имеющихся)
// при этом ФЛАГИ ГОТОВНОСТИ входных операндов не анализируются !
 char aResult[_ID_LEN];
 float Param = 0; // значение полезности

// strcpy(Set, Mem_Instruction[i_Set].Set); // мнемонику i_Set запомнили в Set...
 strcpy(aResult, Mem_Instruction[i_Set].aResult); // адрес результата выполнения i_Set
//
 for(UI i=0; i<Really_Set; i++) // по всем инструкциям...
  {
   if(i == i_Set) // саму с собой инструкции не сравниваем ---------------------
    continue;
//
   switch(Get_CountOperandsByInstruction(Mem_Instruction[i].Set)) // по числу операндов инструкции i
    {
     case 1: if(!strcmp(aResult, Mem_Instruction[i].aOp1)) // aResult[i_Set] == aOp1[i]
               Param ++;
             break;
//
     case 2: if(!strcmp(aResult, Mem_Instruction[i].aOp1))  // aResult[i_Set] == aOp1[i]
               Param ++;
//
             if(!strcmp(aResult, Mem_Instruction[i].aOp2)) // aResult[i_Set] == aOp2[i]
               Param ++;
             break;
//
    } // конец swith(Get_CountOperandsByInstruction(Set))
//
  } // конец по for()  всем инструкция
//
 return Param;  // значение полезности
//
} // конец Calc_02_Param_Instruction ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
float __fastcall
Calc_03_Param_Instruction(int i_Set) // вычиcляет ПОЛЕЗНОСТЬ инструкции i_Set по 03-му методу
{ // максимальный "вес" тестируемой инструкции =1.0 соответствует случаю, когда
// результат выполнения данной приводит тестируемую в состояние ГОТОВНОСТЬ К ВЫПОЛНЕНИЮ
// если у тестируемой инструкции N входных операндов, из которых M уже ГОТОВЫ и
// результат выполнения данной инсрукции совпадает по адресу с К из (N-M) НЕГОТОВЫХ,
// то ПОЛЕЗНОСТЬ равна K/(N-M) --- при K=(N-M) получаем вес ЕДИНИЧНЫЙ тестируемой инструкции
 char aResult[_ID_LEN];
 float Param = 0; // значение полезности
//
 strcpy(aResult, Mem_Instruction[i_Set].aResult); // адрес результата выполнения i_Set
//
 for(UI i=0; i<Really_Set; i++) // по всем инструкциям...
  {
   if(i == i_Set) // саму с собой инструкции не сравниваем ---------------------
    continue;
//
   switch( Get_CountOperandsByInstruction(Mem_Instruction[i].Set) ) // по числу операндов инструкции i
    {
     case 1: if( !MI_fOp1(i) && // первый входной операнд НЕ ГОТОВ "и"
                  MI_aOp1(i) ) // aResult[i_Set] == aOp1[i]
               Param ++;
             break;
//
     case 2: if( !MI_fOp1(i) && // первый входной операнд НЕ ГОТОВ "и"
                  MI_fOp2(i) && // второй входной операнд ГОТОВ "и"
                  MI_aOp1(i) ) // aResult[i_Set] == aOp1[i]
               Param ++ ;
//
             if(  MI_fOp1(i) && // первый входной операнд ГОТОВ "и"
                 !MI_fOp2(i) && // второй входной операнд НЕ ГОТОВ "и"
                  MI_aOp1(i) ) // aResult[i_Set] == aOp2[i]
               Param ++ ;
//
             if( !MI_fOp1(i) && // первый входной операнд НЕ ГОТОВ "и"
                 !MI_fOp2(i) )   // второй входной операнд НЕ ГОТОВ "и"
              if(!strcmp( Mem_Instruction[i].aOp1, aResult)) // aResult[i_Set] == aOp1[i]
               Param += 0.5 ;
              else
              if(!strcmp(aResult, Mem_Instruction[i].aOp2)) // aResult[i_Set] == aOp2[i]
               Param += 0.5 ;
             break;

    } // конец swith(Get_CountOperandsByInstruction(Set))
//
  } // конец по for()  всем инструкция
//
 return Param;  // значение полезности
//
} // конец Calc_02_Param_Instruction ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall
Delay_Vizu_Buffer() // ждет Delay_Buffer миллисек для визуализации буфера
{
 if(!Delay_Buffer) // ежели НОЛЬ - ничего не делаем...
  return;
 else
  Delay(Delay_Buffer);

} // конец Delay_Vizu_Buffer ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // вызывается из "Самое УДИВИТЕЛЬНОЕ" главного меня
TF1::Most_Wonderful(TObject *Sender)
{
// удивительное свойство DATA-FLOW вычислителей - результат вычислений не
// зависит от последовательности расположения операторов !!!
 char tmp[_1024];
//
 strcpy(tmp, "... Самое удивительное в том, что для DATA-FLOW машины\n");
 strcat(tmp, "результат вычислений НЕ ЗАВИСИТ ОТ ПОСЛЕДОВАТЕЛЬНОСТИ\n");
 strcat(tmp, "ОПЕРАТОРОВ (ибо вычисления управляются СОБСТВЕННО\n");
 strcat(tmp, "ДАННЫМИ, а не последовательностью операторов).\n\n");
 strcat(tmp, "Желаете случайным образом ПЕРЕМЕШАТЬ инструкции и далее\n");
 strcat(tmp, "повторить расчёт, дабы убедиться в сказанном?");
//
// MessageBeep(0xFFFFFFFF);
//
 switch( MessageBox(0, tmp, " Информация/вопрос", MB_YESNO) )
 {
  case IDYES: // нажата кнопка Yes
              Start_DataFlow_Process( 1 ); // начать счет после перемешивания инструкций
              break;

  case IDNO:  // нажата кнопка No
              break;
 } // конец switch
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // вызывается из "Работа->Перемешать инструкции+расчет" главного меня
TF1::Mixed_Start(TObject *Sender)
{
 Start_DataFlow_Process ( 1 ); // перемешать инструкции и начать расчёт
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall
TF1::On_Master_Timer(TObject *Sender)
{ // вызывается каждые Interval миллисекунд таймером Master_Timer
//
 char tmp[_512];
 ULI i_Proc, i_Set, dt_ticks;
//
////////////////////////////////////////////////////////////////////////////////
 localTick ++ ; // увеличили число тиков (глобальное) на 1
////////////////////////////////////////////////////////////////////////////////
//
 for(i_Proc=0; i_Proc<Max_Proc; i_Proc++) // по всем АИУ
  {
   if( !Mem_Proc[i_Proc].Busy ) // АИУ номер i_Proc свободно
    continue; // переход к следующему АИУ
//
   i_Set = Mem_Proc[i_Proc].i_Set; // номер инструкции в Mem_Instruction[]
//
   dt_ticks = Get_TicksByInstruction( Mem_Instruction[i_Set].Set ); // число тактов для выполнения инструкции Set
//
   if( dt_ticks <= 0 ) // фиктивно пропускаем тик для инструкций со свременем выполнения 0
    localTick -= dummy_Ticks ;
//
   if( (localTick - Mem_Proc[i_Proc].tick_Start) >= dt_ticks ) // время выполнения инструкции вЫшло
   {
    Finalize_Except_SET( i_Proc ); // по результатам выполнения инструкции i_Proc
    // устанавливает флаги готовности операндов у других инструкций и, если все операнды ГОТОВЫ,
    // добавляет ГОТОВУЮ инструкцию в буфер инсрукций для последующего выполнения
    localTickOfEndLastExecuteSet = localTick; // время окончания выполнения инструкции
   }
// '>=' вместо '==' записано в целях избежания ошибок округления !!!!!!!!!!!!!!!
// не следует опасаться повторного вызова Finalize_Except_SET(i_Proc) - в этой процедуре
// при первом выполнении будет установлен флаг Mem_Proc[i_Proc].Busy = FALSE и сработает continue
//
  } // конец цикла по АИУ
//
 if( localTick - localTickOfEndLastExecuteSet >=
     waitAboveOfEndLastExecuteSet ) // ничего не выполняется более wait... тиков
 {
  Master_Timer->Enabled = FALSE; // выключили главный таймер (больше вызываться эта функция не будет!!!)
//  MessageBox(0, "Конец выполнения программы", "Информация", MB_OK);
  StopCalculations( 1 ); // выполнение остановлено из-за простОя
 }
//
 return;
//
} // --- конец On_Master_Timer -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SG_SetSelectCell(TObject *Sender, int ACol,
                                      int ARow, bool &CanSelect)
{ // вызывается при выборе ячейки ----------------------------------------------
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::Result_toOperands(TObject *Sender)
{ // показывает цветом все входные операнды, зависимые от
// результата выполнения данной (выделенной в SG) инструкции
 char Set[_SET_LEN],
      aResult[_ID_LEN],
      str[_2048], tmp[_2048];
 bool c1, c2; // флаги тестирования операндов
//
 Clear_AllCells(); // очистим цвета всех ячеек таблицы инструкций
//
 if(mI->Col != 4) // это вообще не столбец результата... пропускаем !!!
  return;
//
 strcpy(aResult, Mem_Instruction[mI->Row-1].aResult); // запомнили адрес aResult
//
 strcpy(str, ""); // очистили tmp
//
 Really_Select = 0; // счётчик заполненных в Sel_Cell ячеек (глобал)
//
 for(ULI i=0; i<Really_Set; i++) // по всем строкам Mem_Instruction[i]
 {
//
  c1 = c2 = FALSE; // подготовка к анализу...
//
  strcpy(Set, Mem_Instruction[i].Set); //  взяли мнемонику i-той инструкции
//
  if( is_SET( Set ) ) // инструкцию SET не рассматриваем !!!
    continue;

  switch( Get_CountOperandsByInstruction(Set) ) // ... число входных операндов инструкции Set
  {
   case 1: if( !strcmp(aResult, Mem_Instruction[i].aOp1) ) // есть совпадение с aResult ?
           {
            Sel_Cell[Really_Select].Col = 2;
            Sel_Cell[Really_Select].Row = i + 1;
            Sel_Cell[Really_Select].clBackground = DCT.clOperandOperation;
            Sel_Cell[Really_Select].clSymbol     = clBlack;
//
            Really_Select ++ ;
//
            snprintf(tmp,sizeof(tmp), " %d(1|1)", i); // 1-й (и единственный) операнд ГОТОВ
            strcat(str, tmp);
//
            snprintf(tmp,sizeof(tmp), " %d(*|1)", i); // 1-й (и единственный) операнд ГОТОВ
            strcat(str, tmp);
           }
//
           break;
//
   case 2: if( !strcmp(aResult, Mem_Instruction[i].aOp1) )
           {
            Sel_Cell[Really_Select].Col = 2;
            Sel_Cell[Really_Select].Row = i + 1;
            Sel_Cell[Really_Select].clBackground = DCT.clOperandOperation;
            Sel_Cell[Really_Select].clSymbol     = clBlack;
//
            Really_Select ++ ;
            c1 = TRUE;
           }
//
           if( !strcmp(aResult, Mem_Instruction[i].aOp2) )
           {
            Sel_Cell[Really_Select].Col = 3;
            Sel_Cell[Really_Select].Row = i + 1;
            Sel_Cell[Really_Select].clBackground = DCT.clOperandOperation;
            Sel_Cell[Really_Select].clSymbol     = clBlack;
//
            Really_Select ++ ;
            c2 = TRUE;
           }
//
           break;
//
  default: break;
//
  } // конец switch
//
////////////////////////////////////////////////////////////////////////////////
//
            if( c1 ) // если было совпадение с 1-м операндом
            { snprintf(tmp,sizeof(tmp), " %d(1|2)", i);
              strcat(str, tmp); }
//
            if( c2 ) // если было совпадение со 2-м операндом
            { snprintf(tmp,sizeof(tmp), " %d(2|2)", i);
              strcat(str, tmp); }
//
            if( c1 && c2 ) // было совпадение с 1-м и 2-м операндами
            { snprintf(tmp,sizeof(tmp), " %d(*|2)", i);
              strcat(str, tmp); }
//
////////////////////////////////////////////////////////////////////////////////

 } // конец цикла по Mem_Instruction[]

 mI->Repaint();

 if( strlen(str) ) // строка не пустая
 {
  t_printf( "\n-I- %s(): результат выполнения инструкции #%d используется %d раз/а в качестве операнда/ов: %s -I-",
//                   __FUNC__, mI->Row-1, Really_Select, str);
                     __FUNC__ + 5, mI->Row-1, Really_Select, str); // избавляемся от TF1::
 }
 else // строка пустая
 {
  t_printf( "\n-I- %s(): результат выполнения инструкции #%d не используется в качестве никакого операнда !!! -I-",
//                   __FUNC__, mI->Row-1, Really_Select, str);
                     __FUNC__ + 5, mI->Row-1, Really_Select, str); // избавляемся от TF1::
 }

} //----- конец TF!::Result_toOperands -----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::Operand_toResult(TObject *Sender)
{ // показывает цветом все результаты выполнения инструкций, от
// которых зависит данный входной операнд
//
 char Set[_SET_LEN], aOp1[_ID_LEN], aOp2[_ID_LEN], aResult[_ID_LEN],
      tmp[_512];
 int Col, Row, n_Op,
     i_save, i_save_no = -1234567;
//
 i_save = i_save_no; // предварительное присваивание

 if( is_SET(Mem_Instruction[mI->Row-1].Set) ) // для SET действие бессмысленно...
  return;

 Clear_AllCells(); // очистим цвета всех ячеек таблицы инструкций

 Col = mI->Col; // запомнили номер столбца (2-й соответствует aOp1, 3-й - aOp2)
 Row = mI->Row;

 if(Col == 2)
  strcpy(aOp1, Mem_Instruction[mI->Row-1].aOp1); // запомнили адрес aOp1
 else
 if(Col == 3)
  strcpy(aOp2, Mem_Instruction[mI->Row-1].aOp2); // запомнили адрес aOp2 (может не быть!!!)

 strcpy(Set, Mem_Instruction[Row-1].Set); //  взяли мнемонику выделенной инструкции
 n_Op = Get_CountOperandsByInstruction(Set); // число ее входных операндов
//
 Really_Select = 0; //  счётчик заполненных в Sel_Cell ячеек (глобал)
//
 for(ULI i=0; i<Really_Set; i++) // по всем строкам Mem_Instruction[]
 {
  strcpy(aResult, Mem_Instruction[i].aResult); // взяли адрес результата i-той инструкции

  if(Col == 2) // первый входной операнд ( aOp1 )
   if(!strcmp(aOp1, Mem_Instruction[i].aResult)) // есть совпадение aOp1 с aResult ?
    {
     Sel_Cell[Really_Select].Col = 4;
     Sel_Cell[Really_Select].Row = i + 1;
     Sel_Cell[Really_Select].clBackground = DCT.clOperandOperation;
     Sel_Cell[Really_Select].clSymbol     = clBlack;
//
     Really_Select ++ ;
     i_save = i;
    }

  if(Col == 3 && n_Op == 2) // второй (из двух) входной операнд ( aOp2 )
     if(!strcmp(aOp2, Mem_Instruction[i].aResult)) // есть совпадение aOp2 с aResult ?
    {
     Sel_Cell[Really_Select].Col = 4;
     Sel_Cell[Really_Select].Row = i + 1;
     Sel_Cell[Really_Select].clBackground = DCT.clOperandOperation;
     Sel_Cell[Really_Select].clSymbol     = clBlack;
//
     Really_Select ++ ;
     i_save = i;
    }

 } // конец цикла по Mem_Instruction[]

 mI->Repaint();
//
 if(i_save != i_save_no) // зависимость найдена!
  t_printf( "\n-I- %s(): %d-й операнд инструкции #%d зависит от результата выполнения инструкции #%d -I-",
//                   __FUNC__, Col-1, mI->Row-1, i_save);
                   __FUNC__ + 5, Col-1, mI->Row-1, i_save); // избавляемся от TF1::
 else // зависимость не найдена..
  t_printf( "\n-I- %s(): %d-й операнд инструкции #%d не зависит от результата выполнения никакой инструкции !!! -I-",
//                   __FUNC__, Col-1, mI->Row-1);
                   __FUNC__ + 5, Col-1, mI->Row-1); // избавляемся от TF1::
//
} //--- конец TF1::Operand_toResult --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnPopup_Determine_Links(TObject *Sender)
{ // вызывается при всплывании Determine_Links

 OR_1->Enabled = FALSE; // сделать невидимыми оба варианта всплывающего меню Determine_Links
 RO_1->Enabled = FALSE;

 if(mI->Col == 4) // выбран столбец РЕЗУЛЬТАТ операции
  RO_1->Enabled = TRUE; // высветить вариант меню "Операнды->Результат"

 if( (mI->Col == 2) || (mI->Col == 3) ) // выбран столбец ОПЕРАНД-1 или ОПЕРАНД-2
  OR_1->Enabled = TRUE; // высветить вариант меню "Результат->Операнды"

} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // вызывается при отрисовке каждой ячейки таблицы SG_Sets
TF1::SG_Sets_DrawCell(TObject *Sender, int ACol, int ARow,
                      TRect &Rect, TGridDrawState State)
{
//
 if( Really_Select <= 0 ) // ничего не надо выделять цветом
  return;
//
 for( ULI i=0; i<Really_Select; i++ ) // по содержимому списка выделенных ячеек
 {
//
  if( !Sel_Cell[i].Col && // если нулевые...
      !Sel_Cell[i].Row )
   continue;
//
  if( ACol != Sel_Cell[i].Col || // это не текущая ячейка!..
      ARow != Sel_Cell[i].Row )
   continue;
//
  if( Sel_Cell[i].clBackground == mI->Canvas->Brush->Color && // цвет фона ячейки менять не надо...
      Sel_Cell[i].clSymbol     == mI->Canvas->Font->Color ) // цвет фонта ячейки менять не надо...
   continue;
//
  mI->Canvas->Brush->Color = Sel_Cell[i].clBackground; // настроили цвет фона ячейки
  mI->Canvas->FillRect( Rect ); // закрасили фоновым цветом
//
  mI->Canvas->Font->Color  = Sel_Cell[i].clSymbol; // настроили цвет фонта
  mI->Canvas->TextOut( Rect.Left + 2, Rect.Top + 2, mI->Cells[ACol][ARow] ); // восстановили текст
//
 } // конец цикла for(ULI i=0 ... по содержимому массива Sel_Cell[] ------------
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::DrawNotExecuteSets(TObject *Sender)
{ // визуализируются НЕВЫПОЛНИВШИЕСЯ инструкции
//
 Clear_AllCells(); // очистим цвета всех ячеек таблицы инструкций
//
 Really_Select = 0; // счётчик заполненных в Sel_Cell ячеек (глобал)
//
 for(ULI i=0; i<Really_Set; i++) // по всем строкам Mem_Instruction[]
 {
  if(!Mem_Instruction[i].fExecOut) // если инструкция НЕ ВЫПОЛНИЛАСЬ ни разу...
  {
   Sel_Cell[Really_Select].Col = 6;
   Sel_Cell[Really_Select].Row = i + 1;
   Sel_Cell[Really_Select].clBackground = DCT.clNonExecuted;
   Sel_Cell[Really_Select].clSymbol     = clBlack;
//
   Really_Select ++ ;
  }
 } // конец по всем строкам Mem_Instruction[i] -----------------------------------------

 mI->Repaint();
//
 char tmp[_512];
 snprintf(tmp,sizeof(tmp), " Выделено %d позиции/й...", Really_Select);
 SBM0->Text = tmp; // вывод текста в StatusBarMain
//
} //----------------------------------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::DrawNotUsedResults(TObject *Sender)
{ // визуализизируются инструкции, результат выполнения которых
// НЕ ИСПОЛЬЗУЕТСЯ никакими другими инструкциями в качестве входных операндов
 char aResult[_ID_LEN]; // мнемоника инструкции и имя результата
 int n_Op;
//
 Clear_AllCells(); // очистим цвета всех ячеек таблицы инструкций
//
 Really_Select = 0; // счётчик заполненных в Sel_Cell[] ячеек (глобал)
//
 for(ULI i=0; i<Really_Set; i++) // по всем строкам Mem_Instruction[]
 {
  strcpy(aResult, Mem_Instruction[i].aResult); // запомнили имя РЕЗУЛЬТАТА выполнения инструкции

  for(ULI j=0; j<Really_Set; j++) // ... опять же по всем строкам Mem_Instruction[] для поиска по операндам
  {
   if( is_SET( Mem_Instruction[j].Set ) ) // инструкцию SET не рассматриваем !!!
    continue;
//
   n_Op = Get_CountOperandsByInstruction(Mem_Instruction[j].Set); // число операндов инструкции j
//
   if( n_Op == 1 && // если ОДИН операнд... "И"
       MI_aOp1(j) ) // aResult РАВЕН aOp1
    goto end_i;

   if( n_Op == 2 && // если ДВА операнда... "И"
       (
        MI_aOp1(j) || // aResult РАВЕН aOp1 "ИЛИ"
        MI_aOp2(j) // aResult РАВЕН aOp2
       )
     )
    goto end_i;

  } // конец ВНУТРЕННЕГО цикла по Mem_Instruction[j]

// если НЕТ СОВПАДЕНИЯ, добавляем координаты этой ячейки в Sel_Cell[] для отрисовки
//
   Sel_Cell[Really_Select].Col = 4;
   Sel_Cell[Really_Select].Row = i + 1;
   Sel_Cell[Really_Select].clBackground = DCT.clNonUsedResult;
   Sel_Cell[Really_Select].clSymbol     = clBlack;
//
   Really_Select ++ ;
//
end_i: // в конец цикла по i
//
 } // конец ВНЕШНЕГО чикла по Mem_Instruction[i]
//
 mI->Repaint();
//
 char tmp[_512];
 snprintf(tmp,sizeof(tmp), " Выделено %d позиции/й...", Really_Select);
 SBM0->Text = tmp; // вывод текста в StatusBarMain
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::DrawNotDetermineOperands(TObject *Sender)
{ // визуализируются операнды, НЕ ОПРЕДЕЛЕННЫЕ результатами вычислений
 char aOp1[_ID_LEN], aOp2[_ID_LEN], aResult[_ID_LEN]; // мнемоника инструкции и имя результата
 bool flag_1,   flag_2,
      flag_1_1, flag_1_2, flag_2_2;
 int n_Op;
//
 Clear_AllCells(); // очистим цвета всех ячеек таблицы инструкций
//
 Really_Select = 0; // счётчик заполненных в Sel_Cell ячеек (глобал)
//
 for(ULI i=0; i<Really_Set; i++) // по всем строкам Mem_Instruction[]
 {
  if( is_SET( Mem_Instruction[i].Set ) ) // инструкция SET не рассматривается...
   continue;

  flag_1 = flag_2 = FALSE; // флаги наличия инструкций с 1-м или 2-мя операндами

  n_Op = Get_CountOperandsByInstruction(Mem_Instruction[i].Set); // число операндов инструкции i

  if(n_Op == 1) // есть инструкции с 1-м операндом!
   flag_1 = TRUE;

  if(n_Op == 2) // есть инструкции с 2-мя операндом!
   flag_2 = TRUE;

  strcpy(aOp1, Mem_Instruction[i].aOp1); // запомнили имена ОПЕРАНДОВ инструкции номер i
  strcpy(aOp2, Mem_Instruction[i].aOp2);

  flag_1_1 = flag_1_2 = flag_2_2 = FALSE; // предустанавливаем флаги

  for(ULI j=0; j<Really_Set; j++) // ... опять же по всем строкам Mem_Instruction[] для поиска по РЕЗУЛЬТАТАМ
  {
   strcpy(aResult, Mem_Instruction[j].aResult); // запомнили имя РЕЗУЛЬТАТА выполнения инструкции

   if(n_Op == 1 && !strcmp(aOp1, aResult)) // совпадение с 1-м операндом из одного
    flag_1_1 = TRUE;

   if(n_Op == 2 && !strcmp(aOp1, aResult)) // совпадение с 1-м операндом из двух
    flag_1_2 = TRUE;

   if(n_Op == 2 && !strcmp(aOp2, aResult)) // совпадение со 2-м операндом из двух
    flag_2_2 = TRUE;

  } // конец ВНУТРЕННЕГО цикла по Mem_Instruction[j]

// если НЕТ СОВПАДЕНИЯ, добавляем координаты этой ячейки в Sel_Draw[] для отрисовки

   if( (flag_1 && !flag_1_1) || // есть инструкции с 1-м операндом "И" первый операнд (из одного)
       (flag_2 && !flag_1_2) )  // есть инструкции с 2-мя операндами "И" первый операнд (из двух)
   {
    Sel_Cell[Really_Select].Col = 2; // индицируем столбец с aOp1
    Sel_Cell[Really_Select].Row = i + 1;
    Sel_Cell[Really_Select].clBackground = DCT.clNonDefOperands;
    Sel_Cell[Really_Select].clSymbol     = clBlack;
//
    Really_Select ++ ;
   }

   if(flag_2 && !flag_2_2) // есть инструкции с 2-мя операндами "И" второй операнд (из двух)
   {
    Sel_Cell[Really_Select].Col = 3; // индицируем столбец с aOp2
    Sel_Cell[Really_Select].Row = i + 1;
    Sel_Cell[Really_Select].clBackground = DCT.clNonDefOperands;
    Sel_Cell[Really_Select].clSymbol     = clBlack;
//
    Really_Select ++ ;
   }
//
 } // конец ВНЕШНЕГО чикла по Mem_Instruction[i]
//
 mI->Repaint();
//
 char tmp[_512];
 snprintf(tmp,sizeof(tmp), " Выделено %d позиции/й...", Really_Select);
 SBM0->Text = tmp; // вывод текста в StatusBarMain
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Draw_ReadyOperands()
{ // визуализируются динамика выполнения програамы DATA-FLOW вычислителя
// в динамике используются (ранее установленные) флаги готовности массива Mem_Instruction[]
//
// FILE* fptr;
// fptr = fopen( "a123.txt", "a+" );
// fprintf( fptr, "-=-\n" );
//
 if( !DCE.needDrawColors ) // не надо ничего отрисовывать...
  return;
//
 Really_Select = 0; // счётчик заполненных в Sel_Cell[] ячеек (глобал)
//
 for(ULI i=0; i<Really_Set; i++) // по всем строкам Mem_Instruction[]
 {
//  fprintf( fptr, "i=%5d fOp1=%d fOp2=%d\n", i,Mem_Instruction[i].fOp1,Mem_Instruction[i].fOp2 );
//  fflush( fptr );
  if( MI_fOp1(i) ) // если 1-й операнд ГОТОВ...
  {
   Sel_Cell[Really_Select].Col = 2; // столбец ОПЕРАНД-1
   Sel_Cell[Really_Select].Row = i + 1;
   Sel_Cell[Really_Select].clBackground = DCE.clReadyOperand;
   Sel_Cell[Really_Select].clSymbol     = clBlack;
//
   Really_Select ++ ;
  }
//
  if( Get_CountOperandsByInstruction( Mem_Instruction[i].Set ) == 2 && // если два операнда у инструкции
      MI_fOp2(i) )  // если 2-й операнд ГОТОВ...
  {
   Sel_Cell[Really_Select].Col = 3; // столбец ОПЕРАНД-2
   Sel_Cell[Really_Select].Row = i + 1;
   Sel_Cell[Really_Select].clBackground = DCE.clReadyOperand;
   Sel_Cell[Really_Select].clSymbol     = clBlack;
//
   Really_Select ++ ;
  }
//
  if( Mem_Instruction[i].fExecOut )  // инструкции, которые выполнились 1 раз
  {
   Sel_Cell[Really_Select].Col = 4; // столбец РЕЗУЛЬТАТ
   Sel_Cell[Really_Select].Row = i + 1;
   Sel_Cell[Really_Select].clBackground = DCE.clExecSet,
   Sel_Cell[Really_Select].clSymbol     = clBlack;
//
   Really_Select ++ ;
  }
//
  if( !is_PredicatOrSET( Mem_Instruction[i].Set ) && // это инструкция - НЕ ПРЕДИКТОР
      Mem_Instruction[i].fPredicatTRUE ) // флаг предикатора TRUE
  {
   Sel_Cell[Really_Select].Col = 5; // столбец ПРЕДИКАТ
   Sel_Cell[Really_Select].Row = i + 1;
   Sel_Cell[Really_Select].clBackground = DCE.clTruePredicat;
   Sel_Cell[Really_Select].clSymbol     = clBlack;
//
   Really_Select ++ ;
  }
//
 } // конец цикла по массиву Sel_Cell[] for(ULI...
////////////////////////////////////////////////////////////////////////////////
  mI->Repaint(); // важно! По этому вызову таблица ПЕРЕРИСОВЫВАЕТСЯ (с соответствующими цветАми)
////////////////////////////////////////////////////////////////////////////////
//
} //----- конец Draw_ReadyOperands ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::F1_OnShow(TObject *Sender)
{ // вызывается при отрисовке главной формы
//
 if(ParamCount() == 4) // берем нужное число параметров командной строки (не считая нулевого)
 {
  strcpy(FileNameSet, ParamStr(1).c_str()); // имя файла инструкицй (и проекта)
  Max_Proc       = StrToInt(ParamStr(2).c_str()); // число АИУ
  How_Calc_Param = StrToInt(ParamStr(3).c_str()); // как вычислять параметры приоритета
  How_Calc_Prior = StrToInt(ParamStr(4).c_str()); // как вычислять собственно приоритет
//
  Write_Config(); // сохранить в INI-файл
  Read_Config(); // перечитываем INI-файл...
//
  BitBtn_Run->Click(); // программно нажали кнопку СЧЁТ !!!
//
  OnOf_Execute( 1 ); // "включили" визуальную индикацию режима СЧЁТ
 }
//
} //----- конец F1_OnShow ------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnOf_Execute(int Rule) // "включает/выключает" кнопки при останове/счете
{
 if(Rule) // режим СЧЁТ
 {
  BitBtn_Run->Enabled = FALSE; // "выключили" кнопки
  E_AIU->Enabled      = FALSE;
  Files->Enabled      = FALSE;
  Edit->Enabled       = FALSE;
  Work->Enabled       = FALSE;
  Wonderful->Enabled  = FALSE;
  Analize->Enabled    = FALSE;
 }
 else
 {
  BitBtn_Run->Enabled = TRUE; // "включили" кнопки
  E_AIU->Enabled      = TRUE;
  Files->Enabled      = TRUE;
  Edit->Enabled       = TRUE;
  Work->Enabled       = TRUE;
  Wonderful->Enabled  = TRUE;
  Analize->Enabled    = TRUE;
//
  Label_Data->Font->Color   = clBlack;
  Label_Buffer->Font->Color = clBlack;
 }
//
} //============================================================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
REAL __fastcall
Calc_ConnectedIndex(int Rule) // при Rule # 0 данные выдаются в файл протоколa
{ // вычисляется ИНДЕКС СВяЗНОСТИ (усредненное кол-во операторов, зависящих по операндам)
// от результата выполнения предшествующего в ИНФОРМАЦИОННОМ ГРАФЕ алгоритма
// число ребер, связанных с вершиной - СТЕПЕНЬ ВЕРШИНЫ
 char aResult[_ID_LEN]; // aOp1[_ID_LEN],aOp2[_ID_LEN], // мнемоника инструкции и имя результата
 int n_Op, // число входных операндов у инструкции
     n_EqResOp, i_EqResOp,  // число инструкций, зависящих (по схеме "aResult->aOpN") от данной
     n_Repeat,  i_Repeat; // сколько всего таких по заданному n_EqResOp
 int Sum_EqResOp = 0, // общее число n_EqResOp
     Sum_Repeat = 0, // общее число n_Repeat
     Sum_Repeat_1 = 0, // общее число n_Repeat при n_ResOp >= 2
     n_RepeatEq_1 = 0; // число повторов связей "1->1"
 char tmp[_512]; // рабочий массив
//
 TStringList *CI = new TStringList(); // создать набор строк CI для вычисления индекса связности

 CI->Sorted = FALSE; // не сортировать список
 CI->Duplicates = dupAccept; // одинаковые строки разрешены

 for(UI i=0; i<Really_Set; i++) // по всем строкам Mem_Instruction[i]
 {
  if( is_SET( Mem_Instruction[i].Set ) ) // инструкция SET не рассматривается...
   continue;
//
  n_EqResOp = 0; // число операторов, зависимых от РЕЗУЛЬАТА выполнения данного (i-того)
//
  strcpy(aResult, Mem_Instruction[i].aResult); // запомнили адрес aResult для инструкции i

  for(UI j=0; j<Really_Set; j++) // ... опять же по всем строкам Mem_Instruction[] для поиска по ОПЕРАНДАМ
  {

   if( is_SET( Mem_Instruction[j].Set ) ) // инструкцию SET не рассматриваем !!!
    continue;

   n_Op = Get_CountOperandsByInstruction(Mem_Instruction[j].Set); // число операндов у инструкции  j

   if(n_Op == 1) // один операнд...
   {
    if(!strcmp(aResult, Mem_Instruction[j].aOp1))
     n_EqResOp ++ ;
   }
   else
   if(n_Op == 2) // два операнда...
   {
    if(!strcmp(aResult, Mem_Instruction[j].aOp1))
     n_EqResOp ++ ;
    if(!strcmp(aResult, Mem_Instruction[j].aOp2))
     n_EqResOp ++ ;
   }

  } // конец ВНУТРЕННЕГО цикла по Mem_Instruction[j] ///////////////////////////////////

// итак, к этому моменту n_EqResOp определено (может быть = 0) !!!!!

  if(!n_EqResOp) // если нет зависимости по aResult - то это ВЫХОДНЫЕ данные...
   continue; // заканчиваем цикл по i ... такая информация вообще не интересует !!!

// проверяем, имеется ли в CI строка с таким же n_EqResOp ...
  bool i_flag = FALSE; // признак того, что имеется строка с i_EqResOp = n_EqResOp

  for(int k=0; k<CI->Count; k++) // по всем строкам CI (возможно даже, что CI->Count = 0)
  {
   sscanf(CI->Strings[k].c_str(), "%10d%10d", &i_EqResOp, &i_Repeat); // прочитали строку CI
//   i_EqResOp = atoi(Get_SubString(CI->Strings[k].c_str(),  1,10));
//   i_Repeat  = atoi(Get_SubString(CI->Strings[k].c_str(), 11,20));

   if(i_EqResOp == n_EqResOp) // нашлось значение i_EqResOp, равное n_EqResOp
   {
    i_Repeat ++ ;
    snprintf(tmp,sizeof(tmp), "%10d%10d%30c", n_EqResOp, i_Repeat, 32); // + 30 пробелов!
    CI->Delete(k); // удалили "старую" строку с индексом k
    CI->Insert(k, tmp); // вставили "новую" строку с индексом k
    i_flag = TRUE; // ... да, был случай i_EqResOp == n_EqResOp ...
   }
  } // конец цикла по k

// а если в CI НЕТ СТРОКИ с n_EqResOp ? Тогда добавим такую строку при n_Repeat = 1
  if(!i_flag) // строки с n_EqResOp не нашлось - добавим её !
  {
//   snprintf(tmp,sizeof(tmp), "%10d%10d%30c%s", n_EqResOp, 1, 32, aResult); // i_Repaint=1 // + 30 пробелов!
   snprintf(tmp,sizeof(tmp), "%10d%10d%30c", n_EqResOp, 1, 32); // i_Repeat=1 // + 30 пробелов!
   CI->Add(tmp); // добавили строку в CI
  }

 } // конец ВНЕШНЕГО цикла по Mem_Instruction[i] ///////////////////////////////

// начало вычислений статистики ------------------------------------------------
// вычисляем общее число случаев = СУММА(n_Repeat) кроме строк с n_EqResOp=0

  for(int k=0; k<CI->Count; k++) // по всем строкам CI, кроме строк с n_EqResOp=0
  {
//    Sum_EqResOp  += atoi(Get_SubString(CI->Strings[k].c_str(), 1,10));
   Sum_Repeat += atoi(GetSubString(CI->Strings[k].c_str(), 11,20)); // общая сумма

   if(atoi(GetSubString(CI->Strings[k].c_str(), 1,10)) >= 2)
    Sum_Repeat_1 += atoi(GetSubString(CI->Strings[k].c_str(), 11,20)); // сумма n_ResOp >= 2
  }

// определяем данные для построения гистограммы --------------------------------
  for(int k=0; k<CI->Count; k++) // по всем строкам CI
  {
   sscanf(CI->Strings[k].c_str(), "%10d%10d", &i_EqResOp, &i_Repeat); // прочитали строку CI
//   i_EqResOp = atoi(Get_SubString(CI->Strings[k].c_str(),  1,10));
//   i_Repeat  = atoi(Get_SubString(CI->Strings[k].c_str(), 11,20));
   snprintf(tmp,sizeof(tmp), "%10d%10d%10.3f%10.3f%%", i_EqResOp, i_Repeat, // изменили строку
                 1.0*i_Repeat/Sum_Repeat, 1.0e2*i_Repeat/Sum_Repeat);
   CI->Delete(k); // удалили строку с индексом k
   CI->Insert(k, tmp); // вставили строку с индексом k
//   strncpy(CI->Strings[k].c_str(), tmp, 30); // заменили строку
  }

// средний ИНДЕКС СВЯЗНОСТИ информационного графа программы (исключая выходные данные)

  for(int k=0; k<CI->Count; k++) // по всем строкам CI
  {
   if(atoi(GetSubString(CI->Strings[k].c_str(), 1,10)) == 1) // строка с n_ResOp = 1
    n_RepeatEq_1 = atoi(GetSubString(CI->Strings[k].c_str(), 11,20));
  }

  REAL index;
  if (n_RepeatEq_1)
   {
    index = 1.0 * Sum_Repeat_1 / n_RepeatEq_1;
    snprintf(tmp,sizeof(tmp), "Показатель альтернативности = %.3f", index);
    CI->Add(tmp);
   }
  else
   index = ERR_ALTERNAT; // признак бесконечности

////////////////////////////////////////////////////////////////////////////////

  CI->Sorted = TRUE; // отсортируем (по первому полю - n_EqResOp) в порядке возрастания

// тeперь первая строка (индекс = 0) соответствует n_ResOp = 1 etc etc etc

  if(Rule) // сохранить в файл
  {
   char FileNameConnectIndex[_512]; // путь к файлу индексов связности
   strcpy(FileNameConnectIndex, ChangeFileExt(FileNameSet, ".coi").c_str());  // путь к COI-файлу
   CI->SaveToFile(FileNameConnectIndex);
  }

  delete CI; // уничтожаем набор строк CI

  return index;

} // конец подпрограммы
//---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
REAL __fastcall
StrToReal(char *str, int i_Set)
{ // конвертирует строку в вещественное число с проверкой корректности конвертации
 REAL out;
 char tmp[_512];
//
 try
 {
  out = StrToFloat( AnsiString(str) );
 }
 catch (Exception* exception)
 {
  snprintf(tmp,sizeof(tmp), "Ошибка конвертации строки ''%s'' в вещественное число в инструкции #%d (получено %.*e). \n\nРезультат преобразования",
                str, i_Set, ACC_REAL, out);
  strcat(tmp, "  не определен, но ВЫ ПРЕДУПРЕЖДЕНЫ о возможности получения неожиданных данных при расчёте !..");
  MessageBox(0, tmp, "Предупреждение", MB_OK | MB_ICONWARNING | MB_TOPMOST);
 }
//
 return out;
//
} // ----- конец функции StrToReal ---------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::F1_OnResize(TObject *Sender)
{ // вызывается при кадомй перерисовке главного окна
 int tmp,  // рабочая переменная
     dH = 40, // расстояние по высоте между подокном протокола и нижней группой окон
     W = F1->Width, // взяли текущий размер главного окна программы
     H = F1->Height;
//     Scrollbar_Width  = GetSystemMetrics(SM_CXVSCROLL), // ширина вертикального ScrollBar'a
//     Scrollbar_Height = GetSystemMetrics(SM_CYHSCROLL); // высота горизонтального ScrollBar'a
 float partProtocolH = 0.35; // относительная доля по высоте окна вывода протокола решения задачи
// MessageBeep( MB_OK );

 if( W < minW_F1 ) // окно не может быть менее minW_F1 * minH_F1
  W = minW_F1;

 if( H < minH_F1 ) // ...
  H = minH_F1;

// установим размер главного окна F1
 F1->Width  = W; // новый размер главного окна F1
 F1->Height = H;

// установим размер и положение внутренних компонентов окна F1

// верхний фрейм - окно вывода протокола расчёта -------------------------------
 mR->Height = F1->Height * partProtocolH;
 mR->Width  = F1->ClientWidth - 8;

// нижний ряд фреймов (координаты верхов) --------------------------------------
 tmp = F1->M1->Top + F1->M1->Height + dH;
 mB->Top  = tmp; // присваивания "цепочкой" недопустимы для СВОЙСТВ (Properties)
 mP->Top  = tmp;
 mI->Top  = tmp;
 mD->Top  = tmp;

// нижний ряд фреймов (высоты) -------------------------------------------------
 tmp = F1->ClientHeight - F1->SG_Buffer->Top - F1->StatusBarMain->Height - 3;
 F1->SG_Buffer->Height  = tmp; // присваивания "цепочкой" недопустИмы для СВОЙСТВ (Properties)
 F1->PB_1->Height       = tmp;
 F1->SG_Set->Height     = tmp;
 F1->SG_Data->Height    = tmp;

// нижний ряд фреймов (по ширине) ----------------------------------------------
 mB->Width = mB->ColWidths[0] + mB->ColWidths[1] + 6; // F1->ClientWidth * partBufferW;
 mP->Left  = mB->Left + mB->Width + 2;
 mI->Left  = mP->Left + mP->Width + 4;

 mI->Width = F1->ClientWidth - mI->Left - mD->Width - 8;
 mD->Left  = F1->ClientWidth - mD->Width - 4; // mI->Left  + mI->Width + 2;
 mD->Width = mD->ColWidths[0] + mD->ColWidths[1] + 6; //F1->ClientWidth - mD->Left - 6;

// средний ряд (кнопки) --------------------------------------------------------
 tmp = mR->Top + mR->Height + ( dH - F1->BitBtn_Run->Height ) / 2;
 F1->BitBtn_Run->Top  = tmp; F1->BitBtn_Run->Left  = mB->Left;
 F1->BitBtn_Stop->Top = tmp; F1->BitBtn_Stop->Left = mI->Left;

// средний ряд ( E_AIU + Label_AIU ) -------------------------------------------
 F1->E_AIU->Top     = tmp + 2; F1->E_AIU->Left     = F1->BitBtn_Stop->Left + F1->BitBtn_Stop->Width + 70;
 F1->Label_AIU->Top = tmp + 5; F1->Label_AIU->Left = F1->E_AIU->Left + F1->E_AIU->Width + 7;

// средний ряд (надписи) -------------------------------------------------------
 tmp = mR->Top + mR->Height + ( dH - F1->BitBtn_Run->Height ) / 2 + F1->BitBtn_Run->Height - F1->Label_Buffer->Height;
 F1->Label_Buffer->Top = tmp; F1->Label_Buffer->Left = mB->Left + mB->Width - F1->Label_Buffer->Width;
 F1->Label_Set->Top    = tmp; F1->Label_Set->Left    = mI->Left + mI->Width - F1->Label_Set->Width;
 F1->Label_Data->Top   = tmp; F1->Label_Data->Left   = mD->Left + mD->Width - F1->Label_Data->Width;

// определяем ширину последнего столбца SG_Set (столбец комментариев к инструкции)
 tmp = mI->ColWidths[0] + mI->ColWidths[1] + mI->ColWidths[2]  // ширина первых 0-5 столбцов
     + mI->ColWidths[3] + mI->ColWidths[4] + mI->ColWidths[5];
//
 mI->ColWidths[7] = SG_Set->Width - tmp - 28; // + 60; // ширина 8-го по счёту столбца SG_Set
//
 if( mI->ColWidths[7] <= sizeof(M_I.Comment) ) // не менее sizeof(M_S.Comment)
  mI->ColWidths[7] = sizeof(M_I.Comment);
//
// секции нижней информационной панели -----------------------------------------
 SBM0->Width = 3 * F1->ClientWidth / 8;
 SBM1->Width = SBM0->Width;
 SBM2->Width = F1->ClientWidth / 4;

} //----- конец F1_OnResize ----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::INC0_Connected(TObject *Sender)
{ // вызывается при соединении с сервером
 SBM0->Text = " Соединение с сервером установлено";
 Delay( 500 );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::INC0_Disconnected(TObject *Sender)
{ // вызывается при разрыве соединения с сервером
 SBM0->Text = " Соединение с сервером разорвано";
 Delay( 500 );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::INC0_OnStatus(TObject *axSender, const TIdStatus axStatus, const AnsiString asStatusText)
{ // состояние процесса вЫгрузки
  switch( axStatus )
  {
   case hsResolving:     //SBM0->Text = " A host name is being resolved for an IP address...";
                         SBM0->Text = " Доменное имя успешно разрешено в IP-адрес...";
        break;
   case hsConnecting:    //SBM0->Text = " A connection is being opened...";
                         SBM0->Text = " Соединение устанавливается...";
        break;
//   case hsConnected:    //SBM0->Text = " A connection has been made...";
//                        SBM0->Text = " Соединение успешно устанавлено...";
//        break;
   case hsDisconnecting: //SBM0->Text = " The connection is being closed...";
                         SBM0->Text = " Соединение закрывается...";
        break;
//   case hsDisconnected:  //SBM0->Text = " The connection has been closed...";
//                         SBM0->Text = " Соединение разорвано...";
//        break;
//   case hsText:          //SBM0->Text = asStatusText;
//                         SBM0->Text = asStatusText;
//        break;
//   default:              //SBM0->Text = asStatusText;
//                         SBM0->Text = asStatusText;
  }
//
 Delay( 500 );
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::INC0_OnWork(TObject *Sender, TWorkMode AWorkMode, const int AWorkCount)
{ // вызывается при вЫгрузке данных с сервера на клиент
 SBM0->Text = Format(" %.0f%% (из %d байт) данных получено с сервера", OPENARRAY(TVarRec, (100.0*AWorkCount/FileSizeFromServer, int(FileSizeFromServer)) ) );
 Delay( 500 );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::INC0_OnWorkBegin(TObject *Sender, TWorkMode AWorkMode, const int AWorkCountMax)
{ // вызывается в начало вЫгрузке данных с сервера на клиент
 FileSizeFromServer = AWorkCountMax; // запомнили
 SBM0->Text = Format(" %d байт запрошено для получения с сервера", OPENARRAY(TVarRec, (AWorkCountMax) ) );
 Delay( 500 );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::INC0_OnWorkEnd(TObject *Sender, TWorkMode AWorkMode)
{ // вызывается в конце вЫгрузки данных с сервера на клиент
 Delay( 500 );
 SBM0->Text = Format(" %d байт получено с сервера", OPENARRAY(TVarRec, (int(FileSizeFromServer)) ) );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnClickGetRar(TObject *Sender)
{ // получить файл с сервера
 GetFileFromServer( "install_df.exe" );
} // ---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall GetFileFromServer( char FileName[] )
{ // получить файл с HTTP-сервера ( FileNameInServer - полное имя файла на сервере,
 char FileNameOnServer[_512], FileNameOnClient[_512]; // полные имена файла на сервере и клиенте

 TMemoryStream *UnLoadStream = new TMemoryStream;  // создаём поток для сохранения вЫгруженного из Сети файла

// --- полный путь к каталогу исходных данных (включая слэш в конце)
 snprintf( PathToSubDirInData,sizeof(PathToSubDirInData), "%s%s\\", ExtractFilePath ( Application->ExeName ), NameSubDirInData);
 if( !DirectoryExists( PathToSubDirInData ) ) // если не существует этого каталога...
  if( !CreateDir( PathToSubDirInData ) ) // если не удалось создать...
   strcpy( PathToSubDirInData, '\0' ); // обнуляем путь к подкаталогу PathToSubDirOutData

 snprintf( FileNameOnClient,sizeof(FileNameOnClient), "%s%s", PathToSubDirInData, FileName ); // куда сохранять на клиенте (+++)
 snprintf( FileNameOnServer,sizeof(FileNameOnServer), "%s/dataflow/content/%s", MySite, FileName ); // полное имя файла на сервере (+++)

// ShowMessageFmt( "Client: |%s|\n\nServer: |%s|", OPENARRAY(TVarRec, (FileNameOnClient,FileNameOnServer) ) );

 F1->INC0->Get( FileNameOnServer, UnLoadStream ); // метод Get выгружает файл посредством потока UnLoadStream
 UnLoadStream->SaveToFile( FileNameOnClient ); // сохраняем данные в файл на клиенте

 delete UnLoadStream; // поток более не нужен...

 F1->INC0->Disconnect(); // разрываем соединениe с сервером
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::EndedUploadFile(TObject *Sender)
{ // принудительно разорвать соединение с сервером - прекратить вЫгрузку файла
 F1->INC0->Disconnect(); // разрываем соединение с сервером
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall Test_All_Operands()
{ // тестирует все инструкции на потенциальную определённость операндов
// путём поиска соответствия имен результатоы именем операндов
// при нажатии ПРОДОЛЖИТЬ ВЫПОЛНЕНИЕ возвращается 1, при отмене выполнения - 7
 char Set[_SET_LEN], // мнемоника инструкции
      aOp1[_ID_LEN], aOp2[_ID_LEN], aResult[_ID_LEN], // операнд 1, операнд 2, результат
      str[_512],
      fmt1[] = "-E- Test_All_Operands(): у инструкции #%d [%s %s, %s] операнд [%s] принципиально неразрешим -E-", // строка формата (1 операнд)
      fmt2[] = "-E- Test_All_Operands(): у инструкции #%d [%s %s, %s, %s] операнд #%d [%s] принципиально неразрешим -E-"; // строка формата (2 операнда)
 int nInputOperands; // число входных операндов инструкции
 bool flagOp1,flagOp2, flagAll=TRUE; // флаги разрешимости операндов
//
 for(UI i=0; i<Really_Set; i++) // по всем инструкциям в буфере
 {
  strcpy( Set,Mem_Instruction[i].Set ); // мнемоника инсрукции i
//
  if( is_SET( Set ) ) // если это SET...
   continue; // пропускаем цикл по i
//
  strcpy( aOp1,Mem_Instruction[i].aOp1 ); // операнд 1 инструкции i запомним в aOp1
  strcpy( aOp2,Mem_Instruction[i].aOp2 ); // операнд 2 инструкции i запомним в aOp2
  nInputOperands = Get_CountOperandsByInstruction( Set ); // реальное число операндов инструкции i
//
  flagOp1 = flagOp2 = FALSE; // первоначально считаем, что разрешимости нет...
//
  for(UI j=0; j<Really_Set; j++) // по всем инструкциям в буфере
  {
   if( (j == i) && !is_SET( Set ) ) // саму с собой не сравниваем... но с SET надо сравнивать!
    continue; // пропускаем цикл по j

   strcpy( aResult,Mem_Instruction[j].aResult ); // результат инструкции j запомним в aResult
//
   switch( nInputOperands ) // число входных операндов инструкции Set
   {
    case 1: if( !strcmp( aOp1,aResult )) // если aOp1 = aResult -> Ok операнд 1
             flagOp1 = TRUE; // операнд 1 разрешён
     break;
//
    case 2: if( !strcmp( aOp1,aResult )) // если aOp1 = aResult -> Ok операнд 1
             flagOp1 = TRUE; // операнд 1 разрешён
//
            if( !strcmp( aOp2,aResult )) // если aOp2 = aResult -> Ok операнд 1
             flagOp2 = TRUE;  // операнд 2 разрешён
     break;
//
    default:
//
     break;
//
   } // конец switch( nInputOperands )
//==============================================================================
  } // конец цикла по j
//==============================================================================
// выводим результат -----------------------------------------------------------
//
   switch( nInputOperands ) // число входных операндов инструкции Set
   {
    case 1: if( !flagOp1 )
            {
             flagAll = FALSE; // была хоть одна неразрешимость..!
             t_printf( fmt1, i, Set,Mem_Instruction[i].aOp1, Mem_Instruction[i].aResult, Mem_Instruction[i].aOp1 );
            }
            break;
//
    case 2: if( !flagOp1 )
            {
             flagAll = FALSE; // была хоть одна неразрешимость..!
             t_printf( fmt2, i, Set,Mem_Instruction[i].aOp1, Mem_Instruction[i].aOp2,Mem_Instruction[i].aResult, 1,Mem_Instruction[i].aOp1 );
            }
//
            if( !flagOp2 )
            {
             flagAll = FALSE; // была хоть одна неразрешимость..!
             t_printf( fmt2, i, Set,Mem_Instruction[i].aOp1,Mem_Instruction[i].aOp2,Mem_Instruction[i].aResult, 2,Mem_Instruction[i].aOp2 );
            }
            break;
//
    default: break;
//
    } //  // конец switch( nInputOperands )
//
 } // конец цикла по i
//
//==============================================================================
//
 if( flagAll ) // не было проблем...
  return TRUE;  // все хорошо -> выполняем дальше!
//
  F1->Master_Timer->Enabled = FALSE; // остановили главный таймер
//
  snprintf( str,sizeof(str), "%s(): %s", __FUNC__,
"В программе встречаются операции, принципиально не могущие выполниться \
вследствие неготовности одного или более операндов; \
см. данные в окне протоколирования.\n\n\
Остановить выполнение программы (рекомендуется) или продолжить \
(на свой страх и риск)..?" );
//
  if( MessageBox(0, str, "Остановить / продолжить?",
                          MB_YESNO | MB_ICONQUESTION | MB_APPLMODAL ) == IDYES )
   return FALSE; // конец выполнения
  else
  {
   F1->Master_Timer->Enabled = TRUE; // активировали главный таймер
   return TRUE; // все хорошо... выполняем дальше!
  }
//
} // ---- Test_All_Operands ----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int __fastcall RunPreProcessor()
{ // препроцессор для конвертации макросов в операторы
 char str[_512], // строка для считывания и расшифровки инструкций
      tmp[_512], // рабочая строка
      sIndex[2]="?\0", // символ индекса одномерного массива
      chr;
//      Set[_SET_LEN], // мнемоника инструкции
//      startFor1[] = "for[", // маска для поиска начала описания макросов цикла
//      fmtFor1[]   = "for[%c]=%d,%d,%d;"; // формат выявления начала макроса цикла
//
 int minI,maxI,stepI; // диапазон индексов одномерного цикла
//
 strcpy( FileNameSetPrP, ChangeFileExt(FileNameSet,ExtPrP).c_str() ); // имя файла инструкций после препроцессора
//
 if( !(fptrIn  = fopen( FileNameSet,    "r") ) || // исходный файл инструкций открыть не удалось... ИЛИ
     !(fptrOut = fopen( FileNameSetPrP, "w") ) ) // файл инструкций после препроцессора открыть не удалось...
  return -1;

//
 if( !mPM )
  mPM = new TStringList(); // создали PM (набор строк для тела исходного макро)
//
 snprintf( tmp,sizeof(tmp), " Препроцессинг..." ); // вывод в строку статуса
 SBM2->Text = tmp;
//
 while( 1 ) // по всем строкам инструкций в исходном файле =====================
 {
  if( fgets(str, sizeof(str), fptrIn) == NULL ) // читаем строку из fptrIn
   break; // если строки кончились, функция fgets возвращает NULL
//
  DelSpacesTabsAround(str); // чистка строки str от лидирующих и терминирующих пробелов ...
//
// =============================================================================
  if( strncmp( str, "for[", 4 ) ) // если в начале str не "for[" (первые 4 символа)
  {
   fputs( str, fptrOut );  // пишем в fptrOut
   continue; // уходим на повтор while( 1 ) ====================================
  }
// остались строки с "for[" (первые 4 символа) в начале.........................
//
// ----- пытаемся прочитать первую строку описания параметров одномерного массива
//
  if( sscanf( str, "for[%c]=%d,%d,%d {", sIndex,&minI,&maxI,&stepI ) != 4 ) // не все 4 полей корректно прочитаны..!
  {
   fputs( str, fptrOut );  // пишем в fptrOut
   continue; // уходим на повтор цикла while( 1 ) ==============================
  }
//
// чистим строку от ненужностей ................................................
//
  if(str[strlen(str)-1] == 10) // если в конце символ новой строки (10) в десятичной)...
   str[strlen(str)-1] = '\0';   // ... то заменим на КОНЕЦ СТРОКИ !
//
  if(!strlen(str)) // если длина нулевая - просто пропускаем ее !
   continue; // повтор цикла while( 1 ) ========================================
//
  if( str[0] == startComments[0] ) // если строка начинается с комментария - просто пропускаем ее !
   continue;
//
// а вот теперь всё верно..! Начинаем анализировать содержиое строк между "for[c]=n1,n2.n3 {" и "}"
//
// ----- проверки корректности значений sIndex,minI,maxI,stepI -----------------
  startPos[0] = '\0'; // строки выводятся без комментариев
  if( minI >= maxI && stepI == 0 )
   startPos[0] = startComments[0]; // все строки комментируются
//
cont_withim_macros_body: // начинаем цикл по строкам тела макроса --------------
//
  if( fgets(str, sizeof(str), fptrIn) == NULL ) // читаем строку из fptrIn
   goto enf_of_fptrIn; // выход из цикла while( 1 ) ============================
//
   if( str[0] == '}' ) // это конец тела макроса -------------------------------
   {
// тут была отладочная печать --------------------------------------------------
   }
   else // это ещё не конец тела for[]...
   {
    if(str[strlen(str)-1] == 10) // если в конце символ новой строки (10) в десятичной)...
     str[strlen(str)-1] = '\0';   // ... то заменим на КОНЕЦ СТРОКИ !
//
    DelSpacesTabsAround(str); // чистка строки str от лидирующих и терминирующих пробелов ...
//
    if( str[0] != startComments[0] && strlen( str ) ) // комментированные или пустые строки тела макроса не добавляем в PM
     mPM->Add( str ); // добавили в PM
    goto cont_withim_macros_body; // идём на считывание новой строки тела макроса
   }
//
enf_of_fptrIn: // конец входного файла fptrIn ----------------------------------
//
//  snprintf( tmp,sizeof(tmp), "// start preprocessor (PrP) the 1D-cycle \"for[%s]=%d,%d,%d\"\n", sIndex,minI,maxI,stepI );
//  fputs( tmp, fptrOut );  // пишем в fptrOut (файл инструкций после обработки препроцессором)
  fprintf( fptrOut, "%c%c start pre-prosessor (PrP) the 1D-cycle \"for[%s]=%d,%d,%d\"\n",
                    startComments[0],startComments[0], sIndex,minI,maxI,stepI );
//
  for( int iRow=0; iRow<mPM->Count; iRow++ ) // по всем строкам в PM
  {
//   fputs( "// ", fptrOut ); // строки до обработки препроцессором выдаются как комментируемые
//   fputs( mPM->Strings[iRow].c_str(), fptrOut );  // строка до расширенияя препроцессором
//   fputs( " / source line (before PreP)\n", fptrOut ); // fputs сама строку не переводит!
   fprintf( fptrOut, "%c%c %s %c source line (before PreP)\n", startComments[0],startComments[0],
                     mPM->Strings[iRow].c_str(), startComments[0] );
//
   for( int i=minI; i<=maxI; i+=stepI ) // для каждого значения параметра цикла
    PreProcRow_For1( iRow, sIndex, i ); // расширяем строку iRow тела макроса
//
  } // конец цикла while( 1 ) ==================================================
//
// ---- выводим преобразованные данные -----------------------------------------
//  snprintf( tmp,sizeof(tmp), "// end pre-prosessor (PrP) the 1D-cycle \"for[%s]=%d,%d,%d\"\n", sIndex,minI,maxI,stepI );
//  fputs( tmp, fptrOut );  // пишем в fptrOut (файл инструкций после обработки препроцессором)
  fprintf( fptrOut, "%c%c end pre-prosessor (PrP) the 1D-cycle \"for[%s]=%d,%d,%d\"\n",
                    startComments[0],startComments[0], sIndex,minI,maxI,stepI );
//
  mPM->Clear(); // очистить PM (TStringList) после обработки очередного макроса

////////////////////////////////////////////////////////////////////////////////
//
 } // конец цикла for( UI i=0; ; i++ ) по всем строкам инструкций в исходном файле
//
 fclose( fptrIn  ); // закрываем все открытые файлы
 fclose( fptrOut );

 return 0; // всё Ok

} // ===========================================================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall ParseAndCalculateIndex(char* Expression)
{ // парсеринг и вычисление выражения (без параметров) Expression
 char str[_128];
//
 try
 {
  parser.Compile( Expression ); // разборка выражения
  parser.Evaluate( 0.0 ); // значение использоваться не будет, но должно присутствовать
  strcpy( str, IntToStr( int( parser.GetResult() )).c_str() ); // возвращаем ВСЕГДА ЦЕЛОЕ в виде строки !!!
  return str;
 }
 catch(TError error)
 {
  if( flagAlarmParser ) // выдать предупреждение...
  {
   MessageBeep( MB_OK ); // звуковое предупреждение...
   snprintf( str,sizeof(str), "Препроцессор: проблема разборки выражения\n\n%s\n\nошибка %s в позиции %d", Expression, error.error, error.pos );
   MessageBox(0, str, "Ошибка !", MB_OK);
//
   flagAlarmParser = FALSE;
  } // и больше не выдавать..!
//
  startPos[0] = startComments[0]; // после ошибки все строки комментируются ";"
//
 } // конец catch( )
//
} // --- конец ParseAndCalculate -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::Show_Graph(TObject *Sender)
{ // показать график интенсивности вычислений
//
 if( Regim != 2 || // если программы не выполнилась корректно (защита от F6)
     parallel_Ticks <= 0 ) // время выполнения НЕ ПОЛОЖИТЕЛЬНОЕ
 {
  MessageBeep( MB_OK ); // звуковое предупреждение...
  return;
 }
//
 char str[_512];
//
 F2->Chart_IC->Title->Text->Clear(); // очистка TSting перед новым заполнением
 F2->Chart_IC->Title->Text->Add( "Зависимость показывает число одновременно выполняющихся" );
 F2->Chart_IC->Title->Text->Add( "операторов в функции времени (в тактах) выполнения программы" );
 F2->Chart_IC->Title->Text->Add( "" );
//
 F2->Chart_IC->Foot->Text->Clear(); // очистка TSting перед новым заполнением
 snprintf( str,sizeof(str), "параллельное вычисление: %d тактов, ускорение = %.*e", parallel_Ticks, ACC_REAL, 1.0 * serial_Ticks / parallel_Ticks );
 F2->Chart_IC->Foot->Text->Add( str );
//
 snprintf( str,sizeof(str), "всего задействовано %d штук/и АИУ из %d доступных", all_maxProcs, Max_Proc );
 F2->Chart_IC->Foot->Text->Add( str );
//
 snprintf( str,sizeof(str), "из них одновременно не более %d штук/и АИУ", simult_maxProcs );
 F2->Chart_IC->Foot->Text->Add( str );
//
 F2->Top  = F1->Top  + 40;
 F2->Left = F1->Left + 40;
//
 F2->Width  = 470; // чтобы помешался текст...
 F2->Height = 2 * F2->Width / 3 ;
//
 F2->Show(); // показать окно формы F2 в НЕМОДАЛЬНОМ режиме
//
 F2->Caption = " Функция интенсивности вычислений (программа ";
 F2->Caption = F2->Caption + AnsiUpperCase(FileNameSet) + ")"; // добавили имя файла программы
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::OnKeyPress_E_AIU(TObject *Sender, char &Key)
{ // вызывается при нажатии клавиши в E_AIU (ввод числа АИУ)
 if( !( isdigit( Key ) || Key == VK_BACK || Key == VK_ESCAPE ) )
 {
  Beep( 440, 100 ); // звуковое предупреждение...
  Beep( 880, 150 );
//  Beep( 2048, 100 );
  Key = NULL; // ничего кроме '0-9', BackSpace не пропускаем..!
 }
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Out_Data_SBM1()
{ // выводит данные в центральную часть StatusBar (все данные - ГЛОБАЛЫ) -------
 char tmp[_512];
//
 snprintf(tmp,sizeof(tmp), " АИУ/инстр./данн./буф./такт (страт.) = %d/%d/%d/%d/%d (%d|%d)",
                Max_Proc, Max_Instruction, Max_Data, Max_Buffer, F1->Master_Timer->Interval,
                How_Calc_Param, How_Calc_Prior);
 SBM1->Text=tmp;
} // ------ конец Out_Data_SBM1 ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall strReplace( char* dest, int num, const char* source, const char* orig, const char* rep )
{ // dest  - new string (dest), num - sizeof(dest)-1
//  source - source string for replace, orig - source substring, rep - dest substring
  const char* ptr;
  size_t len1 = strlen(orig);
  size_t len2 = strlen(rep);
  char*  tmp  = dest;

  num -= 1;

  while( (ptr = strstr(source, orig)) != NULL )
  {
   num -= (ptr - source) + len2;
   if( num < 1 )
     break;

   strncpy( dest, source, (size_t)(ptr - source) );
   dest += ptr - source;
   strncpy(dest, rep, len2);
   dest += len2;
   source  = ptr + len1;
  } // конец while

  for( ; (*dest = *source) && (num > 0); --num)
  {
   ++dest;
   ++source;
  }

  return tmp;

} //  --------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int __fastcall PreProcRow_For1(int iRow, char* sIndex, int iCycle)
{ // препроцессор для конвертации одной строки тела макроса одномерного массива
// здесь iRow - номер строки исходного тела макроса (из RM),
// sIndex - строка индекса одномерного массива, iCycle - номер цикла
 char str[_512], tmp[_256], dest[_256], w[_512], *p,
      *pStartSB, *pEndSB, // указатели на '[' и ']' (Start Square Brecket - End Square Brecket)
      work[_512]="\0", // работаем с внешней рабочей строкой (в ней будем НАКАПЛИВАТЬ) преобразованные части обрабатываемой строки
      buff[_512], // рабочий буффер для work
      ch[2] = "?\0";
 int  Start=0, i, // начиная с какого символа в str ищем [хххх]
      lenOld=strlen(sIndex);
//
 strcpy( str, mPM->Strings[iRow].c_str() ); // эту строку тела макроса будем конвертировать
//
 for( i=1; ; i++ ) // поиск всех вхождений шаблона [хххх]
 {
  if( p = strchr(str,startComments[0]) ) // если есть символ начала комментария (символ startComments[0])...
   str[ p-str ] = '\0'; // убираем комментарии вместе с этим символом..!
//
  pStartSB = strstr( &str[ Start ], "[\0" ); // p_Start указатель на символ '[' (ищем начиная с позиции Start)
  if( !pStartSB ) // не найдено p_Start - первого начиная с Start
   break; // цикл по j (внутренний)
//
  pEndSB = strstr( &str[ pStartSB-str ], "]\0" ); // p_End указатель на символ ']' (ищем начиная с последнего '[')
//
// итак, у нас '[' в позиции p_Start-Start и ']' в позиции p_End-Start ---------
// подстроку без с '[' и ']' копируем во временный буфер w ------------------
  strncpy( tmp, &str[ pStartSB+1-str ], pEndSB-pStartSB ); // на единицу больше - чтобы поместилось '\0'
  tmp[ pEndSB-pStartSB-1 ] = '\0'; // добавили '\0' - strncat часто работает некоррректно
//
// теперь можем заменить все вхождения sIndex на IntToStr(iCycle) в строке w ---
  strReplace( dest, sizeof(dest)-1, tmp, sIndex, IntToStr(iCycle).c_str() );
//
// вычислили выражение БЕЗ ПАРАМЕТРОВ в строке w -------------------------------
  strcpy( tmp, ParseAndCalculateIndex( dest ) );

// добавляем в work часть str от Start до p_Start (включая '[') ----------------
  strncat( work, &str[ Start ], pStartSB-str-Start + 1 ); // прибавим 1, чтобы поместился '\0'

// часть str от Start до первого символа слева от '[' прибавляем в work --------
  strcat( work, tmp );

// добавим ']', ибо его в w не заносили ----------------------------------------
  strcat( work, "]\0" );

// новый цикл ( i ) поиска '[...]' начинаем c символа номер Start в строке str
  Start = pEndSB - str + 1 ;
//
////////////////////////////////////////////////////////////////////////////////
 } // конец for( int i=1; ; i++ ) = цикл по числу вхождений '[...]'
//
 strcpy( str, work ); // заменим исходную строку для возврата
//
 DelSpacesTabsAround( str ); // чистка строки str от лидирующих и терминирующих пробелов ...
//
 strcpy( buff, str ); // запомнили str в буфере buff
//
////////////////////////////////////////////////////////////////////////////////
// обработка операнда команды SET ----------------------------------------------
////////////////////////////////////////////////////////////////////////////////
//
 strncpy( tmp, str, 3 ); // скопировали первые три символа str в tmp
 tmp[3] = '\0' ; // добавили конец строки после SET (иногда strncpy срабатывает некорректно)
//
 if( is_SET( strupr(tmp) ) ) // это инструкция SET..
 {
  strcpy( work, "SET " ); // начали готовить временную строку work
//
  p = strtok( str, " " ); // ищем входение первого пробела за SET
  p = strtok( NULL, ", " ); // ищем вхождение ',' после 1-го операнда
  strcpy( tmp, p ); // в tmp первый операнд SET

//  strcpy( str, mPM->Strings[iRow].c_str() ); // восстановим str после применения strtok
  strcpy( str, buff ); // восстановим str после применения strtok
//
  strReplace( dest, sizeof(dest)-1, tmp, sIndex, IntToStr(iCycle).c_str() ); // заменяем символ индекса его значением
  strcpy( tmp, ParseAndCalculateIndex( dest ) ); // вычисляем это значение
//
  strcat( work, tmp ); // добавили в work
  strcat( work, "," ); // добавили запятую и пробел
//
  strcpy( str, buff ); // восстановим str после применения strtok
//
  p = strtok( str, "," ); // ищем начало вхождение результата инструкции SET
//  p = strtok( NULL, "/; " ); // ищем конец вхождения инструкции SET (без комментариев)
//  strcpy( w, startComments_1 ); // в w "/"
//  strcat( w, startComments_2 ); // в w "/;"
  snprintf( w, sizeof(w), "%s%s", startComments,startComments ); // в w теперь ";;"
  p = strtok( NULL,  w ); // ищем конец вхождения инструкции SET (без комментариев)
//
  strcat( work, " " ); // пробел перед результатом операции SET
  strcat( work, p ); // адрес результата
//
  strcpy( str, work ); // всё готово - результат снова в str
//
 } // конец обработки инструкции SET -------------------------------------------
//
// fputs( startPos, fptrOut ); // при некорректности minI,maxI,stepI строки комментируются
// fputs( str, fptrOut ); // сохраняем расширенную строку макроса ( fputs строку не переводит! )
 fprintf( fptrOut, "%s%s %s line after PrP\n", startPos, str, startComments );
// fputs( " ; line after PrP\n", fptrOut );
//
 return 0; // всё Ok
//
} // --------- конец PreProcRow_For1 -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall is_ResultIsPredicat(char* str)
{ // возвращает TRUE, если str суть результат выполнения ПРЕДИКАРНОГО оператора
//
 for(UI i=0; i<Really_Set; i++) // по всем инструкциям в программе // (просмотр с конца к началу)
 {
  if( is_Predicat( Mem_Instruction[i].Set ) &&  // этот оператор - ПРЕДИКАТ ?
     !strcmp( Mem_Instruction[i].aResult,str ) ) // имя str совпадает с именем результата
   return TRUE;
//
 } // конец for(UI i...
//
  return FALSE;
//
} // ----- конец is_Predicat --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int __fastcall
Get_CountOperandsByInstruction(char *Set)
{ // определяет число входных операндов в инструкции с мнемоникой Set
 char tmp[_256];
//
 for(int i=0; i<Count_Sets; i++) // по списку инструкций ...
  if( !strcmp( Set_Params[i].Set, Set ) ) // это инструкция с мнемоникой Set
   return Set_Params[i].nInputOperands ;
//
// не нашли... информируем об этом !!! /////////////////////////////////////////
  t_printf( "-E- %s() не нашёл в Set_Params[] значения для инструкции %s. Ошибка (-13) -E-",
                   __FUNC__, Set);
//
  return (-13); // нет такой инструкции ...
//
} // ---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int __fastcall // определяет по Set_Params[] время выполнения инструкции с мнемоникой Set в тиках
Get_TicksByInstruction(char *Set)
{ // если мнемоники не найдено, возвращается 100 (тиков) .......................
 char tmp[_1024];
//
 for(int i=0; i<Count_Sets; i++) // ищем путем простого последовательного перебора
 {
  if( !strcmp( Set_Params[i].Set, Set ) )
// return Set_Params[i].Time
   return Set_Params[i].Time > 0 ? Set_Params[i].Time : 0 ; // return 0 при Set_Params[i].Time <= 0
 }
//
// не нашли... информируем об этом !!! /////////////////////////////////////////
  snprintf(tmp,sizeof(tmp), "- W - %s() не нашёл в Set_Params[] времени выполнения инструкции %s. Принято 100 тиков - W -",
                __FUNC__, Set);
  MessageBox(0, tmp, "Ошибка !", MB_OK);
  AddLineToProtocol(tmp);
//
  return ( 100 ); // ... default ...
} // ---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall is_Predicat(char* Set)
{  // возвращает  TRUE, если Set - мнемоника оператора-предикатора
//
 if ( !strcmp( Set, "PGE" ) || // оператор PGE
      !strcmp( Set, "PLE" ) || // ...
      !strcmp( Set, "PEQ" ) ||
      !strcmp( Set, "PNE" ) || // ...
      !strcmp( Set, "PGT" ) ||
      !strcmp( Set, "PLT" ) ||
      !strcmp( Set, "PNT" ) || // отрицание
      !strcmp( Set, "POR" ) || // OR (дизъюнкция) для двух предикатов
      !strcmp( Set, "PAN" ) || // AND (коньюнкция) для двух предикатов
      !strcmp( Set, "PIM" ) || // импликация, слЕдование двух предикатов
      !strcmp( Set, "PEV" ) || // эквиваленция двух предикатов
//
      !strcmp( Set, "PAP" ) || // стрелка Пирса двух предикатов
      !strcmp( Set, "PHS" ) || // штрих Шеффера двух предикатов
      !strcmp( Set, "PRM" ) || // обратная импликация двух предикатов
      !strcmp( Set, "PXR" ) )  // строгая дизъюнкция (исключающее ИЛИ) двух предикатов
//      !strcmp( Set, SET ) ) // это "SET"
  return TRUE;
 else
  return FALSE;
//
} // ------ конец is_Predicat -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Clear_AllCells()
{  // очищает все ячейки таблицы инструкций
//
 Really_Select = 0; // число ВЫДЕЛЕННЫХ ячеек - нулевое
 mI->Repaint(); // очистим предыдущее выделение...
//
} // ------ конец Clear_AllCells -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SelectColors(TObject *Sender)
{  // выбор цветов для индикации в таблице инструкций
 outGlobal = ((TComponent *)Sender)->Tag; // какой из вариантов MenuItem вызвал эту процедуру
//
 switch( outGlobal ) // выбор по значению outGlobal
 {
  case 11: CD_1->Color = DCT.clOperandOperation;
           if( CD_1->Execute() )
            DCT.clOperandOperation = CD_1->Color;
           break;
  case 12: CD_1->Color = DCT.clNonExecuted;
           if( CD_1->Execute() )
            DCT.clNonExecuted = CD_1->Color;
           break;
  case 13: CD_1->Color = DCT.clNonUsedResult;
           if( CD_1->Execute() )
            DCT.clNonUsedResult = CD_1->Color;
           break;
  case 14: CD_1->Color = DCT.clNonDefOperands;
           if( CD_1->Execute() )
            DCT.clNonDefOperands = CD_1->Color;
           break;
// =============================================================================
  case 21: CD_1->Color = DCE.clReadyOperand;
           if( CD_1->Execute() )
            DCE.clReadyOperand = CD_1->Color;
           break;
  case 22: CD_1->Color = DCE.clTruePredicat;
           if( CD_1->Execute() )
            DCE.clTruePredicat = CD_1->Color;
           break;
  case 23: CD_1->Color = DCE.clExecSet;
           if( CD_1->Execute() )
            DCE.clExecSet = CD_1->Color;
           break;
// =============================================================================
  case 31: CD_1->Color = DGR.clGraphStart;
           if( CD_1->Execute() )
            DGR.clGraphStart = CD_1->Color;
           break;
  case 32: CD_1->Color = DGR.clGraphEnd;
           if( CD_1->Execute() )
            DGR.clGraphEnd = CD_1->Color;
           break;
// =============================================================================
  default: break;
//
 } // конец switch
//
 Write_Config(); // сохранили изменения цветов
//
} //----------------------------------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::CD_1_Show(TObject *Sender)
{ // вызывается при отрисовке таблицы выбора цветов
//
 switch( outGlobal ) // выбор по значению outGlobal
 {
  case 11: SetWindowText( CD_1->Handle, "Выбор цвета ячеек информац. зависимостей ОПЕРАНДЫ <-> ОПЕРАТОРЫ" );
           break;
  case 12: SetWindowText( CD_1->Handle, "Выбор цвета ячеек НЕВЫПОЛНИВШИХСЯ операторов" );
           break;
  case 13: SetWindowText( CD_1->Handle, "Выбор цвета ячеек НЕИСПОЛЬЗОВАННЫХ результатов" );
           break;
  case 14: SetWindowText( CD_1->Handle, "Выбор цвета ячеек НЕОПРЕДЕЛЁННЫХ операндов" );
           break;
//
  case 21: SetWindowText( CD_1->Handle, "Выбор цвета ячеек ГОТОВЫХ операндов" );
           break;
  case 22: SetWindowText( CD_1->Handle, "Выбор цвета ячеек флагов предикатов в состоянии ИСТИНА" );
           break;
  case 23: SetWindowText( CD_1->Handle, "Выбор цвета ячеек ВЫПОЛНИВШИХСЯ операторов" );
           break;
//
  default: break;
 } // конец switch
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::F1_OnKeyUp(TObject *Sender, WORD &Key,
                                TShiftState Shift)
{ // вызывается при отпускании клавиш Ctrl+S на главной форме (останов счёта)
//
 if( Shift.Contains(ssCtrl) && ( Key == 'S' || Key == 's' ) )
  Stop_Calculations( Sender ); // остановить выполнение
//
 if( Shift.Contains(ssAlt) && Key == VK_F2 )
 {
//  Save_Select_Protocols( FALSE,FALSE, TRUE, FALSE,FALSE ); // сохранить данные
 }
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall
Finalize_Only_SET(int i_Set)
{ // выполнение инструкции SET номер i_Set
// предполагается, что это мгновенно (время учитывать не надо)..................
// инструкция SET выполняется НЕ ПРОЦЕССОРОМ, а ВХОДНЫМ коммуникатором !!!
 char Set[_SET_LEN],
      aResult[_ID_LEN],
      aPredicat[_ID_LEN], // поле предиката
      str[_4096], tmp[_512];
 bool s_isPredicat, // TRUE, если ВЫПОЛНИВШИЙСЯ оператор есть ПРЕДИКАТ
      isPredicat, // TRUE, если ЗАВИСИМЫЙ оператор ПРЕДИКАТ
      flagNot, // TRUE, если в ЗАВИСИМОМ операторе первый символ имени флага предиката "!" или "~"
      flagPredicat, // TRUE, если в имени ЗАВИСИМОГО оператора есть переменная (XXX или !XXX)
      flagPredicatTRUE; // TRUE, если в ЗАВИСИМОМ операторе флаг предиката TRUE (с учётом isNot)
//
 if( !Regim ) // не выполнять - закончить счет ---------------------------------
  return;
//
 REAL Result = StrToReal( Mem_Instruction[i_Set].aOp1, i_Set ); // запомнили значение 1-го операнда инструкции SET номер i_Set
 strcpy( aResult, Mem_Instruction[i_Set].aResult ); // строка-адрес результата выполненного оператора
//
 Mem_Instruction[i_Set].fOp1 = TRUE; // у SET всегда готов!...
//
 s_isPredicat = FALSE; // is_Predicat( Mem_Instruction[i_Set].Set ); // у SET всегда FALSE
//
////////////////////////////////////////////////////////////////////////////////
//
 Add_toData( i_Set, aResult, Result ); // добавим в Mem_Data[] и для визуализации
//
////////////////////////////////////////////////////////////////////////////////
//
// установим флаг единократного выполнения SET .................................
//
 Mem_Instruction[i_Set].fExecOut = TRUE; // установили флаг единичного выполнения
 mI->Cells[6][i_Set+1] = Vizu_Flags(i_Set); // визуализировали это в таблице SG_Sets
//
 t_printf( "-I- %s(){1}: инструкция #%d [%s] выполнена (%s) -I-",
                  __FUNC__, i_Set, Line_Set(i_Set, 1), Get_Time_asLine());
//
////////////////////////////////////////////////////////////////////////////////
// установим флаг ГОТОВ у ВСЕХ операндов, совпадающих по имени с адресом aResult в пуле инструкций Mem_Sets[i_set]
//
 strcpy(str, ""); // очистим str
//
////////////////////////////////////////////////////////////////////////////////
 for( ULI i=0; i<Really_Set; i++ ) // по всему пулу инструкций в Mem_Instruction[]
  {
   strcpy( Set, Mem_Instruction[i].Set ); // ... так удобнее для дальнейшей работы !
//
   if( is_SET( Set ) ) // это инструкция SET - не обрабатываем ! ---------------
    continue;
//
   strcpy( aPredicat, Mem_Instruction[i].aPredicat ); // будем работать с aPredicat, не изменяя Mem_Instruction[i].aPredicat
//
   isPredicat = is_Predicat( Set ); // TRUE, если ЗАВИСИМЫЙ оператор - ПРЕДИКАТ
//
//--- проверяем, начинается ли имя флага ПРЕДИКАТА с '!' или '~' ...............
   if ( !isPredicat ) // это инструкция - НЕ ПРЕДИКАТ...
    flagNot = ( aPredicat[0] == symbolNot_1 || aPredicat[0] == symbolNot_2 )
              ? TRUE : FALSE; // TRUE, если в поле aPredicat первый символ '!' или '~'
//
//--- проверяем, совпадает ли имя возврашённой переменной с именем -------------
//--- переменной в поле предиката ЗАВИСИМОЙ инструкции -------------------------
   flagPredicat = FALSE;  // начальная установка
   if( !isPredicat &&  // ЗАВИСИМАЯ инструкция - НЕ ПРЕДИКАТ
        strcmp( aPredicat, trueLowerCase  ) && // И это НЕ статический true
        strcmp( aPredicat, falseLowerCase ) )  // И это НЕ статический false
   {
    if( flagNot ) // имя флага предиката НАЧИНАЕТСЯ с '!' или '~'
     if( !strcmp( &aPredicat[1],aResult ) ) // начиная со второго символа...
      flagPredicat = TRUE;
//
    if( !flagNot ) // имя флага предиката  НЕ НАЧИНАЕТСЯ с '!' или '~'
     if( !strcmp( aPredicat,aResult ) )
      flagPredicat = TRUE;
   }
//
//--- теперь определяем значение Result на true или false и окончательно -------
//--- (с учётом статических true/false) устанавливаем flagPredicatTrue ---------
//
   flagPredicatTRUE = FALSE; // начальная установка
   if( flagPredicat ) // переменная-предиктор определена, но значение ещё неизвестно
    if( ( flagNot && !Result ) || // имя начинается с '!' или '~' и Result==FALSE
       ( !flagNot &&  Result ) ) // имя Не начинается с '!' или '~' и Result==TRUE
     flagPredicatTRUE = TRUE;
//
//--- отдельно обрабатываем статический true или false -------------------------
   if( !strcmp( aPredicat, trueLowerCase ) ) // если true...
    flagPredicatTRUE = TRUE;
   if( !strcmp( aPredicat, falseLowerCase ) ) // если false...
    flagPredicatTRUE = FALSE;
//
////////////////////////////////////////////////////////////////////////////////
//
   switch( Get_CountOperandsByInstruction( Set ) ) // ... число входных операндов инструкции Set
   {
    case 1: // ----- один операнд + (возможно) предикат ------------------------
// ----- обрабатываем случай, когда ЗАВИСИМЫЙ оператор - не предикат -----------
            if( !isPredicat ) // ... этот оператор - не предикат ...
            {
             if( MI_aOp1(i) ) // 1-й операнд ГОТОВ
             {
              MI_fOp1(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(1|1)", i); strcat(str, tmp); // флаг ГОТОВ у 1-го операнда
              snprintf(tmp,sizeof(tmp), " %d(*|1)", i); strcat(str, tmp); // флаг ГОТОВ у инструкции
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
//----- если это НЕ ПРЕДИКАТНАЯ инструкция, надо ещё проверить истинность поля ПРЕДИКАТА
            if( !flagPredicat &&
                flagPredicatTRUE ) // значение флага ПРЕДИКАТА
            {
//             Mem_Instruction[i].fPredicat = TRUE; // установили флаг ПРЕДИКТОР_ГОТОВ
             if( !Mem_Instruction[i].fPredicatTRUE ) // если не был установлен TRUE...
             {
              Mem_Instruction[i].fPredicatTRUE = TRUE; // установили флаг ПРЕДИКТОР_ИСТИНЕН
              snprintf(tmp,sizeof(tmp), " %d(PredTRUE|1)", i); strcat(str, tmp); // флаг TRUE предиктора
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
            }
//
            if( MI_fOp1(i) && // первый операнд ГОТОВ...
                flagPredicatTRUE ) // ... и флаг предикатора есть TRUE
             Add_toBuffer( i ); // добавить ГКВ-команду в буфер команд для исполнения
            } // конец if( !isPredicat )
//
// ----- обрабатываем случай, когда ЗАВИСИМЫЙ оператор суть предикат -----------
/* таких случаев теперь НЕТ.....................................................
            if( isPredicat ) // ... этот оператор - предикат ...
            {
             if( MI_aOp1(i) ) // 1-й операнд ГОТОВ
             {  // если был установлен TRUE - не надо ЗАНОВО ПЕРЕУСТАНАВЛИВАТЬ ..!
              MI_fOp1 = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(1|1)", i); strcat(str, tmp); // флаг ГОТОВ у 1-го операнда
              snprintf(tmp,sizeof(tmp), " %d(*|1)", i); strcat(str, tmp); // флаг ГОТОВ у инструкции
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_fOp1 ) // первый операнд предиката ГОТОВ... у предиката нет предиката
              Add_toBuffer( i ); // добавить ГКВ-команду в буфер команд для исполнения
            } // конец if( isPredicat )
//
// ---- добавляем в текст протокола --------------------------------------------
//
*/
            break; // конец обработки оператора с одним операндом + возможно, предиктор
////////////////////////////////////////////////////////////////////////////////
    case 2: // ----- два операнда + (возможно) предикат ------------------------
// ----- обрабатываем случай ЗАВИСИМОЙ инструкции - НЕ ПРЕДИКАТА ---------------
            if( !isPredicat ) // ... не предикат ...
            {
             if( MI_aOp1(i) ) // 1-й операнд ГОТОВ
             {
              MI_fOp1(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(1|2)", i); strcat(str, tmp); // флаг ГОТОВ у 1-го операнда
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_aOp2(i) ) // 2-й операнд ГОТОВ
             {
              MI_fOp2(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(2|2)", i); strcat(str, tmp); // флаг ГОТОВ у 2-го операнда
              if( MI_fOp1(i) &&
                  MI_fOp2(i) )
               { snprintf(tmp,sizeof(tmp), " %d(*|2)", i); strcat(str, tmp); } // флаг ГОТОВ у инструкции
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
//----- если эта инструкция-НЕ ПРЕДИКАТ, надо проверить флаг (и его значение) поля предиктора
            if( !flagPredicat && // это инструкция НЕ ПРЕДИКАТ
                flagPredicatTRUE ) // значение флага ПРЕДИКАТА
            {
//             Mem_Instruction[i].fPredicat = TRUE; // установили флаг ПРЕДИКТОР_ГОТОВ
             if( !Mem_Instruction[i].fPredicatTRUE ) // если не был установлен TRUE...
             { // если был установлен TRUE - не надо ЗАНОВО ПЕРЕУСТАНАВЛИВАТЬ ..!
              Mem_Instruction[i].fPredicatTRUE = TRUE; // установили флаг ПРЕДИКТОР_ИСТИНЕН
              snprintf(tmp,sizeof(tmp), " %d(PredTRUE|1)", i); strcat(str, tmp); // флаг TRUE предиктора
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
            }
//
             if( MI_fOp1(i) && // первый операнд ГОТОВ...
                 MI_fOp2(i) && // второй операнд ГОТОВ...
                 flagPredicatTRUE ) // ... и флаг предикатора есть TRUE
              Add_toBuffer(i); // добавить ГКВ-команду в буфер команд для исполнения
            } // конец if( !isPredictor )
//
// ----- обрабатываем случай ЗАВИСИМОЙ инструкции - ПРЕДИКАТА ------------------
//            else // так "КРАСИВШЕ" с точки зрения синтаксиса языка, но ЛОГИЧНЕЕ - см. след. строку...
            if( isPredicat ) // ... предикат ...
            {
             if( MI_aOp1(i) ) // 1-й операнд ГОТОВ
             {
              MI_fOp1(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(1|2)", i); strcat(str, tmp); // флаг ГОТОВ у 1-го операнда
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_aOp1(i) ) // 2-й операнд ГОТОВ
             {
              MI_fOp2(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(2|2)", i); strcat(str, tmp); // флаг ГОТОВ у 2-го операнда
//
              if( MI_fOp1(i)  &&
                  MI_fOp2(i) )
               { snprintf(tmp,sizeof(tmp), " %d(*|2)", i); strcat(str, tmp); } // флаг ГОТОВ у инструкции
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_fOp1(i) && // первый операнд ГОТОВ...
                 MI_fOp2(i) && // второй операнд ГОТОВ...
                 flagPredicatTRUE ) // ... и флаг предикатора есть TRUE
              Add_toBuffer(i); // добавить ГКВ-команду в буфер команд для исполнения
            } // конец if( isPredictor )
//
            break; // конец обработки оператора с двумя операндами + возможно, предикат
////////////////////////////////////////////////////////////////////////////////
   default: break;  // кроме 1 или 2 операнда у оператора...
//
   } // конец switch по числу операндов у i-того оператора ---------------------
//
  } // конец цикла по списку инструкций в Mem_Instruction[i] ...........................
////////////////////////////////////////////////////////////////////////////////
//
 Draw_ReadyOperands(); // выделение ячеек цветом (будет вызываться при выполнении каждого SET'a )
//
  if( strlen(str) ) // если в str что-то заносилось...
   t_printf( "-I- %s(){2}: по выполнению инструкции #%d установлены флаги готовности операндов у инструкций: %s -I-",
                    __FUNC__, i_Set, str);
//
////////////////////////////////////////////////////////////////////////////////
 Already_Exec ++ ; // число уже исполненных инструкций
//
 AttemptExecMaxInstructions_fromBuffer(); // пытаемся выполнить как можно больше ГКВ-инструкций из буфера
// для фактического выполнения инструкций из AttemptExecMaxInstructions_fromBuffer()
// вызывается ExecuteInstructions_ExceptET( i_Set )
//
 Vizu_Flow_Exec(); // визуализация процента исполненных инструкций
//
} // ----- конец Finalize_Only_SET ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::Save_All_Protocols(TObject *Sender)
{ // сохранение всех протоколов данного расчёта
 Save_Protocol_Master(); // сохраняем главный протокол (*.pro)
 Save_Protocol_AIU(); // сохраняем протокол использвания АИУ по времени (*.aiuAIU)
 Save_Protocol_Data(); // сохраняем протокол рассчитанных данных (*.dat)
 Save_Protocol_ExecInstructions(); // сохраняем протокол выполнения инструкций (*.tst)
 Save_Protocol_ConnectedGraph(); // сохраняем протокол свЯзности в информ.графе (*.coi)
//
 SBM0->Text = " Выбранные протоколы сохранены !.."; // вывод текста в StatusBarMain
 Delay(300); // ...чтобы увидеть!..
} // ---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::Save_Data(TObject *Sender)
{ // сохранить данные расчёта
 Save_Protocol_Data(); // сохраняем протокол рассчитанных данных (*.dat)
//
 SBM0->Text = " Выбранные протоколы сохранены !.."; // вывод текста в StatusBarMain
 Delay(300); // ...чтобы увидеть!..
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // вызывается для завершения выполнения инструкции на АИУ i_Proc
Finalize_Except_SET(int i_Proc) // все операци кроме SET !!!!!!!!!!!!!!!!!!!!!!!
{ // устанавливаются флаги готовности у входных операндов иных инструкций, зависящих
// по входным операндам от результата выполнения данной на АИУ номер i_Proc
 char Set[_SET_LEN],
      aResult[_ID_LEN],
      aPredicat[_ID_LEN], // поле предиката
      str[_4096], tmp[_256];
 bool s_isPredicat, // TRUE, если ВЫПОЛНИВШИЙСЯ оператор есть ПРЕДИКАТ
      isPredicat, // TRUE, если ЗАВИСИМЫЙ оператор ПРЕДИКАТ
      flagNot, // TRUE, если в ЗАВИСИМОМ операторе первый символ имени флага предиката "!" или "~"
      flagPredicat, // TRUE, если в имени ЗАВИСИМОГО оператора есть переменная (XXX или !XXX)
      flagPredicatTRUE; // TRUE, если в ЗАВИСИМОМ операторе флаг предиката TRUE (с учётом isNot)
//
 if( !Regim ) // не выполнять - закончить счет ---------------------------------
  return;
//
 int i_Set = Mem_Proc[i_Proc].i_Set; // на этом АИУ выполнялась инструкция номер i_Set
//
 REAL Result = Mem_Proc[i_Proc].Result; // значение результата выполненной операции
//
 strcpy( aResult, Mem_Proc[i_Proc].aResult ); // запомнили адрес результата выполнения инструкции i_Set_Result
//
 s_isPredicat = is_Predicat( Mem_Instruction[i_Set].Set ); // TRUE, если выполнившийся оператор суть ПРЕДИКАТ
//
 Add_toData( i_Set, Mem_Proc[i_Proc].aResult, Result ); // добавить результат выполнившейся инструкции
//
 t_printf( "-I- %s(){1}: АИУ номер %d выполнило инструкцию #%d [%s] [%d/%d/%d тактов] -I-",
                  __FUNC__, i_Proc, i_Set, Line_Set(i_Set, 1),
                  Mem_Proc[i_Proc].tick_Start, localTick, localTick - Mem_Proc[i_Proc].tick_Start);
//
 Vizu_Data(); // визуализировать...
//
////////////////////////////////////////////////////////////////////////////////
// добавили запись в набор строк Tpr для анализа загруженности АИУ...........
 snprintf(str,sizeof(str), "%10d%10d%10d%10d%10d [%s]",
               i_Proc,
               Mem_Proc[i_Proc].tick_Start, localTick, localTick - Mem_Proc[i_Proc].tick_Start,
               i_Set, Line_Set(i_Set, 1));
 mTpr->Add(str); // добавили строку
//
////////////////////////////////////////////////////////////////////////////////
//
 strcpy(str, ""); // очистим str
//
//==============================================================================
 for(UI i=0; i<Really_Set; i++) // по всем инструкциям из Mem_Instruction[] ============
  {
//
   if( i == i_Set ) // кроме только что выполненной.............................
    continue;
//
   strcpy( Set, Mem_Instruction[i].Set ); // ... так удобнее для дальнейшей работы !
   if( is_SET(Set) ) // инструкция SET уже давно едИножды выполнена !
    continue;
//
   strcpy( aPredicat, Mem_Instruction[i].aPredicat ); // будем работать с aPredicat, не изменяя Mem_Instruction[i].aPredicat
//
   isPredicat = is_Predicat( Set ); // TRUE, если это инструкция ПРЕДИКАТ
//
////////////////////////////////////////////////////////////////////////////////
//
//--- проверяем, начинается ли имя переменной предиктора с '!' или '~'
   if ( !isPredicat ) // это инструкция - НЕ предиктор
    flagNot = ( aPredicat[0] == symbolNot_1 || aPredicat[0] == symbolNot_2 )
                ? TRUE : FALSE; // TRUE, если в поле aPredicat первый символ '!' или '~'
//
//--- проверяем, совпадает ли имя возврашённой переменной с именем -------------
//--- переменной в поле предиктора i-той инструкции ----------------------------
   flagPredicat = FALSE;  // начальная установка
   if( !isPredicat &&  // это инструкция - НЕ предиктор
       strcmp( aPredicat, trueLowerCase  ) && // И это НЕ статический true
       strcmp( aPredicat, falseLowerCase ) )  // И это НЕ статический false
   {
    if( flagNot ) // имя начинается с '!' или '~'
     if( !strcmp( &aPredicat[1],aResult ) )  // начиная со второго символа...
      flagPredicat = TRUE;
//
    if( !flagNot ) // имя Не начинается с '!' или '~'
     if( !strcmp( aPredicat,aResult ) )
      flagPredicat = TRUE;
   }
//
//--- теперь определяем значение Result на true или false и окончательно -------
//--- (с учётом статических true/false) устанавливаем flagPredicatTrue ---------
//
   flagPredicatTRUE = FALSE; // начальная установка
   if( flagPredicat ) // переменная-предиктор определена, но значение ещё неизвестно
    if( ( flagNot  && !Result ) || // имя начинается с '!' или '~' и Result==FALSE
        ( !flagNot &&  Result ) ) // имя Не начинается с '!' или '~' и Result==TRUE
     flagPredicatTRUE = TRUE;
//
//--- отдельно обрабатываем статический true или false -------------------------
   if( !strcmp( aPredicat, trueLowerCase ) ) // если true...
    flagPredicatTRUE = TRUE;
   if( !strcmp( aPredicat,falseLowerCase ) ) // если false...
    flagPredicatTRUE = FALSE;
//
////////////////////////////////////////////////////////////////////////////////
//
   if(Mem_Instruction[i].fExec    || // если инструкция ВЫПОЛНЯЕТСЯ "или"
      Mem_Instruction[i].fExecOut || // уже ВЫПОЛНЕНА "или"
      Mem_Instruction[i].fAddBuffer) // уже ДОБАВЛЕНА В БУФЕР
    continue;
//
////////////////////////////////////////////////////////////////////////////////
//
   switch( Get_CountOperandsByInstruction( Set ) ) // !!! число входных операндов инструкции Set
   {
////////////////////////////////////////////////////////////////////////////////
    case 1: // ----- один операнд + (возможно) предикат ------------------------
////////////////////////////////////////////////////////////////////////////////
// ----- ВЫПОЛНИВШИЙСЯ оператор - НЕ ПРЕДИКАТ && ЗАВИСИМЫЙ оператор - НЕ ПРЕДИКАТ (1 операнд) ...
            if( !s_isPredicat && !isPredicat )
            {
             if( MI_aOp1(i) ) // 1-й операнд ГОТОВ
             {
              MI_fOp1(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(1|1)", i); strcat(str, tmp); // флаг ГОТОВ у 1-го операнда
              snprintf(tmp,sizeof(tmp), " %d(*|1)", i); strcat(str, tmp); // флаг ГОТОВ у инструкции
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
//----- если это НЕ ПРЕДИКАТНАЯ инструкция, надо ещё проверить истинность поля ПРЕДИКАТА
             if( !flagPredicat &&
                 flagPredicatTRUE ) // значение флага ПРЕДИКАТА
             {
//             Mem_Instruction[i].fPredicat = TRUE; // установили флаг ПРЕДИКТОР_ГОТОВ
              Mem_Instruction[i].fPredicatTRUE = TRUE; // установили флаг ПРЕДИКТОР_ИСТИНЕН
              snprintf(tmp,sizeof(tmp), " %d(PredTRUE|1)", i); strcat(str, tmp); // флаг TRUE у предиката
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_fOp1(i) && // первый операнд ГОТОВ...
                 flagPredicatTRUE ) // ... и флаг предикатора есть TRUE
              Add_toBuffer( i ); // добавить ГКВ-команду в буфер команд для исполнения
            } // конец if( !s_isPredicat && !isPredicat )
//
// ----- ВЫПОЛНИВШИЙСЯ оператор - ПРЕДИКАТ && ЗАВИСИМЫЙ оператор - НЕ ПРЕДИКАТ (1 операнд) ...
            if( s_isPredicat && !isPredicat )
            {
             if( flagPredicatTRUE )
              Mem_Instruction[i].fPredicatTRUE = TRUE; // установим  флаг предиката
//
             if( MI_fOp1(i) && // первый операнд ГОТОВ...
                 Mem_Instruction[i].fPredicatTRUE ) // ... и флаг-предикат есть TRUE
             {
              snprintf(tmp,sizeof(tmp), " %d(PredTRUE|1)", i); strcat(str, tmp); // флаг TRUE у предиката
              Add_toBuffer( i ); // добавить ГКВ-команду в буфер команд для исполнения
             }
//
            } // конец if( s_isPredicat && !isPredicat )
//
// ----- ВЫПОЛНИВШИЙСЯ оператор - НЕ ПРЕДИКАТ && ЗАВИСИМЫЙ оператор - НЕ ПРЕДИКАТ (1 операнд) ...
            if( !s_isPredicat && !isPredicat )
            {
//             if( MI_aOp1(i) ) // 1-й операнд ГОТОВ
//             {
//              Mem_Instruction[i].fOp1 = TRUE;
//              snprintf(tmp,sizeof(tmp), " %d(1|1)", i); strcat(str, tmp); // флаг ГОТОВ у 1-го операнда
//              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
//             }
//----- если эта инструкция-НЕ ПРЕДИКАТ, надо проверить флаг (и его значение) поля предиката
            if( !flagPredicat && // это инструкция НЕ ПРЕДИКАТ
                 flagPredicatTRUE ) // значение флага ПРЕДИКАТА
             {
              Mem_Instruction[i].fPredicatTRUE = TRUE; // установили флаг ПРЕДИКAТ_ИСТИНЕН
              snprintf(tmp,sizeof(tmp), " %d(PredTRUE|1)", i);
              strcat(str, tmp); // флаг TRUE предиката
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_fOp1(i) && // 1-й операнд ГОТОВ...
                 Mem_Instruction[i].fPredicatTRUE ) // ... и флаг предиката есть TRUE
              Add_toBuffer( i ); // добавить ГКВ-команду в буфер команд для исполнения
//
            } // конец if( !s_isPredicat && !isPredicat )
//
// ----- ВЫПОЛНИВШИЙСЯ оператор - ПРЕДИКАТ && ЗАВИСИМЫЙ оператор - ПРЕДИКАТ (1 операнд) ...
            if( s_isPredicat && isPredicat )
            {
             if( MI_aOp1(i) ) // 1-й операнд ГОТОВ
             {
              MI_fOp1(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(Pred 1|1)", i); strcat(str, tmp); // флаг ГОТОВ у 1-го операнда
              snprintf(tmp,sizeof(tmp), " %d(Pred *|1)", i); strcat(str, tmp); // флаг ГОТОВ у инструкции
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_fOp1(i) ) // 1-й операнд ГОТОВ...
              Add_toBuffer( i ); // добавить ГКВ-команду в буфер команд для исполнения
//
            }  // конец if( s_isPredicat && isPredicat )
//
////////////////////////////////////////////////////////////////////////////////
            break; // конец обработки оператора с одним операндом + возможно, предиктор
////////////////////////////////////////////////////////////////////////////////
    case 2: // ----- два операнда + (возможно) предикат ------------------------
////////////////////////////////////////////////////////////////////////////////
// ----- ВЫПОЛНИВШИЙСЯ оператор - НЕ ПРЕДИКАТ && ЗАВИСИМЫЙ оператор - НЕ ПРЕДИКАТ (2 операнда) ...
            if( !s_isPredicat && !isPredicat )
            {
             if( MI_aOp1(i) ) // 1-й операнд ГОТОВ
             {
              MI_fOp1(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(1|2)", i); strcat(str, tmp); // флаг ГОТОВ у 1-го операнда
//
              if( MI_fOp1(i) &&
                  MI_fOp2(i) )
               { snprintf(tmp,sizeof(tmp), " %d(*|2)", i); strcat(str, tmp); } // флаг ГОТОВ у инструкции
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_aOp2(i) ) // 2-й операнд ГОТОВ
             {
              MI_fOp2(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(2|2)", i); strcat(str, tmp); // флаг ГОТОВ у 2-го операнда
//
              if( MI_fOp1(i) &&
                  MI_fOp2(i) )
               { snprintf(tmp,sizeof(tmp), " %d(*|2)", i); strcat(str, tmp); } // флаг ГОТОВ у инструкции
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
//----- если эта инструкция-НЕ ПРЕДИКАТ, надо проверить флаг (и его значение) поля предиката
             if( !flagPredicat && // это инструкция НЕ ПРЕДИКАТ
                 flagPredicatTRUE ) // значение флага ПРЕДИКАТА
             {
              Mem_Instruction[i].fPredicatTRUE = TRUE; // установили флаг ПРЕДИКAТ_ИСТИНЕН
              snprintf(tmp,sizeof(tmp), " %d(PredTRUE|2)", i); strcat(str, tmp); // флаг TRUE предиката
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_fOp1(i) && // первый операнд ГОТОВ...
                 MI_fOp2(i) && // второй операнд ГОТОВ...
                 Mem_Instruction[i].fPredicatTRUE ) // ... и флаг предиката есть TRUE
              Add_toBuffer( i ); // добавить ГКВ-команду в буфер команд для исполнения
//
            } // конец if( !s_isPredicat && !isPredicat )
//
// ----- ВЫПОЛНИВШИЙСЯ оператор - НЕ ПРЕДИКАТ && ЗАВИСИМЫЙ оператор - ПРЕДИКАТ (2 операнда) ...
            if( !s_isPredicat && isPredicat )
            {
             if( MI_aOp1(i) ) // 1-й операнд ГОТОВ
             {
              MI_fOp1(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(1|1)", i); strcat(str, tmp); // флаг ГОТОВ у 1-го операнда
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_aOp2(i) ) // 2-й операнд ГОТОВ
             {
              MI_fOp2(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(2|2)", i); strcat(str, tmp); // флаг ГОТОВ у 2-го операнда
//
              if( MI_fOp1(i) &&
                  MI_fOp2(i) )
               { snprintf(tmp,sizeof(tmp), " %d(*|2)", i); strcat(str, tmp); } // флаг ГОТОВ у инструкции
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_fOp1(i) && // первый операнд предиката ГОТОВ... у предиката нет предиката
                 MI_fOp1(i) )  // второй операнд ГОТОВ...
              Add_toBuffer( i ); // добавить ГКВ-команду в буфер команд для исполнения
            } // конец if( !s_isPredicat && isPredicat )
//
// ----- ВЫПОЛНИВШИЙСЯ оператор - ПРЕДИКАТ && ЗАВИСИМЫЙ оператор - НЕ ПРЕДИКАТ (2 операнда) ...
            if( s_isPredicat && !isPredicat )
            {
             if( flagPredicatTRUE )
              Mem_Instruction[i].fPredicatTRUE = TRUE; // установим  флаг предиката
//
             if( MI_fOp1(i) && // первый операнд ГОТОВ...
                 MI_fOp2(i) && // второй операнд ГОТОВ...
                 Mem_Instruction[i].fPredicatTRUE ) // ... и флаг предиката есть TRUE
             {
              snprintf(tmp,sizeof(tmp), " %d(PredTRUE|2)", i); strcat(str, tmp); // флаг TRUE у предиката
              Add_toBuffer( i ); // добавить ГКВ-команду в буфер команд для исполнения
             }
//
            } // конец if( s_isPredicat && !isPredicat )
//
// ----- ВЫПОЛНИВШИЙСЯ оператор - не ПРЕДИКАТ && ЗАВИСИМЫЙ оператор - ПРЕДИКАТ (2 операнда) ...
            if( !s_isPredicat && isPredicat )
            {
             if( MI_aOp1(i) ) // 1-й операнд ГОТОВ
             {
              MI_fOp1(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(1|2)", i); strcat(str, tmp); // флаг ГОТОВ у 1-го операнда
//
              if( MI_fOp1(i) &&
                  MI_fOp2(i) )
               { snprintf(tmp,sizeof(tmp), " %d(*|2)", i); strcat(str, tmp); } // флаг ГОТОВ у инструкции
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_aOp2(i) ) // 2-й операнд ГОТОВ
             {
              MI_fOp2(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(2|2)", i); strcat(str, tmp); // флаг ГОТОВ у 2-го операнда
//
              if( MI_fOp1(i) &&
                  MI_fOp2(i) )
               { snprintf(tmp,sizeof(tmp), " %d(*|2)", i); strcat(str, tmp); } // флаг ГОТОВ у инструкции
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_fOp1(i) && // первый операнд ГОТОВ...
                 MI_fOp2(i) )  // второй операнд ГОТОВ...
              Add_toBuffer( i ); // добавить ГКВ-команду в буфер команд для исполнения
//
            } // конец if( !s_isPredicat && isPredicat )
//
// ----- ВЫПОЛНИВШИЙСЯ оператор - ПРЕДИКАТ && ЗАВИСИМЫЙ оператор - ПРЕДИКАТ (2 операнда) ...
            if( s_isPredicat && isPredicat )
            {
             if( MI_aOp1(i) ) // 1-й операнд ГОТОВ
             {
              MI_fOp1(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(Pred 1|2)", i); strcat(str, tmp); // флаг ГОТОВ у 1-го операнда
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_aOp2(i) ) // 2-й операнд ГОТОВ
             {
              MI_fOp2(i) = TRUE;
              snprintf(tmp,sizeof(tmp), " %d(Pred 2|2)", i); strcat(str, tmp); // флаг ГОТОВ у 2-го операнда
              mI->Cells[6][i+1] = Vizu_Flags(i); // визуализировали ФЛАГИ данной инструкции
             }
//
             if( MI_fOp1(i) && // 1-й операнд ГОТОВ...
                 MI_fOp2(i) ) // и 2-й операнд ГОТОВ!
             {
              snprintf(tmp,sizeof(tmp), " %d(Pred *|2)", i); strcat(str, tmp); // готов весь оператор !..
              Add_toBuffer( i ); // добавить ГКВ-команду в буфер команд для исполнения
             }
//
            }  // конец if( s_isPredicat && isPredicat )
//
////////////////////////////////////////////////////////////////////////////////
            break; // конец обработки оператора с двумя операндами + возможно, предикат
////////////////////////////////////////////////////////////////////////////////
   default: break; // кроме 1 или 2 операнда у оператора...
//
   } // конец switch по числу операндов у i-того оператора ---------------------
//
////////////////////////////////////////////////////////////////////////////////
  } // конец цикла по пулу инструкций ..........................................
////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
//
 if(strlen(str)) // если в str что-то записывалось...
 {
  t_printf( "-I- %s(){2}: по выполнению инструкции #%d/%d установлены флаги готовности операндов у инструкций: %s -I-",
                   __FUNC__, i_Set, i_Proc, str);
 }
//
////////////////////////////////////////////////////////////////////////////////
// устанавливаем флаг однократного выполнения инструкции .......................
 Mem_Instruction[i_Set].fExecOut = TRUE; // установили флаг ИНСТРУКЦИЯ_ИСПОЛЬЗОВАНА
// снимаем флаг ИНСТРУКЦИЯ_ВЫПОЛНЯЕТСЯ
 Mem_Instruction[i_Set].fExec    = FALSE; // сняли флаг ИНСТРУКЦИЯ_ВЫПОЛНЯЕТСЯ
////////////////////////////////////////////////////////////////////////////////
 mI->Cells[6][i_Set+1] = Vizu_Flags(i_Set); // визуализировать...
////////////////////////////////////////////////////////////////////////////////
 Draw_ReadyOperands(); // выделение ячеек цветом
////////////////////////////////////////////////////////////////////////////////
//
 Mem_Proc[i_Proc].Busy = FALSE; // АИУ номер i_Proc теперь СВОБОДНО !!!
//
 t_printf( "-I- %s(){3}: АИУ номер %d освобождено (%s) после выполнения инструкции #%d -I-",
                  __FUNC__, i_Proc, Get_Time_asLine(), i_Set);
//
 Free_Proc ++ ; // число свободных АИУ увеличили на 1 ==========================
//
////////////////////////////////////////////////////////////////////////////////
 sleep_for_vizu_buffer // ждем-с для визуализации буфера
////////////////////////////////////////////////////////////////////////////////
 AttemptExecMaxInstructions_fromBuffer(); // пытаемся выполнить как можно больше ГКВ-инструкций из буфера
// для фактического выполнения инструкций из AttemptExecMaxInstructions_fromBuffer()
// вызывается ExecuteInstructions_ExceptET( i_Set )
////////////////////////////////////////////////////////////////////////////////
 sleep_for_vizu_buffer // визуализируем буфер...
////////////////////////////////////////////////////////////////////////////////
//
 Already_Exec ++ ; // число уже испОлненных инструкций
//
 Vizu_Flow_Exec(); // визуализация процента исполненных инструкций
//
} // --- конец Finalize_Except_SET ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int __fastcall Work_TimeSets_Protocol_IC()
{ // вычисляется и возвращается max число ОДНОВРЕМЕННО работающих АИУ (процессоров)
// и заполняется серия данных для постройки графика интенсивности вычислений
 char tmp[_512],  tmp1[_512],
      tmp2[_512], w[_512];
 INT tick_End, // конец времени последней выполненной инструкции (в тактах)
     tick_1, tick_2, // начало и конец выполнения данной инструкции (в тактах)
     n_i, // число выполняемых инструкций в момент времени
     n_proc, // номер АИУ
     n_set,  // номер инструкции
     simult_Max_Proc = 0, // максимальное ОДНОВРЕМЕННО работающее число АИУ (процессоров)
     i_tick; // надо..!
//
////////////////////////////////////////////////////////////////////////////////
 F2->Series1->Clear(); // очистим серию данных для графика интенсивности вычислений
////////////////////////////////////////////////////////////////////////////////
 if(! mTpr || // если этот TStringList-список не существует... "ИЛИ"
    ! mTpr->Count) // если число строк = 0 ...
  goto ended;
//
 strcpy(tmp,  mTpr->Strings[mTpr->Count-1].c_str()); // последняя строка таблицы в Tpr
 strcpy(tmp1, GetSubString(tmp, 21,30)); // время конца выполнения последней инструкции
 tick_End = atoi ( tmp1 ); // конец всех вычислений ( в тактах )
//
 for( i_tick=0; i_tick<=tick_End; i_tick++ ) // по всем тактам программы
 {
  APM // дать поработать Windows -----------------------------------------------
//
  if( i_tick % tick_ScanForGraph ) // ВЫДАВАТЬ каждые tick_ScanForGraph (global) тактов
   continue;
//
  if( !(i_tick % 100 ) ) // если i кратно 100
  {
   sprintf( w, " Обработка данных для оценки работы АИУ (%.0f%%)...", 1e2*i_tick/tick_End);
   SBM0->Text = w;
  }
//
  n_i = 0; // число выполняемых инструкций в момент времени времени t_i
//
// начало тела вычислений для каждой из mTpr->Count инструкций ...............
////////////////////////////////////////////////////////////////////////////////
  for( ULI i=0; i<mTpr->Count; i++ ) // по таблице выполненных инструкций в Tpr
  {
   APM // дать поработать Windows -----------------------------------------------
//
   n_proc = _atoi64(GetSubString(mTpr->Strings[i].c_str(),  1,10)); // номер АИУ, на котором инструкция выполнялась
   n_set  = _atoi64(GetSubString(mTpr->Strings[i].c_str(), 41,50)); // номер выполненной инструкции
   tick_1 = _atoi64(GetSubString(mTpr->Strings[i].c_str(), 11,20)); // время НАЧАЛА выполнения инструкции (в тактах)
   tick_2 = _atoi64(GetSubString(mTpr->Strings[i].c_str(), 21,30)); // время КОНЦА выполнения инструкции (в тактах)
//
// анализируем число работающих АИУ в промежутке [ (tick_1) - (tick_2) ] .......
   if( (i_tick >= tick_1) && (i_tick < tick_2) ) // момент (i_tick) находится между (tick_1) и (tick_2)
   {
    n_i ++ ; // число выполняемых инструкций в момент времени времени tick_i
    simult_Max_Proc = max( simult_Max_Proc, n_i ); // максимальное ОДНОВРЕМЕННО работающее число АИУ
   } // конец  if( (i_tick >= tick_1) && (i_tick < tick_2) )
//
  } // конец цикла по строкам Tpr
////////////////////////////////////////////////////////////////////////////////
// дополняем массив Series1 ----------------------------------------------------
//  if( flagGraph ) // если не было серьёзных ошибок при выполнении...
  F2->Series1->Add( n_i, i_tick, RGB( GetRValue(DGR.clGraphStart) + 1.0 * i_tick / parallel_Ticks * (GetRValue(DGR.clGraphEnd) - GetRValue(DGR.clGraphStart)) ,
                                      GetGValue(DGR.clGraphStart) + 1.0 * i_tick / parallel_Ticks * (GetGValue(DGR.clGraphEnd) - GetGValue(DGR.clGraphStart)) ,
                                      GetBValue(DGR.clGraphStart) + 1.0 * i_tick / parallel_Ticks * (GetBValue(DGR.clGraphEnd) - GetBValue(DGR.clGraphStart)) ) ) ;
//
////////////////////////////////////////////////////////////////////////////////
//
  } // конец цикла по всем тактам i_tick программы
//
// ----- добавляем точку x=i_tick-1,y=0 для корректного масштабирования оси ординат на графике
  F2->Series1->Add( 0, --i_tick, DGR.clGraphEnd ) ;
//
ended: /////////////////////////////////////////////////////////////////////////
//
 return simult_Max_Proc ; // максимальное ОДНОВРЕМЕННО работающее число АИУ
//
} // ------- конец процедуры Work_TimeSets_Protocol ----------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Save_Protocol_Master()
{ // сохранение ГЛАВНОГО_ПРОТОКОЛА выполнения задания (*.pro)
 char FileNameProtocol[_512]; // файл протокола '*.pro'
//
////////////////////////////////////////////////////////////////////////////////
// сохраняем ГЛАВНЫЙ_ПРОТОКОЛ (*.pro) //////////////////////////////////////////
//
 if( !mR->Lines->Count ) // если число записей 0...
  return;
//
 SBM0->Text = " Сохраняется протокол расчета (PRO-файл)..."; // вывод текста в StatusBarMain
 Delay(100); // чтобы успеть увидеть...
//
 strcpy( FileNameProtocol, ChangeFileExt(FileNameSet, ".pro").c_str() );  // путь к PRO-файлу
 mR->Lines->SaveToFile( FileNameProtocol ); // сохранили файл протокола
//
} // ----- конец функции Save_Protocol -----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Save_Protocol_AIU()
{ // сохранение протокола использования АИУ (*.tpr)
 char FileNameTimeProc[_512]; // файл протокола использования АИУ '*.tpr'
//
 if( ! mTpr || // если этот TStringList-список не существует...
     ! mTpr->Count ) // если нет строк...
  return;
//
 SBM0->Text = " Сохраняется протокол использования АИУ (TPR-файл)..."; // вывод текста в StatusBarMain
 Delay(100); // чтобы успеть увидеть...
//
 strcpy( FileNameTimeProc, ChangeFileExt(FileNameSet, ".tpr").c_str() ); // путь к TPR-файлу
//
 mTpr->SaveToFile( FileNameTimeProc );
//
} // ----- конец функции Save_Protocol_AIU -------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Save_Protocol_Data()
{ // сохранение файла рассчитанных данных (*.dat)
 char FileNameData[_512], // файл рассчитанных данных '*.dat'
      tmp[_512];
//
 FILE *fptr;
////////////////////////////////////////////////////////////////////////////////
// сохраняем ПРОТОКОЛ_ПАМЯТИ_ДАННЫХ (*.dat) ////////////////////////////////////
//
 if( !Really_Data ) // если данных нет...
  return;
//
 strcpy( FileNameData, ChangeFileExt(FileNameSet, ".dat").c_str() ); // путь к DAT-файлу
 if( !(fptr = fopen(FileNameData, "w")) ) // файл не открылся...
  return;
//
 SBM0->Text = " Сохраняется протокол данных расчета (DAT-файл).."; // вывод текста в StatusBarMain
 Delay(100); // чтобы успеть увидеть...
//
 for( ULI i=0; i<Really_Data; i++ ) // по всем Mem_Data[i]
 {
  snprintf( tmp,sizeof(tmp), "#%d [%s]", Mem_Data[i].i_Set, Line_Set(Mem_Data[i].i_Set, -1) ); // в результате какой команды определилось данное значение..?
//
  if( is_ResultIsPredicat( Mem_Data[i].Addr ) ) // это результат выполнения инструкции-ПРЕДИКАТОРА...
   fprintf( fptr, "%20s%20s     %s\n", Mem_Data[i].Addr, Mem_Data[i].Data ? trueLowerCase : falseLowerCase, tmp );
  else
   fprintf( fptr, "%20s%20.5e     %s\n", Mem_Data[i].Addr, Mem_Data[i].Data, tmp );
//
 } // конец цикла for( ULI i=0; i<Really_Data; i++ )
//
 fclose( fptr ); // закрыли файл
//
} // ----- конец функции Save_Data ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Save_Protocol_ExecInstructions()
{ // сохранение протокола выполнения инструкций по времени (*.tst)
 char FileNameTimeSets[_512], // файл протокола выполнений инструкций АИУ '*.tst'
//      tmp[_512],  tmp1[_512],
      tmp2[_512], tmp3[_2048]; // при ГКВ=99 длина ~1200 символов
 INT tick_End, // конец времени последней выполненной инструкции (в тактах)
     tick_1, tick_2, // начало и конец выполнения данной инструкции (в тактах)
     n_i, // число выполняемых инструкций в момент времени времени
     n_proc, // номер АИУ
     n_set;  // номер инструкции
//
 FILE *fptr;
//
////////////////////////////////////////////////////////////////////////////////
// сохраняем ПРОТОКОЛ_ВЫПОЛНЕНИЯ_ИНСТРУКЦИЙ (*.tst) ////////////////////////////
//
 if( ! mTpr || // если этот TStringList-список не существует... "ИЛИ"
     ! mTpr->Count ) // если число строк = 0 ...
  return;
//
  strcpy( FileNameTimeSets, ChangeFileExt(FileNameSet, ".tst").c_str() ); // путь к TST-файлу
  if( !(fptr = fopen(FileNameTimeSets, "w")) ) // файл не открылся...
   return;
//
  SBM0->Text = " Сохраняется протокол выполнения инструкций (TST-файл)..."; // вывод текста в StatusBarMain
  Delay(100); // чтобы успеть увидеть...
//
  tick_End = _atoi64(GetSubString(mTpr->Strings[mTpr->Count-1].c_str(), 21,30)); // конец всех вычислений ( в тактах )
//
  for( ULI i_tick=0; i_tick<=tick_End; i_tick++ ) // по всем тактам программы
  {
   if( i_tick % tick_ScanForGraph ) // ВЫДАВАТЬ каждые tick_ScanForGraph тактов
    continue;
//
   n_i = 0; // число выполняемых инструкций в момент времени времени t_i
   strcpy(tmp3, ""); // очистили tmp3
//
// начало тела вычислений для каждой из Tpr (0-n_Tpr) инструкций .........
////////////////////////////////////////////////////////////////////////////////
   for( ULI i=0; i<mTpr->Count; i++ ) // по строкам выполненных инструкций в Tpr
   {
    n_proc = _atoi64(GetSubString(mTpr->Strings[i].c_str(),  1,10)); // номер АИУ, на котором инструкция выполнялась
    n_set =  _atoi64(GetSubString(mTpr->Strings[i].c_str(), 41,50));  // номер выполненной инструкции
    tick_1 = _atoi64(GetSubString(mTpr->Strings[i].c_str(), 11,20) ); // время НАЧАЛА выполнения инструкции (в тактах)
    tick_2 = _atoi64(GetSubString(mTpr->Strings[i].c_str(), 21,30)); // время КОНЦА выполнения инструкции (в тактах)
//
// анализируем число работающих АИУ в промежутке [ (tick_1) - (tick_2) ] .......
    if( (i_tick >= tick_1) && (i_tick < tick_2) ) // момент (i_tick) находится между (tick_1) и (tick_2)
    {
     n_i ++ ; // число выполняемых инструкций в момент времени времени tick_i
//
     snprintf( tmp2,sizeof(tmp2), "%d/%d/%s  ", n_proc, n_set, Mem_Instruction[n_set].Set );
     strcat( tmp3, tmp2 ); // накапливаем 'АИУ/Номер_инстр/Мнемоника'
//
     if( strlen(tmp3) > 0.7 * sizeof(tmp3) ) // чтобы tmp3 не переполнялось..!
      strcpy( tmp3, " (...) " );
    } // конец if( (i_tick >= tick_1) && (i_tick < tick_2) ) // момент (i_tick) находится между (tick_1) и (tick_2)
//
   } // конец for( ULI i=0; i<mTpr->Count; i++ ) // по строкам выполненных инструкций в Tpr
////////////////////////////////////////////////////////////////////////////////
  fprintf(fptr, "%10ld%10d     %s\n", i_tick, n_i, tmp3);
//
  } // конец for( ULI i_tick=0; i_tick<=tick_End; i_tick++ ) // по всем тактам программы
//
 fclose( fptr ); // закрыли файл
//
} // ----- конец функции Save_ExecInsrucrions ----------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Save_Protocol_ConnectedGraph()
{ // сохранение протокола свЯзности графа (*.coi)
 char tmp[_512],  tmp1[_512],
      tmp2[_512], tmp3[_2048]; // при ГКВ=99 длина ~1200 символов
 ULI tick_End, // конец времени последней выполненной инструкции (в тактах)
     tick_1, tick_2, // начало и конец выполнения данной инструкции (в тактах)
     n_i, // число выполняемых инструкций в момент времени времени
     n_proc, // номер АИУ
     n_set;  // номер инструкции
// FILE *fptr;
//
// сохраняем ПРОТОКОЛ_АНАЛИЗА_СВЯЗНОСТИ_ГРАФА_ПРОГРАММЫ (*.coi) ////////////////
//
 SBM0->Text = " Сохраняется протокол анализа связности графа программы (COI-файл)...";
 Delay(100); // чтобы успеть увидеть...
//
 Calc_ConnectedIndex( 1 ); // подсчет ИНДЕКСОВ СВяЗНОСТИ c сохранением в файл
//
} // ----- конец функции Save_Protocol_ConnectedGraph --------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall AddLineToProtocol(char *str)
{ // добавляет строку str в окно текстового представлЕния данных (учитывается "\n")
 char c, cc[2] = "?\0", buf[_16384] = "\0"; // buf - "рабочая" строка для вывода
//
 for(int Pos=0; Pos<=strlen(str); Pos++) // Pos - номер символа в строке str
 {
  c = str[Pos]; // прочитали Pos-й символ строки str
//
  if ( (c!='\n') && (c!='\0') ) // это не UPR-символ (управляющий) и не конец строки
  {
   cc[0] = c;
   strcat( buf, cc ); // добавляем символ с в buf
  } // конец if( c != UPR )
//
  else
//  if( (c=='\n') || (c=='\0') ) // управляющий символ или конец строки
  {
   F1->M1->Lines->Add( buf ); // вывод строки buf в M1
   strcpy( buf, "" ); // очистили строку w для дальнейшей работы
  }
//
 } // конец по символам строки str
//
 return TRUE ; // для Lua всегда надо что-то возвратить (void не допускается!)
//
} // --- конец c_AddLineToProtocol ----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SG_Data_Info(TObject *Sender, TMouseButton Button,
                                      TShiftState Shift, int X, int Y)
{ // щелчок левой кнопкой мыши на SG_Data - вывод в MessageBox -----------------
 char str[_512];
//
 if( !strlen( Mem_Data[SG_Data->Row-1].Addr ) ) // строка пустая !..
  return;
//
 if( is_ResultIsPredicat( Mem_Data[SG_Data->Row-1].Addr ) ) // это результат выполнения инструкции-ПРЕДИКАТА...
  snprintf( str,sizeof(str), "     %s = %s", Mem_Data[SG_Data->Row-1].Addr, Mem_Data[SG_Data->Row-1].Data ? trueLowerCase : falseLowerCase );
 else
  snprintf( str,sizeof(str), "     %s = %.10e", Mem_Data[SG_Data->Row-1].Addr, Mem_Data[SG_Data->Row-1].Data );
//
 MessageBox(0, str," Значение переменной в памяти данных", MB_OK | MB_ICONINFORMATION | MB_TOPMOST | MB_TASKMODAL ); // МОДаЛЬНОЕ окно ..!
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::M1_ClearAll(TObject *Sender)
{ // очистить M1
 M1->Clear(); // полностью очистить M1 (TMemo)
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::M1_CopyAll(TObject *Sender)
{ // копировать M1 в ClipBoard
// Clipboard->AsText = M1->Text.
 M1->SelectAll(); // выделить весь текст в M1
 M1->CopyToClipboard(); // копировать всё из M1 в Clipboard
 M1->SelLength = 0; // снять выделение
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::M1_CopyToNotepad(TObject *Sender)
{ // копировать M1 в Notepad
 char FileName[_256];
 strcpy( FileName, ChangeFileExt( FileNameSet, ".txt" ).c_str()); // имя проекта + "txt"
 M1->Lines->SaveToFile( FileName ); // выдать все строки из M1 в файл FileName
 ShellExecute( Handle, "open", FileName, NULL, NULL, SW_RESTORE ); // открыть файл FileName
//
 sleep( 1 ); // #include <dos.h>
//
 DeleteFile( FileName ); // уничтожить (временный) файл
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::Save_IGA_Click(TObject *Sender)
{ // сохранить программу в виде информационного графа алгоритма (ИГА) - списка дуг
 Save_IGA(); // сохранение GV-файла
} //----- конец TF1::Save_IGA_Click --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Save_IGA()
{ // сохранить программу в виде списка дуг (формат *.GV)
 INT i,j, nArg, fromOp, iEdge = 0; // номер дуги в ИГА
 TStringList *sIGA = new TStringList(); // массив строк для запоминания ИГА
 char FileName[_256], tmp[_2048],
      aResult[_ID_LEN], aPredicat[_ID_LEN];
 bool flagNot, flagPredicat;
//
// сохраняем ИНФОРМАЦИОННЫЙ_ГРАФ_ПРОГРАММЫ (*.gv) //////////////////////////////
//
 SBM0->Text = " Сохраняется информационный граф программы (GV-файл)...";
 Delay(100); // чтобы успеть увидеть...
//
 strcpy( FileName, FileNameSet ); // имя файла дуг
 strcpy( FileName, ChangeFileExt( FileName, ExtIGA ).c_str()); // ".gv" рекомендует стандарт, ибо ".dot" задействовано в Word'е
//
 snprintf(tmp,sizeof(tmp), "#\n// Valery Bakanov research computer complex (2008 and further); e881e@mail.ru, http://vbakanov.ru/left_1.htm" );
 sIGA->Add( tmp ); // добавить строку комментария
//
 snprintf(tmp,sizeof(tmp), "\/* This file was automatically created thru program DATA_FLOW.EXE\n   from the original data file %s \*/\n#",
          AnsiUpperCase(ExtractFileName(FileNameSet) ) );
 sIGA->Add( tmp ); // добавить строку комментария
//
 snprintf(tmp,sizeof(tmp), "digraph %s {", AnsiUpperCase(ChangeFileExt(ExtractFileName(FileNameSet),"")) );
// ChangeFileExt(ExtractFileName(FileName),'')
 sIGA->Add( tmp ); // добавить cтроку начала описания графа
//
// === ищем ДУГИ (информационные зависимости) в алгоритме ----------------------
// опервтор ОТКУДА - это i-й оператор (поле aResult) ---------------------------
// оператор КУДА - это j-й оператор (поле aOp1 или aOp2) -----------------------
 for(i=0; i<Really_Set; i++) // по всем инcтрукциям (операторам) - это ОТКУДА
 {
  strcpy( aResult, Mem_Instruction[i].aResult ); // запомнили...
//
// внутренний цикл (инструкцию [i] сравниваем с инструкцией [j] ----------------
  for(j=0; j<Really_Set; j++) // по всем инcтрукциям (операторам) - это КУДА
  {
   if( is_SET( Mem_Instruction[j].Set ) || // c КУДА (SET) не сравниваем (ибо у SET нету ОТКУДА)
       i == j ) // самого с собой не сравниваем (ибо ИЗВРаТ сие есмь)...
    continue;
//
   strcpy( aPredicat, Mem_Instruction[j].aPredicat ); // запомнили...
//--- проверяем, начинается ли имя флага предиктора с '!' или '~'
   flagNot = ( aPredicat[0] == symbolNot_1 || aPredicat[0] == symbolNot_2 )
               ? TRUE : FALSE; // TRUE, если в поле aPredicat первый символ '!' или '~'
//--- это флаг ПРЕДИКТОРА (не true и не false) ? -------------------------------
   flagPredicat = ( strcmp( aPredicat, trueLowerCase ) && strcmp( aPredicat, falseLowerCase )
                   ? TRUE : FALSE );
//
// очищаем от лидирующих '!' или '~'
   if( flagPredicat ) // не true/false
    if( flagNot )
     strcpy( aPredicat, &Mem_Instruction[j].aPredicat[1] ); // начиная со второго символа...
//
   if( !strcmp( Mem_Instruction[j].aOp1, aResult ) || // c Result совпало имя первого операнда...
       !strcmp( Mem_Instruction[j].aOp2, aResult ) || // c Result совпало имя второго операнда...
      ( flagPredicat &&
        is_Predicat( Mem_Instruction[i].Set ) &&
       !is_Predicat( Mem_Instruction[j].Set ) &&
       !strcmp( aPredicat, aResult ) ) ) // зависимость от флага предиктора
    {
     snprintf(tmp,sizeof(tmp), "%d -> %d ; [[%d]%s %s,%s,%s,%s; %s] -> [[%d]%s %s,%s,%s,%s; %s]",
              i+StartNumb, j+StartNumb,
              i+StartNumb, Mem_Instruction[i].Set,Mem_Instruction[i].aOp1,Mem_Instruction[i].aOp2,Mem_Instruction[i].aResult,Mem_Instruction[i].aPredicat,Mem_Instruction[i].Comment,
              j+StartNumb, Mem_Instruction[j].Set,Mem_Instruction[j].aOp1,Mem_Instruction[j].aOp2,Mem_Instruction[j].aResult,Mem_Instruction[j].aPredicat,Mem_Instruction[j].Comment);
//     snprintf(tmp,sizeof(tmp), "%d -> %d ;", i+StartNumb,j+StartNumb); // краткий вариант... ежели необходимо!..
     sIGA->Add( tmp );
     iEdge ++ ;
    }
//
   } // конец внутреннего цикла по по j (списку операторов) --------------------
//
 } // конец внешнего цикла по i (списку операторов) ----------------------------
////////////////////////////////////////////////////////////////////////////////
//
 sIGA->Add( "}" ); // добавить cтроку в конце списка дуг
//
 snprintf(tmp,sizeof(tmp), "#  Total edges in this directed graph: %d", iEdge );
 sIGA->Insert( 1, tmp ); // добавить строку комментария
//
 sIGA->SaveToFile( FileName ); // сохраняем в файл
 sIGA->Free(); // освободИм список строк sIGA
//
} //----- конец Save_IGA -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::ExtendedSave_IGA_Click(TObject *Sender)
{ // сохраняем в виде списка дуг в *.GV + данные о времени выполнения операторов в *.MVS
 Save_IGA(); // сохраняем список дуг (формат *.GV)
 Extended_Save_IGA(); // сохранение GV-файла
} //-----  конец TF1::ExtebdedSave_IGA_Click -----------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Extended_Save_IGA()
{ // сохранить данные о времени выполнения операторов (формат *.MVR)
 INT i; // номер оператора
 char FileName[_256];
 FILE *fptr;
//
// сохраняем ДАННЫЕ_О_ВРЕМЕНИ_ВЫПОЛНЕНИЯ_ОПЕРАТОРОВ (*.mvr) //////////////////////////////
//
 SBM0->Text = " Сохраняется файл данных о времени выполнения операторов (MVR-файл)...";
 Delay(100); // чтобы успеть увидеть...
//
 strcpy( FileName, FileNameSet ); // имя файла "MVR"
 strcpy( FileName, ChangeFileExt( FileName, ExtMVR).c_str()); // формат ".MVR" - данные о времени выполнения каждого оператора (вершины графа)
//
 if( !(fptr = fopen(FileName, "w")) ) // файл не открылся...
  return;
//
 fprintf( fptr, "; Valery Bakanov research computer complex (2008 and further); e881e@mail.ru, http://vbakanov.ru/left_1.htm\n" );
 fprintf( fptr, "; This file was automatically created thru program DATA_FLOW.EXE\n; from the original data file %s\n;\n",
          AnsiUpperCase(ExtractFileName(FileNameSet) ) );
//
 for(i=0; i<Really_Set; i++) // по всем инcтрукциям (операторам)
  fprintf(fptr, "=%d/%d: -Times %d ; [%s,%s,%s,%s,%s,%s]\n",
                 i+StartNumb,i+StartNumb,Get_TicksByInstruction(Mem_Instruction[i].Set),
                 Mem_Instruction[i].Set,
                 Mem_Instruction[i].aOp1,Mem_Instruction[i].aOp2,Mem_Instruction[i].aResult,
                 Mem_Instruction[i].aPredicat,Mem_Instruction[i].Comment);
//
 fclose(fptr);
//
} //----- конец Extended_Save_IGA -----------------------------------------------

void __fastcall TF1::Show_AIU(TObject *Sender)
{ // показать график загрузки АИУ по времени выполнения программы
//
 if( Regim != 2 || // если программы не выполнилась корректно (защита от F6)
     parallel_Ticks <= 0 ) // время выполнения НЕ ПОЛОЖИТЕЛЬНОЕ
 {
  MessageBeep( MB_OK ); // звуковое предупреждение...
  return;
 }
//
 char str[_512];
//
 F3->Chart_AIU->Title->Text->Clear(); // очистка TSting перед новым заполнением
 F3->Chart_AIU->Title->Text->Add( "Показывается нагруженность отдельных АИУ выполнением" );
 F3->Chart_AIU->Title->Text->Add( "операторов в функции времени (в тактах) выполнения программы" );
 F3->Chart_AIU->Title->Text->Add( "(цифры по центру горизонтальных линий - номера операторов)" );
 F3->Chart_AIU->Title->Text->Add( "" );
//
 F3->Chart_AIU->Foot->Text->Clear(); // очистка TSting перед новым заполнением
//
 snprintf( str,sizeof(str), "параллельное вычисление: %d тактов, ускорение = %.*e", parallel_Ticks, ACC_REAL, 1.0 * serial_Ticks / parallel_Ticks );
 F3->Chart_AIU->Foot->Text->Add( str );
//
 snprintf( str,sizeof(str), "всего задействовано %d штук/и АИУ из %d доступных", all_maxProcs, Max_Proc );
 F3->Chart_AIU->Foot->Text->Add( str );
//
 snprintf( str,sizeof(str), "из них одновременно не более %d штук/и АИУ", simult_maxProcs );
 F3->Chart_AIU->Foot->Text->Add( str );
//
 F3->Top  = F1->Top  + 40;
 F3->Left = F1->Left + 40;
//
 F3->Width  = 500; // чтобы помешался текст...
 F3->Height = 2 * F3->Width / 3 ;
//
 Work_TimeSets_Protocol_AIU(); // вычисление значений для индикации
//
 F3->Show(); // показать окно формы F2 в НЕМОДАЛЬНОМ режиме
//
 F3->Caption = " Функция загруженности АИУ по времени (программа ";
 F3->Caption = F3->Caption + AnsiUpperCase(FileNameSet) + ")"; // добавили имя файла программы
//
} //------ конец Show_AIU ------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int __fastcall Work_TimeSets_Protocol_AIU()
{ // вычисляется и возвращается max число ОДНОВРЕМЕННО работающих АИУ (процессоров)
// и заполняется серия данных для постройки графика интенсивности вычислений
 ULI i_Op, n_Op, ii_Op, nn_Op,
     i_Proc, start, end, i_Set, ii_Set;
 char aResult[_ID_LEN];
//
////////////////////////////////////////////////////////////////////////////////
 F3->Series1->Clear(); // очистим серию данных для графика нагруженности АИУ
////////////////////////////////////////////////////////////////////////////////
 if( ! mTpr || // если этот TStringList-список не существует... "ИЛИ"
     ! mTpr->Count) // если число строк = 0 ...
//  goto ended;
 return 1;
//
 F3->Chart_AIU->BottomAxis->SetMinMax( 0, parallel_Ticks ); // показываем только первый год
 F3->Chart_AIU->LeftAxis->SetMinMax(   0, all_maxProcs+1 ); // показываем только первый год
//
 F3->Series1->Pointer->VertSize = 3; // вертикальный размер прямоугольников
 F3->Series1->Marks->Font->Size = 7; // размер символов текста на прямоугольниках
//
 if( all_maxProcs <= 10 || Really_Set+1 <= 100 ) // АИУ <= 100 или число операторов <= 100
 {
  F3->Series1->Pointer->VertSize = 8; // вертикальный размер прямоугольников
 }
//
 for( i_Op=0; i_Op < mTpr->Count; i_Op++ ) // по строкам выполненных инструкций в Tpr
 {
  i_Proc = _atoi64( GetSubString(mTpr->Strings[i_Op].c_str(), 1,10) ); // номер АИУ
  start  = _atoi64( GetSubString(mTpr->Strings[i_Op].c_str(),11,20) ); // момент начала выполнения инструкции
  end    = _atoi64( GetSubString(mTpr->Strings[i_Op].c_str(),21,30) ); // момент окончания выполнения инструкции
  i_Set  = _atoi64( GetSubString(mTpr->Strings[i_Op].c_str(),41,50) ); // номер выполняющегося на данном АИУ оператора
//
  F3->Series1->AddGantt( start, end, i_Proc+1, "АИУ #" + AnsiString( GetSubString(F1->Tpr->Strings[i_Op].c_str(), 1,10) ).TrimLeft() );
//
  strcpy( aResult, Mem_Instruction[i_Set].aResult ); // результат выполнения оператора i_Set
//
  for( ii_Op=0; ii_Op < mTpr->Count; ii_Op++ ) // по строкам выполненных инструкций в Tpr
  {
   if( ii_Op == i_Op ) // строки (операторы) сами с собой не сравниваем..!
    continue;
//
   ii_Set  = atoi( GetSubString(mTpr->Strings[ii_Op].c_str(),41,50) ); // номер выполняющегося на данном АИУ оператора
//
   if( ( Get_CountOperandsByInstruction(Mem_Instruction[ii_Set].Set) == 1 && // всего один операнд...
         MI_aOp1(ii_Set) ) ||
       ( Get_CountOperandsByInstruction(Mem_Instruction[ii_Set].Set) == 2 && // два операнда...
        (MI_aOp1(ii_Set) ||
         MI_aOp2(ii_Set) ) ) )
    {
     F3->Series1->NextTask->Value[i_Op] = ii_Op ; // ниточка связи бАров "i_Op <-> ii_Op"
//     t_printf( "i_Set/ii_Set: %d/%d   i_Op/ii_Op: %d/%d ", i_Set,ii_Set, i_Op,ii_Op );
    }
//
  }  // конец  for( ii_Op=0; ii_Op < mTpr->Count; ii_Op++ )
//
 } // конец  for( i_Op=0; i_Op < mTpr->Count; i_Op++ )
//
ended: /////////////////////////////////////////////////////////////////////////
//
 return 0 ; // максимальное ОДНОВРЕМЕННО работающее число АИУ
//
} // ------- конец Work_TimeSets_Protocol_AIU ----------------------------------

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
void __fastcall Save_All_Protocols_To_Out_Dir()
{ // сохранение всех протоколов данного расчёта и перенос подкаталог Out!Data
 char tmp[_512], cnst[_512];
//
 snprintf( cnst, sizeof(cnst), "!%s!AIU=%d_Param=%d_Prior=%d!%s.txt", ExtractFileName(FileNameSet),
                                Max_Proc, How_Calc_Param, How_Calc_Prior, uniqueStr ); // постоянная часть имени файла
//
 Save_Protocol_Master(); // сохраняем главный протокол (*.pro)
  snprintf( tmp, sizeof(tmp), "%s\\pro%s", NameSubDirOutData, cnst );
  MoveFile( ChangeFileExt( FileNameSet, ".pro").c_str(), tmp ); // перенос в подкаталог NameSubDirOutData (Out!Data)
//
 Save_Protocol_AIU(); // сохраняем протокол использвания АИУ по времени (*.tpr)
  snprintf( tmp, sizeof(tmp), "%s\\tpr%s", NameSubDirOutData, cnst );
  MoveFile( ChangeFileExt( FileNameSet, ".tpr").c_str(), tmp );
//
 Save_Protocol_Data(); // сохраняем протокол рассчитанных данных (*.dat)
  snprintf( tmp, sizeof(tmp), "%s\\dat%s", NameSubDirOutData, cnst );
  MoveFile( ChangeFileExt( FileNameSet, ".dat").c_str(), tmp );
//
 Save_Protocol_ExecInstructions(); // сохраняем протокол выполнения инструкций (*.tst)
  snprintf( tmp, sizeof(tmp), "%s\\tst%s", NameSubDirOutData, cnst );
  MoveFile( ChangeFileExt( FileNameSet, ".tst").c_str(), tmp );
//
 Save_Protocol_ConnectedGraph(); // сохраняем протокол свЯзности в информ.графе (*.coi)
  snprintf( tmp, sizeof(tmp), "%s\\coi%s", NameSubDirOutData, cnst );
  MoveFile( ChangeFileExt( FileNameSet, ".coi").c_str(), tmp );
//
 Save_IGA(); // // сохраняем файл списка дуг в информационномграфе (*.gv)
  snprintf( tmp, sizeof(tmp), "%s\\gv%s", NameSubDirOutData, cnst );
  MoveFile( ChangeFileExt( FileNameSet, ".gv").c_str(), tmp );
//
 Extended_Save_IGA(); // сохранить данные о времени выполнения операторов (*.mvr)
  snprintf( tmp, sizeof(tmp), "%s\\mvr%s", NameSubDirOutData, cnst );
  MoveFile( ChangeFileExt( FileNameSet, ".mvr").c_str(), tmp );
//
 SBM0->Text = " Все файлы протоколов сохранены...";
//
} // --- конец Save_All_Protocols_To_Out_Dir------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall Read_Instructions()
{ // читаем инструкции из файла FileNameSets в массив структур Mem->Set[]
 FILE *fptr; // указатель на структуру ФАЙЛ
 char str[_1024], // строка для считывания и расшифровки инструкций
      tmp[_512], // рабочая строка
      Set[_SET_LEN], // мнемоника инструкции
      *p, *p1,*p2;
 bool flagPredicate; // TRUE если в операторе допустимо поле предиката
//
  RunPreProcessor(); // обработать препроцессором
//
 if(!(fptr = fopen(FileNameSetPrP, "r"))) // файл ПОСЛЕ ПРЕПРОЦЕССОРА открыть не удалось...
 {
  return FALSE ;
 }
//
 snprintf( tmp,sizeof(tmp), " Загружен файл %s [*%s]", ExtractFileName(FileNameSet), ExtPrP ); // вывод в строку статуса
 SBM2->Text = tmp;
//
////////////////////////////////////////////////////////////////////////////////
//
 for(UI i=0; i<Max_Instruction; i++) // по строкам инструкций
  {
   if(fgets(str, sizeof(str), fptr) == NULL) // читаем строку из fptr
    break; // если строки кончились, функция fgets возвращает NULL

   if(str[strlen(str)-1] == 10) // если в конце символ новой строки (10) в десятичной)...
    str[strlen(str)-1] = ' ';   // ... то заменим на пробел !
//
// ----- все Tab в строке str заменяем на пробелы ------------------------------
   for( int i=0; i<strlen(str); i++ ) // по всем символам строки...
    if( str[i] == VK_TAB ) // если i-тый символ есть Tab (9/0x9)...
     str[i] = VK_SPACE; // то заменяем его на пробел (32/0x20) !
//
   DelSpacesTabsAround( str ); // чистка строки str от лидирующих и терминирующих пробелов
//
   if( !strlen(str) || // если длина строки нулевая...
       str[0]==startComments[0] || // или строка начинается с ";"...
       str[0]==':' ) // частая описка...
    {
     i -- ; // строку пропускаем...!
     continue;
    }
//
// начали разборку (parsing) строки инструкции /////////////////////////////////
//
   if( !strpbrk(str,startComments) ) // если ";" в строке нет!
    strcpy(Mem_Instruction[i].Comment, " "); // значит, комментарий пустой....
   else
   {
    strcpy(Mem_Instruction[i].Comment, strstr(str,startComments)); // все что за ";" - суть комментарий
    Mem_Instruction[i].Comment[0] = ' '; // заменяем ";" пробелом
    DelSpacesTabsAround( Mem_Instruction[i].Comment ); // избавляемся от лидирующих и конечных пробелов
   }
//
   strtok(str,startComments); // комментарий (вместе с ";") убрали !
   DelSpacesTabsAround(str); // "справа" могли остаться пробелы...
   strcat(str, " "); // добавили 1 пробел на всякий случай (для последующей разборки)
//
   p = strtok(str, " "); // "выкусываем" мнемонику команды
//
   strcpy(Set, AnsiUpperCase(p).c_str()); // запомнили мнемонику в Set (AnsiUpperCase работает с латиницей)
   strcpy(Mem_Instruction[i].Set, Set); // запомнили мнемонику инструкции в Mem_Sets[]
//
// ---- случаи !false, ~false, !true, ~true в поле предиката--------------------
//
////////////////////////////////////////////////////////////////////////////////
   flagPredicate = !is_Predicat( Set ); // TRUE если в операторе допустимо поле предиката
////////////////////////////////////////////////////////////////////////////////
//
   switch( Get_CountOperandsByInstruction( Set ) ) // число входных операндов инструкции Set
   {
    case 1: p = strtok(NULL, ", "); // адрес единственного операнда aOp1.........
//            strcpy(Mem_Instruction[i].aOp1, p);
            p ? strcpy(Mem_Instruction[i].aOp1, p) : strcpy(Mem_Instruction[i].aOp1, notDefined);
            DelSpacesTabsAround(Mem_Instruction[i].aOp1);
            strcpy(Mem_Instruction[i].aOp2, ""); // очистка ОБЯЗАТЕЛЬНА !!!

            p = strtok(NULL, ", "); // адрес результата aResult ................
//            strcpy(Mem_Instruction[i].aResult, p);
            p ? strcpy(Mem_Instruction[i].aResult, p) : strcpy(Mem_Instruction[i].aResult, notDefined);
            DelSpacesTabsAround(Mem_Instruction[i].aResult);
//
            if( flagPredicate ) // поле предиката возможно
            {
             p = strtok(NULL, " "); // адрес флага предиката aPredicate.........
//
             p ? strcpy(Mem_Instruction[i].aPredicat, p) : strcpy(Mem_Instruction[i].aPredicat, "true");
// ---- начало случаев !false, ~false, !true, ~true в поле предиката -----------
             if( ( Mem_Instruction[i].aPredicat[0] == symbolNot_1 || Mem_Instruction[i].aPredicat[0] == symbolNot_2 ) ) // начинается с '!' или '~'
             {
              if( !strcmp( AnsiLowerCase(&Mem_Instruction[i].aPredicat[1]).c_str(),falseLowerCase ) ) // если начиная со второго символа "false"'
               strcpy( Mem_Instruction[i].aPredicat, trueLowerCase );
//
              if( !strcmp( AnsiLowerCase(&Mem_Instruction[i].aPredicat[1]).c_str(),trueLowerCase ) )  // если начиная со второго символа "true"'
               strcpy( Mem_Instruction[i].aPredicat, falseLowerCase );
             }
//
// ---- конец  случаев !false, ~false, !true, ~true в поле предиката -----------
//
            if( !strcmp( AnsiLowerCase(p).c_str(), trueLowerCase) )  strcpy(Mem_Instruction[i].aPredicat, trueLowerCase);
            if( !strcmp( AnsiLowerCase(p).c_str(), falseLowerCase) ) strcpy(Mem_Instruction[i].aPredicat, falseLowerCase);
            }
//
             Mem_Instruction[i].fExecOut   = FALSE;
             Mem_Instruction[i].fAddBuffer = FALSE;
//
             break;

    case 2: p = strtok(NULL, ", "); // адрес первого операнда aOp1...............
//            strcpy(Mem_Instruction[i].aOp1, p);
            p ? strcpy(Mem_Instruction[i].aOp1, p) : strcpy(Mem_Instruction[i].aOp1, notDefined);
            DelSpacesTabsAround(Mem_Instruction[i].aOp1);

            p = strtok(NULL, ", "); // адрес второго операнда aOp2...............
//            strcpy(Mem_Instruction[i].aOp2, p);
            p ? strcpy(Mem_Instruction[i].aOp2, p) : strcpy(Mem_Instruction[i].aOp2, notDefined);
            DelSpacesTabsAround(Mem_Instruction[i].aOp2);

            p = strtok(NULL, ", "); // адрес результата aResult .................
//            strcpy(Mem_Instruction[i].aResult, p);
            p ? strcpy(Mem_Instruction[i].aResult, p) : strcpy(Mem_Instruction[i].aResult, notDefined);
// предыдущий оператор выбрасывает исключение в случае оператора SUB y08(07), temp_02
// вместо правильного SUB y08(07), temp_02, temp_03 ... ПРАВИТЬ!!! Ситуация - нет поля РЕЗУЛЬТАТ
            DelSpacesTabsAround(Mem_Instruction[i].aResult);
//
            if( flagPredicate ) // поле предиката возможно
            {
             p = strtok(NULL, " "); // адрес флага предиката aPredicate..........
//             if( p ) strcpy(Mem_Instruction[i].aPredicate, p);
//             else    strcpy(Mem_Instruction[i].aPredicate, "true");
             p ? strcpy(Mem_Instruction[i].aPredicat, p) : strcpy(Mem_Instruction[i].aPredicat, "true");
//
// ---- начало случаев !false, ~false, !true, ~true в поле предиката -----------
             if( ( Mem_Instruction[i].aPredicat[0] == symbolNot_1 || Mem_Instruction[i].aPredicat[0] == symbolNot_2 ) ) // начинается с '!' или '~'
             {
              if( !strcmp( AnsiLowerCase(&Mem_Instruction[i].aPredicat[1]).c_str(),falseLowerCase ) ) // если начиная со второго символа "false"'
               strcpy( Mem_Instruction[i].aPredicat, trueLowerCase );
//
              if( !strcmp( AnsiLowerCase(&Mem_Instruction[i].aPredicat[1]).c_str(),trueLowerCase ) )  // если начиная со второго символа "true"'
               strcpy( Mem_Instruction[i].aPredicat, falseLowerCase );
             }
//
             if( !strcmp( AnsiLowerCase(p).c_str(), trueLowerCase ) )  strcpy( Mem_Instruction[i].aPredicat, trueLowerCase );
             if( !strcmp( AnsiLowerCase(p).c_str(), falseLowerCase ) ) strcpy( Mem_Instruction[i].aPredicat, falseLowerCase );
            }
//
             Mem_Instruction[i].fExecOut   = FALSE;
             Mem_Instruction[i].fAddBuffer = FALSE;
//
             break;
//
   default: return TRUE;

   } // конец switch...
//
//..............................................................................
   if( !is_SET( Mem_Instruction[i].Set ) ) // если это НЕ инструкция SET
    bool flag = Test_aResult_Eq_aOperand(i); // тестирование на совпадение адреса результата с адресами операндов
//..............................................................................
//
   Really_Set = i + 1 ; // реальное число инструкций (на 1 больше, ибо счет i с нуля)
//
  } // конец цикла по строкам в файле FileNameSets
//
 fclose(fptr);
//
 Vizu_Sets(); // визуализировать пул инструкций
//
 return TRUE ;
//
} // конец Read_Instructions -----------------------------------------------------------




