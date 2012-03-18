/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class LegacyGLWidget
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/LegacyGLWidget.h"


/** Cast (class_name)
 * 
 */
static int LegacyGLWidget__cast_(lua_State *L) {

  LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata_n(L, 1, "mimas.LegacyGLWidget"));
  const char *key = luaL_checkstring(L, 2);
  void **retval__ = (void**)lua_newuserdata(L, sizeof(void*));
  int key_h = dub_hash(key, 2);
  switch(key_h) {
    case 1: {
      if (DUB_ASSERT_KEY(key, "mimas.QObject")) break;
      *retval__ = static_cast<QObject *>(self);
      return 1;
    }
    case 0: {
      if (DUB_ASSERT_KEY(key, "mimas.QWidget")) break;
      *retval__ = static_cast<QWidget *>(self);
      return 1;
    }
  }
  return 0;
}

/** LegacyGLWidget::LegacyGLWidget()
 * include/mimas/LegacyGLWidget.h:75
 */
static int LegacyGLWidget_LegacyGLWidget(lua_State *L) {
  try {
    LegacyGLWidget *retval__ = new LegacyGLWidget();
    retval__->pushobject(L, retval__, "mimas.LegacyGLWidget", true);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "LegacyGLWidget: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "LegacyGLWidget: Unknown exception");
  }
  return dub_error(L);
}

/** LegacyGLWidget::~LegacyGLWidget()
 * include/mimas/LegacyGLWidget.h:88
 */
static int LegacyGLWidget__LegacyGLWidget(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "mimas.LegacyGLWidget"));
    if (userdata->gc) {
      LegacyGLWidget *self = (LegacyGLWidget *)userdata->ptr;
      delete self;
    }
    userdata->gc = false;
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "~LegacyGLWidget: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "~LegacyGLWidget: Unknown exception");
  }
  return dub_error(L);
}

/** void LegacyGLWidget::addWidgetToScene(QWidget *widget, float x=0, float y=0)
 * include/mimas/LegacyGLWidget.h:91
 */
static int LegacyGLWidget_addWidgetToScene(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    int top__ = lua_gettop(L);
    if (top__ >= 4) {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      float x = dub_checknumber(L, 3);
      float y = dub_checknumber(L, 4);
      self->addWidgetToScene(widget, x, y);
      return 0;
    } else if (top__ >= 3) {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      float x = dub_checknumber(L, 3);
      self->addWidgetToScene(widget, x);
      return 0;
    } else {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      self->addWidgetToScene(widget);
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "addWidgetToScene: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "addWidgetToScene: Unknown exception");
  }
  return dub_error(L);
}

/** void LegacyGLWidget::update()
 * include/mimas/LegacyGLWidget.h:99
 */
static int LegacyGLWidget_update(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    self->update();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "update: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "update: Unknown exception");
  }
  return dub_error(L);
}

/** QString QObject::objectName() const
 * bind/QObject.h:7
 */
static int LegacyGLWidget_objectName(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    QByteArray s_self->objectName()_(self->objectName().toUtf8());
    lua_pushlstring(L, s_self->objectName()_.constData(), s_self->objectName()_.size());
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
static int LegacyGLWidget_setObjectName(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
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
static int LegacyGLWidget_property(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    const char *name = dub_checkstring(L, 2);
    pushVariantInLua(L, self->property(name))
    return 1;
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
static int LegacyGLWidget_setProperty(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
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

/** void QWidget::move(int x, int y)
 * bind/QWidget.h:10
 */
static int LegacyGLWidget_move(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    int x = dub_checkint(L, 2);
    int y = dub_checkint(L, 3);
    self->move(x, y);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "move: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "move: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::resize(int w, int h)
 * bind/QWidget.h:11
 */
static int LegacyGLWidget_resize(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    int w = dub_checkint(L, 2);
    int h = dub_checkint(L, 3);
    self->resize(w, h);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "resize: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "resize: Unknown exception");
  }
  return dub_error(L);
}

/** int QWidget::x()
 * bind/QWidget.h:12
 */
static int LegacyGLWidget_x(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    lua_pushnumber(L, self->x());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "x: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "x: Unknown exception");
  }
  return dub_error(L);
}

/** int QWidget::y()
 * bind/QWidget.h:13
 */
static int LegacyGLWidget_y(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    lua_pushnumber(L, self->y());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "y: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "y: Unknown exception");
  }
  return dub_error(L);
}

/** int QWidget::width()
 * bind/QWidget.h:14
 */
static int LegacyGLWidget_width(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    lua_pushnumber(L, self->width());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "width: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "width: Unknown exception");
  }
  return dub_error(L);
}

/** int QWidget::height()
 * bind/QWidget.h:15
 */
static int LegacyGLWidget_height(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    lua_pushnumber(L, self->height());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "height: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "height: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::setParent(QWidget *parent)
 * bind/QWidget.h:16
 */
static int LegacyGLWidget_setParent(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    QWidget *parent = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
    self->setParent(parent);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setParent: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setParent: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::adjustSize()
 * bind/QWidget.h:18
 */
static int LegacyGLWidget_adjustSize(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    self->adjustSize();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "adjustSize: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "adjustSize: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::setFocus()
 * bind/QWidget.h:19
 */
static int LegacyGLWidget_setFocus(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    self->setFocus();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setFocus: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setFocus: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::setFocusPolicy(int policy)
 * bind/QWidget.h:20
 */
static int LegacyGLWidget_setFocusPolicy(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    int policy = dub_checkint(L, 2);
    self->setFocusPolicy(policy);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setFocusPolicy: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setFocusPolicy: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::setAttribute(int attr, bool enabled)
 * bind/QWidget.h:21
 */
static int LegacyGLWidget_setAttribute(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    int attr = dub_checkint(L, 2);
    bool enabled = dub_checkboolean(L, 3);
    self->setAttribute(attr, enabled);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setAttribute: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setAttribute: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::setMinimumSize(float w, float h)
 * bind/QWidget.h:24
 */
static int LegacyGLWidget_setMinimumSize(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    float w = dub_checknumber(L, 2);
    float h = dub_checknumber(L, 3);
    self->setMinimumSize(w, h);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setMinimumSize: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setMinimumSize: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::setMouseTracking(bool enable)
 * bind/QWidget.h:27
 */
static int LegacyGLWidget_setMouseTracking(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    bool enable = dub_checkboolean(L, 2);
    self->setMouseTracking(enable);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setMouseTracking: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setMouseTracking: Unknown exception");
  }
  return dub_error(L);
}

/** bool QWidget::close()
 * bind/QWidget.h:28
 */
static int LegacyGLWidget_close(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    lua_pushboolean(L, self->close());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "close: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "close: Unknown exception");
  }
  return dub_error(L);
}

/** bool QWidget::isVisible()
 * bind/QWidget.h:29
 */
static int LegacyGLWidget_isVisible(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    lua_pushboolean(L, self->isVisible());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "isVisible: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "isVisible: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::show()
 * bind/QWidget.h:30
 */
static int LegacyGLWidget_show(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    self->show();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "show: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "show: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::hide()
 * bind/QWidget.h:31
 */
static int LegacyGLWidget_hide(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    self->hide();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "hide: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "hide: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::lower()
 * bind/QWidget.h:32
 */
static int LegacyGLWidget_lower(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    self->lower();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "lower: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "lower: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::raise()
 * bind/QWidget.h:33
 */
static int LegacyGLWidget_raise(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    self->raise();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "raise: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "raise: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::activateWindow()
 * bind/QWidget.h:34
 */
static int LegacyGLWidget_activateWindow(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    self->activateWindow();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "activateWindow: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "activateWindow: Unknown exception");
  }
  return dub_error(L);
}

/** bool QWidget::isFullScreen()
 * bind/QWidget.h:35
 */
static int LegacyGLWidget_isFullScreen(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    lua_pushboolean(L, self->isFullScreen());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "isFullScreen: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "isFullScreen: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::addAction(Action *action)
 * bind/QWidget.h:36
 */
static int LegacyGLWidget_addAction(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    Action *action = *((Action **)dub_checksdata(L, 2, "mimas.Action"));
    self->addAction(action);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "addAction: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "addAction: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::setWindowTitle(const QString &text)
 * bind/QWidget.h:37
 */
static int LegacyGLWidget_setWindowTitle(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    size_t text_sz_;
    const char *text = dub_checklstring(L, 2, &text_sz_);
    
    self->setWindowTitle(QString::fromUtf8(text, text_sz_));
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setWindowTitle: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setWindowTitle: Unknown exception");
  }
  return dub_error(L);
}

/** QString QWidget::windowTitle()
 * bind/QWidget.h:38
 */
static int LegacyGLWidget_windowTitle(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    QByteArray s_self->windowTitle()_(self->windowTitle().toUtf8());
    lua_pushlstring(L, s_self->windowTitle()_.constData(), s_self->windowTitle()_.size());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "windowTitle: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "windowTitle: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::addWidget(QWidget *widget)
 * bind/QWidget.h:44
 */
static int LegacyGLWidget_addWidget(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
    self->addWidget(widget);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "addWidget: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "addWidget: Unknown exception");
  }
  return dub_error(L);
}

/** LuaStackSize QWidget::size()
 * bind/QWidget.h:48
 */
static int LegacyGLWidget_size(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    return self->size();
  } catch (std::exception &e) {
    lua_pushfstring(L, "size: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "size: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::setStyle(const char *text)
 * bind/QWidget.h:49
 */
static int LegacyGLWidget_setStyle(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    const char *text = dub_checkstring(L, 2);
    self->setStyle(text);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setStyle: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setStyle: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::setStyleSheet(const char *text)
 * bind/QWidget.h:50
 */
static int LegacyGLWidget_setStyleSheet(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
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

/** void QWidget::textSize(const char *text)
 * bind/QWidget.h:53
 */
static int LegacyGLWidget_textSize(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    const char *text = dub_checkstring(L, 2);
    self->textSize(text);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "textSize: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "textSize: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::setCssClass(const char *css_class)
 * bind/QWidget.h:55
 */
static int LegacyGLWidget_setCssClass(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    const char *css_class = dub_checkstring(L, 2);
    self->setCssClass(css_class);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setCssClass: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setCssClass: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::setSizeHit(int w, int h)
 * bind/QWidget.h:56
 */
static int LegacyGLWidget_setSizeHit(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    int w = dub_checkint(L, 2);
    int h = dub_checkint(L, 3);
    self->setSizeHit(w, h);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setSizeHit: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setSizeHit: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::setSizePolicy(int horizontal, int vertical)
 * bind/QWidget.h:60
 */
static int LegacyGLWidget_setSizePolicy(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    int horizontal = dub_checkint(L, 2);
    int vertical = dub_checkint(L, 3);
    self->setSizePolicy(horizontal, vertical);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setSizePolicy: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setSizePolicy: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::showFullScreen(bool enable=true)
 * bind/QWidget.h:62
 */
static int LegacyGLWidget_showFullScreen(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    int top__ = lua_gettop(L);
    if (top__ >= 2) {
      bool enable = dub_checkboolean(L, 2);
      self->showFullScreen(enable);
      return 0;
    } else {
      self->showFullScreen();
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "showFullScreen: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "showFullScreen: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::swapFullScreen()
 * bind/QWidget.h:66
 */
static int LegacyGLWidget_swapFullScreen(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    self->swapFullScreen();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "swapFullScreen: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "swapFullScreen: Unknown exception");
  }
  return dub_error(L);
}

/** LuaStackSize QWidget::globalPosition()
 * bind/QWidget.h:70
 */
static int LegacyGLWidget_globalPosition(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    return self->globalPosition();
  } catch (std::exception &e) {
    lua_pushfstring(L, "globalPosition: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "globalPosition: Unknown exception");
  }
  return dub_error(L);
}

/** LuaStackSize QWidget::position()
 * bind/QWidget.h:75
 */
static int LegacyGLWidget_position(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    return self->position();
  } catch (std::exception &e) {
    lua_pushfstring(L, "position: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "position: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::globalMove(float x, float y)
 * bind/QWidget.h:79
 */
static int LegacyGLWidget_globalMove(lua_State *L) {
  try {
    LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata(L, 1, "mimas.LegacyGLWidget"));
    float x = dub_checknumber(L, 2);
    float y = dub_checknumber(L, 3);
    self->globalMove(x, y);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "globalMove: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "globalMove: Unknown exception");
  }
  return dub_error(L);
}



// --=============================================== __tostring
static int LegacyGLWidget___tostring(lua_State *L) {
  LegacyGLWidget *self = *((LegacyGLWidget **)dub_checksdata_n(L, 1, "mimas.LegacyGLWidget"));
  lua_pushfstring(L, "mimas.LegacyGLWidget: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg LegacyGLWidget_member_methods[] = {
  { "_cast_"       , LegacyGLWidget__cast_ },
  { "new"          , LegacyGLWidget_LegacyGLWidget },
  { "__gc"         , LegacyGLWidget__LegacyGLWidget },
  { "addWidgetToScene", LegacyGLWidget_addWidgetToScene },
  { "update"       , LegacyGLWidget_update },
  { "objectName"   , LegacyGLWidget_objectName },
  { "setObjectName", LegacyGLWidget_setObjectName },
  { "property"     , LegacyGLWidget_property },
  { "setProperty"  , LegacyGLWidget_setProperty },
  { "move"         , LegacyGLWidget_move  },
  { "resize"       , LegacyGLWidget_resize },
  { "x"            , LegacyGLWidget_x     },
  { "y"            , LegacyGLWidget_y     },
  { "width"        , LegacyGLWidget_width },
  { "height"       , LegacyGLWidget_height },
  { "setParent"    , LegacyGLWidget_setParent },
  { "adjustSize"   , LegacyGLWidget_adjustSize },
  { "setFocus"     , LegacyGLWidget_setFocus },
  { "setFocusPolicy", LegacyGLWidget_setFocusPolicy },
  { "setAttribute" , LegacyGLWidget_setAttribute },
  { "setMinimumSize", LegacyGLWidget_setMinimumSize },
  { "setMouseTracking", LegacyGLWidget_setMouseTracking },
  { "close"        , LegacyGLWidget_close },
  { "isVisible"    , LegacyGLWidget_isVisible },
  { "show"         , LegacyGLWidget_show  },
  { "hide"         , LegacyGLWidget_hide  },
  { "lower"        , LegacyGLWidget_lower },
  { "raise"        , LegacyGLWidget_raise },
  { "activateWindow", LegacyGLWidget_activateWindow },
  { "isFullScreen" , LegacyGLWidget_isFullScreen },
  { "addAction"    , LegacyGLWidget_addAction },
  { "setWindowTitle", LegacyGLWidget_setWindowTitle },
  { "windowTitle"  , LegacyGLWidget_windowTitle },
  { "addWidget"    , LegacyGLWidget_addWidget },
  { "size"         , LegacyGLWidget_size  },
  { "setStyle"     , LegacyGLWidget_setStyle },
  { "setStyleSheet", LegacyGLWidget_setStyleSheet },
  { "textSize"     , LegacyGLWidget_textSize },
  { "setCssClass"  , LegacyGLWidget_setCssClass },
  { "setSizeHit"   , LegacyGLWidget_setSizeHit },
  { "setSizePolicy", LegacyGLWidget_setSizePolicy },
  { "showFullScreen", LegacyGLWidget_showFullScreen },
  { "swapFullScreen", LegacyGLWidget_swapFullScreen },
  { "globalPosition", LegacyGLWidget_globalPosition },
  { "position"     , LegacyGLWidget_position },
  { "globalMove"   , LegacyGLWidget_globalMove },
  { "__tostring"   , LegacyGLWidget___tostring },
  { NULL, NULL},
};


extern "C" int luaopen_mimas_LegacyGLWidget(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.LegacyGLWidget");
  // <mt>

  // register member methods
  luaL_register(L, NULL, LegacyGLWidget_member_methods);
  // save meta-table in mimas
  dub_register(L, "mimas", "LegacyGLWidget");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
