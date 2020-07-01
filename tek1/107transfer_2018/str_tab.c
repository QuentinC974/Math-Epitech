/*
** EPITECH PROJECT, 2019
** str to
** File description:
** tab
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

char *my_strcon(char *a, char *b)
{
    int len = 0;
    int cpt = 0;
    int cpt2 = 0;
    char *dest = NULL;

    if (a && strlen(a) > 0)
        len = strlen(a);
    if (b && strlen(b) > 0)
        len += strlen(b);
    dest = malloc(sizeof(char) * (len + 1));
    while (a && a[cpt] != '\0') {
        dest[cpt] = a[cpt];
        cpt++;
    }
    for (; b && b[cpt2] != '\0' ; cpt++, cpt2++)
        dest[cpt] = b[cpt2];
    dest[cpt] = '\0';
    return (dest);
}

int count_charac(char *str, int i, char sep)
{
    int count = 0;

    if (str[i] == sep)
        i++;
    while (str[i] != sep && str[i] != '\0')
    {
        i++;
        count++;
    }
    return count;
}

char **nb_sep(int *nb, char *str, char sep)
{
    char **ret = NULL;
    int i = 0;

    for (; str[i] != '\0' ; i++)
        if (str[i] == sep)
            *nb += 1;
    ret = malloc(sizeof(char *) * (*nb + 1));
    return (ret);
}

char **str_to_tab(char *str, int *row, char sep)
{
    int nb = (strlen(str) > 0) ? 1 : 0;
    char **ret = nb_sep(&nb, str, sep);
    int n_row = 0;
    int j = 0;
    int i = 0;

    ret[0] = malloc(sizeof(char) * (count_charac(str, i, sep) + 1));
    for (i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] == sep) {
            ret[n_row][j] = '\0';
            j = 0;
            i++;
            n_row++;
            ret[n_row] = malloc(sizeof(char) * (count_charac(str, i, sep) + 1));
        }
        ret[n_row][j] = str[i];
        j++;
    }
    ret[n_row + 1] = NULL;
    *row = n_row;
    return (ret);
}
