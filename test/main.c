#define CTEST_MAIN

#include "add_tem.h"
#include <ctest.h>
#include <string.h>
#include <stdio.h>

//SlavaKPSS
CTEST (Creat_file_without_space, True_file)
{
    char nameTest[256];

    strcpy(nameTest, "testxt/setTrueFile.txt");

    int result = setFile(nameTest);
    int expected = 0;

    ASSERT_EQUAL(expected, result);
}

CTEST (Creat_ThemeFile, True_file)
{
    char theme[256], nameFile[256], nameThemeWay[256];

    strcpy(nameThemeWay, "testxt/setfileTheme.txt");
    strcpy(theme, "Тема\n");
    strcpy(nameFile, "testxt/checkCorrect1.txt");

    int result = setTheme(theme, nameFile, nameThemeWay);
    int expected = 0;

    ASSERT_EQUAL(expected, result);
}

CTEST (Creat_ThemeFile, False_file)
{
    char theme[256], nameFile[256], nameThemeWay[256];

    strcpy(nameThemeWay, "testxt/setfileTheme.txt");
    strcpy(theme, "Тема");
    strcpy(nameFile, "NoFile.txt");

    int result = setTheme(theme, nameFile, nameThemeWay);
    int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST (No_ThemeFile, False_file)
{
    char theme[256], nameFile[256], nameThemeWay[256];

    strcpy(nameThemeWay, "testxt/setNoTheme.txt");
    strcpy(theme, "Тема");
    strcpy(nameFile, "NoFile.txt");

    int result = setTheme(theme, nameFile, nameThemeWay);
    int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST (setQuestion, True_set)
{
    char quest[256] = "Вопрос";
    FILE *file = fopen("testxt/setQuestion.txt", "wb");

    int result = setQuest(quest, 1, file);
    int expected = 0;

    ASSERT_EQUAL(expected, result);
}

CTEST (setQuestion, False_set)
{
    char quest[256] = "\n";
    FILE *file = fopen("testxt/setQuestion.txt", "wb");

    int result = setQuest(quest, 1, file);
    int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST (setAnwer, True_set)
{
    char answer[256] = "Ответ";
    FILE *file = fopen("testxt/setAnswer.txt", "wb");

    int result = setAnswer(answer, 1, file);
    int expected = 0;

    ASSERT_EQUAL(expected, result);
}

CTEST (setAnwer, Fasle_set)
{
    char answer[256] = "\n";
    FILE *file = fopen("testxt/setAnswer.txt", "wb");

    int result = setAnswer(answer, 1, file);
    int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST (setTryAnwer, True_set)
{
    char try[12];
    int k = 1, n = 2;
    FILE *file = fopen("testxt/setTryAnswer.txt", "wb");
    try[1] = '1';

    int result = setTryAnswer(try, &k, n, file);
    int expected = 0;

    ASSERT_EQUAL(expected, result);
}

CTEST (setTryAnwer, False_set_try_no_int)
{
    char try[12];
    int k = 1, n = 2;
    FILE *file = fopen("testxt/setTryAnswer.txt", "wb");
    try[1] = 'n';

    int result = setTryAnswer(try, &k, n, file);
    int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST (setTryAnwer, False_set_more_n)
{
    char try[12];
    int k = 2, n = 1;
    FILE *file = fopen("testxt/setTryAnswer.txt", "wb");
    try[1] = '2';

    int result = setTryAnswer(try, &k, n, file);
    int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST (setTryAnwer, False_set_repeat_try)
{
    char try[12];
    int k = 3, n = 4;
    FILE *file = fopen("testxt/setTryAnswer.txt", "wb");
    try[1] = '1';
    try[2] = '2';
    try[3] = '2';

    int result = setTryAnswer(try, &k, n, file);
    int expected = 1;

    ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv)
{
    int test_result = ctest_main(argc, argv);
    return test_result;
}
