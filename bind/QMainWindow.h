/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QMainWindow.
 *
 * @see QWidget
 * @dub super: QWidget
 *
 */
class QMainWindow {
 public:
  void setMenuBar(MenuBar *bar);
  void setCentralWidget(QWidget *w);
};

