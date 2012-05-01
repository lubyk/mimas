/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class SocketNotifier
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/SocketNotifier.h"


/** Cast (class_name)
 * 
 */
static int SocketNotifier__cast_(lua_State *L) {

  SocketNotifier *self = *((SocketNotifier **)dub_checksdata_n(L, 1, "mimas.SocketNotifier"));
  const char *key = luaL_checkstring(L, 2);
  void **retval__ = (void**)lua_newuserdata(L, sizeof(void*));
  int key_h = dub_hash(key, 2);
  switch(key_h) {
    case 1: {
      if (DUB_ASSERT_KEY(key, "mimas.QObject")) break;
      *retval__ = static_cast<QObject *>(self);
      return 1;
    }
  }
  return 0;
}

/** SocketNotifier::SocketNotifier(int fd, int event_type)
 * include/mimas/SocketNotifier.h:53
 */
static int SocketNotifier_SocketNotifier(lua_State *L) {
  try {
    int fd = dub_checkint(L, 1);
    int event_type = dub_checkint(L, 2);
    SocketNotifier *retval__ = new SocketNotifier(fd, event_type);
    retval__->pushobject(L, retval__, "mimas.SocketNotifier", true);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "SocketNotifier: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "SocketNotifier: Unknown exception");
  }
  return dub_error(L);
}

/** virtual SocketNotifier::~SocketNotifier()
 * include/mimas/SocketNotifier.h:58
 */
static int SocketNotifier__SocketNotifier(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "mimas.SocketNotifier"));
    if (userdata->gc) {
      SocketNotifier *self = (SocketNotifier *)userdata->ptr;
      delete self;
    }
    userdata->gc = false;
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "~SocketNotifier: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "~SocketNotifier: Unknown exception");
  }
  return dub_error(L);
}

/** int SocketNotifier::socket() const
 * include/mimas/SocketNotifier.h:61
 */
static int SocketNotifier_socket(lua_State *L) {
  try {
    SocketNotifier *self = *((SocketNotifier **)dub_checksdata(L, 1, "mimas.SocketNotifier"));
    lua_pushnumber(L, self->socket());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "socket: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "socket: Unknown exception");
  }
  return dub_error(L);
}

/** void SocketNotifier::setEnabled(bool enabled)
 * include/mimas/SocketNotifier.h:68
 */
static int SocketNotifier_setEnabled(lua_State *L) {
  try {
    SocketNotifier *self = *((SocketNotifier **)dub_checksdata(L, 1, "mimas.SocketNotifier"));
    bool enabled = dub_checkboolean(L, 2);
    self->setEnabled(enabled);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setEnabled: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setEnabled: Unknown exception");
  }
  return dub_error(L);
}

/** QString QObject::objectName() const
 * bind/QObject.h:7
 */
static int SocketNotifier_objectName(lua_State *L) {
  try {
    SocketNotifier *self = *((SocketNotifier **)dub_checksdata(L, 1, "mimas.SocketNotifier"));
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
static int SocketNotifier_setObjectName(lua_State *L) {
  try {
    SocketNotifier *self = *((SocketNotifier **)dub_checksdata(L, 1, "mimas.SocketNotifier"));
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
static int SocketNotifier_property(lua_State *L) {
  try {
    SocketNotifier *self = *((SocketNotifier **)dub_checksdata(L, 1, "mimas.SocketNotifier"));
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
static int SocketNotifier_setProperty(lua_State *L) {
  try {
    SocketNotifier *self = *((SocketNotifier **)dub_checksdata(L, 1, "mimas.SocketNotifier"));
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
static int SocketNotifier_setParent(lua_State *L) {
  try {
    SocketNotifier *self = *((SocketNotifier **)dub_checksdata(L, 1, "mimas.SocketNotifier"));
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
static int SocketNotifier_parent(lua_State *L) {
  try {
    SocketNotifier *self = *((SocketNotifier **)dub_checksdata(L, 1, "mimas.SocketNotifier"));
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
static int SocketNotifier___tostring(lua_State *L) {
  SocketNotifier *self = *((SocketNotifier **)dub_checksdata_n(L, 1, "mimas.SocketNotifier"));
  lua_pushfstring(L, "mimas.SocketNotifier: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg SocketNotifier_member_methods[] = {
  { "_cast_"       , SocketNotifier__cast_ },
  { "new"          , SocketNotifier_SocketNotifier },
  { "__gc"         , SocketNotifier__SocketNotifier },
  { "socket"       , SocketNotifier_socket },
  { "setEnabled"   , SocketNotifier_setEnabled },
  { "objectName"   , SocketNotifier_objectName },
  { "setObjectName", SocketNotifier_setObjectName },
  { "property"     , SocketNotifier_property },
  { "setProperty"  , SocketNotifier_setProperty },
  { "setParent"    , SocketNotifier_setParent },
  { "parent"       , SocketNotifier_parent },
  { "__tostring"   , SocketNotifier___tostring },
  { "deleted"      , dub_isDeleted        },
  { NULL, NULL},
};

// --=============================================== CONSTANTS
static const struct dub_const_Reg SocketNotifier_const[] = {
  { "Read"         , SocketNotifier::Read },
  { "Write"        , SocketNotifier::Write },
  { NULL, 0},
};

extern "C" int luaopen_mimas_SocketNotifier(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "mimas.SocketNotifier");
  // <mt>
  // register class constants
  dub_register_const(L, SocketNotifier_const);

  // register member methods
  luaL_register(L, NULL, SocketNotifier_member_methods);
  // save meta-table in mimas
  dub_register(L, "mimas", "SocketNotifier_core");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
