--[[------------------------------------------------------

  Basic tests for TableView
  -------------------------

  ...

--]]------------------------------------------------------
require 'lubyk'
local should = test.Suite('mimas.TableView')
local withUser = should:testWithUser()

local data = {
  head={'first name', 'last name', 'profession'},
       {'György',     'Ligeti',    'Composer'},
       {'John',       'Click in the Cage',      'Composer'},
       {'Marina',     'Abramović', 'Perormance artist'},
       {'Damian',     'Marley',    'Musician'},
}

function should.loadCode()
  assertTrue(mimas.TableView)
end

function withUser.should.displayTable(t)
  t.view = mimas.TableView()
  t.view:move(10,10)
  t.view:setAlternatingRowColors(true)
  t.view:setVisibleHeaders(mimas.Vertical, false)
  t.view:setGridStyle(mimas.NoPenStyle)

  function t.view:columnCount()
    return #data.head
  end

  function t.view:rowCount()
    return #data
  end

  function t.view:data(row_i, column_i)
    local row = data[row_i]
    if row then
      return row[column_i]
    else
      return nil
    end
  end

  function t.view:header(column_i, orientation)
    if orientation == mimas.Horizontal then
      return data.head[column_i]
    else
      return nil
    end
  end

  function t.view:select(row, col)
    if row == 2 and col == 2 then
      t.continue = true
    end
  end

  -- We must do this because the column count is cached on the first
  -- call which occurs during 'setModel' (in mimas.TableView()).
  t.view:reset()
  t.view:show()

  t:timeout(function()
    return t.continue
  end)
  assertTrue(t.continue)
  t.view:close()
end

function should.respondToUpdate(t)
  t.view = mimas.TableView()
  t.view:show()
  assertPass(function()
    t.view:update()
  end)
  t.view:close()
end
test.all()

