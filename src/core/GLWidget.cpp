#include "mimas/GLWidget.h"

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


GLWidget::GLWidget()
#ifdef __macosx__
  : QGLWidget(new GLSLContext(QGLFormat::defaultFormat()))
#else
  : QGLWidget(GLSLFormat())
#endif
  , vertext_shader_id_(0)
  , fragment_shader_id_(0)
  , program_id_(0)
  , vao_id_(0)
  , vbo_id_(0)
  , color_buffer_id_(0) {
  // FIXME: Linux VM without OpenGL displays an error but marks as valid.
  // see related bug below.
  if (!isValid()) throw dub::Exception("Could not create OpenGL context.");
  setAttribute(Qt::WA_DeleteOnClose);
  // get focus on tab and click
  setFocusPolicy(Qt::StrongFocus);
}   

GLWidget::~GLWidget() {
  destroyShaders();
  destroyVBO();
}

const GLchar* FragmentShader = {
    "#version 150\n"\
 
    "in vec4 ex_Color;\n"\
    "out vec4 out_Color;\n"\
 
    "void main(void)\n"\
    "{\n"\
    "   out_Color = ex_Color;\n"\
    "}\n"
};

const GLchar* VertexShader = {
    "#version 150\n"\
 
    "layout(location=0) in vec4 in_Position;\n"\
    "layout(location=1) in vec4 in_Color;\n"\
    "out vec4 ex_Color;\n"\
 
    "void main(void)\n"\
    "{\n"\
    "   gl_Position = in_Position;\n"\
    "   ex_Color = in_Color;\n"\
    "}\n"
};
 
static bool compileShader(GLuint shader_id, const char *source) {
  GLenum gl_error = glGetError();
  //glShaderSource(vertext_shader_id_, 1, &source, NULL);
  glShaderSource(shader_id, 1, &source, NULL);
  CHECKERROR(glShaderSource);
  glCompileShader(shader_id);
  CHECKERROR(glCompileShader);
  GLint params;
  glGetShaderiv(shader_id, GL_COMPILE_STATUS, &params);
  if (GL_FALSE == params) {
    GLint len;
    //glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &len);
    char buf[2048];
    glGetShaderInfoLog(shader_id, 2084, &len, buf);
    throw dub::Exception("Compilation error: %s\n", buf);
  }
  return true;
}

void GLWidget::createShaders(const char *vertex_shader, const char *fragment_shader) {
  GLenum gl_error = glGetError();

  vertext_shader_id_ = glCreateShader(GL_VERTEX_SHADER);
  CHECKERROR(glCreateShader);
  if (!compileShader(vertext_shader_id_, vertex_shader)) return;


  fragment_shader_id_ = glCreateShader(GL_FRAGMENT_SHADER);
  CHECKERROR(glCreateShader);
  if (!compileShader(fragment_shader_id_, fragment_shader)) return;

  program_id_ = glCreateProgram();
  CHECKERROR(glCreateProgram);
  glAttachShader(program_id_, vertext_shader_id_);
  CHECKERROR(glAttachShader);
  glAttachShader(program_id_, fragment_shader_id_);
  CHECKERROR(glAttachShader2);
  glLinkProgram(program_id_);
  CHECKERROR(glLinkProgram);
  glUseProgram(program_id_);
  CHECKERROR(glUseProgram);
}

void GLWidget::destroyShaders() {
  if (program_id_ == 0) return;
  GLenum gl_error = glGetError();
  glUseProgram(0);
  glDetachShader(program_id_, vertext_shader_id_);
  glDetachShader(program_id_, fragment_shader_id_);
  if (fragment_shader_id_ > 0) glDeleteShader(fragment_shader_id_);
  if (fragment_shader_id_ > 0) glDeleteShader(vertext_shader_id_);

  glDeleteProgram(program_id_);
  CHECKERROR(destroyShaders);
}

void GLWidget::createVBO() {
  GLenum gl_error = glGetError();

  GLfloat Vertices[] = {
    -0.8f, -0.8f, 0.0f, 1.0f,
    0.0f,  0.8f, 0.0f, 1.0f,
    0.8f, -0.8f, 0.0f, 1.0f
  };

  GLfloat Colors[] = {
    1.0f, 0.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f, 1.0f
  };


  glGenVertexArrays(1, &vao_id_);
  glBindVertexArray(vao_id_);

  glGenBuffers(1, &vbo_id_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_id_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);

  glGenBuffers(1, &color_buffer_id_);
  glBindBuffer(GL_ARRAY_BUFFER, color_buffer_id_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(1);

  CHECKERROR(createVBO);
}

void GLWidget::destroyVBO() {
  GLenum gl_error = glGetError();

  // FIXME: what does this do ? Do we need this ?
  // Makes linux crash if object does not have a proper OpenGL context (see
  // GLWidget() bug above.
  // glBindBuffer(GL_ARRAY_BUFFER, 0);

  if (color_buffer_id_ > 0) {
    glDisableVertexAttribArray(1);
    glDeleteBuffers(1, &color_buffer_id_);
  }

  if (vbo_id_ > 0) {
    glDisableVertexAttribArray(0);
    glDeleteBuffers(1, &vbo_id_);
  }

  if (vao_id_ > 0) {
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vao_id_);
  }

  CHECKERROR(destroyVBO);
}
