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

        Fixed&  operator=(const Fixed& fixed);
        bool    operator>(const Fixed& fixed);
        bool    operator<(const Fixed& fixed);
        bool    operator>=(const Fixed& fixed);
        bool    operator<=(const Fixed& fixed);
        bool    operator==(const Fixed& fixed);
        bool    operator!=(const Fixed& fixed);

        Fixed   operator+(const Fixed& fixed);
        Fixed   operator-(const Fixed& fixed);
        Fixed   operator*(const Fixed& fixed);
        Fixed   operator/(const Fixed& fixed);

        Fixed&  operator++(void);
        Fixed&  operator--(void);
        const Fixed    operator++(int);
        const Fixed    operator--(int);

        ~Fixed();

        int     getRawBits() const;
        void    setRawBits(const int raw);

        static Fixed&  min(Fixed& fixedA, Fixed& fixedB);
        static const Fixed&  min(const Fixed& fixedA, const Fixed& fixedB);
        static Fixed&  max(Fixed& fixedA, Fixed& fixedB);
        static const Fixed&  max(const Fixed& fixedA, const Fixed& fixedB);

        int     toInt() const;
        float   toFloat() const;
};

    std::ostream& operator<<(std::ostream& ofs, const Fixed& fixed);

#endif
