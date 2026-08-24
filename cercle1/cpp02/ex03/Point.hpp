#include "Fixed.hpp"

class Point
{
private:
    Fixed x;
    Fixed y;
public:
    Point ();
    Point (Fixed const x, Fixed const y);
    Point(Point const &other);
    ~Point();
    int Getx();
    int Gety();
};

bool bsp( Point const A, Point const B, Point const C, Point const P);


