--[[------------------------------------------------------

  mimas.Widget
  ------------

  ...

--]]------------------------------------------------------
local lib     = mimas.Widget_core
mimas.Widget  = lib
-- We use this from C++. Make sure it is loaded to use the
-- Lua changes before being used.
require 'mimas.Menu'

local new = lib.new
function lib.new(...)
  return mimas.bootstrap(lib, new, ...)
end


--=============================================== COPY CODE TO GLWidget
--local close  = lib.close
--function lib:close()
--  if self:deleted() then
--    return false
--  else
--    close(self)
--    return true
--  end
--end

function lib:center()
  -- WARNING: global 'app' used here
  local w, h = app:screenSize()
  local sw, sh = self:size()
  self:move((w - sw) / 2, (h - sh) / 2)
end

--=============================================== dialog (maybe we should have
--                                                        this in GLWidget too)

local getOpenFileName = lib.getOpenFileName

function lib:getOpenFileName(caption, base_dir, filter, options)
  return getOpenFileName(self, caption, base_dir or '', filter or '', options or 0)
end

local getExistingDirectory = lib.getExistingDirectory
function lib:getExistingDirectory(caption, base_dir, options)
  return getExistingDirectory(self, caption, base_dir or '', options or mimas.ShowDirsOnly)
end
