/** This is a dummy class to create bindings for objects inheriting from Qt's
 * QPainter.
 *
 * @see Painter
 */
class QPainter {
 public:
  void fillRect(int x, int y, int width, int height, const Color &color);

  void drawPath(const Path &path);

  /** Draw a single point with the current pen.
   */
  void drawPoint(int x, int y);

  /** Draw a single line with the current pen.
   */
  void drawLine(int x1, int y1, int x2, int y2);

  /** Draw an ellipse in the given rectangle.
   */
  void drawEllipse(int x, int y, int width, int height);

};

