/*
** EPITECH PROJECT, 2020
** redirect_all_std.c
** File description:
** redirect_all_std
*/

#ifndef _TEST_MYTEAMS_
#define _TEST_MYTEAMS_

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

#endif