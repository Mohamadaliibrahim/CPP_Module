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