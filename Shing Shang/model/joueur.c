//
//  joueur.c
//  Shing Shang
//
//  Created by Paul on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include <stdio.h>
#include "model.h"

Joueur creerJoueur(char nom[255], Couleur couleur) {
    Joueur player;
    player.nom = nom;
    player.couleur = couleur;

    return player;
}