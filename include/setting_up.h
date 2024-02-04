/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Setting up header
** setting_up
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef SETTING_UP_H_
    #define SETTING_UP_H_

int test_ac_2(char **av);
int test_ac_3(char **av);
int is_valid_file(char *buff);
int print_tab(char **tab);
char **get_file_content(char **tab, char *file_name);
char **create_own_tab(char **tab, int dimensions, char *pattern);

#endif
