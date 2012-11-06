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

#include "GL/glew.h"

#include "mimas/mimas.h"
#include "mimas/Widget.h"

#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QGLContext>

#ifdef __macosx__
  //#include <OpenGL/gl.h>
  //#include <OpenGL/glu.h>
  void* mimasSelectModernOpenGLMac(GDHandle handle);
#else
  //#include <GL/gl.h>
  //#include <GL/glu.h>
#endif

#define CHECKERROR(msg) gl_error = glGetError();\
if (gl_error != GL_NO_ERROR) { \
  fprintf(stderr, "%s: %s \n", #msg, gluErrorString(gl_error)); \
}
  
/** GLWidget
 * This class lets you draw OpenGL elements with Widgets on top.
 * http://doc.trolltech.com/qq/qq26-openglcanvas.html
 *
 * @dub register: GLWidget_core
 *      push: pushobject
 *      super: QWidget
 */
class GLWidget : public QGLWidget, public dub::Thread {
  Q_OBJECT
public:
  GLWidget();

  ~GLWidget();

  // =============================================================

  void update() {
    QGLWidget::update();
  }
  
  LuaStackSize openGLVersion(lua_State *L) {
    lua_pushstring(L, (char*)glGetString(GL_VERSION));
    lua_pushstring(L, (char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
    return 2;
  }

  bool compile(const char *vertex_shader, const char *fragment_shader) {
    if (!isVisible()) {
      // This should initialize OpenGL
      show();
    }
    if (!glGetString(GL_VERSION)) {
      printf("OpenGL not initialized. Show window before compiling.\n");
    } else {
      createShaders(vertex_shader, fragment_shader);
      createVBO();
    }
    update();
    return true;
  }

protected:
  virtual void initializeGL() {
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err) {
      throw dub::Exception(
        "glewInit error: %s\n",
        glewGetErrorString(err)
        );
    } 

    if (!dub_pushcallback("initializeGL")) return;
    // <func> <self>
    dub_call(1, 0);
  }

  virtual void resizeGL(int width, int height) {
    // glViewport(0, 0, width, height);
    lua_State *L = dub_L;

    if (!dub_pushcallback("resizeGL")) return;
    lua_pushnumber(L, width);
    lua_pushnumber(L, height);
    // <func> <self> <width> <height>
    dub_call(3, 0);
  }

  virtual void paintGL() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glDrawArrays(GL_TRIANGLES, 0, 3);

    if (!dub_pushcallback("paintGL")) return;
    // <func> <self>
    dub_call(1, 0);
  }

  // --=============================================== Widget callbacks
  virtual void closeEvent(QCloseEvent *event) {
    Widget::closed(this, event);
  }

  virtual void mouseMoveEvent(QMouseEvent *event) {
    Widget::mouse(this, event);
  }

  virtual void mousePressEvent(QMouseEvent *event) {
    if (!Widget::click(this, event, MousePress))
      QWidget::mousePressEvent(event);
  }

  virtual void mouseDoubleClickEvent(QMouseEvent *event) {
    if (!Widget::click(this, event, DoubleClick))
      QWidget::mouseDoubleClickEvent(event);
  }

  virtual void mouseReleaseEvent(QMouseEvent *event) {
    if (!Widget::click(this, event, MouseRelease))
      QWidget::mouseReleaseEvent(event);
  }

  virtual void resizeEvent(QResizeEvent *event) {
    Widget::resized(this, width(), height());
  }

  virtual void moveEvent(QMoveEvent * event) {
    Widget::moved(this, event);
  }

  virtual void keyPressEvent(QKeyEvent *event) {
    if (!Widget::keyboard(this, event, true))
      QWidget::keyPressEvent(event);
  }

  virtual void keyReleaseEvent(QKeyEvent *event) {
    if (!Widget::keyboard(this, event, false))
      QWidget::keyReleaseEvent(event);
  }



  //virtual void paintEvent(QPaintEvent *event);
private:
  GLuint
    vertext_shader_id_,
    fragment_shader_id_,
    program_id_,
    vao_id_,
    vbo_id_,
    color_buffer_id_;
   
  // FIXME: Write gl bindings so that we can do all this in Lua.
  void createVBO();

  void destroyVBO();

  void createShaders(const char *vertex_shader, const char *fragment_shader);

  void destroyShaders();
};

#endif // LUBYK_INCLUDE_MIMAS_GLWIDGET_H_

