--[[------------------------------------------------------

  Basic tests for lubyk GUI
  -------------------------

  This tests multi-threading and event posting / triggering.
  We cannot trigger these tests with other tests because Qt
  does not like beeing started and stopped multiple times.

--]]------------------------------------------------------
require 'lubyk'

local should = test.Suite('mimas.HBoxLayout')
local withUser = should:testWithUser()

function withUser.should.displayWidgets(t)
  local win = mimas.Window()
  local lay = mimas.HBoxLayout(win)
  local btn1 = mimas.Button("Push if OK", function()
    t.continue = true
    t.win:close()
  end)
  local btn2 = mimas.Button("Quit")
  lay:addWidget(btn1)
  lay:addWidget(btn2)

  win:move(10, 10)
  win:show()
  t:timeout(function()
    return t.continue
  end)
  assertTrue(t.continue)
end

function should.displayWidgets(t)
  local win = mimas.Window()
  local lay = mimas.HBoxLayout(win)
  local btn1 = mimas.Button("Hello")
  local btn2 = mimas.Button("Quit")
  lay:addWidget(btn1)
  lay:addWidget(btn2)

  win:move(10, 10)
  local callback = mimas.Callback(function()
    t.continue = true
    win:close()
  end)

  callback:connect(btn1, 'clicked')
  callback:connect(btn2, 'clicked')

  win:show()
  app:click(btn1)
  assertTrue(t.continue)
end

test.all()
