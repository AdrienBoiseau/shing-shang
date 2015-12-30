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
    DRAGON = 3 , LION = 2 , SINGE = 1, PORTAIL = 0
} Type;

typedef enum
{
    ROUGE, NOIR
} Couleur;

typedef enum {
    VIDE, PION, OUT
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
    Coordonnees coordonnees;
    Pion pion;
} Case;

Case creerCase(int x, int y, int jouable);
Pion creerPion(Coordonnees coordonnes, Type type, Joueur joueur);
Joueur creerJoueur(char nom[255], Couleur couleur);
Coordonnees creerCoordonnees(int x, int y);

#endif /* model_h */
