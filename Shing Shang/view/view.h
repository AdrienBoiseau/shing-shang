//
//  view.h
//  Shing Shang
//
//  Created by Paul on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#ifndef view_h
#define view_h

#define NBLIGNE 12
#define NBCOLONE 12

void initialiser();
void afficherDamier();
Joueur* choixJoueur();

TypeCase verifierCase(int x, int y);
Case* recupererCellule(Coordonnees coordonnees);
Joueur* recupererJoueur(Couleur couleur);

void deplacerPion(Coordonnees depart, Coordonnees arrive);
void jouerCoup();
void run();

#endif /* view_h */
