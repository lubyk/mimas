#include "mimas/Application.h"

#include <QtCore/QRect>
#include <QtCore/QTextCodec>
#include <QtCore/QLocale>
#include <QtGui/QDesktopWidget>

#include <signal.h>

static char arg0[] = "Lubyk";
static char arg1[] = "-style";
static char arg2[] = "Plastique";
static char *app_argv[] = {&arg0[0], &arg1[0], &arg2[0], NULL};
static int   app_argc   = (int)(sizeof(app_argv) / sizeof(app_argv[0])) - 1;
                    
pthread_key_t Application::sAppKey = 0;

Application::Application()
   : QApplication(app_argc, app_argv) {
  // create a key to find 'app' object in current thread
  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
  if (!sAppKey) pthread_key_create(&sAppKey, NULL);
  // Avoid nasty number parsing bugs (0.5 not parsed)
  QLocale::setDefault(QLocale::c());
  setlocale(LC_NUMERIC, "C");
}

Application::~Application() {
}

int Application::exec() {
  // register interrupt signal
  pthread_setspecific(sAppKey, (void*)this);
  signal(SIGINT, terminate);
  return QApplication::exec();
}

void Application::terminate(int sig) {
  Application *app = (Application*)pthread_getspecific(sAppKey);
  app->quit();
}

LuaStackSize Application::screenSize(lua_State *L) {
  QRect rect = desktop()->geometry();
  lua_pushnumber(L, rect.width());
  lua_pushnumber(L, rect.height());
  return 2;
}

bool Application::event(QEvent *event) {
#ifdef __MACOSX_CORE__
  if (event->type() == QEvent::FileOpen) {
    // macosx file open event
    QFileOpenEvent *fop = static_cast<QFileOpenEvent*>(event);
    QString file = fop->file();
    lua_State *L = dub_L;

    if (!dub_pushcallback("openFile")) {
      // printf("Called 'openFile' for '%s' but Lua method is not defined for 'app'.\n
      return false;
    }

    lua_pushstring(L, file.toUtf8().data());
    // <func> <self> <'file'>
    dub_call(2, 0);
    return true;
  }
#endif
  return QApplication::event(event);
}

