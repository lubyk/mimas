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
#ifndef LUBYK_INCLUDE_MIMAS_APPLICATION_H_
#define LUBYK_INCLUDE_MIMAS_APPLICATION_H_

#include "dub/dub.h"
#include "mimas/mimas.h" // pushVariantInLua

#include <QtGui/QApplication>
#include <QtGui/QMouseEvent>
#include <QtGui/QWidget>

#include <iostream>

/** Application (starts the GUI and manages the event loop).
 *
 * @dub push: pushobject
 *      register: Application_core
 */
class Application : public QApplication, public dub::Thread {
  Q_OBJECT
public:

  enum ApplicationType {
    Desktop,
    Plugin,
  };

  Application();

  ~Application();

  /** Start event loop.
   */
  int exec();

  // Maybe this could be used for automated testing.
  // void postEvent(QObject *receiver, QEvent *event) {
  //   QApplication::postEvent(receiver, event);

  /** Return the size of the desktop as a pair (width, height).
   */
  LuaStackSize screenSize(lua_State *L);

  /** Simulate user click events (used for testing).
   */
  void click(QWidget *widget,
      int x = 10,
      int y = 10,
      int type = QEvent::None,
      int btn  = Qt::LeftButton,
      int mod  = Qt::NoModifier
      ) {
    if (type == QEvent::None) {
      sendMouseEvent(widget, QPoint(x,y), QEvent::MouseButtonPress, btn, mod);
      sendMouseEvent(widget, QPoint(x,y), QEvent::MouseButtonRelease, btn, mod);
    } else {
      sendMouseEvent(widget, QPoint(x,y), type, btn, mod);
    }
  }

  /** Simulate user mouse events (used for testing).
   */
  void mouse(QWidget *widget, int x = 10, int y = 10) {
    sendMouseEvent(widget, QPoint(x,y), QEvent::MouseMove, Qt::NoButton, Qt::NoModifier);
  }

protected:
  void sendMouseEvent(QWidget *widget, const QPoint &pos, int type, int btn, int mod) {
    sendEvent(widget, new QMouseEvent(
        (QEvent::Type)type,
        // local to widget
        pos,
        // global
        widget->mapToGlobal(pos),
        (Qt::MouseButton)btn,
        (Qt::MouseButton)btn,
        (Qt::KeyboardModifiers)mod
       ));
  }

  /** Application event handler.
   */
  virtual bool event(QEvent *event);

  /** Key to retrieve 'this' value from a running thread.
   */
  static pthread_key_t sAppKey;

  /** Termination signal handler.
   */
  static void terminate(int sig);
};

#endif // LUBYK_INCLUDE_MIMAS_APPLICATION_H_
