#include "snake.h"

Snake * head;
Snake * last;

char * initSymbol(char * _color, char _symbol){

    char * _tmp = (char *)calloc(2, sizeof(char));
    _tmp[0] = _symbol;

    char * symbol = (char *)calloc(SNAKE_SYMBOL_SIZE, sizeof(char));
    strcat(symbol, _color);
    strcat(symbol, _tmp);

    free(_tmp);

    return symbol;
}


void initSnake() {

    head = (Snake *)malloc(sizeof(Snake));

    char * symbol = initSymbol(ANSI_CYAN, SNAKE_HEAD_TILE);

    *head = (Snake){
        .x = STARTING_X + STARTING_LENGTH, .y = STARTING_Y + STARTING_LENGTH, .prev = NULL, .next = NULL, .currDir = DOWN, .symbol = symbol
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

    char * symbol = initSymbol(ANSI_CYAN, SNAKE_BODY_TILE);

    *_newPart = (Snake) {
        .x = last->x + addX, .y = last->y + addY, .prev = last,.next = NULL, .currDir = last->currDir, .symbol = symbol
    };

    last->next = _newPart;

    last = _newPart;

}


