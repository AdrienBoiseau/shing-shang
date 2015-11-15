//
//  main.c
//  Shing Shang
//
//  Created by Adrien Boiseau on 13/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include <stdio.h>
#define NBLIGNE 10
#define NBCOLONE 10
int main(void) {
    //Déclaration
    int damier[NBLIGNE][NBCOLONE] ={{9,6,5,4,0,0,4,5,6,9}, //Les pions du joueurs 1 sont 1=Singe,   2=Lion, 3=Dragon
        {9,5,4,0,8,8,0,4,5,9},  //Les pions du joueurs 2 sont 4=Singe, 5=Lion,6=Dragon
        {9,4,0,0,0,0,0,0,4,9},  //8=Portail, 9=Abs de cases
        {9,0,0,0,0,0,0,0,0,9},  //0=Case vide
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {9,0,0,0,0,0,0,0,0,9},
        {9,1,0,0,0,0,0,0,1,9},
        {9,2,1,0,8,8,0,1,2,9},
        {9,3,2,1,0,0,1,2,3,9}};
    
    int ligne=0;
    int colone=0;
    
    
    
    for(ligne = 0 ; ligne <NBLIGNE ; ligne ++) {
        for(colone = 0 ; colone <NBCOLONE ; colone++)
        {
            if (damier[ligne][colone]>3 && damier[ligne][colone]<7)
            {
                damier[ligne][colone]-=3; //-3 pour revenir à 1,2,3.
            }
            if (damier[ligne][colone]==9)
            {
                printf(" ");
            }
            else
            {
                if (damier[ligne][colone]==3)
                {
                    printf("D");
                }
                else  if (damier[ligne][colone]==2)
                {
                    printf("L");
                }
                else  if (damier[ligne][colone]==1)
                {
                    printf("S");
                }
                else  if (damier[ligne][colone]==8)
                {
                    printf("*");
                }
                else
                {
                    printf("%d",damier[ligne][colone]);
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}
