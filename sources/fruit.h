/*
===========================================================


 ________  ________   ________                 ________     
|\   ____\|\   ___  \|\   __  \               |\   ____\    
\ \  \___|\ \  \\ \  \ \  \|\  \  ____________\ \  \___|    
 \ \_____  \ \  \\ \  \ \   __  \|\____________\ \  \       
  \|____|\  \ \  \\ \  \ \  \ \  \|____________|\ \  \____  
    ____\_\  \ \__\\ \__\ \__\ \__\              \ \_______\ 
   |\_________\|__| \|__|\|__|\|__|               \|_______|
   \|_________|                                             
                                                           
                                 By Mike4544       


	-=	Yet another Snake Implementation	=- 


===========================================================

 @github: Mike4544

===========================================================
*/



#ifndef __FRUIT_H__
#define __FRUIT_H__

#include "defines.h"


//  The fruit struct
//
//  It contains the x and y coordinates of the fruit
/// @param x The x coordonate of the fruit
/// @param y The y coordonate of the fruit
typedef struct Fruit {
    int x, y;
} Fruit;

//  The fruit
extern Fruit fruit;

#endif