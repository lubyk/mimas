--[[------------------------------------------------------

  mimas.Button test
  -----------------

  ...

--]]------------------------------------------------------
require 'lubyk'

local should = test.Suite('mimas.Button')

function should.connectToCallback(t)
  t.win = mimas.Window()
  t.win:move(100, 100)
  t.win:resize(200,200)

  t.btn = mimas.Button("click me", t.win)
  t.btn:move(40, 10)
  local callback = mimas.Callback(function()
    t.clicked = true
  end)
  callback:connect(t.btn, 'clicked')
  callback = nil
  collectgarbage('collect')
  collectgarbage('collect')
  -- should not remove the callback because it is saved with
  -- the button's env
  t.btn2 = mimas.Button('ignore me')
  t.win:addWidget(t.btn2)
  t.btn2:move(40,40)
  t.win:show()
  -- Simulate user click on t.win at pos 45, 15
  app:click(t.btn)
  assertTrue(t.clicked)
end

function should.createWithFunction(t)
  t.win = mimas.Window()
  t.win:move(200, 200)
  t.win:resize(200,200)
  t.lay = mimas.HBoxLayout(t.win)
  local btn = mimas.Button("click me too", function()
    t.continue = true
  end)
  t.lay:addWidget(btn)
  t.win:show()
  app:click(btn)
  assertTrue(t.continue)
  t.win:close()
end

function should.styleButtons(t)
  t.win = mimas.Window()
  t.win:move(100, 400)
  t.win:resize(200,200)
  t.lay = mimas.VBoxLayout(t.win)

  -- can use rgb(), rgba(), hsv(), hsva() or #00FA88 (caps)
  local tests = {
    '.button {color:#EAA844}',
    '.button {border: 3px solid #EAA844; border-radius:5}',
    '.button {background-color: hsva(80, 255, 255, 40%)}',
    '.button:hover {background:#EAA844}'
  }

  for _, style_test in ipairs(tests) do
    local lbl = mimas.Button(string.format("setStyle: %s", style_test))
    t.lay:addWidget(lbl)
    lbl:setStyleSheet(style_test)
    -- avoid GC
    t[style_test] = lbl
  end
  t.win:show()
  t.timeout = lk.Thread(function()
    sleep(3000)
    t.win:close()
  end)
end

test.all()
