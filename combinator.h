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
    
    
    // Constructer publique avant une tableau d'antennes et un tableau d'immeubles
    Combinator( const Tableau<Station>& stations, const Tableau<Immeuble>& immeubles );
    
    // Placer les antennes dans la position maximale
    void placerAntennes();
    
    
private:
    
    // Obtenir tous les voisins d'une station positionnée sur un immeuble
    Tableau<int> voisins( const Immeuble& immeuble , const Station& station );
    
    // Appellé pour chacune des combinaison.
    // combine: les immeubles choisis
    // permutation: la position de chaque antenne
    void onCombinaison( const Tableau<int>& combine, const Tableau<int>& permutation );
    
    
    // énumérer recursivement chacune des positions possibles
    void combinate(int offset, int k );
    
    // une fonction recursive pour enumerer les permutaions
    void permutation(int * arr, int curr, int size, Tableau<Tableau<int> >& callback);
    
    // indices de la combinaison courante
    Tableau<int> indices;
    
    // permutations d'entennes
    Tableau< Tableau<int> > permutations;
    
    // un tableau de k choisi 2
    Tableau< Tableau<int> > kChoisit2;
    
    // la combinaison courante
    Tableau<int> combinaison;
    
    // les antennes disponibles
    Tableau<Station> stations;
    
    // les immeubles disponibles
    Tableau<Immeuble> immeubles;
    
    
    // la couverture maximum
    int couvertureMax;
    
    // la combinaison gangante (liste d"immeubles)
    Tableau<int> combineGagnante;
    
    
    // la permutaion gangante: liste d'antennes 
    Tableau<int> permuteGagnante;
    
    
};

#endif
