--[[------------------------------------------------------

  Basic tests for lubyk GUI
  -------------------------

  This tests multi-threading and event posting / triggering.
  We cannot trigger these tests with other tests because Qt
  does not like beeing started and stopped multiple times.

--]]------------------------------------------------------
require 'lubyk'
Lubyk.mimas_quit_on_close = false

local should   = test.Suite('mimas.Widget')
local withUser = should:testWithUser()

--==================== Widget sub-class example =======

-- This is how you create a sub-class of mimas.Widget
local lib = lk.SubClass(mimas.Widget)
lib.type  = 'test.MyWidget'
MyWidget  = lib

function lib:init(name)
  self.name = name
end

-- custom paint
function lib:paint(p, w, h)
  local box_padding = 5
  local hpen_width = 2 -- half pen width
  local bp = hpen_width + box_padding -- full box padding
  local arc_radius = 15
  local text_padding = 20
  local pen = mimas.Pen(hpen_width * 2, mimas.Color(0.2, 0.8, 0.8, 0.8))
  pen:setStyle(mimas.DashLine)
  p:setBrush(mimas.Color(0.5, 0.5, 0.5))
  p:setPen(pen)
  p:drawRoundedRect(bp, bp, w + arc_radius + bp, h - 2 * bp, arc_radius)
  p:drawText(text_padding, text_padding, w - 2*text_padding, h - 2*text_padding, mimas.AlignCenter, self.name)
end

--=====================================================

function withUser.should.centerWidget(t)
  t.win = mimas.Window()
  t.win:setStyle 'background:transparent'
  t.lay = mimas.VBoxLayout(t.win)
  t.lbl = mimas.Label("This should be centered")
  t.win:resize(300,200)
  t.win:center()
  t.lbl:setStyle "color:#fee; text-align:center; background:orange"
  t.lay:addWidget(t.lbl)
  t.win:show()
  function t.win:click()
    t.continue = true
  end

  t:timeout(function()
    return t.continue
  end)
  t.win:close()
end

function should.showWindow(t)
  t.win = mimas.Window()
  t.win:show()
  sleep(100)
  t.win:close()
  assertTrue(true)
end

function withUser.should.addWidgetsToWindow(t)
  t.win = mimas.Window()
  t.lay = mimas.VBoxLayout(t.win)
  t.wid1 = MyWidget('Hello')
  t.lay:addWidget(t.wid1)
  t.wid2 = MyWidget('Lubyk')
  t.lay:addWidget(t.wid2)
  t.win:move(10, 10)
  t.win:resize(400, 400)
  t.win:show()

  function t.win:click()
    t.continue = true
    t.win:close()
  end

  t:timeout(function()
    return t.continue
  end)
end

local function opName(op)
  if op == mimas.MousePress then
    return 'MousePress'
  elseif op == mimas.MouseRelease then
    return 'MouseRelease'
  elseif op == mimas.DoubleClick then
    return 'DoubleClick'
  else
    return '???'
  end
end

local function modName(mod)
  if mod == mimas.NoModifier then
    return 'NoModifier'
  elseif mod == mimas.ShiftModifier then
    return 'ShiftModifier'
  elseif mod == mimas.ControlModifier then
    return 'ControlModifier'
  elseif mod == mimas.AltModifier then
    return 'AltModifier'
  elseif mod == mimas.MetaModifier then
    return 'MetaModifier'
  elseif mod == mimas.KeypadModifier then
    return 'KeypadModifier'
  elseif mod == mimas.GroupSwitchModifier then
    return 'GroupSwitchModifier'
  else
    return '???'
  end
end

function should.respondToClick(t)
  -- we use the test env to protect from gc
  t.win = mimas.Window()
  function t.win:click(x, y, op, btn, mod)
    t.continue = true
  end

  t.lay = mimas.VBoxLayout(t.win)
  t.label = mimas.Label('Click on window (not on me, press ESC to close)')
  t.lay:addWidget(t.label)
  t.win:move(10, 10)
  t.win:resize(400, 400)
  t.win:show()
  -- Simulate user click at local pos 10, 10
  app:click(t.win, 10, 10)
  assertTrue(t.continue)
  t.win:close()
end

--[[
function withUser.should.openFileDialog(t)
  local path = lk.scriptPath()
  local basedir, filename = lk.pathDir(path)
  t.win = mimas.Window()
  t.win:show()
  assertMatch(path..'$', t.win:getOpenFileName(string.format('Select "%s"', filename), basedir, 'Lua files (*.lua)'))
  t.win:close()
end

function withUser.should.getExistingDirectory(t)
  local path = lk.pathDir(lk.scriptPath())
  local basedir, dirname = lk.pathDir(path)
  t.win = mimas.Window()
  t.win:show()
  assertMatch(path..'$', t.win:getExistingDirectory(string.format('Select "%s"', dirname), basedir))
  t.win:close()
end
--]]

function withUser.should.callbackOnClose(t)
  t.win = mimas.Window()
  t.lay = mimas.VBoxLayout(t.win)
  t.lbl = mimas.Label('Close window.')
  t.lay:addWidget(t.lbl)
  function t.win:closed()
    t.continue = true
  end
  t.win:resize(100,100)
  t.win:move(10,10)
  t.win:show()
  t:timeout(function()
    return t.continue
  end)
  assertTrue(t.continue)
end

function withUser.should.showContextualMenu(t)
  t.win = mimas.Window()
  t.lay = mimas.VBoxLayout(t.win)
  t.lbl = mimas.Label('Ctrl-click for contextual menu.')
  t.lay:addWidget(t.lbl)
  function t.win:click(x, y, typ, btn)
    if btn == mimas.RightButton then
      t.menu = mimas.Menu()
      t.menu:addAction('Select me', '', function()
        t.continue = true
      end)
      t.menu:addAction('Ignore me', '', function()
      end)
      local gx, gy = self:globalPosition()
      t.menu:popup(gx + x, gy + y)
    end
  end
  t.win:resize(100,100)
  t.win:move(10,10)
  t.win:show()
  t:timeout(function()
    return t.continue
  end)
  t.win:close()
  assertTrue(t.continue)
end

-- Qt cannot pass events 'down'. This cannot work.
-- function withUser.should.passClick(t)
--   t.win = mimas.Window()
--   t.lbl = mimas.Label('Click on bar above btn', t.win)
--   t.lbl:show()
--   t.lbl:move(10, 10)
--   t.btn = mimas.Button('click me', function()
--     t.lbl:setText('Click on btn')
--     t.continue = true
--   end)
--   t.win:addWidget(t.btn)
--   t.btn:move(50, 50)
--   t.top = mimas.Widget()
--   t.win:addWidget(t.top)
--   t.top:move(60, 50)
--   function t.top:paint(p, w, h)
--     p:fillRect(0, 0, w, h, mimas.Color(0.3,1,1,0.3))
--   end
--   t.top:resize(40, 200)
--   function t.top:click()
--     t.lbl:setText('Click on bar')
--     return false -- we want to ignore the event so that it is passed down.
--   end
--   t.win:resize(200,300)
--   t.win:move(10,10)
--   t.win:show()
--   t:timeout(function()
--     return t.continue
--   end)
--   t.win:close()
--   assertTrue(t.continue)
-- end

function withUser.should.captureKeyboard(t)
  t.win = mimas.Window()
  t.lay = mimas.VBoxLayout(t.win)
  t.lbl = mimas.Label('Pres key "d".')
  t.lay:addWidget(t.lbl)
  function t.win:keyboard(key, on, chr, mod)
    t.lbl:setText(string.format('key=%i, on=%s, chr=%s, mod=%i', key, (on and 'on') or 'off', chr, mod))
    if chr == 'd' then
      t.continue = true
    end
  end
  t.win:resize(400,100)
  t.win:move(10,10)
  t.win:show()
  t:timeout(function()
    return t.continue
  end)
  t.win:close()
  assertTrue(t.continue)
end

function should.captureErrors()
  local win = mimas.Widget()
  local err_msg

  function win:click()
    error('Some bad message')
  end

  function win:error(msg)
    err_msg = msg
  end

  app:click(win)
  assertMatch('test/Widget_test.lua:%d+: Some bad message', err_msg)
end

function should.acceptDestroyFromGui(t)
  t.win = mimas.Widget()
  t.win:move(10, 10)
  t.win:resize(50, 50)
  t.win:show()

  sleep(200)
  t.win:close()
  sleep(200)
  assertTrue(t.win:deleted())
end

function should.acceptDestroyFromLua()
  local win = mimas.Widget()
  win:move(10, 10)
  win:resize(50, 50)
  win:show()
  local label = mimas.Label("Hop", win)

  win = nil
  collectgarbage('collect')
  -- not deleted by Lua, but marked as deleted in C++
  -- proof that win was deleted in C++
  assertTrue(label:deleted())
end

test.all()
