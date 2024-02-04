/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Permits to create our own tab.
** create_own_tab
*/

#include "include/my.h"
#include "include/setting_up.h"

char **fill_tab(char **tab, int dimensions, char *pattern)
{
    int ind_pattern = 0;
    int ind_tab = 0;
    int i = 0;

    while (ind_tab < dimensions) {
        tab[ind_tab][i] = pattern[ind_pattern];
        i++;
        ind_pattern++;
        if (i == dimensions) {
            tab[ind_tab][i] = '\n';
            tab[ind_tab][i + 1] = '\0';
            i = 0;
            ind_tab++;
        }
        if (ind_pattern == my_strlen(pattern))
            ind_pattern = 0;
    }
    return tab;
}

char **create_own_tab(char **tab, int dimensions, char *pattern)
{
    tab = malloc(sizeof(char *) * (dimensions + 1));
    for (int i = 0; i < dimensions; i++)
        tab[i] = malloc(sizeof(char) * (dimensions + 2));
    tab = fill_tab(tab, dimensions, pattern);
    tab[dimensions] = NULL;
    return tab;
}
