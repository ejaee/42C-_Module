#ifndef POINT_H_
# define POINT_H_

#include <iostream>
#include "Fixed.hpp"

class Point {
  private:
    Fixed const _x;
    Fixed const _y;

  public:
    Point();
    Point(const float x, const float y);
    Point(const Point& point);
    Point& operator=(const Point& point);
    ~Point();
    const Fixed& getX() const;
    const Fixed& getY() const;
};

std::ostream& operator<<(std::ostream& ofs, const Point& point);

bool bsp(Point const a, Point const b, Point const c, Point const point);
Point operator-(const Point &point1, const Point &point2);
Fixed	operator*(const Point& point1, const Point& point2);
bool operator~(const Fixed& fixed);

#endif
