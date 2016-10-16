/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 */
#include <iostream>
#include <fstream>
#include "immeuble.h"
#include "station.h"
#include "tableau.h"
#include <vector>
#include "combinator.h"
// Program to print all combination of size r in an array of size n
#include <stdio.h>

using namespace std;
int tp1(std::istream& entree);


// argc: nombre d'arguments passés.
// argv: tableau de chaines de carractères.
int main(int argc, const char** argv)
{
    
    
    
    
    if(argc>1){
        // Au moins un argement est passé.
        std::ifstream fichier_entree(argv[1]);
        if(fichier_entree.fail()){
            std::cerr << "Erreur de lecture du fichier '" << argv[1] << "'" << std::endl;
            return 1;
        }
        return tp1(fichier_entree);
    }else{
        // Aucun arguement. Lecture depuis l'entrée standard avec std::cin.
        return tp1(std::cin);
    }
}




int tp1(std::istream& entree){
    
    Tableau<Station> stations;
    Tableau<Immeuble> immeubles;
    
    { // Début de la lecture.
        int nbstations=0;
        entree >> nbstations;
        
        
        for(int i=0;i<nbstations;i++){
            Station s;
            entree >> s;
            stations.ajouter(s);
        }
        
        while(entree){
            
            Immeuble immeuble;
            entree >> immeuble;
            
            if(!entree)
                break;
            immeubles.ajouter(immeuble);
        }
        
    } // Fin de la lecture.
    
    Combinator* combinator  = new Combinator(stations , immeubles);
    combinator->placerAntennes( );
    
    
    return 0;
}
