#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    fixedPointNumber = 0;
}

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << std::endl;
    fixedPointNumber = num << fractionalBits;
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << std::endl;
    fixedPointNumber = roundf(num * 256);
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed&  Fixed::operator=(const Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->fixedPointNumber = fixed.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& ofs, const Fixed& fixed) {
    return ofs << fixed.toFloat();
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPointNumber;
}

void    Fixed::setRawBits(const int raw) {
    fixedPointNumber = raw;
}

int Fixed::toInt() const {
    return  fixedPointNumber >> fractionalBits;
}

float Fixed::toFloat(void) const {
    return((float)fixedPointNumber / (256));
}
