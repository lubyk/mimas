--[[------------------------------------------------------

  mimas.TableView
  ---------------

  Display tabular data

--]]------------------------------------------------------
local lib = mimas.TableView_core
mimas.TableView = lib

local base_new = lib.new

local function new(...)
  local tv = base_new(...)
  -- To ease a purely functional style, we pass calls to the
  -- DataSource (ds) directly to TableView (tv)
  local ds = mimas.DataSource()

  function ds:header(...)
    return tv:header(...)
  end

  function ds:columnCount()
    return tv:columnCount()
  end

  function ds:rowCount()
    return tv:rowCount()
  end

  function ds:data(...)
    return tv:data(...)
  end

  tv:setModel(ds)
  -- Prevent garbage collection
  tv.ds = ds
  return tv
end

function lib.new(...)
  return mimas.bootstrap(lib, new, ...)
end

-- Default column count.
function lib:columnCount()
  return 1
end

function lib:rowCount()
  return 0
end

function lib:data()
  return nil
end

function lib:header()
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

