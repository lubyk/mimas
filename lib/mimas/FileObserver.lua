--[[------------------------------------------------------

  mimas.Label
  -----------

  ...

--]]------------------------------------------------------
local lib          = mimas.FileObserver_core
mimas.FileObserver = lib

local addPath = lib.addPath
function lib:addPath(path)
  path = lk.absolutizePath(path)
  if not self.paths[path] then
    addPath(self, path)
    self.paths[path] = true
  end
end

local removePath = lib.removePath
function lib:removePath(path)
  path = lk.absolutizePath(path)
  if self.paths[path] then
    removePath(self, path)
    self.paths[path] = nil
  end
end

local constr = lib.new
function lib.new(file_or_files)
  local self = constr()
  self.paths = {}
  if file_or_files then
    if type(file_or_files) == 'table' then
      for file in ipairs(file_or_files) do
        self:addPath(file)
      end
    else
      self:addPath(file_or_files)
    end
  end
  return self
end

