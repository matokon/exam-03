#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int checker(char *str1){
    int opened = 0;
    int closed = 0;
    for(int i = 0; str1[i]; i++){
        if(str1[i] == '(')
            opened++;
        else if(str1[i] == ')')
            if(opened > 0)
                opened--;
            else
                closed++;
    }
    return opened + closed;
}

void solve(char *str1, int to_fix, int fixed, int position){
    if(to_fix == fixed && checker(str1) == 0){
        puts(str1);
        return ;
    }
    for(int i = position; str1[i]; i++){
        char type_of = str1[i];
        str1[i] = ' ';
        solve(str1, to_fix, fixed + 1, i + 1);
        str1[i] = type_of;
    }
}

int main(int argc, char **argv)
{
    if(argc != 2)
        return 1;
    char* string1 = argv[1];
    int to_fix = checker(string1);
    solve(string1, to_fix, 0, 0);
    return 0;
}