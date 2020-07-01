/*
** EPITECH PROJECT, 2018
** usage
** File description:
** screensaver
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void usage(void)
{
    int fd = open("usage.txt", O_RDONLY);
    char buffer[32];
    int x = 1;
    int cpt = 0;

    buffer[31] = 0;
    while ((x = read(fd, buffer, 32)) != 0) {
        write(1, buffer, x);
        cpt = 0;
        while (cpt != 32) {
            buffer[cpt] = 0;
            cpt++;
        }
    }
    close(fd);
}

void desc(void)
{
    int fd = open("desc.txt", O_RDONLY);
    char buffer[32];
    int x = 1;
    int cpt = 0;

    buffer[31] = 0;
    while ((x = read(fd, buffer, 32)) != 0) {
        write(1, buffer, x);
        cpt = 0;
        while (cpt != 32) {
            buffer[cpt] = 0;
            cpt++;
        }
    }
    close(fd);
}
