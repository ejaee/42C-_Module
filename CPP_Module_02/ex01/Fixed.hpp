#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
