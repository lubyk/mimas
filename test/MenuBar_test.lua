--[[------------------------------------------------------

  Basic tests for MenuBar
  -----------------------

  ...

--]]------------------------------------------------------
require 'lubyk'
local should = test.Suite('mimas.MenuBar')
local withUser = should:testWithUser()

function withUser.should.addMenuBarToWindow(t)
  t.win = mimas.MainWindow()
  t.lbl = mimas.Label('Type Cmd-S or choose from menu')
  t.win:setCentralWidget(t.lbl)
  t.bar = mimas.MenuBar(t.win)
  local menu = t.bar:addMenu('Foo')
  menu:addAction('Ignore me', 'Ctrl+I', function()
  end)
  menu:addAction('select me', 'Ctrl+S', function()
    t.continue = true
  end)
  t.win:show()
  t:timeout(function()
    return t.continue == true
  end)
  t.win:close()
  assertTrue(t.continue)
end

test.all()
