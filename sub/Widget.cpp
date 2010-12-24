#include "mimas/Widget.h"

#include "lua_cpp_helper.h"


using namespace mimas;


/* ============================ Constructors     ====================== */

/** mimas::Widget::Widget()
 * include/mimas/Widget.h:45
 */
static int Widget_Widget(lua_State *L) {
  try {
    Widget * retval__ = new Widget();
    lua_pushclass<Widget>(L, retval__, "mimas.Widget");
    return 1;
  } catch (std::exception &e) {
    std::string *s = new std::string("mimas.Widget.Widget: ");
    s->append(e.what());
    lua_pushstring(L, s->c_str());
    delete s;
    lua_error(L);
    // never reached
    return 0;
  } catch (...) {
    lua_pushstring(L, "mimas.Widget.Widget: Unknown exception");
    lua_error(L);
    return 0;
  }
}

/* ============================ Destructor       ====================== */

static int Widget_destructor(lua_State *L) {
  Widget **userdata = (Widget**)luaL_checkudata(L, 1, "mimas.Widget");
  if (*userdata) delete *userdata;
  *userdata = NULL;
  return 0;
}

/* ============================ tostring         ====================== */

static int Widget__tostring(lua_State *L) {
  Widget **userdata = (Widget**)luaL_checkudata(L, 1, "mimas.Widget");
  
  lua_pushfstring(L, "<mimas.Widget: %p>", *userdata);
  
  return 1;
}

/* ============================ Member Methods   ====================== */


/** void mimas::Widget::resize(int w, int h)
 * include/mimas/Widget.h:49
 */
static int Widget_resize(lua_State *L) {
  try {
    Widget *self__ = *((Widget**)luaL_checkudata(L, 1, "mimas.Widget"));
    lua_remove(L, 1);
    int w = luaL_checkint(L, 1);
    int h = luaL_checkint(L, 2);
    self__->resize(w, h);
    return 0;
  } catch (std::exception &e) {
    std::string *s = new std::string("mimas.Widget.resize: ");
    s->append(e.what());
    lua_pushstring(L, s->c_str());
    delete s;
    lua_error(L);
    // never reached
    return 0;
  } catch (...) {
    lua_pushstring(L, "mimas.Widget.resize: Unknown exception");
    lua_error(L);
    return 0;
  }
}


/** void mimas::Widget::show()
 * include/mimas/Widget.h:53
 */
static int Widget_show(lua_State *L) {
  try {
    Widget *self__ = *((Widget**)luaL_checkudata(L, 1, "mimas.Widget"));
    lua_remove(L, 1);
    self__->show();
    return 0;
  } catch (std::exception &e) {
    std::string *s = new std::string("mimas.Widget.show: ");
    s->append(e.what());
    lua_pushstring(L, s->c_str());
    delete s;
    lua_error(L);
    // never reached
    return 0;
  } catch (...) {
    lua_pushstring(L, "mimas.Widget.show: Unknown exception");
    lua_error(L);
    return 0;
  }
}




/* ============================ Lua Registration ====================== */

static const struct luaL_Reg Widget_member_methods[] = {
  {"resize"            , Widget_resize},
  {"show"              , Widget_show},
  {"__tostring"        , Widget__tostring},
  {"__gc"              , Widget_destructor},
  {NULL, NULL},
};

static const struct luaL_Reg Widget_namespace_methods[] = {
  {"Widget"            , Widget_Widget},
  {NULL, NULL},
};



#ifdef DUB_LUA_NO_OPEN
int luaload_mimas_Widget(lua_State *L) {
#else
extern "C" int luaopen_mimas_Widget(lua_State *L) {
#endif
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.Widget");

  // metatable.__index = metatable (find methods in the table itself)
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");

  // register member methods
  luaL_register(L, NULL, Widget_member_methods);

  // register class methods in a global namespace table
  luaL_register(L, "mimas", Widget_namespace_methods);


	return 1;
}
