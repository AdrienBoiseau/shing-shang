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
                    printf("P");
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
             Coordonnees coordonnes;
    for(int i = 0; i < NBLIGNE; i++) {
        for(int j = 0; j < NBCOLONE; j++) {
         
            if ((i==3 && j==3) || (i==10 && j==3)) {
       
                coordonnes.x = i;
                coordonnes.y = j;
            
                damier[i][j].pion = creerPion(coordonnes, DRAGON, joueur1);
            }
            if ((i==3 && j==10) || (i==10 && j==10)) {
             
                coordonnes.x = i;
                coordonnes.y =j;
                damier[i][j].pion = creerPion(coordonnes, DRAGON, joueur2);
            }
            if ( ((i==4 && j==3) && (i==3 && j==4)) || ((i==9 && j==3) && (i==10 && j==4)) ) {
      
                coordonnes.x = i;
                coordonnes.y = j;
                damier[i][j].pion = creerPion(coordonnes, LION, joueur1);
            }
            if ( ((i==3 && j==9) && (i==4 && j==10)) || ((i==10 && j==9) && (i==9 && j==10)) ) {
                coordonnes.x = i;
                coordonnes.y = j;
                damier[i][j].pion = creerPion(coordonnes, LION, joueur2);
            }
            
        
        
        }
    }
        
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
}

