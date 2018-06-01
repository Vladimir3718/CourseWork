#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "select.h"

int Select(char source[256], char name[256], int choice)
{
    int num = 0, flag, i;
    char ch;
    FILE *f1;

    for (i = 0; i < 256; i ++) {
        name[i] = 0;
    }

    f1 = fopen(source, "rb");
    if (!f1) {
        return 1;
    }

    while (!feof(f1)) {
        ch = getc(f1);
        if (ch == 0x0a) {
            num++;
        }
    }
    fclose(f1);

    if (num < choice || choice < 1) {
        return 1;
    }
    num = 0;

    f1 = fopen(source, "rb");
    if (!f1) {
        return 1;
    }
    while (!feof(f1)) {
        flag = 0;
        i = 0;
        ch = ' ';
        num++;
        while (ch != 0x0a) {
            ch = getc(f1);
            if (feof(f1)) {
                break;
            }
            if (num != choice) {
                continue;
            }
            if (ch == '&') {
                flag = 1;
                continue;
            }
            if (flag == 1) {
                if (ch != 0x0a) {
                    name[i] = ch;
                    i++;
                } else {
                    flag = 0;
                }
            }
        }
    }
    fclose(f1);

    return 0;
}