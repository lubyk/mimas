--[[------------------------------------------------------

  Basic tests for legacy OpenGL window
  ------------------------------------

  This is for direct-mode OpenGL. Please look at GLSLWindow
  for the modern approach.

--]]------------------------------------------------------
require 'lubyk'

local should = test.Suite('mimas.LegacyGLWidget')
local withUser = should:testWithUser()

function withUser.should.displayGlWindow(t)
  -- we use the test env to protect from gc
  t.win = mimas.LegacyGLWidget()
  t.win:move(300,300)
  t.win:resize(400,400)
  function t.win:initializeGL()
    gl.Enable("POINT_SMOOTH")
    gl.Enable("SMOOTH")
    gl.Enable("BLEND")                                -- Enable alpha blending
    gl.BlendFunc("SRC_ALPHA", "ONE_MINUS_SRC_ALPHA")  -- Set blend function

    gl.ClearDepth(1.0)
    gl.DepthFunc("LEQUAL");

    -- gl.Enable('GL_CULL_FACE')
    -- gl.Enable('GL_DEPTH_TEST')

    gl.Hint("PERSPECTIVE_CORRECTION_HINT", "NICEST") -- Really nice perspective
    gl.ClearColor(0.2,0.2,0.2,0.5)
  end

  function t.win:resizeGL(width, height)
    gl.Enable("BLEND")
    --gl.Disable("DEPTH_TEST")
    gl.BlendFunc("SRC_ALPHA", "ONE_MINUS_SRC_ALPHA")

    gl.Enable("LINE_SMOOTH")
    -- Select the projection matrix
    gl.MatrixMode("PROJECTION")
    -- reset
    gl.LoadIdentity()
    -- Calculate the aspect ratio of the view
    glu.Perspective(
      45,               -- Field of view angle
      width / height,   -- Aspect ration
      1,                -- zNear
      100               -- zFar
    )
  end
  t.n = 0
  t.x = 0
  t.y = 0
  t.z = 0
  t.dt = (math.pi / 100)
  t.last = elapsed()

  t.fps  = 0
  local AVG = 100
  local function computeFps(now)
    local fps = 1000 / (now - t.last)
    t.fps = (AVG * t.fps + fps) / (AVG+1)
    return t.fps
  end

  t.label = mimas.Label('fps: 0.000')
  local function animate(now)
    local dt = (now - t.last) * t.dt
    t.n = t.n + t.dt
    t.x = math.cos(t.n / 0.9) * 180 / math.pi
    t.y = math.sin(t.n / 0.7) * 180 / math.pi
    t.z = math.sin(t.n) * 180 / math.pi
    t.label:setText(string.format('fps: %.2f', computeFps(now)))
    t.last = now
  end

  function t.win:paintGL()
    animate(elapsed())
    gl.Clear( "COLOR_BUFFER_BIT, DEPTH_BUFFER_BIT")
    gl.MatrixMode("MODELVIEW")
    gl.LoadIdentity()

    gl.Translate(0.0, 0.0, -6.0)

    gl.Rotate(t.x, 1.0, 0.0, 0.0)
    gl.Rotate(t.y, 0.0, 1.0, 0.0)
    gl.Rotate(t.z, 0.0, 0.0, 1.0)

    gl.Color(0.5,0.5,0.0,0.3)
    gl.LineWidth(1.0)
    glut.WireCube(2.6)

    gl.Color(0.5,0.5,0.0,0.1)
    glut.SolidCube(2.6)
    t.win:update()
  end

  t.btn = mimas.Button('Push if OK', function()
    t.continue = true
    t.win:hide()
  end)
  t.win:addWidget(t.btn, 10, 10)

  t.shape = mimas.Widget()
  t.shape:addWidget(t.label)
  t.label:move(17, 40)
  t.win:addWidget(t.shape, 100, 100)
  t.shape:resize(100, 100)
  function t.shape:paint(p, w, h)
    p:setBrush(mimas.Color(0, 0.8, 0.8, 0.3))
    p:setPen(3, mimas.Color(0.3, 0.8, 0.8, 0.5))
    p:drawRoundedRect(5, 5, 90, 90, 10, 10)
  end
  t.shape:setStyle('background:transparent')

  t.win:resize(300,300)
  t.win:show()
  t:timeout(function()
    return t.continue
  end)
  assertTrue(t.continue)
end

function should.acceptDestroyFromGui(t)
  t.win = mimas.LegacyGLWidget()
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
  local win = mimas.LegacyGLWindow()
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
