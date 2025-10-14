#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_board(int *board, int n)
{
    for(int x = 0; x < n; x++)
    {
        fprintf(stdout,"%d" , board[x]);
        if(x < n - 1)
            fprintf(stdout, " ");
        else
            fprintf(stdout, "\n");
    }
}
int checker(int *board, int col, int row)
{
    for(int i = 0; i < col; i++)
    {
        if(board[i] == row || board[i] - row == col - i || row - board[i] == col - i)
            return 1;
    }
    return 0;
}
void solve(int *board, int col, int n)
{
    if(col == n)
    {
        print_board(board, n);
        return ;
    }
    for(int row = 0; row < n; row++)
    {
        if(checker(board, col, row) == 0)
        {
            board[col] = row;
            solve(board, col + 1, n);
        }
    }
}

int main(int argc, char **argv)
{
    (void)argc;
    if (argc != 2) {
        write(2, "Usage: ./n_queens N\n", 21);
        return 1;
    }
    int n = atoi(argv[1]);

    int *board = malloc(sizeof(int) * n);
    solve(board, 0, n);
    free(board);
}