/*
** EPITECH PROJECT, 2021
** teams
** File description:
** test use cmd
*/

#include "tests.h"

Test(split_quoted, simple_split)
{
    char *buff = strdup("/login \"tester\"");
    char **res = split_quoted(buff, 0);
    int len = 0;
    int i = 0;

    for (; res && res[len]; len++);
    cr_assert_eq(len, 2);
    free(buff);
}

Test(split_quoted, bad_split_expected)
{
    char *buff = strdup("/login \"tester\"");
    char **res = split_quoted(buff, 1);
    int len = 0;
    int i = 0;

    for (; res && res[len]; len++);
    cr_assert_eq(res, 0);
    free(buff);
}

Test(split_quoted, one_split_expected)
{
    char *buff = strdup("/login");
    char **res = split_quoted(buff, 0);
    int len = 0;
    int i = 0;

    cr_assert_neq(res, 0);
    free(buff);
}

Test(parts_main, simple_main)
{
    char *buff = strdup("toto\nmdr\nlul");
    char **res = parts_main(buff);
    int len = 0;
    int i = 0;

    for (; res && res[len]; len++);
    cr_assert_eq(len, 3);
    free(buff);
}

Test(parts_main, simple_one_main)
{
    char *buff = strdup("toto");
    char **res = parts_main(buff);
    int len = 0;
    int i = 0;

    for (; res && res[len]; len++);
    cr_assert_eq(len, 1);
    free(buff);
}