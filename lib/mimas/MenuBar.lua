--[[------------------------------------------------------

  mimas.MenuBar
  ------------

  A MenuBar contains menus. The first menu bar created
  will be used as default for widgets without a specific
  menu bar (MainWindow::setMenuBar).

--]]------------------------------------------------------
local lib     = mimas.MenuBar_core
mimas.MenuBar = lib

local new = lib.new
function lib.new(win)
  local self = new()
  if win then
    win:setMenuBar(self)
  end
  return self
end

local addMenu = lib.addMenu
function lib:addMenu(title)
  local menu
  if type(title) == 'table' then
    -- we suppose we have a menu
    menu = title
  else
    menu = mimas.Menu(title)
  end
  addMenu(self, menu)
  self[title] = menu
  return menu
end
