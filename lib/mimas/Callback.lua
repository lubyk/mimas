--[[------------------------------------------------------

  mimas.Callback
  --------------

  GUI event callback (can be connected to widget signals).

--]]------------------------------------------------------
local lib    = mimas.Callback_core
local constr = lib.new
mimas.Callback = lib

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
  connect(self, other:object(), target, callback)
end

function lib:callback()
  print('dummy callback')
end

function lib.new(func)
  local self = constr()
  self.callback = func
  return self
end

