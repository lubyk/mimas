/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QLineEdit.
 *
 * @see LineEdit
 * @see QWidget
 * @dub super: QWidget
 */
class QLineEdit {
 public:
  void setText(const QString &str);

  QString text() const;

  void setSelection(int start, int length);

  void selectAll();
};
   
