--[[------------------------------------------------------

  mimas.CheckBox test
  -------------------

  This tests multi-threading and event posting / triggering.
  We cannot trigger these tests with other tests because Qt
  does not like beeing started and stopped multiple times.

--]]------------------------------------------------------
require 'lubyk'

local should = test.Suite('mimas.CheckBox')
local withUser = should:testWithUser()

function should.connectToCallback(t)
  t.win = mimas.Window()
  t.win:move(10, 10)
  t.win:resize(200,200)

  t.btn = mimas.CheckBox("btn", t.win)
  local callback = mimas.Callback(function()
    t.continue = true
  end)

  t.btn2 = mimas.CheckBox('btn2')
  t.btn2:setCheckable(false)
  t.win:addWidget(t.btn2)
  t.btn2:move(40,40)
  callback:connect(t.btn, 'clicked')
  callback = nil
  collectgarbage('collect')
  -- should not remove the callback because it is saved with
  -- the button's env
  t.win:show()
  app:click(t.btn)
  t.win:close()
  assertTrue(t.continue)
end

function should.createWithFunction(t)
  t.win = mimas.Window()
  t.win:move(10, 10)
  t.win:resize(200,200)
  t.lay = mimas.HBoxLayout(t.win)
  local btn = mimas.CheckBox("btn", function(b, state)
    t.continue = not state
  end)
  btn:setChecked(true)
  t.lay:addWidget(btn)
  t.win:show()
  app:click(btn)
  t.win:close()
  assertTrue(t.continue)
end

function withUser.should.styleCheckBoxs(t)
  t.win = mimas.Window()
  t.win:move(10, 10)
  t.win:resize(200,200)
  t.lay = mimas.VBoxLayout(t.win)
  t.btn = mimas.Button('Push if OK', function()
    t.continue = true
  end)
  t.lay:addWidget(t.btn)

  -- can use rgb(), rgba(), hsv(), hsva() or #00FA88 (caps)
  local tests = {
    'CheckBox {color:#EAA844}',
    'CheckBox {border: 3px solid #EAA844; border-radius:5}',
    'CheckBox {background-color: hsva(80, 255, 255, 40%)}',
    'CheckBox:hover {background:#EAA844}'
  }

  for _, style_test in ipairs(tests) do
    local lbl = mimas.CheckBox(string.format("setStyle: %s", style_test))
    t.lay:addWidget(lbl)
    lbl:setStyleSheet(style_test)
    -- avoid GC
    t[style_test] = lbl
  end
  t.win:show()
  t:timeout(function()
    return t.continue
  end)
  t.win:close()
end

test.all()

