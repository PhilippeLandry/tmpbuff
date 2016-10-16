/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 */
#include <assert.h>
#include <math.h>
#include "point.h"
#include <iostream>

Point::Point(const Point& point)
: x(point.x), y(point.y)
{
}

Point::Point(double x_, double y_)
: x(x_), y(y_)
{
}

double Point::distance(const Point& point) const
{
    double x = point.x - this->x;
    double y = point.y - this->y;
    return sqrt(x*x + y*y);
}

std::ostream& operator << (std::ostream& os, const Point& point) {
    os << "(" << point.x << "," << point.y << ")";
    return os;
}

std::istream& operator >> (std::istream& is, Point& point) {
    char po, vir, pf;
    is >> po;
    if(is){
        is >> point.x >> vir >> point.y >> pf;
        
    }
    return is;
}
