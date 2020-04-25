-- стратеги€ DICHOTOMY  (2015)
--
--projectName = "squa_equ_2"  -- им€ проекта 
--projectName = "squa_equ_2.pred"
--
--projectName = "max-1_mass-8.pred"
--projectName = "max-2_mass-8.pred"
--
--projectName = "slau_2"
--projectName = "slau_3"
--projectName = "slau_4" 
--projectName = "slau_5"
--projectName = "slau_7"
projectName = "slau_10"
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
function UnloadTier( Tier ) -- разгрузка €руса Tier 
-- путем переноса с него 50% операторов на 
-- вновь созданный €рус ниже данного
local j,j_max,Op
local Ops={} -- таблица хранени€ # опер. перед переносом их на нижерасположенные €руса
-- 
j_max=GetCountOpsOnTier(Tier) -- число операций на €русе Tier
--
if j_max < 2 then -- при одном операторе переносить нечего! 
 return -1313
end
--
 AddTier(Tier) -- создали пустой €рус под Tier  
--
for j=1,j_max,1 do -- по операторам €руса Tier
if  j%2 == 0   -- с чЄтными работаем...
then 
  Op=GetOpByNumbOnTier(j,Tier) -- номер оператора
  table.insert(Ops,Op) -- список переносимых вниз операторов 
end -- конец if
end -- конец for
--
for j=1,#Ops,1 -- собственно перенос
do 
 MoveOpTierToTier(Ops[j],Tier+1) -- перенос чЄтных 
-- AddLineToTextFrame( "---" .. Tier .. "/" .. j_max .. "|" .. Ops[j] .. "=>" .. MoveOpTierToTier(Ops[j],Tier+1) .. "---" )
end -- конец for
--
return 0
end -- конец функции UnloadTiers()


local function Visual() -- визуализаци€ состо€ни€ яѕ‘
--AddLineToTextFrame("=====================================")  
PutTiersToTextFrame() 
ClearDiagrTiers() 
PutParamsTiers() 
DrawDiagrTiers()
DelayMS(100)
end -- конец функции Visual()


-- MAIN - функци€ -------------------------------------
--===================================
--
ClearTextFrame()
--
WidthMax=10 -- max ширина яѕ‘
WidthMax = tonumber ( InputDialog( "ѕредельна€ ширина яѕ‘ ", "¬водите целое больше нул€ как строку", tostring( WidthMax  )))
OutLine ( "«адано WidthMax= " .. WidthMax  )
DelayMS( -3  )-- задержка 3 сек
--
--ReadEdges(  projectName .. ".gv" )  -- читаем файл описани€ графа
--
CreateTiersByEdges(  projectName .. ".gv" )  -- создать яѕ‘ по »√ј
--
Visual() -- визуализаци€ состо€ни€ яѕ‘
--
DelayMS( -1 )
------------------------------------------------------------------------
------------------------------------------------------------------------
nTiers=GetCountTiers() -- общее число €русов
--
CountMovesZeroing() -- обнулили число перемещений
--
while GetCountOpsOnTier(GetTierFirstMaxOps(1,nTiers)) > WidthMax do -- пока ширина > WidthMax
 nOps=GetCountOps() -- общее число операторов
 print( nOps .. "/" .. nTiers )
--
 AverOpsByTier=nOps / nTiers
 print( AverOpsByTier )
--
 UnloadTier( GetTierFirstMaxOps(1,nTiers) ) -- разгрузка MAX нагруженного €руса
--
 nTiers=GetCountTiers() -- общее число €русов
--
-- AddLineToTextFrame(GetTierFirstMaxOps(1,nTiers)) .. "-" ..  GetTierFirstMaxOps(1,nTiers) .. "=" .. GetOpsMoves()  )
 print(GetCountOpsOnTier(GetTierFirstMaxOps(1,nTiers)) .. "-" ..  GetTierFirstMaxOps(1,nTiers) .. "=" .. GetOpsMoves())
--
--Visual()  -- визуализаци€ состо€ни€ яѕ‘ -- можно закомментировать дл€ повышени€ скорости
--
--SoundPlay("kuku.wav") -- проиграть звук из файла  
--
print(GetCountOpsOnTier(GetTierFirstMaxOps(1,nTiers)) .. "=" ..  GetTierFirstMaxOps(1,nTiers) .. "-" .. GetOpsMoves())
--
end -- конец while GetCountOpsOnTier(...) > WidthMax 
--
SoundPlay("rooster.wav") -- петух возвещает, что работа сделана
--
Visual()  -- визуализаци€ состо€ни€ яѕ‘
--
print("\nѕеремещений:" ..  GetOpsMoves() ) -- общее число перемещений
OutLine( "\nѕеремещений:" ..  GetOpsMoves() )
--
-- конец main
