//
//  damier.c
//  Shing Shang
//
//  Created by Paul on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "../model/model.h"
#include "view.h"

Case damier[NBLIGNE][NBCOLONE];
Joueur joueur1;
Joueur joueur2;

void afficherDamier() {
    for (int i = 0; i < NBLIGNE; i++) {
        for (int j = 0; j < NBCOLONE; j++) {
            
            switch (damier[i][j].pion.type) {
                case DRAGON:
                    printf("D");
                    break;
                case SINGE:
                    printf("S");
                    break;
                case LION:
                    printf("L");
                    break;
                case PORTAIL:
                    printf("*");
                    break;
                default:
                    printf("%i", damier[i][j].jouable);
                    break;
            }
            
        }
        
        printf("\n");
    }
}
void initialiserPion() {
    
    //JOUEUR 1
    
    //DRAGON
    damier[2][2].pion = creerPion(creerCoordonnees(2,2), DRAGON, joueur1);
    damier[9][2].pion = creerPion(creerCoordonnees(9,2), DRAGON, joueur1);
    //LION
    damier[3][2].pion = creerPion(creerCoordonnees(3,2), LION, joueur1);
    damier[2][3].pion = creerPion(creerCoordonnees(2,3), LION, joueur1);
    damier[8][2].pion = creerPion(creerCoordonnees(8,2), LION, joueur1);
    damier[9][3].pion = creerPion(creerCoordonnees(9,3), LION, joueur1);
    //SINGE
    damier[4][2].pion = creerPion(creerCoordonnees(4,2), SINGE, joueur1);
    damier[3][3].pion = creerPion(creerCoordonnees(3,3), SINGE, joueur1);
    damier[2][4].pion = creerPion(creerCoordonnees(2,4), SINGE, joueur1);
    damier[7][2].pion = creerPion(creerCoordonnees(7,2), SINGE, joueur1);
    damier[8][3].pion = creerPion(creerCoordonnees(8,3), SINGE, joueur1);
    damier[9][4].pion = creerPion(creerCoordonnees(9,4), SINGE, joueur1);
    //PORTAILS
    damier[3][5].pion = creerPion(creerCoordonnees(3,5), PORTAIL, joueur1);
    damier[3][6].pion = creerPion(creerCoordonnees(3,6), PORTAIL, joueur1);
    
    //JOUEUR 2
    
    //DRAGON
    damier[2][9].pion = creerPion(creerCoordonnees(2,9), DRAGON, joueur2);
    damier[9][9].pion = creerPion(creerCoordonnees(9,9), DRAGON, joueur2);
    //LION
    damier[2][8].pion = creerPion(creerCoordonnees(2,8), LION, joueur2);
    damier[3][9].pion = creerPion(creerCoordonnees(3,9), LION, joueur2);
    damier[9][8].pion = creerPion(creerCoordonnees(9,8), LION, joueur2);
    damier[8][9].pion = creerPion(creerCoordonnees(8,9), LION, joueur2);
    //SINGE
    damier[2][7].pion = creerPion(creerCoordonnees(2,7), SINGE, joueur2);
    damier[3][8].pion = creerPion(creerCoordonnees(3,8), SINGE, joueur2);
    damier[4][9].pion = creerPion(creerCoordonnees(4,9), SINGE, joueur2);
    damier[9][7].pion = creerPion(creerCoordonnees(9,7), SINGE, joueur2);
    damier[8][8].pion = creerPion(creerCoordonnees(8,8), SINGE, joueur2);
    damier[7][9].pion = creerPion(creerCoordonnees(7,9), SINGE, joueur2);
    //PORTAILS
    damier[8][5].pion = creerPion(creerCoordonnees(8,5), PORTAIL, joueur2);
    damier[8][6].pion = creerPion(creerCoordonnees(8,6), PORTAIL, joueur2);
}

void initialiser() {
    joueur1 = creerJoueur("joueur1", ROUGE);
    joueur2 = creerJoueur("joueur2", NOIR);
    
    for(int i = 0; i < NBLIGNE; i++) {
        for(int j = 0; j < NBCOLONE; j++) {
            
            int jouable = 1;
            
            if (j <= 1 || i <= 1 || i >= NBLIGNE - 2 || j >= NBCOLONE - 2) {
                if((i == 5 || i == 6) && (j == 1 || j == NBCOLONE - 2)) {
                    jouable = 1;
                } else {
                    jouable = 0;
                }
            }
            
            // creer une case vide dans le damier
            damier[i][j] = creerCase(i, j, jouable);
        }
    }
    
    initialiserPion();
}

TypeCase verifierCase(int x, int y) {
    
    Case cellule = damier[x][y];
    
    if (!cellule.jouable) {
        return OUT;
    }
    
    return VIDE;
}

void deplacerPion(Coordonnees depart, Coordonnees arrive) {
    
}