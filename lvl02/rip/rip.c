#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int checking_parentheses(char *parentheses)
{
    int opened = 0;
    int closed = 0;

    for(int i = 0; parentheses[i]; i++)
    {
        if(parentheses[i] == '(')
            opened++;
        else if(parentheses[i] == ')')
            if(opened > 0)
                opened--;
            else
                closed++;
    }
    return (opened + closed);
}
void solve(char *st, int to_fix, int fixed, int position)
{
    if(to_fix == fixed && !checking_parentheses(st))
    {
        puts(st);
        return ;
    }
    for(int i = position; st[i]; i++)
    {
        char type_of = st[i];
        st[i] = ' ';
        solve(st, to_fix, fixed + 1, i + 1);
        st[i] = type_of;
    }
}

int main(int argc, char **argv)
{
    if(argc < 2)
        return 1;
    int to_fix = checking_parentheses(argv[1]);
    solve(argv[1], to_fix, 0, 0);
    return 0;
}