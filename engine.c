#include "engine.h"

Fruit fruit;

int main()
{
    MAXIMIZE;
    //  displayMainMenu();

    initGeneral();

    while (1)
    {
        input();

        drawSnake(head);

        displayMap();
    }

    return 0;
}

void initGeneral()
{

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

    SLEEP;

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

    _sleep(100);
}

void collisionCheck(Snake *_head)
{

    switch (_head->currDir)
    {

    case UP:
        if (map[_head->y][_head->x] == WALL_TILE)
        {
            _head->y = MAP_HEIGHT - 2;
        }
        break;

    case DOWN:
        if (map[_head->y][_head->x] == WALL_TILE)
        {
            _head->y = 1;
        }
        break;

    case LEFT:
        if (map[_head->y][_head->x] == WALL_TILE)
        {
            _head->x = MAP_WIDTH - 2;
        }
        break;

    case RIGHT:
        if (map[_head->y][_head->x] == WALL_TILE)
        {
            _head->x = 1;
        }
        break;
    }

    if (map[head->y][head->x] == FRUIT_TILE)
    {
        insertPart(head);
        spawnFruit(&fruit);
        updateScore();
    }
    else if (map[head->y][head->x] == SNAKE_BODY_TILE)
    {
        exit(0);
    }
}

void drawSnake(Snake *_head)
{

    // Clear the previous position
    while (_head != NULL)
    {

        map[_head->y][_head->x] = MAP_TILE;

        _head = _head->next;
    }

    //  Give the default value back
    _head = head;

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
    }

    collisionCheck(_head);

    map[_head->y][_head->x] = _head->symbol;

    _head = last;

    while (_head != head)
    {
        _head->currDir = _head->prev->currDir;

        if (_head->prev != head)
        {
            _head->x = _head->prev->x;
            _head->y = _head->prev->y;
        }
        else
        {
            _head->x = _head->prev->currDir == UP || _head->prev->currDir == DOWN 
                ? _head->prev->x 
                : _head->prev->x + (_head->prev->currDir == LEFT ? 1 : -1);

            _head->y = _head->prev->currDir == LEFT || _head->prev->currDir == RIGHT 
                ? _head->prev->y 
                : _head->prev->y + (_head->prev->currDir == UP ? 1 : -1);
        }

        collisionCheck(_head);

        map[_head->y][_head->x] = _head->symbol;

        _head = _head->prev;
    }
}

void spawnFruit(Fruit *_fruit)
{

    //  Reset current position
    map[_fruit->y][_fruit->x] = MAP_TILE;

    _fruit->x = rand() % (MAP_WIDTH - 5) + 2;
    _fruit->y = rand() % (MAP_HEIGHT - 5) + 2;

    drawFruit(_fruit);
}

void drawFruit(Fruit *_fruit)
{

    map[_fruit->y][_fruit->x] = FRUIT_TILE;
}

void updateScore() {
    MOVE_CURSOR(SCORE_X, SCORE_Y);
    printf("%d", length ++);

    CNS_CLEAR;
}

