//
//==============================================================================
//
TStringList *ListVarOps = new( TStringList ) ; // список операторов с ненулевой вариативностью
//
bool __fastcall c_FindAllVarOps(); // най и запомнить в ListVarOps все операторы с ненулевой вариативностью
bool __fastcall c_RecursiveCalcTotalCountSPF( INT n, int Rule );  // рекурсивно вычисляет общее число рассатриваемых ЯПФ
bool __fastcall c_RecursiveCalcParamsSPF( INT n ); // рекурсивно вызывает c_CalcParamsSPF
void __fastcall c_CalcParamsSPF( INT Op, INT toTier ); // вычисляет параметры ЯПФ после перемещения оператора Op на ярус toTier
INT  __fastcall c_BruteForce_SPF( bool RuleTiers, bool RuleTierParameters, bool RuleGraph, INT RuleFreqOut ); // прототипы функций
//
TDateTime startDT, currDT, dt; // момент старта программы, текущий момент и промежуток времени
__int64 iSPF, nSPF, // счётчик рассмотренных вариантов / всего ЯПФ
        i_min_CV, i_max_CV; // варианты SPF, соответствующие min / max ЯПФ
REAL min_CV, max_CV; // min и max CV по рассмотренным ЯПФ
int RuleTiersRange = 0, RuleTiersOut = 0, RuleTierParameters = 0, RuleGraph = 0, RuleTopDown = 0;
INT RuleFreqLineVarOps = 0, RuleFreqVarOps = 0; // режим выдачи данных (предварительно и в режиме вЫдачи)
//
#define PRINT_AND_RECURSE /* выдача + рекурсивный вызов */ \
{ /* начало #define PRINT_AND_RECURSE / начало блока for( i=... ) */ \
if( flagHook ) /* пользователем выдан запрос на останов программы */ \
   return false ; \
/* */ \
  APM /* ------------------------------------------------------------------------ */ \
  iSPF ++ ; \
  c_CalcParamsSPF( Op, i ) ; /* вычисление параметров iSPF-той ЯПФ (после перемещения оператора Op на ярус i ) */ \
/* */ \
  if( n+1 <= ListVarOps->Count-1 ) /* ... пока ещё есть строки в ListVarOps */ \
   c_RecursiveCalcParamsSPF( n+1 ) ; /* рекурсивный вызов (следующая строка ListVarOps) */ \
} /* конец #define PRINT_AND_RECURSE / конец блока for( i=... ) */
//

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_FindAllVarOps()
{ // находит и сохраняет в ListVarOps все операторы, обладающие ненулевой вариативностью
// при отсутствии обладающих вариативностью операторов возвращает false, иначе true
 INT iTier, jOp, Op, min_T, max_T;
 char tmpStr[_256]="\0";
//
 for( iTier=1; iTier<=nTiers; iTier++ ) // по всем ярусам ЯПФ (кроме нулевого)
  for( jOp=1; jOp<=c_GetCountOpsOnTier(iTier); jOp++ ) // по операторам на ярусе iTier
  {
   Op = c_GetOpByNumbOnTier(jOp,iTier); // получить реальный номер оператора по его положению на ярусе
//
   if( !RuleTiersRange ) // диапазон ярусов вычисляется
   {
    min_T = c_GetMinTierMaybeOp( Op ); // min / max ярус для вариативности оператора Op
    max_T = c_GetMaxTierMaybeOp( Op );
   }
   else // дапазон ярусов принимается равным высоте ЯПФ
   {
    min_T = 1;
    max_T = nTiers ;
   }
//
   if( max_T > min_T ) // вариативность ненулевая..!
   {
    sprintf( tmpStr, "%60d%60d%60d", Op,min_T,max_T ); // запомним в строке для добавления в ListVarOps
    ListVarOps->Add( tmpStr ); // добавили..
   }
//
  } // конец цикла по jOp,iTier
//
 if( !ListVarOps->Count ) // ни одного оператора с ненулевой вариативностью нет !
  return false ;
//
 t_printf( "\nОператоры с ненулевой вариативностью (количество: %d)\n"
             "===============================================\n", ListVarOps->Count ) ;
//
 for( INT i=0; i<ListVarOps->Count; i++ ) // по всем строкам ListVarOps
 {
  sscanf( ListVarOps->Strings[i].c_str(), "%60d%60d%60d", &Op,&min_T,&max_T ) ; // прочитали n-ю строку ListVarOps
  t_printf( "#%d Op= #%d T_min/max: %d/%d [%d]", i+1, Op, min_T,max_T, max_T-min_T+1 ); // отладочная печать
 }
//
 return true ;
//
} // -------------- конец c_FindAllVarOps --------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_RecursiveCalcTotalCountSPF( INT n )
{ // рекурсивно (по строкам ListVarOps) вычисляем общее число анализируемых ЯПФ
// Rule управляет подробностями вЫдачи данных об ЯПФ (см. ниже)
// возвращает false при останове пользователем и true при нормальном завершении
 INT Op,min_T,max_T ;
//
 sscanf( ListVarOps->Strings[n].c_str(), "%60d%60d%60d", &Op,&min_T,&max_T ) ; // прочитали n-ю  строку ListVarOps
//
 for( INT i=min_T; i<=max_T; i++ ) // по всему диапазону min_T - max_T
 {
  if( flagHook ) // пользователем выдан запрос на останов программы
   return false ;
//
  APM //------------------------------------------------------------------------
  nSPF ++ ;
//
  if( RuleFreqLineVarOps >= 1 && // выдача данных только при >=0 "и"
     ( !( nSPF % RuleFreqLineVarOps ) || // выдача каждых RuleFreqLineVarOps строк "или"
         nSPF==1 ) ) // выдать обязательно первую строку
  {
   Delay( 1 ); // дать поработать Windows в течение 1 миллисекунды
   t_printf( "line_VarOp= #%d i= %d T_min/max: %d/%d [%d]  #%Ld",
              n,i, min_T,max_T, max_T-min_T+1, nSPF ) ; // отладочная печать
  }
//
  if( n+1 <= ListVarOps->Count-1 ) // ... пока ещё есть строки в ListVarOps
   c_RecursiveCalcTotalCountSPF( n+1 ) ; // рекурсивный вызов (следующая строка ListVarOps)
 } // конец цикла по i \
 //
 return true ;
//
} // -------------- конец c_CalcTotalCountSPF ----------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_RecursiveCalcParamsSPF( INT n )
{ // рекурсивно (по ListVarOps) вычисляем параметры текущей  ЯПФ
// возвращает false при останове пользователем и true при нормальном завершении
 INT Op, min_T, max_T, i ;
//
 sscanf( ListVarOps->Strings[n].c_str(), "%60d%60d%60d", &Op,&min_T,&max_T ) ; // прочитали n-ю  строку ListVarOps
//
 if( !RuleTopDown ) // при =0 перебор операторов с var#0 идёт "снизу вверх"
  for( i=max_T; i>=min_T; i-- ) // по всему диапазону max_T - min_T снизу вверх по ярусам
   PRINT_AND_RECURSE
 else // ... RuleTopDown#0 ...
  for( i=min_T; i<=max_T; i++ ) // по всему диапазону min_T - max_T сверху вниз по ярусам
   PRINT_AND_RECURSE
//
 return true ;
//
} // -------------- конец c_RecursiveCalcParamsSPF -----------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall c_CalcParamsSPF( INT Op, INT toTier )
{ // вычисляет параметры ЯПФ после перемещения оператора Op на ярус toTier
//
 if( c_MoveOpTierToTier( Op, toTier ) != RETURN_OK ) // неудачная попытка перемещения..!
 {
  Delay( 1 ); // дать поработать Windows в течение 1 миллисекунды
  t_printf( "- В перемещении #%Ld (из #%Ld) - оператор #%d  (%d:%d/%d) на ярус #%d отказано...",
             iSPF, nSPF, Op,
             c_GetTierByOp( Op ), c_GetMinTierMaybeOp( Op ), c_GetMaxTierMaybeOp( Op ),
             toTier ) ;
  return ;
 }
//
// ниже вывод ЯПФ, визуализация etc etc...
//
 c_CalcParamsTiers() ; // вычисляем параметры текущей ЯПФ
 REAL CV = StatTiers.CV ; // рассчитали CV
//
 if( CV <= min_CV ) // фиксируем min_CV (последнее по встречАемости)
 { min_CV = CV ; i_min_CV = iSPF ; }
//
 if( CV >= max_CV ) // фиксируем max_CV  (последнее по встречАемости)
 { max_CV = CV ; i_max_CV = iSPF ; }
//
 dt = TDateTime::CurrentDateTime() - startDT ; // прошедшее с момента startDT время
//
 if( RuleFreqVarOps >= 1 && // выдача данных только при >=0 "и"
     ( !( iSPF % RuleFreqVarOps ) || // выдача каждых RuleFreqVarOps строк "или"
         iSPF == 1 || iSPF == nSPF ) ) // выдать обязательно первую и последнюю строки (для анализа min / max)
  {
   Delay( 1 ); // дать поработать Windows в течение 1 миллисекунды
   t_printf( "+ ЯПФ #%Ld (из #%Ld, выполнено: %.1f%%, прошло: %s ч:м:с), выс.= %d, шир.= %.0f "
             "(ср-а.шир.= %.2f), ср-а.дуг= %.3g, CV= %.3g (%.3g:%Ld/%.3g:%Ld)",
             iSPF,nSPF, 1e2*iSPF/nSPF, dt.FormatString("h:n:s").c_str(), nTiers, StatTiers.MaxOpsByTiers,
             StatTiers.averWidth, StatTiers.AAL, CV, min_CV,i_min_CV, max_CV,i_max_CV ) ;
  }
//  t_printf( "---%d---", strlen(F2->M1->Lines->Text.c_str()) ); // отладочная печать
//
 if( RuleTiersOut ) // вывод ЯПФ
 {
  c_PutTiersToTextFrame() ; // выдать ЯПФ по ярусам в текстовое окно
  t_printf( "\n\n" ) ;
 }
//
 if( RuleTierParameters ) // вывод параметров ЯПФ
  c_PutParamsTiers() ; // выдать параметры ЯПФ в нижнюю часть текстового окна
//
 if( RuleGraph ) // вывод графика
 {
  c_ClearDiagrArea() ; // очистить область линейчатого графика
  c_DrawDiagrTiers() ; // построить линейчатый график ширин ярусов ЯПФ
 }
//
} // -------------- конец c_CalcParamsSPF --------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_BruteForce_SPF( int RuleTiersRange, int RuleTiers, int RuleTierParameters,
                                 int RuleGraph,      int RuleTopDown,
                                 INT RuleFreqLineVarOps, INT RuleFreqVarOps )
{ // силовой перебор всех допустимых сочетаний операторов по ярусам ЯПФ из ИГА-файла FileName
 INT iTier, jOp, Op;
//
 if( !flagExistsTiers ) // массив Tiers[][] ещё не существует - выходим с ошибкой
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_EDGES ); // выдать сообщение
  return ERR_NOT_MASSIVE_EDGES ;
 }
// ----- присвАивание формальных параметров глобальным переменным --------------
 ::RuleTiersRange     = RuleTiersRange; // 0/#0 - диапазон вариативности вычисляется или принимается равным высоте ЯПФ
 ::RuleTiersOut       = RuleTiersOut; // 0/#0 - выдавать ли  ЯПФ по ярусам
 ::RuleTierParameters = RuleTierParameters; // 0/#0 - выдача параметров ЯПФ в нижнюю часть текстового окна
 ::RuleGraph          = RuleGraph; // 0/#0 - выдача линейчатого графика ширин ярусов ЯПФ;
 ::RuleTopDown        = RuleTopDown; // 0/#0 - перебор операторов с var#0 "снизу вверх" / "сверху вниз"
 ::RuleFreqLineVarOps = RuleFreqLineVarOps; // 0/NNN - не выдавать / выдавать каждые NNN строки вариантов строки операторов с var#0
 ::RuleFreqVarOps     = RuleFreqVarOps;  // 0/NNN - не выдавать / выдавать каждые NNN строки вариантов  с вариативностью ЯПФ
////////////////////////////////////////////////////////////////////////////////
 c_CalcParamsTiers() ; // параметры текущей ЯПФ
 t_printf( "\nЗаданная ЯПФ: выс.= %d, шир.= %.0f (ср-а.шир.= %.2f), ср-а.дуг= %.3g, CV= %.3g",
           nTiers, StatTiers.MaxOpsByTiers, StatTiers.averWidth,
           StatTiers.AAL, StatTiers.CV ); // параметры внесённой на обработку ЯПФ
//
 ListVarOps->Clear() ; // очистили перед началом работы
////////////////////////////////////////////////////////////////////////////////
 if( !c_FindAllVarOps() ) // первонач.нахожд. и запомин. в ListVarOps всех операторов с ненулевой вариативностью
 {
  t_printf( "\nВ заданной ЯПФ нет ни одного оператора с ненулевой вариативностью. Конец работы...\n" ) ;
  goto ended ;
 }
//
 startDT = TDateTime::CurrentDateTime() ;
 t_printf( "\nНачало работы: %s\n", startDT.FormatString("dd'/'mm'/'yyyy hh:nn:ss").c_str() ) ;
////////////////////////////////////////////////////////////////////////////////
 if( RuleFreqLineVarOps >= 1 )
  t_printf( "Варианты ЯПФ:\n=============\n" );
 nSPF = 0 ; // обнуляем в начале
 if( !c_RecursiveCalcTotalCountSPF( 0 ) ) // рекурсивно подсчитываем общее число ЯПФ для последующего анализа
 {
  t_printf( "\nВыполнение остановлено пользователем (1). Конец работы...\n" ) ;
  goto ended ;
 }
////////////////////////////////////////////////////////////////////////////////
  t_printf( "\nОператоров с вариативностью: #%d, вариантов ЯПФ: #%Ld\n"
            "==================================================\n",
             ListVarOps->Count, nSPF ) ;
//
 min_CV =  1.0e12; // инициализация переменных для min и max CV по рассмотренным ЯПФ
 max_CV = -1.0e12;
 iSPF = 0 ; // обнуляем в начале
 if( !c_RecursiveCalcParamsSPF( 0 ) ) // рекурсивно вызываем c_CalcParamsSPF для анализа конкретной ЯПФ
 {
  t_printf( "\nВыполнение остановлено пользователем (2). Конец работы...\n" ) ;
  goto ended ;
 }
//
ended: // конец работы программы...
//
 ListVarOps->Clear() ; // очистили в конце работы
//
 t_printf( "\nКонец работы: %s\n", TDateTime::CurrentDateTime().FormatString("dd'/'mm'/'yyyy hh:nn:ss").c_str() );
//
} // ------- конец c_BruteForce_SPF --------------------------------------------















