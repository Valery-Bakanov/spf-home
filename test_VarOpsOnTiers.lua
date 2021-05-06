--
-- информаци€ о вариативности операторов по €русам яѕ‘;  2020 )
--
--projectName = "abc_r" -- им€ проекта 
--
projectName = "squa_equ_2"   
--projectName = "squa_equ_2.pred"
--
--projectName = "polinom_10-1"
--projectName = "polinom_10-2"
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

--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------

local function Visual() -- визуализаци€ состо€ни€ яѕ‘
AddLineToTextFrame("=============================================================================")  
PutTiersToTextFrame() 
PutParamsTiers() 
ClearDiagrArea() 
DelayMS( -1  )
DrawDiagrTiers()
DelayMS( -1  )
end -- конец функции Visual()

--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------

-- MAIN - функци€ -------------------------------------
--=================================
local H,iTier,j,nTiers,nOps,iOp, fromTier,toTier,newTier
--
ClearTextFrame() -- очистить текстовое окно
--
--ReadEdges(  projectName .. ".gv" )  -- читаем файл описани€ графа
--
CreateTiersByEdges( projectName .. ".gv" ) -- создать яѕ‘ по »√ј
--
Visual() -- визуализаци€ состо€ни€ яѕ‘
--
nTiers=GetCountTiers() -- общее число €русов
nOps=GetCountOps() -- общее число операторов 
--
OutLine("\n") 
--
sVarT=0 -- сумма вариаций  возможного нахождени€ операторов по всем €русам nTiers
--
for iTier=1,nTiers -- !!! по всем €русам сверху вниз
do
sVar=0 -- сумма вариаций возможного нахождени€ операторов по €русу iTier
nOpsOnTier=GetCountOpsOnTier(iTier) -- число операторов на €русе iTier
out2="" -- строка дл€ суммировани€ данных об операторах каждого €руса
--
for jOp=1,nOpsOnTier -- !!! по всем операторам на €русе Tier
do
iOp=GetOpByNumbOnTier (jOp,iTier) -- номер оператора jOps на €русе iTier
fromTier=GetMinTierMaybeOp (iOp) -- верхний €рус возможного нахождени€ iOp
toTier=GetMaxTierMaybeOp (iOp) -- нижний €рус нвозможного нахождени€ iOp
--
--out2r=outStr..string.format(" %d/%d:%d", iOp,fromTier,toTier) -- добавл€ем данные о каждом операторе на €руск Itier
out2=out2..string.format(" %d{%d}", iOp,toTier-fromTier) -- добавл€ем данные о каждом операторе на €руск Itier
--
sVar=sVar+(toTier-fromTier) -- накапливающа€с€ сумма вариаций по €русу iTier
end -- конец по jOp
--
sVarT=sVarT+sVar --  сумма по всем €русам
--
out1=string.format("%d|%d{av_var=%g}",  iTier,nOpsOnTier,sVar / nOpsOnTier) -- начало строки вывода дл€ каждого €руса
out2=out1 .. out2 -- полна€ строка вывода дл€ каждого €руса
OutLine(out2) -- фактический вывода строки
end -- конец по iTier
--
OutLine("\n—реднее по €русам=     " .. string.format("%g", sVarT / nTiers) );
OutLine("—реднее по всей яѕ‘= " .. string.format("%g", sVarT / nOps) );
--
SoundPlay("rooster.wav") -- петух возвещает, что работа сделана
--
-- конец main 

