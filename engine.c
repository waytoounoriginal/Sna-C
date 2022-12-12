#include "engine.h"

Fruit fruit;

int main() {
    //  displayMainMenu();

    initGeneral();

    while(1) {
        input();

        drawSnake(head);

        displayMap();
    }


    return 0;
}


void initGeneral() {

    srand(time(NULL));

    initMap();
    initSnake();
    spawnFruit(&fruit);

}



void initMap(){

    int i, j;

    for(i = 0; i < MAP_HEIGHT; i++){

        for(j = 0; j < MAP_WIDTH; j++){

            map[i][j] = MAP_TILE;

            if(i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1)  map[i][j] = WALL_TILE;
        }

        map[i][j] = '\n'; 

    }

    map[MAP_HEIGHT - 1][MAP_WIDTH] = '\0';

}

void displayMap() {


    puts(map);

    SLEEP;

    CNS_CLEAR;

}

void input() {

    if(kbhit()){

        char ch = getch();

        if(ch >= 'a' && ch <= 'z') ch -= 32;    //  Convert to uppercase

        switch(ch){

            case UP:
                head->currDir = UP;
                break;

            case DOWN:
                head->currDir = DOWN;
                break;

            case LEFT:
                head->currDir = LEFT;
                break;

            case RIGHT:
                head->currDir = RIGHT;
                break;

            case EXIT:
                exit(0);
                break;

        }


    }

    _sleep(100);

}

void collisionCheck() {

    switch(head->currDir){

        case UP:
            if(map[head->y - 1][head->x] == WALL_TILE){
                head->y = MAP_HEIGHT - 2;
            }
            break;

        case DOWN:
            if(map[head->y + 1][head->x] == WALL_TILE){
                head->y = 1;
            }
            break;
        
        case LEFT:
            if(map[head->y][head->x - 1] == WALL_TILE){
                head->x = MAP_WIDTH - 2;
            }
            break;

        case RIGHT:
            if(map[head->y][head->x + 1] == WALL_TILE){
                head->x = 1;
            }
            break;

    }

    if(map[head->y][head->x] == FRUIT_TILE){
        insertPart(head);
        spawnFruit(&fruit);
    }
    else if(map[head->y][head->x] == SNAKE_BODY_TILE){
        exit(0);
    }


}



void drawSnake(Snake * _head) {

    // Clear the previous position
    while(_head != NULL) {

        map[_head->y][_head->x] = MAP_TILE;

        _head = _head->next;
    }

    //  Give the default value back
    _head = head;

    //  Snake * temp = _head;

    switch(_head->currDir) {

        case UP:
            _head->y--;
            break;

        case DOWN:
            _head->y++;
            break;

        case LEFT:
            _head->x--;
            break;


        case RIGHT:
            _head->x++;
            break;

    }

    collisionCheck();

    while(_head != NULL) {

        map[_head->y][_head->x] = _head->symbol;

        _head = _head->next;
    }

}

void spawnFruit(Fruit * _fruit) {

    //  Reset current position
    map[_fruit->y][_fruit->x] = MAP_TILE;

    _fruit->x = rand() % (MAP_WIDTH - 5) + 2;
    _fruit->y = rand() % (MAP_HEIGHT - 5) + 2;

    drawFruit(_fruit);

}

void drawFruit(Fruit * _fruit){

    map[_fruit->y][_fruit->x] = FRUIT_TILE;

}


