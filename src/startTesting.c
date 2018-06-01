#include <stdio.h>
#include <stdlib.h>

int ANSWER_QUANTITY = 16;

void askName(char *nameAndFamily)
{
    system("clear");
    printf("Введите Имя и Фамилию: ");
    __fpurge(stdin);
    fgets(nameAndFamily, 128, stdin);
    system("clear");
}

int recordResult(int *answerMass, int *result, int key)
{
    static int resultNumber = 0, quantityPoints = 0;
    int userAnswer[ANSWER_QUANTITY];
    int i;

    if( key == 1) {
        resultNumber = 0;
        quantityPoints = 0;
    }

    for (i = 0; i < ANSWER_QUANTITY; i++) {
        userAnswer[i] = 0;
    }

    int quantityRightAnswer = 0;

    for (i = 0; i < ANSWER_QUANTITY; i++) {
        if (answerMass[i] != 0) {
            quantityRightAnswer += 1;
        } else {
            break;
        }
    }

    i = 0;
    do {
        printf("\nВведите номер %d-ого ответа:", i + 1);
        scanf("%d", userAnswer + i++);
        quantityRightAnswer--;
    } while (quantityRightAnswer != 0);

    int j = 0;
    for (i = 0; i < ANSWER_QUANTITY; i++) {
        if (answerMass[i] == 0) {
            break;
        }
        quantityPoints++;
        for (j = 0; j < ANSWER_QUANTITY; j++) {
            if(answerMass[i] == userAnswer[j]) {
                result[resultNumber++] = 1;
                break;
            }
        }
    }

    for (i = 0; i < ANSWER_QUANTITY; i++) {
        answerMass[i] = 0;
    }

    return quantityPoints;
}

int  startTesting(char *testName)
{
    FILE *file;
    char cPtr;
    char nameAndFamily[128];
    int answerMass[ANSWER_QUANTITY], result[ANSWER_QUANTITY];
    int i;
	int quantityPoints = 0;

    for (i = 0; i < ANSWER_QUANTITY; i++) {
        answerMass[i] = 0;
        result[i] = 0;
    }

    if (!(file = fopen(testName, "rb"))) {
        fputs("ERROR\n", stdout);
    }

	askName(nameAndFamily);
	
    fputs("Прохождение теста\n", stdout);
    key = 1;
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
            } else {
                 quantityPoints = recordResult(answerMass, result, key);
                 key++;
        }
    }
    
    int summ = 0;
    for (i = 0; i < ANSWER_QUANTITY; i++) {
        if (result[i] != 0) {
            summ += result[i];
        }
    }
    float pers = ((float)summ/quantityPoints)*100;
    printf("Ваш результат: ");
    printf("%sБаллы: %3d из %-3d -> %-.2f%%\n", nameAndFamily, summ, quantityPoints, pers);
    
    fclose(file);

    return 0;
}    
