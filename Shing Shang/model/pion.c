//
//  pion.c
//  Shing Shang
//
//  Created by Paul on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include "model.h"

Pion creerPion(Coordonnees coordonnees, Type type, Joueur joueur) {
    Pion nouveauPion;
    nouveauPion.cordonnees = coordonnees;
    nouveauPion.type = type;

    return nouveauPion;
}