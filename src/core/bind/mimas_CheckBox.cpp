/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class CheckBox
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/CheckBox.h"


/** Cast (class_name)
 * 
 */
static int CheckBox__cast_(lua_State *L) {

  CheckBox *self = *((CheckBox **)dub_checksdata_n(L, 1, "mimas.CheckBox"));
  const char *key = luaL_checkstring(L, 2);
  void **retval__ = (void**)lua_newuserdata(L, sizeof(void*));
  return 0;
}

/** CheckBox::CheckBox(const char *title=NULL, QWidget *parent=NULL)
 * include/mimas/CheckBox.h:52
 */
static int CheckBox_CheckBox(lua_State *L) {
  try {
    int top__ = lua_gettop(L);
    if (top__ >= 2) {
      const char *title = dub_checkstring(L, 1);
      QWidget *parent = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      CheckBox *retval__ = new CheckBox(title, parent);
      retval__->pushobject(L, retval__, "mimas.CheckBox", true);
      return 1;
    } else if (top__ >= 1) {
      const char *title = dub_checkstring(L, 1);
      CheckBox *retval__ = new CheckBox(title);
      retval__->pushobject(L, retval__, "mimas.CheckBox", true);
      return 1;
    } else {
      CheckBox *retval__ = new CheckBox();
      retval__->pushobject(L, retval__, "mimas.CheckBox", true);
      return 1;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "CheckBox: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "CheckBox: Unknown exception");
  }
  return dub_error(L);
}

/** CheckBox::~CheckBox()
 * include/mimas/CheckBox.h:57
 */
static int CheckBox__CheckBox(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "mimas.CheckBox"));
    if (userdata->gc) {
      CheckBox *self = (CheckBox *)userdata->ptr;
      delete self;
    }
    userdata->gc = false;
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "~CheckBox: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "~CheckBox: Unknown exception");
  }
  return dub_error(L);
}



// --=============================================== __tostring
static int CheckBox___tostring(lua_State *L) {
  CheckBox *self = *((CheckBox **)dub_checksdata_n(L, 1, "mimas.CheckBox"));
  lua_pushfstring(L, "mimas.CheckBox: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg CheckBox_member_methods[] = {
  { "_cast_"       , CheckBox__cast_      },
  { "new"          , CheckBox_CheckBox    },
  { "__gc"         , CheckBox__CheckBox   },
  { "__tostring"   , CheckBox___tostring  },
  { NULL, NULL},
};


extern "C" int luaopen_mimas_CheckBox(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.CheckBox");
  // <mt>

  // register member methods
  luaL_register(L, NULL, CheckBox_member_methods);
  // save meta-table in mimas
  dub_register(L, "mimas", "CheckBox_core");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
