/*
** EPITECH PROJECT, 2019
** str to
** File description:
** tab 2.0
*/

#include "my.h"

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
    while (str[i] != '\0' && str[i] != sep)
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
    for (int lol = 0; lol != *nb + 1; lol++)
        ret[lol] = NULL;
    return (ret);
}

char **str_to_tab(char *str, char sep)
{
    int nb = (strlen(str) > 0) ? 1 : 0;
    char **ret = nb_sep(&nb, str, sep);
    int j = 0;
    int len = 0;
    int r = 0;

    len = (count_charac(str, 0, sep) + 1);
    ret[0] = malloc(sizeof(char) * len);
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] == sep) {
            j = 0 + (0 * (i += 1)) + (0 * (r += 1));
            len = (count_charac(str, i, sep) + 1);
            ret[r] = malloc(sizeof(char) * len);
            ret[r][j] = 0;
        }
        ret[r][j] = str[i];
        j++;
        ret[r][j] = '\0';
    }
    ret[r + 1] = NULL;
    return (ret);
}
