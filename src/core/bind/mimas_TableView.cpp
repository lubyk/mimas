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
  return 0;
}

/** TableView::TableView()
 * include/mimas/TableView.h:50
 */
static int TableView_TableView(lua_State *L) {
  try {
    TableView *retval__ = new TableView();
    retval__->pushobject(L, retval__, "mimas.TableView", true);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "TableView: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "TableView: Unknown exception");
  }
  return dub_error(L);
}

/** TableView::~TableView()
 * include/mimas/TableView.h:56
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
 * include/mimas/TableView.h:61
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
 * include/mimas/TableView.h:78
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

/** void TableView::setAlternatingRowColors(bool should_enable)
 * include/mimas/TableView.h:84
 */
static int TableView_setAlternatingRowColors(lua_State *L) {
  try {
    TableView *self = *((TableView **)dub_checksdata(L, 1, "mimas.TableView"));
    bool should_enable = dub_checkboolean(L, 2);
    self->setAlternatingRowColors(should_enable);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setAlternatingRowColors: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setAlternatingRowColors: Unknown exception");
  }
  return dub_error(L);
}

/** virtual void TableView::selectRow(int row)
 * include/mimas/TableView.h:88
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
 * include/mimas/TableView.h:92
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

/** void TableView::setModel(DataSource *model)
 * include/mimas/TableView.h:98
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
  { "setAlternatingRowColors", TableView_setAlternatingRowColors },
  { "selectRow"    , TableView_selectRow  },
  { "selectColumn" , TableView_selectColumn },
  { "setModel"     , TableView_setModel   },
  { "__tostring"   , TableView___tostring },
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
  dub_register(L, "mimas", "TableView");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
