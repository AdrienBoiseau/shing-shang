//
//  app.h
//  Shing Shang
//
//  Created by Adrien Boiseau on 30/12/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#ifndef app_h
#define app_h

#include <stdio.h>
#include "model.h"

#define COULEUR_NOIR "30"
#define COULEUR_ROUGE "31"

#define clrscr() printf("\033[H\033[2J")
#define couleur(param) printf("\033[%sm", param)

void viderBuffer();
Coordonnees recupererCoordonnees();

// fonction d'affichage
void afficherErreurDeplacement(TypeCase type);
void afficherTourJoueur(Joueur *joueur);


#endif /* app_h */
