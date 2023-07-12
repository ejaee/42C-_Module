#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y)
	: _x(x), _y(y) {}

Point::Point(const Point& point)
	: _x(point.getX()), _y(point.getY()) {
}

Point& Point::operator=(const Point& point) {
	if (this != &point) {
		const_cast<Fixed&>(_x) = point.getX();
		const_cast<Fixed&>(_y) = point.getY();
	}
	return *this;
}

Point::~Point() {
}

const Fixed& Point::getX() const {
	return this->_x;
}

const Fixed& Point::getY() const {
	return this->_y;
}

std::ostream& operator<<(std::ostream& ofs, const Point& point) {
	return ofs << "( " << point.getX().toFloat() << ", " << point.getY().toFloat() << " )";
}
