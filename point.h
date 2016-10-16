/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 */
#if !defined(_POINT__H_)
#define _POINT__H_
#include <iostream>

class Point {
public:
    Point(const Point&);
    Point(double x=0, double y=0);
    double distance(const Point&) const;
    
    double x;
    double y;
private:
    friend std::istream& operator >> (std::istream&, Point&);
    friend std::ostream& operator << (std::ostream&, const Point&);
};
#endif

