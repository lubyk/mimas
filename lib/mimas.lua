--[[------------------------------------------------------

  # mimas GUI

  Portable GUI scripted in Lua and compatible with Lubyk. The GUI is based on
  Qt.

--]]------------------------------------------------------
mimas = Autoload('mimas')
require 'mimas.core'

--=============================================== app
app = mimas.Application()
if rawget(_G, 'test') then
  app:setQuitOnLastWindowClosed(false)
end

--=============================================== scheduler
-- First calls to Window creation in mimas should
-- yield so that the mimas scheduler can start
function mimas.bootstrap(base, func, ...)
  if sched.mimas then
    -- already running mimas
  else
    -- restart with mimas scheduler
    if coroutine.running() then
      coroutine.yield('mimas')
    end
  end
  -- Replace bootstrapping constructor by original
  -- function for further calls.
  base.new = func
  return func(...)
end

mimas.WhitePen   = mimas.Pen(1, 0, 0, 1)
mimas.WhiteBrush = mimas.Brush(0, 0, 1)
mimas.BlackPen   = mimas.Pen(1, 0, 0, 0)
mimas.BlackBrush = mimas.Brush(0, 0, 0)

mimas.NoPen   = mimas.Pen()
mimas.NoBrush = mimas.Brush()

mimas.colors = {
  Black     = mimas.Color(0, 0, 0),
  LightGrey = mimas.Color(0, 0, 0.75),
  Grey      = mimas.Color(0, 0, 0.5),
  DarkGrey  = mimas.Color(0, 0, 0.25),
  White     = mimas.Color(0, 0, 1),
  Red       = mimas.Color(0   / 360),
  Orange    = mimas.Color(33  / 360),
  Yellow    = mimas.Color(60  / 360),
  Green     = mimas.Color(120 / 360),
  Blue      = mimas.Color(240 / 360),
  Pink      = mimas.Color(300 / 360),
  Purple    = mimas.Color(275 / 360),
}

-- # KeyboardModifiers
-- + NoModifier          : No keyboard modifier.
-- + ShiftModifier       : Shift ⇧.
-- + ControlModifier     : Control (= ⌘ Command on Mac).
-- + AltModifier         : Alt (= ⌥ Option on Mac).
-- + MetaModifier        : Meta (= ctrl on Mac).
-- + KeypadModifier      : Keypad pressed.
-- + GroupSwitchModifier : X11 only (Mode_switch key pressed).
-- 
-- # Align
-- Alignment flags can be combined. For example:
--
--   local flag = mimas.AlignLeft + mimas.AlignVCenter
--
-- + AlignLeft:    Align left.
-- + AlignRight:   Align right.
-- + AlignHCenter: Center horizontally.
-- + AlignJustify: Justify (for text).
-- + AlignTop:     Start content at top.
-- + AlignBottom:  Place content on the bottom.
-- + AlignVCenter: Align content in the middle.
-- + AlignCenter:  Center both horizontally and vertically.

-- # PenStyles
-- Line drawing styles used with mimas.TableView.setGridStyle for example.
-- + NoPenStyle     : Do not draw anything.
-- + SolidLine      : `_____________`.
-- + DashLine       : `_ _ _ _ _ _ _`.
-- + DotLine        : `. . . . . . .`.
-- + DashDotLine    : `_ . _ . _ . _`.
-- + DashDotDotLine : `_ . . _ . . _`.
-- + CustomDashLine : A custom pattern (not supported).
-- 
-- # ItemFlags
-- Flags to be used with mimas.TableView or mimas.ListView items.
--
-- + NoItemFlags:         No flags, nothing, niet, nada.
-- + ItemIsSelectable:    It can be selected.
-- + ItemIsEditable:      It can be edited.
-- + ItemIsDragEnabled:   It can be dragged.
-- + ItemIsDropEnabled:   It can be used as a drop target.
-- + ItemIsUserCheckable: It can be checked or unchecked by the user.
-- + ItemIsEnabled:       The user can interact with the item.
-- + ItemIsTristate:      The item is checkable with three separate states.
--
-- # EditTriggers
-- Select which action will trigger an edit operation. Used with mimas.TableView.
--
-- + NoEditTriggers  : No editing possible.
-- + CurrentChanged  : Edit on item changes (?).
-- + DoubleClicked   : Edit on double click.
-- + SelectedClicked : Edit on clicking of an already selected item.
-- + EditKeyPressed  : Edit on keyboard "edit key" press (enter on Mac).
-- + AnyKeyPressed   : Edit on any key press.
-- + AllEditTriggers : Edit on any of the above actions.
--
-- # WindowFlags
-- These flags enable the creation of different types of windows. They are
-- used with mimas.Window.
--
-- ![window examples](img/mimas_WindowFlags.png)
--
-- + WidgetFlag       : Default type.
-- + WindowFlag       : The widget is a window (with title bar and such). This
--                    : flag is automatically set if the widget does not have a
--                    : parent.
-- + DialogFlag       : Dialog (no difference on Mac).
-- + SheetFlag        : Sheet comming from under the window's bar.
-- + DrawerFlag       : Side drawer.
-- + PopupFlag        : Window without window bar.
-- + ToolFlag         : Small window bar, floats on top of other windows and
--                      disappears when app is not active (can be changed with
--                      WA_MacAlwaysShowToolWindow attribute).
-- + ToolTipFlag      : Window without window bar.
-- + SplashScreenFlag : Splash screen (?).
-- + DesktopFlag      : Desktop (?).
-- + SubWindowFlag    : SubWindow (?).
--
-- # Key
-- + Key_Escape       : ` `
-- + Key_Tab          : 
-- + Key_Backtab      : 
-- + Key_Backspace    : 
-- + Key_Return       : ↵  (main return)
-- + Key_Enter        : ⌤  (numeric pad enter)
-- + Key_Insert       : 
-- + Key_Delete       : 
-- + Key_Pause        : 
-- + Key_Print        : 
-- + Key_SysReq       : 
-- + Key_Clear        : 
-- + Key_Home         : 
-- + Key_End          : 
-- + Key_Left         : 
-- + Key_Up           : 
-- + Key_Right        : 
-- + Key_Down         : 
-- + Key_PageUp       : 
-- + Key_PageDown     : 
-- + Key_Shift        : 
-- + Key_Control      : 
-- + Key_Meta         : 
-- + Key_Alt          : 
-- + Key_AltGr        : 
-- + Key_CapsLock     : 
-- + Key_NumLock      : 
-- + Key_ScrollLock   : 
-- + Key_F1           : 
-- + Key_F2           : 
-- + Key_F3           : 
-- + Key_F4           : 
-- + Key_F5           : 
-- + Key_F6           : 
-- + Key_F7           : 
-- + Key_F8           : 
-- + Key_F9           : 
-- + Key_F10          : 
-- + Key_F11          : 
-- + Key_F12          : 
-- + Key_F13          : 
-- + Key_F14          : 
-- + Key_F15          : 
-- + Key_F16          : 
-- + Key_F17          : 
-- + Key_F18          : 
-- + Key_F19          : 
-- + Key_F20          : 
-- + Key_F21          : 
-- + Key_F22          : 
-- + Key_F23          : 
-- + Key_F24          : 
-- + Key_F25          : 
-- + Key_F26          : 
-- + Key_F27          : 
-- + Key_F28          : 
-- + Key_F29          : 
-- + Key_F30          : 
-- + Key_F31          : 
-- + Key_F32          : 
-- + Key_F33          : 
-- + Key_F34          : 
-- + Key_F35          : 
-- + Key_Super_L      : 
-- + Key_Super_R      : 
-- + Key_Menu         : 
-- + Key_Hyper_L      : 
-- + Key_Hyper_R      : 
-- + Key_Help         : 
-- + Key_Direction_L  : 
-- + Key_Direction_R  : 
-- + Key_Space        : 
-- + Key_Any          : 
-- + Key_Exclam       : 
-- + Key_QuoteDbl     : 
-- + Key_NumberSign   : 
-- + Key_Dollar       : 
-- + Key_Percent      : 
-- + Key_Ampersand    : 
-- + Key_Apostrophe   : 
-- + Key_ParenLeft    : 
-- + Key_ParenRight   : 
-- + Key_Asterisk     : 
-- + Key_Plus         : 
-- + Key_Comma        : 
-- + Key_Minus        : 
-- + Key_Period       : 
-- + Key_Slash        : 
-- + Key_0            : 
-- + Key_1            : 
-- + Key_2            : 
-- + Key_3            : 
-- + Key_4            : 
-- + Key_5            : 
-- + Key_6            : 
-- + Key_7            : 
-- + Key_8            : 
-- + Key_9            : 
-- + Key_Colon        : 
-- + Key_Semicolon    : 
-- + Key_Less         : 
-- + Key_Equal        : 
-- + Key_Greater      : 
-- + Key_Question     : 
-- + Key_At           : `@`
-- + Key_A            : 
-- + Key_B            : 
-- + Key_C            : 
-- + Key_D            : 
-- + Key_E            : 
-- + Key_F            : 
-- + Key_G            : 
-- + Key_H            : 
-- + Key_I            : 
-- + Key_J            : 
-- + Key_K            : 
-- + Key_L            : 
-- + Key_M            : 
-- + Key_N            : 
-- + Key_O            : 
-- + Key_P            : 
-- + Key_Q            : 
-- + Key_R            : 
-- + Key_S            : 
-- + Key_T            : 
-- + Key_U            : 
-- + Key_V            : 
-- + Key_W            : 
-- + Key_X            : 
-- + Key_Y            : 
-- + Key_Z            : 
-- + Key_BracketLeft  : 
-- + Key_Backslash    : 
-- + Key_BracketRight : 
-- + Key_AsciiCircum  : 
-- + Key_Underscore   : 
-- + Key_QuoteLeft    : 
-- + Key_BraceLeft    : 
-- + Key_Bar          : 
-- + Key_BraceRight   : 
-- + Key_AsciiTilde   : 
-- + Key_nobreakspace : 
-- + Key_exclamdown   : 
-- + Key_cent         : 
-- + Key_sterling     : 
-- + Key_currency     : 
-- + Key_yen          : 
-- + Key_brokenbar    : 
-- + Key_section      : 
-- + Key_diaeresis    : 
-- + Key_copyright    : 
-- + Key_ordfeminine  : 
-- + Key_guillemotleft: 
-- + Key_notsign      : 
-- + Key_hyphen       : 
-- + Key_registered   : 
-- + Key_macron       : 
-- + Key_degree       : 
-- + Key_plusminus    : 
-- + Key_twosuperior  : 
-- + Key_threesuperior: 
-- + Key_acute        : 
-- + Key_mu           : 
-- + Key_paragraph    : 
-- + Key_periodcentered: 
-- + Key_cedilla      : 
-- + Key_onesuperior  : 
-- + Key_masculine    : 
-- + Key_guillemotright: 
-- + Key_onequarter   : 
-- + Key_onehalf      : 
-- + Key_threequarters: 
-- + Key_questiondown : 
-- + Key_Agrave       : 
-- + Key_Aacute       : 
-- + Key_Acircumflex  : 
-- + Key_Atilde       : 
-- + Key_Adiaeresis   : 
-- + Key_Aring        : 
-- + Key_AE           : 
-- + Key_Ccedilla     : 
-- + Key_Egrave       : 
-- + Key_Eacute       : 
-- + Key_Ecircumflex  : 
-- + Key_Ediaeresis   : 
-- + Key_Igrave       : 
-- + Key_Iacute       : 
-- + Key_Icircumflex  : 
-- + Key_Idiaeresis   : 
-- + Key_ETH          : 
-- + Key_Ntilde       : 
-- + Key_Ograve       : 
-- + Key_Oacute       : 
-- + Key_Ocircumflex  : 
-- + Key_Otilde       : 
-- + Key_Odiaeresis   : 
-- + Key_multiply     : 
-- + Key_Ooblique     : 
-- + Key_Ugrave       : 
-- + Key_Uacute       : 
-- + Key_Ucircumflex  : 
-- + Key_Udiaeresis   : 
-- + Key_Yacute       : 
-- + Key_THORN        : 
-- + Key_ssharp       : 
-- + Key_division     : 
-- + Key_ydiaeresis   : 
-- + Key_Multi_key    : 
-- + Key_Codeinput    : 
-- + Key_SingleCandidate: 
-- + Key_MultipleCandidate: 
-- + Key_PreviousCandidate: 
-- + Key_Mode_switch  : 
-- + Key_Kanji        : 
-- + Key_Muhenkan     : 
-- + Key_Henkan       : 
-- + Key_Romaji       : 
-- + Key_Hiragana     : 
-- + Key_Katakana     : 
-- + Key_Hiragana_Katakana: 
-- + Key_Zenkaku      : 
-- + Key_Hankaku      : 
-- + Key_Zenkaku_Hankaku: 
-- + Key_Touroku      : 
-- + Key_Massyo       : 
-- + Key_Kana_Lock    : 
-- + Key_Kana_Shift   : 
-- + Key_Eisu_Shift   : 
-- + Key_Eisu_toggle  : 
-- + Key_Hangul       : 
-- + Key_Hangul_Start : 
-- + Key_Hangul_End   : 
-- + Key_Hangul_Hanja : 
-- + Key_Hangul_Jamo  : 
-- + Key_Hangul_Romaja: 
-- + Key_Hangul_Jeonja: 
-- + Key_Hangul_Banja : 
-- + Key_Hangul_PreHanja: 
-- + Key_Hangul_PostHanja: 
-- + Key_Hangul_Special: 
-- + Key_Dead_Grave   : 
-- + Key_Dead_Acute   : 
-- + Key_Dead_Circumflex: 
-- + Key_Dead_Tilde   : 
-- + Key_Dead_Macron  : 
-- + Key_Dead_Breve   : 
-- + Key_Dead_Abovedot: 
-- + Key_Dead_Diaeresis: 
-- + Key_Dead_Abovering: 
-- + Key_Dead_Doubleacute: 
-- + Key_Dead_Caron   : 
-- + Key_Dead_Cedilla : 
-- + Key_Dead_Ogonek  : 
-- + Key_Dead_Iota    : 
-- + Key_Dead_Voiced_Sound: 
-- + Key_Dead_Semivoiced_Sound: 
-- + Key_Dead_Belowdot: 
-- + Key_Dead_Hook    : 
-- + Key_Dead_Horn    : 
-- + Key_Back         : 
-- + Key_Forward      : 
-- + Key_Stop         : 
-- + Key_Refresh      : 
-- + Key_VolumeDown   : 
-- + Key_VolumeMute   : 
-- + Key_VolumeUp     : 
-- + Key_BassBoost    : 
-- + Key_BassUp       : 
-- + Key_BassDown     : 
-- + Key_TrebleUp     : 
-- + Key_TrebleDown   : 
-- + Key_MediaPlay    : 
-- + Key_MediaStop    : 
-- + Key_MediaPrevious: 
-- + Key_MediaNext    : 
-- + Key_MediaRecord  : 
-- + Key_MediaPause   : 
-- + Key_MediaTogglePlayPause: 
-- + Key_HomePage     : 
-- + Key_Favorites    : 
-- + Key_Search       : 
-- + Key_Standby      : 
-- + Key_OpenUrl      : 
-- + Key_LaunchMail   : 
-- + Key_LaunchMedia  : 
-- + Key_Launch0      : 
-- + Key_Launch1      : 
-- + Key_Launch2      : 
-- + Key_Launch3      : 
-- + Key_Launch4      : 
-- + Key_Launch5      : 
-- + Key_Launch6      : 
-- + Key_Launch7      : 
-- + Key_Launch8      : 
-- + Key_Launch9      : 
-- + Key_LaunchA      : 
-- + Key_LaunchB      : 
-- + Key_LaunchC      : 
-- + Key_LaunchD      : 
-- + Key_LaunchE      : 
-- + Key_LaunchF      : 
-- + Key_LaunchG      : 
-- + Key_LaunchH      : 
-- + Key_MonBrightnessUp: 
-- + Key_MonBrightnessDown: 
-- + Key_KeyboardLightOnOff: 
-- + Key_KeyboardBrightnessUp: 
-- + Key_KeyboardBrightnessDown: 
-- + Key_PowerOff     : 
-- + Key_WakeUp       : 
-- + Key_Eject        : 
-- + Key_ScreenSaver  : 
-- + Key_WWW          : 
-- + Key_Memo         : 
-- + Key_LightBulb    : 
-- + Key_Shop         : 
-- + Key_History      : 
-- + Key_AddFavorite  : 
-- + Key_HotLinks     : 
-- + Key_BrightnessAdjust: 
-- + Key_Finance      : 
-- + Key_Community    : 
-- + Key_AudioRewind  : 
-- + Key_BackForward  : 
-- + Key_ApplicationLeft: 
-- + Key_ApplicationRight: 
-- + Key_Book         : 
-- + Key_CD           : 
-- + Key_Calculator   : 
-- + Key_ToDoList     : 
-- + Key_ClearGrab    : 
-- + Key_Close        : 
-- + Key_Copy         : 
-- + Key_Cut          : 
-- + Key_Display      : 
-- + Key_DOS          : 
-- + Key_Documents    : 
-- + Key_Excel        : 
-- + Key_Explorer     : 
-- + Key_Game         : 
-- + Key_Go           : 
-- + Key_iTouch       : 
-- + Key_LogOff       : 
-- + Key_Market       : 
-- + Key_Meeting      : 
-- + Key_MenuKB       : 
-- + Key_MenuPB       : 
-- + Key_MySites      : 
-- + Key_News         : 
-- + Key_OfficeHome   : 
-- + Key_Option       : 
-- + Key_Paste        : 
-- + Key_Phone        : 
-- + Key_Calendar     : 
-- + Key_Reply        : 
-- + Key_Reload       : 
-- + Key_RotateWindows: 
-- + Key_RotationPB   : 
-- + Key_RotationKB   : 
-- + Key_Save         : 
-- + Key_Send         : 
-- + Key_Spell        : 
-- + Key_SplitScreen  : 
-- + Key_Support      : 
-- + Key_TaskPane     : 
-- + Key_Terminal     : 
-- + Key_Tools        : 
-- + Key_Travel       : 
-- + Key_Video        : 
-- + Key_Word         : 
-- + Key_Xfer         : 
-- + Key_ZoomIn       : 
-- + Key_ZoomOut      : 
-- + Key_Away         : 
-- + Key_Messenger    : 
-- + Key_WebCam       : 
-- + Key_MailForward  : 
-- + Key_Pictures     : 
-- + Key_Music        : 
-- + Key_Battery      : 
-- + Key_Bluetooth    : 
-- + Key_WLAN         : 
-- + Key_UWB          : 
-- + Key_AudioForward : 
-- + Key_AudioRepeat  : 
-- + Key_AudioRandomPla: 
-- + Key_Subtitle     : 
-- + Key_AudioCycleTrac: 
-- + Key_Time         : 
-- + Key_Hibernate    : 
-- + Key_View         : 
-- + Key_TopMenu      : 
-- + Key_PowerDown    : 
-- + Key_Suspend      : 
-- + Key_ContrastAdjust: 
-- + Key_MediaLast    : 
-- + Key_unknown      : 
-- + Key_Call         : 
-- + Key_Camera       : 
-- + Key_CameraFocus  : 
-- + Key_Context1     : 
-- + Key_Context2     : 
-- + Key_Context3     : 
-- + Key_Context4     : 
-- + Key_Flip         : 
-- + Key_Hangup       : 
-- + Key_No           : 
-- + Key_Select       : 
-- + Key_Yes          : 
-- + Key_ToggleCallHangup: 
-- + Key_VoiceDial    : 
-- + Key_LastNumberRedial: 
-- + Key_Execute      : 
-- + Key_Printer      : 
-- + Key_Play         : 
-- + Key_Sleep        : 
-- + Key_Zoom         : 
-- + Key_Cancel       : 
