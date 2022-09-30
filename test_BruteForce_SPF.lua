--
-- 03.07.2022 [10-06.09.2022]
--
--projectName = "abc_r" -- им€ проекта 
--
--projectName = "squa_equ_2"  -- им€ проекта 
projectName = "squa_equ_2.pred"
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
projectName = "korr_5" 
--projectName = "korr_10"
--projectName = "korr_15"
--projectName = "korr_20"
--
--projectName = "e17_o11_t6"
--projectName = "e313_o206_t32"
--projectName = "e2367_o1397_t137"
--projectName = "e451_o271_t30"
--projectName = "e916_o619_t89" 
--projectName = "e17039_o9853_t199"
-- ===
--
local function f_Visual() -- визуализаци€ состо€ни€ яѕ‘
AddLineToTextFrame("=============================================================================")  
PutTiersToTextFrame() 
PutParamsTiers() 
ClearDiagrArea() 
DrawDiagrTiers()
end -- конец функции f_Visual()
--
----------------------------------------------------------------------------------------------------------------------------------------------
--=== ѕ–ќ√–јћћј MAIN =========================================================
----------------------------------------------------------------------------------------------------------------------------------------------
--
ClearTextFrame() -- очистка тестового экрана
--
CreateTiersByEdges( projectName .. ".gv" ) -- создать яѕ‘ по »√ј в ¬≈–’Ќ≈… форме
CreateTiersByEdges_Bottom( projectName .. ".gv" ) -- создать яѕ‘ по »√ј в ¬≈–’Ќ≈… форме
f_Visual()
--
OutLine("\n")
--[[
for iTier=1,GetCountTiers() do -- по всем €русам яѕ‘
 for iOp=1,GetCountOpsOnTier( iTier )  do  -- по номерам операторов на €русе
  Op = GetOpByNumbOnTier( iOp, iTier)  -- реальный номер оператора
  min_Tier = GetMinTierMaybeOp ( Op ) -- min/max €рус корректного расположени€ опертора Op
  max_Tier =  GetMaxTierMaybeOp ( Op )
  if min_Tier ~= max_Tier then 
   OutLine( string.format( "Op= #%d Tier=%d min/max=%d/%d", Op, GetTierByOp( Op ), min_Tier,max_Tier  ) )
  end 
end end
--]]
--
BruteForce_SPF( 0, 0,0,0,0, 1000000, 1000000 ) -- полный перебор всех положений операторов на €русах яѕ‘
-- 0/#0 - диапазон вариативности вычисл€етс€ или принимаетс€ равным высоте яѕ‘
-- 0/#0 - выдавать ли  яѕ‘ по €русам
-- 0/#0 - выдача параметров яѕ‘ в нижнюю часть текстового окна
-- 0/#0 - выдача линейчатого графика ширин €русов яѕ‘;
-- 0/#0 - перебор операторов с var#0 "снизу вверх" / "сверху вниз"
-- 0/NNN - не выдавать / выдавать каждые NNN строки вариантов строки операторов с var#0
-- 0/NNN - не выдавать / выдавать каждые NNN строки вариантов  с вариативностью яѕ‘
--
