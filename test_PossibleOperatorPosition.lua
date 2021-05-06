--
-- ������������  PossibleOperatorPosition  (��� 2021)
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
--projectName = "m_m_10P"
--
--projectName = "e17_o11_t6"
--projectName = "e313_o206_t32"
--projectName = "e2367_o1397_t137"
--projectName = "e451_o271_t30"
--projectName = "e916_o624_t89" 
--projectName = "e17039_o9853_t199"
--
local function Visual() -- ������������ ��������� ���
--AddLineToTextFrame("=====================================")  
PutTiersToTextFrame() 
ClearDiagrArea() 
PutParamsTiers() 
DrawDiagrTiers()
end -- ����� ������� Visual()
--
function UnloadTier( Tier ) -- ��������� ����� Tier 
-- ����� �������� ����� ���������� � ���� �� ����� ������������ ����� ����
-- (��� ���������� ������ ����� �������� WidthMax)
-- ���������� ����� ������������� ��������� ������
local Ops ={} -- ������� �������� #����. ����� ��������� �� ����
local i,j,Op, nOpsAtTier, Quet, Rem, nTiersUpper,nOpsAtTier,nOpsBelow,jOpAtTier
local Width = WidthMax -- �������� � ��������� ������ WidthMax
--
nOpsAtTier = GetCountOpsOnTier(Tier) -- ����� �������� �� ����� Tier
-- ���� �� ����� WidthByWidth - ������ ���� ���������� �� ����
if nOpsAtTier <= Width then -- �� ���� ������ ������...
--OutLine ( string.format("\n--- UnloadTier: Tier= %d Width=%d nOpsAtTier= %d ===>", Tier,Width,nOpsAtTier  ))
 return 0  -- �� ������ ����� �� ���� ������� ��� ������ 
end -- ����� nOpsAtTtier <= Width
--------------------------------------------------------------------------------------------------------------------------------------------------
-- 1 ����. �������� � Ops{} ��������� ��� �������� �� ����� ����������� ����� ��� ������
-- ��������� - ����������� ������ �� ����� ���������, �������� ��������� Width ����
-- �� ������ ����������� ��������� ������������� ������ ���� � ��������� �������
--------------------------------------------------------------------------------------------------------------------------------------------------
nOpsBelow = nOpsAtTier - Width -- �� ����� Tier ������� Width ����������, ��������� - ���� (below)!
--
--Quet = math.floor(nOpsBelow / Width) -- �����, ������� �� ������� nOpsBelow �� Width
Quet = nOpsBelow // Width  -- ������������� �������, ������� �� ������� nOpsBelow �� Width
Rem = nOpsBelow % Width -- �����, ������� �� ����� �� �������
--
--OutLine ( string.format("\n--- UnloadTier: Tier= %d nOps= %d|%d Width=%d Quet= %d Rem= %d\n", Tier,nOpsAtTier,nOpsBelow,Width,Quet,Rem  ))
--
-- ������ � Ops{} ����� ��������� ����������� ��� Tier ������ (i - ����� �����)
--
jOpAtTier=1 -- �������� � ������� ��������� �� ����� Tier
--
if Quet > 0 then 
for i=1,Quet,1 do -- �� ������ � WidthMax ���������� �� ������ �����
 Ops[i] = {} -- ������� i-��� ������ Ops[][]
 for j=1,Width,1 do -- �� ���������� �� �����
  Op=GetOpByNumbOnTier(jOpAtTier,Tier) -- ����� ��������� �� ����� Tier
  Ops[i][j] =  Op -- ��������� � �������� Ops[i][j] �������� Op
  jOpAtTier  = jOpAtTier +1 -- ������� � ���������� ��������� �� ����� Tier
 end -- ����� for j=1,Width,1
end -- ����� for i=1,Quet,1
end -- ����� if Quet > 0
--
if Rem > 0 then -- ������ ���  Rem > 0
 Ops[Quet+1] = {}-- ������� ��������� ������ Ops[][]
 for j=1,Rem,1 do -- �� ������� �� �������
  Op=GetOpByNumbOnTier(jOpAtTier,Tier) -- ����� ��������� �� ����� Tier
  Ops[Quet+1][j] =  Op -- ��������� � �������� Ops[Ouet+1][j] �������� Op
  jOpAtTier  = jOpAtTier +1 -- ������� � ���������� ��������� �� ����� Tier
 end -- ����� for j=1,Rem,1 
end -- ����� Rem > 0
----------------------------------------------------------------------------------------------------------------------------------------------------------------
-- 2 ����. �������� ��������� Width � ����� ��������� ������� ��������������� ���������� �� ������
----------------------------------------------------------------------------------------------------------------------------------------------------------------
--
----------------------------------------------------------------------------------------------------------------------------------------------------------------
-- 3 ����. ������ ����� ��� ������ ������  � ��������� �� Ops{} ��������� �� ���
----------------------------------------------------------------------------------------------------------------------------------------------------------------
--
if Quet > 0 then 
for i=1,Quet,1 do -- �� ����������� ������ c Width ����������� (��� ����� �����)
 AddTier(Tier+i-1) -- ������� ������ ���� ��� Tier
  OutLine("\n===>������ ����� ���� ��� ������="..Tier+1)
 for j=1,Width,1 do -- �� ������� ���������� �� �����
  MoveOpTierToTier(Ops[i][j],Tier+ i ) -- ������� ���������� �� ���� Tier+i
  OutLine("��������="..Ops[i][j].." � �����="..GetTierByOp(Ops[i][j]).."  ��������� �� ����="..Tier+ i ) -- ���������� � �������� ���������
 end -- ����� j=1,Width,1
end -- ����� i=1,Quet,1
end -- if Quet > 0
--
if Rem > 0 then -- ������ ��� Rem > 0
 AddTier(Tier+Quet ) -- ������� ������ ���� ���� ����� Tier+Quet
 OutLine("\n--->������ ����� ���� ��� ������="..Tier+Quet)
 for j=1,Rem,1 do -- �� ���������, �������� ������
  MoveOpTierToTier(Ops[Quet+1][j],Tier+Quet+1 ) -- ��������� ��������� �� ���� Tier+Quet+1
  OutLine("��������="..Ops[Quet+1][j].." � �����="..GetTierByOp(Ops[Quet+1][j]) .. " ��������� �� ����="..Tier+Quet+1 ) -- ���������� � �������� ���������
 end -- ����� for j=1,Rem,1 
end -- ����� Rem > 0
--
Ops = nil -- ���������� ������� Ops
--
--Visual() -- ������������ ��������� ���
--
if Rem == 0 then
 return Quet -- ���� ������� Quet ������ ��� ������ ������ Tier
else 
 return Quet+1 -- ���� ������� Quet+1 ������ ��� ������ ������ Tier 
end -- ����� Rem == 0
--
end -- ����� ������� UnloadTiers( ) ----------------------------------------------------------------------------------------
--
function Calc_POP( ) -- ���������� ������������� PossibleOperatorPosition
local nTiers=GetCountTiers() -- ����� ����� ������ (��� �������� �����)
local nOps=GetCountOps()  -- ����� ����� ���������� (��� �������� �����)
--
for iGap=0,nTiers-1 do -- �� ����� ����������� ����� ������� ( iGap - ������� ���� ���������� )
--
OutLine(  "\n==== iGap= "  .. iGap .. " ====="  )
--
sumPOP = 0 -- ����� ��������� �����������
 for iOp=1,nOps do -- �� ���� ����������
 Op = GetNumbOp( iOp ) -- ����� ���������
--
 minTier = GetMinTierMaybeOp( Op )
 maxTier =  GetMaxTierMaybeOp( Op )   -- ���� ����� - �� ���������� !!!
--
-- if GetTierByOp( Op ) >= iGap+1 and minTier = maxTier then -- ���� ����� ��������� ����, ��� ������������� �� ����� !!!
--  goto no_sum 
-- end 
--
OutLine( "==== Op= " .. Op .. "   "  ..  minTier .. " - " .. maxTier  .. "  Tier= " ..  GetTierByOp( Op ) )
--
 if minTier >= iGap and maxTier <= iGap then -- iGap ��������� ������ ��������� minTier-maxTier
  sumPOP = sumPOP + 1 -- ���������
 end -- ����� if
--
::no_sum:: -- ���������� �� ���������������
--
 end  -- �����  for iOp=1,nOps do
--
OutLine(  "iGap="  .. iGap .. " | " ..  iGap+1 .. "   " .. "sumPOP= " .. sumPOP )
--
SoundPlay("kuku.wav")
-- 
end -- ����� for iGap=1,nTiers-1 do   
--
end -- ����� �������  Calc_POP  -----------------------------------------------------------------------
--
-- MAIN - ������� -------------------------------------
--===================================
--
ClearTextFrame()
--
CreateTiersByEdges( projectName .. ".gv" ) -- ������� ��� �� ��� � ������� �����
--
--PutEdgesToTextFrame()
--PutTiersToTextFrame()
--
Visual() -- ������������ ������
--
PutTLDToTextFrame() -- ������ ������� ����� ������
ClearDiagrArea() -- �������� ���� �������
DrawDiagrTLD() -- ������� � ���� ���������� ���������
--
OutLine( "\n" ) 
--
Calc_POP() --!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
--
SoundPlay("rooster.wav") -- ����� ���������, ��� ������ �������
--
-- ����� main
