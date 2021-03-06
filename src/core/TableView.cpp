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

#include <QtGui/QScrollBar>

bool TableView::click(QMouseEvent *event, int type) {
  lua_State *L = dub_L;

  if (dub_pushcallback("select")) {
    // ... <select> <self>
    if (type == MousePress) {
      // normal click processing
      lua_pop(L, 2);
      // continue processing
      update();
      return false;
    } else {
      // select
      QModelIndex idx = QTableView::indexAt(QPoint(event->x(), event->y()));
      return select(idx, event);
    }
  }
  return Widget::click(this, event, type);
}

bool TableView::select(const QModelIndex &idx, QEvent *event) {
  lua_State *L = dub_L;
  // ... <select> <self>
  if (!idx.isValid()) {
    lua_pop(L, 2);
    return false;
  }

  lua_pushnumber(L, idx.row() + 1);
  lua_pushnumber(L, idx.column() + 1);
  // ... <select> <self> <row> <col>
  if (!dub_call(3, 1)) {
    // Error in callback
    return false;
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


TableView::TableView(QWidget *parent)
  : QTableView(parent) {
  setAttribute(Qt::WA_DeleteOnClose);
  setSelectionMode(QAbstractItemView::SingleSelection);
  // Not editable
  setEditTriggers(QAbstractItemView::NoEditTriggers);

  QObject::connect(
      verticalScrollBar(), SIGNAL(actionTriggered(int)),
      this,                SLOT(sliderVActionTriggered(int)));

  QObject::connect(
      horizontalScrollBar(), SIGNAL(actionTriggered(int)),
      this,                  SLOT(sliderHActionTriggered(int)));

}

TableView::~TableView() {
}

void TableView::slider(int orientation, int action) {
  if (!dub_pushcallback("slider")) return;
  lua_State *L = dub_L;
  lua_pushnumber(L, orientation);
  lua_pushnumber(L, action);
  // <func> <self> <dir> <action>
  dub_call(3, 0);
}

#include <QPlastiqueStyle>
void TableView::foobar() {
  printf("Set Style\n");
  verticalHeader()->setStyle(new QPlastiqueStyle);
}

