//
//  joueur.c
//  Shing Shang
//
//  Created by Adrien Boiseau on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include "../app.h"

/**
 *  Permet de créer les deux joueurs
 *
 *  @param nom     Nom de joueur
 *  @param couleur Couleur du joueur (peut prendre ROUGE ou NOIR)
 */
Joueur creerJoueur(char nom[], Couleur couleur) {
    Joueur player;
    player.nom = nom;
    player.couleur = couleur;

    return player;
}