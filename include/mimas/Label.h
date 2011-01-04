/*
  ==============================================================================

   This file is part of the RUBYK project (http://rubyk.org)
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
#ifndef RUBYK_INCLUDE_MIMAS_LABEL_H_
#define RUBYK_INCLUDE_MIMAS_LABEL_H_

#include "rubyk.h"
#include <QtGui/QLabel>

#include <iostream>

namespace mimas {

/** Label widget.
 * @dub lib_name:'Label_core'
 */
class Label : public QLabel
{
  Q_OBJECT
public:
  Label(const char *title = NULL)
   : QLabel(title) {}

  Label(const char *title, QWidget *parent)
   : QLabel(title, parent) {}

  ~Label() {}

  void setText(const char *text) {
    QLabel::setText(QString(text));
  }

  void setStyle(const char *text) {
    QLabel::setStyleSheet(QString("QLabel { %1 }").arg(text));
  }

  QWidget *widget() {
    return this;
  }

  QObject *object() {
    return this;
  }

  /** Set widget color.
   */
  void setHue(float hue);

  void move(int x, int y) {
    QWidget::move(x, y);
  }

  void resize(int w, int h) {
    QWidget::resize(w, h);
  }

protected:
  //virtual void paintEvent(QPaintEvent *event);

  /** The component's color.
   */
  float hue_;

  /** Cached text color.
   */
  QColor text_color_;
};

} // mimas
#endif // RUBYK_INCLUDE_MIMAS_LABEL_H_