/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 */
#if !defined(_IMMEUBLE__H_)
#define _IMMEUBLE__H_
#include <iostream>
#include <string>
#include "Point.h"
class Immeuble
{
public:
    Immeuble();
    bool operator ==(const Immeuble& autre) const;
    
    
public:
    std::string nom;
    Point position;
    float hauteur;
    int population;
    
    
    friend std::istream& operator >> (std::istream&, Immeuble&);
    
    
    friend std::ostream& operator << (std::ostream&, const Immeuble&);
};
#endif