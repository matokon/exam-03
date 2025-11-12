#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int compare(char *str1, char *str_cmp, int len_of_cmp){
    for(int i = 0; i < len_of_cmp; i++)
    {
        if(str_cmp[i] != str1[i])
            return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if(argc != 2 || strlen(argv[1]) == 0)
        return 1;
    char *buffor = malloc(10000);
    if (!buffor) { perror("malloc"); return 1; }
    char *to_cmp;
    to_cmp = argv[1];
    int len_of_cmp = strlen(to_cmp);
    char letter;
    int helper = 0;
    helper = read(0,&letter,1);
    if(helper < 0)
    {
        free(buffor);
        perror("read error");
        return(1);
    }
    int i = -1;
    while(helper > 0)
    {
        buffor[++i] = letter;
        helper = read(0,&letter,1);
    }
    if(helper < 0)
        {
            free(buffor);
            perror("read error");
            return(1);
        }
    buffor[i+1] = '\0';
    i = -1;
    int len_of_buffor = strlen(buffor);
    int len_helper;
    while(buffor[++i] != '\0')
    {
        if(i + len_of_cmp <= len_of_buffor && compare(&buffor[i], to_cmp, len_of_cmp) == 0)
        {
            i = i + len_of_cmp -1;
            len_helper = len_of_cmp;
            while(len_helper != 0)
            {
                write(1,"*",1);
                len_helper--;
            }
        }
        else
        {
            write(1,&buffor[i],1);
        }
    }
    free(buffor);
    return 0;
}