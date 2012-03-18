/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class ListView
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/ListView.h"


/** Cast (class_name)
 * 
 */
static int ListView__cast_(lua_State *L) {

  ListView *self = *((ListView **)dub_checksdata_n(L, 1, "mimas.ListView"));
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
      if (DUB_ASSERT_KEY(key, "mimas.QListView")) break;
      *retval__ = static_cast<QListView *>(self);
      return 1;
    }
  }
  return 0;
}

/** ListView::ListView()
 * include/mimas/ListView.h:54
 */
static int ListView_ListView(lua_State *L) {
  try {
    ListView *retval__ = new ListView();
    retval__->pushobject(L, retval__, "mimas.ListView", true);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "ListView: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "ListView: Unknown exception");
  }
  return dub_error(L);
}

/** ListView::~ListView()
 * include/mimas/ListView.h:56
 */
static int ListView__ListView(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "mimas.ListView"));
    if (userdata->gc) {
      ListView *self = (ListView *)userdata->ptr;
      delete self;
    }
    userdata->gc = false;
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "~ListView: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "~ListView: Unknown exception");
  }
  return dub_error(L);
}

/** LuaStackSize ListView::selectedIndexes(lua_State *L)
 * include/mimas/ListView.h:63
 */
static int ListView_selectedIndexes(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
    return self->selectedIndexes(L);
  } catch (std::exception &e) {
    lua_pushfstring(L, "selectedIndexes: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "selectedIndexes: Unknown exception");
  }
  return dub_error(L);
}

/** LuaStackSize ListView::indexAt(float x, float y, lua_State *L)
 * include/mimas/ListView.h:86
 */
static int ListView_indexAt(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
    float x = dub_checknumber(L, 2);
    float y = dub_checknumber(L, 3);
    return self->indexAt(x, y, L);
  } catch (std::exception &e) {
    lua_pushfstring(L, "indexAt: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "indexAt: Unknown exception");
  }
  return dub_error(L);
}

/** void ListView::selectRow(int row)
 * include/mimas/ListView.h:98
 */
static int ListView_selectRow(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
    int row = dub_checkint(L, 2);
    self->selectRow(row);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "selectRow: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "selectRow: Unknown exception");
  }
  return dub_error(L);
}

/** void ListView::enablePaintItem(bool enable)
 * include/mimas/ListView.h:129
 */
static int ListView_enablePaintItem(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
    bool enable = dub_checkboolean(L, 2);
    self->enablePaintItem(enable);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "enablePaintItem: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "enablePaintItem: Unknown exception");
  }
  return dub_error(L);
}

/** void ListView::enableHtml(bool enable, const char *css=NULL)
 * include/mimas/ListView.h:134
 */
static int ListView_enableHtml(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
    int top__ = lua_gettop(L);
    if (top__ >= 3) {
      bool enable = dub_checkboolean(L, 2);
      const char *css = dub_checkstring(L, 3);
      self->enableHtml(enable, css);
      return 0;
    } else {
      bool enable = dub_checkboolean(L, 2);
      self->enableHtml(enable);
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "enableHtml: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "enableHtml: Unknown exception");
  }
  return dub_error(L);
}

/** QString QObject::objectName() const
 * bind/QObject.h:7
 */
static int ListView_objectName(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setObjectName(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_property(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setProperty(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_move(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_resize(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_x(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_y(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_width(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_height(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setParent(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_update(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_adjustSize(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setFocus(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setFocusPolicy(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setAttribute(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setMinimumSize(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setMouseTracking(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_close(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_isVisible(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_show(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_hide(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_lower(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_raise(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_activateWindow(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_isFullScreen(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_addAction(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setWindowTitle(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_windowTitle(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_addWidget(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_size(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setStyle(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setStyleSheet(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_textSize(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setCssClass(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setSizeHit(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_setSizePolicy(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_showFullScreen(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_swapFullScreen(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_globalPosition(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_position(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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
static int ListView_globalMove(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
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

/** void QListView::setModel(DataSource *model)
 * bind/QListView.h:12
 */
static int ListView_setModel(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
    DataSource *model = *((DataSource **)dub_checksdata(L, 2, "mimas.DataSource"));
    self->setModel(model);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setModel: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setModel: Unknown exception");
  }
  return dub_error(L);
}

/** void QListView::scrollToBottom()
 * bind/QListView.h:13
 */
static int ListView_scrollToBottom(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
    self->scrollToBottom();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "scrollToBottom: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "scrollToBottom: Unknown exception");
  }
  return dub_error(L);
}

/** void QListView::scrollToTop()
 * bind/QListView.h:14
 */
static int ListView_scrollToTop(lua_State *L) {
  try {
    ListView *self = *((ListView **)dub_checksdata(L, 1, "mimas.ListView"));
    self->scrollToTop();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "scrollToTop: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "scrollToTop: Unknown exception");
  }
  return dub_error(L);
}



// --=============================================== __tostring
static int ListView___tostring(lua_State *L) {
  ListView *self = *((ListView **)dub_checksdata_n(L, 1, "mimas.ListView"));
  lua_pushfstring(L, "mimas.ListView: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg ListView_member_methods[] = {
  { "_cast_"       , ListView__cast_      },
  { "new"          , ListView_ListView    },
  { "__gc"         , ListView__ListView   },
  { "selectedIndexes", ListView_selectedIndexes },
  { "indexAt"      , ListView_indexAt     },
  { "selectRow"    , ListView_selectRow   },
  { "enablePaintItem", ListView_enablePaintItem },
  { "enableHtml"   , ListView_enableHtml  },
  { "objectName"   , ListView_objectName  },
  { "setObjectName", ListView_setObjectName },
  { "property"     , ListView_property    },
  { "setProperty"  , ListView_setProperty },
  { "move"         , ListView_move        },
  { "resize"       , ListView_resize      },
  { "x"            , ListView_x           },
  { "y"            , ListView_y           },
  { "width"        , ListView_width       },
  { "height"       , ListView_height      },
  { "setParent"    , ListView_setParent   },
  { "update"       , ListView_update      },
  { "adjustSize"   , ListView_adjustSize  },
  { "setFocus"     , ListView_setFocus    },
  { "setFocusPolicy", ListView_setFocusPolicy },
  { "setAttribute" , ListView_setAttribute },
  { "setMinimumSize", ListView_setMinimumSize },
  { "setMouseTracking", ListView_setMouseTracking },
  { "close"        , ListView_close       },
  { "isVisible"    , ListView_isVisible   },
  { "show"         , ListView_show        },
  { "hide"         , ListView_hide        },
  { "lower"        , ListView_lower       },
  { "raise"        , ListView_raise       },
  { "activateWindow", ListView_activateWindow },
  { "isFullScreen" , ListView_isFullScreen },
  { "addAction"    , ListView_addAction   },
  { "setWindowTitle", ListView_setWindowTitle },
  { "windowTitle"  , ListView_windowTitle },
  { "addWidget"    , ListView_addWidget   },
  { "size"         , ListView_size        },
  { "setStyle"     , ListView_setStyle    },
  { "setStyleSheet", ListView_setStyleSheet },
  { "textSize"     , ListView_textSize    },
  { "setCssClass"  , ListView_setCssClass },
  { "setSizeHit"   , ListView_setSizeHit  },
  { "setSizePolicy", ListView_setSizePolicy },
  { "showFullScreen", ListView_showFullScreen },
  { "swapFullScreen", ListView_swapFullScreen },
  { "globalPosition", ListView_globalPosition },
  { "position"     , ListView_position    },
  { "globalMove"   , ListView_globalMove  },
  { "setModel"     , ListView_setModel    },
  { "scrollToBottom", ListView_scrollToBottom },
  { "scrollToTop"  , ListView_scrollToTop },
  { "__tostring"   , ListView___tostring  },
  { NULL, NULL},
};


extern "C" int luaopen_mimas_ListView(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.ListView");
  // <mt>

  // register member methods
  luaL_register(L, NULL, ListView_member_methods);
  // save meta-table in mimas
  dub_register(L, "mimas", "ListView");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
