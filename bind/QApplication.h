/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QApplication.
 *
 * @see Application
 * @see QObject
 * @dub super: QObject
 */
class QApplication {
 public:
   
  void quit();

  /** If this is true (default), mimas quits when the last window is closed.
   */
  void setQuitOnLastWindowClosed(bool quit);
 
  void setStyleSheet(QString text);

  QString styleSheet();

  static void setAttribute(int key, bool value);
};

