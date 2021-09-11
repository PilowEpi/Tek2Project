/*
** EPITECH PROJECT, 2021
** teams
** File description:
** test use cmd
*/

#include "tests.h"

Test(use, use_one_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", NULL};

    use(1, buf, 1);
    cr_assert_stdout_eq_str("TCP USET\nTCP USEC\nTCP USETR\n");
}

Test(use, use_two_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "toto", NULL};

    use(2, buf, 1);
    cr_assert_stdout_eq_str("TCP USET toto\nTCP USEC\nTCP USETR\n");
}

Test(use, use_three_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "toto", "tptp", NULL};

    use(3, buf, 1);
    cr_assert_stdout_eq_str("TCP USET toto\nTCP USEC tptp\nTCP USETR\n");
}

Test(use, use_four_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "toto", "tptp", "LUL", NULL};

    use(4, buf, 1);
    cr_assert_stdout_eq_str("TCP USET toto\nTCP USEC tptp\nTCP USETR LUL\n");
}