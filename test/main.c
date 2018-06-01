#define CTEST_MAIN

#include "add_tem.h"
#include <ctest.h>
#include <string.h>
#include <stdio.h>
#include "select.h"
#include "startTesting.h"
#include "displaylist.h"
#include "checkfile.h"

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
//V-znachit Vova
CTEST (Check_Fake_File, Correct_Check)
{
    char a[256];
    strcpy(a,"Empty.txt");
    int result = Checkfile(a);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST (Check_File, Correct_Check)
{
    char a[256];
    strcpy(a,"testxt/testfile.txt");
    int result = Checkfile(a);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST (Check_Empty_File, Correct_Check)
{
    char a[256];
    strcpy(a,"testxt/testfile_empty.txt");
    int result = Checkfile(a);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST (Display_Empty_File, Correct_Check)
{
    char a[256];
    strcpy(a,"testxt/testfile_empty.txt");
    int result = Displaylist(a);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST (Display_Fake_File, Correct_Check)
{
    char a[256];
    strcpy(a,"Empty.txt");
    int result = Displaylist(a);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST (Display_File, Correct_Check)
{
    char a[256];
    strcpy(a,"testxt/testfile.txt");
    printf("\n");
    int result = Displaylist(a);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST (Select_InCorrect_Theme, Correct_Check)
{
    char a[256],tema[256];
    int choice=2;
    strcpy(a,"testxt/testfile.txt");
    int result = Select(a,tema,choice);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST (Select_Correct_Theme, Correct_Check)
{
    char a[256],tema[256];
    int choice=1;
    strcpy(a,"testxt/testfile.txt");
    int result = Select(a,tema,choice);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST (Select_In_Fake_File, Correct_Check)
{
    char a[256],tema[256];
    int choice=1;
    strcpy(a,"Empty.txt");
    int result = Select(a,tema,choice);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST (Select_In_Empty_File, Correct_Check)
{
    char a[256],tema[256];
    int choice=0;
    strcpy(a,"testxt/testfile_empty.txt");
    int result = Select(a,tema,choice);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}
//Maxim_Sladkiy
CTEST (checkCorrect1, Right_File)
{
    char testName[256];
    strcpy(testName, "testxt/checkCorrect1.txt");
    int result=checkCorrect(testName);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (checkCorrect2, Absolutely_False_File)
{
    char testName[256];
    strcpy(testName, "testxt/checkCorrect2.txt");
    int result=checkCorrect(testName);
    int expected=1;
    ASSERT_EQUAL(expected, result);
}

CTEST (checkCorrect3, False_File_With_One_Right_Symbol)
{
    char testName[256];
    strcpy(testName, "testxt/checkCorrect3.txt");
    int result=checkCorrect(testName);
    int expected=1;
    ASSERT_EQUAL(expected, result);
}

CTEST (checkCorrect4, False_File_With_Two_Right_Symbol)
{
    char testName[256];
    strcpy(testName, "testxt/checkCorrect4.txt");
    int result=checkCorrect(testName);
    int expected=1;
    ASSERT_EQUAL(expected, result);
}

CTEST (checkCorrect5, False_File_With_Three_Right_Symbol)
{
    char testName[256];
    strcpy(testName, "testxt/checkCorrect5.txt");
    int result=checkCorrect(testName);
    int expected=1;
    ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv)
{
    int test_result = ctest_main(argc, argv);
    return test_result;
}
