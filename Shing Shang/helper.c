#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"

//Fonction pour vider le Buffer
void viderBuffer()
{
    int c = 0;
    while(c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

//Cette fonction permet de recuperer les coordonnees sous forme de 3,2 et supprimer la virgule
Coordonnees recupererCoordonnees() {
    char string[6];
    
    int x = 0;
    int y = 0;
    
    fgets(string, sizeof(string), stdin);
    
    char *token = strtok(string, ",");
    
    y = atoi(token);
    
    /* walk through other tokens */
    while(token) {
        token = strtok(NULL, ",");
        if(token != NULL){
            x = atoi(token);
        }
        break;
    }
    
    return creerCoordonnees(x, y);
}
//Cette fonction permet de recuperer la direction choisi
Direction recupererDirection() {
    char direction[2];
    
    fgets(direction, sizeof(direction), stdin);

    return atoi(direction);
}
//Cette fonction afficher les erreurs de déplacement
void afficherErreurDeplacement(TypeCase type) {
    switch (type) {
        case VIDE:
            printf("Cette case est vide\n");
            break;
        case OUT:
            printf("Cette case est hors du damier\n");
            viderBuffer();
            break;
        case OBJET:
            printf("Cette case est un portail\n");
            break;
        default:
            break;
    }
}
//Fonction qui affiche a qui de joueur
void afficherTourJoueur(Joueur *joueur) {
    if(joueur->couleur == NOIR) {
        printf("Joueur 1 à vous de jouer\n");
    } else if(joueur->couleur == ROUGE) {
        printf("Joueur 2 à vous de jouer\n");
    }
}
//Fonction pour afficher le pion que contient la case
char* afficherTypeCase(Type type) {
    switch (type) {
        case DRAGON:
            return "DRAGON";
            break;
        case LION:
            return "LION";
            break;
        case SINGE:
            return "SINGE";
            break;
        default:
            return "PION";
            break;
    }
}
