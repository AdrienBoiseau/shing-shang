//
//  helper.c
//  Shing Shang
//
//  Created by Adrien Boiseau on 29/12/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "model.h"

void viderBuffer() //Fonction pour vider le Buffer
{
    int c = 0;
    while(c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

Coordonnees recupererCoordonnees() {
    char string[6];
    
    int x = 0;
    int y = 0;
    
    fgets(string, sizeof(string), stdin);
    //viderBuffer();
    
    char *token = strtok(string, ",");
    
    x = atoi(token);
    
    /* walk through other tokens */
    while(token) {
        token = strtok(NULL, ",");
        if(token != NULL){
            y = atoi(token);
        }
        break;
    }
    return creerCoordonnees(x, y);
}

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

void afficherTourJoueur(Joueur *joueur) {
    if(joueur->couleur == NOIR) {
        printf("Joueur 1 à vous de jouer\n");
    } else if(joueur->couleur == ROUGE) {
        printf("Joueur 2 à vous de jouer\n");
    }
}

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
