#ifndef __SNAKE__
#define __SNAKE__


#define STARTING_X      1
#define STARTING_Y      1

#include "defines.h"

typedef struct snake {
    int x;
    int y;

    Keys currDir;

    char symbol;

    struct snake * next;
    struct snake * prev;

} Snake;

extern Snake * head;
extern Snake * last;


void initSnake();

void insertPart(Snake * _head);



#endif
