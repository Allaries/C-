#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
	return (this->fpoint);
}

void    Fixed::setRawBits(int const raw)
{
	this->fpoint = raw;
}

int	Fixed::ToInt() const
{
	return (this->fpoint >> 8);
}

float	Fixed::ToFloat() const
{
	return (this->fpoint / 256.0f);
}

Fixed::Fixed(int const other)
{
	std::cout << "Int construcor called\n";
	this->fpoint = other << 8;
}

Fixed::Fixed(float const other)
{
	std::cout << "Float construcor called\n";
	this->fpoint = (int)roundf(other * 256);
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

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
    out << value.ToFloat();
    return out;
}

// COMPARAISON //

bool Fixed::operator>(Fixed const &b) const
{
	return (this->getRawBits() > b.getRawBits());
}

bool Fixed::operator>=(Fixed const &b) const
{
	return (this->getRawBits() >= b.getRawBits());
}

bool Fixed::operator<(Fixed const &b) const
{
	return (this->getRawBits() < b.getRawBits());
}

bool Fixed::operator<=(Fixed const &b) const
{
	return (this->getRawBits() <= b.getRawBits());
}

bool Fixed::operator==(Fixed const &b) const
{
	return (this->getRawBits() == b.getRawBits());
}

bool Fixed::operator!=(Fixed const &b) const
{
	return (this->getRawBits() != b.getRawBits());
}

//Arithmetique//

bool Fixed::operator+(Fixed const &b) const
{

}