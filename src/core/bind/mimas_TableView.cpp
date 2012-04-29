/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class TableView
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/TableView.h"


/** Cast (class_name)
 * 
 */
static int TableView__cast_(lua_State *L) {

  TableView *self = *((TableView **)dub_checksdata_n(L, 1, "mimas.TableView"));
  const char *key = luaL_checkstring(L, 2);
  void **retval__ = (void**)lua_newuserdata(L, sizeof(void*));
  int key_h = dub_hash(key, 3);
  switch(key_h) {
    case 0: {
      if (DUB_ASSERT_KEY(key, "mimas.QTableView")) break;
      *retval__ = static_cast<QTableView *>(self);
      return 1;
    }
    case 1: {
      if (DUB_ASSERT_KEY(key, "mimas.QWidget")) break;
      *retval__ = static_cast<QWidget *>(self);
      return 1;
    }
    case 2: {
      if (DUB_ASSERT_KEY(key, "mimas.QObject")) break;
      *retval__ = static_cast<QObject *>(self);
      return 1;
    }
  }
  return 0;
}

/** TableView::TableView(QWidget *parent=NULL)
 * include/mimas/TableView.h:52
 */
static int TableView_TableView(lua_State *L) {
  try {
    int top__ = lua_gettop(L);
    if (top__ >= 1) {
      QWidget *parent = *((QWidget **)dub_checksdata(L, 1, "mimas.QWidget"));
      TableView *retval__ = new TableView(parent);
      retval__->pushobject(L, retval__, "mimas.TableView", true);
      return 1;
    } else {
      TableView *retval__ = new TableView();
      retval__->pushobject(L, retval__, "mimas.TableView", true);
      return 1;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "TableView: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "TableView: Unknown exception");
  }
  return dub_error(L);
}

/** TableView::~TableView()
 * include/mimas/TableView.h:54
 */
static int TableView__TableView(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "mimas.TableView"));
    if (userdata->gc) {
      TableView *self = (TableView *)userdata->ptr;
      delete self;
    }
    userdata->gc = false;
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "~TableView: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "~TableView: Unknown exception");
  }
  return dub_error(L);
}

/** void TableView::setVisibleHeaders(int orientation, bool visible)
 * include/mimas/TableView.h:58
 */
static int TableView_setVisibleHeaders(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
    int orientation = dub_checkint(L, 2);
    bool visible = dub_checkboolean(L, 3);
    self->setVisibleHeaders(orientation, visible);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setVisibleHeaders: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setVisibleHeaders: Unknown exception");
  }
  return dub_error(L);
}

/** void TableView::setGridStyle(int style)
 * include/mimas/TableView.h:75
 */
static int TableView_setGridStyle(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
    int style = dub_checkint(L, 2);
    self->setGridStyle(style);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setGridStyle: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setGridStyle: Unknown exception");
  }
  return dub_error(L);
}

/** virtual void TableView::selectRow(int row)
 * include/mimas/TableView.h:79
 */
static int TableView_selectRow(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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

/** virtual void TableView::selectColumn(int row)
 * include/mimas/TableView.h:83
 */
static int TableView_selectColumn(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
    int row = dub_checkint(L, 2);
    self->selectColumn(row);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "selectColumn: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "selectColumn: Unknown exception");
  }
  return dub_error(L);
}

/** void QTableView::setModel(DataSource *model)
 * bind/QTableView.h:12
 */
static int TableView_setModel(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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

/** void QTableView::scrollToBottom()
 * bind/QTableView.h:13
 */
static int TableView_scrollToBottom(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
    self->scrollToBottom();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "scrollToBottom: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "scrollToBottom: Unknown exception");
  }
  return dub_error(L);
}

/** void QTableView::scrollToTop()
 * bind/QTableView.h:14
 */
static int TableView_scrollToTop(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
    self->scrollToTop();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "scrollToTop: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "scrollToTop: Unknown exception");
  }
  return dub_error(L);
}

/** void QTableView::setAlternatingRowColors(bool enable)
 * bind/QTableView.h:15
 */
static int TableView_setAlternatingRowColors(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
    bool enable = dub_checkboolean(L, 2);
    self->setAlternatingRowColors(enable);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setAlternatingRowColors: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setAlternatingRowColors: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::move(int x, int y)
 * bind/QWidget.h:10
 */
static int TableView_move(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
static int TableView_resize(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
static int TableView_x(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
static int TableView_y(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
static int TableView_width(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
static int TableView_height(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
static int TableView_setParent(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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

/** QWidget* QWidget::parentWidget()
 * bind/QWidget.h:17
 */
static int TableView_parentWidget(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
    QWidget *retval__ = self->parentWidget();
    if (!retval__) return 0;
    dub_pushudata(L, retval__, "mimas.QWidget", false);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "parentWidget: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "parentWidget: Unknown exception");
  }
  return dub_error(L);
}

/** void QWidget::update()
 * bind/QWidget.h:18
 */
static int TableView_update(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:19
 */
static int TableView_adjustSize(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:20
 */
static int TableView_setFocus(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:21
 */
static int TableView_setFocusPolicy(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:22
 */
static int TableView_setAttribute(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:25
 */
static int TableView_setMinimumSize(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:28
 */
static int TableView_setMouseTracking(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:29
 */
static int TableView_close(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:30
 */
static int TableView_isVisible(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:31
 */
static int TableView_show(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:32
 */
static int TableView_hide(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:33
 */
static int TableView_lower(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:34
 */
static int TableView_raise(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:35
 */
static int TableView_activateWindow(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:36
 */
static int TableView_isFullScreen(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:37
 */
static int TableView_addAction(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:38
 */
static int TableView_setWindowTitle(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:39
 */
static int TableView_windowTitle(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:45
 */
static int TableView_addWidget(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:49
 */
static int TableView_size(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:50
 */
static int TableView_setStyle(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:51
 */
static int TableView_setStyleSheet(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:54
 */
static int TableView_textSize(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:61
 */
static int TableView_setSizePolicy(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:63
 */
static int TableView_showFullScreen(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:67
 */
static int TableView_swapFullScreen(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:71
 */
static int TableView_globalPosition(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:76
 */
static int TableView_position(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
 * bind/QWidget.h:80
 */
static int TableView_globalMove(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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

/** QString QObject::objectName() const
 * bind/QObject.h:7
 */
static int TableView_objectName(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
static int TableView_setObjectName(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
static int TableView_property(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
static int TableView_setProperty(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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

/** QObject* QObject::parent()
 * bind/QObject.h:12
 */
static int TableView_parent(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
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
static int TableView___tostring(lua_State *L) {
  TableView *self = *((TableView **)dub_checksdata_n(L, 1, "mimas.TableView"));
  lua_pushfstring(L, "mimas.TableView: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg TableView_member_methods[] = {
  { "_cast_"       , TableView__cast_     },
  { "new"          , TableView_TableView  },
  { "__gc"         , TableView__TableView },
  { "setVisibleHeaders", TableView_setVisibleHeaders },
  { "setGridStyle" , TableView_setGridStyle },
  { "selectRow"    , TableView_selectRow  },
  { "selectColumn" , TableView_selectColumn },
  { "setModel"     , TableView_setModel   },
  { "scrollToBottom", TableView_scrollToBottom },
  { "scrollToTop"  , TableView_scrollToTop },
  { "setAlternatingRowColors", TableView_setAlternatingRowColors },
  { "move"         , TableView_move       },
  { "resize"       , TableView_resize     },
  { "x"            , TableView_x          },
  { "y"            , TableView_y          },
  { "width"        , TableView_width      },
  { "height"       , TableView_height     },
  { "setParent"    , TableView_setParent  },
  { "parentWidget" , TableView_parentWidget },
  { "update"       , TableView_update     },
  { "adjustSize"   , TableView_adjustSize },
  { "setFocus"     , TableView_setFocus   },
  { "setFocusPolicy", TableView_setFocusPolicy },
  { "setAttribute" , TableView_setAttribute },
  { "setMinimumSize", TableView_setMinimumSize },
  { "setMouseTracking", TableView_setMouseTracking },
  { "close"        , TableView_close      },
  { "isVisible"    , TableView_isVisible  },
  { "show"         , TableView_show       },
  { "hide"         , TableView_hide       },
  { "lower"        , TableView_lower      },
  { "raise"        , TableView_raise      },
  { "activateWindow", TableView_activateWindow },
  { "isFullScreen" , TableView_isFullScreen },
  { "addAction"    , TableView_addAction  },
  { "setWindowTitle", TableView_setWindowTitle },
  { "windowTitle"  , TableView_windowTitle },
  { "addWidget"    , TableView_addWidget  },
  { "size"         , TableView_size       },
  { "setStyle"     , TableView_setStyle   },
  { "setStyleSheet", TableView_setStyleSheet },
  { "textSize"     , TableView_textSize   },
  { "setSizePolicy", TableView_setSizePolicy },
  { "showFullScreen", TableView_showFullScreen },
  { "swapFullScreen", TableView_swapFullScreen },
  { "globalPosition", TableView_globalPosition },
  { "position"     , TableView_position   },
  { "globalMove"   , TableView_globalMove },
  { "objectName"   , TableView_objectName },
  { "setObjectName", TableView_setObjectName },
  { "property"     , TableView_property   },
  { "setProperty"  , TableView_setProperty },
  { "parent"       , TableView_parent     },
  { "__tostring"   , TableView___tostring },
  { "deleted"      , dub_isDeleted        },
  { NULL, NULL},
};


extern "C" int luaopen_mimas_TableView(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.TableView");
  // <mt>

  // register member methods
  luaL_register(L, NULL, TableView_member_methods);
  // save meta-table in mimas
  dub_register(L, "mimas", "TableView_core");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
