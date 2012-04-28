--[[------------------------------------------------------

  mimas.ListView
  --------------

  Display data as a list.

--]]------------------------------------------------------
local lib      = mimas.ListView_core
mimas.ListView = lib

-- Default column count.
function lib:columnCount()
  return 1
end

--function lib:close()
--  -- close is like delete: ensure it only runs in GUI thread
--  if not self:deleted() then
--    close(self)
--  end
--end

-- refresh
function lib:reset()
  self.data_source:reset()
end

