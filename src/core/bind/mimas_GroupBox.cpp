/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class GroupBox
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/GroupBox.h"


/** Cast (class_name)
 * 
 */
static int GroupBox__cast_(lua_State *L) {

  GroupBox *self = *((GroupBox **)dub_checksdata_n(L, 1, "mimas.GroupBox"));
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

/** GroupBox::GroupBox(const char *title=NULL, QWidget *parent=NULL)
 * include/mimas/GroupBox.h:49
 */
static int GroupBox_GroupBox(lua_State *L) {
  try {
    int top__ = lua_gettop(L);
    if (top__ >= 2) {
      const char *title = dub_checkstring(L, 1);
      QWidget *parent = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      GroupBox *retval__ = new GroupBox(title, parent);
      retval__->pushobject(L, retval__, "mimas.GroupBox", true);
      return 1;
    } else if (top__ >= 1) {
      const char *title = dub_checkstring(L, 1);
      GroupBox *retval__ = new GroupBox(title);
      retval__->pushobject(L, retval__, "mimas.GroupBox", true);
      return 1;
    } else {
      GroupBox *retval__ = new GroupBox();
      retval__->pushobject(L, retval__, "mimas.GroupBox", true);
      return 1;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "GroupBox: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "GroupBox: Unknown exception");
  }
  return dub_error(L);
}

/** GroupBox::~GroupBox()
 * include/mimas/GroupBox.h:52
 */
static int GroupBox__GroupBox(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "mimas.GroupBox"));
    if (userdata->gc) {
      GroupBox *self = (GroupBox *)userdata->ptr;
      delete self;
    }
    userdata->gc = false;
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "~GroupBox: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "~GroupBox: Unknown exception");
  }
  return dub_error(L);
}

/** QString QObject::objectName() const
 * bind/QObject.h:7
 */
static int GroupBox_objectName(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_setObjectName(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_property(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_setProperty(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_move(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_resize(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_x(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_y(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_width(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_height(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_setParent(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_update(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_adjustSize(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_setFocus(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_setFocusPolicy(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_setAttribute(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_setMinimumSize(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_setMouseTracking(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_close(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_isVisible(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_show(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_hide(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_lower(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_raise(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_activateWindow(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_isFullScreen(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_addAction(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_setWindowTitle(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_windowTitle(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_addWidget(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_size(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_setStyle(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_setStyleSheet(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_textSize(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_setSizePolicy(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_showFullScreen(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_swapFullScreen(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_globalPosition(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_position(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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
static int GroupBox_globalMove(lua_State *L) {
  try {
    GroupBox *self = *((GroupBox **)dub_checksdata(L, 1, "mimas.GroupBox"));
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



// --=============================================== __tostring
static int GroupBox___tostring(lua_State *L) {
  GroupBox *self = *((GroupBox **)dub_checksdata_n(L, 1, "mimas.GroupBox"));
  lua_pushfstring(L, "mimas.GroupBox: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg GroupBox_member_methods[] = {
  { "_cast_"       , GroupBox__cast_      },
  { "new"          , GroupBox_GroupBox    },
  { "__gc"         , GroupBox__GroupBox   },
  { "objectName"   , GroupBox_objectName  },
  { "setObjectName", GroupBox_setObjectName },
  { "property"     , GroupBox_property    },
  { "setProperty"  , GroupBox_setProperty },
  { "move"         , GroupBox_move        },
  { "resize"       , GroupBox_resize      },
  { "x"            , GroupBox_x           },
  { "y"            , GroupBox_y           },
  { "width"        , GroupBox_width       },
  { "height"       , GroupBox_height      },
  { "setParent"    , GroupBox_setParent   },
  { "update"       , GroupBox_update      },
  { "adjustSize"   , GroupBox_adjustSize  },
  { "setFocus"     , GroupBox_setFocus    },
  { "setFocusPolicy", GroupBox_setFocusPolicy },
  { "setAttribute" , GroupBox_setAttribute },
  { "setMinimumSize", GroupBox_setMinimumSize },
  { "setMouseTracking", GroupBox_setMouseTracking },
  { "close"        , GroupBox_close       },
  { "isVisible"    , GroupBox_isVisible   },
  { "show"         , GroupBox_show        },
  { "hide"         , GroupBox_hide        },
  { "lower"        , GroupBox_lower       },
  { "raise"        , GroupBox_raise       },
  { "activateWindow", GroupBox_activateWindow },
  { "isFullScreen" , GroupBox_isFullScreen },
  { "addAction"    , GroupBox_addAction   },
  { "setWindowTitle", GroupBox_setWindowTitle },
  { "windowTitle"  , GroupBox_windowTitle },
  { "addWidget"    , GroupBox_addWidget   },
  { "size"         , GroupBox_size        },
  { "setStyle"     , GroupBox_setStyle    },
  { "setStyleSheet", GroupBox_setStyleSheet },
  { "textSize"     , GroupBox_textSize    },
  { "setSizePolicy", GroupBox_setSizePolicy },
  { "showFullScreen", GroupBox_showFullScreen },
  { "swapFullScreen", GroupBox_swapFullScreen },
  { "globalPosition", GroupBox_globalPosition },
  { "position"     , GroupBox_position    },
  { "globalMove"   , GroupBox_globalMove  },
  { "__tostring"   , GroupBox___tostring  },
  { NULL, NULL},
};


extern "C" int luaopen_mimas_GroupBox(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.GroupBox");
  // <mt>

  // register member methods
  luaL_register(L, NULL, GroupBox_member_methods);
  // save meta-table in mimas
  dub_register(L, "mimas", "GroupBox_core");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
