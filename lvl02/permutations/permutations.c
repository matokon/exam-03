#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void swap1(char *el1, char *el2)
{
    char tmp = *el1;
    *el1 = *el2;
    *el2 = tmp;
}

void sorting(char *arg){
    for(int i = 0; arg[i]; i++)
    {
        for(int j = 0; arg[j]; j++)
        {
            if(arg[i] > arg[j])
                swap1(&arg[i], &arg[j]);
        }
    }
}

void printf_f(char *arg, int len_of_argv)
{
    write(1, arg, len_of_argv);
    write(1,"\n",1);
}
void solve1(char *arg, int len_of_argv, int position)
{
    if(position == len_of_argv)
    {
        printf_f(arg, len_of_argv);
        return ;
    }
    for(int i = position; arg[i]; i++)
    {
        swap1(&arg[position], &arg[i]);
        solve1(arg, len_of_argv, position + 1);
        swap1(&arg[position], &arg[i]);
    }
}

int main(int argc, char **argv)
{
    if(argc != 2)
        return 1;
    char *arg = strdup(argv[1]);
    int len_of_argv = strlen(argv[1]);
    sorting(arg);
    solve1(arg, len_of_argv, 0);
}