#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
    fixedPointNumber = 0;
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
