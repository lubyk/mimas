--[[------------------------------------------------------

  mimas
  -----

  Portable GUI scripted in Lua and compatible with Lubyk.

--]]------------------------------------------------------
mimas = Autoload('mimas', mimas)
require 'mimas.core'

--=============================================== app
app = mimas.Application()
if rawget(_G, 'test') then
  app:setQuitOnLastWindowClosed(false)
end

--=============================================== scheduler
-- First calls to Window creation in mimas should
-- yield so that the mimas scheduler can start
function mimas.bootstrap(base, func, ...)
  if sched.mimas then
    -- already running mimas
  else
    -- restart with mimas scheduler
    if coroutine.running() then
      coroutine.yield('mimas')
    end
  end
  -- Replace bootstrapping constructor by original
  -- function for further calls.
  base.new = func
  return func(...)
end

mimas.WhitePen   = mimas.Pen(1, 0, 0, 1)
mimas.WhiteBrush = mimas.Brush(0, 0, 1)
mimas.BlackPen   = mimas.Pen(1, 0, 0, 0)
mimas.BlackBrush = mimas.Brush(0, 0, 0)

mimas.NoPen   = mimas.Pen()
mimas.NoBrush = mimas.Brush()

mimas.colors = {
  Black     = mimas.Color(0, 0, 0),
  LightGrey = mimas.Color(0, 0, 0.75),
  Grey      = mimas.Color(0, 0, 0.5),
  DarkGrey  = mimas.Color(0, 0, 0.25),
  White     = mimas.Color(0, 0, 1),
  Red       = mimas.Color(0   / 360),
  Orange    = mimas.Color(33  / 360),
  Yellow    = mimas.Color(60  / 360),
  Green     = mimas.Color(120 / 360),
  Blue      = mimas.Color(240 / 360),
  Pink      = mimas.Color(300 / 360),
  Purple    = mimas.Color(275 / 360),
}

