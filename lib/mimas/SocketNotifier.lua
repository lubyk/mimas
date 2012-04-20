--[[------------------------------------------------------

  mimas.SocketNotifier
  --------------------

  Used internally to process zmq and other sockets from
  within mimas event loop.

--]]------------------------------------------------------
local lib = mimas.SocketNotifier_core
mimas.SocketNotifier = lib

function lib.new(...)
  return mimas.bootstrap(lib, new, ...)
end

