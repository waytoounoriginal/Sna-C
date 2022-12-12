#ifndef __SNAKE__
#define __SNAKE__


#define STARTING_X      1
#define STARTING_Y      1

#include "defines.h"

typedef struct snake {
    int x;
    int y;
    int length;

    Keys currDir;

    char symbol;

    struct snake * next;

} Snake;

extern Snake * head;

void initSnake();

void insertPart(Snake * _head);



#endif
