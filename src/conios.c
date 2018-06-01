#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "conios.h"

static struct termios old, new;

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

void clrscr(void)
{
    system("clear");
}

void initTermios(int echo)
{
    tcgetattr(0, &old);
    new=old;
    new.c_lflag&=~ICANON;
    new.c_lflag&=~ECHO;
    tcsetattr(0, TCSANOW, &new);
}

void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch=getchar();
    resetTermios();
    return ch;
}

char getch(void)
{
    return getch_(0);
}
