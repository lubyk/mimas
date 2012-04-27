/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QAction.
 *
 * @see Action
 * @see QObject
 * @dub super: QObject
 *      bind:  'QAction.yml'
 */
class QAction {
 public:
  QString text();
  void setText(const QString &txt);
  bool isChecked() const;
  void setChecked(bool on);
  bool isEnabled() const;
  void setEnabled(bool on);
  bool isCheckable() const;
  void setCheckable(bool on);
};
