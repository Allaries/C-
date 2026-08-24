#include "Point.hpp"

int cross(Point A, Point B, Point P)
{
    int m = (B.Getx() - A.Getx()) * (P.Gety() - A.Gety()) / 256;
    int n = (B.Gety() - A.Gety()) * (P.Getx() - A.Getx()) / 256;
    return (m - n);
    //(B.x - A.x)*(P.y - A.y) - (B.y - A.y)*(P.x - A.x)
}

bool bsp( Point const A, Point const B, Point const C, Point const P)
{
    int d1 = cross(A, B, P);
    int d2 = cross(B, C, P);
    int d3 = cross(C, A, P);
    if (d1 > 0)
    {
        if (d2 > 0 && d3 > 0)
            return (true);
    }
    if (d1 < 0)
    {
        if (d2 < 0 && d3 < 0)
            return (true);
    }
    if (d1 == 0)
        return (false);
    return (false);
}

Point::Point()
{
    Fixed x;
    Fixed y;
    std::cout << "Default constructor called\n";
    this->x = y;
    this->y = x;
}

Point::Point(Fixed const x, Fixed const y)
{
	std::cout << "Some constructor called\n";
    this->x = x;
    this->y = y;
}

Point::~Point()
{
}

Point::Point(Point const &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

int Point::Getx()
{
    return(this->x.getRawBits());
}

int Point::Gety()
{
    return(this->y.getRawBits());
}