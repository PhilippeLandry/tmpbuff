#if !defined(_COMBINATOR__H_)
#define _COMBINATOR__H_
#include "Tableau.h"
#include "Station.h"
#include "Immeuble.h"



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
    float maxRayon;
    
    
};

#endif
