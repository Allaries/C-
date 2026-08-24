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
    int     ToInt() const;
    float   ToFloat() const;
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);
