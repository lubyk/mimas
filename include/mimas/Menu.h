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
#ifndef LUBYK_INCLUDE_MIMAS_MENU_H_
#define LUBYK_INCLUDE_MIMAS_MENU_H_

#include "mimas/mimas.h"
#include "mimas/Action.h"
#include "mimas/Color.h"
#include <QtGui/QMenu>

#include <iostream>

/** A Menu is an element from a MenuBar.
 * FIXME: The Menu does not need to have dub_L: what is the
 * cost of this lua thread ? Should we remove it ?
 *
 * @see MenuBar
 * @see QMenu
 * @dub push: pushobject
 */
class Menu : public QMenu, public dub::Thread {
  Q_OBJECT
public:
  Menu(const char *name = "")
      : QMenu(QString(name)) {
  }

  ~Menu() {
  }

  void popup(int gx, int gy) {
    QMenu::popup(QPoint(gx,gy));
  }
};

#endif // LUBYK_INCLUDE_MIMAS_MENU_H_

