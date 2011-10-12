namespace mimas {

/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QWidget.
 *
 * @see Widget
 * @see QObject
 * @dub bind: 'QWidget.yml'
 *      super: 'QObject'
 */
class QWidget {
 public:
  void move(int x, int y);
  void resize(int w, int h);
  int x();
  int y();
  int width();
  int height();
  void setParent(QWidget *parent);
  void update();
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

  // ==============================================
  // === custom (implementation in QWidget.yml)
  // ==============================================

  void widget();
  void addWidget(QWidget *widget, float x=0, float y=0);

  /** Return the size of the widget as a pair (width, height).
   */
  void size();
  void setStyle(const char *text);
  void setStyleSheet(const char *text);
  /** Get size of text with current widget font.
   */
  void textSize(const char *text);
  /** Set the prefered size. Use setSizePolicy to define how the
   * widget resizes compared to this value.
   */
  void setSizeHint(float w, float h);

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
  /** Move the widget to the given global coordinates.
   */
  void globalMove(float x, float y);
};

} // mimas