--[[------------------------------------------------------

  # GUI Widget class

  This is the basic empty view class for the GUI.

--]]------------------------------------------------------
local lib     = mimas.Widget_core
mimas.Widget  = lib
-- We use this from C++. Make sure it is loaded to use the
-- Lua changes before being used.
require 'mimas.Menu'

local new = lib.new

-- Create a new mimas.Widget. Optional arguments are:
--
-- + `(parent)`         : Insert the widget in a parent widget.
-- + `(parent, flags)`  : Insert in a parent and set flags.
-- + `(flags)`          : Set flags.
--
-- The flags are used for mimas.Window (an alias for this class) and correspond
-- to:
function lib.new(...)
  return mimas.bootstrap(lib, new, ...)
end

-- # Callbacks
-- These callbacks are common to all widgets.

-- Receive a click event at position `(x,y)` relative to the widget. Arguments
-- are:
--
-- + `x, y`  : click position relative to widget in pixels.
-- + `op`    : click type: mimas.MousePress, mimas.MouseRelease, mimas.DoubleClick.
-- + `mod`   : special keyboard key (see [KeyboardModifiers](mimas.html#KeyboardModifiers).
--
-- The return value defines if normal click processing occurs. If the callback
-- is not defined, use normal processing (same as returning `true`)
--
-- + `true`  : Continue normal click processing (normal widget implementation).
-- + `false` : Ignore event (bubble up to parent).
-- + `nil`   : No return value means that we have dealt with the event.
-- function lib:click(x, y, op, btn, mod)

-- A keyboard event was captured by this widget.
-- + `key`   : A number representing the key [mimas.Key](mimas.html#Key).
-- + `on`    : True if the key is depressed, false if released.
-- + `chr`   : A string representing the Utf-8 character.
-- + `mod`   : special keyboard key (see [KeyboardModifiers](mimas.html#KeyboardModifiers).
--
-- The return value defines if normal key processing occurs. If the callback
-- is not defined, use normal processing (same as returning `true`)
-- + `true`  : Continue normal keyboard processing (normal widget implementation).
-- + `false` : Ignore event (bubble up to parent).
-- + `nil`   : No return value means that we have dealt with the event.
-- function lib:keyboard(key, on, chr, mod)

--=============================================== COPY CODE TO GLWidget
--local close  = lib.close
--function lib:close()
--  if self:deleted() then
--    return false
--  else
--    close(self)
--    return true
--  end
--end

function lib:center()
  -- WARNING: global 'app' used here
  local w, h = app:screenSize()
  local sw, sh = self:size()
  self:move((w - sw) / 2, (h - sh) / 2)
end

--=============================================== dialog (maybe we should have
--                                                        this in GLWidget too)

local getOpenFileName = lib.getOpenFileName

function lib:getOpenFileName(caption, base_dir, filter, options)
  return getOpenFileName(self, caption, base_dir or '', filter or '', options or 0)
end

local getExistingDirectory = lib.getExistingDirectory
function lib:getExistingDirectory(caption, base_dir, options)
  return getExistingDirectory(self, caption, base_dir or '', options or mimas.ShowDirsOnly)
end
