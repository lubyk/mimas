/*
   QVariant variantFromLua(lua_State *L, int index);
  ==============================================================================

   This file is part of the LUBYK project (http://lubyk.org)
   Copyright (c) 2007-2011 by Gaspard Bucher (http://teti.ch).

  ------------------------------------------------------------------------------

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.

  ==============================================================================
*/
#include "mimas/mimas.h"
#include "mimas/Callback.h"

#include <QtCore/QVariant>
#include <QtCore/QRectF>

// create value for Callback::Event type here
const QEvent::Type Callback::EventType = static_cast<QEvent::Type>(QEvent::registerEventType());

QVariant variantFromLua(lua_State *L, int index) {
  int type = lua_type(L, index);
  switch (type) {
  case LUA_TNUMBER:
    return QVariant(lua_tonumber(L, index));
  case LUA_TBOOLEAN:
    return QVariant((bool)lua_toboolean(L, index));
  case LUA_TSTRING:
    return QVariant(QString::fromUtf8(lua_tostring(L, index)));
  // case LUA_TNIL:           // continue
  // case LUA_TTABLE:         // continue
  // case LUA_TUSERDATA:      // continue
  // case LUA_TUSERDATA:      // continue
  // case LUA_TTHREAD:        // continue
  // case LUA_TLIGHTUSERDATA: // continue
  default:
    return QVariant();
  }
}

int pushVariantInLua(lua_State *L, const QVariant &value) {
  int ret = 0;
  if (value.canConvert(QVariant::String)) {
    QByteArray str(value.toString().toUtf8());
    lua_pushlstring(L, str.constData(), str.size());
    ret = 1;
  } else if (value.canConvert(QVariant::Double)) {
    double d = value.toDouble();
    lua_pushnumber(L, d);
    ret = 1;
  } else if (value.canConvert(QVariant::Rect)) {
    QRectF r(value.toRectF());
    lua_pushnumber(L, r.x());
    lua_pushnumber(L, r.y());
    ret = 2;
  } else if (value.canConvert(QVariant::Bool)) {
    bool b(value.toBool());
    lua_pushboolean(L, b);
    ret = 1;
  }
  return ret;
}
