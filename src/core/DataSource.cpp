
#include "mimas/DataSource.h"
#include "mimas/Color.h"

QVariant DataSource::data(const QModelIndex &index, int role) const {
  if (role == Qt::DisplayRole) {
    if (!dub_pushcallback("data")) return QVariant();
  } else if (role == Qt::EditRole) {
    if (!dub_pushcallback("editData") && !dub_pushcallback("data")) return QVariant();
  } else if (role == Qt::ToolTipRole) {
    if (!dub_pushcallback("tooltip")) return QVariant();
  } else if (role == Qt::BackgroundRole) {
    if (!dub_pushcallback("background")) return QVariant();
  } else if (role == Qt::ForegroundRole) {
    if (!dub_pushcallback("foreground")) return QVariant();
  } else {
    return QVariant();
  }
  lua_State *L = const_cast<lua_State*>(dub_L);
  lua_pushnumber(L, index.row() + 1);
  lua_pushnumber(L, index.column() + 1);
  // <func> <self> <row> <column>
  if (!dub_call(3, 1)) {
    // failed
    return QVariant();
  } 
  QVariant res;
  if (role == Qt::BackgroundRole || role == Qt::ForegroundRole) {
    if (!lua_isnil(L, -1)) {
      try {
        Color *color = *((Color **)dub_checksdata_n(L, -1, "mimas.Color"));
        res = *color;
      } catch (dub::Exception) {
        // ignore
      }
    }
  } else {
    res = variantFromLua(L, -1);
  }
  lua_pop(L, 1);
  return res;
}

QVariant DataSource::headerData(int section, Qt::Orientation orientation, int role) const {
  lua_State *L = const_cast<lua_State*>(dub_L);
  if (role == Qt::DisplayRole) {
    if (!dub_pushcallback("header")) return QVariant();
    lua_pushnumber(L, section + 1);
    lua_pushnumber(L, orientation);
    // <func> <self> <section> <orientation>
    if (!dub_call(3, 1)) {
      return QVariant();
    }
    QVariant res = variantFromLua(L, -1);
    lua_pop(L, 1);
    return res;
  } else if (role == Qt::BackgroundRole || role == Qt::ForegroundRole) {
    if (!dub_pushcallback(
         role == Qt::BackgroundRole ? "background" : "foreground"
        )) return QVariant();
    lua_pushnumber(L, section + 1);
    // <func> <self> <section>
    if (!dub_call(2, 1)) {
      return QVariant();
    }
    if (!lua_isnil(L, -1)) {
      try {
        Color *color = *((Color **)dub_checksdata_n(L, -1, "mimas.Color"));
        QVariant res = *color;
        lua_pop(L, 1);
        return res;
      } catch(dub::Exception) {
        return QVariant();
      }
    }
  }
  return QVariant();
}

