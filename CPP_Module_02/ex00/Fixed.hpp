#ifndef FIXED_HPP
# define FIXED_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

# include <iostream>

class Fixed {

    private:
        int fixedPointNumber;
        static const int fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed();
        int     getRawBits() const;
        void    setRawBits(const int raw);
};

#endif
