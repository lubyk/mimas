--[[------------------------------------------------------

  # Table view

  Display data in a grid. The view is connected to data by either setting
  a mimas.DataSource through #setModel or by providing the same callbacks
  as those available for mimas.DataSource. Here is a walkthrough of these
  callbacks with an example:

    local tv = mimas.TableView()
    local data = {
      head = {'first name', 'last name', 'profession'},
             {'György',     'Ligeti',    'Composer'},
             {'John',       'Click in the Cage',      'Composer'},
             {'Marina',     'Abramović', 'Perormance artist'},
             {'Damian',     'Marley',    'Musician'},
    }
    -- columnCount should return the number of colums in the data.
    function tv:columnCount()
      return #data.head
    end

    -- rowCount returns the number of rows.
    function t.view:rowCount()
      return #data
    end

    -- data provides data for the given row and column.
    function t.view:data(row, column)
      return data[row][column]
    end
  
    -- header provides horizontal and vertical headers.
    function t.view:header(section, orientation)
      if orientation == mimas.Horizontal then
        return data.head[section]
      else
        return nil
      end
    end

    -- Show the table view:
    tv:show()

--]]------------------------------------------------------
local lib = mimas.TableView_core
mimas.TableView = lib

local base_new = lib.new

local function new(...)
  local tv = base_new(...)
  local ds = mimas.DataSource()

  -- To ease a purely functional style, we pass calls to the
  -- DataSource (ds) directly to TableView (tv)
  -- TODO: move all this into DataSource.lua with a "delegate"
  -- field.
  function ds:header(...)   return tv:header(...)   end
  function ds:columnCount() return tv:columnCount() end
  function ds:rowCount()    return tv:rowCount()    end
  function ds:data(...)     return tv:data(...)     end
  function ds:editData(...)
    local f = tv.editData or tv.data
    return f(tv, ...)
  end
  function ds:tooltip(...)  return tv:tooltip(...)  end
  function ds:setData(...)  return tv:setData(...)  end
  function ds:flags(...)    return tv:flags(...)    end
  function ds:background(...)    return tv:background(...)    end
  function ds:foreground(...)    return tv:foreground(...)    end

  tv:setModel(ds)
  -- Prevent garbage collection
  tv.ds = ds
  return tv
end

-- Create a new mimas.TableView. If the optional `parent` widget is provided,
-- automatically add the table to this parent.
function lib.new(parent)
  if parent then
    return mimas.bootstrap(lib, new, parent)
  else
    return mimas.bootstrap(lib, new)
  end
end

-- # Callbacks
-- If #setModel is not used, the table view behaves in a functional way. Simply
-- define the callbacks and return the appropriate values.


-- Column count. The default implementation returns `1`.
function lib:columnCount()
  return 1
end

-- Row count. The default implementation returns `0`.
function lib:rowCount()
  return 0
end

-- Return data for the given `row` and `column` (1-based index). The default
-- implementation returns `nil` (= no value).
function lib:data(row, col)
  return nil
end

-- Return edit data for the given `row` and `column` (1-based index). The
-- default implementation calls #data.
-- function lib:editData(row, col)

-- Return tooltip data for the given `row` and `column` (1-based index). The
-- default implementation returns no value.
function lib:tooltip(row, col)
  return nil
end

-- Set data for the given `row` and `column` to `value`. This is called after
-- a cell has been edited (see #flags). Return `false` to refuse the
-- edit operation.
function lib:setData(row, col, value)
  -- noop
end


-- Return flags for the given data element identified by `row` and `column`
-- (1-based index). The default implementation returns `0` (= no flags).
--
-- See [mimas.ItemFlags](mimas.html#ItemFlags).
function lib:flags(row, col)
  return 0
end

-- Return header for the given `section` and `orientation`. If orientation is
-- `mimas.Horizontal`, *section* represents the column number, otherwise it
-- is the row number.
--
-- The default implementation returns `nil`.
function lib:header(section, orientation)
  return nil
end

local show = lib.show

-- Callback triggered when the user clicks on cell `(row, col)`. This callback
-- replaces #click. The return value defines if normal click processing occurs.
-- If the callback is not defined, use normal processing (same as returning
-- `true`).
--
-- FIXME: Remove if #selected works for all uses (it is confusing).
--
-- + `true`  : Continue normal click/select processing.
-- + `false` : Ignore event (bubble up to parent).
-- + `nil`   : No return value means that we have dealt with the event.
-- function lib:select(row, col)

-- Receive a click event. If #select callback is defined, this is not called.
-- See mimas.Widget.click for details.
-- function lib:click(x, y, op, btn, mod)

-- Called when a cell is selected or deselected. Currently only returns the
-- last selected cell or `nil` on deselection.
-- function lib:selected(row, col)

-- Return a size in pixel for the given column to help the view properly
-- size columns for the content. This is called when triggered by 
-- #resizeColumnsToContents.
-- function lib:sizeHintForColumn(col)

-- # Methods

-- Return `row` and `col` of the currently selected cell.
-- function lib:currentIndex()

-- Select a cell identified by `row` and `col`.
-- function lib:setCurrentIndex(row, col)


-- Show the table view.
function lib:show()
  -- We need to call reset because the first call to columnCount occurs on
  -- setModel in #new (= before callbacks are defined).
  self:reset()
  show(self)
end

-- Refresh view content. This must be called when the data changes.
function lib:reset()
  self.ds:reset()
end


-- ### C++ only methods

-- Turn headers on or off. `orientation` can be `mimas.Horizontal` or
-- `mimas.Vertical`.
-- function lib:setVisibleHeaders(orientation, visible)

-- Select which events start editing. By default, no action triggers an edit.
-- See [mimas.EditTriggers](mimas.html#EditTriggers) for a complete list of
-- triggering options. To allow editing simply use:
--
--   tv:setEditTriggers(mimas.AllEditTriggers)
--
-- function lib:setEditTriggers(triggers)

-- Show/hide grid (set style to `mimas.NoPenStyle` to hide). See
-- [mimas.PenStyles](mimas.html#PenStyles).
-- function lib:setGridStyle(style)

-- Select `row` (1-based index).
-- function lib:selectRow(row)

-- Select `column` (1-based index).
-- function lib:selectColumn(column)

-- Start editing a cell. You can use this function to force editing a cell.
-- function lib:edit(row, column)
  lib.edit = lib.do_edit

-- Scroll to the bottom of the table.
-- function lib:scrollToBottom()

-- Scroll to the top of the table.
-- function lib:scrollToTop()

-- Use alternating colors in the table if `enable` is true. The alternate color used is the CSS key
-- `alternate-background-color`.
-- function lib:setAlternatingRowColors(enable)

-- Show or hide grid.
-- function lib:setShowGrid(enable)

-- Resize columns to fit current content.
-- function lib:resizeColumnsToContents()

-- Stretch last horizontal cells.
-- function lib:setStretchHorizontal(enable)

-- Stretch last vertical cells.
-- function lib:setStretchHorizontal(enable)

-- Show/hide horizontal header.
-- function lib:setShowHorizontalHeader(enable)

-- Show/hide vertical header.
-- function lib:setShowVerticalHeader(enable)

-- # Widget methods
-- TableView inherits all methods from mimas.Widget.
