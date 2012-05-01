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
#ifndef LUBYK_INCLUDE_MIMAS_SOCKET_NOTIFIER_H_
#define LUBYK_INCLUDE_MIMAS_SOCKET_NOTIFIER_H_

#include "mimas/mimas.h"

#include <QtCore/QSocketNotifier>

/** SocketNotifer wraps filedescriptors so that they can be used
 * in Qt's event loop. A SocketNotifer can only be used for a single
 * file descriptor and a single event (read or write).
 *
 * @dub register: SocketNotifier_core
 *      push: pushobject
 *      super: QObject
 */
class SocketNotifier : public QSocketNotifier, public dub::Thread {
  Q_OBJECT
public:
  enum EventType {
    Read  = QSocketNotifier::Read,
    Write = QSocketNotifier::Write,
  };

  SocketNotifier(int fd, int event_type)
      : QSocketNotifier(fd, (QSocketNotifier::Type)event_type) {
    QObject::connect(this, SIGNAL(activated(int)),
                     this, SLOT(activatedSlot(int)));
  }

  virtual ~SocketNotifier() {
  }

  int socket() const {
    return QSocketNotifier::socket();
  }


  /** Enable or disable a socket notifier.
   */
  void setEnabled(bool enabled) {
    QSocketNotifier::setEnabled(enabled);
  }

private slots:
  void activatedSlot(int socket) {
    if (dub_pushcallback("activated")) {
      // <func> <self>
      dub_call(1, 0);
    }
  }
};
#endif // LUBYK_INCLUDE_MIMAS_SOCKET_NOTIFIER_H_
