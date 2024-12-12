#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed
{
    private:
        int                 _rb;
        static const int    _fb = 8;

    public:
        Fixed();
        Fixed(const Fixed &that);
        Fixed(const int raw);
        Fixed(const float raw);
        Fixed &operator=(const Fixed &that);
        bool operator>(const Fixed &that);       
        bool operator<(const Fixed &that);
        bool operator>=(const Fixed &that);
        bool operator<=(const Fixed &that);
        bool operator==(const Fixed &that);
        bool operator!=(const Fixed &that);
        Fixed operator+(const Fixed &that);
        Fixed operator-(const Fixed &that);
        Fixed operator*(const Fixed &that);
        Fixed operator/(const Fixed &that);
        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);
        friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
        ~Fixed();

        static  Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static  Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

        float   toFloat(void) const;
        int     toInt(void) const;
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};
#endif