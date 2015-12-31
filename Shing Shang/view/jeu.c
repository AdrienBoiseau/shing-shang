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

void jouerCoup() {
    
    // recuperer coordonnées pion
    while(1) {
        printf("Quel Pion voulez-vous jouer ? (exemple 9,2)\n");
        Coordonnees from = recupererCoordonnees();
        
        TypeCase caseDepart = verifierCase(from.x, from.y);
        if (caseDepart == PION)
            break;
        
        afficherErreurDeplacement(caseDepart);
        viderBuffer();
    }
    
    while(1) {
        printf("Où voulez-vous aller? (exemple 9,2)\n");
        Coordonnees to = recupererCoordonnees();
        
        TypeCase caseFin = verifierCase(to.x, to.y);
        if (caseFin == PION || caseFin == VIDE)
            break;
        
        afficherErreurDeplacement(caseFin);
        viderBuffer();
    }
}

void run() {
    do {
        // joueur1 ou joueur2 ?
        
        jouerCoup();
        
        // test si partie fini (break)
        
    } while (1); //
}

/*
 
 int choixjoueur (int joueur)
 {
 jouerCoup();
 
 joueur = 0;
 do {
 printf("Quel joueur commence à jouer ? (Tapez 1 pour joueur 1, 2 pour joueur 2, 3 pour aléatoire)\n");
 scanf("%d",&joueur); //Choix du joueur qui commence
 viderBuffer();
 }
 while (joueur!=1 && joueur!=2 && joueur!=3);//Répète le Do tant que la valeur rentrer n'est pas bonne
 
 //Regarde quel joueur commence
 if (joueur==1) {
 printf("Le joueur 1 commence\n"); // Regarde quel joueur commence
 return 1;
 }
 
 if (joueur==2) {
 printf("Le joueur 2 commence\n"); //Regarde quel joueur commence
 return 2;
 }
 
 if (joueur==3) {
 srand(time(NULL));
 joueur = 1 + rand()%( 2 - 1 + 1); //Fait un rand entre 1 et 2
 if (joueur==1) {
 printf("Le joueur 1 commence\n");//En fonction du rand regarde quel joueur commence
 return 1;
 }
 if (joueur==2) {
 printf("Le joueur 2 commence\n");//En fonction du rand regarde quel joueur commence
 return 2;
 }
 }
 
 return 0;
 }
 */