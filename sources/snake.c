#include "snake.h"

Snake * head;
Snake * last;

Colors _color = CYAN;

void initSnake() {

    head = (Snake *)malloc(sizeof(Snake));


    *head = (Snake){
        .x = STARTING_X + STARTING_LENGTH, .y = STARTING_Y + STARTING_LENGTH, .prev = NULL, .next = NULL, .currDir = DOWN, .symbol = SNAKE_HEAD_TILE, .color = _color
    };

    last = head;

    for(int i = 0; i < STARTING_LENGTH; i++){
        insertPart(head);
    }


}

void insertPart(Snake * _head) {

   

    Snake * _newPart = (Snake *)malloc(sizeof(Snake));

    int addX = 0, addY = 0;

    switch(_head->currDir){
        case UP:
            addX = 0;
            addY = 1;
            break;
        
        case DOWN:
            addX = 0;
            addY = -1;
            break;
        
        case LEFT:
            addX = 1;
            addY = 0;
            break;
        
        case RIGHT:
            addX = -1;
            addY = 0;
            break;
        
        default:
            break;
    }

    *_newPart = (Snake) {
        .x = last->x + addX, .y = last->y + addY, .prev = last,.next = NULL, .currDir = last->currDir, .symbol = SNAKE_BODY_TILE, .color = head->color
    };

    last->next = _newPart;

    last = _newPart;

}