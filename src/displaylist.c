#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "displaylist.h"

int Displaylist(char source[256])
{
    int i = 0, flag = 0, end = 0;
    char ch;
    FILE *f1;

    f1 = fopen(source, "rb");
    if (!f1) {
        return 1;
    }

    while (!feof(f1)) {
        ch = getc(f1);
        if(ch == 0x0a)
        end++;
    }
    fclose(f1);

    if (end == 0) {
        return 1;
    }

    f1 = fopen(source, "rb");
    while (!feof(f1)) {
        ch = ' ';
        i++;
        if (i <= end) {
            printf("%d) ", i);
        }

        while (ch != 0x0a) {
            ch = getc(f1);
            if (feof(f1)) {
                break;
            }
            if (ch == '&') {
                flag = 1;
            }
            if (flag == 1 && ch != 0x0a) {
                continue;
            } else {
                flag = 0;
            }
            putchar(ch);
        }
    }
    fclose(f1);

    return 0;
}