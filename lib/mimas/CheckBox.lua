--[[------------------------------------------------------

  mimas.CheckBox
  --------------

  ...

--]]------------------------------------------------------
local lib      = mimas.CheckBox_core
mimas.CheckBox = lib

local new = lib.new
function lib.new(title, parent, func)
  local self
  if not func then
    if type(parent) == 'function' then
      func = parent
      parent = nil
    end
  end
  if parent then
    self = new(title, parent)
  else
    self = new(title)
  end
  if func then
    self.click = func
  end
  return self
end

