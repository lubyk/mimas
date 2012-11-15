/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class Painter
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/Painter.h"


/** Cast (class_name)
 * 
 */
static int Painter__cast_(lua_State *L) {

  Painter *self = *((Painter **)dub_checksdata_n(L, 1, "mimas.Painter"));
  const char *key = luaL_checkstring(L, 2);
  void **retval__ = (void**)lua_newuserdata(L, sizeof(void*));
  int key_h = dub_hash(key, 2);
  switch(key_h) {
    case 1: {
      if (DUB_ASSERT_KEY(key, "mimas.QPainter")) break;
      *retval__ = static_cast<QPainter *>(self);
      return 1;
    }
  }
  return 0;
}

/** Painter::Painter(QWidget *widget)
 * include/mimas/Painter.h:50
 */
static int Painter_Painter(lua_State *L) {
  try {
    QWidget *widget = *((QWidget **)dub_checksdata(L, 1, "mimas.QWidget"));
    Painter *retval__ = new Painter(widget);
    dub_pushudata(L, retval__, "mimas.Painter", true);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "new: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "new: Unknown exception");
  }
  return dub_error(L);
}

/** void Painter::setPen(const Pen &pen)
 * include/mimas/Painter.h:57
 */
static int Painter_setPen(lua_State *L) {
  try {
    Painter *self = *((Painter **)dub_checksdata(L, 1, "mimas.Painter"));
    int top__ = lua_gettop(L);
    if (top__ >= 6) {
      float width = dub_checknumber(L, 2);
      float h = dub_checknumber(L, 3);
      float s = dub_checknumber(L, 4);
      float v = dub_checknumber(L, 5);
      float a = dub_checknumber(L, 6);
      self->setPen(width, h, s, v, a);
      return 0;
    } else if (top__ >= 5) {
      float width = dub_checknumber(L, 2);
      float h = dub_checknumber(L, 3);
      float s = dub_checknumber(L, 4);
      float v = dub_checknumber(L, 5);
      self->setPen(width, h, s, v);
      return 0;
    } else if (top__ >= 4) {
      float width = dub_checknumber(L, 2);
      float h = dub_checknumber(L, 3);
      float s = dub_checknumber(L, 4);
      self->setPen(width, h, s);
      return 0;
    } else if (top__ >= 3) {
      int type__ = lua_type(L, 3);
      if (type__ == LUA_TNUMBER) {
        float width = dub_checknumber(L, 2);
        float h = dub_checknumber(L, 3);
        self->setPen(width, h);
        return 0;
      } else {
        float width = dub_checknumber(L, 2);
        Color *color = *((Color **)dub_checksdata(L, 3, "mimas.Color"));
        self->setPen(width, *color);
        return 0;
      }
    } else {
      Pen *pen = *((Pen **)dub_checksdata(L, 2, "mimas.Pen"));
      self->setPen(*pen);
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "setPen: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setPen: Unknown exception");
  }
  return dub_error(L);
}

/** void Painter::setBrush(float h, float s=1.0, float v=1.0, float a=1.0)
 * include/mimas/Painter.h:71
 */
static int Painter_setBrush(lua_State *L) {
  try {
    Painter *self = *((Painter **)dub_checksdata(L, 1, "mimas.Painter"));
    int top__ = lua_gettop(L);
    if (top__ >= 5) {
      float h = dub_checknumber(L, 2);
      float s = dub_checknumber(L, 3);
      float v = dub_checknumber(L, 4);
      float a = dub_checknumber(L, 5);
      self->setBrush(h, s, v, a);
      return 0;
    } else if (top__ >= 4) {
      float h = dub_checknumber(L, 2);
      float s = dub_checknumber(L, 3);
      float v = dub_checknumber(L, 4);
      self->setBrush(h, s, v);
      return 0;
    } else if (top__ >= 3) {
      float h = dub_checknumber(L, 2);
      float s = dub_checknumber(L, 3);
      self->setBrush(h, s);
      return 0;
    } else {
      int type__ = lua_type(L, 2);
      void **ptr2__;
      if (type__ == LUA_TNUMBER) {
        float h = dub_checknumber(L, 2);
        self->setBrush(h);
        return 0;
      } else if ( (ptr2__ = dub_issdata(L, 2, "mimas.Color", type__)) ) {
        Color *color = *((Color **)ptr2__);
        self->setBrush(*color);
        return 0;
      } else {
        Brush *brush = *((Brush **)dub_checksdata(L, 2, "mimas.Brush"));
        self->setBrush(*brush);
        return 0;
      }
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "setBrush: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setBrush: Unknown exception");
  }
  return dub_error(L);
}

/** void Painter::drawRect(float x, float y, float w, float h)
 * include/mimas/Painter.h:98
 */
static int Painter_drawRect(lua_State *L) {
  try {
    Painter *self = *((Painter **)dub_checksdata(L, 1, "mimas.Painter"));
    float x = dub_checknumber(L, 2);
    float y = dub_checknumber(L, 3);
    float w = dub_checknumber(L, 4);
    float h = dub_checknumber(L, 5);
    self->drawRect(x, y, w, h);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "drawRect: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "drawRect: Unknown exception");
  }
  return dub_error(L);
}

/** void Painter::drawRoundedRect(float x, float y, float w, float h, float xRadius, lua_State *L)
 * include/mimas/Painter.h:104
 */
static int Painter_drawRoundedRect(lua_State *L) {
  try {
    Painter *self = *((Painter **)dub_checksdata(L, 1, "mimas.Painter"));
    float x = dub_checknumber(L, 2);
    float y = dub_checknumber(L, 3);
    float w = dub_checknumber(L, 4);
    float h = dub_checknumber(L, 5);
    float xRadius = dub_checknumber(L, 6);
    self->drawRoundedRect(x, y, w, h, xRadius, L);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "drawRoundedRect: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "drawRoundedRect: Unknown exception");
  }
  return dub_error(L);
}

/** void Painter::drawText(float x, float y, float w, float h, int flags, const char *text)
 * include/mimas/Painter.h:111
 */
static int Painter_drawText(lua_State *L) {
  try {
    Painter *self = *((Painter **)dub_checksdata(L, 1, "mimas.Painter"));
    float x = dub_checknumber(L, 2);
    float y = dub_checknumber(L, 3);
    float w = dub_checknumber(L, 4);
    float h = dub_checknumber(L, 5);
    int flags = dub_checkint(L, 6);
    const char *text = dub_checkstring(L, 7);
    self->drawText(x, y, w, h, flags, text);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "drawText: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "drawText: Unknown exception");
  }
  return dub_error(L);
}

/** void QPainter::fillRect(int x, int y, int width, int height, const Color &color)
 * bind/QPainter.h:8
 */
static int Painter_fillRect(lua_State *L) {
  try {
    Painter *self = *((Painter **)dub_checksdata(L, 1, "mimas.Painter"));
    int x = dub_checkint(L, 2);
    int y = dub_checkint(L, 3);
    int width = dub_checkint(L, 4);
    int height = dub_checkint(L, 5);
    Color *color = *((Color **)dub_checksdata(L, 6, "mimas.Color"));
    self->fillRect(x, y, width, height, *color);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "fillRect: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "fillRect: Unknown exception");
  }
  return dub_error(L);
}

/** void QPainter::drawPath(const Path &path)
 * bind/QPainter.h:10
 */
static int Painter_drawPath(lua_State *L) {
  try {
    Painter *self = *((Painter **)dub_checksdata(L, 1, "mimas.Painter"));
    Path *path = *((Path **)dub_checksdata(L, 2, "mimas.Path"));
    self->drawPath(*path);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "drawPath: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "drawPath: Unknown exception");
  }
  return dub_error(L);
}

/** void QPainter::drawPoint(int x, int y)
 * bind/QPainter.h:14
 */
static int Painter_drawPoint(lua_State *L) {
  try {
    Painter *self = *((Painter **)dub_checksdata(L, 1, "mimas.Painter"));
    int x = dub_checkint(L, 2);
    int y = dub_checkint(L, 3);
    self->drawPoint(x, y);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "drawPoint: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "drawPoint: Unknown exception");
  }
  return dub_error(L);
}

/** void QPainter::drawLine(int x1, int y1, int x2, int y2)
 * bind/QPainter.h:18
 */
static int Painter_drawLine(lua_State *L) {
  try {
    Painter *self = *((Painter **)dub_checksdata(L, 1, "mimas.Painter"));
    int x1 = dub_checkint(L, 2);
    int y1 = dub_checkint(L, 3);
    int x2 = dub_checkint(L, 4);
    int y2 = dub_checkint(L, 5);
    self->drawLine(x1, y1, x2, y2);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "drawLine: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "drawLine: Unknown exception");
  }
  return dub_error(L);
}

/** void QPainter::drawEllipse(int x, int y, int width, int height)
 * bind/QPainter.h:22
 */
static int Painter_drawEllipse(lua_State *L) {
  try {
    Painter *self = *((Painter **)dub_checksdata(L, 1, "mimas.Painter"));
    int x = dub_checkint(L, 2);
    int y = dub_checkint(L, 3);
    int width = dub_checkint(L, 4);
    int height = dub_checkint(L, 5);
    self->drawEllipse(x, y, width, height);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "drawEllipse: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "drawEllipse: Unknown exception");
  }
  return dub_error(L);
}



// --=============================================== __tostring
static int Painter___tostring(lua_State *L) {
  Painter *self = *((Painter **)dub_checksdata_n(L, 1, "mimas.Painter"));
  lua_pushfstring(L, "mimas.Painter: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg Painter_member_methods[] = {
  { "_cast_"       , Painter__cast_       },
  { "new"          , Painter_Painter      },
  { "setPen"       , Painter_setPen       },
  { "setBrush"     , Painter_setBrush     },
  { "drawRect"     , Painter_drawRect     },
  { "drawRoundedRect", Painter_drawRoundedRect },
  { "drawText"     , Painter_drawText     },
  { "fillRect"     , Painter_fillRect     },
  { "drawPath"     , Painter_drawPath     },
  { "drawPoint"    , Painter_drawPoint    },
  { "drawLine"     , Painter_drawLine     },
  { "drawEllipse"  , Painter_drawEllipse  },
  { "__tostring"   , Painter___tostring   },
  { "deleted"      , dub_isDeleted        },
  { NULL, NULL},
};


extern "C" int luaopen_mimas_Painter(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.Painter");
  // <mt>

  // register member methods
  luaL_register(L, NULL, Painter_member_methods);
  // save meta-table in mimas
  dub_register(L, "mimas", "Painter", "Painter");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
