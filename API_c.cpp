//
//#define TEST_PRINT
//
char Test_eq,Test_sl,Test_sll,Test_cl,Test_sp,Test_vr; // "=//: |"
char Test_symb[]="=/: |";
#define Test_n1n2     (sscanf(sN,"%c%d%c%d%c%c",&Test_eq,&n1,&Test_sl,&n2,&Test_cl,&Test_sp)==6 || \
                                  Test_eq==Test_symb[0]  || Test_sl==Test_symb[1] || Test_cl==Test_symb[2] || Test_sp==Test_symb[3])
//
#define Test_n1n2m1m2 (sscanf(sN,"%c%d%c%d%c%d%c%d%c%c",&Test_eq,&n1,&Test_sl,&n2,&Test_vr,&m1,&Test_sll,&m2,&Test_cl,&Test_sp)==10 || \
                                  Test_eq==Test_symb[0]  || Test_sl==Test_symb[1] || Test_cl==Test_symb[2] || Test_sp==Test_symb[3] || \
                                  Test_sll==Test_symb[1] || Test_vr==Test_symb[4])
//
//#define strcat(dest,src) strncat(dest,src,sizeof(dest)-strlen(dest)-5) // безопасное добавление src к dest
//
#define strEndZero(s) s[strlen(s)]='\0' // добавление '\0' в конец строки str
//
#define strNcpy(d,s)  strncpy(d,s,sizeof(d)) // безопасное копирование
//
////////////////////////////////////////////////////////////////////////////////
// файл API_func.cpp ===========================================================
////////////////////////////////////////////////////////////////////////////////
// имена функций API на — начинаютс€ с "c_"; сответствующие функции в Lua освобождены от этого
////////////////////////////////////////////////////////////////////////////////
//#define TEST_PRINT // если определено - тестова€ печать
////////////////////////////////////////////////////////////////////////////////
//
#define APM Application->ProcessMessages(); // дать поработать Windows ---------
//
////////////////////////////////////////////////////////////////////////////////
//
INT  __fastcall c_CreateAndOutputDataLiveDiagrByTiers( int Rule, char FileName[] ); // рассчитывает и выводит параметры ∆»«Ќ» ¬Ќ”“–≈ЌЌ»’ ƒјЌЌџ’ в яѕ‘
INT  __fastcall c_PutTLDToTextFrame(); // выдать диаграмму времени жизни данных в текстовое окно
INT  __fastcall c_SaveTLD( char FileName[] ); // выдать диаграмму времени жизни данных в файл
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
INT  __fastcall c_PutEdgesToTextFrame(); // выдаЄт массив дуг Mem_Edges[] в окно дл€ визуализации
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
bool __fastcall c_SaveEdges(char FileName[]); // вывод в FileName дуг описани€ графа + Tiers[0/nTiers][*]
bool __fastcall c_ReadTiers(char FileName[]); // читает из FileName яѕ‘ графа
bool __fastcall c_SaveTiers(char FileName[]); // вывод в FileName яѕ‘ графа
//
INT  __fastcall c_SaveTiersVizu(char FileName[]); // сохранение файла операторов по €русам
INT  __fastcall c_SaveEdgesVizu(char FileName[]); // сохранение файла зависимостей (дуг) операторов
INT  __fastcall c_SaveInOutOpVizu(char FileName[]); // сохранение файла вход€щих и выход€щих душ дл€ оператора Op
INT  __fastcall c_SaveParamsVizu(char FileName[]); // параметры графа - выдаютс€ GetParamsGraph()
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
bool  __fastcall c_IsCorrectParamCalc(char* str); // TRUE при корректности распознавани€ параметра вычислител€
bool  __fastcall c_IsCorrectParamOpVertEdg(char* str); // TRUE при корректности распознавани€ параметра оператора
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
INT   __fastcall c_PutParamsTiers(); // вывод основных параметров »√ј и яѕ‘
//
bool  __fastcall c_IsOpContainOnTiers(INT Op); // если оператор Op присутствует в Tiers[][], возращаетс€ TRUE, иначе - FALSE
INT   __fastcall c_GetOpByMaxTierLowerPreset(INT Op); // выдаЄт оператор, информационно зависимый от заданного и наход€щийс€ на €русе
// с максимальным номером (если таких оператор несколько - выдаЄтс€ последний по списку)
//
INT  __fastcall c_WinExec( char *cmdLine, INT cmdShow ); // выполнить WinExec
INT  __fastcall c_ShellExecute( char *Operation, char *File, char *Parameters, char *Directory, INT cmdShow ); // выполнить ShellExecute
//
INT  __fastcall c_CreateProsess(char* CommandLine, byte RuleParent, byte Priority, bool RuleMessage); // запуск процесса-потомка
//==============================================================================
bool __fastcall TestAndAddMemoryForEdges( INT nEdges ); // попытка увеличени€ пам€ти дл€ Mem_Edges[]
bool __fastcall ParseStringAndAddEdges( char *str ); // парсит str и добавл€ет дуги в общий массив дуг
//
bool __fastcall ReadAndPrimWorkOpsCalcsVertEdgeFiles( char FileName[] ); // чтение и предв.обработка файлов настроек
//
INT  __fastcall c_LuaCallByTimer( char *CommandLine, INT d_Ticks ); // вызов Lua-команд с задержкой d_Ticks
//
void __fastcall CallLuaThread( char *CommandLine ); // вызов CommandLine во вновь созданном потоке Lua
//
char* __fastcall ReformFileName( char Filename[], char Ext[] ); // нужным образом преобразовать им€ файла
//
INT  __fastcall c_CalcParamsTiers(); // расчЄт статистики €русов яѕ‘
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall cmp_def( char *s )
{ // сравнивает попарно 5 первых символов s и sDef; возвращает TRUE, если они все равны
 return( toupper(s[0])==toupper(sDef[0]) && toupper(s[1])==toupper(sDef[1]) &&
         toupper(s[2])==toupper(sDef[2]) && toupper(s[3])==toupper(sDef[3]) &&
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
INT __fastcall c_SaveTiersVizu(char FileName[])
{ // вывод числа операций по €русам
 char str[_16384], tmp[_256];
 FILE *fptr = NULL; // рабочий указатель на файл
//
 if( !isTiers ) // массива Tiers[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extVizu) ); // преобразованное им€ файла
//
 if(!(fptr = fopen( NewFileName,"w" ))) // открыли дл€ записи
 {
  t_printf( "\n-E- Ќевозможно записать файл %s содержани€ яѕ‘ -E-\n\n-W- проверьте осуществимость записи на заданный носитель данных -W-",
                   NewFileName );
  return FALSE ;
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
    snprintf(tmp,sizeof(tmp), _IN,  Tiers(iTier,j)); // это выходной оператор (результат программы)
   else
   if( !c_GetCountOutEdgesByOp( Tiers(iTier,j) )) // у этого оператора нет ¬џ’ќƒ€ў»’ дуг...
    snprintf(tmp,sizeof(tmp), _OUT, Tiers(iTier,j)); // это выходной оператор (результат программы)
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
 return TRUE ;
//
} // --- конец SaveTiersVizu ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_SaveEdgesVizu(char FileName[])
{ // вывод св€зей между операторами
 FILE *fptr = NULL; // рабочий указатель на файл
//
 if( !isEdges ) // массива Mem_Edges[] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extVizu) ); // преобразованное им€ файла
//
 if(!(fptr = fopen( NewFileName,"w" ))) // открыли дл€ записи
 {
  t_printf( "\n-E- Ќевозможно записать файл %s содержани€ »√ј -E-\n\n-W- проверьте осуществимость записи на заданный носитель данных -W-",
                   NewFileName );
  return FALSE ;
 }
//
// setbuf( fptr, NULL ); // отключили буфферизацию при записи
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по номерам дуг
  fprintf(fptr, "#Edge= %d %d -> %d\n", iEdge, Edges(0,iEdge),Edges(1,iEdge)); // дуга номер i
//
 fclose(fptr); // закрыли файл
//
 return TRUE ;
//
} // --- конец SaveEdgesVizu ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_SaveInOutOpVizu(char FileName[])
{ // вывод числа ¬’ќƒяў»’ и ¬џ’ќƒяў»’ дуг дл€ операторов
 char str[_16384], tmp[_256], s1[]="* \0";
 INT jOpOnTier, iOp, j, nIn,nOut;
 FILE *fptr = NULL; // рабочий указатель на файл
//
 if( !isEdges ) // массива Mem_Edges[] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 if( !isTiers ) // массива Tiers[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extVizu) ); // преобразованное им€ файла
//
 if(!(fptr = fopen( NewFileName,"w" ))) // открыли дл€ записи
 {
  t_printf( "\n-E- Ќевозможно записать файл %s вход€щих и исход€щих дуг по операторам -E-\n\n-W- проверьте осуществимость записи на заданный носитель данных -W-",
                   NewFileName );
  return FALSE ;
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
 return TRUE ;
//
} // --- конец SaveInOutOpVizu -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_SaveParamsVizu(char FileName[])
{ // вывод числа ¬’ќƒяў»’ и ¬џ’ќƒяў»’ дл€ операторов
 FILE *fptr = NULL; // рабочий указатель на файл
//
 if( !isEdges ) // массива Mem_Edges[] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extVizu) ); // преобразованное им€ файла
//
 if(!(fptr = fopen( NewFileName,"w" ))) // открыли дл€ записи
 {
  t_printf( "\n-E- Ќевозможно сохранить файл %s числа вход€щих и выход€щих дуг по операторам -E-\n-W- проверьте осуществимость записи на заданный носитель данных -W-",
                   NewFileName );
  return FALSE ;
 }
//
// setbuf( fptr, NULL ); // отключили буфферизацию при записи
//
 GetParamsGraph(); // вз€ли параметры графа ----------------------------------
//
 fprintf(fptr, "#nOpMinIn=%12d #nEdgesMinIn=%10d\n#nOpMaxIn=%10d #nEdgesMaxIn=%10d\n#nOpMinOut=%9d #nEdgesMinOut=%9d\n#nOpMaxOut=%9d #nEdgesMaxOut=%9d\nAveIn=%14.3f AveOut=%16.3f",
               PG.nOpMinIn,  PG.nEdgesMinIn,
               PG.nOpMaxIn,  PG.nEdgesMaxIn,
               PG.nOpMinOut, PG.nEdgesMinOut,
               PG.nOpMaxOut, PG.nEdgesMaxOut,
               PG.AveIn,     PG.AveOut);
//
 fclose(fptr); // закрыли файл
//
 return TRUE ;
//
} // --- конец SaveParamsVizu -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_SaveTiers(char FileName[])
{  // вывод операторов по €русам дл€ полного описани€ графа в виде яѕ‘
 char str[_16384], tmp[_256];
 FILE *fptr = NULL; // рабочий указатель на файл
//
//
 if( !isTiers ) // массива Tiers[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 char NewFileName[_512];
 strcpy( NewFileName, ReformFileName(FileName,extTiers) ); // преобразованное им€ €файла
//
 if(!(fptr = fopen( NewFileName, "w" ))) // открыли дл€ записи
 {
  t_printf( "\n-E- Ќевозможно записать файл %s полного описани€ »√ј в яѕ‘ -E-\n\n-W- проверьте осуществимость записи на заданный носитель данных -W-",
                   NewFileName );
  return FALSE ;
 }
//
// setbuf( fptr, NULL ); // отключили буфферизацию при записи
//
//  // число €русов (глобальное), max операторов на €русе, на каком именно
 fprintf(fptr, "%d %d %d\n", nTiers+1, c_GetCountOpsOnTier( c_GetTierFirstMaxOps(1,nTiers) ),
                                       c_GetTierFirstMaxOps(1,nTiers) );
//
 for(INT iTiers=0; iTiers<=nTiers; iTiers++) // по €русам яѕ‘ графа
 {
  strNcpy(str, ""); // очистили строку перед заполнением

  for(INT j=0; j<=Tiers(iTiers,0); j++) // по номерам операторов на €русе iTiers
  {
   snprintf(tmp,sizeof(tmp), "%d ", Tiers(iTiers,j)); // по элементам строки уровн€ iTiers
   strcat(str, tmp); // прибавили дл€ формировани€ строки
  } // конец цикла по j
//
  fprintf(fptr, "%s\n", str); // вывели в файл готовую строку
//
 } // конец цикла по iTiers
//
 fclose(fptr); // закрыли файл
//
 return TRUE ;
//
} // --- конец SaveTiers -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ReadTiers(char FileName[])
{  // чтение операторов по €русам дл€ полного описани€ графа в виде яѕ‘
 char str[_16384], *p;
 FILE *fptr = NULL; // рабочий указатель на файл
//
 INT MaxOpsOnTier, // мах число операторов на €русе данной яѕ‘ графа
     TierWithMaxOps, // на каком (сверху) €русе этот мах реализуетс€
     j;
//
 strNcpy( FileName, ChangeFileExt( FileName, extTiers ).c_str() ); // расширение - extTiers
//
 if(!(fptr = fopen(FileName, "r"))) // открыли дл€ чтени€
 {
  t_printf( "\n-E- Ќевозможно прочитать файл %s содержани€ яѕ‘ -E-\n-W- веро€тна некорректность при дальнейшей работе -W-",
                   FileName );
  isTiers = FALSE;
  return FALSE ;
 }
//
 nTiers = 0 ; // глобальное, число €русов яѕ‘
//
 fgets(str, sizeof(str), fptr); // прочитали первую строку файла
// число €русов (глобальное), max операторов на €русе, на каком €русе этот max
 if( sscanf(str, "%d %d %d", &nTiers, &MaxOpsOnTier, &TierWithMaxOps) == 0 ) // 0 = ошибка
 {
  isTiers = FALSE;
  return FALSE ;
 }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( ( nTiers < _maxTiers ) && ( MaxOpsOnTier < _maxOpsOnTier ) ) // пам€ти достаточно
  goto cont; // ... не надо реаллокировать пам€ть
//
 _maxTiers = nTiers * stockMem; // число €русов с запасом в stockMem раз
 _maxOpsOnTier = MaxOpsOnTier * stockMem; // число операторов на €русе с запасом в stockMem раз
 pTiers = (INT*) realloc( pTiers, (_maxTiers+1) * (_maxOpsOnTier+1) * sizeof(INT) ); // реаллокировали пам€ть под Tiers[][]...
//
 if( !pTiers ) // совсем плохо - пам€ть в "куче" закончилась
 {
  snprintf(str,sizeof(str), "Ќехватка пам€ти дл€ размещени€ массива я–”—ќ¬ (4). «атребовано %d x %d = %d элементов...",
                (_maxTiers+1), (_maxOpsOnTier+1), (_maxTiers+1) * (_maxOpsOnTier+1));
  MessageBox(0, str, "ѕредупреждение", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  isTiers = FALSE ; // массив Tiers[][] не создан...
  return FALSE ;
 }
//
  t_printf( "\n-I- ћассив я–”—ќ¬ (4) перераспределЄн на %d x %d = %d элементов -I-",
                   (_maxTiers+1), (_maxOpsOnTier+1), (_maxTiers+1) * (_maxOpsOnTier+1) );
//
cont: // не надо реаллокировать пам€ть...

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

 for(INT iTier=0; iTier<=nTiers; iTier ++) // по €русам яѕ‘ графа
 {
  fgets(str, sizeof(str), fptr); // прочитали очередную строку файла

  j = 0; // номер оператора на €русе iTier

  if( p = strtok( str, " " ) ) // выдел€ем первое число до пробела
  if( sscanf( p, "%d", &Tiers(iTier, ++j) ) != 1 ) // прочитали первый #оператора в Tiers[iTier][1]
   goto cont_1;  // при успехе sscanf возвращаетс€ число успешно прочитанных элементов

  while( p ) // пока p = TRUE
  {
   p = strtok( NULL, " "); // до следующего пробела..
   if( sscanf( p, "%d", &Tiers(iTier, ++j) ) != 1 ) // прочитали #операторов больше первого в Tiers[iTier][*]
    goto cont_1;
  } // конец while

cont_1: // все операторы на €русе iTier запомнены в Tiers[][] ------------------

  Tiers(iTier, 0) = j-1; // общее число операторов на €русе iTier

 } // конец цикла по iTiers

 fclose(fptr); // закрыли файл

 isTiers = TRUE ; // all O'k...

 t_printf( "-I- яѕ‘ графа из файла %s успешно прочитана -I-", FileName );

 return TRUE ;

} // --- конец с_ReadTiers -----------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_IsOpsHaveEdge(INT Op1, INT Op2)
{ // TRUE - если наличествует дуга между операторами Op1 -> Op2
 if( !isEdges ) // массив Mem_Edges[] ещЄ не существует - выходим с FALSE
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // по общему списку дуг между операторами
  if ( (Op1 == Edges(0,iEdge)) && (Op2 == Edges(1,iEdge)) ) // така€ дуга в списке имеетс€...
   return ( TRUE );
//
 return ( FALSE );
// 
} // --- конец c_IsOpsHaveEdge -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierByOp(INT Op)
{ // --- вернуть номер €руса дл€ оператора Op ----------------------------------
 if( !isTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }

 for(INT iTier=0; iTier<=nTiers; iTier++) // по всем €русам
  if( c_IsOpExistOnTier( Op, iTier ) == TRUE ) // оператор Op имеет честь присутствовать на €русе iTier
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

 if( !isEdges && !isTiers ) // нет массивов Mem_Edges[] и Tiers[][]
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

   PG.AveOut += nEdgesOutOp ; // сумма числа дуг Out дл€ оператора Op

   if(nEdgesOutOp < PG.nEdgesMinOut) // ищем MIN выход€щих...
   {
    PG.nEdgesMinOut = nEdgesOutOp;
    PG.nOpMinOut    = Op; // запомнили соответствующий Op
   }

   if(nEdgesOutOp > PG.nEdgesMaxOut) // ищем NAX выход€щих...
   {
    PG.nEdgesMaxOut = nEdgesOutOp;
    PG.nOpMaxOut    = Op; // запомнили соответствующий Op
   }

  } // конец цикла по j

////////////////////////////////////////////////////////////////////////////////

 PG.AveIn  /= nOps - Tiers(1,0); // среднее число дуг, ¬’ќƒяў»’ ( to ) в операторы графа
 PG.AveOut /= nOps - Tiers(nTiers,0); // среднее число дуг, ¬џ’ќƒяў»’ ( from ) из операторов графа

 return TRUE ;

} // --- конец GetParamsGraph --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetOpByMinInOnTiers(INT minTier, INT maxTier)
{ // --- вернуть номер оператора с MIN ¬’ќƒќ¬ на €русах с minTier по maxTier
 INT nEdgesInOp = nEdges,  // больше быть не может
     iOp,iOpMinIn, sumEdgesIn;
//
 if( !isTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
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

 if( !isTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }

 for(INT j=minTier; j<=maxTier; j++) // по всем €русам с minTier по maxTier

 for(INT iOpOnTier=1; iOpOnTier<=Tiers(j,0); iOpOnTier++) // по всем этим операторам €руса Tier
 {
  iOp = Tiers(j,iOpOnTier); // вз€ли номер iOpOnToer по счЄту оператора на €русе j

  sumEdgesOut = 0; // суммируем в переменной sumEdgesIn
  for(INT iEdge = 0; iEdge < nEdges; iEdge ++ ) // по всем дугам графа ========
   if( Edges(0,iEdge) == iOp ) // нашли дугу, ¬џ’ќƒяў”ё из оператора iOp
    sumEdgesOut ++ ; // суммируем число дуг, ¬џ’ќƒяў»’ из оператор iOp...

  if(sumEdgesOut < nEdgesOutOp) // MIN ¬џ’ќƒќ¬ по всем опер. €русов minTier-maxTier
  {
   nEdgesOutOp = sumEdgesOut;
   iOpMinOut = iOp; // запомнили номер оператора
  }

 } // конец цикла по i
   // конец цикла по j

 return iOpMinOut; // оператор с MIN выходов на €русах minTier-maxTier

} // --- конец GetOpByOutMinOnTiers --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall AddEdge(INT fromOp, INT toOp)
{ // --- прибавл€ет дугу и провер€ет, есть ли еще место в Mem_Edges[] ----------
 char str[_256];

 if( !isEdges ) // нет массива Mem_Edges[]...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }

//////////////////////c/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//////////////////////c/////////////////////////////////////////////////////////

 if( ( nEdges+3 ) < Max_Edges ) // размера массива Mem_Edges[] ещЄ хватает!..
  goto cont;
//
 Max_Edges *= stockMem; // увеличили в stockMem раз
 Mem_Edges = (me*) realloc( Mem_Edges, Max_Edges * sizeof(INT) ); // реаллокировали пам€ть под Mem_Edges[]...
//
 if( !Mem_Edges ) // совсем плохо - пам€ть в "куче" закончилась
 {
  snprintf(str,sizeof(str), "Ќехватка пам€ти дл€ размещени€ массива ƒ”√ (00). «атребовано %d элементов...",
                             Max_Edges );
  MessageBox(0, str, "ѕредупреждение", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  MessageBeep(MB_OK); // звуковое предупреждение...
  isEdges = FALSE ; // массив Mem_Edges[] не создан...
  return FALSE ;
 }
//
 t_printf( "\n-I- ћассив ƒ”√ (00) перераспределЄн на %d x %d = %d элементов -I-",
                  Max_Edges );
//
 cont: // не надо дополнительно аллокировать пам€ть дл€ Mem_Edges[]
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
 return TRUE; // дуга успешно добавлена
//
} // --- конец AddEdge ---------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetFirstToOpFromOp(INT fromOp)
{ // --- вернуть ѕ≈–¬џ… по счЄту оператор toOp, €вл€ющийс€ ¬џ’ќƒяў»ћ
// --- по дуге графа относительно fromOp
//
 if( !isEdges ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
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
 if( !isEdges ) // массив Mem_Edges[] ещЄ не существует - выходим с ошибкой
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
 if( !isTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
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
//  t_printf( "\n-E- %s(): %s {%d-%d}, [%d] -E-", __FUNC__, messParams2, Tier1,Tier2, ERR_RANGE_IN );
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

 if( !isTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }

 if( ( Tier1 < 1 ) || ( Tier1 > nTiers ) ||
     ( Tier2 < 1 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }

 if( Tier2 < Tier1 ) // неверен диапазон Tier1 - Tier2
 {
//  t_printf( "\n-E- %s(): %s {%d-%d}, [%d] -E-", __FUNC__, messParams2, Tier1,Tier2, ERR_RANGE_IN );
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }

 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // по заданным €русам яѕ‘ ---------
  if ( Tiers(iTier,0) >= TierMaxOp ) // ищем MAX...
  {
   TierMaxOp = Tiers(iTier,0); // число операторов на €русе iTier
   Tier = iTier; // запомнили iTier с “≈ ”ў»ћ максимумом операторов
  }

 return Tier ;

} // --- конец  c_GetTierLastMaxOps --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierFirstMinOps(INT Tier1, INT Tier2)
{ // возвращает ѕ≈–¬џ… #€руса с MIN по диапазону €русов (Tier1-Tier2) числом операторов
// - если экстремумов (одинаковых) несколько - возвращаетс€ ѕ≈–¬џ… из них (c Tier = min)
 INT TierMinOp = _maxOpsOnTier , // дл€ поиска MIN
     Tier;

 if( !isTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }

 if( ( Tier1 < 1 ) || ( Tier1 > nTiers ) ||
     ( Tier2 < 1 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1,  ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }

 if( Tier2 < Tier1 ) // неверен диапазон Tier1 - Tier2
 {
//  t_printf( "\n-E- %s(): %s {%d-%d}, [%d] -E-", __FUNC__, messParams2, Tier1,Tier2, ERR_RANGE_IN );
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }

 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // по всем €русам яѕ‘ ------------
  if ( Tiers(iTier,0) < TierMinOp ) // ищем MIN...
  {
   TierMinOp = Tiers(iTier,0); //  число операторов на €русе iTier
   Tier = iTier; // запомнили iTier с “≈ ”ў»ћ минимумом операторов
  }

 return Tier ;

} // --- конец  c_GetTierFirstMinOps -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierLastMinOps(INT Tier1, INT Tier2)
{ // возвращает ѕќ—Ћ≈ƒЌ»… #€руса с MIN по диапазону €русов (Tier1-Tier2) числом операторов
// - если экстремумов (одинаковых) несколько - возвращаетс€ ѕѕќ—Ћ≈ƒЌ»… из них (c Tier = max)
 INT TierMinOp = _maxOpsOnTier , // дл€ поиска MIN
     Tier;

 if( !isTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }

 if( ( Tier1 < 0 ) || ( Tier1 > nTiers ) ||
     ( Tier2 < 0 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }

 if( Tier2 < Tier1 ) // неверен диапазон Tier1 - Tier2
 {
//  t_printf( "\n-E- %s(): %s {%d-%d}, [%d] -E-", __FUNC__, messParams2, Tier1,Tier2, ERR_RANGE_IN );
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }

 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // по всем €русам яѕ‘ ------------
  if ( Tiers(iTier,0) <= TierMinOp ) // ищем MIN...
  {
   TierMinOp = Tiers(iTier,0); //  число операторов на €русе iTier
   Tier = iTier; // запомнили iTier с “≈ ”ў»ћ минимумом операторов
  }

 return Tier ;

} // --- конец  c_GetTierLastMinOps --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsOpExistOnTier(INT Op, INT Tier)
{ // возвращает TRUE только если оператор Op присутствует на €русе Tier

 for(INT jOpOnTier=1; jOpOnTier<=Tiers(Tier,0); jOpOnTier++) // по всем операторам €руса Tier
  if( Tiers(Tier,jOpOnTier) == Op ) // нашли искќмый оператор Op !..
   return TRUE;

 return FALSE;

} // --- конец  c_IsOpExistOnTier ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsOpDependOnlyAboveTiers(INT toOp, INT Tier)
{ // TRUE - только если оператор toOp зависит (ѕќ ¬—≈ћ свом In-дугам)
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
    if ( c_IsOpExistOnTier( fromOp, iTier ) == TRUE ) // оператор fromOp присутствует на €русе iTier...
     sumIn ++ ; // суммируем число найденных fromOp на €русах с 0 по Tier-1
  } // конец if ( Mem_Edges[1][iEdge] == toOp )
//
 } // конец цикла по iEdge
//
 if( sumIn == c_GetCountInEdgesByOp(toOp) ) // насчитали столько In, сколько есть у оператора toOp ?
  return TRUE; // тогда все ¬’ќƒяў»≈ в toOp оператор дуги наход€тс€ на €русах от 0 до Tier-1
 else
  return FALSE;
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
 if( !isEdges ) // массив Mem_Edges[] ещЄ не существует - выходим с ошибкой
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
 if( !isEdges ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
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
 if( !isTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
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
 if( !isEdges ) // массив Mem_Edges[] ещЄ не существует - выходим с ошибкой
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
{ // --- переносит оператор Op на €рус toTier с проверкой корректности действи€
// ----- ни €рус первоначального нахождени€ Op ни toTier не могут быть €русами первым или последним
// ----- если удалось благополучно перенести - возвращаетс€ TRUE и глобальна€ iMove
//
 if( !isTiers ) // если массива Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 INT fromTier = c_GetTierByOp( Op ); // €рус первоначального нахождени€ оператора Op
//
 if( ( fromTier < 1 ) || // с первого €руса оператор перенести можно, а с нулевого - нельз€!
     ( fromTier > nTiers ) ) // с последнего €руса оператор перести можно, а с более низкого - нельз€!
 {
  DisplayMessage( "E", __FUNC__, messParams1, FALSE ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 if( fromTier == toTier ) // не желаем-с делать глупостев-с... Ќ» ј ќ√ќ ѕ≈–≈Ќќ—ј !!!
 {
//  DisplayMessage( "E", __FUNC__, messParams2, FALSE ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
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
  if( IncreaseOpsOnTier( toTier, _maxOpsOnTier * stockMem, 111 ) == FALSE ) // неудача перераспределени€ пам€ти
  {
   isTiers = FALSE ; // массив Tiers[][] не создан...
   return FALSE ;
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
   return TRUE ;
  } // конец if
//
} // --- конец c_MoveOpTierToTier ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_AddTier(INT Tier)
{ // --- создаЄт (пустой) €рус Ќ»∆≈ €руса Tier (кроме последнего)
// ----- св€зи не мен€ютс€; возвращает TRUE, если удачно
 char str[_2048];
//
 if( !isTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier <  0 ) ||  // этого нельз€...  а всЄ остальное ћќ∆Ќќ !
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
    isTiers = FALSE ; // массив Tiers[][] не создан...
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

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

 nTiers ++ ; // увеличили число €русов на 1

// --- сдвигаем €русы с Tier по nTiers-1 вниз ----------------------------------
 for(INT iTier=nTiers; iTier>Tier; iTier--) // по €русам снизу вверх
  for(INT j=0; j<=Tiers(iTier-1,0); j++) // цикл по "верхнему" из двух
   Tiers(iTier,j) = Tiers(iTier-1,j); // "верхний" переносим в "нижний"

 Tiers( Tier+1,0 ) = 0; // вновь созданный €рус ѕ”—“ !

 return TRUE ; // успешно выполнено

} // --- конец c_AddTier -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_DelTier(INT Tier)
{ // --- уничтожает (пустой) €рус Tier (кроме нулевого)
// ----- св€зи не мен€ютс€; возвращает TRUE, если удачно
//
 if( !isTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
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

 nTiers -- ; // €русов стало на 1 меньше...

 return TRUE ; // успешно выполнено

} // --- конец c_DelTier -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountEdges()
{ // возвращает общее число дуг в информационном графе алгоритма (»√ј)
//
 if( !isEdges ) // нет массива Mem_Edges[]
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
 if( !isTiers ) // нет массива Tiers[][]
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
 INT old = nMoves ; // запомнили
 nMoves = 0 ;
 return old ; // вернули
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
//   Application->ProcessMessages(); // дать поработать Windows
  }
//
 } // конец по символам строки str
//
 return TRUE ; // дл€ Lua всегда надо что-то возвратить (void не допускаетс€!)
//
} // --- конец c_AddLineToTextFrame --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ClearTextFrame()
{ // очищает окно  текстового представл≈ни€
 TM1->Clear(); // очистка M1
 return TRUE ; // дл€ Lua всегда надо что-то возвратить (void не допускаетс€!)
} // --- конец ClearTextFrame --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_DelayMS(INT Sec)
{ // ждЄт Sec секунд, дава€ при этом поработать Windows
 Delay ( Sec ); // ждать Sec секунд
 return TRUE ; // дл€ Lua всегда надо что-то возвратить (void не допускаетс€!)
} // --- конец c_DelayMS -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutTiersToTextFrame()
{ // выдаЄт яѕ‘ (массив Tiers[][]) в окно дл€ текстовой визуализации
 char str[_16384], tmp[_512];
//
 if( !isTiers ) // массив Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 t_printf( "\n-=- ярусов яѕ‘ = %d -=-", nTiers ); // строка с числом €русов
//
// --- выводим в M1 номера операторов по €русам --------------------------------
 for(INT iTier=0; iTier<=nTiers; iTier++) // по всем вы€вленным €русам яѕ‘
 {
  snprintf(str,sizeof(str), "%d|%d: ", iTier,Tiers(iTier,0)); // готовим строку (iTier €рус) дл€ вывода в M1
//
  for(INT j=1; j<=Tiers(iTier,0); j++) // по номерам операторов на €русе iTier
  {
   if( !c_GetCountInEdgesByOp( Tiers(iTier,j) )) // у этого оператора нет ¬’ќƒ€ў»’ дуг...
    snprintf(tmp,sizeof(tmp), _IN,  Tiers(iTier,j)); // это выходной оператор (результат программы)
   else
   if( !c_GetCountOutEdgesByOp( Tiers(iTier,j) )) // у этого оператора нет ¬џ’ќƒ€ў»’ дуг...
    snprintf(tmp,sizeof(tmp), _OUT, Tiers(iTier,j)); // это выходной оператор (результат программы)
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
// c_PutParamsTiers(); // вывод параметров графа и его яѕ‘ на главную форму и в файл протокола
//
 return TRUE ; // всЄ успешно сделано
//
} // --- конец c_PutTiersToTextFrame -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutEdgesToTextFrame()
{ // выдаЄт массив дуг Mem_Edges[] в окно дл€ визуализации
 char str[_2048];
//
 if( !isEdges ) // если массив Edges[][] пуст - выйти и вернуть FALSE
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
 return TRUE; // всЄ нормально - массив Mem_Edges[] выдан в текстовое окно
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
 bool Err = FALSE; // возвращаемое значение
//
 if( !isTiers ) // нет массива Tiers[][]
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
    Err = TRUE ;
   }
//
// --- тест на наличие ¬џ’ќƒяў»’ дуг -------------------------------------------
   if( !c_GetCountOutEdgesByOp( Op ) && ( iTier != nTiers ) ) // не на ѕќ—Ћ≈ƒЌ≈ћ €русе "»" ¬џ’ќƒяў»’ дуг нет
   {
    t_printf( "\n-W- ќператор %d не на ѕќ—Ћ≈ƒЌ≈ћ €русе %d не имеет ¬џ’ќƒяЎ»’ дуг -W-", Op, iTier );
    Err = TRUE ;
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
 if( !isEdges ) // массив Mem_Edges[] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
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
 if( !isEdges ) // массив Mem_Edges[] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
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
 if( !isEdges ) // массив Mem_Edges[] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
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
 if( !isEdges ) // массив Mem_Edges[] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
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
 return 0 ; // если не нашли ни одной дуги...
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
  return TRUE;
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
  return TRUE;
//
 } // всЄ нормально с файлом с именем по умолчанию... работаем дальше !
//
////////////////////////////////////////////////////////////////////////////////
// --- не удалось открыть ни заданный файл, ни файл с именем по умолчанию ------
 strNcpy( sCalcs, "\0" ); // очищаем строку-пам€ть параметров ¬џ„»—Ћ»“≈Ћ≈…
 return FALSE; // проблемы с файлом...
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
  return TRUE;
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
  return TRUE;
//
 } // всЄ нормально с файлом с именем по умолчанию... работаем дальше !
//
////////////////////////////////////////////////////////////////////////////////
// --- не удалось открыть ни заданный файл, ни файл с именем по умолчанию ------
 strNcpy( sOps, "\0" ); // очищаем строку-пам€ть параметров ќѕ≈–ј“ќ–ќ¬

 return FALSE; // проблемы с файлом...

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
  return TRUE;
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
  return TRUE;
//
 } // всЄ нормально с файлом с именем по умолчанию... работаем дальше !
//
////////////////////////////////////////////////////////////////////////////////
// --- не удалось открыть ни заданный файл, ни файл с именем по умолчанию ------
 strNcpy( sEdg, "" ); // очищаем строку-пам€ть параметров ƒ”√
 return FALSE; // проблемы с файлом...
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
  return TRUE;
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
  return TRUE;
//
 } // всЄ нормально с файлом с именем по умолчанию... работаем дальше !
//
////////////////////////////////////////////////////////////////////////////////
// --- не удалось открыть ни заданный файл, ни файл с именем по умолчанию ------
 strNcpy( sVrt, "\0" ); // очищаем строку-пам€ть параметров ¬≈–Ў»Ќ
 return FALSE; // проблемы с файлом...
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
{ // если подстрока параметров вычислител€ корректна, возвращаетс€ TRUE
 bool out = FALSE;
 char sName[_128]; // им€ параметра (без '-' в начале)
 REAL minVal, maxVal; // численные значени€ параметров
//
 if( sscanf( str, "-%s %g %g", sName, &minVal, &maxVal ) == 3 ) // если Ok - 3 распќзнанных параметров
 {
  snprintf( str,sizeof(str), "-%s %g %g", sName, min(minVal,maxVal), max(minVal,maxVal) ); // восстановим str по прочитанному
  out = TRUE;
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
{ // если подстрока параметров оператора корректна, возвращаетс€ TRUE
 bool out = FALSE;
 char sName[_128]; // им€ параметра (без '-' в начале)
 REAL Val; // численное значение параметра
//
 if( sscanf( str, "-%s %g", sName, &Val ) == 2 ) // если Ok - 2 распќзнанных параметров
 {
  snprintf( str,sizeof(str), "-%s %g", sName, Val ); // восстановим str по прочитанному
  out = TRUE;
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
   return FALSE;
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
 return TRUE;
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
   return FALSE;
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
 return TRUE;
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
   return FALSE;
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
 return TRUE;
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
   return FALSE;
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
 return TRUE;
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
INT __fastcall c_GetNumbOp(INT Numb)
{ // возвращает номер Numb оператора (исключа€ входные) по мере вхождени€ в файл дуг
//
 if( !isEdges ) // нет массива Mem_Edges[]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ищем число операторов (имеем nEdges дуг графа)===========================
////////////////////////////////////////////////////////////////////////////////
 INT nW, iEdges, jEdges,
     iOps = 0; // счЄтчик числа вершин (глобальное)
 bool flag;
//
  for(iEdges=1; iEdges<=nEdges; iEdges++) // по все дугам начина€ с #1
   Mem_Edges[iEdges].flag_From =
   Mem_Edges[iEdges].flag_To   = FALSE; // сн€ли метку со всех операторов
//
// === по всем дугам »√ј =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // по все дугам начина€ с #1
  {
   if( !Mem_Edges[iEdges].flag_From ) // запомнили »—’ќƒяў”ё вершину дуги iEdges
   { // --- вершины метим номерами с минусом -----------------------------------
    nW=Edges(0,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     if( Edges(0,jEdges) == nW )
      Mem_Edges[jEdges].flag_From == TRUE; // пометили "From"
//
     if( Edges(1,jEdges) == nW )
      Mem_Edges[jEdges].flag_To == TRUE;  // пометили "To" (это лишнее)
    } // конец for(jEdges=1; jEdges<=nEdges; jEdges++)
//
   } // конец if( nW > 0 )
//
// --- найденное nW принимаетс€, если только его Ќ≈“ в Edges(1,*) --------------
// --- если оно встречаетс€ в Edges(1,*), то пропускаем iEdges -----------------
//
   flag = FALSE;
   for(jEdges=1; jEdges<=nEdges; jEdges++) // ищем вхождение -nW
    if( Mem_Edges[jEdges].flag_To && Edges(1,jEdges)==nW )
//  if( Edges(1,jEdges) == -nW )
     flag = TRUE ; // итак, nW встречаетс€ в Edges(1,*) ..!
//
   if( flag ) // если nW ¬—“–≈„ј≈“—я в Edges(1,*) - подходит!
    iOps ++ ;
//
   if( iOps == Numb ) // нашли вхожд≈ние номер Numb
    goto cont ;
//
////////////////////////////////////////////////////////////////////////////////
//
   if( !Mem_Edges[iEdges].flag_To ) // запомнили ¬’ќƒяў”ё вершину дуги iEdges
// if( ( nW=Edges(1,iEdges) ) > 0 ) // запомнили ¬’ќƒяў”ё вершину дуги iEdges
   { // --- вершины метим номерами с минусом -----------------------------------
    nW=Edges(1,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     if( Edges(0,jEdges) == nW )
      Mem_Edges[jEdges].flag_From == TRUE; // пометили "From" (это лишнее)
//
      if( Edges(1,jEdges) == nW )
       Mem_Edges[jEdges].flag_To == TRUE; // пометили "To"
    } // конец for(jEdges=1; jEdges<=nEdges; jEdges++)
//
    iOps ++ ; // счЄтчик ќЅў≈√ќ числа вершин
    if( iOps == Numb ) // нашли вхожд≈ние номер Numb
     goto cont ;
//
   } // конец if( nW > 0 )
//
  } // конец for(iEdges=1; iEdges<=nEdges; iEdges++)
//
////////////////////////////////////////////////////////////////////////////////
 cont:
////////////////////////////////////////////////////////////////////////////////
//
 return nW ;
//
} // ------ конец c_GetNumbOp --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOps()
{ // возвращает число вершин »√ј без учЄта входных данных
//
 if( !isEdges ) // нет массива Mem_Edges[]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ищем общее число операторов nOps (имеем nEdges дуг графа)================
////////////////////////////////////////////////////////////////////////////////
//
 INT iEdges, jEdges,
     nW; // nW помнит (текущую) вершину дуги iEdges
 nOps = 0; // число вершин без входных (глобальное)
//
////////////////////////////////////////////////////////////////////////////////
#ifdef METHOD_OF_CALC_COUNT_OPS //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////////////////////////////////////////////////////////////////////////////////
  for(iEdges=1; iEdges<=nEdges; iEdges++) // по всем дугам начина€ с #1
   Mem_Edges[iEdges].flag_From =
   Mem_Edges[iEdges].flag_To   = TRUE; // пометили все операторы
//
// === по всем дугам »√ј =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // по всем nEdges дугам начина€ с #1
  {
   if( !c_GetCountInEdgesByOp( Edges(0,iEdges) ) ) // "отс≈иваем" операторы входного €руса
    continue;
//
// обработка случа€ ¬’ќƒяў≈… (From) вершины дуги iEdges
   if( Mem_Edges[iEdges].flag_From ) // запомнили "пом≈ченную" ¬’ќƒяў”ё вершину дуги iEdges
   {
    nW = Edges(0,iEdges);
    nOps ++ ; // счЄтчик числа вершин (»—’ќƒяў»’ по дугам)
////////////////////////////////////////////////////////////////////////////////
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     if( Edges(0,jEdges) == nW )
      Mem_Edges[jEdges].flag_From = FALSE; // сн€ли метку с вершины "откуда" (From)
//
     if( Edges(1,jEdges) == nW )
      Mem_Edges[jEdges].flag_To   = FALSE; // сн€ли метку с вершины "куда" (To)
    } // конец for(jEdges=1; jEdges<=nEdges; jEdges++)
//
   } // конец if( Mem_Edges[iEdges].FlagFrom )
////////////////////////////////////////////////////////////////////////////////
// обработка случа€ ¬џ’ќƒяў≈… (To) вершины дуги iEdges
   if( Mem_Edges[iEdges].flag_To ) // запомнили "пом≈ченную" ¬џ’ќƒяў”ё вершину дуги iEdges
   {
    nW = Edges(1,iEdges);
    nOps ++ ; // счЄтчик вершин числа (¬’ќƒяў»’ по дугам)
////////////////////////////////////////////////////////////////////////////////
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     if( Edges(0,jEdges) == nW )
      Mem_Edges[jEdges].flag_From = FALSE; // сн€ли метку с вершины "откуда" (From)
//
     if( Edges(1,jEdges) == nW )
      Mem_Edges[jEdges].flag_To   = FALSE; // сн€ли метку с вершины "куда" (To)
    } // конец for(jEdges=1; jEdges<=nEdges; jEdges++)
////////////////////////////////////////////////////////////////////////////////
   } // конец if( Mem_Edges[iEdges].FlagFTo )
//
  } // конец for(iEdges=1; iEdges<=nEdges; iEdges++)
////////////////////////////////////////////////////////////////////////////////
#else //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////////////////////////////////////////////////////////////////////////////////
  for(iEdges=1; iEdges<=nEdges; iEdges++) // по всем дугам начина€ с #1
   Mem_Edges[iEdges].flag_To = TRUE; // пометили  операторы ...To
//
  for(iEdges=1; iEdges<=nEdges; iEdges++) // по всем nEdges дугам начина€ с #1
// обработка случа€ ¬џ’ќƒяў≈… (To) вершины дуги iEdges
   if( Mem_Edges[iEdges].flag_To ) // запомнили "пом≈ченную" ¬џ’ќƒяў”ё вершину дуги iEdges
   {
    nW = Edges(1,iEdges);
    nOps ++ ; // счЄтчик вершин числа (¬’ќƒяў»’ по дугам)
////////////////////////////////////////////////////////////////////////////////
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     if( Edges(1,jEdges) == nW )
      Mem_Edges[jEdges].flag_To   = FALSE; // сн€ли метку с вершины "куда" (To)
    } // конец for(jEdges=1; jEdges<=nEdges; jEdges++)
////////////////////////////////////////////////////////////////////////////////
   } // конец if( Mem_Edges[iEdges].FlagFTo )
//
////////////////////////////////////////////////////////////////////////////////
#endif //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////////////////////////////////////////////////////////////////////////////////
//
 return nOps ;
//
} // --- конец c_GetCountOps ---------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbOpInput(INT Numb)
{ // возвращает номер Numb оператора (только из ¬’ќƒЌџ’ операторов)
//
 if( !isEdges ) // нет массива Mem_Edges[]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ищем Numb-тый оператор (имеем nEdges дуг графа)==========================
////////////////////////////////////////////////////////////////////////////////
 INT nW, iEdges, jEdges,
     iOps = 0 ; // счЄтчик числа вершин графа (операторов)
 bool flag;
//
  for(iEdges=1; iEdges<=nEdges; iEdges++) // по все дугам начина€ с #1
   Edges_f(0,iEdges) =
   Edges_f(1,iEdges) = FALSE; // сн€ли метку со всех вершин
//
// === по всем дугам »√ј =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // по всем дугам начина€ с #1
   if( !Edges_f(0,iEdges) ) // запомнили »—’ќƒяў”ё вершину дуги iEdges
   {
    nW = Edges(0,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     Edges_f(0,jEdges) = Edges(0,jEdges)==nW ? TRUE : Edges_f(0,jEdges) ; // пометили "From"
     Edges_f(1,jEdges) = Edges(1,jEdges)==nW ? TRUE : Edges_f(1,jEdges) ; // пометили "To"
    } // конец for(jEdges=1; jEdges<=nEdges; jEdges++)
//
   flag = FALSE;
   for(jEdges=1; jEdges<=nEdges; jEdges++)
    if( Edges_f(1,jEdges) && Edges(1,jEdges)==nW ) // помечено и равно nW
     flag = TRUE ; // итак, nW встречаетс€ в Edges(1,*) ..!
//
   if( !flag ) // если nW Ќ≈ ¬—“–≈„ј≈“—я в Edges(1,*) - подходит!
    iOps ++ ;
//
   if( iOps == Numb ) // нашли вхожд≈ние номер Numb
    return nW ;
//
   } // конец if(!Edges_f(0,iEdges)) и for(iEdges=1; iEdges<=nEdges; iEdges++)
//
} // ------ конец c_GetNumbOpInput ---------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbOpOutput(INT Numb)
{ // возвращает номер Numb вершины (только из ¬џ’ќƒЌџ’ операторов)
//
 if( !isEdges ) // нет массива Mem_Edges[]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ищем число операторов (имеем nEdges дуг графа)===========================
////////////////////////////////////////////////////////////////////////////////
 INT nW, iEdges, jEdges,
     iOps = 0 ; // счЄтчик числа вершин
 bool flag;
//
 for(iEdges=1; iEdges<=nEdges; iEdges++) // по все дугам начина€ с #1
  Edges_f(0,iEdges) =
  Edges_f(1,iEdges) = FALSE; // сн€ли метку со всех вершин (операторов0
//
// === по всем дугам »√ј =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // по всем дугам начина€ с #1
   if( !Edges_f(1,iEdges) ) // запомнили »—’ќƒяў”ё вершину дуги iEdges
   {
    nW = Edges(1,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     Edges_f(0,jEdges) = Edges(0,jEdges)==nW ? TRUE : Edges_f(0,jEdges) ; // пометили "From"
     Edges_f(1,jEdges) = Edges(1,jEdges)==nW ? TRUE : Edges_f(1,jEdges) ; // пометили "To"
    } // конец for(jEdges=1; jEdges<=nEdges; jEdges++)
//
   flag = FALSE;
   for(jEdges=1; jEdges<=nEdges; jEdges++)
    if( Edges_f(0,jEdges) && Edges(0,jEdges)==nW ) // помечено и равно nW
     flag = TRUE ; // итак, nW встречаетс€ в Edges(0,*) ..!
//
   if( !flag ) // если nW Ќ≈ ¬—“–≈„ј≈“—я в Edges(0,*) - подходит!
    iOps ++ ;
//
   if( iOps == Numb ) // нашли вхожд≈ние номер Numb
     return nW ;
//
   } // конец if(!Edges_f(1,iEdges)) и for(iEdges=1; iEdges<=nEdges; iEdges++)
//
} // ------ конец c_GetNumbOpOutput --------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOpsInput()
{ // возвращает только ¬’ќƒЌџ≈ вершины (0-й €рус) в »√ј ------------------------
//
//
 if( !isEdges ) // нет массива Mem_Edges[]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ищем число nOpsInput ¬’ќƒЌџ’ операторов (имеем nEdges дуг графа)=========
////////////////////////////////////////////////////////////////////////////////
 INT nW, iEdges, jEdges;
 bool flag;
 nOpsInput = 0; // число входных операторов (0-й €рус; глобальное)
//
 for(iEdges=1; iEdges<=nEdges; iEdges++) // по всем дугам начина€ с #1
  Edges_f(0,iEdges) =
  Edges_f(1,iEdges) = FALSE; // "сн€ли метку" со всех вершин (операторов)
//
// === по всем дугам »√ј =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // по все дугам начина€ с #1
   if( !Edges_f(0,iEdges) ) // запомнили »—’ќƒяў”ё вершину дуги iEdges
   {
    nW = Edges(0,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++) // по всем дугам начина€ с #1
    {
     Edges_f(0,jEdges) = Edges(0,jEdges)==nW ? TRUE : Edges_f(0,jEdges) ; // пометили "From"
     Edges_f(1,jEdges) = Edges(1,jEdges)==nW ? TRUE : Edges_f(1,jEdges) ; // пометили "To"
    } // конец for(jEdges=1; jEdges<=nEdges; jEdges++)
//
   flag = FALSE;
   for(jEdges=1; jEdges<=nEdges; jEdges++)
    if( Edges_f(1,jEdges) && Edges(1,jEdges)==nW ) // помечено и =nW
     flag = TRUE ; // итак, nW встречаетс€ в Edges(1,*) ..!
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
 if( !isEdges ) // нет массива Mem_Edges[]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ищем число nOpsInput ¬’ќƒЌџ’ операторов (имеем nEdges дуг графа)=========
////////////////////////////////////////////////////////////////////////////////
 INT nW, iEdges, jEdges;
 bool flag;
 nOpsOutput = 0; // число ¬џ’ќƒЌџ’ операторов (глобальное)
//
 for(iEdges=1; iEdges<=nEdges; iEdges++) // по всем дугам начина€ с #1
  Edges_f(0,iEdges) =
  Edges_f(1,iEdges) = FALSE; // сн€ли метку со всех вершин (операторов)
//
// === по всем дугам »√ј =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // по всем дугам начина€ с #1
   if( !Edges_f(1,iEdges) ) // запомнили »—’ќƒяў”ё вершину дуги iEdges
   {
    nW = Edges(1,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     Edges_f(0,jEdges) = Edges(0,jEdges)==nW ? TRUE : Edges_f(0,jEdges) ; // пометили "From"
     Edges_f(1,jEdges) = Edges(1,jEdges)==nW ? TRUE : Edges_f(1,jEdges) ; // пометили "To"
    }
//
   flag = FALSE;
   for(jEdges=1; jEdges<=nEdges; jEdges++)
    if( Edges_f(0,jEdges) && Edges(0,jEdges)==nW ) // помечено и =nW
     flag = TRUE ; // итак, nW встречаетс€ в Edges(0,*) ..!
//
   if( !flag ) // если nW Ќ≈ ¬—“–≈„ј≈“—я в Edges(0,*) - подходит!
    nOpsOutput ++ ;
//
   } // конец if(!Edges_f(1,iEdges)) и for(iEdges=1; iEdges<=nEdges; iEdges++)
//
 return nOpsOutput ;
//
} // --- конец c_GetCountOpsOutput----------------------------------------------


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

 strNcpy( sDst, "\0" ); // очистим sDst

 for( i=iStart; i<=lenSrc; i++ ) // вдоль по строке sSrc индексу i - ищем первое вхождение шаблона

  if( ( ( Rule==0 && sSrc[i]=='=' ) && // Rule=0 и первый символ '=' (вход€ща€ последовательность)
        ( isdigit(sSrc[i+1]) || toupper(sSrc[i+1]=='D') ) // [цифра] или [D(d)]
      || // или дл€ Rule != 0
        ( Rule!=0 && sSrc[i]=='-' ) && // Rule!=1 и первый символ '-'
          isalpha(sSrc[i+1]) ) ) // шаблон [лат.буква]

  for( j=i+1; j<=lenSrc; j++ ) // вдоль по строке sSrc по индексу j - ищем следующее вхождение шаблона

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

 t_printf( "\n-I- ѕараметры ¬џ„»—Ћ»“≈Ћ≈… и ќѕ≈–ј“ќ–ќ¬, метрики ƒ”√ и ¬≈–Ў»Ќ -I-" ); // информационное сообщение

 if( c_LoadFileNameParamsCalcs( FileNameParamsCalcs ) ) // если с файлом всЄ удачно...
 {
  t_printf( "=> ¬џ„»—Ћ»“≈Ћ»: файл |%s|", FileNameParamsCalcs ); // им€ файла параметров ¬џ„»—Ћ»“≈Ћ≈…
  t_printf( "исходна€:   |%s|", sWork ); // исходна€ строка
  t_printf( "коррекци€: |%s|", sCalcs ); // скоректированна€ строка
 }

 if( c_LoadFileNameParamsOps( FileNameParamsOps ) )
 {
  t_printf( "=> ќѕ≈–ј“ќ–џ: файл |%s|", FileNameParamsOps ); // им€ файла параметров ќѕ≈–ј“ќ–ќ¬
  t_printf( "исходна€:   |%s|", sWork ); // исходна€ строка
  t_printf( "коррекци€: |%s|", sOps ); // скоректированна€ строка
 }

 if( c_LoadFileNameParamsEdges( FileNameParamsEdges ) )
 {
  t_printf( "=> ћ≈“–» » ƒ”√: файл |%s|", FileNameParamsEdges ); // им€ файла метрик ƒ”√
  t_printf( "исходна€:   |%s|", sWork ); // исходна€ строка
  t_printf( "коррекци€: |%s|", sEdg ); // скоректированна€ строка
 }

 if( c_LoadFileNameParamsVertices( FileNameParamsVertices ) )
 {
  t_printf( "=> ћ≈“–» » ¬≈–Ў»Ќ: файл |%s|", FileNameParamsVertices ); // им€ файла метрик ¬≈–Ў»Ќ
  t_printf( "исходна€:   |%s|", sWork ); // исходна€ строка
  t_printf( "коррекци€: |%s|", sVrt ); // скоректированна€ строка
 }

 c_AddLineToTextFrame( "\n" );

 return TRUE ;

} // --- конец c_PutParamsAll --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetParamsByOp(INT Op)
{ // проcматривает строку sOps и возвращает подстроку всех параметров ќѕ≈–ј“ќ–ј Op
 char sN[_8192], sName[_128];
 INT  lOps, iStart=0, iEnd, n1, n2;

 if( ! (lOps = strlen( sOps ) ) ) // если строка ќѕ≈–ј“ќ–ќ¬ пуста€...
  return "\0" ;

////////////////////////////////////////////////////////////////////////////////
// --- начали искать sN среди подстрок типа '=n1/n2:'---------------------------

 do // по подстрокам '=n1/n2:' или '=Def:'
 {
  iEnd = c_FindSubString( sOps, sN, iStart, 0 );
// --- начало обработки строки sOps списка параметров --------------------------

//  DelSpacesTabsAround( sN ); // обрезаем внешние пробелы

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

// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lOps ); // пока не конец строки sOps ( конец соотв. do )
//
////////////////////////////////////////////////////////////////////////////////
// --- начали искать sN среди подстрок типа '=Def:'-----------------------------

 iStart = 0;

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

  if( sscanf( sN, "%s ", sName ) == 1 ) // правильное чтение
   return strchr( sN,':' ) + 2 ; // перескакиваем через ':' и 'пробел'

// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lOps ); // пока не конец строки sOps ( конец соотв. do )

////////////////////////////////////////////////////////////////////////////////

 return "\0" ; // не найдено вообще ничего - возращаем (по умолчанию)

} // --- конец c_GetParamsByOp -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetParamsByCalc(INT Calc)
{ // проcматривает строку sCalcs и возвращает подстроку всех параметров ¬џ„»—Ћ»“≈Ћя Op
 char sN[_8192], sName[_128];
 INT  lCalcs, iStart=0, iEnd, n1, n2;

 if( ! (lCalcs = strlen( sCalcs ) ) ) // если строка ¬џ„»—Ћ»“≈Ћ≈… пуста€...
  return "\0" ;

////////////////////////////////////////////////////////////////////////////////
// --- начали искать sN среди подстрок типа '=n1/n2:'---------------------------

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

// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lCalcs ); // пока не конец строки sCalcs ( конец соотв. do )

////////////////////////////////////////////////////////////////////////////////
// --- начали искать sN среди подстрок типа '=Def:'-----------------------------

 iStart = 0;

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

  if( sscanf( sN, "%s ", sName ) == 1 ) // правильное чтение
   return strchr( sN,':' ) + 2 ; // перескакиваем через ':' и 'пробел'

// --- конец обработки строки sN спиcка параметров -----------------------------
  iStart = iEnd;
 } while( iEnd !=lCalcs ); // пока не конец строки sCalcs ( конец соотв. do )

////////////////////////////////////////////////////////////////////////////////

 return "\0" ; // не найдено вообще ничего - возращаем (по умолчанию)

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
 bool flagPoss = TRUE, // флаг ¬ќ«ћќ∆Ќќ—“»...
      flagNameParam = FALSE; // есть ли совпадающие имена параметров
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
//    flagNameParam = TRUE; // нашлось совпадение по параметрам
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
// при Rule==0 возвращаетс€ TRUE при выполн»мости и FALSE при обратном
// при Rule!=0 выдаЄтс€ список ќѕ≈–ј“ќ–ќ¬, которые могут быть выполнены на конкретном ¬џ„»—Ћ»“≈Ћ≈
INT  iOp,Op,Calc, numbCalcsByOp,
     countOps, countCalcs,
     countAll, countOut, countDone=0;
bool canAllExec = TRUE ;
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
 if( countOps <= 0 ) // проблемы! —корее всего массива Mem_Edges[] не существует (соответсвующий файл не был загружен)
 {
  t_printf( "\n-W- „исло ќѕ≈–ј“ќ–ќ¬ не определено. ¬озможно, файл данных графа не был загружен... -W-\n" );
  return FALSE ;
 }
//
// --- работаем с параметрами ¬џ„»—Ћ»“≈Ћ≈… -------------------------------------
//
 if( countCalcs <= 0 ) // проблемы! —корее всего файл параметров ¬џ„»—Ћ»“≈Ћ≈… не был загружен
 {
  t_printf( "\n-W- „исло ¬џ„»—Ћ»“≈Ћ≈… не определено. ¬озможно, файл параметров ¬џ„»—Ћ»“≈Ћ≈… не был загружен... -W-\n" );
  return TRUE ;
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
  canAllExec = FALSE ;
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

 TMsgDlgButtons mb; // тип кнопок на форме
 TMsgDlgType mt; // тип пиктограммы на форме

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

// if( !strcmp(Buttons, "00000000\0") ) // если в Buttons[] все 0 - включена кнопка Yes
//  mb << mbYes;

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
 if( !isTiers ) // массива Tiers[][] ещЄ нет...
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
 REAL dH_pix = 1.0 * H_pix / nTiers, // единица в  пикселах по высоте и ширине области отрисовки диаграммы
       dB_pix = 1.0 * B_pix / MaxOpsOnTier;
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
  REAL b_average = 1.0 * c_GetCountOps() / c_GetCountTiers(); // средн€€ ширина яѕ‘
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
  return TRUE; // всЄ успешно сделано
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
 return TRUE; // всЄ нормально
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
{ // если оператор Op присутствует в Tiers[][], возращаетс€ TRUE, иначе - FALSE
 bool out = FALSE;
 register INT i;
//
 if( !isEdges ) // массива Mem_Edges[] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(i=1; i<=c_GetCountOps(); i++) // по всем операторам
  if( c_GetNumbOp( i ) == Op )
   return TRUE;
//
 return out;
//
} // ---- конец c_IsOpContainOnTiers -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetOpByMaxTierLowerPreset(INT Op)
{ // выдаЄт оператор, информационно зависимый от заданного Op и наход€щийс€ на €русе
// с максимальным номером (если таких оператор несколько - выдаЄтс€ последний по списку)
 register INT i;
 INT to_Op, Op_maxTier, to_Tier, maxTier = -134567,
     nOut = c_GetCountOutEdgesByOp(Op); // число выходных дуг оператора Op
//
 if( !isTiers ) // массива Tiers[][] не существует...
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
  to_Op = c_GetNumbOutEdgeByOp( i, Op ); // i-тый комплементарный по дуге оператор относительно Op
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
INT __fastcall c_CreateAndOutputDataLiveDiagrByTiers( int Rule, char FileName[] )
{ // по массиву Tiers[][] строит и выводит в Tld информацию о времени жижни данных
// числа сообщений между €русами (полезно дл€ определени€ числа необходимых
// дл€ хранени€/передачи данных между оператораи на €русах яѕ‘
// полагаем, что файл регистров ќЅў»… дл€ всех параллельных вычислителей
// при Rule = 0 вывод в текстовое окно, при Rule == 1 вывод в файл FileName
// при Rule == 2 вывод в строку специального формата
 char sN[_8192], sS[_8192], sW[_128];
 INT i,j,k,l, from_Op,to_Op, to_Tier, max_to_Tier;
//
 if( !isTiers ) // массива Tiers[][] не существует...
 {
  t_printf( "\n-W- ƒл€ построени€ диаграммы времени жизни данных создайте сначала яѕ‘..! -W-\n");
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 TLD->Clear(); // очистим на вс€кий случай...
//
 TLD->Add( IntToStr(nTiers+1) ); // всего строк в Tld
//
 if( !Rule ) // вывод в текстовое окно
  t_printf( "\n-=- —троитс€ диаграмма времени жизни внутренних данных -=-\n     (интервалов диапазонов €русов яѕ‘ = %d )", nTiers+1 ); // строка с числом €русов
//
 for(INT iBottom=1; iBottom<=nTiers+1; iBottom++) // iBottom - нижн€€ граница »Ќ“≈–¬јЋј в яѕ‘
 {
  strNcpy( sN, "" ); // очистили строку параметров диапазона €русов с "дном" в виде €руса iBot
  l = 0; // число параметров данной строки
//
  for(i=0; i<iBottom; i++) // по €русам яѕ‘, не бќльшим (включающим) iBot
  {
   for(j=1; j<=c_GetCountOpsOnTier(i); j++) // по операторам по €русе i
   {
//
    APM // дать поработать Wimdows ---------------------------------------------
//
    from_Op = c_GetOpByNumbOnTier(j,i); // получили номер вершины, из которой ¬џ’ќƒя“ дуги
    to_Op = c_GetOpByMaxTierLowerPreset( from_Op ); // если выходных дуг нет вообще - возвращаетс€ ERR_COMMON
//
    max_to_Tier = ( to_Op == ERR_COMMON ) ? nTiers + 1 : c_GetTierByOp( to_Op ); // соответствующий to_Op €рус суть выходной / не выходной
//
    if( max_to_Tier >= iBottom ) // €рус конца дуги более или равен €русу Ќ»«ј интервала
    {
     if( !c_GetCountInEdgesByOp( from_Op ) ) // это вершина (оператор) ¬’ќƒЌџ’ данных
     {
      if( !Rule ) snprintf( sW,sizeof(sW), " \xAB%d|%d->%d", from_Op, i, max_to_Tier ); // "\xAB" = "<<" ; "\x96\x9B" = "->"
      else        snprintf( sW,sizeof(sW), " %d|%d->%d",     from_Op, i, max_to_Tier ); // вывод в файл
     }
     else
     if( !c_GetCountOutEdgesByOp( from_Op ) ) //  // это вершина (оператор) ¬џ’ќƒЌџ’ данных
     {
      if( !Rule ) snprintf( sW,sizeof(sW), " %d\xBB|%d->$", from_Op, i ); // "\xBB" = ">>"; "x96\x9B"= "->"
      else        snprintf( sW,sizeof(sW), " %d|%d->$",     from_Op, i ); // вывод в файл

     }
     else
      snprintf( sW,sizeof(sW), " %d|%d->%d", from_Op,i, max_to_Tier ); // "x96\x9" = "->"
//
     strcat( sN, sW ); // добавл€ем в sN дл€ формировани€ строки вывода
//
     l ++ ;
    } // конец if( max_to_Tier >= iBottom )
//
   } // конец по j (номерам операторов на €русе i)
//

  } // конец цикла по i (по всем €русам яѕ‘)
//
 if( iBottom == nTiers+1 ) // последний фиктивный €рус (рассчитанные данные)
  if( !Rule ) t_printf(      "%d/$|%d: %s",  iBottom-1, l, sN ); // выводим строку параметров »Ќ“≈–¬јЋј c нижним €русом iBot
  else      TLD->Add( Format("%d/$|%d: %s",  OPENARRAY(TVarRec, ((int(iBottom-1)),(int(l)),sN))) );
 else // не последний (фиктивный) €рус
  if( !Rule ) t_printf(      "%d/%d|%d: %s", iBottom-1, iBottom,l, sN );
  else      TLD->Add( Format("%d/%d|%d: %s", OPENARRAY(TVarRec, ((int(iBottom-1)),(int(iBottom)),(int(l)),sN))) );
//
 } // конец цикла по iBottom (iBottom - нижн€€ граница »Ќ“≈–¬јЋј в яѕ‘)
//
 if( Rule == 1 ) // вывод в файл
  TLD->SaveToFile( ReformFileName(FileName,extTld) );
//
} // ---- конец c_CreateAndOutputDataLiveDiagrByTiers --------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutTLDToTextFrame()
{ // выдать диаграмму времени жизни данных в текстовое окно
 c_CreateAndOutputDataLiveDiagrByTiers( 0, "" );
} // ----- конец c_PutTLDToTextFrame -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_SaveTLD( char FileName[] )
{ // выдать диаграмму времени жизни данных в файл
 c_CreateAndOutputDataLiveDiagrByTiers( 1, FileName ); // преобразование Filename - при непосредственном вызове
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
//  ѕри RuleMessage=TRUE выдаетс€ сообщение об ошибках }
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
  out = CreateProcess(NULL,CommandLine,NULL,NULL,FALSE,
                      dwCreationFlag,NULL,NULL,&si,&pi);
//
  if (!out) // если старт неудачен... out=FALSE
  {
   if (RuleMessage)  // если задан режим выдачи сообщений об ошибках
    MessageDlg("»звините, выполнение\n\r\n\r" +
                AnsiUpperCase(CommandLine)  +
               "\n\r\n\rневозможно...  (ошибка " +
                IntToStr(GetLastError()) + ")",
                mtError,
                TMsgDlgButtons() << mbYes, 0);
   return FALSE ;
  } // конец IF out = FALSE
//
  if (out) // если старт удачен... out = TRUE
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
    return FALSE ; // выход - ничего не дела€
//
   if ((RuleParent != 0) && // родитель завершаетс€
       (RuleParent != 1))
    Application->Terminate(); // закончить родительский процесс
//
 } // конец IF out=TRUE
//
} // ----- конец c_CreateProcess -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CreateProsess( char *cmdLine, byte RuleParent, byte Priority, bool RuleMessage )
{ // выполнить системный вызов CreateProsess -----------------------------------
 tp_printf( "\n->%s %d %d %d\n", cmdLine, RuleParent, Priority, RuleMessage );
 c_CreateProcess( cmdLine, RuleParent, Priority, RuleMessage );
} // ----- конец c_CreateProcess -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_SaveEdges(char FileName[])
{  // вывод дуг дл€ полного описани€ графа
 FILE *fptr = NULL; // рабочий указатель на файл
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName( FileName,extEdges ) ); // преобразованное им€ файла
//
 if(!(fptr = fopen(NewFileName, "w"))) // открыли дл€ записи
 {
  t_printf( "\n-E- Ќевозможно сохранить файл %s списка дуг (комплементарных вершин) »√ј -E-\n-W- проверьте осуществимость записи на заданный носитель данных -W-",
                   NewFileName );
  return FALSE ;
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
 return TRUE ;
//
} // --- конец c_SaveEdges -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ReadEdges(char FileName[])
{ // читает из файла FileName данные о графе (массив Mem_Edges[] св€зей вершин
// - и список операторов на уровне Tier = 0 - входные данные ); Mem_Edges[]
// - и Tiers[][] - глобальные; при ошибке открыти€ файла FileName возращаетс€ FALSE
 char str[_2048*4];
 FILE *fptr = NULL; // указатель на файл
 bool flagEdges = FALSE, // флаг начала описани€ дуг в »√A
      flagMLC   = FALSE; // флаг многострочного комментари€ (Many Lines Comment)
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extGv) ); // преобразованное им€ файла
//
 if( !(fptr = fopen(NewFileName, "r")) ) // файл описани€ графа открыли дл€ чтени€
 {
  t_printf( "\n-E- Ќевозможно прочитать файл %s описани€ »√ј -E-\n-W- веро€тна некорректность при дальнейшей работе -W-",
                   NewFileName );
  isEdges = FALSE ; // массив Mem_Edges[] не создан...
  isTiers = FALSE;
  return FALSE ;
 }
//
 strNcpy( FileNameEdges, NewFileName ); // запомнили текущее им€ файла описани€ »√ј
//
 Max_Edges = _128; // первоначальное максимальное количество дуг в »√ј
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 Mem_Edges = ( me* ) realloc( Mem_Edges, Max_Edges * sizeof( me ) ); // захватить или перераспределить пам€ть массив структур дуг информационного графа
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
   flagMLC = TRUE; // начало многострочного комментари€
   continue; // эту строку пропускаем
  }
  if( str[0] == '*' && str[1] == '/' ) // конец многострочного комментари€
  {
   flagMLC = FALSE; // начало многострочного комментари€
   continue; // эту строку пропускаем
  }
//
  if( sscanf( str, "digraph %s {", GraphName ) == 1 ) // ровно одно поле прочитано...
   flagEdges = TRUE; // начало описани€ дуг »√ј
  if( str[0] == '}' )
   flagEdges = FALSE; // конец описани€ дуг »√ј
//
//  if( flagEdges && !flagMLC )
  if( flagEdges )
   if ( !ParseStringAndAddEdges( str ) ) // оптравл€ем строку str на рвзборку дл€ пополнени€ массива дуг
    return FALSE;
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
 isEdges = TRUE ; // всЄ нормально - массив Mem_Edges[] создан
//
 c_GetCountOps(); // подсчЄт числа операторов (вершин графа) Ѕ≈« ¬’ќƒЌџ’
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
 isTiers = FALSE; // массив Tiers[][] не создан
//
 return TRUE ;
//
} // ------ конец c_ReadEdges --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall TestAndAddMemoryForEdges( INT nEdges )
{ // тестирует необходимость увеличени€ массива дуг Mem_Edges[] и при
// необходимости увеличивает его в stockMem раз. ѕри успехе возращает TRUE...
//
 if( nEdges < Max_Edges ) // пам€ти дл€ массива Mem_Edges[] достаточно...
  return TRUE;
//
// ===== пам€ти не хватает =====================================================
//
 Max_Edges *= stockMem; // захватываем в stockMem раз больше, чем было...
 Mem_Edges = ( me* ) realloc( Mem_Edges, Max_Edges * sizeof(me) ); // реаллокировали пам€ть под Mem_Edges[]...
//
 if( !Mem_Edges ) // совсем плохо - реалокировать дополнительную пам€ть не получилось..!
 {
  char str[_1024];
  snprintf(str,sizeof(str), "Ќехватка пам€ти дл€ размещени€ массива ƒ”√ (Input). «атребовано %d элементов...",
                             Max_Edges );
  MessageBeep(MB_OK); // звуковое предупреждение...
  MessageBox(0, str, "ѕредупреждение", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  isEdges = FALSE ; // массив Mem_Edges[] не создан...
  return FALSE ;
 } // конец  if( Mem_Edges == NULL )
 else
 {
  t_printf( "\n-I- ћассив ƒ”√ (Input) перераспределЄн на %d элементов -I-",  Max_Edges );
  return TRUE;
 }
//
} // ---- конец TestAndAddMemoryForEdges ---------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall ParseStringAndAddEdges( char *str )
{ // разбирает строку str, выдел€ет составл€ющих дуги номера вершин и добавл€ет их в массив дуг
// общий формат строки: a -> b -> c -> -> d ; где a,b,c,d - целые числа
// при ошибки аллокировани€ пам€ти при расширении массива дуг возращает FALSE
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
   if( !TestAndAddMemoryForEdges( nEdges ) ) // надо ли добавл€ть пам€ть дл€ Mem_Edges[] ?
    return FALSE;
  } // конец  if( sscanf( str, "%d -> %d",
 else // ровно 2 пол€ прочитать на удалось..!
  return TRUE;
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
  return TRUE;
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
  return FALSE ; // не удалось открыть...
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
 return TRUE;
} // ----- конец ReadAndPrimWorkOpsCalcsVertEdgeFiles --------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_LuaCallByTimer( char *CommandLine, INT d_Ticks )
{ // вызов Lua-операторов с задержкой d_Tick (аналог settimeout() из JS)
//
 if( d_Ticks <= 0 )
  return -1 ;
//
 bool flag = FALSE; // если в строке не только пробелы...
 for( int i=0; i<strlen(CommandLine); i++) // цикл по символам в строке CommandLine
 {
  if( CommandLine[i] != ' ')
  {
   flag = TRUE; // есть хот€ бы один не-пробел..!
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
  if( flag_Busy == TRUE ) // не окончен предыдущий вызов CallLuaThread...
  {
   tpe_printf( "\n-W- ¬ызов %s пропущен из-за неокончани€ предыдущего вызова %s... -W-",
               Mem_EV[i].CommandLine, busy_CommandLine );
   continue;  // пропускаем-c...
  }
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  
*/
 if( !L ) // если основное состо€ние L уже прекращено, ничего делать не надо - возврат...
 {
  Master_Timer->Enabled = FALSE; // остановили Master_Timer
  return;
 }
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
 flag_Busy = TRUE; // выполнение CallLuaThread нјчато..!
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
ended: flag_Busy = FALSE; // выполнение CallLuaThread закончено...
//
} // ----- конец CallLuaThread -------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_SwapOpsTierToTier(INT Op1, INT Op2)
{ // --- мен€ет местами операторы Op1 и Op2, наход€щиес€ на –ј«Ќџ’ €русах
// ----- если удалось благополучно перенести - возвращаетс€ TRUE и глобальна€ iMove
//
 if( !isTiers ) // если массива Tiers[][] ещЄ не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 INT Tier1 = c_GetTierByOp( Op1 ), // €рус нахождени€ первого из обмениваемых операторов
     Tier2 = c_GetTierByOp( Op2 ); // ...второго...
//
 if( Op1 == Op2 ||  // не желаем-с делать глупостев-с... Ќ» ј ќ√ќ ѕ≈–≈Ќќ—ј !!!
     Tier1 == Tier2 )
 {
//  DisplayMessage( "E", __FUNC__, messParams2, FALSE ); // выдать сообщение
  return TRUE ;
 }
//
 if( Tier1 == ERR_COMMON || // проверка на корректность определени€ Tier1
     Tier2 == ERR_COMMON ) // ...tier2
 {
  DisplayMessage( "E", __FUNC__, messParams1, FALSE ); // выдать сообщение
  return FALSE ;
 }
//
 if( ( Tier1 < 1 && Tier1 > nTiers ) || // с нулевого и с €руса ниже последнего перенести нельз€...
     ( Tier2 < 1 && Tier2 > nTiers ) )  // то же...
 {
  DisplayMessage( "E", __FUNC__, messParams1, FALSE ); // выдать сообщение
  return FALSE ;
 }
//
 if( ( Tier1 < c_GetMinTierMaybeOp( Op1 ) ) || // проверка допуст»мости переноса оператора Op1
     ( Tier1 > c_GetMaxTierMaybeOp( Op1 ) ) ||
     ( Tier2 < c_GetMinTierMaybeOp( Op2 ) ) || // проверка допуст»мости переноса оператора Op2
     ( Tier2 > c_GetMaxTierMaybeOp( Op2 ) ) )
 {
  DisplayMessage( "E", __FUNC__, messParams3, ERR_RANGE_IN ); // выдать сообщение
  return ERR_RANGE_IN ;
 }
//
 if( c_MoveOpTierToTier( Op1, Tier2 ) == TRUE ) // успешный перенос ќp1 на €рус нахождени€ Op2
  if( c_MoveOpTierToTier( Op2, Tier1 ) == TRUE ) // успешен перенос ќp2 на €рус нахождени€ Op1
   return TRUE ;
//
 return FALSE ;
//
} // ----- конец c_SwapOpsTierToTier -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutTimeLiveDataToTextFrame()
{ // построить и выдать в текстовое окно диаграмму жизни данных (аналог F6)
 c_CreateAndOutputDataLiveDiagrByTiers( 0, "" ); // создать и выдать в текстовое окно диаграмму времени жизни данных по текущeve Tiers[][]
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_DrawDiagrTLD()
{ // строит графическое изображение (диаграмму) времЄн жизни внутренних данных
 INT OpsOnTier,
     H_pix, B_pix, // высота и ширина области отрисовки IM1 в пикселах
     B_rect, // ширина горизонтальной полоски в пикселах
     x1,y1, x2,y2; // координаты горизонтальной полоски в пикселах
 char str[_256];
//
 if( !isTiers ) // массива Tiers[][] ещЄ нет...
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
 INT n,n1,n2,m, // n1,n2 - номера промежутков между €русами яѕ‘, m - число данных в этом промежутке
     maxM=-1e10,minM=1e10, n1x,n2x, n1n,n2n; // max данных, min данных, диапазоны €русов выше и ниже
 REAL averTLD=0.0; // средне-арифметическое времени жижниданных между €русами яѕ‘
//
 c_CreateAndOutputDataLiveDiagrByTiers( 2, "" ); // рассчитали информацию дл€ времени жизни данных по текущ. Tiers[][]
//
 sscanf( TLD->Strings[0].c_str(), "%d", &n ); // число меж-€русов в яѕ‘
//
// ищем экстремумы числа данных ------------------------------------------------
 for(INT i=1; i<=n; i++) // цикл по всем промежуткам €русов яѕ‘ дл€ поисков max/min
 {
  if( i < n ) // кроме последней строки с $
   sscanf( TLD->Strings[i].c_str(), "%d/%d|%d:", &n1,&n2,&m ); // верхний €рус / нижний €рус / число данных в этом промежутке
  else // последн€€ строка формата "n/$|m"
  {
   sscanf( TLD->Strings[i].c_str(), "%d/$|%d:", &n1,&m ); // верхний €рус / $ / число данных в этом промежутке
   n2=n1+1;
  }
//
  if( m >= maxM ) // ищем мах число живых данных
  { maxM = max(maxM,m); n1x=n1; n2x=n2; } // запомнили €рус выше | запомнили €рус ниже (избыточно вообще-то...)
//
  if( m < minM ) // ищем мin число живых данных
  { minM = min(minM,m); n1n=n1; n2n=n2; } // запомнили €рус выше | запомнили €рус ниже (избыточно вообще-то...)
//
 averTLD += (REAL)m; // суммируем дл€ получени€ средн.арифметического времени жизни данных между €русам
//
 } // конец  for(INT i=1; i<=n; i++)
//
 averTLD /= (REAL)n; // средн.арифметическое времени жизни данных между €русам
//
 REAL dH_pix = 1.0 * H_pix / n, // единица в  пикселах по высоте и ширине области отрисовки диаграммы
      dB_pix = 1.0 * B_pix / maxM;
//
 dH_pix = max( dH_pix, 1.0 ); // высота должна быть  <= 1 , иначе отрисовка невозможна...
//
 snprintf(str,sizeof(str), "H|N/W=%d|/%d/%d-%d", n,maxM,n1x,n2x ); // число лент / мах данных / €рус сверху - €рус снизу
 F2->L_OM->Caption = str;
 F2->L_OM->Repaint(); // принудительно перерисовываем
//
 for(INT i=1; i<=n; i++) // цикл по всем промежуткам €русов яѕ‘ дл€ построени€ графика
 {
//
  if( i < n ) // кроме последней строки с $
   sscanf( TLD->Strings[i].c_str(), "%d/%d|%d:", &n1,&n2,&m ); // верхний €рус / нижний €рус / число данных в этом промежутке
  else // последн€€ строка формата "n/$|m"
  {
   sscanf( TLD->Strings[i].c_str(), "%d/$|%d:", &n1,&m ); // верхний €рус / $ / число данных в этом промежутке
   n2=n1+1;
  }
//
  B_rect = dB_pix * m; // ширина горизонтальной полоски
//
// --- устанавливаем цвета графика ---------------------------------------------
  if( m == minM )
   TIM1->Canvas->Brush->Color = brush_draw_color_MIN; // цвет кисти ћ»Ќ»ћ”ћ
  else
  if( m == maxM )
   TIM1->Canvas->Brush->Color = brush_draw_color_MAX; // цвет кисти ћј —»ћ”ћ
  else
   TIM1->Canvas->Brush->Color = brush_draw_color_TLD; // цвет кисти обычный
////////////////////////////////////////////////////////////////////////////////
  x1 = 0;  // лева€ верхн€€ точка горизонтальной полоски ( Rectangle, Rect )
  y1 = dH_pix * ( i-1 );
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
 } // конец цикла  for(INT i=1; i<=n; i++)
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
  return TRUE; // всЄ успешно сделано
//
} // --- конец с_DrawDiagrTLD --------------------------------------------------


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
INT __fastcall c_CalcParamsTiers() // расчЄт статистических параметров €русов яѕ‘
{
//
 if( !isTiers ) // массива Tiers[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 REAL averWidth = ( 1.0 * nOps ) / nTiers, // средн€€ ширина по всем €русам яѕ‘ кроме ¬’ќƒЌќ√ќ (нулевого)
      sumSqWidth = 0.0 , // суммирование квадратов нев€зок
      sumOps = 0.0 , // сумма операторов по €русам  яѕ‘
      sumICL = 0.0 , // сумма дл€ коэффициента неравномерности по кривой Ћоренца
      xAxis,yAxis, xAxis_old = 0.0,yAxis_old = 0.0 ;
 INT iTier, iOp ,
     nOpsOnTier, // число операторов на €русе
     minOpsByTiers = 1000000, maxOpsByTiers = -minOpsByTiers , // минимум и максимум операторов по €русам яѕ‘
//
     sumDump = 0, sumEdges = 0 , // дл€ вычислени€ —–≈ƒЌ≈… ƒЋ»Ќџ ƒ”√»;;
     OpFrom, OpTo, nOutEdges, iOutEdge ; // ... то же ...
//
// =============================================================================
 for( iTier=1; iTier<=nTiers; iTier++ ) // по всем €русам яѕ‘
 {
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
   } // конец цикла    for( iOutEdge=1; iOutEdge<=nOutEdges; iOutEdge++ )
//
// =============================================================================
  } // конец for( iOp=1; iOp<=nOpsOnTier; iOp++ )
//
 } // конец for( iTier=1; iTier<=nTiers; iTier++ )
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
} // ----- конец c_—alcParamsTiers() -------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutParamsTiers()
{ // --- вывод основных параметров »√ј и его яѕ‘ -------------------------------
 char szOut[_4096], // строка дл€ выдачи интегрированных данных
      Delimeter[] = " \246 " ; // разделитель частей выводимых данных
// circle \225 \x0095; крест \207 \x0087; верт.лин \174 \x007c; разорв.верт.лини€ \246 \x00A6
 REAL AverWidth, // средн€€ ширина по €русам кроме первого и последнего
      SumSqWidth = 0.0, // сумма квадратов нев€зок ширины по €русам
      AverSqDevWidth = 0.0; // ср.кв.отклонение ширины €русов яѕ‘ (кроме €русов 1 и nTiers)
 INT  iOp, nOp,     iTier,     nTierMin,    nTierMax,
      Op,  dTiers,  sdOps = 0, sdTiers = 0;
//
 if( !isTiers ) // массива Tiers[][] не существует...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // выдать сообщение
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
// =============================================================================
 c_CalcParamsTiers() ; // вычисление параметров ширин €русов яѕ‘ и занесение в стр-ру StatTiers (глобал)
//
 AverWidth = StatTiers.averWidth ; // среднеарифметичеса€ ширина яѕ‘ (кроме 0-го уровн€)
//
 AverSqDevWidth = StatTiers.SD ; // сумма квадратов нев€зок
//
////////////////////////////////////////////////////////////////////////////////
//
 char szStatTiers[_256]; // данные статистики €русов яѕ‘
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
//
// === начало обработки информации о времени жизни данных между €русами яѕ‘ ====
//
 INT n,n1,n2,m, // n1,n2 - номера промежутков между €русами яѕ‘
     maxM=-1e10,minM=-maxM, // max данных, min данных
     n1x,n2x, n1n,n2n; //  диапазоны €русов выше и ниже
 REAL averTLD=0.0; // средне-арифметическое времени жизни данных между €русами яѕ‘ (≈ƒ¬)
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( !PutParamsDataLiveOnTextFrame ) // обход вычислени€ времени жизни данных
  goto calc_data_live; // ...да простит мен€ Ёдсгер ¬ибе ƒейкстра! -------------
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 c_CreateAndOutputDataLiveDiagrByTiers( 2, "" ); // создать диаграмму времени жизни данных по текущ. Tiers[][]
//
 sscanf( TLD->Strings[0].c_str(), "%d", &n ); // число промежутков €русов в яѕ‘
//
 for( INT i=1; i<=n; i++) // по числу промежутков между €русами яѕ‘
 {
  if( i < n ) // кроме последней строки с $
   sscanf( TLD->Strings[i].c_str(), "%d/%d|%d:", &n1,&n2,&m ); // верхний €рус / нижний €рус / число данных в этом промежутке
  else // последн€€ строка формата "n/$|m"
  {
   sscanf( TLD->Strings[i].c_str(), "%d/$|%d:",  &n1,&m ); // верхний €рус / $ / число данных в этом промежутке
   n2=n1+1;
  }
//
  if( m >= maxM ) // ищем мах число TLD
  { maxM = max(maxM,m); n1x=n1; n2x=n2; } // запомнили €рус выше | запомнили €рус ниже (избыточно вообще-то...)
//
  if( m < minM ) // ищем мin число TLD
  { minM = min(minM,m); n1n=n1; } // запомнили €рус выше | запомнили €рус ниже (избыточно вообще-то...)
//
  averTLD += (REAL)m; // средне-арифметическое времени жизни данных
 } // конец цикла по промежуткам между €русами яѕ‘
//
// дополнение строки информацией о времени жизни данных
//
 char szStatTLD[_512], // строка данных о времени жизни локальных данных (TLD)
      szTemp[_128] ;
//
 if( n2n == n )
  sprintf( szStatTLD,"%sTLD: min=%d(%d/%c), ", Delimeter, minM,n1n,'$' );
 else
  sprintf( szStatTLD,"%sTLD: min=%d(%d/%d), ", Delimeter, minM,n1n,n2n );
//
 if( n2x == n )
  sprintf( szTemp, "max=%d(%d/%c), ср.арифм.=%.4g", maxM,n1x,'$',averTLD / n );
 else
  sprintf( szTemp, "max=%d(%d/%d), ср.арифм.=%.4g", maxM,n1x,n2x,averTLD / n );
//
 strcat( szStatTLD, szTemp ); // подготовили строку дл€ вывода на F2
//
// === конец обработки информации о времени жижни данных между €русами яѕ‘ =====
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
calc_data_live: //проще, чем разбиратьс€ в куче фигурных скобок ----------------
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// --- вывод рассчитанных данных на форму F2 в L_GP ----------------------------
//
 char szFormat[] = // строка формата дл€ вывода данных в строку szOut ----------
"ќператоров= %d, дуг= %d, €русов= %d\
%sяѕ‘: %s\
%sоператоров на €русе/€рус (min:max)= %d/%d:%d/%d\
%sвариативность яѕ‘: Vo|Vt|Vot= %.4g|%.4g|%.4g\
%sср.арифм.длин дуг= %.4g €русов\
%s";
//
 snprintf( szOut,sizeof(szOut), szFormat, // вывод по формату szFormat в строку szOut
//
 nOps, nEdges, nTiers,
 Delimeter,
//
 szStatTiers, // данные статистики €русов яѕ‘
 Delimeter,
//
 Tiers(c_GetTierFirstMinOps(1,nTiers),0), c_GetTierFirstMinOps(1,nTiers),
 Tiers(c_GetTierFirstMaxOps(1,nTiers),0), c_GetTierFirstMaxOps(1,nTiers),
 Delimeter,
//
 (REAL)sdOps / nOps, // Vo
 (REAL)sdTiers / nOps, // Vt
 (REAL)sdOps*sdTiers / (nOps*nOps), // Vot
 Delimeter,
//
 StatTiers.AAL, // среднеарифметическа€ длина дуги
//
 szStatTLD ); // данные статистики времени жизни локальных данных (TLD)
//
 F2->L_GP->Caption = szOut; // вывод основных параметров яѕ‘ графа
 F2->L_GP->Repaint(); // принудительно перерисовываем
//
//
 strcpy( szStatTLD, "\n" );
 strcat( szStatTLD, szTemp ); // подготовили строку дл€ вывода в файл протокола
//
 if( !PutParamsDataLiveOnTextFrame ) // обход вычислени€ времени жизни данных
  strcpy( szStatTLD, "\0" );
//
// ===== вывод рассчитанных данных в протокол расчЄта (файл) ===================
//
////////////////////////////////////////////////////////////////////////////////
 ReplaceEqualLengthSubstring( szOut, Delimeter, "  \n" ) ; // замен€ем Delimeter на "^^\n"
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
 return TRUE ;
//
} // ----- конец c_PutParamsTiers ----------------------------------------------










