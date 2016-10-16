#if !defined(_COMBINATOR__H_)
#define _COMBINATOR__H_
#include "tableau.h"
#include "station.h"
#include "immeuble.h"

/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 *  AUTEUR(S): PHILIPPE LANDRY LANP28096606
 */

class Combinator {
public:
    
    
    Combinator( const Tableau<Station>& stations, const Tableau<Immeuble>& immeubles );
    void placerAntennes();
    
    Tableau<int> voisins( const Immeuble& immeuble , const Station& station );
private:
    
    void onCombinaison( const Tableau<int>& combine, const Tableau<int>& permutation );
    void combinate(int offset, int k );
    Tableau<int> indices;
    Tableau< Tableau<int> > permutations;
    Tableau< Tableau<int> > kChoisit2;
    Tableau<int> combinaison;
    Tableau<Station> stations;
    Tableau<Immeuble> immeubles;
    Tableau< Tableau< int>  > voisinages;
    int couvertureMax;
    Tableau<int> combineGagnante;
    Tableau<int> permuteGagnante;
    
    
};

#endif
