/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class Button
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/Button.h"


/** Cast (class_name)
 * 
 */
static int Button__cast_(lua_State *L) {

  Button *self = *((Button **)dub_checksdata_n(L, 1, "mimas.Button"));
  const char *key = luaL_checkstring(L, 2);
  void **retval__ = (void**)lua_newuserdata(L, sizeof(void*));
  int key_h = dub_hash(key, 10);
  switch(key_h) {
    case 3: {
      if (DUB_ASSERT_KEY(key, "mimas.QObject")) break;
      *retval__ = static_cast<QObject *>(self);
      return 1;
    }
    case 6: {
      if (DUB_ASSERT_KEY(key, "mimas.QWidget")) break;
      *retval__ = static_cast<QWidget *>(self);
      return 1;
    }
    case 8: {
      if (DUB_ASSERT_KEY(key, "mimas.QPushButton")) break;
      *retval__ = static_cast<QPushButton *>(self);
      return 1;
    }
  }
  return 0;
}

/** Button::Button(const char *title=NULL, QWidget *parent=NULL)
 * include/mimas/Button.h:51
 */
static int Button_Button(lua_State *L) {
  try {
    int top__ = lua_gettop(L);
    if (top__ >= 2) {
      const char *title = dub_checkstring(L, 1);
      QWidget *parent = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      Button *retval__ = new Button(title, parent);
      retval__->pushobject(L, retval__, "mimas.Button", true);
      return 1;
    } else if (top__ >= 1) {
      const char *title = dub_checkstring(L, 1);
      Button *retval__ = new Button(title);
      retval__->pushobject(L, retval__, "mimas.Button", true);
      return 1;
    } else {
      Button *retval__ = new Button();
      retval__->pushobject(L, retval__, "mimas.Button", true);
      return 1;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "Button: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "Button: Unknown exception");
  }
  return dub_error(L);
}

/** Button::~Button()
 * include/mimas/Button.h:56
 */
static int Button__Button(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "mimas.Button"));
    if (userdata->gc) {
      Button *self = (Button *)userdata->ptr;
      delete self;
    }
    userdata->gc = false;
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "~Button: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "~Button: Unknown exception");
  }
  return dub_error(L);
}

/** QString QObject::objectName() const
 * bind/QObject.h:7
 */
static int Button_objectName(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setObjectName(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_property(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setProperty(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_move(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_resize(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_x(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_y(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_width(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_height(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setParent(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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

/** void QWidget::update()
 * bind/QWidget.h:17
 */
static int Button_update(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
    self->update();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "update: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "update: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::adjustSize()
 * bind/QWidget.h:18
 */
static int Button_adjustSize(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setFocus(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setFocusPolicy(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setAttribute(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setMinimumSize(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setMouseTracking(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_close(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_isVisible(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_show(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_hide(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_lower(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_raise(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_activateWindow(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_isFullScreen(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_addAction(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setWindowTitle(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_windowTitle(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_addWidget(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_size(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setStyle(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setStyleSheet(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_textSize(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setCssClass(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setSizeHit(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_setSizePolicy(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_showFullScreen(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_swapFullScreen(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_globalPosition(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_position(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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
static int Button_globalMove(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
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

/** void QPushButton::setText(const QString &text)
 * bind/QPushButton.h:10
 */
static int Button_setText(lua_State *L) {
  try {
    Button *self = *((Button **)dub_checksdata(L, 1, "mimas.Button"));
    size_t text_sz_;
    const char *text = dub_checklstring(L, 2, &text_sz_);
    
    self->setText(QString::fromUtf8(text, text_sz_));
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setText: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setText: Unknown exception");
  }
  return dub_error(L);
}



// --=============================================== __tostring
static int Button___tostring(lua_State *L) {
  Button *self = *((Button **)dub_checksdata_n(L, 1, "mimas.Button"));
  lua_pushfstring(L, "mimas.Button: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg Button_member_methods[] = {
  { "_cast_"       , Button__cast_        },
  { "new"          , Button_Button        },
  { "__gc"         , Button__Button       },
  { "objectName"   , Button_objectName    },
  { "setObjectName", Button_setObjectName },
  { "property"     , Button_property      },
  { "setProperty"  , Button_setProperty   },
  { "move"         , Button_move          },
  { "resize"       , Button_resize        },
  { "x"            , Button_x             },
  { "y"            , Button_y             },
  { "width"        , Button_width         },
  { "height"       , Button_height        },
  { "setParent"    , Button_setParent     },
  { "update"       , Button_update        },
  { "adjustSize"   , Button_adjustSize    },
  { "setFocus"     , Button_setFocus      },
  { "setFocusPolicy", Button_setFocusPolicy },
  { "setAttribute" , Button_setAttribute  },
  { "setMinimumSize", Button_setMinimumSize },
  { "setMouseTracking", Button_setMouseTracking },
  { "close"        , Button_close         },
  { "isVisible"    , Button_isVisible     },
  { "show"         , Button_show          },
  { "hide"         , Button_hide          },
  { "lower"        , Button_lower         },
  { "raise"        , Button_raise         },
  { "activateWindow", Button_activateWindow },
  { "isFullScreen" , Button_isFullScreen  },
  { "addAction"    , Button_addAction     },
  { "setWindowTitle", Button_setWindowTitle },
  { "windowTitle"  , Button_windowTitle   },
  { "addWidget"    , Button_addWidget     },
  { "size"         , Button_size          },
  { "setStyle"     , Button_setStyle      },
  { "setStyleSheet", Button_setStyleSheet },
  { "textSize"     , Button_textSize      },
  { "setCssClass"  , Button_setCssClass   },
  { "setSizeHit"   , Button_setSizeHit    },
  { "setSizePolicy", Button_setSizePolicy },
  { "showFullScreen", Button_showFullScreen },
  { "swapFullScreen", Button_swapFullScreen },
  { "globalPosition", Button_globalPosition },
  { "position"     , Button_position      },
  { "globalMove"   , Button_globalMove    },
  { "setText"      , Button_setText       },
  { "__tostring"   , Button___tostring    },
  { NULL, NULL},
};


extern "C" int luaopen_mimas_Button(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.Button");
  // <mt>

  // register member methods
  luaL_register(L, NULL, Button_member_methods);
  // save meta-table in mimas
  dub_register(L, "mimas", "Button");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
