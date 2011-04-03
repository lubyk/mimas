#include "mimas/TableView.h"

#include "lua_cpp_helper.h"


using namespace mimas;


/* ============================ Constructors     ====================== */

/** mimas::TableView::TableView(lubyk::Worker *worker)
 * include/mimas/TableView.h:77
 */
static int TableView_TableView(lua_State *L) {
  try {
    lubyk::Worker *worker = *((lubyk::Worker **)luaL_checkudata(L, 1, "lubyk.Worker"));
    TableView * retval__ = new TableView(worker);
    lua_pushclass2<TableView>(L, retval__, "mimas.TableView");
    return 1;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.TableView: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.TableView: Unknown exception");
  }
}


/* ============================ Destructor       ====================== */

static int TableView_destructor(lua_State *L) {
  TableView **userdata = (TableView**)luaL_checkudata(L, 1, "mimas.TableView");

  
  // custom destructor
  if (*userdata) (*userdata)->dub_destroy();
  
  *userdata = NULL;
  return 0;
}




// test if class is deleted
static int TableView_deleted(lua_State *L) {
  TableView **userdata = (TableView**)luaL_checkudata(L, 1, "mimas.TableView");
  lua_pushboolean(L, *userdata == NULL);
  return 1;
}

/* ============================ tostring         ====================== */

static int TableView__tostring(lua_State *L) {
  TableView **userdata = (TableView**)luaL_checkudata(L, 1, "mimas.TableView");
  
  if (!*userdata) {
    lua_pushstring(L, "<mimas.TableView: NULL>");
    return 1;
  }
  
  
  lua_pushfstring(L, "<mimas.TableView: %p>", *userdata);
  
  return 1;
}

/* ============================ Member Methods   ====================== */


/** void mimas::TableView::__newindex(lua_State *L)
 * include/mimas/TableView.h:249
 */
static int TableView___newindex(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in __newindex");
    
    self__->__newindex(L);
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.__newindex: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.__newindex: Unknown exception");
  }
}


/** bool mimas::TableView::close()
 * include/mimas/TableView.h:198
 */
static int TableView_close(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in close");
    bool  retval__ = self__->close();
    lua_pushboolean(L, retval__);
    return 1;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.close: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.close: Unknown exception");
  }
}


/** QString mimas::TableView::cssClass() const 
 * include/mimas/TableView.h:104
 */
static int TableView_cssClass(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in cssClass");
    QString  retval__ = self__->cssClass();
    lua_pushclass<QString>(L, retval__, "mimas.QString");
    return 1;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.cssClass: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.cssClass: Unknown exception");
  }
}


/** void mimas::TableView::globalMove(float x, float y)
 * include/mimas/TableView.h:229
 */
static int TableView_globalMove(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in globalMove");
    float x = luaL_checknumber(L, 2);
    float y = luaL_checknumber(L, 3);
    self__->globalMove(x, y);
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.globalMove: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.globalMove: Unknown exception");
  }
}


/** LuaStackSize mimas::TableView::globalPosition(lua_State *L)
 * include/mimas/TableView.h:220
 */
static int TableView_globalPosition(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in globalPosition");
    
    LuaStackSize  retval__ = self__->globalPosition(L);
    return retval__;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.globalPosition: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.globalPosition: Unknown exception");
  }
}


/** void mimas::TableView::hide()
 * include/mimas/TableView.h:212
 */
static int TableView_hide(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in hide");
    self__->hide();
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.hide: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.hide: Unknown exception");
  }
}


/** float mimas::TableView::hue()
 * include/mimas/TableView.h:148
 */
static int TableView_hue(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in hue");
    float  retval__ = self__->hue();
    lua_pushnumber(L, retval__);
    return 1;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.hue: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.hue: Unknown exception");
  }
}


/** bool mimas::TableView::isVisible() const 
 * include/mimas/TableView.h:203
 */
static int TableView_isVisible(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in isVisible");
    bool  retval__ = self__->isVisible();
    lua_pushboolean(L, retval__);
    return 1;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.isVisible: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.isVisible: Unknown exception");
  }
}


/** void mimas::TableView::lower()
 * include/mimas/TableView.h:236
 */
static int TableView_lower(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in lower");
    self__->lower();
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.lower: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.lower: Unknown exception");
  }
}


/** void mimas::TableView::move(int x, int y)
 * include/mimas/TableView.h:129
 */
static int TableView_move(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in move");
    int x = luaL_checkint(L, 2);
    int y = luaL_checkint(L, 3);
    self__->move(x, y);
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.move: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.move: Unknown exception");
  }
}


/** LuaStackSize mimas::TableView::name(lua_State *L)
 * include/mimas/TableView.h:118
 */
static int TableView_name(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in name");
    
    LuaStackSize  retval__ = self__->name(L);
    return retval__;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.name: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.name: Unknown exception");
  }
}


/** QObject* mimas::TableView::object()
 * include/mimas/TableView.h:112
 */
static int TableView_object(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in object");
    QObject * retval__ = self__->object();
    lua_pushclass<QObject>(L, retval__, "mimas.QObject");
    return 1;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.object: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.object: Unknown exception");
  }
}


/** void mimas::TableView::raise()
 * include/mimas/TableView.h:242
 */
static int TableView_raise(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in raise");
    self__->raise();
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.raise: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.raise: Unknown exception");
  }
}


/** void mimas::TableView::resize(int w, int h)
 * include/mimas/TableView.h:134
 */
static int TableView_resize(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in resize");
    int w = luaL_checkint(L, 2);
    int h = luaL_checkint(L, 3);
    self__->resize(w, h);
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.resize: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.resize: Unknown exception");
  }
}


/** void mimas::TableView::setHeaders(lua_State *L)
 * include/mimas/TableView.h:92
 */
static int TableView_setHeaders(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in setHeaders");
    
    self__->setHeaders(L);
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.setHeaders: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.setHeaders: Unknown exception");
  }
}


/** void mimas::TableView::setHue(float hue)
 * include/mimas/TableView.h:143
 */
static int TableView_setHue(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in setHue");
    float hue = luaL_checknumber(L, 2);
    self__->setHue(hue);
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.setHue: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.setHue: Unknown exception");
  }
}


/** void mimas::TableView::setMinimumSize(float w, float h)
 * include/mimas/TableView.h:183
 */
static int TableView_setMinimumSize(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in setMinimumSize");
    float w = luaL_checknumber(L, 2);
    float h = luaL_checknumber(L, 3);
    self__->setMinimumSize(w, h);
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.setMinimumSize: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.setMinimumSize: Unknown exception");
  }
}


/** void mimas::TableView::setMouseTracking(bool enable)
 * include/mimas/TableView.h:190
 */
static int TableView_setMouseTracking(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in setMouseTracking");
    bool enable = lua_toboolean(L, 2);
    self__->setMouseTracking(enable);
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.setMouseTracking: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.setMouseTracking: Unknown exception");
  }
}


/** void mimas::TableView::setName(const char *name)
 * include/mimas/TableView.h:125
 */
static int TableView_setName(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in setName");
    const char *name = luaL_checkstring(L, 2);
    self__->setName(name);
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.setName: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.setName: Unknown exception");
  }
}


/** void mimas::TableView::setSizeHint(float w, float h)
 * include/mimas/TableView.h:168
 */
static int TableView_setSizeHint(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in setSizeHint");
    float w = luaL_checknumber(L, 2);
    float h = luaL_checknumber(L, 3);
    self__->setSizeHint(w, h);
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.setSizeHint: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.setSizeHint: Unknown exception");
  }
}


/** void mimas::TableView::setSizePolicy(int horizontal, int vertical)
 * include/mimas/TableView.h:176
 */
static int TableView_setSizePolicy(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in setSizePolicy");
    int horizontal = luaL_checkint(L, 2);
    int vertical = luaL_checkint(L, 3);
    self__->setSizePolicy(horizontal, vertical);
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.setSizePolicy: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.setSizePolicy: Unknown exception");
  }
}


/** void mimas::TableView::setStyle(const char *text)
 * include/mimas/TableView.h:139
 */
static int TableView_setStyle(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in setStyle");
    const char *text = luaL_checkstring(L, 2);
    self__->setStyle(text);
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.setStyle: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.setStyle: Unknown exception");
  }
}


/** void mimas::TableView::show()
 * include/mimas/TableView.h:207
 */
static int TableView_show(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in show");
    self__->show();
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.show: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.show: Unknown exception");
  }
}


/** LuaStackSize mimas::TableView::textSize(const char *text, lua_State *L)
 * include/mimas/TableView.h:159
 */
static int TableView_textSize(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in textSize");
    const char *text = luaL_checkstring(L, 2);
    
    LuaStackSize  retval__ = self__->textSize(text, L);
    return retval__;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.textSize: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.textSize: Unknown exception");
  }
}


/** void mimas::TableView::update()
 * include/mimas/TableView.h:152
 */
static int TableView_update(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in update");
    self__->update();
    return 0;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.update: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.update: Unknown exception");
  }
}


/** QWidget* mimas::TableView::widget()
 * include/mimas/TableView.h:108
 */
static int TableView_widget(lua_State *L) {
  try {
    TableView *self__ = *((TableView**)luaL_checkudata(L, 1, "mimas.TableView"));
    if (!self__) return luaL_error(L, "Using deleted mimas.TableView in widget");
    QWidget * retval__ = self__->widget();
    lua_pushclass<QWidget>(L, retval__, "mimas.QWidget");
    return 1;
  } catch (std::exception &e) {
    return luaL_error(L, "mimas.TableView.widget: %s", e.what());
  } catch (...) {
    return luaL_error(L, "mimas.TableView.widget: Unknown exception");
  }
}




/* ============================ Lua Registration ====================== */

static const struct luaL_Reg TableView_member_methods[] = {
  {"__newindex"        , TableView___newindex},
  {"close"             , TableView_close},
  {"cssClass"          , TableView_cssClass},
  {"globalMove"        , TableView_globalMove},
  {"globalPosition"    , TableView_globalPosition},
  {"hide"              , TableView_hide},
  {"hue"               , TableView_hue},
  {"isVisible"         , TableView_isVisible},
  {"lower"             , TableView_lower},
  {"move"              , TableView_move},
  {"name"              , TableView_name},
  {"object"            , TableView_object},
  {"raise"             , TableView_raise},
  {"resize"            , TableView_resize},
  {"setHeaders"        , TableView_setHeaders},
  {"setHue"            , TableView_setHue},
  {"setMinimumSize"    , TableView_setMinimumSize},
  {"setMouseTracking"  , TableView_setMouseTracking},
  {"setName"           , TableView_setName},
  {"setSizeHint"       , TableView_setSizeHint},
  {"setSizePolicy"     , TableView_setSizePolicy},
  {"setStyle"          , TableView_setStyle},
  {"show"              , TableView_show},
  {"textSize"          , TableView_textSize},
  {"update"            , TableView_update},
  {"widget"            , TableView_widget},
  {"__tostring"        , TableView__tostring},
  {"__gc"              , TableView_destructor},
  {"deleted"           , TableView_deleted},
  {NULL, NULL},
};

static const struct luaL_Reg TableView_namespace_methods[] = {
  {"TableView"         , TableView_TableView},
  {NULL, NULL},
};



#ifdef DUB_LUA_NO_OPEN
int luaload_mimas_TableView(lua_State *L) {
#else
extern "C" int luaopen_mimas_TableView(lua_State *L) {
#endif
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.TableView");

  // metatable.__index = metatable (find methods in the table itself)
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");

  // register member methods
  luaL_register(L, NULL, TableView_member_methods);
  // save meta-table in mimas.TableView_
  register_mt(L, "mimas", "TableView");

  // register class methods in a global namespace table
  luaL_register(L, "mimas", TableView_namespace_methods);


	return 1;
}
