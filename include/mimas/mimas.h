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
#ifndef LUBYK_INCLUDE_MIMAS_MIMAS_H_
#define LUBYK_INCLUDE_MIMAS_MIMAS_H_

#include "dub/dub.h"
#include <QtCore/QVariant>

enum ClickTypes {
  MousePress   = 1,
  MouseRelease = 2,
  DoubleClick  = 3,
  // Used to detect event type in controls.
  MouseMove    = 4,
};


#define MIMAS_COMMON QSize size_hint_; \
  QString css_class_; \
  virtual QSize sizeHint() const { \
    return size_hint_; \
  } \
  QString cssClass() const { \
    return css_class_; \
  } \

QVariant variantFromLua(lua_State *L, int index);
int pushVariantInLua(lua_State *L, const QVariant &value);

#endif // LUBYK_INCLUDE_MIMAS_MIMAS_H_
