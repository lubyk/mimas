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
#ifndef LUBYK_INCLUDE_MIMAS_LIST_VIEW_H_
#define LUBYK_INCLUDE_MIMAS_LIST_VIEW_H_

#include "mimas/mimas.h"
#include "mimas/DataSource.h"
#include "mimas/Widget.h"

#include <QtGui/QListView>
#include <QtGui/QHeaderView>
#include <QtGui/QMouseEvent>
#include <QtCore/QPoint>

#include <iostream>


/** The ListView is used to display data as a list.
 *
 * @dub register: ListView_core
 *      push: pushobject
 *      super: QListView
 */
class ListView : public QListView, public dub::Thread {
  Q_OBJECT
  QAbstractItemDelegate *item_delegate_;
 public:

  ListView(QWidget *parent = NULL);

  ~ListView();

  // ============================================================= ListView
  void selectRow(int row) {
    QModelIndex index = model()->index(row - 1, 0);
    if ( index.isValid() )
        selectionModel()->select( index, QItemSelectionModel::ClearAndSelect );
  }

  /** Turning this option on will call the 'paintItem' callback to draw
   * each cell (with the text as parameter).
   */
  void enablePaintItem(bool enable);

  /** Turning this option on will render html content in
   * each cell.
   */
  void enableHtml(bool enable, const char *css = NULL);
      
  /** Return a list of selected elements. Each element is identified
   * with a table {row, col}.
   *
   * @dub name: selectedIndexes
   */
  LuaStackSize lselectedIndexes(lua_State *L) {
    QModelIndexList indexes = selectedIndexes();
    lua_newtable(L);
    // <tbl>
    int i = 0;
    foreach(QModelIndex index, indexes) {
      ++i;
      lua_newtable(L);
      lua_pushnumber(L, index.row() + 1);
      // <tbl> <tbl> row
      lua_rawseti(L, -2, 1);
      lua_pushnumber(L, index.column() + 1);
      // <tbl> <tbl> col
      lua_rawseti(L, -2, 2);
      // <tbl> <tbl>
      lua_rawseti(L, -2, i);
    }
    return 1;
  }

  /** Return the index of the model at the given x,y position.
   * @return row, col
   *
   * @dub name: indexAt
   */
  LuaStackSize lindexAt(float x, float y, lua_State *L) {
    // indexAt calls "data" method in data_source_ (don't ask why...)
    QModelIndex idx = indexAt(QPoint(x, y));
    if (idx.isValid()) {
      lua_pushnumber(L, idx.row() + 1);
      lua_pushnumber(L, idx.column() + 1);
      return 2;
    } else {
      return 0;
    }
  }

protected:

  //--=============================================== COMMON CALLBACKS [
  virtual void closeEvent(QCloseEvent *event) {
    Widget::closed(this, event);
  }

  virtual void mouseMoveEvent(QMouseEvent *event) {
    Widget::mouse(this, event);
  }

  virtual void mousePressEvent(QMouseEvent *event) {
    if (!click(event, MousePress))
      QListView::mousePressEvent(event);
  }

  virtual void mouseDoubleClickEvent(QMouseEvent *event) {
    if (!click(event, DoubleClick))
      QListView::mouseDoubleClickEvent(event);
  }

  virtual void mouseReleaseEvent(QMouseEvent *event) {
    if (!click(event, MouseRelease))
      QListView::mouseReleaseEvent(event);
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
      QListView::keyPressEvent(event);
  }

  virtual void keyReleaseEvent(QKeyEvent *event) {
    if (!Widget::keyboard(this, event, false))
      QListView::keyReleaseEvent(event);
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
  friend class ItemPaintDelegate;
  bool paintItem(Painter *p, const QStyleOptionViewItem &option, const QModelIndex &idx);

  bool click(QMouseEvent *event, int type);
  bool select(const QModelIndex &idx, QEvent *event);
  void slider(int orientation, int action);

};

#endif // LUBYK_INCLUDE_MIMAS_LIST_VIEW_H_
