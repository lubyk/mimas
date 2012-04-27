--[[------------------------------------------------------

  mimas.Menu
  ------------

  A Menu contains actions (added with addAction) and must
  be inserted in a MenuBar (with addMenu).

--]]------------------------------------------------------
local lib  = mimas.Menu_core
mimas.Menu = lib

local addAction = lib.addAction
function lib:addAction(title, shortcut, func)
  local action
  if type(title) == 'table' then
    -- we suppose that we have an action
    action = title
  else
    -- we create a new action
    action = mimas.Action(title, self)
    if shortcut then
      action:setShortcut(shortcut)
    end
    action.trigger = func
  end
  addAction(self, action)
  self[action:text()] = action
  return action
end
