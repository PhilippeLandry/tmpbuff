/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 *  AUTEUR(S): PHILIPPE LANDRY LANP28096606
 */
#include "immeuble.h"
#include <assert.h>

Immeuble::Immeuble(){}

bool
Immeuble::operator ==(const Immeuble& autre) const {
    return nom == autre.nom;
}

std::istream& operator >> (std::istream& is, Immeuble& im){
    is >> im.nom  >> im.position  >> im.hauteur  >> im.population;
    return is;
}

std::ostream& operator << (std::ostream& os, const Immeuble& im){
    os << im.nom << ' ' << im.position << ' ' << im.hauteur << ' ' << im.population;
    return os;
}
