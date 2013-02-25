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
#ifndef LUBYK_INCLUDE_MIMAS_TIMER_H_
#define LUBYK_INCLUDE_MIMAS_TIMER_H_

#include "mimas/mimas.h"

#include <QtCore/QTimer>

/** The Timer class calls the "timeout" callback at regular intervals.
 *
 * @dub register: Timer_core
 *      push: pushobject
 *      super: QObject
 */
class Timer : public QTimer, public dub::Thread {
  Q_OBJECT
public:

  /** Private constructor. Use MakeApplication instead.
   */
  Timer(double timeout)
    : QTimer(0)
  {
    setInterval(timeout);
    QObject::connect(this, SIGNAL(timeout()),
                     this, SLOT(timeoutSlot()));

  }

  virtual ~Timer() {
  }

  /** Expects an interval in seconds.
   */
  void start(double interval) {
    QTimer::start(interval * 1000);
  }

  void start() {
    QTimer::start();
  }

  void stop() {
    QTimer::stop();
  }

  /** Expects an interval in seconds.
   */
  void setInterval(double interval) {
    // QTimer expects an interval in milliseconds.
    QTimer::setInterval(interval * 1000);
  }

private slots:
  void timeoutSlot() {
    if (dub_pushcallback("timeout")) {
      // <func> <self>
      dub_call(1, 0);
    }
  }
};

#endif // LUBYK_INCLUDE_MIMAS_TIMER_H_

