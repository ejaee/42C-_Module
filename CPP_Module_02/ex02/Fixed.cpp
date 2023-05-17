#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
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
    std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
    *this = fixed;
}

Fixed&  Fixed::operator=(const Fixed& fixed) {
    std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
    if (this != &fixed)
        this->fixedPointNumber = fixed.getRawBits();
    return *this;
}

bool    Fixed::operator>(const Fixed& fixed) {
    return this->fixedPointNumber > fixed.fixedPointNumber;
}

bool    Fixed::operator<(const Fixed& fixed) {
    return this->fixedPointNumber < fixed.fixedPointNumber;
}

bool    Fixed::operator>=(const Fixed& fixed) {
    return this->fixedPointNumber >= fixed.fixedPointNumber;
}

bool    Fixed::operator<=(const Fixed& fixed) {
    return this->fixedPointNumber <= fixed.fixedPointNumber;
}

bool    Fixed::operator==(const Fixed& fixed) {
    return this->fixedPointNumber == fixed.fixedPointNumber;
}

bool    Fixed::operator!=(const Fixed& fixed) {
    return this->fixedPointNumber != fixed.fixedPointNumber;
}

Fixed   Fixed::operator+(const Fixed& fixed) {
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed   Fixed::operator-(const Fixed& fixed) {
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed   Fixed::operator*(const Fixed& fixed) {
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed   Fixed::operator/(const Fixed& fixed) {
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed&  Fixed::operator++(void) {
    this->fixedPointNumber++;
    return *this;
}

Fixed&  Fixed::operator--(void) {
    this->fixedPointNumber--;
    return *this;
}

const Fixed  Fixed::operator++(int) {
    const Fixed temp(*this);

    this->fixedPointNumber++;
    return temp;
}

const Fixed  Fixed::operator--(int) {
    const Fixed temp(*this);

    this->fixedPointNumber--;
    return temp;
}

std::ostream& operator<<(std::ostream& ofs, const Fixed& fixed) {
    return ofs << fixed.toFloat();
}

Fixed::~Fixed() {
    std::cout << RED << "Destructor called" << RESET << std::endl;
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

Fixed&  Fixed::min(Fixed& fixedA, Fixed& fixedB) {
    return (fixedA.getRawBits() <= fixedB.getRawBits()) ? fixedA : fixedB;
}

const Fixed&  Fixed::min(const Fixed& fixedA, const Fixed& fixedB) {
    return (fixedA.getRawBits() <= fixedB.getRawBits()) ? fixedA : fixedB;
}

Fixed&  Fixed::max(Fixed& fixedA, Fixed& fixedB) {
    return (fixedA.getRawBits() >= fixedB.getRawBits()) ? fixedA : fixedB;
}

const Fixed&  Fixed::max(const Fixed& fixedA, const Fixed& fixedB) {
    return (fixedA.getRawBits() >= fixedB.getRawBits()) ? fixedA : fixedB;
}
