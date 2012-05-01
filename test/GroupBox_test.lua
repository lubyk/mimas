--[[------------------------------------------------------

  mimas.GroupBox test
  -------------------

  ...

--]]------------------------------------------------------
require 'lubyk'

local should = test.Suite('mimas.GroupBox')
local withUser = should:testWithUser()

function should.autoload()
  assertTrue(mimas.GroupBox)
end

function withUser.should.displayGroupBox(t)
  t.win = mimas.Window()
  t.box = mimas.GroupBox('Hello')
  t.win:addWidget(t.box)
  t.box:move(10,10)
  t.lay = mimas.VBoxLayout(t.box)
  t.btn = mimas.Button('Push if OK')
  t.lay:addWidget(t.btn)
  t.win:show()
  function t.btn:click(x, y)
    t.continue = true
    t.win:close()
  end

  t:timeout(function()
    return t.continue
  end)
  assertTrue(t.continue)
end

function should.displayGroupBox(t)
  t.win = mimas.GroupBox('Hello')
  t.lay = t.win
  t.lay = mimas.VBoxLayout(t.win)
  t.lay:addStretch()
  t.btn = mimas.Button('click if ok')
  t.lay:addWidget(t.btn)
  t.win:show()
  t.win:close()
  assertTrue(true)
end

test.all()
