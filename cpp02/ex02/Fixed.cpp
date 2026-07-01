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

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

// COMPARAISON //

Fixed& Fixed::operator=(Fixed const &other){
	std::cout << "Copy assignment operator called\n";
	this->fpoint = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
    out << value.ToFloat();
    return out;
}

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

Fixed Fixed::operator+(Fixed const &b) const
{
	Fixed c;
	c.setRawBits(this->getRawBits() + b.getRawBits());
	return (c);
}

Fixed Fixed::operator-(Fixed const &b) const
{
	Fixed c;
	c.setRawBits(this->getRawBits() - b.getRawBits());
	return (c);
}

Fixed Fixed::operator*(Fixed const &b) const
{
	Fixed c;
	c.setRawBits((this->getRawBits() * b.getRawBits()) / 256);
	return (c);
}

Fixed Fixed::operator/(Fixed const &b) const
{
	Fixed c;
	c.setRawBits((this->getRawBits() * 256) / b.getRawBits());
	return (c);
}

//Incrementation//

Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed ret(*this);
	this->setRawBits(this->getRawBits() + 1);
	return (ret);
}

Fixed Fixed::operator--(int)
{
	Fixed ret(*this);
	this->setRawBits(this->getRawBits() - 1);
	return (ret);
}

Fixed	&Fixed::min(Fixed &n1, Fixed &n2)
{
	return (n1 < n2 ? n1 : n2);
}
const Fixed	&Fixed::min(const Fixed &n1, const Fixed &n2)
{
	return ((n1 < n2) ? n1 : n2);
}
Fixed	&Fixed::max(Fixed &n1, Fixed &n2)
{
	return (n1 > n2 ? n1 : n2);
}
const Fixed	&Fixed::max(const Fixed &n1, const Fixed &n2)
{
	return (n1 > n2 ? n1 : n2);
}