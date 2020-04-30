-- стратегия BULLDOZER ( ver. #1-02, август 2017)
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
--
function SearchToOp_v01(fromTier, toTier)
-- ищет (среди fromTier-toTier) и возвращает ярус, на который 
-- рационально переместить оператор 
local minH=1000000000 -- для поиска min
local sTier=0 -- возврат, если не нашлось ни одного уровня, на который можно переносить оператор
local H,iTier
--
for iTier=fromTier+1,toTier do -- по ярусам ЯПФ
H=GetCountOpsOnTier(iTier) -- число операторов на ярусе iTier
--
if H>=bordH then -- больше среднего = неинтересно!
 goto cont_iTier  -- идём на новый цикл по iTier
end 
-- теперь остался вариант H<bordH (что нам и нужно!)
-- ищем ярус с минимальной шириной
if H<minH then
 minH=H
 sTier=iTier -- это ярус c min операторов на нём
end -- конец поиска min
--
::cont_iTier:: -- заканчиваем цикл 
end -- конец цикла  по iTier
--
return sTier -- возвращаем найденное...
--
end -- конец функции SearchToOp_v01()
--
--
function SearchToOp_v02(fromTier, toTier)
-- ищет (среди fromTier-toTier) и возвращает ярус, на который 
-- рационально переместить оператор 
local iTier
--
for iTier=fromTier+1,toTier do -- по ярусам ЯПФ
-- if GetCountOpsOnTier(iTier)<bordH and GetCountOpsOnTier(iTier-1)>bordH then
 if GetCountOpsOnTier(iTier)<bordH then 
   return iTier
 end -- конец if GetCountOpsOnTier(iTier)<bordH and …
end -- конец цикла  по iTier
--
return 0 -- не нашлось целевого яруса
--
end -- конец функции SearchToOp_v02()
--
--
function DefOpByMaxVar(iTier)
-- находит (ПЕРВЫЙ ПО СЧЁТУ) оператор с max вариабельностью на ярусе iTier
local jOp, iOp,  fromTier,toTier,varTier, iOpSave,fromTierSave,toTierSave
local maxVarTier = -1000000000 -- для поиска максимально вариативного оператора на ярусе iTier
--
for jOp=GetCountOpsOnTier(iTier),1,-1 do -- jOp - номер оператора на ярусе iTier (справа налево)
 iOp=GetOpByNumbOnTier(jOp,iTier) -- iOp - номер оператора
 fromTier=GetMinTierMaybeOp(iOp) -- верхний ярус вариативности расположения  iOp
 toTier=GetMaxTierMaybeOp(iOp) -- нижний ярус вариативности расположения iOp
 varTier=toTier-fromTier -- вариативностью оператора iOp
--
 if varTier>maxVarTier then -- ищем max( varTier )
  iOpSave=iOp -- запомнили глобальный номер оператора с max (на ярусе iTier) вариативностью
  fromTierSave=fromTier
  toTierSave=toTier
  maxVarTier=varTier
 end -- конец  if varTier>maxVarTier
 --
 end --  конец цикла for jOp=1,(iTier)
 --
 return iOpSave,fromTierSave,toTierSave -- вернули оператор с max вариабельностью и его данные
end -- конец функции DefOpByMaxVar()
--
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
                                                 
local function Visual() -- визуализация состояния ЯПФ
AddLineToTextFrame("=====================================")  
PutTiersToTextFrame() 
PutParamsTiers() 
ClearDiagrTiers() 
DrawDiagrTiers()
end -- конец функции Visual()
--
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
-- MAIN - функция ----------------------------------------------------------------------------
--=========================================================
local averH,H,iTier,nTiers,nOps,iOp, fromTier,toTier,newTier
--
ClearTextFrame() -- очистить текстовое окно
--
--ReadEdges(  projectName .. ".gv" )  -- читаем файл описания графа
--
CreateTiersByEdges(  projectName .. ".gv" ) -- создать ЯПФ по ИГА
--
Visual() -- визуализация состояния ЯПФ
--
DelayMS( -1 )
--
CountMovesZeroing() -- обнулили число перемещений
--
nTiers=GetCountTiers() -- общее число ярусов
nOps=GetCountOps() -- общее число операторов
averH=1.0 * nOps / nTiers -- средняя ширина  ЯПФ
bordH=math.ceil(averH) -- граничное значение средней величины
--
--***************************************************
for iTier=1,nTiers-1 do -- по номеру яруса от 1 до предпоследнего  (nTiers-1)
--
::retry_iTier:: -- повторное рассмотрение параметров яруса iTier
AddLineToTextFrame("\niTier="..iTier..', bordH='..bordH.. ", шир.="..GetCountOpsOnTier(iTier))  
--
if GetCountOpsOnTier(iTier)<bordH then  -- ширина яруса < bordH - отсюда переносить нельзя !!!
 goto cont_iTier -- конец обработки яруса iTier
end
--
iOp,fromTier,toTier=DefOpByMaxVar(iTier) -- ищем оператор с максимумом вариативности
--
if fromTier==toTier then  -- вариативностью == 0 (переносить нечего)
 goto cont_iTier
end
--
-- теперь переносим “вниз” оператор с max( varTier ) 

newTier=SearchToOp_v02(fromTier,toTier) -- пытаемся найти возможность
-- перестановки (логика нахождения newTier внутри SearchToOp
AddLineToTextFrame("newTier= "..newTier)
--
if newTier==0 then -- признак того, что переставлять некуда
 goto cont_iTier
end
--
-- собственно перестановка оператора iOp на ярус newTier
print( string.format("#iOp=%d fromTier=%d toTier=%d newTier=%d", iOp,fromTier,toTier,newTier)) 
AddLineToTextFrame("\nПеремещение: iOp=".. iOp.."("..GetTierByOp(iOp).."), fromTier=".. fromTier ..", toTier="..toTier.. ", newTier="..newTier.." ["..GetOpsMoves().."]")  
MoveOpTierToTier(iOp, newTier) -- собственно перестановка
--
Visual() -- визуализация состояния ЯПФ после изменения
SoundPlay("kuku.wav") -- проиграть звук из файла  
--
goto retry_iTier -- число операторов на ярусе iTier изменилось, анализируем ярус снова
--
::cont_iTier:: -- конец итераций по iTier
end -- конец основного цикла (по iTier)
--
PutTiersToTextFrame() -- конечный ЯПФ
--
print( "Moves=" .. GetOpsMoves() ) -- число перемещений
--
SoundPlay("rooster.wav") -- петух возвещает, что работа сделана
--
-- конец main       
