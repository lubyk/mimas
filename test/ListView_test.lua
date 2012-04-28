--[[------------------------------------------------------

  Basic tests for ListView
  ------------------------

  ...

--]]------------------------------------------------------
require 'lubyk'
local should = test.Suite('mimas.ListView')
local withUser = should:testWithUser()
local data = {'György', 'John', 'Marina', 'Damian'}

function should.displayList(t)
  t.view = mimas.ListView()

  function t.view:rowCount()
    return #data
  end

  function t.view:data(row_i)
    return data[row_i]
  end

  t.view:show()
  t:timeout(500, function()
    return t.continue
  end)
  assertTrue(true)
end

function withUser.should.reloadOnClick(t)
  t.data = data
  t.win = mimas.Window()
  t.win:move(10,10)
  t.lay = mimas.VBoxLayout(t.win)
  t.view = mimas.ListView()
  t.lay:addWidget(t.view)

  function t.view:rowCount()
    return #t.data
  end

  function t.view:data(row_i)
    return t.data[row_i]
  end

  function t.view:select(row)
    assertEqual(2, row)
    t.continue = true
  end

  t.btn = mimas.Button('click to change')
  t.lay:addWidget(t.btn)
  function t.btn:click()
    t.data = {'cat', 'select me', 'mouse'}
    t.view:reset()
  end

  t.win:show()
  t:timeout(function()
    return t.continue
  end)
  t.win:close()
  assertTrue(t.continue)
end

function should.accessDataSource(t)
  t.view = mimas.ListView()
  assertType('table', t.view.ds)
end

function should.respondToClick(t)
  t.view = mimas.ListView()
  t.view:move(10,10)

  function t.view:rowCount()
    return #data
  end

  function t.view:data(row_i)
    return data[row_i]
  end

  function t.view:click(x, y)
    local i, j = t.view:indexAt(x, y)
    assertEqual(2, i)
  end

  function t.view:mouse(x, y)
    print('mouse', x, y)
  end

  t.view:show()
  t.thread = lk.Thread(function()
    sleep(200000)
    t.view:close()
    assertTrue(true)
  end)
end

function should.useDataSource(t)
  t.view = mimas.ListView()
  t.data = mimas.DataSource()

  function t.data:rowCount()
    return #data
  end

  function t.data:data(row)
    return data[row]
  end

  t.view:setModel(t.data)

  function t.view:select(row)
    assertTrue(2, row)
    t.view:close()
  end
  t.view:show()
end

test.all()

