#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fpoint);
}

void    Fixed::setRawBits(int const raw)
{
    this->fpoint = raw;
}

Fixed::Fixed():fpoint(0)
{
    std::cout << "Default construcor called\n";
}

Fixed::Fixed(Fixed const &other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed& Fixed::operator=(Fixed const &other){
    std::cout << "Copy assignment operator called\n";
    this->fpoint = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}
