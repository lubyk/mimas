--[[------------------------------------------------------

  mimas.TabWidget
  ---------------

  A TabWidget displays widgets with tabs.

--]]------------------------------------------------------
local lib = mimas.TabWidget_core
mimas.TabWidget = lib

local new = lib.new
function lib.new(...)
  local self = new(...)
  self.tabs = {}
  return self
end

local function styleFix(self)
  -- FIXME: why doesn't the rule QTabBar::tab:first work with a
  -- single element ?
  if self:count() > 1 then
    self:setStyleSheet [[
    QTabBar::tab {
      margin-left:-1px;
    }
    QTabBar::tab:first {
      margin-left:0;
    }
    ]]
  else
    self:setStyleSheet [[
    QTabBar::tab {
      margin-left:0px;
    }
    ]]
  end
end

local addTab    = lib.addTab
local insertTab = lib.insertTab
function lib:addTab(widget, label)
  local pos = addTab(self, widget, label)
  self.tabs[pos] = widget
  --styleFix(self)
  return pos
end

function lib:insertTab(pos, widget, label)
  local pos = insertTab(self, pos, widget, label)
  self.tabs[pos] = widget
  --styleFix(self)
  return pos
end

function lib:currentWidget()
  local idx = self.super:currentIndex()
  if idx then
    return self.tabs[idx]
  end
end

lib.selectTab = lib.setCurrentIndex
local Key_Left, Key_Right = mimas.Key_Left, mimas.Key_Right
local Modifier = mimas.AltModifier
function lib:keyboard(key, on, chr, mod)
  -- FIXME: Why don't we capture keyPress of arrow keys ?
  -- FIXME: Why can't we capture ControlModifier with arrows ?
  if not on and bit.band(mod, Modifier) ~= 0 then
    if key == Key_Right then
      return self:selectTab(self:currentIndex() + 1)
    elseif key == Key_Left then
      return self:selectTab(self:currentIndex() - 1)
    end
  end
  -- Continue processing
  return true
end
