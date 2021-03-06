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
#ifndef LUBYK_INCLUDE_MIMAS_BUTTON_H_
#define LUBYK_INCLUDE_MIMAS_BUTTON_H_

#include "mimas/mimas.h"
#include "mimas/Widget.h"

#include <QtGui/QPushButton>
#include <QtGui/QMouseEvent>

#include <iostream>

/** Button widget.
 *
 * @dub register: Button_core
 *      push: pushobject
 *      super: QPushButton
 */
class Button : public QPushButton, public dub::Thread {
  Q_OBJECT
public:
  Button(const char *title = NULL, QWidget *parent = NULL)
      : QPushButton(title, parent) {
    QObject::connect(this, SIGNAL(clicked()),
                     this, SLOT(clickedSlot()));
  }

  ~Button() {
  }

private slots:
  void clickedSlot() {
    if (!dub_pushcallback("click")) return;
    // <func> <self>
    dub_call(1, 0);
  }
};

#endif // LUBYK_INCLUDE_MIMAS_BUTTON_H_
