#ifndef app_h
#define app_h

#include <stdio.h>
#include "model.h"

#define COULEUR_NOIR "30"
#define COULEUR_ROUGE "31"

#define clrscr() printf("\033[H\033[2J")
#define couleur(param) printf("\033[%sm", param)

//Ficher de header pour les fonctions de coordonnees
void viderBuffer();
Coordonnees recupererCoordonnees();
Direction recupererDirection();

// fonction d'affichage
void afficherErreurDeplacement(TypeCase type);
void afficherTourJoueur(Joueur *joueur);
char* afficherTypeCase(Type type);

#endif /* app_h */
