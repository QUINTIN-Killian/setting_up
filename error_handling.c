/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Manages the error handling.
** error_handling
*/

#include "include/my.h"
#include "include/setting_up.h"

int test_ac_2(char **av)
{
    struct stat st;

    if (stat(av[1], &st) == -1)
        return 84;
    if (!S_ISREG(st.st_mode))
        return 84;
    if (st.st_size == 0)
        return 84;
}

int test_ac_3(char **av)
{
    if (my_strlen(av[1]) == 0 || my_strlen(av[2]) == 0)
        return 84;
    for (int i = 0; i < my_strlen(av[1]); i++)
        if (av[1][i] < 48 || av[1][i] > 57)
            return 84;
    for (int i = 0; i < my_strlen(av[2]); i++)
        if (av[2][i] != '.' && av[2][i] != 'o')
            return 84;
    return 0;
}

static int get_len(int *ind, char *buff)
{
    int len = 0;

    while (buff[*ind] != '\n' && buff[*ind] != '\0') {
        if (buff[*ind] != '.' && buff[*ind] != 'o')
            return -1;
        *ind = *ind + 1;
        len++;
    }
    if (buff[*ind] == '\0')
        return -1;
    *ind = *ind + 1;
    return len;
}

static int verif_len(char *buff, int ind, int *temp, int len)
{
    if (buff[ind] == '\n') {
        if (*temp != len)
            return 84;
        *temp = -1;
    }
}

int is_valid_file_aux(char *buff, int *ind, int *temp, int len)
{
    while (buff[*ind] != '\0') {
        if (buff[*ind] != '.' && buff[*ind] != 'o' && buff[*ind] != '\n')
            return 84;
        if (verif_len(buff, *ind, temp, len) == 84)
            return 84;
        *ind = *ind + 1;
        *temp = *temp + 1;
    }
    return 0;
}

int is_valid_file(char *buff)
{
    int ind = 0;
    int len;
    int temp = 0;

    while (buff[ind] != '\n' && buff[ind] != '\0') {
        if (buff[ind] < 48 || buff[ind] > 57)
            return 84;
        ind++;
    }
    if (buff[ind] == '\0')
        return 84;
    ind++;
    len = get_len(&ind, buff);
    if (len == -1)
        return 84;
    if (is_valid_file_aux(buff, &ind, &temp, len) == 84)
        return 84;
}
