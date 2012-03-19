--[[------------------------------------------------------

  mimas.Action
  ------------

  An action is a way to connect a callback with some menu
  or shortcut.

--]]------------------------------------------------------
local lib = mimas.Action_core
mimas.Action = lib

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
    self.trigger = func
  end
  return self
end
