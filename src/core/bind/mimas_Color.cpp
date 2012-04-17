/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class Color
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/Color.h"


/** Color::Color()
 * include/mimas/Color.h:42
 */
static int Color_Color(lua_State *L) {
  try {
    int top__ = lua_gettop(L);
    if (top__ >= 4) {
      float h = dub_checknumber(L, 1);
      float s = dub_checknumber(L, 2);
      float v = dub_checknumber(L, 3);
      float a = dub_checknumber(L, 4);
      Color *retval__ = new Color(h, s, v, a);
      dub_pushudata(L, retval__, "mimas.Color", true);
      return 1;
    } else if (top__ >= 3) {
      float h = dub_checknumber(L, 1);
      float s = dub_checknumber(L, 2);
      float v = dub_checknumber(L, 3);
      Color *retval__ = new Color(h, s, v);
      dub_pushudata(L, retval__, "mimas.Color", true);
      return 1;
    } else if (top__ >= 2) {
      float h = dub_checknumber(L, 1);
      float s = dub_checknumber(L, 2);
      Color *retval__ = new Color(h, s);
      dub_pushudata(L, retval__, "mimas.Color", true);
      return 1;
    } else if (top__ >= 1) {
      float h = dub_checknumber(L, 1);
      Color *retval__ = new Color(h);
      dub_pushudata(L, retval__, "mimas.Color", true);
      return 1;
    } else {
      Color *retval__ = new Color();
      dub_pushudata(L, retval__, "mimas.Color", true);
      return 1;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "Color: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "Color: Unknown exception");
  }
  return dub_error(L);
}

/** Color::~Color()
 * include/mimas/Color.h:51
 */
static int Color__Color(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "mimas.Color"));
    if (userdata->gc) {
      Color *self = (Color *)userdata->ptr;
      delete self;
    }
    userdata->gc = false;
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "~Color: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "~Color: Unknown exception");
  }
  return dub_error(L);
}

/** float Color::hue() const
 * include/mimas/Color.h:54
 */
static int Color_hue(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
    lua_pushnumber(L, self->hue());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "hue: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "hue: Unknown exception");
  }
  return dub_error(L);
}

/** float Color::saturation() const
 * include/mimas/Color.h:58
 */
static int Color_saturation(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
    lua_pushnumber(L, self->saturation());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "saturation: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "saturation: Unknown exception");
  }
  return dub_error(L);
}

/** float Color::value() const
 * include/mimas/Color.h:62
 */
static int Color_value(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
    lua_pushnumber(L, self->value());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "value: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "value: Unknown exception");
  }
  return dub_error(L);
}

/** float Color::alpha() const
 * include/mimas/Color.h:66
 */
static int Color_alpha(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
    lua_pushnumber(L, self->alpha());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "alpha: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "alpha: Unknown exception");
  }
  return dub_error(L);
}

/** void Color::setRgba(float r, float g, float b, float a=1.0)
 * include/mimas/Color.h:70
 */
static int Color_setRgba(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
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

/** void Color::setHsva(float h, float s=1.0, float v=1.0, float a=1.0)
 * include/mimas/Color.h:74
 */
static int Color_setHsva(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
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

/** void Color::setHue(float h)
 * include/mimas/Color.h:78
 */
static int Color_setHue(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
    float h = dub_checknumber(L, 2);
    self->setHue(h);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setHue: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setHue: Unknown exception");
  }
  return dub_error(L);
}

/** void Color::setSaturation(float s)
 * include/mimas/Color.h:82
 */
static int Color_setSaturation(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
    float s = dub_checknumber(L, 2);
    self->setSaturation(s);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setSaturation: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setSaturation: Unknown exception");
  }
  return dub_error(L);
}

/** void Color::setValue(float v)
 * include/mimas/Color.h:86
 */
static int Color_setValue(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
    float v = dub_checknumber(L, 2);
    self->setValue(v);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setValue: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setValue: Unknown exception");
  }
  return dub_error(L);
}

/** void Color::setAlpha(float a)
 * include/mimas/Color.h:90
 */
static int Color_setAlpha(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
    float a = dub_checknumber(L, 2);
    self->setAlpha(a);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setAlpha: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setAlpha: Unknown exception");
  }
  return dub_error(L);
}

/** Color* Color::colorWithHue(float h)
 * include/mimas/Color.h:94
 */
static int Color_colorWithHue(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
    float h = dub_checknumber(L, 2);
    Color *retval__ = self->colorWithHue(h);
    if (!retval__) return 0;
    dub_pushudata(L, retval__, "mimas.Color", false);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "colorWithHue: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "colorWithHue: Unknown exception");
  }
  return dub_error(L);
}

/** Color* Color::colorWithSaturation(float s)
 * include/mimas/Color.h:98
 */
static int Color_colorWithSaturation(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
    float s = dub_checknumber(L, 2);
    Color *retval__ = self->colorWithSaturation(s);
    if (!retval__) return 0;
    dub_pushudata(L, retval__, "mimas.Color", false);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "colorWithSaturation: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "colorWithSaturation: Unknown exception");
  }
  return dub_error(L);
}

/** Color* Color::colorWithValue(float v)
 * include/mimas/Color.h:102
 */
static int Color_colorWithValue(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
    float v = dub_checknumber(L, 2);
    Color *retval__ = self->colorWithValue(v);
    if (!retval__) return 0;
    dub_pushudata(L, retval__, "mimas.Color", false);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "colorWithValue: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "colorWithValue: Unknown exception");
  }
  return dub_error(L);
}

/** Color* Color::colorWithAlpha(float a)
 * include/mimas/Color.h:106
 */
static int Color_colorWithAlpha(lua_State *L) {
  try {
    Color *self = *((Color **)dub_checksdata(L, 1, "mimas.Color"));
    float a = dub_checknumber(L, 2);
    Color *retval__ = self->colorWithAlpha(a);
    if (!retval__) return 0;
    dub_pushudata(L, retval__, "mimas.Color", false);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "colorWithAlpha: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "colorWithAlpha: Unknown exception");
  }
  return dub_error(L);
}



// --=============================================== __tostring
static int Color___tostring(lua_State *L) {
  Color *self = *((Color **)dub_checksdata_n(L, 1, "mimas.Color"));
  lua_pushfstring(L, "mimas.Color: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg Color_member_methods[] = {
  { "new"          , Color_Color          },
  { "__gc"         , Color__Color         },
  { "hue"          , Color_hue            },
  { "saturation"   , Color_saturation     },
  { "value"        , Color_value          },
  { "alpha"        , Color_alpha          },
  { "setRgba"      , Color_setRgba        },
  { "setHsva"      , Color_setHsva        },
  { "setHue"       , Color_setHue         },
  { "setSaturation", Color_setSaturation  },
  { "setValue"     , Color_setValue       },
  { "setAlpha"     , Color_setAlpha       },
  { "colorWithHue" , Color_colorWithHue   },
  { "colorWithSaturation", Color_colorWithSaturation },
  { "colorWithValue", Color_colorWithValue },
  { "colorWithAlpha", Color_colorWithAlpha },
  { "__tostring"   , Color___tostring     },
  { NULL, NULL},
};


extern "C" int luaopen_mimas_Color(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.Color");
  // <mt>

  // register member methods
  luaL_register(L, NULL, Color_member_methods);
  // save meta-table in mimas
  dub_register(L, "mimas", "Color");
  // <mt>
  lua_pop(L, 1);
  return 0;
}