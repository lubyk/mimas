/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QListView.
 *
 * @see ListView
 * @see QWidget
 * @dub super: QWidget
 */
class QListView {
 public:
  /** Set data source model.
   */
  void setModel(DataSource *model);
  void scrollToBottom();
  void scrollToTop();
};
   

