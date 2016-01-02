#include "model.h"
/**
 *  Permet de créer les cases du damier
 *
 *  @param x       coordonnées x de la case
 *  @param y       coordonnées y de la case
 *  @param jouable case jouable ou non
 *  @param pleine  case rempli ou non
 */
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
    cellule->pleine = 1; //Rempli les cases en pleine pour differencier case vide/pleine
}
/**
 *  Fonction de déplacement
 *
 *  @param celluleDepart  reçoit la cellule de départ
 *  @param celluleArrivee et la cellule d'arrivee 
 *  effectue ensuite le deplacement
 */
void updateCase(Case *celluleDepart, Case *celluleArrivee) {
    celluleArrivee->pion = creerPion(celluleArrivee->coordonnees, celluleDepart->pion.type, celluleDepart->pion.joueur);
    celluleArrivee->pleine = 1;
    
    *celluleDepart = creerCase(celluleDepart->coordonnees.y, celluleDepart->coordonnees.x, 1, 0);
}
//Différentes coordonnées pour chaque direction de déplacement
Coordonnees haut(Coordonnees initial, Type typePion) {
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
            return creerCoordonnees(initial.x, initial.y + 2);
            break;
        default:
            return creerCoordonnees(initial.x, initial.y + 1);
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
            return creerCoordonnees(initial.x + 2, initial.y);
            break;
        default:
            return creerCoordonnees(initial.x + 1, initial.y);
            break;
    }
}

Coordonnees basgauche(Coordonnees initial, Type typePion) {
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

Coordonnees gauche(Coordonnees initial, Type typePion) {
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

Coordonnees hautdroit(Coordonnees initial, Type typePion) {
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
//Nouvelle coordonnees de déplacement lors d'un saut d'un pion
Coordonnees coordonneesDeplacement(Direction direction) {
    Coordonnees coordonnees;
    
    switch (direction) {
        case HAUT:
            coordonnees = creerCoordonnees(-1, 0);
            break;
        case HAUTDROIT:
            coordonnees = creerCoordonnees(-1, 1);
            break;
        case DROIT:
            coordonnees = creerCoordonnees(0, 1);
            break;
        case BASDROIT:
            coordonnees = creerCoordonnees(1, 1);
            break;
        case BAS:
            coordonnees = creerCoordonnees(1, 0);
            break;
        case BASGAUCHE:
            coordonnees = creerCoordonnees(1, -1);
            break;
        case GAUCHE:
            coordonnees = creerCoordonnees(0, -1);
            break;
        case HAUTGAUCHE:
            coordonnees = creerCoordonnees(-1, -1);
            break;
    }
    
    return coordonnees;
}
