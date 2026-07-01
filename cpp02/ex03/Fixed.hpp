#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fpoint;
	static const int fracbit = 8;
public:
	Fixed();
	Fixed(int const other);
	Fixed(float const other);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	
	//Class Function//

	int     ToInt() const;
	float   ToFloat() const;
	int     getRawBits(void) const;
	void    setRawBits(int const raw);
	static Fixed		&min(Fixed &n1, Fixed &n2);
	static const Fixed	&min(const Fixed &n1, const Fixed &n2);
	static Fixed		&max(Fixed &n1, Fixed &n2);
	static const Fixed	&max(const Fixed &n1, const Fixed &n2);
	
	//Comparaison//
	
	bool operator>(Fixed const &b) const;
	bool operator>=(Fixed const &b) const;
	bool operator<(Fixed const &b) const;
	bool operator<=(Fixed const &b) const;
	bool operator==(Fixed const &b) const;
	bool operator!=(Fixed const &b) const;
	
	//Arithmetique//
	
	Fixed operator+(Fixed const &b) const;
	Fixed operator-(Fixed const &b) const;
	Fixed operator*(Fixed const &b) const;
	Fixed operator/(Fixed const &b) const;

	// In/De - crementation//
	
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);
