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
  Edges_f(1,iEdges) = FALSE; // "сн€ли метку" со всех операторов
//
// === по всем дугам »√ј =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // по все дугам начина€ с #1
   if( Edges_f(0,iEdges) == FALSE ) // запомнили »—’ќƒяў”ё вершину дуги iEdges
   {
    nW = Edges(0,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++) // по всем дугам начина€ с #1
    {
     Edges_f(0,jEdges) = Edges(0,jEdges)==nW ? TRUE : Edges_f(0,jEdges) ; // пометили "From"
     Edges_f(1,jEdges) = Edges(1,jEdges)==nW ? TRUE : Edges_f(1,jEdges) ; // пометили "To"
    } // конец for(jEdges=1; jEdges<=nEdges; jEdges++)
//
   flag = FALSE;
   for(jEdges=1; jEdges<=nEdges; jEdges++) // по всем дугам начина€ с #1
    if( Edges_f(1,jEdges) && Edges(1,jEdges)==nW ) // помечено и =nW
     flag = TRUE ; // итак, nW встречаетс€ в Edges(1,*) ..!
//
   if( !flag ) // если nW Ќ≈ ¬—“–≈„ј≈“—я в Edges(1,*) - подходит!
    nOpsInput ++ ;
//
   } // if( Edges_f(0,iEdges) == FALSE )
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
 for(iEdges=1; iEdges<=nEdges; iEdges++) // по все дугам начина€ с #1
  Edges_f(0,iEdges) =
  Edges_f(1,iEdges) = FALSE; // сн€ли метку со всех операторов
//
// === по всем дугам »√ј =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // по все дугам начина€ с #1
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
   } // конец if( !Edges_f(1,iEdges) )
//
 return nOpsOutput ;
//
} // --- конец c_GetCountOpsOutput----------------------------------------------

