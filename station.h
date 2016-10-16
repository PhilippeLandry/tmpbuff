/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 */
#if !defined(_STATION__H_)
#define _STATION__H_
#include <iostream>
#include <string>

class Station
{
public:
    Station();
    
    bool operator == (const Station& autre) const;
    
    
    std::string nom;
    float rayon;
    float hauteurMax;
    float freq;
    
    friend std::istream& operator >> (std::istream&, Station&);
    friend std::ostream& operator << (std::ostream&, const Station&);
};
#endif
