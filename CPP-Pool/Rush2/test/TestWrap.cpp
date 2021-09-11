/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Test File
*/

#include <criterion/criterion.h>
#include "Test.hpp"
#include "Wrap.hpp"
#include "Teddy.hpp"

Test(getName, test_Wrap_getName)
{
    Wrap wrap("test");

    cr_assert_eq(wrap.getName(), "test");
}

Test(getToyType, test_Wrap_getType)
{
    Wrap wrap("test");

    cr_assert_eq(wrap.getType(), 1);
}

Test(Redirector, test_Wrap_getOut)
{
    OSRedirector oss(std::cerr);
    Wrap wrap("test");
    std::string output = "test, an object. Is taken!\n";

    std::cerr << wrap;
    cr_assert_eq(oss.getContent(), output);
}

Test(openClose, test_Wrap_openAndClose)
{
    Wrap wrap("test");

    cr_assert_eq(wrap.isOpen(), true);
    wrap.closeMe();
    cr_assert_eq(wrap.isOpen(), false);
    wrap.openMe();
    cr_assert_eq(wrap.isOpen(), true);
}

Test(deleteWrap, test_Wrap_delete)
{
    Wrap *wrap = new Wrap("test");

    wrap->~Wrap();
}

Test(testWrap, test_Wrap_meThat)
{
    Wrap wrap("test");
    Teddy *ted = new Teddy("test");

    wrap.wrapMeThat(ted);
}

Test(testWrap, test_Wrap_whatInside)
{
    Wrap wrap("test");
    Teddy *ted = new Teddy("test");

    wrap.wrapMeThat(ted);
    cr_assert_eq(wrap.whatsInside(), ted);
}