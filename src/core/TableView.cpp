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

#include "mimas/TableView.h"
#include "mimas/Painter.h"
#include "mimas/Widget.h"

void TableView::mouseMoveEvent(QMouseEvent *event) {
  if (!dub_pushcallback("mouse")) return;
  lua_State *L = dub_L;
  lua_pushnumber(L, event->x());
  lua_pushnumber(L, event->y());
  // <func> <self> <x> <y>
  if (!dub_call(3, 1)) return;

  if (lua_isfalse(L, -1)) {
    // Pass to QTableView
    QTableView::mouseMoveEvent(event);
  }
  lua_pop(L, 1);
}

bool TableView::click(QMouseEvent *event, int type) {
  if (dub_pushcallback("select")) {
    // ... <select> <self>
    return select(event, type);
  } else {
    return Widget::click(this, event, type);
  }
}

bool TableView::select(QMouseEvent *event, int type) {
  lua_State *L = dub_L;
  // ... <select> <self>
  if (type != MousePress) {
    lua_pop(L, 2);
    return true; // ignore
  }

  QModelIndex idx = QTableView::indexAt(QPoint(event->x(), event->y()));
  if (!idx.isValid()) {
    lua_pop(L, 2);
    return false;
  }

  lua_pushnumber(L, idx.row() + 1);
  lua_pushnumber(L, idx.column() + 1);
  // ... <select> <self> <row> <col>
  if (!dub_call(3, 1)) {
    // error
    return false;
  }

  // FIXME: find another way to remove the dotted lines around text after click.
  clearFocus();

  if (lua_isfalse(L, -1)) {
    // Pass to TableView
    lua_pop(L, 1);
    return false;
  }

  lua_pop(L, 1);
  return true;
}

