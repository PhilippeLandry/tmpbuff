/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 *  AUTEUR(S): PHILIPPE LANDRY LANP28096606
 */
#include "combinator.h"
#include <iostream>


using namespace std;


// échanger deux valeurs
void swap(int *fir, int *sec)
{
    int temp = *fir;
    *fir = *sec;
    *sec = temp;
}


void
Combinator::permutation(int * arr, int curr, int size, Tableau<Tableau<int> >& callback)
{
    if(curr == size-1)
    {
        Tableau<int> t;
        for(int a=0; a<size; a++){
            t.ajouter(arr[a]);
        }
        callback.ajouter(t);
        
        
    }
    
    else
    {
        for(int i=curr; i<size; i++)
        {
            swap(&arr[curr], &arr[i]);
            permutation(arr, curr+1, size, callback);
            swap(&arr[curr], &arr[i]);
        }
    }
}

Tableau<int>
Combinator::voisins( const Immeuble& immeuble , const Station& station ) {
    
    
    Tableau<int> resultat;
    
    float xmin = immeuble.position.x - station.rayon;
    float xmax = immeuble.position.x + station.rayon;
    float ymin = immeuble.position.y - station.rayon;
    float ymax = immeuble.position.y + station.rayon;
    
    for( int i = 0 ; i < this->immeubles.taille(); i++){
        
        // on continue si immeuble hors du bounding box
        if( this->immeubles[i].position.x < xmin) continue;
        if( this->immeubles[i].position.x > xmax) continue;
        if( this->immeubles[i].position.y < ymin) continue;
        if( this->immeubles[i].position.y > ymax) continue;
        
        // ajouter l'immeuble à la liste si couvert part la station
        float distance = immeuble.position.distance( this->immeubles[i].position);
        if( distance <= station.rayon ){
            resultat.ajouter(i);
        }
    }
    
    
    return resultat;
    
}

Combinator::Combinator( const Tableau<Station>& stations, const Tableau<Immeuble>& immeubles )
{
    this->stations = stations;
    this->immeubles = immeubles;
    this->couvertureMax = 0;
    
    // On crée un tableau de permutations de k
    int k = stations.taille();
    int* str = new int[k];
    for( int i = 0 ; i < k; i++){
        str[i] = i;
    }
    permutation(str, 0, k, this->permutations);
    delete [] str;

    
    // on créer un tableau de k choisit 2
    int idx(0);
    for( int i = 0 ; i < k; i++){
        for(int j = i + 1 ; j < k ; j ++ , idx++){
            this->kChoisit2.ajouter(Tableau<int>());
            this->kChoisit2[idx].ajouter(i);
            this->kChoisit2[idx].ajouter(j);
        }
    }
}






void
Combinator::combinate(int offset, int k ) {
    
    if (k == 0) {
        for( int i = 0 ; i < this->permutations.taille(); i++){
            this->onCombinaison( combinaison , this->permutations[i]);
        }
        return;
    }
    
    
    for (int i = offset; i <= indices.taille() - k; ++i) {
        
        combinaison.ajouter(indices[i]);
        combinate(i+1, k-1);
        combinaison.enlever( combinaison.taille() -1);
    }
}


void Combinator::onCombinaison( const Tableau<int>& combine, const Tableau<int>& permutation ){
    
    
    // On regarde si les antennes sont compatibles sur leur position
    for( int i = 0; i < combine.taille(); i ++ ){
        
        if(this->immeubles[combine[i]].hauteur < this->stations[permutation[i]].hauteurMin ){
            // rejeté car hauteur incompatible
            
            return;
        }
    }
    
    
    
    // On regarde si il y a des interférences entre les antennes
    if( this->stations.taille() > 1 ){
        for( int i = 0;  i < this->kChoisit2.taille(); i++){
            const Immeuble& immeubleA = this->immeubles[combine[kChoisit2[i][0]]];
            const Station& stationA = this->stations[permutation[kChoisit2[i][0]]];
            const Immeuble& immeubleB = this->immeubles[combine[kChoisit2[i][1]]];
            const Station& stationB = this->stations[permutation[kChoisit2[i][1]]];
            
            // ON PASSE LA VALIDATION SI LES DEUX STATIONS N'ONT PAS LA MÊME FRÉQUENCE
            if( stationA.freq != stationB.freq ){
                continue;
            }
            
            // ON BLOQUE SI LES DEUX STATIONS SONT TROP PROCHES
            float distance = immeubleA.position.distance( immeubleB.position );
            float rayon = stationA.rayon + stationB.rayon;
            if( distance <= rayon ){
                // on passe si par chance l'antenne est inclue
                if( distance + stationA.rayon <= stationB.rayon || distance + stationB.rayon <= stationA.rayon ){
                    continue;
                }
                return;
            }
         
            
            
        }
    }
    
    
    // On calcule la couverture de la combinaison
    Tableau<int> couverture;
    for( int i = 0 ; i < combine.taille(); i ++ ){
        
        
        
        Immeuble immeuble = this->immeubles[combine[i]];
        Station station = this->stations[permutation[i]];
        Tableau<int> voisins =  this->voisins(immeuble, station);
        if( i == 0 ){
            couverture = voisins;
            continue;
        }
        
        Tableau<int> nouveauxVoisins;
        for( int j = 0; j < voisins.taille(); j++){
            if( couverture.trouver( voisins[j]) == -1 ){
                nouveauxVoisins.ajouter(voisins[j]);
            }
        }
        
        for( int k = 0 ; k < nouveauxVoisins.taille(); k++){
            couverture.ajouter(nouveauxVoisins[k]);
        }
    }
    
    float couvertureCourante(0);
    for( int i = 0 ; i < couverture.taille() ; i++){
        couvertureCourante += this->immeubles[couverture[i]].population;
    }
    
    
    if( couvertureCourante > couvertureMax ){
        couvertureMax = couvertureCourante;
        combineGagnante = combine;
        permuteGagnante = permutation;
    }
}

void
Combinator::placerAntennes(  ) {
    
    for (int i = 0; i < this->immeubles.taille(); ++i) {
        indices.ajouter(i);
    }
    combinate(0, this->stations.taille() );
    
    for( int i = 0 ; i < stations.taille(); i++){
        Immeuble immeuble = this->immeubles[combineGagnante[i]];
        Station station = this->stations[permuteGagnante[i]];
        
        // ON REGARDE SI LA STATION EST INUTILE
        bool inutile(false);
        for( int j = 0 ; j < stations.taille(); j++ ){
            if( i == j) continue;
            Immeuble im = this->immeubles[combineGagnante[j]];
            Station st = this->stations[permuteGagnante[j]];
            float distance = im.position.distance(immeuble.position);
            if( distance + station.rayon <= st.rayon){
                inutile = true;
                break;
            }
        }
        
        cout << station.nom << " " << (inutile ? "--" : immeuble.nom) << endl;
    
        
    }
    cout << couvertureMax << endl;
}


