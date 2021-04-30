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
//#define strcat(dest,src) strncat(dest,src,sizeof(dest)-strlen(dest)-5) // ���������� ���������� src � dest
//
#define strEndZero(s) s[strlen(s)]='\0' // ���������� '\0' � ����� ������ str
//
#define strNcpy(d,s)  strncpy(d,s,sizeof(d)) // ���������� �����������
//
////////////////////////////////////////////////////////////////////////////////
// ���� API_func.cpp ===========================================================
////////////////////////////////////////////////////////////////////////////////
// ����� ������� API �� � ���������� � "c_"; �������������� ������� � Lua ����������� �� �����
////////////////////////////////////////////////////////////////////////////////
//#define TEST_PRINT // ���� ���������� - �������� ������
////////////////////////////////////////////////////////////////////////////////
//
#define APM Application->ProcessMessages(); // ���� ���������� Windows ---------
//
////////////////////////////////////////////////////////////////////////////////
//
INT  __fastcall c_CreateAndOutputDataLiveDiagrByTiers( int Rule, char FileName[] ); // ������������ � ������� ��������� ����� ���������� ������ � ���
INT  __fastcall c_PutTLDToTextFrame(); // ������ ��������� ������� ����� ������ � ��������� ����
INT  __fastcall c_SaveTLD( char FileName[] ); // ������ ��������� ������� ����� ������ � ����
//
INT  __fastcall c_GetCountTiers(); // ���������� ����� ����� ������ � ��� ��������������� ����� ��������� (���)
INT  __fastcall c_AddTier(INT Tier); // ������ (������) ���� ���� ����� Tier
INT  __fastcall c_DelTier(INT Tier); // ���������� (������) ���� Tier
//
INT  __fastcall c_GetTierFirstMinOps(INT Tier1, INT Tier2); // ���������� ������ #����� � MIN �� ������ Tier1-Tier2 ������ ����������
INT  __fastcall c_GetTierLastMinOps(INT Tier1, INT Tier2); // ���������� ��������� #����� � MIN �� ������ Tier1-Tier2 ������ ����������
INT  __fastcall c_GetTierFirstMaxOps(INT Tier1, INT Tier2); // ���������� ������ #����� � MAX �� ������ Tier1-Tier2 ������ ����������
INT  __fastcall c_GetTierLastMaxOps(INT Tier1, INT Tier2); // ���������� ��������� #����� � MAX �� ������ Tier1-Tier2 ������ ����������
//
INT  __fastcall c_GetCountOpsOnTier(INT Tier); // ���������� ���������� ���������� �� ����� Tier
INT  __fastcall c_GetOpByNumbOnTier(INT Numb, INT Tier); // ���������� ����� ��������� �� ��� ������ Numb �� ����� Tier
//
INT  __fastcall c_PutTiersToTextFrame(); // ����� ��� (������ Tiers[][]) � ���� ��� ������������
bool __fastcall c_AddLineToTextFrame(char *str); // ��������� ������ � ���� ���������� �������������
bool __fastcall c_ClearTextFrame(); // ������� ����  ���������� �������������
//
INT  __fastcall c_GetMaxTierMaybeOp(INT Op); // ���������� MAX ����� �����, �� ������� ����� ������������� �������� Op
INT  __fastcall c_GetMinTierMaybeOp(INT Op); // ���������� MIN ����� �����, �� ������� ����� ������������� �������� Op
INT  __fastcall c_MoveOpTierToTier(INT Op, INT toTier); // ��������� �������� Op �� ���� toTier
INT  __fastcall c_SwapOpsTierToTier(INT Op1, INT Op2); // ����� ����� ����������� Op1 � Op2
//
INT  __fastcall c_GetOpsMoves(); // ���������� ������� �������� ����� ����������� ���������� � ����� �� ���� return nMoves ;
INT  __fastcall c_CountMovesZeroing(); // �������� �������� �������� ����� ����������� ���������� � ����� �� ���� ���
//
INT  __fastcall c_PutEdgesToTextFrame(); // ����� ������ ��� Mem_Edges[] � ���� ��� ������������
bool __fastcall c_DelayMS(INT Sec); // ��� Sec �����-������, ����� ��� ���� ���������� Windows
bool __fastcall c_SoundPlay(char str[]); // ����������� ������� �� ��������� �����
//
INT  __fastcall c_GetCountOpsInput(); // ���������� ����� ������ � ��� � �������� �������
INT  __fastcall c_GetNumbOpInput(); // ���������� Numb-�� ������� � ��� � �������� �������
//
INT  __fastcall c_GetCountOpsOutput(); // ���������� ����� ������ � ��� � ��������� �������
INT  __fastcall c_GetNumbOpOutput(); // ���������� Numb-�� ������� � ��� � ��������� �������
//
INT  __fastcall c_GetCountOps(); // ���������� ����� ������ � ��� ��� ������� ������
INT  __fastcall c_GetNumbOp(INT Numb); // ����� ����� ��������� �� ������ ��� ������������� � ����� ��� ��� (�������� �������)
//
INT  __fastcall c_GetCountEdges(); // ���������� ����� ����� ��� � �������������� ����� ��������� (���)
INT  __fastcall c_GetTierByOp(INT Op); // ������� ����� ����� �� ������ ���������
//
INT  __fastcall c_GetCountInEdgesByOp(INT Op); // ������� ����� ���, �������� � �������� Op
INT  __fastcall c_GetCountOutEdgesByOp(INT Op); // ������� ����� ���, ���������� �� ��������� Op
INT  __fastcall c_GetNumbInEdgeByOp(INT Numb, INT Op); // ������� #����., ������������ �� Numb �������� � Op ����
INT  __fastcall c_GetNumbOutEdgeByOp(INT Numb,INT Op); // ������� #����., ������������ �� Numb ��������� �� Op ����
//
bool __fastcall c_ReadEdges(char FileName[]); // ������ �� FileName ���� �������� �����
bool __fastcall c_SaveEdges(char FileName[]); // ����� � FileName ��� �������� ����� + Tiers[0/nTiers][*]
bool __fastcall c_ReadTiers(char FileName[]); // ������ �� FileName ��� �����
bool __fastcall c_SaveTiers(char FileName[]); // ����� � FileName ��� �����
//
INT  __fastcall c_SaveTiersVizu(char FileName[]); // ���������� ����� ���������� �� ������
INT  __fastcall c_SaveEdgesVizu(char FileName[]); // ���������� ����� ������������ (���) ����������
INT  __fastcall c_SaveInOutOpVizu(char FileName[]); // ���������� ����� �������� � ��������� ��� ��� ��������� Op
INT  __fastcall c_SaveParamsVizu(char FileName[]); // ��������� ����� - �������� GetParamsGraph()
//
//------------------------------------------------------------------------------
//
bool __fastcall c_IsOpExistOnTier(INT Op, INT Tier); // ������������ �� �������� Op �� ����� Tier
bool __fastcall c_IsOpDependOnlyAboveTiers(INT toOp, INT Tier); // ������� �� toOp �� ���������� �� ����������� ������
INT  __fastcall c_IsOpsHaveEdge(INT Op1, INT Op2); // �������� ������������� ���� Op1 -> Op2
//
INT  __fastcall GetParamsGraph(); // ��������� ���������� �������� � ��������� ��� �� ����������
INT  __fastcall GetOpByMinInOnTiers(INT minTier, INT maxTier); // #����. � MIN ������ �� ������ mimTier-maxTier
INT  __fastcall GetOpByMinOutOnTiers(INT minTier, INT maxTier); // #����. � MIN ������� �� ������ mimTier-maxTier
void __fastcall Delay(long mSecs); // ����� mSecs ����������� (� ������������ ���������� WINDOWS)
INT  __fastcall AddEdge(INT fromOp, INT toOp); // ���������� ���� � ��������� ������������� Edges
INT  __fastcall GetFirstToOpFromOp(INT fromOp); // ������� #��., ��������� ������ �� ����� ��������� �� ���� ����� ������������ fromOp
INT  __fastcall GetFirstFromOpToOp(INT toOp); // ������� #��., ��������� ������ �� ����� �������� �� ���� ����� ������������ tomOp
//
INT  __fastcall GetCountInOp(INT toOp, INT Numb); // ������� from-��������, ��������������� Numb-��� In-���� ��� to-��������� toOp
INT  __fastcall GetCountOutOp(INT fromOp, INT Numb); // ������� to-��������, ��������������� Numb-��� Out-���� ��� to-��������� fromOp
//
INT  __fastcall TestExistInOutAtAllOps(); // ��������� ������� ���� ����� ������� ��� �������� ���� � ������� ���������
//
////////////////////////////////////////////////////////////////////////////////
// ���� �������������� ��������������� ���� ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// ������� ������������ --------------------------------------------------------
INT   __fastcall c_GetCountParamsByCalc(INT Calc); // ����� ���������� ����������� Calc
char* __fastcall c_GetNumbParamByCalc(INT Numb, INT Calc); // �������� Numb (������� � 1) ����������� Calc
char* __fastcall c_GetNameNumbParamByCalc(INT Numb, INT Calc); // ��� ��������� Numb (������� � 1) ����������� Calc
REAL  __fastcall c_GetMinValNumbParamByCalc(INT Numb, INT Calc); // ��� �������� ��������� Numb (������� � 1) ����������� Calc
REAL  __fastcall c_GetMaxValNumbParamByCalc(INT Numb, INT Calc); // ��� �������� ��������� Numb (������� � 1) ����������� Calc
// ������� ���������� ----------------------------------------------------------
INT   __fastcall c_GetCountParamsByOp(INT Op); // ����� ���������� ����������� Op
char* __fastcall c_GetNumbParamByOp(INT Numb, INT Op); // �������� Numb (������� � 1) ��������� Op
char* __fastcall c_GetNameNumbParamByOp(INT Numb, INT Op); // ��� ��������� Numb (������� � 1) ��������� Op
REAL  __fastcall c_GetValNumbParamByOp(INT Numb, INT Op); // �������� ��������� Numb (������� � 1) ��������� Op
//
// ������ � ��������� ������ (����������) --------------------------------------
REAL  __fastcall c_GetMetricOpByName(INT Op, char* nameMetric); // ������� �������� �������� ������� nameMetric ������� (���������) Op
INT   __fastcall c_GetCountMetricsByOp(INT Op); // ����� ���������� ������� (���������) Op
char* __fastcall c_GetNumbMetricByOp(INT Numb, INT Op); // ����� �������� Numb-� ������� nameMetric ������� (���������) Op
char* __fastcall c_GetMetricsByOp(INT Op); // �� ������ sVrt ���������� ��������� ���� ���������� ������� (���������) Op
//
// ������ � ��������� ��� ------------------------------------------------------
REAL  __fastcall c_GetMetricEdgeByName(INT from_Op, INT to_Op, char* nameMetric); // ������� �������� �������� ������� nameMetric ���� ����� ��������� (�����������) from_Op � to_Op
INT   __fastcall c_GetCountMetricsByEdge(INT from_Op, INT to_Op); // ����� ���������� ���� �� from_Op �� to_Op
char* __fastcall c_GetNumbMetricByEdge(INT Numb, INT from_Op, INT to_Op); // ����� �������� ������� ���� �� from_Op �� to_Op
char* __fastcall c_GetMetricsByEdge(INT from_Op, INT to_Op); // �� ������ sEdg ���������� ��������� ���� ���������� ����  �� from_Op �� to_Op
//
// ������� ����������� ������ �� ������� ������������� ���������� � ������������
INT   __fastcall c_CanExecOpCalc(INT Op, INT Calc); // ������� >0, ���� Op ����� ��������� �� Calc
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_LoadFileNameParamsCalcs(char FileName[]); // �������� ��� ����� ���������� ������������
bool  __fastcall c_ReadAndCorrectParamsCalcs(char FileName[]); // ������ ���� ���������� ������������
//
bool  __fastcall c_LoadFileNameParamsOps(char FileName[]); // �������� ��� ����� ���������� ����������
bool  __fastcall c_ReadAndCorrectParamsOps(char FileName[]); // ������ ���� ���������� ����������
//
bool  __fastcall c_LoadFileNameParamsEdges(char FileName[]); // �������� ��� ����� ������ ���
bool  __fastcall c_ReadAndCorrectParamsEdges(char FileName[]); // ������ ���� ������ ���
//
bool  __fastcall c_LoadFileNameParamsVertices(char FileName[]); // �������� ��� ����� ������ ������ (����������)
bool  __fastcall c_ReadAndCorrectParamsVertices(char FileName[]); // ������ ���� ������ ������ (����������)
//
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetParamsByCalc(INT Calc); // ���������� ��� ������ ���������� ����������� �alc
char* __fastcall c_GetParamsByOp(INT Op); // ���������� ��� ������ ���������� ��������� Op
//
////////////////////////////////////////////////////////////////////////////////
// ����� ������� - ��������� �� � Calc ��� Op, � �� �������� -------------------
INT   __fastcall c_GetCountParamsInString(char* str); // ����� ���������� � ������ str
char* __fastcall c_GetNumbParamInString(INT Numb, char* str); // �������� Numb � ������ str
char* __fastcall c_GetNameNumbParamInString(INT Numb, char* str); // ��� ��������� Numb � ������ str
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_IsCorrectParamCalc(char* str); // TRUE ��� ������������ ������������� ��������� �����������
bool  __fastcall c_IsCorrectParamOpVertEdg(char* str); // TRUE ��� ������������ ������������� ��������� ���������
////////////////////////////////////////////////////////////////////////////////
INT  __fastcall  c_FindSubString( char* sSrc, char* sDst, INT iStart , INT Rule);
INT  __fastcall  c_GetCountCalcs(); // ����� ����� ������������
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_PutParamsAll(); // ����� (�����������������) ����� ������������ � ����������, ������ ��� � ������
bool  __fastcall c_TestCanExecAllOpsCalcs( INT  Rule ); // ���� ������������ ���������� �� ������������
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall cmp_def( char *s );
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_InputDialog( char *sCaption, char *sPrompt, char *sDefault ); // ����������� ���� ����� Windows
int   __fastcall c_MessageDialog( char *sCaption, char *sText, char *Buttons, INT Pictogram ); // ����������� ���� ������ Windows
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_DrawDiagrTiers(); // ������ ����������� ����������� (���������) ������� ������ �����
bool  __fastcall c_DrawDiagrTLD(); // ������ ����������� ����������� (���������) ����� ����� ���������� ������
bool  __fastcall c_ClearDiagrArea(); // �������� ����������� ����������� (���������)
INT   __fastcall c_PutParamsTiers(); // ����� �������� ���������� ��� � ���
//
bool  __fastcall c_IsOpContainOnTiers(INT Op); // ���� �������� Op ������������ � Tiers[][], ����������� TRUE, ����� - FALSE
INT   __fastcall c_GetOpByMaxTierLowerPreset(INT Op); // ����� ��������, ������������� ��������� �� ��������� � ����������� �� �����
// � ������������ ������� (���� ����� �������� ��������� - ������� ��������� �� ������)
//
INT  __fastcall c_WinExec( char *cmdLine, INT cmdShow ); // ��������� WinExec
INT  __fastcall c_ShellExecute( char *Operation, char *File, char *Parameters, char *Directory, INT cmdShow ); // ��������� ShellExecute
//
INT  __fastcall c_CreateProsess(char* CommandLine, byte RuleParent, byte Priority, bool RuleMessage); // ������ ��������-�������
//==============================================================================
bool __fastcall TestAndAddMemoryForEdges( INT nEdges ); // ������� ���������� ������ ��� Mem_Edges[]
bool __fastcall ParseStringAndAddEdges( char *str ); // ������ str � ��������� ���� � ����� ������ ���
//
bool __fastcall ReadAndPrimWorkOpsCalcsVertEdgeFiles( char FileName[] ); // ������ � �����.��������� ������ ��������
//
INT  __fastcall c_LuaCallByTimer( char *CommandLine, INT d_Ticks ); // ����� Lua-������ � ��������� d_Ticks
//
void __fastcall CallLuaThread( char *CommandLine ); // ����� CommandLine �� ����� ��������� ������ Lua
//
char* __fastcall ReformFileName( char Filename[], char Ext[] ); // ������ ������� ������������� ��� �����
//
INT  __fastcall c_CalcParamsTiers(); // ������ ���������� ������ ���
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall cmp_def( char *s )
{ // ���������� ������� 5 ������ �������� s � sDef; ���������� TRUE, ���� ��� ��� �����
 return( toupper(s[0])==toupper(sDef[0]) && toupper(s[1])==toupper(sDef[1]) &&
         toupper(s[2])==toupper(sDef[2]) && toupper(s[3])==toupper(sDef[3]) &&
         toupper(s[4])==toupper(sDef[4]) ) ;
} // === ����� cmp_def =========================================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall // ����� mSecs ����������� (� ������������ ���������� WINDOWS)
Delay(long mSecs)
{ // ��� mSecs < 0 ����� �������� ���������� ��� � ��������
 if ( !mSecs ) // ���� ���� - �������� ��������!... ���� ����� Windows - "��������� ���������� �������!"
  return ;
//
 unsigned long t, FirstTick = ::GetTickCount(); // ��������� ������ ������� ( :: ��� ������� �� ����������� � TldHTTP)
 t= mSecs>=0 ? mSecs : -1e3*mSecs;
 while( (::GetTickCount()-FirstTick) < t ) // ��������, ���� �������� �������� ������� �� �����...
  Application->ProcessMessages(); // ���� ���������� WINDOWS
}
// === ����� Delay =============================================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_SaveTiersVizu(char FileName[])
{ // ����� ����� �������� �� ������
 char str[_16384], tmp[_256];
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 if( !isTiers ) // ������� Tiers[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extVizu) ); // ��������������� ��� �����
//
 if(!(fptr = fopen( NewFileName,"w" ))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� �������� ���� %s ���������� ��� -E-\n\n-W- ��������� �������������� ������ �� �������� �������� ������ -W-",
                   NewFileName );
  return FALSE ;
 }
//
// setbuf( fptr, NULL ); // ��������� ������������ ��� ������
//
 for(INT iTier=0; iTier<=nTiers; iTier++) // �� ������ ���
 {
  snprintf(str,sizeof(str), "#Tier=%4d #Op=%4d|", iTier, Tiers(iTier,0)); // ����� ����� + ����� ���������� �� ��
  for(INT j = 1; j<=Tiers( iTier,0 ); j++) // �� ������ ������� ���������� �� ����� i
  {
   if( !c_GetCountInEdgesByOp( Tiers(iTier,j) )) // � ����� ��������� ��� �������� ���...
    snprintf(tmp,sizeof(tmp), _IN,  Tiers(iTier,j)); // ��� �������� �������� (��������� ���������)
   else
   if( !c_GetCountOutEdgesByOp( Tiers(iTier,j) )) // � ����� ��������� ��� ��������� ���...
    snprintf(tmp,sizeof(tmp), _OUT, Tiers(iTier,j)); // ��� �������� �������� (��������� ���������)
   else
    snprintf(tmp,sizeof(tmp), " %d", Tiers(iTier,j) ); // ������ ���������� ��������� ��� �������� ������
//
   strcat(str, tmp); // ���������� ������ ��������� �� ����� i
  } // ����� �� j (������ ��������� �� �����)
  fprintf(fptr, "%s\r\n", str); // ������ � ���� ������� ������
 } // ����� �� i (������ �����)
//
 fclose(fptr); // ������� ����
//
 return TRUE ;
//
} // --- ����� SaveTiersVizu ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_SaveEdgesVizu(char FileName[])
{ // ����� ������ ����� �����������
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 if( !isEdges ) // ������� Mem_Edges[] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extVizu) ); // ��������������� ��� �����
//
 if(!(fptr = fopen( NewFileName,"w" ))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� �������� ���� %s ���������� ��� -E-\n\n-W- ��������� �������������� ������ �� �������� �������� ������ -W-",
                   NewFileName );
  return FALSE ;
 }
//
// setbuf( fptr, NULL ); // ��������� ������������ ��� ������
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ������� ���
  fprintf(fptr, "#Edge= %d %d -> %d\n", iEdge, Edges(0,iEdge),Edges(1,iEdge)); // ���� ����� i
//
 fclose(fptr); // ������� ����
//
 return TRUE ;
//
} // --- ����� SaveEdgesVizu ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_SaveInOutOpVizu(char FileName[])
{ // ����� ����� �������� � ��������� ��� ��� ����������
 char str[_16384], tmp[_256], s1[]="* \0";
 INT jOpOnTier, iOp, j, nIn,nOut;
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 if( !isEdges ) // ������� Mem_Edges[] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 if( !isTiers ) // ������� Tiers[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extVizu) ); // ��������������� ��� �����
//
 if(!(fptr = fopen( NewFileName,"w" ))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� �������� ���� %s �������� � ��������� ��� �� ���������� -E-\n\n-W- ��������� �������������� ������ �� �������� �������� ������ -W-",
                   NewFileName );
  return FALSE ;
 }
//
// setbuf( fptr, NULL ); // ��������� ������������ ��� ������
//
 for(INT iTier=0; iTier<=nTiers; iTier++) // �� ���� ������ ������� �������...
  for(jOpOnTier=1; jOpOnTier<=Tiers(iTier,0); jOpOnTier++) // �� ���������� �� �����...
  {
   iOp = Tiers(iTier,jOpOnTier); // ����� ���������
// --- ������ ������������ ������ ������ ---------------------------------------
   snprintf(str,sizeof(str), "#Op=%d #Tier=%d #In=%d ",
                iOp, c_GetTierByOp(iOp), c_GetCountInEdgesByOp(iOp)); // c_GetCountOutEdgesByOp(iOp) );
//
   for(j=1; j<=c_GetCountInEdgesByOp(iOp); j++) // �� ������ ������� ��� ��������� iOp
   {
    nIn = c_GetNumbInEdgeByOp(j,iOp); // j-� �������� �� ������� ���� ��������� iOp
    if( nIn > 0 ) snprintf(tmp,sizeof(tmp), "%d ", nIn);  // ���� IN-��������...
    else          strNcpy(tmp, s1); // ��� IN-���������...
    strcat(str, tmp); // ... ���������!
   }
//
   snprintf(tmp,sizeof(tmp), "#Out=%d ", c_GetCountOutEdgesByOp(iOp)); // ����� �������� ��� ��������� iOp
   strcat(str, tmp); // ... ���������!
//
   for(j=1; j<=c_GetCountOutEdgesByOp(iOp); j++) // �� ������ �������� ��� ��������� iOp
   {
    nOut = c_GetNumbOutEdgeByOp(j,iOp); // j-� �������� �� ������� ���� ��������� iOp
    if( nOut > 0 )
     snprintf(tmp,sizeof(tmp), "%d ", nOut);  // ���� OUT-��������...
    else
     strNcpy(tmp, s1); // ��� OUT-���������...
    strcat(str, tmp); // ... ���������!
   }
//
// --- ����� ������������ ������ ������ ----------------------------------------
//
   fprintf(fptr, "%s\r\n", str); // ������ � ���� ������� ������
  } // ����� ����� �� jOpOnTier ================================================
//
 fclose(fptr); // ������� ����
//
 return TRUE ;
//
} // --- ����� SaveInOutOpVizu -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_SaveParamsVizu(char FileName[])
{ // ����� ����� �������� � ��������� ��� ����������
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 if( !isEdges ) // ������� Mem_Edges[] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extVizu) ); // ��������������� ��� �����
//
 if(!(fptr = fopen( NewFileName,"w" ))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� ��������� ���� %s ����� �������� � ��������� ��� �� ���������� -E-\n-W- ��������� �������������� ������ �� �������� �������� ������ -W-",
                   NewFileName );
  return FALSE ;
 }
//
// setbuf( fptr, NULL ); // ��������� ������������ ��� ������
//
 GetParamsGraph(); // ����� ��������� ����� ----------------------------------
//
 fprintf(fptr, "#nOpMinIn=%12d #nEdgesMinIn=%10d\n#nOpMaxIn=%10d #nEdgesMaxIn=%10d\n#nOpMinOut=%9d #nEdgesMinOut=%9d\n#nOpMaxOut=%9d #nEdgesMaxOut=%9d\nAveIn=%14.3f AveOut=%16.3f",
               PG.nOpMinIn,  PG.nEdgesMinIn,
               PG.nOpMaxIn,  PG.nEdgesMaxIn,
               PG.nOpMinOut, PG.nEdgesMinOut,
               PG.nOpMaxOut, PG.nEdgesMaxOut,
               PG.AveIn,     PG.AveOut);
//
 fclose(fptr); // ������� ����
//
 return TRUE ;
//
} // --- ����� SaveParamsVizu -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_SaveTiers(char FileName[])
{  // ����� ���������� �� ������ ��� ������� �������� ����� � ���� ���
 char str[_16384], tmp[_256];
 FILE *fptr = NULL; // ������� ��������� �� ����
//
//
 if( !isTiers ) // ������� Tiers[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 char NewFileName[_512];
 strcpy( NewFileName, ReformFileName(FileName,extTiers) ); // ��������������� ��� ������
//
 if(!(fptr = fopen( NewFileName, "w" ))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� �������� ���� %s ������� �������� ��� � ��� -E-\n\n-W- ��������� �������������� ������ �� �������� �������� ������ -W-",
                   NewFileName );
  return FALSE ;
 }
//
// setbuf( fptr, NULL ); // ��������� ������������ ��� ������
//
//  // ����� ������ (����������), max ���������� �� �����, �� ����� ������
 fprintf(fptr, "%d %d %d\n", nTiers+1, c_GetCountOpsOnTier( c_GetTierFirstMaxOps(1,nTiers) ),
                                       c_GetTierFirstMaxOps(1,nTiers) );
//
 for(INT iTiers=0; iTiers<=nTiers; iTiers++) // �� ������ ��� �����
 {
  strNcpy(str, ""); // �������� ������ ����� �����������

  for(INT j=0; j<=Tiers(iTiers,0); j++) // �� ������� ���������� �� ����� iTiers
  {
   snprintf(tmp,sizeof(tmp), "%d ", Tiers(iTiers,j)); // �� ��������� ������ ������ iTiers
   strcat(str, tmp); // ��������� ��� ������������ ������
  } // ����� ����� �� j
//
  fprintf(fptr, "%s\n", str); // ������ � ���� ������� ������
//
 } // ����� ����� �� iTiers
//
 fclose(fptr); // ������� ����
//
 return TRUE ;
//
} // --- ����� SaveTiers -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ReadTiers(char FileName[])
{  // ������ ���������� �� ������ ��� ������� �������� ����� � ���� ���
 char str[_16384], *p;
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 INT MaxOpsOnTier, // ��� ����� ���������� �� ����� ������ ��� �����
     TierWithMaxOps, // �� ����� (������) ����� ���� ��� �����������
     j;
//
 strNcpy( FileName, ChangeFileExt( FileName, extTiers ).c_str() ); // ���������� - extTiers
//
 if(!(fptr = fopen(FileName, "r"))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� ��������� ���� %s ���������� ��� -E-\n-W- �������� �������������� ��� ���������� ������ -W-",
                   FileName );
  isTiers = FALSE;
  return FALSE ;
 }
//
 nTiers = 0 ; // ����������, ����� ������ ���
//
 fgets(str, sizeof(str), fptr); // ��������� ������ ������ �����
// ����� ������ (����������), max ���������� �� �����, �� ����� ����� ���� max
 if( sscanf(str, "%d %d %d", &nTiers, &MaxOpsOnTier, &TierWithMaxOps) == 0 ) // 0 = ������
 {
  isTiers = FALSE;
  return FALSE ;
 }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( ( nTiers < _maxTiers ) && ( MaxOpsOnTier < _maxOpsOnTier ) ) // ������ ����������
  goto cont; // ... �� ���� �������������� ������
//
 _maxTiers = nTiers * stockMem; // ����� ������ � ������� � stockMem ���
 _maxOpsOnTier = MaxOpsOnTier * stockMem; // ����� ���������� �� ����� � ������� � stockMem ���
 pTiers = (INT*) realloc( pTiers, (_maxTiers+1) * (_maxOpsOnTier+1) * sizeof(INT) ); // �������������� ������ ��� Tiers[][]...
//
 if( !pTiers ) // ������ ����� - ������ � "����" �����������
 {
  snprintf(str,sizeof(str), "�������� ������ ��� ���������� ������� ������ (4). ����������� %d x %d = %d ���������...",
                (_maxTiers+1), (_maxOpsOnTier+1), (_maxTiers+1) * (_maxOpsOnTier+1));
  MessageBox(0, str, "��������������", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  isTiers = FALSE ; // ������ Tiers[][] �� ������...
  return FALSE ;
 }
//
  t_printf( "\n-I- ������ ������ (4) �������������� �� %d x %d = %d ��������� -I-",
                   (_maxTiers+1), (_maxOpsOnTier+1), (_maxTiers+1) * (_maxOpsOnTier+1) );
//
cont: // �� ���� �������������� ������...

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

 for(INT iTier=0; iTier<=nTiers; iTier ++) // �� ������ ��� �����
 {
  fgets(str, sizeof(str), fptr); // ��������� ��������� ������ �����

  j = 0; // ����� ��������� �� ����� iTier

  if( p = strtok( str, " " ) ) // �������� ������ ����� �� �������
  if( sscanf( p, "%d", &Tiers(iTier, ++j) ) != 1 ) // ��������� ������ #��������� � Tiers[iTier][1]
   goto cont_1;  // ��� ������ sscanf ������������ ����� ������� ����������� ���������

  while( p ) // ���� p = TRUE
  {
   p = strtok( NULL, " "); // �� ���������� �������..
   if( sscanf( p, "%d", &Tiers(iTier, ++j) ) != 1 ) // ��������� #���������� ������ ������� � Tiers[iTier][*]
    goto cont_1;
  } // ����� while

cont_1: // ��� ��������� �� ����� iTier ��������� � Tiers[][] ------------------

  Tiers(iTier, 0) = j-1; // ����� ����� ���������� �� ����� iTier

 } // ����� ����� �� iTiers

 fclose(fptr); // ������� ����

 isTiers = TRUE ; // all O'k...

 t_printf( "-I- ��� ����� �� ����� %s ������� ��������� -I-", FileName );

 return TRUE ;

} // --- ����� �_ReadTiers -----------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_IsOpsHaveEdge(INT Op1, INT Op2)
{ // TRUE - ���� ������������ ���� ����� ����������� Op1 -> Op2
 if( !isEdges ) // ������ Mem_Edges[] ��� �� ���������� - ������� � FALSE
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ������ ������ ��� ����� �����������
  if ( (Op1 == Edges(0,iEdge)) && (Op2 == Edges(1,iEdge)) ) // ����� ���� � ������ �������...
   return ( TRUE );
//
 return ( FALSE );
// 
} // --- ����� c_IsOpsHaveEdge -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierByOp(INT Op)
{ // --- ������� ����� ����� ��� ��������� Op ----------------------------------
 if( !isTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }

 for(INT iTier=0; iTier<=nTiers; iTier++) // �� ���� ������
  if( c_IsOpExistOnTier( Op, iTier ) == TRUE ) // �������� Op ����� ����� �������������� �� ����� iTier
   return iTier ;

 return ERR_COMMON ; // �� ������� ����� �������� Op...

} // --- ����� c_GetTierByOp -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetParamsGraph()
{ // --- ������� ���������� ����� ������� � �������� ��� ��� ���� ����������
// ----- (������ � ��������� ����� �� ���������������) - ������� � ��������� ParGraph
 INT Extr = nOps,  // ������ ���� �� ����� !!!
     Op, nEdgesInOp,  // In  �� ���� ����������...
         nEdgesOutOp; // Out �� ���� ����������...
 char w[_256];

// PG - ���������� ! -----------------------------------------------------------

 if( !isEdges && !isTiers ) // ��� �������� Mem_Edges[] � Tiers[][]
 {
  DisplayMessage( "E", __FUNC__, "������� ��� � ������ �� ������������", ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }

 PG.nEdgesMinIn  =        // ������������� �� ����� �������� ���... (MIN)
 PG.nEdgesMinOut =  Extr; // ������������� �� ����� ��������� ���... (MIN)

 PG.nEdgesMaxIn  =    // �� �� ����� (MAX)
 PG.nEdgesMaxOut = - Extr; // �� �� ����� (MAX)

 PG.AveIn  =       // ��� ������������ ����� ���
 PG.AveOut = 0.0;

// --- ���� �������� ( to ) � ��������� ���� -----------------------------------
 for(INT iTier=2; iTier<=nTiers; iTier++) // �� ���� ������ �� 2 �� nTiers
  for(INT j=1; j<=Tiers(iTier,0); j++) // �� ������� ���������� �� ����� ����� �������
  {
   Op = Tiers(iTier,j); // ����� ���������
// ���� MIN � ��� ����� �������� (...In...) ��� ||||||||||||||||||||||||||||||||
   nEdgesInOp = 0; // ������� ����� ���, ���������� �������� ( to ) ��� ��������� Op
   for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� �����
    if( Edges(1,iEdge) == Op ) // ����� ����, �������� ( to ) � ������ ��������...
     nEdgesInOp ++ ; // ��������� ����, �������� ( to ) ��� ��������� Op

   PG.AveIn += nEdgesInOp ;  // ����� ����� ��� In ��� ��������� Op

   if(nEdgesInOp < PG.nEdgesMinIn) // ���� MIN ��������...
   {
    PG.nEdgesMinIn = nEdgesInOp;
    PG.nOpMinIn    = Op; // ��������� ��������������� Op
   }

   if(nEdgesInOp > PG.nEdgesMaxIn) // ���� NAX ��������...
   {
    PG.nEdgesMaxIn = nEdgesInOp;
    PG.nOpMaxIn    = Op; // ��������� ��������������� Op
   }

  } // ����� ����� �� j

////////////////////////////////////////////////////////////////////////////////

// --- ���� ��������� ( from ) � ��������� ���� --------------------------------
 for(INT iTier=1; iTier<nTiers; iTier++) // �� ���� ������ �� 1 �� nTiers-1
  for(INT j=1; j<=Tiers(iTier,0); j++) // �� ������� ���������� �� ����� ����� �������
  {
   Op = Tiers(iTier,j); // ����� ���������
// ���� MIN � ��� ����� ��������� (...Out...) ��� ||||||||||||||||||||||||||||||
   nEdgesOutOp = 0; // ������� ��� ������������ ����� ���, ���������� ��������� ��� ��������� iOp
   for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� ����� ========
    if( Edges(0,iEdge) == Op ) // ����� ����, ��������� ( from ) �� ������� ���������...
     nEdgesOutOp ++ ; // ��������� ����, ��������� �� ��������� Op...

   PG.AveOut += nEdgesOutOp ; // ����� ����� ��� Out ��� ��������� Op

   if(nEdgesOutOp < PG.nEdgesMinOut) // ���� MIN ���������...
   {
    PG.nEdgesMinOut = nEdgesOutOp;
    PG.nOpMinOut    = Op; // ��������� ��������������� Op
   }

   if(nEdgesOutOp > PG.nEdgesMaxOut) // ���� NAX ���������...
   {
    PG.nEdgesMaxOut = nEdgesOutOp;
    PG.nOpMaxOut    = Op; // ��������� ��������������� Op
   }

  } // ����� ����� �� j

////////////////////////////////////////////////////////////////////////////////

 PG.AveIn  /= nOps - Tiers(1,0); // ������� ����� ���, �������� ( to ) � ��������� �����
 PG.AveOut /= nOps - Tiers(nTiers,0); // ������� ����� ���, ��������� ( from ) �� ���������� �����

 return TRUE ;

} // --- ����� GetParamsGraph --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetOpByMinInOnTiers(INT minTier, INT maxTier)
{ // --- ������� ����� ��������� � MIN ������ �� ������ � minTier �� maxTier
 INT nEdgesInOp = nEdges,  // ������ ���� �� �����
     iOp,iOpMinIn, sumEdgesIn;
//
 if( !isTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 for(INT j=minTier; j<=maxTier; j++) // �� ���� ������ � minTier �� maxTier
//
 for(INT iOpOnTier=1; iOpOnTier<=Tiers(j,0); iOpOnTier++) // �� ���� ���� ���������� ����� Tier
 {
  iOp = Tiers(j,iOpOnTier); // ����� ����� iOpOnTier �� ����� ��������� �� ����� j
//
  sumEdgesIn = 0; // ��������� In-����� � ���������� sumEdgesIn
  for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� ����� ==============
   if( Edges(1,iEdge) == iOp ) // ����� ����, �������� � �������� iOp
    sumEdgesIn ++ ; // ��������� ����� ���, �������� � �������� iOp...
//
  if(sumEdgesIn < nEdgesInOp) // MIN ������ �� ���� ����. ������ minTier-maxTier
  {
   nEdgesInOp = sumEdgesIn;
   iOpMinIn = iOp; // ��������� ����� ���������
  }

 } // ����� ����� �� i
   // ����� ����� �� j
//
 return iOpMinIn; // �������� � MIN ������ �� ������ minTier - maxTier
//
} // --- ����� GetOpByInMinOnTiers ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetOpByMinOutOnTiers(INT minTier, INT maxTier)
{ // --- ������� ����� ��������� � MIN ������� �� ������ � minTier �� maxTier
 INT nEdgesOutOp = nEdges,  // ������ ���� �� �����
     iOp,iOpMinOut, sumEdgesOut;

 if( !isTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }

 for(INT j=minTier; j<=maxTier; j++) // �� ���� ������ � minTier �� maxTier

 for(INT iOpOnTier=1; iOpOnTier<=Tiers(j,0); iOpOnTier++) // �� ���� ���� ���������� ����� Tier
 {
  iOp = Tiers(j,iOpOnTier); // ����� ����� iOpOnToer �� ����� ��������� �� ����� j

  sumEdgesOut = 0; // ��������� � ���������� sumEdgesIn
  for(INT iEdge = 0; iEdge < nEdges; iEdge ++ ) // �� ���� ����� ����� ========
   if( Edges(0,iEdge) == iOp ) // ����� ����, ��������� �� ��������� iOp
    sumEdgesOut ++ ; // ��������� ����� ���, ��������� �� �������� iOp...

  if(sumEdgesOut < nEdgesOutOp) // MIN ������� �� ���� ����. ������ minTier-maxTier
  {
   nEdgesOutOp = sumEdgesOut;
   iOpMinOut = iOp; // ��������� ����� ���������
  }

 } // ����� ����� �� i
   // ����� ����� �� j

 return iOpMinOut; // �������� � MIN ������� �� ������ minTier-maxTier

} // --- ����� GetOpByOutMinOnTiers --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall AddEdge(INT fromOp, INT toOp)
{ // --- ���������� ���� � ���������, ���� �� ��� ����� � Mem_Edges[] ----------
 char str[_256];

 if( !isEdges ) // ��� ������� Mem_Edges[]...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }

//////////////////////c/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//////////////////////c/////////////////////////////////////////////////////////

 if( ( nEdges+3 ) < Max_Edges ) // ������� ������� Mem_Edges[] ��� �������!..
  goto cont;
//
 Max_Edges *= stockMem; // ��������� � stockMem ���
 Mem_Edges = (me*) realloc( Mem_Edges, Max_Edges * sizeof(INT) ); // �������������� ������ ��� Mem_Edges[]...
//
 if( !Mem_Edges ) // ������ ����� - ������ � "����" �����������
 {
  snprintf(str,sizeof(str), "�������� ������ ��� ���������� ������� ��� (00). ����������� %d ���������...",
                             Max_Edges );
  MessageBox(0, str, "��������������", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  MessageBeep(MB_OK); // �������� ��������������...
  isEdges = FALSE ; // ������ Mem_Edges[] �� ������...
  return FALSE ;
 }
//
 t_printf( "\n-I- ������ ��� (00) �������������� �� %d x %d = %d ��������� -I-",
                  Max_Edges );
//
 cont: // �� ���� ������������� ������������ ������ ��� Mem_Edges[]
//
//////////////////////c/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 nEdges ++ ;
//
 Edges(0,nEdges) = fromOp; // ���� "������"
 Edges(1,nEdges) = toOp;   // ���� "����"
//
 return TRUE; // ���� ������� ���������
//
} // --- ����� AddEdge ---------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetFirstToOpFromOp(INT fromOp)
{ // --- ������� ������ �� ����� �������� toOp, ���������� ���������
// --- �� ���� ����� ������������ fromOp
//
 if( !isEdges ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� �����...
  if( Edges(0,iEdge) == fromOp ) // ����� fromOp ( "������" )
   return Edges(1,iEdge) ; // ������� toOp ( "����" )
//
} // --- �����  GetFirstToOpFromOp ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetFirstFromOpToOp(INT toOp)
{ // --- ������� ������ �� ����� �������� fromOp, ���������� ��������
// --- �� ���� ����� ������������ toOp
//
 if( !isEdges ) // ������ Mem_Edges[] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� �����...
  if( Edges(1,iEdge) == toOp ) // ����� toOp ( "����" )
   return Edges(0,iEdge) ; // ������� fromOp ( "������" )
//
} // --- �����  GetFirstFromOpToOp ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierFirstMaxOps(INT Tier1, INT Tier2)
{ // ���������� ������ #����� � MAX �� ��������� ������ (Tier1-Tier2) ������ ����������
// - ���� ����������� (����������) ��������� - ������������ ������ �� ��� (c Tier = min)
 INT TierMaxOp = - _maxOpsOnTier , // ��� ������ MAX
     Tier;
//
 if( !isTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier1 < 1 ) || ( Tier1 > nTiers ) ||
     ( Tier2 < 1 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 if( Tier2 < Tier1 ) // ������� �������� Tier1 - Tier2
 {
//  t_printf( "\n-E- %s(): %s {%d-%d}, [%d] -E-", __FUNC__, messParams2, Tier1,Tier2, ERR_RANGE_IN );
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // �� �������� ������ ��� ---------
  if ( Tiers(iTier,0) > TierMaxOp ) // ���� MAX...
  {
   TierMaxOp = Tiers(iTier,0); // ����� ���������� �� ����� iTier
   Tier = iTier; // ��������� iTier � ������� ���������� ����������
  }
//
 return Tier ;
//
} // --- �����  c_GetTierFirstMaxOps -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierLastMaxOps(INT Tier1, INT Tier2)
{ // ���������� ��������� #����� � MAX �� ��������� ������ (Tier1-Tier2) ������ ����������
// - ���� ����������� (����������) ��������� - ������������ ��������� �� ��� (c Tier = max)
 INT TierMaxOp = - _maxOpsOnTier , // ��� ������ MAX
     Tier;
 char w[_256];

 if( !isTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }

 if( ( Tier1 < 1 ) || ( Tier1 > nTiers ) ||
     ( Tier2 < 1 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }

 if( Tier2 < Tier1 ) // ������� �������� Tier1 - Tier2
 {
//  t_printf( "\n-E- %s(): %s {%d-%d}, [%d] -E-", __FUNC__, messParams2, Tier1,Tier2, ERR_RANGE_IN );
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }

 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // �� �������� ������ ��� ---------
  if ( Tiers(iTier,0) >= TierMaxOp ) // ���� MAX...
  {
   TierMaxOp = Tiers(iTier,0); // ����� ���������� �� ����� iTier
   Tier = iTier; // ��������� iTier � ������� ���������� ����������
  }

 return Tier ;

} // --- �����  c_GetTierLastMaxOps --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierFirstMinOps(INT Tier1, INT Tier2)
{ // ���������� ������ #����� � MIN �� ��������� ������ (Tier1-Tier2) ������ ����������
// - ���� ����������� (����������) ��������� - ������������ ������ �� ��� (c Tier = min)
 INT TierMinOp = _maxOpsOnTier , // ��� ������ MIN
     Tier;

 if( !isTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }

 if( ( Tier1 < 1 ) || ( Tier1 > nTiers ) ||
     ( Tier2 < 1 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1,  ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }

 if( Tier2 < Tier1 ) // ������� �������� Tier1 - Tier2
 {
//  t_printf( "\n-E- %s(): %s {%d-%d}, [%d] -E-", __FUNC__, messParams2, Tier1,Tier2, ERR_RANGE_IN );
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }

 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // �� ���� ������ ��� ------------
  if ( Tiers(iTier,0) < TierMinOp ) // ���� MIN...
  {
   TierMinOp = Tiers(iTier,0); //  ����� ���������� �� ����� iTier
   Tier = iTier; // ��������� iTier � ������� ��������� ����������
  }

 return Tier ;

} // --- �����  c_GetTierFirstMinOps -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierLastMinOps(INT Tier1, INT Tier2)
{ // ���������� ��������� #����� � MIN �� ��������� ������ (Tier1-Tier2) ������ ����������
// - ���� ����������� (����������) ��������� - ������������ ���������� �� ��� (c Tier = max)
 INT TierMinOp = _maxOpsOnTier , // ��� ������ MIN
     Tier;

 if( !isTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }

 if( ( Tier1 < 0 ) || ( Tier1 > nTiers ) ||
     ( Tier2 < 0 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }

 if( Tier2 < Tier1 ) // ������� �������� Tier1 - Tier2
 {
//  t_printf( "\n-E- %s(): %s {%d-%d}, [%d] -E-", __FUNC__, messParams2, Tier1,Tier2, ERR_RANGE_IN );
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }

 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // �� ���� ������ ��� ------------
  if ( Tiers(iTier,0) <= TierMinOp ) // ���� MIN...
  {
   TierMinOp = Tiers(iTier,0); //  ����� ���������� �� ����� iTier
   Tier = iTier; // ��������� iTier � ������� ��������� ����������
  }

 return Tier ;

} // --- �����  c_GetTierLastMinOps --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsOpExistOnTier(INT Op, INT Tier)
{ // ���������� TRUE ������ ���� �������� Op ������������ �� ����� Tier

 for(INT jOpOnTier=1; jOpOnTier<=Tiers(Tier,0); jOpOnTier++) // �� ���� ���������� ����� Tier
  if( Tiers(Tier,jOpOnTier) == Op ) // ����� ������� �������� Op !..
   return TRUE;

 return FALSE;

} // --- �����  c_IsOpExistOnTier ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsOpDependOnlyAboveTiers(INT toOp, INT Tier)
{ // TRUE - ������ ���� �������� toOp ������� (�� ���� ���� In-�����)
// - ������������� �� from-����������, ����������� �� ������ � 1 �� Tier-1
// - ������������ ��� ������������ �������������� ��������� toOp ����� Tier
// - ������������ ������ IsOpExistOnTier(*,*) � GetInToOp(*)
 INT fromOp, iTier,
     sumIn = 0; // ��� ������������ ����� In'��
// --- ����, �� ����� ���������� ������� toOp ----------------------------------
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� �����...
 {
//
  if( Edges(1,iEdge) == toOp ) // ����� (���������) ���� � ��������� toOp
  {
   fromOp = Edges(0,iEdge); // ����� fromOp, ��������������� ��������� toOp
// --- ���� fromOp ����� ���������� �� ������ � 1 �� Tier-1 (�.�. ���� ������� Tier)
   for(iTier=0; iTier<=Tier-1; iTier++) // �������� ������ � 0 �� Tier-1
    if ( c_IsOpExistOnTier( fromOp, iTier ) == TRUE ) // �������� fromOp ������������ �� ����� iTier...
     sumIn ++ ; // ��������� ����� ��������� fromOp �� ������ � 0 �� Tier-1
  } // ����� if ( Mem_Edges[1][iEdge] == toOp )
//
 } // ����� ����� �� iEdge
//
 if( sumIn == c_GetCountInEdgesByOp(toOp) ) // ��������� ������� In, ������� ���� � ��������� toOp ?
  return TRUE; // ����� ��� �������� � toOp �������� ���� ��������� �� ������ �� 0 �� Tier-1
 else
  return FALSE;
//
} // --- �����  c_IsOpDependOnlyAboveTiers -------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetCountInOp(INT toOp, INT Numb)
{ // --- ������� from-��������, ��������������� Numb-��� In-���� ��� to-��������� toOp
// ----- ����� ����� �������� (In) ��� ��� ��������� Op ��� ����� GetInToOp( Op )
// ----- ���� ������� - ������������ -1
 INT nIn = 0;
//
 if( !isEdges ) // ������ Mem_Edges[] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� �����
 {
//
  if( Edges(1,iEdge) == toOp )  // ����� ����, �������� � ������ �������� toOp
   nIn ++ ;
  if( nIn == Numb ) // ���� ��� ���� ��� toOp �������� Numb-���...
   return Edges(0,iEdge); // ���������� ��������������� from-��������
 }
//
 return ERR_COMMON ;
//
} // --- ����� GetCountInOp ----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetCountOutOp(INT fromOp, INT Numb)
{ // --- ������� to-��������, ��������������� Numb-��� Out-���� ��� from-��������� fromOp
// ----- ����� ����� ��������� (Out) ��� ��� ��������� Op ��� ����� GetOutToOp( Op )
// ----- ���� ������� - ������������ -1
 INT nOut = 0;
//
 if( !isEdges ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� �����
 {
//
  if( Edges(0,iEdge) == fromOp )  // ����� ����, �������� � ������ �������� fromOp
   nOut ++ ;
  if( nOut == Numb ) // ���� ��� ���� ��� fromOp �������� Numb-���...
   return Edges(1,iEdge); // ���������� ��������������� to-��������
 }
//
 return ERR_COMMON ;
//
} // --- ����� GetCountOutOp ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetMaxTierMaybeOp(INT Op)
{ // --- ���������� MAX ����� �����, �� ������� ����� ������������� �������� Op
// ----- ��� ������� � ���������� ������ ������������ ����� ��������� ����� ----
 INT toOp, toTier,
     retTier = nTiers;
//
 if( !isTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( c_IsOpExistOnTier(Op, 0) ) // ...�������� Op ��������� �� ������� �����
  return 0 ; // ��� ������ �� ���������!
//
 if( c_IsOpExistOnTier(Op, nTiers) ) // ...�������� Op ��������� �� ��������� �����
  return nTiers ; // ���� ��������� ����������!
//
// ===== ��������� ������ - �������� �� ����� ��������� ��� "�" ================
// ==== ���������� �� �� ��������� ����� !!! ===================================
 if( !c_GetCountOutEdgesByOp( Op ) && // ����� ��������� ��� �������..!!!!!!!!!!!!!!!!!!!!
     !c_IsOpExistOnTier(Op, nTiers) ) // �� �� ��������� �����
  return nTiers ; // ������ ��������� ����� � �� ���������� ����� ����������...
////////////////////////////////////////////////////////////////////////////////
//
// --- � ��������� Op ������� GetInToOp(Op) ������� (In) ���... ���� ��!
 for(INT iEdge=1; iEdge<=nEdges;  iEdge++) // �� ���� ����� � �����...
 {
//
  if ( Edges(0,iEdge) != Op ) // ����������� - ����� ����� ����, ��� �������� Op �������� ���������...
   continue;
//
  toOp = Edges(1,iEdge); // ��� ������������� ��� ���� �������� toOp !
//
  toTier = c_GetTierByOp ( toOp ); // �������� toOp ��������� �� ����� toTier
//
  if ( toTier < retTier ) // ������� toOp ���������� � retTier
   retTier = toTier;
//
 } // ����� ����� �� iEdge
//
 return retTier - 1 ; // ���������� ����� ����� �� 1 ������
//
} // --- ����� c_GetMaxTierMayBeOp ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetMinTierMaybeOp(INT Op)
{ // --- ���������� MIN ����� �����, �� ������� ����� ������������� �������� Op
// ----- ��� ������� � ���������� ����� ������������ ����� ��������� ����� -----
 INT fromOp, fromTier,
     retTier = 0;
//
 if( !isEdges ) // ������ Mem_Edges[] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 if( c_IsOpExistOnTier(Op, 1) ) // ...�������� Op ��������� �� ������ �����
  return 1 ; // ���� ��������� ����������!
//
// --- � ��������� Op ������� GetInToOp(Op) ������� (In) ���... ���� ��!
 for(INT iEdge=1; iEdge<=nEdges;  iEdge++) // �� ���� ����� � �����...
 {
//
  if ( Edges(1,iEdge) != Op ) // ����������� - ����� ����� ����, ��� �������� Op �������� ��������...
   continue;
//
  fromOp = Edges(0,iEdge); // ��� ������������� ��� ���� ��������� fromOp !
//
  fromTier = c_GetTierByOp ( fromOp ); // �������� fromOp ��������� �� ����� fromTier
//
  if ( fromTier > retTier ) // �������� fromOp ���������� � retTier
   retTier = fromTier;
//
 } // ����� ����� �� iEdge
//
 return retTier + 1 ; // ���������� ����� ����� �� 1 ������
//
} // --- ����� c_GetMinTierMayBeOp ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_MoveOpTierToTier(INT Op, INT toTier)
{ // --- ��������� �������� Op �� ���� toTier � ��������� ������������ ��������
// ----- �� ���� ��������������� ���������� Op �� toTier �� ����� ���� ������� ������ ��� ���������
// ----- ���� ������� ������������ ��������� - ������������ TRUE � ���������� iMove
//
 if( !isTiers ) // ���� ������� Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 INT fromTier = c_GetTierByOp( Op ); // ���� ��������������� ���������� ��������� Op
//
 if( ( fromTier < 1 ) || // � ������� ����� �������� ��������� �����, � � �������� - ������!
     ( fromTier > nTiers ) ) // � ���������� ����� �������� ������� �����, � � ����� ������� - ������!
 {
  DisplayMessage( "E", __FUNC__, messParams1, FALSE ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 if( fromTier == toTier ) // �� ������-� ������ ���������-�... �������� �������� !!!
 {
//  DisplayMessage( "E", __FUNC__, messParams2, FALSE ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 if( ( toTier < c_GetMinTierMaybeOp( Op ) ) || // �������� ������������ ��������
     ( toTier > c_GetMaxTierMaybeOp( Op ) ) )
 {
  DisplayMessage( "E", __FUNC__, messParams3, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( ( Tiers(toTier,0)+1 ) >= _maxOpsOnTier ) // �� ���������� � _maxOpsOnTier...
  if( IncreaseOpsOnTier( toTier, _maxOpsOnTier * stockMem, 111 ) == FALSE ) // ������� ����������������� ������
  {
   isTiers = FALSE ; // ������ Tiers[][] �� ������...
   return FALSE ;
  }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// --- ��������� �������� Op �� ���� toTier ------------------------------------
// --- �������, ��� ������� ��������� � ����� ������� ���� �� ����� - ��� �� ���������!
 Tiers(toTier,0) ++ ; // ��������� ����� ���������� �� ����� toTier
 Tiers(toTier,Tiers(toTier,0) ) = Op;
//
// --- ������� �������� Op c ����� fromTier ------------------------------------
 for(INT j=1; j<=Tiers(fromTier,0); j++) // �� ���������� ����� fromTier
  if( Tiers(fromTier,j) == Op )
  {
   for(INT jj=j; jj<Tiers(fromTier,0); jj++) // �������� �� ������� �����
    Tiers(fromTier,jj) = Tiers(fromTier,jj+1);
//
   Tiers(fromTier,0) -- ; // ��������� �� ������� ����� ���������� �� ����� fromTier
//
   nMoves ++ ; // ������ ��� �������� ����� �������� �����������
//
   return TRUE ;
  } // ����� if
//
} // --- ����� c_MoveOpTierToTier ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_AddTier(INT Tier)
{ // --- ������ (������) ���� ���� ����� Tier (����� ����������)
// ----- ����� �� ��������; ���������� TRUE, ���� ������
 char str[_2048];
//
 if( !isTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier <  0 ) ||  // ����� ������...  � �� ��������� ����� !
     ( Tier > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// if( ( nTiers+1 ) >= _maxTiers ) // �� ������� ����� � ������� Tiers[][]
 if( ( nTiers+3 ) >= _maxTiers ) // �� �� �����, �� ����� �������� �����
 {
// --- ����������� _maxTiers, � _maxOpsInTier ��������� ��� �� ����� -----------
// --- � ���� ������ ����� ������������ realloc, �������������� ����������� ������
   _maxTiers *= stockMem; // ����� ����� ����� � ������� stockMem
//
   pTiers = (INT*) realloc( pTiers, (_maxTiers+1) * (_maxOpsOnTier+1) * sizeof(INT) ); // ������ ������ ��� ����� ������
//
   if( !pTiers ) // ������ ����� - ������ � "����" �����������
   {
    snprintf(str,sizeof(str), "%s(): �������� ������ ��� ���������� ������� ������ (Prim0). ����������� %d x %d = %d ���������...",
                 _maxTiers+1, _maxOpsOnTier+1, (_maxTiers+1) * (_maxOpsOnTier+1));
    MessageBeep(MB_OK); // �������� ��������������...
    isTiers = FALSE ; // ������ Tiers[][] �� ������...
    DisplayMessage( "E", __FUNC__, str, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
    return ERR_NOT_MASSIVE_TIERS ;
   } // ����� if ( npTiers == NULL )
//
   snprintf(str,sizeof(str), "������ ������ (Prim0) �������������� �� %d x %d = %d ���������",
                 _maxTiers+1, _maxOpsOnTier+1, (_maxTiers+1) * (_maxOpsOnTier+1));
   DisplayMessage( "I", __FUNC__, str, 0 ); // ������ ���������
  }  // ����� if( nTiers+1 >= _maxTiers ) ...
//
// --- �� ������� - ����� ���������� �������� ��� � ����� pTiers --------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

 nTiers ++ ; // ��������� ����� ������ �� 1

// --- �������� ����� � Tier �� nTiers-1 ���� ----------------------------------
 for(INT iTier=nTiers; iTier>Tier; iTier--) // �� ������ ����� �����
  for(INT j=0; j<=Tiers(iTier-1,0); j++) // ���� �� "��������" �� ����
   Tiers(iTier,j) = Tiers(iTier-1,j); // "�������" ��������� � "������"

 Tiers( Tier+1,0 ) = 0; // ����� ��������� ���� ���� !

 return TRUE ; // ������� ���������

} // --- ����� c_AddTier -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_DelTier(INT Tier)
{ // --- ���������� (������) ���� Tier (����� ��������)
// ----- ����� �� ��������; ���������� TRUE, ���� ������
//
 if( !isTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier <= 0 ) ||  // ����� ������!..
     ( Tier >  nTiers ) ||
     ( ( Tiers(Tier,0) != 0 ) ) ) // ���� ���� �� ���� !
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
// --- �������� ����� � Tier+1 �� nTiers ����� ---------------------------------
 for(INT iTier=Tier; iTier<=nTiers; iTier++) // �� ������ ������ �����
  for(INT j=0; j<=Tiers(iTier+1,0); j++) // ���� �� "�������" �� ����
   Tiers(iTier,j) = Tiers(iTier+1,j); // "������" ��������� � "�������"

 nTiers -- ; // ������ ����� �� 1 ������...

 return TRUE ; // ������� ���������

} // --- ����� c_DelTier -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountEdges()
{ // ���������� ����� ����� ��� � �������������� ����� ��������� (���)
//
 if( !isEdges ) // ��� ������� Mem_Edges[]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 return nEdges ;
} // --- ����� c_GetCountEdges -------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountTiers()
{ // ���������� ����� ������ � ��� ��������������� ����� ��������� (���) ��� �������� (��������) �����
//
 if( !isTiers ) // ��� ������� Tiers[][]
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 return nTiers ;
} // --- ����� c_GetCountTiers -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetOpsMoves()
{ // ���������� ������� �������� ����� ����������� ���������� � ����� �� ���� ���
 return nMoves ;
} // --- ����� c_GetOpsMoves -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CountMovesZeroing()
{ // �������� �������� �������� ����� ����������� ���������� � ����� �� ���� ���
 INT old = nMoves ; // ���������
 nMoves = 0 ;
 return old ; // �������
} // --- ����� c_GetOpsZeroing -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOpsOnTier(INT Tier)
{ // ���������� ���������� ���������� �� ����� Tier ��� ��� ������� ���
//
 if( ( Tier < 0 ) || ( Tier > nTiers) ) // �������� ������������ �������� Tier
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 return Tiers(Tier,0) ;
} // --- ����� c_GetCountOpsInTier----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetOpByNumbOnTier(INT Numb, INT Tier)
{ // ���������� ����� Numb-���� �� ����� ��������� �� ����� Tier
//
 if( ( Tier < 0 ) || ( Tier > nTiers ) ) // �������� ������������ �������� Tier
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 if( ( Numb < 1 ) || ( Numb > Tiers(Tier,0) ) ) // �������� ������������ �������� Numb
 {
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 return Tiers(Tier,Numb) ;
//
} // --- ����� c_GetOpByNumbOnTier----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_AddLineToTextFrame(char *str)
{ // ��������� ������ str � ���� ���������� ������������� ������ (����������� "\n")
 char c, cc[2] = "?\0", buf[_16384] = "\0"; // buf - "�������" ������ ��� ������
//
 for(int Pos=0; Pos<=strlen(str); Pos++) // Pos - ����� ������� � ������ str
 {
  c = str[Pos]; // ��������� Pos-� ������ ������ str
  if ( (c != '\n') && (c != '\0') ) // ��� �� UPR-������ (�����������) � �� ����� ������
  {
   cc[0] = c;
   strcat( buf, cc ); // ��������� ������ � � buf
  } // ����� if( c != UPR )
//
  else
//
//  if( (c=='\n') || (c=='\0') ) // ����������� ������ ��� ����� ������
  {
   TM1->Lines->Add( buf ); // ����� ������ buf � M1
   strNcpy( buf, "" ); // �������� ������ w ��� ���������� ������
//
//   Application->ProcessMessages(); // ���� ���������� Windows
  }
//
 } // ����� �� �������� ������ str
//
 return TRUE ; // ��� Lua ������ ���� ���-�� ���������� (void �� �����������!)
//
} // --- ����� c_AddLineToTextFrame --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ClearTextFrame()
{ // ������� ����  ���������� �������������
 TM1->Clear(); // ������� M1
 return TRUE ; // ��� Lua ������ ���� ���-�� ���������� (void �� �����������!)
} // --- ����� ClearTextFrame --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_DelayMS(INT Sec)
{ // ��� Sec ������, ����� ��� ���� ���������� Windows
 Delay ( Sec ); // ����� Sec ������
 return TRUE ; // ��� Lua ������ ���� ���-�� ���������� (void �� �����������!)
} // --- ����� c_DelayMS -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutTiersToTextFrame()
{ // ����� ��� (������ Tiers[][]) � ���� ��� ��������� ������������
 char str[_16384], tmp[_512];
//
 if( !isTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 t_printf( "\n-=- ������ ��� = %d -=-", nTiers ); // ������ � ������ ������
//
// --- ������� � M1 ������ ���������� �� ������ --------------------------------
 for(INT iTier=0; iTier<=nTiers; iTier++) // �� ���� ���������� ������ ���
 {
  snprintf(str,sizeof(str), "%d|%d: ", iTier,Tiers(iTier,0)); // ������� ������ (iTier ����) ��� ������ � M1
//
  for(INT j=1; j<=Tiers(iTier,0); j++) // �� ������� ���������� �� ����� iTier
  {
   if( !c_GetCountInEdgesByOp( Tiers(iTier,j) )) // � ����� ��������� ��� �������� ���...
    snprintf(tmp,sizeof(tmp), _IN,  Tiers(iTier,j)); // ��� �������� �������� (��������� ���������)
   else
   if( !c_GetCountOutEdgesByOp( Tiers(iTier,j) )) // � ����� ��������� ��� ��������� ���...
    snprintf(tmp,sizeof(tmp), _OUT, Tiers(iTier,j)); // ��� �������� �������� (��������� ���������)
   else
    snprintf(tmp,sizeof(tmp), " %d", Tiers(iTier,j) ); // ������ ���������� ��������� ��� �������� ������
//
   strcat(str, tmp); // ����������� �������� ������ � str

  } // ����� ����� �� j
//
  c_AddLineToTextFrame( str ); // ����� ������� ������ � M1 (���� iTier)
//
 } // ����� ����� �� iTier (������ ���)
//
// c_PutParamsTiers(); // ����� ���������� ����� � ��� ��� �� ������� ����� � � ���� ���������
//
 return TRUE ; // �� ������� �������
//
} // --- ����� c_PutTiersToTextFrame -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutEdgesToTextFrame()
{ // ����� ������ ��� Mem_Edges[] � ���� ��� ������������
 char str[_2048];
//
 if( !isEdges ) // ���� ������ Edges[][] ���� - ����� � ������� FALSE
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 t_printf( "\n-=- ��� ��� = %d -=-", nEdges ); // ������ � ����� ������ ���
//
// --- ������� � M1 ��� ����
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ���������� ����� ��������������� ����� ���������
  t_printf( "#%d: %d -> %d", iEdge, Edges(0,iEdge), Edges(1,iEdge) ); // ������� ������ ��� ���� iEdge
//
 return TRUE; // �� ��������� - ������ Mem_Edges[] ����� � ��������� ����
//
} // --- ����� c_PutEdgesToTextFrame--------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_SoundPlay(char FileName[])
{ // ��������� ������� �� ��������� �����
 return PlaySound( FileName, 0, SND_SYNC ); // ��������� ���� � ���������� ������ (����� ����� ���������)
} // --- ����� c_PlaySound------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall TestExistInOutAtAllOps()
{ // ��������� ������� ���� ����� ������� ��� �������� ���� � ������� ���������
 INT Op; // ����� ���������
 char str[_256];
 bool Err = FALSE; // ������������ ��������
//
 if( !isTiers ) // ��� ������� Tiers[][]
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 for(INT iTier=1; iTier<=nTiers; iTier++) // �� ���� ������ ���
  for(INT j=1; j<=Tiers(iTier,0); j++) // �� ���������� �� ���� �����
  {
   Op = Tiers(iTier,j); // ����� ����� ���������
//
// --- ���� �� ������� �������� ��� --------------------------------------------
   if( !c_GetCountInEdgesByOp( Op ) && ( iTier != 1 ) ) // �� �� ������ ����� "�" �������� ��� ���
   {
    t_printf( "\n-W- �������� %d �� �� ������ ����� %d �� ����� �������� ��� -W-", Op, iTier );
    Err = TRUE ;
   }
//
// --- ���� �� ������� ��������� ��� -------------------------------------------
   if( !c_GetCountOutEdgesByOp( Op ) && ( iTier != nTiers ) ) // �� �� ��������� ����� "�" ��������� ��� ���
   {
    t_printf( "\n-W- �������� %d �� �� ��������� ����� %d �� ����� ��������� ��� -W-", Op, iTier );
    Err = TRUE ;
   }
//
  } // ����� ����� �� j
//
 if( !Err ) // �������������� ���������
 {
  MessageBeep(MB_OK); // �������� ��������������...
  SB0->Text = " ��� ��������� ����� ���� �� �� ����� �������� � ��������� ����...";
  Delay( -1 ); // ��� 1 ���
 }
//
 return Err ;
//
} // --- ����� TestExistInOutAtOp-----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountInEdgesByOp(INT Op)
{ // --- ������� ����� �������� ��� ��� ��������� Op ---------------------------
 INT nIn = 0, iEdge;
//
 if( !isEdges ) // ������ Mem_Edges[] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(INT i=0; i<=1; i++) // �������� ������� Op � ������ ����������
  for(iEdge=1; iEdge<=nEdges; iEdge++)
   if( Op == Edges(i,iEdge) )
    goto find_Op;
//
 return ERR_IN_DATA; // �������� Op �� ������ � ������ ������������
//
find_Op: // �������� Op ������ � ������ ������������
//
 for(iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� �����
  if( Edges(1,iEdge) == Op )  // ����� ����, �������� � ������ �������� Op...
   nIn ++ ;
//
 return nIn ; // ������������ 0, ���� ��� ������� (�������� ������ ��� ���������� ���������) ��������
//
} // --- ����� c_GetCountInEdgesByOp -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOutEdgesByOp(INT Op)
{ // --- ������� ����� ��������� ��� ��� ��������� Op --------------------------
 INT nOut = 0, iEdge;
//
 if( !isEdges ) // ������ Mem_Edges[] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 for(INT i=0; i<=1; i++) // �������� ������� Op � ������ ����������
  for(iEdge=1; iEdge<=nEdges; iEdge++)
   if(Op == Edges(i,iEdge))
    goto find_Op;
//
 return ERR_IN_DATA; // �������� Op �� ������ � ������ ������������
//
find_Op: // �������� Op ������ � ������ ������������
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� �����
  if( Edges(0,iEdge) == Op )  // ����� ����, ��������� �� ������� ���������...
   nOut ++ ;
//
 return nOut ; // ������������ 0, ���� ��� �������� (��������� ���������� ���������) ��������
//
} // --- ����� c_GetCountOutEdgesByOp ------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbInEdgeByOp(INT Numb, INT Op)
{ // --- ������� ����� ���������, ��������������� Numb-��� �������� ���� ��� ��������� Op
 INT nIn = 0,
     maxNumb = c_GetCountInEdgesByOp( Op ); // ����� ����� �������� ��� ��������� Op
//
 if( !isEdges ) // ������ Mem_Edges[] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 if( ( Numb < 1 ) || ( Numb > maxNumb) ) // ��� ���������...
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� �����
  if( Edges(1,iEdge) == Op )  // ����� ����, �������� � ������ �������� Op...
  {
   nIn ++ ;
   if( nIn == Numb )
    return Edges(0,iEdge) ;
  }
//
  return ERR_COMMON ; // ���� �� ����� �� ����� ����...
//
} // --- ����� c_GetNumbInEdgeByOp ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbOutEdgeByOp(INT Numb,INT Op)
{ // --- ������� ����� ��������� ��� ��� ��������� Op --------------------------
 INT nOut = 0,
     maxNumb = c_GetCountOutEdgesByOp( Op ); // ����� ����� ��������� ��� ��������� Op;
//
 if( !isEdges ) // ������ Mem_Edges[] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Numb < 1 ) || ( Numb > maxNumb ) ) // ��� ���������...
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� �����
  if( Edges(0,iEdge) == Op )  // ����� ����, ��������� �� ������� ���������...
  {
   nOut ++ ;
   if( nOut == Numb )
    return Edges(1,iEdge) ;
  }
//
 return 0 ; // ���� �� ����� �� ����� ����...
//
} // --- ����� c_GetNumbOutEdgeByOp --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// ���� �������������� ��������������� ���� ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// ������� ������������ --------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountParamsByCalc(INT Calc)
{ // --- ���������� ����� ���������� ����������� �alc --------------------------
 char str[_4096];
 INT k = 0;
//
 strNcpy( str, c_GetParamsByCalc( Calc )  ); // ���� ��� ������ ����������
//
 for( INT i=0; str[i+1] != '\0'; i++ ) // �� ������ ���������� �� ��� �������
  if ( (str[i]=='-') && (isalpha(str[i+1])) ) // �������� �� ������ ['-' + ���.�����]
   k ++ ; // ���������, ����� ��� ����������� ['-' + ���.�����]
//
 return ( k ) ;
} // --- ����� c_GetCountParamsByCalc ------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
REAL __fastcall c_GetMinValNumbParamByCalc(INT Numb, INT Calc) // ��� �������� ��������� Numb (������� � 1) ����������� Calc
{ // ����� ��� �������� ��������� ����� Numb (������� � 1) ����������� Calc ---
 char str[_1024],
      sName[_512]; // ��� ���������
 REAL minVal,maxVal; // �������� ����������

 strNcpy( str, c_GetNumbParamByCalc( Numb, Calc ) ); // ����� ������ ���������

 if( sscanf( str, "-%s %g %g", sName, &minVal, &maxVal ) == 3 ) // ���� Ok - 3 ��������������� ���������
  return min( minVal, maxVal );
 else
  return ERR_TRANSFORM ;

} // --- ����� c_GetMinValNumbParamByCalc --------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
REAL __fastcall c_GetMaxValNumbParamByCalc(INT Numb, INT Calc) // ��� �������� ��������� Numb (������� � 1) ����������� Calc
{ // ����� ��� �������� ��������� ����� Numb (������� � 1) ����������� Calc ---
 char str[_1024],
      sName[_512]; // ��� ���������
 REAL minVal,maxVal; // �������� ����������

 strNcpy( str, c_GetNumbParamByCalc( Numb, Calc ) ); // ����� ������ ���������

 if( sscanf( str, "-%s %g %g", sName, &minVal, &maxVal ) == 3 ) // ���� Ok - 3 ��������������� ���������
  return max( minVal, maxVal ) ;
 else
  return ERR_TRANSFORM ;

} // --- ����� c_GetMaxValNumbParamByCalc --------------------------------------

////////////////////////////////////////////////////////////////////////////////
// ������� ���������� ----------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountParamsByOp(INT Op)
{ // --- ���������� ����� ���������� ��������� Op ------------------------------
 char str[_1024];
 INT k=0;

 strNcpy( str, c_GetParamsByOp( Op )  ); // ���� ��� ������ ����������

 for(INT i=0; str[i+1] != '\0'; i++) // �� ������ ���������� �� ��� �������
  if ( ( str[i] == '-' ) && ( isalpha( str[i+1] ) ) ) // �������� �� '-' + ���.�����
   k ++ ; // ���������, ����� ��� ����������� "'-'+���.�����"

 return ( k ) ;
} // --- ����� c_GetCountParamsByOp --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNameNumbParamByCalc(INT Numb, INT Calc)
{ // ��� ��������� ����� Numb (������� � 1) ����������� Calc -------------------
 char str[_1024],
      sName[_512]; // ��� ���������
 REAL minVal,maxVal; // �������� ����������

 strNcpy( str, c_GetNumbParamByCalc( Numb, Calc ) ); // ����� ������ ���������

 if( sscanf( str, "-%s %g %g", sName, &minVal, &maxVal ) == 3 ) // ���� Ok - 3 ��������������� ���������
  return sName ;
 else
  return "\0" ;

} // --- ����� c_GetNameNumbParamByCalc ----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNameNumbParamByOp(INT Numb, INT Op)
{ // ��� ��������� ����� Numb (������� � 1) ��������� Op -----------------------
 char str[_1024],
      sName[_1024]; // ��� ���������
 REAL Val; // �������� ���������

 strNcpy( str, c_GetNumbParamByOp( Numb, Op ) ); // ����� ������ ���������

 if( sscanf( str, "-%s %g", sName, &Val ) == 2 ) // ���� Ok - 2 ��������������� ���������
  return sName ;
 else
  return "\0" ;

} // --- ����� c_GetNameNumbParamByOp ----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
REAL __fastcall c_GetValNumbParamByOp(INT Numb, INT Op)
{ // ����� ��� �������� ��������� ����� Numb (������� � 1) ��������� Op -------
 char str[_1024],
      sName[_1024]; // ��� ���������
 REAL Val; // �������� ���������

 strNcpy( str, c_GetNumbParamByOp( Numb, Op ) ); // ����� ������ ���������

 if( sscanf( str, "-%s %g", sName, &Val ) == 2 ) // ���� Ok - 2 ��������������� ���������
  return Val ;
 else
  return ERR_TRANSFORM ;

} // --- ����� c_GetValNumbParamByOp -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_LoadFileNameParamsCalcs( char FileName[] )
{ // �������� ��� ����� � ��������� ���� ���������� ������������
//
 if( !FileExists( FileName ) ) // �������� ���� �� ����������...
 {
  t_printf( "\n-W- ���� %s ���������� ������������ �� ���������� -W-\n", FileName );
 }
 else // � ������ �� Ok!
 {
  strNcpy( FileNameParamsCalcs, FileName ); // ��������� ������� ��� ����� ���������� ������������
  c_ReadAndCorrectParamsCalcs( FileNameParamsCalcs ); // ������������ � ������������ ���� ���������� ������������
  return TRUE;
 } // �� ��������� � �������� ������... �������� ������ !
//
////////////////////////////////////////////////////////////////////////////////
 if( !FileExists( DefFileNameParamsCalcs ) ) // ���� �� ��������� �� ����������...
  t_printf( "\n-E- ���� %s ���������� ������������ �� ��������� �� ���������� -E-\n",
                   AnsiUpperCase(DefFileNameParamsCalcs) );
 else // � ������ �� Ok!
 {
  t_printf( "-I- �������������� ���� %s ���������� ������������ �� ��������� -I-\n",
                 AnsiUpperCase(DefFileNameParamsCalcs) );
//
  strNcpy( FileNameParamsCalcs, DefFileNameParamsCalcs );
  c_ReadAndCorrectParamsCalcs( FileNameParamsCalcs );
  return TRUE;
//
 } // �� ��������� � ������ � ������ �� ���������... �������� ������ !
//
////////////////////////////////////////////////////////////////////////////////
// --- �� ������� ������� �� �������� ����, �� ���� � ������ �� ��������� ------
 strNcpy( sCalcs, "\0" ); // ������� ������-������ ���������� ������������
 return FALSE; // �������� � ������...
//
} // --- ����� c_LoadFileNameParamsCalcs =======================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_LoadFileNameParamsOps( char FileName[] )
{ // �������� ��� ����� � ��������� ���� ���������� ����������
 char str[_2048];

 if( !FileExists( FileName ) ) // �������� ���� �� ����������...
 {
  t_printf( "\n-W- ���� %s ���������� ���������� �� ���������� -W-\n",
                   FileName );
 }
 else // � ������ �� Ok!
 {
  strNcpy( FileNameParamsOps, FileName ); // ��������� ������� ��� ����� ���������� ����������
  c_ReadAndCorrectParamsOps( FileNameParamsOps ); // ������������ � ������������ ���� ���������� ����������
  return TRUE;
 } // �� ��������� � �������� ������... �������� ������ !

////////////////////////////////////////////////////////////////////////////////
 if( !FileExists( DefFileNameParamsOps ) ) // ���� �� ��������� �� ����������...
  t_printf( "\n-E- ���� %s ���������� ���������� �� ��������� �� ���������� -E-\n",
                   AnsiUpperCase(DefFileNameParamsOps) );
 else // � ������ �� Ok!
 {
  t_printf( "-I- �������������� ���� %s ���������� ���������� �� ��������� -I-\n",
                 AnsiUpperCase(DefFileNameParamsOps) );

  strNcpy( FileNameParamsOps, DefFileNameParamsOps );
  c_ReadAndCorrectParamsOps( FileNameParamsOps );
  return TRUE;
//
 } // �� ��������� � ������ � ������ �� ���������... �������� ������ !
//
////////////////////////////////////////////////////////////////////////////////
// --- �� ������� ������� �� �������� ����, �� ���� � ������ �� ��������� ------
 strNcpy( sOps, "\0" ); // ������� ������-������ ���������� ����������

 return FALSE; // �������� � ������...

} // --- ����� c_LoadFileNameParamsOps =========================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_LoadFileNameParamsEdges( char FileName[] )
{ // �������� ��� ����� � ��������� ���� ������ ���
//
 if( !FileExists( FileName ) ) // �������� ���� �� ����������...
 {
  t_printf( "\n-W- ���� %s ���������� ��� �� ���������� -W-\n", FileName );
 }
 else // � ������ �� Ok!
 {
  strNcpy( FileNameParamsEdges, FileName ); // ��������� ������� ��� ����� ���������� ���
  c_ReadAndCorrectParamsEdges( FileNameParamsEdges ); // ������������ � ������������ ���� ���������� ���
  return TRUE;
 } // �� ��������� � �������� ������... �������� ������ !
//
////////////////////////////////////////////////////////////////////////////////
 if( !FileExists( DefFileNameParamsEdges ) ) // ���� �� ��������� �� ����������...
  t_printf( "\n-E- ���� %s ���������� ��� �� ��������� �� ���������� -E-\n",
                   AnsiUpperCase(DefFileNameParamsEdges) );
 else // � ������ �� Ok!
 {
  t_printf( "-I- �������������� ���� %s ���������� ��� �� ��������� -I-\n",
                 AnsiUpperCase(DefFileNameParamsEdges) );
  strNcpy( FileNameParamsEdges, DefFileNameParamsEdges );
  c_ReadAndCorrectParamsEdges( FileNameParamsEdges );
  return TRUE;
//
 } // �� ��������� � ������ � ������ �� ���������... �������� ������ !
//
////////////////////////////////////////////////////////////////////////////////
// --- �� ������� ������� �� �������� ����, �� ���� � ������ �� ��������� ------
 strNcpy( sEdg, "" ); // ������� ������-������ ���������� ���
 return FALSE; // �������� � ������...
//
} // --- ����� c_LoadFileNameParamsEdges =======================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool  __fastcall c_LoadFileNameParamsVertices( char FileName[] )
{ // �������� ��� ����� � ��������� ���� ������ ������
//
  if( !FileExists( FileName ) ) // �������� ���� �� ����������...
 {
  t_printf( "\n-W- ���� %s ���������� ������ �� ���������� -W-\n", FileName );
 }
 else // � ������ �� Ok!
 {
  strNcpy( FileNameParamsVertices, FileName ); // ��������� ������� ��� ����� ���������� ������
  c_ReadAndCorrectParamsVertices( FileNameParamsVertices ); // ������������ � ������������ ���� ���������� ������
  return TRUE;
 } // �� ��������� � �������� ������... �������� ������ !
//
////////////////////////////////////////////////////////////////////////////////
 if( !FileExists( DefFileNameParamsVertices ) ) // ���� �� ��������� �� ����������...
  t_printf( "\n-E- ���� %s ���������� ������ �� ��������� �� ���������� -E-\n",
                   AnsiUpperCase(DefFileNameParamsVertices) );
 else // � ������ �� Ok!
 {
  t_printf( "-I- �������������� ���� %s ���������� ������ �� ��������� -I-\n",
                 AnsiUpperCase(DefFileNameParamsVertices) );

  strNcpy( FileNameParamsVertices, DefFileNameParamsVertices );
  c_ReadAndCorrectParamsVertices( FileNameParamsVertices );
  return TRUE;
//
 } // �� ��������� � ������ � ������ �� ���������... �������� ������ !
//
////////////////////////////////////////////////////////////////////////////////
// --- �� ������� ������� �� �������� ����, �� ���� � ������ �� ��������� ------
 strNcpy( sVrt, "\0" ); // ������� ������-������ ���������� ������
 return FALSE; // �������� � ������...
//
} // --- ����� c_LoadFileNameParamsVertices ====================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountParamsInString( char* str )
{ // --- ���������� ����� ���������� � ������ str ------------------------------
 INT k=0;
//
 for( INT i=0; str[i+1] != '\0'; i++ ) // �� ������ ���������� �� ��� �������
  if ( (str[i]=='-') && (isalpha(str[i+1])) ) // �������� �� [-]+[���.�����]
   k ++ ; // ���������, ����� ��� ����������� ������ ['-' + ���.�����]
//
 return ( k ) ;
} // --- ����� c_GetCountParamsInString ----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNumbParamInString(INT Numb, char* str)
{ // --- ���������� ��������� Numb ������ ���������� � ������ str --------------
// --- ���� �������������� ������ [-]+[���.�����] ==============================
 char s_ret[_2048]="\0";
 register INT k,j,i;
 INT //m = 0,
     rep=0, // ����� ��������� �������
     len = strlen( str ); // ����� ������ str
//
// ���� �������������� ������ ��� ������ ��������� ���������� ------------------
 for( i=0; i<=len; i++ ) // ����� �� ������ ���������� �� ������������ �������
  if ( (str[i]=='-') && (isalpha(str[i+1])) ) // �������� �� ������ �������
  {
   rep ++ ; // ����� ������ ������� ����� rep (���������� � ������� i � ������ s)

   if( rep != Numb ) // ��� ����� �� ����...
    continue; // ���������� ���� �� i

// --- � ����� rep == Numb � �������� ������ ����� ��������� rep

   for( j=i+1; j<=len; j++ ) // ����� �� ������ ���������� �� ������� ==========
// --- ���� ������ ��� ������� ����� ��������� (��� �� ������ ���������) -------
// --- ������� ��������� ������� ����� � �� ���� = �� � ����� ����� ������ -----
    if ( ( (str[j]=='-') && (isalpha(str[j+1])) ) || // ����� �� ������ ���� ������
           ( (j+1)==len) ) // �� � ����� ����� ������ str
    { // ������� �������� ���������� � ������� i � ��������� j-1 (��� j==len) � ������ sdr

// --- ������ ������� - ��������� ���������� ������� ������ ���������, ������ - ������ ���� ������
     for( k=i; ((j+1)!=len)?(k<j-1):(k<=len ); k++ ) // �������� ��������� � s_ret
      s_ret[ k-i ] = str[ k ];
//
     strEndZero( s_ret ); // ������� "\0" � ����� ������
//
     DeleteSpacesTabsAround( s_ret ); // ������� ������� �������
     return s_ret ; // ���������� ���������
//
    } // ����� if �� str[j]
   } // ����� if �� str[i]
} // --- ����� c_GetNumbParamInString ------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNameNumbParamInString(INT Numb, char* str)
{ // ��� ��������� ����� Numb (������� � 1) � ������ str -----------------------
 char sW[_2048],
      sName[_1024]; // ��� ��������� (��� '-' � ������)
//
 strNcpy( sW, c_GetNumbParamInString( Numb, str ) ); // ����� ������ ���������
//
 if( sscanf( sW, "-%s", sName ) == 1 ) // ���� Ok - 1 ������������ ��������
  return sName ;
 else
  return "" ;
//
} // --- ����� c_GetNameNumbParamInString --------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsCorrectParamCalc(char* str)
{ // ���� ��������� ���������� ����������� ���������, ������������ TRUE
 bool out = FALSE;
 char sName[_128]; // ��� ��������� (��� '-' � ������)
 REAL minVal, maxVal; // ��������� �������� ����������
//
 if( sscanf( str, "-%s %g %g", sName, &minVal, &maxVal ) == 3 ) // ���� Ok - 3 ������������ ����������
 {
  snprintf( str,sizeof(str), "-%s %g %g", sName, min(minVal,maxVal), max(minVal,maxVal) ); // ����������� str �� ������������
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
} // --- ����� c_IsCorrectParamCalc --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsCorrectParamOpVertEdg(char* str)
{ // ���� ��������� ���������� ��������� ���������, ������������ TRUE
 bool out = FALSE;
 char sName[_128]; // ��� ��������� (��� '-' � ������)
 REAL Val; // ��������� �������� ���������
//
 if( sscanf( str, "-%s %g", sName, &Val ) == 2 ) // ���� Ok - 2 ������������ ����������
 {
  snprintf( str,sizeof(str), "-%s %g", sName, Val ); // ����������� str �� ������������
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
} // --- ����� c_IsCorrectParamOpVertEdg ---------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool _fastcall c_ReadAndCorrectParamsCalcs( char FileNameParamsCalcs[] )
{ // ���������� ������ ���� ���������� ������������ � ������ sCalcs � ������������ ���������
 INT n1,n2,
     ch; // �����!..
 char sN[_8192], // ��������� ������ ����������
      sP[_4096], // ��������� ����������� ���������
      s[_512],
      w[2] = "?\0";
//
 if( !ReadAndPrimWorkOpsCalcsVertEdgeFiles( FileNameParamsCalcs ) ) // ������ � sWork � ��������������� ����������
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
// --- �������� �������� sW � ����������� � sCalcs c ��������� ������������ ----
////////////////////////////////////////////////////////////////////////////////
//
 strNcpy( sCalcs, "\0" ); // �������� sCalcs
//
 INT iStart = 0, iEnd,
     lW = strlen( sWork ), // ����� ������ sW
     lPrevCalcs;
//
// int countSP = 0 ; // ������� ����� sP ������������� ���� ������� � ������ sN
//
 do // �� ���������� [=][�����][/][�����][:] ��� [=][Def:] ( �� sN )
 {
  iEnd = c_FindSubString( sWork, sN, iStart, 0 );
// --- ������ ��������� ������ sN ������ ���������� ��������� ------------------
//
  DeleteSpacesTabsAround( sN ); // �������� ������� �������
//
////////////////////////////////////////////////////////////////////////////////
  lPrevCalcs = strlen( sCalcs ) ; // ����� ������ sCalcs ����� ����������� '=n1/n2:' ��� '=Def:'
// ���� �������, ���� ����� ���������� ���������� ��������� �������
//
////////////////////////////////////////////////////////////////////////////////
// �� ������ �������� sN �������� ��������� '=n1/n2:' ��� '=Def:'
  if( sN[0]=='=' && isdigit(sN[1]) ) // ��������� ������������ "=n1/n2:^"
  {
// --- ������ ��������� ����������� '=n1/n2:^' ---------------------------------
  if( !Test_n1n2 ) // ������ "=n1/n2:^" �� sN (�o����� !=6 - ������ )
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // �� ���������!..
  {
//   F2->L_TMM->Caption = sN ;
//   Delay( -5 );
   snprintf( s,sizeof(s), "=%d/%d: ", n1, n2 );  // �������� ����� "=n1/n2:^"
   strcat( sCalcs, s );
///
   strNcpy( sN, strchr( sN,':' ) + 2 ) ; // ������ ����� ������ ����� ':'
//
   DeleteSpacesTabsAround( sN ); // �������� sN �� ������� ��������...
//
  } // ����� else... if( sscanf( sN, ...
  } // ����� if( sN[0]=='='...
//
////////////////////////////////////////////////////////////////////////////////
  else // if( sN[0]=='=' ...
////////////////////////////////////////////////////////////////////////////////
//
//  if( !( sN[0]=='='          && toupper(sN[1])=='D' && toupper(sN[2])=='E' &&
//         toupper(sN[3])=='F' &&  sN[4]==':' ) )
  if( ! cmp_def( sN ) ) // ��� ������ '=Def:'
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // �� ���������!..
  {
   snprintf( s,sizeof(s), "%s ", sDef );
   strcat( sCalcs, s );
//
//   DEL_TO_COLON // ������ ��� ������� SN �� 'xxx:'
   strNcpy( sN, strchr( sN,':' ) + 2 ) ; // ������ ����� ������ ����� ':'
//
   DeleteSpacesTabsAround( sN ); // �������� sN �� ������� ��������...
//
  }  // ����� ��������� ����������� "=Def:^"
//
// --- �������� ������ sN �� ��������� ���������� sP ---------------------------
//
 INT jStart = 0, jEnd,
     lN = strlen( sN ); // ����� ������ sN
//
 int countSP = 0 ; // ������� ����� sP ������������� ���� ������� � ������ sN
//
 do // �� ���������� [-][���.�����]
 {
  jEnd = c_FindSubString( sN, sP, jStart, 1 );
//
// --- ������ ��������� ������ ��������� sP ------------------------------------
//
// --- �������� �� ������������ ���������� �������� ���������� ���� ������������� sscanf(...)
  if( !c_IsCorrectParamCalc( sP ) )
  {
   jStart = jEnd ;
   continue; // ...do
  }
//
  countSP ++ ; // ...��� ���� ����������� ������..!
//
  strcat( sCalcs, sP ); // ����� ���������� � sCalcs
  strcat( sCalcs, " \0" );
//
// --- ����� ��������� ������ ��������� sP -------------------------------------
  jStart = jEnd;
 } while( jEnd !=lN ); // ���� �� ����� ������ sN ( ����� �����. do )
//
 if( countSP==0 )
  sOps[ lPrevCalcs ] = '\0' ;
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
//
  iStart = iEnd;
 } while( iEnd !=lW ); // ���� �� ����� ������ sW ( ����� �����. do )
//
 DeleteSpacesTabsAround ( sCalcs ); // ������� ������� �������
 ReplaceManySpacesOne( sCalcs ); // ������� ������� �������� ������
//
#ifdef TEST_PRINT //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 c_AddLineToTextFrame( sCalcs ); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif
//
 return TRUE;
//
} // --- ����� ReadAndCorrectParamsCalcs =======================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool _fastcall c_ReadAndCorrectParamsOps( char FileNameParamsOps[] )
{ // ���������� ������ ���� ���������� ������������ � ������ sOps � ������������ �������
 INT k, n1,n2,
     ch; // �����!..
 char // sWork[_16384] = "", // ������� ������ ��� ���������� ���������� ������������ (����������)
      sN[_8192], // ��������� ������ ����������
      sP[_4096], // ��������� ����������� ���������
      s[_512],
      w[2] = "?\0";
//
 if( !ReadAndPrimWorkOpsCalcsVertEdgeFiles( FileNameParamsOps ) ) // ������ � sWork � ��������������� ����������
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
// --- �������� �������� sW � ����������� � sOps c ��������� ������������ ------
////////////////////////////////////////////////////////////////////////////////
//
 strNcpy( sOps, "\0" ); // �������� sOps
//
 INT iStart = 0, iEnd,
     lW = strlen( sWork ), // ����� ������ sW
     lPrevOps;
//
// int countSP = 0 ; // ������� ����� sP ������������� ���� ������� � ������ sN
//
 do // �� ���������� [=][�����][/][�����][:] ��� [=][Def:] ( �� sN )
 {
  iEnd = c_FindSubString( sWork, sN, iStart, 0 );
// --- ������ ��������� ������ sN ������ ���������� ��������� ------------------
//
  DeleteSpacesTabsAround( sN ); // �������� ������� �������
//
////////////////////////////////////////////////////////////////////////////////
  lPrevOps = strlen( sOps ) ; // ����� ������ sOps ����� ����������� '=n1/n2:' ��� '=Def:'
// ���� �������, ���� ����� ���������� ���������� ��������� �������
//
////////////////////////////////////////////////////////////////////////////////
// �� ������ �������� sN �������� ��������� '=n1/n2:' ��� '=Def:'
  if( sN[0]=='=' && isdigit(sN[1]) ) // ��������� ������������ "=n1/n2:"
  {
// --- ������ ��������� ����������� '=n1/n2:^' ---------------------------------
  if( !Test_n1n2 ) // ������ "=n1/n2:^" �� sN (�o����� !=6 - ������ )
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // �� ���������!..
  {
   snprintf( s,sizeof(s), "=%d/%d: ", n1,n2 );  // �������� ����� "=n1/n2:^"
   strcat( sOps, s );
//
  strNcpy( sN, strchr( sN,':' ) + 2 ) ; // ������ ����� ������ ����� ':'
//
  DeleteSpacesTabsAround( sN ); // �������� sN �� ������� ��������...
//
  } // ����� if( sscanf( sN, ...
  } // ����� if( sN[0]=='='...
//
////////////////////////////////////////////////////////////////////////////////
  else // if( sN[0]=='=' ...
////////////////////////////////////////////////////////////////////////////////
//
  if( ! cmp_def( sN ) ) // ��� ��� ��� ������ '=Def:'
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // �� ���������!..
  {
   snprintf( s,sizeof(s), "%s ", sDef );
   strcat( sOps, s );
//
//   DEL_TO_COLON // ������ ��� ������� SN �� 'xxx:'
   strNcpy( sN, strchr( sN,':' ) + 2 ) ; // ������ ����� ������ ����� ':'
//
   DeleteSpacesTabsAround( sN ); // �������� sN �� ������� ��������...
//
  }  // ����� ��������� ����������� "=Def:^"
//
// --- �������� ������ sN �� ��������� ���������� sP ---------------------------
//
 INT jStart = 0, jEnd,
     lN = strlen( sN ); // ����� ������ sN
//
 int countSP = 0 ; // ������� ����� sP ������������� ���� ������� � ������ sN
//
 do // �� ���������� [-][���.�����]
 {
  jEnd = c_FindSubString( sN, sP, jStart, 1 );
//
// --- ������ ��������� ������ ��������� sP ------------------------------------
//
// --- �������� �� ������������ ���������� �������� ���������� ���� ������������� sscanf(...)
  if( !c_IsCorrectParamOpVertEdg( sP ) )
  {
   jStart = jEnd ;
   continue; // ...do
  }
//
  countSP ++ ; // ...��� ���� ����������� ������..!
//
  strcat( sOps, sP ); // ����� ���������� � sOps
  strcat( sOps, " \0" );
//
// --- ����� ��������� ������ ��������� sP -------------------------------------
  jStart = jEnd;
 } while( jEnd !=lN ); // ���� �� ����� ������ sN ( ����� �����. do )
//
 if( countSP==0 )
  sOps[ lPrevOps ] = '\0' ;
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
//
  iStart = iEnd;
 } while( iEnd !=lW ); // ���� �� ����� ������ sW ( ����� �����. do )
//
 DeleteSpacesTabsAround ( sOps ); // ������� ������� �������
 ReplaceManySpacesOne( sOps ); // ������� ������� �������� ������
//
#ifdef TEST_PRINT //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 c_AddLineToTextFrame( sOps ); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif
//
 return TRUE;
//
} // --- ����� ReadAndCorrectParamsOps =========================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool _fastcall c_ReadAndCorrectParamsEdges( char FileNameParamsEdges[] )
{ // ���������� ������ ���� ���������� ��������� � ������ sMess � ������������ �������
 INT k, n1,n2, m1,m2,
     ch; // �����!..
 char // sWork[_16384] = "", // ������� ������ ��� ���������� ���������� ������������ (����������)
      sN[_8192], // ��������� ������ ����������
      sP[_4096], // ��������� ����������� ���������
      s[_512],
      w[2] = "?\0";
//
 if( !ReadAndPrimWorkOpsCalcsVertEdgeFiles( FileNameParamsEdges ) ) // ������ � sWork � ��������������� ����������
  {
   strNcpy( sEdg, "\0" );
   return FALSE;
  }
//
////////////////////////////////////////////////////////////////////////////////
// --- �������� �������� sW � ����������� � sEdg c ��������� ������������ ------
////////////////////////////////////////////////////////////////////////////////
//
 strNcpy( sEdg, "\0" ); // �������� sEdg
//
 INT iStart = 0, iEnd,
     lW = strlen( sWork ), // ����� ������ sW
     lPrevOps;
//
// int countSP = 0 ; // ������� ����� sP ������������� ���� ������� � ������ sN
//
 do // �� ���������� [=][�����][/][�����][:] ��� [=][Def:] ( �� sN )
 {
  iEnd = c_FindSubString( sWork, sN, iStart, 0 );
// --- ������ ��������� ������ sN ������ ���������� ��������� ------------------
//
  DeleteSpacesTabsAround( sN ); // �������� ������� �������
//
////////////////////////////////////////////////////////////////////////////////
  lPrevOps = strlen( sEdg ) ; // ����� ������ sEdg ����� ����������� '=n1/n2|m1/m2:' ��� '=Def:'
// ���� �������, ���� ����� ���������� ���������� ��������� �������
//
////////////////////////////////////////////////////////////////////////////////
// �� ������ �������� sN �������� ��������� '=n1/n2|m1/m2:' ��� '=Def:'
  if( sN[0]=='=' && isdigit(sN[1]) ) // ��������� ������������ "=n1/n2|m1/m2:"
  {
// --- ������ ��������� ����������� '=n1/n2|m1/m2:^' ---------------------------------
//  if( sscanf( sN, "=%d/%d|%d/%d: ", &n1, &n2, &m1, &m2 ) != 4 ) // ������ n1/n2|m1/m2 �� sN (�o����� !=4 - ������ )
  if( !Test_n1n2m1m2 ) // ������ "=n1/n2|m1/m2:^" �� sN (�o����� !=10 - ������ )
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // �� ���������!..
  {
   snprintf( s,sizeof(s), "=%d/%d|%d/%d: ", n1,n2, m1,m2 );  // �������� ����� "=n1/n2|m1/m2:^"
   strcat( sEdg, s );
//
  strNcpy( sN, strchr( sN,':' ) + 2 ) ; // ������ ����� ������ ����� ':'
//
  DeleteSpacesTabsAround( sN ); // �������� sN �� ������� ��������...
//
  } // ����� if( sscanf( sN, ...
  } // ����� if( sN[0]=='='...
//
////////////////////////////////////////////////////////////////////////////////
  else // if( sN[0]=='=' ...
////////////////////////////////////////////////////////////////////////////////
//
  if( ! cmp_def( sN ) ) // ��� ��� ��� ������ '=Def:'
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // �� ���������!..
  {
   snprintf( s,sizeof(s), "%s ", sDef );
   strcat( sEdg, s );
//
   strNcpy( sN, strchr( sN,':' ) + 2 ) ; // ������ ����� ������ ����� ':'
//
   DeleteSpacesTabsAround( sN ); // �������� sN �� ������� ��������...
//
  }  // ����� ��������� ����������� "=Def:^"
//
// --- �������� ������ sN �� ��������� ���������� sP ---------------------------
//
 INT jStart = 0, jEnd,
     lN = strlen( sN ); // ����� ������ sN
//
 int countSP = 0 ; // ������� ����� sP ������������� ���� ������� � ������ sN
//
 do // �� ���������� [-][���.�����]
 {
  jEnd = c_FindSubString( sN, sP, jStart, 1 );
//
// --- ������ ��������� ������ ��������� sP ------------------------------------
//
// --- �������� �� ������������ ���������� �������� ���������� ���� ������������� sscanf(...)
  if( !c_IsCorrectParamOpVertEdg( sP ) )
  {
   jStart = jEnd ;
   continue; // ...do
  }
//
  countSP ++ ; // ...��� ���� ����������� ������..!
//
  strcat( sEdg, sP ); // ����� ���������� � sEdg
  strcat( sEdg, " \0" );
//
// --- ����� ��������� ������ ��������� sP -------------------------------------
  jStart = jEnd;
 } while( jEnd !=lN ); // ���� �� ����� ������ sN ( ����� �����. do )
//
 if( countSP==0 )
  sOps[ lPrevOps ] = '\0' ;
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
//
  iStart = iEnd;
 } while( iEnd !=lW ); // ���� �� ����� ������ sW ( ����� �����. do )
//
 DeleteSpacesTabsAround ( sEdg ); // ������� ������� �������
 ReplaceManySpacesOne( sEdg ); // ������� ������� �������� ������
//
#ifdef TEST_PRINT //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 c_AddLineToTextFrame( sEdg ); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif
//
 return TRUE;
//
} // --- ����� c_ReadAndCorrectParamsEdges =====================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool _fastcall c_ReadAndCorrectParamsVertices( char FileNameParamsVertices[] )
{ // ���������� ������ ���� ���������� ������ � ������ sVrt � ������������ �������
 INT k, n1,n2,
     ch; // �����!..
 char // sWork[_16384] = "", // ������� ������ ��� ���������� ���������� ������������ (����������)
      sN[_8192], // ��������� ������ ����������
      sP[_4096], // ��������� ����������� ���������
      s[_512],
      w[2] = "?\0";
//
 if( !ReadAndPrimWorkOpsCalcsVertEdgeFiles( FileNameParamsVertices ) ) // ������ � sWork � ��������������� ����������
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
// --- �������� �������� sW � ����������� � sVrt c ��������� ������������ ------
////////////////////////////////////////////////////////////////////////////////
//
 strNcpy( sVrt, "\0" ); // �������� sVrt
//
 INT iStart = 0, iEnd,
     lW = strlen( sWork ), // ����� ������ sW
     lPrevOps;
//
 do // �� ���������� [=][�����][/][�����][:] ��� [=][Def:] ( �� sN )
 {
  iEnd = c_FindSubString( sWork, sN, iStart, 0 );
// --- ������ ��������� ������ sN ������ ���������� ��������� ------------------
//
  DeleteSpacesTabsAround( sN ); // �������� ������� �������
//
////////////////////////////////////////////////////////////////////////////////
  lPrevOps = strlen( sVrt ); // ����� ������ sVrt ����� ����������� '=n1/n2:' ��� '=Def:'
// ���� �������, ���� ����� ���������� ���������� ��������� �������
//
////////////////////////////////////////////////////////////////////////////////
// �� ������ �������� sN �������� ��������� '=n1/n2:' ��� '=Def:'
  if( sN[0]=='=' && isdigit(sN[1]) ) // ��������� ������������ "=n1/n2:"
  {
// --- ������ ��������� ����������� '=n1/n2:^' ---------------------------------

  if( !Test_n1n2 ) // ������ "=n1/n2:^" �� sN (�o����� !=6 - ������ )
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // �� ���������!..
  {
   snprintf( s,sizeof(s), "=%d/%d: ", n1,n2 );  // �������� ����� "=n1/n2:^"
   strcat( sVrt, s );
//
// --- ������ ������ sN �� ��������� "xxx:" ------------------------------------
//  DEL_TO_COLON // ������ ��� ������� sN �� 'xxx:'
  strNcpy( sN, strchr( sN,':' ) + 2 ) ; // ������ ����� ������ ����� ':'
//
  DeleteSpacesTabsAround( sN ); // �������� sN �� ������� ��������...
//
  } // ����� if( sscanf( sN, ...
  } // ����� if( sN[0]=='='...
//
////////////////////////////////////////////////////////////////////////////////
  else // if( sN[0]=='=' ...
////////////////////////////////////////////////////////////////////////////////
//
  if( ! cmp_def( sN ) ) // ��� ��� ��� ������ '=Def:'
  {
   iStart = iEnd;
   continue; // ...do
  }
  else // �� ���������!..
  {
   snprintf( s,sizeof(s), "%s ", sDef );
   strcat( sVrt, s );
//
   strNcpy( sN, strchr( sN,':' ) + 2 ) ; // ������ ����� ������ ����� ':'
//
   DeleteSpacesTabsAround( sN ); // �������� sN �� ������� ��������...
//
  }  // ����� ��������� ����������� "=Def:^"
//
// --- �������� ������ sN �� ��������� ���������� sP ---------------------------
//
 INT jStart = 0, jEnd,
     lN = strlen( sN ); // ����� ������ sN
//
 int countSP = 0 ; // ������� ����� sP ������������� ���� ������� � ������ sN
//
 do // �� ���������� [-][���.�����]
 {
  jEnd = c_FindSubString( sN, sP, jStart, 1 );
//
// --- ������ ��������� ������ ��������� sP ------------------------------------
//
// --- �������� �� ������������ ���������� �������� ���������� ���� ������������� sscanf(...)
  if( !c_IsCorrectParamOpVertEdg( sP ) )
  {
   jStart = jEnd ;
   continue; // ...do
  }
//
  countSP ++ ; // ...��� ���� ����������� ������..!
//
  strcat( sVrt, sP ); // ����� ���������� � sVrt
  strcat( sVrt, " \0" );
//
// --- ����� ��������� ������ ��������� sP -------------------------------------
  jStart = jEnd;
 } while( jEnd !=lN ); // ���� �� ����� ������ sN ( ����� �����. do )
//
 if( countSP==0 )
  sOps[ lPrevOps ] = '\0' ;
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
//
  iStart = iEnd;
 } while( iEnd !=lW ); // ���� �� ����� ������ sW ( ����� �����. do )
//
 DeleteSpacesTabsAround ( sVrt ); // ������� ������� �������
 ReplaceManySpacesOne( sVrt ); // ������� ������� �������� ������
//
#ifdef TEST_PRINT //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 c_AddLineToTextFrame( sVrt ); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif
//
 return TRUE;
//
} // --- ����� c_ReadAndCorrectParamsVertices ==================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountCalcs()
{ // --- ���������� ����� ����� ������������ -----------------------------------
 char sN[_4096] = "";
 INT  n1,n2, nSum = 0,
      iStart = 0, iEnd,
      lS = strlen( sCalcs ); // ����� ������ sCalcs

 if( !lS ) // ���� sCalcs ������...
  return 0 ;
//
 do // �� ���������� '=' + ����� ( �� sN )
 {
  iEnd = c_FindSubString( sCalcs, sN, iStart, 0 );
// --- ������ ��������� ������ sN ������ ���������� ��������� ------------------
//
  DeleteSpacesTabsAround( sN ); // �������� ������� �������
//
// --- ��������� ������������ �������������� '=n1/n2:' -------------------------
//  if( sscanf( sN, "=%d/%d: ", &n1, &n2 ) != 2 ) // �o����� !=2 - ������
  if( !Test_n1n2 ) // ������ "=n1/n2:^" �� sN (�o����� !=6 - ������ )
  {
   iStart = iEnd;
   continue;
  }
//
  nSum = max( nSum, max( abs(n1), abs(n2) ) ) ; // ���������� ����� ����� ������������
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
//  cont_i:
  iStart = iEnd;
 } while( iEnd !=lS ); // ���� �� ����� ������ sCalcs ( ����� �����. do )
//
 return nSum ;
} // --- ����� c_GetCountCalcs -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNumbParamByCalc(INT Numb, INT Calc )
{ // --- ���������� ��������� Numb ������ ���������� ����������� Calc ----------
// --- ���� �������������� ������ '-'+���.�����] -------------------------------
 char sN[_4096], sR[_2048];
 INT iStart = 0, iEnd,
     rep=0; // ����� ��������� �������
//
 strNcpy( sN, c_GetParamsByCalc( Calc ) ); // ���� ��������� ���������� ��� ����������� Calc
 INT lN = strlen( sN ); // ����� ������ sN
//
 do // �� ���������� '-' + ���.����� ( �� sN )
 {
  iEnd = c_FindSubString( sN, sR, iStart, 1 );
//
// --- ������ ��������� ������ sN ������ ���������� ��������� ------------------
//
  rep ++ ; // ����� ��������� sR � sN
//
  if ( rep == Numb ) // ����� ��� ����...
  {
   DeleteSpacesTabsAround( sR ); // ������� ������� ������� � �����
   return sR ; // ���������� ���������
  }
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
//  cont_i:
  iStart = iEnd;
 } while( iEnd !=lN ); // ���� �� ����� ������ sN
///
 return "\0" ; // ���� ������ �� �����...
//
} // --- ����� c_GetNumbParamByCalc --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNumbParamByOp(INT Numb, INT Op )
{ // --- ���������� ��������� Numb ������ ���������� ��������� Op --------------
// --- ���� �������������� ������ '-'+���.�����] -------------------------------
 char sN[_4096], sR[_2048];
 INT iStart = 0, iEnd,
     rep=0; // ����� ��������� �������
//
 strNcpy( sN, c_GetParamsByOp( Op ) ); // ���� ��������� ���������� ��� ����������� Op
 INT lN = strlen( sN ); // ����� ������ sN
//
 do // �� ���������� '-'+���.����� ( �� sN )
 {
  iEnd = c_FindSubString( sN, sR, iStart, 1 );
//
// --- ������ ��������� ������ sN ������ ���������� ��������� ------------------
//
  rep ++ ; // ����� ��������� sR � sN
//
  if ( rep == Numb ) // ����� ��� ����...
  {
   DeleteSpacesTabsAround( sR ); // ������� ������� ������� � �����
   return sR ; // ���������� ���������
  }
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lN ); // ���� �� ����� ������ sN
//
 return "\0" ; // ���� ������ �� �����...
//
} // --- ����� c_GetNumbParamByOp ----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbOp(INT Numb)
{ // ���������� ����� Numb ��������� (�������� �������) �� ���� ��������� � ���� ���
//
 if( !isEdges ) // ��� ������� Mem_Edges[]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ���� ����� ���������� (����� nEdges ��� �����)===========================
////////////////////////////////////////////////////////////////////////////////
 INT nW, iEdges, jEdges,
     iOps = 0; // ������� ����� ������ (����������)
 bool flag;
//
  for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ��� ����� ������� � #1
   Mem_Edges[iEdges].flag_From =
   Mem_Edges[iEdges].flag_To   = FALSE; // ����� ����� �� ���� ����������
//
// === �� ���� ����� ��� =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ��� ����� ������� � #1
  {
   if( !Mem_Edges[iEdges].flag_From ) // ��������� ��������� ������� ���� iEdges
   { // --- ������� ����� �������� � ������� -----------------------------------
    nW=Edges(0,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     if( Edges(0,jEdges) == nW )
      Mem_Edges[jEdges].flag_From == TRUE; // �������� "From"
//
     if( Edges(1,jEdges) == nW )
      Mem_Edges[jEdges].flag_To == TRUE;  // �������� "To" (��� ������)
    } // ����� for(jEdges=1; jEdges<=nEdges; jEdges++)
//
   } // ����� if( nW > 0 )
//
// --- ��������� nW �����������, ���� ������ ��� ��� � Edges(1,*) --------------
// --- ���� ��� ����������� � Edges(1,*), �� ���������� iEdges -----------------
//
   flag = FALSE;
   for(jEdges=1; jEdges<=nEdges; jEdges++) // ���� ��������� -nW
    if( Mem_Edges[jEdges].flag_To && Edges(1,jEdges)==nW )
//  if( Edges(1,jEdges) == -nW )
     flag = TRUE ; // ����, nW ����������� � Edges(1,*) ..!
//
   if( flag ) // ���� nW ����������� � Edges(1,*) - ��������!
    iOps ++ ;
//
   if( iOps == Numb ) // ����� ��������� ����� Numb
    goto cont ;
//
////////////////////////////////////////////////////////////////////////////////
//
   if( !Mem_Edges[iEdges].flag_To ) // ��������� �������� ������� ���� iEdges
// if( ( nW=Edges(1,iEdges) ) > 0 ) // ��������� �������� ������� ���� iEdges
   { // --- ������� ����� �������� � ������� -----------------------------------
    nW=Edges(1,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     if( Edges(0,jEdges) == nW )
      Mem_Edges[jEdges].flag_From == TRUE; // �������� "From" (��� ������)
//
      if( Edges(1,jEdges) == nW )
       Mem_Edges[jEdges].flag_To == TRUE; // �������� "To"
    } // ����� for(jEdges=1; jEdges<=nEdges; jEdges++)
//
    iOps ++ ; // ������� ������ ����� ������
    if( iOps == Numb ) // ����� ��������� ����� Numb
     goto cont ;
//
   } // ����� if( nW > 0 )
//
  } // ����� for(iEdges=1; iEdges<=nEdges; iEdges++)
//
////////////////////////////////////////////////////////////////////////////////
 cont:
////////////////////////////////////////////////////////////////////////////////
//
 return nW ;
//
} // ------ ����� c_GetNumbOp --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOps()
{ // ���������� ����� ������ ��� ��� ����� ������� ������
//
 if( !isEdges ) // ��� ������� Mem_Edges[]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ���� ����� ����� ���������� nOps (����� nEdges ��� �����)================
////////////////////////////////////////////////////////////////////////////////
//
 INT iEdges, jEdges,
     nW; // nW ������ (�������) ������� ���� iEdges
 nOps = 0; // ����� ������ ��� ������� (����������)
//
////////////////////////////////////////////////////////////////////////////////
#ifdef METHOD_OF_CALC_COUNT_OPS //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////////////////////////////////////////////////////////////////////////////////
  for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ���� ����� ������� � #1
   Mem_Edges[iEdges].flag_From =
   Mem_Edges[iEdges].flag_To   = TRUE; // �������� ��� ���������
//
// === �� ���� ����� ��� =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ���� nEdges ����� ������� � #1
  {
   if( !c_GetCountInEdgesByOp( Edges(0,iEdges) ) ) // "���������" ��������� �������� �����
    continue;
//
// ��������� ������ �������� (From) ������� ���� iEdges
   if( Mem_Edges[iEdges].flag_From ) // ��������� "����������" �������� ������� ���� iEdges
   {
    nW = Edges(0,iEdges);
    nOps ++ ; // ������� ����� ������ (��������� �� �����)
////////////////////////////////////////////////////////////////////////////////
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     if( Edges(0,jEdges) == nW )
      Mem_Edges[jEdges].flag_From = FALSE; // ����� ����� � ������� "������" (From)
//
     if( Edges(1,jEdges) == nW )
      Mem_Edges[jEdges].flag_To   = FALSE; // ����� ����� � ������� "����" (To)
    } // ����� for(jEdges=1; jEdges<=nEdges; jEdges++)
//
   } // ����� if( Mem_Edges[iEdges].FlagFrom )
////////////////////////////////////////////////////////////////////////////////
// ��������� ������ ��������� (To) ������� ���� iEdges
   if( Mem_Edges[iEdges].flag_To ) // ��������� "����������" ��������� ������� ���� iEdges
   {
    nW = Edges(1,iEdges);
    nOps ++ ; // ������� ������ ����� (�������� �� �����)
////////////////////////////////////////////////////////////////////////////////
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     if( Edges(0,jEdges) == nW )
      Mem_Edges[jEdges].flag_From = FALSE; // ����� ����� � ������� "������" (From)
//
     if( Edges(1,jEdges) == nW )
      Mem_Edges[jEdges].flag_To   = FALSE; // ����� ����� � ������� "����" (To)
    } // ����� for(jEdges=1; jEdges<=nEdges; jEdges++)
////////////////////////////////////////////////////////////////////////////////
   } // ����� if( Mem_Edges[iEdges].FlagFTo )
//
  } // ����� for(iEdges=1; iEdges<=nEdges; iEdges++)
////////////////////////////////////////////////////////////////////////////////
#else //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////////////////////////////////////////////////////////////////////////////////
  for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ���� ����� ������� � #1
   Mem_Edges[iEdges].flag_To = TRUE; // ��������  ��������� ...To
//
  for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ���� nEdges ����� ������� � #1
// ��������� ������ ��������� (To) ������� ���� iEdges
   if( Mem_Edges[iEdges].flag_To ) // ��������� "����������" ��������� ������� ���� iEdges
   {
    nW = Edges(1,iEdges);
    nOps ++ ; // ������� ������ ����� (�������� �� �����)
////////////////////////////////////////////////////////////////////////////////
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     if( Edges(1,jEdges) == nW )
      Mem_Edges[jEdges].flag_To   = FALSE; // ����� ����� � ������� "����" (To)
    } // ����� for(jEdges=1; jEdges<=nEdges; jEdges++)
////////////////////////////////////////////////////////////////////////////////
   } // ����� if( Mem_Edges[iEdges].FlagFTo )
//
////////////////////////////////////////////////////////////////////////////////
#endif //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////////////////////////////////////////////////////////////////////////////////
//
 return nOps ;
//
} // --- ����� c_GetCountOps ---------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbOpInput(INT Numb)
{ // ���������� ����� Numb ��������� (������ �� ������� ����������)
//
 if( !isEdges ) // ��� ������� Mem_Edges[]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ���� Numb-��� �������� (����� nEdges ��� �����)==========================
////////////////////////////////////////////////////////////////////////////////
 INT nW, iEdges, jEdges,
     iOps = 0 ; // ������� ����� ������ ����� (����������)
 bool flag;
//
  for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ��� ����� ������� � #1
   Edges_f(0,iEdges) =
   Edges_f(1,iEdges) = FALSE; // ����� ����� �� ���� ������
//
// === �� ���� ����� ��� =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ���� ����� ������� � #1
   if( !Edges_f(0,iEdges) ) // ��������� ��������� ������� ���� iEdges
   {
    nW = Edges(0,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     Edges_f(0,jEdges) = Edges(0,jEdges)==nW ? TRUE : Edges_f(0,jEdges) ; // �������� "From"
     Edges_f(1,jEdges) = Edges(1,jEdges)==nW ? TRUE : Edges_f(1,jEdges) ; // �������� "To"
    } // ����� for(jEdges=1; jEdges<=nEdges; jEdges++)
//
   flag = FALSE;
   for(jEdges=1; jEdges<=nEdges; jEdges++)
    if( Edges_f(1,jEdges) && Edges(1,jEdges)==nW ) // �������� � ����� nW
     flag = TRUE ; // ����, nW ����������� � Edges(1,*) ..!
//
   if( !flag ) // ���� nW �� ����������� � Edges(1,*) - ��������!
    iOps ++ ;
//
   if( iOps == Numb ) // ����� ��������� ����� Numb
    return nW ;
//
   } // ����� if(!Edges_f(0,iEdges)) � for(iEdges=1; iEdges<=nEdges; iEdges++)
//
} // ------ ����� c_GetNumbOpInput ---------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbOpOutput(INT Numb)
{ // ���������� ����� Numb ������� (������ �� �������� ����������)
//
 if( !isEdges ) // ��� ������� Mem_Edges[]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ���� ����� ���������� (����� nEdges ��� �����)===========================
////////////////////////////////////////////////////////////////////////////////
 INT nW, iEdges, jEdges,
     iOps = 0 ; // ������� ����� ������
 bool flag;
//
 for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ��� ����� ������� � #1
  Edges_f(0,iEdges) =
  Edges_f(1,iEdges) = FALSE; // ����� ����� �� ���� ������ (����������0
//
// === �� ���� ����� ��� =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ���� ����� ������� � #1
   if( !Edges_f(1,iEdges) ) // ��������� ��������� ������� ���� iEdges
   {
    nW = Edges(1,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++)
    {
     Edges_f(0,jEdges) = Edges(0,jEdges)==nW ? TRUE : Edges_f(0,jEdges) ; // �������� "From"
     Edges_f(1,jEdges) = Edges(1,jEdges)==nW ? TRUE : Edges_f(1,jEdges) ; // �������� "To"
    } // ����� for(jEdges=1; jEdges<=nEdges; jEdges++)
//
   flag = FALSE;
   for(jEdges=1; jEdges<=nEdges; jEdges++)
    if( Edges_f(0,jEdges) && Edges(0,jEdges)==nW ) // �������� � ����� nW
     flag = TRUE ; // ����, nW ����������� � Edges(0,*) ..!
//
   if( !flag ) // ���� nW �� ����������� � Edges(0,*) - ��������!
    iOps ++ ;
//
   if( iOps == Numb ) // ����� ��������� ����� Numb
     return nW ;
//
   } // ����� if(!Edges_f(1,iEdges)) � for(iEdges=1; iEdges<=nEdges; iEdges++)
//
} // ------ ����� c_GetNumbOpOutput --------------------------------------------


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
  Edges_f(1,iEdges) = FALSE; // "����� �����" �� ���� ������ (����������)
//
// === �� ���� ����� ��� =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ��� ����� ������� � #1
   if( !Edges_f(0,iEdges) ) // ��������� ��������� ������� ���� iEdges
   {
    nW = Edges(0,iEdges);
    for(jEdges=1; jEdges<=nEdges; jEdges++) // �� ���� ����� ������� � #1
    {
     Edges_f(0,jEdges) = Edges(0,jEdges)==nW ? TRUE : Edges_f(0,jEdges) ; // �������� "From"
     Edges_f(1,jEdges) = Edges(1,jEdges)==nW ? TRUE : Edges_f(1,jEdges) ; // �������� "To"
    } // ����� for(jEdges=1; jEdges<=nEdges; jEdges++)
//
   flag = FALSE;
   for(jEdges=1; jEdges<=nEdges; jEdges++)
    if( Edges_f(1,jEdges) && Edges(1,jEdges)==nW ) // �������� � =nW
     flag = TRUE ; // ����, nW ����������� � Edges(1,*) ..!
//
   if( !flag ) // ���� nW �� ����������� � Edges(1,*) - ��������!
    nOpsInput ++ ;
//
   } // if(!Edges_f(0,iEdges)) � for(iEdges=1; iEdges<=nEdges; iEdges++)
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
 for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ���� ����� ������� � #1
  Edges_f(0,iEdges) =
  Edges_f(1,iEdges) = FALSE; // ����� ����� �� ���� ������ (����������)
//
// === �� ���� ����� ��� =======================================================
  for(iEdges=1; iEdges<=nEdges; iEdges++) // �� ���� ����� ������� � #1
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
   } // ����� if(!Edges_f(1,iEdges)) � for(iEdges=1; iEdges<=nEdges; iEdges++)
//
 return nOpsOutput ;
//
} // --- ����� c_GetCountOpsOutput----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT _fastcall c_FindSubString( char* sSrc, char* sDst, INT iStart, INT Rule)
{ // � ������ sSrc ������� � ������� iStart ������ ��������� sDst --------------
// --- ������������ ����� ������� ������ � ������ sSrc -------------------------
// --- ��� Rule = 0  ������ ��� ������ �� �������: ������ ��������� [=][�����]
// --- ��� [=][D(d)] � ������ ��������� ����� �� (����� ������ � ������
// --- ����������� ����� ���������� ����� ��������)
// --- ��� Rule != 0  ������ ��� ������ [-][���.�����]-[-][���.�����]-----------
// --- ��� "-" ����� ���������� ����� ��������, D(d) - ���.����� D � ����� ��������
 register INT k,j,i;
 INT lenSrc = strlen( sSrc ); // ����� ������ sSrc

 strNcpy( sDst, "\0" ); // ������� sDst

 for( i=iStart; i<=lenSrc; i++ ) // ����� �� ������ sSrc ������� i - ���� ������ ��������� �������

  if( ( ( Rule==0 && sSrc[i]=='=' ) && // Rule=0 � ������ ������ '=' (�������� ������������������)
        ( isdigit(sSrc[i+1]) || toupper(sSrc[i+1]=='D') ) // [�����] ��� [D(d)]
      || // ��� ��� Rule != 0
        ( Rule!=0 && sSrc[i]=='-' ) && // Rule!=1 � ������ ������ '-'
          isalpha(sSrc[i+1]) ) ) // ������ [���.�����]

  for( j=i+1; j<=lenSrc; j++ ) // ����� �� ������ sSrc �� ������� j - ���� ��������� ��������� �������

  if(  j==lenSrc // ���� ����� ������ sSrc
     || // ��� ��� Rule == 0
     ( ( Rule==0 && sSrc[j]=='=' ) && // Rule=0 � ������ ������ '=' (�������� ������������������)
       ( isdigit(sSrc[j+1]) || toupper(sSrc[j+1]=='D') ) // [�����] ��� [D(d)]
     || // ��� ��� Rule != 0
       ( Rule!=0 && sSrc[j]=='-' ) && // Rule!=1 � ������ ������ '-'
         isalpha(sSrc[j+1]) ) ) // [���.�����]
// �������� �������� �� ������ ���������� - ������ ���������: [-][���.�����]...������: [-][�����.�����]
// isalpha (,tp setlocale) �� ����� ������ ��������� (��� Rule!=0 ��������� ����� �������� �� ������ ���������)
// � ������ ������ ��� �������� ��������� ������� str c_IsCorrectParamCalc (...Op)
     {
//      for( k=i; (j!=lenSrc) ? (k<j) : (k<=lenSrc) ; k++ ) // �������� ��������� � sDst
      for( k=i; k<j; k++ ) // �������� ��������� � sDst
       sDst[ k-i ] = sSrc[ k ];
      sDst[ j-i ] = '\0' ; // ������ ������������� "�������" ����

      if( sDst[j-i-1] == ' ' ) // ��� ������������ DelSpacesTabsAround ( sDst );
       sDst[j-i-1] = '\0';

//      DelSpacesTabsAround ( sDst ); // ������� ������� �������
//
      return j ; // �������, ��������� �� ������ ���������
//      return (j<lenSrc) ? (j) : (lenSrc) ; // �������, ��������� �� ������ ���������

     } // ����� if( Rule == ?? && ...
//
 sDst[ 0 ] = '\0' ;
//
 return lenSrc ; // ...���� ������ �� ����� - ������� ����� ������, � �������� ������
//
} // --- ����� c_FindSubString =================================================

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_PutParamsAll()
{ // ����� ����� ���������� ������������ � ����������, ������ ��� � ������
 char str[_16384]; // ������� ������

 t_printf( "\n-I- ��������� ������������ � ����������, ������� ��� � ������ -I-" ); // �������������� ���������

 if( c_LoadFileNameParamsCalcs( FileNameParamsCalcs ) ) // ���� � ������ �� ������...
 {
  t_printf( "=> �����������: ���� |%s|", FileNameParamsCalcs ); // ��� ����� ���������� ������������
  t_printf( "��������:   |%s|", sWork ); // �������� ������
  t_printf( "���������: |%s|", sCalcs ); // ���������������� ������
 }

 if( c_LoadFileNameParamsOps( FileNameParamsOps ) )
 {
  t_printf( "=> ���������: ���� |%s|", FileNameParamsOps ); // ��� ����� ���������� ����������
  t_printf( "��������:   |%s|", sWork ); // �������� ������
  t_printf( "���������: |%s|", sOps ); // ���������������� ������
 }

 if( c_LoadFileNameParamsEdges( FileNameParamsEdges ) )
 {
  t_printf( "=> ������� ���: ���� |%s|", FileNameParamsEdges ); // ��� ����� ������ ���
  t_printf( "��������:   |%s|", sWork ); // �������� ������
  t_printf( "���������: |%s|", sEdg ); // ���������������� ������
 }

 if( c_LoadFileNameParamsVertices( FileNameParamsVertices ) )
 {
  t_printf( "=> ������� ������: ���� |%s|", FileNameParamsVertices ); // ��� ����� ������ ������
  t_printf( "��������:   |%s|", sWork ); // �������� ������
  t_printf( "���������: |%s|", sVrt ); // ���������������� ������
 }

 c_AddLineToTextFrame( "\n" );

 return TRUE ;

} // --- ����� c_PutParamsAll --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetParamsByOp(INT Op)
{ // ���c��������� ������ sOps � ���������� ��������� ���� ���������� ��������� Op
 char sN[_8192], sName[_128];
 INT  lOps, iStart=0, iEnd, n1, n2;

 if( ! (lOps = strlen( sOps ) ) ) // ���� ������ ���������� ������...
  return "\0" ;

////////////////////////////////////////////////////////////////////////////////
// --- ������ ������ sN ����� �������� ���� '=n1/n2:'---------------------------

 do // �� ���������� '=n1/n2:' ��� '=Def:'
 {
  iEnd = c_FindSubString( sOps, sN, iStart, 0 );
// --- ������ ��������� ������ sOps ������ ���������� --------------------------

//  DelSpacesTabsAround( sN ); // �������� ������� �������

//  if( !strncmp( sN, sDef, 5 ) ) // '=Def:' ���� �� �����... ������ �� do !
  if( cmp_def( sN ) ) // '=Def:' ���� �� �����... ������ �� do !
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
// if( sscanf( sN, "=%d/%d: ", &n1, &n2 ) == 2 ) // ���������� ������
 if( Test_n1n2 ) // ���������� ������ "=n1/n2:^" �� sN
   if( Op >= min(n1,n2) && Op <= max(n1,n2) ) // Op � ��������� n1-n2
    return strchr( sN,':' ) + 2 ; // ������������� ����� ':' � '������'

// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lOps ); // ���� �� ����� ������ sOps ( ����� �����. do )
//
////////////////////////////////////////////////////////////////////////////////
// --- ������ ������ sN ����� �������� ���� '=Def:'-----------------------------

 iStart = 0;

 do // �� ���������� '=n1/n2:' ��� '=Def:'
 {
  iEnd = c_FindSubString( sOps, sN, iStart, 0 );
// --- ������ ��������� ������ sMess ������ ���������� -------------------------

//  DelSpacesTabsAround( sN ); // �������� ������� �������

//  if( strncmp( sN, sDef, 5 ) ) // '=Def:' ��� ��� �����...
  if( ! cmp_def( sN ) ) // '=Def:' ��� ��� �����...
  {
   iStart = iEnd ;
   continue; // ...do
  }

  if( sscanf( sN, "%s ", sName ) == 1 ) // ���������� ������
   return strchr( sN,':' ) + 2 ; // ������������� ����� ':' � '������'

// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lOps ); // ���� �� ����� ������ sOps ( ����� �����. do )

////////////////////////////////////////////////////////////////////////////////

 return "\0" ; // �� ������� ������ ������ - ��������� (�� ���������)

} // --- ����� c_GetParamsByOp -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetParamsByCalc(INT Calc)
{ // ���c��������� ������ sCalcs � ���������� ��������� ���� ���������� ����������� Op
 char sN[_8192], sName[_128];
 INT  lCalcs, iStart=0, iEnd, n1, n2;

 if( ! (lCalcs = strlen( sCalcs ) ) ) // ���� ������ ������������ ������...
  return "\0" ;

////////////////////////////////////////////////////////////////////////////////
// --- ������ ������ sN ����� �������� ���� '=n1/n2:'---------------------------

 do // �� ���������� '=n1/n2:' ��� '=Def:'
 {
  iEnd = c_FindSubString( sCalcs, sN, iStart, 0 );
// --- ������ ��������� ������ sOps ������ ���������� --------------------------

//  DelSpacesTabsAround( sN ); // �������� ������� �������

//  if( !strncmp( sN, sDef, 5 ) ) // '=Def:' ���� �� �����... ������ �� do !
  if( cmp_def( sN ) ) // '=Def:' ���� �� �����... ������ �� do !
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
//  if( sscanf( sN, "=%d/%d: ", &n1, &n2 ) == 2 ) // ���������� ������
 if( Test_n1n2 ) // ���������� ������ "=n1/n2:^" �� sN
   if( Calc >= min(n1,n2) && Calc<= max(n1,n2) ) // Calc � ��������� n1-n2
    return strchr( sN,':' ) + 2 ; // ������������� ����� ':' � '������'

// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lCalcs ); // ���� �� ����� ������ sCalcs ( ����� �����. do )

////////////////////////////////////////////////////////////////////////////////
// --- ������ ������ sN ����� �������� ���� '=Def:'-----------------------------

 iStart = 0;

 do // �� ���������� '=n1/n2:' ��� '=Def:'
 {
  iEnd = c_FindSubString( sCalcs, sN, iStart, 0 );
// --- ������ ��������� ������ sMess ������ ���������� -------------------------

//  DelSpacesTabsAround( sN ); // �������� ������� �������

//  if( strncmp( sN, sDef, 5 ) ) // '=Def:' ��� ��� �����...
  if( ! cmp_def( sN ) ) // '=Def:' ��� ��� �����...
  {
   iStart = iEnd ;
   continue; // ...do
  }

  if( sscanf( sN, "%s ", sName ) == 1 ) // ���������� ������
   return strchr( sN,':' ) + 2 ; // ������������� ����� ':' � '������'

// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lCalcs ); // ���� �� ����� ������ sCalcs ( ����� �����. do )

////////////////////////////////////////////////////////////////////////////////

 return "\0" ; // �� ������� ������ ������ - ��������� (�� ���������)

} // --- ����� c_GetParamsByCalc -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CanExecOpCalc(INT Op, INT Calc)
{ // �������� ����������� ���������� ��������� Op �� ����������� Calc
// --- ���������� ����� ����������, �� ������� ���������� �������� (>0)
// --- ���� ���� ��� ����������, �� ������������ ����� �������� � �������
// --- ���� ��� ����������� ���������� - ������������ math.huge
 register INT iOp,iCalc;
 INT countEq = 0, // ����� ���������� �������� ���������� ���������� � ������������
     nOp   = c_GetCountParamsByOp( Op ), // ����� ���������� ��������� Op
     nCalc = c_GetCountParamsByCalc( Calc ); // ����� ���������� ����������� �alc
 bool flagPoss = TRUE, // ���� �����������...
      flagNameParam = FALSE; // ���� �� ����������� ����� ����������
 REAL ValOp, minValCalc, maxValCalc; // �������� ����������
 char NameParamOp[_512], NameParamCalc[_512]; // ��� ���������� ��������� � �����������
//
 if( !strlen( sOps ) || // ������ ���������� ��������� Op ������...
     !nOp ) // ��� ���������� ��������� Op
  return maxRet ;
//
 if( !strlen( sCalcs ) || // ������ ���������� ����������� Calc ������...
     !nCalc ) // ��� ���������� ������������
  return -maxRet ;
//
 for( iOp=1; iOp<=nOp; iOp++ ) // ���� �� ���������� ���������
 {
  APM // -----------------------------------------------------------------------
//
  strNcpy( NameParamOp, c_GetNameNumbParamByOp( iOp, Op ) ); // ���������...
//
  for( iCalc=1; iCalc<=nCalc; iCalc++ ) // ���� �� ���������� �����������
  {
   APM // ----------------------------------------------------------------------
//
   strNcpy( NameParamCalc, c_GetNameNumbParamByCalc( iCalc, Calc ) ); // ���������...
//
// --- ��������� �� ��� ��������� ��������� � ������ ��������� ����������� ? ---
   if( !strcmp( NameParamOp, NameParamCalc ) ) // ���������� = 0
   { // ������������ ������ ���������� �� ����� ���������...
//    flagNameParam = TRUE; // ������� ���������� �� ����������
    ValOp      = c_GetValNumbParamByOp( iOp, Op ); // �������� ��������� Op
    minValCalc = c_GetMinValNumbParamByCalc( iCalc, Calc ); // �������� min ��������� Calc
    maxValCalc = c_GetMaxValNumbParamByCalc( iCalc, Calc ); // �������� max ��������� Calc
//
// --- ���������� �������� ��������� �� �������� -------------------------------
    if( ValOp>=min(minValCalc,maxValCalc) && ValOp<=max(minValCalc,maxValCalc) ) // ������ � ��������...
    // �� ��������� � ������ NameParamOp = NameParamCalc �������� "���������� ��������"
     countEq ++ ;
   } // ����� if !strcmp (�� ������ ����������)
//
  } // ����� for iCalc (�� ������������)
 } // ����� for iOp (�� ����������)
//
 return ( countEq == nOp ) ? countEq : -countEq ; // ����� ���������� �� ����������
//
} // --- ����� c_�anExecOpCalc -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_TestCanExecAllOpsCalcs( INT  Rule )
{ // �������� ����������� ���������� ���� ���������� �� ���� ������������
// ��� Rule==0 ������������ TRUE ��� ������������ � FALSE ��� ��������
// ��� Rule!=0 ������� ������ ����������, ������� ����� ���� ��������� �� ���������� �����������
INT  iOp,Op,Calc, numbCalcsByOp,
     countOps, countCalcs,
     countAll, countOut, countDone=0;
bool canAllExec = TRUE ;
char str[_4096], w[_256], sOut[_128], sSave[_128];;
//
 strNcpy( sSave, F2->L_OM->Caption.c_str() ); // ��������� ����� �� F2->L_OM->Caption
//
// --- ������� � ��� ���������� � ������������ ? -------------------------------
 countOps = c_GetCountOps(); // ����� ����� ����������
 countCalcs = c_GetCountCalcs(); // ����� ����� ������������
// --- � ������� ����� ������ ����� ������� ? ----------------------------------
 countAll = countOps * countCalcs;
 countOut = countAll / 100; // ������ ������� �����
//
 if( countOps <= 0 ) // ��������! ������ ����� ������� Mem_Edges[] �� ���������� (�������������� ���� �� ��� ��������)
 {
  t_printf( "\n-W- ����� ���������� �� ����������. ��������, ���� ������ ����� �� ��� ��������... -W-\n" );
  return FALSE ;
 }
//
// --- �������� � ����������� ������������ -------------------------------------
//
 if( countCalcs <= 0 ) // ��������! ������ ����� ���� ���������� ������������ �� ��� ��������
 {
  t_printf( "\n-W- ����� ������������ �� ����������. ��������, ���� ���������� ������������ �� ��� ��������... -W-\n" );
  return TRUE ;
 }
//
// --- �� ��������� - �������� ������� ����� ������ ---------------------------
 t_printf( "\n-I- ����� ����������= %d, ����� ������������= %d -I-\n", countOps, countCalcs );
//
 for( iOp=1; iOp<=countOps; iOp++ ) // �� ������ ����� ����������
 {
  APM // -----------------------------------------------------------------------
  Delay( 1 ); // ����� ���������� Windows 0,001 ��� ( APM �� �������� !!! )
//
  Op = c_GetNumbOp( iOp ); // ���������� ����� ���������
  snprintf( str,sizeof(str), "��������= %d ����� ���� �������� �� ������������:", Op );
  numbCalcsByOp = 0; // ����� ������������, �� ������� ����� ����������� �������� Op
//
  for( Calc=1; Calc<=countCalcs; Calc++ ) // �� ���� ������������
  {
   APM // ----------------------------------------------------------------------
//
////////////////////////////////////////////////////////////////////////////////
// --- �������� ������� ���������� (��� ������� ����� ����� ���� ����� �����)
////////////////////////////////////////////////////////////////////////////////
   countDone ++ ; // ������� ����� ������
   if( !( countDone % countOut ) )
   {
    snprintf( sOut,sizeof(sOut), " = %.0f%% ���������", 100.0 * countDone / countAll );
    F2->L_OM->Caption = sOut;
    F2->L_OM->Repaint();
   }
////////////////////////////////////////////////////////////////////////////////
//
   if( c_CanExecOpCalc( Op, Calc ) > 0 ) // ���� Op ����� ���� �������� �� Calc
   {
    snprintf( w,sizeof(w), " %d", Calc );
    strcat( str, w );
    numbCalcsByOp ++ ;
   }
//
  } // ����� �� ������������ ---------------------------------------------------
//
 if( !numbCalcsByOp ) // ���� ������� "���� ����" �������� (���������), ��� ������� ��� �����������...
  canAllExec = FALSE ;
//
 if( Rule ) // ����� ����� "��������= �����������:"
  c_AddLineToTextFrame( str );
//
 } // ����� �� ����������
//
 F2->L_OM->Caption = sSave; // ������������ ����� � F2->L_OM->Caption
//
 if( !Rule ) // ���� 0 -> �������� ������..!
  return canAllExec ;
//
 if( canAllExec ) // ��� ������� � �������������!..
  c_AddLineToTextFrame( "\n-I- ����� �������� ����� ���� �������� ���� �� �� ����� �����������... -I-\n" );
 else
  c_AddLineToTextFrame( "\n-W- ���� ��� ��������� ���������� �� ����� ���� ��������� �� �� ����� �����������...-W-\n" );
//
 return canAllExec ;
//
} // --- ����� c_TestCanExecAllOpsCalcs ----------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_InputDialog( char *sCaption, char *sPrompt, char *sDefault )
{ // ����� ���� Windows c ���������� sCaption, ������������ sPrompt � ������� sDefault
 char sOut[_512]; // 256 �� ��������!!!
 strNcpy( sOut, InputBox( sCaption, sPrompt, sDefault ).c_str() );
 return sOut;
} // --- ����� �_InputDialog ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int __fastcall c_MessageDialog( char *sCaption, char *sText, char *Buttons, INT Pictogram )
{ // ����� ���� Windows c ���������� sCaption � ������� sText
 char flag[] = "0\0"; // ������ ������������ (��������������) ������ � ����� �� ���������� �����

 TMsgDlgButtons mb; // ��� ������ �� �����
 TMsgDlgType mt; // ��� ����������� �� �����

 if( strlen(Buttons) == 8 ) // ������ ����� 8 �������� !!! ����� - mbYes !!!
 {
  if( Buttons[0] != flag[0] ) mb << mbYes; // ����� ������ ������
  if( Buttons[1] != flag[0] ) mb << mbNo;
  if( Buttons[2] != flag[0] ) mb << mbOK;
  if( Buttons[3] != flag[0] ) mb << mbCancel;
//  else if( Buttons[4] == flag[0] ) mb << mbHelp; // ������ Help �� ���� !!!
  if( Buttons[4] != flag[0] ) mb << mbAbort;
  if( Buttons[5] != flag[0] ) mb << mbRetry;
  if( Buttons[6] != flag[0] ) mb << mbIgnore;
  if( Buttons[7] != flag[0] ) mb << mbAll;
 }
 else
  mb << mbYes; // ��������� (������ ������� ������ Buttons[]) - �������� ������ Yes

// if( !strcmp(Buttons, "00000000\0") ) // ���� � Buttons[] ��� 0 - �������� ������ Yes
//  mb << mbYes;

 switch( Pictogram ) // ����� ����������� ��� ����
 {
  case 0:  mt = mtConfirmation; break;
  case 1:  mt = mtInformation;  break;
  case 2:  mt = mtError;        break;
  case 3:  mt = mtWarning;      break;
  case 4:  mt = mtCustom;       break;
  default: mt = mtConfirmation; // ��������� - ������������� (�������������� ����)
                                break;
 }
//
 TForm *FMess;
 FMess = CreateMessageDialog( sText, mt, mb );
 FMess->Caption = sCaption; // ��������� ����
//
 int out = FMess->ShowModal(); // �������� ��� ��������� ���� � ������� ��� ��������� ������
//
 FMess->Free(); // ���������� FMess
//
 return out;
//
} // --- ����� �_MessageDialog -------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_DrawDiagrTiers()
{ // ������ ����������� ����������� (���������) 
 INT MinOpsOnTier, // ������� ���������� �� �����
     MaxOpsOnTier, // �������� ���������� �� �����
     OpsOnTier,
     H_pix, B_pix, // ������ � ������ ������� ��������� IM1 � ��������
     B_rect, // ������ �������������� ������� � ��������
     x1,y1, x2,y2; // ���������� �������������� ������� � ��������
//
 if( !isTiers ) // ������� Tiers[][] ��� ���...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 MinOpsOnTier = c_GetCountOpsOnTier( c_GetTierFirstMinOps(1, nTiers) ); // ������� ...
 MaxOpsOnTier = c_GetCountOpsOnTier( c_GetTierFirstMaxOps(1, nTiers) ); // �������� ���������� �� ����
//
////////////////////////////////////////////////////////////////////////////////
 TIM1->Picture->Bitmap->Height = TIM1->Height; // ��������� ������� �anvas �� �������� Image
 TIM1->Picture->Bitmap->Width  = TIM1->Width;  // !!! ����� ����� ( ���� 08.02.2017 ) !!!!!!
//
 H_pix = TIM1->Height; // ������ � ������ ������� ��������� IM1 � ��������
 B_pix = TIM1->Width;
//
 REAL dH_pix = 1.0 * H_pix / nTiers, // ������� �  �������� �� ������ � ������ ������� ��������� ���������
       dB_pix = 1.0 * B_pix / MaxOpsOnTier;
//
 dH_pix = max( dH_pix, 1.0 ); // ������ ������ ����  <= 1 , ����� ��������� ����������...
//
// --- ��������� ���������� ����� � ��������� (����) ---------------------------
 TIM1->Canvas->CopyMode     = cmSrcCopy; // ������ �������� ������ ������������
//
 TIM1->Canvas->Brush->Style = bsSolid; // �������� �����
//
 TIM1->Canvas->Pen->Style   = psSolid; // ��������
 TIM1->Canvas->Pen->Mode    = pmCopy;  // ����� ���� = color
 TIM1->Canvas->Pen->Width   = 1; // ������� = 1
//
 TIM1->Transparent = false; // !!! ����������� !!! ����� �� ���� �����, ��� ��� IM1
//
 for(INT iTier=1; iTier<=nTiers; iTier++) // ���� �� ���� ������ ��� ��� ���������� �������
 {
  F2->L_OM->Repaint(); // ����� ��� �������������... !!!!!!!!!!!!!!!!!!!!!!!!!!!
//
  OpsOnTier = c_GetCountOpsOnTier( iTier ); // ����� ����� ���������� �� �����
  B_rect = dB_pix * OpsOnTier; // ������ �������������� �������
//
// --- ������������� ����� ������� ---------------------------------------------
  if( OpsOnTier == MinOpsOnTier )
   TIM1->Canvas->Brush->Color = brush_draw_color_MIN; // ���� ����� �������
  else
  if( OpsOnTier == MaxOpsOnTier )
   TIM1->Canvas->Brush->Color = brush_draw_color_MAX; // ���� ����� ��������
  else
   TIM1->Canvas->Brush->Color = brush_draw_color_TIERS; // ���� ����� �������
////////////////////////////////////////////////////////////////////////////////
  x1 = 0;  // ����� ������� ����� �������������� ������� ( Rectangle, Rect )
  y1 = dH_pix * ( iTier-1 );
//
  x2 = x1 + B_rect; // ������ ������ ����� �������������� ������� ( Rectangle, Rect )
  y2 = y1 + dH_pix;
//
// --- ������ �������������� ������, ���������������� ����� ���������� �� �����
  TIM1->Canvas->FillRect( TRect( x1,y1, x2,y2 ) ); // ������������� �������� ������
//
//  Delay( 1 ); // �������� 1 msec - ��� �� ��������� ������ �� ����������..!
//
  Application->ProcessMessages(); // ���� ���������� Windows
//
 } // ����� ����� �� iTier
//
////////////////////////////////////////////////////////////////////////////////
// ----- ������ ������������ ����� - ������ �������� ����� ������ --------------
  REAL b_average = 1.0 * c_GetCountOps() / c_GetCountTiers(); // ������� ������ ���
//
  TIM1->Canvas->Pen->Color = pen_draw_b_average; // ���� ����� �������� ����� ���������� �� ������; // ���� ����
  TIM1->Canvas->Pen->Mode  = pmCopy; // ���� ��� ������������� � �����
  TIM1->Canvas->Pen->Style = psDot; // �������� �����
  TIM1->Canvas->Pen->Width = 1; // ������� ���� 3 �������
//
  x1 = x2 = b_average * dB_pix ;
  y1 = 0; y2 = TIM1->Height;
//
  TIM1->Canvas->MoveTo( x1,   y1 ); // ��������� ���� � x1,y1
  TIM1->Canvas->LineTo( x1,   y2 ); // �������� ����� � x1,y2
//
  TIM1->Canvas->MoveTo( x1-1, y1 ); // ��������� ���� � x1-1,y1
  TIM1->Canvas->LineTo( x1-1, y2 ); // �������� ����� � x1-1,y2
//
  TIM1->Canvas->MoveTo( x1+1, y1 ); // ��������� ���� � x1+1,y1
  TIM1->Canvas->LineTo( x1+1, y2 ); // �������� ����� � x1+1,y2
//
//  TIM1->Repaint(); // ������������� ������������
//
  return TRUE; // �� ������� �������
//
} // --- ����� �_DrawDiagrTiers ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ClearDiagrArea()
{ // ������� ����������� ����������� (���������)
//
 TIM1->Transparent = false; // !!! ����������� !!! ����� �� ���� �����, ��� ��� IM1
//
 TIM1->Canvas->Brush->Color = clear_brush_draw_color; // ���� �����
 TIM1->Canvas->Brush->Style = bsSolid; // �������� �����
 TIM1->Canvas->FillRect( TRect( TIM1->Left-2, TIM1->Top-1, // ������������� ������ Brush
                                TIM1->Left +  TIM1->Width, TIM1->Top + TIM1->Height ));
 return TRUE; // �� ���������
//
} // --- ����� �_ClearDiagrArea ------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
// ===== ������ � ��������� ������ (���������) =================================
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountMetricsByOp(INT Op)
{ // --- ���������� ����� ������ ������� (���������) Op ------------------------
 char str[_4096];
 INT k = 0;
//
 strNcpy( str, c_GetMetricsByOp( Op )  ); // ���� ��� ������ ����������
//
 for( INT i=0; str[i+1]!='\0'; i++ ) // �� ������ ���������� �� ��� �������
  if ( (str[i]=='-') && (isalpha(str[i+1])) ) // �������� �� ������ ['-' + ���.�����]
   k ++ ; // ���������, ����� ��� ����������� ['-' + ���.�����]
//
 return ( k ) ;
//
} // --- �����  c_GetCountMetricsByOp ------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNumbMetricByOp(INT Numb, INT Op)
{ // --- ���������� ��������� Numb ������ ������� ������� (�����������) ����������� Op
// --- ���� �������������� ������ '-'+���.�����] -------------------------------
 char sN[_4096], sR[_2048];
 INT iStart = 0, iEnd,
     rep=0; // ����� ��������� �������
//
 strNcpy( sN, c_GetMetricsByOp( Op ) ); // ���� ��������� ���������� ��� ������� (���������) Op
 INT lN = strlen( sN ); // ����� ������ sN
//
 do // �� ���������� '-' + ���.����� ( �� sN )
 {
  iEnd = c_FindSubString( sN, sR, iStart, 1 );
//
// --- ������ ��������� ������ sN ������ ���������� ��������� ------------------
//
  rep ++ ; // ����� ��������� sR � sN
//
  if ( rep == Numb ) // ����� ��� ����...
  {
   DeleteSpacesTabsAround( sR ); // ������� ������� ������� � �����
   return sR ; // ���������� ���������
  }
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
//  cont_i:
  iStart = iEnd;
 } while( iEnd !=lN ); // ���� �� ����� ������ sN
//
 return "\0" ; // ���� ������ �� �����...
//
} // --- ����� c_GetNumbMrtricByOp ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetMetricsByOp(INT Op)
{ // ���c��������� ������ sVrt � ���������� ��������� ���� ���������� ������� (���������) Op
 char sN[_8192], sName[_128];
 INT  lVrt, iStart=0, iEnd, n1, n2;
//
 if( ! (lVrt = strlen( sVrt ) ) ) // ���� ������ ������ ������ ������...
  return "\0" ;
//
////////////////////////////////////////////////////////////////////////////////
// --- ������ ������ sN ����� �������� ���� '=n1/n2:'---------------------------
//
 do // �� ���������� '=n1/n2:' ��� '=Def:'
 {
  iEnd = c_FindSubString( sVrt, sN, iStart, 0 );
// --- ������ ��������� ������ sOps ������ ���������� --------------------------
//
  if( cmp_def( sN ) ) // '=Def:' ���� �� �����... ������ �� do !
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
  if( Test_n1n2 ) // ���������� ������ "=n1/n2:^" �� sN
   if( Op >= min(n1,n2) && Op <= max(n1,n2) ) // Op � ��������� n1-n2
    return strchr( sN,':' ) + 2 ; // ������������� ����� ':' � '������'
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lVrt ); // ���� �� ����� ������ sVrt ( ����� �����. do )
//
////////////////////////////////////////////////////////////////////////////////
// --- ������ ������ sN ����� �������� ���� '=Def:'-----------------------------
//
 iStart = 0;
//
 do // �� ���������� '=n1/n2:' ��� '=Def:'
 {
  iEnd = c_FindSubString( sVrt, sN, iStart, 0 );
// --- ������ ��������� ������ sMess ������ ���������� -------------------------
//
  if( ! cmp_def( sN ) ) // '=Def:' ��� ��� �����...
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
  if( sscanf( sN, "%s ", sName ) == 1 ) // ���������� ������
   return strchr( sN,':' ) + 2 ; // ������������� ����� ':' � '������'
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lVrt ); // ���� �� ����� ������ sVrt ( ����� �����. do )
//
////////////////////////////////////////////////////////////////////////////////
//
 return "\0" ; // �� ������� ������ ������ - ��������� (�� ���������)
//
} // --- ����� c_GetMetricsByOp ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
REAL __fastcall c_GetMetricOpByName( INT Op, char* nameMetric )
{ // ������� �������� �������� ������� nameMetric ������� (���������) Op
 char sW[_512], nameM[_128];
 REAL Val; // �������� �������
//
 for( INT iM=1; iM<=c_GetCountMetricsByOp(Op); iM++ ) // ���� �� ����� "-nameMetric Val"
 {
  strNcpy( sW, c_GetNumbMetricByOp( iM, Op ) ); // ��������� ��� ��������� � s
  if ( sscanf( sW, "-%s %g", nameM, &Val) != 2 ) // �������� ��������� "-nameMetric Val"
   continue;
//
  if ( !strcmp( nameM, nameMetric ) ) // ���� ����� ������ - ���������� Val
   return Val;
 }
//
 return ERR_METRIC ; // ���� �� ����� ������� ������ �� �������...
//
} // ----- ����� c_GetMetricOpByName -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// ==== ������ � ��������� ��� =================================================
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountMetricsByEdge(INT from_Op,INT to_Op)
{ // --- ���������� ����� ������ ��� ����� ��������� from_Op-to_Op -------------
 char str[_4096];
 INT k = 0;
//
 strNcpy( str, c_GetMetricsByEdge( from_Op, to_Op )  ); // ���� ��� ������ ����������
//
 for( INT i=0; str[i+1] != '\0'; i++ ) // �� ������ ���������� �� ��� �������
  if ( (str[i]=='-') && (isalpha(str[i+1])) ) // �������� �� ������ ['-' + ���.�����]
   k ++ ; // ���������, ����� ��� ����������� ['-' + ���.�����]
//
 return ( k ) ;
//
} // --- �����  c_GetCountMetricsByEdge ----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetNumbMetricByEdge(INT Numb, INT from_Op, INT to_Op)
{ // --- ���������� ��������� Numb ������ ������� ������� (�����������) ����������� Op
// --- ���� �������������� ������ '-'+���.�����] -------------------------------
 char sN[_4096], sR[_2048];
 INT iStart = 0, iEnd,
     rep=0; // ����� ��������� �������
//
 strNcpy( sN, c_GetMetricsByEdge( from_Op, to_Op ) ); // ���� ��������� ���������� ��� ������� (���������) from_Op - to_Op
 INT lN = strlen( sN ); // ����� ������ sN
//
 do // �� ���������� '-' + ���.����� ( �� sN )
 {
  iEnd = c_FindSubString( sN, sR, iStart, 1 );
//
// --- ������ ��������� ������ sN ������ ���������� ��������� ------------------
//
  rep ++ ; // ����� ��������� sR � sN
//
  if ( rep == Numb ) // ����� ��� ����...
  {
   DeleteSpacesTabsAround( sR ); // ������� ������� ������� � �����
   return sR ; // ���������� ���������
  }
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lN ); // ���� �� ����� ������ sN
//
 return "\0" ; // ���� ������ �� �����...
//
} // --- ����� c_GetNumbMrtricByEdge -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetMetricsByEdge(INT from_Op, INT to_Op)
{ // ���c��������� ������ sVrt � ���������� ��������� ���� ���������� ������� (���������) Op
 char sN[_8192], sName[_128];
 INT  lEdg, iStart=0, iEnd, n1,n2, m1,m2;
//
 if( ! (lEdg = strlen( sEdg ) ) ) // ���� ������ ������ ������ ������...
  return "\0" ;
//
////////////////////////////////////////////////////////////////////////////////
// --- ������ ������ sN ����� �������� ���� '=n1/n2:'---------------------------
//
 do // �� ���������� '=n1/n2:' ��� '=Def:'
 {
  iEnd = c_FindSubString( sEdg, sN, iStart, 0 );
// --- ������ ��������� ������ sOps ������ ���������� --------------------------
//
  if( cmp_def( sN ) ) // '=Def:' ���� �� �����... ������ �� do !
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
  if( Test_n1n2m1m2 ) // ���������� ������ "=n1/n2|m1/m2:^" �� sN
   if( ( from_Op >= min(n1,n2) && from_Op <= max(n1,n2) ) &&
       (   to_Op >= min(m1,m2) &&   to_Op <= max(m1,m2) ) ) // Op � ��������� n1/n2 - m1/m2
    return strchr( sN,':' ) + 2 ; // ������������� ����� ':' � '������'
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lEdg ); // ���� �� ����� ������ sVrt ( ����� �����. do )
//
////////////////////////////////////////////////////////////////////////////////
// --- ������ ������ sN ����� �������� ���� '=Def:'-----------------------------
//
 iStart = 0;
//
 do // �� ���������� '=n1/n2|m1/m2:' ��� '=Def:'
 {
  iEnd = c_FindSubString( sEdg, sN, iStart, 0 );
// --- ������ ��������� ������ sMess ������ ���������� -------------------------
//
//  DelSpacesTabsAround( sN ); // �������� ������� �������
//
//  if( strncmp( sN, sDef, 5 ) ) // '=Def:' ��� ��� �����...
  if( ! cmp_def( sN ) ) // '=Def:' ��� ��� �����...
  {
   iStart = iEnd ;
   continue; // ...do
  }
//
  if( sscanf( sN, "%s ", sName ) == 1 ) // ���������� ������
   return strchr( sN,':' ) + 2 ; // ������������� ����� ':' � '������'
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lEdg ); // ���� �� ����� ������ sEdg ( ����� �����. do )
//
////////////////////////////////////////////////////////////////////////////////
//
 return "\0" ; // �� ������� ������ ������ - ��������� (�� ���������)
//
} // --- ����� c_GetMetricsByEdge ----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
REAL __fastcall c_GetMetricEdgeByName(INT from_Op, INT to_Op, char* nameMetric)
{ // ������� �������� �������� ������� nameMetric ���� from_Op - to_Op
 char sW[_512], nameM[_128];
 REAL Val; // �������� �������
//
 for( INT iM=1; iM<=c_GetCountMetricsByEdge(from_Op,to_Op); iM++ ) // ���� �� ����� "-nameMetric Val"
 {
  strNcpy( sW, c_GetNumbMetricByEdge( iM, from_Op, to_Op ) ); // ��������� ��� ��������� � sW
  if ( sscanf( sW, "-%s %g", nameM, &Val) != 2 ) // �������� ��������� "-nameMetric Val"
   continue;
//
  if ( !strcmp( nameM, nameMetric ) ) // ���� ����� ������ - ���������� Val
   return Val;
 }
//
 return ERR_METRIC ; // ���� �� ����� ������� ������ �� �������...
//
} // ----- ����� c_GetMetricEdgeByName ------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsOpContainOnTiers(INT Op)
{ // ���� �������� Op ������������ � Tiers[][], ����������� TRUE, ����� - FALSE
 bool out = FALSE;
 register INT i;
//
 if( !isEdges ) // ������� Mem_Edges[] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(i=1; i<=c_GetCountOps(); i++) // �� ���� ����������
  if( c_GetNumbOp( i ) == Op )
   return TRUE;
//
 return out;
//
} // ---- ����� c_IsOpContainOnTiers -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetOpByMaxTierLowerPreset(INT Op)
{ // ����� ��������, ������������� ��������� �� ��������� Op � ����������� �� �����
// � ������������ ������� (���� ����� �������� ��������� - ������� ��������� �� ������)
 register INT i;
 INT to_Op, Op_maxTier, to_Tier, maxTier = -134567,
     nOut = c_GetCountOutEdgesByOp(Op); // ����� �������� ��� ��������� Op
//
 if( !isTiers ) // ������� Tiers[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( !nOut ) // ��� �������� ��������...
  return ERR_COMMON ; // ������, ��� ��� �������� ��������
//
 for(i=1; i<=nOut; i++) // �� ���� ��������� �����
 {
  to_Op = c_GetNumbOutEdgeByOp( i, Op ); // i-��� ��������������� �� ���� �������� ������������ Op
  to_Tier = c_GetTierByOp( to_Op ); // ���� �������� ��������� �� ����� to_Tier
//
  if( to_Tier >= maxTier ) // ���� ��������
  {
   maxTier = to_Tier;
   Op_maxTier = to_Op; // ���������� to_Op...
  }
//
 } // ����� ����� �� ��������� �����
//
 return Op_maxTier;
//
} // --- �����  c_GetOpByMaxTierLowerPreset ------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CreateAndOutputDataLiveDiagrByTiers( int Rule, char FileName[] )
{ // �� ������� Tiers[][] ������ � ������� � Tld ���������� � ������� ����� ������
// ����� ��������� ����� ������� (������� ��� ����������� ����� �����������
// ��� ��������/�������� ������ ����� ���������� �� ������ ���
// ��������, ��� ���� ��������� ����� ��� ���� ������������ ������������
// ��� Rule = 0 ����� � ��������� ����, ��� Rule == 1 ����� � ���� FileName
// ��� Rule == 2 ����� � ������ ������������ �������
 char sN[_8192], sS[_8192], sW[_128];
 INT i,j,k,l, from_Op,to_Op, to_Tier, max_to_Tier;
//
 if( !isTiers ) // ������� Tiers[][] �� ����������...
 {
  t_printf( "\n-W- ��� ���������� ��������� ������� ����� ������ �������� ������� ���..! -W-\n");
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 TLD->Clear(); // ������� �� ������ ������...
//
 TLD->Add( IntToStr(nTiers+1) ); // ����� ����� � Tld
//
 if( !Rule ) // ����� � ��������� ����
  t_printf( "\n-=- �������� ��������� ������� ����� ���������� ������ -=-\n     (���������� ���������� ������ ��� = %d )", nTiers+1 ); // ������ � ������ ������
//
 for(INT iBottom=1; iBottom<=nTiers+1; iBottom++) // iBottom - ������ ������� ��������� � ���
 {
  strNcpy( sN, "" ); // �������� ������ ���������� ��������� ������ � "����" � ���� ����� iBot
  l = 0; // ����� ���������� ������ ������
//
  for(i=0; i<iBottom; i++) // �� ������ ���, �� ������� (����������) iBot
  {
   for(j=1; j<=c_GetCountOpsOnTier(i); j++) // �� ���������� �� ����� i
   {
//
    APM // ���� ���������� Wimdows ---------------------------------------------
//
    from_Op = c_GetOpByNumbOnTier(j,i); // �������� ����� �������, �� ������� ������� ����
    to_Op = c_GetOpByMaxTierLowerPreset( from_Op ); // ���� �������� ��� ��� ������ - ������������ ERR_COMMON
//
    max_to_Tier = ( to_Op == ERR_COMMON ) ? nTiers + 1 : c_GetTierByOp( to_Op ); // ��������������� to_Op ���� ���� �������� / �� ��������
//
    if( max_to_Tier >= iBottom ) // ���� ����� ���� ����� ��� ����� ����� ���� ���������
    {
     if( !c_GetCountInEdgesByOp( from_Op ) ) // ��� ������� (��������) ������� ������
     {
      if( !Rule ) snprintf( sW,sizeof(sW), " \xAB%d|%d->%d", from_Op, i, max_to_Tier ); // "\xAB" = "<<" ; "\x96\x9B" = "->"
      else        snprintf( sW,sizeof(sW), " %d|%d->%d",     from_Op, i, max_to_Tier ); // ����� � ����
     }
     else
     if( !c_GetCountOutEdgesByOp( from_Op ) ) //  // ��� ������� (��������) �������� ������
     {
      if( !Rule ) snprintf( sW,sizeof(sW), " %d\xBB|%d->$", from_Op, i ); // "\xBB" = ">>"; "x96\x9B"= "->"
      else        snprintf( sW,sizeof(sW), " %d|%d->$",     from_Op, i ); // ����� � ����

     }
     else
      snprintf( sW,sizeof(sW), " %d|%d->%d", from_Op,i, max_to_Tier ); // "x96\x9" = "->"
//
     strcat( sN, sW ); // ��������� � sN ��� ������������ ������ ������
//
     l ++ ;
    } // ����� if( max_to_Tier >= iBottom )
//
   } // ����� �� j (������� ���������� �� ����� i)
//

  } // ����� ����� �� i (�� ���� ������ ���)
//
 if( iBottom == nTiers+1 ) // ��������� ��������� ���� (������������ ������)
  if( !Rule ) t_printf(      "%d/$|%d: %s",  iBottom-1, l, sN ); // ������� ������ ���������� ��������� c ������ ������ iBot
  else      TLD->Add( Format("%d/$|%d: %s",  OPENARRAY(TVarRec, ((int(iBottom-1)),(int(l)),sN))) );
 else // �� ��������� (���������) ����
  if( !Rule ) t_printf(      "%d/%d|%d: %s", iBottom-1, iBottom,l, sN );
  else      TLD->Add( Format("%d/%d|%d: %s", OPENARRAY(TVarRec, ((int(iBottom-1)),(int(iBottom)),(int(l)),sN))) );
//
 } // ����� ����� �� iBottom (iBottom - ������ ������� ��������� � ���)
//
 if( Rule == 1 ) // ����� � ����
  TLD->SaveToFile( ReformFileName(FileName,extTld) );
//
} // ---- ����� c_CreateAndOutputDataLiveDiagrByTiers --------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutTLDToTextFrame()
{ // ������ ��������� ������� ����� ������ � ��������� ����
 c_CreateAndOutputDataLiveDiagrByTiers( 0, "" );
} // ----- ����� c_PutTLDToTextFrame -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_SaveTLD( char FileName[] )
{ // ������ ��������� ������� ����� ������ � ����
 c_CreateAndOutputDataLiveDiagrByTiers( 1, FileName ); // �������������� Filename - ��� ���������������� ������
} // ----- ����� c_SaveTLD -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_WinExec( char *cmdLine, INT cmdShow )
{ // ��������� ��������� ����� WinExec -----------------------------------------
// t_printf( "\n->%s %d %d\n", cmdLine, cmdShow, WinExec( cmdLine, cmdShow ) );
 return WinExec( cmdLine, cmdShow );
} // ----- ����� c_WinExec -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_ShellExecute( char *Operation, char *File, char *Parameters, char *Directory, INT cmdShow )
{ // ��������� ��������� ����� ShellExecute ------------------------------------
// t_printf( "\n->%s %s %s %s %d\n", Operation, File, Parameters, Directory, cmdShow );
 return (INT)ShellExecute( Application->Handle, Operation, File, Parameters, Directory, cmdShow );
} // ----- ����� c_ShellExecute ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall
c_CreateProcess(char* CommandLine, byte RuleParent, byte Priority, bool RuleMessage)
// �������� ���������� �������-������� �������� ��������� �����e CommandLine
// ��� RuleParent=0 �������-�������� ���� ��������� ������ ������� (��� ����
// �������� �������� ������ WINDOWS-����������� ����� ������ ProcessMessages)
// ��� RuleParent=1 �������-�������� �� ���� ��������� ������ �������
// ��� ���� ������ ��������� RuleParent �������-��������
// ����� ������� ��������-������� �����������.
//-----------------------------------------------------------------------
// Priority=0/1/2/3 ������������� ����������� ������������ ����������
//           REALTIME/HIGH/NORMAL/IDLE �������������� (��� 16-��� �� ������������)
//          (��� ������ �������� Priority ������������� IDLE)
//-----------------------------------------------------------------------
//  ��� RuleMessage=TRUE �������� ��������� �� ������� }
{
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  DWORD dwCreationFlag,dwExitCode;
  bool out;
//
// ��� ���� ��������� si (����� ���� cb) ������ ���� ��������
// �.�. ���� ����� �����, ���������� ���� ������� ������ ����...
// ���� �������� ����� ���������� ��������� ������ (������������ FillChar)
  memset( &si, 0, sizeof(STARTUPINFO) );
  si.cb = sizeof(STARTUPINFO);  // �������� ���� cb
//
  switch (Priority)  // ��������� ���������� ��������-�������
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
  if (!out) // ���� ����� ��������... out=FALSE
  {
   if (RuleMessage)  // ���� ����� ����� ������ ��������� �� �������
    MessageDlg("��������, ����������\n\r\n\r" +
                AnsiUpperCase(CommandLine)  +
               "\n\r\n\r����������...  (������ " +
                IntToStr(GetLastError()) + ")",
                mtError,
                TMsgDlgButtons() << mbYes, 0);
   return FALSE ;
  } // ����� IF out = FALSE
//
  if (out) // ���� ����� ������... out = TRUE
  {
   if (RuleParent == 0) // ���� �������� ������ ����� ��������� ������ �������
   {
    CloseHandle(pi.hThread); // ����� ������ �� ����� - �������
    if (WaitForSingleObject(pi.hProcess, INFINITE) != WAIT_FAILED) // ����������� ���� ��������
    {
     GetExitCodeProcess(pi.hProcess, &dwExitCode); // ���� ������ ������� ��������...
     if (RuleMessage) // ���� ����� ����� ������ ��������� �� �������
      if (dwExitCode != WAIT_OBJECT_0) // WAIT_OBJECT_0 = ������������ ���������� ��������
       MessageDlg("��������, �������\n\r\n\r" +
                   AnsiUpperCase(CommandLine) +
                  "\n\r\n\r�������� � ������� " +
                   IntToStr(dwExitCode) + "\n\r",
                   mtError,
                   TMsgDlgButtons() << mbOK, 0);
     CloseHandle(pi.hProcess); // ����������� ����� ��������
    } // ����� IF WaitForSingleObject...
   } // ����� IF RuleParent = 0
//
   if (RuleParent == 1) // �������� �� ������ ����� ��������� ������ �������
    return FALSE ; // ����� - ������ �� �����
//
   if ((RuleParent != 0) && // �������� �����������
       (RuleParent != 1))
    Application->Terminate(); // ��������� ������������ �������
//
 } // ����� IF out=TRUE
//
} // ----- ����� c_CreateProcess -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CreateProsess( char *cmdLine, byte RuleParent, byte Priority, bool RuleMessage )
{ // ��������� ��������� ����� CreateProsess -----------------------------------
 tp_printf( "\n->%s %d %d %d\n", cmdLine, RuleParent, Priority, RuleMessage );
 c_CreateProcess( cmdLine, RuleParent, Priority, RuleMessage );
} // ----- ����� c_CreateProcess -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_SaveEdges(char FileName[])
{  // ����� ��� ��� ������� �������� �����
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName( FileName,extEdges ) ); // ��������������� ��� �����
//
 if(!(fptr = fopen(NewFileName, "w"))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� ��������� ���� %s ������ ��� (��������������� ������) ��� -E-\n-W- ��������� �������������� ������ �� �������� �������� ������ -W-",
                   NewFileName );
  return FALSE ;
 }
//
// setbuf( fptr, NULL ); // ��������� ������������ ��� ������
//
 fprintf( fptr, "#\n// Valery Bakanov research computer complex (2008 and further); e881e@mail.ru, http://vbakanov.ru/left_1.htm\n");
 fprintf( fptr, "#  Total edges in this directed graph: %d\n", nEdges ); // ����� ���
 fprintf( fptr, "/* This file was automatically created thru program SPF_CLIENT.EXE\n" ); // ����� ��������� ������ ����
 fprintf( fptr, "   file name: %s , dat� creation: %s */\n#\n", AnsiUpperCase(NewFileName) , uniqueStr );  // ���� ��������
 fprintf( fptr, "digraph %s {\n", AnsiUpperCase(ChangeFileExt(ExtractFileName(NewFileName),"") )); // ��� ����� ��� ����������
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ����� �����
  fprintf(fptr, "%d -> %d ;\n", Edges(0,iEdge), Edges(1,iEdge)); // �������� "������" -> �������� "����"
//
 fprintf( fptr, "}\n" ); // ��������� ������ �����
//
 fclose( fptr); // ������� ����
//
 return TRUE ;
//
} // --- ����� c_SaveEdges -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ReadEdges(char FileName[])
{ // ������ �� ����� FileName ������ � ����� (������ Mem_Edges[] ������ ������
// - � ������ ���������� �� ������ Tier = 0 - ������� ������ ); Mem_Edges[]
// - � Tiers[][] - ����������; ��� ������ �������� ����� FileName ����������� FALSE
 char str[_2048*4];
 FILE *fptr = NULL; // ��������� �� ����
 bool flagEdges = FALSE, // ���� ������ �������� ��� � ��A
      flagMLC   = FALSE; // ���� �������������� ����������� (Many Lines Comment)
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extGv) ); // ��������������� ��� �����
//
 if( !(fptr = fopen(NewFileName, "r")) ) // ���� �������� ����� ������� ��� ������
 {
  t_printf( "\n-E- ���������� ��������� ���� %s �������� ��� -E-\n-W- �������� �������������� ��� ���������� ������ -W-",
                   NewFileName );
  isEdges = FALSE ; // ������ Mem_Edges[] �� ������...
  isTiers = FALSE;
  return FALSE ;
 }
//
 strNcpy( FileNameEdges, NewFileName ); // ��������� ������� ��� ����� �������� ���
//
 Max_Edges = _128; // �������������� ������������ ���������� ��� � ���
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 Mem_Edges = ( me* ) realloc( Mem_Edges, Max_Edges * sizeof( me ) ); // ��������� ��� ���������������� ������ ������ �������� ��� ��������������� �����
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 nEdges = 1; // ����� ��� � ��� (����������, ��� ������������� � Lua ����������� � 1 )
//
 while ( 1 ) // ����������� ���� �� ������� GV-�����
 {
  if( fgets( str,sizeof(str), fptr ) == NULL ) // ������ ��������� ������ GV-�����
   break; // ���� ������ ��������� ��� ������ ����������...
//
  ReplaceManySpacesOne( str ); // �������� ��������� �������� ������ ������ �����-������������
  DeleteSpacesTabsAround( str ); // ������� ������� � ������ � ����� ������
//
  if( ( str[0] == '#' ) || ( (str[0] == '/') && (str[1] == '/') ) )
   continue; // ������ ���������� - ��� �����������
//
  if( str[0] == '/' && str[1] == '*' ) // ������ �������������� �����������
  {
   flagMLC = TRUE; // ������ �������������� �����������
   continue; // ��� ������ ����������
  }
  if( str[0] == '*' && str[1] == '/' ) // ����� �������������� �����������
  {
   flagMLC = FALSE; // ������ �������������� �����������
   continue; // ��� ������ ����������
  }
//
  if( sscanf( str, "digraph %s {", GraphName ) == 1 ) // ����� ���� ���� ���������...
   flagEdges = TRUE; // ������ �������� ��� ���
  if( str[0] == '}' )
   flagEdges = FALSE; // ����� �������� ��� ���
//
//  if( flagEdges && !flagMLC )
  if( flagEdges )
   if ( !ParseStringAndAddEdges( str ) ) // ���������� ������ str �� �������� ��� ���������� ������� ���
    return FALSE;
//
////////////////////////////////////////////////////////////////////////////////
 } // ����� while( 1) ----------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
//
 fclose(fptr); // ������� ���� FileName
//
 nEdges -- ; // ����� ��� � ��� (global)
//
 t_printf( "\n-I- ���� %s �������� ����� ������� �������� -I-", FileNameEdges );
//
 isEdges = TRUE ; // �� ��������� - ������ Mem_Edges[] ������
//
 c_GetCountOps(); // ������� ����� ���������� (������ �����) ��� �������
//
 c_GetCountOpsInput(); // ������� ����� ���������� (������ �����) ������ �������
//
 c_GetCountOpsOutput(); // ������� ����� ���������� (������ �����) ������ ��������
//
////////////////////////////////////////////////////////////////////////////////
 snprintf( str,sizeof(str), "%s (��� - ����: %s ; ���: %s)", TitleF2, FileNameEdges, GraphName );
 F2->L_TMM->Caption = str;
 F2->L_TMM->Repaint();
////////////////////////////////////////////////////////////////////////////////
//
 isTiers = FALSE; // ������ Tiers[][] �� ������
//
 return TRUE ;
//
} // ------ ����� c_ReadEdges --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall TestAndAddMemoryForEdges( INT nEdges )
{ // ��������� ������������� ���������� ������� ��� Mem_Edges[] � ���
// ������������� ����������� ��� � stockMem ���. ��� ������ ��������� TRUE...
//
 if( nEdges < Max_Edges ) // ������ ��� ������� Mem_Edges[] ����������...
  return TRUE;
//
// ===== ������ �� ������� =====================================================
//
 Max_Edges *= stockMem; // ����������� � stockMem ��� ������, ��� ����...
 Mem_Edges = ( me* ) realloc( Mem_Edges, Max_Edges * sizeof(me) ); // �������������� ������ ��� Mem_Edges[]...
//
 if( !Mem_Edges ) // ������ ����� - ������������� �������������� ������ �� ����������..!
 {
  char str[_1024];
  snprintf(str,sizeof(str), "�������� ������ ��� ���������� ������� ��� (Input). ����������� %d ���������...",
                             Max_Edges );
  MessageBeep(MB_OK); // �������� ��������������...
  MessageBox(0, str, "��������������", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  isEdges = FALSE ; // ������ Mem_Edges[] �� ������...
  return FALSE ;
 } // �����  if( Mem_Edges == NULL )
 else
 {
  t_printf( "\n-I- ������ ��� (Input) �������������� �� %d ��������� -I-",  Max_Edges );
  return TRUE;
 }
//
} // ---- ����� TestAndAddMemoryForEdges ---------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall ParseStringAndAddEdges( char *str )
{ // ��������� ������ str, �������� ������������ ���� ������ ������ � ��������� �� � ������ ���
// ����� ������ ������: a -> b -> c -> -> d ; ��� a,b,c,d - ����� �����
// ��� ������ ������������� ������ ��� ���������� ������� ��� ��������� FALSE
//
 INT i,j,k=0;
//
// ----- ���� ������ ����������� -----------------------------------------------
//
 for( i=0; i<strlen( str ); i++ ) // �� c����� str...
  if( str[i] == ';' ) // ���� ������ ��������� ������� ";"
  {
   for( j=i+1; j<=strlen(str); j++ ) // �� ������� ������ ������� �� ";" �� ����� ������
    Mem_Edges[ nEdges ].Operators[ k++ ] = str[ j ]; // �������� �����������
//
   DeleteSpacesTabsAround( Mem_Edges[nEdges].Operators ); // ������� ������� ������ � ����� � ������ Mem_Edges[nEdges].Operators
   ReplaceManySpacesOne( Mem_Edges[nEdges].Operators ); // ������������� ������� �������� ������������
//
//   t_printf( "-= %d %s =-", nEdges, Mem_Edges[ nEdges ].Operators );
//
   str[i] = '\0';
   break;
  }
//
 DeleteAllSpaces( str ); // ������� ��� ������� � ������ str
//
 while( 1 ) // ����������� ���� �� ���������� ���� "a -> b"
 {
//
  if( sscanf( str, "%d->%d", &Edges(0,nEdges), &Edges(1,nEdges) ) == 2 ) // ����� 2 ���� ���������
  {
   nEdges ++ ;
   if( !TestAndAddMemoryForEdges( nEdges ) ) // ���� �� ��������� ������ ��� Mem_Edges[] ?
    return FALSE;
  } // �����  if( sscanf( str, "%d -> %d",
 else // ����� 2 ���� ��������� �� �������..!
  return TRUE;
//
 for( i=0; i<strlen( str ); i++ ) // �� ������ str...
 {
  str[i] = ' ';
  if( str[i+1] == '>' )
  {
   str[i+1] = ' ';
   break;
  } // ����� if( str[i+1] == '>' )
//
 } // ����� for( i=0; i<strlen( str ); i++ )
//
 DeleteSpacesTabsAround( str ); // ������� ������� � ������ � ����� ������
//
 if( strstr( str, "->" ) == NULL ) // ����� � str ��� ��������� "->"...
  return TRUE;
//
 } // ����� while ( 1 )
//
} // ----- ����� ParseStringAndAddEdges ----------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall ReadAndPrimWorkOpsCalcsVertEdgeFiles( char FileName[] )
{ // ������ � ��������������� ��������� ������ *.ops, *.cls, *.med, *.mvr
 FILE *fptr;
 char buff[_4096]; // ������������ ����� ������ �����
//
 if( !(fptr = fopen(FileName, "r")) ) // ������� �������?..
  return FALSE ; // �� ������� �������...
//
 strNcpy( sWork, "\0" ); // �������� ������ (sWork - ����������)
//
 while( 1 ) // ���� �� �������� �����
 {
  if( !fgets(buff,sizeof(buff),fptr) ) // ���� � ����� ������ ��� �����...
   break;
//
  for( INT i=0; i<strlen(buff); i++ ) // �� ���� ��������� ������...
   if( buff[i] == ';' ) // ';' �������� �� ����� ������
    {
     buff[i] = '\0';
     break;
    }
//
  strcat( sWork, buff ); // buff ��������� � ������ sWork (������)
 } // ����� while( 1 )
//
 fclose( fptr ); // ������� ���� FileName
//
 for( INT j=0; j<strlen(sWork); j++ ) // �� ���� ������ sWork...
  if( sWork[j] == '\n' || sWork[j] == '\r' || sWork[j] == '\t' )
   sWork[j] = ' ';
//
 DeleteSpacesTabsAround ( sWork ); // ������� ������� �������
 ReplaceManySpacesOne( sWork ); // ������� ������� �������� ������
//
 return TRUE;
} // ----- ����� ReadAndPrimWorkOpsCalcsVertEdgeFiles --------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_LuaCallByTimer( char *CommandLine, INT d_Ticks )
{ // ����� Lua-���������� � ��������� d_Tick (������ settimeout() �� JS)
//
 if( d_Ticks <= 0 )
  return -1 ;
//
 bool flag = FALSE; // ���� � ������ �� ������ �������...
 for( int i=0; i<strlen(CommandLine); i++) // ���� �� �������� � ������ CommandLine
 {
  if( CommandLine[i] != ' ')
  {
   flag = TRUE; // ���� ���� �� ���� ��-������..!
   break;
  }
 } // ����� �� �������� � ������
 if( !flag ) // ������ ������
  return -2 ;
//
 i_Events ++ ; // ������ ��������� � ������� �������
//
 if( i_Events >= max_Events-10 ) // ������� � ������� max_Events
 {
  max_Events *= 1.5 ; // ��������� ������� �������...
  Mem_EV = (ev*) realloc( Mem_EV, max_Events*sizeof(ev) ); // ��������� ������ �������
  t_printf( "\n-I- ������ Mem_EV �������������� �� %d ��������� -I-", max_Events );
 }
//
 Mem_EV[i_Events].start_Ticks = ticks; // ������ ������ �������
 Mem_EV[i_Events].d_Ticks     = abs(d_Ticks); // �������� ����� �������� ������
 Mem_EV[i_Events].ev_Ticks    = ticks + abs(d_Ticks); // ������ ������
 strNcpy( Mem_EV[i_Events].CommandLine, CommandLine ); // ����� ������
//
// t_printf("\n������: Start: %d, Delay: %d, Now: %d ticks, [Real_Delay: %d] [i_Events: %d] |%s|\n\n",
//            Mem_EV[i_Events].start_Ticks, Mem_EV[i_Events].d_Ticks, ticks,
//            ticks-Mem_EV[i_Events].start_Ticks, i_Events, Mem_EV[i_Events].CommandLine );
//
 return 0 ; // ���������� ����� �������
//
} // ------ ����� c_LuaCallByTimer ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::On_Master_Timer(TObject *Sender)
{ // ���������� Master_Timer'�� ������ Master_Timer->Interval �����������
//
 ticks ++ ; // ����������� ������� �����...
//
 for( INT i=0; i<=i_Events; i++ ) // �� ����� ������� �������
 {
  if( Mem_EV[i].d_Ticks <= 0 || // ���� ������������ ����� ���� ��� 0.. "���"
      Mem_EV[i].ev_Ticks != ticks ) // ����� ������ ������� �� ����� �������� ������ ����... ���
   continue; // ���������� ����-c...
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  if( flag_Busy == TRUE ) // �� ������� ���������� ����� CallLuaThread...
  {
   tpe_printf( "\n-W- ����� %s �������� ��-�� ����������� ����������� ������ %s... -W-",
               Mem_EV[i].CommandLine, busy_CommandLine );
   continue;  // ����������-c...
  }
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  
*/
 if( !L ) // ���� �������� ��������� L ��� ����������, ������ ������ �� ���� - �������...
 {
  Master_Timer->Enabled = FALSE; // ���������� Master_Timer
  return;
 }
////////////////////////////////////////////////////////////////////////////////
// ------ �� ���������, ��������� ����� Lua � ����� ������ --------------------
   CallLuaThread( Mem_EV[i].CommandLine ); // ����� CommandLine �� ����� ��������� ������ Lua
//
//   t_printf("\n\n�����: Start: %d, Delay: %d, Now: %d ticks, [Real_Delay: %d] [i_Events: %d] |%s|\n\n",
//            Mem_EV[i].start_Ticks, Mem_EV[i].d_Ticks, ticks,
//            ticks-Mem_EV[i].start_Ticks, i_Events, Mem_EV[i].CommandLine );
//
   if( Mem_EV[i].d_Ticks != ticks-Mem_EV[i].start_Ticks )
    tpe_printf( "\n\n-W- �������������� �������� ���������� Lua-������� '%s', �������� ������/��������: %d/%d; ������/�����: %d/%d ����� -W-\n",
                Mem_EV[i].CommandLine, Mem_EV[i].d_Ticks, ticks-Mem_EV[i].start_Ticks,
                Mem_EV[i].start_Ticks, ticks );
//
   Mem_EV[i].d_Ticks *= -1; // ������� ��������� - ��� "�������" ���� �������� �������������� ������� ������������
//
 } // ����� ����� �� ����� ������� ������� for( INT i=0; i<=i_Events; i++ )
//
} // ----- ����� TF1::On_Master_Timer ------------------------------------------

void __fastcall CallLuaThread( char *CommandLine )
{ // ����� CommandLine �� ����� ��������� ������ Lua
 char *sf = "\n�������� � %s. ���������� Lua �����������... (%s)\n��������� ������������ ������ '%s'...\n";
 int error1, error2;
 lua_State *L1;
//
 flag_Busy = TRUE; // ���������� CallLuaThread ������..!
//
 strNcpy( busy_CommandLine, CommandLine ); // �������� ��� ������������� Lua-�������...
//
 try
 {
  L1 = lua_newthread( L ); // ������ ���� (���������) L1 ������ ��������� L
 }
 catch( ... ) // ����� ����� ����������...
 {
  tpe_printf( "\n�������� � ����������� lua_newthread � ������ %s (%s)...\n", CommandLine, __FUNC__ );
  goto ended;
 } // ����� cath( ... )
//
// luaL_openlibs(L1); // ���������� ����������� ����������
//
 try
 {
  error1 = luaL_loadstring(L1,CommandLine); // �������� ������ ��� ����������
 }
 catch( ... ) // ����� ����� ����������...
 {
  tpe_printf( sf, "luaL_loadstring", __FUNC__, CommandLine );
  goto ended;
 } // ����� cath( ... )
//
 try
 {
  error2 = lua_pcall(L1,0,0,0); // ���������� � ����������
 }
 catch( ... ) // ����� ����� ����������...
 {
  tpe_printf( sf, "lua_pcall", __FUNC__, CommandLine );
  goto ended;
 } // ����� cath( ... )
//
 if( error1 || error2 )
  t_printf( "\n%s: ������ ������� ���������� Lua: %s\n", __FUNC__, lua_tostring (L1,-1) );
//
ended: flag_Busy = FALSE; // ���������� CallLuaThread ���������...
//
} // ----- ����� CallLuaThread -------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_SwapOpsTierToTier(INT Op1, INT Op2)
{ // --- ������ ������� ��������� Op1 � Op2, ����������� �� ������ ������
// ----- ���� ������� ������������ ��������� - ������������ TRUE � ���������� iMove
//
 if( !isTiers ) // ���� ������� Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 INT Tier1 = c_GetTierByOp( Op1 ), // ���� ���������� ������� �� ������������ ����������
     Tier2 = c_GetTierByOp( Op2 ); // ...�������...
//
 if( Op1 == Op2 ||  // �� ������-� ������ ���������-�... �������� �������� !!!
     Tier1 == Tier2 )
 {
//  DisplayMessage( "E", __FUNC__, messParams2, FALSE ); // ������ ���������
  return TRUE ;
 }
//
 if( Tier1 == ERR_COMMON || // �������� �� ������������ ����������� Tier1
     Tier2 == ERR_COMMON ) // ...tier2
 {
  DisplayMessage( "E", __FUNC__, messParams1, FALSE ); // ������ ���������
  return FALSE ;
 }
//
 if( ( Tier1 < 1 && Tier1 > nTiers ) || // � �������� � � ����� ���� ���������� ��������� ������...
     ( Tier2 < 1 && Tier2 > nTiers ) )  // �� ��...
 {
  DisplayMessage( "E", __FUNC__, messParams1, FALSE ); // ������ ���������
  return FALSE ;
 }
//
 if( ( Tier1 < c_GetMinTierMaybeOp( Op1 ) ) || // �������� ������������ �������� ��������� Op1
     ( Tier1 > c_GetMaxTierMaybeOp( Op1 ) ) ||
     ( Tier2 < c_GetMinTierMaybeOp( Op2 ) ) || // �������� ������������ �������� ��������� Op2
     ( Tier2 > c_GetMaxTierMaybeOp( Op2 ) ) )
 {
  DisplayMessage( "E", __FUNC__, messParams3, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 if( c_MoveOpTierToTier( Op1, Tier2 ) == TRUE ) // �������� ������� �p1 �� ���� ���������� Op2
  if( c_MoveOpTierToTier( Op2, Tier1 ) == TRUE ) // ������� ������� �p2 �� ���� ���������� Op1
   return TRUE ;
//
 return FALSE ;
//
} // ----- ����� c_SwapOpsTierToTier -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutTimeLiveDataToTextFrame()
{ // ��������� � ������ � ��������� ���� ��������� ����� ������ (������ F6)
 c_CreateAndOutputDataLiveDiagrByTiers( 0, "" ); // ������� � ������ � ��������� ���� ��������� ������� ����� ������ �� �����eve Tiers[][]
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_DrawDiagrTLD()
{ // ������ ����������� ����������� (���������) ����� ����� ���������� ������
 INT OpsOnTier,
     H_pix, B_pix, // ������ � ������ ������� ��������� IM1 � ��������
     B_rect, // ������ �������������� ������� � ��������
     x1,y1, x2,y2; // ���������� �������������� ������� � ��������
 char str[_256];
//
 if( !isTiers ) // ������� Tiers[][] ��� ���...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
////////////////////////////////////////////////////////////////////////////////
 TIM1->Picture->Bitmap->Height = TIM1->Height; // ��������� ������� �anvas �� �������� Image
 TIM1->Picture->Bitmap->Width  = TIM1->Width;  // !!! ����� ����� ( ���� 08.02.2017 ) !!!!!!
//
 H_pix = TIM1->Height; // ������ � ������ ������� ��������� IM1 � ��������
 B_pix = TIM1->Width;
//
// --- ��������� ���������� ����� � ��������� (����) ---------------------------
 TIM1->Canvas->CopyMode     = cmSrcCopy; // ������ �������� ������ ������������
//
 TIM1->Canvas->Brush->Style = bsSolid; // �������� �����
//
 TIM1->Canvas->Pen->Style   = psSolid; // ��������
 TIM1->Canvas->Pen->Mode    = pmCopy;  // ����� ���� = color
 TIM1->Canvas->Pen->Width   = 1; // ������� = 1
//
 TIM1->Transparent = false; // !!! ����������� !!! ����� �� ���� �����, ��� ��� IM1
//
// ��� �������� ���� ������ ���� � �c_DrawDiagrTLD(), � �������������� ---------
// ����� ���������� (� ��������� �������������) ����� � c_PutParamsTiers() -----
//
 INT n,n1,n2,m, // n1,n2 - ������ ����������� ����� ������� ���, m - ����� ������ � ���� ����������
     maxM=-1e10,minM=1e10, n1x,n2x, n1n,n2n; // max ������, min ������, ��������� ������ ���� � ����
 REAL averTLD=0.0; // ������-�������������� ������� ����������� ����� ������� ���
//
 c_CreateAndOutputDataLiveDiagrByTiers( 2, "" ); // ���������� ���������� ��� ������� ����� ������ �� �����. Tiers[][]
//
 sscanf( TLD->Strings[0].c_str(), "%d", &n ); // ����� ���-������ � ���
//
// ���� ���������� ����� ������ ------------------------------------------------
 for(INT i=1; i<=n; i++) // ���� �� ���� ����������� ������ ��� ��� ������� max/min
 {
  if( i < n ) // ����� ��������� ������ � $
   sscanf( TLD->Strings[i].c_str(), "%d/%d|%d:", &n1,&n2,&m ); // ������� ���� / ������ ���� / ����� ������ � ���� ����������
  else // ��������� ������ ������� "n/$|m"
  {
   sscanf( TLD->Strings[i].c_str(), "%d/$|%d:", &n1,&m ); // ������� ���� / $ / ����� ������ � ���� ����������
   n2=n1+1;
  }
//
  if( m >= maxM ) // ���� ��� ����� ����� ������
  { maxM = max(maxM,m); n1x=n1; n2x=n2; } // ��������� ���� ���� | ��������� ���� ���� (��������� ������-��...)
//
  if( m < minM ) // ���� �in ����� ����� ������
  { minM = min(minM,m); n1n=n1; n2n=n2; } // ��������� ���� ���� | ��������� ���� ���� (��������� ������-��...)
//
 averTLD += (REAL)m; // ��������� ��� ��������� �����.��������������� ������� ����� ������ ����� ������
//
 } // �����  for(INT i=1; i<=n; i++)
//
 averTLD /= (REAL)n; // �����.�������������� ������� ����� ������ ����� ������
//
 REAL dH_pix = 1.0 * H_pix / n, // ������� �  �������� �� ������ � ������ ������� ��������� ���������
      dB_pix = 1.0 * B_pix / maxM;
//
 dH_pix = max( dH_pix, 1.0 ); // ������ ������ ����  <= 1 , ����� ��������� ����������...
//
 snprintf(str,sizeof(str), "H|N/W=%d|/%d/%d-%d", n,maxM,n1x,n2x ); // ����� ���� / ��� ������ / ���� ������ - ���� �����
 F2->L_OM->Caption = str;
 F2->L_OM->Repaint(); // ������������� ��������������
//
 for(INT i=1; i<=n; i++) // ���� �� ���� ����������� ������ ��� ��� ���������� �������
 {
//
  if( i < n ) // ����� ��������� ������ � $
   sscanf( TLD->Strings[i].c_str(), "%d/%d|%d:", &n1,&n2,&m ); // ������� ���� / ������ ���� / ����� ������ � ���� ����������
  else // ��������� ������ ������� "n/$|m"
  {
   sscanf( TLD->Strings[i].c_str(), "%d/$|%d:", &n1,&m ); // ������� ���� / $ / ����� ������ � ���� ����������
   n2=n1+1;
  }
//
  B_rect = dB_pix * m; // ������ �������������� �������
//
// --- ������������� ����� ������� ---------------------------------------------
  if( m == minM )
   TIM1->Canvas->Brush->Color = brush_draw_color_MIN; // ���� ����� �������
  else
  if( m == maxM )
   TIM1->Canvas->Brush->Color = brush_draw_color_MAX; // ���� ����� ��������
  else
   TIM1->Canvas->Brush->Color = brush_draw_color_TLD; // ���� ����� �������
////////////////////////////////////////////////////////////////////////////////
  x1 = 0;  // ����� ������� ����� �������������� ������� ( Rectangle, Rect )
  y1 = dH_pix * ( i-1 );
//
  x2 = x1 + B_rect; // ������ ������ ����� �������������� ������� ( Rectangle, Rect )
  y2 = y1 + dH_pix;
//
// --- ������ �������������� ������, ���������������� ����� ���������� �� �����
  TIM1->Canvas->FillRect( TRect( x1,y1, x2,y2 ) ); // ������������� �������� ������
//
//  Delay( 1 ); // �������� 1 msec - ��� �� ��������� ������ �� ����������..!
//
  Application->ProcessMessages(); // ���� ���������� Windows
//
 } // ����� �����  for(INT i=1; i<=n; i++)
//
////////////////////////////////////////////////////////////////////////////////
// ----- ������ ������������ ����� - �����.�������������� �������� -------------
//
  TIM1->Canvas->Pen->Color = pen_draw_b_average; // ���� ����� �������� ����� ���������� �� ������; // ���� ����
  TIM1->Canvas->Pen->Mode  = pmCopy; // ���� ��� ������������� � �����
  TIM1->Canvas->Pen->Style = psDot; // �������� �����
  TIM1->Canvas->Pen->Width = 1; // ������� ���� 3 �������
//
  x1 = x2 = averTLD * dB_pix ;
  y1 = 0; y2 = TIM1->Height;
//
  TIM1->Canvas->MoveTo( x1,   y1 ); // ��������� ���� � x1,y1
  TIM1->Canvas->LineTo( x1,   y2 ); // �������� ����� � x1,y2
//
  TIM1->Canvas->MoveTo( x1-1, y1 ); // ��������� ���� � x1-1,y1
  TIM1->Canvas->LineTo( x1-1, y2 ); // �������� ����� � x1-1,y2
//
  TIM1->Canvas->MoveTo( x1+1, y1 ); // ��������� ���� � x1+1,y1
  TIM1->Canvas->LineTo( x1+1, y2 ); // �������� ����� � x1+1,y2
//
//  TIM1->Repaint(); // ������������� ������������
//
  return TRUE; // �� ������� �������
//
} // --- ����� �_DrawDiagrTLD --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall ReformFileName( char FileName[], char Ext[] )
{ // ����������� FileName � ������ ����� � ������ ������������ ���������� (".ext")
//
 char wF[_512],wE[_256],*p,
      NewFileName[_512],extFile[_128], // ����� ��� �����, ���������� ��� '>'
      Comma[]=".\0",Space[]=" \0",Unknown_Name[]="Unknown_Name\0", // �����, ������, ����������������
      UnacceptableSymbols[]="\/\\:*?\"<>|\0"; // ������������ ������� '/\:*?"<>|'
//
 if( strpbrk( ExtractFileName(FileName).c_str(),UnacceptableSymbols ) ) // �������� �� ������������ ������� UnacceptableSymbols � ����� �����
 {
  TVarRec Vr[]={ FileName,Unknown_Name,ExtractFileExt(FileName).c_str() }; // �������� ������ ��� ����������� ��������� ������
  DisplayMessage( "W", __FUNC__, TrimRight(Format("������������ ��� �����: %s , ���� ������������ �: %s%s",Vr,2)).c_str(),
                   ERR_UNCERTAIN );
//
  strcpy( FileName,Unknown_Name ) ;
  strcat( FileName,ExtractFileExt(FileName).c_str() );
 }
//
 DeleteSpacesTabsAround( FileName ); // ������� ������� � Tabs � ������ � � ����� ������
 DeleteSpacesTabsAround( Ext );
//
 if( FileName[0] == Comma[0] ) // ��� ���������� � '.'
 {
  strcpy( NewFileName, Unknown_Name ) ; // � ������ ������ 'Unknown_Name'
  strcat( NewFileName, ExtractFileExt(FileName).c_str() ); // ��������� ����������
  goto cont ;
 }
//
 strcpy( wF, ExtractFileName(FileName).c_str() ); // �������� ������ ���� "xxx.zzz"
 if( !strchr(wF,Comma[0]) ) // ���� '.' � ����� ����� �� �������...
  strcat(wF,Comma); // �������� � ����� �����
//
 p = strrchr( wF,Comma[0] ); // ���� ��������� ��������� '.' � wF
 if( p ) // ����� ��������� ��������� '.' � wF
 {
  strcpy( NewFileName, wF ); // �����������
  NewFileName[p-wF+1] = '\0'; // ���������� ��������� �� '.' �������� (��� '.' ��������)
 }
//
 strcpy( wE, ExtractFileExt( FileName).c_str() ); // �������� ������ ���� ".zzz"
//
 if( wE[0] == Comma[0] ) // ��������� ������ wE=='.'
 {
  wE[0] = Space[0]; // ��������� ������ wE �������� �� ������
  DeleteSpacesTabsAround( wE); // ������ �� ��������
 }
//
 if( !strlen( wE ) ) // ���� �����...
  strcat( NewFileName,Ext ); // ������� �������� ����������...
 else
  strcat( NewFileName,wE ); // ���������� ��� ����...
//
cont:
// t_printf( "\n��������������� ��� �����/����������: |%s|%s|\n", NewFileName,Ext );
 return NewFileName ;
//
} // --- ����� ReformFileName --------------------------------------------------



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CalcParamsTiers() // ������ �������������� ���������� ������ ���
{
//
 if( !isTiers ) // ������� Tiers[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 REAL averWidth = ( 1.0 * nOps ) / nTiers, // ������� ������ �� ���� ������ ��� ����� �������� (��������)
      sumSqWidth = 0.0 , // ������������ ��������� �������
      sumOps = 0.0 , // ����� ���������� �� ������  ���
      sumICL = 0.0 , // ����� ��� ������������ ��������������� �� ������ �������
      xAxis,yAxis, xAxis_old = 0.0,yAxis_old = 0.0 ;
 INT iTier, iOp ,
     nOpsOnTier, // ����� ���������� �� �����
     minOpsByTiers = 1000000, maxOpsByTiers = -minOpsByTiers , // ������� � �������� ���������� �� ������ ���
//
     sumDump = 0, sumEdges = 0 , // ��� ���������� ������� ����� ����;;
     OpFrom, OpTo, nOutEdges, iOutEdge ; // ... �� �� ...
//
// =============================================================================
 for( iTier=1; iTier<=nTiers; iTier++ ) // �� ���� ������ ���
 {
//
  nOpsOnTier = c_GetCountOpsOnTier(iTier); // ����� ���������� �� ����� iTier
//
  minOpsByTiers = min( minOpsByTiers, nOpsOnTier ) ; // ���� min / max
  maxOpsByTiers = max( maxOpsByTiers, nOpsOnTier ) ;
//
  sumSqWidth += ( averWidth - nOpsOnTier ) * ( averWidth - nOpsOnTier ) ; // ����� ��������� �������
// -----------------------------------------------------------------------------
//
  sumOps += nOpsOnTier ; // ����������� ����� ���������� �� ������ ���
  xAxis = (REAL)iTier / nTiers ; // ��� �������  (���� �������)
  yAxis = sumOps / nOps ; // ��� �������  (���� �������)
//
  sumICL += 0.5 * ( yAxis + yAxis_old ) * ( xAxis - xAxis_old ) ; // ������� ��������
//
  xAxis_old = xAxis ; yAxis_old = yAxis ; // �������� ���������� ��������
//
// =============================================================================
  for( iOp=1; iOp<=nOpsOnTier; iOp++ ) // �� ������� ���������� �� ����� iTier
  {
//
   OpFrom = c_GetOpByNumbOnTier( iOp, iTier ); // ����� ��������� �� ��� ������ iOp �� ����� iTier
   nOutEdges = c_GetCountOutEdgesByOp( OpFrom ); // ����� ��������� ��� � ��������� OpFrom
//
   for( iOutEdge=1; iOutEdge<=nOutEdges; iOutEdge++ ) // ���� �� ���� ��������� �����
   {
    OpTo = c_GetNumbOutEdgeByOp( iOutEdge, OpFrom ); // ����� ���������, � �������� ��� ���� iOutEdge �� ��������� OpFrom
    sumDump  += c_GetTierByOp( OpTo) - c_GetTierByOp( OpFrom ); // (#����� ��������� OpFrom) - (#����� ��������� OpTo)
    sumEdges += 1; // ����� ����� ������������������ ���
   } // ����� �����    for( iOutEdge=1; iOutEdge<=nOutEdges; iOutEdge++ )
//
// =============================================================================
  } // ����� for( iOp=1; iOp<=nOpsOnTier; iOp++ )
//
 } // ����� for( iTier=1; iTier<=nTiers; iTier++ )
//
 StatTiers.averWidth  = averWidth ;  // ������������������� ������ ��� (����� 0-�� ������)
 StatTiers.sumSqWidth = sumSqWidth ; // ����� ��������� �������
 StatTiers.SD = nTiers>1 ? sqrt(sumSqWidth/(nTiers-1.0)) : ERR_CALC ; // ��� (Standard Deviation)
 StatTiers.CV = nTiers>1 ? StatTiers.SD/averWidth : ERR_CALC ; // ����������� �������� CV (�����������)
//
// IC = max/min ���������� �� ������ ��� ( Irregularity Coefficient, ����������� ��������������� )
 StatTiers.IC = (REAL)maxOpsByTiers / minOpsByTiers ;
//
// ��������������� ������������� ���������� �� ������ ��� �� ������ �������
 StatTiers.ICL = ( sumICL - 0.5 ) / 0.5 ; // (����� ����������� ��������) �� ��������� � �����������
//
 StatTiers.AAL = (REAL)sumDump / sumEdges ; // �������������������� ����� ���� (Average Arc Length)
//
} // ----- ����� c_�alcParamsTiers() -------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutParamsTiers()
{ // --- ����� �������� ���������� ��� � ��� ��� -------------------------------
 char szOut[_4096], // ������ ��� ������ ��������������� ������
      Delimeter[] = " \246 " ; // ����������� ������ ��������� ������
// circle \225 \x0095; ����� \207 \x0087; ����.��� \174 \x007c; ������.����.����� \246 \x00A6
 REAL AverWidth, // ������� ������ �� ������ ����� ������� � ����������
      SumSqWidth = 0.0, // ����� ��������� ������� ������ �� ������
      AverSqDevWidth = 0.0; // ��.��.���������� ������ ������ ��� (����� ������ 1 � nTiers)
 INT  iOp, nOp,     iTier,     nTierMin,    nTierMax,
      Op,  dTiers,  sdOps = 0, sdTiers = 0;
//
 if( !isTiers ) // ������� Tiers[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
// =============================================================================
 c_CalcParamsTiers() ; // ���������� ���������� ����� ������ ��� � ��������� � ���-�� StatTiers (������)
//
 AverWidth = StatTiers.averWidth ; // ������������������� ������ ��� (����� 0-�� ������)
//
 AverSqDevWidth = StatTiers.SD ; // ����� ��������� �������
//
////////////////////////////////////////////////////////////////////////////////
//
 char szStatTiers[_256]; // ������ ���������� ������ ���
//
 if( nTiers != 1 )
  snprintf( szStatTiers,sizeof(szStatTiers), "��.�����.���.= %.4g, ���= %.4g, CV= %.4g, IC= %.4g, ICL= %.4g",
            StatTiers.averWidth, StatTiers.SD, StatTiers.CV, StatTiers.IC, StatTiers.ICL ) ;
 else
  snprintf( szStatTiers,sizeof(szStatTiers), "��.�����.���.= %,4g, ���= x.x, CV= x.x, IC= x.x, ICL= x.x",
            StatTiers.averWidth ) ;
//
// --- ��������� ������������� -------------------------------------------------
 for( iTier=1; iTier<=nTiers; iTier++ ) // �� ���� ������ ���
  for( iOp=1; iOp<=c_GetCountOpsOnTier(iTier); iOp++ ) // �� ������� ���������� �� ����� iTier
  {
   Op = c_GetOpByNumbOnTier( iOp, iTier ); // ����� ��������� �� ��� ������ iOp �� ����� iTier
   dTiers = c_GetMaxTierMaybeOp( Op ) - c_GetMinTierMaybeOp( Op ); // �������� ���������� ����������� Op �� ������

   if( dTiers ) // ���� �� ����...
   {
    sdOps += 1; // ��������� ����� ����������, ������� ����� ���� ���������� �� ������ ���
    sdTiers += dTiers; // ����� ���������� ��������� ����������� �� ������ ��� ��������� Op
   }
  } // ����� ����� �� iOp
//
// === ������ ��������� ���������� � ������� ����� ������ ����� ������� ��� ====
//
 INT n,n1,n2,m, // n1,n2 - ������ ����������� ����� ������� ���
     maxM=-1e10,minM=-maxM, // max ������, min ������
     n1x,n2x, n1n,n2n; //  ��������� ������ ���� � ����
 REAL averTLD=0.0; // ������-�������������� ������� ����� ������ ����� ������� ��� (���)
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( !PutParamsDataLiveOnTextFrame ) // ����� ���������� ������� ����� ������
  goto calc_data_live; // ...�� ������� ���� ������ ���� ��������! -------------
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 c_CreateAndOutputDataLiveDiagrByTiers( 2, "" ); // ������� ��������� ������� ����� ������ �� �����. Tiers[][]
//
 sscanf( TLD->Strings[0].c_str(), "%d", &n ); // ����� ����������� ������ � ���
//
 for( INT i=1; i<=n; i++) // �� ����� ����������� ����� ������� ���
 {
  if( i < n ) // ����� ��������� ������ � $
   sscanf( TLD->Strings[i].c_str(), "%d/%d|%d:", &n1,&n2,&m ); // ������� ���� / ������ ���� / ����� ������ � ���� ����������
  else // ��������� ������ ������� "n/$|m"
  {
   sscanf( TLD->Strings[i].c_str(), "%d/$|%d:",  &n1,&m ); // ������� ���� / $ / ����� ������ � ���� ����������
   n2=n1+1;
  }
//
  if( m >= maxM ) // ���� ��� ����� TLD
  { maxM = max(maxM,m); n1x=n1; n2x=n2; } // ��������� ���� ���� | ��������� ���� ���� (��������� ������-��...)
//
  if( m < minM ) // ���� �in ����� TLD
  { minM = min(minM,m); n1n=n1; } // ��������� ���� ���� | ��������� ���� ���� (��������� ������-��...)
//
  averTLD += (REAL)m; // ������-�������������� ������� ����� ������
 } // ����� ����� �� ����������� ����� ������� ���
//
// ���������� ������ ����������� � ������� ����� ������
//
 char szStatTLD[_512], // ������ ������ � ������� ����� ��������� ������ (TLD)
      szTemp[_128] ;
//
 if( n2n == n )
  sprintf( szStatTLD,"%sTLD: min=%d(%d/%c), ", Delimeter, minM,n1n,'$' );
 else
  sprintf( szStatTLD,"%sTLD: min=%d(%d/%d), ", Delimeter, minM,n1n,n2n );
//
 if( n2x == n )
  sprintf( szTemp, "max=%d(%d/%c), ��.�����.=%.4g", maxM,n1x,'$',averTLD / n );
 else
  sprintf( szTemp, "max=%d(%d/%d), ��.�����.=%.4g", maxM,n1x,n2x,averTLD / n );
//
 strcat( szStatTLD, szTemp ); // ����������� ������ ��� ������ �� F2
//
// === ����� ��������� ���������� � ������� ����� ������ ����� ������� ��� =====
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
calc_data_live: //�����, ��� ����������� � ���� �������� ������ ----------------
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// --- ����� ������������ ������ �� ����� F2 � L_GP ----------------------------
//
 char szFormat[] = // ������ ������� ��� ������ ������ � ������ szOut ----------
"����������= %d, ���= %d, ������= %d\
%s���: %s\
%s���������� �� �����/���� (min:max)= %d/%d:%d/%d\
%s������������� ���: Vo|Vt|Vot= %.4g|%.4g|%.4g\
%s��.�����.���� ���= %.4g ������\
%s";
//
 snprintf( szOut,sizeof(szOut), szFormat, // ����� �� ������� szFormat � ������ szOut
//
 nOps, nEdges, nTiers,
 Delimeter,
//
 szStatTiers, // ������ ���������� ������ ���
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
 StatTiers.AAL, // �������������������� ����� ����
//
 szStatTLD ); // ������ ���������� ������� ����� ��������� ������ (TLD)
//
 F2->L_GP->Caption = szOut; // ����� �������� ���������� ��� �����
 F2->L_GP->Repaint(); // ������������� ��������������
//
//
 strcpy( szStatTLD, "\n" );
 strcat( szStatTLD, szTemp ); // ����������� ������ ��� ������ � ���� ���������
//
 if( !PutParamsDataLiveOnTextFrame ) // ����� ���������� ������� ����� ������
  strcpy( szStatTLD, "\0" );
//
// ===== ����� ������������ ������ � �������� ������� (����) ===================
//
////////////////////////////////////////////////////////////////////////////////
 ReplaceEqualLengthSubstring( szOut, Delimeter, "  \n" ) ; // �������� Delimeter �� "^^\n"
////////////////////////////////////////////////////////////////////////////////
//
 if( PutParamsTiersOnTextFrame ) // ���� ������ �������� ������ ������� ������ (������� � INI-�����)
  t_printf( szOut ); // ����� � ��������� ���� ���� �� ������, ��� � ������ ����� ���������� ���� ������
//
 p_printf( "\n" ); // ����� � ����� - ������ ������ !!!
 p_printf( szOut ); // ��������� ���� ���������
 p_printf( "\n\n" );
//
 snprintf(szOut,sizeof(szOut), "H|N/W=%d|%d/%d", nTiers,c_GetTierFirstMaxOps(1,nTiers),
                                Tiers(c_GetTierFirstMaxOps(1,nTiers),0) );
 F2->L_OM->Caption = szOut; // ����� ��������� ���������� �� ����� �� ����� ���
 F2->L_OM->Repaint(); // ������������� ��������������
//
 return TRUE ;
//
} // ----- ����� c_PutParamsTiers ----------------------------------------------










