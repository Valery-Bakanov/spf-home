//
//#define TEST_PRINT
//
// circle \225 \x0095; ����� \207 \x0087; ����.��� \174 \x007c; ������.����.����� \246 \x00A6
#define SS_01 " \246 " // ������-����������� ������ ��� ������ � �_PutParamsTiers() // Special Sequence ������� ������������
#define SS_02 "$" // ������-������ ���������� ����� ���� � ������������ �������
#define _OUT "\xBB" // ������-������ "\xBB" = ">>" ||| ������� ����, ��� � ��������� ��� ��������� ��� (��� �������� ������)
#define _IN  "\xAB" // ������-������ "\xAB" = "<<" ||| ������� ����, ��� � ��������� ��� ��������  ��� (��� �������� ������)
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
//#define strcat(dest,src) strncat(dest,src,sizeof(dest)-strlen(dest)-5) // ���������� ���������� src � dest
//
#define strEndZero(str) str[strlen(str)]='\0' // ���������� '\0' � ����� ������ str
//
#define strNcpy(dest,source)  strncpy(dest,source,sizeof(dest)) // ���������� ����������� dest <- source
//
////////////////////////////////////////////////////////////////////////////////
// ���� API_func.cpp ===========================================================
////////////////////////////////////////////////////////////////////////////////
// ����� ������� API �� � ���������� � "c_"; Lua-������� ����������� �� �����
////////////////////////////////////////////////////////////////////////////////
//#define TEST_PRINT // ���� ���������� - �������� ������
////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
//
INT  __fastcall c_CalcParamsTLD(); // ��������� (�� �� �������!) ������ ������� ����� ���������� ������ � ���
INT  __fastcall c_PutTLDToTextFrame(); // ������ ��������� ������� ����� ������ � ��������� ����
char* __fastcall c_SaveTLD( char FileName[] ); // ������ ��������� ������� ����� ������ � ����
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
INT  __fastcall c_PutEdgesToTextFrame(); // ����� ������ ��� Mem_Edges[][] � ���� ��� ������������
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
char* __fastcall c_SaveEdges(char FileName[]); // ����� � FileName ��� �������� ����� + Tiers[0/nTiers][*]
bool __fastcall c_ReadTiers(char FileName[]); // ������ �� FileName ��� �����
char* __fastcall c_SaveTiers(char FileName[]); // ����� � FileName ��� �����
//
char* __fastcall c_SaveTiersVizu(char FileName[]); // ���������� ����� ���������� �� ������
char* __fastcall c_SaveEdgesVizu(char FileName[]); // ���������� ����� ������������ (���) ����������
char* __fastcall c_SaveInOutOpVizu(char FileName[]); // ���������� ����� �������� � ��������� ��� ��� ��������� Op
char* __fastcall c_SaveParamsVizu(char FileName[]); // ��������� ����� - �������� GetParamsGraph()
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
bool  __fastcall c_IsCorrectParamCalc(char* str); // true ��� ������������ ������������� ��������� �����������
bool  __fastcall c_IsCorrectParamOpVertEdg(char* str); // true ��� ������������ ������������� ��������� ���������
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
INT   __fastcall c_PutParamsTiers(); // ����� �������� ���������� ��� � ��� � ������ ����� ���������� ������ (F2)
//
bool  __fastcall c_IsOpContainOnTiers(INT Op); // ���� �������� Op ������������ � Tiers[][], ����������� true, ����� - false
INT   __fastcall c_GetOpByMaxTierLowerPreset(INT Op); // ����� ��������, ������������� ��������� �� ��������� � ����������� �� �����
// � ������������ ������� (���� ����� �������� ��������� - ������� ��������� �� ������)
//
INT   __fastcall c_WinExec( char *cmdLine, INT cmdShow ); // ��������� WinExec
INT   __fastcall c_ShellExecute( char *Operation, char *File, char *Parameters, char *Directory, INT cmdShow ); // ��������� ShellExecute
//
INT   __fastcall c_CreateProsess(char* CommandLine, byte RuleParent, byte Priority, bool RuleMessage); // ������ ��������-�������
//==============================================================================
bool __fastcall TestAndAddMemoryForEdges( INT nEdges ); // ������� ���������� ������ ��� Mem_Edges[][]
bool __fastcall ParseStringAndAddEdges( char *str ); // ������ str � ��������� ���� � ����� ������ ���
bool __fastcall ReadAndPrimWorkOpsCalcsVertEdgeFiles( char FileName[] ); // ������ � �����.��������� ������ ��������
INT  __fastcall c_LuaCallByTimer( char *CommandLine, INT d_Ticks ); // ����� Lua-������ � ��������� d_Ticks
void __fastcall CallLuaThread( char *CommandLine ); // ����� CommandLine �� ����� ��������� ������ Lua
char* __fastcall ReformFileName( char Filename[], char Ext[] ); // ������ ������� ������������� ��� �����
INT  __fastcall c_CalcParamsTiers(); // ������ ���������� ������ ���
//
void __fastcall tuneFlagsAll( bool FLAG, INT FromTo ); // ������������� FLAG � ���������� ������� ��� From/To=0/1 ������ Edges[][]
void __fastcall tuneFlagsIfEqual( bool FLAG, INT FromTo, INT Value ); // ������������� FLAG � Value � ���������� ������� ��� From/To=0/1 ������ Edges[][]
void __fastcall clearFlagsDuplicateOps( INT FromTo, INT Op ); // ������������� � false ��� ����� ����������-������ Op � ������� ��� From/To=0/1 ������ Edges[][]
//
char* __fastcall CreateUniqueFileName(char* FileName); // �������� ����������� ����� ����� ��� ������������� ����� � ������, �������� FileName
//
void __fastcall OutRepeatComplete(char* s_Before, INT i, INT n, INT di, REAL Value, char* Fmt, char* s_After);
//
INT  __fastcall c_CountOfMemoryLuaUse(); // ���������� ����, ������������ Lua
INT  __fastcall c_CountOfFreeMemory(); // ��������� � ����� �������� ���������� ������
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall cmp_def( char *s )
{ // ���������� ������� 5 ������ �������� s � sDef; ���������� true, ���� ��� ��� �����
 return( toupper(s[0])==toupper(sDef[0]) &&
         toupper(s[1])==toupper(sDef[1]) &&
         toupper(s[2])==toupper(sDef[2]) &&
         toupper(s[3])==toupper(sDef[3]) &&
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
char* __fastcall c_SaveTiersVizu(char FileName[])
{ // ����� ����� �������� �� ������
 char str[_16384], tmp[_256];
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 if( !flagExistsTiers ) // ������� Tiers[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // ������� ����� ��� ������
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,Format("%s%s",OPENARRAY(TVarRec,(extTiers,extVizu))).c_str() ) ); // ��������������� ��� �����
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // ���� MewFileName ��� ����������...
//
 if(!(fptr = fopen( NewFileName,"w" ))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� �������� ���� %s ���������� ��� -E-\n\n-W- ��������� �������������� ������ �� �������� �������� ������ -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // ������� ����� ��� ������
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
    snprintf(tmp,sizeof(tmp), " " _IN "%d",  Tiers(iTier,j)); // ��� �������� �������� (��������� ���������)
   else
   if( !c_GetCountOutEdgesByOp( Tiers(iTier,j) )) // � ����� ��������� ��� ��������� ���...
    snprintf(tmp,sizeof(tmp), " %d" _OUT , Tiers(iTier,j)); // ��� �������� �������� (��������� ���������)
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
 return NewFileName ;
//
} // --- ����� SaveTiersVizu ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_SaveEdgesVizu(char FileName[])
{ // ����� ������ ����� �����������
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 if( !flagExistsEdges ) // ������� Mem_Edges[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // ������� ����� ��� ������
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,Format("%s%s",OPENARRAY(TVarRec,(extGv,extVizu))).c_str() ) ); // ��������������� ��� �����
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // ���� MewFileName ��� ����������...
//
 if(!(fptr = fopen( NewFileName,"w" ))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� �������� ���� %s ���������� ��� -E-\n\n-W- ��������� �������������� ������ �� �������� �������� ������ -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // ������� ����� ��� ������
 }
//
// setbuf( fptr, NULL ); // ��������� ������������ ��� ������
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ������� ���
  fprintf(fptr, "#Edge= %d %d -> %d\n", iEdge, Edges(0,iEdge),Edges(1,iEdge)); // ���� ����� i
//
 fclose(fptr); // ������� ����
//
 return NewFileName ;
//
} // --- ����� SaveEdgesVizu ---------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_SaveInOutOpVizu(char FileName[])
{ // ����� ����� �������� � ��������� ��� ��� ����������
 char str[_16384], tmp[_256], s1[]="* \0";
 INT jOpOnTier, iOp, j, nIn,nOut;
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 if( !flagExistsEdges ) // ������� Mem_Edges[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // ������� ����� ��� ������
 }
//
 if( !flagExistsTiers ) // ������� Tiers[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // ������� ����� ��� ������
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,Format("%s%s",OPENARRAY(TVarRec,(extIno,extVizu))).c_str() ) ); // ��������������� ��� �����
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // ���� MewFileName ��� ����������... 
//
 if(!(fptr = fopen( NewFileName,"w" ))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� �������� ���� %s �������� � ��������� ��� �� ���������� -E-\n\n-W- ��������� �������������� ������ �� �������� �������� ������ -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // ������� ����� ��� ������
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
 return NewFileName ;
//
} // --- ����� SaveInOutOpVizu -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_SaveParamsVizu(char FileName[])
{ // ����� ����� �������� � ��������� ��� ����������
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 if( !flagExistsEdges ) // ������� Mem_Edges[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // ������� ����� ��� ������
 }
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,Format("%s%s",OPENARRAY(TVarRec,(extPrm,extVizu))).c_str() ) ); // ��������������� ��� �����
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // ���� MewFileName ��� ����������...
//
 if(!(fptr = fopen( NewFileName,"w" ))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� ��������� ���� %s ����� �������� � ��������� ��� �� ���������� -E-\n-W- ��������� �������������� ������ �� �������� �������� ������ -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // ������� ����� ��� ������
 }
//
// setbuf( fptr, NULL ); // ��������� ������������ ��� ������
//
 GetParamsGraph(); // ����� ��������� ����� ----------------------------------
//
 fprintf(fptr, "#nOpMinIn=%10d #nEdgesMinIn=%10d\n#nOpMaxIn=%10d #nEdgesMaxIn=%10d\n#nOpMinOut=%9d #nEdgesMinOut=%9d\n#nOpMaxOut=%9d #nEdgesMaxOut=%9d\nAveIn=%14.3f AveOut=%16.3f",
               PG.nOpMinIn,  PG.nEdgesMinIn,
               PG.nOpMaxIn,  PG.nEdgesMaxIn,
               PG.nOpMinOut, PG.nEdgesMinOut,
               PG.nOpMaxOut, PG.nEdgesMaxOut,
               PG.AveIn,     PG.AveOut);
//
 fclose(fptr); // ������� ����
//
 return NewFileName ;
//
} // --- ����� SaveParamsVizu -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_SaveTiers(char FileName[])
{  // ����� ���������� �� ������ ��� ������� �������� ����� � ���� ���
 char str[_16384], tmp[_256];
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 if( !flagExistsTiers ) // ������� Tiers[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // ������� ����� ��� ������
 }
//
 char NewFileName[_512];
 strcpy( NewFileName, ReformFileName(FileName,extTiers) ); // ��������������� ��� ������
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // ���� MewFileName ��� ����������...
//
 if(!(fptr = fopen( NewFileName, "w" ))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� �������� ���� %s ������� �������� ��� � ��� -E-\n\n-W- ��������� �������������� ������ �� �������� �������� ������ -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // ������� ����� ��� ������
 }
//
// setbuf( fptr, NULL ); // ��������� ������������ ��� ������
//
////////////////////////////////////////////////////////////////////////////////
// ���������� �������� ����� ���������� �� ����� � ����� ����� ����� (������� �������)
//
 INT MaxOpsOnTier = -1, TierWithMaxOps = -1; // ��������� ��������
//
 for(INT iTiers=0; iTiers<nTiers; iTiers++) // �� ������ ��� �����
  if( Tiers(iTiers,0) > MaxOpsOnTier ) // ���� ������...
  {
   MaxOpsOnTier   = Tiers(iTiers,0);
   TierWithMaxOps = iTiers;
  }
//
////////////////////////////////////////////////////////////////////////////////
//
 fprintf(fptr, "%d %d %d\n", nTiers+1, MaxOpsOnTier, TierWithMaxOps); // ����� ������ ������
 for(INT iTiers=0; iTiers<=nTiers; iTiers++) // �� ������ ��� �����
 {
  strNcpy(str, ""); // �������� ������ ����� �����������
//
  for(INT j=0; j<=Tiers(iTiers,0); j++) // �� ������� ���������� �� ����� iTiers
  {
   snprintf( tmp,sizeof(tmp), "%d ", Tiers(iTiers,j) ); // �� ��������� ������ ������ iTiers
   strcat(str, tmp); // ��������� ��� ������������ ������
  } // ����� ����� �� j
//
  fprintf(fptr, "%s\n", str); // ������ � ���� ������� ������
//
 } // ����� ����� �� iTiers
//
 fclose(fptr); // ������� ����
//
 return NewFileName ; // ������ �������������� ��� �����
//
} // --- ����� SaveTiers -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ReadTiers(char FileName[])
{  // ������ ���������� �� ������ ��� ������� �������� ����� � ���� ���
 char str[_16384], *p;
 INT nTiersAll; // ����� ������ � ��� (������� �������)
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 INT MaxOpsOnTier, // ��� ����� ���������� �� ����� ������ ��� ����� (������� �������)
     TierWithMaxOps; // �� ����� (������) ����� ���� ��� ����������� (������� �������)
//
 char NewFileName[_512];
 strcpy( NewFileName, ReformFileName(FileName,extTiers) ); // ��������������� ��� ������
//
 if(!(fptr = fopen(NewFileName, "r"))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� ��������� ���� %s ���������� ��� -E-\n-W- �������� �������������� ��� ���������� ������ -W-",
                   NewFileName );
  flagExistsTiers = false;
  return false ;
 }
//
 fgets(str, sizeof(str), fptr); // ��������� ������ ������ �����
// ����� ������ (����������), max ���������� �� �����, �� ����� ����� ���� max (������� �������)
 if( sscanf(str, "%d %d %d", &nTiersAll, &MaxOpsOnTier, &TierWithMaxOps) != 3 ) // ������...
 {
  flagExistsTiers = false;
  return false ;
 }
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 _maxTiers = nTiersAll; // ����� ������ (� ������ �������� �����)
 _maxOpsOnTier = MaxOpsOnTier+1; // �������� ����� ���������� �� ������
 pTiers = (INT*) realloc( pTiers, _maxTiers * _maxOpsOnTier * stockMem * sizeof(INT) ); // �������������� ������ ��� Tiers[][] � ������� � stockMem ���
//
 if( !pTiers ) // ������ ����� - ������ � "����" �����������
 {
  snprintf(str,sizeof(str), "�������� ������ ��� ���������� ������� ������ (4). ����������� %d x %d = %d ���������...",
                (_maxTiers+1), (_maxOpsOnTier+1), (_maxTiers+1) * (_maxOpsOnTier+1));
  MessageBox(0, str, "��������������", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  flagExistsTiers = false ; // ������ Tiers[][] �� ������...
  return false ;
 }
//
  t_printf( "\n-I- ������ ������ (4) �������������� �� %d x %d = %d ��������� -I-",
                   (_maxTiers+1), (_maxOpsOnTier+1), (_maxTiers+1) * (_maxOpsOnTier+1) );
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 nTiers = nTiersAll-1; // nTiers - ����� ������ ��� �������� �����
//
 for( INT iTier=0; iTier<=nTiers; iTier++ ) // �� ������ ��� �����
 {
  fgets(str, sizeof(str), fptr); // ��������� ��������� ������ �����
//
  INT j = 0; // ������ ����� � ������ str
//
  p = strtok( str, " " ); // ����� �� ������ str, �������������� �� ��������...
  if( p )
   sscanf( p, "%d", &Tiers(iTier,j++) ); // ����� ����� 0 = ����� ���������� �� �����
//
  while( p ) // ���� p = true
  {
   p = strtok( NULL, " "); // �� ���������� �������..
   if( p )
    sscanf( p, "%d", &Tiers(iTier,j++) ); // ��������� ����� ����� =>1
  } // ����� while
//
 } // ����� ����� �� iTiers
//
 fclose(fptr); // ������� ����
//
 flagExistsTiers = true ; // all O'k...
//
 t_printf( "\n-I- ��� ����� �� ����� %s ������� ��������� -I-", NewFileName );
//
 flagCalcTLD = false ; // paramsTLD �� ������������� Tiers[][]
//
 return true ;
//
} // --- ����� �_ReadTiers -----------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_IsOpsHaveEdge(INT Op1, INT Op2)
{ // true - ���� ������������ ���� ����� ����������� Op1 -> Op2
 if( !flagExistsEdges ) // ������ Mem_Edges[][] ��� �� ���������� - ������� � false
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(INT iEdge=1; iEdge<=nEdges; iEdge++) // �� ������ ������ ��� ����� �����������
  if ( (Op1 == Edges(0,iEdge)) && (Op2 == Edges(1,iEdge)) ) // ����� ���� � ������ �������...
   return ( true );
//
 return ( false );
//
} // --- ����� c_IsOpsHaveEdge -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierByOp(INT Op)
{ // --- ������� ����� ����� ��� ��������� Op ----------------------------------
 if( !flagExistsTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }

 for(INT iTier=0; iTier<=nTiers; iTier++) // �� ���� ������
  if( c_IsOpExistOnTier( Op, iTier ) == true ) // �������� Op ����� ����� �������������� �� ����� iTier
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

 if( !flagExistsEdges && !flagExistsTiers ) // ��� �������� Mem_Edges[][] � Tiers[][]
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
//
   PG.AveOut += nEdgesOutOp ; // ����� ����� ��� Out ��� ��������� Op
//
   if(nEdgesOutOp < PG.nEdgesMinOut) // ���� MIN ���������...
   {
    PG.nEdgesMinOut = nEdgesOutOp;
    PG.nOpMinOut    = Op; // ��������� ��������������� Op
   }
//
   if(nEdgesOutOp > PG.nEdgesMaxOut) // ���� NAX ���������...
   {
    PG.nEdgesMaxOut = nEdgesOutOp;
    PG.nOpMaxOut    = Op; // ��������� ��������������� Op
   }
//
  } // ����� ����� �� j
//
////////////////////////////////////////////////////////////////////////////////
//
 PG.AveIn  /= nOps - Tiers(1,0); // ������� ����� ���, �������� ( to ) � ��������� �����
 PG.AveOut /= nOps - Tiers(nTiers,0); // ������� ����� ���, ��������� ( from ) �� ���������� �����
//
 return true ;
//
} // --- ����� GetParamsGraph --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetOpByMinInOnTiers(INT minTier, INT maxTier)
{ // --- ������� ����� ��������� � MIN ������ �� ������ � minTier �� maxTier
 INT nEdgesInOp = nEdges,  // ������ ���� �� �����
     iOp,iOpMinIn, sumEdgesIn;
//
 if( !flagExistsTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
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
//
 if( !flagExistsTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 for(INT j=minTier; j<=maxTier; j++) // �� ���� ������ � minTier �� maxTier
 for(INT iOpOnTier=1; iOpOnTier<=Tiers(j,0); iOpOnTier++) // �� ���� ���� ���������� ����� Tier
 {
  iOp = Tiers(j,iOpOnTier); // ����� ����� iOpOnToer �� ����� ��������� �� ����� j
//
  sumEdgesOut = 0; // ��������� � ���������� sumEdgesIn
  for(INT iEdge = 0; iEdge < nEdges; iEdge ++ ) // �� ���� ����� ����� ========
   if( Edges(0,iEdge) == iOp ) // ����� ����, ��������� �� ��������� iOp
    sumEdgesOut ++ ; // ��������� ����� ���, ��������� �� �������� iOp...
//
  if(sumEdgesOut < nEdgesOutOp) // MIN ������� �� ���� ����. ������ minTier-maxTier
  {
   nEdgesOutOp = sumEdgesOut;
   iOpMinOut = iOp; // ��������� ����� ���������
  }
//
 } // ����� ����� �� i
   // ����� ����� �� j
//
 return iOpMinOut; // �������� � MIN ������� �� ������ minTier-maxTier
//
} // --- ����� GetOpByOutMinOnTiers --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall AddEdge(INT fromOp, INT toOp)
{ // --- ���������� ���� � ���������, ���� �� ��� ����� � Mem_Edges[][] ----------
 char str[_256];

 if( !flagExistsEdges ) // ��� ������� Mem_Edges[][]...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }

//////////////////////c/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//////////////////////c/////////////////////////////////////////////////////////

 if( ( nEdges+3 ) < Max_Edges ) // ������� ������� Mem_Edges[][] ��� �������!..
  goto cont;
//
 Max_Edges *= stockMem; // ��������� � stockMem ���
 Mem_Edges = (me*) realloc( Mem_Edges, Max_Edges * sizeof(INT) ); // �������������� ������ ��� Mem_Edges[][]...
//
 if( !Mem_Edges ) // ������ ����� - ������ � "����" �����������
 {
  snprintf(str,sizeof(str), "�������� ������ ��� ���������� ������� ��� (00). ����������� %d ���������...",
                             Max_Edges );
  MessageBox(0, str, "��������������", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  MessageBeep(MB_OK); // �������� ��������������...
  flagExistsEdges = false ; // ������ Mem_Edges[][] �� ������...
  return false ;
 }
//
 t_printf( "\n-I- ������ ��� (00) �������������� �� %d x %d = %d ��������� -I-",
                  Max_Edges );
//
 cont: // �� ���� ������������� ������������ ������ ��� Mem_Edges[][]
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
 return true; // ���� ������� ���������
//
} // --- ����� AddEdge ---------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall GetFirstToOpFromOp(INT fromOp)
{ // --- ������� ������ �� ����� �������� toOp, ���������� ���������
// --- �� ���� ����� ������������ fromOp
//
 if( !flagExistsEdges ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
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
 if( !flagExistsEdges ) // ������ Mem_Edges[][] ��� �� ���������� - ������� � �������
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
 if( !flagExistsTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier1 < 1 ) || ( Tier1 > nTiers ) || // "���"
     ( Tier2 < 1 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 if( Tier2 < Tier1 ) // ������� �������� Tier1 - Tier2
 {
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
//
 if( !flagExistsTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
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
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // �� �������� ������ ��� ---------
  if ( Tiers(iTier,0) >= TierMaxOp ) // ���� MAX...
  {
   TierMaxOp = Tiers(iTier,0); // ����� ���������� �� ����� iTier
   Tier = iTier; // ��������� iTier � ������� ���������� ����������
  }
//
 return Tier ;
//
} // --- �����  c_GetTierLastMaxOps --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierFirstMinOps(INT Tier1, INT Tier2)
{ // ���������� ������ #����� � MIN �� ��������� ������ (Tier1-Tier2) ������ ����������
// - ���� ����������� (����������) ��������� - ������������ ������ �� ��� (c Tier = min)
 INT TierMinOp = _maxOpsOnTier , // ��� ������ MIN
     Tier;
//
 if( !flagExistsTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier1 < 1 ) || ( Tier1 > nTiers ) ||
     ( Tier2 < 1 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1,  ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 if( Tier2 < Tier1 ) // ������� �������� Tier1 - Tier2
 {
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // �� ���� ������ ��� ------------
  if ( Tiers(iTier,0) < TierMinOp ) // ���� MIN...
  {
   TierMinOp = Tiers(iTier,0); //  ����� ���������� �� ����� iTier
   Tier = iTier; // ��������� iTier � ������� ��������� ����������
  }
//
 return Tier ;
//
} // --- �����  c_GetTierFirstMinOps -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetTierLastMinOps(INT Tier1, INT Tier2)
{ // ���������� ��������� #����� � MIN �� ��������� ������ (Tier1-Tier2) ������ ����������
// - ���� ����������� (����������) ��������� - ������������ ���������� �� ��� (c Tier = max)
 INT TierMinOp = _maxOpsOnTier , // ��� ������ MIN
     Tier;
//
 if( !flagExistsTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier1 < 0 ) || ( Tier1 > nTiers ) ||
     ( Tier2 < 0 ) || ( Tier2 > nTiers ) )
 {
  DisplayMessage( "E", __FUNC__, messParams1, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 if( Tier2 < Tier1 ) // ������� �������� Tier1 - Tier2
 {
  DisplayMessage( "E", __FUNC__, messParams2, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 for(INT iTier=Tier1; iTier<=Tier2; iTier++) // �� ���� ������ ��� ------------
  if ( Tiers(iTier,0) <= TierMinOp ) // ���� MIN...
  {
   TierMinOp = Tiers(iTier,0); //  ����� ���������� �� ����� iTier
   Tier = iTier; // ��������� iTier � ������� ��������� ����������
  }
//
 return Tier ;
//
} // --- �����  c_GetTierLastMinOps --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsOpExistOnTier(INT Op, INT Tier)
{ // ���������� true ������ ���� �������� Op ������������ �� ����� Tier

 for(INT jOpOnTier=1; jOpOnTier<=Tiers(Tier,0); jOpOnTier++) // �� ���� ���������� ����� Tier
  if( Tiers(Tier,jOpOnTier) == Op ) // ����� ������� �������� Op !..
   return true;

 return false;

} // --- �����  c_IsOpExistOnTier ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsOpDependOnlyAboveTiers(INT toOp, INT Tier)
{ // true - ������ ���� �������� toOp ������� (�� ���� ���� In-�����)
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
    if ( c_IsOpExistOnTier( fromOp, iTier ) == true ) // �������� fromOp ������������ �� ����� iTier...
     sumIn ++ ; // ��������� ����� ��������� fromOp �� ������ � 0 �� Tier-1
  } // ����� if ( Mem_Edges[1][iEdge] == toOp )
//
 } // ����� ����� �� iEdge
//
 if( sumIn == c_GetCountInEdgesByOp(toOp) ) // ��������� ������� In, ������� ���� � ��������� toOp ?
  return true; // ����� ��� �������� � toOp �������� ���� ��������� �� ������ �� 0 �� Tier-1
 else
  return false;
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
 if( !flagExistsEdges ) // ������ Mem_Edges[][] ��� �� ���������� - ������� � �������
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
 if( !flagExistsEdges ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
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
 if( !flagExistsTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
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
 if( !flagExistsEdges ) // ������ Mem_Edges[][] ��� �� ���������� - ������� � �������
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
{ // ��������� �������� Op �� ���� toTier � ��������� ������������ ��������
// �� ���� ��������������� ���������� Op �� toTier �� ����� ���� ������� ������ ��� ���������
// ���� ������� ������������ ��������� - ������������ true � ���������� nMoves ���������������� �� 1
// ������� ����������� �� ���� ������������ ��������� Op ������� �� ��������� ..!
// ���� �� ��������� - ������������ 0
//
 if( !flagExistsTiers ) // ���� ������� Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 INT fromTier = c_GetTierByOp( Op ); // ���� ��������������� ���������� ��������� Op
//
// t_printf( "- Op= #%d fromTier= %d toTier= %d =", Op,fromTier,toTier );
 if( fromTier == toTier ) // ��������� ������� ������ ��� ..!
  return RETURN_OK ;
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
  if( IncreaseOpsOnTier( toTier, _maxOpsOnTier * stockMem, 111 ) == false ) // ������� ����������������� ������
  {
   flagExistsTiers = false ; // ������ Tiers[][] �� ������...
   return ERR_NOT_MEMORY ;
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
   flagCalcTLD = false ; // paramsTLD �� ������������� Tiers[][]
//
   return RETURN_OK ;
//
  } // ����� if
//
} // --- ����� c_MoveOpTierToTier ------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_AddTier(INT Tier)
{ // --- ������ (������) ���� ���� ����� Tier (����� ����������)
// ----- ����� �� ��������; ���������� true, ���� ������
 char str[_2048];
//
 if( !flagExistsTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( ( Tier <  1 ) ||  // ����� ������...  � �� ��������� ����� !
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
    flagExistsTiers = false ; // ������ Tiers[][] �� ������...
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
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 nTiers ++ ; // ��������� ����� ������ �� 1
//
// --- �������� ����� � Tier �� nTiers-1 ���� ----------------------------------
 for(INT iTier=nTiers; iTier>Tier; iTier--) // �� ������ ����� �����
  for(INT j=0; j<=Tiers(iTier-1,0); j++) // ���� �� "��������" �� ����
   Tiers(iTier,j) = Tiers(iTier-1,j); // "�������" ��������� � "������"
//
 Tiers( Tier+1,0 ) = 0; // ����� ��������� ���� ���� !
//
 flagCalcTLD = false ; // paramsTLD �� ������������� Tiers[][]
//
 return RETURN_OK ; // ������� ���������
//
} // --- ����� c_AddTier -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_DelTier(INT Tier)
{ // --- ���������� (������) ���� Tier (����� ��������)
// ----- ����� �� ��������; ���������� true, ���� ������
//
 if( !flagExistsTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
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
//
 nTiers -- ; // ������ ����� �� 1 ������...
//
 flagCalcTLD = false ; // paramsTLD �� ������������� Tiers[][]
//
 return true ; // ������� ���������
//
} // --- ����� c_DelTier -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountEdges()
{ // ���������� ����� ����� ��� � �������������� ����� ��������� (���)
//
 if( !flagExistsEdges ) // ��� ������� Mem_Edges[][]
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
 if( !flagExistsTiers ) // ��� ������� Tiers[][]
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
 INT old_nMoves = nMoves ; // ��������� "������" ��������
 nMoves = 0 ; // �������� ������� ����� �����������
 return old_nMoves ; // ������� "������" �������� ��������
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
  }
//
 } // ����� �� �������� ������ str
//
 return true ; // ��� Lua ������ ���� ���-�� ���������� (void �� �����������!)
//
} // --- ����� c_AddLineToTextFrame --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ClearTextFrame()
{ // ������� ����  ���������� �������������
 TM1->Clear(); // ������� M1
 return true ; // ��� Lua ������ ���� ���-�� ���������� (void �� �����������!)
} // --- ����� ClearTextFrame --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_DelayMS(INT Sec)
{ // ��� Sec ������, ����� ��� ���� ���������� Windows
 Delay ( Sec ); // ����� Sec ������
 return true ; // ��� Lua ������ ���� ���-�� ���������� (void �� �����������!)
} // --- ����� c_DelayMS -------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutTiersToTextFrame()
{ // ����� ��� (������ Tiers[][]) � ���� ��� ��������� ������������
 char str[_16384], tmp[_512];
//
 if( !flagExistsTiers ) // ������ Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 t_printf( "\n-=- ������ ��� = %d -=-", nTiers ); // ������ � ������ ������ (��� ��������)
//
// --- ������� � M1 ������ ���������� �� ������ --------------------------------
 for(INT iTier=0; iTier<=nTiers; iTier++) // �� ���� ���������� ������ ��� (��� ��������)
 {
  snprintf(str,sizeof(str), "%d|%d: ", iTier,Tiers(iTier,0)); // ������� ������ (iTier ����) ��� ������ � M1
//
  for(INT j=1; j<=Tiers(iTier,0); j++) // �� ������� ���������� �� ����� iTier
  {
   if( !c_GetCountInEdgesByOp( Tiers(iTier,j) )) // � ����� ��������� ��� �������� ���...
    snprintf(tmp,sizeof(tmp), " " _IN "%d", Tiers(iTier,j)); // ��� �������� �������� (��������� ���������)
   else
   if( !c_GetCountOutEdgesByOp( Tiers(iTier,j) )) // � ����� ��������� ��� ��������� ���...
    snprintf(tmp,sizeof(tmp), " %d" _OUT , Tiers(iTier,j)); // ��� �������� �������� (��������� ���������)
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
 return true ; // �� ������� �������
//
} // --- ����� c_PutTiersToTextFrame -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutEdgesToTextFrame()
{ // ����� ������ ��� Mem_Edges[][] � ���� ��� ������������
 char str[_2048];
//
 if( !flagExistsEdges ) // ���� ������ Edges[][] ���� - ����� � ������� false
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
 return true; // �� ��������� - ������ Mem_Edges[][] ����� � ��������� ����
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
 bool Err = false; // ������������ ��������
//
 if( !flagExistsTiers ) // ��� ������� Tiers[][]
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
    Err = true ;
   }
//
// --- ���� �� ������� ��������� ��� -------------------------------------------
   if( !c_GetCountOutEdgesByOp( Op ) && ( iTier != nTiers ) ) // �� �� ��������� ����� "�" ��������� ��� ���
   {
    t_printf( "\n-W- �������� %d �� �� ��������� ����� %d �� ����� ��������� ��� -W-", Op, iTier );
    Err = true ;
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
 if( !flagExistsEdges ) // ������ Mem_Edges[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
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
 if( !flagExistsEdges ) // ������ Mem_Edges[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
////////////////////////////////////////////////////////////////////////////////
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
 if( !flagExistsEdges ) // ������ Mem_Edges[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
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
 if( !flagExistsEdges ) // ������ Mem_Edges[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
////////////////////////////////////////////////////////////////////////////////
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
 return ERR_COMMON ; // ���� �� ����� �� ����� ����...
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
  return true;
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
  return true;
//
 } // �� ��������� � ������ � ������ �� ���������... �������� ������ !
//
////////////////////////////////////////////////////////////////////////////////
// --- �� ������� ������� �� �������� ����, �� ���� � ������ �� ��������� ------
 strNcpy( sCalcs, "\0" ); // ������� ������-������ ���������� ������������
 return false; // �������� � ������...
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
  return true;
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
  return true;
//
 } // �� ��������� � ������ � ������ �� ���������... �������� ������ !
//
////////////////////////////////////////////////////////////////////////////////
// --- �� ������� ������� �� �������� ����, �� ���� � ������ �� ��������� ------
 strNcpy( sOps, "\0" ); // ������� ������-������ ���������� ����������

 return false; // �������� � ������...

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
  return true;
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
  return true;
//
 } // �� ��������� � ������ � ������ �� ���������... �������� ������ !
//
////////////////////////////////////////////////////////////////////////////////
// --- �� ������� ������� �� �������� ����, �� ���� � ������ �� ��������� ------
 strNcpy( sEdg, "" ); // ������� ������-������ ���������� ���
 return false; // �������� � ������...
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
  return true;
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
  return true;
//
 } // �� ��������� � ������ � ������ �� ���������... �������� ������ !
//
////////////////////////////////////////////////////////////////////////////////
// --- �� ������� ������� �� �������� ����, �� ���� � ������ �� ��������� ------
 strNcpy( sVrt, "\0" ); // ������� ������-������ ���������� ������
 return false; // �������� � ������...
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
{ // ���� ��������� ���������� ����������� ���������, ������������ true
 bool out = false;
 char sName[_128]; // ��� ��������� (��� '-' � ������)
 REAL minVal, maxVal; // ��������� �������� ����������
//
 if( sscanf( str, "-%s %g %g", sName, &minVal, &maxVal ) == 3 ) // ���� Ok - 3 ������������ ����������
 {
  snprintf( str,sizeof(str), "-%s %g %g", sName, min(minVal,maxVal), max(minVal,maxVal) ); // ����������� str �� ������������
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
} // --- ����� c_IsCorrectParamCalc --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_IsCorrectParamOpVertEdg(char* str)
{ // ���� ��������� ���������� ��������� ���������, ������������ true
 bool out = false;
 char sName[_128]; // ��� ��������� (��� '-' � ������)
 REAL Val; // ��������� �������� ���������
//
 if( sscanf( str, "-%s %g", sName, &Val ) == 2 ) // ���� Ok - 2 ������������ ����������
 {
  snprintf( str,sizeof(str), "-%s %g", sName, Val ); // ����������� str �� ������������
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
   return false;
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
 return true;
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
   return false;
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
 return true;
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
   return false;
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
 return true;
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
   return false;
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
 return true;
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
//
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
//
 strNcpy( sDst, "\0" ); // ������� sDst
//
 for( i=iStart; i<=lenSrc; i++ ) // ����� �� ������ sSrc ������� i - ���� ������ ��������� �������
//
  if( ( ( Rule==0 && sSrc[i]=='=' ) && // Rule=0 � ������ ������ '=' (�������� ������������������)
        ( isdigit(sSrc[i+1]) || toupper(sSrc[i+1]=='D') ) // [�����] ��� [D(d)]
      || // ��� ��� Rule != 0
        ( Rule!=0 && sSrc[i]=='-' ) && // Rule!=1 � ������ ������ '-'
          isalpha(sSrc[i+1]) ) ) // ������ [���.�����]
//
  for( j=i+1; j<=lenSrc; j++ ) // ����� �� ������ sSrc �� ������� j - ���� ��������� ��������� �������
//
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
//
 t_printf( "\n-I- ��������� ������������ � ����������, ������� ��� � ������ -I-" ); // �������������� ���������
//
 if( c_LoadFileNameParamsCalcs( FileNameParamsCalcs ) ) // ���� � ������ �� ������...
 {
  t_printf( "=> �����������: ���� |%s|", FileNameParamsCalcs ); // ��� ����� ���������� ������������
  t_printf( "��������:  |%s|", sWork ); // �������� ������
  t_printf( "���������: |%s|", sCalcs ); // ���������������� ������
 }
//
 if( c_LoadFileNameParamsOps( FileNameParamsOps ) )
 {
  t_printf( "=> ���������: ���� |%s|", FileNameParamsOps ); // ��� ����� ���������� ����������
  t_printf( "��������:  |%s|", sWork ); // �������� ������
  t_printf( "���������: |%s|", sOps ); // ���������������� ������
 }
//
 if( c_LoadFileNameParamsEdges( FileNameParamsEdges ) )
 {
  t_printf( "=> ������� ���: ���� |%s|", FileNameParamsEdges ); // ��� ����� ������ ���
  t_printf( "��������:  |%s|", sWork ); // �������� ������
  t_printf( "���������: |%s|", sEdg ); // ���������������� ������
 }
//
 if( c_LoadFileNameParamsVertices( FileNameParamsVertices ) )
 {
  t_printf( "=> ������� ������: ���� |%s|", FileNameParamsVertices ); // ��� ����� ������ ������
  t_printf( "��������:  |%s|", sWork ); // �������� ������
  t_printf( "���������: |%s|", sVrt ); // ���������������� ������
 }
//
 c_AddLineToTextFrame( "\n" );
//
 return true ;
//
} // --- ����� c_PutParamsAll --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetParamsByOp(INT Op)
{ // ���c��������� ������ sOps � ���������� ��������� ���� ���������� ��������� Op
 char sN[_8192], sName[_128];
 INT  lOps, iStart=0, iEnd, n1, n2;
//
 if( ! (lOps = strlen( sOps ) ) ) // ���� ������ ���������� ������...
  return "\0" ;
//
////////////////////////////////////////////////////////////////////////////////
// --- ������ ������ sN ����� �������� ���� '=n1/n2:'---------------------------

 do // �� ���������� '=n1/n2:' ��� '=Def:'
 {
  iEnd = c_FindSubString( sOps, sN, iStart, 0 );
// --- ������ ��������� ������ sOps ������ ���������� --------------------------
///
//  DelSpacesTabsAround( sN ); // �������� ������� �������
//
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
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lOps ); // ���� �� ����� ������ sOps ( ����� �����. do )
//
////////////////////////////////////////////////////////////////////////////////
// --- ������ ������ sN ����� �������� ���� '=Def:'-----------------------------
//
 iStart = 0;
//
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
//
  if( sscanf( sN, "%s ", sName ) == 1 ) // ���������� ������
   return strchr( sN,':' ) + 2 ; // ������������� ����� ':' � '������'
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lOps ); // ���� �� ����� ������ sOps ( ����� �����. do )
//
////////////////////////////////////////////////////////////////////////////////
//
 return "\0" ; // �� ������� ������ ������ - ��������� (�� ���������)
//
} // --- ����� c_GetParamsByOp -------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_GetParamsByCalc(INT Calc)
{ // ���c��������� ������ sCalcs � ���������� ��������� ���� ���������� ����������� Op
 char sN[_8192], sName[_128];
 INT  lCalcs, iStart=0, iEnd, n1, n2;
//
 if( ! (lCalcs = strlen( sCalcs ) ) ) // ���� ������ ������������ ������...
  return "\0" ;
//
////////////////////////////////////////////////////////////////////////////////
// --- ������ ������ sN ����� �������� ���� '=n1/n2:'---------------------------
//
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
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lCalcs ); // ���� �� ����� ������ sCalcs ( ����� �����. do )

////////////////////////////////////////////////////////////////////////////////
// --- ������ ������ sN ����� �������� ���� '=Def:'-----------------------------
//
 iStart = 0;
//
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
//
  if( sscanf( sN, "%s ", sName ) == 1 ) // ���������� ������
   return strchr( sN,':' ) + 2 ; // ������������� ����� ':' � '������'
//
// --- ����� ��������� ������ sN ���c�� ���������� -----------------------------
  iStart = iEnd;
 } while( iEnd !=lCalcs ); // ���� �� ����� ������ sCalcs ( ����� �����. do )
//
////////////////////////////////////////////////////////////////////////////////
//
 return "\0" ; // �� ������� ������ ������ - ��������� (�� ���������)
//
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
 bool flagPoss = true, // ���� �����������...
      flagNameParam = false; // ���� �� ����������� ����� ����������
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
//    flagNameParam = true; // ������� ���������� �� ����������
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
// ��� Rule==0 ������������ true ��� ������������ � false ��� ��������
// ��� Rule!=0 ������� ������ ����������, ������� ����� ���� ��������� �� ���������� �����������
INT  iOp,Op,Calc, numbCalcsByOp,
     countOps, countCalcs,
     countAll, countOut, countDone=0;
bool canAllExec = true ;
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
 if( countOps <= 0 ) // ��������! ������ ����� ������� Mem_Edges[][] �� ���������� (�������������� ���� �� ��� ��������)
 {
  t_printf( "\n-W- ����� ���������� �� ����������. ��������, ���� ������ ����� �� ��� ��������... -W-\n" );
  return false ;
 }
//
// --- �������� � ����������� ������������ -------------------------------------
//
 if( countCalcs <= 0 ) // ��������! ������ ����� ���� ���������� ������������ �� ��� ��������
 {
  t_printf( "\n-W- ����� ������������ �� ����������. ��������, ���� ���������� ������������ �� ��� ��������... -W-\n" );
  return true ;
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
  canAllExec = false ;
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
//
 TMsgDlgButtons mb; // ��� ������ �� �����
 TMsgDlgType mt; // ��� ����������� �� �����
//
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
//
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
 if( !flagExistsTiers ) // ������� Tiers[][] ��� ���...
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
 REAL dH_pix = (REAL)H_pix / nTiers, // ������� �  �������� �� ������ � ������ ������� ��������� ���������
      dB_pix = (REAL)B_pix / MaxOpsOnTier;
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
  REAL b_average = (REAL)c_GetCountOps() / c_GetCountTiers(); // ������� ������ ���
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
  return true; // �� ������� �������
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
 return true; // �� ���������
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
{ // ���� �������� Op ������������ � Tiers[][], ����������� true, ����� - false
 bool out = false;
 register INT i;
//
 if( !flagExistsEdges ) // ������� Mem_Edges[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
 for(i=1; i<=c_GetCountOps(); i++) // �� ���� ����������
  if( c_GetNumbOp( i ) == Op )
   return true;
//
 return out;
//
} // ---- ����� c_IsOpContainOnTiers -------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutTLDToTextFrame()
{ // ������ ��������� ������� ����� ������ � ��������� ����
//
 t_printf( "\n-=- ��������� ������� ����� ���������� ������ -=-\n     (���������� ���������� ������ ��� = %d )", nTiers+1 ); // ������ � ������ ������
//
 if( !flagCalcTLD ) // ���� paramsTLD �� ��������...
 {
  c_CalcParamsTLD(); // ��������� ��������� ������� ����� ������ �� �������� Tiers[][]
  flagCalcTLD = true ; // ���������� flag "paramsTLD ������������� �������� Tiers[][]"
 }
//
 for( INT i=1; i<=paramsTLD->Count-1; i++ ) // ����� 0-� ������ �� TLD
  t_printf( "%s", paramsTLD->Strings[i] ) ;
//
// === ������ ��������� ���������� � ������� ����� ������ ����� ������� ��� ====
//
 INT iGap,nGaps, n1, n2, CountTLD, // n1,n2 - ������ ����������� ����� ������� ���, CountTLD - ����� ������ � ���� ����������
     maxCountTLD_0 = _minINT, minCountTLD_0 = _maxINT, // max/min ������ - �������� 0/$
     maxCountTLD_1 = _minINT, minCountTLD_1 = _maxINT, // max/min ������ - �������� 1/$
     n1x_0,n1x_1, n2x_0,n2x_1, n1n_0,n1n_1, n2n_0,n2n_1; //  ��������� ������ ���� � ���� ���������������� ����������
 REAL averTLD_0=0.0, // ������-�������������� ������� ����� ������ � ��������� ����������� ������ 0/$
      averTLD_1=0.0; // �� �� � ��������� ����������� ������ 1/$
//
 if( !flagCalcTLD ) // ���� paramsTLD �� ��������...
 {
  c_CalcParamsTLD(); // ��������� ��������� ������� ����� ������ �� �������� Tiers[][]
  flagCalcTLD = true ; // ���������� flag "paramsTLD ������������� �������� Tiers[][]"
 }
//
 sscanf( paramsTLD->Strings[0].c_str(), "%d", &nGaps ); // ����� ����������� (Gap) ������ � ���
//
 for( iGap=1; iGap<=nGaps; iGap++ ) // �� ����� ����������� (Gap) ����� ������� ���
 {
  if( iGap < nGaps ) // ����� ��������� ������ � $
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/%d|%d:", &n1,&n2,&CountTLD ); // ������� / ������ ���� / ����� ������ � ���� ����������
  else // ��������� ������ ������� "n/$|m"
  {
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/" SS_02 "|%d:", &n1,&CountTLD ); // ������� ���� / $ / ����� ������ � ���� ����������
   n2=n1+1;
  }
// ��������� ���������� TLD � ��������� ����������� ������ 0/$ =================
//
// ���� ��� TLD � ��������� ����������� ������ 0/$ -----------------------------
  if( CountTLD >= maxCountTLD_0 )
  { maxCountTLD_0 = max(maxCountTLD_0,CountTLD); n1x_0=n1; n2x_0=n2; } // ��������� ���� ���� | ��������� ���� ���� (��������� ������-��...)
// ���� �in TLD � ��������� ����������� ������ 0/$ -----------------------------
  if( CountTLD < minCountTLD_0 )
  { minCountTLD_0 = min(minCountTLD_0,CountTLD); n1n_0=n1; n2n_0=n2; } // ��������� ���� ���� | ��������� ���� ���� (��������� ������-��...)
//
  averTLD_0 += (REAL)CountTLD; // ������-�������������� ������� ����� ������
// ����� ��������� TLD � ��������� 0/$ -----------------------------------------
//
// ��������� ���������� TLD � ��������� ����������� ������ 1/$ =================
  if( iGap == 1 )
   continue; // �� ������������ 1-� ���������� (����� 0-1) ---------------------
//
// ���� ��� TLD � ��������� ����������� ������ 1/$ -----------------------------
  if( CountTLD >= maxCountTLD_1 )
  { maxCountTLD_1 = max(maxCountTLD_1,CountTLD); n1x_1=n1; n2x_1=n2; } // ��������� ���� ���� | ��������� ���� ���� (��������� ������-��...)
// ���� �in TLD � ��������� ����������� ������ 1/$ -----------------------------
  if( CountTLD < minCountTLD_1 )
  { minCountTLD_1 = min(minCountTLD_1,CountTLD); n1n_1=n1; n2n_1=n2; } // ��������� ���� ���� | ��������� ���� ���� (��������� ������-��...)
//
  averTLD_1 += (REAL)CountTLD; // ������-�������������� ������� ����� ������
//
 } // ����� ����� �� ����������� ����� ������� ���
//
// ���������� ������ ����������� � ������� ����� ������
//
 char szStatTLD[_512], // ������ ������ � ������� ����� ��������� ������ (ParamsTLD)
      szTemp_0[_128], szTemp_1[_128] ;
// �������� �� �������� ���������� TLD � ��������� ������ 0/$ -------------------
 n2n_0==nGaps ? sprintf( szStatTLD,"�����:\n0/$: min=%d(%d/" SS_02 "), ", minCountTLD_0,n1n_0 ) :
                sprintf( szStatTLD,"�����:\n0/$: min=%d(%d/%d), ",        minCountTLD_0,n1n_0, n2n_0 ) ;
 n2x_0==nGaps ? sprintf( szTemp_0, "max=%d(%d/" SS_02 "), ��.�����.=%.4g; �����(TLD)=%.4g", maxCountTLD_0,n1x_0,        averTLD_0 / nGaps, averTLD_0 ) :
                sprintf( szTemp_0, "max=%d(%d/%d), ��.�����.=%.4g; �����(TLD)=%.4g",        maxCountTLD_0,n1x_0, n2x_0, averTLD_0 / nGaps, averTLD_0 ) ;
 strcat( szStatTLD, szTemp_0 ); // ����������� ������ ��� ������ �� F2
 t_printf( "\n%s", szStatTLD ); // ����� TLD-������ � ��������� ������ 0/$ � ��������� �����
//
// �������� �� �������� ���������� TLD � ��������� ������ 1/$ -------------------
 n2n_1==nGaps ? sprintf( szStatTLD,"1/$: min=%d(%d/" SS_02 "), ", minCountTLD_1,n1n_1 ) :
                sprintf( szStatTLD,"1/$: min=%d(%d/%d), ",        minCountTLD_1,n1n_1, n2n_1 ) ;
 n2x_1==nGaps ? sprintf( szTemp_1, "max=%d(%d/" SS_02 "), ��.�����.=%.4g; �����(TLD)=%.4g", maxCountTLD_1,n1x_1,        averTLD_1 / (nGaps-1.0), averTLD_1 ) :
                sprintf( szTemp_1, "max=%d(%d/%d), ��.�����.=%.4g; �����(TLD)=%.4g",        maxCountTLD_1,n1x_1, n2x_1, averTLD_1 / (nGaps-1.0), averTLD_1 ) ;
//
 strcat( szStatTLD, szTemp_1 );
 t_printf( "%s\n", szStatTLD ); // ����� TLD-������ � ��������� ������ 1/$ � ��������� �����
//
} // ----- ����� c_PutTLDToTextFrame -------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_SaveTLD( char FileName[] )
{ // ������ ��������� ������� ����� ������ � ����
//
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extTld) ); // ��������������� ��� �����
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // ���� MewFileName ��� ����������...
//
 if(!(fptr = fopen( NewFileName,"w" ))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� �������� ���� %s ������� ����� ���������� ������ -E-\n\n-W- ��������� �������������� ������ �� �������� �������� ������ -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // ������� ����� ��� ������
 }
//
// setbuf( fptr, NULL ); // ��������� ������������ ��� ������
//
 if( !flagCalcTLD ) // ���� paramsTLD �� ��������...
 {
  c_CalcParamsTLD(); // ��������� ��������� ������� ����� ������ �� �������� Tiers[][]
  flagCalcTLD = true ; // ���������� flag "paramsTLD ������������� �������� Tiers[][]"
 }
//
 for( INT i=0; i<=paramsTLD->Count-1; i++ ) // ����� 0-� ������ �� TLD
 {
  DeleteSymbolAll( paramsTLD->Strings[i].c_str(), *_OUT ) ; // ���������� ������ _OUT[0] = ">>" � �������
  DeleteSymbolAll( paramsTLD->Strings[i].c_str(), *_IN ) ; // ���������� ������ _IN[0] = "<<" � ������
//
  fprintf( fptr, "%s\n", paramsTLD->Strings[i] ); // ������ � ����
 }
//
 fclose( fptr ) ; // ������� ����
//
 return NewFileName ;
//
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
//  ��� RuleMessage=true �������� ��������� �� ������� }
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
  out = CreateProcess(NULL,CommandLine,NULL,NULL,false,
                      dwCreationFlag,NULL,NULL,&si,&pi);
//
  if (!out) // ���� ����� ��������... out=false
  {
   if (RuleMessage)  // ���� ����� ����� ������ ��������� �� �������
    MessageDlg("��������, ����������\n\r\n\r" +
                AnsiUpperCase(CommandLine)  +
               "\n\r\n\r����������...  (������ " +
                IntToStr(GetLastError()) + ")",
                mtError,
                TMsgDlgButtons() << mbYes, 0);
   return false ;
  } // ����� IF out = false
//
  if (out) // ���� ����� ������... out = true
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
    return false ; // ����� - ������ �� �����
//
   if ((RuleParent != 0) && // �������� �����������
       (RuleParent != 1))
    Application->Terminate(); // ��������� ������������ �������
//
 } // ����� IF out=true
//
} // ----- ����� c_CreateProcess -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//INT __fastcall c_CreateProsess( char *cmdLine, byte RuleParent, byte Priority, bool RuleMessage )
//{ // ��������� ��������� ����� CreateProsess -----------------------------------
// tp_printf( "\n->%s %d %d %d\n", cmdLine, RuleParent, Priority, RuleMessage );
// c_CreateProcess( cmdLine, RuleParent, Priority, RuleMessage );
//} // ----- ����� c_CreateProcess -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall c_SaveEdges(char FileName[])
{  // ����� ��� ��� ������� �������� �����
 FILE *fptr = NULL; // ������� ��������� �� ����
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName( FileName,extGv ) ); // ��������������� ��� �����
 strcpy( NewFileName, CreateUniqueFileName(NewFileName) ); // ���� MewFileName ��� ����������...
//
 if(!(fptr = fopen(NewFileName, "w"))) // ������� ��� ������
 {
  t_printf( "\n-E- ���������� ��������� ���� %s ������ ��� (��������������� ������) ��� -E-\n-W- ��������� �������������� ������ �� �������� �������� ������ -W-",
                   NewFileName );
  return IntToStr(ERR_NOT_MASSIVE_TIERS).c_str() ; // ������� ����� ��� ������
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
 return NewFileName ;
//
} // --- ����� c_SaveEdges -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall c_ReadEdges(char FileName[])
{ // ������ �� ����� FileName ������ � ����� (������ Mem_Edges[][] ������ ������
// - � ������ ���������� �� ������ Tier = 0 - ������� ������ ); Mem_Edges[][]
// - � Tiers[][] - ����������; ��� ������ �������� ����� FileName ����������� false
 char str[_2048*4];
 FILE *fptr = NULL; // ��������� �� ����
 bool flagEdges = false, // ���� ������ �������� ��� � ��A
      flagMLC   = false; // ���� �������������� ����������� (Many Lines Comment)
//
 flagExistsEdges =  // ������ Mem_Edges[][] �� ������...
 flagExistsOps   =  // nOps �� ���������
 flagExistsTiers = false ; // ������ Tiers[][] �� ������...
//
 char NewFileName[_512];
 strcpy( NewFileName,ReformFileName(FileName,extGv) ); // ��������������� ��� �����
//
 if( !(fptr = fopen(NewFileName, "r")) ) // ���� �������� ����� ������� ��� ������
 {
  t_printf( "\n-E- ���������� ��������� ���� %s �������� ��� -E-\n-W- �������� �������������� ��� ���������� ������ -W-",
                   NewFileName );
  return false ;
 }
//
 strNcpy( FileNameEdges, NewFileName ); // ��������� ������� ��� ����� �������� ���
//
 Max_Edges = _128; // �������������� ������������ ���������� ��� � ���
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 Mem_Edges = ( me* ) realloc( Mem_Edges, Max_Edges * sizeof( me ) ); // ���������������� ������ ������ �������� ��� ��������������� �����
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
   flagMLC = true; // ������ �������������� �����������
   continue; // ��� ������ ����������
  }
  if( str[0] == '*' && str[1] == '/' ) // ����� �������������� �����������
  {
   flagMLC = false; // ������ �������������� �����������
   continue; // ��� ������ ����������
  }
//
  if( sscanf( str, "digraph %s {", GraphName ) == 1 ) // ����� ���� ���� ���������...
   flagEdges = true; // ������ �������� ��� ���
  if( str[0] == '}' )
   flagEdges = false; // ����� �������� ��� ���
//
//  if( flagEdges && !flagMLC )
  if( flagEdges )
   if ( !ParseStringAndAddEdges( str ) ) // ���������� ������ str �� �������� � ���������� ������� ���
    return false;
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
 flagExistsEdges = true ; // ������ Mem_Edges[][] ������ !!!
//
 flagExistsOps = false; // ����� ���������� ����������
 c_GetCountOps(); // ������� ����� ���������� (������ �����) ��� �������
 flagExistsOps = true; // ... �� ������ ������ !
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
 flagExistsTiers = false; // ������ Tiers[][] �� ������
//
 return true ;
//
} // ------ ����� c_ReadEdges --------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall TestAndAddMemoryForEdges( INT nEdges )
{ // ��������� ������������� ���������� ������� ��� Mem_Edges[][] � ���
// ������������� ����������� ��� � stockMem ���. ��� ������ ��������� true...
//
 if( nEdges < Max_Edges ) // ������ ��� ������� Mem_Edges[][] ����������...
  return true;
//
// ===== ������ �� ������� =====================================================
//
 Max_Edges *= stockMem; // ����������� � stockMem ��� ������, ��� ����...
 Mem_Edges = ( me* ) realloc( Mem_Edges, Max_Edges * sizeof(me) ); // �������������� ������ ��� Mem_Edges[][]...
//
 if( !Mem_Edges ) // ������ ����� - ������������� �������������� ������ �� ����������..!
 {
  char str[_1024];
  snprintf(str,sizeof(str), "�������� ������ ��� ���������� ������� ��� (Input). ����������� %d ���������...",
                             Max_Edges );
  MessageBeep(MB_OK); // �������� ��������������...
  MessageBox(0, str, "��������������", MB_OK | MB_ICONWARNING | MB_TOPMOST);
  flagExistsEdges = false ; // ������ Mem_Edges[][] �� ������...
  return false ;
 } // �����  if( Mem_Edges == NULL )
 else
 {
  t_printf( "\n-I- ������ ��� (Input) �������������� �� %d ��������� -I-",  Max_Edges );
  return true;
 }
//
} // ---- ����� TestAndAddMemoryForEdges ---------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall ParseStringAndAddEdges( char *str )
{ // ��������� ������ str, �������� ������������ ���� ������ ������ � ��������� �� � ������ ���
// ����� ������ ������: a -> b -> c -> -> d ; ��� a,b,c,d - ����� �����
// ��� ������ ������������� ������ ��� ���������� ������� ��� ��������� false
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
   if( !TestAndAddMemoryForEdges( nEdges ) ) // ���� �� ��������� ������ ��� Mem_Edges[][] ?
    return false;
  } // �����  if( sscanf( str, "%d -> %d",
 else // ����� 2 ���� ��������� �� �������..!
  return true;
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
  return true;
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
  return false ; // �� ������� �������...
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
 return true;
} // ----- ����� ReadAndPrimWorkOpsCalcsVertEdgeFiles --------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_LuaCallByTimer( char *CommandLine, INT d_Ticks )
{ // ����� Lua-���������� � ��������� d_Tick (������ settimeout() �� JS)
//
 if( d_Ticks <= 0 )
  return -1 ;
//
 bool flag = false; // ���� � ������ �� ������ �������...
 for( int i=0; i<strlen(CommandLine); i++) // ���� �� �������� � ������ CommandLine
 {
  if( CommandLine[i] != ' ')
  {
   flag = true; // ���� ���� �� ���� ��-������..!
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
  if( flag_Busy == true ) // �� ������� ���������� ����� CallLuaThread...
  {
   tpe_printf( "\n-W- ����� %s �������� ��-�� ����������� ����������� ������ %s... -W-",
               Mem_EV[i].CommandLine, busy_CommandLine );
   continue;  // ����������-c...
  }
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
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
 flag_Busy = true; // ���������� CallLuaThread ������..!
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
ended: flag_Busy = false; // ���������� CallLuaThread ���������...
//
} // ----- ����� CallLuaThread -------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_SwapOpsTierToTier(INT Op1, INT Op2)
{ // --- ������ ������� ��������� Op1 � Op2, ����������� �� ������ ������
// ----- ���� ������� ������������ ��������� - ������������ RETURN_OK � ���������� iMove
//
 if( !flagExistsTiers ) // ���� ������� Tiers[][] ��� �� ���������� - ������� � �������
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 if( Op1 == Op2 )  // �� ������-� ������ ���������-�... �������� �������� !!!
 {
  DisplayMessage( "E", __FUNC__, messParams2, false ); // ������ ���������
  return RETURN_OK ;
 }
//
 INT TierOp1,TierOp2 ;
// 
 if( ( TierOp1 = c_GetTierByOp( Op1 ) ) == ERR_COMMON || // �������� �� ������������ ����������� Tier1 "���"
     ( TierOp2 = c_GetTierByOp( Op2 ) ) == ERR_COMMON ) // ...tier2
 {
  DisplayMessage( "E", __FUNC__, messParams1, false ); // ������ ���������
  return ERR_IN_DATA ;
 }
//
 if( ( TierOp1 < c_GetMinTierMaybeOp( Op2 ) ) || // �������� ������.����.����. Op1 �� ������ Op2 "���"
     ( TierOp1 > c_GetMaxTierMaybeOp( Op2 ) ) ||
     ( TierOp2 < c_GetMinTierMaybeOp( Op1 ) ) || // �������� ������.����.����. Op2 �� ������ Op1 "���"
     ( TierOp2 > c_GetMaxTierMaybeOp( Op1 ) ) )
 {
  DisplayMessage( "E", __FUNC__, messParams3, ERR_RANGE_IN ); // ������ ���������
  return ERR_RANGE_IN ;
 }
//
 if( c_MoveOpTierToTier( Op1, TierOp2 ) == RETURN_OK && // �������� ������� �p1 �� ���� ���������� Op2 "�"
     c_MoveOpTierToTier( Op2, TierOp1 ) == RETURN_OK )  // �������� ������� �p2 �� ���� ���������� Op1
   return RETURN_OK ;
//
 flagCalcTLD = false ; // paramsTLD �� ������������� Tiers[][]
//
 return ERR_IN_DATA ;
//
} // ----- ����� c_SwapOpsTierToTier -------------------------------------------


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
INT __fastcall c_GetNumbOp(INT Numb)
{ // ���������� ����� Numb ��������� (�������� �������) �� ���� ��������� � ���� ���
// ������� ������� ������� ����������
 if( !flagExistsEdges ) // ��� ������� Mem_Edges[][]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ���� ����� ���������� (����� nEdges ��� �����)===========================
////////////////////////////////////////////////////////////////////////////////
 INT nW, iEdge, jEdge, FromTo=1,
     iOps = 0; // ������� ����� ������ (����������)
//
 for( iEdge=1; iEdge<=nEdges; iEdge++ ) // �� ���� ����� ������� � #1
  Edges_f(1,iEdge) = true ; // �������� ��� true
//
  for(iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� nEdges ����� ������� � #1
// ��������� ������ ��������� (To) ������� ���� iEdges
   if( Edges_f(1,iEdge) ) // ��������� "����������" ��������� ������� ���� iEdges
   {
    nW = Edges(1,iEdge);
    iOps ++ ; // ������� ������ ����� (�������� �� �����)
//
    if( iOps == Numb ) // ��� Numb-��� ��������� ������ ���������
     return nW ;
//
    for(jEdge=1; jEdge<=nEdges; jEdge++)
     if( Edges(1,jEdge) == nW )
       Edges_f(1,jEdge) = false; // ����� ����� � ������� "����" (To)
//
   } // ����� if( Mem_Edges[iEdges].FlagFTo )
//
} // ------ ����� c_GetNumbOp --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall tuneFlagsAll( bool FLAG, INT FromTo )
{ // ������������� � FLAG ��� ����� ���������� ������� ��� Edges[][]
// �������������� ������ "From" ��� "To" ��� From/To = 0/1 ��������������
//
 register INT iEdge; // �������� ����������..!
//
 for( iEdge=1; iEdge<=nEdges; iEdge++ ) // �� ���� ����� ������� � #1
  Edges_f(FromTo,iEdge) = FLAG ; // �������� ��� FLAG
//
} // ----- ����� tuneFlagsAll --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall tuneFlagsIfEqual( bool FLAG, INT FromTo, INT Value )
{ // ������������� � FLAG ����� ���������� ������� ��� Edges[][] , ���� �������� ������� value
// �������������� ������ "From" ��� "To" ��� From/To = 0/1 ��������������
//
 register INT iEdge; // �������� ����������..!
//
 for( iEdge=1; iEdge<=nEdges; iEdge++ ) // �� ���� ����� ������� � #1
  Edges_f(FromTo,iEdge) = Edges(FromTo,iEdge)==Value ? FLAG : Edges_f(FromTo,iEdge) ; // ��������...
//
} // ----- ����� tuneFlagsAll --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall clearFlagsDuplicateOps( INT FromTo,INT Op )
{ // ������������� � false ��� ����� ���������� �� �������� Op (����� ������� ��������������)
// �������������� ������ "From" ��� "To" ��� From/To = 0/1 ��������������
//
 register INT iEdge; // �������� ����������..!
 register bool flagEq, flagOp = false; // ���� Op ����������� � ������ - true !
//
 for( iEdge=1; iEdge<=nEdges; iEdge++ ) // �� ���� ����� ������� � #1
///  for( jFromTo=0; jFromTo<=1; jFromTo++ ) // �� ���������� "From"/"To" ( 0/1 �������������� )
  {
   flagEq = Edges(FromTo,iEdge)==Op ? true : false ; // ����� �� ���������� ������...
//
   if( flagEq && flagOp )
    Edges_f(FromTo,iEdge) = false ; // ����� ������� ��������� Op ��� ��������� - false
// ----- ������������������ if �� ������ ! -------------------------------------
   if( flagEq ) // ��������� Op...
    flagOp = true;
  }
//
} // ----- ����� clearFlagsDuplicateOps ----------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOpsInput()
{ // ���������� ������ ������� ������� (0-� ����) � ��� ------------------------
//
 if( !flagExistsEdges ) // ��� ������� Mem_Edges[][]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ���� ����� nOpsInput ������� ���������� (����� nEdges ��� �����)=========
////////////////////////////////////////////////////////////////////////////////
 register INT iEdge, jEdge, nW ;
 bool flag;
 nOpsInput = 0; // ����� ������� ���������� (0-� ����; ����������)
//
 tuneFlagsAll( false, 0 ); // ������������� � false ����� "From" ���������� ������� ��� Edges[][]
 tuneFlagsAll( false, 1 ); // ������������� � false ����� "To" ���������� ������� ��� Edges[][]
//
// === �� ���� ����� ��� =======================================================
 for(iEdge=1; iEdge<=nEdges; iEdge++) // �� ��� ����� ������� � #1
  if( !Edges_f(0,iEdge) ) // ��������� ��������� ������� ���� iEdge
  {
   nW = Edges(0,iEdge);
//
   tuneFlagsIfEqual( true, 0, nW ) ; // �������� "From"
   tuneFlagsIfEqual( true, 1, nW ) ; // �������� "To"
//
  flag = false;
  for(jEdge=1; jEdge<=nEdges; jEdge++)
   if( Edges_f(1,jEdge) && Edges(1,jEdge)==nW ) // �������� � =nW
    flag = true ; // ����, nW ����������� � Edges(1,*) ..!
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
 if( !flagExistsEdges ) // ��� ������� Mem_Edges[][]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ���� ����� nOpsInput ������� ���������� (����� nEdges ��� �����)=========
////////////////////////////////////////////////////////////////////////////////
 register INT iEdge, jEdge, nW ;
 bool flag;
 nOpsOutput = 0; // ����� �������� ���������� (����������)
//
 tuneFlagsAll( false, 0 ); // ������������� � false ����� "From" ���������� ������� ��� Edges[][]
 tuneFlagsAll( false, 1 ); // ������������� � false ����� "To" ���������� ������� ��� Edges[][]
//
// === �� ���� ����� ��� =======================================================
 for(iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� ������� � #1
  if( !Edges_f(1,iEdge) ) // ��������� ��������� ������� ���� iEdge
  {
   nW = Edges(1,iEdge);
//
   tuneFlagsIfEqual( true, 0, nW ) ; // �������� "From"
   tuneFlagsIfEqual( true, 1, nW ) ; // �������� "To"
//
   flag = false;
   for(jEdge=1; jEdge<=nEdges; jEdge++)
    if( Edges_f(0,jEdge) && Edges(0,jEdge)==nW ) // �������� � =nW
     flag = true ; // ����, nW ����������� � Edges(0,*) ..!
//
   if( !flag ) // ���� nW �� ����������� � Edges(0,*) - ��������!
    nOpsOutput ++ ;
//
  } // ����� if(!Edges_f(1,iEdge)) � for(iEdge=1; iEdge<=nEdges; iEdge++)
//
 return nOpsOutput ;
//
} // --- ����� c_GetCountOpsOutput----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbOpInput(INT Numb)
{ // ���������� ����� Numb ��������� (������ �� ������� ����������)
//
 if( !flagExistsEdges ) // ��� ������� Mem_Edges[][]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ���� Numb-��� �������� (����� nEdges ��� �����)==========================
////////////////////////////////////////////////////////////////////////////////
 register INT iEdge, jEdge, nW ;
          INT iOps = 0 ; // ������� ����� ������ ����� (����������)
 bool flag;
//
 tuneFlagsAll( false, 0 ); // ������������� � false ����� "From" ���������� ������� ��� Edges[][]
 tuneFlagsAll( false, 1 ); // ������������� � false ����� "To" ���������� ������� ��� Edges[][]
//
// === �� ���� ����� ��� =======================================================
//
 for(iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� ������� � #1
  if( !Edges_f(0,iEdge) ) // ��������� ��������� ������� ���� iEdge
  {
   nW = Edges(0,iEdge);
//
   tuneFlagsIfEqual( true, 0, nW ) ; // �������� "From"
   tuneFlagsIfEqual( true, 1, nW ) ; // �������� "To"
//
   flag = false;
   for(jEdge=1; jEdge<=nEdges; jEdge++)
    if( Edges_f(1,jEdge) && Edges(1,jEdge)==nW ) // �������� � ����� nW
     flag = true ; // ����, nW ����������� � Edges(1,*) ..!
//
   if( !flag ) // ���� nW �� ����������� � Edges(1,*) - ��������!
    iOps ++ ;
//
   if( iOps == Numb ) // ����� ��������� ����� Numb
    return nW ;
//
  } // ����� if(!Edges_f(0,iEdge)) � for(iEdge=1; iEdge<=nEdges; iEdge++)
//
} // ------ ����� c_GetNumbOpInput ---------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetNumbOpOutput(INT Numb)
{ // ���������� ����� Numb ������� (������ �� �������� ����������)
//
 if( !flagExistsEdges ) // ��� ������� Mem_Edges[][]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ���� ����� ���������� (����� nEdges ��� �����)===========================
////////////////////////////////////////////////////////////////////////////////
 register INT iEdge, jEdge, nW ;
          INT iOps = 0 ; // ������� ����� ������
 bool flag;
//
 tuneFlagsAll( false, 0 ); // ������������� � false ����� "From" ���������� ������� ��� Edges[][]
 tuneFlagsAll( false, 1 ); // ������������� � false ����� "To" ���������� ������� ��� Edges[][]
//
// === �� ���� ����� ��� =======================================================
//
 for(iEdge=1; iEdge<=nEdges; iEdge++) // �� ���� ����� ������� � #1
  if( !Edges_f(1,iEdge) ) // ��������� ��������� ������� ���� iEdge
  {
   nW = Edges(1,iEdge);
//
   tuneFlagsIfEqual( true, 0, nW ) ; // �������� "From"
   tuneFlagsIfEqual( true, 1, nW ) ; // �������� "To"
//
   flag = false;
   for(jEdge=1; jEdge<=nEdges; jEdge++)
    if( Edges_f(0,jEdge) && Edges(0,jEdge)==nW ) // �������� � ����� nW
     flag = true ; // ����, nW ����������� � Edges(0,*) ..!
//
   if( !flag ) // ���� nW �� ����������� � Edges(0,*) - ��������!
    iOps ++ ;
//
   if( iOps == Numb ) // ����� ��������� ����� Numb
    return nW ;
//
  } // ����� if(!Edges_f(1,iEdge)) � for(iEdge=1; iEdges<=nEdges; iEdge++)
//
} // ------ ����� c_GetNumbOpOutput --------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetCountOps()
{ // ���������� ����� ���������� (���������� ������� ������ ��� ��� ����� ������� ������)
//
 if( flagExistsOps ) // ���������� ���������� nOps ����������..!
  return nOps ;
//
 if( !flagExistsEdges ) // �� ���������� ������� Mem_Edges[][]
 {
  DisplayMessage( "E", __FUNC__, messNotEdges, ERR_NOT_MASSIVE_EDGES ); // ������ ���������
  return ERR_NOT_MASSIVE_EDGES ;
 }
//
////////////////////////////////////////////////////////////////////////////////
// --- ���� ����� ����� ���������� nOps (��� �������� �����) ===================
////////////////////////////////////////////////////////////////////////////////
//
 register INT iEdge;
 nOps = 0; // ����� ������ ��� ������� (������)
//
 tuneFlagsAll( true, 0 ); // ������������� � true ����� "From" ���������� ������� ��� Edges[][]
 tuneFlagsAll( true, 1 ); // ������������� � true ����� "To" ���������� ������� ��� Edges[][]
//
 for( iEdge=1; iEdge<=nEdges; iEdge++ ) // �� ���� ����� ������� � #1
  clearFlagsDuplicateOps(1,Edges(1,iEdge) ) ; // ������ false � ����������
//
 for( iEdge=1; iEdge<=nEdges; iEdge++ ) // �� ���� ����� ������� � #1
  if( Edges_f(1,iEdge) ) // ���� true (� ���������� - false )
    nOps ++ ;
//
 flagExistsOps = true; // ����� ���������� (������) ����������
//
 return nOps ;
//
} // --- ����� c_GetCountOps ---------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_GetOpByMaxTierLowerPreset(INT Op)
{ // ����� ��������, ������������� ��������� �� ��������� Op � ����������� �� �����
// � ������������ ������� (���� ����� �������� ��������� - ������� ��������� �� ������)
 register INT i;
 INT to_Op, Op_maxTier, to_Tier, maxTier = -134567,
     nOut = c_GetCountOutEdgesByOp(Op); // ����� �������� ��� ��������� Op
//
 if( !flagExistsTiers ) // ������� Tiers[][] �� ����������...
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
  to_Op   = c_GetNumbOutEdgeByOp( i, Op ); // i-��� ��������������� �� ���� �������� ������������ Op
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
bool __fastcall c_DrawDiagrTLD()
{ // ������ ����������� ����������� (���������) ����� ����� ���������� ������ (TLD)
 INT OpsOnTier,
     H_pix, B_pix, // ������ � ������ ������� ��������� IM1 � ��������
     B_rect, // ������ �������������� ������� � ��������
     x1,y1, x2,y2; // ���������� �������������� ������� � ��������
 char str[_256]="\0";
//
 if( !flagExistsTiers ) // ������� Tiers[][] ��� ���...
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
 INT n1,n2,CountTLD, // n1,n2 - ������ ����������� ����� ������� ���, CountTLD - ����� ������ � ���� ����������
     maxCountTLD = _minINT, minCountTLD = _maxINT, // max/min ������
     n1x,n2x, n1n,n2n, // ��������� ������ ���� � ���� ����������������� ����������
     iGap, nGaps ;
 REAL averTLD=0.0; // ������-�������������� ������� ����������� ����� ������� ���
//
 if( !flagCalcTLD ) // ���� paramsTLD �� ��������...
 {
  c_CalcParamsTLD(); // ��������� ��������� ������� ����� ������ �� �������� Tiers[][]
  flagCalcTLD = true ; // ���������� flag "paramsTLD ������������� �������� Tiers[][]"
 }
//
 sscanf( paramsTLD->Strings[0].c_str(), "%d", &nGaps ); // ����� ���������� ����������� � ���
//
// ���� ���������� ����� ������ ------------------------------------------------
 for( iGap=1; iGap<=nGaps; iGap++ ) // ���� �� ���� ����������� (Gap) ������ ��� ��� ������� max/min
 {
  if( iGap < nGaps ) // ����� ��������� ������ � $
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/%d|%d:", &n1,&n2,&CountTLD ); // ������� ���� / ������ ���� / ����� ������ � ���� ����������
  else // ��������� ������ ������� "n/$|m"
  {
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/" SS_02 "|%d:",  &n1,&CountTLD ); // ������� ���� / $ / ����� ������ � ���� ����������
   n2=n1+1;
  }
//
  if( CountTLD >= maxCountTLD ) // ���� ��� ����� ����� ������
  { maxCountTLD = max(maxCountTLD,CountTLD); n1x=n1; n2x=n2; } // ��������� ���� ���� | ��������� ���� ���� (��������� ������-��...)
//
  if( CountTLD < minCountTLD ) // ���� �in ����� ����� ������
  { minCountTLD = min(minCountTLD,CountTLD); n1n=n1; n2n=n2; } // ��������� ���� ���� | ��������� ���� ���� (��������� ������-��...)
//
 averTLD += (REAL)CountTLD; // ��������� ��� ��������� �����.��������������� ������� ����� ������ ����� ������
//
 } // �����  for( iGap=1; iGap<=n; iGap++ )
//
 averTLD /= (REAL)nGaps; // �����.�������������� ������� ����� ������ ����� ������
//
 REAL dH_pix = 1.0 * H_pix / nGaps, // ��� ������� �  �������� �� ������ � ������ ������� ��������� ���������
      dB_pix = 1.0 * B_pix / maxCountTLD;
//
 dH_pix = max( dH_pix, 1.0 ); // ������ ������ ����  <= 1 , ����� ��������� ����������...
//
 snprintf(str,sizeof(str), "H|N/W=%d|/%d/%d-%d", nGaps,maxCountTLD,n1x,n2x ); // ����� ���� / ��� ������ / ���� ������ - ���� �����
 F2->L_OM->Caption = str;
 F2->L_OM->Repaint(); // ������������� ��������������
//
 for( iGap=1; iGap<=nGaps; iGap++ ) // ���� �� ���� ����������� (Gap) ������ ��� ��� ���������� �������
 {
//
  if( iGap < nGaps ) // ����� ��������� ������ � $
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/%d|%d:", &n1,&n2,&CountTLD ); // ������� ���� / ������ ���� / ����� ������ � ���� ����������
  else // ��������� ������ ������� "n/$|m"
  {
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/" SS_02 "|%d:",  &n1,&CountTLD ); // ������� ���� / $ / ����� ������ � ���� ����������
   n2=n1+1;
  }
//
  B_rect = dB_pix * CountTLD; // ������ �������������� �������
//
// --- ������������� ����� ������� ---------------------------------------------
  if( CountTLD == minCountTLD )
   TIM1->Canvas->Brush->Color = brush_draw_color_MIN; // ���� ����� �������
  else
  if( CountTLD == maxCountTLD )
   TIM1->Canvas->Brush->Color = brush_draw_color_MAX; // ���� ����� ��������
  else
   TIM1->Canvas->Brush->Color = brush_draw_color_TLD; // ���� ����� ������� ��� TLD
////////////////////////////////////////////////////////////////////////////////
  x1 = 0;  // ����� ������� ����� �������������� ������� ( Rectangle, Rect )
  y1 = dH_pix * ( iGap - 1 );
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
 } // ����� �����  for( iGap=1; iGap<=n; iGap++ )
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
  return true; // �� ������� �������
//
} // --- ����� �_DrawDiagrTLD --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall  c_CalcParamsTLD()
{ // �� ������� Tiers[][] ������ � ������� � TLD ���������� � ������� ����� ������
// ����� ��������� ����� ������� (������� ��� ����������� ����� �����������
// ��� ��������/�������� ������ ����� ���������� �� ������ ���
// ��������, ��� ���� ��������� ����� ��� ���� ������������ ������������
//
 char sN[_8192]="\0", sS[_8192]="\0", sW[_128]="\0";
 INT k,l, from_Op,to_Op, to_Tier, max_to_Tier;
 register INT i,j;
//
 if( !flagExistsTiers ) // ������� Tiers[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  t_printf( "\n-W- ��� ���������� ��������� ������� ����� ������ �������� ������� ���..! -W-\n");
  MessageBeep( MB_ICONQUESTION ); // �������� ��������������...
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 paramsTLD->Clear(); // ������� ��� ������ ���������� ����������� �������
//
 paramsTLD->Add( IntToStr(nTiers+1) ); // ����� ����� � TLD
//
// ---- �������� ���� �� ����������� ����� ������� (Gap) ��� -------------------
// ---- iBottomOfGap - ������ ������� ���������� ������������ ������� ������� ����� ���
 for( INT iBottomOfGap=1; iBottomOfGap<=nTiers+1; iBottomOfGap++ ) // �� iBottomOfGap - ������ ������� ��������� � ���
 {
//
  OutRepeatComplete(" * "__FUNC__"(): ", iBottomOfGap, (nTiers+1), 50, (1.0e2*iBottomOfGap)/(nTiers+1), "%.0f", "% ���������"); // ��������� ���������� ���������� ����� �����
//
  strNcpy( sN, "" ); // �������� ������ ���������� ��������� ������ � "����" � ���� ����� iBottomOfGap
  l = 0; // ����� ���������� ������ ������
//
  for( i=0; i<iBottomOfGap; i++ ) // �� ������ ���, �� ������� (�������) iBottomOfGap
  {
//
   for( j=1; j<=c_GetCountOpsOnTier(i); j++ ) // �� ���������� �� ����� j
   {
//
    APM // ���� ���������� Windows ---------------------------------------------
//
    from_Op = c_GetOpByNumbOnTier( j,i ); // �������� ����� �������, �� ������� ������� ����
    to_Op   = c_GetOpByMaxTierLowerPreset( from_Op ); // ���� �������� ��� ��� ������ - ������������ ERR_COMMON
//
    max_to_Tier = ( to_Op == ERR_COMMON ) ? nTiers + 1 : c_GetTierByOp( to_Op ); // ��������������� to_Op ���� ���� �������� / �� ��������
//
    if( max_to_Tier >= iBottomOfGap ) // ���� ����� ���� ����� ��� ����� ����� ���� ���������
    {
     if( !c_GetCountInEdgesByOp( from_Op ) ) // ��� ������� (��������) ������� ������
//      snprintf( sW,sizeof(sW), " %1s%d|%d->%d", _IN, from_Op, i, max_to_Tier ) ; // _IN = "\xAB" = "<<"
      snprintf( sW,sizeof(sW), " " _IN "%d|%d->%d", from_Op, i, max_to_Tier ) ; // _IN = "\xAB" = "<<"
     else
     if( !c_GetCountOutEdgesByOp( from_Op ) ) // ��� ������� (��������) �������� ������
       snprintf( sW,sizeof(sW), " %d" _OUT "|%d->"  SS_02 "", from_Op, i ) ; // _OUT = "\xBB" = ">>"
     else
      snprintf( sW,sizeof(sW), " %d|%d->%d", from_Op, i, max_to_Tier );
//
     strcat( sN, sW ); // ��������� � sN ��� ������������ ������ ������
//
     l ++ ;
    } // ����� if( max_to_Tier >= iBottomOfGap )
//
   } // ����� �� j (������� ���������� �� ����� i)
//
  } // ����� ����� �� i (�� ���� ������ ���)
//
 iBottomOfGap == nTiers+1 ? // SS_02 = "$"
  paramsTLD->Add( Format("%d/" SS_02 "|%d: %s", OPENARRAY(TVarRec, ((int(iBottomOfGap-1)),(int(l)),sN))) ) : // ������� ������ ���������� ��������� c ������ ������ iBottomOfGap
  paramsTLD->Add( Format("%d/%d|%d: %s", OPENARRAY(TVarRec, ((int(iBottomOfGap-1)),(int(iBottomOfGap)),(int(l)),sN))) );
//
 } // ����� ����� �� iBottomOfGap (iBottomOfGap - ������ ������� ��������� � ���)
//
} // ---- �����  c_CalcParamsTLD -----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_PutParamsTiers()
{ // --- ����� �������� ���������� ��� � ��� ��� -------------------------------
 char szOut[_4096]="\0"; // ������ ��� ������ ��������������� ������
 REAL AverWidth, // ������� ������ �� ������ ����� ������� � ����������
      SumSqWidth = 0.0, // ����� ��������� ������� ������ �� ������
      AverSqDevWidth = 0.0; // ��.��.���������� ������ ������ ��� (����� ������ 1 � nTiers)
 INT  iOp, nOp,     iTier,     nTierMin,    nTierMax,
      Op,  dTiers,  sdOps = 0, sdTiers = 0;
//
 if( !flagExistsTiers ) // ������� Tiers[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
// =============================================================================
//
 c_CalcParamsTiers() ; // ���������� ���������� ����� ������ ��� � ��������� � ���-�� StatTiers (������)
//
 AverWidth = StatTiers.averWidth ; // ������������������� ������ ��� (����� 0-�� ������)
//
 AverSqDevWidth = StatTiers.SD ; // ����� ��������� �������
//
////////////////////////////////////////////////////////////////////////////////
//
 char szStatTiers[_256]="\0"; // ������ ���������� ������ ���
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
 {
//
  OutRepeatComplete(" * "__FUNC__"(): ", iTier, nTiers, 30, (1.0e2*iTier)/nTiers, "%.0f", "% ���������"); // ��������� ���������� ���������� ����� �����
//
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
 } // ����� ����� �� iTier
//
// === ������ ��������� ���������� � ������� ����� ������ ����� ������� ��� ====
//
 INT iGap,nGaps, n1,n2, CountTLD, // n1,n2 - ������ ����������� ����� ������� ���, CountTLD - ����� ������ � ���� ����������
     maxCountTLD = _minINT, minCountTLD = _maxINT, // max/min ������
     n1x,n2x, n1n,n2n; //  ��������� ������ ���� � ���� ���������������� ����������
 REAL averTLD=0.0; // ������-�������������� ������� ����� ������ ����� ������� ��� (ParamsTLD)
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( !PutParamsTLDOnTextFrame ) // ����� ���������� ������� ����� ������
  goto calc_TLD ; // ...�� ������� ���� ������ ���� ��������! -------------
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
 if( !flagCalcTLD ) // ���� paramsTLD �� ��������...
 {
  c_CalcParamsTLD(); // ��������� ��������� ������� ����� ������ �� �������� Tiers[][]
  flagCalcTLD = true ; // ���������� flag "paramsTLD ������������� �������� Tiers[][]"
 }
//
 sscanf( paramsTLD->Strings[0].c_str(), "%d", &nGaps ); // ����� ����������� (Gap) ������ � ���
//
 for( iGap=1; iGap<=nGaps; iGap++ ) // �� ����� ����������� (Gap) ����� ������� ���
 {
  if( iGap < nGaps ) // ����� ��������� ������ � $
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/%d|%d:", &n1,&n2,&CountTLD ); // ������� / ������ ���� / ����� ������ � ���� ����������
  else // ��������� ������ ������� "n/$|m"
  {
   sscanf( paramsTLD->Strings[iGap].c_str(), "%d/" SS_02 "|%d:", &n1,&CountTLD ); // ������� ���� / $ / ����� ������ � ���� ����������
   n2=n1+1;
  }
//
  if( CountTLD >= maxCountTLD ) // ���� ��� ����� ����� ������
  { maxCountTLD = max(maxCountTLD,CountTLD); n1x=n1; n2x=n2; } // ��������� ���� ���� | ��������� ���� ���� (��������� ������-��...)
//
  if( CountTLD < minCountTLD ) // ���� �in ����� ParamsTLD
  { minCountTLD = min(minCountTLD,CountTLD); n1n=n1; n2n=n2; } // ��������� ���� ���� | ��������� ���� ���� (��������� ������-��...)
//
  averTLD += (REAL)CountTLD; // ������-�������������� ������� ����� ������
 } // ����� ����� �� ����������� ����� ������� ���
//
// ���������� ������ ����������� � ������� ����� ������
//
 char szStatTLD[_512], // ������ ������ � ������� ����� ��������� ������ (ParamsTLD)
      szTemp[_128] ;
//
 n2n==nGaps ? sprintf( szStatTLD,"" SS_01 "TLD: 0/$: min=%d(%d/" SS_02 "), ", minCountTLD,n1n ) :
              sprintf( szStatTLD,"" SS_01 "TLD: 0/$: min=%d(%d/%d), ",        minCountTLD,n1n, n2n ) ;
//
 n2x==nGaps ? sprintf( szTemp, "max=%d(%d/" SS_02 "), ��.�����.=%.4g", maxCountTLD,n1x, averTLD / nGaps ) :
              sprintf( szTemp, "max=%d(%d/%d), ��.�����.=%.4g", maxCountTLD,n1x, n2x,   averTLD / nGaps ) ;
//
 strcat( szStatTLD, szTemp ); // ����������� ������ ��� ������ �� F2
//
// === ����� ��������� ���������� � ������� ����� ������ ����� ������� ��� =====
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
calc_TLD : // --- �����, ��� ����������� � ���� �������� ������ ----------------
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// --- ����� ������������ ������ �� ����� F2 � L_GP ----------------------------
//
 char szFormat[] = // ������ ������� ��� ������ ������ � ������ szOut ----------
"����������= %d, ���= %d, ���: ������= %d, ������= %d (%d)\
%s%s\
%s���������� �� �����/���� (min:max)= %d/%d:%d/%d\
%s������������� ���: Vn|Vt|Vnt= %.4g|%s|%s\
%s��.�����.���� ���= %.4g ������\
%s��.�����.����.���.����.= %.4g\
%s\0";
//
 snprintf( szOut,sizeof(szOut), szFormat, // ����� �� ������� szFormat � ������ szOut
//
 nOps, nEdges, nTiers, Tiers(c_GetTierFirstMaxOps(1,nTiers),0), c_GetTierFirstMaxOps(1,nTiers),
 SS_01,
//
 szStatTiers, // ������ ���������� ������ ���
 SS_01,
//
 Tiers(c_GetTierFirstMinOps(1,nTiers),0), c_GetTierFirstMinOps(1,nTiers),
 Tiers(c_GetTierFirstMaxOps(1,nTiers),0), c_GetTierFirstMaxOps(1,nTiers),
 SS_01,
//
 (REAL)sdOps / nOps, // Vn (%.4g)
// (REAL)sdTiers / nTiers // Vt
 nTiers==1 ? "???" : Format("%.4g",OPENARRAY(TVarRec,( (REAL)sdTiers/(nTiers-1) ))).c_str(), // Vt (%.4g) �� ������ �� 0 ��� nTiers=1
// (REAL)sdOps*sdTiers / (nOps*nOps), // Vnt
// (REAL)sdOps*sdTiers / ( nOps*nOps*(nTiers-1) ), // Vnt (%.4g)
 nTiers==1 ? "???" : Format("%.4g",OPENARRAY(TVarRec,( (REAL)sdOps*sdTiers/(nOps*(nTiers-1)) ))).c_str(), // Vnt (%.4g) �� ������ �� 0 ��� nTiers=1
 SS_01,
//
 StatTiers.AAL, // �������������������� ����� ����
 SS_01,
 StatTiers.averCOP, // �������������������� ����������� ������������ ���������� (Cooperative Operators Parallelismf)
//
 PutParamsTLDOnTextFrame ? szStatTLD : "" ); // ������ ���������� ������� ����� ��������� ������ (ParamsTLD) ... ����������� !!!
//
 F2->L_GP->Caption = szOut; // ����� �������� ���������� ��� �����
 F2->L_GP->Repaint(); // ������������� �������������� ���� L_GP
//
 strcpy( szStatTLD, "\n" );
 strcat( szStatTLD, szTemp ); // ����������� ������ ��� ������ � ���� ���������
//
 if( !PutParamsTLDOnTextFrame ) // ����� ���������� ������� ����� ������
  strcpy( szStatTLD, "\0" );
//
// ===== ����� ������������ ������ � �������� ������� (����) ===================
//
////////////////////////////////////////////////////////////////////////////////
 ReplaceEqualLengthSubstring( szOut, SS_01, "  \n" ) ; // �������� SS_01 �� "^^\n"
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
 return true ;
//
} // ----- ����� c_PutParamsTiers ----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char* __fastcall CreateUniqueFileName(char* FileName)
{ // �������� ����������� ����� ����� ��� ������������� ����� � ������, ��������� FileName
//
 if( !FileExists( FileName ) ) // ���� �� c���������...
  return FileName ;
//
 char OldFileName[_512], NewFileName[_512]="\0", Comma[]=".\0";
//
 Delay( 100 ); // ��� 0,1 ��� ���������������� ���������� ������������ ������ ����� �����
//
 strcpy( OldFileName, FileName ); // �������� ��� ����� ��������� � OldFileName
 OldFileName[ strrchr(OldFileName,Comma[0]) -
                     &OldFileName[0] ] = '\0'; // ���c�� ����� ������ '\0' (�������� ���������� ����� �����)
//
 strcpy( NewFileName, OldFileName ); // ��� �����
 strcat( NewFileName, Comma ); // �������� "." � �������� ����������� � ���������� ������
 strcat( NewFileName, PutDateTimeToString(1) ); // ���������� ������
 strcat( NewFileName, ExtractFileExt(FileName).c_str() ); // ���������� ��������� �����
//
 t_printf( "\n-W- ������������ ���� %s ��� ����������, ������������ �� %s -W-\n",
           FileName, NewFileName ); // ����� ��������� � ��������� ����
//
 return NewFileName ;
//
} // ------ ����� CreateUniqueFileName -----------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall OutRepeatComplete(char* s_Before, INT i, INT n, INT di,
                                  REAL Value, char* Fmt, char* s_After)
{ // ����� ������� ������������ ����� ��� ��������� Value �� ������� Fmt
// � ����� di ��� �������� i �� ������ n ��� ������� (i % n/di) # 0
// ������ ���������� �������� s_Before � s_After
//
 if( !(n/di) || // ������ �� 0 ������ !!!
       i%(n/di) ) // ���� ���� ������� �� ������� �� ������ - ������...
  return ;
//
 char _Fmt[_256] = "%s";
 strcat( _Fmt,Fmt ); // �������� Fmt
 strcat( _Fmt,"%s" ); // �������� %s
 SB0->Text = Format( _Fmt, OPENARRAY( TVarRec,(s_Before,Value,s_After) ) ).c_str();
 F1->SB->Repaint(); // ����������...
//
} // ----- ����� OutRepeatComplete ---------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CalcParamsTiers() // ������ �������������� ���������� ������ ���
{
//
 if( !flagExistsTiers ) // ������� Tiers[][] �� ����������...
 {
  DisplayMessage( "E", __FUNC__, messNotTiers, ERR_NOT_MASSIVE_TIERS ); // ������ ���������
  return ERR_NOT_MASSIVE_TIERS ;
 }
//
 REAL averWidth =  (REAL)nOps / nTiers, // ������� ������ �� ���� ������ ��� ����� �������� (��������)
      sumSqWidth = 0.0 , // ������������ ��������� �������
      sumOps = 0.0 , // ����� ���������� �� ������  ���
      sumICL = 0.0 , // ����� ��� ������������ ��������������� �� ������ �������
      xAxis,yAxis, xAxis_old = 0.0,yAxis_old = 0.0,
      averCOP = 0.0 ; // �������������������� ����������� ������������ ���������� (Cooperative Operators Parallelism)
 INT iTier, iOp ,
     nOpsOnTier, // ����� ���������� �� �����
     minOpsByTiers = _maxINT, maxOpsByTiers = _minINT , // ��� ������ min/max ���������� �� ������ ���
//
     sumDump = 0, sumEdges = 0 , // ��� ���������� ������� ����� ����;;
     OpFrom, OpTo, nOutEdges, iOutEdge; // ... �� �� ...
//
// =============================================================================
 for( iTier=1; iTier<=nTiers; iTier++ ) // �� ���� ������ ���
 {
//
  OutRepeatComplete(" * "__FUNC__"(): ", iTier, nTiers, 30, (1.0e2*iTier)/nTiers, "%.0f", "% ���������"); // ��������� ���������� ���������� ����� �����
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
//
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
    // t_printf( "-= %d %d=%d %d-%d", iTier, OpFrom,OpTo, sumDump,sumEdges );
   } // ����� ����� for( iOutEdge=1; iOutEdge<=nOutEdges; iOutEdge++ )
//
// =============================================================================
  } // ����� for( iOp=1; iOp<=nOpsOnTier; iOp++ )
//
 averCOP += (REAL)c_GetCountOpsOnTier(iTier) * ((REAL)c_GetCountOpsOnTier(iTier)-1.0); // �������������������� ����������� ������������ ���������� (Cooperative Operators Parallelism)
// 
 } // ����� for( iTier=1; iTier<=nTiers; iTier++ ) // ����� �� ���� ������ ���
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
 StatTiers.MinOpsByTiers = minOpsByTiers; // ���. ���������� �� ������
 StatTiers.MaxOpsByTiers = maxOpsByTiers; // ����. ...
//
 StatTiers.averCOP = averCOP / (REAL)nOps; // �������������������� ����������� ������������ ���������� (Cooperative Operators Parallelism)
//
} // ----- ����� c_�alcParamsTiers() -------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CountOfMemoryLuaUse() // ���������� ����, ������������ Lua
{
 return lua_gc( L, LUA_GCCOUNT, 0 ) * 1024 + lua_gc( L, LUA_GCCOUNTB, 0 ) ;
} // ----- ����� c_CountOfMemoryLuaUse -----------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
INT __fastcall c_CountOfFreeMemory() // ��������� � ����� �������� ���������� ������
{
//
#define WIDTH 10 // ������ ���� ��� ������ �����
#define DIV 1024 // ������� ���� � ���������
//
 MEMORYSTATUSEX stat_ex;
 stat_ex.dwLength = sizeof( stat_ex );
//
 GlobalMemoryStatusEx( &stat_ex );
//
 t_printf("\n������������ %*ld %% ������.",              WIDTH, stat_ex.dwMemoryLoad);
 t_printf("�����        %*I64d kB ���������� ������",    WIDTH, stat_ex.ullTotalPhys / DIV);
 t_printf("��������     %*I64d kB ���������� ������",    WIDTH, stat_ex.ullAvailPhys / DIV);
 t_printf("�����        %*I64d kB � ����� ��������",     WIDTH, stat_ex.ullTotalPageFile / DIV);
 t_printf("��������     %*I64d kB � ����� ��������",     WIDTH, stat_ex.ullAvailPageFile / DIV);
 t_printf("�����        %*I64d kB ����������� ������",   WIDTH, stat_ex.ullTotalVirtual / DIV);
 t_printf("��������     %*I64d kB ����������� ������",   WIDTH, stat_ex.ullAvailVirtual / DIV);
 t_printf("��������     %*I64d kB ����������� ������\n", WIDTH, stat_ex.ullAvailExtendedVirtual / DIV);
//
} // ----- ����� c_CountOfFreeMemory -------------------------------------------


//
#include "BruteForce_SPF.cpp" // ������ ������� ���� ��������� ��� (�� ���������������)
//

