--
-- 17.04.2021
--projectName = "squa_equ_2"  -- им€ проекта 
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
local function f_Visual() -- визуализаци€ состо€ни€ яѕ‘
AddLineToTextFrame("=============================================================================")  
PutTiersToTextFrame() 
PutParamsTiers() 
ClearDiagrArea() 
DrawDiagrTiers()
end -- конец функции f_Visual()
--
local function f_OpsOnTiers() -- создать яѕ‘ внутри Lua
OpsOnTiers={} -- создаЄм пустой 1D-массив OpsOnTiers 
for iTier=1,GetCountTiers() do -- по €русам яѕ‘
   OpsOnTiers[iTier]={} -- создаЄм iTier-тую строку 2D-массива OpsOnTiers
   for nOp=1,GetCountOpsOnTier(iTier) do -- по пор€дковым номерам операторов на €русе iTier  
      OpsOnTiers[iTier][nOp]=GetOpByNumbOnTier(nOp,iTier) -- вз€ть номер оператора nOp
end end -- конец циклов for по iTier и for по nOp
end -- конец функции f_OpsOnTiers(0
--
local function f_OutTiers() -- вывод яѕ‘ из массива OpsOnTiers в текстовый фрейм
OutLine( "\n--- ярусов яѕ‘ = " .. GetCountTiers() .. " ---") -- вывод заголовка
for iTier=1,GetCountTiers() do -- по €русам яѕ‘
   local outStr = string.format( "%d|%d:", iTier,GetCountOpsOnTier(iTier) ) -- начало строки=€русы яѕ‘
   for nOp=1,GetCountOpsOnTier(iTier) do -- по пор€дковым номерам операторов на €русе iTier  
      OpsOnTiers[iTier][nOp]=GetOpByNumbOnTier(nOp,iTier) -- вз€ть номер оператора nOp
      outStr = outStr .. string.format(" %d", OpsOnTiers[iTier][nOp] ) -- добавл€ем номера операторов
   end -- конец цикла  по nOp - по пор€дковым номерам операторов на €русе iTier
OutLine( outStr ) -- вывод строки=€руса яѕ‘
end -- конец цикла  по iTier - по €русам яѕ‘
end -- конец функции f_OutTiers()
--
local function f_AllOpsDown() -- перемещает все операторы как можно Ќ»∆≈ по уровн€м яѕ‘
local  iTier,iOp -- локальные переменные (действуют только внутри функции)
CountMovesZeroing() -- обнулили счЄтчик переносов
for iTier=GetCountTiers(),1,-1 do -- по €русам снизу вверх
 for iOp=GetCountOpsOnTier(iTier),1,-1 do -- по #операторов на €русе справа налево
  Op=GetOpByNumbOnTier(iOp,iTier) -- номер оператора
  out = MoveOpTierToTier(Op,GetMaxTierMaybeOp(Op)) -- переносим Op
--
if out ==1 then  -- если перемещение успешно...
 OutLine( Op .. "=>" .. GetMaxTierMaybeOp(Op) .. " |"  .. out .. "| " .. GetOpsMoves() )
 f_Visual() -- визуализаци€ данных
 DelayMS( 1000 )
end 
--
end end -- конец цикла по iOp / конец цикла по iTier
--
return GetOpsMoves() -- число переносов операторов
-- 
end -- конец функции f_AllOpsDown
--
local function f_AllOpsTop() -- перемещает все операторы как можно ¬џЎ≈ по уровн€м яѕ‘
local  iTier,iOp -- локальные переменные (действуют только внутри функции)
CountMovesZeroing() -- обнулили счЄтчик переносов
for iTier=1,GetCountTiers(),1 do -- по €русам сверху вниз
 for iOp=GetCountOpsOnTier(iTier),1,-1 do --по #операторов на €русе справа налево
  Op=GetOpByNumbOnTier(iOp,iTier) -- номер оператора
  MoveOpTierToTier(Op,GetMinTierMaybeOp(Op)) -- переносим Op
end end -- конец цикла по iOp / конец цикла по iTier
--
return GetOpsMoves() -- число переносов операторов
-- 
end -- конец функции f_AllOpsTop


----------------------------------------------------------------------------------------------------------------------------------------------
--=== ѕ–ќ√–јћћј MAIN =========================================================
----------------------------------------------------------------------------------------------------------------------------------------------
--
ClearTextFrame() -- очистка тестового экрана
--
CreateTiersByEdges( projectName .. ".gv" ) -- создать яѕ‘ по »√ј в ¬≈–’Ќ≈… форме
--CreateTiersByEdges_Bottom( projectName .. ".gv" ) -- создать яѕ‘ по »√ј в Ќ»∆Ќ≈… форме
--
f_Visual() -- визуализаци€ данных
--
f_OpsOnTiers() -- создать яѕ‘ внутри Lua
--
f_OutTiers() -- печать яѕ‘
--
OutLine( "\n--- ѕеремещаем ¬Ќ»« ---" )
OutLine( "„исло перемещений - 1-й раз = " .. f_AllOpsDown() ) -- перемещаем все операторы ¬Ќ»«
OutLine( "„исло перемещений - 2-й раз = " .. f_AllOpsDown() ) -- перемещаем все операторы ¬Ќ»«
f_OutTiers() -- печать яѕ‘
--
--OutLine( "\n--- ѕеремещаем ¬¬≈–’ ---" )
--OutLine( "„исло перемещений - 1-й раз = " .. f_AllOpsTop() ) -- перемещаем все операторы ¬¬≈–’
--OutLine( "„исло перемещений - 2-й раз = " .. f_AllOpsTop() ) -- перемещаем все операторы ¬¬≈–’
--f_OutTiers() -- печать яѕ‘
--


--OutLine( "\n" .. f_AllOpsDown() .. " " .. f_AllOpsTop()  ) --
--
