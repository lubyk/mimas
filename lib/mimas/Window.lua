--[[------------------------------------------------------

  # GUI Window

  This is an alias for mimas.Widget. It should be used to create windows.

--]]------------------------------------------------------
require 'mimas.Widget'
mimas.Window = mimas.Widget


-- Create a new mimas.Window. Optional arguments are:
--
-- + `(parent)`         : Insert the window in a parent widget.
-- + `(parent, flags)`  : Insert in a parent and set [window flags](mimas.html#WindowFlags).
-- + `(flags)`          : Set [window flags](mimas.html#WindowFlags).
--
--
-- Flags usage example. From top-left to bottom-right:
--
-- * [mimas.DrawerFlag](mimas.html#WindowFlags)
-- * [mimas.SheetFlag](mimas.html#WindowFlags)
-- * [mimas.WindowFlag](mimas.html#WindowFlags)
-- * [mimas.ToolFlag](mimas.html#WindowFlags)
--
-- ![window examples](img/mimas_WindowFlags.png)
-- function lib.new(...)
