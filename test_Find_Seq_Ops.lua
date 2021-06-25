--
-- ���� 2021
--
--projectName = "abc_r" -- ��� ������� 
projectName = "abc1_r" 
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
--
--
local function find_SerOps( Op ) -- ���� ������� ���������� ������� � Op
local Tier = GetTierByOp( Op ) -- �������� Op ��������� �� ����� Tier
local CIE = GetCountInEdgesByOp( Op ) -- ����� �������� ��� � �������� Op
local COE = GetCountOutEdgesByOp( Op ) -- ����� ��������� ��� �� ��������� Op
local nex_CIE,naxt_COI
-- ���� �������� - ������ ����������� �������
if not ((Tier==1 and COE==1) or -- ���� 1-� ���� ���
           (Tier~=1 and COE==1 and CIE~=1)) then -- ���� �� 1-� ���� ���
 do return end
end 
--
outStr =  string.format( "%d(%d/%d)", Op,CIE,COE )
OutLine( "\n..... ��������� ������ �������= " .. outStr  )
--
::contin::
--
next_Op =  GetNumbOutEdgeByOp( 1, Op  ) -- ���������� �� ����� ���� (������������), ��������� �� Op
next_CIE = GetCountInEdgesByOp( next_Op ) -- ����� �������� ��� � �������� next_Op
next_COE = GetCountOutEdgesByOp( next_Op ) -- ����� ��������� ��� �� ��������� next_Op
--
outStr = outStr .. string.format(" => %d(%d/%d)", next_Op,next_CIE,next_COE) -- �������
OutLine( outStr )
--
if  next_CIE==1 and  next_COE==1 then -- ��������� �������
 Op = next_Op
 goto contin
end
--
OutLine( ".....  ������� �������� �� ���������= " .. string.format(" %d(%d/%d)",  next_Op,next_CIE,next_COE))
--
end -- ����� ������� find_SerOps
--
--
----------------------------------------------------------------------------------------------------------------------------------------------
--=== ��������� MAIN =========================================================
----------------------------------------------------------------------------------------------------------------------------------------------
local i
--
ClearTextFrame() -- ������� ��������� ������
--
CreateTiersByEdges(  projectName .. ".gv" )  -- ������� ��� �� ���
PutTiersToTextFrame()
-- PutEdgesToTextFrame()
PutParamsTiers() 
ClearDiagrArea() 
DrawDiagrTiers()
--
DelayMS( -1 )
--
for i=1,GetCountOps(),1 do
 find_SerOps( GetNumbOp( i ))  -- ��������� ���������
end 
--
SoundPlay("rooster.wav")-- ����� ���������, ��� ������ �������
--
-- ����� main






