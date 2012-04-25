/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QListView.
 *
 * @see ListView
 * @see QWidget
 * @dub super: QWidget
 */
class QListView {
 public:
  /** Use an external model instead of the default one.
   */
  void setModel(DataSource *model);
  void scrollToBottom();
  void scrollToTop();
};
   

