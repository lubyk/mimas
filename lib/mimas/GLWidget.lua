--[[------------------------------------------------------

  mimas.GLWidget
  --------------

  A context to draw modern OpenGL content.

--]]------------------------------------------------------
local lib = mimas.GLWidget_core
mimas.GLWidget = lib

local DEFAULT_OPTIONS = 0 +
  lib.AlphaChannel  +
  lib.DoubleBuffer  +
  lib.DepthBuffer   +
  --lib.Rgba          +
  --lib.SampleBuffers +
  --lib.StereoBuffers +
  0

local orig_new = lib.new
-- This will become "lib.new" after bootstrap.
local function new(options)
  return orig_new(options or DEFAULT_OPTIONS)
end

function lib.new(options)
  return mimas.bootstrap(lib, new, options)
end

function lib:center()
  local w, h = app:screenSize()
  local sw, sh = self:size()
  self:move((w - sw) / 2, (h - sh) / 2)
end

