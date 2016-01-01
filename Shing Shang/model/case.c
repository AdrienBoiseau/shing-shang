//
//  case.c
//  Shing Shang
//
//  Created by Paul on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include "model.h"

Case creerCase(int x, int y, int jouable, int pleine)
{
    Case nouvelleCase;
    nouvelleCase.coordonnees.x = x;
    nouvelleCase.coordonnees.y = y;
    nouvelleCase.jouable = jouable;
    nouvelleCase.pleine = pleine;
    
    return nouvelleCase;
}

void remplirCase(Case *cellule) {
    cellule->pleine = 1;
}

Coordonnees haut(Coordonnees initial, Type typePion) {
    switch (typePion) {
        case SINGE:
        case DRAGON:
            return creerCoordonnees(initial.x, initial.y - 2);
            break;
        default:
            return creerCoordonnees(initial.x, initial.y - 1);
            break;
    }
}

Coordonnees hautgauche(Coordonnees initial, Type typePion) {
    switch (typePion) {
        case SINGE:
        case DRAGON:
            return creerCoordonnees(initial.x - 2, initial.y - 2);
            break;
        default:
            return creerCoordonnees(initial.x - 1, initial.y - 1);
            break;
    }
}

Coordonnees droit(Coordonnees initial, Type typePion) {
    switch (typePion) {
        case SINGE:
        case DRAGON:
            return creerCoordonnees(initial.x + 2, initial.y);
            break;
        default:
            return creerCoordonnees(initial.x + 1, initial.y);
            break;
    }
    
}

Coordonnees basdroit(Coordonnees initial, Type typePion) {
    switch (typePion) {
        case SINGE:
        case DRAGON:
            return creerCoordonnees(initial.x + 2, initial.y + 2);
            break;
        default:
            return creerCoordonnees(initial.x + 1, initial.y + 1);
            break;
    }
    
}

Coordonnees bas(Coordonnees initial, Type typePion) {
    switch (typePion) {
        case SINGE:
        case DRAGON:
            return creerCoordonnees(initial.x, initial.y + 2);
            break;
        default:
            return creerCoordonnees(initial.x, initial.y + 1);
            break;
    }
    
}

Coordonnees basgauche(Coordonnees initial, Type typePion) {
    switch (typePion) {
        case SINGE:
        case DRAGON:
            return creerCoordonnees(initial.x - 2, initial.y + 2);
            break;
        default:
            return creerCoordonnees(initial.x - 1, initial.y + 1);
            break;
    }
    
}

Coordonnees gauche(Coordonnees initial, Type typePion) {
    switch (typePion) {
        case SINGE:
        case DRAGON:
            return creerCoordonnees(initial.x - 2, initial.y);
            break;
        default:
            return creerCoordonnees(initial.x - 1, initial.y);
            break;
    }
    
}

Coordonnees hautdroit(Coordonnees initial, Type typePion) {
    switch (typePion) {
        case SINGE:
        case DRAGON:
            return creerCoordonnees(initial.x + 2, initial.y - 2);
            break;
        default:
            return creerCoordonnees(initial.x + 1, initial.y - 1);
            break;
    }
    
}
