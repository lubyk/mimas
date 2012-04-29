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
#ifndef LUBYK_INCLUDE_MIMAS_WIDGET_H_
#define LUBYK_INCLUDE_MIMAS_WIDGET_H_

#include "mimas/mimas.h"
// Used for addAction.
#include "mimas/Action.h"

#include <QtGui/QWidget>
#include <QtGui/QMouseEvent>
#include <QtCore/QPoint>

class Painter;

/** The Widget is used to display custom elements or windows.
 * The Widget uses the following callbacks:  paint, mouse,
 * click, keyboard, move and resized.
 *
 * @see QWidget
 * @dub push: pushobject
 *      register: Widget_core
 *      ignore: keyboard, mouse, click, paint, resized, moved, closed, showHide
 */
class Widget : public QWidget, public dub::Thread {
  Q_OBJECT
  Q_PROPERTY(QString class READ cssClass)
  QString css_class_;

public:
  Widget(int window_flags)
    : QWidget(NULL, (Qt::WindowFlags)window_flags)
    , css_class_("widget") {
    setAttribute(Qt::WA_DeleteOnClose);
  }

  Widget(QWidget *parent = 0, int window_flags = 0) :
    QWidget(parent, (Qt::WindowFlags)window_flags) {
    setAttribute(Qt::WA_DeleteOnClose);
  }

  ~Widget() {}

  QString cssClass() const {
    return css_class_;
  }

  void setCssClass(const char *css_class) {
    css_class_ = css_class;
    update();
  }

  void setStyle(const char *text) {
    setStyleSheet(QString("Widget { %2 }").arg(text));
  }

  // ============================================================ Dialog
  LuaStackSize getOpenFileName(const char *caption,
      const char *base_dir,
      const char *filter,
      int options,
      lua_State *L);
  LuaStackSize getExistingDirectory(const char *caption,
      const char *base_dir,
      int options,
      lua_State *L);

  /** Common keyboard, mouse and click event handling to many widgets.
   */
  static bool keyboard(dub::Thread *obj, QKeyEvent *event, bool isPressed);
  static bool mouse(dub::Thread *obj, QMouseEvent *event);
  static bool click(dub::Thread *obj, QMouseEvent *event, int type);
  static void paint(dub::Thread *obj, Painter *p, int w, int h);
  static void resized(dub::Thread *obj, double width, double height);
  static void moved(dub::Thread *obj, QMoveEvent *event);
  static void closed(dub::Thread *obj, QCloseEvent *event);
  static void showHide(dub::Thread *obj, bool shown);
protected:

  virtual void paintEvent(QPaintEvent *event);

  //--=============================================== COMMON CALLBACKS [
  virtual void closeEvent(QCloseEvent *event) {
    Widget::closed(this, event);
  }

  virtual void mouseMoveEvent(QMouseEvent *event) {
    Widget::mouse(this, event);
  }

  virtual void mousePressEvent(QMouseEvent *event) {
    if (!Widget::click(this, event, MousePress))
      QWidget::mousePressEvent(event);
  }

  virtual void mouseDoubleClickEvent(QMouseEvent *event) {
    if (!Widget::click(this, event, DoubleClick))
      QWidget::mouseDoubleClickEvent(event);
  }

  virtual void mouseReleaseEvent(QMouseEvent *event) {
    if (!Widget::click(this, event, MouseRelease))
      QWidget::mouseReleaseEvent(event);
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
      QWidget::keyPressEvent(event);
  }

  virtual void keyReleaseEvent(QKeyEvent *event) {
    if (!Widget::keyboard(this, event, false))
      QWidget::keyReleaseEvent(event);
  }

  //--=============================================== COMMON CALLBACKS ]
};

#endif // LUBYK_INCLUDE_MIMAS_WIDGET_H_
