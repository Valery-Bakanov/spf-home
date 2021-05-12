--
-- тестирование TestLiveData  (сентябрь 2020)
--
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
--projectName = "m_m_10P"
--
--projectName = "e17_o11_t6"
--projectName = "e313_o206_t32"
--projectName = "e2367_o1397_t137"
--projectName = "e451_o271_t30"
--projectName = "e916_o624_t89" 
--projectName = "e17039_o9853_t199"
--
local function Visual() -- визуализация состояния ЯПФ
--AddLineToTextFrame("=====================================")  
PutTiersToTextFrame() 
ClearDiagrArea() 
PutParamsTiers() 
DrawDiagrTiers()
end -- конец функции Visual()
--
function UnloadTier( Tier ) -- разгрузка яруса Tier 
-- путем переноса части операторов с него на вновь образованные ярусы ниже
-- (при превышении ширины яруса величины WidthMax)
-- возвращает число дополнительно созданных ярусов
local Ops ={} -- таблица хранения #опер. перед переносом их вниз
local i,j,Op, nOpsAtTier, Quet, Rem, nTiersUpper,nOpsAtTier,nOpsBelow,jOpAtTier
local Width = WidthMax -- работаем с локальной копией WidthMax
--
nOpsAtTier = GetCountOpsOnTier(Tier) -- число операций на ярусе Tier
-- если не более WidthByWidth - данный ярус разгружать не надо
if nOpsAtTier <= Width then -- не надо ничего делать...
--OutLine ( string.format("\n--- UnloadTier: Tier= %d Width=%d nOpsAtTier= %d ===>", Tier,Width,nOpsAtTier  ))
 return 0  -- ни одного яруса не было создано под данным 
end -- конец nOpsAtTtier <= Width
--------------------------------------------------------------------------------------------------------------------------------------------------
-- 1 этап. Копируем в Ops{} операторы для переноса на вновь создаваемые ярусы под данным
-- стратегия - переносятся первые по счёту операторы, остаются последние Width штук
-- по ярусам перенесённые операторы располагаются сверху вниз в указанном порядке
--------------------------------------------------------------------------------------------------------------------------------------------------
nOpsBelow = nOpsAtTier - Width -- на ярусе Tier оставим Width операторов, остальные - вниз (below)!
--
--Quet = math.floor(nOpsBelow / Width) -- целое, частное от деления nOpsBelow на Width
Quet = nOpsBelow // Width  -- целочисленное деление, частное от деления nOpsBelow на Width
Rem = nOpsBelow % Width -- целое, остаток от этого же деления
--
--OutLine ( string.format("\n--- UnloadTier: Tier= %d nOps= %d|%d Width=%d Quet= %d Rem= %d\n", Tier,nOpsAtTier,nOpsBelow,Width,Quet,Rem  ))
--
-- создаём в Ops{} копию структуры создаваемых под Tier ярусов (i - номер яруса)
--
jOpAtTier=1 -- начинаем с первого оператора на ярусу Tier
--
if Quet > 0 then 
for i=1,Quet,1 do -- по ярусам с WidthMax операторов на каждом ярусе
 Ops[i] = {} -- создали i-тую строку Ops[][]
 for j=1,Width,1 do -- по операторам на ярусе
  Op=GetOpByNumbOnTier(jOpAtTier,Tier) -- номер оператора на ярусе Tier
  Ops[i][j] =  Op -- запомнили в элементе Ops[i][j] оператор Op
  jOpAtTier  = jOpAtTier +1 -- переход к следующему оператору на ярусе Tier
 end -- конец for j=1,Width,1
end -- конец for i=1,Quet,1
end -- конец if Quet > 0
--
if Rem > 0 then -- только при  Rem > 0
 Ops[Quet+1] = {}-- создали последнюю строку Ops[][]
 for j=1,Rem,1 do -- по остатку от деления
  Op=GetOpByNumbOnTier(jOpAtTier,Tier) -- номер оператора на ярусе Tier
  Ops[Quet+1][j] =  Op -- запомнили в элементе Ops[Ouet+1][j] оператор Op
  jOpAtTier  = jOpAtTier +1 -- переход к следующему оператору на ярусе Tier
 end -- конец for j=1,Rem,1 
end -- конец Rem > 0
----------------------------------------------------------------------------------------------------------------------------------------------------------------
-- 2 этап. Пытаемся уменьшить Width с целью получения меньшей неравномерности операторов по ярусам
----------------------------------------------------------------------------------------------------------------------------------------------------------------
--
----------------------------------------------------------------------------------------------------------------------------------------------------------------
-- 3 этап. Создаём яруса под данным ярусом  и операторы из Ops{} переносим на них
----------------------------------------------------------------------------------------------------------------------------------------------------------------
--
if Quet > 0 then 
for i=1,Quet,1 do -- по добавляемым ярусам c Width операторами (идём снизу вверх)
 AddTier(Tier+i-1) -- создали пустой ярус под Tier
  OutLine("\n===>Создан новый ярус под ярусом="..Tier+1)
 for j=1,Width,1 do -- по номерам операторов на ярусе
  MoveOpTierToTier(Ops[i][j],Tier+ i ) -- перенос операторов на ярус Tier+i
  OutLine("Оператор="..Ops[i][j].." с яруса="..GetTierByOp(Ops[i][j]).."  перенесен на ярус="..Tier+ i ) -- информация о переносе оператора
 end -- конец j=1,Width,1
end -- конец i=1,Quet,1
end -- if Quet > 0
--
if Rem > 0 then -- только при Rem > 0
 AddTier(Tier+Quet ) -- создали пустой ярус подо всеми Tier+Quet
 OutLine("\n--->Создан новый ярус под ярусом="..Tier+Quet)
 for j=1,Rem,1 do -- по последней, неполной строке
  MoveOpTierToTier(Ops[Quet+1][j],Tier+Quet+1 ) -- переносим операторы на ярус Tier+Quet+1
  OutLine("Оператор="..Ops[Quet+1][j].." с яруса="..GetTierByOp(Ops[Quet+1][j]) .. " перенесен на ярус="..Tier+Quet+1 ) -- информация о переносе оператора
 end -- конец for j=1,Rem,1 
end -- конец Rem > 0
--
Ops = nil -- освободили таблицу Ops
--
--Visual() -- визуализация состояния ЯПФ
--
if Rem == 0 then
 return Quet -- было создано Quet ярусов под данным ярусом Tier
else 
 return Quet+1 -- было создано Quet+1 ярусов под данным ярусом Tier 
end -- конец Rem == 0
--
end -- конец функции UnloadTiers( ) ----------------------------------------------------------------------------------------
--
-- MAIN - функция -------------------------------------
--===================================
--
ClearTextFrame()
--
WidthMax = 1 -- заданная ширина ЯПФ
OutLine ( "Задано WidthMax= " .. WidthMax  )
DelayMS(  -10 )-- задержка 10 сек
--
::retry::
--
CreateTiersByEdges(  projectName .. ".gv" )  -- создать ЯПФ по ИГА
CreateTiersByEdges(  projectName  )  -- создать ЯПФ по ИГА
--
Visual() -- визуализация состояния ЯПФ
--
PutTLDToTextFrame() -- данные времени жизни данных
SaveTLD( 1 ) -- вывод TLD в файла "1" (расширение по умолчанию TLD)
ClearDiagrArea() -- очистить поле графики
DrawDiagrTLD() -- вывести в виде линейчатой диаграммы
--
DelayMS( -10 )
--
Visual() -- визуализация состояния ЯПФ
--
------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------
--
CountMovesZeroing() -- обнулили число перемещений
--
iTier = 1 -- начинаем с яруса 1
uTier = 1
::contin:: -- продолжаем цикл по ярусам ЯПФ
--
uTier = UnloadTier( iTier  ) --- разгружаем яруса iTier от операторов (было создано uTier ярусов под iTier)
--
if uTier > 0 then
 OutLine ( string.format("\n--- Разгрузили ярус %d (дополнительно создано %d ярусов)", iTier, uTier  ))
end -- конец uTier > 0 
--
iTier = iTier + 1 -- следующий ярус
--
--Visual() -- визуализация состояния ЯПФ -- можно закомментировать для повышения скорости
--
--SoundPlay("kuku.wav") -- проиграть звук из файла
--
if iTier <= GetCountTiers() then -- общее число ярусов
 goto contin -- яруса ЯПФ ещё не кончились..!
end -- конец  iTier <= GetCountTiers()
--
Visual() -- визуализация состояния ЯПФ
--
--goto retry
--
print("\nВсего перемещений: " ..  GetOpsMoves() ) -- общее число перемещений
OutLine("\nВсего перемещений: " ..  GetOpsMoves() )
--
SoundPlay("kuku.wav") -- проиграть звук из файла
--
PutTLDToTextFrame() -- данные времени жизни данных
SaveTLD( 2 ) -- вывод TLD в файла "1" (расширение по умолчанию TLD)
ClearDiagrArea() -- очистить поле графики
DrawDiagrTLD() -- вывести в виде линейчатой диаграммы
--
SoundPlay("rooster.wav")-- петух возвещает, что работа сделана
--
-- конец main
