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



#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "snake.h"
#include "fruit.h"

//  The map, along with the snake and the fruit
//
//  The map is an array of [MAP_HEIGHT] rows and [MAP_WIDTH] + 1 columns to account for the '\0' character
char map[MAP_HEIGHT][MAP_WIDTH + 1];

//  The score 
int length = 1;


//  ========================
//
//  Misc + Map
//
//  ========================


//  Initialises serveral things, such as the map, the snake and the fruit
//
//  It also draws the instructions and the score
void initGeneral();

//  Initialises the map as an array of [MAP_HEIGHT] rows and [MAP_WIDTH] columns
void initMap();

//  Displays the map every [SLEEP_TIME] in ms
void displayMap();

//  Updates the score
void updateScore();









//  ========================
//
//  Snake
//
//  ========================


//  Checks for input from the user. They use the Keys enum from defines.h
//  
//  The inputs are defined as follows:
//      [UP] - Key: W
//      [DOWN] - Key: S
//      [LEFT] - Key: A
//      [RIGHT] - Key: D
void input();

//  Checks fot serval collision. It works in this way:
//      The [WALL_TILE] is a '#', the [SNAKE_BODY_TILE] is a '+', the [SNAKE_HEAD_TILE] is a '0' and the [FRUIT_TILE] is a '*'
//      If the snake's head collides with the [WALL_TILE], the whole snake wraps around the map
//      If the snake's head collides with the [SNAKE_BODY_TILE], the game ends (until a new game is started)
//
/// @param _head The snake's head. Type: Snake *
void collisionCheck(Snake * _head);

//  Draws the snake, aka moves the head to the position and every other part to the position of the part in front of it
//
/// @param _head The snake's head. Type: Snake *
void drawSnake(Snake * _head);









//  ========================
//
//  Fruit
//
//  ========================


//  Spawns the fruit in a random position
//
/// @param _fruit The pointer to the fruit. Type: Fruit *
void spawnFruit(Fruit *_fruit);

//  Draws the fruit
//
/// @param _fruit The pointer to the fruit. Type: Fruit *
void drawFruit(Fruit *_fruit);

#endif
