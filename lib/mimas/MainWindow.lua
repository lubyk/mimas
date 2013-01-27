--[[------------------------------------------------------

  mimas.MainWindow
  ----------------

  ...

--]]------------------------------------------------------
local lib = mimas.MainWindow_core
mimas.MainWindow = lib

local new = lib.new
function lib.new(...)
  return mimas.bootstrap(lib, new, ...)
end

function lib:center()
  local w, h = app:screenSize()
  local sw, sh = self:size()
  self:move((w - sw) / 2, (h - sh) / 2)
end

local getOpenFileName = lib.getOpenFileName

function lib:getOpenFileName(caption, base_dir, filter, options)
  return getOpenFileName(self, caption, base_dir or '', filter or '', options or 0)
end

local getExistingDirectory = lib.getExistingDirectory
function lib:getExistingDirectory(caption, base_dir, options)
  return getExistingDirectory(self, caption, base_dir or '', options or mimas.ShowDirsOnly)
end

