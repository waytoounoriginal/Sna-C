#ifndef __LINUX_H__
#define __LINUX_H__


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <stropts.h>
#include <ncurses.h>


#define CNS_CLEAR move(0, 0);
#define MOVE_CURSOR(x, y) move(y, x);
#define HIDE_CURSOR curs_set(0);

#define KBHIT _kbhit();

#define SLEEP _sleep(SLEEP_TIME);
#define MAXIMIZE //  Not supported

typedef enum Colors
{
    //  Primary colors RGB
    RED = COLOR_RED,
    GREEN = COLOR_GREEN,
    BLUE = COLOR_BLUE,

    //  Default color
    WHITE = COLOR_WHITE,

    //  Secondary colors CMY
    CYAN = COLOR_CYAN,
    YELLOW = COLOR_YELLOW,
    PURPLE = COLOR_MAGENTA,
    MAGENTA = PURPLE
} Colors;

#define SET_CURSOR_COLOR(color) attron(COLOR_PAIR(color));





//  Linux KBHIT

int _kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;

    if (! initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}

#endif