/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Test File
*/

#include <criterion/criterion.h>
#include "Test.hpp"
#include "LittlePony.hpp"

Test(getName, test_LittlePony_getName)
{
    LittlePony ted("test");

    cr_assert_eq(ted.getName(), "test");
}

Test(getToyType, test_LittlePony_getType)
{
    LittlePony ted("test");

    cr_assert_eq(ted.getType(), 0);
}

Test(Redirector, test_LittlePony_getOut)
{
    OSRedirector oss(std::cerr);
    LittlePony ted("test");
    std::string output = "test, a Toy of type LittlePony, overall an Object. Is taken!\n";

    std::cerr << ted;
    cr_assert_eq(oss.getContent(), output);
}