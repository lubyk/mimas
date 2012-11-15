--[[------------------------------------------------------

  mimas.Application
  --------------

  GUI Application. The object returned by
  mimas.Application() is a table that will contain
  callbacks (stored as references in the numerical index).
  This means that storing things in the application with
  app[4] = 'xxx' is very bad. Doing app.foo = 'yyy' is
  good.

--]]------------------------------------------------------
local lib         = mimas.Application_core
mimas.Application = lib

local app
local new = lib.new
function lib.new(type)
  if app then
    return app
  end
  local app = new(type)
  app:setQuitOnLastWindowClosed(mimas.Settings.quit_on_close)
  app:setStyleSheet [[
    /* FIXME: QWidget is too broad... we need to fix QPushButton and Co...
    */
    Widget, MainWindow, Label, ListView, TableView, TabWidget, QTabBar::tab:selected,
    Menu, CheckBox, GroupBox {
      background:#151515;
      color:#B4B4B4;
    }
    TableView {
      alternate-background-color:#333;
      border:0;
    }
    ListView, Menu {
      border:0;
      padding:0;
    }
    ListView {
      alternate-background-color:#333;
      border:0;
      min-height:90px;
    }
    ListView::item {
      padding:2px;
    }
    ListView::item:selected, TableView::item:selected {
      border: 0;
      color: #B4B4B4;
      background:#6E4E24;
      padding:0px;
    }
    Menu {
      border:1px solid #777;
      font-size:13px;
      background:#222;
    }
    Menu::separator {
      height: 2px;
      background: #444;
    }
    Menu::item {
      padding:2px 5px;
      border-top:1px solid #444;
    }
    Menu::item:first {
      border-top:0;
    }
    Menu::item:selected {
      background: #444;
    }
    GroupBox {
      background: hsva(0,0,70,80);
      border: 1px solid #555;
      border-radius: 5px;
    }
    QGroupBox::title {
      subcontrol-origin: margin;
      subcontrol-position: top left;
      position:relative;
      left:6px;
    }
    LineEdit {
      background:#333;
      color:white;
      selection-color:white;
      selection-background-color: rgb(40,85,140);
    }
    GLWidget, LegacyGLWidget { border-style: none;}
    Label { background: transparent; }

    /* TabWidget */
    TabWidget::pane {
      position:absolute;
      top: -1px;
      border-top:1px solid #999;
    }
    TabWidget::tab-bar {
      left:15px;
    }
    QTabBar::tab {
      margin-top:8px;
      border: 1px solid #999;
      border-top-left-radius: 4px;
      border-top-right-radius: 4px;
      padding:2px 8px;
      background:#777;
      color:#222;
    }
    QTabBar::tab:first {
      margin-left:0px;
    }
    QTabBar::tab:selected {
      border-bottom:0;
      margin-top:5px;
      color:#B4B4B4;
    }
    QScrollBar:horizontal{
      background: #262626;
      height: 8px;
      margin:0;
    }
    QScrollBar:vertical {
      background: #262626;
      width: 8px;
      margin:0;
    }
    QScrollBar::handle:horizontal {
        background: #555;
        min-width: 10px;
    }
    QScrollBar::handle:vertical {
        background: #555;
        min-height: 10px;
    }
    QScrollBar::add-line:horizontal,
    QScrollBar::sub-line:horizontal,
    QScrollBar::sub-line:vertical,
    QScrollBar::add-line:vertical {
        height: 0px;
        width: 0px;
    }
    /* end TabWidget */
    Control {
      font-size:10px;
    }
    CheckBox::indicator {
      border:1px solid #aaa;
      width: 6px;
      height: 6px;
    }
    CheckBox::indicator:checked {
      background:#888;
    }

    #test_name { color: hsva(20, 255, 255, 80%); }
    #test_name.slider { color:hsv(30,200,200); }
  ]]

  return app
end

local singleShot = lib.singleShot
function lib.singleShot(app, timeout, func_or_clbk)
  local clbk = func_or_clbk
  if type(func_or_clbk) == 'function' then
    clbk = mimas.Callback(function(self)
      func_or_clbk()
      app[self] = nil
    end)
    -- avoid gc
    app[clbk] = clbk
  end
  singleShot(app, timeout, clbk, '1callback()')
end

local setOverrideCursor = lib.setOverrideCursor
function lib:hideCursor()
  self.cursor = mimas.Cursor(mimas.BlankCursor)
  setOverrideCursor(self.cursor)
end

local restoreOverrideCursor = lib.restoreOverrideCursor
function lib:restoreCursor()
  restoreOverrideCursor()
  self.cursor = nil
end

function lib:setCursor(type)
  self.cursor = mimas.Cursor(type)
  setOverrideCursor(self.cursor)
end
