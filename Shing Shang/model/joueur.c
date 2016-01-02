//
//  joueur.c
//  Shing Shang
//
//  Created by Adrien Boiseau on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include <stdio.h>

#include "../app.h"

Joueur creerJoueur(char nom[], Couleur couleur) {
    Joueur player;
    player.nom = nom;
    player.couleur = couleur;

    return player;
}