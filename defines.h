#ifndef __INCLUDES_H__
#define __INCLUDES_H__

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



#define FPS                     5
#define SLEEP_TIME              1000 / FPS

#define MAP_HEIGHT              32
#define MAP_WIDTH               32

#define CNS_CLEAR               system("cls")
#define SLEEP                   _sleep(SLEEP_TIME);

#define WALL_TILE               '#'
#define MAP_TILE                ' '
#define SNAKE_HEAD_TILE         '0'
#define SNAKE_BODY_TILE         '+'
#define FRUIT_TILE              '*'

#define DEBUG                   0


typedef enum Keys {
    UP      = 'W',
    DOWN    = 'S',
    LEFT    = 'A',
    RIGHT   = 'D',
    EXIT    = 'X'
} Keys;



#endif