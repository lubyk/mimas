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

-- CSS color themes
lib.THEMES = { -- doc
  -- Dark theme (good for scene, theater)
  dark = {
    -- This must be set to either 'dark' or 'light' for computed color values
    -- in code.
    style          = 'dark',
    background     = '#151515',
    header         = '#333',
    _background    = mimas.Color(0, 0, 0.12),
    alt_background = '#333',
    alt2_background= '#292929',
    edit_color     = '#fff',
    menu           = '#222',
    color          = '#B4B4B4',
    _color         = mimas.Color(0, 0, 0.4),
    selected       = '#6E4E24',
    selected_bg    = 'rgb(40,85,140)',
    selected_row   = '#aaa',
    box            = 'hsva(0,0,70,80)',
    high_color     = '#fff',
    _high_color    = mimas.Color(0, 0, 0.8),
  },

  -- Light theme (good for desktop)
  light = {
    -- This must be set to either 'dark' or 'light' for computed color values
    -- in code.
    style          = 'light',
    background     = '#e5e5e5',
    header         = '#ccc',
    _background    = mimas.Color(0, 0, 0.8),
    alt_background = '#ddd',
    alt2_background= '#ccc',
    edit_color     = '#333',
    menu           = '#aaa',
    color          = '#444',
    _color         = mimas.Color(0, 0, 0.4),
    selected       = '#6E4E24',
    selected_bg    = 'rgb(40,85,140)',
    selected_row   = '#ccc',
    box            = 'hsva(0,0,70,80)',
    high_color     = '#111',
    _high_color    = mimas.Color(0, 0, 0),
  },
}

local app
local new = lib.new
-- Create a new application. This returns the 'app' singleton if an application
-- has already been created.
function lib.new(type)
  -- Singleton
  if app then return app end
  local self = new(type)
  app = self

  self:setQuitOnLastWindowClosed(mimas.Settings.quit_on_close)

  self:setTheme 'dark'

  return self
end

function lib:setTheme(theme)
  self.theme = lib.THEMES[theme] or lib.THEMES.dark
  self:setStyleSheet(self:compileCss(lib.BASE_CSS))
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

-- Compile CSS with the current theme's colors.
function lib:compileCss(css)
  local theme = self.theme
  return string.gsub(css, '@([0-9a-zA-Z_]+)', function(key)
    return theme[key]
  end)
end

-- Basic CSS rules.
-- Used: QHeaderView::section
lib.BASE_CSS = [[
  /* FIXME: QWidget is too broad... we need to fix QPushButton and Co...
  */
  Widget, MainWindow, Label, ListView, TableView, TabWidget,
  QTabBar::tab:selected, Menu, CheckBox, GroupBox {
    background:@background;
    color:@color;
  }
  QStatusBar {
    background:#fee;
  }

  TableView {
    alternate-background-color:@alt_background;
    border:0;
  }
  QHeaderView {
    background:@header;
    color:@color;
  }

  TableView QTableCornerButton::section,
  TableView QHeaderView::section,
  TableView QHeaderView::section:horizontal,
  TableView QHeaderView::section:vertical {
    padding:5px;
    background:@header;
    border:none;
    font-size:12px;
  }

  TableView QHeaderView::section:vertical {
    border-bottom:1px solid #777;
  }
  ListView, Menu {
    border:0;
    padding:0;
  }
  ListView {
    alternate-background-color:@alt_background;
    border:0;
    min-height:90px;
  }
  ListView::item {
    padding:2px;
  }
  ListView::item:selected, TableView::item:selected {
    border: 0;
    color: @color;
    background:@selected_row;
    padding:0px;
  }
  Menu {
    border:1px solid #777;
    font-size:13px;
    background:@menu;
  }
  Menu::separator {
    height: 2px;
    background: #444;
  }
  Menu::item {
    padding:2px 5px;
    border-top:1px solid #777;
  }
  /* too bad this doesn't work */
  Menu::item:first {
    border-top:0;
  }
  Menu::item:selected {
    background: @selected_row;
  }
  GroupBox {
    background: @box;
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
    background:@alt_background;
    color:@edit_color;
    selection-color:white;
    selection-background-color: @selected_bg;
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
    background:@background;
    color:@color;
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
