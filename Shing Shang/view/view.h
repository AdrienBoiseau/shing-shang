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
int choixjoueur(int joueur);

TypeCase verifierCase(int x, int y);
void deplacerPion(Coordonnees depart, Coordonnees arrive);
void jouerCoup();

#endif /* view_h */
