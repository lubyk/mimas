--[[------------------------------------------------------

  mimas.GroupBox test
  -------------------

  ...

--]]------------------------------------------------------
require 'lubyk'

local should = test.Suite('mimas.GroupBox')

function should.autoload()
  assertTrue(mimas.GroupBox)
end

function should.displayGroupBox(t)
  t.win = mimas.GroupBox('Hello')
  t.lay = t.win
  t.lay = mimas.VBoxLayout(t.win)
  t.lay:addStretch()
  t.btn = mimas.Button('click if ok')
  t.lay:addWidget(t.btn)
  t.win:show()
  function t.btn:click(x, y)
    t.continue = true
  end

  t:timeout(function(elapsed)
    if elapsed > 2000 then
      app:click(t.btn)
    end
    return t.continue
  end)
  t.win:close()
  assertTrue(t.continue)
end
test.all()

