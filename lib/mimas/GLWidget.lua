--[[------------------------------------------------------

  mimas.GLWidget
  --------------

  A context to draw modern OpenGL content.

--]]------------------------------------------------------
local lib = mimas.GLWidget_core
mimas.GLWidget = lib

local new = lib.new
function lib.new(...)
  return mimas.bootstrap(lib, new, ...)
end

-- local close  = lib.close
-- function lib:close()
--   if self:deleted() then
--     return false
--   else
--     close(self)
--     return true
--   end
-- end

function lib:center()
  local w, h = app:screenSize()
  local sw, sh = self:size()
  self:move((w - sw) / 2, (h - sh) / 2)
end

--=============================================== DEFAULT METHODS
function lib:initializeGL()
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

function lib:resizeGL(w, h)
  self.w = w
  self.h = h
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
  w / h,   -- Aspect ration
  1,                -- zNear
  100               -- zFar
  )
end

