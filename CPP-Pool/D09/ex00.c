/*
** EPITECH PROJECT, 2020
** CPOOL D08
** File description:
** CPOOL D08
*/

#include <stdlib.h>
#include <stdio.h>

#include "ex00.h"

cthulhu_t *new_cthulhu()
{
    cthulhu_t *new_cthulhu = malloc(sizeof(cthulhu_t));

    if (!new_cthulhu)
        return (0);
    printf("----\n");
    cthulhu_initializer(new_cthulhu);
    return (new_cthulhu);
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power = this->m_power - 42;
        printf("%s attacks and destroys the city\n", this->m_name);
        return;
    }
    printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void sleeping(cthulhu_t *this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new_koala = malloc(sizeof(koala_t));

    if (!new_koala)
        return (0);
    printf("----\n");
    koala_initializer(new_koala, name, is_a_legend);
    return (new_koala);
}

void eat(koala_t *this)
{
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.m_name);
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_legend)
{
    this->m_is_a_legend = _is_A_legend;
    printf("Building Cthulhu\n");
    this->m_parent.m_name = _name;
    if (this->m_is_a_legend == 0)
        this->m_parent.m_power = 0;
    else
        this->m_parent.m_power = 42;
    printf("Building %s\n", this->m_parent.m_name);
}

static void cthulhu_initializer(cthulhu_t *this)
{
    this->m_name = "Cthulhu";
    this->m_power = 42;
    printf("Building %s\n", this->m_name);
}
