#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int sum_of_subset(int *subset, int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += subset[i];
    }
    return sum;
}

void printing_subset(int *subset, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d", subset[i]);
        if(i < size - 1)
            printf(" ");
    }
    printf("\n");
}

void solve(int *numbers, int *subset, int sub_size ,int n, int size, int index)
{
    if(index == size)
    {
        if(sum_of_subset(subset, sub_size) == n)
            printing_subset(subset, sub_size);
        return ;
    }
    subset[sub_size] = numbers[index];
    solve(numbers, subset, sub_size + 1, n, size, index + 1);
    solve(numbers, subset, sub_size, n, size, index + 1);
}

int  main(int argc, char **argv)
{
    if(argc == 1)
        return 1;
    int size = argc - 2;
    int n =  atoi(argv[1]);
    int *numbers = malloc(sizeof(int)* size);
    int *subset = malloc(sizeof(int)* size);
    for(int i = 0; i < size; i++)
    {
        numbers[i] = atoi(argv[i + 2]);
    }
    solve(numbers, subset, 0, n, size, 0);
    free(numbers);
    free(subset);
    return 0;
}