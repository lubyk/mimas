--[[------------------------------------------------------

  mimas.Application test
  ----------------------

  ...

--]]------------------------------------------------------
require 'lubyk'

local should = test.Suite('mimas.Application')
local withUser = should:testWithUser()

function should.autoCreateApp()
  -- load mimas
  assertTrue(mimas)
  assertType('table', app)
end

function withUser.should.changeCursor(t)
  local win = mimas.Window()
  win:move(10,10)
  win:resize(600,600)
  win:show()
  function win:click()
    t.continue = 'focus'
  end
  t:timeout(function()
    return t.continue == 'focus'
  end)
  -- Hide cursor
  app:hideCursor()

  function win:click()
    t.continue = 'hidden'
  end
  t:timeout(function()
    return t.continue == 'hidden'
  end)

  -- Wait cursor
  app:setCursor(mimas.WaitCursor)
  function win:click()
    t.continue = 'wait'
  end
  t:timeout(function()
    return t.continue == 'wait'
  end)

  -- Restore
  app:restoreCursor()

  function win:click()
    t.continue = 'restore'
  end
  t:timeout(function()
    return t.continue == 'restore'
  end)
  assertTrue(t.continue)
end

test.all()
