//
//  main.c
//  Shing Shang
//
//  Created by Adrien Boiseau on 13/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "model/model.h"
#include "view/view.h"

int main(void) {

    initialiser();
    afficherDamier();
  
    jouerCoup();
    
    //choixjoueur(joueur);
    
    return 0;
}
