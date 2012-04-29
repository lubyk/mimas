--[[------------------------------------------------------

  mimas.ListView
  --------------

  Display data as a list.

--]]------------------------------------------------------
local lib      = mimas.ListView_core
mimas.ListView = lib

local base_new = lib.new

local function new(...)
  local lv = base_new(...)
  -- To ease a purely functional style, we pass calls to the
  -- DataSource (ds) directly to ListView (lv)
  local ds = mimas.DataSource()
  function ds:rowCount()
    return lv:rowCount()
  end

  function ds:data(...)
    return lv:data(...)
  end

  lv:setModel(ds)
  -- Prevent garbage collection
  lv.ds = ds
  return lv
end

function lib.new(...)
  return mimas.bootstrap(lib, new, ...)
end

function lib:rowCount()
  return 0
end

function lib:data()
  return nil
end
--function lib:close()
--  -- close is like delete: ensure it only runs in GUI thread
--  if not self:deleted() then
--    close(self)
--  end
--end

-- refresh
function lib:reset()
  self.ds:reset()
end

