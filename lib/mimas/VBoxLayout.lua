--[[------------------------------------------------------

  mimas.VBoxLayout
  ----------------

  Vertical layout of GUI widgets.

--]]------------------------------------------------------
local constr      = mimas_core.VBoxLayout
local mt          = mimas_core.VBoxLayout_
mimas.VBoxLayout_ = mt

function mimas.VBoxLayout(parent)
  if parent then
    return constr(parent:widget())
  else
    return constr()
  end
end

local addWidget = mt.addWidget
local addLayout = mt.addLayout
function mt:addWidget(other, ...)
  if other.layout then
    -- sub layout
    addLayout(self, other:layout(), ...)
  else
    addWidget(self, other:widget(), ...)
  end
end

function mt:addLayout(other, ...)
  -- sub layout
  addLayout(self, other:layout(), ...)
end

local insertWidget = mt.insertWidget
local insertLayout = mt.insertLayout
function mt:insertWidget(pos, other, ...)
  if other.layout then
    -- sub layout
    insertLayout(self, pos, other:layout(), ...)
  else
    insertWidget(self, pos, other:widget(), ...)
  end
end

function mt:insertLayout(pos, other, ...)
  insertLayout(self, pos, other:layout(), ...)
end
