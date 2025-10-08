#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int compare(char *buffor, char *to_compare, int len_of_compare)
{
    int x = 0;
    while(x < len_of_compare && buffor[x] == to_compare[x])
        x++;
    if(x == len_of_compare)
        return 1;
    else
        return 0;
}


int main(int argc, char **argv)
{
    if(argc != 2 || argv[1] == NULL || strlen(argv[1]) == 0)
        return 1;
    char *to_compare;
    char *buffor = malloc(10000);
    if(!buffor)
    {
        perror("Malloc error!");
        free(buffor);
        return 1;
    }
    int len_to_compare;
    char letter;
    int helper;
    int i;

    to_compare = argv[1];
    len_to_compare = strlen(to_compare);
    i = 0;
    
    helper = read(0, &letter, 1);
    if(helper < 0)
    {
        free(buffor);
        perror("Error");
        return 1;
    }
    while(helper > 0)
    {
        buffor[i++] = letter;
        helper = read(0, &letter, 1);
    }
    if(helper < 0)
    {
        free(buffor);
        perror("Error");
        return 1;
    }
    buffor[i] = '\0';

    int len_helper;
    i = -1;
    while(buffor[++i] != '\0')
    {
        if(compare(&buffor[i], to_compare, len_to_compare) == 1)
        {
            i = i + len_to_compare-1;
            len_helper = len_to_compare;
            while(len_helper != 0)
            {
                printf("%s","*");
                len_helper--;
            }
        }
        else
            printf("%c",buffor[i]);
    }
    free(buffor);
    return 0;
}