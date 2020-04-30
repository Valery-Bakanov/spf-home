-- стратегия BULLDOZER ( ver. #1-01, 2015 )
--
--projectName = "squa_equ_2"  -- имя проекта 
--projectName = "squa_equ_2.pred"
--
--projectName = "max-1_mass-8.pred"
--projectName = "max-2_mass-8.pred"
--
--projectName = "slau_2"
--projectName = "slau_3"
--projectName = "slau_4" 
--projectName = "slau_5"
--projectName = "slau_10"
--
--projectName = "doubling_32"
--
--projectName = "m_matr_2"
--projectName = "m_matr_3"
projectName = "m_matr_5"
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
-- ищет (среди fromTier-toTier) и возвращает ярус, на который 
-- рационально переместить оператор (не нашли -> возвр. 0)
local minH=1000000000 -- для поиска min
local i,H,sTier
--
-- есть ли ярусы с шириной H мЕньшей, чем средняя - averH (глоб.) ?
-- если нет ярусов с H<averH, то возвращаем 0
for i=fromTier+1,toTier -- по ярусам ЯПФ
do
H=GetCountOpsOnTier(i) -- ширина яруса i
--
if H<averH then -- нашли меньше среднего - уже интересно!
 goto succ end -- выход из цикла, ибо нашли хоть одно нужное  
--
end -- конец цикла по i
-- 
-- если return не последн. в функции, надо его заключить в do/end 
do return 0 end -- нет ни одного яруса с H<averH...
::succ:: -- нашли хоть один ярус с H<averH !!!
--
--
for i=fromTier+1,toTier -- по ярусам ЯПФ
do
H=GetCountOpsOnTier(i) -- число операторов на ярусе i  
--
if H>=averH -- больше среднего = неинтересно!
then goto cont_i end -- идём на новый цикл по i  
--
-- теперь остался вариант H<averH (что нам и нужно!)
-- ищем ярус с минимальной шириной
if H<minH then
 minH=H
 sTier=i -- это ярус c min операторов на нём
end -- конец поиска min
--
::cont_i:: -- заканчиваем цикл 
end -- конец цикла  по i
--
return sTier -- возвращаем найденное...
--
end -- конец функции SearchToOp()

--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------


local function Visual() -- визуализация состояния ЯПФ
AddLineToTextFrame("=============================================================================")  
PutTiersToTextFrame() 
PutParamsTiers() 
ClearDiagrTiers() 
-- DelayMS( -1  )
DrawDiagrTiers()
-- DelayMS( -1  )
end -- конец функции Visual()

--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------

-- MAIN - функция -------------------------------------
--=================================
local H,iTier,j,nTiers,nOps,iOp, fromTier,toTier,newTier
--
ClearTextFrame() -- очистить текстовое окно
--
--ReadEdges(  projectName .. ".gv" )  -- читаем файл описания графа
--
CreateTiersByEdges( projectName .. ".gv" ) -- создать ЯПФ по ИГА
--
Visual() -- визуализация состояния ЯПФ
--
--print( debug.gethook(L) )
--
DelayMS( -3  )
--
nTiers=GetCountTiers() -- общее число ярусов
nOps=GetCountOps() -- общее число операторов 
averH=1.0 * nOps / nTiers -- средняя шир. ЯПФ 
--
print ("nTiers=" .. nTiers .. ", nOps=" .. nOps .. ", средн.опер./ярус=" .. averH)  
--
CountMovesZeroing() -- обнулили число перемещений
--
-- число ярусов не меняется, поэтому используем for 
for iTier=1,nTiers,1 -- по всем ярусам кроме нулевого
do 
--
if GetCountOpsOnTier(iTier) == 0 -- пустой ярус проскакивем!
then goto cont_iTier end 
--
-- цикл по операторам на ярусе имитируем repeat/until, ибо
-- верхняя граница цикла изменяется (что в Lua недопустимо)
j=1 -- начало цикла по операторам на ярусе iTier
repeat 
 iOp=GetOpByNumbOnTier (j,iTier) -- номер оператора
 fromTier=GetMinTierMaybeOp (iOp) -- 'верх' нахождения iOp
 toTier=GetMaxTierMaybeOp (iOp) -- 'низ' нахождения iOp
--
-- print("=-= iOp=" .. iOp .. ", fromTier=" ..  fromTier .. ", toTier=" .. toTier)
--
if toTier == fromTier then -- если оператор переместить "вниз" нельзя...
goto cont_j end
--
newTier=SearchToOp(fromTier,toTier) -- пытаемся найти возможность перестановки
-- если нет возможности - возвращается 0
--
if newTier == 0 then -- если = 0, то нельзя переставлять...
goto cont_j end
--
-- перестановка оператора iOp на ярус newTier
print( string.format("#iOp=%d fromTier=%d toTier=%d", iOp, fromTier, toTier )) 
--
AddLineToTextFrame("\nПеремещение: iOp=".. iOp..", fromTier=".. fromTier ..", toTier="..toTier.. ", newTier="..newTier.." [Movies="..GetOpsMoves().."]")  
MoveOpTierToTier(iOp, newTier) -- собственно перестановка
--
Visual() -- визуализация состояния ЯПФ
SoundPlay("kuku.wav") -- проиграть звук из файла  
--
::cont_j::
--
j=j+1 -- новый номер оператора на ярусе iTier
--
N=GetCountOpsOnTier(iTier) -- текущее число операторов на уровне iTier
--
until j>N -- пока не перебрали все операторы на уровне iTier
--
::cont_iTier:: -- на новый цикл по ITier
end -- конец по ярусам ЯПФ 
--
PutTiersToTextFrame() -- конечный ЯПФ
--
SaveEdgesVizu( "a111.txt" )
--
SaveDataLiveDiagr("a222")
--
AddLineToTextFrame( string.format("\nlWinExec: %d", lWinExec( "calc.exe", 9  ) ) )
AddLineToTextFrame( string.format("\nlWinExec: %d", lWinExec( "notepad.exe history.txt", 9  ) ) )
AddLineToTextFrame( string.format("\nlShellExecute: %d", lShellExecute("","http://vbakanov.ru/spf@home/spf@home.htm",0,0,9  ) ) )
AddLineToTextFrame( string.format("\nCreateProcess: %d", lCreateProcess("notepad.exe history.txt",0,2,1 ) ) )
--
DelayMS( -3 )
--
AddLineToTextFrame( "\nMoves=" .. GetOpsMoves() )
print( "Moves=" .. GetOpsMoves() ) -- число перемещений
--
SoundPlay("rooster.wav") -- петух возвещает, что работа сделана
--
-- конец main 

