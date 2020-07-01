/*
** EPITECH PROJECT, 2019
** titre
** File description:
** moi !
*/

#include "my.h"

char **create(char *filepath)
{
    int i = count_it(filepath);
    FILE *fd = fopen(filepath, "r");
    size_t s = 0;
    char **values = malloc(sizeof(char *) * (i + 1));
    int e = 0;

    for (int u = 0 ; u != i ; u++)
        values[u] = NULL;
    while (getline(&values[e], &s, fd) != -1)
        e++;
    values[e] = NULL;
    fclose(fd);
    return (values);
}

double **init_tab(char **val)
{
    double **values = NULL;
    int i = 0;
    char **tmp = NULL;

    for (; val[i] != NULL ; i++);
    values = malloc(sizeof(double *) * (i + 1));
    values[i] = NULL;
    for (int j = 0 ; val[j] != NULL ; j++)
        values[j] = malloc(sizeof(double) * 3);
    for (int k = 0 ; val[k] != NULL ; k++) {
        tmp = str_to_tab(val[k], ';');
        values[k][0] = atof(tmp[0]);
        values[k][1] = atof(tmp[1]);
    }
    return (values);
}

int do_it(char *filepath)
{
    char **val = create(filepath);
    double **values = init_tab(val);
    double **res1 = init_tab(val);
    double equi[2] = {0, 0};

    res1 = first(values, res1, &equi);
    second(res1, values);
    values = third(values, equi);
    return (0);
}

/*
ph+1 - ph-1
-----------
vl+1 - vl-1
*/
