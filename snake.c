#include "snake.h"

Snake * head;

void initSnake() {

    head = (Snake *)malloc(sizeof(Snake));

    *head = (Snake){
        .x = STARTING_X + 1, .y = STARTING_Y + 1, .length = 2, .next = NULL, .currDir = DOWN, .symbol = SNAKE_HEAD_TILE
    };


}

void insertPart(Snake * _head) {


    head->length++;

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
    }


   while(_head->next != NULL) {
        _head = _head->next;
    }

    *_newPart = (Snake){
        .x = _head->x + addX, .y = _head->y + addY, .length = head->length, .next = NULL, .currDir = _head->currDir, .symbol = SNAKE_BODY_TILE
    };

    _head->next = _newPart;

    if(DEBUG){
        FILE * fp = fopen("debug.txt", "a");

        fprintf(fp, "New part added: \n\t{ x: %d, y: %d, length: %d, next: %d}\n", _newPart->x, _newPart->y, _newPart->length, _newPart->next);

        fclose(fp);

    }

}


