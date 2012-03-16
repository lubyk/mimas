/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QWidget.
 *
 * @see Widget
 * @see QObject
 * @dub bind: 'QWidget.yml'
 */
class QWidget : public QObject {
 public:
  void move(int x, int y);
  void resize(int w, int h);
  int x();
  int y();
  int width();
  int height();
  void setParent(QWidget *parent);
  void update();
  void adjustSize();
  void setFocus();
  void setFocusPolicy(int policy);
  void setAttribute(int attr, bool enabled);

  // FIXME: maybe we can remove this and only use setSizeHint + setSizePolicy...
  void setMinimumSize(float w, float h);
  /** Receive mouse move events even if no button is pressed.
   */
  void setMouseTracking(bool enable);
  bool close();
  bool isVisible();
  void show();
  void hide();
  void lower();
  void raise();
  void activateWindow();
  bool isFullScreen();
  void addAction(Action *action);
  void setWindowTitle(const QString &text);
  QString windowTitle();

  // ==============================================
  // === custom (implementation in QWidget.yml)
  // ==============================================

  void addWidget(QWidget *widget);

  /** Return the size of the widget as a pair (width, height).
   */
  LuaStackSize size();
  void setStyle(const char *text);
  void setStyleSheet(const char *text);
  /** Get size of text with current widget font.
   */
  void textSize(const char *text);
  
  void setCssClass(const char *css_class);
  void setSizeHit(int w, int h);

  /** Control how the widget behaves in a layout related to it's sizeHint().
   */
  void setSizePolicy(int horizontal, int vertical);
  
  void showFullScreen(bool enable=true);

  /** Swap fullscreen mode.
   */
  void swapFullScreen();
  /** Returns (x,y) position of the widget in the global
   * screen coordinates.
   */
  LuaStackSize globalPosition();

  /** Returns (x,y) position of the widget in the parent
   * coordinates.
   */
  LuaStackSize position();

  /** Move the widget to the given global coordinates.
   */
  void globalMove(float x, float y);
};

