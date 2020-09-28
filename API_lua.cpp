#define APM Application->ProcessMessages(); // дать поработать Windows
//
#define strNcpy(d,s) strncpy(d,s,sizeof(d)) // ?????????? ???????????
//
////////////////////////////////////////////////////////////////////////////////
static int AddTier(lua_State *L) // вызов С-функции AddTier из Lua
{
 INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_AddTier(%ld)", (INT)arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_AddTier((INT)arg) ); // вызовем c_AddTier() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец AddTier =======================================================

////////////////////////////////////////////////////////////////////////////////
static int DelTier(lua_State *L) // вызов С-функции DelTier из Lua
{
 INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_DelTier(%ld)", (INT)arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_DelTier((INT)arg)); // вызовем c_DelTier() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец DelTier =======================================================

////////////////////////////////////////////////////////////////////////////////
static int GetMaxTierMaybeOp(lua_State *L) // вызов С-функции GetMaxTiermayBeOp из Lua
{
 INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetMaxTierMaybeOp(%ld)", (INT)arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetMaxTierMaybeOp((INT)arg)); // вызовем c_GetMaxTierMayBeOp() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetMaxTierMayBeOp =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetMinTierMaybeOp(lua_State *L) // вызов С-функции GetMinTiermayBeOp из Lua
{
 INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetMinTierMaybeOp(%ld)", (INT)arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetMinTierMaybeOp((INT)arg)); // вызовем c_GetMinTierMaybeOp() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetMinTierMayBeOp =============================================

////////////////////////////////////////////////////////////////////////////////
static int MoveOpTierToTier(lua_State *L) // вызов С-функции MoveOpTierToTier из Lua
{
 INT arg1 = luaL_checkinteger(L, 1), // получим 1-й аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2); // получим 2-й аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_MoveOpTierToTier(%ld,%ld)", (INT)arg1, (INT)arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_MoveOpTierToTier((INT)arg1, (INT)arg2)); // вызовем конец MoveOpTierToTier и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец MoveOpTierToTier ==============================================

////////////////////////////////////////////////////////////////////////////////
static int SwapOpsTierToTier(lua_State *L) // вызов С-функции SwapOpsTierToTier из Lua 
{
 INT arg1 = luaL_checkinteger(L, 1), // получим 1-й аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2); // получим 2-й аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SwapOpsTierToTier(%ld,%ld)", (INT)arg1, (INT)arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_SwapOpsTierToTier((INT)arg1, (INT)arg2)); // вызовем c_SwapOpsTierToTier() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец SwapOpsTierToTier =============================================

////////////////////////////////////////////////////////////////////////////////
static int PutTiersToTextFrame(lua_State *L) // описываем функцию PutTiersToTextFrame на С
{
//  INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_PutTiersToTextFrame()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_PutTiersToTextFrame()); // вызовем c_PutTiersToTextFrame() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец PutTiersToTextFrame =============================================

////////////////////////////////////////////////////////////////////////////////
static int PutEdgesToTextFrame(lua_State *L) // описываем функцию PutEdgesToTextFrame на С
{
// INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_PutEdgesToTextFrame()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_PutEdgesToTextFrame()); // вызовем c_PutEdgesToTextFrame() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец PutEdgesToTextFrame ===========================================

////////////////////////////////////////////////////////////////////////////////
static int ClearTextFrame(lua_State *L) // описываем функцию ClearTextFrame на С
{
// INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_ClearTextFrame()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_ClearTextFrame()); // вызовем c_PutSPSToTextFrame() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец PutSPSToTextFrame =============================================

////////////////////////////////////////////////////////////////////////////////
static int DrawDiagrTiers(lua_State *L) // описываем функцию DrawDiagrTiers на С
{
// INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_DrawDiagrTiers()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_DrawDiagrTiers()); // вызовем c_DrawDiagrTiers() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_DrawDiagrTiers ==============================================

////////////////////////////////////////////////////////////////////////////////
static int DrawDiagrTLD(lua_State *L) // описываем функцию DrawDiagrTLD на С
{
// INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_DrawDiagrTLD()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_DrawDiagrTLD()); // вызовем c_DrawDiagrTLD() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_DrawDiagrTLD ================================================

////////////////////////////////////////////////////////////////////////////////
static int PutParamsTiers(lua_State *L) // описываем функцию PutParamsTiers на С
{
// INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call PutParamsTiers()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_PutParamsTiers()); // вызовем PutParamsTiers и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец PutParamsTiers ================================================

////////////////////////////////////////////////////////////////////////////////
static int ClearDiagrArea(lua_State *L) // описываем функцию ClearDiagrArea на С
{
// INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_ClearDiagrArea()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_ClearDiagrArea()); // вызовем c_ClearDiagrArea() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_ClearDiagrArea =============================================

////////////////////////////////////////////////////////////////////////////////
static int DelayMS(lua_State *L) // описываем функцию DelayMS на С
{
 INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_DelayMS(%ld)", (INT)arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_DelayMS((INT)arg)); // вызовем c_DelayMS() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_DelayMS =====================================================

////////////////////////////////////////////////////////////////////////////////
static int AddLineToTextFrame(lua_State *L) // описываем функцию AddLineToTextFrame на С
{
 char arg[_4096];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_AddLineToTextFrame(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_AddLineToTextFrame(arg)); // вызовем c_AddLineToTextFrame() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_AddLineToTextFrame ==========================================

////////////////////////////////////////////////////////////////////////////////
static int OutLine(lua_State *L) // описываем функцию OutLine на С
{
 char arg[_4096];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_AddLineToTextFrame(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_AddLineToTextFrame(arg)); // вызовем c_AddLineToTextFrame() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_OutLine =====================================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountTiers(lua_State *L) // описываем функцию GetCountTiers на С
{
// INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountTiers()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetCountTiers()); // вызовем c_GetCountTiers и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetCountTiers =================================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountOpsOnTier(lua_State *L) // описываем функцию GetCountOpsOnTier на С
{
 INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountOpsOnTier(%ld)",(INT)arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetCountOpsOnTier((INT)arg)); // вызовем c_GetCountOpsOnTier и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetCountOpsOnTier =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetOpByNumbOnTier(lua_State *L) // описываем функцию GetOpByNumbOnTier на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим один аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2); // получим второй аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetOpByNumbOnTier(%ld,%ld)", (INT)arg1, (INT)arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetOpByNumbOnTier((INT)arg1, (INT)arg2)); // вызовем c_GetOpByNumbOnTier и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetOpByNumbOnTier =============================================

////////////////////////////////////////////////////////////////////////////////
static int SoundPlay(lua_State *L) // вызов С-функции c_SoundPlay из Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SoundPlay(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_SoundPlay(arg)); // вызовем c_SoundPlay() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец SoundPlay =====================================================

////////////////////////////////////////////////////////////////////////////////
static int CreateTiersByEdges(lua_State *L) // описываем функцию CreateTiersByEdges на С
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 sp_printf(" Lua call c_CreateTiersByEdges(\"%s\")", arg );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_CreateTiersByEdges( arg )); // вызовем c_CreateTiersByEdges и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец CreateTiersByEdges ============================================

////////////////////////////////////////////////////////////////////////////////
static int CreateTiersByEdges_Bottom(lua_State *L) // описываем функцию CreateTiersByEdges_Bottom на С
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 sp_printf(" Lua call c_CreateTiersByEdges_Bottom(\"%s\")", arg );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_CreateTiersByEdges_Bottom( arg )); // вызовем c_CreateTiersByEdges_Bottom и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец CreateTiersByEdges_Bottom =====================================

////////////////////////////////////////////////////////////////////////////////
static int GetOpsMoves(lua_State *L) // описываем функцию GetOpsMoves на С
{
// INT arg1 = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetOpsMoves()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetOpsMoves()); // вызовем c_GetOpsMoves и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetOpsMoves ===================================================

////////////////////////////////////////////////////////////////////////////////
static int CountMovesZeroing(lua_State *L) // описываем функцию CountMovesZeroing на С
{
// INT arg1 = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_CountMovesZeroing()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_CountMovesZeroing()); // вызовем c_CountMovesZeroing и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец CountMovesZeroing =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetTierFirstMinOps(lua_State *L) // описываем функцию GetTierFirstMinOps на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим один аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2); // получим второй аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetTierFirstMinOps(%ld,%ld)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetTierFirstMinOps(arg1,arg2)); // вызовем c_GetTierFirstMinOps и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetTierFirstMinOps ============================================

////////////////////////////////////////////////////////////////////////////////
static int GetTierLastMinOps(lua_State *L) // описываем функцию GetTierLastMinOps на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим один аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2); // получим второй аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetTierLastMinOps(%ld,%ld)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetTierLastMinOps(arg1, arg2)); // вызовем c_GetTierLastMinOps и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetTierLastMinOps =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetTierFirstMaxOps(lua_State *L) // описываем функцию GetTierFirstMaxOps на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим один аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2); // получим второй аргумент (с проверкой "на число
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetTierFirstMaxOps(%ld,%ld)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetTierFirstMaxOps(arg1, arg2)); // вызовем c_GetTierFirstMaxOps и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetTierFirstMaxOps ============================================

////////////////////////////////////////////////////////////////////////////////
static int GetTierLastMaxOps(lua_State *L) // описываем функцию GetTierLastMaxOps на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим один аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2); // получим второй аргумент (с проверкой "на число
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetTierLastMaxOps(%ld,%ld)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetTierLastMaxOps(arg1, arg2)); // вызовем c_GetTierLastMaxOps и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetTierLastMaxOps =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountOpsInput(lua_State *L) // описываем функцию GetCountOpsInput на С
{
// INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountOpsInput()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetCountOpsInput()); // вызовем c_GetCountOpsInput и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetCountOpsInput ==============================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountOpsOutput(lua_State *L) // описываем функцию GetCountOpsOutput на С
{
// INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountOpsOutput()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetCountOpsOutput()); // вызовем c_GetCountOpsOutput и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetCountOpsOutput =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountOps(lua_State *L) // описываем функцию GetCountOps на С
{
// INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountOps()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetCountOps()); // вызовем c_GetCountOps и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetCountOps ===================================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountEdges(lua_State *L) // описываем функцию GetCountEdges на С
{
// INT arg1 = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountEdges()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetCountEdges()); // вызовем c_GetCountEdges и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetCountEdges =================================================

////////////////////////////////////////////////////////////////////////////////
static int GetTierByOp(lua_State *L) // описываем функцию IsOpExistEdge на С
{
 INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetTierByOp(%ld)", arg );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetTierByOp( arg )); // вызовем c_GetTierByOp и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetTierByOp  ==================================================

////////////////////////////////////////////////////////////////////////////////
static int ReadEdges(lua_State *L) // вызов С-функции c_ReadEdges из Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_ReadEdges(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_ReadEdges( arg )); // вызовем c_ReadEdges и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец ReadEdges =====================================================

////////////////////////////////////////////////////////////////////////////////
static int SaveEdges(lua_State *L) // вызов С-функции c_SaveEdges из Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveEdges(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_SaveEdges( arg )); // вызовем c_SaveEdges и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец SaveEdges =====================================================

////////////////////////////////////////////////////////////////////////////////
static int ReadTiers(lua_State *L) // вызов С-функции c_ReadTiers из Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_ReadTiers(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_ReadTiers( arg )); // вызовем c_ReadTiers и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец ReadTiers =====================================================

////////////////////////////////////////////////////////////////////////////////
static int SaveTiers(lua_State *L) // вызов С-функции c_SaveTiers из Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveTiers(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_SaveTiers( arg )); // вызовем c_SaveTiers и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец SaveTiers =====================================================

////////////////////////////////////////////////////////////////////////////////
static int SaveEdgesVizu(lua_State *L) // вызов С-функции c_SaveEdgesVizu из Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveEdgesVizu(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_SaveEdgesVizu( arg )); // вызовем c_SaveEdgesVizu и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец SaveEdgesVizu =================================================

////////////////////////////////////////////////////////////////////////////////
static int SaveTiersVizu(lua_State *L) // вызов С-функции c_SaveTiersVizu из Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveTiersVizu(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_SaveTiersVizu( arg )); // вызовем c_SaveTiersVizu и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец SaveTiersVizu =================================================

////////////////////////////////////////////////////////////////////////////////
static int SaveInOutOpVizu(lua_State *L) // вызов С-функции c_SaveInOutOpVizu из Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveInOutOpVizu(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_SaveInOutOpVizu( arg )); // вызовем c_SaveInOutOpVizu и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец SaveInOutOpVizu =================================================

////////////////////////////////////////////////////////////////////////////////
static int SaveParamsVizu(lua_State *L) // вызов С-функции c_SaveParamsVizu из Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveParamsVizu(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_SaveParamsVizu( arg )); // вызовем c_SaveParamsVizu и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец SaveParamsVizu =================================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountInEdgesByOp(lua_State *L) // описываем функцию GetCountInEdgesByOp на С
{
 INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountInEdgesByOp(%ld)", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetCountInEdgesByOp( arg )); // вызовем c_GetCountInEdgesByOp и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetCountOutEdgesByOp ==========================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountOutEdgesByOp(lua_State *L) // описываем функцию GetCountOutEdgesByOp на С
{
 INT arg = luaL_checkinteger(L, 1); // получим один аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountOutEdgesByOp(%ld)", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetCountOutEdgesByOp( arg )); // вызовем c_GetCountOutEdgesByOp и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetCountOutEdgesByOp ==========================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbInEdgeByOp(lua_State *L) // описываем функцию GetNumbInEdgeByOp на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим аргументы (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbInEdgeByOp(%ld,%ld)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetNumbInEdgeByOp( arg1, arg2 )); // вызовем c_GetNumbInEdgeByOp и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetNumbInEdgeByOp =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbOutEdgeByOp(lua_State *L) // описываем функцию GetNumbOutEdgeByOp на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим аргументы (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbOutEdgeByOp(%ld,%ld)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetNumbOutEdgeByOp( arg1, arg2 )); // вызовем c_GetNumbOutEdgeByOp и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetNumbOutEdgeByOp ============================================

////////////////////////////////////////////////////////////////////////////////
// учёт гетерогенности вычислительного поля ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// сторона вычислителей --------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
static int GetParamsByCalc(lua_State *L) // описываем функцию GetParamsByCalc на С
{
 INT arg1 = luaL_checkinteger(L, 1); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetParamsByCalc( %ld )", arg1 );

 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushstring(L, c_GetParamsByCalc( arg1 )); // вызовем c_GettParamsByCalc и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetParamsByCalc ===============================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountParamsByCalc(lua_State *L) // описываем функцию GetCountParamsByCalcна С
{
 INT arg1 = luaL_checkinteger(L, 1); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountParamsByCalc( %ld )", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetCountParamsByCalc( arg1 )); // вызовем c_GettParamsByCalc и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetCountParamsByCalc ==========================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbParamByCalc(lua_State *L) // описываем функцию GetNumbParamByCalc на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbParamByCalc( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushstring(L, c_GetNumbParamByCalc( arg1, arg2 )); // вызовем c_GetNumbParamByCalc и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetNumbParamByCalc ============================================

////////////////////////////////////////////////////////////////////////////////
static int GetNameNumbParamByCalc(lua_State *L) // описываем функцию GetNumbParamByCalc на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNameNumbParamByCalc( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushstring(L, c_GetNameNumbParamByCalc( arg1, arg2 )); // вызовем c_GetNameNumbParamByCalc и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_GetNameNumbParamByCalc ======================================

////////////////////////////////////////////////////////////////////////////////
static int GetMinValNumbParamByCalc(lua_State *L) // описываем функцию c_GetMinValNumbParamByCalc на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetMinValNumbParamByCalc( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushnumber(L, c_GetMinValNumbParamByCalc( arg1, arg2 )); // вызовем c_GetMinValNumbParamByCalc и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_GetMinValNumbParamByCalc ====================================

////////////////////////////////////////////////////////////////////////////////
static int GetMaxValNumbParamByCalc(lua_State *L) // описываем функцию c_GetMaxValNumbParamByCalc на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetMaxValNumbParamByCalc( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushnumber(L, c_GetMaxValNumbParamByCalc( arg1, arg2 )); // вызовем c_GetMaxValNumbParamByCalc и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_GetMaxValNumbParamByCalc ====================================

////////////////////////////////////////////////////////////////////////////////
// сторона операторов
////////////////////////////////////////////////////////////////////////////////
static int GetParamsByOp(lua_State *L) // описываем функцию GetParamsByOp на С
{
 INT arg1 = luaL_checkinteger(L, 1); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetParamsByOp( %ld )", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushstring(L, c_GetParamsByOp( arg1 )); // вызовем c_GettParamsByOp и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetParamsByOp =================================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountParamsByOp(lua_State *L) // описываем функцию GetCountParamsByOp на С
{
 INT arg1 = luaL_checkinteger(L, 1); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountParamsByOp( %ld )", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetCountParamsByOp( arg1 )); // вызовем c_GettParamsByOp и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetCountParamsByOp ============================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbParamByOp(lua_State *L) // описываем функцию GetNumbParamByOp на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbParamByOp( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushstring(L, c_GetNumbParamByOp( arg1, arg2 )); // вызовем c_GetNumbParamByOp и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetNumbParamByOp ==============================================

////////////////////////////////////////////////////////////////////////////////
static int GetNameNumbParamByOp(lua_State *L) // описываем функцию GetNameNumbParamByOp на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNameNumbParamByOp( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushstring(L, c_GetNameNumbParamByOp( arg1, arg2 )); // вызовем c_GetNameNumbParamByOp и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_GetNameNumbParamByOp ========================================

////////////////////////////////////////////////////////////////////////////////
static int GetValNumbParamByOp(lua_State *L) // описываем функцию c_GetValNumbParamByOp на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetValNumbParamByOp( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushnumber(L, c_GetValNumbParamByOp( arg1, arg2 )); // вызовем c_GetValNumbParamByOp и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_GetValNumbParamByOp =========================================

////////////////////////////////////////////////////////////////////////////////
// функции логического вывода о возможности выполнения оператора Op на вычислителе Calc
////////////////////////////////////////////////////////////////////////////////
static int CanExecOpCalc(lua_State *L) // описываем функцию CanExecOpCalc на С
{
 INT arg1 = luaL_checkinteger(L, 1), // получим аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_CanExecOpCalc( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_CanExecOpCalc( arg1, arg2 )); // вызовем c_CanExecOpCalc и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец CanExecOpCalc =================================================

////////////////////////////////////////////////////////////////////////////////
// функции работы с гетерогенным полем вычислителей ============================
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
static int LoadFileNameParamsCalcs(lua_State *L) // описываем функцию LoadFileNameParamsCalcs на С
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_LoadFileNameParamsCalcs(\"%s\")",arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_LoadFileNameParamsCalcs( arg )); // вызовем c_LoadFileNameParamsCalcs и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец LoadFileNameParamsCalcs ========================================

////////////////////////////////////////////////////////////////////////////////
static int LoadFileNameParamsOps(lua_State *L) // описываем функцию LoadFileNameParamsOps на С
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_LoadFileNameParamsOps(\"%s\")",arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_LoadFileNameParamsOps( arg )); // вызовем c_LoadFileNameParamsOps и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец LoadFileNameParamsOps =========================================

////////////////////////////////////////////////////////////////////////////////
static int LoadFileNameParamsEdges(lua_State *L) // описываем функцию LoadFileNameParamsEdges на С
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_LoadFileNameParamsEdges(\"%s\")",arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_LoadFileNameParamsEdges( arg )); // вызовем c_LoadFileNameParamsEdges и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец LoadFileNameParamsEdges =======================================

////////////////////////////////////////////////////////////////////////////////
static int LoadFileNameParamsVertices(lua_State *L) // описываем функцию LoadFileNameParamsVertices на С
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_LoadFileNameParamsVertices(\"%s\")",arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_LoadFileNameParamsVertices( arg )); // вызовем c_LoadFileNameParamsVertices и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец LoadFileNameParamsVertices ====================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountCalcs(lua_State *L) // описываем функцию GetCountCalcs на С
{
// INT arg1 = luaL_checkinteger(L, 1); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountCalcs()" );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetCountCalcs( )); // вызовем c_GetCountCalcs и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetCountCalcs =================================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbOpInput(lua_State *L) // описываем функцию GetNumbOpInput на С
{
 INT arg1 = luaL_checkinteger(L, 1); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbOpInput( %ld )", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetNumbOpInput( arg1 )); // вызовем c_GetNumbOpInput и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetNumbOpInput ================================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbOpOutput(lua_State *L) // описываем функцию GetNumbOpOutput на С
{
 INT arg1 = luaL_checkinteger(L, 1); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbOpOutput( %ld )", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetNumbOpOutput( arg1 )); // вызовем c_GetNumbOpOutput и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetNumbOpOutput ===============================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbOp(lua_State *L) // описываем функцию GetNumbOp на С
{
 INT arg1 = luaL_checkinteger(L, 1); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbOp(%ld)", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_GetNumbOp( arg1 )); // вызовем c_GetNumbOp и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец GetNumbOp =====================================================

////////////////////////////////////////////////////////////////////////////////
// --- функции тестирования параметров ОПЕРАТОРОВ, ВЫЧИСЛИТЕЛЕЙ и СООБЩЕНИЙ ----
////////////////////////////////////////////////////////////////////////////////
static int TestCanExecAllOpsCalcs(lua_State *L) // описываем функцию TestCanExecAllOpsCalcs на С
{
 INT arg1 = luaL_checkinteger(L, 1); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_TestCanExecAllOpsCalcs( %ld )", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_TestCanExecAllOpsCalcs(arg1)); // вызовем c_TestCanExecAllOpsCalcs и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец TestCanExecAllOpsCalcs ========================================

////////////////////////////////////////////////////////////////////////////////
static int PutParamsAll(lua_State *L) // описываем функцию PutParamsAll на С
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_PutParamsAll()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_PutParamsAll()); // вызовем c_PutParamsAll и результат -> стек
 return 1 ; // фикция, но так необходимо для Lua
} // ===== конец PutParamsAll ==================================================

////////////////////////////////////////////////////////////////////////////////
// --- работа с диалоговыми панелями -------------------------------------------
////////////////////////////////////////////////////////////////////////////////
static int InputDialog(lua_State *L) // описываем функцию InputBox на С
{
 char arg1[_512], arg2[_512], arg3[_512];
 strNcpy(arg1, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 strNcpy(arg2, luaL_checkstring(L, 2));
 strNcpy(arg3, luaL_checkstring(L, 3));
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_InputBox(\"%s\",\"%s\",\"%s\")", arg1,arg2,arg3);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushstring(L, c_InputDialog( arg1,arg2,arg3 )); // вызовем c_InputDialog и результат -> стек
 return 1 ; // фикция, но так необходимо для Lua
} // ===== конец InputDialog ===================================================

////////////////////////////////////////////////////////////////////////////////
static int MessageDialog(lua_State *L) // описываем функцию MessageDialog на С
{
 char arg1[_512], arg2[_512], arg3[_512];
 strNcpy(arg1, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 strNcpy(arg2, luaL_checkstring(L, 2));
 strNcpy(arg3, luaL_checkstring(L, 3));
 INT  arg4 = luaL_checkinteger(L, 4); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_MessageDialog(\"%s\",\"%s\",\"%s\",%d)", arg1,arg2,arg3,arg4);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushinteger(L, c_MessageDialog( arg1,arg2,arg3,arg4 )); // вызовем c_MessageDialog и результат -> стек
 return 1 ; // фикция, но так необходимо для Lua
} // ===== конец MessageDialog =================================================

////////////////////////////////////////////////////////////////////////////////
static int GetMetricOpByName(lua_State *L) // описываем функцию GetMetricOpByName на С
{
 char arg2[_512];
 INT arg1 = luaL_checkinteger(L, 1); // получим аргумент (с проверкой "на число")
 strNcpy(arg2, luaL_checkstring(L, 2)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetMetricOpByName(%d,\"%s\")", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushnumber(L, c_GetMetricOpByName( arg1, arg2 )); // вызовем c_GetMetricOpByName и результат -> стек
 return 1 ; // фикция, но так необходимо для Lua
} // ===== конец GetMetricOpByName =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetMetricEdgeByName(lua_State *L) // описываем функцию GetMetricEdgeByName на С
{
 char arg3[_512];
 INT arg1 = luaL_checkinteger(L, 1), // получим аргумент (с проверкой "на число")
     arg2 = luaL_checkinteger(L, 2);
 strNcpy(arg3, luaL_checkstring(L, 3)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetMetricEdgeByName(%d,%d,\"%s\")", arg1, arg2, arg3);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushnumber(L, c_GetMetricEdgeByName( arg1, arg2, arg3 )); // вызовем c_GetMetricEdgeByName и результат -> стек
 return 1 ; // фикция, но так необходимо для Lua
} // ===== конец GetMetricEdgeByName ===========================================

////////////////////////////////////////////////////////////////////////////////
static int GetOpByMaxTierLowerPreset(lua_State *L) // описываем функцию GetOpByMaxTierLowerPreset на С
{
 INT arg = luaL_checkinteger(L, 1); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetOpByMaxTierLowerPreset(%d)", arg );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushnumber(L, c_GetOpByMaxTierLowerPreset( arg )); // вызовем c_GetOpByMaxTierLowerPreset и результат -> стек
 return 1 ; // фикция, но так необходимо для Lua
} // ===== конец GetOpByMaxTierLowerPreset =====================================

////////////////////////////////////////////////////////////////////////////////
static int PutTLDToTextFrame(lua_State *L) // описываем функцию PutTLDToTextFrame на С
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call PutTLDToTextFrame()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushnumber(L, c_PutTLDToTextFrame()); // вызовем с_PutTLDToTextFrame и результат -> стек
 return 1 ; // фикция, но так необходимо для Lua
} // ===== конец PutTLDToTextFrame =============================================

////////////////////////////////////////////////////////////////////////////////
static int SaveTLD(lua_State *L) // описываем функцию SaveTLD на С
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveTLD(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushboolean(L, c_SaveTLD(arg)); // вызовем c_SaveTLD() и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_SaveTLD =====================================================

////////////////////////////////////////////////////////////////////////////////
static int lWinExec(lua_State *L) // описываем функцию lWinExec на С
{
 char arg1[_512];
 strNcpy(arg1, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 INT arg2 = luaL_checkinteger(L, 2); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_WinExec(\"%s\",%d)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushnumber(L, c_WinExec( arg1, arg2 )); // вызовем c_WinExec и результат -> стек
 return 1 ; // фикция, но так необходимо для Lua
} // ===== конец lWinExec ======================================================

////////////////////////////////////////////////////////////////////////////////
static int lShellExecute(lua_State *L) // описываем функцию lShellExecute на С
{
 char arg1[_512], arg2[_512], arg3[_512], arg4[_512];
 strNcpy(arg1, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 strNcpy(arg2, luaL_checkstring(L, 2));
 strNcpy(arg3, luaL_checkstring(L, 3));
 strNcpy(arg4, luaL_checkstring(L, 4));
 INT arg5 = luaL_checkinteger(L, 5); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_lShellExecute(\"%s\",\"%s\",\"%s\",\"%s\",%d)", arg1, arg2, arg3, arg4, arg5 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushnumber(L, c_ShellExecute( arg1, arg2, arg3, arg4, arg5 )); // вызовем c_lShellExecute и результат -> стек
 return 1 ; // фикция, но так необходимо для Lua
} // ===== конец lShellExecute =================================================

////////////////////////////////////////////////////////////////////////////////
static int lCreateProcess(lua_State *L) // описываем функцию lCreateProcess на С
{
 char arg1[_512];
 strNcpy(arg1, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 INT arg2 = luaL_checkinteger(L, 2); // получим аргумент (с проверкой "на число")
 INT arg3 = luaL_checkinteger(L, 3);
 INT arg4 = luaL_checkinteger(L, 4);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_CreateProcsess(\"%s\",%d,%d,%d)", arg1, arg2, arg3, arg4 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushnumber(L, c_CreateProcess( arg1, arg2, arg3, arg4 )); // вызовем c_CreateProcess и результат -> стек
 return 1 ; // фикция, но так необходимо для Lua
} // ===== конец lCreateProcess ================================================

////////////////////////////////////////////////////////////////////////////////
static int LuaCallByTimer(lua_State *L) // описываем функцию LuaCallByTimer на С
{
 char arg1[_1024];
 strNcpy(arg1, luaL_checkstring(L, 1)); // получим один аргумент (с проверкой "на строку")
 INT arg2 = luaL_checkinteger(L, 2); // получим аргумент (с проверкой "на число")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_LuaCallByTimer(\"%s\",%d,)", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushnumber(L, c_LuaCallByTimer( arg1, arg2 )); // вызовем FuncCallTimer и результат -> стек
 return 1 ; // фикция, но так необходимо для Lua
} // ===== конец LuaCallByTimer ================================================

////////////////////////////////////////////////////////////////////////////////
static int CalcAverMeanOpsOnTiers(lua_State *L) // описываем функцию c_CalcAverMeanOpsOnTiers на С
{
// INT arg1 = luaL_checkinteger(L, 1), // получим аргумент (с проверкой "на число")
//     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_CalcAverMeanOpsOnTiers()" );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushnumber(L, c_CalcAverMeanOpsOnTiers()); // вызовем c_CalcAverMeanOpsOnTiers и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_CalcAverMeanOpsOnTiers ======================================

////////////////////////////////////////////////////////////////////////////////
static int CalcStdDevOpsOnTiers(lua_State *L) // описываем функцию c_CalcStdDevOpsOnTiers на С
{
// INT arg1 = luaL_checkinteger(L, 1), // получим аргумент (с проверкой "на число")
//     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_CalcStdDevOpsOnTiers()" );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // сброcим стек Lua
 lua_pushnumber(L, c_CalcStdDevOpsOnTiers()); // вызовем c_CalcStdDevOpsOnTiers и результат -> стек
 return 1 ; // число результатов выполнения функции
} // ===== конец c_CalcAverMeanOpsOnTiers ======================================
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void __fastcall RegisterFunctions(lua_State *L)
{ // ----регистрирует С-функции в Lua в экземпляре L ---------------------------
 lua_register(L, "AddTier", AddTier);
 lua_register(L, "DelTier", DelTier);
 lua_register(L, "GetMaxTierMaybeOp", GetMaxTierMaybeOp);
 lua_register(L, "GetMinTierMaybeOp", GetMinTierMaybeOp);
 lua_register(L, "MoveOpTierToTier",  MoveOpTierToTier);
 lua_register(L, "SwapOpsTierToTier", SwapOpsTierToTier);
 lua_register(L, "PutTiersToTextFrame", PutTiersToTextFrame);
 lua_register(L, "PutEdgesToTextFrame", PutEdgesToTextFrame);
 lua_register(L, "ClearTextFrame", ClearTextFrame);
 lua_register(L, "DrawDiagrTiers", DrawDiagrTiers);
 lua_register(L, "DrawDiagrTLD",   DrawDiagrTLD);
 lua_register(L, "ClearDiagrArea", ClearDiagrArea);
 lua_register(L, "DelayMS", DelayMS);
 lua_register(L, "AddLineToTextFrame", AddLineToTextFrame);
 lua_register(L, "GetCountTiers", GetCountTiers);
 lua_register(L, "GetCountOpsOnTier", GetCountOpsOnTier);
 lua_register(L, "GetOpByNumbOnTier", GetOpByNumbOnTier);
 lua_register(L, "SoundPlay", SoundPlay);
 lua_register(L, "CreateTiersByEdges", CreateTiersByEdges);
 lua_register(L, "CreateTiersByEdges_Bottom", CreateTiersByEdges_Bottom);
 lua_register(L, "GetOpsMoves", GetOpsMoves);
 lua_register(L, "CountMovesZeroing", CountMovesZeroing);
 lua_register(L, "GetTierFirstMinOps", GetTierFirstMinOps);
 lua_register(L, "GetTierLastMinOps", GetTierLastMinOps);
 lua_register(L, "GetTierFirstMaxOps", GetTierFirstMaxOps);
 lua_register(L, "GetTierLastMaxOps", GetTierLastMaxOps);
 lua_register(L, "GetCountEdges", GetCountEdges);
 lua_register(L, "GetTierByOp", GetTierByOp);
 lua_register(L, "ReadEdges", ReadEdges);
 lua_register(L, "SaveEdges", SaveEdges);
 lua_register(L, "ReadTiers", ReadTiers);
 lua_register(L, "SaveTiers", SaveTiers);
 lua_register(L, "SaveTiersVizu", SaveTiersVizu);
 lua_register(L, "SaveEdgesVizu", SaveEdgesVizu);
 lua_register(L, "SaveInOutOpVizu", SaveInOutOpVizu);
 lua_register(L, "SaveParamsVizu", SaveParamsVizu);
 lua_register(L, "PutParamsTiers", PutParamsTiers);
 lua_register(L, "GetCountInEdgesByOp", GetCountInEdgesByOp);
 lua_register(L, "GetCountOutEdgesByOp", GetCountOutEdgesByOp);
 lua_register(L, "GetNumbInEdgeByOp", GetNumbInEdgeByOp);
 lua_register(L, "GetNumbOutEdgeByOp", GetNumbOutEdgeByOp);
//
////////////////////////////////////////////////////////////////////////////////
// учёт гетерогенности вычислительного поля ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// сторона вычислителей --------------------------------------------------------
//------------------------------------------------------------------------------
 lua_register(L, "GetParamsByCalc", GetParamsByCalc);
 lua_register(L, "GetCountParamsByCalc", GetCountParamsByCalc);
 lua_register(L, "GetNumbParamByCalc",   GetNumbParamByCalc);
 lua_register(L, "GetNameNumbParamByCalc", GetNameNumbParamByCalc);
 lua_register(L, "GetMinValNumbParamByCalc", GetMinValNumbParamByCalc);
 lua_register(L, "GetMaxValNumbParamByCalc", GetMaxValNumbParamByCalc);
// сторона операторов ----------------------------------------------------------
 lua_register(L, "GetParamsByOp", GetParamsByOp);
 lua_register(L, "GetCountParamsByOp", GetCountParamsByOp);
 lua_register(L, "GetNumbParamByOp",   GetNumbParamByOp);
 lua_register(L, "GetNameNumbParamByOp", GetNameNumbParamByOp);
 lua_register(L, "GetValNumbParamByOp",  GetValNumbParamByOp);
// функции логического вывода о возможности выполнения оператора Op на вычислителе Calc
 lua_register(L, "CanExecOpCalc", CanExecOpCalc );
////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
// функции работы с гетерогенным полем вычислителей ============================
////////////////////////////////////////////////////////////////////////////////
 lua_register(L, "LoadFileNameParamsCalcs", LoadFileNameParamsCalcs);
 lua_register(L, "LoadFileNameParamsOps",   LoadFileNameParamsOps);
 lua_register(L, "LoadFileNameParamsEdges",    LoadFileNameParamsEdges);
 lua_register(L, "LoadFileNameParamsVertices", LoadFileNameParamsVertices);
//
 lua_register(L, "GetCountCalcs", GetCountCalcs);
//
//------------------------------------------------------------------------------
 lua_register(L, "GetCountOps", GetCountOps);
 lua_register(L, "GetNumbOp",   GetNumbOp);
//
 lua_register(L, "GetCountOpsInput", GetCountOpsInput);
 lua_register(L, "GetNumbOpInput",   GetNumbOpInput);
//
 lua_register(L, "GetCountOpsOutput", GetCountOpsOutput);
 lua_register(L, "GetNumbOpOutput",   GetNumbOpOutput);
//
//------------------------------------------------------------------------------
 lua_register(L, "PutParamsAll",           PutParamsAll);
 lua_register(L, "TestCanExecAllOpsCalcs", TestCanExecAllOpsCalcs);
//
// --- окна ввода / вывода -----------------------------------------------------
 lua_register(L, "InputDialog",   InputDialog);
 lua_register(L, "MessageDialog", MessageDialog);
//
// --- аналог ADDLineToTexFrame ------------------------------------------------
 lua_register(L, "OutLine", OutLine);
//
// --- взять МЕТРИКИ ВЕРШИН (операторов) и ДУГ (по имени параметра) ------------
 lua_register(L, "GetMetricOpByName",   GetMetricOpByName);
 lua_register(L, "GetMetricEdgeByName", GetMetricEdgeByName);
//
// выдаёт оператор, информационно зависимый от заданного и находящийся на ярусе
// с максимальным номером (если таких оператор несколько - выдаётся последний по списку)
 lua_register(L, "GetOpByMaxTierLowerPreset", GetOpByMaxTierLowerPreset);
//
// создание и сохранение информации о "времени жизни данных" внутри ЯПФ --------
 lua_register(L, "PutTLDToTextFrame",  PutTLDToTextFrame);
 lua_register(L, "SaveTLD",            SaveTLD);
//
// --- выполнение команд операционной системы ----------------------------------
//
 lua_register(L, "lWinExec",       lWinExec);
 lua_register(L, "lShellExecute",  lShellExecute);
 lua_register(L, "lCreateProcess", lCreateProcess);
//
 lua_register(L, "LuaCallByTimer",   LuaCallByTimer);
//
 lua_register(L, "CalcAverMeanOpsOnTiers", CalcAverMeanOpsOnTiers );
 lua_register(L, "CalcStdDevOpsOnTiers", CalcStdDevOpsOnTiers );
//
} // ---- конец RegisterFunctions ----------------------------------------------


