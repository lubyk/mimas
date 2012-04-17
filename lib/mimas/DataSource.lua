--[[------------------------------------------------------

  mimas.DataSource
  ----------------

  Can replace the default (inner) source of data for
  ListView, TableView and friends.

--]]------------------------------------------------------
local lib        = mimas.DataSource_core
mimas.DataSource = lib

local constr = lib.new
function lib.new(data)
  local self = constr()
  self.data = data
  return self
end

function lib:columnCount()
  -- default useful for ListView
  return 1
end

function self:rowCount()
  return self.data and #self.data
end

function self:data(row)
  return self.data and self.data[row]
end
