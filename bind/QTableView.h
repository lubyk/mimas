/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QTableView.
 *
 * @see TableView
 * @see QWidget
 * @dub super: QWidget
 */
class QTableView {
 public:
  /** Set data source model.
   */
  void setModel(DataSource *model);
  void scrollToBottom();
  void scrollToTop();
  void setAlternatingRowColors(bool enable);
  void setShowGrid(bool enable);
  void resizeColumnsToContents();
};
   

