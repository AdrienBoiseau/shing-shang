//
//  pion.c
//  Shing Shang
//
//  Created by Paul on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include "model.h"

Coordonnees creerCoordonnees(int x, int y) {
    Coordonnees coordoonees;
    coordoonees.x = x;
    coordoonees.y = y;
    
    return coordoonees;
}

Pion creerPion(Coordonnees coordonnees, Type type, Joueur joueur) {
    Pion nouveauPion;
    nouveauPion.cordonnees = coordonnees;
    nouveauPion.type = type;
    
    return nouveauPion;
}