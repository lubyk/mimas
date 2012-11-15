/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QBoxLayout.
 *
 * @see HBoxLayout, VBoxLayout
 * @dub super: QLayout
 */
class QBoxLayout : public QLayout {
public:
  /** Add a strechable item.
   */
  void addStretch(int stretch = 0);

  /** Add a single fixed space.
   */
  void addSpacing(int size);

  /** Fixed spacing between items.
   */
  void setSpacing(int space);
};
