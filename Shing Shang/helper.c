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
    char string[5];
    
    fgets(string, sizeof(string), stdin);
    //viderBuffer();
    
    char *token = strtok(string, ",");
    
    int x = atoi(token);
    int y;
    
    /* walk through other tokens */
    while(token) {
        token = strtok(NULL, ",");
        y = atoi(token);
        break;
    }
    
    return creerCoordonnees(x, y);
}
