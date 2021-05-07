--
--выполнение программы на гетерогенном поле вычислителей
--оптимизированный вариант 03 (апрель 2017)
--   ]
--projectName = "abc_r" -- имя проекта 
--
projectName = "squa_equ_2"  -- имя проекта 
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
--
ClearTextFrame() -- очистка тестового экрана
--
LoadFileNameParamsOps( projectName .. ".ops" )
LoadFileNameParamsCalcs( projectName .. ".cls" )
LoadFileNameParamsEdges( projectName .. ".med" )
LoadFileNameParamsVertices( projectName .. ".mvr" )
--
PutParamsAll() -- вывод ИСХОДНЫХ и СКОРРЕКТИРОВАННЫХ параметров настройки
--
AddLineToTextFrame ( "\n=== ВЫЧИСЛИТЕЛИ === " )
AddLineToTextFrame ( "Всего вычислителей= " .. GetCountCalcs() )
--
ReadEdges(  projectName .. ".gv" )  -- читаем файл описания графа
--
AddLineToTextFrame ( "\n=== ОПЕРАТОРЫ ===" )
AddLineToTextFrame ( "Всего операторов= " .. GetCountOps() )
--
nCalcs = GetCountCalcs() -- всего ВЫЧИСЛИТЕЛЕЙ
--
CreateTiersByEdges( projectName .. ".gv" ) -- создать ЯПФ по ИГА
--CreateTiersByEdges_Bottom( projectName .. ".gv" ) -- создать ЯПФ по ИГА
--
PutTiersToTextFrame() -- вывести ЯПФ как текст
ClearDiagrArea() -- очистить поле графики
DrawDiagrTiers() -- вывести ЯПФ в виде линейной диаграммы
--
OutLine("");
--
Op=100
OutLine("GetParamsByOp("..Op..") = ".."|".. GetParamsByOp( Op ).."|" );
OutLine("GetCountParamsByOp("..Op..") = ".. GetCountParamsByOp(Op) );
for  Numb=1,GetCountParamsByOp( Op ) do
OutLine("GetNumbParamByOp("..Numb..","..Op..") = ".."|".. GetNumbParamByOp( Numb,Op ).."|" );
end
--
Calc=1
OutLine("\nGetParamsByCalc("..Calc..") = ".."|".. GetParamsByCalc( Calc ).."|" );
OutLine("GetCountParamsByCalc("..Calc..") = " .. GetCountParamsByCalc( Calc ) );
for  Numb=1,GetCountParamsByCalc( Calc ) do
OutLine("GetNumbParamByCalc("..Numb..","..Calc..") = ".."|".. GetNumbParamByCalc( Numb,Calc ).."|" );
end
 --
Op=100
Name="Time"
OutLine("\nGetMetricOpByName("..Op..","..Name..") = ".. GetMetricOpByName(Op, Name) );
--
from_Op=100
to_Op=109
Name="Size"
OutLine("\nGetMetricEdgeByName("..from_Op..","..to_Op..","..Name..") = " .. GetMetricEdgeByName(from_Op,to_Op,Name) );
--
if ( not TestCanExecAllOpsCalcs( 1 ) )  then -- проверка выполнИмости ОПЕРАТОРОВ на ВЫЧИСЛИТЕЛЯХ
 AddLineToTextFrame ( "\n...Проблемы с выполнимостью ОПЕРАТОРОВ на ВЫЧИСЛИТЕЛЯХ..." )
end
--
PutParamsTiers()
--
PutTLDToTextFrame() -- вывод диаграммы времени жизни данных в текстовое окно
--
ClearDiagrArea() -- очистить поле графики
DrawDiagrTLD() -- вывод в графике
--
SaveTLD( "123" ) -- вывод в файл (расширение по умолчанию *.tld)
--
SoundPlay("rooster.wav") -- петух возвещает, что работа сделана
--
-- конец main



