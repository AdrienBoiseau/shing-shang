//
//  damier.c
//  Shing Shang
//
//  Created by Paul on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include <stdio.h>

#include "../model/model.h"
#include "view.h"

Case damier[NBLIGNE][NBCOLONE];

void afficherDamier() {
    for (int i = 0; i < NBLIGNE; i++) {
        for (int j = 0; j < NBCOLONE; j++) {
            printf("%i", damier[i][j].jouable);
        }
        printf("\n");
    }
}

void initialiser() {
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

