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

#ifndef __INCLUDES_H__
#define __INCLUDES_H__

//  ========================
//
//  Versioning
//
//  ========================

#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_PATCH 1

#define OWNER         "Mike4544"
#define CONTRIBUTORS  "Darius\nDeea\n"

//  ========================

//  ========================
//
//  Includes
//
//  ========================

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>

  //  Helper functions for the terminal
  #define CNS_CLEAR                       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){0, 0});
  #define MOVE_CURSOR(x, y)               SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x, y});
  #define SLEEP                           _sleep(SLEEP_TIME);
  #define MAXIMIZE                        ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

  typedef enum Colors
  {
    //  Primary colors RGB
    RED       = FOREGROUND_RED,
    GREEN     = FOREGROUND_GREEN,
    BLUE      = FOREGROUND_BLUE,

    //  Default color
    WHITE     = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,

    //  Secondary colors CMY
    CYAN      = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    YELLOW    = FOREGROUND_RED  | FOREGROUND_GREEN,
    PURPLE    = FOREGROUND_RED  | FOREGROUND_BLUE,
    MAGENTA   = PURPLE          | FOREGROUND_INTENSITY
  } Colors;

  #define SET_CURSOR_COLOR(color)         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

#endif

#ifdef __linux__
#include <unistd.h>
#endif

//  ========================
//
//  Defines
//
//  ========================

//  The FPS of the game and the sleep time in ms
#define FPS                     30
#define SLEEP_TIME              1000 / FPS

//  The map size (in tiles)
#define MAP_HEIGHT              32
#define MAP_WIDTH               64

//  The coordonates of the GUI
#define GUI_X                   0
#define GUI_Y                   MAP_HEIGHT + 2

//  The coordonates of the score
#define SCORE_X                 GUI_X + 58 // 58 = 64 - 6  (6 = strlen("SCORE:"))
#define SCORE_Y                 GUI_Y + 1

//  The tiles of the map and the snake
#define WALL_TILE               '#'
#define MAP_TILE                ' '
#define SNAKE_HEAD_TILE         '0'
#define SNAKE_BODY_TILE         '+'
#define FRUIT_TILE              '*'

//  The debug mode
#define DEBUG                   1

#define DEBUG_X                 0
#define DEBUG_Y                 GUI_Y + 5

#define DEBUG_PRINT(string, ...)              \
  if (DEBUG)                                  \
  {                                           \
    MOVE_CURSOR(DEBUG_X, DEBUG_Y);            \
    printf("DEBUG:\n" string, ##__VA_ARGS__); \
  }

//  The starting length of the snake
#define STARTING_LENGTH         3

//  The keys enum
//
//  Defines the keys used for the input
///  @param UP - Key: W
///  @param DOWN - Key: S
///  @param LEFT - Key: A
///  @param RIGHT - Key: D
///  @param EXIT - Key: X
typedef enum Keys
{
  UP = 'W',
  DOWN = 'S',
  LEFT = 'A',
  RIGHT = 'D',
  EXIT = 'X'
} Keys;


#endif
