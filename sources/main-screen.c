#include "main-screen.h"

int selectedOptions = 0;

bool selected = false;

Option options[2] = {
    {OPTIONS_X, OPTIONS_Y, "Play"},
    {OPTIONS_X + 7, OPTIONS_Y, "Exit"} // 7 = strlen("Play") + 2 spaces
};

void drawLogo()
{
    MOVE_CURSOR(LOGO_X, LOGO_Y);
    puts(
        " ________  ________   ________                 ________     \n"
        "|\\   ____\\|\\   ___  \\|\\   __  \\               |\\   ____\\    \n"
        "\\ \\  \\___|\\ \\  \\\\ \\  \\ \\  \\|\\  \\  ____________\\ \\  \\___|    \n"
        " \\ \\_____  \\ \\  \\\\ \\  \\ \\   __  \\|\\____________\\ \\  \\       \n"
        "  \\|____|\\  \\ \\  \\\\ \\  \\ \\  \\ \\  \\|____________|\\ \\  \\____  \n"
        "    ____\\_\\  \\ \\__\\\\ \\__\\ \\__\\ \\__\\              \\ \\_______\\\n"
        "   |\\_________\\|__| \\|__|\\|__|\\|__|               \\|_______|\n"
        "   \\|_________|                                             ");
}

void drawCredits()
{
    MOVE_CURSOR(CREDITS_X, CREDITS_Y);

    puts(
        "Made by: " OWNER "\n"
        "With the help of: " CONTRIBUTORS);
}

void drawVersion()
{
    MOVE_CURSOR(VERSION_X, VERSION_Y);

    puts(
        VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH);
}

void drawOptions()
{
    for (int i = 0; i < 2; ++i)
    {
        MOVE_CURSOR(options[i].x, options[i].y);
        puts(options[i].text);
    }
}

void checkInput()
{

    if (kbhit())
    {
        char ch = getch();

        if (ch >= 'A' && ch <= 'Z')
        {
            ch += 32;
        }

        switch (ch)
        {
        case 'a':
            selectedOptions = 0;
            changeOption(selectedOptions);
            break;
        case 'd':
            selectedOptions = 1;
            changeOption(selectedOptions);
            break;

        case 13:
            selected = true;
            break;
        }

        SLEEP;
    }
}

void changeOption(int option)
{
    //  clear the previous option
    fputs("  ", stdin);

    MOVE_CURSOR(options[option].x - 2, options[option].y);
    fputs("->", stdin);
}

int drawMainMenu()
{

    drawLogo();
    drawOptions();
    drawCredits();
    drawVersion();

    MOVE_CURSOR(options[selectedOptions].x - 2, options[selectedOptions].y);

    changeOption(selectedOptions);

    while (!selected)
    {
        checkInput();
    }

    return selectedOptions;
}
