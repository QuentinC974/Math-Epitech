/*
** EPITECH PROJECT, 2019
** header
** File description:
** header
*/

int isnumber(char *str)
{
    int i = 1;

    while (str[i] != 0) {
        if (str[i] == '.') {
            i++;
            continue;
        }
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (84);
        i++;
    }
    return (0);
}
