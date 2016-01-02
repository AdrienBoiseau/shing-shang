//
//  main.c
//  Shing Shang
//
//  Created by Adrien Boiseau on 13/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include "app.h"

int main(void) {
    
    int jouer = 0;
    
    do {
        printf("===================================================\n");
        printf("'                Shing Shang                      '\n");
        printf("'                Menu du Jeu                      '\n");
        printf("'                                                 '\n");
        printf("'                1 : Jouer                        '\n");
        printf("'               2 : Quitter                       '\n");
        printf("===================================================\n");
        scanf("%d",&jouer);
        viderBuffer();
        
        if (jouer == 1) {
            initialiser();
            
            afficherDamier();
            
            run();
            
            return 0;
        }
        else if (jouer == 2) {
            return 0;
        }
        
    } while (jouer != 1 || jouer !=2 );
}
