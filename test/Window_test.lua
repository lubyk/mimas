--[[------------------------------------------------------

  Basic tests for lubyk GUI
  -------------------------

  This tests multi-threading and event posting / triggering.
  We cannot trigger these tests with other tests because Qt
  does not like beeing started and stopped multiple times.

--]]------------------------------------------------------
require 'lubyk'

local should = test.Suite('mimas.Window')
local withUser = should:testWithUser()

function should.displayWindow(t)
  -- direct call to userdata
  t.win = mimas.Window().super
  t.layout = mimas.HBoxLayout(t.win)
  t.win:move(10, 10)
  t.win:show()
  t.label = mimas.Label("Window closes in 200ms")
  t.layout:addWidget(t.label)
  sleep(200)
  assertTrue(true)
end

function should.accessUserdataWithSuper(t)
  t.win = mimas.Window()
  assertType('table', t.win)
  t.layout = mimas.HBoxLayout(t.win)
  t.win:move(10, 10)
  t.win:show()
  -- callbacks
  t.label = mimas.Label("Super closes in 200ms")
  t.layout:addWidget(t.label)

  sleep(200)
  t.win:close()
  assertTrue(true)
end

function withUser.should.useCustomPaint(t)
  -- we use the test env to protect from gc
  t.win = mimas.Window()
  t.btn = mimas.Button('Push if OK', function()
    t.continue = true
  end)
  t.win:addWidget(t.btn, 10, 10)
  t.win:move(10, 10)
  t.win:resize(100, 100)
  function t.win:paint(p)
    for i=0,40,10 do
      p:fillRect(10+i, 10+i, 80-2*i, 80-2*i, mimas.Color(0.2 + i/50, 0.5, 0.8, 0.5))
    end
  end
  t.win:show()

  t:timeout(function()
    return t.continue
  end)
  assertTrue(t.continue)
end

function should.setResizedCallback(t)
  t.win = mimas.Window()
  t.win:move(10, 10)
  t.ok = false
  function t.win:resized(w, h)
    assertEqual(10, w)
    assertEqual(20, h)
    t.ok = true
  end
  t.win:resize(10, 20)
  t.win:show()

  sleep(200)
  t.win:close()
  while not t.ok do
    sleep(200)
  end
  assertTrue(t.ok)
end

function should.acceptDestroyFromGui(t)
  t.win = mimas.Window()
  t.win:move(10, 10)
  t.win:resize(50, 50)
  t.win:show()

  sleep(200)
  t.win:close()
  while not t.win:deleted() do
    sleep(200)
  end
  assertTrue(t.win:deleted())
end

function should.acceptDestroyFromLua()
  local win = mimas.Window()
  win:move(10, 10)
  win:resize(50, 50)
  win:show()
  local label = mimas.Label("Hop", win)

  thread = lk.Thread(function()
    win = nil
    collectgarbage('collect')
    -- not deleted by Lua, but marked as deleted in C++
    -- proof that win was deleted in C++
    assertTrue(label:deleted())
  end)
end

function should.computeTextSize()
  local win = mimas.Window()
  assertEqual(78, win:textSize("Hello Lubyk!"))
end

test.all()
