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
#ifndef LUBYK_INCLUDE_MIMAS_GLWIDGET_H_
#define LUBYK_INCLUDE_MIMAS_GLWIDGET_H_

#include "mimas/mimas.h"
#include "mimas/Widget.h"

#include <QtGui/QWidget>
#include <QtGui/QGraphicsScene>
#include <QtOpenGL/QtOpenGL>

#include <iostream>

/** LegacyGLWidget
 * This class lets you draw OpenGL 1.x elements with Widgets on top.
 * http://doc.trolltech.com/qq/qq26-openglcanvas.html
 *
 * @dub push: pushobject
 *      super: QWidget
 */
class LegacyGLWidget : public QGraphicsView, public dub::Thread {
  Q_OBJECT

  class OpenGLScene : public QGraphicsScene {
  public:
    LegacyGLWidget *master_;
    bool resized_;

    OpenGLScene(LegacyGLWidget *master)
        : master_(master)
        , resized_(false)
    {}

    virtual void drawBackground(QPainter *painter, const QRectF &rect) {
      master_->initializeGL();
      if (resized_) {
        master_->resizeGL(width(), height());
        resized_ = false;
      }
      master_->paintGL();
      // Could we draw 2D stuff with painter also ?
      // master_->paint(painter, width(), height());
    }
  };

  OpenGLScene *gl_scene_;
public:
  LegacyGLWidget() {
    setViewport(new QGLWidget(QGLFormat(
            QGL::SampleBuffers
            )));
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    gl_scene_ = new OpenGLScene(this);
    setScene(gl_scene_);

    setAttribute(Qt::WA_DeleteOnClose);
    // get focus on tab and click
    setFocusPolicy(Qt::StrongFocus);
  }   

  ~LegacyGLWidget() {
  }

  void addWidgetToScene(QWidget *widget, float x=0, float y=0) {
    gl_scene_->addWidget(widget);
    widget->move(x, y);
    widget->show();
  }

  // =============================================================

  void update() {
    gl_scene_->update();
  }

protected:
  /** Force the scene to have the same size as the view.
   */
  void resizeEvent(QResizeEvent *event) {
    gl_scene_->resized_ = true;
    gl_scene_->setSceneRect(QRect(QPoint(0, 0), event->size()));
    QGraphicsView::resizeEvent(event);
  }

  virtual void initializeGL() {
    if (!dub_pushcallback("initializeGL")) return;
    // <func> <self>
    dub_call(1, 0);
  }

  virtual void resizeGL(int width, int height) {
    if (!dub_pushcallback("resizeGL")) return;
    lua_pushnumber(dub_L, width);
    lua_pushnumber(dub_L, height);
    // <func> <self> <width> <height>
    dub_call(3, 0);
  }

  virtual void paintGL() {
    if (!dub_pushcallback("paintGL")) return;
    // <func> <self>
    dub_call(1, 0);
  }

  virtual void mousePressEvent(QMouseEvent *event) {
    if (!Widget::click(this, event, MousePress))
      QGraphicsView::mousePressEvent(event);
  }

  virtual void mouseDoubleClickEvent(QMouseEvent *event) {
    if (!Widget::click(this, event, DoubleClick))
      QGraphicsView::mouseDoubleClickEvent(event);
  }

  virtual void mouseReleaseEvent(QMouseEvent *event) {
    if (!Widget::click(this, event, MouseRelease))
      QGraphicsView::mouseReleaseEvent(event);
  }

  virtual void mouseMoveEvent(QMouseEvent *event) {
    if (!Widget::mouse(this, event))
      QGraphicsView::mouseMoveEvent(event);
  }

  //virtual void paintEvent(QPaintEvent *event);

  virtual void keyPressEvent(QKeyEvent *event) {
    if (!Widget::keyboard(this, event, true))
      QGraphicsView::keyPressEvent(event);
  }

  virtual void keyReleaseEvent(QKeyEvent *event) {
    if (!Widget::keyboard(this, event, false))
      QGraphicsView::keyReleaseEvent(event);
  }

private:
  // virtual void paintEvent(QPaintEvent *event) {
  //   makeCurrent();

  //   glMatrixMode(GL_MODELVIEW);
  //   glPushMatrix();

  //   setupViewport(width(), height());
  //   initializeGL();
  //   paintGL();

  //   // Paint
  //   glShadeModel(GL_FLAT);
  //   glDisable(GL_CULL_FACE);
  //   glDisable(GL_DEPTH_TEST);
  //   glDisable(GL_LIGHTING);
  //   glMatrixMode(GL_MODELVIEW);
  //   glPopMatrix();
  //   Painter painter(this);
  //   painter.setRenderHint(QPainter::Antialiasing);
  //   paint(painter);
  //   // Paint children ??
  //   painter.end();
  // }

  // void paint(Painter &p) {
  //   lua_State *L = lua_;

  //   if (!pushLuaCallback("paint")) return;

  //   // Deletable out of Lua
  //   lua_pushclass2<Painter>(L, &p, "mimas.Painter");
  //   lua_pushnumber(L, width());
  //   lua_pushnumber(L, height());
  //   // <func> <self> <Painter> <width> <height>
  //   int status = lua_pcall(L, 4, 0, 0);

  //   if (status) {
  //     fprintf(stderr, "Error in 'paint' callback: %s\n", lua_tostring(L, -1));
  //   }
  // }
};

#endif // LUBYK_INCLUDE_MIMAS_GLWIDGET_H_
