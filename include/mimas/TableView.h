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
#ifndef LUBYK_INCLUDE_MIMAS_TABLE_VIEW_H_
#define LUBYK_INCLUDE_MIMAS_TABLE_VIEW_H_

#include "mimas/mimas.h"
#include "mimas/DataSource.h"
#include "mimas/Widget.h"

#include <QtGui/QTableView>
#include <QtGui/QHeaderView>
#include <QtGui/QMouseEvent>
#include <QtCore/QPoint>

#include <iostream>

/** The TableView is used to display data in a table.
 *
 * @dub push: pushobject
 *      register: TableView_core
 *      super: QWidget
 */
class TableView : public QTableView, public dub::Thread {
  Q_OBJECT
public:
  TableView(QWidget *parent = NULL);

  ~TableView();

  /** Show or hide horizontal and vertical headers.
   */
  void setVisibleHeaders(int orientation, bool visible) {
    if (orientation & Qt::Horizontal) {
      if (visible)
        horizontalHeader()->show();
      else
        horizontalHeader()->hide();
    }
    if (orientation & Qt::Vertical) {
      if (visible)
        verticalHeader()->hide();
      else
        verticalHeader()->hide();
    }
  }

  /** Show/hide grid (set to NoPen to hide).
   */
  void setGridStyle(int style) {
    QTableView::setGridStyle((Qt::PenStyle)style);
  }

  void setEditTriggers(int triggers) {
    QTableView::setEditTriggers((QAbstractItemView::EditTriggers)triggers);
  }

  // What does this do ?
  virtual void selectRow(int row) {
    QTableView::selectRow(row - 1);
  }

  // What does this do ?
  virtual void selectColumn(int row) {
    QTableView::selectColumn(row - 1);
  }

  LuaStackSize currentIndex(lua_State *L) {
    QModelIndex idx = QAbstractItemView::currentIndex();
    lua_pushnumber(L, idx.row() + 1);
    lua_pushnumber(L, idx.column() + 1);
    return 2;
  }

  void setCurrentIndex(int row, int col) {
    QAbstractItemView::setCurrentIndex(
        model()->index(row - 1, col - 1, QModelIndex())
    );
  }

  /** Start editing a cell.
   * We call this function "do_edit" to avoid overloading virtual "edit"
   * function.
   */
  void do_edit(int row, int col) {
    QModelIndex index = model()->index(row - 1, col - 1, QModelIndex());
    QTableView::edit(index);
  }

  void setStretchHorizontal(bool enable) {
    horizontalHeader()->setStretchLastSection(enable);
  }

  void setStretchVertical(bool enable) {
    verticalHeader()->setStretchLastSection(enable);
  }

  void setShowHorizontalHeader(bool enable) {
    if (enable) {
      horizontalHeader()->show();
    } else {
      horizontalHeader()->hide();
    }
  }

  void setShowVerticalHeader(bool enable) {
    if (enable) {
      verticalHeader()->show();
    } else {
      verticalHeader()->hide();
    }
  }

  void foobar();

protected:

  virtual int sizeHintForColumn(int column) const {
    if (!dub_pushcallback("sizeHintForColumn")) return -1;
    lua_State *L = const_cast<lua_State*>(dub_L);
    lua_pushnumber(L, column + 1);
    // ... <func> <self> <column>
    if (!dub_call(2, 1)) return -1;
    int res = lua_tonumber(L, -1);
    lua_pop(L, 1);
    return res;
  }


  virtual void selectionChanged(const QItemSelection & selected, const QItemSelection & deselected ) {
    if (dub_pushcallback("selected")) {
      lua_State *L = dub_L;
      if (selected.indexes().isEmpty()) {
        // ... <selected> <self>
        dub_call(1, 0);
      } else {
        const QModelIndex idx = selected.indexes().last();
        lua_pushnumber(L, idx.row() + 1);
        lua_pushnumber(L, idx.column() + 1);
        // ... <selected> <self> <row> <col>
        dub_call(3, 0);
      }
    }
  }
  //--=============================================== COMMON CALLBACKS [
  virtual void closeEvent(QCloseEvent *event) {
    Widget::closed(this, event);
  }

  virtual void mouseMoveEvent(QMouseEvent *event) {
    Widget::mouse(this, event);
  }

  virtual void mousePressEvent(QMouseEvent *event) {
    if (!click(event, MousePress))
      QTableView::mousePressEvent(event);
  }

  virtual void mouseDoubleClickEvent(QMouseEvent *event) {
    if (!click(event, DoubleClick))
      QTableView::mouseDoubleClickEvent(event);
  }

  virtual void mouseReleaseEvent(QMouseEvent *event) {
    if (!click(event, MouseRelease))
      QTableView::mouseReleaseEvent(event);
  }

  virtual void resizeEvent(QResizeEvent *event) {
    Widget::resized(this, width(), height());
  }

  virtual void moveEvent(QMoveEvent * event) {
    Widget::moved(this, event);
  }

  // Not sure this is useful

  // virtual void showEvent(QShowEvent *event) {
  //   Widget::showHide(this, true);
  // }

  // virtual void hideEvent(QHideEvent *event) {
  //   Widget::showHide(this, false);
  // }

  virtual void keyPressEvent(QKeyEvent *event) {
    if (!Widget::keyboard(this, event, true))
      QTableView::keyPressEvent(event);
  }

  virtual void keyReleaseEvent(QKeyEvent *event) {
    if (!Widget::keyboard(this, event, false))
      QTableView::keyReleaseEvent(event);
  }
  //--=============================================== COMMON CALLBACKS ]

private slots:

  void sliderVActionTriggered(int action) {
    slider(Qt::Vertical, action);
  }

  void sliderHActionTriggered(int action) {
    slider(Qt::Horizontal, action);
  }

private:
  bool click(QMouseEvent *event, int type);
  bool select(const QModelIndex &idx, QEvent *event);
  void slider(int orientation, int action);
};

#endif // LUBYK_INCLUDE_MIMAS_TABLE_VIEW_H_
