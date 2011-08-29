#include "mimas/Button.h"

#include "lua_cpp_helper.h"


using namespace mimas;


/* ============================ Constructors     ====================== */

/** mimas::Button::Button(lubyk::Worker *worker, const char *title=NULL, QWidget *parent=NULL)
 * include/mimas/Button.h:57
 */
static int Button_Button(lua_State *L) {
  try {
    int top__ = lua_gettop(L);
    Button * retval__;
    lubyk::Worker *worker = *((lubyk::Worker **)dubL_checksdata(L, 1, "lubyk.Worker"));
    if (top__ < 2) {
      retval__ = new Button(worker);
    } else {
      const char *title = dubL_checkstring(L, 2);
      if (top__ < 3) {
        retval__ = new Button(worker, title);
      } else {
        QWidget *parent = *((QWidget **)dubL_checksdata(L, 3, "mimas.QWidget"));
        retval__ = new Button(worker, title, parent);
      }
    }
    // The class inherits from 'LuaCallback', use lua_init instead of pushclass.
    return retval__->luaInit(L, retval__, "mimas.Button");
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.Button: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.Button: Unknown exception");
  }
  return lua_error(L);
}



/* ============================ Destructor       ====================== */

static int Button_destructor(lua_State *L) {
  Button **userdata = (Button**)dubL_checksdata_n(L, 1, "mimas.Button");

  
  // custom destructor
  if (*userdata) (*userdata)->luaDestroy();
  
  *userdata = NULL;
  return 0;
}




// test if class is deleted
static int Button_deleted(lua_State *L) {
  Button **userdata = (Button**)dubL_checksdata_n(L, 1, "mimas.Button");
  lua_pushboolean(L, *userdata == NULL);
  return 1;
}

/* ============================ tostring         ====================== */

static int Button__tostring(lua_State *L) {
  Button **userdata = (Button**)dubL_checksdata_n(L, 1, "mimas.Button");
  
  if (!*userdata) {
    lua_pushstring(L, "<mimas.Button: NULL>");
    return 1;
  }
  
  
  lua_pushfstring(L, "<mimas.Button: %p>", *userdata);
  
  return 1;
}

/* ============================ Member Methods   ====================== */


/** QString mimas::Button::cssClass() const 
 * include/mimas/Button.h:65
 */
static int Button_cssClass(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in cssClass");
    QString  retval__ = self__->cssClass();
    lua_pushclass<QString>(L, retval__, "mimas.QString");
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.cssClass: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.cssClass: Unknown exception");
  }
  return lua_error(L);
}



/** int mimas::Button::height()
 * include/mimas/Button.h:110
 */
static int Button_height(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in height");
    int  retval__ = self__->height();
    lua_pushnumber(L, retval__);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.height: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.height: Unknown exception");
  }
  return lua_error(L);
}



/** float mimas::Button::hue()
 * include/mimas/Button.h:127
 */
static int Button_hue(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in hue");
    float  retval__ = self__->hue();
    lua_pushnumber(L, retval__);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.hue: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.hue: Unknown exception");
  }
  return lua_error(L);
}



/** void mimas::Button::move(int x, int y)
 * include/mimas/Button.h:90
 */
static int Button_move(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in move");
    int x = dubL_checkint(L, 2);
    int y = dubL_checkint(L, 3);
    self__->move(x, y);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.move: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.move: Unknown exception");
  }
  return lua_error(L);
}



/** LuaStackSize mimas::Button::name(lua_State *L)
 * include/mimas/Button.h:79
 */
static int Button_name(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in name");
    
    LuaStackSize  retval__ = self__->name(L);
    return retval__;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.name: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.name: Unknown exception");
  }
  return lua_error(L);
}



/** QObject* mimas::Button::object()
 * include/mimas/Button.h:73
 */
static int Button_object(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in object");
    QObject * retval__ = self__->object();
    lua_pushclass<QObject>(L, retval__, "mimas.QObject");
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.object: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.object: Unknown exception");
  }
  return lua_error(L);
}



/** void mimas::Button::resize(int w, int h)
 * include/mimas/Button.h:94
 */
static int Button_resize(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in resize");
    int w = dubL_checkint(L, 2);
    int h = dubL_checkint(L, 3);
    self__->resize(w, h);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.resize: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.resize: Unknown exception");
  }
  return lua_error(L);
}



/** void mimas::Button::setHue(float hue)
 * include/mimas/Button.h:122
 */
static int Button_setHue(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in setHue");
    float hue = dubL_checknumber(L, 2);
    self__->setHue(hue);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.setHue: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.setHue: Unknown exception");
  }
  return lua_error(L);
}



/** void mimas::Button::setName(const char *name)
 * include/mimas/Button.h:86
 */
static int Button_setName(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in setName");
    const char *name = dubL_checkstring(L, 2);
    self__->setName(name);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.setName: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.setName: Unknown exception");
  }
  return lua_error(L);
}



/** void mimas::Button::setStyle(const char *text)
 * include/mimas/Button.h:114
 */
static int Button_setStyle(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in setStyle");
    const char *text = dubL_checkstring(L, 2);
    self__->setStyle(text);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.setStyle: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.setStyle: Unknown exception");
  }
  return lua_error(L);
}



/** void mimas::Button::setStyleSheet(const char *text)
 * include/mimas/Button.h:118
 */
static int Button_setStyleSheet(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in setStyleSheet");
    const char *text = dubL_checkstring(L, 2);
    self__->setStyleSheet(text);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.setStyleSheet: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.setStyleSheet: Unknown exception");
  }
  return lua_error(L);
}



/** QWidget* mimas::Button::widget()
 * include/mimas/Button.h:69
 */
static int Button_widget(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in widget");
    QWidget * retval__ = self__->widget();
    lua_pushclass<QWidget>(L, retval__, "mimas.QWidget");
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.widget: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.widget: Unknown exception");
  }
  return lua_error(L);
}



/** int mimas::Button::width()
 * include/mimas/Button.h:106
 */
static int Button_width(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in width");
    int  retval__ = self__->width();
    lua_pushnumber(L, retval__);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.width: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.width: Unknown exception");
  }
  return lua_error(L);
}



/** int mimas::Button::x()
 * include/mimas/Button.h:98
 */
static int Button_x(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in x");
    int  retval__ = self__->x();
    lua_pushnumber(L, retval__);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.x: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.x: Unknown exception");
  }
  return lua_error(L);
}



/** int mimas::Button::y()
 * include/mimas/Button.h:102
 */
static int Button_y(lua_State *L) {
  try {
    Button *self__ = *((Button**)dubL_checksdata(L, 1, "mimas.Button"));
    if (!self__) throw dub::Exception("Using deleted mimas.Button in y");
    int  retval__ = self__->y();
    lua_pushnumber(L, retval__);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.Button.y: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.Button.y: Unknown exception");
  }
  return lua_error(L);
}





/* ============================ Lua Registration ====================== */

static const struct luaL_Reg Button_member_methods[] = {
  {"cssClass"          , Button_cssClass},
  {"height"            , Button_height},
  {"hue"               , Button_hue},
  {"move"              , Button_move},
  {"name"              , Button_name},
  {"object"            , Button_object},
  {"resize"            , Button_resize},
  {"setHue"            , Button_setHue},
  {"setName"           , Button_setName},
  {"setStyle"          , Button_setStyle},
  {"setStyleSheet"     , Button_setStyleSheet},
  {"widget"            , Button_widget},
  {"width"             , Button_width},
  {"x"                 , Button_x},
  {"y"                 , Button_y},
  {"__tostring"        , Button__tostring},
  {"__gc"              , Button_destructor},
  {"deleted"           , Button_deleted},
  {NULL, NULL},
};

static const struct luaL_Reg Button_namespace_methods[] = {
  {"Button"            , Button_Button},
  {NULL, NULL},
};



#ifdef DUB_LUA_NO_OPEN
int luaload_mimas_Button_core(lua_State *L) {
#else
extern "C" int luaopen_mimas_Button_core(lua_State *L) {
#endif
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.Button");

  // metatable.__index = metatable (find methods in the table itself)
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");

  // register member methods
  luaL_register(L, NULL, Button_member_methods);
  // save meta-table in mimas.Button_
  register_mt(L, "mimas", "Button");

  // register class methods in a global namespace table
  luaL_register(L, "mimas", Button_namespace_methods);


	return 1;
}
