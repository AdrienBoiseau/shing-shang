#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../app.h"

/**
 *  Fonction permettant de gerer les différents cas d'erreur lors de la selection d'un pion
 *  Elle permet aussi de gerer à qui appartient les pions pour chaque joueur
 */
void jouerCoup(Joueur *joueur) {
    Coordonnees from;
    Coordonnees to;
    Direction direction;
    Case *cellule;
    
    // recuperer coordonnées pion
    printf("AIDE : La dragon en haut à gauche ce situe en 2,2 // Le dragon en bas à droite ce situe en 9,9\n");
    while(1) {
        printf("Quel Pion voulez-vous jouer ? (exemple 9,2)\n");
        from = recupererCoordonnees();
        
        TypeCase caseDepart = verifierCase(from.x, from.y);
        if (caseDepart == PION) {
            cellule = recupererCellule(from);
            //Regarde à qui appartient le pion sélectionné
            if (cellule->pion.joueur.couleur == joueur->couleur) {
                printf("Vous avez selectionné un %s\n", afficherTypeCase(cellule->pion.type));
                break;
            } else {
                printf("Ce pion ne vous appartiens pas\n");
            }
        }
        afficherErreurDeplacement(caseDepart);
    }
    //Permet de choisir la direction du déplacement
    while(1) {
        printf("Dans quel direction voulez-vous aller ?\n");
        printf("HAUT = 1, HAUTDROIT = 2, DROIT = 3, BASDROIT = 4, BAS = 5, BASGAUCHE = 6, GAUCHE = 7, HAUTGAUCHE = 8\n");
        
        direction = recupererDirection();
        to = preparerDeplacement(from, cellule->pion.type, direction);
        
        TypeCase caseFin = verifierCase(to.x, to.y);
        if (caseFin == PION || caseFin == VIDE) 
            break;
        
        afficherErreurDeplacement(caseFin);
    }
    
    deplacerPion(from, to, direction); //Appel la fonction de déplacement
}
/**
 *  La fonction regarde quel est la couleur du dernier joueur qui a jouer
 *  et permet ensuite de changer le joueur qui joue
 *  Cette fonction est répeter à chaque fois lors de l'exécution du programme
 */
void run() {
    Joueur *joueur = choixJoueur();
    
    do {
        
        afficherTourJoueur(joueur);
        jouerCoup(joueur);
        
        system("clear");
        afficherDamier();
        
        if (joueur->couleur == NOIR) {
            joueur = recupererJoueur(ROUGE);
        } else {
            joueur = recupererJoueur(NOIR);
        }
        
        viderBuffer();
    } while (1);
}
/**
 * Cette fonction permet de choisir quel joueur commence à jouer
 */
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
