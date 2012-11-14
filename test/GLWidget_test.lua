--[[------------------------------------------------------

  Basic tests for modern OpenGL window
  ------------------------------------

  This is for modern, shader based OpenGL.

--]]------------------------------------------------------
require 'lubyk'

local should = test.Suite('mimas.GLWidget')
local withUser = should:testWithUser()

function should.autoload()
  assertTrue(mimas.GLWindow)
end

function should.createGl3Context()
  local w = mimas.GLWindow()
  w:show() -- this creates the OpenGL
  local gl_version, glsl_version = w:openGLVersion()
  assertMatch('3.2', gl_version)
end


function withUser.should.callResizeCallback(t)
  t.win = mimas.GLWindow()
  t.win:move(10,10)
  t.win:resize(400,400)
  t.win:show()

  function t.win:resizeGL(w, h)
    t.continue = true
  end

  function t.win:resize(w, h)
    t.continue = true
  end

  t:timeout(function()
    return t.continue
  end)
  assertTrue(t.continue)
end

function should.acceptDestroyFromGui(t)
  t.win = mimas.GLWidget()
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
  local win = mimas.GLWindow()
  win:move(100, 240)
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

test.all()
