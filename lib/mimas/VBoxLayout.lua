--[[------------------------------------------------------

  # Vertical stacking layout

  Organize widgets into a parent widget by stacking them vertically.

  WARN: You must keep hold of the widgets added to the layout because they
  are not "held" by the layout and will be garbage collected otherwise.

  Example:

    local win = mimas.Window()
    local layout = mimas.VBoxLayout(win)
    layout.btn1 = mimas.Button("Click here")
    layout:addWidget(layout.btn1)
    
    layout.btn2 = mimas.Button("Ignore")
    layout:addWidget(layout.btn2)  
    win:show()

--]]------------------------------------------------------
local lib = mimas.VBoxLayout_core
-- nodoc
lib.is_layout    = true
mimas.VBoxLayout = lib

-- Create a new mimas.VBoxLayout. Provide a `parent` widget that the layout
-- will fill. If no `parent` is provided, the layout is to be inserted in
-- another layout with #addWidget or #insertWidget.
-- function lib.new(parent)


local addWidget = lib.addWidget
local addLayout = lib.addLayout
-- Add a widget to the layout.
-- Use a larger `stretch` factor (default = 0) to stretch more then other
-- widgets. The `alignment` is a combinaison of
-- [mimas.Align](mimas.html#Align) flags. The default is 0 (fill entire cell).
function lib:addWidget(other, stretch, alignment)
  stretch = stretch     or 0
  alignment = alignment or 0
  if other.is_layout then
    -- this is a layout
    self:addLayout(other, stretch, alignment)
  else
    addWidget(self, other, stretch, alignment)
  end
end

local insertWidget = lib.insertWidget
-- Insert a widget at `pos` (1-based index) to the layout.
-- Use a larger `stretch` factor (default = 0) to stretch more then other
-- widgets. The `alignment` is a combinaison of
-- [mimas.Align](mimas.html#Align) flags. The default is 0 (fill entire cell).
--
-- You can use negative `pos` values to add at the end (`-1`), before the last
-- element (`-2`), etc.
function lib:insertWidget(pos, other, stretch, alignment)
  stretch = stretch     or 0
  alignment = alignment or 0
  if other.is_layout then
    -- sub layout
    self:insertLayout(pos, other, stretch, alignment)
  else
    insertWidget(self, pos, other, stretch, alignment)
  end
end

-- Add a strechable item (empty item for spacing).
-- Use a larger `stretch` factor (default = 0) to stretch more then other
-- widgets.
-- function lib:addStretch(stretch)

-- Add some fixed space of `size` pixels.
-- function lib:addSpacing(size)

-- Set the fixed spacing between items to `space`.
-- function lib:setSpacing(int space)

