/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class Application
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/Application.h"


/** Set attributes (key, value)
 * 
 */
static int Application__set_(lua_State *L) {

  Application *self = *((Application **)dub_checksdata_n(L, 1, "mimas.Application"));
  const char *key = luaL_checkstring(L, 2);
  int key_h = dub_hash(key, 2);
  switch(key_h) {
    case 1: {
      if (DUB_ASSERT_KEY(key, "sAppKey")) break;
      Application::sAppKey = **((pthread_key_t *)dub_checksdata_n(L, 3, "pthread_key_t"));
      return 0;
    }
  }
  if (lua_istable(L, 1)) {
    lua_rawset(L, 1);
  } else {
    luaL_error(L, KEY_EXCEPTION_MSG, key);
  }
  return 0;
}

/** Get attributes (key)
 * 
 */
static int Application__get_(lua_State *L) {

  Application *self = *((Application **)dub_checksdata_n(L, 1, "mimas.Application", true));
  const char *key = luaL_checkstring(L, 2);
  // <self> "key" <mt>
  // rawget(mt, key)
  lua_pushvalue(L, 2);
  // <self> "key" <mt> "key"
  lua_rawget(L, -2);
  if (!lua_isnil(L, -1)) {
    // Found method.
    return 1;
  } else {
    // Not in mt = attribute access.
    lua_pop(L, 2);
  }
  int key_h = dub_hash(key, 2);
  switch(key_h) {
    case 1: {
      if (DUB_ASSERT_KEY(key, "sAppKey")) break;
      dub_pushudata(L, &Application::sAppKey, "pthread_key_t", false);
      return 1;
    }
  }
  return 0;
}

/** Cast (class_name)
 * 
 */
static int Application__cast_(lua_State *L) {

  Application *self = *((Application **)dub_checksdata_n(L, 1, "mimas.Application"));
  const char *key = luaL_checkstring(L, 2);
  void **retval__ = (void**)lua_newuserdata(L, sizeof(void*));
  return 0;
}

/** Application::Application()
 * include/mimas/Application.h:56
 */
static int Application_Application(lua_State *L) {
  try {
    Application *retval__ = new Application();
    retval__->pushobject(L, retval__, "mimas.Application", true);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "Application: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "Application: Unknown exception");
  }
  return dub_error(L);
}

/** Application::~Application()
 * include/mimas/Application.h:87
 */
static int Application__Application(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "mimas.Application"));
    if (userdata->gc) {
      Application *self = (Application *)userdata->ptr;
      delete self;
    }
    userdata->gc = false;
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "~Application: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "~Application: Unknown exception");
  }
  return dub_error(L);
}

/** void Application::setQuitOnLastWindowClosed(bool quit)
 * include/mimas/Application.h:92
 */
static int Application_setQuitOnLastWindowClosed(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    bool quit = dub_checkboolean(L, 2);
    self->setQuitOnLastWindowClosed(quit);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setQuitOnLastWindowClosed: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setQuitOnLastWindowClosed: Unknown exception");
  }
  return dub_error(L);
}

/** virtual void Application::luaDestroy()
 * include/mimas/Application.h:97
 */
static int Application_luaDestroy(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    self->luaDestroy();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "luaDestroy: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "luaDestroy: Unknown exception");
  }
  return dub_error(L);
}

/** int Application::exec()
 * include/mimas/Application.h:103
 */
static int Application_exec(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    lua_pushnumber(L, self->exec());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "exec: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "exec: Unknown exception");
  }
  return dub_error(L);
}

/** void Application::processEvents(int maxtime)
 * include/mimas/Application.h:109
 */
static int Application_processEvents(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    int maxtime = dub_checkint(L, 2);
    self->processEvents(maxtime);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "processEvents: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "processEvents: Unknown exception");
  }
  return dub_error(L);
}

/** void Application::quit()
 * include/mimas/Application.h:124
 */
static int Application_quit(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    self->quit();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "quit: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "quit: Unknown exception");
  }
  return dub_error(L);
}

/** void Application::setStyleSheet(const char *text)
 * include/mimas/Application.h:128
 */
static int Application_setStyleSheet(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    const char *text = dub_checkstring(L, 2);
    self->setStyleSheet(text);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setStyleSheet: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setStyleSheet: Unknown exception");
  }
  return dub_error(L);
}

/** LuaStackSize Application::styleSheet(lua_State *L)
 * include/mimas/Application.h:132
 */
static int Application_styleSheet(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    return self->styleSheet(L);
  } catch (std::exception &e) {
    lua_pushfstring(L, "styleSheet: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "styleSheet: Unknown exception");
  }
  return dub_error(L);
}

/** LuaStackSize Application::screenSize(lua_State *L)
 * include/mimas/Application.h:140
 */
static int Application_screenSize(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    return self->screenSize(L);
  } catch (std::exception &e) {
    lua_pushfstring(L, "screenSize: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "screenSize: Unknown exception");
  }
  return dub_error(L);
}

/** void Application::singleShot(int msec, QObject *receiver, const char *member)
 * include/mimas/Application.h:151
 */
static int Application_singleShot(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    int msec = dub_checkint(L, 2);
    QObject *receiver = *((QObject **)dub_checksdata(L, 3, "mimas.QObject"));
    const char *member = dub_checkstring(L, 4);
    self->singleShot(msec, receiver, member);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "singleShot: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "singleShot: Unknown exception");
  }
  return dub_error(L);
}

/** static LuaStackSize Application::MakeApplication(lua_State *L)
 * include/mimas/Application.h:66
 */
static int Application_MakeApplication(lua_State *L) {
  try {
    return Application::MakeApplication(L);
  } catch (std::exception &e) {
    lua_pushfstring(L, "MakeApplication: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "MakeApplication: Unknown exception");
  }
  return dub_error(L);
}

/** static void Application::terminate(int sig)
 * include/mimas/Application.h:122
 */
static int Application_terminate(lua_State *L) {
  try {
    int sig = dub_checkint(L, 1);
    Application::terminate(sig);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "terminate: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "terminate: Unknown exception");
  }
  return dub_error(L);
}



// --=============================================== __tostring
static int Application___tostring(lua_State *L) {
  Application *self = *((Application **)dub_checksdata_n(L, 1, "mimas.Application"));
  lua_pushfstring(L, "mimas.Application: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg Application_member_methods[] = {
  { "__newindex"   , Application__set_    },
  { "__index"      , Application__get_    },
  { "_cast_"       , Application__cast_   },
  { "new"          , Application_Application },
  { "__gc"         , Application__Application },
  { "setQuitOnLastWindowClosed", Application_setQuitOnLastWindowClosed },
  { "luaDestroy"   , Application_luaDestroy },
  { "exec"         , Application_exec     },
  { "processEvents", Application_processEvents },
  { "quit"         , Application_quit     },
  { "setStyleSheet", Application_setStyleSheet },
  { "styleSheet"   , Application_styleSheet },
  { "screenSize"   , Application_screenSize },
  { "singleShot"   , Application_singleShot },
  { "MakeApplication", Application_MakeApplication },
  { "terminate"    , Application_terminate },
  { "__tostring"   , Application___tostring },
  { NULL, NULL},
};

// --=============================================== CONSTANTS
static const struct dub_const_Reg Application_const[] = {
  { "Desktop"      , Application::Desktop },
  { "Plugin"       , Application::Plugin  },
  { NULL, 0},
};

extern "C" int luaopen_mimas_Application(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.Application");
  // <mt>
  // register class constants
  dub_register_const(L, Application_const);

  // register member methods
  luaL_register(L, NULL, Application_member_methods);
  // save meta-table in mimas
  dub_register(L, "mimas", "Application_core");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
