
#include "Point.hpp"

Point operator-(const Point& point1, const Point& point2) {
  return Point(
      (point1.getX() - point2.getX()).toFloat(),
      (point1.getY() - point2.getY()).toFloat());
}

Fixed	operator*(const Point& point1, const Point& point2)
{
	return Fixed(
    point1.getX() * point2.getY() -
    point1.getY() * point2.getX());
}

bool operator~(const Fixed& fixed)
{
	return (fixed > Fixed(0));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
  Point ab = a - b;
  Point ap = a - point;

  Point bc = b - c;
  Point bp = b - point;
  
  Point ca = c - a;
  Point cp = c - point;

  if ((~(ab * bp) && ~(bc * cp) && ~(ca * ap))
    || (!(~(ab * bp)) && !(~(bc * cp)) && !(~(ca * ap))))
    return true;
  return false;
}
