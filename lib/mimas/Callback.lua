--[[------------------------------------------------------

  mimas.Callback
  --------------

  GUI event callback (can be connected to widget signals).

--]]------------------------------------------------------
local lib    = mimas.Callback_core
mimas.Callback = lib

local connect = lib.connect
function lib:connect(other, target)
  local callback = nil
  if string.match(target, '%(double%)') then
    callback = '1callback(double)'
  elseif string.match(target, '%(int%)') then
    callback = '1callback(int)'
  else
    callback = '1callback()'
  end
  if not string.match(target, '%(') then
    target = string.format("2%s()", target)
  else
    target = string.format("2%s", target)
  end
  -- Make sure the callback lives as long as the target
  other[target] = self
  connect(self, other, target, callback)
end

function lib:callback()
  print('dummy callback')
end

local new = lib.new
function lib.new(func)
  local self = new()
  self.callback = func
  return self
end

