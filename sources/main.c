#include "engine.h"
#include "main-screen.h"

int main()
{
    MAXIMIZE;

    //   draw the main screen

    int selected_mode = drawMainMenu();

    if(selected_mode == 1)  exit(0);

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