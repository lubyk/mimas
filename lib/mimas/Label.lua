--[[------------------------------------------------------

  mimas.Label
  -----------

  ...

--]]------------------------------------------------------
local lib   = mimas.Label_core
mimas.Label = lib

local resize = lib.resize
function lib:resize(w, h)
  h = h or self:height()
  resize(self, w, h)
end
