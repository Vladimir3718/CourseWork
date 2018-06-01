#include <stdio.h>
#include <stdlib.h>

int ANSWER_QUANTITY = 16;

int  startTesting(char *testName)
{
    FILE *file;
    char cPtr;
    int answerMass[ANSWER_QUANTITY];
    int i;

    for (i = 0; i < ANSWER_QUANTITY; i++) {
        answerMass[i] = 0;
    }

    if (!(file = fopen(testName, "rb"))) {
        fputs("ERROR\n", stdout);
    }

    fputs("Прохождение теста\n", stdout);
    while (fread(&cPtr, 1, 1, file)) {

        if (cPtr == '!' || cPtr == '$' || cPtr == '#') {
            printf("\n");
        } else {
            if (cPtr == '^') {
                i = -1;
                fread(&cPtr, 1, 1, file);
                while(cPtr != '#') {
                    i++;
                    cPtr -= 10;
                    answerMass[i] = atoi(&cPtr);
                    fread(&cPtr, 1, 1, file);
                }
            }
            if (cPtr != '#') {
                printf("%c", cPtr);
            }
        }
    }
    fclose(file);

    return 0;
}    
