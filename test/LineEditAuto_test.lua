--[[------------------------------------------------------

  Basic tests for LineEditAuto
  ----------------------------

  ...

--]]------------------------------------------------------
require 'lubyk'

local should = test.Suite('mimas.LineEditAuto')
local withUser = should:testWithUser()

function should.loadCoad()
  assertType('table', mimas.LineEditAuto)
end

function withUser.should.callback(t)
  t.win = mimas.Window()
  t.win:move(10, 10)
  t.win:resize(200, 200)
  local data = {
    'lk.Node',
    'lk.Socket',
    'zmq.Socket',
    'lubyk.Metro',
  }

  t.lb = mimas.LineEditAuto("type 'm=l'", '^(.+= *)(.+)')
  t.win:addWidget(t.lb)
  t.lb:selectAll()

  t.win:addWidget(t.lb)
  t.lb:move(40, 40)

  -- ====================================================
  -- How this particular auto-complete works is defined by the following
  -- methods
  function t.lb:cueChanged(cue)
    self.db_pattern = cue
  end

  local function find(pattern, row)
    row = row or 1
    if data.pattern ~= pattern then
      local found = {}
      for _, v in ipairs(data) do
        if v:match(pattern) then
          table.insert(found, v)
        end
      end
      data.found = found
    end
    return data.found[row]
  end

  function t.lb:resultCount()
    -- dummy find to update pattern cache
    find(self.db_pattern)
    return #data.found
  end

  function t.lb:data(row)
    if row then
      -- data for list
      return find(self.db_pattern, row)
    else
      -- data for inline
      return find('^'..self.cue)
    end
  end

  function t.lb:editingFinished(text)
    self:autoFinished()
    assertEqual('m=lubyk.Metro', text)
    t.continue = true
  end
  -- ====================================================

  t.win:show()

  t:timeout(function()
    return t.continue
  end)
  t.win:close()
  assertTrue(t.continue)
end

test.all()
