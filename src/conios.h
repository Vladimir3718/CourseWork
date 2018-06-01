#include <stdio.h>

void gotoxy(int x, int y);

void clrscr(void);

void initTermios(int echo);

void resetTermios(void);

char getch_(int echo);

char getch(void);

