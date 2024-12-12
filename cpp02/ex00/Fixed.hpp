#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
    private:
        int                 _rb;
        int jnde;
        static const int    _fb = 8;

    public:
        Fixed();
        Fixed(const Fixed &that);
        Fixed &operator=(const Fixed &that);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};
#endif