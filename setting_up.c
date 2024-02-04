/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Finds the biggest square possible in a square.
** setting_up
*/

#include "include/my.h"
#include "include/setting_up.h"

static int free_tab(char **tab)
{
    for (int i = 0; i < my_strlen_array(tab); i++)
        free(tab[i]);
    free(tab);
}

static int y_plus_one_when_x_equal_to(int *y, int *x, int equal)
{
    if (*x == equal) {
        *x = 0;
        *y = *y + 1;
    }
    return 0;
}

int print_tab(char **tab)
{
    for (int i = 0; i < my_strlen_array(tab); i++) {
        write(1, tab[i], my_strlen(tab[i]));
    }
    return 0;
}

int edit_tab(char **tab, int abs_ref, int ord_ref, int nb_elt_max)
{
    for (int y = 0; y < nb_elt_max; y++) {
        for (int x = 0; x < nb_elt_max; x++) {
            tab[ord_ref + y][abs_ref + x] = 'x';
        }
    }
    return 0;
}

int find_square(char **tab, int abs, int ord, int ans)
{
    int y = 0;
    int x = 0;

    if (abs + ans >= my_strlen(tab[0]) ||
    ord + ans > my_strlen_array(tab))
        return ans;
    if (tab[ord][abs] == 'o')
        return ans;
    while (y < ans) {
        if (tab[ord + y][abs + x] == 'o')
            return ans;
        x++;
        y_plus_one_when_x_equal_to(&y, &x, ans);
    }
    return find_square(tab, abs, ord, ans + 1);
}

int explore_square(char **tab)
{
    int y = 0;
    int x = 0;
    int nb_elt_max = 0;
    int abs_ref = 0;
    int ord_ref = 0;
    int ans_temp;

    while (y < my_strlen_array(tab)) {
        ans_temp = find_square(tab, x, y, 0) - 1;
        if (ans_temp > nb_elt_max) {
            nb_elt_max = ans_temp;
            abs_ref = x;
            ord_ref = y;
        }
        x++;
        y_plus_one_when_x_equal_to(&y, &x, my_strlen(tab[0]) - 1);
    }
    edit_tab(tab, abs_ref, ord_ref, nb_elt_max);
    return 0;
}

static void main_calls(char **tab)
{
    explore_square(tab);
    print_tab(tab);
    free_tab(tab);
}

int main(int ac, char **av)
{
    char **tab;

    if (ac <= 1 || ac > 3)
        return 84;
    if (ac == 2) {
        if (test_ac_2(av) == 84)
            return 84;
        tab = get_file_content(tab, av[1]);
    }
    if (ac == 3) {
        if (test_ac_3(av) == 84)
            return 84;
        tab = create_own_tab(tab,
        convert_str_in_int(av[1]), av[2]);
    }
    if (tab == NULL)
        return 84;
    main_calls(tab);
    return 0;
}
