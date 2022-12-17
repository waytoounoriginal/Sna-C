#ifndef __MAIN_SCREEN_H__
#define __MAIN_SCREEN_H__

#include "defines.h"

#define SCREEN_HEIGHT GUI_Y + 2
#define SCREEN_WIDTH MAP_WIDTH

#define LOGO_X 0
#define LOGO_Y 0

#define CREDITS_X 0
#define CREDITS_Y SCREEN_HEIGHT - 1

#define VERSION_X SCREEN_WIDTH - 10
#define VERSION_Y SCREEN_HEIGHT - 1

#define OPTIONS_Y LOGO_Y + 10
#define OPTIONS_X LOGO_X + 5

extern int selectedOption;

void drawLogo();

void drawOption(int x, int y, int option);

void drawCredits();

void drawVersion();





void checkInput();

void changeOption(int option);

int drawMainMenu();


typedef struct Option
{
    int x;
    int y;
    const char * text;
} Option;

extern Option options[2];





#endif