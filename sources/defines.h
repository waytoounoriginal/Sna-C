#ifndef __INCLUDES_H__
#define __INCLUDES_H__

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include <windows.h>



#define FPS                     120
#define SLEEP_TIME              1000 / FPS

#define MAP_HEIGHT              32
#define MAP_WIDTH               64

#define CNS_CLEAR               SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){0, 0});
#define MOVE_CURSOR(x, y)       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x, y});
#define SLEEP                   _sleep(SLEEP_TIME);
#define MAXIMIZE                ShowWindow( GetConsoleWindow() , SW_MAXIMIZE);

#define GUI_X                   0
#define GUI_Y                   MAP_HEIGHT + 2

#define SCORE_X                 GUI_X + 58  // 58 = 64 - 6  (6 = strlen("SCORE:"))
#define SCORE_Y                 GUI_Y + 1


#define WALL_TILE               '#'
#define MAP_TILE                ' '
#define SNAKE_HEAD_TILE         '0'
#define SNAKE_BODY_TILE         '+'
#define FRUIT_TILE              '*'

#define DEBUG                   1


typedef enum Keys {
    UP      = 'W',
    DOWN    = 'S',
    LEFT    = 'A',
    RIGHT   = 'D',
    EXIT    = 'X'
} Keys;



#endif