/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for library mimas
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "mimas/Action.h"
#include "mimas/Application.h"
#include "mimas/Brush.h"
#include "mimas/Button.h"
#include "mimas/Callback.h"
#include "mimas/CheckBox.h"
#include "mimas/Color.h"
#include "mimas/Cursor.h"
#include "mimas/DataSource.h"
#include "mimas/FileObserver.h"
#include "mimas/GLWidget.h"
#include "mimas/GroupBox.h"
#include "mimas/HBoxLayout.h"
#include "mimas/Label.h"
#include "mimas/LegacyGLWidget.h"
#include "mimas/LineEdit.h"
#include "mimas/ListView.h"
#include "mimas/MainWindow.h"
#include "mimas/Menu.h"
#include "mimas/MenuBar.h"
#include "mimas/Painter.h"
#include "mimas/Path.h"
#include "mimas/Pen.h"
#include "mimas/SocketNotifier.h"
#include "mimas/TableView.h"
#include "mimas/TabWidget.h"
#include "mimas/Timer.h"
#include "mimas/VBoxLayout.h"
#include "mimas/Widget.h"
#include "mimas/mimas.h"
#include "mimas/constants.h"


extern "C" {
int luaopen_mimas_Action(lua_State *L);
int luaopen_mimas_Application(lua_State *L);
int luaopen_mimas_Brush(lua_State *L);
int luaopen_mimas_Button(lua_State *L);
int luaopen_mimas_Callback(lua_State *L);
int luaopen_mimas_CheckBox(lua_State *L);
int luaopen_mimas_Color(lua_State *L);
int luaopen_mimas_Cursor(lua_State *L);
int luaopen_mimas_DataSource(lua_State *L);
int luaopen_mimas_FileObserver(lua_State *L);
int luaopen_mimas_GLWidget(lua_State *L);
int luaopen_mimas_GroupBox(lua_State *L);
int luaopen_mimas_HBoxLayout(lua_State *L);
int luaopen_mimas_Label(lua_State *L);
int luaopen_mimas_LegacyGLWidget(lua_State *L);
int luaopen_mimas_LineEdit(lua_State *L);
int luaopen_mimas_ListView(lua_State *L);
int luaopen_mimas_MainWindow(lua_State *L);
int luaopen_mimas_Menu(lua_State *L);
int luaopen_mimas_MenuBar(lua_State *L);
int luaopen_mimas_Painter(lua_State *L);
int luaopen_mimas_Path(lua_State *L);
int luaopen_mimas_Pen(lua_State *L);
int luaopen_mimas_SocketNotifier(lua_State *L);
int luaopen_mimas_TableView(lua_State *L);
int luaopen_mimas_TabWidget(lua_State *L);
int luaopen_mimas_Timer(lua_State *L);
int luaopen_mimas_VBoxLayout(lua_State *L);
int luaopen_mimas_Widget(lua_State *L);
}

/** QVariant variantFromLua(lua_State *L, int index)
 * include/mimas/mimas.h:53
 */
static int mimas_variantFromLua(lua_State *L) {
  try {
    int index = dub_checkint(L, 2);
    return pushVariantInLua(L, variantFromLua(L, index));
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.variantFromLua: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.variantFromLua: Unknown exception");
  }
  return lua_error(L);
}

/** int pushVariantInLua(lua_State *L, const QVariant &value)
 * include/mimas/mimas.h:54
 */
static int mimas_pushVariantInLua(lua_State *L) {
  try {
    QVariant value(variantFromLua(L, 2));
    lua_pushnumber(L, pushVariantInLua(L, value));
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "mimas.pushVariantInLua: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "mimas.pushVariantInLua: Unknown exception");
  }
  return lua_error(L);
}

// --=============================================== FUNCTIONS
static const struct luaL_Reg mimas_functions[] = {
  { "variantFromLua", mimas_variantFromLua },
  { "pushVariantInLua", mimas_pushVariantInLua },
  { NULL, NULL},
};

// --=============================================== CONSTANTS
static const struct dub_const_Reg mimas_const[] = {
  { "NoBrushStyle" , NoBrushStyle         },
  { "SolidPattern" , SolidPattern         },
  { "LinearGradientPattern", LinearGradientPattern },
  { "ConicalGradientPattern", ConicalGradientPattern },
  { "RadialGradientPattern", RadialGradientPattern },
  { "TexturePattern", TexturePattern       },
  { "NoPenStyle"   , NoPenStyle           },
  { "SolidLine"    , SolidLine            },
  { "DashLine"     , DashLine             },
  { "DotLine"      , DotLine              },
  { "DashDotLine"  , DashDotLine          },
  { "DashDotDotLine", DashDotDotLine       },
  { "CustomDashLine", CustomDashLine       },
  { "FlatCap"      , FlatCap              },
  { "SquareCap"    , SquareCap            },
  { "RoundCap"     , RoundCap             },
  { "MiterJoin"    , MiterJoin            },
  { "BevelJoin"    , BevelJoin            },
  { "RoundJoin"    , RoundJoin            },
  { "SvgMiterJoin" , SvgMiterJoin         },
  { "AlignLeft"    , AlignLeft            },
  { "AlignRight"   , AlignRight           },
  { "AlignHCenter" , AlignHCenter         },
  { "AlignJustify" , AlignJustify         },
  { "AlignTop"     , AlignTop             },
  { "AlignBottom"  , AlignBottom          },
  { "AlignVCenter" , AlignVCenter         },
  { "AlignCenter"  , AlignCenter          },
  { "NoItemFlags"  , NoItemFlags          },
  { "ItemIsSelectable", ItemIsSelectable     },
  { "ItemIsEditable", ItemIsEditable       },
  { "ItemIsDragEnabled", ItemIsDragEnabled    },
  { "ItemIsDropEnabled", ItemIsDropEnabled    },
  { "ItemIsUserCheckable", ItemIsUserCheckable  },
  { "ItemIsEnabled", ItemIsEnabled        },
  { "ItemIsTristate", ItemIsTristate       },
  { "NoEditTriggers", NoEditTriggers       },
  { "CurrentChanged", CurrentChanged       },
  { "DoubleClicked", DoubleClicked        },
  { "SelectedClicked", SelectedClicked      },
  { "EditKeyPressed", EditKeyPressed       },
  { "AnyKeyPressed", AnyKeyPressed        },
  { "AllEditTriggers", AllEditTriggers      },
  { "TextDontClip" , TextDontClip         },
  { "TextSingleLine", TextSingleLine       },
  { "TextExpandTabs", TextExpandTabs       },
  { "TextShowMnemonic", TextShowMnemonic     },
  { "TextWordWrap" , TextWordWrap         },
  { "TextIncludeTrailingSpaces", TextIncludeTrailingSpaces },
  { "TabFocus"     , TabFocus             },
  { "ClickFocus"   , ClickFocus           },
  { "StrongFocus"  , StrongFocus          },
  { "WheelFocus"   , WheelFocus           },
  { "NoFocus"      , NoFocus              },
  { "WA_MacAlwaysShowToolWindow", WA_MacAlwaysShowToolWindow },
  { "WA_MacShowFocusRect", WA_MacShowFocusRect  },
  { "ShowDirsOnly" , ShowDirsOnly         },
  { "DontResolveSymlinks", DontResolveSymlinks  },
  { "DontConfirmOverwrite", DontConfirmOverwrite },
  { "DontUseNativeDialog", DontUseNativeDialog  },
  { "ReadOnly"     , ReadOnly             },
  { "HideNameFilterDetails", HideNameFilterDetails },
  { "DontUseSheet" , DontUseSheet         },
  { "NoRole"       , NoRole               },
  { "TextHeuristicRole", TextHeuristicRole    },
  { "ApplicationSpecificRole", ApplicationSpecificRole },
  { "AboutQtRole"  , AboutQtRole          },
  { "AboutRole"    , AboutRole            },
  { "PreferencesRole", PreferencesRole      },
  { "QuitRole"     , QuitRole             },
  { "Fixed"        , Fixed                },
  { "Minimum"      , Minimum              },
  { "Maximum"      , Maximum              },
  { "Preferred"    , Preferred            },
  { "Expanding"    , Expanding            },
  { "MinimumExpanding", MinimumExpanding     },
  { "Ignored"      , Ignored              },
  { "SliderNoAction", SliderNoAction       },
  { "SliderSingleStepAdd", SliderSingleStepAdd  },
  { "SliderSingleStepSub", SliderSingleStepSub  },
  { "SliderPageStepAdd", SliderPageStepAdd    },
  { "SliderPageStepSub", SliderPageStepSub    },
  { "SliderToMinimum", SliderToMinimum      },
  { "SliderToMaximum", SliderToMaximum      },
  { "SliderMove"   , SliderMove           },
  { "NoButton"     , NoButton             },
  { "LeftButton"   , LeftButton           },
  { "RightButton"  , RightButton          },
  { "MidButton"    , MidButton            },
  { "MiddleButton" , MiddleButton         },
  { "XButton1"     , XButton1             },
  { "XButton2"     , XButton2             },
  { "NoModifier"   , NoModifier           },
  { "ShiftModifier", ShiftModifier        },
  { "ControlModifier", ControlModifier      },
  { "AltModifier"  , AltModifier          },
  { "MetaModifier" , MetaModifier         },
  { "KeypadModifier", KeypadModifier       },
  { "GroupSwitchModifier", GroupSwitchModifier  },
  { "Horizontal"   , Horizontal           },
  { "Vertical"     , Vertical             },
  { "Key_Escape"   , Key_Escape           },
  { "Key_Tab"      , Key_Tab              },
  { "Key_Backtab"  , Key_Backtab          },
  { "Key_Backspace", Key_Backspace        },
  { "Key_Return"   , Key_Return           },
  { "Key_Enter"    , Key_Enter            },
  { "Key_Insert"   , Key_Insert           },
  { "Key_Delete"   , Key_Delete           },
  { "Key_Pause"    , Key_Pause            },
  { "Key_Print"    , Key_Print            },
  { "Key_SysReq"   , Key_SysReq           },
  { "Key_Clear"    , Key_Clear            },
  { "Key_Home"     , Key_Home             },
  { "Key_End"      , Key_End              },
  { "Key_Left"     , Key_Left             },
  { "Key_Up"       , Key_Up               },
  { "Key_Right"    , Key_Right            },
  { "Key_Down"     , Key_Down             },
  { "Key_PageUp"   , Key_PageUp           },
  { "Key_PageDown" , Key_PageDown         },
  { "Key_Shift"    , Key_Shift            },
  { "Key_Control"  , Key_Control          },
  { "Key_Meta"     , Key_Meta             },
  { "Key_Alt"      , Key_Alt              },
  { "Key_AltGr"    , Key_AltGr            },
  { "Key_CapsLock" , Key_CapsLock         },
  { "Key_NumLock"  , Key_NumLock          },
  { "Key_ScrollLock", Key_ScrollLock       },
  { "Key_F1"       , Key_F1               },
  { "Key_F2"       , Key_F2               },
  { "Key_F3"       , Key_F3               },
  { "Key_F4"       , Key_F4               },
  { "Key_F5"       , Key_F5               },
  { "Key_F6"       , Key_F6               },
  { "Key_F7"       , Key_F7               },
  { "Key_F8"       , Key_F8               },
  { "Key_F9"       , Key_F9               },
  { "Key_F10"      , Key_F10              },
  { "Key_F11"      , Key_F11              },
  { "Key_F12"      , Key_F12              },
  { "Key_F13"      , Key_F13              },
  { "Key_F14"      , Key_F14              },
  { "Key_F15"      , Key_F15              },
  { "Key_F16"      , Key_F16              },
  { "Key_F17"      , Key_F17              },
  { "Key_F18"      , Key_F18              },
  { "Key_F19"      , Key_F19              },
  { "Key_F20"      , Key_F20              },
  { "Key_F21"      , Key_F21              },
  { "Key_F22"      , Key_F22              },
  { "Key_F23"      , Key_F23              },
  { "Key_F24"      , Key_F24              },
  { "Key_F25"      , Key_F25              },
  { "Key_F26"      , Key_F26              },
  { "Key_F27"      , Key_F27              },
  { "Key_F28"      , Key_F28              },
  { "Key_F29"      , Key_F29              },
  { "Key_F30"      , Key_F30              },
  { "Key_F31"      , Key_F31              },
  { "Key_F32"      , Key_F32              },
  { "Key_F33"      , Key_F33              },
  { "Key_F34"      , Key_F34              },
  { "Key_F35"      , Key_F35              },
  { "Key_Super_L"  , Key_Super_L          },
  { "Key_Super_R"  , Key_Super_R          },
  { "Key_Menu"     , Key_Menu             },
  { "Key_Hyper_L"  , Key_Hyper_L          },
  { "Key_Hyper_R"  , Key_Hyper_R          },
  { "Key_Help"     , Key_Help             },
  { "Key_Direction_L", Key_Direction_L      },
  { "Key_Direction_R", Key_Direction_R      },
  { "Key_Space"    , Key_Space            },
  { "Key_Any"      , Key_Any              },
  { "Key_Exclam"   , Key_Exclam           },
  { "Key_QuoteDbl" , Key_QuoteDbl         },
  { "Key_NumberSign", Key_NumberSign       },
  { "Key_Dollar"   , Key_Dollar           },
  { "Key_Percent"  , Key_Percent          },
  { "Key_Ampersand", Key_Ampersand        },
  { "Key_Apostrophe", Key_Apostrophe       },
  { "Key_ParenLeft", Key_ParenLeft        },
  { "Key_ParenRight", Key_ParenRight       },
  { "Key_Asterisk" , Key_Asterisk         },
  { "Key_Plus"     , Key_Plus             },
  { "Key_Comma"    , Key_Comma            },
  { "Key_Minus"    , Key_Minus            },
  { "Key_Period"   , Key_Period           },
  { "Key_Slash"    , Key_Slash            },
  { "Key_0"        , Key_0                },
  { "Key_1"        , Key_1                },
  { "Key_2"        , Key_2                },
  { "Key_3"        , Key_3                },
  { "Key_4"        , Key_4                },
  { "Key_5"        , Key_5                },
  { "Key_6"        , Key_6                },
  { "Key_7"        , Key_7                },
  { "Key_8"        , Key_8                },
  { "Key_9"        , Key_9                },
  { "Key_Colon"    , Key_Colon            },
  { "Key_Semicolon", Key_Semicolon        },
  { "Key_Less"     , Key_Less             },
  { "Key_Equal"    , Key_Equal            },
  { "Key_Greater"  , Key_Greater          },
  { "Key_Question" , Key_Question         },
  { "Key_At"       , Key_At               },
  { "Key_A"        , Key_A                },
  { "Key_B"        , Key_B                },
  { "Key_C"        , Key_C                },
  { "Key_D"        , Key_D                },
  { "Key_E"        , Key_E                },
  { "Key_F"        , Key_F                },
  { "Key_G"        , Key_G                },
  { "Key_H"        , Key_H                },
  { "Key_I"        , Key_I                },
  { "Key_J"        , Key_J                },
  { "Key_K"        , Key_K                },
  { "Key_L"        , Key_L                },
  { "Key_M"        , Key_M                },
  { "Key_N"        , Key_N                },
  { "Key_O"        , Key_O                },
  { "Key_P"        , Key_P                },
  { "Key_Q"        , Key_Q                },
  { "Key_R"        , Key_R                },
  { "Key_S"        , Key_S                },
  { "Key_T"        , Key_T                },
  { "Key_U"        , Key_U                },
  { "Key_V"        , Key_V                },
  { "Key_W"        , Key_W                },
  { "Key_X"        , Key_X                },
  { "Key_Y"        , Key_Y                },
  { "Key_Z"        , Key_Z                },
  { "Key_BracketLeft", Key_BracketLeft      },
  { "Key_Backslash", Key_Backslash        },
  { "Key_BracketRight", Key_BracketRight     },
  { "Key_AsciiCircum", Key_AsciiCircum      },
  { "Key_Underscore", Key_Underscore       },
  { "Key_QuoteLeft", Key_QuoteLeft        },
  { "Key_BraceLeft", Key_BraceLeft        },
  { "Key_Bar"      , Key_Bar              },
  { "Key_BraceRight", Key_BraceRight       },
  { "Key_AsciiTilde", Key_AsciiTilde       },
  { "Key_nobreakspace", Key_nobreakspace     },
  { "Key_exclamdown", Key_exclamdown       },
  { "Key_cent"     , Key_cent             },
  { "Key_sterling" , Key_sterling         },
  { "Key_currency" , Key_currency         },
  { "Key_yen"      , Key_yen              },
  { "Key_brokenbar", Key_brokenbar        },
  { "Key_section"  , Key_section          },
  { "Key_diaeresis", Key_diaeresis        },
  { "Key_copyright", Key_copyright        },
  { "Key_ordfeminine", Key_ordfeminine      },
  { "Key_guillemotleft", Key_guillemotleft    },
  { "Key_notsign"  , Key_notsign          },
  { "Key_hyphen"   , Key_hyphen           },
  { "Key_registered", Key_registered       },
  { "Key_macron"   , Key_macron           },
  { "Key_degree"   , Key_degree           },
  { "Key_plusminus", Key_plusminus        },
  { "Key_twosuperior", Key_twosuperior      },
  { "Key_threesuperior", Key_threesuperior    },
  { "Key_acute"    , Key_acute            },
  { "Key_mu"       , Key_mu               },
  { "Key_paragraph", Key_paragraph        },
  { "Key_periodcentered", Key_periodcentered   },
  { "Key_cedilla"  , Key_cedilla          },
  { "Key_onesuperior", Key_onesuperior      },
  { "Key_masculine", Key_masculine        },
  { "Key_guillemotright", Key_guillemotright   },
  { "Key_onequarter", Key_onequarter       },
  { "Key_onehalf"  , Key_onehalf          },
  { "Key_threequarters", Key_threequarters    },
  { "Key_questiondown", Key_questiondown     },
  { "Key_Agrave"   , Key_Agrave           },
  { "Key_Aacute"   , Key_Aacute           },
  { "Key_Acircumflex", Key_Acircumflex      },
  { "Key_Atilde"   , Key_Atilde           },
  { "Key_Adiaeresis", Key_Adiaeresis       },
  { "Key_Aring"    , Key_Aring            },
  { "Key_AE"       , Key_AE               },
  { "Key_Ccedilla" , Key_Ccedilla         },
  { "Key_Egrave"   , Key_Egrave           },
  { "Key_Eacute"   , Key_Eacute           },
  { "Key_Ecircumflex", Key_Ecircumflex      },
  { "Key_Ediaeresis", Key_Ediaeresis       },
  { "Key_Igrave"   , Key_Igrave           },
  { "Key_Iacute"   , Key_Iacute           },
  { "Key_Icircumflex", Key_Icircumflex      },
  { "Key_Idiaeresis", Key_Idiaeresis       },
  { "Key_ETH"      , Key_ETH              },
  { "Key_Ntilde"   , Key_Ntilde           },
  { "Key_Ograve"   , Key_Ograve           },
  { "Key_Oacute"   , Key_Oacute           },
  { "Key_Ocircumflex", Key_Ocircumflex      },
  { "Key_Otilde"   , Key_Otilde           },
  { "Key_Odiaeresis", Key_Odiaeresis       },
  { "Key_multiply" , Key_multiply         },
  { "Key_Ooblique" , Key_Ooblique         },
  { "Key_Ugrave"   , Key_Ugrave           },
  { "Key_Uacute"   , Key_Uacute           },
  { "Key_Ucircumflex", Key_Ucircumflex      },
  { "Key_Udiaeresis", Key_Udiaeresis       },
  { "Key_Yacute"   , Key_Yacute           },
  { "Key_THORN"    , Key_THORN            },
  { "Key_ssharp"   , Key_ssharp           },
  { "Key_division" , Key_division         },
  { "Key_ydiaeresis", Key_ydiaeresis       },
  { "Key_Multi_key", Key_Multi_key        },
  { "Key_Codeinput", Key_Codeinput        },
  { "Key_SingleCandidate", Key_SingleCandidate  },
  { "Key_MultipleCandidate", Key_MultipleCandidate },
  { "Key_PreviousCandidate", Key_PreviousCandidate },
  { "Key_Mode_switch", Key_Mode_switch      },
  { "Key_Kanji"    , Key_Kanji            },
  { "Key_Muhenkan" , Key_Muhenkan         },
  { "Key_Henkan"   , Key_Henkan           },
  { "Key_Romaji"   , Key_Romaji           },
  { "Key_Hiragana" , Key_Hiragana         },
  { "Key_Katakana" , Key_Katakana         },
  { "Key_Hiragana_Katakana", Key_Hiragana_Katakana },
  { "Key_Zenkaku"  , Key_Zenkaku          },
  { "Key_Hankaku"  , Key_Hankaku          },
  { "Key_Zenkaku_Hankaku", Key_Zenkaku_Hankaku  },
  { "Key_Touroku"  , Key_Touroku          },
  { "Key_Massyo"   , Key_Massyo           },
  { "Key_Kana_Lock", Key_Kana_Lock        },
  { "Key_Kana_Shift", Key_Kana_Shift       },
  { "Key_Eisu_Shift", Key_Eisu_Shift       },
  { "Key_Eisu_toggle", Key_Eisu_toggle      },
  { "Key_Hangul"   , Key_Hangul           },
  { "Key_Hangul_Start", Key_Hangul_Start     },
  { "Key_Hangul_End", Key_Hangul_End       },
  { "Key_Hangul_Hanja", Key_Hangul_Hanja     },
  { "Key_Hangul_Jamo", Key_Hangul_Jamo      },
  { "Key_Hangul_Romaja", Key_Hangul_Romaja    },
  { "Key_Hangul_Jeonja", Key_Hangul_Jeonja    },
  { "Key_Hangul_Banja", Key_Hangul_Banja     },
  { "Key_Hangul_PreHanja", Key_Hangul_PreHanja  },
  { "Key_Hangul_PostHanja", Key_Hangul_PostHanja },
  { "Key_Hangul_Special", Key_Hangul_Special   },
  { "Key_Dead_Grave", Key_Dead_Grave       },
  { "Key_Dead_Acute", Key_Dead_Acute       },
  { "Key_Dead_Circumflex", Key_Dead_Circumflex  },
  { "Key_Dead_Tilde", Key_Dead_Tilde       },
  { "Key_Dead_Macron", Key_Dead_Macron      },
  { "Key_Dead_Breve", Key_Dead_Breve       },
  { "Key_Dead_Abovedot", Key_Dead_Abovedot    },
  { "Key_Dead_Diaeresis", Key_Dead_Diaeresis   },
  { "Key_Dead_Abovering", Key_Dead_Abovering   },
  { "Key_Dead_Doubleacute", Key_Dead_Doubleacute },
  { "Key_Dead_Caron", Key_Dead_Caron       },
  { "Key_Dead_Cedilla", Key_Dead_Cedilla     },
  { "Key_Dead_Ogonek", Key_Dead_Ogonek      },
  { "Key_Dead_Iota", Key_Dead_Iota        },
  { "Key_Dead_Voiced_Sound", Key_Dead_Voiced_Sound },
  { "Key_Dead_Semivoiced_Sound", Key_Dead_Semivoiced_Sound },
  { "Key_Dead_Belowdot", Key_Dead_Belowdot    },
  { "Key_Dead_Hook", Key_Dead_Hook        },
  { "Key_Dead_Horn", Key_Dead_Horn        },
  { "Key_Back"     , Key_Back             },
  { "Key_Forward"  , Key_Forward          },
  { "Key_Stop"     , Key_Stop             },
  { "Key_Refresh"  , Key_Refresh          },
  { "Key_VolumeDown", Key_VolumeDown       },
  { "Key_VolumeMute", Key_VolumeMute       },
  { "Key_VolumeUp" , Key_VolumeUp         },
  { "Key_BassBoost", Key_BassBoost        },
  { "Key_BassUp"   , Key_BassUp           },
  { "Key_BassDown" , Key_BassDown         },
  { "Key_TrebleUp" , Key_TrebleUp         },
  { "Key_TrebleDown", Key_TrebleDown       },
  { "Key_MediaPlay", Key_MediaPlay        },
  { "Key_MediaStop", Key_MediaStop        },
  { "Key_MediaPrevious", Key_MediaPrevious    },
  { "Key_MediaNext", Key_MediaNext        },
  { "Key_MediaRecord", Key_MediaRecord      },
  { "Key_MediaPause", Key_MediaPause       },
  { "Key_MediaTogglePlayPause", Key_MediaTogglePlayPause },
  { "Key_HomePage" , Key_HomePage         },
  { "Key_Favorites", Key_Favorites        },
  { "Key_Search"   , Key_Search           },
  { "Key_Standby"  , Key_Standby          },
  { "Key_OpenUrl"  , Key_OpenUrl          },
  { "Key_LaunchMail", Key_LaunchMail       },
  { "Key_LaunchMedia", Key_LaunchMedia      },
  { "Key_Launch0"  , Key_Launch0          },
  { "Key_Launch1"  , Key_Launch1          },
  { "Key_Launch2"  , Key_Launch2          },
  { "Key_Launch3"  , Key_Launch3          },
  { "Key_Launch4"  , Key_Launch4          },
  { "Key_Launch5"  , Key_Launch5          },
  { "Key_Launch6"  , Key_Launch6          },
  { "Key_Launch7"  , Key_Launch7          },
  { "Key_Launch8"  , Key_Launch8          },
  { "Key_Launch9"  , Key_Launch9          },
  { "Key_LaunchA"  , Key_LaunchA          },
  { "Key_LaunchB"  , Key_LaunchB          },
  { "Key_LaunchC"  , Key_LaunchC          },
  { "Key_LaunchD"  , Key_LaunchD          },
  { "Key_LaunchE"  , Key_LaunchE          },
  { "Key_LaunchF"  , Key_LaunchF          },
  { "Key_LaunchG"  , Key_LaunchG          },
  { "Key_LaunchH"  , Key_LaunchH          },
  { "Key_MonBrightnessUp", Key_MonBrightnessUp  },
  { "Key_MonBrightnessDown", Key_MonBrightnessDown },
  { "Key_KeyboardLightOnOff", Key_KeyboardLightOnOff },
  { "Key_KeyboardBrightnessUp", Key_KeyboardBrightnessUp },
  { "Key_KeyboardBrightnessDown", Key_KeyboardBrightnessDown },
  { "Key_PowerOff" , Key_PowerOff         },
  { "Key_WakeUp"   , Key_WakeUp           },
  { "Key_Eject"    , Key_Eject            },
  { "Key_ScreenSaver", Key_ScreenSaver      },
  { "Key_WWW"      , Key_WWW              },
  { "Key_Memo"     , Key_Memo             },
  { "Key_LightBulb", Key_LightBulb        },
  { "Key_Shop"     , Key_Shop             },
  { "Key_History"  , Key_History          },
  { "Key_AddFavorite", Key_AddFavorite      },
  { "Key_HotLinks" , Key_HotLinks         },
  { "Key_BrightnessAdjust", Key_BrightnessAdjust },
  { "Key_Finance"  , Key_Finance          },
  { "Key_Community", Key_Community        },
  { "Key_AudioRewind", Key_AudioRewind      },
  { "Key_BackForward", Key_BackForward      },
  { "Key_ApplicationLeft", Key_ApplicationLeft  },
  { "Key_ApplicationRight", Key_ApplicationRight },
  { "Key_Book"     , Key_Book             },
  { "Key_CD"       , Key_CD               },
  { "Key_Calculator", Key_Calculator       },
  { "Key_ToDoList" , Key_ToDoList         },
  { "Key_ClearGrab", Key_ClearGrab        },
  { "Key_Close"    , Key_Close            },
  { "Key_Copy"     , Key_Copy             },
  { "Key_Cut"      , Key_Cut              },
  { "Key_Display"  , Key_Display          },
  { "Key_DOS"      , Key_DOS              },
  { "Key_Documents", Key_Documents        },
  { "Key_Excel"    , Key_Excel            },
  { "Key_Explorer" , Key_Explorer         },
  { "Key_Game"     , Key_Game             },
  { "Key_Go"       , Key_Go               },
  { "Key_iTouch"   , Key_iTouch           },
  { "Key_LogOff"   , Key_LogOff           },
  { "Key_Market"   , Key_Market           },
  { "Key_Meeting"  , Key_Meeting          },
  { "Key_MenuKB"   , Key_MenuKB           },
  { "Key_MenuPB"   , Key_MenuPB           },
  { "Key_MySites"  , Key_MySites          },
  { "Key_News"     , Key_News             },
  { "Key_OfficeHome", Key_OfficeHome       },
  { "Key_Option"   , Key_Option           },
  { "Key_Paste"    , Key_Paste            },
  { "Key_Phone"    , Key_Phone            },
  { "Key_Calendar" , Key_Calendar         },
  { "Key_Reply"    , Key_Reply            },
  { "Key_Reload"   , Key_Reload           },
  { "Key_RotateWindows", Key_RotateWindows    },
  { "Key_RotationPB", Key_RotationPB       },
  { "Key_RotationKB", Key_RotationKB       },
  { "Key_Save"     , Key_Save             },
  { "Key_Send"     , Key_Send             },
  { "Key_Spell"    , Key_Spell            },
  { "Key_SplitScreen", Key_SplitScreen      },
  { "Key_Support"  , Key_Support          },
  { "Key_TaskPane" , Key_TaskPane         },
  { "Key_Terminal" , Key_Terminal         },
  { "Key_Tools"    , Key_Tools            },
  { "Key_Travel"   , Key_Travel           },
  { "Key_Video"    , Key_Video            },
  { "Key_Word"     , Key_Word             },
  { "Key_Xfer"     , Key_Xfer             },
  { "Key_ZoomIn"   , Key_ZoomIn           },
  { "Key_ZoomOut"  , Key_ZoomOut          },
  { "Key_Away"     , Key_Away             },
  { "Key_Messenger", Key_Messenger        },
  { "Key_WebCam"   , Key_WebCam           },
  { "Key_MailForward", Key_MailForward      },
  { "Key_Pictures" , Key_Pictures         },
  { "Key_Music"    , Key_Music            },
  { "Key_Battery"  , Key_Battery          },
  { "Key_Bluetooth", Key_Bluetooth        },
  { "Key_WLAN"     , Key_WLAN             },
  { "Key_UWB"      , Key_UWB              },
  { "Key_AudioForward", Key_AudioForward     },
  { "Key_AudioRepeat", Key_AudioRepeat      },
  { "Key_AudioRandomPlay", Key_AudioRandomPlay  },
  { "Key_Subtitle" , Key_Subtitle         },
  { "Key_AudioCycleTrack", Key_AudioCycleTrack  },
  { "Key_Time"     , Key_Time             },
  { "Key_Hibernate", Key_Hibernate        },
  { "Key_View"     , Key_View             },
  { "Key_TopMenu"  , Key_TopMenu          },
  { "Key_PowerDown", Key_PowerDown        },
  { "Key_Suspend"  , Key_Suspend          },
  { "Key_ContrastAdjust", Key_ContrastAdjust   },
  { "Key_MediaLast", Key_MediaLast        },
  { "Key_unknown"  , Key_unknown          },
  { "Key_Call"     , Key_Call             },
  { "Key_Camera"   , Key_Camera           },
  { "Key_CameraFocus", Key_CameraFocus      },
  { "Key_Context1" , Key_Context1         },
  { "Key_Context2" , Key_Context2         },
  { "Key_Context3" , Key_Context3         },
  { "Key_Context4" , Key_Context4         },
  { "Key_Flip"     , Key_Flip             },
  { "Key_Hangup"   , Key_Hangup           },
  { "Key_No"       , Key_No               },
  { "Key_Select"   , Key_Select           },
  { "Key_Yes"      , Key_Yes              },
  { "Key_ToggleCallHangup", Key_ToggleCallHangup },
  { "Key_VoiceDial", Key_VoiceDial        },
  { "Key_LastNumberRedial", Key_LastNumberRedial },
  { "Key_Execute"  , Key_Execute          },
  { "Key_Printer"  , Key_Printer          },
  { "Key_Play"     , Key_Play             },
  { "Key_Sleep"    , Key_Sleep            },
  { "Key_Zoom"     , Key_Zoom             },
  { "Key_Cancel"   , Key_Cancel           },
  { "WidgetFlag"   , WidgetFlag           },
  { "WindowFlag"   , WindowFlag           },
  { "DialogFlag"   , DialogFlag           },
  { "SheetFlag"    , SheetFlag            },
  { "DrawerFlag"   , DrawerFlag           },
  { "PopupFlag"    , PopupFlag            },
  { "ToolFlag"     , ToolFlag             },
  { "ToolTipFlag"  , ToolTipFlag          },
  { "SplashScreenFlag", SplashScreenFlag     },
  { "DesktopFlag"  , DesktopFlag          },
  { "SubWindowFlag", SubWindowFlag        },
  { "ArrowCursor"  , ArrowCursor          },
  { "UpArrowCursor", UpArrowCursor        },
  { "CrossCursor"  , CrossCursor          },
  { "WaitCursor"   , WaitCursor           },
  { "IBeamCursor"  , IBeamCursor          },
  { "SizeVerCursor", SizeVerCursor        },
  { "SizeHorCursor", SizeHorCursor        },
  { "SizeBDiagCursor", SizeBDiagCursor      },
  { "SizeFDiagCursor", SizeFDiagCursor      },
  { "SizeAllCursor", SizeAllCursor        },
  { "BlankCursor"  , BlankCursor          },
  { "SplitVCursor" , SplitVCursor         },
  { "SplitHCursor" , SplitHCursor         },
  { "PointingHandCursor", PointingHandCursor   },
  { "ForbiddenCursor", ForbiddenCursor      },
  { "OpenHandCursor", OpenHandCursor       },
  { "ClosedHandCursor", ClosedHandCursor     },
  { "WhatsThisCursor", WhatsThisCursor      },
  { "BusyCursor"   , BusyCursor           },
  { "DragMoveCursor", DragMoveCursor       },
  { "DragCopyCursor", DragCopyCursor       },
  { "DragLinkCursor", DragLinkCursor       },
  { "BitmapCursor" , BitmapCursor         },
  { "MousePress"   , MousePress           },
  { "MouseRelease" , MouseRelease         },
  { "DoubleClick"  , DoubleClick          },
  { "MouseMove"    , MouseMove            },
  { NULL, 0},
};

extern "C" int luaopen_mimas_core(lua_State *L) {
  luaopen_mimas_Action(L);
  luaopen_mimas_Application(L);
  luaopen_mimas_Brush(L);
  luaopen_mimas_Button(L);
  luaopen_mimas_Callback(L);
  luaopen_mimas_CheckBox(L);
  luaopen_mimas_Color(L);
  luaopen_mimas_Cursor(L);
  luaopen_mimas_DataSource(L);
  luaopen_mimas_FileObserver(L);
  luaopen_mimas_GLWidget(L);
  luaopen_mimas_GroupBox(L);
  luaopen_mimas_HBoxLayout(L);
  luaopen_mimas_Label(L);
  luaopen_mimas_LegacyGLWidget(L);
  luaopen_mimas_LineEdit(L);
  luaopen_mimas_ListView(L);
  luaopen_mimas_MainWindow(L);
  luaopen_mimas_Menu(L);
  luaopen_mimas_MenuBar(L);
  luaopen_mimas_Painter(L);
  luaopen_mimas_Path(L);
  luaopen_mimas_Pen(L);
  luaopen_mimas_SocketNotifier(L);
  luaopen_mimas_TableView(L);
  luaopen_mimas_TabWidget(L);
  luaopen_mimas_Timer(L);
  luaopen_mimas_VBoxLayout(L);
  luaopen_mimas_Widget(L);

  // Create the table which will contain all the constants
  lua_getfield(L, LUA_GLOBALSINDEX, "mimas");
  if (lua_isnil(L, -1)) {
    // no global table called mimas
    lua_pop(L, 1);
    lua_newtable(L);
    // <lib>
    lua_pushvalue(L, -1);
    // <lib> <lib>
    // _G.mimas = <lib>
    lua_setglobal(L, "mimas");
    // <lib>
  }
  // <lib>
  // register global constants
  dub_register_const(L, mimas_const);
  luaL_register(L, NULL, mimas_functions);
  // <lib>
  lua_pop(L, 1);
  return 0;
}
