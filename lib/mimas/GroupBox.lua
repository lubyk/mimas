--[[------------------------------------------------------

  mimas.GroupBox
  --------------

  Group widgets with a frame and a title.

--]]------------------------------------------------------
local lib = mimas.GroupBox_core
mimas.GroupBox = lib

local new = lib.new
function lib.new(...)
  return mimas.bootstrap(lib, new, ...)
end
