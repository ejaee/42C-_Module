#ifndef FIXED_HPP
# define FIXED_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

# include <iostream>
# include <cmath>

class Fixed {

    private:
        int fixedPointNumber;
        static const int fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed();
        int     getRawBits() const;
        void    setRawBits(const int raw);

        int     toInt() const;
        float   toFloat() const;
};

    std::ostream& operator<<(std::ostream& ofs, const Fixed& fixed);


#endif
