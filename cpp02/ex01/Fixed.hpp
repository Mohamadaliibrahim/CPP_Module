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
        friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
        ~Fixed();

        float   toFloat(void) const;
        int     toInt(void) const;
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};
#endif