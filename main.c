#include "pipex.h"

void ft_create_prechain(void)
{
    int i;
    char *path;
    path = ft_search_path("PATH=");
    g_da.pre_chain = ft_split(path, 58);
    i = 0;
    while (g_da.pre_chain[i] != NULL)
    {
        path = ft_strjoin(g_da.pre_chain[i], "/");
        free(g_da.pre_chain[i]);
        g_da.pre_chain[i] = path;
        i++;
    }
}

int main(int argc, char *argv[], char *env[])
{
    pid_t n1;
    pid_t n2;


    g_da.env = env;
    ft_handle_nb_arg(argc, argv);
    ft_create_prechain();
    n1 = fork();
    n2 = -1;
    if (n1 == 0)
        n2 = fork();
    /*if (pid == -1)
    {
        perror("fork");
        return 1;
    }
    else */
    if (n2 == 0)
    {
        ft_exec_part_one(env);
        return (1);
    }   
    else if (n1 == 0 && n2 != 0)
    {
        waitpid(-1, NULL, 0);
        ft_exec_part_two(env);
        return(1);
    }
    return (0);
}