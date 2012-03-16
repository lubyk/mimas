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
#ifndef LUBYK_INCLUDE_MIMAS_LINE_EDIT_H_
#define LUBYK_INCLUDE_MIMAS_LINE_EDIT_H_

#include "mimas/mimas.h"
#include "mimas/constants.h"
#include "mimas/Widget.h"

#include <QtGui/QWidget>
#include <QtGui/QLineEdit>
#include <QtGui/QMouseEvent>

/** Label widget.
 * @dub register: LineEdit_core
 *      push: pushobject
 *      super: QLineEdit
 */
class LineEdit : public QLineEdit, public dub::Thread {
  Q_OBJECT
public:
  LineEdit(const char *content = NULL, QWidget *parent = NULL)
     : QLineEdit(content, parent), hue_(-1) {
    QObject::connect(this, SIGNAL(editingFinished()),
                     this, SLOT(editingFinishedSlot()));

    QObject::connect(this, SIGNAL(textEdited(QString)),
                     this, SLOT(textEditedSlot(QString)));
  }

  ~LineEdit() {
  }

  // =============================================================

  void setFocus() { // Qt::FocusReason reason
    QWidget::setFocus(Qt::OtherFocusReason);
  }

  void setFocusPolicy(int policy) {
    QLineEdit::setFocusPolicy((Qt::FocusPolicy)policy);
  }

protected:

  virtual void keyPressEvent(QKeyEvent *event) {
    if (!Widget::keyboard(this, event, true))
      QLineEdit::keyPressEvent(event);
  }

  virtual void keyReleaseEvent(QKeyEvent *event) {
    if (!Widget::keyboard(this, event, false))
      QLineEdit::keyReleaseEvent(event);
  }

  virtual void mousePressEvent(QMouseEvent *event) {
    if (!Widget::click(this, event, MousePress))
      QLineEdit::mousePressEvent(event);
  }

  virtual void mouseDoubleClickEvent(QMouseEvent *event) {
    if (!Widget::click(this, event, DoubleClick))
      QLineEdit::mouseDoubleClickEvent(event);
  }

  virtual void mouseReleaseEvent(QMouseEvent *event) {
    if (!Widget::click(this, event, MouseRelease))
      QLineEdit::mouseReleaseEvent(event);
  }

  virtual void moveEvent(QMoveEvent * event);
  virtual void resizeEvent(QResizeEvent *event);

private:
  virtual void paintEvent(QPaintEvent *event);

private slots:

  // set function to call on text change
  // textChanged(const QString & text)

  // connected to the editingFinished signal
	void editingFinishedSlot();

  // connected to the textEdited signal
	void textEditedSlot(const QString &text);
};

#endif // LUBYK_INCLUDE_MIMAS_LINE_EDIT_H_
