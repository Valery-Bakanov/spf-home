////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOpsInput()
{ // ���������� ������ ������� ������� (0-� ����) � ��� ------------------------
//
//
 if( !isEdges ) // ��� ������� Mem_Edges[]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ���� ����� nOpsInput ������� ���������� (����� nEdges ��� �����)=========
////////////////////////////////////////////////////////////////////////////////
 INT nW, iEdges, jEdges;
 bool flag;
 nOpsInput = 0; // ����� ������� ���������� (0-� ����; ����������)
//
 for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ���� ����� ������� � #1
  Edges_f(0,iEdges) =
  Edges_f(1,iEdges) = FALSE; // "����� �����" �� ���� ����������
//
// === �� ���� ����� ��� =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ��� ����� ������� � #1
   if( Edges_f(0,iEdges) == FALSE ) // ��������� ��������� ������� ���� iEdges
   {
    nW = Edges(0,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++) // �� ���� ����� ������� � #1
    {
     Edges_f(0,jEdges) = Edges(0,jEdges)==nW ? TRUE : Edges_f(0,jEdges) ; // �������� "From"
     Edges_f(1,jEdges) = Edges(1,jEdges)==nW ? TRUE : Edges_f(1,jEdges) ; // �������� "To"
    } // ����� for(jEdges=1; jEdges<=nEdges; jEdges++)
//
   flag = FALSE;
   for(jEdges=1; jEdges<=nEdges; jEdges++) // �� ���� ����� ������� � #1
    if( Edges_f(1,jEdges) && Edges(1,jEdges)==nW ) // �������� � =nW
     flag = TRUE ; // ����, nW ����������� � Edges(1,*) ..!
//
   if( !flag ) // ���� nW �� ����������� � Edges(1,*) - ��������!
    nOpsInput ++ ;
//
   } // if( Edges_f(0,iEdges) == FALSE )
//
 return nOpsInput ;
//
} // --- ����� c_GetCountOpsInput-----------------------------------------------




////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOpsOutput()
{ // ���������� ����� ������ � ��� (������ �������� ������)
//
 if( !isEdges ) // ��� ������� Mem_Edges[]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ���� ����� nOpsInput ������� ���������� (����� nEdges ��� �����)=========
////////////////////////////////////////////////////////////////////////////////
 INT nW, iEdges, jEdges;
 bool flag;
 nOpsOutput = 0; // ����� �������� ���������� (����������)
//
 for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ��� ����� ������� � #1
  Edges_f(0,iEdges) =
  Edges_f(1,iEdges) = FALSE; // ����� ����� �� ���� ����������
//
// === �� ���� ����� ��� =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ��� ����� ������� � #1
   if( !Edges_f(1,iEdges) ) // ��������� ��������� ������� ���� iEdges
   {
    nW = Edges(1,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     Edges_f(0,jEdges) = Edges(0,jEdges)==nW ? TRUE : Edges_f(0,jEdges) ; // �������� "From"
     Edges_f(1,jEdges) = Edges(1,jEdges)==nW ? TRUE : Edges_f(1,jEdges) ; // �������� "To"
    }
//
   flag = FALSE;
   for(jEdges=1; jEdges<=nEdges; jEdges++)
    if( Edges_f(0,jEdges) && Edges(0,jEdges)==nW ) // �������� � =nW
     flag = TRUE ; // ����, nW ����������� � Edges(0,*) ..!
//
   if( !flag ) // ���� nW �� ����������� � Edges(0,*) - ��������!
    nOpsOutput ++ ;
//
   } // ����� if( !Edges_f(1,iEdges) )
//
 return nOpsOutput ;
//
} // --- ����� c_GetCountOpsOutput----------------------------------------------

