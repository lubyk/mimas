--[[------------------------------------------------------

  mimas.Timer
  -----------

  Simple timer.

--]]------------------------------------------------------
local lib = mimas.Timer_core
mimas.Timer = lib

local constr = lib.new
local function new(msec, func)
  local self = constr(msec)
  if func then
    self.timeout = func
  end
  return self
end

function lib.new(...)
  return mimas.bootstrap(lib, new, ...)
end

