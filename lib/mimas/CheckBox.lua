--[[------------------------------------------------------

  mimas.CheckBox
  --------------

  ...

--]]------------------------------------------------------
local lib      = mimas.CheckBox_core
mimas.CheckBox = lib

local MousePress = mimas.MousePress
local constr = lib.new
function lib.new(title, parent, func)
  local self
  if not func then
    if type(parent) == 'function' then
      func = parent
      parent = nil
    end
  end
  if parent then
    self = constr(title, parent)
  else
    self = constr(title)
  end
  if func then
    self.click = func
  end
  return self
end

