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

#include <QtGui/QApplication>
#include <QtCore/QTimer>

#include <iostream>

/** Application (starts the GUI and manages the event loop).
 *
 * @dub push: pushobject
 *      register: Application_core
 */
class Application : public QApplication, dub::Thread {
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

  /** Key to retrieve 'this' value from a running thread.
   */
  static pthread_key_t sAppKey;

  /** Termination signal handler.
   */
  static void terminate(int sig);

  /** Return the size of the desktop as a pair (width, height).
   */
  LuaStackSize screenSize(lua_State *L) {
    QRect rect = desktop()->geometry();
    lua_pushnumber(L, rect.width());
    lua_pushnumber(L, rect.height());
    return 2;
  }

protected:
  /** Application event handler.
   */
  virtual bool event(QEvent *event);
 }
};

#endif // LUBYK_INCLUDE_MIMAS_APPLICATION_H_
