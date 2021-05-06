--
-- ���������� � ������������� ���������� �� ������ ���;  2020 )
--
--projectName = "abc_r" -- ��� ������� 
--
projectName = "squa_equ_2"   
--projectName = "squa_equ_2.pred"
--
--projectName = "polinom_10-1"
--projectName = "polinom_10-2"
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
--

--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------

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
nTiers=GetCountTiers() -- ����� ����� ������
nOps=GetCountOps() -- ����� ����� ���������� 
--
OutLine("\n") 
--
sVarT=0 -- ����� ��������  ���������� ���������� ���������� �� ���� ������ nTiers
--
for iTier=1,nTiers -- !!! �� ���� ������ ������ ����
do
sVar=0 -- ����� �������� ���������� ���������� ���������� �� ����� iTier
nOpsOnTier=GetCountOpsOnTier(iTier) -- ����� ���������� �� ����� iTier
out2="" -- ������ ��� ������������ ������ �� ���������� ������� �����
--
for jOp=1,nOpsOnTier -- !!! �� ���� ���������� �� ����� Tier
do
iOp=GetOpByNumbOnTier (jOp,iTier) -- ����� ��������� jOps �� ����� iTier
fromTier=GetMinTierMaybeOp (iOp) -- ������� ���� ���������� ���������� iOp
toTier=GetMaxTierMaybeOp (iOp) -- ������ ���� ����������� ���������� iOp
--
--out2r=outStr..string.format(" %d/%d:%d", iOp,fromTier,toTier) -- ��������� ������ � ������ ��������� �� ����� Itier
out2=out2..string.format(" %d{%d}", iOp,toTier-fromTier) -- ��������� ������ � ������ ��������� �� ����� Itier
--
sVar=sVar+(toTier-fromTier) -- ��������������� ����� �������� �� ����� iTier
end -- ����� �� jOp
--
sVarT=sVarT+sVar --  ����� �� ���� ������
--
out1=string.format("%d|%d{av_var=%g}",  iTier,nOpsOnTier,sVar / nOpsOnTier) -- ������ ������ ������ ��� ������� �����
out2=out1 .. out2 -- ������ ������ ������ ��� ������� �����
OutLine(out2) -- ����������� ������ ������
end -- ����� �� iTier
--
OutLine("\n������� �� ������=     " .. string.format("%g", sVarT / nTiers) );
OutLine("������� �� ���� ���= " .. string.format("%g", sVarT / nOps) );
--
SoundPlay("rooster.wav") -- ����� ���������, ��� ������ �������
--
-- ����� main 

