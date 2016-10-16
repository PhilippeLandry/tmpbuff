# Makefile pour TP1.
# Adaptez ce fichier au besoin.

# Options standard.
#OPTIONS=-Wall -q

# L'option -g permet de générer les infos de débogage.
# Décommentez la ligne suivante si vous désirez utiliser un débogueur.
OPTIONS = -g -O0 -Wall

# Les options -O, -O1, -O2, -O3 permetent d'optimiser le code binaire produit.
# Décommentez la ligne suivante si avant la remise finale

OPTIONS = -O3 -Wall


tp1: tp1.cpp immeuble.o point.o station.o combinator.o tableau.h
	g++ ${OPTIONS} -o tp1 tp1.cpp immeuble.o point.o station.o combinator.o

combinator.o: combinator.cpp combinator.h tableau.h
	g++ $(OPTIONS) -c -o combinator.o combinator.cpp

immeuble.o: immeuble.h immeuble.cpp
	g++ $(OPTIONS) -c -o immeuble.o immeuble.cpp

point.o: point.h point.cpp
	g++ $(OPTIONS) -c -o point.o point.cpp

station.o: station.h station.cpp
	g++ $(OPTIONS) -c -o station.o station.cpp

clean :
	rm -f *.o
	rm -f tp1
	rm -f *~
