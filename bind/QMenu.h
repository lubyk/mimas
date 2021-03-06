/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QMenu.
 *
 * @see Menu
 * @see QWidget
 * @dub super: QWidget
 */
class QMenu {
 public:
  void addAction(Action *action);
  void addSeparator();
  /** Remove all actions.
   */
  void clear();
};

