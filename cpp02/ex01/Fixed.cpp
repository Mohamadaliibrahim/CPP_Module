#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout<<"Default constructor called"<< std::endl;
    _rb = 0;
}
Fixed::~Fixed()
{
    std::cout<<"Destructor called"<< std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_rb);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _rb = raw;
}

Fixed::Fixed(const Fixed &that)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = that;
}

Fixed &Fixed::operator=(const Fixed &there)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &there)
        _rb = there.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

Fixed::Fixed(const int raw)
{
    std::cout<<"Int constructor called"<<std::endl;
    _rb = raw << _fb;
}

Fixed::Fixed(const float raw)
{
    float   temp;
    std::cout<<"Float constructor called"<<std::endl;
    temp = raw * (1 << _fb);
    _rb = roundf(temp);
}

float   Fixed::toFloat(void) const
{
    return ((float)_rb / (1 << _fb));
}

int     Fixed::toInt(void) const
{
    return (_rb >>_fb);
}
