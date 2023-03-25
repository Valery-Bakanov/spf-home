//
//#define TEST_PRINT
//
// circle \225 \x0095; крест \207 \x0087; верт.лин \174 \x007c; разорв.верт.лини€ \246 \x00A6
#define SS_01 " \246 " // строка-разделитель блоков при выводе в с_PutParamsTiers() // Special Sequence двойна€ вертикальна€
#define SS_02 "$" // строка-символ фиктивного €руса ниже с максимальным номером
#define _OUT "\xBB" // строка-символ "\xBB" = ">>" ||| признак того, что у оператора нет ¬џ’ќƒ€ў»’ дуг (это выходные данные)
#define _IN  "\xAB" // строка-символ "\xAB" = "<<" ||| признак того, что у оператора нет ¬’ќƒ€ў»’  дуг (это исходные данные)
//
char Test_eq,Test_sl,Test_sll,Test_cl,Test_sp,Test_vr; // "=//: |"
char Test_symb[] = "=/: |";
#define Test_n1n2     (sscanf(sN,"%c%d%c%d%c%c",&Test_eq,&n1,&Test_sl,&n2,&Test_cl,&Test_sp)==6 || \
                                  Test_eq==Test_symb[0]  || Test_sl==Test_symb[1] || Test_cl==Test_symb[2] || Test_sp==Test_symb[3])
//
#define Test_n1n2m1m2 (sscanf(sN,"%c%d%c%d%c%d%c%d%c%c",&Test_eq,&n1,&Test_sl,&n2,&Test_vr,&m1,&Test_sll,&m2,&Test_cl,&Test_sp)==10 || \
                                  Test_eq==Test_symb[0]  || Test_sl==Test_symb[1] || Test_cl==Test_symb[2] || Test_sp==Test_symb[3] || \
                                  Test_sll==Test_symb[1] || Test_vr==Test_symb[4])
//
//#define strcat(dest,src) strncat(dest,src,sizeof(dest)-strlen(dest)-5) // безопасное добавление src к dest
//
#define strEndZero(str) str[strlen(str)]='\0' // добавление '\0' в конец строки str
//
#define strNcpy(dest,source)  strncpy(dest,source,sizeof(dest)) // безопасное копирование dest <- source
//
////////////////////////////////////////////////////////////////////////////////
// файл API_func.cpp ===========================================================
////////////////////////////////////////////////////////////////////////////////
// имена функций API на — начинаютс€ с "c_"; Lua-функции освобождены от этого
////////////////////////////////////////////////////////////////////////////////
//#define TEST_PRINT // если определено - тестова€ печать
////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
//
INT  __fastcall c_CalcParamsTLD(); // вычисл€ет (но не выводит!) данные времени жизни внутренних данных в яѕ‘
INT  __fastcall c_PutTLDToTextFrame(); // выдать диаграмму времени жизни данных в текстовое окно
char* __fastcall c_SaveTLD( char FileName[] ); // выдать диаграмму времени жизни данных в файл
//
INT  __fastcall c_GetCountTiers(); // возвращает общее число €русов в яѕ‘ информационного графа алгоритма (»√ј)
INT  __fastcall c_AddTier(INT Tier); // создаЄт (пустой) €рус ниже €руса Tier
INT  __fastcall c_DelTier(INT Tier); // уничтожает (пустой) €рус Tier
//
INT  __fastcall c_GetTierFirstMinOps(INT Tier1, INT Tier2); // возвращает ѕ≈–¬џ… #€руса с MIN по €русам Tier1-Tier2 числом операторов
INT  __fastcall c_GetTierLastMinOps(INT Tier1, INT Tier2); // возвращает ѕќ—Ћ≈ƒЌ»… #€руса с MIN по €русам Tier1-Tier2 числом операторов
INT  __fastcall c_GetTierFirstMaxOps(INT Tier1, INT Tier2); // возвращает ѕ≈–¬џ… #€руса с MAX по €русам Tier1-Tier2 числом операторов
INT  __fastcall c_GetTierLastMaxOps(INT Tier1, INT Tier2); // возвращает ѕќ—Ћ≈ƒЌ»… #€руса с MAX по €русам Tier1-Tier2 числом операторов
//
INT  __fastcall c_GetCountOpsOnTier(INT Tier); // возвращает количество операторов на €русе Tier
INT  __fastcall c_GetOpByNumbOnTier(INT Numb, INT Tier); // возвращает номер оператора по его номеру Numb на €русе Tier
//
INT  __fastcall c_PutTiersToTextFrame(); // выдаЄт яѕ‘ (массив Tiers[][]) в окно дл€ визуализации
bool __fastcall c_AddLineToTextFrame(char *str); // вставл€ет строку в окно текстового представл≈ни€
bool __fastcall c_ClearTextFrame(); // очищает окно  текстового представл≈ни€
//
INT  __fastcall c_GetMaxTierMaybeOp(INT Op); // возвращает MAX номер €руса, на котором ћќ∆≈“ –ј—ѕќЋј√ј“№—я оператор Op
INT  __fastcall c_GetMinTierMaybeOp(INT Op); // возвращает MIN номер €руса, на котором ћќ∆≈“ –ј—ѕќЋј√ј“№—я оператор Op
INT  __fastcall c_MoveOpTierToTier(INT Op, INT toTier); // переносит оператор Op на €рус toTier
INT  __fastcall c_SwapOpsTierToTier(INT Op1, INT Op2); // обмен между операторами Op1 и Op2
//
INT  __fastcall c_GetOpsMoves(); // возвращает текущее значение числа перемещений операторов с €руса на €рус return nMoves ;
INT  __fastcall c_CountMovesZeroing(); // обнул€ет значение счЄтчика числа перемещений операторов с €руса на €рус яѕ‘
//
INT  __fastcall c_PutEdgesToTextFrame(); // выдаЄт массив дуг Mem_Edges[][] в окно дл€ визуализации
bool __fastcall c_DelayMS(INT Sec); // ждЄт Sec милли-секунд, дава€ при этом поработать Windows
bool __fastcall c_SoundPlay(char str[]); // проигрывает мелодию из заданного файла
//
INT  __fastcall c_GetCountOpsInput(); // возвращает число вершин в »√ј с ¬’ќƒЌџћ» ƒјЌЌџћ»
INT  __fastcall c_GetNumbOpInput(); // возвращает Numb-ую вершину в »√ј с ¬’ќƒЌџћ» ƒјЌЌџћ»
//
INT  __fastcall c_GetCountOpsOutput(); // возвращает число вершин в »√ј с ¬џ’ќƒЌџћ» ƒјЌЌџћ»
INT  __fastcall c_GetNumbOpOutput(); // возвращает Numb-ую вершину в »√ј с ¬џ’ќƒЌџћ» ƒјЌЌџћ»
//
INT  __fastcall c_GetCountOps(); // возвращает число вершин в »√ј без ¬’ќƒЌџ’ ƒјЌЌџ’
INT  __fastcall c_GetNumbOp(INT Numb); // вз€ть номер оператора по номеру его встречаемости в файле дуг »√ј (исключа€ входные)
//
INT  __fastcall c_GetCountEdges(); // возвращает общее число дуг в информационном графе алгоритма (»√ј)
INT  __fastcall c_GetTierByOp(INT Op); // вернуть номер €руса по номеру оператора
//
INT  __fastcall c_GetCountInEdgesByOp(INT Op); // вернуть число дуг, ¬’ќƒяў»’ в оператор Op
INT  __fastcall c_GetCountOutEdgesByOp(INT Op); // вернуть число дуг, ¬¬џ’ќƒяў»’ из оператора Op
INT  __fastcall c_GetNumbInEdgeByOp(INT Numb, INT Op); // вернуть #опер., наход€щегос€ на Numb ¬’ќƒяў≈… в Op дуге
INT  __fastcall c_GetNumbOutEdgeByOp(INT Numb,INT Op); // вернуть #опер., наход€щегос€ на Numb ¬џ’ќƒяў≈… из Op дуге
//
bool __fastcall c_ReadEdges(char FileName[]); // читает из FileName дуги описани€ графа
char* __fastcall c_SaveEdges(char FileName[]); // вывод в FileName дуг описани€ графа + Tiers[0/nTiers][*]
bool __fastcall c_ReadTiers(char FileName[]); // читает из FileName яѕ‘ графа
char* __fastcall c_SaveTiers(char FileName[]); // вывод в FileName яѕ‘ графа
//
char* __fastcall c_SaveTiersVizu(char FileName[]); // сохранение файла операторов по €русам
char* __fastcall c_SaveEdgesVizu(char FileName[]); // сохранение файла зависимостей (дуг) операторов
char* __fastcall c_SaveInOutOpVizu(char FileName[]); // сохранение файла вход€щих и выход€щих душ дл€ оператора Op
char* __fastcall c_SaveParamsVizu(char FileName[]); // параметры графа - выдаютс€ GetParamsGraph()
//
//------------------------------------------------------------------------------
//
bool __fastcall c_IsOpExistOnTier(INT Op, INT Tier); // присутствует ли оператор Op на €русе Tier
bool __fastcall c_IsOpDependOnlyAboveTiers(INT toOp, INT Tier); // зависит ли toOp от операторов на нижележащих €русах
INT  __fastcall c_IsOpsHaveEdge(INT Op1, INT Op2); // проверка существовани€ дуги Op1 -> Op2
//
INT  __fastcall GetParamsGraph(); // вычислить экстремумы ¬’ќƒяў»’ и ¬џ’ќƒяў»’ дуг по операторам
INT  __fastcall GetOpByMinInOnTiers(INT minTier, INT maxTier); // #опер. с MIN ¬’ќƒќ¬ на €русах mimTier-maxTier
INT  __fastcall GetOpByMinOutOnTiers(INT minTier, INT maxTier); // #опер. с MIN ¬џ’ќƒќ¬ на €русах mimTier-maxTier
void __fastcall Delay(long mSecs); // ждать mSecs миллисекунд (с возможностью поработать WINDOWS)
INT  __fastcall AddEdge(INT fromOp, INT toOp); // добавление дуги с проверкой заполненности Edges
INT  __fastcall GetFirstToOpFromOp(INT fromOp); // вернуть #оп., €вл€ющего первым по счЄту ¬џ’ќƒяў»ћ по дуге графа относительно fromOp
INT  __fastcall GetFirstFromOpToOp(INT toOp); // вернуть #оп., €вл€ющего первым по счЄту ¬’ќƒяў»ћ по дуге графа относительно tomOp
//
INT  __fastcall GetCountInOp(INT toOp, INT Numb); // вернуть from-оператор, соответствующий Numb-той In-дуге дл€ to-оператора toOp
INT  __fastcall GetCountOutOp(INT fromOp, INT Numb); // вернуть to-оператор, соответствующий Numb-той Out-дуге дл€ to-оператора fromOp
//
INT  __fastcall TestExistInOutAtAllOps(); // тестирует наличие хоть одной ¬’ќƒЌќ… или ¬џ’ќƒЌќ… дуги у каждого оператора
//
////////////////////////////////////////////////////////////////////////////////
// учЄт гетерогенности вычислительного пол€ ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// сторона вычислителей --------------------------------------------------------
INT   __fastcall c_GetCountParamsByCalc(INT Calc); // число параметров вычислител€ Calc
char* __fastcall c_GetNumbParamByCalc(INT Numb, INT Calc); // параметр Numb (начина€ с 1) вычислител€ Calc
char* __fastcall c_GetNameNumbParamByCalc(INT Numb, INT Calc); // им€ параметра Numb (начина€ с 1) вычислител€ Calc
REAL  __fastcall c_GetMinValNumbParamByCalc(INT Numb, INT Calc); // мин значение параметра Numb (начина€ с 1) вычислител€ Calc
REAL  __fastcall c_GetMaxValNumbParamByCalc(INT Numb, INT Calc); // мах значение параметра Numb (начина€ с 1) вычислител€ Calc
// сторона операторов ----------------------------------------------------------
INT   __fastcall c_GetCountParamsByOp(INT Op); // число параметров вычислител€ Op
char* __fastcall c_GetNumbParamByOp(INT Numb, INT Op); // параметр Numb (начина€ с 1) оператора Op
char* __fastcall c_GetNameNumbParamByOp(INT Numb, INT Op); // им€ параметра Numb (начина€ с 1) оператора Op
REAL  __fastcall c_GetValNumbParamByOp(INT Numb, INT Op); // значение параметра Numb (начина€ с 1) оператора Op
//
// работа с ћ≈“–» јћ» вершин (операторов) --------------------------------------
REAL  __fastcall c_GetMetricOpByName(INT Op, char* nameMetric); // вернуть числовое значение метрики nameMetric вершины (оператора) Op
INT   __fastcall c_GetCountMetricsByOp(INT Op); // число параметров вершины (оператора) Op
char* __fastcall c_GetNumbMetricByOp(INT Numb, INT Op); // вз€ть значение Numb-й метрики nameMetric вершины (оператора) Op
char* __fastcall c_GetMetricsByOp(INT Op); // из строки sVrt возвращает подстроку всех параметров ¬≈–Ў»Ќџ (оператора) Op
//
// работа с ћ≈“–» јћ» дуг ------------------------------------------------------
REAL  __fastcall c_GetMetricEdgeByName(INT from_Op, INT to_Op, char* nameMetric); // вернуть числовое значение метрики nameMetric дуги между вершинами (операторами) from_Op и to_Op
INT   __fastcall c_GetCountMetricsByEdge(INT from_Op, INT to_Op); // число параметров дуги от from_Op до to_Op
char* __fastcall c_GetNumbMetricByEdge(INT Numb, INT from_Op, INT to_Op); // вз€ть значение метрики дуги от from_Op до to_Op
char* __fastcall c_GetMetricsByEdge(INT from_Op, INT to_Op); // из строки sEdg возвращает подстроку всех параметров дуги  от from_Op до to_Op
//
// функции логического вывода по вопросу совместимости ќѕ≈–ј“ќ–ќ¬ и ¬ы„»—Ћ»“≈Ћ≈…
INT   __fastcall c_CanExecOpCalc(INT Op, INT Calc); // возврат >0, если Op можно выполнить на Calc
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_LoadFileNameParamsCalcs(char FileName[]); // настроим им€ файла параметров ¬џ„»—Ћ»“≈Ћ≈…
bool  __fastcall c_ReadAndCorrectParamsCalcs(char FileName[]); // читаем файл параметров ¬џ„»—Ћ»“≈Ћ≈…
//
bool  __fastcall c_LoadFileNameParamsOps(char FileName[]); // настроим им€ файла параметров ќѕ≈–ј“ќ–ќ¬
bool  __fastcall c_ReadAndCorrectParamsOps(char FileName[]); // читаем файл параметров ќѕ≈–ј“ќ–ќ¬
//
bool  __fastcall c_LoadFileNameParamsEdges(char FileName[]); // настроим им€ файла метрик ƒ”√
bool  __fastcall c_ReadAndCorrectParamsEdges(char FileName[]); // читаем файл метрик ƒ”√
//
bool  __fastcall c_LoadFileNameParamsVertices(char FileName[]); // настроим им€ файла метрик ¬≈–Ў»Ќ (операторов)
bool  __fastcall c_ReadAndCorrectParamsVertices(char FileName[]); // читаем файл метрик ¬≈–Ў»Ќ (операторов)
//
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetParamsByCalc(INT Calc); // возвращает всю строку параметров вычислител€ —alc
char* __fastcall c_GetParamsByOp(INT Op); // возвращает всю строку параметров оператора Op
//
////////////////////////////////////////////////////////////////////////////////
// общие функции - оперируют не с Calc или Op, а со строками -------------------
INT   __fastcall c_GetCountParamsInString(char* str); // число параметров в строке str
char* __fastcall c_GetNumbParamInString(INT Numb, char* str); // параметр Numb в строке str
char* __fastcall c_GetNameNumbParamInString(INT Numb, char* str); // им€ параметра Numb в строке str
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_IsCorrectParamCalc(char* str); // true при корректности распознавани€ параметра вычислител€
bool  __fastcall c_IsCorrectParamOpVertEdg(char* str); // true при корректности распознавани€ параметра оператора
////////////////////////////////////////////////////////////////////////////////
INT  __fastcall  c_FindSubString( char* sSrc, char* sDst, INT iStart , INT Rule);
INT  __fastcall  c_GetCountCalcs(); // общее число вычислителей
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_PutParamsAll(); // вывод (скорректированных) строк ¬џ„»—Ћ»“≈Ћ≈… и ќѕ≈–ј“ќ–ќ¬, метрик ƒ”√ и ¬≈–Ў»Ќ
bool  __fastcall c_TestCanExecAllOpsCalcs( INT  Rule ); // тест выполнимости ќѕ≈–ј“ќ–ќ¬ на ¬џ„»—Ћ»“≈Ћя’
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall cmp_def( char *s );
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_InputDialog( char *sCaption, char *sPrompt, char *sDefault ); // стандартное окно ввода Windows
int   __fastcall c_MessageDialog( char *sCaption, char *sText, char *Buttons, INT Pictogram ); // стандартное окно вывода Windows
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_DrawDiagrTiers(); // строит графическое изображение (диаграмму) текущей ширины графа
bool  __fastcall c_DrawDiagrTLD(); // строит графическое изображение (диаграмму) времЄн жизни внутренних данных
bool  __fastcall c_ClearDiagrArea(); // затирает графическое изображение (диаграмму)
INT   __fastcall c_PutParamsTiers(); // вывод основных параметров »√ј и яѕ‘ в нижнюю часть текстового фрейма (F2)
//
bool  __fastcall c_IsOpContainOnTiers(INT Op); // если оператор Op присутствует в Tiers[][], возращаетс€ true, иначе - false
INT   __fastcall c_GetOpByMaxTierLowerPreset(INT Op); // выдаЄт оператор, информационно зависимый от заданного и наход€щийс€ на €русе
// с максимальным номером (если таких оператор несколько - выдаЄтс€ последний по списку)
//
INT   __fastcall c_WinExec( char *cmdLine, INT cmdShow ); // выполнить WinExec
INT   __fastcall c_ShellExecute( char *Operation, char *File, char *Parameters, char *Directory, INT cmdShow ); // выполнить ShellExecute
//
INT   __fastcall c_CreateProsess(char* CommandLine, byte RuleParent, byte Priority, bool RuleMessage); // запуск процесса-потомка
//==============================================================================
bool __fastcall TestAndAddMemoryForEdges( INT nEdges ); // попытка увеличени€ пам€ти дл€ Mem_Edges[][]
bool __fastcall ParseStringAndAddEdges( char *str ); // парсит str и добавл€ет дуги в общий массив дуг
bool __fastcall ReadAndPrimWorkOpsCalcsVertEdgeFiles( char FileName[] ); // чтение и предв.обработка файлов настроек
INT  __fastcall c_LuaCallByTimer( char *CommandLine, INT d_Ticks ); // вызов Lua-команд с задержкой d_Ticks
void __fastcall CallLuaThread( char *CommandLine ); // вызов CommandLine во вновь созданном потоке Lua
char* __fastcall ReformFileName( char Filename[], char Ext[] ); // нужным образом преобразовать им€ файла
INT  __fastcall c_CalcParamsTiers(); // расчЄт статистики €русов яѕ‘
//
void __fastcall tuneFlagsAll( bool FLAG, INT FromTo ); // устанавливает FLAG у операторов массива дуг From/To=0/1 списка Edges[][]
void __fastcall tuneFlagsIfEqual( bool FLAG, INT FromTo, INT Value ); // устанавливает FLAG и Value у операторов массива дуг From/To=0/1 списка Edges[][]
void __fastcall clearFlagsDuplicateOps( INT FromTo, INT Op ); // устанавливает в false все флаги операторов-дублей Op в массиве дуг From/To=0/1 списка Edges[][]
//
char* __fastcall CreateUniqueFileName(char* FileName); // создание уникального имени файла при существовании файла с именем, заданным FileName
//
void __fastcall OutRepeatComplete(char* s_Before, INT i, INT n, INT di, REAL Value, char* Fmt, char* s_After);
//
INT  __fastcall c_CountOfMemoryLuaUse(); // количество байт, используемых Lua
INT  __fastcall c_CountOfFreeMemory(); // получение и вывод размеров физической пам€ти
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall cmp_def( char *s )
{ // сравнивает попарно 5 первых символов s и sDef; возвращает true, если они все равны
 return( toupper(s[0])==toupper(sDef[0]) &&
         toupper(s[1])==toupper(sDef[1]) &&
         toupper(s[2])==toupper(sDef[2]) &&
         toupper(s[3])==toupper(sDef[3]) &&
         toupper(s[4])==toupper(sDef[4]) ) ;
} // === конец cmp_def =========================================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // ждать mSecs миллисекунд (с возможностью поработать WINDOWS)
Delay(long mSecs)
{ // при mSecs < 0 врем€ ожидани€ измер€етс€ уже в секундах
 if ( !mSecs ) // если ноль - никакого ожидани€!... жаль токмо Windows - "чегтовски погаботать хочетс€!"
  return ;
//
 unsigned long t, FirstTick = ::GetTickCount(); // запомнили начало отсчета ( :: дл€ отличи€ от наход€щейс€ в TldHTTP)
 t= mSecs>=0 ? mSecs : -1e3*mSecs;
 while( (::GetTickCount()-FirstTick) < t ) // работать, пока заданный интервал времени не истек...
  Application->ProcessMessages(); // дать поработать WINDOWS
}
// === конец Delay =============================================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_SaveTiersVizu(char FileName[])
{ // вывод числа операций по €русам
 char str[_16384], tmp[_256];
 FILE *fptr = NULL; // рабочий указатель на файл
//
 if( !flagExistsTiers ) // массива Tiers[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // вернуть число как строку
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,Format("%s%s",OPENARRAY(TVarRec,(extTiers,extVizu))).c_str() ) ); // преобразованное им€ файла
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // если MewFileName уже существует...
//
 if(!(fptr = fopen( NewFileName,"w" ))) // открыли дл€ записи
 {
  t_printf( "\n-E- Ќевозможно записать файл %s содержани€ яѕ‘ -E-\n\n-W- проверьте осуществимость записи на заданный носитель данных -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // вернуть число как строку
 }
//
// setbuf( fptr, NULL ); // отключили буфферизацию при записи
//
 for(INT iTier=0; iTier<=nTiers; iTier++) // по €русам яѕ‘
 {
  snprintf(str,sizeof(str), "#Tier=%4d #Op=%4d|", iTier, Tiers(iTier,0)); // номер €руса + число операторов на нЄм
  for(INT j = 1; j<=Tiers( iTier,0 ); j++) // по списку номеров операторов на €русе i
  {
   if( !c_GetCountInEdgesByOp( Tiers(iTier,j) )) // у этого оператора нет ¬’ќƒ€ў»’ дуг...
    snprintf(tmp,sizeof(tmp), " " _IN "%d",  Tiers(iTier,j)); // это выходной оператор (результат программы)
   else
   if( !c_GetCountOutEdgesByOp( Tiers(iTier,j) )) // у этого оператора нет ¬џ’ќƒ€ў»’ дуг...
    snprintf(tmp,sizeof(tmp), " %d" _OUT , Tiers(iTier,j)); // это выходной оператор (результат программы)
   else
    snprintf(tmp,sizeof(tmp), " %d", Tiers(iTier,j) ); // порци€ очередного оператора дл€ выводной строки
//
   strcat(str, tmp); // добавление номера оператора на €русе i
  } // конец по j (номеру оператора на €русе)
  fprintf(fptr, "%s\r\n", str); // вывели в файл готовую строку
 } // конец по i (номеру €руса)
//
 fclose(fptr); // закрыли файл
//
 return NewFileName ;
//
} // --- конец SaveTiersVizu ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_SaveEdgesVizu(char FileName[])
{ // вывод св€зей между операторами
 FILE *fptr = NULL; // рабочий указатель на файл
//
 if( !flagExistsEdges ) // массива Mem_Edges[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // вернуть число как строку
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,Format("%s%s",OPENARRAY(TVarRec,(extGv,extVizu))).c_str() ) ); // преобразованное им€ файла
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // если MewFileName уже существует...
//
 if(!(fptr = fopen( NewFileName,"w" ))) // открыли дл€ записи
 {
  t_printf( "\n-E- Ќевозможно записать файл %s содержани€ »√ј -E-\n\n-W- проверьте осуществимость записи на заданный носитель данных -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // вернуть число как строку
 }
//
// setbuf( fptr, NULL ); // отключили буфферизацию при записи
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по номерам дуг
  fprintf(fptr, "#Edge= %d %d -> %d\n", iEdge, Edges(0,iEdge),Edges(1,iEdge)); // дуга номер i
//
 fclose(fptr); // закрыли файл
//
 return NewFileName ;
//
} // --- конец SaveEdgesVizu ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_SaveInOutOpVizu(char FileName[])
{ // вывод числа ¬’ќƒяў»’ и ¬џ’ќƒяў»’ дуг дл€ операторов
 char str[_16384], tmp[_256], s1[]="* \0";
 INT jOpOnTier, iOp, j, nIn,nOut;
 FILE *fptr = NULL; // рабочий указатель на файл
//
 if( !flagExistsEdges ) // массива Mem_Edges[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // вернуть число как строку
 }
//
 if( !flagExistsTiers ) // массива Tiers[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // вернуть число как строку
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,Format("%s%s",OPENARRAY(TVarRec,(extIno,extVizu))).c_str() ) ); // преобразованное им€ файла
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // если MewFileName уже существует... 
//
 if(!(fptr = fopen( NewFileName,"w" ))) // открыли дл€ записи
 {
  t_printf( "\n-E- Ќевозможно записать файл %s вход€щих и исход€щих дуг по операторам -E-\n\n-W- проверьте осуществимость записи на заданный носитель данных -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // вернуть число как строку
 }
//
// setbuf( fptr, NULL ); // отключили буфферизацию при записи
//
 for(INT iTier=0; iTier<=nTiers; iTier++) // по всем €русам ¬ Ћё„јя ¬’ќƒЌќ…...
  for(jOpOnTier=1; jOpOnTier<=Tiers(iTier,0); jOpOnTier++) // по операторам на €русе...
  {
   iOp = Tiers(iTier,jOpOnTier); // номер оператора
// --- начало формировани€ строки вывода ---------------------------------------
   snprintf(str,sizeof(str), "#Op=%d #Tier=%d #In=%d ",
                iOp, c_GetTierByOp(iOp), c_GetCountInEdgesByOp(iOp)); // c_GetCountOutEdgesByOp(iOp) );
//
   for(j=1; j<=c_GetCountInEdgesByOp(iOp); j++) // по списку ¬’ќƒЌџ’ дуг оператора iOp
   {
    nIn = c_GetNumbInEdgeByOp(j,iOp); // j-й оператор по входной дуге оператора iOp
    if( nIn > 0 ) snprintf(tmp,sizeof(tmp), "%d ", nIn);  // есть IN-оператор...
    else          strNcpy(tmp, s1); // нет IN-оператора...
    strcat(str, tmp); // ... прибавили!
   }
//
   snprintf(tmp,sizeof(tmp), "#Out=%d ", c_GetCountOutEdgesByOp(iOp)); // число ¬џ’ќƒЌџ’ дуг оператора iOp
   strcat(str, tmp); // ... прибавили!
//
   for(j=1; j<=c_GetCountOutEdgesByOp(iOp); j++) // по списку ¬џ’ќƒЌџ’ дуг оператора iOp
   {
    nOut = c_GetNumbOutEdgeByOp(j,iOp); // j-й оператор по входной дуге оператора iOp
    if( nOut > 0 )
     snprintf(tmp,sizeof(tmp), "%d ", nOut);  // есть OUT-оператор...
    else
     strNcpy(tmp, s1); // нет OUT-оператора...
    strcat(str, tmp); // ... прибавили!
   }
//
// --- конец формировани€ строки вывода ----------------------------------------
//
   fprintf(fptr, "%s\r\n", str); // вывели в файл готовую строку
  } // конец цикла по jOpOnTier ================================================
//
 fclose(fptr); // закрыли файл
//
 return NewFileName ;
//
} // --- конец SaveInOutOpVizu -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_SaveParamsVizu(char FileName[])
{ // вывод числа ¬’ќƒяў»’ и ¬џ’ќƒяў»’ дл€ операторов
 FILE *fptr = NULL; // рабочий указатель на файл
//
 if( !flagExistsEdges ) // массива Mem_Edges[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // вернуть число как строку
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,Format("%s%s",OPENARRAY(TVarRec,(extPrm,extVizu))).c_str() ) ); // преобразованное им€ файла
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // если MewFileName уже существует...
//
 if(!(fptr = fopen( NewFileName,"w" ))) // открыли дл€ записи
 {
  t_printf( "\n-E- Ќевозможно сохранить файл %s числа вход€щих и выход€щих дуг по операторам -E-\n-W- проверьте осуществимость записи на заданный носитель данных -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // вернуть число как строку
 }
//
// setbuf( fptr, NULL ); // отключили буфферизацию при записи
//
 GetParamsGraph(); // вз€ли параметры графа ----------------------------------
//
 fprintf(fptr, "#nOpMinIn=%10d #nEdgesMinIn=%10d\n#nOpMaxIn=%10d #nEdgesMaxIn=%10d\n#nOpMinOut=%9d #nEdgesMinOut=%9d\n#nOpMaxOut=%9d #nEdgesMaxOut=%9d\nAveIn=%14.3f AveOut=%16.3f",
               PG.nOpMinIn,  PG.nEdgesMinIn,
               PG.nOpMaxIn,  PG.nEdgesMaxIn,
               PG.nOpMinOut, PG.nEdgesMinOut,
               PG.nOpMaxOut, PG.nEdgesMaxOut,
               PG.AveIn,     PG.AveOut);
//
 fclose(fptr); // закрыли файл
//
 return NewFileName ;
//
} // --- конец SaveParamsVizu -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_SaveTiers(char FileName[])
{  // вывод операторов по €русам дл€ полного описани€ графа в виде яѕ‘
 char str[_16384], tmp[_256];
 FILE *fptr = NULL; // рабочий указатель на файл
//
 if( !flagExistsTiers ) // массива Tiers[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // вернуть число как строку
 }
//
 char NewFileName[_512];
 strcpy( NewFileName, ReformFileName(FileName,extTiers) ); // преобразованное им€ €файла
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // если MewFileName уже существует...
//
 if(!(fptr = fopen( NewFileName, "w" ))) // открыли дл€ записи
 {
  t_printf( "\n-E- Ќевозможно записать файл %s полного описани€ »√ј в яѕ‘ -E-\n\n-W- проверьте осуществимость записи на заданный носитель данных -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // вернуть число как строку
 }
//
// setbuf( fptr, NULL ); // отключили буфферизацию при записи
//
////////////////////////////////////////////////////////////////////////////////
// определ€ем максимум числа операторов на €русе и номер этого €руса (включа€ нулевой)
//
 INT MaxOpsOnTier = -1, TierWithMaxOps = -1; // начальные значени€
//
 for(INT iTiers=0; iTiers<nTiers; iTiers++) // по €русам яѕ‘ графа
  if( Tiers(iTiers,0) > MaxOpsOnTier ) // если больше...
  {
   MaxOpsOnTier   = Tiers(iTiers,0);
   TierWithMaxOps = iTiers;
  }
//
////////////////////////////////////////////////////////////////////////////////
//
 fprintf(fptr, "%d %d %d\n", nTiers+1, MaxOpsOnTier, TierWithMaxOps); // вывод первой строки
 for(INT iTiers=0; iTiers<=nTiers; iTiers++) // по €русам яѕ‘ графа
 {
  strNcpy(str, ""); // очистили строку перед заполнением
//
  for(INT j=0; j<=Tiers(iTiers,0); j++) // по номерам операторов на €русе iTiers
  {
   snprintf( tmp,sizeof(tmp), "%d ", Tiers(iTiers,j) ); // по элементам строки уровн€ iTiers
   strcat(str, tmp); // прибавили дл€ формировани€ строки
  } // конец цикла по j
//
  fprintf(fptr, "%s\n", str); // вывели в файл готовую строку
//
 } // конец цикла по iTiers
//
 fclose(fptr); // закрыли файл
//
 return NewFileName ; // венули действительное им€ файла
//
} // --- конец SaveTiers -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ReadTiers(char FileName[])
{  // чтение операторов по €русам дл€ полного описани€ графа в виде яѕ‘
 char str[_16384], *p;
 INT nTiersAll; // всего €русов в яѕ‘ (включа€ нулевой)
 FILE *fptr = NULL; // рабочий указатель на файл
//
 INT MaxOpsOnTier, // мах число операторов на €русе данной яѕ‘ графа (включа€ нулевой)
     TierWithMaxOps; // на каком (сверху) €русе этот мах реализуетс€ (включа€ нулевой)
//
 char NewFileName[_512];
 strcpy( NewFileName, ReformFileName(FileName,extTiers) ); // преобразованное им€ €файла
//
 if(!(fptr = fopen(NewFileName, "r"))) // открыли дл€ чтени€
 {
  t_printf( "\n-E- Ќевозможно прочитать файл %s содержани€ яѕ‘ -E-\n-W- веро€тна некорректность при дальнейшей работе -W-",
                   NewFileName );
  flagExistsTiers = false;
  return false ;
 }
//
 fgets(str, sizeof(str), fptr); // прочитали первую строку файла
// число €русов (глобальное), max операторов на €русе, на каком €русе этот max (включа€ нулевой)
 if( sscanf(str, "%d %d %d", &nTiersAll, &MaxOpsOnTier, &TierWithMaxOps) != 3 ) // ошибка...
 {
  flagExistsTiers = false;
  return false ;
 }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 _maxTiers = nTiersAll; // число €русов (с учЄтом нулевого €руса)
 _maxOpsOnTier = MaxOpsOnTier+1; // максимум числа операторов по €русам
 pTiers = (INT*) realloc( pTiers, _maxTiers * _maxOpsOnTier * stockMem * sizeof(INT) ); // реаллокировали пам€ть под Tiers[][] с запасом в stockMem раз
//
 if( !pTiers ) // совсем плохо - пам€ть в "куче" закончилась
 {
  snprintf(str,sizeof(str), "Ќехватка пам€ти дл€ размещени€ массива я–”—ќ¬ (4). «атребовано %d x %d = %d элементов...",
                (_maxTiers+1), (_maxOpsOnTier+1), (_maxTiers+1) * (_maxOpsOnTier+1));
  MessageBox(0, str, "ѕредупреждение", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  flagExistsTiers = false ; // массив Tiers[][] не создан...
  return false ;
 }
//
  t_printf( "\n-I- ћассив я–”—ќ¬ (4) перераспределЄн на %d x %d = %d элементов -I-",
                   (_maxTiers+1), (_maxOpsOnTier+1), (_maxTiers+1) * (_maxOpsOnTier+1) );
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 nTiers = nTiersAll-1; // nTiers - число €русов без входного €руса
//
 for( INT iTier=0; iTier<=nTiers; iTier++ ) // по €русам яѕ‘ графа
 {
  fgets(str, sizeof(str), fptr); // прочитали очередную строку файла
//
  INT j = 0; // номера чисел в строке str
//
  p = strtok( str, " " ); // бежим по строке str, останавлива€сь на пробелах...
  if( p )
   sscanf( p, "%d", &Tiers(iTier,j++) ); // число номер 0 = число операторов на €русе
//
  while( p ) // пока p = true
  {
   p = strtok( NULL, " "); // до следующего пробела..
   if( p )
    sscanf( p, "%d", &Tiers(iTier,j++) ); // прочитали число номер =>1
  } // конец while
//
 } // конец цикла по iTiers
//
 fclose(fptr); // закрыли файл
//
 flagExistsTiers = true ; // all O'k...
//
 t_printf( "\n-I- яѕ‘ графа из файла %s успешно прочитана -I-", NewFileName );
//
 flagCalcTLD = false ; // paramsTLD не соответствует Tiers[][]
//
 return true ;
//
} // --- конец с_ReadTiers -----------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_IsOpsHaveEdge(INT Op1, INT Op2)
{ // true - если наличествует дуга между операторами Op1 -> Op2
 if( !flagExistsEdges ) // массив Mem_Edges[][] ещЄ не существует - выходим с false
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по общему списку дуг между операторами
  if ( (Op1 == Edges(0,iEdge)) && (Op2 == Edges(1,iEdge)) ) // така€ дуга в списке имеетс€...
   return ( true );
//
 return ( false );
//
} // --- конец c_IsOpsHaveEdge -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierByOp(INT Op)
{ // --- вернуть номер €руса дл€ оператора Op ----------------------------------
 if( !flagExistsTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }

 for(INT iTier=0; iTier<=nTiers; iTier++) // по всем €русам
  if( c_IsOpExistOnTier( Op, iTier ) == true ) // оператор Op имеет честь присутствовать на €русе iTier
   return iTier ;

 return ERR_COMMON ; // не удалось найти оператор Op...

} // --- конец c_GetTierByOp -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetParamsGraph()
{ // --- вернуть экстремумы числа входных и выходных дуг дл€ всех операторов
// ----- (первый и последний €русы не рассматриваютс€) - возврат в структуре ParGraph
 INT Extr = nOps,  // больше быть не может !!!
     Op, nEdgesInOp,  // In  по всем операторам...
         nEdgesOutOp; // Out по всем операторам...
 char w[_256];

// PG - глобальна€ ! -----------------------------------------------------------

 if( !flagExistsEdges && !flagExistsTiers ) // нет массивов Mem_Edges[][] и Tiers[][]
 {
  DisplayMessage( "E", __FUNC__, "массивы ƒ”√ и я–”—ќ¬ не сформированы", ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }

 PG.nEdgesMinIn  =        // инициализаци€ по числу ¬’ќƒяў»’ дуг... (MIN)
 PG.nEdgesMinOut =  Extr; // инициализаци€ по числу ¬џ’ќƒяў»’ дуг... (MIN)

 PG.nEdgesMaxIn  =    // то же самое (MAX)
 PG.nEdgesMaxOut = - Extr; // то же самое (MAX)

 PG.AveIn  =       // дл€ суммировани€ числа дуг
 PG.AveOut = 0.0;

// --- ищем ¬’ќƒ€ў»≈ ( to ) в операторы дуги -----------------------------------
 for(INT iTier=2; iTier<=nTiers; iTier++) // по всем €русам от 2 до nTiers
  for(INT j=1; j<=Tiers(iTier,0); j++) // по номерам операторов на €русе слева направо
  {
   Op = Tiers(iTier,j); // номер оператора
// ищем MIN и ћј’ числа ¬’ќƒяў»’ (...In...) дуг ||||||||||||||||||||||||||||||||
   nEdgesInOp = 0; // счЄтчик суммы дуг, €вл€ющихс€ ¬’ќƒЌџћ» ( to ) дл€ оператора Op
   for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам графа
    if( Edges(1,iEdge) == Op ) // нашли дугу, ¬’ќƒяў”ё ( to ) в нужный оператор...
     nEdgesInOp ++ ; // суммируем дуги, ¬’ќƒяў»≈ ( to ) дл€ оператора Op

   PG.AveIn += nEdgesInOp ;  // сумма числа дуг In дл€ оператора Op

   if(nEdgesInOp < PG.nEdgesMinIn) // ищем MIN вход€щих...
   {
    PG.nEdgesMinIn = nEdgesInOp;
    PG.nOpMinIn    = Op; // запомнили соответствующий Op
   }

   if(nEdgesInOp > PG.nEdgesMaxIn) // ищем NAX вход€щих...
   {
    PG.nEdgesMaxIn = nEdgesInOp;
    PG.nOpMaxIn    = Op; // запомнили соответствующий Op
   }

  } // конец цикла по j

////////////////////////////////////////////////////////////////////////////////

// --- ищем ¬џ’ќƒ€ў»≈ ( from ) в операторы дуги --------------------------------
 for(INT iTier=1; iTier<nTiers; iTier++) // по всем €русам от 1 до nTiers-1
  for(INT j=1; j<=Tiers(iTier,0); j++) // по номерам операторов на €русе слева направо
  {
   Op = Tiers(iTier,j); // номер оператора
// ищем MIN и ћј’ числа ¬џ’ќƒяў»’ (...Out...) дуг ||||||||||||||||||||||||||||||
   nEdgesOutOp = 0; // счЄтчик дл€ суммировани€ числа дуг, €вл€ющихс€ ¬џ’ќƒЌџћ» дл€ оператора iOp
   for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам графа ========
    if( Edges(0,iEdge) == Op ) // нашли дугу, ¬џ’ќƒяў”ё ( from ) из нужного оператора...
     nEdgesOutOp ++ ; // суммируем дуги, ¬џ’ќƒяў»≈ из оператора Op...
//
   PG.AveOut += nEdgesOutOp ; // сумма числа дуг Out дл€ оператора Op
//
   if(nEdgesOutOp < PG.nEdgesMinOut) // ищем MIN выход€щих...
   {
    PG.nEdgesMinOut = nEdgesOutOp;
    PG.nOpMinOut    = Op; // запомнили соответствующий Op
   }
//
   if(nEdgesOutOp > PG.nEdgesMaxOut) // ищем NAX выход€щих...
   {
    PG.nEdgesMaxOut = nEdgesOutOp;
    PG.nOpMaxOut    = Op; // запомнили соответствующий Op
   }
//
  } // конец цикла по j
//
////////////////////////////////////////////////////////////////////////////////
//
 PG.AveIn  /= nOps - Tiers(1,0); // среднее число дуг, ¬’ќƒяў»’ ( to ) в операторы графа
 PG.AveOut /= nOps - Tiers(nTiers,0); // среднее число дуг, ¬џ’ќƒяў»’ ( from ) из операторов графа
//
 return true ;
//
} // --- конец GetParamsGraph --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetOpByMinInOnTiers(INT minTier, INT maxTier)
{ // --- вернуть номер оператора с MIN ¬’ќƒќ¬ на €русах с minTier по maxTier
 INT nEdgesInOp = nEdges,  // больше быть не может
     iOp,iOpMinIn, sumEdgesIn;
//
 if( !flagExistsTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 for(INT j=minTier; j<=maxTier; j++) // по всем €русам с minTier по maxTier
//
 for(INT iOpOnTier=1; iOpOnTier<=Tiers(j,0); iOpOnTier++) // по всем этим операторам €руса Tier
 {
  iOp = Tiers(j,iOpOnTier); // вз€ли номер iOpOnTier по счЄту оператора на €русе j
//
  sumEdgesIn = 0; // суммируем In-св€зи в переменной sumEdgesIn
  for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам графа ==============
   if( Edges(1,iEdge) == iOp ) // нашли дугу, ¬’ќƒяў”ё в оператор iOp
    sumEdgesIn ++ ; // суммируем число дуг, ¬’ќƒяў»’ в оператор iOp...
//
  if(sumEdgesIn < nEdgesInOp) // MIN ¬’ќƒќ¬ по всем опер. €русов minTier-maxTier
  {
   nEdgesInOp = sumEdgesIn;
   iOpMinIn = iOp; // запомнили номер оператора
  }

 } // конец цикла по i
   // конец цикла по j
//
 return iOpMinIn; // оператор с MIN входов на €русах minTier - maxTier
//
} // --- конец GetOpByInMinOnTiers ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetOpByMinOutOnTiers(INT minTier, INT maxTier)
{ // --- вернуть номер оператора с MIN ¬џ’ќƒќ¬ на €русах с minTier по maxTier
 INT nEdgesOutOp = nEdges,  // больше быть не может
     iOp,iOpMinOut, sumEdgesOut;
//
 if( !flagExistsTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 for(INT j=minTier; j<=maxTier; j++) // по всем €русам с minTier по maxTier
 for(INT iOpOnTier=1; iOpOnTier<=Tiers(j,0); iOpOnTier++) // по всем этим операторам €руса Tier
 {
  iOp = Tiers(j,iOpOnTier); // вз€ли номер iOpOnToer по счЄту оператора на €русе j
//
  sumEdgesOut = 0; // суммируем в переменной sumEdgesIn
  for(INT iEdge = 0; iEdge < nEdges; iEdge ++ ) // по всем дугам графа ========
   if( Edges(0,iEdge) == iOp ) // нашли дугу, ¬џ’ќƒяў”ё из оператора iOp
    sumEdgesOut ++ ; // суммируем число дуг, ¬џ’ќƒяў»’ из оператор iOp...
//
  if(sumEdgesOut < nEdgesOutOp) // MIN ¬џ’ќƒќ¬ по всем опер. €русов minTier-maxTier
  {
   nEdgesOutOp = sumEdgesOut;
   iOpMinOut = iOp; // запомнили номер оператора
  }
//
 } // конец цикла по i
   // конец цикла по j
//
 return iOpMinOut; // оператор с MIN выходов на €русах minTier-maxTier
//
} // --- конец GetOpByOutMinOnTiers --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall AddEdge(INT fromOp, INT toOp)
{ // --- прибавл€ет дугу и провер€ет, есть ли еще место в Mem_Edges[][] ----------
 char str[_256];

 if( !flagExistsEdges ) // нет массива Mem_Edges[][]...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }

//////////////////////c/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//////////////////////c/////////////////////////////////////////////////////////

 if( ( nEdges+3 ) < Max_Edges ) // размера массива Mem_Edges[][] ещЄ хватает!..
  goto cont;
//
 Max_Edges *= stockMem; // увеличили в stockMem раз
 Mem_Edges = (me*) realloc( Mem_Edges, Max_Edges * sizeof(INT) ); // реаллокировали пам€ть под Mem_Edges[][]...
//
 if( !Mem_Edges ) // совсем плохо - пам€ть в "куче" закончилась
 {
  snprintf(str,sizeof(str), "Ќехватка пам€ти дл€ размещени€ массива ƒ”√ (00). «атребовано %d элементов...",
                             Max_Edges );
  MessageBox(0, str, "ѕредупреждение", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  MessageBeep(MB_OK); // звуковое предупреждение...
  flagExistsEdges = false ; // массив Mem_Edges[][] не создан...
  return false ;
 }
//
 t_printf( "\n-I- ћассив ƒ”√ (00) перераспределЄн на %d x %d = %d элементов -I-",
                  Max_Edges );
//
 cont: // не надо дополнительно аллокировать пам€ть дл€ Mem_Edges[][]
//
//////////////////////c/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 nEdges ++ ;
//
 Edges(0,nEdges) = fromOp; // дуга "откуда"
 Edges(1,nEdges) = toOp;   // дуга "куда"
//
 return true; // дуга успешно добавлена
//
} // --- конец AddEdge ---------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetFirstToOpFromOp(INT fromOp)
{ // --- вернуть ѕ≈–¬џ… по счЄту оператор toOp, €вл€ющийс€ ¬џ’ќƒяў»ћ
// --- по дуге графа относительно fromOp
//
 if( !flagExistsEdges ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам графа...
  if( Edges(0,iEdge) == fromOp ) // нашли fromOp ( "откуда" )
   return Edges(1,iEdge) ; // вернули toOp ( "куда" )
//
} // --- конец  GetFirstToOpFromOp ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetFirstFromOpToOp(INT toOp)
{ // --- вернуть ѕ≈–¬џ… по счЄту оператор fromOp, €вл€ющийс€ ¬’ќƒяў»ћ
// --- по дуге графа относительно toOp
//
 if( !flagExistsEdges ) // массив Mem_Edges[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам графа...
  if( Edges(1,iEdge) == toOp ) // нашли toOp ( "куда" )
   return Edges(0,iEdge) ; // вернули fromOp ( "откуда" )
//
} // --- конец  GetFirstFromOpToOp ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierFirstMaxOps(INT Tier1, INT Tier2)
{ // возвращает ѕ≈–¬џ… #€руса с MAX по диапазону €русов (Tier1-Tier2) числом операторов
// - если экстремумов (одинаковых) несколько - возвращаетс€ ѕ≈–¬џ… из них (c Tier = min)
 INT TierMaxOp = - _maxOpsOnTier , // дл€ поиска MAX
     Tier;
//
 if( !flagExistsTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier1 < 1 ) || ( Tier1 > nTiers ) || // "или"
     ( Tier2 < 1 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 if( Tier2 < Tier1 ) // неверен диапазон Tier1 - Tier2
 {
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // по заданным €русам яѕ‘ ---------
  if ( Tiers(iTier,0) > TierMaxOp ) // ищем MAX...
  {
   TierMaxOp = Tiers(iTier,0); // число операторов на €русе iTier
   Tier = iTier; // запомнили iTier с “≈ ”ў»ћ максимумом операторов
  }
//
 return Tier ;
//
} // --- конец  c_GetTierFirstMaxOps -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierLastMaxOps(INT Tier1, INT Tier2)
{ // возвращает ѕќ—Ћ≈ƒЌ»… #€руса с MAX по диапазону €русов (Tier1-Tier2) числом операторов
// - если экстремумов (одинаковых) несколько - возвращаетс€ ѕќ—Ћ≈ƒЌ»… из них (c Tier = max)
 INT TierMaxOp = - _maxOpsOnTier , // дл€ поиска MAX
     Tier;
 char w[_256];
//
 if( !flagExistsTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier1 < 1 ) || ( Tier1 > nTiers ) ||
     ( Tier2 < 1 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 if( Tier2 < Tier1 ) // неверен диапазон Tier1 - Tier2
 {
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // по заданным €русам яѕ‘ ---------
  if ( Tiers(iTier,0) >= TierMaxOp ) // ищем MAX...
  {
   TierMaxOp = Tiers(iTier,0); // число операторов на €русе iTier
   Tier = iTier; // запомнили iTier с “≈ ”ў»ћ максимумом операторов
  }
//
 return Tier ;
//
} // --- конец  c_GetTierLastMaxOps --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierFirstMinOps(INT Tier1, INT Tier2)
{ // возвращает ѕ≈–¬џ… #€руса с MIN по диапазону €русов (Tier1-Tier2) числом операторов
// - если экстремумов (одинаковых) несколько - возвращаетс€ ѕ≈–¬џ… из них (c Tier = min)
 INT TierMinOp = _maxOpsOnTier , // дл€ поиска MIN
     Tier;
//
 if( !flagExistsTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier1 < 1 ) || ( Tier1 > nTiers ) ||
     ( Tier2 < 1 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1,  ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 if( Tier2 < Tier1 ) // неверен диапазон Tier1 - Tier2
 {
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // по всем €русам яѕ‘ ------------
  if ( Tiers(iTier,0) < TierMinOp ) // ищем MIN...
  {
   TierMinOp = Tiers(iTier,0); //  число операторов на €русе iTier
   Tier = iTier; // запомнили iTier с “≈ ”ў»ћ минимумом операторов
  }
//
 return Tier ;
//
} // --- конец  c_GetTierFirstMinOps -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierLastMinOps(INT Tier1, INT Tier2)
{ // возвращает ѕќ—Ћ≈ƒЌ»… #€руса с MIN по диапазону €русов (Tier1-Tier2) числом операторов
// - если экстремумов (одинаковых) несколько - возвращаетс€ ѕѕќ—Ћ≈ƒЌ»… из них (c Tier = max)
 INT TierMinOp = _maxOpsOnTier , // дл€ поиска MIN
     Tier;
//
 if( !flagExistsTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier1 < 0 ) || ( Tier1 > nTiers ) ||
     ( Tier2 < 0 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 if( Tier2 < Tier1 ) // неверен диапазон Tier1 - Tier2
 {
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // по всем €русам яѕ‘ ------------
  if ( Tiers(iTier,0) <= TierMinOp ) // ищем MIN...
  {
   TierMinOp = Tiers(iTier,0); //  число операторов на €русе iTier
   Tier = iTier; // запомнили iTier с “≈ ”ў»ћ минимумом операторов
  }
//
 return Tier ;
//
} // --- конец  c_GetTierLastMinOps --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsOpExistOnTier(INT Op, INT Tier)
{ // возвращает true только если оператор Op присутствует на €русе Tier

 for(INT jOpOnTier=1; jOpOnTier<=Tiers(Tier,0); jOpOnTier++) // по всем операторам €руса Tier
  if( Tiers(Tier,jOpOnTier) == Op ) // нашли искќмый оператор Op !..
   return true;

 return false;

} // --- конец  c_IsOpExistOnTier ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsOpDependOnlyAboveTiers(INT toOp, INT Tier)
{ // true - только если оператор toOp зависит (ѕќ ¬—≈ћ свом In-дугам)
// - исключительно от from-операторов, наход€щихс€ на €русах с 1 по Tier-1
// - используетс€ дл€ тестировани€ принадлежности оператора toOp €русу Tier
// - используютс€ вызовы IsOpExistOnTier(*,*) и GetInToOp(*)
 INT fromOp, iTier,
     sumIn = 0; // дл€ суммировани€ числа In'ов
// --- ищем, ќ“  ј »’ операторов зависит toOp ----------------------------------
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам графа...
 {
//
  if( Edges(1,iEdge) == toOp ) // нашли (очередную) дугу к оператору toOp
  {
   fromOp = Edges(0,iEdge); // нашли fromOp, соответствующий заданному toOp
// --- ищем fromOp среди операторов на €русах с 1 по Tier-1 (т.е. ¬џЎ≈ данного Tier)
   for(iTier=0; iTier<=Tier-1; iTier++) // просмотр €русов с 0 по Tier-1
    if ( c_IsOpExistOnTier( fromOp, iTier ) == true ) // оператор fromOp присутствует на €русе iTier...
     sumIn ++ ; // суммируем число найденных fromOp на €русах с 0 по Tier-1
  } // конец if ( Mem_Edges[1][iEdge] == toOp )
//
 } // конец цикла по iEdge
//
 if( sumIn == c_GetCountInEdgesByOp(toOp) ) // насчитали столько In, сколько есть у оператора toOp ?
  return true; // тогда все ¬’ќƒяў»≈ в toOp оператор дуги наход€тс€ на €русах от 0 до Tier-1
 else
  return false;
//
} // --- конец  c_IsOpDependOnlyAboveTiers -------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetCountInOp(INT toOp, INT Numb)
{ // --- вернуть from-оператор, соответствующий Numb-той In-дуге дл€ to-оператора toOp
// ----- всего число вход€щих (In) дуг дл€ оператора Op даЄт вызов GetInToOp( Op )
// ----- если неудача - возвращаетс€ -1
 INT nIn = 0;
//
 if( !flagExistsEdges ) // массив Mem_Edges[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам графа
 {
//
  if( Edges(1,iEdge) == toOp )  // нашли дугу, ¬’ќƒяў”ё в нужный оператор toOp
   nIn ++ ;
  if( nIn == Numb ) // если эта дуга дл€ toOp €вл€етс€ Numb-той...
   return Edges(0,iEdge); // возвращаем соответствующий from-оператор
 }
//
 return ERR_COMMON ;
//
} // --- конец GetCountInOp ----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetCountOutOp(INT fromOp, INT Numb)
{ // --- вернуть to-оператор, соответствующий Numb-той Out-дуге дл€ from-оператора fromOp
// ----- всего число выход€щих (Out) дуг дл€ оператора Op даЄт вызов GetOutToOp( Op )
// ----- если неудача - возвращаетс€ -1
 INT nOut = 0;
//
 if( !flagExistsEdges ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам графа
 {
//
  if( Edges(0,iEdge) == fromOp )  // нашли дугу, ¬’ќƒяў”ё в нужный оператор fromOp
   nOut ++ ;
  if( nOut == Numb ) // если эта дуга дл€ fromOp €вл€етс€ Numb-той...
   return Edges(1,iEdge); // возвращаем соответствующий to-оператор
 }
//
 return ERR_COMMON ;
//
} // --- конец GetCountOutOp ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetMaxTierMaybeOp(INT Op)
{ // --- возвращает MAX номер €руса, на котором ћќ∆≈“ –ј—ѕќЋј√ј“№—я оператор Op
// ----- дл€ первого и последнего €русов возвращаетс€ номер исходного €руса ----
 INT toOp, toTier,
     retTier = nTiers;
//
 if( !flagExistsTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( c_IsOpExistOnTier(Op, 0) ) // ...оператор Op находитс€ на Ќ”Ћ≈¬ќћ €русе
  return 0 ; // его никуда не переносим!
//
 if( c_IsOpExistOnTier(Op, nTiers) ) // ...оператор Op находитс€ на последнем €русе
  return nTiers ; // ниже перенести невозможно!
//
// ===== необычный случай - оператор не имеет ¬џ’ќƒ€ў»’ дуг "»" ================
// ==== располќжен не на ѕќ—Ћ≈ƒЌ≈ћ €русе !!! ===================================
 if( !c_GetCountOutEdgesByOp( Op ) && // число ¬џ’ќƒ€ў»’ дуг нулевое..!!!!!!!!!!!!!!!!!!!!
     !c_IsOpExistOnTier(Op, nTiers) ) // не на последнем €русе
  return nTiers ; // такому оператору можно и до ѕќ—Ћ≈ƒЌ≈√ќ €руса спускатьс€...
////////////////////////////////////////////////////////////////////////////////
//
// --- у оператора Op имеетс€ GetInToOp(Op) ¬’ќƒЌџ’ (In) дуг... ищем их!
 for(INT iEdge=1; iEdge<=nEdges;  iEdge++) // по всем дугам в графе...
 {
//
  if ( Edges(0,iEdge) != Op ) // неинтересно - нужна така€ дуга, где оператор Op €вл€етс€ ¬џ’ќƒ€ў»ћ...
   continue;
//
  toOp = Edges(1,iEdge); // ему соответствует вот этот ¬’ќƒ€ў»… toOp !
//
  toTier = c_GetTierByOp ( toOp ); // оператор toOp находитс€ на €русе toTier
//
  if ( toTier < retTier ) // минимум toOp запоминаем в retTier
   retTier = toTier;
//
 } // конец цикла по iEdge
//
 return retTier - 1 ; // возвращаем номер €руса на 1 меньше
//
} // --- конец c_GetMaxTierMayBeOp ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetMinTierMaybeOp(INT Op)
{ // --- возвращает MIN номер €руса, на котором ћќ∆≈“ –ј—ѕќЋј√ј“№—я оператор Op
// ----- дл€ первого и последнего €руса возвращаетс€ номер исходного €руса -----
 INT fromOp, fromTier,
     retTier = 0;
//
 if( !flagExistsEdges ) // массив Mem_Edges[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 if( c_IsOpExistOnTier(Op, 1) ) // ...оператор Op находитс€ на первом €русе
  return 1 ; // выше перенести невозможно!
//
// --- у оператора Op имеетс€ GetInToOp(Op) ¬’ќƒЌџ’ (In) дуг... ищем их!
 for(INT iEdge=1; iEdge<=nEdges;  iEdge++) // по всем дугам в графе...
 {
//
  if ( Edges(1,iEdge) != Op ) // неинтересно - нужна така€ дуга, где оператор Op €вл€етс€ ¬’ќƒ€ў»ћ...
   continue;
//
  fromOp = Edges(0,iEdge); // ему соответствует вот этот ¬џ’ќƒ€ў»… fromOp !
//
  fromTier = c_GetTierByOp ( fromOp ); // оператор fromOp находитс€ на €русе fromTier
//
  if ( fromTier > retTier ) // максимум fromOp запоминаем в retTier
   retTier = fromTier;
//
 } // конец цикла по iEdge
//
 return retTier + 1 ; // возвращаем номер €руса на 1 больше
//
} // --- конец c_GetMinTierMayBeOp ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_MoveOpTierToTier(INT Op, INT toTier)
{ // переносит оператор Op на €рус toTier с проверкой корректности действи€
// ни €рус первоначального нахождени€ Op ни toTier не могут быть €русами первым или последним
// если удалось благополучно перенести - возвращаетс€ true и глобальное nMoves инкрементируетс€ на 1
// попытка перемещени€ на €рус расположени€ оператора Op ошибкой не считаетс€ ..!
// если всЄ нормально - возвращаетс€ 0
//
 if( !flagExistsTiers ) // если массива Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 INT fromTier = c_GetTierByOp( Op ); // €рус первоначального нахождени€ оператора Op
//
// t_printf( "- Op= #%d fromTier= %d toTier= %d =", Op,fromTier,toTier );
 if( fromTier == toTier ) // формально никакой ошибки нет ..!
  return RETURN_OK ;
//
 if( ( toTier < c_GetMinTierMaybeOp( Op ) ) || // проверка допуст»мости переноса
     ( toTier > c_GetMaxTierMaybeOp( Op ) ) )
 {
  DisplayMessage( "E", __FUNC__, messParams3, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( ( Tiers(toTier,0)+1 ) >= _maxOpsOnTier ) // не помещаемс€ в _maxOpsOnTier...
  if( IncreaseOpsOnTier( toTier, _maxOpsOnTier * stockMem, 111 ) == false ) // неудача перераспределени€ пам€ти
  {
   flagExistsTiers = false ; // массив Tiers[][] не создан...
   return ERR_NOT_MEMORY ;
  }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// --- добавл€ем оператор Op на €рус toTier ------------------------------------
// --- считаем, что второго оператора с таким номером быть не может - это не провер€ем!
 Tiers(toTier,0) ++ ; // увеличили число операторов на €русе toTier
 Tiers(toTier,Tiers(toTier,0) ) = Op;
//
// --- убираем оператор Op c €руса fromTier ------------------------------------
 for(INT j=1; j<=Tiers(fromTier,0); j++) // по операторам €руса fromTier
  if( Tiers(fromTier,j) == Op )
  {
   for(INT jj=j; jj<Tiers(fromTier,0); jj++) // сдвигаем на позицию влево
    Tiers(fromTier,jj) = Tiers(fromTier,jj+1);
//
   Tiers(fromTier,0) -- ; // уменьшили на единицу число операторов на €русе fromTier
//
   nMoves ++ ; // глобал дл€ подсчЄта числа успешных перемещений
//
   flagCalcTLD = false ; // paramsTLD не соответствует Tiers[][]
//
   return RETURN_OK ;
//
  } // конец if
//
} // --- конец c_MoveOpTierToTier ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_AddTier(INT Tier)
{ // --- создаЄт (пустой) €рус Ќ»∆≈ €руса Tier (кроме последнего)
// ----- св€зи не мен€ютс€; возвращает true, если удачно
 char str[_2048];
//
 if( !flagExistsTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier <  1 ) ||  // этого нельз€...  а всЄ остальное ћќ∆Ќќ !
     ( Tier > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// if( ( nTiers+1 ) >= _maxTiers ) // не хватает строк в массиве Tiers[][]
 if( ( nTiers+3 ) >= _maxTiers ) // то же самое, но «јѕј— побольше будет
 {
// --- увеличиваем _maxTiers, а _maxOpsInTier оставл€ем тем же самым -----------
// --- в этом случае можно использовать realloc, обеспечивающий сохранность данных
   _maxTiers *= stockMem; // новое число строк с запасом stockMem
//
   pTiers = (INT*) realloc( pTiers, (_maxTiers+1) * (_maxOpsOnTier+1) * sizeof(INT) ); // захват пам€ти под новый массив
//
   if( !pTiers ) // совсем плохо - пам€ть в "куче" закончилась
   {
    snprintf(str,sizeof(str), "%s(): нехватка пам€ти дл€ размещени€ массива я–”—ќ¬ (Prim0). «атребовано %d x %d = %d элементов...",
                 _maxTiers+1, _maxOpsOnTier+1, (_maxTiers+1) * (_maxOpsOnTier+1));
    MessageBeep(MB_OK); // звуковое предупреждение...
    flagExistsTiers = false ; // массив Tiers[][] не создан...
    DisplayMessage( "E", __FUNC__, str, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
    return ERR_NOT_MASSIVE_TIERS ;
   } // конец if ( npTiers == NULL )
//
   snprintf(str,sizeof(str), "ћассив я–”—ќ¬ (Prim0) перераспределЄн на %d x %d = %d элементов",
                 _maxTiers+1, _maxOpsOnTier+1, (_maxTiers+1) * (_maxOpsOnTier+1));
   DisplayMessage( "I", __FUNC__, str, 0 ); // выдать сообщение
  }  // конец if( nTiers+1 >= _maxTiers ) ...
//
// --- всЄ сделано - можно продолжать работать уже с новым pTiers --------------
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 nTiers ++ ; // увеличили число €русов на 1
//
// --- сдвигаем €русы с Tier по nTiers-1 вниз ----------------------------------
 for(INT iTier=nTiers; iTier>Tier; iTier--) // по €русам снизу вверх
  for(INT j=0; j<=Tiers(iTier-1,0); j++) // цикл по "верхнему" из двух
   Tiers(iTier,j) = Tiers(iTier-1,j); // "верхний" переносим в "нижний"
//
 Tiers( Tier+1,0 ) = 0; // вновь созданный €рус ѕ”—“ !
//
 flagCalcTLD = false ; // paramsTLD не соответствует Tiers[][]
//
 return RETURN_OK ; // успешно выполнено
//
} // --- конец c_AddTier -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_DelTier(INT Tier)
{ // --- уничтожает (пустой) €рус Tier (кроме нулевого)
// ----- св€зи не мен€ютс€; возвращает true, если удачно
//
 if( !flagExistsTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier <= 0 ) ||  // этого нельз€!..
     ( Tier >  nTiers ) ||
     ( ( Tiers(Tier,0) != 0 ) ) ) // этот €рус не ѕ”—“ !
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
// --- сдвигаем €русы с Tier+1 по nTiers вверх ---------------------------------
 for(INT iTier=Tier; iTier<=nTiers; iTier++) // по €русам сверху внизх
  for(INT j=0; j<=Tiers(iTier+1,0); j++) // цикл по "нижнему" из двух
   Tiers(iTier,j) = Tiers(iTier+1,j); // "нижний" переносим в "верхний"
//
 nTiers -- ; // €русов стало на 1 меньше...
//
 flagCalcTLD = false ; // paramsTLD не соответствует Tiers[][]
//
 return true ; // успешно выполнено
//
} // --- конец c_DelTier -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountEdges()
{ // возвращает общее число дуг в информационном графе алгоритма (»√ј)
//
 if( !flagExistsEdges ) // нет массива Mem_Edges[][]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 return nEdges ;
} // --- конец c_GetCountEdges -------------------------------------------------
     
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountTiers()
{ // возвращает число €русов в яѕ‘ информационного графа алгоритма (»√ј) без входного (нулевого) €руса
//
 if( !flagExistsTiers ) // нет массива Tiers[][]
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 return nTiers ;
} // --- конец c_GetCountTiers -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetOpsMoves()
{ // возвращает текущее значение числа перемещений операторов с €руса на €рус яѕ‘
 return nMoves ;
} // --- конец c_GetOpsMoves -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CountMovesZeroing()
{ // обнул€ет значение счЄтчика числа перемещений операторов с €руса на €рус яѕ‘
 INT old_nMoves = nMoves ; // запомнили "старое" значение
 nMoves = 0 ; // обнулили счЄтчик числа перемещений
 return old_nMoves ; // вернули "старое" значение счЄтчика
} // --- конец c_GetOpsZeroing -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOpsOnTier(INT Tier)
{ // возвращает количество операторов на €русе Tier дл€ яѕ‘ данного »√ј
//
 if( ( Tier < 0 ) || ( Tier > nTiers) ) // проверка допустимости значени€ Tier
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 return Tiers(Tier,0) ;
} // --- конец c_GetCountOpsInTier----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetOpByNumbOnTier(INT Numb, INT Tier)
{ // возвращает номер Numb-ного по счЄту оператора на €русе Tier
//
 if( ( Tier < 0 ) || ( Tier > nTiers ) ) // проверка допустимости значени€ Tier
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 if( ( Numb < 1 ) || ( Numb > Tiers(Tier,0) ) ) // проверка допустимости значени€ Numb
 {
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 return Tiers(Tier,Numb) ;
//
} // --- конец c_GetOpByNumbOnTier----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_AddLineToTextFrame(char *str)
{ // добавл€ет строку str в окно текстового представл≈ни€ данных (учитываетс€ "\n")
 char c, cc[2] = "?\0", buf[_16384] = "\0"; // buf - "рабоча€" строка дл€ вывода
//
 for(int Pos=0; Pos<=strlen(str); Pos++) // Pos - номер символа в строке str
 {
  c = str[Pos]; // прочитали Pos-й символ строки str
  if ( (c != '\n') && (c != '\0') ) // это не UPR-символ (управл€ющий) и не конец строки
  {
   cc[0] = c;
   strcat( buf, cc ); // добавл€ем символ с в buf
  } // конец if( c != UPR )
//
  else
//
//  if( (c=='\n') || (c=='\0') ) // управл€ющий символ или конец строки
  {
   TM1->Lines->Add( buf ); // вывод строки buf в M1
   strNcpy( buf, "" ); // очистили строку w дл€ дальнейшей работы
//
  }
//
 } // конец по символам строки str
//
 return true ; // дл€ Lua всегда надо что-то возвратить (void не допускаетс€!)
//
} // --- конец c_AddLineToTextFrame --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ClearTextFrame()
{ // очищает окно  текстового представл≈ни€
 TM1->Clear(); // очистка M1
 return true ; // дл€ Lua всегда надо что-то возвратить (void не допускаетс€!)
} // --- конец ClearTextFrame --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_DelayMS(INT Sec)
{ // ждЄт Sec секунд, дава€ при этом поработать Windows
 Delay ( Sec ); // ждать Sec секунд
 return true ; // дл€ Lua всегда надо что-то возвратить (void не допускаетс€!)
} // --- конец c_DelayMS -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutTiersToTextFrame()
{ // выдаЄт яѕ‘ (массив Tiers[][]) в окно дл€ текстовой визуализации
 char str[_16384], tmp[_512];
//
 if( !flagExistsTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 t_printf( "\n-=- ярусов яѕ‘ = %d -=-", nTiers ); // строка с числом €русов (без входного)
//
// --- выводим в M1 номера операторов по €русам --------------------------------
 for(INT iTier=0; iTier<=nTiers; iTier++) // по всем вы€вленным €русам яѕ‘ (без входного)
 {
  snprintf(str,sizeof(str), "%d|%d: ", iTier,Tiers(iTier,0)); // готовим строку (iTier €рус) дл€ вывода в M1
//
  for(INT j=1; j<=Tiers(iTier,0); j++) // по номерам операторов на €русе iTier
  {
   if( !c_GetCountInEdgesByOp( Tiers(iTier,j) )) // у этого оператора нет ¬’ќƒ€ў»’ дуг...
    snprintf(tmp,sizeof(tmp), " " _IN "%d", Tiers(iTier,j)); // это выходной оператор (результат программы)
   else
   if( !c_GetCountOutEdgesByOp( Tiers(iTier,j) )) // у этого оператора нет ¬џ’ќƒ€ў»’ дуг...
    snprintf(tmp,sizeof(tmp), " %d" _OUT , Tiers(iTier,j)); // это выходной оператор (результат программы)
   else
    snprintf(tmp,sizeof(tmp), " %d", Tiers(iTier,j) ); // порци€ очередного оператора дл€ выводной строки
//
   strcat(str, tmp); // накапливаем выводную строку в str

  } // конец цикла по j
//
  c_AddLineToTextFrame( str ); // вывод готовой строки в M1 (€рус iTier)
//
 } // конец цикла по iTier (€русам яѕ‘)
//
 return true ; // всЄ успешно сделано
//
} // --- конец c_PutTiersToTextFrame -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutEdgesToTextFrame()
{ // выдаЄт массив дуг Mem_Edges[][] в окно дл€ визуализации
 char str[_2048];
//
 if( !flagExistsEdges ) // если массив Edges[][] пуст - выйти и вернуть false
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 t_printf( "\n-=- ƒуг »√ј = %d -=-", nEdges ); // строка с общим числом дуг
//
// --- выводим в M1 все дуги
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по всем вы€вленным дугам информационного графа алгоритма
  t_printf( "#%d: %d -> %d", iEdge, Edges(0,iEdge), Edges(1,iEdge) ); // готовим строку дл€ дуги iEdge
//
 return true; // всЄ нормально - массив Mem_Edges[][] выдан в текстовое окно
//
} // --- конец c_PutEdgesToTextFrame--------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_SoundPlay(char FileName[])
{ // проиграть мелодию из заданного файла
 return PlaySound( FileName, 0, SND_SYNC ); // проиграть файл в синхронном режиме (ждать конца проигрыша)
} // --- конец c_PlaySound------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall TestExistInOutAtAllOps()
{ // тестирует наличие хоть одной ¬’ќƒЌќ… или ¬џ’ќƒЌќ… дуги у каждого оператора
 INT Op; // номер оператора
 char str[_256];
 bool Err = false; // возвращаемое значение
//
 if( !flagExistsTiers ) // нет массива Tiers[][]
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 for(INT iTier=1; iTier<=nTiers; iTier++) // по всем €русам яѕ‘
  for(INT j=1; j<=Tiers(iTier,0); j++) // по операторам на этом €русе
  {
   Op = Tiers(iTier,j); // вз€ли номер оператора
//
// --- тест на наличие ¬’ќƒяў»’ дуг --------------------------------------------
   if( !c_GetCountInEdgesByOp( Op ) && ( iTier != 1 ) ) // не на ѕ≈–¬ќћ €русе "»" ¬’ќƒяў»’ дуг нет
   {
    t_printf( "\n-W- ќператор %d не на ѕ≈–¬ќћ €русе %d не имеет ¬’ќƒяў»’ дуг -W-", Op, iTier );
    Err = true ;
   }
//
// --- тест на наличие ¬џ’ќƒяў»’ дуг -------------------------------------------
   if( !c_GetCountOutEdgesByOp( Op ) && ( iTier != nTiers ) ) // не на ѕќ—Ћ≈ƒЌ≈ћ €русе "»" ¬џ’ќƒяў»’ дуг нет
   {
    t_printf( "\n-W- ќператор %d не на ѕќ—Ћ≈ƒЌ≈ћ €русе %d не имеет ¬џ’ќƒяЎ»’ дуг -W-", Op, iTier );
    Err = true ;
   }
//
  } // конец цикла по j
//
 if( !Err ) // информационное сообщение
 {
  MessageBeep(MB_OK); // звуковое предупреждение...
  SB0->Text = " ¬се операторы имеют хот€ бы по одной ¬’ќƒяў≈… и ¬џ’ќƒяў≈… дуге...";
  Delay( -1 ); // ждЄм 1 сек
 }
//
 return Err ;
//
} // --- конец TestExistInOutAtOp-----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountInEdgesByOp(INT Op)
{ // --- вернуть число ¬’ќƒяў»’ дуг дл€ оператора Op ---------------------------
 INT nIn = 0, iEdge;
//
 if( !flagExistsEdges ) // массив Mem_Edges[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
//
 for(INT i=0; i<=1; i++) // проверка наличи€ Op в списке операторов
  for(iEdge=1; iEdge<=nEdges; iEdge++)
   if( Op == Edges(i,iEdge) )
    goto find_Op;
//
 return ERR_IN_DATA; // оператор Op не входит в список существующих
//
find_Op: // оператор Op входит в список существующих
//
 for(iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам графа
  if( Edges(1,iEdge) == Op )  // нашли дугу, ¬’ќƒяў”ё в нужный оператор Op...
   nIn ++ ;
//
 return nIn ; // тождественно 0, если это входной (исходные данные дл€ выполнени€ алгоритма) оператор
//
} // --- конец c_GetCountInEdgesByOp -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOutEdgesByOp(INT Op)
{ // --- вернуть число ¬џ’ќƒяў»’ дуг дл€ оператора Op --------------------------
 INT nOut = 0, iEdge;
//
 if( !flagExistsEdges ) // массив Mem_Edges[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
////////////////////////////////////////////////////////////////////////////////
//
 for(INT i=0; i<=1; i++) // проверка наличи€ Op в списке операторов
  for(iEdge=1; iEdge<=nEdges; iEdge++)
   if(Op == Edges(i,iEdge))
    goto find_Op;
//
 return ERR_IN_DATA; // оператор Op не входит в список существующих
//
find_Op: // оператор Op входит в список существующих
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам графа
  if( Edges(0,iEdge) == Op )  // нашли дугу, ¬џ’ќƒяў”ё из нужного оператора...
   nOut ++ ;
//
 return nOut ; // тождественно 0, если это выходной (результат выполнени€ алгоритма) оператор
//
} // --- конец c_GetCountOutEdgesByOp ------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbInEdgeByOp(INT Numb, INT Op)
{ // --- вернуть номер оператора, соответствуюший Numb-той ¬’ќƒяў≈… дуге дл€ оператора Op
 INT nIn = 0,
     maxNumb = c_GetCountInEdgesByOp( Op ); // общее число ¬’ќƒяў»’ дуг оператора Op
//
 if( !flagExistsEdges ) // массив Mem_Edges[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
//
 if( ( Numb < 1 ) || ( Numb > maxNumb) ) // вне диапазона...
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам графа
  if( Edges(1,iEdge) == Op )  // нашли дугу, ¬’ќƒяў”ё в нужный оператор Op...
  {
   nIn ++ ;
   if( nIn == Numb )
    return Edges(0,iEdge) ;
  }
//
  return ERR_COMMON ; // если не нашли ни одной дуги...
//
} // --- конец c_GetNumbInEdgeByOp ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbOutEdgeByOp(INT Numb,INT Op)
{ // --- вернуть число ¬џ’ќƒяў»’ дуг дл€ оператора Op --------------------------
 INT nOut = 0,
     maxNumb = c_GetCountOutEdgesByOp( Op ); // общее число ¬џ’ќƒяў»’ дуг оператора Op;
//
 if( !flagExistsEdges ) // массив Mem_Edges[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
////////////////////////////////////////////////////////////////////////////////
//
 if( ( Numb < 1 ) || ( Numb > maxNumb ) ) // вне диапазона...
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам графа
  if( Edges(0,iEdge) == Op )  // нашли дугу, ¬џ’ќƒяў”ё из нужного оператора...
  {
   nOut ++ ;
   if( nOut == Numb )
    return Edges(1,iEdge) ;
  }
//
 return ERR_COMMON ; // если не нашли ни одной дуги...
//
} // --- конец c_GetNumbOutEdgeByOp --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// учЄт гетерогенности вычислительного пол€ ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// сторона вычислителей --------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountParamsByCalc(INT Calc)
{ // --- возвращает число параметров вычислител€ —alc --------------------------
 char str[_4096];
 INT k = 0;
//
 strNcpy( str, c_GetParamsByCalc( Calc )  ); // берЄм всю строку параметров
//
 for( INT i=0; str[i+1] != '\0'; i++ ) // по строке сравниваем по два символа
  if ( (str[i]=='-') && (isalpha(str[i+1])) ) // проверка на ЎјЅЋќЌ ['-' + лат.буква]
   k ++ ; // запомнили, какой раз встречаетс€ ['-' + лат.буква]
//
 return ( k ) ;
} // --- конец c_GetCountParamsByCalc ------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
REAL __fastcall c_GetMinValNumbParamByCalc(INT Numb, INT Calc) // мин значение параметра Numb (начина€ с 1) вычислител€ Calc
{ // выдаЄт мин значение параметра номер Numb (начина€ с 1) вычислител€ Calc ---
 char str[_1024],
      sName[_512]; // им€ параметра
 REAL minVal,maxVal; // значени€ параметров

 strNcpy( str, c_GetNumbParamByCalc( Numb, Calc ) ); // вз€ли строку параметра

 if( sscanf( str, "-%s %g %g", sName, &minVal, &maxVal ) == 3 ) // если Ok - 3 преобразованных параметра
  return min( minVal, maxVal );
 else
  return ERR_TRANSFORM ;

} // --- конец c_GetMinValNumbParamByCalc --------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
REAL __fastcall c_GetMaxValNumbParamByCalc(INT Numb, INT Calc) // мин значение параметра Numb (начина€ с 1) вычислител€ Calc
{ // выдаЄт мин значение параметра номер Numb (начина€ с 1) вычислител€ Calc ---
 char str[_1024],
      sName[_512]; // им€ параметра
 REAL minVal,maxVal; // значени€ параметров

 strNcpy( str, c_GetNumbParamByCalc( Numb, Calc ) ); // вз€ли строку параметра

 if( sscanf( str, "-%s %g %g", sName, &minVal, &maxVal ) == 3 ) // если Ok - 3 преобразованных параметра
  return max( minVal, maxVal ) ;
 else
  return ERR_TRANSFORM ;

} // --- конец c_GetMaxValNumbParamByCalc --------------------------------------

////////////////////////////////////////////////////////////////////////////////
// сторона операторов ----------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountParamsByOp(INT Op)
{ // --- возвращает число параметров оператора Op ------------------------------
 char str[_1024];
 INT k=0;

 strNcpy( str, c_GetParamsByOp( Op )  ); // берЄм всю строку параметров

 for(INT i=0; str[i+1] != '\0'; i++) // по строке сравниваем по два символа
  if ( ( str[i] == '-' ) && ( isalpha( str[i+1] ) ) ) // проверка на '-' + лат.буква
   k ++ ; // запомнили, какой раз встречаетс€ "'-'+лат.буква"

 return ( k ) ;
} // --- конец c_GetCountParamsByOp --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNameNumbParamByCalc(INT Numb, INT Calc)
{ // им€ параметра номер Numb (начина€ с 1) вычислител€ Calc -------------------
 char str[_1024],
      sName[_512]; // им€ параметра
 REAL minVal,maxVal; // значени€ параметров

 strNcpy( str, c_GetNumbParamByCalc( Numb, Calc ) ); // вз€ли строку параметра

 if( sscanf( str, "-%s %g %g", sName, &minVal, &maxVal ) == 3 ) // если Ok - 3 преобразованных параметра
  return sName ;
 else
  return "\0" ;

} // --- конец c_GetNameNumbParamByCalc ----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNameNumbParamByOp(INT Numb, INT Op)
{ // им€ параметра номер Numb (начина€ с 1) оператора Op -----------------------
 char str[_1024],
      sName[_1024]; // им€ параметра
 REAL Val; // значение параметра

 strNcpy( str, c_GetNumbParamByOp( Numb, Op ) ); // вз€ли строку параметра

 if( sscanf( str, "-%s %g", sName, &Val ) == 2 ) // если Ok - 2 преобразованных параметра
  return sName ;
 else
  return "\0" ;

} // --- конец c_GetNameNumbParamByOp ----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
REAL __fastcall c_GetValNumbParamByOp(INT Numb, INT Op)
{ // выдаЄт мин значение параметра номер Numb (начина€ с 1) оператора Op -------
 char str[_1024],
      sName[_1024]; // им€ параметра
 REAL Val; // значение параметра

 strNcpy( str, c_GetNumbParamByOp( Numb, Op ) ); // вз€ли строку параметра

 if( sscanf( str, "-%s %g", sName, &Val ) == 2 ) // если Ok - 2 преобразованных параметра
  return Val ;
 else
  return ERR_TRANSFORM ;

} // --- конец c_GetValNumbParamByOp -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_LoadFileNameParamsCalcs( char FileName[] )
{ // настроим им€ файла и прочитаем файл параметров ¬џ„»—Ћ»“≈Ћ≈…
//
 if( !FileExists( FileName ) ) // заданный файл не существует...
 {
  t_printf( "\n-W- ‘айл %s параметров ¬џ„»—Ћ»“≈Ћ≈… не существует -W-\n", FileName );
 }
 else // с файлом всЄ Ok!
 {
  strNcpy( FileNameParamsCalcs, FileName ); // запомнили текущее им€ файла параметров ¬џ„»—Ћ»“≈Ћ≈…
  c_ReadAndCorrectParamsCalcs( FileNameParamsCalcs ); // перечитываем и обрабатываем файл параметров ¬џ„»—Ћ»“≈Ћ≈…
  return true;
 } // всЄ нормально с заданным файлом... работаем дальше !
//
////////////////////////////////////////////////////////////////////////////////
 if( !FileExists( DefFileNameParamsCalcs ) ) // файл по умолчанию не существует...
  t_printf( "\n-E- ‘айл %s параметров ¬џ„»—Ћ»“≈Ћ≈… по умолчанию не существует -E-\n",
                   AnsiUpperCase(DefFileNameParamsCalcs) );
 else // с файлом всЄ Ok!
 {
  t_printf( "-I- ќбрабатываетс€ файл %s параметров ¬џ„»—Ћ»“≈Ћ≈… по умолчанию -I-\n",
                 AnsiUpperCase(DefFileNameParamsCalcs) );
//
  strNcpy( FileNameParamsCalcs, DefFileNameParamsCalcs );
  c_ReadAndCorrectParamsCalcs( FileNameParamsCalcs );
  return true;
//
 } // всЄ нормально с файлом с именем по умолчанию... работаем дальше !
//
////////////////////////////////////////////////////////////////////////////////
// --- не удалось открыть ни заданный файл, ни файл с именем по умолчанию ------
 strNcpy( sCalcs, "\0" ); // очищаем строку-пам€ть параметров ¬џ„»—Ћ»“≈Ћ≈…
 return false; // проблемы с файлом...
//
} // --- конец c_LoadFileNameParamsCalcs =======================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_LoadFileNameParamsOps( char FileName[] )
{ // настроим им€ файла и прочитаем файл параметров ќѕ≈–ј“ќ–ќ¬
 char str[_2048];

 if( !FileExists( FileName ) ) // заданный файл не существует...
 {
  t_printf( "\n-W- ‘айл %s параметров ќѕ≈–ј“ќ–ќ¬ не существует -W-\n",
                   FileName );
 }
 else // с файлом всЄ Ok!
 {
  strNcpy( FileNameParamsOps, FileName ); // запомнили текущее им€ файла параметров ќѕ≈–ј“ќ–ќ¬
  c_ReadAndCorrectParamsOps( FileNameParamsOps ); // перечитываем и обрабатываем файл параметров ќѕ≈–ј“ќ–ќ¬
  return true;
 } // всЄ нормально с заданным файлом... работаем дальше !

////////////////////////////////////////////////////////////////////////////////
 if( !FileExists( DefFileNameParamsOps ) ) // файл по умолчанию не существует...
  t_printf( "\n-E- ‘айл %s параметров ќѕ≈–ј“ќ–ќ¬ по умолчанию не существует -E-\n",
                   AnsiUpperCase(DefFileNameParamsOps) );
 else // с файлом всЄ Ok!
 {
  t_printf( "-I- ќбрабатываетс€ файл %s параметров ќѕ≈–ј“ќ–ќ¬ по умолчанию -I-\n",
                 AnsiUpperCase(DefFileNameParamsOps) );

  strNcpy( FileNameParamsOps, DefFileNameParamsOps );
  c_ReadAndCorrectParamsOps( FileNameParamsOps );
  return true;
//
 } // всЄ нормально с файлом с именем по умолчанию... работаем дальше !
//
////////////////////////////////////////////////////////////////////////////////
// --- не удалось открыть ни заданный файл, ни файл с именем по умолчанию ------
 strNcpy( sOps, "\0" ); // очищаем строку-пам€ть параметров ќѕ≈–ј“ќ–ќ¬

 return false; // проблемы с файлом...

} // --- конец c_LoadFileNameParamsOps =========================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_LoadFileNameParamsEdges( char FileName[] )
{ // настроим им€ файла и прочитаем файл метрик ƒ”√
//
 if( !FileExists( FileName ) ) // заданный файл не существует...
 {
  t_printf( "\n-W- ‘айл %s параметров ƒ”√ не существует -W-\n", FileName );
 }
 else // с файлом всЄ Ok!
 {
  strNcpy( FileNameParamsEdges, FileName ); // запомнили текущее им€ файла параметров ƒ”√
  c_ReadAndCorrectParamsEdges( FileNameParamsEdges ); // перечитываем и обрабатываем файл параметров ƒ”√
  return true;
 } // всЄ нормально с заданным файлом... работаем дальше !
//
////////////////////////////////////////////////////////////////////////////////
 if( !FileExists( DefFileNameParamsEdges ) ) // файл по умолчанию не существует...
  t_printf( "\n-E- ‘айл %s параметров ƒ”√ по умолчанию не существует -E-\n",
                   AnsiUpperCase(DefFileNameParamsEdges) );
 else // с файлом всЄ Ok!
 {
  t_printf( "-I- ќбрабатываетс€ файл %s параметров ƒ”√ по умолчанию -I-\n",
                 AnsiUpperCase(DefFileNameParamsEdges) );
  strNcpy( FileNameParamsEdges, DefFileNameParamsEdges );
  c_ReadAndCorrectParamsEdges( FileNameParamsEdges );
  return true;
//
 } // всЄ нормально с файлом с именем по умолчанию... работаем дальше !
//
////////////////////////////////////////////////////////////////////////////////
// --- не удалось открыть ни заданный файл, ни файл с именем по умолчанию ------
 strNcpy( sEdg, "" ); // очищаем строку-пам€ть параметров ƒ”√
 return false; // проблемы с файлом...
//
} // --- конец c_LoadFileNameParamsEdges =======================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_LoadFileNameParamsVertices( char FileName[] )
{ // настроим им€ файла и прочитаем файл метрик ¬≈–Ў»Ќ
//
  if( !FileExists( FileName ) ) // заданный файл не существует...
 {
  t_printf( "\n-W- ‘айл %s параметров ¬≈–Ў»Ќ не существует -W-\n", FileName );
 }
 else // с файлом всЄ Ok!
 {
  strNcpy( FileNameParamsVertices, FileName ); // запомнили текущее им€ файла параметров ¬≈–Ў»Ќ
  c_ReadAndCorrectParamsVertices( FileNameParamsVertices ); // перечитываем и обрабатываем файл параметров ¬≈–Ў»Ќ
  return true;
 } // всЄ нормально с заданным файлом... работаем дальше !
//
////////////////////////////////////////////////////////////////////////////////
 if( !FileExists( DefFileNameParamsVertices ) ) // файл по умолчанию не существует...
  t_printf( "\n-E- ‘айл %s параметров ¬≈–Ў»Ќ по умолчанию не существует -E-\n",
                   AnsiUpperCase(DefFileNameParamsVertices) );
 else // с файлом всЄ Ok!
 {
  t_printf( "-I- ќбрабатываетс€ файл %s параметров ¬≈–Ў»Ќ по умолчанию -I-\n",
                 AnsiUpperCase(DefFileNameParamsVertices) );

  strNcpy( FileNameParamsVertices, DefFileNameParamsVertices );
  c_ReadAndCorrectParamsVertices( FileNameParamsVertices );
  return true;
//
 } // всЄ нормально с файлом с именем по умолчанию... работаем дальше !
//
////////////////////////////////////////////////////////////////////////////////
// --- не удалось открыть ни заданный файл, ни файл с именем по умолчанию ------
 strNcpy( sVrt, "\0" ); // очищаем строку-пам€ть параметров ¬≈–Ў»Ќ
 return false; // проблемы с файлом...
//
} // --- конец c_LoadFileNameParamsVertices ====================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountParamsInString( char* str )
{ // --- возвращает число параметров в строке str ------------------------------
 INT k=0;
//
 for( INT i=0; str[i+1] != '\0'; i++ ) // по строке сравниваем по два символа
  if ( (str[i]=='-') && (isalpha(str[i+1])) ) // проверка на [-]+[лат.буква]
   k ++ ; // запомнили, какой раз встречаетс€ ЎјЅЋќЌ ['-' + лат.буква]
//
 return ( k ) ;
} // --- конец c_GetCountParamsInString ----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNumbParamInString(INT Numb, char* str)
{ // --- возвращает подстроку Numb строки параметров в строке str --------------
// --- ищем двухсимвольный ЎјЅЋќЌ [-]+[лат.буква] ==============================
 char s_ret[_2048]="\0";
 register INT k,j,i;
 INT //m = 0,
     rep=0, // номер подстроки ЎјЅЋќЌј
     len = strlen( str ); // длина строки str
//
// ищем двухсимвольный ЎјЅЋќЌ как Ќј„јЋќ подстроки параметров ------------------
 for( i=0; i<=len; i++ ) // вдоль по строке сравниваем на соответствие ЎјЅЋќЌ”
  if ( (str[i]=='-') && (isalpha(str[i+1])) ) // проверка на начало ЎјЅЋќЌј
  {
   rep ++ ; // нашли начало ЎјЅЋќЌј номер rep (начинаетс€ с позиции i в строке s)

   if( rep != Numb ) // нам этого на надо...
    continue; // продолжаем цикл по i

// --- а здесь rep == Numb и начинаем искать конец подстроки rep

   for( j=i+1; j<=len; j++ ) // вдоль по строке сравниваем по ЎјЅЋќЌ” ==========
// --- ищем ЎјЅЋќЌ как признак конца подстроки (она же начало следующей) -------
// --- второго вхождени€ ЎјЅЋќЌј может и не быть = мы в самом конце строки -----
    if ( ( (str[j]=='-') && (isalpha(str[j+1])) ) || // далее по строке ищем ЎјЅЋќЌ
           ( (j+1)==len) ) // мы в самом конце строки str
    { // искомый параметр начинаетс€ с позиции i и кончаетс€ j-1 (или j==len) в строке sdr

// --- первое условие - подстрока ограничена началом другой подстроки, второе - концом всей строки
     for( k=i; ((j+1)!=len)?(k<j-1):(k<=len ); k++ ) // копируем подстроку в s_ret
      s_ret[ k-i ] = str[ k ];
//
     strEndZero( s_ret ); // добавим "\0" в конце строки
//
     DeleteSpacesTabsAround( s_ret ); // удал€ем внешние пробелы
     return s_ret ; // возвращаем результат
//
    } // конец if по str[j]
   } // конец if по str[i]
} // --- конец c_GetNumbParamInString ------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNameNumbParamInString(INT Numb, char* str)
{ // им€ параметра номер Numb (начина€ с 1) в строке str -----------------------
 char sW[_2048],
      sName[_1024]; // им€ параметра (без '-' в начале)
//
 strNcpy( sW, c_GetNumbParamInString( Numb, str ) ); // вз€ли строку параметра
//
 if( sscanf( sW, "-%s", sName ) == 1 ) // если Ok - 1 распќзнанный параметр
  return sName ;
 else
  return "" ;
//
} // --- конец c_GetNameNumbParamInString --------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsCorrectParamCalc(char* str)
{ // если подстрока параметров вычислител€ корректна, возвращаетс€ true
 bool out = false;
 char sName[_128]; // им€ параметра (без '-' в начале)
 REAL minVal, maxVal; // численные значени€ параметров
//
 if( sscanf( str, "-%s %g %g", sName, &minVal, &maxVal ) == 3 ) // если Ok - 3 распќзнанных параметров
 {
  snprintf( str,sizeof(str), "-%s %g %g", sName, min(minVal,maxVal), max(minVal,maxVal) ); // восстановим str по прочитанному
  out = true;
 }
//
#ifdef TEST_PRINT //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 t_printf( _256, "_Is_Calc_ %d |%s|", out, str);
 Delay( 100 );
#endif
//
 return out ;
//
} // --- конец c_IsCorrectParamCalc --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsCorrectParamOpVertEdg(char* str)
{ // если подстрока параметров оператора корректна, возвращаетс€ true
 bool out = false;
 char sName[_128]; // им€ параметра (без '-' в начале)
 REAL Val; // численное значение параметра
//
 if( sscanf( str, "-%s %g", sName, &Val ) == 2 ) // если Ok - 2 распќзнанных параметров
 {
  snprintf( str,sizeof(str), "-%s %g", sName, Val ); // восстановим str по прочитанному
  out = true;
 }
//
#ifdef TEST_PRINT //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
t_printf( _256, "_Is_Op_ %d |%s|", out, str );
 Delay( 100 );
#endif
//
 return out ;
//
} // --- конец c_IsCorrectParamOpVertEdg ---------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool _fastcall c_ReadAndCorrectParamsCalcs( char FileNameParamsCalcs[] )
{ // собственно читаем файл параметров ¬џ„»—Ћ»“≈Ћ≈… в строку sCalcs и корректируем синтаксис
 INT n1,n2,
     ch; // важно!..
 char sN[_8192], // подстрока списка параметров
      sP[_4096], // подстрока конкретного параметра
      s[_512],
      w[2] = "?\0";
//
 if( !ReadAndPrimWorkOpsCalcsVertEdgeFiles( FileNameParamsCalcs ) ) // читать в sWork с предварительной обработкой
  {
   strNcpy( sCalcs, "\0" );
   return false;
  }
//
#ifdef TEST_PRINT //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 c_AddLineToTextFrame( sWork );
#endif
//
////////////////////////////////////////////////////////////////////////////////
// --- начинаем разборку sW и копирование в sCalcs c проверкой корректности ----
////////////////////////////////////////////////////////////////////////////////
//
 strNcpy( sCalcs, "\0" ); // очистили sCalcs
//
 INT iStart = 0, iEnd,
     lW = strlen( sWork ), // длина строки sW
     lPrevCalcs;
//
// int countSP = 0 ; // сколько строк sP подпараметров было найдено в строке sN
//
 do // по подстрокам [=][цифра][/][цифра][:] или [=][Def:] ( по sN )
 {
  iEnd = c_FindSubString( sWork, sN, iStart, 0 );
// --- начало обработки строки sN списка параметров параметра ------------------
//
  DeleteSpacesTabsAround( sN ); // обрезаем внешние пробелы
//
////////////////////////////////////////////////////////////////////////////////
  lPrevCalcs = strlen( sCalcs ) ; // длина строки sCalcs ѕ≈–≈ƒ добавлением '=n1/n2:' или '=Def:'
// сюда вернЄмс€, если число корректных параметров подстроки нулевое
//
////////////////////////////////////////////////////////////////////////////////
// по первым символам sN начинаем обработку '=n1/n2:' или '=Def:'
  if( sN[0]=='=' && isdigit(sN[1]) ) // готовимс€ обрабатывать "=n1/n2:^"
  {
// --- начало обработки конструкции '=n1/n2:^' ---------------------------------
  if( !Test_n1n2 ) // читаем "=n1/n2:^" из sN (вoзврат !=6 - ошибка )
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // всЄ корректно!..
  {
//   F2->L_TMM->Caption = sN ;
//   Delay( -5 );
   snprintf( s,sizeof(s), "=%d/%d: ", n1, n2 );  // начинаем новый "=n1/n2:^"
   strcat( sCalcs, s );
///
   strNcpy( sN, strchr( sN,':' ) + 2 ) ; // убрали также пробел после ':'
//
   DeleteSpacesTabsAround( sN ); // очистили sN от ведущих пробелов...
//
  } // конец else... if( sscanf( sN, ...
  } // конец if( sN[0]=='='...
//
////////////////////////////////////////////////////////////////////////////////
  else // if( sN[0]=='=' ...
////////////////////////////////////////////////////////////////////////////////
//
//  if( !( sN[0]=='='          && toupper(sN[1])=='D' && toupper(sN[2])=='E' &&
//         toupper(sN[3])=='F' &&  sN[4]==':' ) )
  if( ! cmp_def( sN ) ) // это случай '=Def:'
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // всЄ корректно!..
  {
   snprintf( s,sizeof(s), "%s ", sDef );
   strcat( sCalcs, s );
//
//   DEL_TO_COLON // макрос дл€ очистки SN от 'xxx:'
   strNcpy( sN, strchr( sN,':' ) + 2 ) ; // убрали также пробел после ':'
//
   DeleteSpacesTabsAround( sN ); // очистили sN от ведущих пробелов...
//
  }  // конец обработки конструкции "=Def:^"
//
// --- разборка строки sN на подстроки параметров sP ---------------------------
//
 INT jStart = 0, jEnd,
     lN = strlen( sN ); // длина строки sN
//
 int countSP = 0 ; // сколько строк sP подпараметров было найдено в строке sN
//
 do // по подстрокам [-][лат.буква]
 {
  jEnd = c_FindSubString( sN, sP, jStart, 1 );
//
// --- начало обработки строки параметра sP ------------------------------------
//
// --- проверка на корректность считывани€ значений параметров путЄм использовани€ sscanf(...)
  if( !c_IsCorrectParamCalc( sP ) )
  {
   jStart = jEnd ;
   continue; // ...do
  }
//
  countSP ++ ; // ...ещЄ один подпараметр найден..!
//
  strcat( sCalcs, sP ); // иначе прибавл€ем к sCalcs
  strcat( sCalcs, " \0" );
//
// --- конец обработки строки параметра sP -------------------------------------
  jStart = jEnd;
 } while( jEnd !=lN ); // пока не конец строки sN ( конец соотв. do )
//
 if( countSP==0 )
  sOps[ lPrevCalcs ] = '\0' ;
//
// --- конец обработки строки sN спиcка параметров -----------------------------
//
  iStart = iEnd;
 } while( iEnd !=lW ); // пока не конец строки sW ( конец соотв. do )
//
 DeleteSpacesTabsAround ( sCalcs ); // удал€ем внешние пробелы
 ReplaceManySpacesOne( sCalcs ); // удал€ем повторы пробелов внутри
//
#ifdef TEST_PRINT //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 c_AddLineToTextFrame( sCalcs ); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif
//
 return true;
//
} // --- конец ReadAndCorrectParamsCalcs =======================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool _fastcall c_ReadAndCorrectParamsOps( char FileNameParamsOps[] )
{ // собственно читаем файл параметров ¬џ„»—Ћ»“≈Ћ≈… в строку sOps и корректируем синтакс
 INT k, n1,n2,
     ch; // важно!..
 char // sWork[_16384] = "", // рабоча€ строка дл€ считывани€ параметров ¬џ„»—Ћ»“≈Ћ≈… (глобальна€)
      sN[_8192], // подстрока списка параметров
      sP[_4096], // подстрока конкретного параметра
      s[_512],
      w[2] = "?\0";
//
 if( !ReadAndPrimWorkOpsCalcsVertEdgeFiles( FileNameParamsOps ) ) // читать в sWork с предварительной обработкой
  {
   strNcpy( sOps, "\0" );
   return false;
  }
//
#ifdef TEST_PRINT //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 c_AddLineToTextFrame( sWork );
#endif
//
////////////////////////////////////////////////////////////////////////////////
// --- начинаем разборку sW и копирование в sOps c проверкой корректности ------
////////////////////////////////////////////////////////////////////////////////
//
 strNcpy( sOps, "\0" ); // очистили sOps
//
 INT iStart = 0, iEnd,
     lW = strlen( sWork ), // длина строки sW
     lPrevOps;
//
// int countSP = 0 ; // сколько строк sP подпараметров было найдено в строке sN
//
 do // по подстрокам [=][цифра][/][цифра][:] или [=][Def:] ( по sN )
 {
  iEnd = c_FindSubString( sWork, sN, iStart, 0 );
// --- начало обработки строки sN списка параметров параметра ------------------
//
  DeleteSpacesTabsAround( sN ); // обрезаем внешние пробелы
//
////////////////////////////////////////////////////////////////////////////////
  lPrevOps = strlen( sOps ) ; // длина строки sOps ѕ≈–≈ƒ добавлением '=n1/n2:' или '=Def:'
// сюда вернЄмс€, если число корректных параметров подстроки нулевое
//
////////////////////////////////////////////////////////////////////////////////
// по первым символам sN начинаем обработку '=n1/n2:' или '=Def:'
  if( sN[0]=='=' && isdigit(sN[1]) ) // готовимс€ обрабатывать "=n1/n2:"
  {
// --- начало обработки конструкции '=n1/n2:^' ---------------------------------
  if( !Test_n1n2 ) // читаем "=n1/n2:^" из sN (вoзврат !=6 - ошибка )
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // всЄ корректно!..
  {
   snprintf( s,sizeof(s), "=%d/%d: ", n1,n2 );  // начинаем новый "=n1/n2:^"
   strcat( sOps, s );
//
  strNcpy( sN, strchr( sN,':' ) + 2 ) ; // убрали также пробел после ':'
//
  DeleteSpacesTabsAround( sN ); // очистили sN от ведущих пробелов...
//
  } // конец if( sscanf( sN, ...
  } // конец if( sN[0]=='='...
//
////////////////////////////////////////////////////////////////////////////////
  else // if( sN[0]=='=' ...
////////////////////////////////////////////////////////////////////////////////
//
  if( ! cmp_def( sN ) ) // это как раз случай '=Def:'
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // всЄ корректно!..
  {
   snprintf( s,sizeof(s), "%s ", sDef );
   strcat( sOps, s );
//
//   DEL_TO_COLON // макрос дл€ очистки SN от 'xxx:'
   strNcpy( sN, strchr( sN,':' ) + 2 ) ; // убрали также пробел после ':'
//
   DeleteSpacesTabsAround( sN ); // очистили sN от ведущих пробелов...
//
  }  // конец обработки конструкции "=Def:^"
//
// --- разборка строки sN на подстроки параметров sP ---------------------------
//
 INT jStart = 0, jEnd,
     lN = strlen( sN ); // длина строки sN
//
 int countSP = 0 ; // сколько строк sP подпараметров было найдено в строке sN
//
 do // по подстрокам [-][лат.буква]
 {
  jEnd = c_FindSubString( sN, sP, jStart, 1 );
//
// --- начало обработки строки параметра sP ------------------------------------
//
// --- проверка на корректность считывани€ значений параметров путЄм использовани€ sscanf(...)
  if( !c_IsCorrectParamOpVertEdg( sP ) )
  {
   jStart = jEnd ;
   continue; // ...do
  }
//
  countSP ++ ; // ...ещЄ один подпараметр найден..!
//
  strcat( sOps, sP ); // иначе прибавл€ем к sOps
  strcat( sOps, " \0" );
//
// --- конец обработки строки параметра sP -------------------------------------
  jStart = jEnd;
 } while( jEnd !=lN ); // пока не конец строки sN ( конец соотв. do )
//
 if( countSP==0 )
  sOps[ lPrevOps ] = '\0' ;
//
// --- конец обработки строки sN спиcка параметров -----------------------------
//
  iStart = iEnd;
 } while( iEnd !=lW ); // пока не конец строки sW ( конец соотв. do )
//
 DeleteSpacesTabsAround ( sOps ); // удал€ем внешние пробелы
 ReplaceManySpacesOne( sOps ); // удал€ем повторы пробелов внутри
//
#ifdef TEST_PRINT //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 c_AddLineToTextFrame( sOps ); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif
//
 return true;
//
} // --- конец ReadAndCorrectParamsOps =========================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool _fastcall c_ReadAndCorrectParamsEdges( char FileNameParamsEdges[] )
{ // собственно читаем файл параметров —ќќЅў≈Ќ»… в строку sMess и корректируем синтакс
 INT k, n1,n2, m1,m2,
     ch; // важно!..
 char // sWork[_16384] = "", // рабоча€ строка дл€ считывани€ параметров ¬џ„»—Ћ»“≈Ћ≈… (глобальна€)
      sN[_8192], // подстрока списка параметров
      sP[_4096], // подстрока конкретного параметра
      s[_512],
      w[2] = "?\0";
//
 if( !ReadAndPrimWorkOpsCalcsVertEdgeFiles( FileNameParamsEdges ) ) // читать в sWork с предварительной обработкой
  {
   strNcpy( sEdg, "\0" );
   return false;
  }
//
////////////////////////////////////////////////////////////////////////////////
// --- начинаем разборку sW и копирование в sEdg c проверкой корректности ------
////////////////////////////////////////////////////////////////////////////////
//
 strNcpy( sEdg, "\0" ); // очистили sEdg
//
 INT iStart = 0, iEnd,
     lW = strlen( sWork ), // длина строки sW
     lPrevOps;
//
// int countSP = 0 ; // сколько строк sP подпараметров было найдено в строке sN
//
 do // по подстрокам [=][цифра][/][цифра][:] или [=][Def:] ( по sN )
 {
  iEnd = c_FindSubString( sWork, sN, iStart, 0 );
// --- начало обработки строки sN списка параметров параметра ------------------
//
  DeleteSpacesTabsAround( sN ); // обрезаем внешние пробелы
//
////////////////////////////////////////////////////////////////////////////////
  lPrevOps = strlen( sEdg ) ; // длина строки sEdg ѕ≈–≈ƒ добавлением '=n1/n2|m1/m2:' или '=Def:'
// сюда вернЄмс€, если число корректных параметров подстроки нулевое
//
////////////////////////////////////////////////////////////////////////////////
// по первым символам sN начинаем обработку '=n1/n2|m1/m2:' или '=Def:'
  if( sN[0]=='=' && isdigit(sN[1]) ) // готовимс€ обрабатывать "=n1/n2|m1/m2:"
  {
// --- начало обработки конструкции '=n1/n2|m1/m2:^' ---------------------------------
//  if( sscanf( sN, "=%d/%d|%d/%d: ", &n1, &n2, &m1, &m2 ) != 4 ) // читаем n1/n2|m1/m2 из sN (вoзврат !=4 - ошибка )
  if( !Test_n1n2m1m2 ) // читаем "=n1/n2|m1/m2:^" из sN (вoзврат !=10 - ошибка )
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // всЄ корректно!..
  {
   snprintf( s,sizeof(s), "=%d/%d|%d/%d: ", n1,n2, m1,m2 );  // начинаем новый "=n1/n2|m1/m2:^"
   strcat( sEdg, s );
//
  strNcpy( sN, strchr( sN,':' ) + 2 ) ; // убрали также пробел после ':'
//
  DeleteSpacesTabsAround( sN ); // очистили sN от ведущих пробелов...
//
  } // конец if( sscanf( sN, ...
  } // конец if( sN[0]=='='...
//
////////////////////////////////////////////////////////////////////////////////
  else // if( sN[0]=='=' ...
////////////////////////////////////////////////////////////////////////////////
//
  if( ! cmp_def( sN ) ) // это как раз случай '=Def:'
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // всЄ корректно!..
  {
   snprintf( s,sizeof(s), "%s ", sDef );
   strcat( sEdg, s );
//
   strNcpy( sN, strchr( sN,':' ) + 2 ) ; // убрали также пробел после ':'
//
   DeleteSpacesTabsAround( sN ); // очистили sN от ведущих пробелов...
//
  }  // конец обработки конструкции "=Def:^"
//
// --- разборка строки sN на подстроки параметров sP ---------------------------
//
 INT jStart = 0, jEnd,
     lN = strlen( sN ); // длина строки sN
//
 int countSP = 0 ; // сколько строк sP подпараметров было найдено в строке sN
//
 do // по подстрокам [-][лат.буква]
 {
  jEnd = c_FindSubString( sN, sP, jStart, 1 );
//
// --- начало обработки строки параметра sP ------------------------------------
//
// --- проверка на корректность считывани€ значений параметров путЄм использовани€ sscanf(...)
  if( !c_IsCorrectParamOpVertEdg( sP ) )
  {
   jStart = jEnd ;
   continue; // ...do
  }
//
  countSP ++ ; // ...ещЄ один подпараметр найден..!
//
  strcat( sEdg, sP ); // иначе прибавл€ем к sEdg
  strcat( sEdg, " \0" );
//
// --- конец обработки строки параметра sP -------------------------------------
  jStart = jEnd;
 } while( jEnd !=lN ); // пока не конец строки sN ( конец соотв. do )
//
 if( countSP==0 )
  sOps[ lPrevOps ] = '\0' ;
//
// --- конец обработки строки sN спиcка параметров -----------------------------
//
  iStart = iEnd;
 } while( iEnd !=lW ); // пока не конец строки sW ( конец соотв. do )
//
 DeleteSpacesTabsAround ( sEdg ); // удал€ем внешние пробелы
 ReplaceManySpacesOne( sEdg ); // удал€ем повторы пробелов внутри
//
#ifdef TEST_PRINT //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 c_AddLineToTextFrame( sEdg ); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif
//
 return true;
//
} // --- конец c_ReadAndCorrectParamsEdges =====================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool _fastcall c_ReadAndCorrectParamsVertices( char FileNameParamsVertices[] )
{ // собственно читаем файл параметров ¬≈–Ў»Ќ в строку sVrt и корректируем синтакс
 INT k, n1,n2,
     ch; // важно!..
 char // sWork[_16384] = "", // рабоча€ строка дл€ считывани€ параметров ¬џ„»—Ћ»“≈Ћ≈… (глобальна€)
      sN[_8192], // подстрока списка параметров
      sP[_4096], // подстрока конкретного параметра
      s[_512],
      w[2] = "?\0";
//
 if( !ReadAndPrimWorkOpsCalcsVertEdgeFiles( FileNameParamsVertices ) ) // читать в sWork с предварительной обработкой
  {
   strNcpy( sVrt, "\0" );
   return false;
  }
//
#ifdef TEST_PRINT //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 c_AddLineToTextFrame( sWork );
#endif
//
////////////////////////////////////////////////////////////////////////////////
// --- начинаем разборку sW и копирование в sVrt c проверкой корректности ------
////////////////////////////////////////////////////////////////////////////////
//
 strNcpy( sVrt, "\0" ); // очистили sVrt
//
 INT iStart = 0, iEnd,
     lW = strlen( sWork ), // длина строки sW
     lPrevOps;
//
 do // по подстрокам [=][цифра][/][цифра][:] или [=][Def:] ( по sN )
 {
  iEnd = c_FindSubString( sWork, sN, iStart, 0 );
// --- начало обработки строки sN списка параметров параметра ------------------
//
  DeleteSpacesTabsAround( sN ); // обрезаем внешние пробелы
//
////////////////////////////////////////////////////////////////////////////////
  lPrevOps = strlen( sVrt ); // длина строки sVrt ѕ≈–≈ƒ добавлением '=n1/n2:' или '=Def:'
// сюда вернЄмс€, если число корректных параметров подстроки нулевое
//
////////////////////////////////////////////////////////////////////////////////
// по первым символам sN начинаем обработку '=n1/n2:' или '=Def:'
  if( sN[0]=='=' && isdigit(sN[1]) ) // готовимс€ обрабатывать "=n1/n2:"
  {
// --- начало обработки конструкции '=n1/n2:^' ---------------------------------

  if( !Test_n1n2 ) // читаем "=n1/n2:^" из sN (вoзврат !=6 - ошибка )
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // всЄ корректно!..
  {
   snprintf( s,sizeof(s), "=%d/%d: ", n1,n2 );  // начинаем новый "=n1/n2:^"
   strcat( sVrt, s );
//
// --- чистим строку sN от подстроки "xxx:" ------------------------------------
//  DEL_TO_COLON // макрос дл€ очистки sN от 'xxx:'
  strNcpy( sN, strchr( sN,':' ) + 2 ) ; // убрали также пробел после ':'
//
  DeleteSpacesTabsAround( sN ); // очистили sN от ведущих пробелов...
//
  } // конец if( sscanf( sN, ...
  } // конец if( sN[0]=='='...
//
////////////////////////////////////////////////////////////////////////////////
  else // if( sN[0]=='=' ...
////////////////////////////////////////////////////////////////////////////////
//
  if( ! cmp_def( sN ) ) // это как раз случай '=Def:'
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // всЄ корректно!..
  {
   snprintf( s,sizeof(s), "%s ", sDef );
   strcat( sVrt, s );
//
   strNcpy( sN, strchr( sN,':' ) + 2 ) ; // убрали также пробел после ':'
//
   DeleteSpacesTabsAround( sN ); // очистили sN от ведущих пробелов...
//
  }  // конец обработки конструкции "=Def:^"
//
// --- разборка строки sN на подстроки параметров sP ---------------------------
//
 INT jStart = 0, jEnd,
     lN = strlen( sN ); // длина строки sN
//
 int countSP = 0 ; // сколько строк sP подпараметров было найдено в строке sN
//
 do // по подстрокам [-][лат.буква]
 {
  jEnd = c_FindSubString( sN, sP, jStart, 1 );
//
// --- начало обработки строки параметра sP ------------------------------------
//
// --- проверка на корректность считывани€ значений параметров путЄм использовани€ sscanf(...)
  if( !c_IsCorrectParamOpVertEdg( sP ) )
  {
   jStart = jEnd ;
   continue; // ...do
  }
//
  countSP ++ ; // ...ещЄ один подпараметр найден..!
//
  strcat( sVrt, sP ); // иначе прибавл€ем к sVrt
  strcat( sVrt, " \0" );
//
// --- конец обработки строки параметра sP -------------------------------------
  jStart = jEnd;
 } while( jEnd !=lN ); // пока не конец строки sN ( конец соотв. do )
//
 if( countSP==0 )
  sOps[ lPrevOps ] = '\0' ;
//
// --- конец обработки строки sN спиcка параметров -----------------------------
//
  iStart = iEnd;
 } while( iEnd !=lW ); // пока не конец строки sW ( конец соотв. do )
//
 DeleteSpacesTabsAround ( sVrt ); // удал€ем внешние пробелы
 ReplaceManySpacesOne( sVrt ); // удал€ем повторы пробелов внутри
//
#ifdef TEST_PRINT //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 c_AddLineToTextFrame( sVrt ); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif
//
 return true;
//
} // --- конец c_ReadAndCorrectParamsVertices ==================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountCalcs()
{ // --- определить общее число вычислитнлей -----------------------------------
 char sN[_4096] = "";
 INT  n1,n2, nSum = 0,
      iStart = 0, iEnd,
      lS = strlen( sCalcs ); // длина строки sCalcs
//
 if( !lS ) // если sCalcs пуста€...
  return 0 ;
//
 do // по подстрокам '=' + цифра ( по sN )
 {
  iEnd = c_FindSubString( sCalcs, sN, iStart, 0 );
// --- начало обработки строки sN списка параметров параметра ------------------
//
  DeleteSpacesTabsAround( sN ); // обрезаем внешние пробелы
//
// --- провер€ем корректность преобразовани€ '=n1/n2:' -------------------------
//  if( sscanf( sN, "=%d/%d: ", &n1, &n2 ) != 2 ) // вoзврат !=2 - ошибка
  if( !Test_n1n2 ) // читаем "=n1/n2:^" из sN (вoзврат !=6 - ошибка )
  {
   iStart = iEnd;
   continue;
  }
//
  nSum = max( nSum, max( abs(n1), abs(n2) ) ) ; // определ€ем общее число вычислителей
//
// --- конец обработки строки sN спиcка параметров -----------------------------
//  cont_i:
  iStart = iEnd;
 } while( iEnd !=lS ); // пока не конец строки sCalcs ( конец соотв. do )
//
 return nSum ;
} // --- конец c_GetCountCalcs -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNumbParamByCalc(INT Numb, INT Calc )
{ // --- возвращает подстроку Numb строки параметров вычислител€ Calc ----------
// --- ищем двухсимвольный ЎјЅЋќЌ '-'+лат.буква] -------------------------------
 char sN[_4096], sR[_2048];
 INT iStart = 0, iEnd,
     rep=0; // номер подстроки ЎјЅЋќЌј
//
 strNcpy( sN, c_GetParamsByCalc( Calc ) ); // берЄм подстроку параметров дл€ вычислител€ Calc
 INT lN = strlen( sN ); // длина строки sN
//
 do // по подстрокам '-' + лат.буква ( по sN )
 {
  iEnd = c_FindSubString( sN, sR, iStart, 1 );
//
// --- начало обработки строки sN списка параметров параметра ------------------
//
  rep ++ ; // номер вхождени€ sR в sN
//
  if ( rep == Numb ) // нашли что надо...
  {
   DeleteSpacesTabsAround( sR ); // удал€ем пробелы спереди и сзади
   return sR ; // возвращаем результат
  }
//
// --- конец обработки строки sN спиcка параметров -----------------------------
//  cont_i:
  iStart = iEnd;
 } while( iEnd !=lN ); // пока не конец строки sN
///
 return "\0" ; // если ничего не нашли...
//
} // --- конец c_GetNumbParamByCalc --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNumbParamByOp(INT Numb, INT Op )
{ // --- возвращает подстроку Numb строки параметров оператора Op --------------
// --- ищем двухсимвольный ЎјЅЋќЌ '-'+лат.буква] -------------------------------
 char sN[_4096], sR[_2048];
 INT iStart = 0, iEnd,
     rep=0; // номер подстроки ЎјЅЋќЌј
//
 strNcpy( sN, c_GetParamsByOp( Op ) ); // берЄм подстроку параметров дл€ вычислител€ Op
 INT lN = strlen( sN ); // длина строки sN
//
 do // по подстрокам '-'+лат.буква ( по sN )
 {
  iEnd = c_FindSubString( sN, sR, iStart, 1 );
//
// --- начало обработки строки sN списка параметров параметра ------------------
//
  rep ++ ; // номер вхождени€ sR в sN
//
  if ( rep == Numb ) // нашли что надо...
  {
   DeleteSpacesTabsAround( sR ); // удал€ем пробелы спереди и сзади
   return sR ; // возвращаем результат
  }
// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lN ); // пока не конец строки sN
//
 return "\0" ; // если ничего не нашли...
//
} // --- конец c_GetNumbParamByOp ----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT _fastcall c_FindSubString( char* sSrc, char* sDst, INT iStart, INT Rule)
{ // в строке sSrc начина€ с позиции iStart ищетс€ подстрока sDst --------------
// --- возвращаетс€ конец позиции поиска в строке sSrc -------------------------
// --- при Rule = 0  шаблон дл€ поиска по условию: первое вхождение [=][цифра]
// --- или [=][D(d)] и второе вхождение такое же (между первым и вторым
// --- вхождени€ми любое количество любых символов)
// --- при Rule != 0  шаблон дл€ поиска [-][лат.буква]-[-][лат.буква]-----------
// --- где "-" любое количество любых символов, D(d) - лат.буква D в любом регистре
 register INT k,j,i;
 INT lenSrc = strlen( sSrc ); // длина строки sSrc
//
 strNcpy( sDst, "\0" ); // очистим sDst
//
 for( i=iStart; i<=lenSrc; i++ ) // вдоль по строке sSrc индексу i - ищем первое вхождение шаблона
//
  if( ( ( Rule==0 && sSrc[i]=='=' ) && // Rule=0 и первый символ '=' (вход€ща€ последовательность)
        ( isdigit(sSrc[i+1]) || toupper(sSrc[i+1]=='D') ) // [цифра] или [D(d)]
      || // или дл€ Rule != 0
        ( Rule!=0 && sSrc[i]=='-' ) && // Rule!=1 и первый символ '-'
          isalpha(sSrc[i+1]) ) ) // шаблон [лат.буква]
//
  for( j=i+1; j<=lenSrc; j++ ) // вдоль по строке sSrc по индексу j - ищем следующее вхождение шаблона
//
  if(  j==lenSrc // если конец строки sSrc
     || // или дл€ Rule == 0
     ( ( Rule==0 && sSrc[j]=='=' ) && // Rule=0 и первый символ '=' (конечна€ последовательность)
       ( isdigit(sSrc[j+1]) || toupper(sSrc[j+1]=='D') ) // [цифра] или [D(d)]
     || // или дл€ Rule != 0
       ( Rule!=0 && sSrc[j]=='-' ) && // Rule!=1 и первый символ '-'
         isalpha(sSrc[j+1]) ) ) // [лат.буква]
// возможны проблемы со вторым вхождением - первое вхождение: [-][лат.буква]...второе: [-][русск.буква]
// isalpha (,tp setlocale) не найдЄт второе вхождение (при Rule!=0 подстрока будет продлена за второе вхождение)
// в данном случае это решаетс€ повторной записью str c_IsCorrectParamCalc (...Op)
     {
//      for( k=i; (j!=lenSrc) ? (k<j) : (k<=lenSrc) ; k++ ) // копируем подстроку в sDst
      for( k=i; k<j; k++ ) // копируем подстроку в sDst
       sDst[ k-i ] = sSrc[ k ];
      sDst[ j-i ] = '\0' ; // строку принудительно "закрыли" нулЄм

      if( sDst[j-i-1] == ' ' ) // это альтернатива DelSpacesTabsAround ( sDst );
       sDst[j-i-1] = '\0';

//      DelSpacesTabsAround ( sDst ); // удал€ем внешние пробелы
//
      return j ; // позици€, следующа€ за концом подстроки
//      return (j<lenSrc) ? (j) : (lenSrc) ; // позици€, следующа€ за концом подстроки

     } // конец if( Rule == ?? && ...
//
 sDst[ 0 ] = '\0' ;
//
 return lenSrc ; // ...если ничего не нашли - вернуть длину строки, в котороый искали
//
} // --- конец c_FindSubString =================================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_PutParamsAll()
{ // вывод строк параметров ¬џ„»—Ћ»“≈Ћ≈… и ќѕ≈–ј“ќ–ќ¬, метрик ƒ”√ » ¬≈–Ў»Ќ
 char str[_16384]; // рабоча€ строка
//
 t_printf( "\n-I- ѕараметры ¬џ„»—Ћ»“≈Ћ≈… и ќѕ≈–ј“ќ–ќ¬, метрики ƒ”√ и ¬≈–Ў»Ќ -I-" ); // информационное сообщение
//
 if( c_LoadFileNameParamsCalcs( FileNameParamsCalcs ) ) // если с файлом всЄ удачно...
 {
  t_printf( "=> ¬џ„»—Ћ»“≈Ћ»: файл |%s|", FileNameParamsCalcs ); // им€ файла параметров ¬џ„»—Ћ»“≈Ћ≈…
  t_printf( "исходна€:  |%s|", sWork ); // исходна€ строка
  t_printf( "коррекци€: |%s|", sCalcs ); // скоректированна€ строка
 }
//
 if( c_LoadFileNameParamsOps( FileNameParamsOps ) )
 {
  t_printf( "=> ќѕ≈–ј“ќ–џ: файл |%s|", FileNameParamsOps ); // им€ файла параметров ќѕ≈–ј“ќ–ќ¬
  t_printf( "исходна€:  |%s|", sWork ); // исходна€ строка
  t_printf( "коррекци€: |%s|", sOps ); // скоректированна€ строка
 }
//
 if( c_LoadFileNameParamsEdges( FileNameParamsEdges ) )
 {
  t_printf( "=> ћ≈“–» » ƒ”√: файл |%s|", FileNameParamsEdges ); // им€ файла метрик ƒ”√
  t_printf( "исходна€:  |%s|", sWork ); // исходна€ строка
  t_printf( "коррекци€: |%s|", sEdg ); // скоректированна€ строка
 }
//
 if( c_LoadFileNameParamsVertices( FileNameParamsVertices ) )
 {
  t_printf( "=> ћ≈“–» » ¬≈–Ў»Ќ: файл |%s|", FileNameParamsVertices ); // им€ файла метрик ¬≈–Ў»Ќ
  t_printf( "исходна€:  |%s|", sWork ); // исходна€ строка
  t_printf( "коррекци€: |%s|", sVrt ); // скоректированна€ строка
 }
//
 c_AddLineToTextFrame( "\n" );
//
 return true ;
//
} // --- конец c_PutParamsAll --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetParamsByOp(INT Op)
{ // проcматривает строку sOps и возвращает подстроку всех параметров ќѕ≈–ј“ќ–ј Op
 char sN[_8192], sName[_128];
 INT  lOps, iStart=0, iEnd, n1, n2;
//
 if( ! (lOps = strlen( sOps ) ) ) // если строка ќѕ≈–ј“ќ–ќ¬ пуста€...
  return "\0" ;
//
////////////////////////////////////////////////////////////////////////////////
// --- начали искать sN среди подстрок типа '=n1/n2:'---------------------------

 do // по подстрокам '=n1/n2:' или '=Def:'
 {
  iEnd = c_FindSubString( sOps, sN, iStart, 0 );
// --- начало обработки строки sOps списка параметров --------------------------
///
//  DelSpacesTabsAround( sN ); // обрезаем внешние пробелы
//
//  if( !strncmp( sN, sDef, 5 ) ) // '=Def:' пока не нужна... уходим на do !
  if( cmp_def( sN ) ) // '=Def:' пока не нужна... уходим на do !
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
// if( sscanf( sN, "=%d/%d: ", &n1, &n2 ) == 2 ) // правильное чтение
 if( Test_n1n2 ) // правильное чтение "=n1/n2:^" из sN
   if( Op >= min(n1,n2) && Op <= max(n1,n2) ) // Op в диапазоне n1-n2
    return strchr( sN,':' ) + 2 ; // перескакиваем через ':' и 'пробел'
//
// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lOps ); // пока не конец строки sOps ( конец соотв. do )
//
////////////////////////////////////////////////////////////////////////////////
// --- начали искать sN среди подстрок типа '=Def:'-----------------------------
//
 iStart = 0;
//
 do // по подстрокам '=n1/n2:' или '=Def:'
 {
  iEnd = c_FindSubString( sOps, sN, iStart, 0 );
// --- начало обработки строки sMess списка параметров -------------------------
//  DelSpacesTabsAround( sN ); // обрезаем внешние пробелы
//  if( strncmp( sN, sDef, 5 ) ) // '=Def:' как раз нужна...
  if( ! cmp_def( sN ) ) // '=Def:' как раз нужна...
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
  if( sscanf( sN, "%s ", sName ) == 1 ) // правильное чтение
   return strchr( sN,':' ) + 2 ; // перескакиваем через ':' и 'пробел'
//
// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lOps ); // пока не конец строки sOps ( конец соотв. do )
//
////////////////////////////////////////////////////////////////////////////////
//
 return "\0" ; // не найдено вообще ничего - возращаем (по умолчанию)
//
} // --- конец c_GetParamsByOp -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetParamsByCalc(INT Calc)
{ // проcматривает строку sCalcs и возвращает подстроку всех параметров ¬џ„»—Ћ»“≈Ћя Op
 char sN[_8192], sName[_128];
 INT  lCalcs, iStart=0, iEnd, n1, n2;
//
 if( ! (lCalcs = strlen( sCalcs ) ) ) // если строка ¬џ„»—Ћ»“≈Ћ≈… пуста€...
  return "\0" ;
//
////////////////////////////////////////////////////////////////////////////////
// --- начали искать sN среди подстрок типа '=n1/n2:'---------------------------
//
 do // по подстрокам '=n1/n2:' или '=Def:'
 {
  iEnd = c_FindSubString( sCalcs, sN, iStart, 0 );
// --- начало обработки строки sOps списка параметров --------------------------
//  DelSpacesTabsAround( sN ); // обрезаем внешние пробелы
//  if( !strncmp( sN, sDef, 5 ) ) // '=Def:' пока не нужна... уходим на do !
  if( cmp_def( sN ) ) // '=Def:' пока не нужна... уходим на do !
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
//  if( sscanf( sN, "=%d/%d: ", &n1, &n2 ) == 2 ) // правильное чтение
 if( Test_n1n2 ) // правильное чтение "=n1/n2:^" из sN
   if( Calc >= min(n1,n2) && Calc<= max(n1,n2) ) // Calc в диапазоне n1-n2
    return strchr( sN,':' ) + 2 ; // перескакиваем через ':' и 'пробел'
//
// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lCalcs ); // пока не конец строки sCalcs ( конец соотв. do )

////////////////////////////////////////////////////////////////////////////////
// --- начали искать sN среди подстрок типа '=Def:'-----------------------------
//
 iStart = 0;
//
 do // по подстрокам '=n1/n2:' или '=Def:'
 {
  iEnd = c_FindSubString( sCalcs, sN, iStart, 0 );
// --- начало обработки строки sMess списка параметров -------------------------
//  DelSpacesTabsAround( sN ); // обрезаем внешние пробелы
//  if( strncmp( sN, sDef, 5 ) ) // '=Def:' как раз нужна...
  if( ! cmp_def( sN ) ) // '=Def:' как раз нужна...
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
  if( sscanf( sN, "%s ", sName ) == 1 ) // правильное чтение
   return strchr( sN,':' ) + 2 ; // перескакиваем через ':' и 'пробел'
//
// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lCalcs ); // пока не конец строки sCalcs ( конец соотв. do )
//
////////////////////////////////////////////////////////////////////////////////
//
 return "\0" ; // не найдено вообще ничего - возращаем (по умолчанию)
//
} // --- конец c_GetParamsByCalc -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CanExecOpCalc(INT Op, INT Calc)
{ // проверка ¬ќ«ћќ∆Ќќ—“» выполнени€ оператора Op на вычислителе Calc
// --- возвращает число параметров, по которым выполнение ¬ќ«ћќ∆Ќќ (>0)
// --- если хоть раз Ќ≈¬ќ«ћќ∆Ќќ, то возвращаетс€ число ¬ќ«ћќ∆Ќќ с ћ»Ќ”—ќћ
// --- если нет совпадающих параметров - возвращаетс€ math.huge
 register INT iOp,iCalc;
 INT countEq = 0, // число совпадений значений параметров ќѕ≈–ј“ќ–ќ¬ и ¬џ„»—Ћ»“≈Ћ≈…
     nOp   = c_GetCountParamsByOp( Op ), // число параметров оператора Op
     nCalc = c_GetCountParamsByCalc( Calc ); // число параметров вычислител€ —alc
 bool flagPoss = true, // флаг ¬ќ«ћќ∆Ќќ—“»...
      flagNameParam = false; // есть ли совпадающие имена параметров
 REAL ValOp, minValCalc, maxValCalc; // значени€ параметров
 char NameParamOp[_512], NameParamCalc[_512]; // им€ параметров ќѕ≈–ј“ќ–ј и ¬џ„»—Ћ»“≈Ћя
//
 if( !strlen( sOps ) || // строка параметров ќѕ≈–ј“ќ–ј Op пуста€...
     !nOp ) // нет параметров ќѕ≈–ј“ќ–а Op
  return maxRet ;
//
 if( !strlen( sCalcs ) || // строка параметров ¬џ„»—Ћ»“≈Ћя Calc пуста€...
     !nCalc ) // нет параметров ¬џ„»—Ћ»“≈Ћ≈…
  return -maxRet ;
//
 for( iOp=1; iOp<=nOp; iOp++ ) // цикл по параметрам ќѕ≈–ј“ќ–ј
 {
  APM // -----------------------------------------------------------------------
//
  strNcpy( NameParamOp, c_GetNameNumbParamByOp( iOp, Op ) ); // запомнили...
//
  for( iCalc=1; iCalc<=nCalc; iCalc++ ) // цикл по параметрам ¬џ„»—Ћ»“≈Ћя
  {
   APM // ----------------------------------------------------------------------
//
   strNcpy( NameParamCalc, c_GetNameNumbParamByCalc( iCalc, Calc ) ); // запомнили...
//
// --- совпадает ли им€ параметра ќѕ≈–ј“ќ–ј и именем параметра ¬џ„»—Ћ»“≈Ћя ? ---
   if( !strcmp( NameParamOp, NameParamCalc ) ) // совпадение = 0
   { // обрабатываем случай —ќ¬ѕјƒеЌ»я по имени параметра...
//    flagNameParam = true; // нашлось совпадение по параметрам
    ValOp      = c_GetValNumbParamByOp( iOp, Op ); // значение параметра Op
    minValCalc = c_GetMinValNumbParamByCalc( iCalc, Calc ); // значение min параметра Calc
    maxValCalc = c_GetMaxValNumbParamByCalc( iCalc, Calc ); // значение max параметра Calc
//
// --- сравниваем значени€ параметра по величине -------------------------------
    if( ValOp>=min(minValCalc,maxValCalc) && ValOp<=max(minValCalc,maxValCalc) ) // входит в диапазон...
    // по параметру с именем NameParamOp = NameParamCalc получили "¬џѕќЋЌ≈Ќ»≈ ¬ќ«ћќ∆Ќќ"
     countEq ++ ;
   } // конец if !strcmp (по именам ѕј–јћ≈“–ќ¬)
//
  } // конец for iCalc (по ¬џ„»—Ћ»“≈Ћяћ)
 } // конец for iOp (по ќѕ≈–ј“ќ–јћ)
//
 return ( countEq == nOp ) ? countEq : -countEq ; // число совпадений по параметрам
//
} // --- конец c_—anExecOpCalc -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_TestCanExecAllOpsCalcs( INT  Rule )
{ // проверка ¬ќ«ћќ∆Ќќ—“» выполнени€ ¬—≈’ операторов на всех вычислител€х
// при Rule==0 возвращаетс€ true при выполн»мости и false при обратном
// при Rule!=0 выдаЄтс€ список ќѕ≈–ј“ќ–ќ¬, которые могут быть выполнены на конкретном ¬џ„»—Ћ»“≈Ћ≈
INT  iOp,Op,Calc, numbCalcsByOp,
     countOps, countCalcs,
     countAll, countOut, countDone=0;
bool canAllExec = true ;
char str[_4096], w[_256], sOut[_128], sSave[_128];;
//
 strNcpy( sSave, F2->L_OM->Caption.c_str() ); // сохранили текст мз F2->L_OM->Caption
//
// --- сколько у нас ќѕ≈–ј“ќ–ќ¬ и ¬џ„»—Ћ»“≈Ћ≈… ? -------------------------------
 countOps = c_GetCountOps(); // общее число ќѕ≈–ј“ќ–ќ¬
 countCalcs = c_GetCountCalcs(); // общее число ¬џ„»—Ћ»“≈Ћ≈…
// --- а сколько всего циклов будет сделано ? ----------------------------------
 countAll = countOps * countCalcs;
 countOut = countAll / 100; // каждый процент выдаЄм
//
 if( countOps <= 0 ) // проблемы! —корее всего массива Mem_Edges[][] не существует (соответсвующий файл не был загружен)
 {
  t_printf( "\n-W- „исло ќѕ≈–ј“ќ–ќ¬ не определено. ¬озможно, файл данных графа не был загружен... -W-\n" );
  return false ;
 }
//
// --- работаем с параметрами ¬џ„»—Ћ»“≈Ћ≈… -------------------------------------
//
 if( countCalcs <= 0 ) // проблемы! —корее всего файл параметров ¬џ„»—Ћ»“≈Ћ≈… не был загружен
 {
  t_printf( "\n-W- „исло ¬џ„»—Ћ»“≈Ћ≈… не определено. ¬озможно, файл параметров ¬џ„»—Ћ»“≈Ћ≈… не был загружен... -W-\n" );
  return true ;
 }
//
// --- всЄ нормально - начинаем Ў“ј“Ќџ… вывод данных ---------------------------
 t_printf( "\n-I- „исло ќѕ≈–ј“ќ–ќ¬= %d, число ¬џ„»—Ћ»“≈Ћ≈…= %d -I-\n", countOps, countCalcs );
//
 for( iOp=1; iOp<=countOps; iOp++ ) // по общему числу ќѕ≈–ј“ќ–ќ¬
 {
  APM // -----------------------------------------------------------------------
  Delay( 1 ); // дадим поработать Windows 0,001 сек ( APM не помогает !!! )
//
  Op = c_GetNumbOp( iOp ); // собственно номер ќѕ≈–ј“ќ–ј
  snprintf( str,sizeof(str), "ќѕ≈–ј“ќ–= %d может быть выполнен на ¬џ„»—Ћ»“≈Ћя’:", Op );
  numbCalcsByOp = 0; // число ¬џ„»—Ћ»“≈Ћ≈…, на которых может выполнитьс€ ќѕ≈–ј“ќ– Op
//
  for( Calc=1; Calc<=countCalcs; Calc++ ) // по всем ¬џ„»—Ћ»“≈Ћяћ
  {
   APM // ----------------------------------------------------------------------
//
////////////////////////////////////////////////////////////////////////////////
// --- протокол времени выполнени€ (дл€ больших задач может быть очень долго)
////////////////////////////////////////////////////////////////////////////////
   countDone ++ ; // текущее число циклов
   if( !( countDone % countOut ) )
   {
    snprintf( sOut,sizeof(sOut), " = %.0f%% выполнено", 100.0 * countDone / countAll );
    F2->L_OM->Caption = sOut;
    F2->L_OM->Repaint();
   }
////////////////////////////////////////////////////////////////////////////////
//
   if( c_CanExecOpCalc( Op, Calc ) > 0 ) // если Op может быть выполнен на Calc
   {
    snprintf( w,sizeof(w), " %d", Calc );
    strcat( str, w );
    numbCalcsByOp ++ ;
   }
//
  } // конец по ¬џ„»—Ћ»“≈Ћяћ ---------------------------------------------------
//
 if( !numbCalcsByOp ) // если имеетс€ "хоть один" ќѕ≈–ј“ќ– (ќѕ≈–ј“ќ–џ), дл€ которых нет ¬џ„»—Ћ»“≈Ћя...
  canAllExec = false ;
//
 if( Rule ) // вывод строк "ќѕ≈–ј“ќ–= ¬џ„»—Ћ»“≈Ћ»:"
  c_AddLineToTextFrame( str );
//
 } // конец по ќѕ≈–ј“ќ–јћ
//
 F2->L_OM->Caption = sSave; // восстановили текст в F2->L_OM->Caption
//
 if( !Rule ) // если 0 -> никакого вывода..!
  return canAllExec ;
//
 if( canAllExec ) // нет проблем с исполнимостью!..
  c_AddLineToTextFrame( "\n-I- Ћюбой ќѕ≈–ј“ќ– может быть выполнен хот€ бы на одном ¬џ„»—Ћ»“≈Ћ≈... -I-\n" );
 else
  c_AddLineToTextFrame( "\n-W- ќдин или несколько ќѕ≈–ј“ќ–ќ¬ не могут быть выполнены ни на одном ¬џ„»—Ћ»“≈Ћ≈...-W-\n" );
//
 return canAllExec ;
//
} // --- конец c_TestCanExecAllOpsCalcs ----------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_InputDialog( char *sCaption, char *sPrompt, char *sDefault )
{ // выдаЄт окно Windows c заголовком sCaption, предложением sPrompt и строкой sDefault
 char sOut[_512]; // 256 не работает!!!
 strNcpy( sOut, InputBox( sCaption, sPrompt, sDefault ).c_str() );
 return sOut;
} // --- конец с_InputDialog ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int __fastcall c_MessageDialog( char *sCaption, char *sText, char *Buttons, INT Pictogram )
{ // выдаЄт окно Windows c заголовком sCaption и строкой sText
 char flag[] = "0\0"; // символ Ќ≈добавлени€ (соответствущей) кнопки в набор на диалоговой форме
//
 TMsgDlgButtons mb; // тип кнопок на форме
 TMsgDlgType mt; // тип пиктограммы на форме
//
 if( strlen(Buttons) == 8 ) // только ровно 8 символов !!! иначе - mbYes !!!
 {
  if( Buttons[0] != flag[0] ) mb << mbYes; // выбор набора кнопок
  if( Buttons[1] != flag[0] ) mb << mbNo;
  if( Buttons[2] != flag[0] ) mb << mbOK;
  if( Buttons[3] != flag[0] ) mb << mbCancel;
//  else if( Buttons[4] == flag[0] ) mb << mbHelp; // кнопки Help не надо !!!
  if( Buttons[4] != flag[0] ) mb << mbAbort;
  if( Buttons[5] != flag[0] ) mb << mbRetry;
  if( Buttons[6] != flag[0] ) mb << mbIgnore;
  if( Buttons[7] != flag[0] ) mb << mbAll;
 }
 else
  mb << mbYes; // умолчание (ошибка размера строки Buttons[]) - включена кнопка Yes
//
 switch( Pictogram ) // выбор пиктограммы дл€ окна
 {
  case 0:  mt = mtConfirmation; break;
  case 1:  mt = mtInformation;  break;
  case 2:  mt = mtError;        break;
  case 3:  mt = mtWarning;      break;
  case 4:  mt = mtCustom;       break;
  default: mt = mtConfirmation; // умолчание - ѕодтверждение (вопросительный знак)
                                break;
 }
//
 TForm *FMess;
 FMess = CreateMessageDialog( sText, mt, mb );
 FMess->Caption = sCaption; // заголовок окна
//
 int out = FMess->ShowModal(); // показать как модальное окно и вернуть код выбранной кнопки
//
 FMess->Free(); // уничтожили FMess
//
 return out;
//
} // --- конец с_MessageDialog -------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_DrawDiagrTiers()
{ // строит графическое изображение (диаграмму)
 INT MinOpsOnTier, // минимум операторов на €русе
     MaxOpsOnTier, // максимум операторов на €русе
     OpsOnTier,
     H_pix, B_pix, // высота и ширина области отрисовки IM1 в пикселах
     B_rect, // ширина горизонтальной полоски в пикселах
     x1,y1, x2,y2; // координаты горизонтальной полоски в пикселах
//
 if( !flagExistsTiers ) // массива Tiers[][] ещЄ нет...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 MinOpsOnTier = c_GetCountOpsOnTier( c_GetTierFirstMinOps(1, nTiers) ); // минимум ...
 MaxOpsOnTier = c_GetCountOpsOnTier( c_GetTierFirstMaxOps(1, nTiers) ); // максимум операторов на €рус
//
////////////////////////////////////////////////////////////////////////////////
 TIM1->Picture->Bitmap->Height = TIM1->Height; // настроить размеры —anvas по размерам Image
 TIM1->Picture->Bitmap->Width  = TIM1->Width;  // !!! ќ„≈Ќ№ ¬ј∆Ќќ ( инфо 08.02.2017 ) !!!!!!
//
 H_pix = TIM1->Height; // высота и ширина области отрисовки IM1 в пикселах
 B_pix = TIM1->Width;
//
 REAL dH_pix = (REAL)H_pix / nTiers, // единица в  пикселах по высоте и ширине области отрисовки диаграммы
      dB_pix = (REAL)B_pix / MaxOpsOnTier;
//
 dH_pix = max( dH_pix, 1.0 ); // высота должна быть  <= 1 , иначе отрисовка невозможна...
//
// --- настройка параметров кисти и карандаша (пера) ---------------------------
 TIM1->Canvas->CopyMode     = cmSrcCopy; // запись пикселов поверх существующих
//
 TIM1->Canvas->Brush->Style = bsSolid; // сплошна€ кисть
//
 TIM1->Canvas->Pen->Style   = psSolid; // сплошной
 TIM1->Canvas->Pen->Mode    = pmCopy;  // режим цвет = color
 TIM1->Canvas->Pen->Width   = 1; // толщина = 1
//
 TIM1->Transparent = false; // !!! об€зательно !!! „тобы не было видно, что ѕќƒ IM1
//
 for(INT iTier=1; iTier<=nTiers; iTier++) // цикл по всем €русам яѕ‘ дл€ построени€ графика
 {
  F2->L_OM->Repaint(); // нужно дл€ синхронизации... !!!!!!!!!!!!!!!!!!!!!!!!!!!
//
  OpsOnTier = c_GetCountOpsOnTier( iTier ); // вз€ли число операторов на €русе
  B_rect = dB_pix * OpsOnTier; // ширина горизонтальной полоски
//
// --- устанавливаем цвета графика ---------------------------------------------
  if( OpsOnTier == MinOpsOnTier )
   TIM1->Canvas->Brush->Color = brush_draw_color_MIN; // цвет кисти ћ»Ќ»ћ”ћ
  else
  if( OpsOnTier == MaxOpsOnTier )
   TIM1->Canvas->Brush->Color = brush_draw_color_MAX; // цвет кисти ћј —»ћ”ћ
  else
   TIM1->Canvas->Brush->Color = brush_draw_color_TIERS; // цвет кисти обычный
////////////////////////////////////////////////////////////////////////////////
  x1 = 0;  // лева€ верхн€€ точка горизонтальной полоски ( Rectangle, Rect )
  y1 = dH_pix * ( iTier-1 );
//
  x2 = x1 + B_rect; // права€ нижн€€ точка горизонтальной полоски ( Rectangle, Rect )
  y2 = y1 + dH_pix;
//
// --- рисуем пр€моугольники длиной, пропорциональной числу операторов на €русе
  TIM1->Canvas->FillRect( TRect( x1,y1, x2,y2 ) ); // пр€моугольник заданной кистью
//
//  Delay( 1 ); // задержка 1 msec - без неЄ отрисовка иногда не получаетс€..!
//
  Application->ProcessMessages(); // дать поработать Windows
//
 } // конец цикла по iTier
//
////////////////////////////////////////////////////////////////////////////////
// ----- рисуем вертикальную линию - средее значение ширин €русов --------------
  REAL b_average = (REAL)c_GetCountOps() / c_GetCountTiers(); // средн€€ ширина яѕ‘
//
  TIM1->Canvas->Pen->Color = pen_draw_b_average; // цвет линии среднего числа операторов по €русам; // цвет пера
  TIM1->Canvas->Pen->Mode  = pmCopy; // цвет при взимодействии с фоном
  TIM1->Canvas->Pen->Style = psDot; // точечна€ лини€
  TIM1->Canvas->Pen->Width = 1; // толщина пера 3 пиксел€
//
  x1 = x2 = b_average * dB_pix ;
  y1 = 0; y2 = TIM1->Height;
//
  TIM1->Canvas->MoveTo( x1,   y1 ); // перевести перо в x1,y1
  TIM1->Canvas->LineTo( x1,   y2 ); // провести линию в x1,y2
//
  TIM1->Canvas->MoveTo( x1-1, y1 ); // перевести перо в x1-1,y1
  TIM1->Canvas->LineTo( x1-1, y2 ); // провести линию в x1-1,y2
//
  TIM1->Canvas->MoveTo( x1+1, y1 ); // перевести перо в x1+1,y1
  TIM1->Canvas->LineTo( x1+1, y2 ); // провести линию в x1+1,y2
//
//  TIM1->Repaint(); // принудительно перерисовали
//
  return true; // всЄ успешно сделано
//
} // --- конец с_DrawDiagrTiers ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ClearDiagrArea()
{ // стирјет графическое изображение (диаграмму)
//
 TIM1->Transparent = false; // !!! об€зательно !!! „тобы не было видно, что ѕќƒ IM1
//
 TIM1->Canvas->Brush->Color = clear_brush_draw_color; // цвет кисти
 TIM1->Canvas->Brush->Style = bsSolid; // сплошна€ кисть
 TIM1->Canvas->FillRect( TRect( TIM1->Left-2, TIM1->Top-1, // пр€моугольник кистью Brush
                                TIM1->Left +  TIM1->Width, TIM1->Top + TIM1->Height ));
 return true; // всЄ нормально
//
} // --- конец с_ClearDiagrArea ------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
// ===== работа с метриками вершин (операторо) =================================
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountMetricsByOp(INT Op)
{ // --- возвращает число метрик вершины (оператора) Op ------------------------
 char str[_4096];
 INT k = 0;
//
 strNcpy( str, c_GetMetricsByOp( Op )  ); // берЄм всю строку параметров
//
 for( INT i=0; str[i+1]!='\0'; i++ ) // по строке сравниваем по два символа
  if ( (str[i]=='-') && (isalpha(str[i+1])) ) // проверка на ЎјЅЋќЌ ['-' + лат.буква]
   k ++ ; // запомнили, какой раз встречаетс€ ['-' + лат.буква]
//
 return ( k ) ;
//
} // --- конец  c_GetCountMetricsByOp ------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNumbMetricByOp(INT Numb, INT Op)
{ // --- возвращает подстроку Numb строки метрики вершины (вычислител€) вычислител€ Op
// --- ищем двухсимвольный ЎјЅЋќЌ '-'+лат.буква] -------------------------------
 char sN[_4096], sR[_2048];
 INT iStart = 0, iEnd,
     rep=0; // номер подстроки ЎјЅЋќЌј
//
 strNcpy( sN, c_GetMetricsByOp( Op ) ); // берЄм подстроку параметров дл€ верщины (оператора) Op
 INT lN = strlen( sN ); // длина строки sN
//
 do // по подстрокам '-' + лат.буква ( по sN )
 {
  iEnd = c_FindSubString( sN, sR, iStart, 1 );
//
// --- начало обработки строки sN списка параметров параметра ------------------
//
  rep ++ ; // номер вхождени€ sR в sN
//
  if ( rep == Numb ) // нашли что надо...
  {
   DeleteSpacesTabsAround( sR ); // удал€ем пробелы спереди и сзади
   return sR ; // возвращаем результат
  }
//
// --- конец обработки строки sN спиcка параметров -----------------------------
//  cont_i:
  iStart = iEnd;
 } while( iEnd !=lN ); // пока не конец строки sN
//
 return "\0" ; // если ничего не нашли...
//
} // --- конец c_GetNumbMrtricByOp ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetMetricsByOp(INT Op)
{ // проcматривает строку sVrt и возвращает подстроку всех параметров ¬≈–Ў»Ќџ (оператора) Op
 char sN[_8192], sName[_128];
 INT  lVrt, iStart=0, iEnd, n1, n2;
//
 if( ! (lVrt = strlen( sVrt ) ) ) // если строка метрик ¬≈–Ў»Ќ пуста€...
  return "\0" ;
//
////////////////////////////////////////////////////////////////////////////////
// --- начали искать sN среди подстрок типа '=n1/n2:'---------------------------
//
 do // по подстрокам '=n1/n2:' или '=Def:'
 {
  iEnd = c_FindSubString( sVrt, sN, iStart, 0 );
// --- начало обработки строки sOps списка параметров --------------------------
//
  if( cmp_def( sN ) ) // '=Def:' пока не нужна... уходим на do !
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
  if( Test_n1n2 ) // правильное чтение "=n1/n2:^" из sN
   if( Op >= min(n1,n2) && Op <= max(n1,n2) ) // Op в диапазоне n1-n2
    return strchr( sN,':' ) + 2 ; // перескакиваем через ':' и 'пробел'
//
// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lVrt ); // пока не конец строки sVrt ( конец соотв. do )
//
////////////////////////////////////////////////////////////////////////////////
// --- начали искать sN среди подстрок типа '=Def:'-----------------------------
//
 iStart = 0;
//
 do // по подстрокам '=n1/n2:' или '=Def:'
 {
  iEnd = c_FindSubString( sVrt, sN, iStart, 0 );
// --- начало обработки строки sMess списка параметров -------------------------
//
  if( ! cmp_def( sN ) ) // '=Def:' как раз нужна...
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
  if( sscanf( sN, "%s ", sName ) == 1 ) // правильное чтение
   return strchr( sN,':' ) + 2 ; // перескакиваем через ':' и 'пробел'
//
// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lVrt ); // пока не конец строки sVrt ( конец соотв. do )
//
////////////////////////////////////////////////////////////////////////////////
//
 return "\0" ; // не найдено вообще ничего - возращаем (по умолчанию)
//
} // --- конец c_GetMetricsByOp ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
REAL __fastcall c_GetMetricOpByName( INT Op, char* nameMetric )
{ // вернуть числовое значение метрики nameMetric вершины (оператора) Op
 char sW[_512], nameM[_128];
 REAL Val; // значение метрики
//
 for( INT iM=1; iM<=c_GetCountMetricsByOp(Op); iM++ ) // цикл по парам "-nameMetric Val"
 {
  strNcpy( sW, c_GetNumbMetricByOp( iM, Op ) ); // запомнить эту подстроку в s
  if ( sscanf( sW, "-%s %g", nameM, &Val) != 2 ) // пытаемс€ прочитать "-nameMetric Val"
   continue;
//
  if ( !strcmp( nameM, nameMetric ) ) // если нашли нужное - возвращаем Val
   return Val;
 }
//
 return ERR_METRIC ; // если по имени метрики ничего не найдено...
//
} // ----- конец c_GetMetricOpByName -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// ==== работа с метриками дуг =================================================
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountMetricsByEdge(INT from_Op,INT to_Op)
{ // --- возвращает число метрик дуг между вершинами from_Op-to_Op -------------
 char str[_4096];
 INT k = 0;
//
 strNcpy( str, c_GetMetricsByEdge( from_Op, to_Op )  ); // берЄм всю строку параметров
//
 for( INT i=0; str[i+1] != '\0'; i++ ) // по строке сравниваем по два символа
  if ( (str[i]=='-') && (isalpha(str[i+1])) ) // проверка на ЎјЅЋќЌ ['-' + лат.буква]
   k ++ ; // запомнили, какой раз встречаетс€ ['-' + лат.буква]
//
 return ( k ) ;
//
} // --- конец  c_GetCountMetricsByEdge ----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNumbMetricByEdge(INT Numb, INT from_Op, INT to_Op)
{ // --- возвращает подстроку Numb строки метрики вершины (вычислител€) вычислител€ Op
// --- ищем двухсимвольный ЎјЅЋќЌ '-'+лат.буква] -------------------------------
 char sN[_4096], sR[_2048];
 INT iStart = 0, iEnd,
     rep=0; // номер подстроки ЎјЅЋќЌј
//
 strNcpy( sN, c_GetMetricsByEdge( from_Op, to_Op ) ); // берЄм подстроку параметров дл€ верщины (оператора) from_Op - to_Op
 INT lN = strlen( sN ); // длина строки sN
//
 do // по подстрокам '-' + лат.буква ( по sN )
 {
  iEnd = c_FindSubString( sN, sR, iStart, 1 );
//
// --- начало обработки строки sN списка параметров параметра ------------------
//
  rep ++ ; // номер вхождени€ sR в sN
//
  if ( rep == Numb ) // нашли что надо...
  {
   DeleteSpacesTabsAround( sR ); // удал€ем пробелы спереди и сзади
   return sR ; // возвращаем результат
  }
//
// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lN ); // пока не конец строки sN
//
 return "\0" ; // если ничего не нашли...
//
} // --- конец c_GetNumbMrtricByEdge -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetMetricsByEdge(INT from_Op, INT to_Op)
{ // проcматривает строку sVrt и возвращает подстроку всех параметров ¬≈–Ў»Ќџ (оператора) Op
 char sN[_8192], sName[_128];
 INT  lEdg, iStart=0, iEnd, n1,n2, m1,m2;
//
 if( ! (lEdg = strlen( sEdg ) ) ) // если строка метрик ¬≈–Ў»Ќ пуста€...
  return "\0" ;
//
////////////////////////////////////////////////////////////////////////////////
// --- начали искать sN среди подстрок типа '=n1/n2:'---------------------------
//
 do // по подстрокам '=n1/n2:' или '=Def:'
 {
  iEnd = c_FindSubString( sEdg, sN, iStart, 0 );
// --- начало обработки строки sOps списка параметров --------------------------
//
  if( cmp_def( sN ) ) // '=Def:' пока не нужна... уходим на do !
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
  if( Test_n1n2m1m2 ) // правильное чтение "=n1/n2|m1/m2:^" из sN
   if( ( from_Op >= min(n1,n2) && from_Op <= max(n1,n2) ) &&
       (   to_Op >= min(m1,m2) &&   to_Op <= max(m1,m2) ) ) // Op в диапазоне n1/n2 - m1/m2
    return strchr( sN,':' ) + 2 ; // перескакиваем через ':' и 'пробел'
//
// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lEdg ); // пока не конец строки sVrt ( конец соотв. do )
//
////////////////////////////////////////////////////////////////////////////////
// --- начали искать sN среди подстрок типа '=Def:'-----------------------------
//
 iStart = 0;
//
 do // по подстрокам '=n1/n2|m1/m2:' или '=Def:'
 {
  iEnd = c_FindSubString( sEdg, sN, iStart, 0 );
// --- начало обработки строки sMess списка параметров -------------------------
//
//  DelSpacesTabsAround( sN ); // обрезаем внешние пробелы
//
//  if( strncmp( sN, sDef, 5 ) ) // '=Def:' как раз нужна...
  if( ! cmp_def( sN ) ) // '=Def:' как раз нужна...
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
  if( sscanf( sN, "%s ", sName ) == 1 ) // правильное чтение
   return strchr( sN,':' ) + 2 ; // перескакиваем через ':' и 'пробел'
//
// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lEdg ); // пока не конец строки sEdg ( конец соотв. do )
//
////////////////////////////////////////////////////////////////////////////////
//
 return "\0" ; // не найдено вообще ничего - возращаем (по умолчанию)
//
} // --- конец c_GetMetricsByEdge ----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
REAL __fastcall c_GetMetricEdgeByName(INT from_Op, INT to_Op, char* nameMetric)
{ // вернуть числовое значение метрики nameMetric дуги from_Op - to_Op
 char sW[_512], nameM[_128];
 REAL Val; // значение метрики
//
 for( INT iM=1; iM<=c_GetCountMetricsByEdge(from_Op,to_Op); iM++ ) // цикл по парам "-nameMetric Val"
 {
  strNcpy( sW, c_GetNumbMetricByEdge( iM, from_Op, to_Op ) ); // запомнить эту подстроку в sW
  if ( sscanf( sW, "-%s %g", nameM, &Val) != 2 ) // пытаемс€ прочитать "-nameMetric Val"
   continue;
//
  if ( !strcmp( nameM, nameMetric ) ) // если нашли нужное - возвращаем Val
   return Val;
 }
//
 return ERR_METRIC ; // если по имени метрики ничего не найдено...
//
} // ----- конец c_GetMetricEdgeByName ------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsOpContainOnTiers(INT Op)
{ // если оператор Op присутствует в Tiers[][], возращаетс€ true, иначе - false
 bool out = false;
 register INT i;
//
 if( !flagExistsEdges ) // массива Mem_Edges[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(i=1; i<=c_GetCountOps(); i++) // по всем операторам
  if( c_GetNumbOp( i ) == Op )
   return true;
//
 return out;
//
} // ---- конец c_IsOpContainOnTiers -------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutTLDToTextFrame()
{ // выдать диаграмму времени жизни данных в текстовое окно
//
 t_printf( "\n-=- ƒиаграмма времени жизни внутренних данных -=-\n     (интервалов диапазонов €русов яѕ‘ = %d )", nTiers+1 ); // строка с числом €русов
//
 if( !flagCalcTLD ) // если paramsTLD не вычислен...
 {
  c_CalcParamsTLD(); // вычислить диаграмму времени жизни данных по текущему Tiers[][]
  flagCalcTLD = true ; // установить flag "paramsTLD соответствует текущему Tiers[][]"
 }
//
 for( INT i=1; i<=paramsTLD->Count-1; i++ ) // кроме 0-й строки из TLD
  t_printf( "%s", paramsTLD->Strings[i] ) ;
//
// === начало обработки информации о времени жизни данных между €русами яѕ‘ ====
//
 INT iGap,nGaps, n1, n2, CountTLD, // n1,n2 - номера промежутков между €русами яѕ‘, CountTLD - число данных в этом промежутке
     maxCountTLD_0 = _minINT, minCountTLD_0 = _maxINT, // max/min данных - диапазон 0/$
     maxCountTLD_1 = _minINT, minCountTLD_1 = _maxINT, // max/min данных - диапазон 1/$
     n1x_0,n1x_1, n2x_0,n2x_1, n1n_0,n1n_1, n2n_0,n2n_1; //  диапазоны €русов выше и ниже рассматриваеиого промежутка
 REAL averTLD_0=0.0, // средне-арифметическое времени жизни данных в диапазоне промежутков €русов 0/$
      averTLD_1=0.0; // то же в диапазоне промежутков €русов 1/$
//
 if( !flagCalcTLD ) // если paramsTLD не вычислен...
 {
  c_CalcParamsTLD(); // вычислить диаграмму времени жизни данных по текущему Tiers[][]
  flagCalcTLD = true ; // установить flag "paramsTLD соответствует текущему Tiers[][]"
 }
//
 sscanf( paramsTLD->Strings[0].c_str(), "%d", &nGaps ); // число промежутков (Gap) €русов в яѕ‘
//
 for( iGap=1; iGap<=nGaps; iGap++ ) // по числу промежутков (Gap) между €русами яѕ‘
 {
  if( iGap < nGaps ) // кроме последней строки с $
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/%d|%d:", &n1,&n2,&CountTLD ); // верхний / нижний €рус / число данных в этом промежутке
  else // последн€€ строка формата "n/$|m"
  {
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/" SS_02 "|%d:", &n1,&CountTLD ); // верхний €рус / $ / число данных в этом промежутке
   n2=n1+1;
  }
// вычисл€ем статистику TLD в диапазоне промежутков €русов 0/$ =================
//
// ищем мах TLD в диапазоне промежутков €русов 0/$ -----------------------------
  if( CountTLD >= maxCountTLD_0 )
  { maxCountTLD_0 = max(maxCountTLD_0,CountTLD); n1x_0=n1; n2x_0=n2; } // запомнили €рус выше | запомнили €рус ниже (избыточно вообще-то...)
// ищем мin TLD в диапазоне промежутков €русов 0/$ -----------------------------
  if( CountTLD < minCountTLD_0 )
  { minCountTLD_0 = min(minCountTLD_0,CountTLD); n1n_0=n1; n2n_0=n2; } // запомнили €рус выше | запомнили €рус ниже (избыточно вообще-то...)
//
  averTLD_0 += (REAL)CountTLD; // средне-арифметическое времени жизни данных
// конец обработки TLD в диапазоне 0/$ -----------------------------------------
//
// вычисл€ем статистику TLD в диапазоне промежутков €русов 1/$ =================
  if( iGap == 1 )
   continue; // не обрабатываем 1-й промежуток (€руса 0-1) ---------------------
//
// ищем мах TLD в диапазоне промежутков €русов 1/$ -----------------------------
  if( CountTLD >= maxCountTLD_1 )
  { maxCountTLD_1 = max(maxCountTLD_1,CountTLD); n1x_1=n1; n2x_1=n2; } // запомнили €рус выше | запомнили €рус ниже (избыточно вообще-то...)
// ищем мin TLD в диапазоне промежутков €русов 1/$ -----------------------------
  if( CountTLD < minCountTLD_1 )
  { minCountTLD_1 = min(minCountTLD_1,CountTLD); n1n_1=n1; n2n_1=n2; } // запомнили €рус выше | запомнили €рус ниже (избыточно вообще-то...)
//
  averTLD_1 += (REAL)CountTLD; // средне-арифметическое времени жизни данных
//
 } // конец цикла по промежуткам между €русами яѕ‘
//
// дополнение строки информацией о времени жизни данных
//
 char szStatTLD[_512], // строка данных о времени жизни локальных данных (ParamsTLD)
      szTemp_0[_128], szTemp_1[_128] ;
// работаем со строками статистики TLD в диапазоне €русов 0/$ -------------------
 n2n_0==nGaps ? sprintf( szStatTLD,"»того:\n0/$: min=%d(%d/" SS_02 "), ", minCountTLD_0,n1n_0 ) :
                sprintf( szStatTLD,"»того:\n0/$: min=%d(%d/%d), ",        minCountTLD_0,n1n_0, n2n_0 ) ;
 n2x_0==nGaps ? sprintf( szTemp_0, "max=%d(%d/" SS_02 "), ср.арифм.=%.4g; сумма(TLD)=%.4g", maxCountTLD_0,n1x_0,        averTLD_0 / nGaps, averTLD_0 ) :
                sprintf( szTemp_0, "max=%d(%d/%d), ср.арифм.=%.4g; сумма(TLD)=%.4g",        maxCountTLD_0,n1x_0, n2x_0, averTLD_0 / nGaps, averTLD_0 ) ;
 strcat( szStatTLD, szTemp_0 ); // подготовили строку дл€ вывода на F2
 t_printf( "\n%s", szStatTLD ); // вывод TLD-данных в диапазоне €русов 0/$ в текстовый фрейм
//
// работаем со строками статистики TLD в диапазоне €русов 1/$ -------------------
 n2n_1==nGaps ? sprintf( szStatTLD,"1/$: min=%d(%d/" SS_02 "), ", minCountTLD_1,n1n_1 ) :
                sprintf( szStatTLD,"1/$: min=%d(%d/%d), ",        minCountTLD_1,n1n_1, n2n_1 ) ;
 n2x_1==nGaps ? sprintf( szTemp_1, "max=%d(%d/" SS_02 "), ср.арифм.=%.4g; сумма(TLD)=%.4g", maxCountTLD_1,n1x_1,        averTLD_1 / (nGaps-1.0), averTLD_1 ) :
                sprintf( szTemp_1, "max=%d(%d/%d), ср.арифм.=%.4g; сумма(TLD)=%.4g",        maxCountTLD_1,n1x_1, n2x_1, averTLD_1 / (nGaps-1.0), averTLD_1 ) ;
//
 strcat( szStatTLD, szTemp_1 );
 t_printf( "%s\n", szStatTLD ); // вывод TLD-данных в диапазоне €русов 1/$ в текстовый фрейм
//
} // ----- конец c_PutTLDToTextFrame -------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_SaveTLD( char FileName[] )
{ // выдать диаграмму времени жизни данных в файл
//
 FILE *fptr = NULL; // рабочий указатель на файл
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extTld) ); // преобразованное им€ файла
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // если MewFileName уже существует...
//
 if(!(fptr = fopen( NewFileName,"w" ))) // открыли дл€ записи
 {
  t_printf( "\n-E- Ќевозможно записать файл %s времени жизни внутренних данных -E-\n\n-W- проверьте осуществимость записи на заданный носитель данных -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // вернуть число как строку
 }
//
// setbuf( fptr, NULL ); // отключили буфферизацию при записи
//
 if( !flagCalcTLD ) // если paramsTLD не вычислен...
 {
  c_CalcParamsTLD(); // вычислить диаграмму времени жизни данных по текущему Tiers[][]
  flagCalcTLD = true ; // установить flag "paramsTLD соответствует текущему Tiers[][]"
 }
//
 for( INT i=0; i<=paramsTLD->Count-1; i++ ) // кроме 0-й строки из TLD
 {
  DeleteSymbolAll( paramsTLD->Strings[i].c_str(), *_OUT ) ; // уничтожили символ _OUT[0] = ">>" в встроке
  DeleteSymbolAll( paramsTLD->Strings[i].c_str(), *_IN ) ; // уничтожили символ _IN[0] = "<<" в строке
//
  fprintf( fptr, "%s\n", paramsTLD->Strings[i] ); // печать в файл
 }
//
 fclose( fptr ) ; // закрыть файл
//
 return NewFileName ;
//
} // ----- конец c_SaveTLD -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_WinExec( char *cmdLine, INT cmdShow )
{ // выполнить системный вызов WinExec -----------------------------------------
// t_printf( "\n->%s %d %d\n", cmdLine, cmdShow, WinExec( cmdLine, cmdShow ) );
 return WinExec( cmdLine, cmdShow );
} // ----- конец c_WinExec -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_ShellExecute( char *Operation, char *File, char *Parameters, char *Directory, INT cmdShow )
{ // выполнить системный вызов ShellExecute ------------------------------------
// t_printf( "\n->%s %s %s %s %d\n", Operation, File, Parameters, Directory, cmdShow );
 return (INT)ShellExecute( Application->Handle, Operation, File, Parameters, Directory, cmdShow );
} // ----- конец c_ShellExecute ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall
c_CreateProcess(char* CommandLine, byte RuleParent, byte Priority, bool RuleMessage)
// пытаетс€ стартовать процесс-потомок согласно командной строкe CommandLine
// при RuleParent=0 процесс-родитель ждет окончани€ работы потомка (при этом
// позвол€€ работать другим WINDOWS-приложени€м через вызовы ProcessMessages)
// при RuleParent=1 процесс-родитель не ждет окончани€ работы потомка
// при всех других значени€х RuleParent процесс-родитель
// после запуска процесса-потомка завершаетс€.
//-----------------------------------------------------------------------
// Priority=0/1/2/3 соответствует приоритетам запускаемого приложени€
//           REALTIME/HIGH/NORMAL/IDLE соответственно (дл€ 16-бит не используетс€)
//          (все другие значени€ Priority соответствуют IDLE)
//-----------------------------------------------------------------------
//  ѕри RuleMessage=true выдаетс€ сообщение об ошибках }
{
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  DWORD dwCreationFlag,dwExitCode;
  bool out;
//
// все пол€ структуры si (кроме пол€ cb) должны быть обнулены
// т.к. этих полей много, присвоение нул€ каждому писать лень...
// ниже приведен метод заполнени€ структуры нул€ми (используетс€ FillChar)
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
  out = CreateProcess(NULL,CommandLine,NULL,NULL,false,
                      dwCreationFlag,NULL,NULL,&si,&pi);
//
  if (!out) // если старт неудачен... out=false
  {
   if (RuleMessage)  // если задан режим выдачи сообщений об ошибках
    MessageDlg("»звините, выполнение\n\r\n\r" +
                AnsiUpperCase(CommandLine)  +
               "\n\r\n\rневозможно...  (ошибка " +
                IntToStr(GetLastError()) + ")",
                mtError,
                TMsgDlgButtons() << mbYes, 0);
   return false ;
  } // конец IF out = false
//
  if (out) // если старт удачен... out = true
  {
   if (RuleParent == 0) // если родитель должен ждать окончани€ работы потомка
   {
    CloseHandle(pi.hThread); // хэндл потока не нужен - удал€ем
    if (WaitForSingleObject(pi.hProcess, INFINITE) != WAIT_FAILED) // бесконечный цикл ожидани€
    {
     GetExitCodeProcess(pi.hProcess, &dwExitCode); // если ошибка функции ожидани€...
     if (RuleMessage) // если задан режим выдачи сообщений об ошибках
      if (dwExitCode != WAIT_OBJECT_0) // WAIT_OBJECT_0 = естественное завершение процесса
       MessageDlg("»звините, процесс\n\r\n\r" +
                   AnsiUpperCase(CommandLine) +
                  "\n\r\n\rзакончен с ошибкой " +
                   IntToStr(dwExitCode) + "\n\r",
                   mtError,
                   TMsgDlgButtons() << mbOK, 0);
     CloseHandle(pi.hProcess); // освобождаем хэндл процесса
    } // конец IF WaitForSingleObject...
   } // конец IF RuleParent = 0
//
   if (RuleParent == 1) // родитель не должен ждать окончани€ работы потомка
    return false ; // выход - ничего не дела€
//
   if ((RuleParent != 0) && // родитель завершаетс€
       (RuleParent != 1))
    Application->Terminate(); // закончить родительский процесс
//
 } // конец IF out=true
//
} // ----- конец c_CreateProcess -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//INT __fastcall c_CreateProsess( char *cmdLine, byte RuleParent, byte Priority, bool RuleMessage )
//{ // выполнить системный вызов CreateProsess -----------------------------------
// tp_printf( "\n->%s %d %d %d\n", cmdLine, RuleParent, Priority, RuleMessage );
// c_CreateProcess( cmdLine, RuleParent, Priority, RuleMessage );
//} // ----- конец c_CreateProcess -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_SaveEdges(char FileName[])
{  // вывод дуг дл€ полного описани€ графа
 FILE *fptr = NULL; // рабочий указатель на файл
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName( FileName,extGv ) ); // преобразованное им€ файла
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // если MewFileName уже существует...
//
 if(!(fptr = fopen(NewFileName, "w"))) // открыли дл€ записи
 {
  t_printf( "\n-E- Ќевозможно сохранить файл %s списка дуг (комплементарных вершин) »√ј -E-\n-W- проверьте осуществимость записи на заданный носитель данных -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // вернуть число как строку
 }
//
// setbuf( fptr, NULL ); // отключили буфферизацию при записи
//
 fprintf( fptr, "#\n// Valery Bakanov research computer complex (2008 and further); e881e@mail.ru, http://vbakanov.ru/left_1.htm\n");
 fprintf( fptr, "#  Total edges in this directed graph: %d\n", nEdges ); // число дуг
 fprintf( fptr, "/* This file was automatically created thru program SPF_CLIENT.EXE\n" ); // какой программо создан файл
 fprintf( fptr, "   file name: %s , datа creation: %s */\n#\n", AnsiUpperCase(NewFileName) , uniqueStr );  // дата создани€
 fprintf( fptr, "digraph %s {\n", AnsiUpperCase(ChangeFileExt(ExtractFileName(NewFileName),"") )); // им€ файла без расширени€
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по дугам графа
  fprintf(fptr, "%d -> %d ;\n", Edges(0,iEdge), Edges(1,iEdge)); // оператор "откуда" -> оператор "куда"
//
 fprintf( fptr, "}\n" ); // последн€€ строка файла
//
 fclose( fptr); // закрыли файл
//
 return NewFileName ;
//
} // --- конец c_SaveEdges -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ReadEdges(char FileName[])
{ // читает из файла FileName данные о графе (массив Mem_Edges[][] св€зей вершин
// - и список операторов на уровне Tier = 0 - входные данные ); Mem_Edges[][]
// - и Tiers[][] - глобальные; при ошибке открыти€ файла FileName возращаетс€ false
 char str[_2048*4];
 FILE *fptr = NULL; // указатель на файл
 bool flagEdges = false, // флаг начала описани€ дуг в »√A
      flagMLC   = false; // флаг многострочного комментари€ (Many Lines Comment)
//
 flagExistsEdges =  // массив Mem_Edges[][] не создан...
 flagExistsOps   =  // nOps не вычислено
 flagExistsTiers = false ; // массив Tiers[][] не создан...
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extGv) ); // преобразованное им€ файла
//
 if( !(fptr = fopen(NewFileName, "r")) ) // файл описани€ графа открыли дл€ чтени€
 {
  t_printf( "\n-E- Ќевозможно прочитать файл %s описани€ »√ј -E-\n-W- веро€тна некорректность при дальнейшей работе -W-",
                   NewFileName );
  return false ;
 }
//
 strNcpy( FileNameEdges, NewFileName ); // запомнили текущее им€ файла описани€ »√ј
//
 Max_Edges = _128; // первоначальное максимальное количество дуг в »√ј
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 Mem_Edges = ( me* ) realloc( Mem_Edges, Max_Edges * sizeof( me ) ); // перераспределить пам€ть массив структур дуг информационного графа
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 nEdges = 1; // число дуг в »√ј (глобальное, дл€ совместимости с Lua индексируем с 1 )
//
 while ( 1 ) // бесконечный цикл по строкам GV-файла
 {
  if( fgets( str,sizeof(str), fptr ) == NULL ) // читаем очередную строку GV-файла
   break; // если строки кончились или ошибка считывани€...
//
  ReplaceManySpacesOne( str ); // замен€ем множество пробелов внутри строки одним-единственным
  DeleteSpacesTabsAround( str ); // удал€ем пробелы в начале и конце строки
//
  if( ( str[0] == '#' ) || ( (str[0] == '/') && (str[1] == '/') ) )
   continue; // строку пропускаем - это комментарий
//
  if( str[0] == '/' && str[1] == '*' ) // начало многострочного комментари€
  {
   flagMLC = true; // начало многострочного комментари€
   continue; // эту строку пропускаем
  }
  if( str[0] == '*' && str[1] == '/' ) // конец многострочного комментари€
  {
   flagMLC = false; // начало многострочного комментари€
   continue; // эту строку пропускаем
  }
//
  if( sscanf( str, "digraph %s {", GraphName ) == 1 ) // ровно одно поле прочитано...
   flagEdges = true; // начало описани€ дуг »√ј
  if( str[0] == '}' )
   flagEdges = false; // конец описани€ дуг »√ј
//
//  if( flagEdges && !flagMLC )
  if( flagEdges )
   if ( !ParseStringAndAddEdges( str ) ) // отправл€ем строку str на рвзборку и пополнение массива дуг
    return false;
//
////////////////////////////////////////////////////////////////////////////////
 } // конец while( 1) ----------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
//
 fclose(fptr); // закрыли файл FileName
//
 nEdges -- ; // всего дуг в »√ј (global)
//
 t_printf( "\n-I- ‘айл %s описани€ графа успешно прочитан -I-", FileNameEdges );
//
 flagExistsEdges = true ; // массив Mem_Edges[][] создан !!!
//
 flagExistsOps = false; // число операторов неизвестно
 c_GetCountOps(); // подсчЄт числа операторов (вершин графа) Ѕ≈« ¬’ќƒЌџ’
 flagExistsOps = true; // ... на вс€кий случай !
//
 c_GetCountOpsInput(); // подсчЄт числа операторов (вершин графа) “ќЋ№ ќ ¬’ќƒЌџ≈
//
 c_GetCountOpsOutput(); // подсчЄт числа операторов (вершин графа) “ќЋ№ ќ ¬џ’ќƒЌџ≈
//
////////////////////////////////////////////////////////////////////////////////
 snprintf( str,sizeof(str), "%s (»√ј - файл: %s ; им€: %s)", TitleF2, FileNameEdges, GraphName );
 F2->L_TMM->Caption = str;
 F2->L_TMM->Repaint();
////////////////////////////////////////////////////////////////////////////////
//
 flagExistsTiers = false; // массив Tiers[][] не создан
//
 return true ;
//
} // ------ конец c_ReadEdges --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall TestAndAddMemoryForEdges( INT nEdges )
{ // тестирует необходимость увеличени€ массива дуг Mem_Edges[][] и при
// необходимости увеличивает его в stockMem раз. ѕри успехе возращает true...
//
 if( nEdges < Max_Edges ) // пам€ти дл€ массива Mem_Edges[][] достаточно...
  return true;
//
// ===== пам€ти не хватает =====================================================
//
 Max_Edges *= stockMem; // захватываем в stockMem раз больше, чем было...
 Mem_Edges = ( me* ) realloc( Mem_Edges, Max_Edges * sizeof(me) ); // реаллокировали пам€ть под Mem_Edges[][]...
//
 if( !Mem_Edges ) // совсем плохо - реалокировать дополнительную пам€ть не получилось..!
 {
  char str[_1024];
  snprintf(str,sizeof(str), "Ќехватка пам€ти дл€ размещени€ массива ƒ”√ (Input). «атребовано %d элементов...",
                             Max_Edges );
  MessageBeep(MB_OK); // звуковое предупреждение...
  MessageBox(0, str, "ѕредупреждение", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  flagExistsEdges = false ; // массив Mem_Edges[][] не создан...
  return false ;
 } // конец  if( Mem_Edges == NULL )
 else
 {
  t_printf( "\n-I- ћассив ƒ”√ (Input) перераспределЄн на %d элементов -I-",  Max_Edges );
  return true;
 }
//
} // ---- конец TestAndAddMemoryForEdges ---------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall ParseStringAndAddEdges( char *str )
{ // разбирает строку str, выдел€ет составл€ющих дуги номера вершин и добавл€ет их в массив дуг
// общий формат строки: a -> b -> c -> -> d ; где a,b,c,d - целые числа
// при ошибке аллокировани€ пам€ти при расширении массива дуг возращает false
//
 INT i,j,k=0;
//
// ----- ищем начало комментари€ -----------------------------------------------
//
 for( i=0; i<strlen( str ); i++ ) // по cтроке str...
  if( str[i] == ';' ) // ищем первое вхождение символа ";"
  {
   for( j=i+1; j<=strlen(str); j++ ) // от первого справа символа за ";" до конца строки
    Mem_Edges[ nEdges ].Operators[ k++ ] = str[ j ]; // копируем посимвольно
//
   DeleteSpacesTabsAround( Mem_Edges[nEdges].Operators ); // удал€ем пробелы справа и слева в строке Mem_Edges[nEdges].Operators
   ReplaceManySpacesOne( Mem_Edges[nEdges].Operators ); // множествкнные пробелы замен€ем единственным
//
//   t_printf( "-= %d %s =-", nEdges, Mem_Edges[ nEdges ].Operators );
//
   str[i] = '\0';
   break;
  }
//
 DeleteAllSpaces( str ); // удал€ем ¬—≈ пробелы в строке str
//
 while( 1 ) // бесконечный цикл по подстрокам вида "a -> b"
 {
//
  if( sscanf( str, "%d->%d", &Edges(0,nEdges), &Edges(1,nEdges) ) == 2 ) // ровно 2 пол€ прочитаны
  {
   nEdges ++ ;
   if( !TestAndAddMemoryForEdges( nEdges ) ) // надо ли добавл€ть пам€ть дл€ Mem_Edges[][] ?
    return false;
  } // конец  if( sscanf( str, "%d -> %d",
 else // ровно 2 пол€ прочитать на удалось..!
  return true;
//
 for( i=0; i<strlen( str ); i++ ) // по строке str...
 {
  str[i] = ' ';
  if( str[i+1] == '>' )
  {
   str[i+1] = ' ';
   break;
  } // конец if( str[i+1] == '>' )
//
 } // конец for( i=0; i<strlen( str ); i++ )
//
 DeleteSpacesTabsAround( str ); // удал€ем пробелы в Ќј„јЋ≈ и конце строки
//
 if( strstr( str, "->" ) == NULL ) // более в str нет подстроки "->"...
  return true;
//
 } // конец while ( 1 )
//
} // ----- конец ParseStringAndAddEdges ----------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall ReadAndPrimWorkOpsCalcsVertEdgeFiles( char FileName[] )
{ // чтение и предварительна€ обработка файлов *.ops, *.cls, *.med, *.mvr
 FILE *fptr;
 char buff[_4096]; // максимальна€ длина строки файла
//
 if( !(fptr = fopen(FileName, "r")) ) // удалось открыть?..
  return false ; // не удалось открыть...
//
 strNcpy( sWork, "\0" ); // очистили строку (sWork - глобальна€)
//
 while( 1 ) // цикл по строчкам файла
 {
  if( !fgets(buff,sizeof(buff),fptr) ) // если в файле больше нет строк...
   break;
//
  for( INT i=0; i<strlen(buff); i++ ) // по всей считанной строке...
   if( buff[i] == ';' ) // ';' замен€ем на конец строки
    {
     buff[i] = '\0';
     break;
    }
//
  strcat( sWork, buff ); // buff добавл€ем в строку sWork (глобал)
 } // конец while( 1 )
//
 fclose( fptr ); // закрыли файл FileName
//
 for( INT j=0; j<strlen(sWork); j++ ) // по всей строке sWork...
  if( sWork[j] == '\n' || sWork[j] == '\r' || sWork[j] == '\t' )
   sWork[j] = ' ';
//
 DeleteSpacesTabsAround ( sWork ); // удал€ем внешние пробелы
 ReplaceManySpacesOne( sWork ); // удал€ем повторы пробелов внутри
//
 return true;
} // ----- конец ReadAndPrimWorkOpsCalcsVertEdgeFiles --------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_LuaCallByTimer( char *CommandLine, INT d_Ticks )
{ // вызов Lua-операторов с задержкой d_Tick (аналог settimeout() из JS)
//
 if( d_Ticks <= 0 )
  return -1 ;
//
 bool flag = false; // если в строке не только пробелы...
 for( int i=0; i<strlen(CommandLine); i++) // цикл по символам в строке CommandLine
 {
  if( CommandLine[i] != ' ')
  {
   flag = true; // есть хот€ бы один не-пробел..!
   break;
  }
 } // конец по символам в строке
 if( !flag ) // пуста€ строка
  return -2 ;
//
 i_Events ++ ; // зан€то элементов в массиве событий
//
 if( i_Events >= max_Events-10 ) // подошли к границе max_Events
 {
  max_Events *= 1.5 ; // увеличили верхний дапазон...
  Mem_EV = (ev*) realloc( Mem_EV, max_Events*sizeof(ev) ); // увеличили размер массива
  t_printf( "\n-I- ћассив Mem_EV перераспределЄн на %d элементов -I-", max_Events );
 }
//
 Mem_EV[i_Events].start_Ticks = ticks; // момент начала отсчЄта
 Mem_EV[i_Events].d_Ticks     = abs(d_Ticks); // заданное врем€ ожидани€ вызова
 Mem_EV[i_Events].ev_Ticks    = ticks + abs(d_Ticks); // момент вызова
 strNcpy( Mem_EV[i_Events].CommandLine, CommandLine ); // текст вызова
//
// t_printf("\nЌачало: Start: %d, Delay: %d, Now: %d ticks, [Real_Delay: %d] [i_Events: %d] |%s|\n\n",
//            Mem_EV[i_Events].start_Ticks, Mem_EV[i_Events].d_Ticks, ticks,
//            ticks-Mem_EV[i_Events].start_Ticks, i_Events, Mem_EV[i_Events].CommandLine );
//
 return 0 ; // нормальный конец функции
//
} // ------ конец c_LuaCallByTimer ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::On_Master_Timer(TObject *Sender)
{ // вызываетс€ Master_Timer'ом каждые Master_Timer->Interval миллисекунд
//
 ticks ++ ; // увеличиваем счЄтчик тиков...
//
 for( INT i=0; i<=i_Events; i++ ) // по всему массиву событий
 {
  if( Mem_EV[i].d_Ticks <= 0 || // если запаздывание менее нул€ или 0.. "»Ћ»"
      Mem_EV[i].ev_Ticks != ticks ) // врем€ вызова событи€ не равно текущему номеру тика... »Ћ»
   continue; // пропускаем цикл-c...
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  if( flag_Busy == true ) // не окончен предыдущий вызов CallLuaThread...
  {
   tpe_printf( "\n-W- ¬ызов %s пропущен из-за неокончани€ предыдущего вызова %s... -W-",
               Mem_EV[i].CommandLine, busy_CommandLine );
   continue;  // пропускаем-c...
  }
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
////////////////////////////////////////////////////////////////////////////////
// ------ всЄ нормально, выполн€ем вызов Lua в новом потоке --------------------
   CallLuaThread( Mem_EV[i].CommandLine ); // вызов CommandLine во вновь созданном потоке Lua
//
//   t_printf("\n\n онец: Start: %d, Delay: %d, Now: %d ticks, [Real_Delay: %d] [i_Events: %d] |%s|\n\n",
//            Mem_EV[i].start_Ticks, Mem_EV[i].d_Ticks, ticks,
//            ticks-Mem_EV[i].start_Ticks, i_Events, Mem_EV[i].CommandLine );
//
   if( Mem_EV[i].d_Ticks != ticks-Mem_EV[i].start_Ticks )
    tpe_printf( "\n\n-W- Ќекорректность задержки выполнени€ Lua-команды '%s', задержка задана/отмерена: %d/%d; начало/конец: %d/%d тиков -W-\n",
                Mem_EV[i].CommandLine, Mem_EV[i].d_Ticks, ticks-Mem_EV[i].start_Ticks,
                Mem_EV[i].start_Ticks, ticks );
//
   Mem_EV[i].d_Ticks *= -1; // событие произошло - его "закрыли" путЄм внесени€ отрицательного времени запаздывани€
//
 } // конец цикла по всему массиву событий for( INT i=0; i<=i_Events; i++ )
//
} // ----- конец TF1::On_Master_Timer ------------------------------------------

void __fastcall CallLuaThread( char *CommandLine )
{ // вызов CommandLine во вновь созданном потоке Lua
 char *sf = "\nѕроблемы с %s. ¬ыполнение Lua остановлено... (%s)\nѕроверьте корректность строки '%s'...\n";
 int error1, error2;
 lua_State *L1;
//
 flag_Busy = true; // выполнение CallLuaThread нјчато..!
//
 strNcpy( busy_CommandLine, CommandLine ); // сохраним им€ выполн€ющейс€ Lua-команды...
//
 try
 {
  L1 = lua_newthread( L ); // создаЄм нить (состо€ние) L1 внутри состо€ни€ L
 }
 catch( ... ) // ловим любое исключение...
 {
  tpe_printf( "\nѕроблемы с выполнением lua_newthread в вызове %s (%s)...\n", CommandLine, __FUNC__ );
  goto ended;
 } // конец cath( ... )
//
// luaL_openlibs(L1); // подключаем стандартные библиотеки
//
 try
 {
  error1 = luaL_loadstring(L1,CommandLine); // загрузка строки дл€ выполнени€
 }
 catch( ... ) // ловим любое исключение...
 {
  tpe_printf( sf, "luaL_loadstring", __FUNC__, CommandLine );
  goto ended;
 } // конец cath( ... )
//
 try
 {
  error2 = lua_pcall(L1,0,0,0); // считывание и исполнение
 }
 catch( ... ) // ловим любое исключение...
 {
  tpe_printf( sf, "lua_pcall", __FUNC__, CommandLine );
  goto ended;
 } // конец cath( ... )
//
 if( error1 || error2 )
  t_printf( "\n%s: ќшибка времени выполнени€ Lua: %s\n", __FUNC__, lua_tostring (L1,-1) );
//
ended: flag_Busy = false; // выполнение CallLuaThread закончено...
//
} // ----- конец CallLuaThread -------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_SwapOpsTierToTier(INT Op1, INT Op2)
{ // --- мен€ет местами операторы Op1 и Op2, наход€щиес€ на –ј«Ќџ’ €русах
// ----- если удалось благополучно перенести - возвращаетс€ RETURN_OK и глобальна€ iMove
//
 if( !flagExistsTiers ) // если массива Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( Op1 == Op2 )  // не желаем-с делать глупостев-с... Ќ» ј ќ√ќ ѕ≈–≈Ќќ—ј !!!
 {
  DisplayMessage( "E", __FUNC__, messParams2, false ); // выдать сообщение
  return RETURN_OK ;
 }
//
 INT TierOp1,TierOp2 ;
// 
 if( ( TierOp1 = c_GetTierByOp( Op1 ) ) == ERR_COMMON || // проверка на корректность определени€ Tier1 "»Ћ»"
     ( TierOp2 = c_GetTierByOp( Op2 ) ) == ERR_COMMON ) // ...tier2
 {
  DisplayMessage( "E", __FUNC__, messParams1, false ); // выдать сообщение
  return ERR_IN_DATA ;
 }
//
 if( ( TierOp1 < c_GetMinTierMaybeOp( Op2 ) ) || // проверка допуст.расп.опер. Op1 на €русах Op2 "»Ћ»"
     ( TierOp1 > c_GetMaxTierMaybeOp( Op2 ) ) ||
     ( TierOp2 < c_GetMinTierMaybeOp( Op1 ) ) || // проверка допуст.расп.опер. Op2 на €русах Op1 "»Ћ»"
     ( TierOp2 > c_GetMaxTierMaybeOp( Op1 ) ) )
 {
  DisplayMessage( "E", __FUNC__, messParams3, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 if( c_MoveOpTierToTier( Op1, TierOp2 ) == RETURN_OK && // успешный перенос ќp1 на €рус нахождени€ Op2 "»"
     c_MoveOpTierToTier( Op2, TierOp1 ) == RETURN_OK )  // успешный перенос ќp2 на €рус нахождени€ Op1
   return RETURN_OK ;
//
 flagCalcTLD = false ; // paramsTLD не соответствует Tiers[][]
//
 return ERR_IN_DATA ;
//
} // ----- конец c_SwapOpsTierToTier -------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall ReformFileName( char FileName[], char Ext[] )
{ // преобразует FileName в нужную форму с учЄтом необходимого расширени€ (".ext")
//
 char wF[_512],wE[_256],*p,
      NewFileName[_512],extFile[_128], // новое им€ файла, расширение без '>'
      Comma[]=".\0",Space[]=" \0",Unknown_Name[]="Unknown_Name\0", // точка, пробел, неопределенность
      UnacceptableSymbols[]="\/\\:*?\"<>|\0"; // недопустимые символы '/\:*?"<>|'
//
 if( strpbrk( ExtractFileName(FileName).c_str(),UnacceptableSymbols ) ) // проверка на недопустимые символы UnacceptableSymbols в имени файла
 {
  TVarRec Vr[]={ FileName,Unknown_Name,ExtractFileExt(FileName).c_str() }; // открытый массив дл€ последующей форматной печати
  DisplayMessage( "W", __FUNC__, TrimRight(Format("Ќедопустимое им€ файла: %s , файл переименован в: %s%s",Vr,2)).c_str(),
                   ERR_UNCERTAIN );
//
  strcpy( FileName,Unknown_Name ) ;
  strcat( FileName,ExtractFileExt(FileName).c_str() );
 }
//
 DeleteSpacesTabsAround( FileName ); // удал€ем пробелы и Tabs с начала и с конца строки
 DeleteSpacesTabsAround( Ext );
//
 if( FileName[0] == Comma[0] ) // им€ начинаетс€ с '.'
 {
  strcpy( NewFileName, Unknown_Name ) ; // в начале внесли 'Unknown_Name'
  strcat( NewFileName, ExtractFileExt(FileName).c_str() ); // прибавили расширение
  goto cont ;
 }
//
 strcpy( wF, ExtractFileName(FileName).c_str() ); // получили строку вида "xxx.zzz"
 if( !strchr(wF,Comma[0]) ) // если '.' в имени файла не найдено...
  strcat(wF,Comma); // добавили в конец имени
//
 p = strrchr( wF,Comma[0] ); // ищем ѕќ—Ћ≈ƒЌ≈≈ вхождение '.' в wF
 if( p ) // нашли ѕќ—Ћ≈ƒЌ≈≈ вхождение '.' в wF
 {
  strcpy( NewFileName, wF ); // скопировали
  NewFileName[p-wF+1] = '\0'; // ограничили следующим за '.' символом (сам '.' оставили)
 }
//
 strcpy( wE, ExtractFileExt( FileName).c_str() ); // получили строку вида ".zzz"
//
 if( wE[0] == Comma[0] ) // начальный символ wE=='.'
 {
  wE[0] = Space[0]; // начальный символ wE замен€ем на пробел
  DeleteSpacesTabsAround( wE); // чистим от пробелов
 }
//
 if( !strlen( wE ) ) // если пусто...
  strcat( NewFileName,Ext ); // добавим заданное расширение...
 else
  strcat( NewFileName,wE ); // расширение как было...
//
cont:
// t_printf( "\nѕреобразованное им€ файла/расширени€: |%s|%s|\n", NewFileName,Ext );
 return NewFileName ;
//
} // --- конец ReformFileName --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbOp(INT Numb)
{ // возвращает номер Numb оператора (исключа€ входные) по мере вхождени€ в файл дуг
// убираем повторы номеров операторов
 if( !flagExistsEdges ) // нет массива Mem_Edges[][]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ищем число операторов (имеем nEdges дуг графа)===========================
////////////////////////////////////////////////////////////////////////////////
 INT nW, iEdge, jEdge, FromTo=1,
     iOps = 0; // счЄтчик числа вершин (глобальное)
//
 for( iEdge=1; iEdge<=nEdges; iEdge++ ) // по всем дугам начина€ с #1
  Edges_f(1,iEdge) = true ; // пометили как true
//
  for(iEdge=1; iEdge<=nEdges; iEdge++) // по всем nEdges дугам начина€ с #1
// обработка случа€ ¬џ’ќƒяў≈… (To) вершины дуги iEdges
   if( Edges_f(1,iEdge) ) // запомнили "пом≈ченную" ¬џ’ќƒяў”ё вершину дуги iEdges
   {
    nW = Edges(1,iEdge);
    iOps ++ ; // счЄтчик вершин числа (¬’ќƒяў»’ по дугам)
//
    if( iOps == Numb ) // это Numb-тое вхождение номера оператора
     return nW ;
//
    for(jEdge=1; jEdge<=nEdges; jEdge++)
     if( Edges(1,jEdge) == nW )
       Edges_f(1,jEdge) = false; // сн€ли метку с вершины "куда" (To)
//
   } // конец if( Mem_Edges[iEdges].FlagFTo )
//
} // ------ конец c_GetNumbOp --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall tuneFlagsAll( bool FLAG, INT FromTo )
{ // устанавливает в FLAG все флаги операторов массива дуг Edges[][]
// обрабатываетс€ список "From" или "To" при From/To = 0/1 соответственно
//
 register INT iEdge; // попросим компил€тор..!
//
 for( iEdge=1; iEdge<=nEdges; iEdge++ ) // по всем дугам начина€ с #1
  Edges_f(FromTo,iEdge) = FLAG ; // пометили как FLAG
//
} // ----- конец tuneFlagsAll --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall tuneFlagsIfEqual( bool FLAG, INT FromTo, INT Value )
{ // устанавливает в FLAG флаги операторов массива дуг Edges[][] , если значение массива value
// обрабатываетс€ список "From" или "To" при From/To = 0/1 соответственно
//
 register INT iEdge; // попросим компил€тор..!
//
 for( iEdge=1; iEdge<=nEdges; iEdge++ ) // по всем дугам начина€ с #1
  Edges_f(FromTo,iEdge) = Edges(FromTo,iEdge)==Value ? FLAG : Edges_f(FromTo,iEdge) ; // пометили...
//
} // ----- конец tuneFlagsAll --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall clearFlagsDuplicateOps( INT FromTo,INT Op )
{ // устанавливает в false все флаги операторов со значение Op (кроме первого встретившегос€)
// обрабатываетс€ список "From" или "To" при From/To = 0/1 соответственно
//
 register INT iEdge; // попросим компил€тор..!
 register bool flagEq, flagOp = false; // если Op встретилост в списке - true !
//
 for( iEdge=1; iEdge<=nEdges; iEdge++ ) // по всем дугам начина€ с #1
///  for( jFromTo=0; jFromTo<=1; jFromTo++ ) // по операторам "From"/"To" ( 0/1 соответственно )
  {
   flagEq = Edges(FromTo,iEdge)==Op ? true : false ; // чтобы не сравнивать дважды...
//
   if( flagEq && flagOp )
    Edges_f(FromTo,iEdge) = false ; // после первого вхождени€ Op все остальные - false
// ----- последовательность if не мен€ть ! -------------------------------------
   if( flagEq ) // встретили Op...
    flagOp = true;
  }
//
} // ----- конец clearFlagsDuplicateOps ----------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOpsInput()
{ // возвращает только ¬’ќƒЌџ≈ вершины (0-й €рус) в »√ј ------------------------
//
 if( !flagExistsEdges ) // нет массива Mem_Edges[][]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ищем число nOpsInput ¬’ќƒЌџ’ операторов (имеем nEdges дуг графа)=========
////////////////////////////////////////////////////////////////////////////////
 register INT iEdge, jEdge, nW ;
 bool flag;
 nOpsInput = 0; // число входных операторов (0-й €рус; глобальное)
//
 tuneFlagsAll( false, 0 ); // устанавливает в false флаги "From" операторов массива дуг Edges[][]
 tuneFlagsAll( false, 1 ); // устанавливает в false флаги "To" операторов массива дуг Edges[][]
//
// === по всем дугам »√ј =======================================================
 for(iEdge=1; iEdge<=nEdges; iEdge++) // по все дугам начина€ с #1
  if( !Edges_f(0,iEdge) ) // запомнили »—’ќƒяў”ё вершину дуги iEdge
  {
   nW = Edges(0,iEdge);
//
   tuneFlagsIfEqual( true, 0, nW ) ; // пометили "From"
   tuneFlagsIfEqual( true, 1, nW ) ; // пометили "To"
//
  flag = false;
  for(jEdge=1; jEdge<=nEdges; jEdge++)
   if( Edges_f(1,jEdge) && Edges(1,jEdge)==nW ) // помечено и =nW
    flag = true ; // итак, nW встречаетс€ в Edges(1,*) ..!
//
  if( !flag ) // если nW Ќ≈ ¬—“–≈„ј≈“—я в Edges(1,*) - подходит!
   nOpsInput ++ ;
//
  } // if(!Edges_f(0,iEdges)) и for(iEdges=1; iEdges<=nEdges; iEdges++)
//
 return nOpsInput ;
//
} // --- конец c_GetCountOpsInput-----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOpsOutput()
{ // возвращает число вершин в »√ј (только выходные данные)
//
 if( !flagExistsEdges ) // нет массива Mem_Edges[][]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ищем число nOpsInput ¬’ќƒЌџ’ операторов (имеем nEdges дуг графа)=========
////////////////////////////////////////////////////////////////////////////////
 register INT iEdge, jEdge, nW ;
 bool flag;
 nOpsOutput = 0; // число ¬џ’ќƒЌџ’ операторов (глобальное)
//
 tuneFlagsAll( false, 0 ); // устанавливает в false флаги "From" операторов массива дуг Edges[][]
 tuneFlagsAll( false, 1 ); // устанавливает в false флаги "To" операторов массива дуг Edges[][]
//
// === по всем дугам »√ј =======================================================
 for(iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам начина€ с #1
  if( !Edges_f(1,iEdge) ) // запомнили »—’ќƒяў”ё вершину дуги iEdge
  {
   nW = Edges(1,iEdge);
//
   tuneFlagsIfEqual( true, 0, nW ) ; // пометили "From"
   tuneFlagsIfEqual( true, 1, nW ) ; // пометили "To"
//
   flag = false;
   for(jEdge=1; jEdge<=nEdges; jEdge++)
    if( Edges_f(0,jEdge) && Edges(0,jEdge)==nW ) // помечено и =nW
     flag = true ; // итак, nW встречаетс€ в Edges(0,*) ..!
//
   if( !flag ) // если nW Ќ≈ ¬—“–≈„ј≈“—я в Edges(0,*) - подходит!
    nOpsOutput ++ ;
//
  } // конец if(!Edges_f(1,iEdge)) и for(iEdge=1; iEdge<=nEdges; iEdge++)
//
 return nOpsOutput ;
//
} // --- конец c_GetCountOpsOutput----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbOpInput(INT Numb)
{ // возвращает номер Numb оператора (только из ¬’ќƒЌџ’ операторов)
//
 if( !flagExistsEdges ) // нет массива Mem_Edges[][]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ищем Numb-тый оператор (имеем nEdges дуг графа)==========================
////////////////////////////////////////////////////////////////////////////////
 register INT iEdge, jEdge, nW ;
          INT iOps = 0 ; // счЄтчик числа вершин графа (операторов)
 bool flag;
//
 tuneFlagsAll( false, 0 ); // устанавливает в false флаги "From" операторов массива дуг Edges[][]
 tuneFlagsAll( false, 1 ); // устанавливает в false флаги "To" операторов массива дуг Edges[][]
//
// === по всем дугам »√ј =======================================================
//
 for(iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам начина€ с #1
  if( !Edges_f(0,iEdge) ) // запомнили »—’ќƒяў”ё вершину дуги iEdge
  {
   nW = Edges(0,iEdge);
//
   tuneFlagsIfEqual( true, 0, nW ) ; // пометили "From"
   tuneFlagsIfEqual( true, 1, nW ) ; // пометили "To"
//
   flag = false;
   for(jEdge=1; jEdge<=nEdges; jEdge++)
    if( Edges_f(1,jEdge) && Edges(1,jEdge)==nW ) // помечено и равно nW
     flag = true ; // итак, nW встречаетс€ в Edges(1,*) ..!
//
   if( !flag ) // если nW Ќ≈ ¬—“–≈„ј≈“—я в Edges(1,*) - подходит!
    iOps ++ ;
//
   if( iOps == Numb ) // нашли вхожд≈ние номер Numb
    return nW ;
//
  } // конец if(!Edges_f(0,iEdge)) и for(iEdge=1; iEdge<=nEdges; iEdge++)
//
} // ------ конец c_GetNumbOpInput ---------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbOpOutput(INT Numb)
{ // возвращает номер Numb вершины (только из ¬џ’ќƒЌџ’ операторов)
//
 if( !flagExistsEdges ) // нет массива Mem_Edges[][]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ищем число операторов (имеем nEdges дуг графа)===========================
////////////////////////////////////////////////////////////////////////////////
 register INT iEdge, jEdge, nW ;
          INT iOps = 0 ; // счЄтчик числа вершин
 bool flag;
//
 tuneFlagsAll( false, 0 ); // устанавливает в false флаги "From" операторов массива дуг Edges[][]
 tuneFlagsAll( false, 1 ); // устанавливает в false флаги "To" операторов массива дуг Edges[][]
//
// === по всем дугам »√ј =======================================================
//
 for(iEdge=1; iEdge<=nEdges; iEdge++) // по всем дугам начина€ с #1
  if( !Edges_f(1,iEdge) ) // запомнили »—’ќƒяў”ё вершину дуги iEdge
  {
   nW = Edges(1,iEdge);
//
   tuneFlagsIfEqual( true, 0, nW ) ; // пометили "From"
   tuneFlagsIfEqual( true, 1, nW ) ; // пометили "To"
//
   flag = false;
   for(jEdge=1; jEdge<=nEdges; jEdge++)
    if( Edges_f(0,jEdge) && Edges(0,jEdge)==nW ) // помечено и равно nW
     flag = true ; // итак, nW встречаетс€ в Edges(0,*) ..!
//
   if( !flag ) // если nW Ќ≈ ¬—“–≈„ј≈“—я в Edges(0,*) - подходит!
    iOps ++ ;
//
   if( iOps == Numb ) // нашли вхожд≈ние номер Numb
    return nW ;
//
  } // конец if(!Edges_f(1,iEdge)) и for(iEdge=1; iEdges<=nEdges; iEdge++)
//
} // ------ конец c_GetNumbOpOutput --------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOps()
{ // возвращает число операторов (уникальных номеров вершин »√ј без учЄта входных данных)
//
 if( flagExistsOps ) // количество операторов nOps подсчитано..!
  return nOps ;
//
 if( !flagExistsEdges ) // не существует массива Mem_Edges[][]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ищем общее число операторов nOps (без входного €руса) ===================
////////////////////////////////////////////////////////////////////////////////
//
 register INT iEdge;
 nOps = 0; // число вершин без входных (глобал)
//
 tuneFlagsAll( true, 0 ); // устанавливает в true флаги "From" операторов массива дуг Edges[][]
 tuneFlagsAll( true, 1 ); // устанавливает в true флаги "To" операторов массива дуг Edges[][]
//
 for( iEdge=1; iEdge<=nEdges; iEdge++ ) // по всем дугам начина€ с #1
  clearFlagsDuplicateOps(1,Edges(1,iEdge) ) ; // ставим false у дубликатов
//
 for( iEdge=1; iEdge<=nEdges; iEdge++ ) // по всем дугам начина€ с #1
  if( Edges_f(1,iEdge) ) // если true (у дубликатов - false )
    nOps ++ ;
//
 flagExistsOps = true; // число операторов (вершин) подсчитато
//
 return nOps ;
//
} // --- конец c_GetCountOps ---------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetOpByMaxTierLowerPreset(INT Op)
{ // выдаЄт оператор, информационно зависимый от заданного Op и наход€щийс€ на €русе
// с максимальным номером (если таких оператор несколько - выдаЄтс€ последний по списку)
 register INT i;
 INT to_Op, Op_maxTier, to_Tier, maxTier = -134567,
     nOut = c_GetCountOutEdgesByOp(Op); // число выходных дуг оператора Op
//
 if( !flagExistsTiers ) // массива Tiers[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( !nOut ) // это ¬џ’ќƒЌќ… оператор...
  return ERR_COMMON ; // сигнал, что это ¬џ’ќƒЌќ… оператор
//
 for(i=1; i<=nOut; i++) // по всем ¬џ’ќƒяў»ћ дугам
 {
  to_Op   = c_GetNumbOutEdgeByOp( i, Op ); // i-тый комплементарный по дуге оператор относительно Op
  to_Tier = c_GetTierByOp( to_Op ); // этот оператор находитс€ на €русе to_Tier
//
  if( to_Tier >= maxTier ) // ищем максимум
  {
   maxTier = to_Tier;
   Op_maxTier = to_Op; // запоминаем to_Op...
  }
//
 } // конец цикла по ¬џ’ќƒяў»ћ дугам
//
 return Op_maxTier;
//
} // --- конец  c_GetOpByMaxTierLowerPreset ------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_DrawDiagrTLD()
{ // строит графическое изображение (диаграмму) времЄн жизни внутренних данных (TLD)
 INT OpsOnTier,
     H_pix, B_pix, // высота и ширина области отрисовки IM1 в пикселах
     B_rect, // ширина горизонтальной полоски в пикселах
     x1,y1, x2,y2; // координаты горизонтальной полоски в пикселах
 char str[_256]="\0";
//
 if( !flagExistsTiers ) // массива Tiers[][] ещЄ нет...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
////////////////////////////////////////////////////////////////////////////////
 TIM1->Picture->Bitmap->Height = TIM1->Height; // настроить размеры —anvas по размерам Image
 TIM1->Picture->Bitmap->Width  = TIM1->Width;  // !!! ќ„≈Ќ№ ¬ј∆Ќќ ( инфо 08.02.2017 ) !!!!!!
//
 H_pix = TIM1->Height; // высота и ширина области отрисовки IM1 в пикселах
 B_pix = TIM1->Width;
//
// --- настройка параметров кисти и карандаша (пера) ---------------------------
 TIM1->Canvas->CopyMode     = cmSrcCopy; // запись пикселов поверх существующих
//
 TIM1->Canvas->Brush->Style = bsSolid; // сплошна€ кисть
//
 TIM1->Canvas->Pen->Style   = psSolid; // сплошной
 TIM1->Canvas->Pen->Mode    = pmCopy;  // режим цвет = color
 TIM1->Canvas->Pen->Width   = 1; // толщина = 1
//
 TIM1->Transparent = false; // !!! об€зательно !!! „тобы не было видно, что ѕќƒ IM1
//
// дл€ экономии кода каркас вз€т и зc_DrawDiagrTLD(), а функциональна€ ---------
// часть аналогична (с частичной избыточностью) блоку в c_PutParamsTiers() -----
//
 INT n1,n2,CountTLD, // n1,n2 - номера промежутков между €русами яѕ‘, CountTLD - число данных в этом промежутке
     maxCountTLD = _minINT, minCountTLD = _maxINT, // max/min данных
     n1x,n2x, n1n,n2n, // диапазоны €русов выше и ниже рассмматриваемого промежутка
     iGap, nGaps ;
 REAL averTLD=0.0; // средне-арифметическое времени жижниданных между €русами яѕ‘
//
 if( !flagCalcTLD ) // если paramsTLD не вычислен...
 {
  c_CalcParamsTLD(); // вычислить диаграмму времени жизни данных по текущему Tiers[][]
  flagCalcTLD = true ; // установить flag "paramsTLD соответствует текущему Tiers[][]"
 }
//
 sscanf( paramsTLD->Strings[0].c_str(), "%d", &nGaps ); // число меж€русных промежутков в яѕ‘
//
// ищем экстремумы числа данных ------------------------------------------------
 for( iGap=1; iGap<=nGaps; iGap++ ) // цикл по всем промежуткам (Gap) €русов яѕ‘ дл€ поисков max/min
 {
  if( iGap < nGaps ) // кроме последней строки с $
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/%d|%d:", &n1,&n2,&CountTLD ); // верхний €рус / нижний €рус / число данных в этом промежутке
  else // последн€€ строка формата "n/$|m"
  {
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/" SS_02 "|%d:",  &n1,&CountTLD ); // верхний €рус / $ / число данных в этом промежутке
   n2=n1+1;
  }
//
  if( CountTLD >= maxCountTLD ) // ищем мах число живых данных
  { maxCountTLD = max(maxCountTLD,CountTLD); n1x=n1; n2x=n2; } // запомнили €рус выше | запомнили €рус ниже (избыточно вообще-то...)
//
  if( CountTLD < minCountTLD ) // ищем мin число живых данных
  { minCountTLD = min(minCountTLD,CountTLD); n1n=n1; n2n=n2; } // запомнили €рус выше | запомнили €рус ниже (избыточно вообще-то...)
//
 averTLD += (REAL)CountTLD; // суммируем дл€ получени€ средн.арифметического времени жизни данных между €русам
//
 } // конец  for( iGap=1; iGap<=n; iGap++ )
//
 averTLD /= (REAL)nGaps; // средн.арифметическое времени жизни данных между €русам
//
 REAL dH_pix = 1.0 * H_pix / nGaps, // вес единицы в  пикселах по высоте и ширине области отрисовки диаграммы
      dB_pix = 1.0 * B_pix / maxCountTLD;
//
 dH_pix = max( dH_pix, 1.0 ); // высота должна быть  <= 1 , иначе отрисовка невозможна...
//
 snprintf(str,sizeof(str), "H|N/W=%d|/%d/%d-%d", nGaps,maxCountTLD,n1x,n2x ); // число лент / мах данных / €рус сверху - €рус снизу
 F2->L_OM->Caption = str;
 F2->L_OM->Repaint(); // принудительно перерисовываем
//
 for( iGap=1; iGap<=nGaps; iGap++ ) // цикл по всем промежуткам (Gap) €русов яѕ‘ дл€ построени€ графика
 {
//
  if( iGap < nGaps ) // кроме последней строки с $
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/%d|%d:", &n1,&n2,&CountTLD ); // верхний €рус / нижний €рус / число данных в этом промежутке
  else // последн€€ строка формата "n/$|m"
  {
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/" SS_02 "|%d:",  &n1,&CountTLD ); // верхний €рус / $ / число данных в этом промежутке
   n2=n1+1;
  }
//
  B_rect = dB_pix * CountTLD; // ширина горизонтальной полоски
//
// --- устанавливаем цвета графика ---------------------------------------------
  if( CountTLD == minCountTLD )
   TIM1->Canvas->Brush->Color = brush_draw_color_MIN; // цвет кисти ћ»Ќ»ћ”ћ
  else
  if( CountTLD == maxCountTLD )
   TIM1->Canvas->Brush->Color = brush_draw_color_MAX; // цвет кисти ћј —»ћ”ћ
  else
   TIM1->Canvas->Brush->Color = brush_draw_color_TLD; // цвет кисти обычный дл€ TLD
////////////////////////////////////////////////////////////////////////////////
  x1 = 0;  // лева€ верхн€€ точка горизонтальной полоски ( Rectangle, Rect )
  y1 = dH_pix * ( iGap - 1 );
//
  x2 = x1 + B_rect; // права€ нижн€€ точка горизонтальной полоски ( Rectangle, Rect )
  y2 = y1 + dH_pix;
//
// --- рисуем пр€моугольники длиной, пропорциональной числу операторов на €русе
  TIM1->Canvas->FillRect( TRect( x1,y1, x2,y2 ) ); // пр€моугольник заданной кистью
//
//  Delay( 1 ); // задержка 1 msec - без неЄ отрисовка иногда не получаетс€..!
//
  Application->ProcessMessages(); // дать поработать Windows
//
 } // конец цикла  for( iGap=1; iGap<=n; iGap++ )
//
////////////////////////////////////////////////////////////////////////////////
// ----- рисуем вертикальную линию - средн.арифметическое значение -------------
//
  TIM1->Canvas->Pen->Color = pen_draw_b_average; // цвет линии среднего числа операторов по €русам; // цвет пера
  TIM1->Canvas->Pen->Mode  = pmCopy; // цвет при взимодействии с фоном
  TIM1->Canvas->Pen->Style = psDot; // точечна€ лини€
  TIM1->Canvas->Pen->Width = 1; // толщина пера 3 пиксел€
//
  x1 = x2 = averTLD * dB_pix ;
  y1 = 0; y2 = TIM1->Height;
//
  TIM1->Canvas->MoveTo( x1,   y1 ); // перевести перо в x1,y1
  TIM1->Canvas->LineTo( x1,   y2 ); // провести линию в x1,y2
//
  TIM1->Canvas->MoveTo( x1-1, y1 ); // перевести перо в x1-1,y1
  TIM1->Canvas->LineTo( x1-1, y2 ); // провести линию в x1-1,y2
//
  TIM1->Canvas->MoveTo( x1+1, y1 ); // перевести перо в x1+1,y1
  TIM1->Canvas->LineTo( x1+1, y2 ); // провести линию в x1+1,y2
//
//  TIM1->Repaint(); // принудительно перерисовали
//
  return true; // всЄ успешно сделано
//
} // --- конец с_DrawDiagrTLD --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall  c_CalcParamsTLD()
{ // по массиву Tiers[][] строит и выводит в TLD информацию о времени жижни данных
// числа сообщений между €русами (полезно дл€ определени€ числа необходимых
// дл€ хранени€/передачи данных между оператораи на €русах яѕ‘
// полагаем, что файл регистров ќЅў»… дл€ всех параллельных вычислителей
//
 char sN[_8192]="\0", sS[_8192]="\0", sW[_128]="\0";
 INT k,l, from_Op,to_Op, to_Tier, max_to_Tier;
 register INT i,j;
//
 if( !flagExistsTiers ) // массива Tiers[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  t_printf( "\n-W- ƒл€ построени€ диаграммы времени жизни данных создайте сначала яѕ‘..! -W-\n");
  MessageBeep( MB_ICONQUESTION ); // звуковое предупреждение...
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 paramsTLD->Clear(); // очистим дл€ нового заполнени€ рассчЄтными данными
//
 paramsTLD->Add( IntToStr(nTiers+1) ); // всего строк в TLD
//
// ---- начинаем цикл по ѕ–ќћ≈∆”“ јћ между €русами (Gap) яѕ‘ -------------------
// ---- iBottomOfGap - Ќ»∆Ќяя граница промежутка определ€етс€ номером Ќ»∆Ќ≈√ќ €руса яѕ‘
 for( INT iBottomOfGap=1; iBottomOfGap<=nTiers+1; iBottomOfGap++ ) // по iBottomOfGap - нижней границе интервала в яѕ‘
 {
//
  OutRepeatComplete(" * "__FUNC__"(): ", iBottomOfGap, (nTiers+1), 50, (1.0e2*iBottomOfGap)/(nTiers+1), "%.0f", "% выполнено"); // индикаци€ готовности выполнени€ части цикла
//
  strNcpy( sN, "" ); // очистили строку параметров диапазона €русов с "дном" в виде €руса iBottomOfGap
  l = 0; // число параметров данной строки
//
  for( i=0; i<iBottomOfGap; i++ ) // по €русам яѕ‘, не бќльшим (включа€) iBottomOfGap
  {
//
   for( j=1; j<=c_GetCountOpsOnTier(i); j++ ) // по операторам по €русе j
   {
//
    APM // дать поработать Windows ---------------------------------------------
//
    from_Op = c_GetOpByNumbOnTier( j,i ); // получили номер вершины, из которой ¬џ’ќƒя“ дуги
    to_Op   = c_GetOpByMaxTierLowerPreset( from_Op ); // если выходных дуг нет вообще - возвращаетс€ ERR_COMMON
//
    max_to_Tier = ( to_Op == ERR_COMMON ) ? nTiers + 1 : c_GetTierByOp( to_Op ); // соответствующий to_Op €рус суть выходной / не выходной
//
    if( max_to_Tier >= iBottomOfGap ) // €рус конца дуги более или равен €русу Ќ»«ј интервала
    {
     if( !c_GetCountInEdgesByOp( from_Op ) ) // это вершина (оператор) ¬’ќƒЌџ’ данных
//      snprintf( sW,sizeof(sW), " %1s%d|%d->%d", _IN, from_Op, i, max_to_Tier ) ; // _IN = "\xAB" = "<<"
      snprintf( sW,sizeof(sW), " " _IN "%d|%d->%d", from_Op, i, max_to_Tier ) ; // _IN = "\xAB" = "<<"
     else
     if( !c_GetCountOutEdgesByOp( from_Op ) ) // это вершина (оператор) ¬џ’ќƒЌџ’ данных
       snprintf( sW,sizeof(sW), " %d" _OUT "|%d->"  SS_02 "", from_Op, i ) ; // _OUT = "\xBB" = ">>"
     else
      snprintf( sW,sizeof(sW), " %d|%d->%d", from_Op, i, max_to_Tier );
//
     strcat( sN, sW ); // добавл€ем в sN дл€ формировани€ строки вывода
//
     l ++ ;
    } // конец if( max_to_Tier >= iBottomOfGap )
//
   } // конец по j (номерам операторов на €русе i)
//
  } // конец цикла по i (по всем €русам яѕ‘)
//
 iBottomOfGap == nTiers+1 ? // SS_02 = "$"
  paramsTLD->Add( Format("%d/" SS_02 "|%d: %s", OPENARRAY(TVarRec, ((int(iBottomOfGap-1)),(int(l)),sN))) ) : // выводим строку параметров »Ќ“≈–¬јЋј c нижним €русом iBottomOfGap
  paramsTLD->Add( Format("%d/%d|%d: %s", OPENARRAY(TVarRec, ((int(iBottomOfGap-1)),(int(iBottomOfGap)),(int(l)),sN))) );
//
 } // конец цикла по iBottomOfGap (iBottomOfGap - нижн€€ граница »Ќ“≈–¬јЋј в яѕ‘)
//
} // ---- конец  c_CalcParamsTLD -----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutParamsTiers()
{ // --- вывод основных параметров »√ј и его яѕ‘ -------------------------------
 char szOut[_4096]="\0"; // строка дл€ выдачи интегрированных данных
 REAL AverWidth, // средн€€ ширина по €русам кроме первого и последнего
      SumSqWidth = 0.0, // сумма квадратов нев€зок ширины по €русам
      AverSqDevWidth = 0.0; // ср.кв.отклонение ширины €русов яѕ‘ (кроме €русов 1 и nTiers)
 INT  iOp, nOp,     iTier,     nTierMin,    nTierMax,
      Op,  dTiers,  sdOps = 0, sdTiers = 0;
//
 if( !flagExistsTiers ) // массива Tiers[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
// =============================================================================
//
 c_CalcParamsTiers() ; // вычисление параметров ширин €русов яѕ‘ и занесение в стр-ру StatTiers (глобал)
//
 AverWidth = StatTiers.averWidth ; // среднеарифметичеса€ ширина яѕ‘ (кроме 0-го уровн€)
//
 AverSqDevWidth = StatTiers.SD ; // сумма квадратов нев€зок
//
////////////////////////////////////////////////////////////////////////////////
//
 char szStatTiers[_256]="\0"; // данные статистики €русов яѕ‘
//
 if( nTiers != 1 )
  snprintf( szStatTiers,sizeof(szStatTiers), "ср.арифм.шир.= %.4g, — ќ= %.4g, CV= %.4g, IC= %.4g, ICL= %.4g",
            StatTiers.averWidth, StatTiers.SD, StatTiers.CV, StatTiers.IC, StatTiers.ICL ) ;
 else
  snprintf( szStatTiers,sizeof(szStatTiers), "ср.арифм.шир.= %,4g, — ќ= x.x, CV= x.x, IC= x.x, ICL= x.x",
            StatTiers.averWidth ) ;
//
// --- вычисл€ем ¬ј–»ј“»¬Ќќ—“№ -------------------------------------------------
 for( iTier=1; iTier<=nTiers; iTier++ ) // по всем €русам яѕ‘
 {
//
  OutRepeatComplete(" * "__FUNC__"(): ", iTier, nTiers, 30, (1.0e2*iTier)/nTiers, "%.0f", "% выполнено"); // индикаци€ готовности выполнени€ части цикла
//
  for( iOp=1; iOp<=c_GetCountOpsOnTier(iTier); iOp++ ) // по номерам операторов на €русе iTier
  {
   Op = c_GetOpByNumbOnTier( iOp, iTier ); // номер оператора по его номеру iOp на €русе iTier
   dTiers = c_GetMaxTierMaybeOp( Op ) - c_GetMinTierMaybeOp( Op ); // диапазон возможного перемещени€ Op по €русам

   if( dTiers ) // если не нуль...
   {
    sdOps += 1; // суммируем число ќѕ≈–ј“ќ–ќ¬, которые могут быть перемещены по €русам яѕ‘
    sdTiers += dTiers; // сумма диапазонов возможных перемещений по €русам дл€ оператора Op
   }
  } // конец цикла по iOp
 } // конец цикла по iTier
//
// === начало обработки информации о времени жизни данных между €русами яѕ‘ ====
//
 INT iGap,nGaps, n1,n2, CountTLD, // n1,n2 - номера промежутков между €русами яѕ‘, CountTLD - число данных в этом промежутке
     maxCountTLD = _minINT, minCountTLD = _maxINT, // max/min данных
     n1x,n2x, n1n,n2n; //  диапазоны €русов выше и ниже рассматриваеиого промежутка
 REAL averTLD=0.0; // средне-арифметическое времени жизни данных между €русами яѕ‘ (ParamsTLD)
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( !PutParamsTLDOnTextFrame ) // обход вычислени€ времени жизни данных
  goto calc_TLD ; // ...да простит мен€ Ёдсгер ¬ибе ƒейкстра! -------------
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( !flagCalcTLD ) // если paramsTLD не вычислен...
 {
  c_CalcParamsTLD(); // вычислить диаграмму времени жизни данных по текущему Tiers[][]
  flagCalcTLD = true ; // установить flag "paramsTLD соответствует текущему Tiers[][]"
 }
//
 sscanf( paramsTLD->Strings[0].c_str(), "%d", &nGaps ); // число промежутков (Gap) €русов в яѕ‘
//
 for( iGap=1; iGap<=nGaps; iGap++ ) // по числу промежутков (Gap) между €русами яѕ‘
 {
  if( iGap < nGaps ) // кроме последней строки с $
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/%d|%d:", &n1,&n2,&CountTLD ); // верхний / нижний €рус / число данных в этом промежутке
  else // последн€€ строка формата "n/$|m"
  {
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/" SS_02 "|%d:", &n1,&CountTLD ); // верхний €рус / $ / число данных в этом промежутке
   n2=n1+1;
  }
//
  if( CountTLD >= maxCountTLD ) // ищем мах число живых данных
  { maxCountTLD = max(maxCountTLD,CountTLD); n1x=n1; n2x=n2; } // запомнили €рус выше | запомнили €рус ниже (избыточно вообще-то...)
//
  if( CountTLD < minCountTLD ) // ищем мin число ParamsTLD
  { minCountTLD = min(minCountTLD,CountTLD); n1n=n1; n2n=n2; } // запомнили €рус выше | запомнили €рус ниже (избыточно вообще-то...)
//
  averTLD += (REAL)CountTLD; // средне-арифметическое времени жизни данных
 } // конец цикла по промежуткам между €русами яѕ‘
//
// дополнение строки информацией о времени жизни данных
//
 char szStatTLD[_512], // строка данных о времени жизни локальных данных (ParamsTLD)
      szTemp[_128] ;
//
 n2n==nGaps ? sprintf( szStatTLD,"" SS_01 "TLD: 0/$: min=%d(%d/" SS_02 "), ", minCountTLD,n1n ) :
              sprintf( szStatTLD,"" SS_01 "TLD: 0/$: min=%d(%d/%d), ",        minCountTLD,n1n, n2n ) ;
//
 n2x==nGaps ? sprintf( szTemp, "max=%d(%d/" SS_02 "), ср.арифм.=%.4g", maxCountTLD,n1x, averTLD / nGaps ) :
              sprintf( szTemp, "max=%d(%d/%d), ср.арифм.=%.4g", maxCountTLD,n1x, n2x,   averTLD / nGaps ) ;
//
 strcat( szStatTLD, szTemp ); // подготовили строку дл€ вывода на F2
//
// === конец обработки информации о времени жижни данных между €русами яѕ‘ =====
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
calc_TLD : // --- проще, чем разбиратьс€ в куче фигурных скобок ----------------
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// --- вывод рассчитанных данных на форму F2 в L_GP ----------------------------
//
 char szFormat[] = // строка формата дл€ вывода данных в строку szOut ----------
"ќператоров= %d, дуг= %d, яѕ‘: высота= %d, ширина= %d (%d)\
%s%s\
%sоператоров на €русе/€рус (min:max)= %d/%d:%d/%d\
%sвариативность яѕ‘: Vn|Vt|Vnt= %.4g|%s|%s\
%sср.арифм.длин дуг= %.4g €русов\
%sср.арифм.совм.исп.опер.= %.4g\
%s\0";
//
 snprintf( szOut,sizeof(szOut), szFormat, // вывод по формату szFormat в строку szOut
//
 nOps, nEdges, nTiers, Tiers(c_GetTierFirstMaxOps(1,nTiers),0), c_GetTierFirstMaxOps(1,nTiers),
 SS_01,
//
 szStatTiers, // данные статистики €русов яѕ‘
 SS_01,
//
 Tiers(c_GetTierFirstMinOps(1,nTiers),0), c_GetTierFirstMinOps(1,nTiers),
 Tiers(c_GetTierFirstMaxOps(1,nTiers),0), c_GetTierFirstMaxOps(1,nTiers),
 SS_01,
//
 (REAL)sdOps / nOps, // Vn (%.4g)
// (REAL)sdTiers / nTiers // Vt
 nTiers==1 ? "???" : Format("%.4g",OPENARRAY(TVarRec,( (REAL)sdTiers/(nTiers-1) ))).c_str(), // Vt (%.4g) не делить на 0 при nTiers=1
// (REAL)sdOps*sdTiers / (nOps*nOps), // Vnt
// (REAL)sdOps*sdTiers / ( nOps*nOps*(nTiers-1) ), // Vnt (%.4g)
 nTiers==1 ? "???" : Format("%.4g",OPENARRAY(TVarRec,( (REAL)sdOps*sdTiers/(nOps*(nTiers-1)) ))).c_str(), // Vnt (%.4g) не делить на 0 при nTiers=1
 SS_01,
//
 StatTiers.AAL, // среднеарифметическа€ длина дуги
 SS_01,
 StatTiers.averCOP, // среднеарифметическое совсестного параллелизма операторов (Cooperative Operators Parallelismf)
//
 PutParamsTLDOnTextFrame ? szStatTLD : "" ); // данные статистики времени жизни локальных данных (ParamsTLD) ... ќѕ÷»ќЌјЋ№Ќќ !!!
//
 F2->L_GP->Caption = szOut; // вывод основных параметров яѕ‘ графа
 F2->L_GP->Repaint(); // принудительно перерисовываем поле L_GP
//
 strcpy( szStatTLD, "\n" );
 strcat( szStatTLD, szTemp ); // подготовили строку дл€ вывода в файл протокола
//
 if( !PutParamsTLDOnTextFrame ) // обход вычислени€ времени жизни данных
  strcpy( szStatTLD, "\0" );
//
// ===== вывод рассчитанных данных в протокол расчЄта (файл) ===================
//
////////////////////////////////////////////////////////////////////////////////
 ReplaceEqualLengthSubstring( szOut, SS_01, "  \n" ) ; // замен€ем SS_01 на "^^\n"
////////////////////////////////////////////////////////////////////////////////
//
 if( PutParamsTiersOnTextFrame ) // если трудно обдумать быстро бегущие данные (задаЄтс€ в INI-файле)
  t_printf( szOut ); // вывод в текстовое окно того же самого, что в нижней части текстового окна вывода
//
 p_printf( "\n" ); // перед и после - пуста€ строка !!!
 p_printf( szOut ); // допќлнили файл протокола
 p_printf( "\n\n" );
//
 snprintf(szOut,sizeof(szOut), "H|N/W=%d|%d/%d", nTiers,c_GetTierFirstMaxOps(1,nTiers),
                                Tiers(c_GetTierFirstMaxOps(1,nTiers),0) );
 F2->L_OM->Caption = szOut; // вывод максимума операторов на €русе по всему яѕ‘
 F2->L_OM->Repaint(); // принудительно перерисовываем
//
 return true ;
//
} // ----- конец c_PutParamsTiers ----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall CreateUniqueFileName(char* FileName)
{ // создание уникального имени файла при существовании файла с именем, задданным FileName
//
 if( !FileExists( FileName ) ) // файл не cуществует...
  return FileName ;
//
 char OldFileName[_512], NewFileName[_512]="\0", Comma[]=".\0";
//
 Delay( 100 ); // ждЄм 0,1 дл€ гарантированного дистижени€ уникальности нового имени файла
//
 strcpy( OldFileName, FileName ); // исходное им€ файла сохран€ем в OldFileName
 OldFileName[ strrchr(OldFileName,Comma[0]) -
                     &OldFileName[0] ] = '\0'; // вмеcто точки ставим '\0' (отрезаем расширение имени файла)
//
 strcpy( NewFileName, OldFileName ); // им€ файла
 strcat( NewFileName, Comma ); // добавили "." в качестве разделител€ к уникальной строке
 strcat( NewFileName, PutDateTimeToString(1) ); // уникальна€ строка
 strcat( NewFileName, ExtractFileExt(FileName).c_str() ); // расширение исходного файла
//
 t_printf( "\n-W- «аписываемый файл %s уже существует, переименован на %s -W-\n",
           FileName, NewFileName ); // вывод сообщени€ в текстовое окно
//
 return NewFileName ;
//
} // ------ конец CreateUniqueFileName -----------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall OutRepeatComplete(char* s_Before, INT i, INT n, INT di,
                                  REAL Value, char* Fmt, char* s_After)
{ // выдаЄт процент выполненного цикла как плавающее Value по формату Fmt
// с шагом di дл€ текушего i из общего n при условии (i % n/di) # 0
// выдача окружаетс€ строками s_Before и s_After
//
 if( !(n/di) || // делить на 0 нельз€ !!!
       i%(n/di) ) // если есть остаток от делени€ по модулю - уходим...
  return ;
//
 char _Fmt[_256] = "%s";
 strcat( _Fmt,Fmt ); // добавили Fmt
 strcat( _Fmt,"%s" ); // добавили %s
 SB0->Text = Format( _Fmt, OPENARRAY( TVarRec,(s_Before,Value,s_After) ) ).c_str();
 F1->SB->Repaint(); // перерис”ем...
//
} // ----- конец OutRepeatComplete ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CalcParamsTiers() // расчЄт статистических параметров €русов яѕ‘
{
//
 if( !flagExistsTiers ) // массива Tiers[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 REAL averWidth =  (REAL)nOps / nTiers, // средн€€ ширина по всем €русам яѕ‘ кроме ¬’ќƒЌќ√ќ (нулевого)
      sumSqWidth = 0.0 , // суммирование квадратов нев€зок
      sumOps = 0.0 , // сумма операторов по €русам  яѕ‘
      sumICL = 0.0 , // сумма дл€ коэффициента неравномерности по кривой Ћоренца
      xAxis,yAxis, xAxis_old = 0.0,yAxis_old = 0.0,
      averCOP = 0.0 ; // среднеарифметическое совсестного параллелизма операторов (Cooperative Operators Parallelism)
 INT iTier, iOp ,
     nOpsOnTier, // число операторов на €русе
     minOpsByTiers = _maxINT, maxOpsByTiers = _minINT , // дл€ поиска min/max операторов по €русам яѕ‘
//
     sumDump = 0, sumEdges = 0 , // дл€ вычислени€ —–≈ƒЌ≈… ƒЋ»Ќџ ƒ”√»;;
     OpFrom, OpTo, nOutEdges, iOutEdge; // ... то же ...
//
// =============================================================================
 for( iTier=1; iTier<=nTiers; iTier++ ) // по всем €русам яѕ‘
 {
//
  OutRepeatComplete(" * "__FUNC__"(): ", iTier, nTiers, 30, (1.0e2*iTier)/nTiers, "%.0f", "% выполнено"); // индикаци€ готовности выполнени€ части цикла
//
  nOpsOnTier = c_GetCountOpsOnTier(iTier); // число операторов на €русе iTier
//
  minOpsByTiers = min( minOpsByTiers, nOpsOnTier ) ; // ищем min / max
  maxOpsByTiers = max( maxOpsByTiers, nOpsOnTier ) ;
//
  sumSqWidth += ( averWidth - nOpsOnTier ) * ( averWidth - nOpsOnTier ) ; // сумма квадратов нев€зок
// -----------------------------------------------------------------------------
//
  sumOps += nOpsOnTier ; // накопленное число операторов по €русам яѕ‘
  xAxis = (REAL)iTier / nTiers ; // ось абсцисс  (доли единицы)
  yAxis = sumOps / nOps ; // ось ординат  (доли единицы)
//
  sumICL += 0.5 * ( yAxis + yAxis_old ) * ( xAxis - xAxis_old ) ; // площадь трапеции
//
  xAxis_old = xAxis ; yAxis_old = yAxis ; // запомним предыдущие значени€
//
// =============================================================================
//
  for( iOp=1; iOp<=nOpsOnTier; iOp++ ) // по номерам операторов на €русе iTier
  {
//
   OpFrom = c_GetOpByNumbOnTier( iOp, iTier ); // номер оператора по его номеру iOp на €русе iTier
   nOutEdges = c_GetCountOutEdgesByOp( OpFrom ); // число »—’ќƒяў»’ дуг у оператора OpFrom
//
   for( iOutEdge=1; iOutEdge<=nOutEdges; iOutEdge++ ) // цикл по всем »—’ќƒяў»ћ дугам
   {
    OpTo = c_GetNumbOutEdgeByOp( iOutEdge, OpFrom ); // номер оператора, к которому идЄт дуга iOutEdge от оператора OpFrom
    sumDump  += c_GetTierByOp( OpTo) - c_GetTierByOp( OpFrom ); // (#€руса оператора OpFrom) - (#€руса оператора OpTo)
    sumEdges += 1; // сумма числа проанализированных дуг
    // t_printf( "-= %d %d=%d %d-%d", iTier, OpFrom,OpTo, sumDump,sumEdges );
   } // конец цикла for( iOutEdge=1; iOutEdge<=nOutEdges; iOutEdge++ )
//
// =============================================================================
  } // конец for( iOp=1; iOp<=nOpsOnTier; iOp++ )
//
 averCOP += (REAL)c_GetCountOpsOnTier(iTier) * ((REAL)c_GetCountOpsOnTier(iTier)-1.0); // среднеарифметическое совсестного параллелизма операторов (Cooperative Operators Parallelism)
// 
 } // конец for( iTier=1; iTier<=nTiers; iTier++ ) // конец по всем €русам яѕ‘
//
 StatTiers.averWidth  = averWidth ;  // среднеарифметичеса€ ширина яѕ‘ (кроме 0-го уровн€)
 StatTiers.sumSqWidth = sumSqWidth ; // сумма квадратов нев€зок
 StatTiers.SD = nTiers>1 ? sqrt(sumSqWidth/(nTiers-1.0)) : ERR_CALC ; // — ќ (Standard Deviation)
 StatTiers.CV = nTiers>1 ? StatTiers.SD/averWidth : ERR_CALC ; // коэффициент вариации CV (несмещЄнный)
//
// IC = max/min операторов по €русам яѕ‘ ( Irregularity Coefficient, коэффициент неравномерности )
 StatTiers.IC = (REAL)maxOpsByTiers / minOpsByTiers ;
//
// неравномерность распределени€ операторов по €русам яѕ‘ по кривой Ћоренца
 StatTiers.ICL = ( sumICL - 0.5 ) / 0.5 ; // (минус полуплощадь квадрата) по отношению к полуплощади
//
 StatTiers.AAL = (REAL)sumDump / sumEdges ; // среднеарифметическа€ длина дуги (Average Arc Length)
//
 StatTiers.MinOpsByTiers = minOpsByTiers; // мин. операторов по €русам
 StatTiers.MaxOpsByTiers = maxOpsByTiers; // макс. ...
//
 StatTiers.averCOP = averCOP / (REAL)nOps; // среднеарифметическое совсестного параллелизма операторов (Cooperative Operators Parallelism)
//
} // ----- конец c_—alcParamsTiers() -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CountOfMemoryLuaUse() // количество байт, используемых Lua
{
 return lua_gc( L, LUA_GCCOUNT, 0 ) * 1024 + lua_gc( L, LUA_GCCOUNTB, 0 ) ;
} // ----- конец c_CountOfMemoryLuaUse -----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CountOfFreeMemory() // получение и вывод размеров физической пам€ти
{
//
#define WIDTH 10 // ширина пол€ дл€ вывода чисел
#define DIV 1024 // перевод байт в килобайты
//
 MEMORYSTATUSEX stat_ex;
 stat_ex.dwLength = sizeof( stat_ex );
//
 GlobalMemoryStatusEx( &stat_ex );
//
 t_printf("\n»спользуетс€ %*ld %% пам€ти.",              WIDTH, stat_ex.dwMemoryLoad);
 t_printf("¬сего        %*I64d kB физической пам€ти",    WIDTH, stat_ex.ullTotalPhys / DIV);
 t_printf("—вободно     %*I64d kB физической пам€ти",    WIDTH, stat_ex.ullAvailPhys / DIV);
 t_printf("¬сего        %*I64d kB в файле подкачки",     WIDTH, stat_ex.ullTotalPageFile / DIV);
 t_printf("—вободно     %*I64d kB в файле подкачки",     WIDTH, stat_ex.ullAvailPageFile / DIV);
 t_printf("¬сего        %*I64d kB виртуальной пам€ти",   WIDTH, stat_ex.ullTotalVirtual / DIV);
 t_printf("—вободно     %*I64d kB виртуальной пам€ти",   WIDTH, stat_ex.ullAvailVirtual / DIV);
 t_printf("—вободно     %*I64d kB расширенной пам€ти\n", WIDTH, stat_ex.ullAvailExtendedVirtual / DIV);
//
} // ----- конец c_CountOfFreeMemory -------------------------------------------


//
#include "BruteForce_SPF.cpp" // полный перебор всех возможных яѕ‘ (не документировано)
//

