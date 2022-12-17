#ifndef __WINDOWS_H__
#define __WINDOWS_H__



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>      //  Get Linux alternative
#include <time.h>
#include <windows.h>

//  Helper functions for the terminal
#define CNS_CLEAR SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){0, 0});
#define MOVE_CURSOR(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x, y});

#define KBHIT kbhit();

#define HIDE_CURSOR                                \
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); \
    CONSOLE_CURSOR_INFO ConCurInf;                 \
    ConCurInf.dwSize = 10;                         \
    ConCurInf.bVisible = FALSE;                    \
    SetConsoleCursorInfo(hOut, &ConCurInf);

#define SLEEP _sleep(SLEEP_TIME);
#define MAXIMIZE ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

typedef enum Colors
{
    //  Primary colors RGB
    RED = FOREGROUND_RED,
    GREEN = FOREGROUND_GREEN,
    BLUE = FOREGROUND_BLUE,

    //  Default color
    WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,

    //  Secondary colors CMY
    CYAN = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    YELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
    PURPLE = FOREGROUND_RED | FOREGROUND_BLUE,
    MAGENTA = PURPLE | FOREGROUND_INTENSITY
} Colors;

#define SET_CURSOR_COLOR(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

#endif