//
//  jeu.c
//  Shing Shang
//
//  Created by Adrien Boiseau on 29/12/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include <stdio.h>
#include "../model/model.h"
#include "view.h"
#include "app.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void jouerCoup(Joueur *joueur) {
    // recuperer coordonnées pion
    printf("AIDE : La dragon en haut à gauche ce situe en 2,2 // Le dragon en bas à droite ce situe en 9,9\n");
    while(1) {
        printf("Quel Pion voulez-vous jouer ? (exemple 9,2)\n");
        Coordonnees from = recupererCoordonnees();
        
        TypeCase caseDepart = verifierCase(from.x, from.y);
        if (caseDepart == PION) {
            Case *cellule = recupererCellule(from);
            if (cellule->pion.joueur.couleur == joueur->couleur) {
                break;
            } else {
                printf("Ce pion ne vous appartiens pas\n");
            }
        }
        afficherErreurDeplacement(caseDepart);
    }
    
    while(1) {
        printf("Où voulez-vous aller? (exemple 9,2)\n");
        Coordonnees to = recupererCoordonnees();
        
        TypeCase caseFin = verifierCase(to.x, to.y);
        if (caseFin == PION || caseFin == VIDE)
            break;
        
        afficherErreurDeplacement(caseFin);
    }
}

void run() {
    Joueur *joueur = choixJoueur();
    
    do {
        afficherTourJoueur(joueur);
        jouerCoup(joueur);
        system("clear");
        afficherDamier();
        
        if (joueur->couleur == NOIR) {
            joueur = recupererJoueur(ROUGE);
        } else if (joueur->couleur == ROUGE) {
            joueur = recupererJoueur(NOIR);
        }
        
    } while (1);
}

Joueur* choixJoueur()
{
    int joueur = 0;
    
    do {
        printf("Quel joueur commence à jouer ? (Tapez 1 pour joueur 1, 2 pour joueur 2, 3 pour aléatoire)\n");
        scanf("%d", &joueur); //Choix du joueur qui commence
        viderBuffer();
    } while (joueur !=1 && joueur !=2 && joueur !=3); //Répète le Do tant que la valeur rentrer n'est pas bonne
    
    //Regarde quel joueur commence
    if (joueur == 1) {
        return recupererJoueur(NOIR);
    }
    
    if (joueur == 2) {
        return recupererJoueur(ROUGE);
    }
    
    if (joueur == 3) {
        srand(time(NULL));
        joueur = 1 + rand()%( 2 - 1 + 1); //Fait un rand entre 1 et 2
        
        if (joueur == 1) {
            return recupererJoueur(NOIR);
        } else if (joueur==2) {
            return recupererJoueur(ROUGE);
        }
    }
    
    return recupererJoueur(NOIR);
}
