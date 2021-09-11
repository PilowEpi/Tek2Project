/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** angles computing
*/

#include <math.h>

#include "zappy.h"

double anglecalc(float dx, float dy)
{
    double d = sqrt(pow(dx, 2) + pow(dy, 2));
    double a = acos(dx/d);

    if (dy > 0)
        a *= -1;
    if (a < 0)
        a += M_PI*2;
    return (a);
}

double find_angle(float xa, float ya, float xb, float yb)
{
    double dx = xa - xb;
    double dy = ya - yb;
    double d = sqrt(pow(dx, 2) + pow(dy, 2));
    if (d == 0)
        return -5000;
    double a = acos(dx/d);

    if (dy > 0)
        a *= -1;
    if (a < 0)
        a += M_PI*2;
    return (a);
}

int case_id(player_t *psrc, player_t *pdest, int with, int height)
{
    float angle = find_angle(with/2, height/2,
        (pdest->x - psrc->x + (int)(with*1.5)) % with - with*0.5,
        (pdest->y - psrc->y + (int)(height*1.5)) % height - height*0.5);
    if (angle == -5000)
        return 0;
    angle -= (6-pdest->rotation)%4*M_PI/2;
    float array[] = {
        anglecalc(1.5, 0.5)-M_PI*2, anglecalc(1.5, -0.5),
        anglecalc(0.5, -1.5), anglecalc(-0.5, -1.5),
        anglecalc(-1.5, -0.5), anglecalc(-1.5, 0.5),
        anglecalc(-0.5, 1.5), anglecalc(0.5, 1.5),
        anglecalc(1.5, 0.5), anglecalc(1.5, -0.5)+M_PI*2,
    };
    for (int i = 0; i < 9; i++)
        if (array[i] <= angle && angle <= array[i+1])
            return (i%8+1);
}
