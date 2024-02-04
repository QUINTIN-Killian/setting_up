/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Converts the file content into a tab array.
** convert_file_in_tab_array
*/

#include "include/my.h"
#include "include/setting_up.h"

static int get_nb_columns(char *buff)
{
    int ind = 0;
    int ans = 0;

    while (buff[ind] != '\n')
        ind++;
    ind++;
    while (buff[ind] != '\n') {
        ind++;
        ans++;
    }
    return ans;
}

static int get_nb_lines(char *buff)
{
    int nb_lines = 0;
    int elt = 0;
    int ind = 0;

    while (buff[ind] != '\n')
        ind++;
    ind--;
    while (ind >= 0) {
        nb_lines = nb_lines + (buff[ind] - 48) *
        (my_compute_power_rec(10, elt));
        ind--;
        elt++;
    }
    return nb_lines;
}

char **get_ind_start_of_buff(char **tab, char *buff, int *elt)
{
    int nb_columns = get_nb_columns(buff);
    int nb_lines = get_nb_lines(buff);

    tab = malloc(sizeof(char *) * (nb_lines + 1));
    for (int k = 0; k < nb_lines; k++)
        tab[k] = malloc(sizeof(char) * (nb_columns + 2));
    while (buff[*elt] != '\n')
        *elt = *elt + 1;
    *elt = *elt + 1;
    return tab;
}

char **convert_file_in_tab_array(char **tab, char *buff)
{
    int ind_tab = 0;
    int i = 0;
    int elt = 0;

    tab = get_ind_start_of_buff(tab, buff, &elt);
    while (buff[elt] != '\0') {
        if (buff[elt] == '\n') {
            tab[ind_tab][i] = buff[elt];
            tab[ind_tab][i + 1] = '\0';
            i = 0;
            ind_tab++;
        } else {
            tab[ind_tab][i] = buff[elt];
            i++;
        }
        elt++;
    }
    tab[get_nb_lines(buff)] = NULL;
    return tab;
}

char *malloc_buff(char *file_name, char *buff, int *file_size)
{
    struct stat statbuff;

    stat(file_name, &statbuff);
    *file_size = statbuff.st_size;
    buff = malloc(*file_size + 1);
    return buff;
}

char **get_file_content(char **tab, char *file_name)
{
    int file_size;
    char *buff;
    int len;
    int fd = open(file_name, O_RDONLY);

    if (fd == -1)
        return NULL;
    buff = malloc_buff(file_name, buff, &file_size);
    len = read(fd, buff, file_size);
    close(fd);
    buff[file_size] = '\0';
    if (len < 0) {
        free(buff);
        return NULL;
    }
    if (is_valid_file(buff) == 84)
        return NULL;
    tab = convert_file_in_tab_array(tab, buff);
    free(buff);
    return tab;
}
