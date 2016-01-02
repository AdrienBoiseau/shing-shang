//
//  damier.c
//  Shing Shang
//
//  Created by Paul on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "model.h"
#include "view.h"
#include "app.h"

Case damier[NBLIGNE][NBCOLONE];
Joueur joueur1;
Joueur joueur2;

Case* recupererCellule(Coordonnees coordonnees) {
    return &damier[coordonnees.x][coordonnees.y];
}

Joueur* recupererJoueur(Couleur couleur) {
    if (couleur == NOIR) {
        return &joueur1;
    } else {
        return &joueur2;
    }
}

void afficherDamier() {
    
    printf("==> Joueur 1 <==");
    
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
                    if(damier[i][j].jouable) {
                        printf("0");
                    } else {
                        printf(" ");
                    }
                    break;
            }
            
        }
        
        printf("\n");
    }
    
    printf("==> Joueur 2 <==\n\n");
}
void initialiserPion() {
    
    //JOUEUR 1
    
    //DRAGON
    damier[2][2].pion = creerPion(creerCoordonnees(2,2), DRAGON, joueur1);
    remplirCase(&damier[2][2]);
    damier[2][9].pion = creerPion(creerCoordonnees(2,9), DRAGON, joueur1);
    remplirCase(&damier[2][9]);
    //damier[2][2].pleine = 1;
    //LION
    damier[2][8].pion = creerPion(creerCoordonnees(2,8), LION, joueur1);
    remplirCase(&damier[2][8]);
    damier[3][9].pion = creerPion(creerCoordonnees(3,9), LION, joueur1);
    remplirCase(&damier[3][9]);
    damier[3][2].pion = creerPion(creerCoordonnees(3,2), LION, joueur1);
    remplirCase(&damier[3][2]);
    damier[2][3].pion = creerPion(creerCoordonnees(2,3), LION, joueur1);
    remplirCase(&damier[2][3]);
    //SINGE
    damier[4][2].pion = creerPion(creerCoordonnees(4,2), SINGE, joueur1);
    remplirCase(&damier[4][2]);
    damier[3][3].pion = creerPion(creerCoordonnees(3,3), SINGE, joueur1);
    remplirCase(&damier[3][3]);
    damier[2][4].pion = creerPion(creerCoordonnees(2,4), SINGE, joueur1);
    remplirCase(&damier[2][4]);
    damier[2][7].pion = creerPion(creerCoordonnees(2,7), SINGE, joueur1);
    remplirCase(&damier[2][7]);
    damier[3][8].pion = creerPion(creerCoordonnees(3,8), SINGE, joueur1);
    remplirCase(&damier[3][8]);
    damier[4][9].pion = creerPion(creerCoordonnees(4,9), SINGE, joueur1);
    remplirCase(&damier[4][9]);
    //PORTAILS
    damier[3][5].pion = creerPion(creerCoordonnees(3,5), PORTAIL, joueur1);
    remplirCase(&damier[3][5]);
    damier[3][6].pion = creerPion(creerCoordonnees(3,6), PORTAIL, joueur1);
    remplirCase(&damier[3][6]);
    
    //JOUEUR 2
    
    //DRAGON
    damier[9][2].pion = creerPion(creerCoordonnees(9,2), DRAGON, joueur2);
    remplirCase(&damier[9][2]);
    damier[9][9].pion = creerPion(creerCoordonnees(9,9), DRAGON, joueur2);
    remplirCase(&damier[9][9]);
    //LION
    damier[8][2].pion = creerPion(creerCoordonnees(8,2), LION, joueur2);
    remplirCase(&damier[8][2]);
    damier[9][3].pion = creerPion(creerCoordonnees(9,3), LION, joueur2);
    remplirCase(&damier[9][3]);
    damier[9][8].pion = creerPion(creerCoordonnees(9,8), LION, joueur2);
    remplirCase(&damier[9][8]);
    damier[8][9].pion = creerPion(creerCoordonnees(8,9), LION, joueur2);
    remplirCase(&damier[8][9]);
    //SINGE
    damier[9][7].pion = creerPion(creerCoordonnees(9,7), SINGE, joueur2);
    remplirCase(&damier[9][7]);
    damier[8][8].pion = creerPion(creerCoordonnees(8,8), SINGE, joueur2);
    remplirCase(&damier[8][8]);
    damier[7][9].pion = creerPion(creerCoordonnees(7,9), SINGE, joueur2);
    remplirCase(&damier[7][9]);
    damier[7][2].pion = creerPion(creerCoordonnees(7,2), SINGE, joueur2);
    remplirCase(&damier[7][2]);
    damier[8][3].pion = creerPion(creerCoordonnees(8,3), SINGE, joueur2);
    remplirCase(&damier[8][3]);
    damier[9][4].pion = creerPion(creerCoordonnees(9,4), SINGE, joueur2);
    remplirCase(&damier[9][4]);
    //PORTAILS
    damier[8][5].pion = creerPion(creerCoordonnees(8,5), PORTAIL, joueur2);
    remplirCase(&damier[8][5]);
    damier[8][6].pion = creerPion(creerCoordonnees(8,6), PORTAIL, joueur2);
    remplirCase(&damier[8][6]);
}

void initialiser() {
    joueur1 = creerJoueur("joueur1", NOIR);
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
            damier[i][j] = creerCase(i, j, jouable, 0);
        }
    }
    
    initialiserPion();
}

TypeCase verifierCase(int x, int y) {
    
    if(x > NBLIGNE || x < 0 || y > NBCOLONE || y < 0) {
        return OUT;
    }
    
    Case cellule = damier[x][y];
    
    if (!cellule.jouable) {
        return OUT;
    }
    
    if (cellule.pleine == 1) {
        if(cellule.pion.type == PORTAIL) {
            return OBJET;
        } else {
            return PION;
        }
    }
    
    return VIDE;
}

Coordonnees preparerDeplacement(Coordonnees depart, Type typePion, Direction direction) {
    Coordonnees arrivee;
    
    switch (direction) {
        case HAUT:
            arrivee = haut(depart, typePion);
            break;
        case HAUTDROIT:
            arrivee = hautdroit(depart, typePion);
            break;
        case DROIT:
            arrivee = droit(depart, typePion);
            break;
        case BASDROIT:
            arrivee = basdroit(depart, typePion);
            break;
        case BAS:
            arrivee = bas(depart, typePion);
            break;
        case BASGAUCHE:
            arrivee = basgauche(depart, typePion);
            break;
        case GAUCHE:
            arrivee = gauche(depart, typePion);
            break;
        case HAUTGAUCHE:
            arrivee = hautgauche(depart, typePion);
            break;
    }
    
    return arrivee;
}

void deplacerPion(Coordonnees depart, Coordonnees arrive, Direction direction) {
    
    
    Case *celluleDepart = &damier[depart.x][depart.y];
    Case *celluleArrivee = &damier[arrive.x][arrive.y];
    
    if (celluleArrivee->pleine == 0) {
        updateCase(celluleDepart, celluleArrivee);
    } else {
        
        do {
            
            if (celluleDepart->pion.joueur.couleur == celluleArrivee->pion.joueur.couleur) {
                arrive = sauterPion(celluleArrivee, direction);
                celluleArrivee = &damier[arrive.x][arrive.y];
            } else {
                
            }
            
        } while(celluleArrivee->pleine == 1);
        
        updateCase(celluleDepart, celluleArrivee);
    }
}

Coordonnees sauterPion(Case *cellule, Direction direction) {
    Coordonnees deplacement = coordonneesDeplacement(direction);
    
    return creerCoordonnees(cellule->coordonnees.x + deplacement.x, cellule->coordonnees.y + deplacement.y);
}