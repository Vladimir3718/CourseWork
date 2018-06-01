#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "conios.h"
#include "add_tem.h"

#include "checkfile.h"

#define x 100
#define y 20
#define xh 70
#define yh 20

int main()
{
    int i;
    char enter;
    char nameFileFull[256], nameFile[256]; 
    char nameTheme[256], nameThemeWay[256];
    char a[256];

    /*CREAT ADDTEST*/
    while(1){
        /*HELP*/

        //Помощь

        gotoxy(xh, yh+1);
        printf("Вверх:   'W'");
        gotoxy(xh, yh+2);
        printf("Вниз:    'S'");
        gotoxy(xh, yh+3);
        printf("Выбрать: 'E'");

        //Меню
        gotoxy(x, y+1);
        printf("\x1b[1;36m");
        printf("Создать тест");
        printf("\x1b[0m");
        gotoxy(x, y+2);
        printf("Пройти  тест");
        gotoxy(x, y+3);
        printf("Помощь");
        gotoxy(x, y+4);
        printf("Выйти");

        i = 1;
        gotoxy(x+12, y+i);
        enter=' ';
        while (enter!='e') {
            clrscr();
            enter=getch();
            /*HELP*/
            gotoxy(xh, yh+1);
            printf("Вверх:   'W'");
            gotoxy(xh, yh+2);
            printf("Вниз:    'S'");
                gotoxy(xh, yh+3);
                printf("Выбрать: 'E'");
            /*MENU*/
            gotoxy(x, y+1);
            printf("Создать тест");
            gotoxy(x, y+2);
            printf("Пройти  тест");
            gotoxy(x, y+3);
            printf("Помощь");
            gotoxy(x, y+4);
            printf("Выйти");
            /*CHECK*/
            if (enter==119) i--;
            if (enter==115) i++;
            if (i<1) i=4;
            if (i>4) i=1;
            /*SWITCH POINTER*/
            gotoxy(x, y+i);
            printf("\x1b[1;36m");
            switch (i) {
            case 1: printf("Создать тест"); break;
            case 2: printf("Пройти  тест"); break;
            case 3: printf("Помощь"); break;
            case 4: printf("Выйти"); break;
            }
            printf("\x1b[0m");
        }

        //Выбор пункта
        printf("\n");
        gotoxy(0, 0);
        switch (i) {
        case 1:

            system("clear");
            fputs("Введите Имя файла: ", stdout);
            scanf("%s", nameFile);

            strcpy(nameFileFull, "../txt/");
            strcat(nameFileFull, nameFile);
            strcat(nameFileFull, ".txt");
            strcpy(nameFile, nameFileFull);

            if (setFile(nameFileFull)) {
                break;
            }

            fputs("Введите Тему: ", stdout);
            __fpurge(stdin);
            fgets(nameTheme, 256, stdin);

            strcpy(nameThemeWay, "../Tests/Tests.txt");

            if (setTheme(nameTheme, nameFileFull, nameThemeWay)) {
                break;
            }

            setTest(nameFileFull);
            break; //Creat
        case 2:
            system("clear");
            strcpy(a, "../Tests/Tests.txt");
            if (Checkfile(a) == 1) {
                printf("\nФайл не существует или изначально был пуст,");
                printf(" пройдите в пункт меню для создания теста.\n");
                printf("Для выхода в меню нажмите любую клавишу...\n");
                getch();
                break;
            }

            break; //StartTest
        case 3:
            break; //HALP
        case 4:
            clrscr();

            return 0; //Выхiд
        }
    }
}
































