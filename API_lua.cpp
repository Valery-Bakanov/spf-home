//
#define APM Application->ProcessMessages(); // ���� ���������� Windows
//
#define strNcpy(d,s) strncpy(d,s,sizeof(d)) // ?????????? ???????????
//
////////////////////////////////////////////////////////////////////////////////
static int AddTier(lua_State *L) // ����� �-������� AddTier �� Lua
{
 INT arg = luaL_checkinteger(L, 1); // ������� ���� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_AddTier(%ld)", (INT)arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_AddTier((INT)arg) ); // ������� c_AddTier() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� AddTier =======================================================

////////////////////////////////////////////////////////////////////////////////
static int DelTier(lua_State *L) // ����� �-������� DelTier �� Lua
{
 INT arg = luaL_checkinteger(L, 1); // ������� ���� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_DelTier(%ld)", (INT)arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_DelTier((INT)arg)); // ������� c_DelTier() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� DelTier =======================================================

////////////////////////////////////////////////////////////////////////////////
static int GetMaxTierMaybeOp(lua_State *L) // ����� �-������� GetMaxTiermayBeOp �� Lua
{
 INT arg = luaL_checkinteger(L, 1); // ������� ���� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetMaxTierMaybeOp(%ld)", (INT)arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetMaxTierMaybeOp((INT)arg)); // ������� c_GetMaxTierMayBeOp() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetMaxTierMayBeOp =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetMinTierMaybeOp(lua_State *L) // ����� �-������� GetMinTiermayBeOp �� Lua
{
 INT arg = luaL_checkinteger(L, 1); // ������� ���� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetMinTierMaybeOp(%ld)", (INT)arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetMinTierMaybeOp((INT)arg)); // ������� c_GetMinTierMaybeOp() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetMinTierMayBeOp =============================================

////////////////////////////////////////////////////////////////////////////////
static int MoveOpTierToTier(lua_State *L) // ����� �-������� MoveOpTierToTier �� Lua
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� 1-� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2); // ������� 2-� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_MoveOpTierToTier(%ld,%ld)", (INT)arg1, (INT)arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_MoveOpTierToTier((INT)arg1, (INT)arg2)); // ������� ����� MoveOpTierToTier � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� MoveOpTierToTier ==============================================

////////////////////////////////////////////////////////////////////////////////
static int SwapOpsTierToTier(lua_State *L) // ����� �-������� SwapOpsTierToTier �� Lua
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� 1-� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2); // ������� 2-� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SwapOpsTierToTier(%ld,%ld)", (INT)arg1, (INT)arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_SwapOpsTierToTier((INT)arg1, (INT)arg2)); // ������� c_SwapOpsTierToTier() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� SwapOpsTierToTier =============================================

////////////////////////////////////////////////////////////////////////////////
static int PutTiersToTextFrame(lua_State *L) // ��������� ������� PutTiersToTextFrame �� �
{
//  INT arg = luaL_checkinteger(L, 1); // ������� ���� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_PutTiersToTextFrame()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_PutTiersToTextFrame()); // ������� c_PutTiersToTextFrame() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� PutTiersToTextFrame =============================================

////////////////////////////////////////////////////////////////////////////////
static int PutEdgesToTextFrame(lua_State *L) // ��������� ������� PutEdgesToTextFrame �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_PutEdgesToTextFrame()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_PutEdgesToTextFrame()); // ������� c_PutEdgesToTextFrame() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� PutEdgesToTextFrame ===========================================

////////////////////////////////////////////////////////////////////////////////
static int ClearTextFrame(lua_State *L) // ��������� ������� ClearTextFrame �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_ClearTextFrame()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_ClearTextFrame()); // ������� c_PutSPSToTextFrame() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� PutSPSToTextFrame =============================================

////////////////////////////////////////////////////////////////////////////////
static int DrawDiagrTiers(lua_State *L) // ��������� ������� DrawDiagrTiers �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_DrawDiagrTiers()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_DrawDiagrTiers()); // ������� c_DrawDiagrTiers() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� c_DrawDiagrTiers ==============================================

////////////////////////////////////////////////////////////////////////////////
static int DrawDiagrTLD(lua_State *L) // ��������� ������� DrawDiagrTLD �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_DrawDiagrTLD()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_DrawDiagrTLD()); // ������� c_DrawDiagrTLD() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� c_DrawDiagrTLD ================================================

////////////////////////////////////////////////////////////////////////////////
static int PutParamsTiers(lua_State *L) // ��������� ������� PutParamsTiers �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call PutParamsTiers()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_PutParamsTiers()); // ������� PutParamsTiers � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� PutParamsTiers ================================================

////////////////////////////////////////////////////////////////////////////////
static int ClearDiagrArea(lua_State *L) // ��������� ������� ClearDiagrArea �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_ClearDiagrArea()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_ClearDiagrArea()); // ������� c_ClearDiagrArea() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� c_ClearDiagrArea =============================================

////////////////////////////////////////////////////////////////////////////////
static int DelayMS(lua_State *L) // ��������� ������� DelayMS �� �
{
 INT arg = luaL_checkinteger(L, 1); // ������� ���� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_DelayMS(%ld)", (INT)arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_DelayMS((INT)arg)); // ������� c_DelayMS() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� c_DelayMS =====================================================

////////////////////////////////////////////////////////////////////////////////
static int AddLineToTextFrame(lua_State *L) // ��������� ������� AddLineToTextFrame �� �
{
 char arg[_4096];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_AddLineToTextFrame(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_AddLineToTextFrame(arg)); // ������� c_AddLineToTextFrame() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� c_AddLineToTextFrame ==========================================

////////////////////////////////////////////////////////////////////////////////
static int OutLine(lua_State *L) // ��������� ������� OutLine �� �
{
 char arg[_4096];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_AddLineToTextFrame(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_AddLineToTextFrame(arg)); // ������� c_AddLineToTextFrame() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� c_OutLine =====================================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountTiers(lua_State *L) // ��������� ������� GetCountTiers �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountTiers()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetCountTiers()); // ������� c_GetCountTiers � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetCountTiers =================================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountOpsOnTier(lua_State *L) // ��������� ������� GetCountOpsOnTier �� �
{
 INT arg = luaL_checkinteger(L, 1); // ������� ���� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountOpsOnTier(%ld)",(INT)arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetCountOpsOnTier((INT)arg)); // ������� c_GetCountOpsOnTier � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetCountOpsOnTier =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetOpByNumbOnTier(lua_State *L) // ��������� ������� GetOpByNumbOnTier �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� ���� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2); // ������� ������ �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetOpByNumbOnTier(%ld,%ld)", (INT)arg1, (INT)arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetOpByNumbOnTier((INT)arg1, (INT)arg2)); // ������� c_GetOpByNumbOnTier � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetOpByNumbOnTier =============================================

////////////////////////////////////////////////////////////////////////////////
static int SoundPlay(lua_State *L) // ����� �-������� c_SoundPlay �� Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SoundPlay(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_SoundPlay(arg)); // ������� c_SoundPlay() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� SoundPlay =====================================================

////////////////////////////////////////////////////////////////////////////////
static int CreateTiersByEdges(lua_State *L) // ��������� ������� CreateTiersByEdges �� �
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 sp_printf(" Lua call c_CreateTiersByEdges(\"%s\")", arg );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_CreateTiersByEdges( arg )); // ������� c_CreateTiersByEdges � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� CreateTiersByEdges ============================================

////////////////////////////////////////////////////////////////////////////////
static int CreateTiersByEdges_Bottom(lua_State *L) // ��������� ������� CreateTiersByEdges_Bottom �� �
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 sp_printf(" Lua call c_CreateTiersByEdges_Bottom(\"%s\")", arg );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_CreateTiersByEdges_Bottom( arg )); // ������� c_CreateTiersByEdges_Bottom � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� CreateTiersByEdges_Bottom =====================================

////////////////////////////////////////////////////////////////////////////////
static int GetOpsMoves(lua_State *L) // ��������� ������� GetOpsMoves �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetOpsMoves()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetOpsMoves()); // ������� c_GetOpsMoves � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetOpsMoves ===================================================

////////////////////////////////////////////////////////////////////////////////
static int CountMovesZeroing(lua_State *L) // ��������� ������� CountMovesZeroing �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_CountMovesZeroing()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_CountMovesZeroing()); // ������� c_CountMovesZeroing � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� CountMovesZeroing =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetTierFirstMinOps(lua_State *L) // ��������� ������� GetTierFirstMinOps �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� ���� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2); // ������� ������ �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetTierFirstMinOps(%ld,%ld)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetTierFirstMinOps(arg1,arg2)); // ������� c_GetTierFirstMinOps � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetTierFirstMinOps ============================================

////////////////////////////////////////////////////////////////////////////////
static int GetTierLastMinOps(lua_State *L) // ��������� ������� GetTierLastMinOps �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� ���� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2); // ������� ������ �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetTierLastMinOps(%ld,%ld)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetTierLastMinOps(arg1, arg2)); // ������� c_GetTierLastMinOps � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetTierLastMinOps =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetTierFirstMaxOps(lua_State *L) // ��������� ������� GetTierFirstMaxOps �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� ���� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2); // ������� ������ �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetTierFirstMaxOps(%ld,%ld)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetTierFirstMaxOps(arg1, arg2)); // ������� c_GetTierFirstMaxOps � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetTierFirstMaxOps ============================================

////////////////////////////////////////////////////////////////////////////////
static int GetTierLastMaxOps(lua_State *L) // ��������� ������� GetTierLastMaxOps �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� ���� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2); // ������� ������ �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetTierLastMaxOps(%ld,%ld)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetTierLastMaxOps(arg1, arg2)); // ������� c_GetTierLastMaxOps � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetTierLastMaxOps =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountOpsInput(lua_State *L) // ��������� ������� GetCountOpsInput �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountOpsInput()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetCountOpsInput()); // ������� c_GetCountOpsInput � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetCountOpsInput ==============================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountOpsOutput(lua_State *L) // ��������� ������� GetCountOpsOutput �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountOpsOutput()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetCountOpsOutput()); // ������� c_GetCountOpsOutput � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetCountOpsOutput =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountOps(lua_State *L) // ��������� ������� GetCountOps �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountOps()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetCountOps()); // ������� c_GetCountOps � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetCountOps ===================================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountEdges(lua_State *L) // ��������� ������� GetCountEdges �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountEdges()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetCountEdges()); // ������� c_GetCountEdges � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetCountEdges =================================================

////////////////////////////////////////////////////////////////////////////////
static int GetTierByOp(lua_State *L) // ��������� ������� IsOpExistEdge �� �
{
 INT arg = luaL_checkinteger(L, 1); // ������� ���� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetTierByOp(%ld)", arg );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetTierByOp( arg )); // ������� c_GetTierByOp � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetTierByOp  ==================================================

////////////////////////////////////////////////////////////////////////////////
static int ReadEdges(lua_State *L) // ����� �-������� c_ReadEdges �� Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_ReadEdges(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_ReadEdges( arg )); // ������� c_ReadEdges � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� ReadEdges =====================================================

////////////////////////////////////////////////////////////////////////////////
static int SaveEdges(lua_State *L) // ����� �-������� c_SaveEdges �� Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveEdges(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_SaveEdges( arg )); // ������� c_SaveEdges � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� SaveEdges =====================================================

////////////////////////////////////////////////////////////////////////////////
static int ReadTiers(lua_State *L) // ����� �-������� c_ReadTiers �� Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_ReadTiers(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_ReadTiers( arg )); // ������� c_ReadTiers � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� ReadTiers =====================================================

////////////////////////////////////////////////////////////////////////////////
static int SaveTiers(lua_State *L) // ����� �-������� c_SaveTiers �� Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveTiers(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_SaveTiers( arg )); // ������� c_SaveTiers � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� SaveTiers =====================================================

////////////////////////////////////////////////////////////////////////////////
static int SaveEdgesVizu(lua_State *L) // ����� �-������� c_SaveEdgesVizu �� Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveEdgesVizu(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_SaveEdgesVizu( arg )); // ������� c_SaveEdgesVizu � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� SaveEdgesVizu =================================================

////////////////////////////////////////////////////////////////////////////////
static int SaveTiersVizu(lua_State *L) // ����� �-������� c_SaveTiersVizu �� Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveTiersVizu(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_SaveTiersVizu( arg )); // ������� c_SaveTiersVizu � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� SaveTiersVizu =================================================

////////////////////////////////////////////////////////////////////////////////
static int SaveInOutOpVizu(lua_State *L) // ����� �-������� c_SaveInOutOpVizu �� Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveInOutOpVizu(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_SaveInOutOpVizu( arg )); // ������� c_SaveInOutOpVizu � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� SaveInOutOpVizu =================================================

////////////////////////////////////////////////////////////////////////////////
static int SaveParamsVizu(lua_State *L) // ����� �-������� c_SaveParamsVizu �� Lua
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveParamsVizu(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_SaveParamsVizu( arg )); // ������� c_SaveParamsVizu � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� SaveParamsVizu =================================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountInEdgesByOp(lua_State *L) // ��������� ������� GetCountInEdgesByOp �� �
{
 INT arg = luaL_checkinteger(L, 1); // ������� ���� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountInEdgesByOp(%ld)", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetCountInEdgesByOp( arg )); // ������� c_GetCountInEdgesByOp � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetCountOutEdgesByOp ==========================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountOutEdgesByOp(lua_State *L) // ��������� ������� GetCountOutEdgesByOp �� �
{
 INT arg = luaL_checkinteger(L, 1); // ������� ���� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountOutEdgesByOp(%ld)", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetCountOutEdgesByOp( arg )); // ������� c_GetCountOutEdgesByOp � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetCountOutEdgesByOp ==========================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbInEdgeByOp(lua_State *L) // ��������� ������� GetNumbInEdgeByOp �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� ��������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbInEdgeByOp(%ld,%ld)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetNumbInEdgeByOp( arg1, arg2 )); // ������� c_GetNumbInEdgeByOp � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetNumbInEdgeByOp =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbOutEdgeByOp(lua_State *L) // ��������� ������� GetNumbOutEdgeByOp �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� ��������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbOutEdgeByOp(%ld,%ld)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetNumbOutEdgeByOp( arg1, arg2 )); // ������� c_GetNumbOutEdgeByOp � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetNumbOutEdgeByOp ============================================

////////////////////////////////////////////////////////////////////////////////
// ���� �������������� ��������������� ���� ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// ������� ������������ --------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
static int GetParamsByCalc(lua_State *L) // ��������� ������� GetParamsByCalc �� �
{
 INT arg1 = luaL_checkinteger(L, 1); // ������� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetParamsByCalc( %ld )", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushstring(L, c_GetParamsByCalc( arg1 )); // ������� c_GettParamsByCalc � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetParamsByCalc ===============================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountParamsByCalc(lua_State *L) // ��������� ������� GetCountParamsByCalc�� �
{
 INT arg1 = luaL_checkinteger(L, 1); // ������� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountParamsByCalc( %ld )", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetCountParamsByCalc( arg1 )); // ������� c_GettParamsByCalc � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetCountParamsByCalc ==========================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbParamByCalc(lua_State *L) // ��������� ������� GetNumbParamByCalc �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbParamByCalc( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushstring(L, c_GetNumbParamByCalc( arg1, arg2 )); // ������� c_GetNumbParamByCalc � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetNumbParamByCalc ============================================

////////////////////////////////////////////////////////////////////////////////
static int GetNameNumbParamByCalc(lua_State *L) // ��������� ������� GetNumbParamByCalc �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNameNumbParamByCalc( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushstring(L, c_GetNameNumbParamByCalc( arg1, arg2 )); // ������� c_GetNameNumbParamByCalc � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� c_GetNameNumbParamByCalc ======================================

////////////////////////////////////////////////////////////////////////////////
static int GetMinValNumbParamByCalc(lua_State *L) // ��������� ������� c_GetMinValNumbParamByCalc �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetMinValNumbParamByCalc( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushnumber(L, c_GetMinValNumbParamByCalc( arg1, arg2 )); // ������� c_GetMinValNumbParamByCalc � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� c_GetMinValNumbParamByCalc ====================================

////////////////////////////////////////////////////////////////////////////////
static int GetMaxValNumbParamByCalc(lua_State *L) // ��������� ������� c_GetMaxValNumbParamByCalc �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetMaxValNumbParamByCalc( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushnumber(L, c_GetMaxValNumbParamByCalc( arg1, arg2 )); // ������� c_GetMaxValNumbParamByCalc � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� c_GetMaxValNumbParamByCalc ====================================

////////////////////////////////////////////////////////////////////////////////
// ������� ����������
////////////////////////////////////////////////////////////////////////////////
static int GetParamsByOp(lua_State *L) // ��������� ������� GetParamsByOp �� �
{
 INT arg1 = luaL_checkinteger(L, 1); // ������� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetParamsByOp( %ld )", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushstring(L, c_GetParamsByOp( arg1 )); // ������� c_GettParamsByOp � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetParamsByOp =================================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountParamsByOp(lua_State *L) // ��������� ������� GetCountParamsByOp �� �
{
 INT arg1 = luaL_checkinteger(L, 1); // ������� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountParamsByOp( %ld )", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetCountParamsByOp( arg1 )); // ������� c_GettParamsByOp � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetCountParamsByOp ============================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbParamByOp(lua_State *L) // ��������� ������� GetNumbParamByOp �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbParamByOp( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushstring(L, c_GetNumbParamByOp( arg1, arg2 )); // ������� c_GetNumbParamByOp � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetNumbParamByOp ==============================================

////////////////////////////////////////////////////////////////////////////////
static int GetNameNumbParamByOp(lua_State *L) // ��������� ������� GetNameNumbParamByOp �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNameNumbParamByOp( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushstring(L, c_GetNameNumbParamByOp( arg1, arg2 )); // ������� c_GetNameNumbParamByOp � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� c_GetNameNumbParamByOp ========================================

////////////////////////////////////////////////////////////////////////////////
static int GetValNumbParamByOp(lua_State *L) // ��������� ������� c_GetValNumbParamByOp �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetValNumbParamByOp( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushnumber(L, c_GetValNumbParamByOp( arg1, arg2 )); // ������� c_GetValNumbParamByOp � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� c_GetValNumbParamByOp =========================================

////////////////////////////////////////////////////////////////////////////////
// ������� ����������� ������ � ����������� ���������� ��������� Op �� ����������� Calc
////////////////////////////////////////////////////////////////////////////////
static int CanExecOpCalc(lua_State *L) // ��������� ������� CanExecOpCalc �� �
{
 INT arg1 = luaL_checkinteger(L, 1), // ������� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_CanExecOpCalc( %ld, %ld )", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_CanExecOpCalc( arg1, arg2 )); // ������� c_CanExecOpCalc � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� CanExecOpCalc =================================================

////////////////////////////////////////////////////////////////////////////////
// ������� ������ � ������������ ����� ������������ ============================
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
static int LoadFileNameParamsCalcs(lua_State *L) // ��������� ������� LoadFileNameParamsCalcs �� �
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_LoadFileNameParamsCalcs(\"%s\")",arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_LoadFileNameParamsCalcs( arg )); // ������� c_LoadFileNameParamsCalcs � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� LoadFileNameParamsCalcs ========================================

////////////////////////////////////////////////////////////////////////////////
static int LoadFileNameParamsOps(lua_State *L) // ��������� ������� LoadFileNameParamsOps �� �
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_LoadFileNameParamsOps(\"%s\")",arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_LoadFileNameParamsOps( arg )); // ������� c_LoadFileNameParamsOps � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� LoadFileNameParamsOps =========================================

////////////////////////////////////////////////////////////////////////////////
static int LoadFileNameParamsEdges(lua_State *L) // ��������� ������� LoadFileNameParamsEdges �� �
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_LoadFileNameParamsEdges(\"%s\")",arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_LoadFileNameParamsEdges( arg )); // ������� c_LoadFileNameParamsEdges � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� LoadFileNameParamsEdges =======================================

////////////////////////////////////////////////////////////////////////////////
static int LoadFileNameParamsVertices(lua_State *L) // ��������� ������� LoadFileNameParamsVertices �� �
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_LoadFileNameParamsVertices(\"%s\")",arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_LoadFileNameParamsVertices( arg )); // ������� c_LoadFileNameParamsVertices � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� LoadFileNameParamsVertices ====================================

////////////////////////////////////////////////////////////////////////////////
static int GetCountCalcs(lua_State *L) // ��������� ������� GetCountCalcs �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetCountCalcs()" );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetCountCalcs( )); // ������� c_GetCountCalcs � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetCountCalcs =================================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbOpInput(lua_State *L) // ��������� ������� GetNumbOpInput �� �
{
 INT arg1 = luaL_checkinteger(L, 1); // ������� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbOpInput( %ld )", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetNumbOpInput( arg1 )); // ������� c_GetNumbOpInput � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetNumbOpInput ================================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbOpOutput(lua_State *L) // ��������� ������� GetNumbOpOutput �� �
{
 INT arg1 = luaL_checkinteger(L, 1); // ������� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbOpOutput( %ld )", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetNumbOpOutput( arg1 )); // ������� c_GetNumbOpOutput � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetNumbOpOutput ===============================================

////////////////////////////////////////////////////////////////////////////////
static int GetNumbOp(lua_State *L) // ��������� ������� GetNumbOp �� �
{
 INT arg1 = luaL_checkinteger(L, 1); // ������� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetNumbOp(%ld)", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_GetNumbOp( arg1 )); // ������� c_GetNumbOp � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� GetNumbOp =====================================================

////////////////////////////////////////////////////////////////////////////////
// --- ������� ������������ ���������� ����������, ������������ � ��������� ----
////////////////////////////////////////////////////////////////////////////////
static int TestCanExecAllOpsCalcs(lua_State *L) // ��������� ������� TestCanExecAllOpsCalcs �� �
{
 INT arg1 = luaL_checkinteger(L, 1); // ������� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_TestCanExecAllOpsCalcs( %ld )", arg1 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_TestCanExecAllOpsCalcs(arg1)); // ������� c_TestCanExecAllOpsCalcs � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� TestCanExecAllOpsCalcs ========================================

////////////////////////////////////////////////////////////////////////////////
static int PutParamsAll(lua_State *L) // ��������� ������� PutParamsAll �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_PutParamsAll()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_PutParamsAll()); // ������� c_PutParamsAll � ��������� -> ����
 return 1 ; // ������, �� ��� ���������� ��� Lua
} // ===== ����� PutParamsAll ==================================================

////////////////////////////////////////////////////////////////////////////////
// --- ������ � ����������� �������� -------------------------------------------
////////////////////////////////////////////////////////////////////////////////
static int InputDialog(lua_State *L) // ��������� ������� InputBox �� �
{
 char arg1[_512], arg2[_512], arg3[_512];
 strNcpy(arg1, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 strNcpy(arg2, luaL_checkstring(L, 2));
 strNcpy(arg3, luaL_checkstring(L, 3));
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_InputBox(\"%s\",\"%s\",\"%s\")", arg1,arg2,arg3);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushstring(L, c_InputDialog( arg1,arg2,arg3 )); // ������� c_InputDialog � ��������� -> ����
 return 1 ; // ������, �� ��� ���������� ��� Lua
} // ===== ����� InputDialog ===================================================

////////////////////////////////////////////////////////////////////////////////
static int MessageDialog(lua_State *L) // ��������� ������� MessageDialog �� �
{
 char arg1[_512], arg2[_512], arg3[_512];
 strNcpy(arg1, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 strNcpy(arg2, luaL_checkstring(L, 2));
 strNcpy(arg3, luaL_checkstring(L, 3));
 INT  arg4 = luaL_checkinteger(L, 4); // ������� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_MessageDialog(\"%s\",\"%s\",\"%s\",%d)", arg1,arg2,arg3,arg4);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushinteger(L, c_MessageDialog( arg1,arg2,arg3,arg4 )); // ������� c_MessageDialog � ��������� -> ����
 return 1 ; // ������, �� ��� ���������� ��� Lua
} // ===== ����� MessageDialog =================================================

////////////////////////////////////////////////////////////////////////////////
static int GetMetricOpByName(lua_State *L) // ��������� ������� GetMetricOpByName �� �
{
 char arg2[_512];
 INT arg1 = luaL_checkinteger(L, 1); // ������� �������� (� ��������� "�� �����")
 strNcpy(arg2, luaL_checkstring(L, 2)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetMetricOpByName(%d,\"%s\")", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushnumber(L, c_GetMetricOpByName( arg1, arg2 )); // ������� c_GetMetricOpByName � ��������� -> ����
 return 1 ; // ������, �� ��� ���������� ��� Lua
} // ===== ����� GetMetricOpByName =============================================

////////////////////////////////////////////////////////////////////////////////
static int GetMetricEdgeByName(lua_State *L) // ��������� ������� GetMetricEdgeByName �� �
{
 char arg3[_512];
 INT arg1 = luaL_checkinteger(L, 1), // ������� �������� (� ��������� "�� �����")
     arg2 = luaL_checkinteger(L, 2);
 strNcpy(arg3, luaL_checkstring(L, 3)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetMetricEdgeByName(%d,%d,\"%s\")", arg1, arg2, arg3);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushnumber(L, c_GetMetricEdgeByName( arg1, arg2, arg3 )); // ������� c_GetMetricEdgeByName � ��������� -> ����
 return 1 ; // ������, �� ��� ���������� ��� Lua
} // ===== ����� GetMetricEdgeByName ===========================================

////////////////////////////////////////////////////////////////////////////////
static int GetOpByMaxTierLowerPreset(lua_State *L) // ��������� ������� GetOpByMaxTierLowerPreset �� �
{
 INT arg = luaL_checkinteger(L, 1); // ������� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_GetOpByMaxTierLowerPreset(%d)", arg );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushnumber(L, c_GetOpByMaxTierLowerPreset( arg )); // ������� c_GetOpByMaxTierLowerPreset � ��������� -> ����
 return 1 ; // ������, �� ��� ���������� ��� Lua
} // ===== ����� GetOpByMaxTierLowerPreset =====================================

////////////////////////////////////////////////////////////////////////////////
static int PutTLDToTextFrame(lua_State *L) // ��������� ������� PutTLDToTextFrame �� �
{
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call PutTLDToTextFrame()");
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushnumber(L, c_PutTLDToTextFrame()); // ������� �_PutTLDToTextFrame � ��������� -> ����
 return 1 ; // ������, �� ��� ���������� ��� Lua
} // ===== ����� PutTLDToTextFrame =============================================

////////////////////////////////////////////////////////////////////////////////
static int SaveTLD(lua_State *L) // ��������� ������� SaveTLD �� �
{
 char arg[_1024];
 strNcpy(arg, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_SaveTLD(\"%s\")", arg);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushboolean(L, c_SaveTLD(arg)); // ������� c_SaveTLD() � ��������� -> ����
 return 1 ; // ����� ����������� ���������� �������
} // ===== ����� c_SaveTLD =====================================================

////////////////////////////////////////////////////////////////////////////////
static int lWinExec(lua_State *L) // ��������� ������� lWinExec �� �
{
 char arg1[_512];
 strNcpy(arg1, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 INT arg2 = luaL_checkinteger(L, 2); // ������� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_WinExec(\"%s\",%d)", arg1, arg2);
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushnumber(L, c_WinExec( arg1, arg2 )); // ������� c_WinExec � ��������� -> ����
 return 1 ; // ������, �� ��� ���������� ��� Lua
} // ===== ����� lWinExec ======================================================

////////////////////////////////////////////////////////////////////////////////
static int lShellExecute(lua_State *L) // ��������� ������� lShellExecute �� �
{
 char arg1[_512], arg2[_512], arg3[_512], arg4[_512];
 strNcpy(arg1, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 strNcpy(arg2, luaL_checkstring(L, 2));
 strNcpy(arg3, luaL_checkstring(L, 3));
 strNcpy(arg4, luaL_checkstring(L, 4));
 INT arg5 = luaL_checkinteger(L, 5); // ������� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_lShellExecute(\"%s\",\"%s\",\"%s\",\"%s\",%d)", arg1, arg2, arg3, arg4, arg5 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushnumber(L, c_ShellExecute( arg1, arg2, arg3, arg4, arg5 )); // ������� c_lShellExecute � ��������� -> ����
 return 1 ; // ������, �� ��� ���������� ��� Lua
} // ===== ����� lShellExecute =================================================

////////////////////////////////////////////////////////////////////////////////
static int lCreateProcess(lua_State *L) // ��������� ������� lCreateProcess �� �
{
 char arg1[_512];
 strNcpy(arg1, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 INT arg2 = luaL_checkinteger(L, 2); // ������� �������� (� ��������� "�� �����")
 INT arg3 = luaL_checkinteger(L, 3);
 INT arg4 = luaL_checkinteger(L, 4);
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_CreateProcsess(\"%s\",%d,%d,%d)", arg1, arg2, arg3, arg4 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushnumber(L, c_CreateProcess( arg1, arg2, arg3, arg4 )); // ������� c_CreateProcess � ��������� -> ����
 return 1 ; // ������, �� ��� ���������� ��� Lua
} // ===== ����� lCreateProcess ================================================

////////////////////////////////////////////////////////////////////////////////
static int LuaCallByTimer(lua_State *L) // ��������� ������� LuaCallByTimer �� �
{
 char arg1[_1024];
 strNcpy(arg1, luaL_checkstring(L, 1)); // ������� ���� �������� (� ��������� "�� ������")
 INT arg2 = luaL_checkinteger(L, 2); // ������� �������� (� ��������� "�� �����")
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_LuaCallByTimer(\"%s\",%d,)", arg1, arg2 );
 APM //-------------------------------------------------------------------------
 lua_settop(L, 0); // ����c�� ���� Lua
 lua_pushnumber(L, c_LuaCallByTimer( arg1, arg2 )); // ������� FuncCallTimer � ��������� -> ����
 return 1 ; // ������, �� ��� ���������� ��� Lua
} // ===== ����� LuaCallByTimer ================================================

////////////////////////////////////////////////////////////////////////////////
static int CalcParamsTiers(lua_State *L) // ��������� ������� c_CalcParamsTiers �� �
{
 INT arg1 = luaL_checkinteger(L, 1); // ������� �������� (� ��������� "�� �����")
 arg1 = ( arg1 <= 0 ) ? 0 : arg1 ;
 arg1 = ( arg1 > sizeof(StatTiers)/sizeof(REAL) ) ? sizeof(StatTiers)/sizeof(REAL) : arg1 ;
 APM //-------------------------------------------------------------------------
 sp_printf(" Lua call c_CalcStatParamsSPF()" );
 APM //-------------------------------------------------------------------------
//
 c_CalcParamsTiers() ; // ��������� ������������� ��������� SPF � ������� �� � ��������� StatTiers
//
 lua_settop(L, 0); // ����c�� ���� Lua
//
 switch( arg1 )
 {
  case 0:
   lua_pushnumber(L, StatTiers.averWidth ); // �������������������� ������ ��� (����� 0-�� ������)
   lua_pushnumber(L, StatTiers.sumSqWidth); // ����� ��������� �������
   lua_pushnumber(L, StatTiers.SD); // ��� (Standard Deviation)
   lua_pushnumber(L, StatTiers.CV); // ����������� ���������� ����� ���������� �� ������ ���
   lua_pushnumber(L, StatTiers.IC); // ����������� ��������������� (max/min)
   lua_pushnumber(L, StatTiers.ICL); // ����������� ��������������� (�� ������ �������)
   lua_pushnumber(L, StatTiers.AAL); // �������������������� ����� ���� (Average Arc Length)
   return sizeof(StatTiers)/sizeof(REAL) ; // ����� ����� �� ����� Lua
  case 1:
   lua_pushnumber(L, StatTiers.averWidth );
   return 1 ;
  case 2:
   lua_pushnumber(L, StatTiers.sumSqWidth);
   return 1 ;
  case 3:
   lua_pushnumber(L, StatTiers.SD);
   return 1 ;
  case 4:
   lua_pushnumber(L, StatTiers.CV);
   return 1 ;
  case 5:
   lua_pushnumber(L, StatTiers.IC);
   return 1 ;
  case 6:
   lua_pushnumber(L, StatTiers.ICL);
   return 1 ;
  case 7:
   lua_pushnumber(L, StatTiers.ICL);
   return 1 ;
  } // �����  switch( arg1 )
//
} // ===== ����� c_CalcStatParamsSPF ===========================================

//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void __fastcall RegisterFunctions(lua_State *L)
{ // ----������������ �-������� � Lua � ���������� L ---------------------------
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
// ���� �������������� ��������������� ���� ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// ������� ������������ --------------------------------------------------------
//------------------------------------------------------------------------------
 lua_register(L, "GetParamsByCalc", GetParamsByCalc);
 lua_register(L, "GetCountParamsByCalc", GetCountParamsByCalc);
 lua_register(L, "GetNumbParamByCalc",   GetNumbParamByCalc);
 lua_register(L, "GetNameNumbParamByCalc", GetNameNumbParamByCalc);
 lua_register(L, "GetMinValNumbParamByCalc", GetMinValNumbParamByCalc);
 lua_register(L, "GetMaxValNumbParamByCalc", GetMaxValNumbParamByCalc);
// ������� ���������� ----------------------------------------------------------
 lua_register(L, "GetParamsByOp", GetParamsByOp);
 lua_register(L, "GetCountParamsByOp", GetCountParamsByOp);
 lua_register(L, "GetNumbParamByOp",   GetNumbParamByOp);
 lua_register(L, "GetNameNumbParamByOp", GetNameNumbParamByOp);
 lua_register(L, "GetValNumbParamByOp",  GetValNumbParamByOp);
// ������� ����������� ������ � ����������� ���������� ��������� Op �� ����������� Calc
 lua_register(L, "CanExecOpCalc", CanExecOpCalc );
////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
// ������� ������ � ������������ ����� ������������ ============================
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
// --- ���� ����� / ������ -----------------------------------------------------
 lua_register(L, "InputDialog",   InputDialog);
 lua_register(L, "MessageDialog", MessageDialog);
//
// --- ������ ADDLineToTexFrame ------------------------------------------------
 lua_register(L, "OutLine", OutLine);
//
// --- ����� ������� ������ (����������) � ��� (�� ����� ���������) ------------
 lua_register(L, "GetMetricOpByName",   GetMetricOpByName);
 lua_register(L, "GetMetricEdgeByName", GetMetricEdgeByName);
//
// ����� ��������, ������������� ��������� �� ��������� � ����������� �� �����
// � ������������ ������� (���� ����� �������� ��������� - ������� ��������� �� ������)
 lua_register(L, "GetOpByMaxTierLowerPreset", GetOpByMaxTierLowerPreset);
//
// �������� � ���������� ���������� � "������� ����� ������" ������ ��� --------
 lua_register(L, "PutTLDToTextFrame",  PutTLDToTextFrame);
 lua_register(L, "SaveTLD",            SaveTLD);
//
// --- ���������� ������ ������������ ������� ----------------------------------
//
 lua_register(L, "lWinExec",       lWinExec);
 lua_register(L, "lShellExecute",  lShellExecute);
 lua_register(L, "lCreateProcess", lCreateProcess);
//
 lua_register(L, "LuaCallByTimer",   LuaCallByTimer);
//
 lua_register(L, "CalcParamsTiers",  CalcParamsTiers );
//
} // ---- ����� RegisterFunctions ----------------------------------------------


