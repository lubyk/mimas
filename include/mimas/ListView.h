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
#include "mimas/constants.h"
#include "mimas/DataSource.h"
#include "mimas/Widget.h"

using namespace lubyk;

#include <QtGui/QListView>
#include <QtGui/QHeaderView>
#include <QtGui/QMouseEvent>
#include <QtCore/QPoint>

#include <iostream>


namespace mimas {


/** The ListView is used to display data as a list.
 *
 * @dub destructor: 'luaDestroy'
 *      ignore: 'luaInit'
 */
class ListView : public QListView, public ThreadedLuaObject {
  Q_OBJECT
  Q_PROPERTY(QString class READ cssClass)
  Q_PROPERTY(float hue READ hue WRITE setHue)

  QAbstractItemDelegate *item_delegate_;
  QSize size_hint_;
 public:
  ListView();

  ~ListView();

  // ============================ [ all Widgets

  QString cssClass() const {
    return QString("list");
  }

  QWidget *widget() {
    return this;
  }

  QObject *object() {
    return this;
  }

  /** Get the widget's name.
   */
  LuaStackSize name(lua_State *L) {
    lua_pushstring(L, QObject::objectName().toUtf8().data());
    return 1;
  }

  /** Set the widget's name.
   */
  void setName(const char *name) {
    QObject::setObjectName(QString(name));
  }

  void move(int x, int y) {
    QWidget::move(x, y);
  }

  void resize(int w, int h) {
    QWidget::resize(w, h);
  }

  int x() {
    return QWidget::x();
  }

  int y() {
    return QWidget::y();
  }

  int width() {
    return QWidget::width();
  }

  int height() {
    return QWidget::height();
  }

  void setStyle(const char *text) {
    QWidget::setStyleSheet(QString(".%1 { %2 }").arg(cssClass()).arg(text));
  }

  void setFocus() {
    QWidget::setFocus(Qt::OtherFocusReason);
  }

  void setStyleSheet(const char *text) {
    QWidget::setStyleSheet(text);
  }

  void setHue(float hue) {
    hue_ = hue;
    update();
  }

  float hue() {
    return hue_;
  }

  void update() {
    QWidget::update();
  }

  /** Get size of text with current widget font.
   */
  LuaStackSize textSize(const char *text, lua_State *L) {
    lua_pushnumber(L, fontMetrics().width(text));
    lua_pushnumber(L, fontMetrics().height());
    return 2;
  }

  /** Set the prefered size. Use setSizePolicy to define how the
   * widget resizes compared to this value.
   */
  void setSizeHint(float w, float h) {
    size_hint_ = QSize(w, h);
    updateGeometry();
  }

  /** Control how the widget behaves in a layout related to it's sizeHint().
   */
  void setSizePolicy(int horizontal, int vertical) {
    QWidget::setSizePolicy((QSizePolicy::Policy)horizontal, (QSizePolicy::Policy)vertical);
    updateGeometry();
  }

  // FIXME: maybe we can remove this and only use setSizeHint + setSizePolicy...
  void setMinimumSize(float w, float h) {
    QWidget::setMinimumSize(w, h);
  }

  /** Receive mouse move events even if no button is pressed.
   */
  void setMouseTracking(bool enable) {
    QWidget::setMouseTracking(enable);
  }

  /** Close and delete the window.
   */
  bool close() {
    return QWidget::close();
  }

  bool isVisible() const {
    return QWidget::isVisible();
  }

  void show() {
    QWidget::show();
  }

  void hide() {
    QWidget::hide();
  }

  /** Returns (x,y) position of the widget in the global
   * screen coordinates.
   */
  LuaStackSize globalPosition(lua_State *L) {
    QPoint pt = mapToGlobal(QPoint(0, 0));
    lua_pushnumber(L, pt.x());
    lua_pushnumber(L, pt.y());
    return 2;
  }

  /** Move the widget to the given global coordinates.
   */
  void globalMove(float x, float y) {
    QWidget::move(mapToParent(mapFromGlobal(QPoint(x, y))));
  }

  /** Bring to bottom of parent widget.
   */
  void lower() {
    QWidget::lower();
  }

  /** Bring to top of parent widget.
   */
  void raise() {
    QWidget::raise();
  }
  // ============================================================= all Widgets ]

  // ============================================================= ListView

  /** Return a list of selected elements. Each element is identified
   * with a table {row, col}.
   */
  LuaStackSize selectedIndexes(lua_State *L) {
    QModelIndexList indexes = QListView::selectedIndexes();
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
   */
  LuaStackSize indexAt(float x, float y, lua_State *L) {
    // indexAt calls "data" method in data_source_ (don't ask why...)
    QModelIndex idx = QListView::indexAt(QPoint(x, y));
    if (idx.isValid()) {
      lua_pushnumber(L, idx.row() + 1);
      lua_pushnumber(L, idx.column() + 1);
      return 2;
    } else {
      return 0;
    }
  }

  void selectRow(int row) {
    QModelIndex index = model()->index(row - 1, 0);
    if ( index.isValid() )
        selectionModel()->select( index, QItemSelectionModel::ClearAndSelect );
  }

  /** Use an external model instead of the default one.
   */
  void setModel(DataSource *model) {
    QListView::setModel(model);
  }

  int luaInit(lua_State *L, ListView *obj, const char *class_name) {
    ThreadedLuaObject::luaInit(L, obj, class_name);
    // <self>
    lua_pushlstring(L, "data_source", 11);
    // <self> <'data_source'>
    // <self>
    DataSource *data = new DataSource();
    data->luaInit(L, data, "mimas.DataSource");
    // <self> <'data_source'> <data>
    lua_settable(L, -3); // self.data_source = data
    // <self>
    // make DataSource look in <self> for callbacks
    lua_pushvalue(L, -1);
    // <self> <self>
    lua_pop(data->lua_, 1);
    lua_xmove(L, data->lua_, 1);
    // data: <self>
    // <self>
    setModel(data);
    return 1;
  }

  void scrollToBottom() {
    QListView::scrollToBottom();
  }

  void scrollToTop() {
    QListView::scrollToTop();
  }

  
  /** Turning this option on will call the 'paintItem' callback to draw
   * each cell (with the text as parameter).
   */
  void enablePaintItem(bool enable);

  /** Turning this option on will render html content in
   * each cell.
   */
  void enableHtml(bool enable, const char *css = NULL);
      
protected:
  //--=============================================== COMMON CALLBACKS
  virtual void closeEvent(QCloseEvent *event) {
    Widget::closed(this, event);
  }

  virtual void mouseMoveEvent(QMouseEvent *event) {
    Widget::mouse(this, event);
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

  // --=============================================== COMMON CALLBACKS END

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

  virtual QSize sizeHint() const {
    return size_hint_;
  }

  /** The component's color.
   */
  float hue_;

private:
  friend class ItemPaintDelegate;
  bool paintItem(Painter *p, const QStyleOptionViewItem &option, const QModelIndex &idx);

  bool click(QMouseEvent *event, int type);
  bool select(const QModelIndex &idx, QEvent *event);

};

} // mimas
#endif // LUBYK_INCLUDE_MIMAS_TABLE_VIEW_H_
