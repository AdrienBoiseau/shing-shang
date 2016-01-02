//
//  model.h
//  Shing Shang
//
//  Created by Paul on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#ifndef model_h
#define model_h

typedef enum
{
    DRAGON = 3 , SINGE = 1, LION = 2, PORTAIL = 9
} Type;

typedef enum
{
   HAUT = 1, HAUTDROIT = 2, DROIT = 3, BASDROIT = 4, BAS = 5, BASGAUCHE = 6, GAUCHE = 7, HAUTGAUCHE = 8
} Direction;

typedef enum
{
    NOIR, ROUGE
} Couleur;

typedef enum {
    VIDE, PION, OUT, OBJET
} TypeCase;

typedef struct
{
    char *nom;
    Couleur couleur;
} Joueur;

typedef struct
{
    int x;
    int y;
} Coordonnees;

typedef struct
{
    Type type;
    Coordonnees cordonnees;
    Joueur joueur;
} Pion;

typedef struct
{
    int jouable;
    int pleine;
    Coordonnees coordonnees;
    Pion pion;
} Case;

Case creerCase(int x, int y, int jouable, int pleine);
void remplirCase(Case *cellule);
void updateCase(Case *celluleDepart, Case *celluleArrivee);

Pion creerPion(Coordonnees coordonnes, Type type, Joueur joueur);
Joueur creerJoueur(char nom[255], Couleur couleur);
Coordonnees creerCoordonnees(int x, int y);
Coordonnees coordonneesDeplacement(Direction direction);

Coordonnees haut(Coordonnees initial, Type typePion);
Coordonnees hautdroit(Coordonnees initial, Type typePion);
Coordonnees droit(Coordonnees initial, Type typePion);
Coordonnees basdroit(Coordonnees initial, Type typePion);
Coordonnees bas(Coordonnees initial, Type typePion);
Coordonnees basgauche(Coordonnees initial, Type typePion);
Coordonnees gauche(Coordonnees initial, Type typePion);
Coordonnees hautgauche(Coordonnees initial, Type typePion);

#endif /* model_h */
