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

#define CHECKERROR(msg) ErrorCheckValue = glGetError();\
if (ErrorCheckValue != GL_NO_ERROR) { \
  fprintf(stderr, "%s: %s \n", #msg, gluErrorString(ErrorCheckValue)); \
  exit(-1); \
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
#ifdef __macosx__
  struct GLSLContext : public QGLContext {
    GLSLContext(const QGLFormat& format, QPaintDevice* device) : QGLContext(format,device) {}
    GLSLContext(const QGLFormat& format) : QGLContext(format) {}

    virtual void* chooseMacVisual(GDHandle handle) {
      return mimasSelectModernOpenGLMac(handle);
    }
  };
#else
  struct GLSLFormat : public QGLFormat {
    GLSLFormat() {
      setVersion(3, 2);
      setProfile(QGLFormat::CoreProfile);
      setSampleBuffers(true);
    }
  };
#endif // __macosx__

public:
 
  GLWidget()
#ifdef __macosx__
    : QGLWidget(new GLSLContext(QGLFormat::defaultFormat()))
#else
    : QGLWidget(GLSLFormat())
#endif
  {
    setAttribute(Qt::WA_DeleteOnClose);
    // get focus on tab and click
    setFocusPolicy(Qt::StrongFocus);
  }   

  ~GLWidget() {
    destroyShaders();
    destroyVBO();
  }

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
      printf("COMPILE...\n");
      createShaders(vertex_shader, fragment_shader);
      createVBO();
    }
    update();
    return true;
  }

protected:
  virtual void initializeGL() {
    printf("glewInit\n");     
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err) {
      fprintf(
        stderr,
        "glewInit error: %s\n",
        glewGetErrorString(err)
        );
      exit(EXIT_FAILURE);
    } 
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
  }
  /*
    lua_State *L = lua_;

    if (!pushLuaCallback("initializeGL")) return;
    // <func> <self>
    int status = lua_pcall(L, 1, 0, 0);

    if (status) {
      fprintf(stderr, "Error in 'initializeGL' callback: %s\n", lua_tostring(L, -1));
    }
  }
  */

  virtual void resizeGL(int width, int height) {
    glViewport(0, 0, width, height);
  }
/*

    lua_State *L = lua_;

    if (!pushLuaCallback("resizeGL")) return;
    lua_pushnumber(L, width);
    lua_pushnumber(L, height);
    // <func> <self> <width> <height>
    int status = lua_pcall(L, 3, 0, 0);

    if (status) {
      fprintf(stderr, "Error in 'resizeGL' callback: %s\n", lua_tostring(L, -1));
    }
  }
  */

  virtual void paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
  }
  /*
    lua_State *L = lua_;

    if (!pushLuaCallback("paintGL")) return;
    // <func> <self>
    int status = lua_pcall(L, 1, 0, 0);

    if (status) {
      fprintf(stderr, "Error in 'paintGL' callback: %s\n", lua_tostring(L, -1));
    }
  }
  */

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
    VertexShaderId,
    FragmentShaderId,
    ProgramId,
    VaoId,
    VboId,
    ColorBufferId;
   
  // FIXME: Write gl bindings so that we can do all this in Lua.
  void createVBO();

  void destroyVBO();

  void createShaders(const char *vertex_shader, const char *fragment_shader);

  void destroyShaders();
};

#endif // LUBYK_INCLUDE_MIMAS_GLWIDGET_H_

