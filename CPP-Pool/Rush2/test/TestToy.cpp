/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Test File
*/

#include <criterion/criterion.h>
#include "Test.hpp"
#include "Toy.hpp"

Test(getName, test_Toy_getName)
{
    Toy ted("test");

    cr_assert_eq(ted.getName(), "test");
}

Test(getToyType, test_Toy_getType)
{
    Toy ted("test");

    cr_assert_eq(ted.getType(), 0);
}

Test(Redirector, test_Toy_getOut)
{
    OSRedirector oss(std::cerr);
    Toy ted("test");

    std::string output = "test, a toy, overall an Object. Is taken!\n";

    std::cerr << ted;
    cr_assert_eq(oss.getContent(), output);
}