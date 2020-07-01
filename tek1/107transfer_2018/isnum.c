/*
** EPITECH PROJECT, 2019
** header
** File description:
** header
*/

int isnumber(char *str)
{
    int i = (str[0] == '-') ? 1 : 0;

    if (str[0] == '*')
        return (84);
    while (str[i] != 0) {
        if (str[i] == '*') {
            i++;
            continue;
        }
        if (str[i] == '-') {
            i++;
            continue;
        }
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (84);
        i++;
    }
    if (str[i] == '*')
        return (84);
    return (0);
}
