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
  t.view:move(10,10)

  function t.view:rowCount()
    return #data
  end

  function t.view:data(row_i)
    t.continue = true
    return data[row_i]
  end

  t.view:show()
  while not t.continue do
    sleep(200)
  end
  assertTrue(t.continue)
  t.view:close()
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

  t.btn = mimas.Button('Click to change')
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

function withUser.should.respondToClick(t)
  t.view = mimas.ListView()
  t.view:move(10,10)

  function t.view:rowCount()
    return #data
  end

  function t.view:data(row_i)
    if row_i == 2 then
      return 'Click on me'
    else
      return data[row_i]
    end
  end

  function t.view:click(x, y)
    local i, j = t.view:indexAt(x, y)
    assertEqual(2, i)
    t.continue = true
  end

  function t.view:mouse(x, y)
    print('mouse', x, y)
  end

  t.view:show()
  t:timeout(function()
    return t.continue
  end)
  assertTrue(t.continue)
  t.view:close()
end

function withUser.should.useDataSource(t)
  t.view = mimas.ListView()
  t.view:move(10, 10)
  t.data = mimas.DataSource()

  function t.data:rowCount()
    return #data
  end

  function t.data:data(row)
    if row == 2 then
      return 'Click on me (data)'
    else
      return data[row]
    end
  end

  t.view:setModel(t.data)

  function t.view:select(row)
    assertTrue(2, row)
    t.continue = true
  end

  t.view:show()
  t:timeout(function()
    return t.continue
  end)
  assertTrue(t.continue)
  t.view:close()
end

test.all()

