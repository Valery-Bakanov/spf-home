--
-- 29.03.2021 = "������������" ��� ��� ���������� ����� ������
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
function SearchToOp(fromTier, toTier)
-- ���� (����� fromTier-toTier) � ���������� ����, �� �������

-- ����������� ����������� �������� (�� ����� -> �����. 0)
local minH=1000000000 -- ��� ������ min
local i,H,sTier
--
-- ���� �� ����� � ������� H �������, ��� ������� - border (����.) ?
-- ���� ��� ������ � H<border, �� ���������� 0
for i=fromTier+1,toTier -- �� ������ ���
do
H=GetCountOpsOnTier(i) -- ������ ����� i
--
if H<border then -- ����� ������ �������� - ��� ���������!
 goto succ end -- ����� �� �����, ��� ����� ���� ���� ������  
--
end -- ����� ����� �� i
-- 
-- ���� return �� �������. � �������, ���� ��� ��������� � do/end 
do return 0 end -- ��� �� ������ ����� � H<border...
::succ:: -- ����� ���� ���� ���� � H<border !!!
--
--
for i=fromTier+1,toTier -- �� ������ ���
do
H=GetCountOpsOnTier(i) -- ����� ���������� �� ����� i  
--
if H>=border -- ������ �������� = �����������!
then goto cont_i end -- ��� �� ����� ���� �� i  
--
-- ������ ������� ������� H<border (��� ��� � �����!)
-- ���� ���� � ����������� �������
if H<minH then
 minH=H
 sTier=i -- ��� ���� c min ���������� �� ��
end -- ����� ������ min
--
::cont_i:: -- ����������� ���� 
end -- ����� �����  �� i
--
return sTier -- ���������� ���������...
--
end -- ����� ������� SearchToOp()

--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
                 
local function Visual() -- ������������ ��������� ���
AddLineToTextFrame("=============================================================================")  
PutTiersToTextFrame() 
PutParamsTiers() 
ClearDiagrArea() 
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

for i=1, 1000000000,1 do -- ���� �� �������������� ������ ����������
--
projectName = "mnk_5" -- ��� ��������������� ���-����� 
if i%2==0 then
projectName = "squa_equ_2.pred"
elseif i%3==0 then
projectName = "slau_3"
elseif i%4==0 then
projectName = "slau_4"
elseif i%5==0 then
projectName = "m_matr_4"
end
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
averH=1.0 * nOps / nTiers -- ������� ���. ��� 
--
print ("nTiers=" .. nTiers .. ", nOps=" .. nOps .. ", �����.����./����=" .. averH)  
--
CountMovesZeroing() -- �������� ����� �����������
--
-- ����� ������ �� ��������, ������� ���������� for 
for iTier=1,nTiers,1 -- !!! �� ���� ������, � ������� ���������� ���� �������� !!!
do 
--
if GetCountOpsOnTier(iTier) == 0 -- ������ ���� �����������!
then goto cont_iTier end 
--
-- ���� �� ���������� �� ����� ��������� repeat/until, ���
-- ������� ������� ����� ���������� (��� � Lua �����������)
--
--border = averH -- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
border = GetCountOpsOnTier(iTier) -1 -- !!! ����� ������� !!!!!!!!!!!!!
--
j=1 -- ������ ����� �� ���������� �� ����� iTier
repeat 
 iOp=GetOpByNumbOnTier (j,iTier) -- ����� ���������
 fromTier=GetMinTierMaybeOp (iOp) -- '����' ���������� iOp
 toTier=GetMaxTierMaybeOp (iOp) -- '���' ���������� iOp
--
-- print("=-= iOp=" .. iOp .. ", fromTier=" ..  fromTier .. ", toTier=" .. toTier)
--
if toTier == fromTier then -- ���� �������� ����������� "����" ������...
goto cont_j end
--
newTier=SearchToOp(fromTier,toTier) -- �������� ����� ����������� ������������
-- ���� ��� ����������� - ������������ 0
--
if newTier == 0 then -- ���� = 0, �� ������ ������������...
goto cont_j end
--
-- ������������ ��������� iOp �� ���� newTier
print( string.format("#iOp=%d fromTier=%d toTier=%d", iOp, fromTier, toTier )) 
--
AddLineToTextFrame("\n�����������: iOp=".. iOp..", fromTier=".. fromTier ..", toTier="..toTier.. ", newTier="..newTier.." [Movies="..GetOpsMoves().."]")  
MoveOpTierToTier(iOp, newTier) -- ���������� ������������
--
Visual() -- ������������ ��������� ���
SoundPlay("kuku.wav") -- ��������� ���� �� �����  
--
::cont_j::
--
j=j+1 -- ����� ����� ��������� �� ����� iTier
--
N=GetCountOpsOnTier(iTier) -- ������� ����� ���������� �� ������ iTier
--
until j>N -- ���� �� ��������� ��� ��������� �� ������ iTier
--
::cont_iTier:: -- �� ����� ���� �� ITier
end -- ����� �� ������ ��� 
--
--PutTiersToTextFrame() -- �������� ���
--
--DelayMS( -3 )
--
AddLineToTextFrame( "\nMoves=" .. GetOpsMoves() )
print( "Moves=" .. GetOpsMoves() ) -- ����� �����������
--
SoundPlay("rooster.wav") -- ����� ���������, ��� ������ �������
--
end -- for i=1, 1000000000,1 do
--
SoundPlay("rooster.wav")-- ����� ���������, ��� ������ �������
--
-- ����� main 

