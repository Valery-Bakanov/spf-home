
void debug_lua_stack(lua_State *L)
{
    int nstack = lua_gettop(L);
    int idx,ltype,len;
    const char* str;
    printf("nstack = %d\n",nstack);
    for (idx = 1; idx <= nstack; idx++) {
        ltype = lua_type(L,idx);
        printf("%d ",idx);
        switch(ltype) {
        case LUA_TNIL:
            printf("<nil>\n"); 
            break;
        case LUA_TNUMBER:
            printf("%f\n",lua_tonumber(L,idx));
            break;
        case LUA_TSTRING:
            str = lua_tolstring(L,idx,&len);
            printf("'%s' [%d]\n",str,len);
            break;
        case LUA_TTABLE:
            printf("table %X\n",lua_topointer(L,idx));
            break;            
        case LUA_TFUNCTION:
            printf("function %X\n",lua_topointer(L,idx));
            break;
        case LUA_TBOOLEAN:
            printf("%s\n",lua_toboolean(L,idx) ? "true" : "false");
            break;
        case LUA_TUSERDATA:
            printf("user %X\n",lua_touserdata(L,idx));
            break;
        case LUA_TLIGHTUSERDATA:
            printf("light user %X\n",lua_touserdata(L,idx));
            break;                        
        case LUA_TTHREAD:
            printf("thread %X\n",lua_tothread(L,idx));
            break;
        }      
    }
}
