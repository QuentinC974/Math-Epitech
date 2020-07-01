/*
** EPITECH PROJECT, 2019
** header
** File description:
** header
*/

int isnum(char *str)
{
    int i = 0;

    if (str[0] == 0)
        return (84);
    while (str[i] != 0) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (84);
        i++;
    }
    return (0);
}
