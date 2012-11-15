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
  int key_h = dub_hash(key, 4);
  switch(key_h) {
    case 3: {
      if (DUB_ASSERT_KEY(key, "mimas.QBoxLayout")) break;
      *retval__ = static_cast<QBoxLayout *>(self);
      return 1;
    }
    case 0: {
      if (DUB_ASSERT_KEY(key, "mimas.QLayout")) break;
      *retval__ = static_cast<QLayout *>(self);
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
    lua_pushfstring(L, "new: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "new: Unknown exception");
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
    lua_pushfstring(L, "__gc: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "__gc: Unknown exception");
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

/** void QBoxLayout::addStretch(int stretch=0)
 * bind/QBoxLayout.h:11
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

/** void QBoxLayout::addSpacing(int size)
 * bind/QBoxLayout.h:15
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

/** void QBoxLayout::setSpacing(int space)
 * bind/QBoxLayout.h:19
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

/** void QLayout::activate()
 * bind/QLayout.h:12
 */
static int HBoxLayout_activate(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
    self->activate();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "activate: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "activate: Unknown exception");
  }
  return dub_error(L);
}

/** bool QLayout::setAlignment(QWidget *w, int alignment)
 * bind/QLayout.h:13
 */
static int HBoxLayout_setAlignment(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
    QWidget *w = *((QWidget **)dub_checksdata(L, 2, "mimas.QWidget"));
    int alignment = dub_checkint(L, 3);
    lua_pushboolean(L, self->setAlignment(w, (Qt::Alignment)alignment));
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setAlignment: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setAlignment: Unknown exception");
  }
  return dub_error(L);
}

/** LuaStackSize QLayout::minimumSize(lua_State *L)
 * bind/QLayout.h:14
 */
static int HBoxLayout_minimumSize(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
    QSize s(self->minimumSize());
    lua_pushnumber(L, s.width());
    lua_pushnumber(L, s.height());
    return 2;
  } catch (std::exception &e) {
    lua_pushfstring(L, "minimumSize: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "minimumSize: Unknown exception");
  }
  return dub_error(L);
}

/** void QLayout::setContentsMargins(int left, int top, int right, int bottom)
 * bind/QLayout.h:15
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

/** QString QObject::objectName() const
 * bind/QObject.h:7
 */
static int HBoxLayout_objectName(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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

/** void QObject::setParent(QObject *parent)
 * bind/QObject.h:11
 */
static int HBoxLayout_setParent(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
static int HBoxLayout_parent(lua_State *L) {
  try {
    HBoxLayout *self = *((HBoxLayout **)dub_checksdata(L, 1, "mimas.HBoxLayout"));
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
  { "addStretch"   , HBoxLayout_addStretch },
  { "addSpacing"   , HBoxLayout_addSpacing },
  { "setSpacing"   , HBoxLayout_setSpacing },
  { "activate"     , HBoxLayout_activate  },
  { "setAlignment" , HBoxLayout_setAlignment },
  { "minimumSize"  , HBoxLayout_minimumSize },
  { "setContentsMargins", HBoxLayout_setContentsMargins },
  { "objectName"   , HBoxLayout_objectName },
  { "setObjectName", HBoxLayout_setObjectName },
  { "property"     , HBoxLayout_property  },
  { "setProperty"  , HBoxLayout_setProperty },
  { "setParent"    , HBoxLayout_setParent },
  { "parent"       , HBoxLayout_parent    },
  { "__tostring"   , HBoxLayout___tostring },
  { "deleted"      , dub_isDeleted        },
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
  dub_register(L, "mimas", "HBoxLayout_core", "HBoxLayout");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
