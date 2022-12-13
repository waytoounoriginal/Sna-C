#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "snake.h"
#include "fruit.h"

char map[MAP_HEIGHT][MAP_WIDTH + 1];

int length = 1;

void initGeneral();

void initMap();
void displayMap();
void input();

void collisionCheck(Snake * _head);

void drawSnake(Snake * _head);

void spawnFruit(Fruit *_fruit);
void drawFruit(Fruit *_fruit);

void updateScore();

#endif
