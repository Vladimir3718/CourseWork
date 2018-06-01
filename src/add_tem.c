#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_tem.h"

#define _OPEN_SYS_ITOA_EXT
#define KEY 10
#define NUM 9

int setFile(char *nameFile)
{
    FILE *file;

    if (!(file = fopen(nameFile, "wb"))) {
        return 1;
    }

    return 0;
}

int setTheme(char *nameTheme, char *nameFile, char *nameThemeWay)
{
    FILE *file, *file_t;
    char pro_s = '&', end_len = '\n';

    if (!(file = fopen(nameThemeWay, "ab"))) {
        return 1;
    }

    if (!(file_t = fopen(nameFile, "rb"))) {
        return 1;
    }
    fclose(file_t);

    fwrite(nameTheme, 1, strlen(nameTheme)-1, file);
    fwrite(&pro_s, 1, 1, file);
    fwrite(nameFile, 1, strlen(nameFile), file);
    fwrite(&end_len, 1, 1, file);

    fclose(file);

    return 0;
}

int setTest(char *nameFile)
{
    FILE *file;
    char quest[256], answer[256], try[12];//question answer number-correct
    char quit = 'u', enter_v = 'u', enter_o = 'u';//exits
    char otv_s = '!', try_s = '^', end_s = '#', end_len = '\n';//service chars
    int k = 1, i = 1, j = 0, n;        //Counters

    if (!(file = fopen(nameFile, "ab"))) {
        return 1;
    }

    do {        // input questions of answers and correct

        system("clear");
        printf("Введите %d-ый вопрос: ", i);
        __fpurge(stdin);
        fgets(quest, 256, stdin);

        while ((setQuest(quest, i, file))) {
            printf("Ошибка!\n");
            printf("Введите %d-ый вопрос: ", i);
            __fpurge(stdin);
            fgets(quest, 256, stdin);
        }

        j = 0;
        fwrite(&otv_s, 1, 1, file);
        do {        // input answers

            j++;
            printf("Введите %d-ый ответ: ", j);
            __fpurge(stdin);
            fgets(answer, 256, stdin);

            while ((setAnswer(answer, j, file))) {
                printf("Ошибка!\n");
                printf("Введите %d-ый ответ: ", j);
                __fpurge(stdin);
                fgets(answer, 256, stdin);
            }

            printf("\nЗакончить ввод ответов?[y]: ");
            scanf("%c", &enter_o);

        } while (enter_o != 'y' && j < NUM);
        n = j;

        k = 1;
        fwrite(&try_s, 1, 1, file);
        do {        //input true answers

            printf("Введите %d-ый правильный номер ответа: ", k);
            __fpurge(stdin);
            try[k] = getchar();

            while ((setTryAnswer(try, &k, n, file))) {
                printf("Ошибка!\n");
                printf("Введите %d-ый правильный номер: ", k);
                __fpurge(stdin);
                try[k] = getchar();
            }

            printf("\nЗакончить ввод правильных номеров?[y]: ");
            __fpurge(stdin);
            scanf("%c", &quit);

        } while (quit != 'y' && k < 10 && k <= n);

        fwrite(&end_s, 1, 1, file);
        fwrite(&end_len, 1, 1, file);

        printf("\nЗакончить ввод вопросов?[y]: ");
        __fpurge(stdin);
        scanf("%c", &enter_v);

        fflush(file);
        i++;

    } while (enter_v != 'y');

    fclose(file);
    printf("Для продолжения нажмите Enter...");
    __fpurge(stdin);
    getchar();

    return 0;
}

int setQuest(char *quest, int i, FILE *file)
{
    char buffer[10], vop_s = '$', t[3] = ". ";

    if (quest[0] == '\n') {
        return 1;
    }

    fwrite(&vop_s, 1, 1, file);
    sprintf(buffer, "%d", i);//convert from int to char
    fwrite(buffer, 1, 1, file);
    fwrite(t, 1, 2, file);
    fwrite(quest, 1, strlen(quest), file);

    return 0;
}

int setAnswer(char *answer, int j, FILE *file)
{
    char buffer[10], sk[3] = ") ";

    if (answer[0] == '\n') {
        return 1;
    }

    sprintf(buffer, "%d", j);

    fwrite(buffer, 1, 1, file);
    fwrite(sk, 1, 2, file);
    fwrite(answer, 1, strlen(answer), file);

    return 0;
}

int setTryAnswer(char *try, int *k, int n, FILE *file)
{
    char num = n + '0';
    int flag;
    try[0] = '0';

    if (try[*k] >= '1' && try[*k] <= '9' && try[*k] <= num) {
        flag = 1;
        for (int i = 0; i < *k; i++) {
            if (try[*k] == try[i]) {
                flag = 0;
            }
        }
        if  (flag) {
            try[*k] += KEY;
            fwrite(try + (*k), 1, 1, file);
            (*k)++;
        } else {
            return 1;
        }
    } else {
        return 1;
    }

    return 0;
}
