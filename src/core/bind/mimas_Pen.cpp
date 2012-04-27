/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class Pen
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/Pen.h"


/** Pen::Pen()
 * include/mimas/Pen.h:43
 */
static int Pen_Pen(lua_State *L) {
  try {
    int top__ = lua_gettop(L);
    if (top__ >= 5) {
      int type__ = lua_type(L, 2);
      if (type__ == LUA_TNUMBER) {
        float width = dub_checknumber(L, 1);
        float h = dub_checknumber(L, 2);
        float s = dub_checknumber(L, 3);
        float v = dub_checknumber(L, 4);
        float a = dub_checknumber(L, 5);
        Pen *retval__ = new Pen(width, h, s, v, a);
        dub_pushudata(L, retval__, "mimas.Pen", true);
        return 1;
      } else {
        float width = dub_checknumber(L, 1);
        Color *color = *((Color **)dub_checksdata(L, 2, "mimas.Color"));
        int style = dub_checkint(L, 3);
        int cap = dub_checkint(L, 4);
        int join = dub_checkint(L, 5);
        Pen *retval__ = new Pen(width, *color, style, cap, join);
        dub_pushudata(L, retval__, "mimas.Pen", true);
        return 1;
      }
    } else if (top__ >= 4) {
      int type__ = lua_type(L, 2);
      if (type__ == LUA_TNUMBER) {
        float width = dub_checknumber(L, 1);
        float h = dub_checknumber(L, 2);
        float s = dub_checknumber(L, 3);
        float v = dub_checknumber(L, 4);
        Pen *retval__ = new Pen(width, h, s, v);
        dub_pushudata(L, retval__, "mimas.Pen", true);
        return 1;
      } else {
        float width = dub_checknumber(L, 1);
        Color *color = *((Color **)dub_checksdata(L, 2, "mimas.Color"));
        int style = dub_checkint(L, 3);
        int cap = dub_checkint(L, 4);
        Pen *retval__ = new Pen(width, *color, style, cap);
        dub_pushudata(L, retval__, "mimas.Pen", true);
        return 1;
      }
    } else if (top__ >= 3) {
      int type__ = lua_type(L, 2);
      if (type__ == LUA_TNUMBER) {
        float width = dub_checknumber(L, 1);
        float h = dub_checknumber(L, 2);
        float s = dub_checknumber(L, 3);
        Pen *retval__ = new Pen(width, h, s);
        dub_pushudata(L, retval__, "mimas.Pen", true);
        return 1;
      } else {
        float width = dub_checknumber(L, 1);
        Color *color = *((Color **)dub_checksdata(L, 2, "mimas.Color"));
        int style = dub_checkint(L, 3);
        Pen *retval__ = new Pen(width, *color, style);
        dub_pushudata(L, retval__, "mimas.Pen", true);
        return 1;
      }
    } else if (top__ >= 2) {
      int type__ = lua_type(L, 2);
      if (type__ == LUA_TNUMBER) {
        float width = dub_checknumber(L, 1);
        float h = dub_checknumber(L, 2);
        Pen *retval__ = new Pen(width, h);
        dub_pushudata(L, retval__, "mimas.Pen", true);
        return 1;
      } else {
        float width = dub_checknumber(L, 1);
        Color *color = *((Color **)dub_checksdata(L, 2, "mimas.Color"));
        Pen *retval__ = new Pen(width, *color);
        dub_pushudata(L, retval__, "mimas.Pen", true);
        return 1;
      }
    } else {
      Pen *retval__ = new Pen();
      dub_pushudata(L, retval__, "mimas.Pen", true);
      return 1;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "Pen: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "Pen: Unknown exception");
  }
  return dub_error(L);
}

/** Pen::~Pen()
 * include/mimas/Pen.h:54
 */
static int Pen__Pen(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "mimas.Pen"));
    if (userdata->gc) {
      Pen *self = (Pen *)userdata->ptr;
      delete self;
    }
    userdata->gc = false;
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "~Pen: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "~Pen: Unknown exception");
  }
  return dub_error(L);
}

/** void Pen::setWidth(float w)
 * include/mimas/Pen.h:57
 */
static int Pen_setWidth(lua_State *L) {
  try {
    Pen *self = *((Pen **)dub_checksdata(L, 1, "mimas.Pen"));
    float w = dub_checknumber(L, 2);
    self->setWidth(w);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setWidth: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setWidth: Unknown exception");
  }
  return dub_error(L);
}

/** void Pen::setRgba(float r, float g, float b, float a=1.0)
 * include/mimas/Pen.h:61
 */
static int Pen_setRgba(lua_State *L) {
  try {
    Pen *self = *((Pen **)dub_checksdata(L, 1, "mimas.Pen"));
    int top__ = lua_gettop(L);
    if (top__ >= 5) {
      float r = dub_checknumber(L, 2);
      float g = dub_checknumber(L, 3);
      float b = dub_checknumber(L, 4);
      float a = dub_checknumber(L, 5);
      self->setRgba(r, g, b, a);
      return 0;
    } else {
      float r = dub_checknumber(L, 2);
      float g = dub_checknumber(L, 3);
      float b = dub_checknumber(L, 4);
      self->setRgba(r, g, b);
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "setRgba: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setRgba: Unknown exception");
  }
  return dub_error(L);
}

/** void Pen::setColor(const Color &color)
 * include/mimas/Pen.h:65
 */
static int Pen_setColor(lua_State *L) {
  try {
    Pen *self = *((Pen **)dub_checksdata(L, 1, "mimas.Pen"));
    Color *color = *((Color **)dub_checksdata(L, 2, "mimas.Color"));
    self->setColor(*color);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setColor: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setColor: Unknown exception");
  }
  return dub_error(L);
}

/** void Pen::setHsva(float h, float s=1.0, float v=1.0, float a=1.0)
 * include/mimas/Pen.h:69
 */
static int Pen_setHsva(lua_State *L) {
  try {
    Pen *self = *((Pen **)dub_checksdata(L, 1, "mimas.Pen"));
    int top__ = lua_gettop(L);
    if (top__ >= 5) {
      float h = dub_checknumber(L, 2);
      float s = dub_checknumber(L, 3);
      float v = dub_checknumber(L, 4);
      float a = dub_checknumber(L, 5);
      self->setHsva(h, s, v, a);
      return 0;
    } else if (top__ >= 4) {
      float h = dub_checknumber(L, 2);
      float s = dub_checknumber(L, 3);
      float v = dub_checknumber(L, 4);
      self->setHsva(h, s, v);
      return 0;
    } else if (top__ >= 3) {
      float h = dub_checknumber(L, 2);
      float s = dub_checknumber(L, 3);
      self->setHsva(h, s);
      return 0;
    } else {
      float h = dub_checknumber(L, 2);
      self->setHsva(h);
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "setHsva: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setHsva: Unknown exception");
  }
  return dub_error(L);
}

/** void Pen::setStyle(int style)
 * include/mimas/Pen.h:75
 */
static int Pen_setStyle(lua_State *L) {
  try {
    Pen *self = *((Pen **)dub_checksdata(L, 1, "mimas.Pen"));
    int style = dub_checkint(L, 2);
    self->setStyle(style);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setStyle: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setStyle: Unknown exception");
  }
  return dub_error(L);
}

/** void Pen::setCapStyle(int style)
 * include/mimas/Pen.h:79
 */
static int Pen_setCapStyle(lua_State *L) {
  try {
    Pen *self = *((Pen **)dub_checksdata(L, 1, "mimas.Pen"));
    int style = dub_checkint(L, 2);
    self->setCapStyle(style);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setCapStyle: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setCapStyle: Unknown exception");
  }
  return dub_error(L);
}

/** void Pen::setJoinStyle(int style)
 * include/mimas/Pen.h:83
 */
static int Pen_setJoinStyle(lua_State *L) {
  try {
    Pen *self = *((Pen **)dub_checksdata(L, 1, "mimas.Pen"));
    int style = dub_checkint(L, 2);
    self->setJoinStyle(style);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setJoinStyle: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setJoinStyle: Unknown exception");
  }
  return dub_error(L);
}



// --=============================================== __tostring
static int Pen___tostring(lua_State *L) {
  Pen *self = *((Pen **)dub_checksdata_n(L, 1, "mimas.Pen"));
  lua_pushfstring(L, "mimas.Pen: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg Pen_member_methods[] = {
  { "new"          , Pen_Pen              },
  { "__gc"         , Pen__Pen             },
  { "setWidth"     , Pen_setWidth         },
  { "setRgba"      , Pen_setRgba          },
  { "setColor"     , Pen_setColor         },
  { "setHsva"      , Pen_setHsva          },
  { "setStyle"     , Pen_setStyle         },
  { "setCapStyle"  , Pen_setCapStyle      },
  { "setJoinStyle" , Pen_setJoinStyle     },
  { "__tostring"   , Pen___tostring       },
  { "deleted"      , dub_isDeleted        },
  { NULL, NULL},
};


extern "C" int luaopen_mimas_Pen(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.Pen");
  // <mt>

  // register member methods
  luaL_register(L, NULL, Pen_member_methods);
  // save meta-table in mimas
  dub_register(L, "mimas", "Pen");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
