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


/** Cast (class_name)
 * 
 */
static int Application__cast_(lua_State *L) {

  Application *self = *((Application **)dub_checksdata_n(L, 1, "mimas.Application"));
  const char *key = luaL_checkstring(L, 2);
  void **retval__ = (void**)lua_newuserdata(L, sizeof(void*));
  int key_h = dub_hash(key, 2);
  switch(key_h) {
    case 0: {
      if (DUB_ASSERT_KEY(key, "mimas.QApplication")) break;
      *retval__ = static_cast<QApplication *>(self);
      return 1;
    }
    case 1: {
      if (DUB_ASSERT_KEY(key, "mimas.QObject")) break;
      *retval__ = static_cast<QObject *>(self);
      return 1;
    }
  }
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
    lua_pushfstring(L, "new: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "new: Unknown exception");
  }
  return dub_error(L);
}

/** Application::~Application()
 * include/mimas/Application.h:58
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
    lua_pushfstring(L, "__gc: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "__gc: Unknown exception");
  }
  return dub_error(L);
}

/** int Application::exec()
 * include/mimas/Application.h:62
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

/** LuaStackSize Application::screenSize(lua_State *L)
 * include/mimas/Application.h:70
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

/** void Application::click(QWidget *widget, int x=10, int y=10, int type=QEvent::None, int btn=Qt::LeftButton, int mod=Qt::NoModifier)
 * include/mimas/Application.h:80
 */
static int Application_click(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    int top__ = lua_gettop(L);
    if (top__ >= 7) {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      int x = dub_checkint(L, 3);
      int y = dub_checkint(L, 4);
      int type = dub_checkint(L, 5);
      int btn = dub_checkint(L, 6);
      int mod = dub_checkint(L, 7);
      self->click(widget, x, y, type, btn, mod);
      return 0;
    } else if (top__ >= 6) {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      int x = dub_checkint(L, 3);
      int y = dub_checkint(L, 4);
      int type = dub_checkint(L, 5);
      int btn = dub_checkint(L, 6);
      self->click(widget, x, y, type, btn);
      return 0;
    } else if (top__ >= 5) {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      int x = dub_checkint(L, 3);
      int y = dub_checkint(L, 4);
      int type = dub_checkint(L, 5);
      self->click(widget, x, y, type);
      return 0;
    } else if (top__ >= 4) {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      int x = dub_checkint(L, 3);
      int y = dub_checkint(L, 4);
      self->click(widget, x, y);
      return 0;
    } else if (top__ >= 3) {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      int x = dub_checkint(L, 3);
      self->click(widget, x);
      return 0;
    } else {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      self->click(widget);
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "click: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "click: Unknown exception");
  }
  return dub_error(L);
}

/** void Application::mouse(QWidget *widget, int x=10, int y=10)
 * include/mimas/Application.h:91
 */
static int Application_mouse(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    int top__ = lua_gettop(L);
    if (top__ >= 4) {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      int x = dub_checkint(L, 3);
      int y = dub_checkint(L, 4);
      self->mouse(widget, x, y);
      return 0;
    } else if (top__ >= 3) {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      int x = dub_checkint(L, 3);
      self->mouse(widget, x);
      return 0;
    } else {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      self->mouse(widget);
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "mouse: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mouse: Unknown exception");
  }
  return dub_error(L);
}

/** void Application::showToolTip(int gx, int gy, const QString &text, QWidget *w=0)
 * include/mimas/Application.h:109
 */
static int Application_showToolTip(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    int top__ = lua_gettop(L);
    if (top__ >= 5) {
      int gx = dub_checkint(L, 2);
      int gy = dub_checkint(L, 3);
      size_t text_sz_;
      const char *text = dub_checklstring(L, 4, &text_sz_);
      
      QWidget *w = *((QWidget **)dub_checksdata(L, 5, "mimas.QWidget"));
      self->showToolTip(gx, gy, QString::fromUtf8(text, text_sz_), w);
      return 0;
    } else {
      int gx = dub_checkint(L, 2);
      int gy = dub_checkint(L, 3);
      size_t text_sz_;
      const char *text = dub_checklstring(L, 4, &text_sz_);
      
      self->showToolTip(gx, gy, QString::fromUtf8(text, text_sz_));
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "showToolTip: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "showToolTip: Unknown exception");
  }
  return dub_error(L);
}

/** void Application::hideToolTip()
 * include/mimas/Application.h:113
 */
static int Application_hideToolTip(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    self->hideToolTip();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "hideToolTip: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "hideToolTip: Unknown exception");
  }
  return dub_error(L);
}

/** static void Application::setAttribute(int key, bool value)
 * include/mimas/Application.h:95
 */
static int Application_setAttribute(lua_State *L) {
  try {
    int key = dub_checkint(L, 1);
    bool value = dub_checkboolean(L, 2);
    Application::setAttribute(key, value);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setAttribute: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setAttribute: Unknown exception");
  }
  return dub_error(L);
}

/** static void Application::setOverrideCursor(const QCursor &cursor)
 * include/mimas/Application.h:99
 */
static int Application_setOverrideCursor(lua_State *L) {
  try {
    QCursor *cursor = *((QCursor **)dub_checksdata(L, 1, "mimas.QCursor"));
    Application::setOverrideCursor(*cursor);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setOverrideCursor: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setOverrideCursor: Unknown exception");
  }
  return dub_error(L);
}

/** static void Application::restoreOverrideCursor()
 * include/mimas/Application.h:103
 */
static int Application_restoreOverrideCursor(lua_State *L) {
  try {
    Application::restoreOverrideCursor();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "restoreOverrideCursor: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "restoreOverrideCursor: Unknown exception");
  }
  return dub_error(L);
}

/** void QApplication::quit()
 * bind/QApplication.h:11
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

/** void QApplication::setQuitOnLastWindowClosed(bool quit)
 * bind/QApplication.h:15
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

/** void QApplication::setStyleSheet(QString text)
 * bind/QApplication.h:17
 */
static int Application_setStyleSheet(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    size_t text_sz_;
    const char *text = dub_checklstring(L, 2, &text_sz_);
    
    self->setStyleSheet(QString::fromUtf8(text, text_sz_));
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setStyleSheet: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setStyleSheet: Unknown exception");
  }
  return dub_error(L);
}

/** QString QApplication::styleSheet()
 * bind/QApplication.h:19
 */
static int Application_styleSheet(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    QByteArray str_(self->styleSheet().toUtf8());
    lua_pushlstring(L, str_.constData(), str_.size());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "styleSheet: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "styleSheet: Unknown exception");
  }
  return dub_error(L);
}

/** QString QObject::objectName() const
 * bind/QObject.h:7
 */
static int Application_objectName(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    QByteArray str_(self->objectName().toUtf8());
    lua_pushlstring(L, str_.constData(), str_.size());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "objectName: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "objectName: Unknown exception");
  }
  return dub_error(L);
}

/** void QObject::setObjectName(const QString &name)
 * bind/QObject.h:8
 */
static int Application_setObjectName(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    size_t name_sz_;
    const char *name = dub_checklstring(L, 2, &name_sz_);
    
    self->setObjectName(QString::fromUtf8(name, name_sz_));
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setObjectName: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setObjectName: Unknown exception");
  }
  return dub_error(L);
}

/** QVariant QObject::property(const char *name)
 * bind/QObject.h:9
 */
static int Application_property(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    const char *name = dub_checkstring(L, 2);
    return pushVariantInLua(L, self->property(name));
  } catch (std::exception &e) {
    lua_pushfstring(L, "property: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "property: Unknown exception");
  }
  return dub_error(L);
}

/** bool QObject::setProperty(const char *name, const QVariant &value)
 * bind/QObject.h:10
 */
static int Application_setProperty(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    const char *name = dub_checkstring(L, 2);
    QVariant value(variantFromLua(L, 3));
    lua_pushboolean(L, self->setProperty(name, value));
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setProperty: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setProperty: Unknown exception");
  }
  return dub_error(L);
}

/** void QObject::setParent(QObject *parent)
 * bind/QObject.h:11
 */
static int Application_setParent(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    QObject *parent = *((QObject **)dub_checksdata(L, 2, "mimas.QObject"));
    self->setParent(parent);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setParent: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setParent: Unknown exception");
  }
  return dub_error(L);
}

/** QObject* QObject::parent()
 * bind/QObject.h:12
 */
static int Application_parent(lua_State *L) {
  try {
    Application *self = *((Application **)dub_checksdata(L, 1, "mimas.Application"));
    QObject *retval__ = self->parent();
    if (!retval__) return 0;
    dub_pushudata(L, retval__, "mimas.QObject", false);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "parent: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "parent: Unknown exception");
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
  { "_cast_"       , Application__cast_   },
  { "new"          , Application_Application },
  { "__gc"         , Application__Application },
  { "exec"         , Application_exec     },
  { "screenSize"   , Application_screenSize },
  { "click"        , Application_click    },
  { "mouse"        , Application_mouse    },
  { "showToolTip"  , Application_showToolTip },
  { "hideToolTip"  , Application_hideToolTip },
  { "setAttribute" , Application_setAttribute },
  { "setOverrideCursor", Application_setOverrideCursor },
  { "restoreOverrideCursor", Application_restoreOverrideCursor },
  { "quit"         , Application_quit     },
  { "setQuitOnLastWindowClosed", Application_setQuitOnLastWindowClosed },
  { "setStyleSheet", Application_setStyleSheet },
  { "styleSheet"   , Application_styleSheet },
  { "objectName"   , Application_objectName },
  { "setObjectName", Application_setObjectName },
  { "property"     , Application_property },
  { "setProperty"  , Application_setProperty },
  { "setParent"    , Application_setParent },
  { "parent"       , Application_parent   },
  { "__tostring"   , Application___tostring },
  { "deleted"      , dub_isDeleted        },
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
  dub_register(L, "mimas", "Application_core", "Application");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
