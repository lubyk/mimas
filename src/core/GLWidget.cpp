#include "mimas/GLWidget.h"

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
  printf("Compile ==============\n%s\n===============\n", source);
  GLenum ErrorCheckValue = glGetError();
  //glShaderSource(VertexShaderId, 1, &source, NULL);
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
    printf("Compilation error: %s\n", buf);
    return false;
  }
  return true;
}

void GLWidget::createShaders(const char *vertex_shader, const char *fragment_shader) {
  GLenum ErrorCheckValue = glGetError();

  VertexShaderId = glCreateShader(GL_VERTEX_SHADER);
  CHECKERROR(glCreateShader);
  if (!compileShader(VertexShaderId, vertex_shader)) return;


  FragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
  CHECKERROR(glCreateShader);
  if (!compileShader(FragmentShaderId, fragment_shader)) return;

  ProgramId = glCreateProgram();
  CHECKERROR(glCreateProgram);
  glAttachShader(ProgramId, VertexShaderId);
  CHECKERROR(glAttachShader);
  glAttachShader(ProgramId, FragmentShaderId);
  CHECKERROR(glAttachShader2);
  glLinkProgram(ProgramId);
  CHECKERROR(glLinkProgram);
  glUseProgram(ProgramId);
  CHECKERROR(glUseProgram);
}

void GLWidget::destroyShaders() {
  GLenum ErrorCheckValue = glGetError();

  glUseProgram(0);

  glDetachShader(ProgramId, VertexShaderId);
  glDetachShader(ProgramId, FragmentShaderId);

  glDeleteShader(FragmentShaderId);
  glDeleteShader(VertexShaderId);

  glDeleteProgram(ProgramId);

  ErrorCheckValue = glGetError();
  if (ErrorCheckValue != GL_NO_ERROR) {
    fprintf(stderr, "ERROR: Could not destroy the shaders: %s \n",
        gluErrorString(ErrorCheckValue)
    );
  }
}

void GLWidget::createVBO() {
  GLenum ErrorCheckValue;

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

  CHECKERROR(createVBO);

  glGenVertexArrays(1, &VaoId);
  glBindVertexArray(VaoId);

  glGenBuffers(1, &VboId);
  glBindBuffer(GL_ARRAY_BUFFER, VboId);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);

  glGenBuffers(1, &ColorBufferId);
  glBindBuffer(GL_ARRAY_BUFFER, ColorBufferId);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(1);

  ErrorCheckValue = glGetError();
  if (ErrorCheckValue != GL_NO_ERROR)
  {
    fprintf(
        stderr,
        "ERROR: Could not create a VBO: %s \n",
        gluErrorString(ErrorCheckValue)
        );

    exit(-1);
  }
}

void GLWidget::destroyVBO() {

  GLenum ErrorCheckValue = glGetError();

  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glDeleteBuffers(1, &ColorBufferId);
  glDeleteBuffers(1, &VboId);

  glBindVertexArray(0);
  glDeleteVertexArrays(1, &VaoId);

  ErrorCheckValue = glGetError();
  if (ErrorCheckValue != GL_NO_ERROR) {
    fprintf(stderr, "ERROR: Could not destroy the VBO: %s \n",
      gluErrorString(ErrorCheckValue)
    );
  }
}
