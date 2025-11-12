#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int sum_subset(int *subset, int size){
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum = sum + subset[i];
    }
    return sum;
}

void print_subset(int *subset, int size){
    for(int i = 0; i < size; i++)
    {
        char c = '0' + subset[i];
        write(1, &c, 1);
        if(i < size - 1)
            write(1, " ", 1);
    }
    write(1, "\n", 1);
}

void solve(int *numbers, int *subset, int sub_size, int n, int size, int index)
{
    if(index == size)
    {   
        if(sum_subset(subset, sub_size) == n)
            print_subset(subset, sub_size);
        return ;
    }
    subset[sub_size] = numbers[index];
    solve(numbers, subset, sub_size + 1, n, size, index + 1);
    solve(numbers, subset, sub_size, n, size, index + 1);
}

int main(int argc, char **argv)
{
    if(argc < 2)
        return 1;
    int size = argc - 2;
    int *numbers = malloc(sizeof(int) * size);
    int *subset = malloc(sizeof(int) * size);
    int n = atoi(argv[1]);
    for(int i = 0; i < size; i++){
        numbers[i] = atoi(argv[i + 2]);
    }
    solve(numbers, subset, 0, n, size, 0);
    free(numbers);
    free(subset);
    return 0;
}