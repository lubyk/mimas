/*
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

#include "mimas/Widget.h"
#include "mimas/Painter.h"

#include <QtGui/QFileDialog>

void Widget::paintEvent(QPaintEvent *event) {
  Painter *p = new Painter(this);
  if (!parent()) {
    // window
    p->QPainter::fillRect(rect(), palette().color(QPalette::Window));
  }
  Widget::paint(this, p, width(), height());
  delete p;
  QWidget::paintEvent(event);
}

void Widget::paint(dub::Thread *obj, Painter *p, int w, int h) {
  lua_State *L = obj->dub_L;

  if (!obj->dub_pushcallback("paint")) return;

  dub_pushudata(L, p, "mimas.Painter");
  lua_pushnumber(L, w);
  lua_pushnumber(L, h);
  // <func> <self> <Painter> <width> <height>
  obj->dub_call(4, 0);
}

void Widget::resized(dub::Thread *obj, double width, double height) {
  lua_State *L = obj->dub_L;

  if (!obj->dub_pushcallback("resized")) return;
  lua_pushnumber(L, width);
  lua_pushnumber(L, height);
  // <func> <self> <width> <height>
  obj->dub_call(3, 0);
}

void Widget::moved(dub::Thread *obj, QMoveEvent *event) {
  if (!obj->dub_pushcallback("moved")) return;
  lua_State *L = obj->dub_L;
  lua_pushnumber(L, event->pos().x());
  lua_pushnumber(L, event->pos().y());
  // <func> <self> <x> <y>
  obj->dub_call(3, 0);
}

void Widget::closed(dub::Thread *obj, QCloseEvent *event) {
  lua_State *L = obj->dub_L;
  if (!obj->dub_pushcallback("closed")) return;
  // <func> <self>
  if (!obj->dub_call(1, 1)) {
    return;
  }
  if (lua_isfalse(L, -1)) {
    // Do not close
    event->ignore();
  }
  lua_pop(L, 1);
}

void Widget::showHide(dub::Thread *obj, bool shown) {
  if (shown) {
    if (!obj->dub_pushcallback("shown")) return;
  } else {
    if (!obj->dub_pushcallback("hidden")) return;
  }
  // <func> <self>
  obj->dub_call(1, 0);
}

bool Widget::mouse(dub::Thread *obj, QMouseEvent *event) {
  if (!obj->dub_pushcallback("mouse")) return false;
  lua_State *L = obj->dub_L;
  lua_pushnumber(L, event->x());
  lua_pushnumber(L, event->y());
  // <func> <self> <x> <y>
  if (!obj->dub_call(3, 1)) {
    return true;
  }

  if (lua_isfalse(L, -1)) {
    // We are not concerned.
    event->ignore();
  } else if (lua_istrue(L, -1)) {
    // continue with processing with super
    lua_pop(L, 1);
    return false;
  }
  // processing done.
  lua_pop(L, 1);
  return true;
}

bool Widget::click(dub::Thread *obj, QMouseEvent *event, int type) {
  if (!obj->dub_pushcallback("click")) return false;
  lua_State *L = obj->dub_L;

  lua_pushnumber(L, event->x());
  lua_pushnumber(L, event->y());
  lua_pushnumber(L, type);
  lua_pushnumber(L, event->button());
  lua_pushnumber(L, event->modifiers());
  // <func> <self> <x> <y> <type> <btn> <modifiers>
  int status = lua_pcall(L, 6, 1, 0);

  if (status) {
    fprintf(stderr, "Error in 'click' callback: %s\n", lua_tostring(L, -1));
  }

  if (lua_isfalse(L, -1)) {
    // We are not concerned.
    event->ignore();
  } else if (lua_istrue(L, -1)) {
    // continue processing with super
    lua_pop(L, 1);
    return false;
  }
  // processing done.
  lua_pop(L, 1);
  return true;
}

bool Widget::keyboard(dub::Thread *obj, QKeyEvent *event, bool isPressed) {
  if (!obj->dub_pushcallback("keyboard")) return false;
  lua_State *L = obj->dub_L;
  lua_pushnumber(L, event->key());
  lua_pushboolean(L, isPressed);
  lua_pushstring(L, event->text().toUtf8());
  lua_pushnumber(L, event->modifiers());
  // <fun> <self> <key> <state> <utf8> <modifiers>
  if (!obj->dub_call(5, 1)) {
    return true;
  }

  if (lua_isfalse(L, -1)) {
    // We are not concerned.
    event->ignore();
  } else if (lua_istrue(L, -1)) {
    // continue processing with super
    lua_pop(L, 1);
    return false;
  }
  // processing done.
  lua_pop(L, 1);
  return true;
}

LuaStackSize Widget::getOpenFileName(const char *caption,
                        const char *the_base_dir,
                        const char *the_filter,
                        int options,
                        lua_State *L) {
  QString base_dir(the_base_dir);
  if (base_dir.isEmpty()) base_dir = QString();

  QString filter(the_filter);
  if (filter.isEmpty()) filter = QString();

  QString path = QFileDialog::getOpenFileName(this, caption, base_dir, filter, 0, (QFileDialog::Option)options);
  if (path.isNull()) {
    return 0;
  } else {
    lua_pushstring(L, path.toUtf8().data());
    return 1;
  }
}

LuaStackSize Widget::getExistingDirectory(const char *caption,
                        const char *the_base_dir,
                        int options,
                        lua_State *L) {
  QString base_dir(the_base_dir);
  if (base_dir.isEmpty()) base_dir = QString();

  QString path = QFileDialog::getExistingDirectory(this, caption, base_dir, (QFileDialog::Option)options);
  if (path.isNull()) {
    return 0;
  } else {
    lua_pushstring(L, path.toUtf8().data());
    return 1;
  }
}

