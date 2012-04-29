--[[------------------------------------------------------

  mimas.VBoxLayout
  ----------------

  Vertical layout of GUI widgets.

--]]------------------------------------------------------
local lib = mimas.VBoxLayout_core
lib.is_layout    = true
mimas.VBoxLayout = lib

local addWidget = lib.addWidget
local addLayout = lib.addLayout
function lib:addWidget(other, ...)
  if other.is_layout then
    -- this is a layout
    self:addLayout(other, ...)
  else
    addWidget(self, other, ...)
  end
end

local insertWidget = lib.insertWidget
function lib:insertWidget(pos, other, ...)
  if other.is_layout then
    -- sub layout
    self:insertLayout(pos, other, ...)
  else
    insertWidget(self, pos, other, ...)
  end
end

