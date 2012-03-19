/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class CheckBox
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/CheckBox.h"


/** Cast (class_name)
 * 
 */
static int CheckBox__cast_(lua_State *L) {

  CheckBox *self = *((CheckBox **)dub_checksdata_n(L, 1, "mimas.CheckBox"));
  const char *key = luaL_checkstring(L, 2);
  void **retval__ = (void**)lua_newuserdata(L, sizeof(void*));
  int key_h = dub_hash(key, 3);
  switch(key_h) {
    case 2: {
      if (DUB_ASSERT_KEY(key, "mimas.QObject")) break;
      *retval__ = static_cast<QObject *>(self);
      return 1;
    }
    case 1: {
      if (DUB_ASSERT_KEY(key, "mimas.QWidget")) break;
      *retval__ = static_cast<QWidget *>(self);
      return 1;
    }
    case 0: {
      if (DUB_ASSERT_KEY(key, "mimas.QCheckBox")) break;
      *retval__ = static_cast<QCheckBox *>(self);
      return 1;
    }
  }
  return 0;
}

/** CheckBox::CheckBox(const char *title=NULL, QWidget *parent=NULL)
 * include/mimas/CheckBox.h:50
 */
static int CheckBox_CheckBox(lua_State *L) {
  try {
    int top__ = lua_gettop(L);
    if (top__ >= 2) {
      const char *title = dub_checkstring(L, 1);
      QWidget *parent = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      CheckBox *retval__ = new CheckBox(title, parent);
      retval__->pushobject(L, retval__, "mimas.CheckBox", true);
      return 1;
    } else if (top__ >= 1) {
      const char *title = dub_checkstring(L, 1);
      CheckBox *retval__ = new CheckBox(title);
      retval__->pushobject(L, retval__, "mimas.CheckBox", true);
      return 1;
    } else {
      CheckBox *retval__ = new CheckBox();
      retval__->pushobject(L, retval__, "mimas.CheckBox", true);
      return 1;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "CheckBox: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "CheckBox: Unknown exception");
  }
  return dub_error(L);
}

/** CheckBox::~CheckBox()
 * include/mimas/CheckBox.h:55
 */
static int CheckBox__CheckBox(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "mimas.CheckBox"));
    if (userdata->gc) {
      CheckBox *self = (CheckBox *)userdata->ptr;
      delete self;
    }
    userdata->gc = false;
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "~CheckBox: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "~CheckBox: Unknown exception");
  }
  return dub_error(L);
}

/** QString QObject::objectName() const
 * bind/QObject.h:7
 */
static int CheckBox_objectName(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_setObjectName(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_property(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_setProperty(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_move(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_resize(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_x(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_y(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_width(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_height(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_setParent(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_update(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_adjustSize(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_setFocus(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    self->setFocus(Qt::OtherFocusReason);
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
static int CheckBox_setFocusPolicy(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    int policy = dub_checkint(L, 2);
    self->setFocusPolicy((Qt::FocusPolicy)policy);
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
static int CheckBox_setAttribute(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    int attr = dub_checkint(L, 2);
    bool enabled = dub_checkboolean(L, 3);
    self->setAttribute((Qt::WidgetAttribute)attr, enabled);
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
static int CheckBox_setMinimumSize(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_setMouseTracking(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_close(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_isVisible(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_show(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_hide(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_lower(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_raise(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_activateWindow(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_isFullScreen(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_addAction(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_setWindowTitle(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_windowTitle(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    lua_pushstring(L, self->windowTitle().toUtf8());
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
static int CheckBox_addWidget(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
    widget->setParent(self);
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
static int CheckBox_size(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    QRect rect = self->geometry();
    lua_pushnumber(L, rect.width());
    lua_pushnumber(L, rect.height());
    return 2;
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
static int CheckBox_setStyle(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    const char *text = dub_checkstring(L, 2);
    self->setStyleSheet(QString("%1 { %2 }").arg(self->metaObject()->className()).arg(text));
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
static int CheckBox_setStyleSheet(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
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
static int CheckBox_textSize(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    const char *text = dub_checkstring(L, 2);
    lua_pushnumber(L, self->fontMetrics().width(text));
    lua_pushnumber(L, self->fontMetrics().height());
    return 2;
  } catch (std::exception &e) {
    lua_pushfstring(L, "textSize: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "textSize: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::setSizePolicy(int horizontal, int vertical)
 * bind/QWidget.h:60
 */
static int CheckBox_setSizePolicy(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    int horizontal = dub_checkint(L, 2);
    int vertical = dub_checkint(L, 3);
    self->setSizePolicy((QSizePolicy::Policy)horizontal, (QSizePolicy::Policy)vertical);
    self->updateGeometry();
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
static int CheckBox_showFullScreen(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    int top__ = lua_gettop(L);
    if (top__ >= 2) {
      bool enable = dub_checkboolean(L, 2);
      if (enable) {
        self->showFullScreen();
      } else {
        self->showNormal();
      }
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
static int CheckBox_swapFullScreen(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    if (!self->isFullScreen()) {
      self->showFullScreen();
    } else {
      self->showNormal();
    }
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
static int CheckBox_globalPosition(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    QPoint pt = self->mapToGlobal(QPoint(0, 0));
    lua_pushnumber(L, pt.x());
    lua_pushnumber(L, pt.y());
    return 2;
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
static int CheckBox_position(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    lua_pushnumber(L, self->x());
    lua_pushnumber(L, self->y());
    return 2;
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
static int CheckBox_globalMove(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    float x = dub_checknumber(L, 2);
    float y = dub_checknumber(L, 3);
    self->move(
      self->mapToParent(
        self->mapFromGlobal(QPoint(x, y))
      )
    );
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "globalMove: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "globalMove: Unknown exception");
  }
  return dub_error(L);
}

/** bool QCheckBox::isCheckable()
 * bind/QCheckBox.h:10
 */
static int CheckBox_isCheckable(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    lua_pushboolean(L, self->isCheckable());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "isCheckable: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "isCheckable: Unknown exception");
  }
  return dub_error(L);
}

/** void QCheckBox::setCheckable(bool check)
 * bind/QCheckBox.h:11
 */
static int CheckBox_setCheckable(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    bool check = dub_checkboolean(L, 2);
    self->setCheckable(check);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setCheckable: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setCheckable: Unknown exception");
  }
  return dub_error(L);
}

/** bool QCheckBox::isChecked()
 * bind/QCheckBox.h:13
 */
static int CheckBox_isChecked(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    lua_pushboolean(L, self->isChecked());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "isChecked: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "isChecked: Unknown exception");
  }
  return dub_error(L);
}

/** void QCheckBox::setChecked(bool check)
 * bind/QCheckBox.h:14
 */
static int CheckBox_setChecked(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    bool check = dub_checkboolean(L, 2);
    self->setChecked(check);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setChecked: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setChecked: Unknown exception");
  }
  return dub_error(L);
}

/** void QCheckBox::setText(QString &txt)
 * bind/QCheckBox.h:16
 */
static int CheckBox_setText(lua_State *L) {
  try {
    CheckBox *self = *((CheckBox **)dub_checksdata(L, 1, "mimas.CheckBox"));
    size_t txt_sz_;
    const char *txt = dub_checklstring(L, 2, &txt_sz_);
    
    self->setText(QString::fromUtf8(txt, txt_sz_));
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setText: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setText: Unknown exception");
  }
  return dub_error(L);
}



// --=============================================== __tostring
static int CheckBox___tostring(lua_State *L) {
  CheckBox *self = *((CheckBox **)dub_checksdata_n(L, 1, "mimas.CheckBox"));
  lua_pushfstring(L, "mimas.CheckBox: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg CheckBox_member_methods[] = {
  { "_cast_"       , CheckBox__cast_      },
  { "new"          , CheckBox_CheckBox    },
  { "__gc"         , CheckBox__CheckBox   },
  { "objectName"   , CheckBox_objectName  },
  { "setObjectName", CheckBox_setObjectName },
  { "property"     , CheckBox_property    },
  { "setProperty"  , CheckBox_setProperty },
  { "move"         , CheckBox_move        },
  { "resize"       , CheckBox_resize      },
  { "x"            , CheckBox_x           },
  { "y"            , CheckBox_y           },
  { "width"        , CheckBox_width       },
  { "height"       , CheckBox_height      },
  { "setParent"    , CheckBox_setParent   },
  { "update"       , CheckBox_update      },
  { "adjustSize"   , CheckBox_adjustSize  },
  { "setFocus"     , CheckBox_setFocus    },
  { "setFocusPolicy", CheckBox_setFocusPolicy },
  { "setAttribute" , CheckBox_setAttribute },
  { "setMinimumSize", CheckBox_setMinimumSize },
  { "setMouseTracking", CheckBox_setMouseTracking },
  { "close"        , CheckBox_close       },
  { "isVisible"    , CheckBox_isVisible   },
  { "show"         , CheckBox_show        },
  { "hide"         , CheckBox_hide        },
  { "lower"        , CheckBox_lower       },
  { "raise"        , CheckBox_raise       },
  { "activateWindow", CheckBox_activateWindow },
  { "isFullScreen" , CheckBox_isFullScreen },
  { "addAction"    , CheckBox_addAction   },
  { "setWindowTitle", CheckBox_setWindowTitle },
  { "windowTitle"  , CheckBox_windowTitle },
  { "addWidget"    , CheckBox_addWidget   },
  { "size"         , CheckBox_size        },
  { "setStyle"     , CheckBox_setStyle    },
  { "setStyleSheet", CheckBox_setStyleSheet },
  { "textSize"     , CheckBox_textSize    },
  { "setSizePolicy", CheckBox_setSizePolicy },
  { "showFullScreen", CheckBox_showFullScreen },
  { "swapFullScreen", CheckBox_swapFullScreen },
  { "globalPosition", CheckBox_globalPosition },
  { "position"     , CheckBox_position    },
  { "globalMove"   , CheckBox_globalMove  },
  { "isCheckable"  , CheckBox_isCheckable },
  { "setCheckable" , CheckBox_setCheckable },
  { "isChecked"    , CheckBox_isChecked   },
  { "setChecked"   , CheckBox_setChecked  },
  { "setText"      , CheckBox_setText     },
  { "__tostring"   , CheckBox___tostring  },
  { NULL, NULL},
};


extern "C" int luaopen_mimas_CheckBox(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.CheckBox");
  // <mt>

  // register member methods
  luaL_register(L, NULL, CheckBox_member_methods);
  // save meta-table in mimas
  dub_register(L, "mimas", "CheckBox_core");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
