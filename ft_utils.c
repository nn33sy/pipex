#include "pipex.h"

char *ft_search_path(char *var)
{
    int i;

    i = 0;
    while (g_da.env[i] != NULL && ft_strncmp(g_da.env[i], var, ft_strlen(var)) != 0 )
        i++;
    return (g_da.env[i]);
}