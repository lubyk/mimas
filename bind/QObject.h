/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QObject.
 *
 */
class QObject {
 public:
  QString objectName() const;
  void setObjectName(const QString &name);
  QVariant property(const char *name);
  bool setProperty(const char *name, const QVariant &value);
  void setParent(QObject *parent);
  QObject *parent();
};
