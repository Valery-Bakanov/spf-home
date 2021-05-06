--
-- ������ ������� � ��������������� �� � ������;  2021 
--
--projectName = "abc_r" -- ��� ������� 
--
--projectName = "squa_equ_2"
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
projectName = "slau_10"
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
--
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
--
local function f_ICL()
-- ���������� ������������ ��������������� ������������� ������ �� ������ ������� -  Irregularity Coefficient Lorenz (ICL)
local nTiers=GetCountTiers() -- ����� ����� ������ � ���
local nOps=GetCountOps() -- ����� ����� ���������� � ���
--
OutLine("\n������ �������")
OutLine("==============\n")
--
sOps = 0 -- ����� ���������� �� ������  ���
sICL = 0 -- ����� ��� ������������ ���������������
--
for iTier=0,nTiers -- !!! �� ���� ������ ��� ������ ����
do
sOps = sOps + GetCountOpsOnTier(iTier) -- ����������� ����� ����������
xAxis =  iTier / nTiers -- ��� �������  (���� �������)
yAxis =  sOps / nOps -- ��� �������  (���� �������)
--
if iTier == 0 then -- ������ ����� - �������
 sOps =  0  xAxis = 0  yAxis = 0
else
 sICL = sICL + 0.5 * ( yAxis + yAxis_old ) * ( xAxis - xAxis_old )  -- ������� ��������
end
--
OutLine( string.format("#%-d   x=%-.2f%%   y=%-.2f%%   (%-+.2f%%)", iTier, 100*xAxis, 100*yAxis, 100*(yAxis-xAxis) ) )
--
xAxis_old = xAxis -- �������� ���������� ��������
yAxis_old = yAxis
--
end -- �����  for iTier=1,nTiers
--
ICL = ( sICL - 0.5  ) / 0.5 -- (����� ����������� ��������) �� ��������� � �����������
--
OutLine( string.format("\n����������� ���������������= %g (%g)", ICL,CalcParamsTiers(6) )) 
--                                                                                                                
return ICL
--
end -- ����� ������� f_ICL
--
local function Visual() -- ������������ ��������� ���
AddLineToTextFrame("=============================================================================")  
PutTiersToTextFrame() 
PutParamsTiers() 
ClearDiagrArea() 
DelayMS( -1  )
DrawDiagrTiers()
DelayMS( -1  )
end -- ����� ������� Visual()

--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------

-- MAIN - ������� -------------------------------------
--=================================
local H,iTier,j,nTiers,nOps,iOp, fromTier,toTier,newTier
--
ClearTextFrame() -- �������� ��������� ����
--
--ReadEdges(  projectName .. ".gv" )  -- ������ ���� �������� �����
--
CreateTiersByEdges( projectName .. ".gv" ) -- ������� ��� �� ���
--
Visual() -- ������������ ��������� ���
--
f_ICL() -- ���������� ������ ������� � ������������ ��������������� ������������� ICL
--
SoundPlay("rooster.wav") -- ����� ���������, ��� ������ �������
--
-- ����� main 

