--[[------------------------------------------------------

  mimas.Button test
  -----------------

  ...

--]]------------------------------------------------------
require 'lubyk'

local should = test.Suite('mimas.Button')
local withUser = should:testWithUser()

function should.connectToCallback(t)
  t.win = mimas.Window()
  t.win:move(10, 10)
  t.win:resize(50,50)

  t.btn = mimas.Button("btn", t.win)
  t.btn:move(40, 10)
  local callback = mimas.Callback(function()
    t.clicked = true
    t.win:hide()
  end)
  callback:connect(t.btn, 'clicked')
  callback = nil
  collectgarbage('collect')
  collectgarbage('collect')
  -- should not remove the callback because it is saved with
  -- the button's env
  t.win:show()
  -- Simulate user click on t.btn
  app:click(t.btn)
  assertTrue(t.clicked)
end

function should.createWithFunction(t)
  t.win = mimas.Window()
  t.win:move(10, 10)
  t.win:resize(50,50)
  t.lay = mimas.HBoxLayout(t.win)
  local btn = mimas.Button("btn", function()
    t.continue = true
    t.win:hide()
  end)
  t.lay:addWidget(btn)
  t.win:show()
  app:click(btn)
  assertTrue(t.continue)
end

function withUser.should.styleButtons(t)
  t.win = mimas.Window()
  t.win:move(100, 400)
  t.win:resize(200,200)
  t.lay = mimas.VBoxLayout(t.win)
  t.btn = mimas.Button('Push if OK')
  function t.btn:click()
    t.continue = true
    t.win:hide()
  end
  t.lay:addWidget(t.btn)

  -- can use rgb(), rgba(), hsv(), hsva() or #00FA88 (caps)
  local tests = {
    'Button {color:#EAA844}',
    'Button {border: 3px solid #EAA844; border-radius:5}',
    'Button {background-color: hsva(80, 255, 255, 40%)}',
    'Button:hover {background:#EAA844}'
  }

  for _, style_test in ipairs(tests) do
    local lbl = mimas.Button(string.format("setStyle: %s", style_test))
    t.lay:addWidget(lbl)
    lbl:setStyleSheet(style_test)
    -- avoid GC
    t[style_test] = lbl
  end
  t.win:show()
  t:timeout(function()
    return t.continue
  end)
  assertTrue(t.continue)
end

test.all()
