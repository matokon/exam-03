#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void swapping(char *el1, char *el2)
{
    char temp;
    temp = *el1;
    *el1 = *el2;
    *el2 = temp;
}

void printing_func(char *word, int len)
{
    write(1,word,len);
    write(1,"\n",1);
}
void sorting(char *s)
{
    for(int i = 0; s[i]; i++)
    {
        for(int j = i + 1; s[j]; j++)
        {
            if(s[i] > s[j])
            {
                swapping(&s[i], &s[j]);
            }
        }
    }
}
void solve(char *arg, int start, int length)
{
    if(start == length)
    {
        printing_func(arg, length);
        return ;
    }
    else
    {
        for(int x = start; x < length; x++)
        {
            swapping(&arg[start], &arg[x]);     
            solve(arg, start + 1, length);
            swapping(&arg[start], &arg[x]);
        }
    }
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Error: wrong number of arguments.\n");
        return 1;
    }
    char *arg = strdup(argv[1]);
    int length = strlen(argv[1]);
    sorting(arg);
    solve(arg, 0, length);
    free(arg);
}