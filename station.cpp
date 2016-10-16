/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 *  AUTEUR(S): PHILIPPE LANDRY LANP28096606
 */
#include "station.h"
#include <assert.h>
#include <iostream>

Station::Station() : rayon(-1.0) , hauteurMax(-1.0), freq(-1.0) {}

bool
Station::operator == (const Station& autre) const{
    return nom == autre.nom;
}



std::istream& operator >> (std::istream& is, Station& s){
    
    is >> s.nom >>  s.rayon  >> s.hauteurMax >> s.freq;
    assert( s.rayon >= 0.0 );
    assert( s.hauteurMax >= 0.0 );
    assert( s.freq >= 0.0 );
    return is;
}

std::ostream& operator << (std::ostream& os, const Station& s) {
    os << s.nom << ' ';
    os << s.rayon << ' ';
    os << s.hauteurMax << ' ';
    os << s.freq;
    
    return os;
}
