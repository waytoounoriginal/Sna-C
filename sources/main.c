#include "engine.h"

int main()
{
    MAXIMIZE;
    //  displayMainMenu();

    initGeneral();
    displayMap();

    while (1)
    {
        input();

        drawSnake(head);
    }

    return 0;
}