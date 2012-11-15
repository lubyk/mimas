/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QLayout. This class is empty and is only used to enable type
 * casting to QLayout.
 *
 * @see HBoxLayout
 * @see VBoxLayout
 * @see QObject
 * @dub super: QObject
 */
class QLayout {
 public:
  void activate();
  bool setAlignment(QWidget *w, int alignment);
  LuaStackSize minimumSize(lua_State *L);
  void setContentsMargins(int left, int top, int right, int bottom);
};

