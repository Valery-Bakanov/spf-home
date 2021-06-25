--
-- июнь 2021
--
--projectName = "abc_r" -- им€ проекта 
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
local function Visual() -- визуализаци€ состо€ни€ яѕ‘
AddLineToTextFrame("=============================================================================")  
PutTiersToTextFrame() 
PutParamsTiers() 
ClearDiagrArea() 
DelayMS( -1  )
DrawDiagrTiers()
DelayMS( -1  )
end -- конец функции Visual()
--
--
local function find_SerOps( Op ) -- ищет цепочки операторов начина€ с Op
local Tier = GetTierByOp( Op ) -- оператор Op находитс€ на €русе Tier
local CIE = GetCountInEdgesByOp( Op ) -- число вход€щих дуг в оператор Op
local COE = GetCountOutEdgesByOp( Op ) -- число выход€щих дуг из оператора Op
local nex_CIE,naxt_COI
-- ищем оператор - начало операторной цепочки
if not ((Tier==1 and COE==1) or -- если 1-й €рус яѕ‘
           (Tier~=1 and COE==1 and CIE~=1)) then -- если не 1-й €рус яѕ‘
 do return end
end 
--
outStr =  string.format( "%d(%d/%d)", Op,CIE,COE )
OutLine( "\n..... ¬озможное начало цепочки= " .. outStr  )
--
::contin::
--
next_Op =  GetNumbOutEdgeByOp( 1, Op  ) -- операторов на конце дуги (единственной), исход€щей из Op
next_CIE = GetCountInEdgesByOp( next_Op ) -- число вход€щих дуг в оператор next_Op
next_COE = GetCountOutEdgesByOp( next_Op ) -- число выход€щих дуг из оператора next_Op
--
outStr = outStr .. string.format(" => %d(%d/%d)", next_Op,next_CIE,next_COE) -- цепочка
OutLine( outStr )
--
if  next_CIE==1 and  next_COE==1 then -- продолжим цепочку
 Op = next_Op
 goto contin
end
--
OutLine( ".....  ÷епочка окончена на операторе= " .. string.format(" %d(%d/%d)",  next_Op,next_CIE,next_COE))
--
end -- конец функции find_SerOps
--
--
----------------------------------------------------------------------------------------------------------------------------------------------
--=== ѕ–ќ√–јћћј MAIN =========================================================
----------------------------------------------------------------------------------------------------------------------------------------------
local i
--
ClearTextFrame() -- очистка тестового экрана
--
CreateTiersByEdges(  projectName .. ".gv" )  -- создать яѕ‘ по »√ј
PutTiersToTextFrame()
-- PutEdgesToTextFrame()
PutParamsTiers() 
ClearDiagrArea() 
DrawDiagrTiers()
--
DelayMS( -1 )
--
for i=1,GetCountOps(),1 do
 find_SerOps( GetNumbOp( i ))  -- тестируем операторы
end 
--
SoundPlay("rooster.wav")-- петух возвещает, что работа сделана
--
-- конец main






