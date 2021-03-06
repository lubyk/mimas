--[[------------------------------------------------------

  mimas.FileObserver
  ------------------

  ...

--]]------------------------------------------------------
require 'lubyk'

local should = test.Suite('mimas.FileObserver')

function should.autoLoad()
  assertTrue(mimas.FileObserver)
end

function should.observeFiles(t)
  local filepath = lk.absolutizePath(fixture.path('baz.txt'))
  -- just because mimas needs a window to start and quit
  local win = mimas.Window()
  win:move(10,10)
  win:resize(50,50)
  win:show()

  lk.writeall(filepath, 'Hello')
  t.observer = mimas.FileObserver(filepath)
  assertTrue(t.observer.paths[filepath])

  function t.observer:pathChanged(path)
    if path == filepath then
      t.continue = true
      t.observer:removePath(filepath)
    end
  end
  -- adding path twice should not raise
  assertPass(function()
    t.observer:addPath(filepath)
  end)
  -- we edit the file
  lk.writeall(filepath, 'World!')
  while not t.continue do
    sleep(100)
  end
  lk.rmFile(filepath)
  win:close()
end

test.all()
