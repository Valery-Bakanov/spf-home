--
-- весна 2021
--
projectName = "abc_r" -- имя проекта 
--
projectName = "squa_equ_2"
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
----------------------------------------------------------------------------------------------------------------------------------------------
--=== ПРОГРАММА MAIN =========================================================
----------------------------------------------------------------------------------------------------------------------------------------------
local i
--
ClearTextFrame() -- очистка тестового экрана
--
CreateTiersByEdges(  projectName .. ".gv" )  -- создать ЯПФ по ИГА
PutTiersToTextFrame()
PutEdgesToTextFrame()
PutParamsTiers() 
ClearDiagrArea() 
PutParamsTiers() 
DrawDiagrTiers()
--
DelayMS( -1 )
--
InOp = 100 -- входные дуги для оператора InOp
OutOp = 100 -- выходные дуги из оператора OutOp
--
OutLine( "\nВсего операторов (без входного яруса)= " .. GetCountOps() )
for iOp=1,GetCountOps() do -- список операторов
 OutLine( "#" .. iOp ..  " Op= " .. GetNumbOp( iOp )   )
end 
--

OutLine( "\nЧисло входных (исходные данные) операторов= " .. GetCountOpsInput() .. " ; см. список ниже:"  )
for i=1,GetCountOpsInput()  do
 OutLine(  "#" .. i .. ". оператор: " .. GetNumbOpInput(i)  )
end
--                                                                                                          
OutLine( "\nЧисло выходных (результаты выполнения) операторов= " .. GetCountOpsOutput() .. " ; см. список ниже:" )
for i=1,GetCountOpsOutput()  do
 OutLine(  "#" .. i .. ". оператор: " .. GetNumbOpOutput(i)  )
end
--
Op=GetOpByNumbOnTier(1,1) -- исследуем первый оператора 1-го яруса ЯПФ
--
OutLine( "\nТестируем окружение вершины  " .. Op  )
OutLine( "==============================" )
--
OutLine( "\nВершина= " .. Op .. " : входящих дуг= " .. GetCountInEdgesByOp(Op) .. " ; см. список ниже:"  )
for i=1,GetCountInEdgesByOp(Op)  do
 OutLine(  "#" .. i .. ". Вершина: " .. GetNumbInEdgeByOp(i,Op) )
end
--
OutLine( "\nВершина= " .. Op .. " : выходящих дуг= " .. GetCountOutEdgesByOp(Op) .. " ; см. список ниже:"  )
for i=1,GetCountOutEdgesByOp(Op)  do
 OutLine(  "#" .. i .. ". Вершина: " .. GetNumbOutEdgeByOp(i,Op) )
end
--
SoundPlay("rooster.wav")-- петух возвещает, что работа сделана
--
-- конец main






