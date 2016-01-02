#include "model.h"

/**
 *  Permet de créer les coordonnees
 *
 *  @param x coordonnees x
 *  @param y coordonnees y
 *
 */
Coordonnees creerCoordonnees(int x, int y) {
    Coordonnees coordoonees;
    coordoonees.x = x;
    coordoonees.y = y;
    
    return coordoonees;
}
/**
 *  Permet de créer les différents pions
 *
 *  @param coordonnees coordonnes du pions
 *  @param type        type du pion (DRAGON/LION/SINGE)
 *  @param joueur      Joueur à qui appartient le pion
 *
 */
Pion creerPion(Coordonnees coordonnees, Type type, Joueur joueur) {
    Pion nouveauPion;
    nouveauPion.cordonnees = coordonnees;
    nouveauPion.type = type;
    nouveauPion.joueur = joueur;
    
    return nouveauPion;
}