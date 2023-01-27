//
//==============================================================================
//
TStringList *ListVarOps = new( TStringList ) ; // ������ ���������� � ��������� ��������������
//
bool __fastcall c_FindAllVarOps(); // ��� � ��������� � ListVarOps ��� ��������� � ��������� ��������������
bool __fastcall c_RecursiveCalcTotalCountSPF( INT n, int Rule );  // ���������� ��������� ����� ����� �������������� ���
bool __fastcall c_RecursiveCalcParamsSPF( INT n ); // ���������� �������� c_CalcParamsSPF
void __fastcall c_CalcParamsSPF( INT Op, INT toTier ); // ��������� ��������� ��� ����� ����������� ��������� Op �� ���� toTier
INT  __fastcall c_BruteForce_SPF( bool RuleTiers, bool RuleTierParameters, bool RuleGraph, INT RuleFreqOut ); // ��������� �������
//
TDateTime startDT, currDT, dt; // ������ ������ ���������, ������� ������ � ���������� �������
__int64 iSPF, nSPF, // ������� ������������� ��������� / ����� ���
        i_min_CV, i_max_CV; // �������� SPF, ��������������� min / max ���
REAL min_CV, max_CV; // min � max CV �� ������������� ���
int RuleTiersRange = 0, RuleTiersOut = 0, RuleTierParameters = 0, RuleGraph = 0, RuleTopDown = 0;
INT RuleFreqLineVarOps = 0, RuleFreqVarOps = 0; // ����� ������ ������ (�������������� � � ������ ������)
//
#define PRINT_AND_RECURSE /* ������ + ����������� ����� */ \
{ /* ������ #define PRINT_AND_RECURSE / ������ ����� for( i=... ) */ \
if( flagHook ) /* ������������� ����� ������ �� ������� ��������� */ \
   return false ; \
/* */ \
  APM /* ------------------------------------------------------------------------ */ \
  iSPF ++ ; \
  c_CalcParamsSPF( Op, i ) ; /* ���������� ���������� iSPF-��� ��� (����� ����������� ��������� Op �� ���� i ) */ \
/* */ \
  if( n+1 <= ListVarOps->Count-1 ) /* ... ���� ��� ���� ������ � ListVarOps */ \
   c_RecursiveCalcParamsSPF( n+1 ) ; /* ����������� ����� (��������� ������ ListVarOps) */ \
} /* ����� #define PRINT_AND_RECURSE / ����� ����� for( i=... ) */
//

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_FindAllVarOps()
{ // ������� � ��������� � ListVarOps ��� ���������, ���������� ��������� ��������������
// ��� ���������� ���������� �������������� ���������� ���������� false, ����� true
 INT iTier, jOp, Op, min_T, max_T;
 char tmpStr[_256]="\0";
//
 for( iTier=1; iTier<=nTiers; iTier++ ) // �� ���� ������ ��� (����� ��������)
  for( jOp=1; jOp<=c_GetCountOpsOnTier(iTier); jOp++ ) // �� ���������� �� ����� iTier
  {
   Op = c_GetOpByNumbOnTier(jOp,iTier); // �������� �������� ����� ��������� �� ��� ��������� �� �����
//
   if( !RuleTiersRange ) // �������� ������ �����������
   {
    min_T = c_GetMinTierMaybeOp( Op ); // min / max ���� ��� ������������� ��������� Op
    max_T = c_GetMaxTierMaybeOp( Op );
   }
   else // ������� ������ ����������� ������ ������ ���
   {
    min_T = 1;
    max_T = nTiers ;
   }
//
   if( max_T > min_T ) // ������������� ���������..!
   {
    sprintf( tmpStr, "%60d%60d%60d", Op,min_T,max_T ); // �������� � ������ ��� ���������� � ListVarOps
    ListVarOps->Add( tmpStr ); // ��������..
   }
//
  } // ����� ����� �� jOp,iTier
//
 if( !ListVarOps->Count ) // �� ������ ��������� � ��������� �������������� ��� !
  return false ;
//
 t_printf( "\n��������� � ��������� �������������� (����������: %d)\n"
             "===============================================\n", ListVarOps->Count ) ;
//
 for( INT i=0; i<ListVarOps->Count; i++ ) // �� ���� ������� ListVarOps
 {
  sscanf( ListVarOps->Strings[i].c_str(), "%60d%60d%60d", &Op,&min_T,&max_T ) ; // ��������� n-� ������ ListVarOps
  t_printf( "#%d Op= #%d T_min/max: %d/%d [%d]", i+1, Op, min_T,max_T, max_T-min_T+1 ); // ���������� ������
 }
//
 return true ;
//
} // -------------- ����� c_FindAllVarOps --------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_RecursiveCalcTotalCountSPF( INT n )
{ // ���������� (�� ������� ListVarOps) ��������� ����� ����� ������������� ���
// Rule ��������� ������������� ������ ������ �� ��� (��. ����)
// ���������� false ��� �������� ������������� � true ��� ���������� ����������
 INT Op,min_T,max_T ;
//
 sscanf( ListVarOps->Strings[n].c_str(), "%60d%60d%60d", &Op,&min_T,&max_T ) ; // ��������� n-�  ������ ListVarOps
//
 for( INT i=min_T; i<=max_T; i++ ) // �� ����� ��������� min_T - max_T
 {
  if( flagHook ) // ������������� ����� ������ �� ������� ���������
   return false ;
//
  APM //------------------------------------------------------------------------
  nSPF ++ ;
//
  if( RuleFreqLineVarOps >= 1 && // ������ ������ ������ ��� >=0 "�"
     ( !( nSPF % RuleFreqLineVarOps ) || // ������ ������ RuleFreqLineVarOps ����� "���"
         nSPF==1 ) ) // ������ ����������� ������ ������
  {
   Delay( 1 ); // ���� ���������� Windows � ������� 1 ������������
   t_printf( "line_VarOp= #%d i= %d T_min/max: %d/%d [%d]  #%Ld",
              n,i, min_T,max_T, max_T-min_T+1, nSPF ) ; // ���������� ������
  }
//
  if( n+1 <= ListVarOps->Count-1 ) // ... ���� ��� ���� ������ � ListVarOps
   c_RecursiveCalcTotalCountSPF( n+1 ) ; // ����������� ����� (��������� ������ ListVarOps)
 } // ����� ����� �� i \
 //
 return true ;
//
} // -------------- ����� c_CalcTotalCountSPF ----------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_RecursiveCalcParamsSPF( INT n )
{ // ���������� (�� ListVarOps) ��������� ��������� �������  ���
// ���������� false ��� �������� ������������� � true ��� ���������� ����������
 INT Op, min_T, max_T, i ;
//
 sscanf( ListVarOps->Strings[n].c_str(), "%60d%60d%60d", &Op,&min_T,&max_T ) ; // ��������� n-�  ������ ListVarOps
//
 if( !RuleTopDown ) // ��� =0 ������� ���������� � var#0 ��� "����� �����"
  for( i=max_T; i>=min_T; i-- ) // �� ����� ��������� max_T - min_T ����� ����� �� ������
   PRINT_AND_RECURSE
 else // ... RuleTopDown#0 ...
  for( i=min_T; i<=max_T; i++ ) // �� ����� ��������� min_T - max_T ������ ���� �� ������
   PRINT_AND_RECURSE
//
 return true ;
//
} // -------------- ����� c_RecursiveCalcParamsSPF -----------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall c_CalcParamsSPF( INT Op, INT toTier )
{ // ��������� ��������� ��� ����� ����������� ��������� Op �� ���� toTier
//
 if( c_MoveOpTierToTier( Op, toTier ) != RETURN_OK ) // ��������� ������� �����������..!
 {
  Delay( 1 ); // ���� ���������� Windows � ������� 1 ������������
  t_printf( "- � ����������� #%Ld (�� #%Ld) - �������� #%d  (%d:%d/%d) �� ���� #%d ��������...",
             iSPF, nSPF, Op,
             c_GetTierByOp( Op ), c_GetMinTierMaybeOp( Op ), c_GetMaxTierMaybeOp( Op ),
             toTier ) ;
  return ;
 }
//
// ���� ����� ���, ������������ etc etc...
//
 c_CalcParamsTiers() ; // ��������� ��������� ������� ���
 REAL CV = StatTiers.CV ; // ���������� CV
//
 if( CV <= min_CV ) // ��������� min_CV (��������� �� �������������)
 { min_CV = CV ; i_min_CV = iSPF ; }
//
 if( CV >= max_CV ) // ��������� max_CV  (��������� �� �������������)
 { max_CV = CV ; i_max_CV = iSPF ; }
//
 dt = TDateTime::CurrentDateTime() - startDT ; // ��������� � ������� startDT �����
//
 if( RuleFreqVarOps >= 1 && // ������ ������ ������ ��� >=0 "�"
     ( !( iSPF % RuleFreqVarOps ) || // ������ ������ RuleFreqVarOps ����� "���"
         iSPF == 1 || iSPF == nSPF ) ) // ������ ����������� ������ � ��������� ������ (��� ������� min / max)
  {
   Delay( 1 ); // ���� ���������� Windows � ������� 1 ������������
   t_printf( "+ ��� #%Ld (�� #%Ld, ���������: %.1f%%, ������: %s �:�:�), ���.= %d, ���.= %.0f "
             "(��-�.���.= %.2f), ��-�.���= %.3g, CV= %.3g (%.3g:%Ld/%.3g:%Ld)",
             iSPF,nSPF, 1e2*iSPF/nSPF, dt.FormatString("h:n:s").c_str(), nTiers, StatTiers.MaxOpsByTiers,
             StatTiers.averWidth, StatTiers.AAL, CV, min_CV,i_min_CV, max_CV,i_max_CV ) ;
  }
//  t_printf( "---%d---", strlen(F2->M1->Lines->Text.c_str()) ); // ���������� ������
//
 if( RuleTiersOut ) // ����� ���
 {
  c_PutTiersToTextFrame() ; // ������ ��� �� ������ � ��������� ����
  t_printf( "\n\n" ) ;
 }
//
 if( RuleTierParameters ) // ����� ���������� ���
  c_PutParamsTiers() ; // ������ ��������� ��� � ������ ����� ���������� ����
//
 if( RuleGraph ) // ����� �������
 {
  c_ClearDiagrArea() ; // �������� ������� ����������� �������
  c_DrawDiagrTiers() ; // ��������� ���������� ������ ����� ������ ���
 }
//
} // -------------- ����� c_CalcParamsSPF --------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_BruteForce_SPF( int RuleTiersRange, int RuleTiers, int RuleTierParameters,
                                 int RuleGraph,      int RuleTopDown,
                                 INT RuleFreqLineVarOps, INT RuleFreqVarOps )
{ // ������� ������� ���� ���������� ��������� ���������� �� ������ ��� �� ���-����� FileName
 INT iTier, jOp, Op;
//
 if( !flagExistsTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
// ----- ������������ ���������� ���������� ���������� ���������� --------------
 ::RuleTiersRange     = RuleTiersRange; // 0/#0 - �������� ������������� ����������� ��� ����������� ������ ������ ���
 ::RuleTiersOut       = RuleTiersOut; // 0/#0 - �������� ��  ��� �� ������
 ::RuleTierParameters = RuleTierParameters; // 0/#0 - ������ ���������� ��� � ������ ����� ���������� ����
 ::RuleGraph          = RuleGraph; // 0/#0 - ������ ����������� ������� ����� ������ ���;
 ::RuleTopDown        = RuleTopDown; // 0/#0 - ������� ���������� � var#0 "����� �����" / "������ ����"
 ::RuleFreqLineVarOps = RuleFreqLineVarOps; // 0/NNN - �� �������� / �������� ������ NNN ������ ��������� ������ ���������� � var#0
 ::RuleFreqVarOps     = RuleFreqVarOps;  // 0/NNN - �� �������� / �������� ������ NNN ������ ���������  � �������������� ���
////////////////////////////////////////////////////////////////////////////////
 c_CalcParamsTiers() ; // ��������� ������� ���
 t_printf( "\n�������� ���: ���.= %d, ���.= %.0f (��-�.���.= %.2f), ��-�.���= %.3g, CV= %.3g",
           nTiers, StatTiers.MaxOpsByTiers, StatTiers.averWidth,
           StatTiers.AAL, StatTiers.CV ); // ��������� �������� �� ��������� ���
//
 ListVarOps->Clear() ; // �������� ����� ������� ������
////////////////////////////////////////////////////////////////////////////////
 if( !c_FindAllVarOps() ) // ��������.������. � �������. � ListVarOps ���� ���������� � ��������� ��������������
 {
  t_printf( "\n� �������� ��� ��� �� ������ ��������� � ��������� ��������������. ����� ������...\n" ) ;
  goto ended ;
 }
//
 startDT = TDateTime::CurrentDateTime() ;
 t_printf( "\n������ ������: %s\n", startDT.FormatString("dd'/'mm'/'yyyy hh:nn:ss").c_str() ) ;
////////////////////////////////////////////////////////////////////////////////
 if( RuleFreqLineVarOps >= 1 )
  t_printf( "�������� ���:\n=============\n" );
 nSPF = 0 ; // �������� � ������
 if( !c_RecursiveCalcTotalCountSPF( 0 ) ) // ���������� ������������ ����� ����� ��� ��� ������������ �������
 {
  t_printf( "\n���������� ����������� ������������� (1). ����� ������...\n" ) ;
  goto ended ;
 }
////////////////////////////////////////////////////////////////////////////////
  t_printf( "\n���������� � ��������������: #%d, ��������� ���: #%Ld\n"
            "==================================================\n",
             ListVarOps->Count, nSPF ) ;
//
 min_CV =  1.0e12; // ������������� ���������� ��� min � max CV �� ������������� ���
 max_CV = -1.0e12;
 iSPF = 0 ; // �������� � ������
 if( !c_RecursiveCalcParamsSPF( 0 ) ) // ���������� �������� c_CalcParamsSPF ��� ������� ���������� ���
 {
  t_printf( "\n���������� ����������� ������������� (2). ����� ������...\n" ) ;
  goto ended ;
 }
//
ended: // ����� ������ ���������...
//
 ListVarOps->Clear() ; // �������� � ����� ������
//
 t_printf( "\n����� ������: %s\n", TDateTime::CurrentDateTime().FormatString("dd'/'mm'/'yyyy hh:nn:ss").c_str() );
//
} // ------- ����� c_BruteForce_SPF --------------------------------------------















