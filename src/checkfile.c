#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "checkfile.h"

int Checkfile(char source[256])
{
    char ch, name[256];
    int i, flag, num, num_buff, error, end = 0;
    FILE *f1, *f2, *f3;

    f1 = fopen(source, "rb");
    if (!f1) {
        return 1;
    }

    while (!feof(f1)) {
        ch = getc(f1);
        if (ch == 0x0a) {
            end++;
        }
    }
    fclose(f1);
    if (end == 0) {
        return 1;
    }

    for (; end > 0; end--) {
        f1 = fopen(source, "rb");
        f2 = fopen("buffer.txt", "wb");
        error = 0;
        num = 0;
        num_buff = 0;

        while (!feof(f1)) {
            ch = ' ';
            flag = 0;

            for (i = 0; i < 256; i++) {
                name[i] = 0;
            }

            i = 0;
            num++;
            while (ch != 0x0a) {
                ch = getc(f1);
                if (feof(f1)) {
                    i++;
                    break;
                }
                if (ch == '&') {
                    flag = 1;
                    continue;
                }
                if (flag == 1) {
                    if (ch != 0x0a) {
                        name[i] = ch;
                        i++;
                    }
                }
            }
            if (flag == 0 && ch != EOF) {
                error = 1;
            }
            name[i] = '\0';
            if (strlen(name) < 3) {
                break;
            }
            if (!(f3 = fopen(name, "rb"))) {
                error = 1;
                break;
            }
        }
        rewind(f1);
        num_buff = 0;

        while (!feof(f1)) {
            if (!error) {
                break;
            }
            num_buff++;
            ch = ' ';

            while (ch != 0x0a) {
                ch = getc(f1);
                if (feof(f1)) {
                    break;
                }
                if (num == num_buff) {
                    continue;
                }
            putchar(ch);
            putc(ch,f2);
            }
        }
        if (error == 1) {
            fclose(f1);
            remove(source);
            fclose(f2);
            rename("buffer.txt" , source);
        } else {
            fclose(f2);
            remove("buffer.txt");
        }
    }

    return 0;
}
