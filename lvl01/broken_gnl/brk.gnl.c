#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *ft_strdup(char *string)
{
    int i = -1;
    char *copy_of_str = malloc(strlen(string) + 1);

    while(string[++i])
    {
        copy_of_str[i] = string[i];
    }
    copy_of_str[i] = '\0';

    return copy_of_str;
}

char *brk_gnl(int fd)
{
    static char buffer[BUFFER_SIZE];
	static int	read_digit;
	static int	read_position;
	char	line[70000];
	int		i = 0;

    if(fd < 0)
        return NULL;

    while(1)
    {
        if(read_digit <= read_position)
        {
            read_digit = read(fd, buffer, BUFFER_SIZE);
            read_position = 0;
            if(read_digit <= 0)
                break;
        }
        line[i++] = buffer[read_position++];
        if(buffer[read_position - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if(i == 0)
        return  NULL;
    return ft_strdup(line);
}

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    if (fd < 0) { perror("open"); return 1; }

    char *s;
    int   n = 1;
    while ((s = brk_gnl(fd)) != NULL) {
        printf("LINE %d: %s", n++, s);
        free(s);
    }
    close(fd);
    return 0;
}