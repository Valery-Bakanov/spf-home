--
-- 17.04.2021
--projectName = "squa_equ_2"  -- ��� ������� 
--projectName = "squa_equ_2.pred"
--
--projectName = "max-1_mass-8.pred"
--projectName = "max-2_mass-8.pred"
--
--projectName = "slau_2"
projectName = "slau_3"
--projectName = "slau_4" 
--projectName = "slau_5"
--projectName = "slau_7"
--projectName = "slau_10"
--
--projectName = "doubling_32"
--
--projectName = "m_matr_2"
--projectName = "m_matr_3"
--ojectName = "m_matr_5"
--prprojectName = "m_matr_7"
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
local function f_Visual() -- ������������ ��������� ���
AddLineToTextFrame("=============================================================================")  
PutTiersToTextFrame() 
PutParamsTiers() 
ClearDiagrArea() 
DrawDiagrTiers()
end -- ����� ������� f_Visual()
--
local function f_OpsOnTiers() -- ������� ��� ������ Lua
OpsOnTiers={} -- ������ ������ 1D-������ OpsOnTiers 
for iTier=1,GetCountTiers() do -- �� ������ ���
   OpsOnTiers[iTier]={} -- ������ iTier-��� ������ 2D-������� OpsOnTiers
   for nOp=1,GetCountOpsOnTier(iTier) do -- �� ���������� ������� ���������� �� ����� iTier  
      OpsOnTiers[iTier][nOp]=GetOpByNumbOnTier(nOp,iTier) -- ����� ����� ��������� nOp
end end -- ����� ������ for �� iTier � for �� nOp
end -- ����� ������� f_OpsOnTiers(0
--
local function f_OutTiers() -- ����� ��� �� ������� OpsOnTiers � ��������� �����
OutLine( "\n--- ������ ��� = " .. GetCountTiers() .. " ---") -- ����� ���������
for iTier=1,GetCountTiers() do -- �� ������ ���
   local outStr = string.format( "%d|%d:", iTier,GetCountOpsOnTier(iTier) ) -- ������ ������=����� ���
   for nOp=1,GetCountOpsOnTier(iTier) do -- �� ���������� ������� ���������� �� ����� iTier  
      OpsOnTiers[iTier][nOp]=GetOpByNumbOnTier(nOp,iTier) -- ����� ����� ��������� nOp
      outStr = outStr .. string.format(" %d", OpsOnTiers[iTier][nOp] ) -- ��������� ������ ����������
   end -- ����� �����  �� nOp - �� ���������� ������� ���������� �� ����� iTier
OutLine( outStr ) -- ����� ������=����� ���
end -- ����� �����  �� iTier - �� ������ ���
end -- ����� ������� f_OutTiers()
--
local function f_AllOpsDown() -- ���������� ��� ��������� ��� ����� ���� �� ������� ���
local  iTier,iOp -- ��������� ���������� (��������� ������ ������ �������)
CountMovesZeroing() -- �������� ������� ���������
for iTier=GetCountTiers(),1,-1 do -- �� ������ ����� �����
 for iOp=GetCountOpsOnTier(iTier),1,-1 do -- �� #���������� �� ����� ������ ������
  Op=GetOpByNumbOnTier(iOp,iTier) -- ����� ���������
  out = MoveOpTierToTier(Op,GetMaxTierMaybeOp(Op)) -- ��������� Op
--
if out ==1 then  -- ���� ����������� �������...
 OutLine( Op .. "=>" .. GetMaxTierMaybeOp(Op) .. " |"  .. out .. "| " .. GetOpsMoves() )
 f_Visual() -- ������������ ������
 DelayMS( 1000 )
end 
--
end end -- ����� ����� �� iOp / ����� ����� �� iTier
--
return GetOpsMoves() -- ����� ��������� ����������
-- 
end -- ����� ������� f_AllOpsDown
--
local function f_AllOpsTop() -- ���������� ��� ��������� ��� ����� ���� �� ������� ���
local  iTier,iOp -- ��������� ���������� (��������� ������ ������ �������)
CountMovesZeroing() -- �������� ������� ���������
for iTier=1,GetCountTiers(),1 do -- �� ������ ������ ����
 for iOp=GetCountOpsOnTier(iTier),1,-1 do --�� #���������� �� ����� ������ ������
  Op=GetOpByNumbOnTier(iOp,iTier) -- ����� ���������
  MoveOpTierToTier(Op,GetMinTierMaybeOp(Op)) -- ��������� Op
end end -- ����� ����� �� iOp / ����� ����� �� iTier
--
return GetOpsMoves() -- ����� ��������� ����������
-- 
end -- ����� ������� f_AllOpsTop


----------------------------------------------------------------------------------------------------------------------------------------------
--=== ��������� MAIN =========================================================
----------------------------------------------------------------------------------------------------------------------------------------------
--
ClearTextFrame() -- ������� ��������� ������
--
CreateTiersByEdges( projectName .. ".gv" ) -- ������� ��� �� ��� � ������� �����
--CreateTiersByEdges_Bottom( projectName .. ".gv" ) -- ������� ��� �� ��� � ������ �����
--
f_Visual() -- ������������ ������
--
f_OpsOnTiers() -- ������� ��� ������ Lua
--
f_OutTiers() -- ������ ���
--
OutLine( "\n--- ���������� ���� ---" )
OutLine( "����� ����������� - 1-� ��� = " .. f_AllOpsDown() ) -- ���������� ��� ��������� ����
OutLine( "����� ����������� - 2-� ��� = " .. f_AllOpsDown() ) -- ���������� ��� ��������� ����
f_OutTiers() -- ������ ���
--
--OutLine( "\n--- ���������� ����� ---" )
--OutLine( "����� ����������� - 1-� ��� = " .. f_AllOpsTop() ) -- ���������� ��� ��������� �����
--OutLine( "����� ����������� - 2-� ��� = " .. f_AllOpsTop() ) -- ���������� ��� ��������� �����
--f_OutTiers() -- ������ ���
--


--OutLine( "\n" .. f_AllOpsDown() .. " " .. f_AllOpsTop()  ) --
--
