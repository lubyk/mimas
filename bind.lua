--[[------------------------------------------------------

  mimas bindings generator
  ------------------------

  This uses the 'dub' tool and Doxygen to generate the
  bindings for mimas.

  Input:  headers in 'include/mimas' and 'bind'
  Output: cpp files in 'src/core'

--]]------------------------------------------------------
require 'lubyk'

local base = lk.directory(lk.file())

local ins = dub.Inspector {
  INPUT    = {
    base .. '/include/mimas',
    base .. '/bind',
  },
  --doc_dir = base .. '/tmp',
  --html = true,
}

local binder = dub.LuaBinder()
local format = string.format

----------------------------------------------------------------
-- Type casting for QString and QVariant
----------------------------------------------------------------
binder:addCustomTypes {
  QString = {
    -- Get value from Lua.
    pull   = function(name, position, prefix)
      return format('size_t %s_sz_;\nconst char *%s = %schecklstring(L, %i, &%s_sz_);\n',
      name, name, prefix, position, name)
    end,
    -- Push value in Lua
    push   = function(name)
      return format('QByteArray s_%s_(%s.toUtf8());\nlua_pushlstring(L, s_%s_.constData(), s_%s_.size());', name, name, name, name)
    end,
    -- Cast value
    cast   = function(name)
      return format('QString::fromUtf8(%s, %s_sz_)', name, name)
    end,
  },
  QVariant = {
    -- Get value from Lua.
    pull   = function(name, position, prefix)
      return format('QVariant %s(variantFromLua(L, %i));', name, position)
    end,
    -- Push value in Lua
    push   = function(name)
      return format('pushVariantInLua(L, %s)', name)
    end,
  },
}

----------------------------------------------------------------
-- bind
----------------------------------------------------------------

local dir = lk.Dir(base .. '/include/mimas')
local only = {}
for file in lfs.dir(base .. '/include/mimas') do
  local name = file:match('^([A-Z][a-zA-Z]+)%.h$')
  if name then
    table.insert(only, name)
  end
end

binder:bind(ins, {
  output_directory = base .. '/src/core/bind',
  -- Remove this part in included headers
  header_base = base .. '/include',
  -- Create a single library.
  single_lib = 'mimas',
  -- Open the library with require 'mimas.core' (not 'mimas')
  luaopen    = 'mimas_core',
  only = only,
})

