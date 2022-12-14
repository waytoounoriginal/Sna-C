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




#ifndef __SNAKE__
#define __SNAKE__

//  The starting position of the snake {x, y}
#define STARTING_X      1
#define STARTING_Y      1

#include "defines.h"

//  The snake struct
//
//  It is a bidirectional linked list
/// @param x The x coordonate of the snake part
/// @param y The y coordonate of the snake part
/// @param currDir The current direction of the snake part
/// @param symbol The symbol of the snake part
/// @param next The next snake part; **[NULL]** if it is the last part
/// @param prev The previous snake part; **[NULL]** if it is the first part
typedef struct snake {
    int x;
    int y;

    Keys currDir;

    char * symbol;

    struct snake * next;
    struct snake * prev;

} Snake;

//  The head of the snake
extern Snake * head;

//  The last part of the snake
extern Snake * last;

//  Initializes the snake, as well as mallocs the memory for it
void initSnake();

//  Initializes the symbol of the snake
char * initSymbol(char * _color, char _symbol);

//  Inserts a new part at the end of the snake.
//  Basically the insert function of a linked list.
/// @param _head The head of the snake
void insertPart(Snake * _head);



#endif
