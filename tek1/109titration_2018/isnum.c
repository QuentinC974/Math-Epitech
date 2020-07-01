/*
** EPITECH PROJECT, 2019
** header
** File description:
** header
*/

int isnum(char *str)
{
    int i = (str[0] == '-') ? 1 : 0;

    if (str[i] == '-')
            i++;
    if (str[0] == 0)
            return (84);
    while (str[i] != 0) {
        if (str[i] == '.' || str[i] == '\n') {
            i++;
            continue;
        }
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (84);
        i++;
    }
    return (0);
}
