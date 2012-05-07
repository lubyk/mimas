--[[------------------------------------------------------

  mimas.GroupBox
  --------------

  Group widgets with a frame and a title.

--]]------------------------------------------------------
local lib = mimas.GroupBox_core
mimas.GroupBox = lib

local new = lib.new
local function bnew(...)
  local self = new(...)
  local title, parent = ...
  if title then
    self:setStyleSheet [[
      GroupBox {
        background: hsva(0,0,70,80);
        border: 1px solid #555;
        border-radius: 5px;
        margin-top:9px;
      }
      QGroupBox::title {
        subcontrol-origin: margin;
        subcontrol-position: top left;
        position:relative;
        left:6px;
      }
    ]]
  end
  return self
end

function lib.new(...)
  return mimas.bootstrap(lib, bnew, ...)
end
