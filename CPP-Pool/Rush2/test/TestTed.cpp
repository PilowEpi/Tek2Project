/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Test File
*/

#include <criterion/criterion.h>
#include "Test.hpp"
#include "Teddy.hpp"

Test(getName, test_Ted_getName)
{
    Teddy ted("test");

    cr_assert_eq(ted.getName(), "test");
}

Test(getToyType, test_Ted_getType)
{
    Teddy ted("test");

    cr_assert_eq(ted.getType(), 0);
}

Test(Redirector, test_Ted_getOut)
{
    OSRedirector oss(std::cerr);
    Teddy ted("test");
    std::string output = "test, a Toy of type Teddy, overall an Object. Is taken!\n";

    std::cerr << ted;
    cr_assert_eq(oss.getContent(), output);
}