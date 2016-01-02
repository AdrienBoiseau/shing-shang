//
//  damier.c
//  Shing Shang
//
//  Created by Adrien Boiseau on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//
#include "../app.h"

Case damier[NBLIGNE][NBCOLONE];
Joueur joueur1;
Joueur joueur2;

//Fonction pour recuperer les coordonnes d'une cellule
Case* recupererCellule(Coordonnees coordonnees) {
    return &damier[coordonnees.x][coordonnees.y];
}
//Fonction pour recuperer le joueur
Joueur* recupererJoueur(Couleur couleur) {
    if (couleur == NOIR) {
        return &joueur1;
    } else {
        return &joueur2;
    }
}
/**
 *  Fonction pour afficher le damier
 */
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
                    //Si case jouable affiche 0
                    if(damier[i][j].jouable) {
                        printf("0");
                    } else {
                        printf(" ");//Sinon afficher un "blanc"
                    }
                    break;
            }
            
        }
        
        printf("\n");
    }
    
    printf("==> Joueur 2 <==\n\n");
}

/**
 Fonction permettant d'initialiser les pions à leur position de départ
 */
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

/**
 Fonction permettant d'initialiser le damier avec ça forme spécifique
 */
void initialiser() {
    joueur1 = creerJoueur("joueur1", NOIR);
    joueur2 = creerJoueur("joueur2", ROUGE);
    
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
/**
 *  Fonction permettant de retourner si une case est en dehors du damier
 *  Si une case est pleine, si elle contient un pion ou un portail
 *  @param x coordonnees de la case x
 *  @param y coordonnees de la case y
 *
 */
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
            return OBJET;//Objet pour portail
        } else {
            return PION;
        }
    }
    
    return VIDE;
}

/**
 *  Fonction permettant de recuperer les coordonnes de depart et le type de pion ainsi que la direction
 *  afin de préparer un deplacement
 *  @param depart    coordonnées de départ sélectionné
 *  @param typePion  type de pion sélectionné
 *  @param direction direciton dans laquelle la personne souhaite déplacer son pion
 *
 */
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
/**
 * Fonction permmettant de déplacer de regarder toute les vérifications pour les déplacements
 * Elle permet d'effectuer un saut, de regarder à qui appartient les pions
 * Gerer si un pion et manger par un autre
 */
void deplacerPion(Coordonnees depart, Coordonnees arrive, Direction direction) {
    
    Case *celluleDepart = &damier[depart.x][depart.y];
    Case *celluleArrivee = &damier[arrive.x][arrive.y];
    
    // si cellule vide
    if (celluleArrivee->pleine == 0) {
        updateCase(celluleDepart, celluleArrivee);
    } else if(celluleArrivee->pleine == 1) {
        // si cellule contient pion
        do {
            // annule deplacement si pion plus fort
            if (celluleDepart->pion.type < celluleArrivee->pion.type) {
                printf("Votre %s ne peut pas sauter un %s\n",
                       afficherTypeCase(celluleDepart->pion.type), afficherTypeCase(celluleArrivee->pion.type));
                return;
            }
            
            if (celluleDepart->pion.joueur.couleur == celluleArrivee->pion.joueur.couleur) {
                arrive = sauterPion(celluleArrivee, direction);
                celluleArrivee = &damier[arrive.x][arrive.y];
            } else {
                // pion ennemi
            }
            
        } while(celluleArrivee->pleine == 1);
        
        updateCase(celluleDepart, celluleArrivee);
    }
}
//Fonction permettant d'effectuer le saut de pion
Coordonnees sauterPion(Case *cellule, Direction direction) {
    Coordonnees deplacement = coordonneesDeplacement(direction);
    
    return creerCoordonnees(cellule->coordonnees.x + deplacement.x, cellule->coordonnees.y + deplacement.y);
}