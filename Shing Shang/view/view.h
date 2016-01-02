//
//  view.h
//  Shing Shang
//
//  Created by Adrien Boiseau on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#ifndef view_h
#define view_h

#include "../model/model.h"

#define NBLIGNE 12
#define NBCOLONE 12

void initialiser();
void afficherDamier();
Joueur* choixJoueur();

TypeCase verifierCase(int x, int y);
Case* recupererCellule(Coordonnees coordonnees);
Joueur* recupererJoueur(Couleur couleur);

Coordonnees preparerDeplacement(Coordonnees depart, Type typePion, Direction direction);
void deplacerPion(Coordonnees depart, Coordonnees arrive, Direction direction);
Coordonnees sauterPion(Case *cellule, Direction direction);

void jouerCoup();
void run();

#endif /* view_h */
