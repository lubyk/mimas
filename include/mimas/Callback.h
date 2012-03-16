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
#ifndef LUBYK_INCLUDE_MIMAS_CALLBACK_H_
#define LUBYK_INCLUDE_MIMAS_CALLBACK_H_

#include "mimas/mimas.h"

#include <QtCore/QObject>
#include <QtCore/QEvent>

#include "mimas/Button.h"

#include <string>

/** Calls a lua function back.
 *
 * @dub lib_name:'Callback_core'
 *      ignore: 'callback'
 *      super: 'QObject'
 */
class Callback : public QObject, public dub::Thread {
  Q_OBJECT
public:
  // Our own custom event id
  static const QEvent::Type EventType;

  Callback() {
  }

  virtual ~Callback() {
  }

  void connect(QObject *obj, const char *method, const char *callback) {
    QObject::connect(obj, method, this, callback);
  }

  /** Simple event that should execute a callback on reception.
   */
  class Event : public QEvent
  {
    public:
      Callback *callback_;

      Event(Callback *clbk)
        : QEvent(Callback::EventType),
          callback_(clbk) {}
  };

public slots:
  void callback() {
    if (!dub_pushcallback("callback")) return;
    // <func> <self>
    dub_call(1, 0);
  }

  void callback(double value) {
    if (!dub_pushcallback("callback")) return;
    lua_pushnumber(dub_L, value);
    // <func> <self> <number>
    dub_call(2, 0);
  }

  void callback(int value) {
    callback((double)value);
  }
};

} // mimas

#endif // LUBYK_INCLUDE_MIMAS_CALLBACK_H_
