/*
** EPITECH PROJECT, 2021
** teams
** File description:
** log errors
*/

#include "logging_client.h"

int err_team(int len, char **buf)
{
    if (len != 2)
        return (1);
    client_error_unknown_team(buf[1]);
    return (0);
}

int err_channel(int len, char **buf)
{
    if (len != 2)
        return (1);
    client_error_unknown_channel(buf[1]);
    return (0);
}

int err_thread(int len, char **buf)
{
    if (len != 2)
        return (1);
    client_error_unknown_thread(buf[1]);
    return (0);
}

int err_user(int len, char **buf)
{
    if (len != 2)
        return (1);
    client_error_unknown_user(buf[1]);
    return (0);
}

int err_exists(int len, char **buf)
{
    if (len != 1)
        return (1);
    client_error_already_exist();
    return (0);
}
