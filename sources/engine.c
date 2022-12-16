#include "engine.h"


//  Extern definitions

Fruit fruit;
int length = 0;
char map[MAP_HEIGHT][MAP_WIDTH + 1];

void initGeneral()
{
    _hideCursor();

    srand(time(NULL));

    initMap();
    initSnake();
    spawnFruit(&fruit);

    MOVE_CURSOR(GUI_X, GUI_Y);
    printf("Instructions:\n\tW, A, S, D - Move\n\tX - Exit\n");
    MOVE_CURSOR(SCORE_X, GUI_Y);
    printf("SCORE:");

    CNS_CLEAR;
}

void initMap()
{

    int i, j;

    for (i = 0; i < MAP_HEIGHT; i++)
    {

        for (j = 0; j < MAP_WIDTH; j++)
        {

            map[i][j] = MAP_TILE;

            if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1)
                map[i][j] = WALL_TILE;
        }

        map[i][j] = '\n';
    }

    map[MAP_HEIGHT - 1][MAP_WIDTH] = '\0';
}

void displayMap()
{

    puts(map);

    //  SLEEP;

    CNS_CLEAR;
}

void input()
{

    if (kbhit())
    {

        char ch = getch();

        if (ch >= 'a' && ch <= 'z')
            ch -= 32; //  Convert to uppercase

        switch (ch)
        {

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

    SLEEP
}

void collisionCheck(Snake *_head)
{
    switch (map[head->y][head->x])
    {
    case WALL_TILE:

        switch (head->currDir)
        {
        case UP:
            head->y = MAP_HEIGHT - 3;
            break;

        case DOWN:
            head->y = 2;
            break;

        case LEFT:
            head->x = MAP_WIDTH - 3;
            break;

        case RIGHT:
            head->x = 2;
            break;

        default:
            break;
        }
        break;

    case FRUIT_TILE:

        insertPart(head);
        spawnFruit(&fruit);
        updateScore();

        break;

    case SNAKE_BODY_TILE:
        killSnake(head);
        break;
    }
}

//  Terminal thingys

void drawChar(int x, int y, char symbol)
{
    MOVE_CURSOR(x, y);
    putchar(symbol);
}

void _hideCursor()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}



//  Basically moves each part to the previous one's position
//  in the case that the part is the one before the head, it will move to the head's position with the tempX and tempY variables
void drawSnake(Snake *_head)
{

    // Clear the previous position
    while (_head != NULL)
    {

        map[_head->y][_head->x] = MAP_TILE;
        drawChar(_head->x, _head->y, MAP_TILE);

        _head = _head->next;
    }

    //  Give the default value back
    _head = head;

    int tempX = _head->x, tempY = _head->y;

    //  Snake * temp = _head;

    //  Give the current Snake part the coordonates of the previous one, before changing them

    switch (_head->currDir)
    {

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

    default:
        break;
    }

    collisionCheck(_head);

    //   Setting the cursor color to the snake's color
    SET_CURSOR_COLOR(_head->color);

    map[_head->y][_head->x] = _head->symbol;
    drawChar(_head->x, _head->y, _head->symbol);

    _head = last;

    while (_head != head)
    {
        Keys _prevCurrDir = _head->prev->currDir;
        int _prevX = _head->prev->x, _prevY = _head->prev->y;

        _head->currDir = _prevCurrDir;

        if (_head->prev != head)
        {
            _head->x = _prevX;
            _head->y = _prevY;
        }
        else
        {
            _head->x = tempX;
            _head->y = tempY;
        }

        collisionCheck(_head);

        map[_head->y][_head->x] = _head->symbol;
        drawChar(_head->x, _head->y, _head->symbol);

        _head = _head->prev;
    }

    //  Reset the cursor color to the default one
    SET_CURSOR_COLOR(WHITE);
}

//  Kills the snake and frees the memory
void killSnake(Snake * _head){

    while(_head != NULL){

        //  The death animation
        map[_head->y][_head->x] = MAP_TILE;
        drawChar(_head->x, _head->y, MAP_TILE);

        Snake * temp = _head->next;

        free(_head);

        _head = temp;

        SLEEP;
    }


}



void spawnFruit(Fruit *_fruit)
{

    //  Reset current position
    map[_fruit->y][_fruit->x] = MAP_TILE;

    //  Solving the bug where the fruit spawns on the snake

    int _maxArea = length + STARTING_LENGTH < 5 ? 5 : length + STARTING_LENGTH;

    do {
        _fruit->x = rand() % (MAP_WIDTH - 5) + 2;
        _fruit->y = rand() % (MAP_HEIGHT - 5) + 2;

    } while(
        _fruit->x >= head->x - _maxArea && _fruit->x <= head->x + _maxArea 
        && 
        _fruit->y >= head->y - _maxArea && _fruit->y <= head->y + _maxArea
    );

    DEBUG_PRINT("Fruit spawned at\nx: %d, y: %d", _fruit->x, _fruit->y);

    drawFruit(_fruit);
}

void drawFruit(Fruit *_fruit)
{

    map[_fruit->y][_fruit->x] = FRUIT_TILE;
    drawChar(_fruit->x, _fruit->y, FRUIT_TILE);
}

void updateScore()
{
    MOVE_CURSOR(SCORE_X, SCORE_Y);
    printf("%d", ++length);

    CNS_CLEAR;
}
