//
//  case.c
//  Shing Shang
//
//  Created by Paul on 15/11/2015.
//  Copyright © 2015 Adrien Boiseau. All rights reserved.
//

#include "model.h"

Case creerCase(int x, int y, int jouable)
{
    Case nouvelleCase;
    nouvelleCase.coordonnees.x = x;
    nouvelleCase.coordonnees.y = y;
    nouvelleCase.jouable = jouable;

    return nouvelleCase;
}
