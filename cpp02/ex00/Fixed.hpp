#include <iostream>

class Fixed
{
private:
    int fpoint;
    static const int fracbit = 8; 
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    
};
