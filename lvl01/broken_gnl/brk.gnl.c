#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
    int i = 0;

    if (!s || !*s)
        return (NULL);
    while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return s + i;
	else
		return NULL;
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;

    // if (dest == src)
    //     return (dest);
    // if (dest < src)
    // {
    //     i = 0;
    //     while (i < n)
    //     {
    //         ((char*)dest)[i] = ((char*)src)[i];
    //         i++;
    //     }
    // }
    // else
    // {
    //     i = n;
    //     while (i-- > 0)
    //     {
    //         ((char*)dest)[i] = ((char*)src)[i];
    //     }
    // }
    i = 0;

    while (i < n)
    {
        ((char *)dest)[i] = ((char *)src)[i];
        i++;
    }
    return dest;
}

size_t  ft_strlen(char *s)
{
    size_t ret = 0;

    if (!s || !*s)
        return (0);
    while (*s)
	{
        // printf("ft_strlen\n");
		s++;
		ret++;
	}
    return (ret);
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
    size_t size1 = ft_strlen(*s1);
    char *tmp = malloc(size2 + size1 + 1);
    if (!tmp)
        return 0;
    ft_memcpy(tmp, *s1, size1);
    ft_memcpy(tmp + size1, s2, size2);
    tmp [size1 + size2] = 0;
    free(*s1);
    *s1 = tmp;
    return 1;
}

int str_append_str(char **s1, char *s2)
{
    return str_append_mem(s1, s2, ft_strlen(s2));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;

    if (dest == src)
        return (dest);
    if (dest < src)
    {
        i = 0;
        while (i < n)
        {
            // printf("ft_memmove\n");
            ((char*)dest)[i] = ((char*)src)[i];
            i++;
        }
    }
    else
    {
        i = n;
        while (i-- > 0)
        {
            // printf("ft_memmove\n");
            ((char*)dest)[i] = ((char*)src)[i];
        }
    }
    return dest;
    // if (dest > src)
    //     return ft_memcpy(dest, src, n);
    // else if (dest == src)
    //     return dest;
	// size_t i = ft_strlen((char *)src) - 1;
    // while (i >= 0)
	// {
	// 	((char *)dest)[i] = ((char *)src)[i];
	// 	i--;
	// }
    // return dest;
}

char    *get_next_line(int fd)
{
    static char b[BUFFER_SIZE + 1] = "";
    char *ret = NULL;


    while (1)
    {
        // printf("gnl\n");
        char *tmp = ft_strchr(b, '\n');
        if (tmp)
        {
            if (!str_append_mem(&ret, b, tmp - b + 1))
            {
                free(ret);
                return NULL;
            }
            // printf("printing b: %s\n", b);
            // printf("printing tmp + 1: %s\n", tmp + 1);
            ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
            return ret;
        }
        if (!str_append_str(&ret, b))
            return (free(ret), NULL);
        int read_ret = read(fd, b, BUFFER_SIZE);
        if (read_ret <= 0)
        {
            if (read_ret == -1 || (!ret || !*b))
                return (free(ret), NULL);
            b[0] = 0;
            if (read_ret == 0)
                break ;

            // return (ret);
        }
        b[read_ret] = 0;
    }
    return ret;
    // if (!str_append_mem(&ret, b, tmp - b + 1))
    // {
    //     free(ret);
    //     return NULL;
    // }
    // return ret;
}

// char    *get_next_line(int fd)
// {
//     static char b[BUFFER_SIZE + 1] = "";
//     char *ret = NULL;

//     char *tmp = ft_strchr(b, '\n');
//     while (!tmp)
//     {
//         if (!str_append_str(&ret, b))
//             return NULL;
//         int read_ret = read(fd, b, BUFFER_SIZE);
//         if (read_ret == -1)
//             return NULL;
//         b[read_ret] = 0;
//     }
//     if (!str_append_mem(&ret, b, tmp - b + 1))
//     {
//         free(ret);
//         return NULL;
//     }
//     return ret;
// }

// int main()
// {
//     int fd = open("test.txt", O_RDONLY);
//     char    *line = NULL;
    
//     while ((line = get_next_line(fd)) != 0)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     return 0;
// }