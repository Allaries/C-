#include "Fixed.hpp"

int Fixed::getRawBits(void)
{
    
}

Fixed::Fixed():fpoint(0)
{
    std::cout << "Construcor called\n";
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called\n";
    this->fpoint = new int(*other.fpoint);
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
    {
        delete fpoint;
        fpoint = new int(*other.fpoint);
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
    delete fpoint;
}
