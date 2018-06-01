#include <stdio.h>
#include <string.h>
#include "info.h"

int Help(char source[])
{
    char ch;
    FILE *f1;

    f1 = fopen(source,"rb");
    if (!f1) {
        return 1;
    }

    while (!feof(f1)) {
        ch = getc(f1);
        if (ch == '%') {
            break;
        }
        putchar(ch);
    }

    return 0;
}