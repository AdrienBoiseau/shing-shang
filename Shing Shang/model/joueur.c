#include <stdio.h>
#include "model.h"
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