--
-- 31.07.2023
--
--projectName = "abc_r" -- ��� ������� 
--
projectName = "squa_equ_2"  -- ��� ������� 
--projectName = "squa_equ_2.pred"
--
--projectName = "polinom_10-1"
--projectName = "polinom_10-2"
--
--projectName = "max-1_mass-8.pred"
--projectName = "max-2_mass-8.pred"
--
--projectName = "slau_2"
--projectName = "slau_3"
--projectName = "slau_4" 
--projectName = "slau_5"
--projectName = "slau_7"
--projectName = "slau_10"
--
--projectName = "doubling_32"
--
--projectName = "m_matr_2"
--projectName = "m_matr_3"
--projectName = "m_matr_5"
--projectName = "m_matr_7"
--projectName = "m_matr_10"
--
--projectName = "m_matr_vec_2"
--projectName = "m_matr_vec_3"
--projectName = "m_matr_vec_5"
--projectName = "m_matr_vec_7"
--projectName = "m_matr_vec_10"
--
--projectName = "fibonn_10"
--projectName = "tribonn_10"
--projectName = "quadronn_10"
--
--projectName = "mnk_5"
--projectName = "mnk_10"
--projectName = "mnk_15"
--projectName = "mnk_20"
--
--projectName = "mnk-2_5"
--projectName = "mnk-2_10"
--projectName = "mnk-2_15"
--projectName = "mnk-2_20"
--
--projectName = "korr_5" 
--projectName = "korr_10"
--projectName = "korr_15"
--projectName = "korr_20"
--
--projectName = "e17_o11_t6"
--projectName = "e313_o206_t32"
--projectName = "e2367_o1397_t137"
--projectName = "e451_o271_t30"
--projectName = "e916_o624_t89" 
--projectName = "e17039_o9853_t199"
-- ===
--
local function f_Visual() -- ������������ ��������� ���
AddLineToTextFrame("=============================================================================")  
PutTiersToTextFrame() 
PutParamsTiers() 
ClearDiagrArea() 
DrawDiagrTiers()
end -- ����� ������� f_Visual()
--
local function testAllOps() -- �������������� ��� ������� ���
--
f_Visual()  -- ������������ ���
--
nOps  = GetCountOps() -- ����� ����������  � ���
nTiers = GetCountTiers() -- ����� ������ � ���
--
ListOpsVar={}  -- ������ ���������� � ��������� �������������� (1D ������ ������)
nOpsVar=0 -- ����� ���������� � ��������� ��������������
--
for iTier=1,nTiers do -- ���� �� ������ ��� � 1 �� ��������� ����
 for jOp=1,GetCountOpsOnTier(iTier) do  -- ���� �� ���������� �� ����� iTier
  nOp = GetOpByNumbOnTier(jOp,iTier) -- �������� ����� ��������� #iOp �� ����� iTier
--
 min_T = GetMinTierMaybeOp(nOp) -- min / max ������ ������, ��� ��������� ����� ������������� �������� Op 
 max_T = GetMaxTierMaybeOp(nOp)
--
dT = max_T - min_T -- ������������� ��������� Op
 --
if(dT~=0) then
-- OutLine( string.format("#Op=%d   i/j=%d/%d    TT-min|max/dt=%d|%d/ %d", nOp, iTier,jOp, min_T,max_T,dT )  )
--
 nOpsVar=nOpsVar+1 -- ���������� � Lua - � ������� !..
 ListOpsVar[nOpsVar]={} -- �������� ������ � 1D-������� ListOpsVar (������ ��� 2D-������)
 ListOpsVar[nOpsVar][1]=nOp -- ��������� ������ � ������� ListOpsVar[][]
 ListOpsVar[nOpsVar][2]=min_T
 ListOpsVar[nOpsVar][3]=max_T
--
end -- ����� �� ��������� �������������
--
 end -- ����� ����� �� ���������� �� ����� iTier
end -- ����� ����� �� ������ ���
--
OutLine( string.format("\n-= H=%d   W=%d   CV=%.3g   AverEdges=%.3g =-\n", nTiers,
                                           CalcParamsTiers(2), -- W (������ ���)
                                           CalcParamsTiers(6), -- CV
                                           CalcParamsTiers(9) ) ) -- ���������� �� ���� ���
 --                                          
 table.sort( ListOpsVar, function (a,b) return (a[1]<b[1]) end ) -- ����������� ������� �� ������� ��������
 --
 for i=1,#ListOpsVar do -- �� ���� ������� ������� ListOpsVar
  OutLine( string.format("#%d Op=%d  T-min/max=%d/%d",  i,ListOpsVar[i][1],ListOpsVar[i][2],ListOpsVar[i][3] ) )
 end
--
end -- ����� ������� testAllOps()
--                                
----------------------------------------------------------------------------------------------------------------------------------------------
--=== ��������� MAIN =========================================================
----------------------------------------------------------------------------------------------------------------------------------------------
--
ClearTextFrame() -- ������� ��������� ������
--
CreateTiersByEdges( projectName .. ".gv" ) -- ������� ��� �� ��� � ������� �����
f_Visual()  -- ������������ ���
--
testAllOps() -- �������������� ��� ���
--
MoveOpTierToTier(100,2) -- ����������� ��������
testAllOps() -- �������������� ��� ���
--
MoveOpTierToTier(100,3) -- ����������� ��������
testAllOps() -- �������������� ��� ���
--
MoveOpTierToTier(100,4) -- ����������� ��������
testAllOps() -- �������������� ��� ���
--
MoveOpTierToTier(100,5) -- ����������� ��������
testAllOps() -- �������������� ��� ���
--
