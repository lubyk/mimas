#include "mimas/GLWidget.h"

#ifdef __macosx__
struct GLSLContext : public QGLContext {
  GLSLContext(const QGLFormat &format, QPaintDevice *device) : QGLContext(format,device) {}
  GLSLContext(const QGLFormat &format) : QGLContext(format) {}

  virtual void* chooseMacVisual(GDHandle handle) {
    return mimasSelectModernOpenGLMac(handle);
  }
};
#else
struct GLSLFormat : public QGLFormat {
  GLSLFormat(const QGLFormat &format) : QGLFormat(format) {
    setVersion(3, 2);
    setProfile(QGLFormat::CoreProfile);
    setSampleBuffers(true);
  }
};
#endif // __macosx__


GLWidget::GLWidget(int options)
#ifdef __macosx__
  : QGLWidget(new GLSLContext(QGLFormat((QGL::FormatOptions)options))) {
#else
  : QGLWidget(GLSLFormat(QGLFormat((QGL::FormatOptions)options))) {
#endif
  // FIXME: Linux VM without OpenGL displays an error but marks as valid.
  // see related bug below.
  if (!isValid()) throw dub::Exception("Could not create OpenGL context.");
  setAttribute(Qt::WA_DeleteOnClose);
  // get focus on tab and click
  setFocusPolicy(Qt::StrongFocus);
}   

GLWidget::~GLWidget() {}

