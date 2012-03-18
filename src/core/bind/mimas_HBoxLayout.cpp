/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class HBoxLayout
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/HBoxLayout.h"


/** Cast (class_name)
 * 
 */
static int HBoxLayout__cast_(lua_State *L) {

  HBoxLayout *self = *((HBoxLayout **)dub_checksdata_n(L, 1, "mimas.HBoxLayout"));
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
      if (DUB_ASSERT_KEY(key, "mimas.QLayout")) break;
      *retval__ = static_cast<QLayout *>(self);
      return 1;
    }
  }
  return 0;
}

/** HBoxLayout::HBoxLayout(QWidget *parent=NULL)
 * include/mimas/HBoxLayout.h:48
 */
static int HBoxLayout_HBoxLayout(lua_State *L) {
  try {
    int top__ = lua_gettop(L);
    if (top__ >= 1) {
      QWidget *parent = *((QWidget **)dub_checksdata(L, 1, "mimas.QWidget"));
      HBoxLayout *retval__ = new HBoxLayout(parent);
      retval__->pushobject(L, retval__, "mimas.HBoxLayout", true);
      return 1;
    } else {
      HBoxLayout *retval__ = new HBoxLayout();
      retval__->pushobject(L, retval__, "mimas.HBoxLayout", true);
      return 1;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "HBoxLayout: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "HBoxLayout: Unknown exception");
  }
  return dub_error(L);
}

/** HBoxLayout::~HBoxLayout()
 * include/mimas/HBoxLayout.h:51
 */
static int HBoxLayout__HBoxLayout(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "mimas.HBoxLayout"));
    if (userdata->gc) {
      HBoxLayout *self = (HBoxLayout *)userdata->ptr;
      delete self;
    }
    userdata->gc = false;
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "~HBoxLayout: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "~HBoxLayout: Unknown exception");
  }
  return dub_error(L);
}

/** void HBoxLayout::addWidget(QWidget *widget, int stretch=0, int alignment=0)
 * include/mimas/HBoxLayout.h:54
 */
static int HBoxLayout_addWidget(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
    int top__ = lua_gettop(L);
    if (top__ >= 4) {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      int stretch = dub_checkint(L, 3);
      int alignment = dub_checkint(L, 4);
      self->addWidget(widget, stretch, alignment);
      return 0;
    } else if (top__ >= 3) {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      int stretch = dub_checkint(L, 3);
      self->addWidget(widget, stretch);
      return 0;
    } else {
      QWidget *widget = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
      self->addWidget(widget);
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "addWidget: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "addWidget: Unknown exception");
  }
  return dub_error(L);
}

/** void HBoxLayout::insertWidget(int pos, QWidget *widget, int stretch=0, int alignment=0)
 * include/mimas/HBoxLayout.h:58
 */
static int HBoxLayout_insertWidget(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
    int top__ = lua_gettop(L);
    if (top__ >= 5) {
      int pos = dub_checkint(L, 2);
      QWidget *widget = *((QWidget **)dub_checksdata(L, 3, "mimas.QWidget"));
      int stretch = dub_checkint(L, 4);
      int alignment = dub_checkint(L, 5);
      self->insertWidget(pos, widget, stretch, alignment);
      return 0;
    } else if (top__ >= 4) {
      int pos = dub_checkint(L, 2);
      QWidget *widget = *((QWidget **)dub_checksdata(L, 3, "mimas.QWidget"));
      int stretch = dub_checkint(L, 4);
      self->insertWidget(pos, widget, stretch);
      return 0;
    } else {
      int pos = dub_checkint(L, 2);
      QWidget *widget = *((QWidget **)dub_checksdata(L, 3, "mimas.QWidget"));
      self->insertWidget(pos, widget);
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "insertWidget: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "insertWidget: Unknown exception");
  }
  return dub_error(L);
}

/** void HBoxLayout::addLayout(QLayout *layout, int stretch=0)
 * include/mimas/HBoxLayout.h:68
 */
static int HBoxLayout_addLayout(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
    int top__ = lua_gettop(L);
    if (top__ >= 3) {
      QLayout *layout = *((QLayout **)dub_checksdata(L, 2, "mimas.QLayout"));
      int stretch = dub_checkint(L, 3);
      self->addLayout(layout, stretch);
      return 0;
    } else {
      QLayout *layout = *((QLayout **)dub_checksdata(L, 2, "mimas.QLayout"));
      self->addLayout(layout);
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "addLayout: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "addLayout: Unknown exception");
  }
  return dub_error(L);
}

/** void HBoxLayout::insertLayout(int pos, QLayout *layout, int stretch=0)
 * include/mimas/HBoxLayout.h:72
 */
static int HBoxLayout_insertLayout(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
    int top__ = lua_gettop(L);
    if (top__ >= 4) {
      int pos = dub_checkint(L, 2);
      QLayout *layout = *((QLayout **)dub_checksdata(L, 3, "mimas.QLayout"));
      int stretch = dub_checkint(L, 4);
      self->insertLayout(pos, layout, stretch);
      return 0;
    } else {
      int pos = dub_checkint(L, 2);
      QLayout *layout = *((QLayout **)dub_checksdata(L, 3, "mimas.QLayout"));
      self->insertLayout(pos, layout);
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "insertLayout: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "insertLayout: Unknown exception");
  }
  return dub_error(L);
}

/** bool HBoxLayout::setAlignment(QWidget *w, int alignment)
 * include/mimas/HBoxLayout.h:86
 */
static int HBoxLayout_setAlignment(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
    QWidget *w = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
    int alignment = dub_checkint(L, 3);
    lua_pushboolean(L, self->setAlignment(w, alignment));
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setAlignment: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setAlignment: Unknown exception");
  }
  return dub_error(L);
}

/** void HBoxLayout::addStretch(int stretch=1)
 * include/mimas/HBoxLayout.h:92
 */
static int HBoxLayout_addStretch(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
    int top__ = lua_gettop(L);
    if (top__ >= 2) {
      int stretch = dub_checkint(L, 2);
      self->addStretch(stretch);
      return 0;
    } else {
      self->addStretch();
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "addStretch: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "addStretch: Unknown exception");
  }
  return dub_error(L);
}

/** void HBoxLayout::addSpacing(int size)
 * include/mimas/HBoxLayout.h:98
 */
static int HBoxLayout_addSpacing(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
    int size = dub_checkint(L, 2);
    self->addSpacing(size);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "addSpacing: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "addSpacing: Unknown exception");
  }
  return dub_error(L);
}

/** void HBoxLayout::setSpacing(int space)
 * include/mimas/HBoxLayout.h:104
 */
static int HBoxLayout_setSpacing(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
    int space = dub_checkint(L, 2);
    self->setSpacing(space);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setSpacing: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setSpacing: Unknown exception");
  }
  return dub_error(L);
}

/** void HBoxLayout::setContentsMargins(int left, int top, int right, int bottom)
 * include/mimas/HBoxLayout.h:108
 */
static int HBoxLayout_setContentsMargins(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
    int left = dub_checkint(L, 2);
    int top = dub_checkint(L, 3);
    int right = dub_checkint(L, 4);
    int bottom = dub_checkint(L, 5);
    self->setContentsMargins(left, top, right, bottom);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setContentsMargins: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setContentsMargins: Unknown exception");
  }
  return dub_error(L);
}

/** LuaStackSize HBoxLayout::minimumSize(lua_State *L) const
 * include/mimas/HBoxLayout.h:112
 */
static int HBoxLayout_minimumSize(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
    return self->minimumSize(L);
  } catch (std::exception &e) {
    lua_pushfstring(L, "minimumSize: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "minimumSize: Unknown exception");
  }
  return dub_error(L);
}

/** QString QObject::objectName() const
 * bind/QObject.h:7
 */
static int HBoxLayout_objectName(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setObjectName(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_property(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setProperty(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_move(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_resize(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_x(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_y(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_width(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_height(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setParent(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_update(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_adjustSize(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setFocus(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setFocusPolicy(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setAttribute(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setMinimumSize(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setMouseTracking(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_close(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_isVisible(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_show(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_hide(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_lower(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_raise(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_activateWindow(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_isFullScreen(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_addAction(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setWindowTitle(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_windowTitle(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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

/** LuaStackSize QWidget::size()
 * bind/QWidget.h:48
 */
static int HBoxLayout_size(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setStyle(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setStyleSheet(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_textSize(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setCssClass(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setSizeHit(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_setSizePolicy(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_showFullScreen(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_swapFullScreen(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_globalPosition(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_position(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_globalMove(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout___tostring(lua_State *L) {
  HBoxLayout *self = *((HBoxLayout **)dub_checksdata_n(L, 1, "mimas.HBoxLayout"));
  lua_pushfstring(L, "mimas.HBoxLayout: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg HBoxLayout_member_methods[] = {
  { "_cast_"       , HBoxLayout__cast_    },
  { "new"          , HBoxLayout_HBoxLayout },
  { "__gc"         , HBoxLayout__HBoxLayout },
  { "addWidget"    , HBoxLayout_addWidget },
  { "insertWidget" , HBoxLayout_insertWidget },
  { "addLayout"    , HBoxLayout_addLayout },
  { "insertLayout" , HBoxLayout_insertLayout },
  { "setAlignment" , HBoxLayout_setAlignment },
  { "addStretch"   , HBoxLayout_addStretch },
  { "addSpacing"   , HBoxLayout_addSpacing },
  { "setSpacing"   , HBoxLayout_setSpacing },
  { "setContentsMargins", HBoxLayout_setContentsMargins },
  { "minimumSize"  , HBoxLayout_minimumSize },
  { "objectName"   , HBoxLayout_objectName },
  { "setObjectName", HBoxLayout_setObjectName },
  { "property"     , HBoxLayout_property  },
  { "setProperty"  , HBoxLayout_setProperty },
  { "move"         , HBoxLayout_move      },
  { "resize"       , HBoxLayout_resize    },
  { "x"            , HBoxLayout_x         },
  { "y"            , HBoxLayout_y         },
  { "width"        , HBoxLayout_width     },
  { "height"       , HBoxLayout_height    },
  { "setParent"    , HBoxLayout_setParent },
  { "update"       , HBoxLayout_update    },
  { "adjustSize"   , HBoxLayout_adjustSize },
  { "setFocus"     , HBoxLayout_setFocus  },
  { "setFocusPolicy", HBoxLayout_setFocusPolicy },
  { "setAttribute" , HBoxLayout_setAttribute },
  { "setMinimumSize", HBoxLayout_setMinimumSize },
  { "setMouseTracking", HBoxLayout_setMouseTracking },
  { "close"        , HBoxLayout_close     },
  { "isVisible"    , HBoxLayout_isVisible },
  { "show"         , HBoxLayout_show      },
  { "hide"         , HBoxLayout_hide      },
  { "lower"        , HBoxLayout_lower     },
  { "raise"        , HBoxLayout_raise     },
  { "activateWindow", HBoxLayout_activateWindow },
  { "isFullScreen" , HBoxLayout_isFullScreen },
  { "addAction"    , HBoxLayout_addAction },
  { "setWindowTitle", HBoxLayout_setWindowTitle },
  { "windowTitle"  , HBoxLayout_windowTitle },
  { "size"         , HBoxLayout_size      },
  { "setStyle"     , HBoxLayout_setStyle  },
  { "setStyleSheet", HBoxLayout_setStyleSheet },
  { "textSize"     , HBoxLayout_textSize  },
  { "setCssClass"  , HBoxLayout_setCssClass },
  { "setSizeHit"   , HBoxLayout_setSizeHit },
  { "setSizePolicy", HBoxLayout_setSizePolicy },
  { "showFullScreen", HBoxLayout_showFullScreen },
  { "swapFullScreen", HBoxLayout_swapFullScreen },
  { "globalPosition", HBoxLayout_globalPosition },
  { "position"     , HBoxLayout_position  },
  { "globalMove"   , HBoxLayout_globalMove },
  { "__tostring"   , HBoxLayout___tostring },
  { NULL, NULL},
};


extern "C" int luaopen_mimas_HBoxLayout(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.HBoxLayout");
  // <mt>

  // register member methods
  luaL_register(L, NULL, HBoxLayout_member_methods);
  // save meta-table in mimas
  dub_register(L, "mimas", "HBoxLayout_core");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
