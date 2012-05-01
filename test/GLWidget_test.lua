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

function should.compile(t)
  t.win = mimas.GLWindow()
  t.win:move(10,10)
  t.win:resize(400,400)
  t.win:show()

  assertTrue(t.win:compile(
-- Vertex shader
[=[
#version 150
layout(location=0) in vec4 in_Position;
layout(location=1) in vec4 in_Color;
out vec4 ex_Color;

void main(void)
{
  gl_Position = in_Position;
  ex_Color = in_Color;
}
]=],

-- Fragment shader
[=[
#version 150
 
in vec4 ex_Color;
out vec4 out_Color;
 
void main(void)
{
  out_Color = ex_Color;
}
]=]
  ))
  t.win:close()
end     

function withUser.should.displayGlWindow(t)
  t.win = mimas.GLWindow()
  t.win:move(10,10)
  t.win:resize(400,400)
  t.win:show()

  t.win:compile(
-- Vertex shader
[=[
#version 150
layout(location=0) in vec4 in_Position;
layout(location=1) in vec4 in_Color;
out vec4 ex_Color;

void main(void)
{
  gl_Position = in_Position;
  ex_Color = in_Color;
}
]=],

-- Fragment shader
[=[
#version 150
 
in vec4 ex_Color;
out vec4 out_Color;
 
void main(void)
{
  out_Color = ex_Color;
}
]=]
  )
  function t.win:click()
    t.continue = true
  end

  t:timeout(function()
    return t.continue
  end)
  t.win:hide()
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
