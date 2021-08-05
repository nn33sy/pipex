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
    int            pipe_fd[2];


    g_da.env = env;
    ft_handle_nb_arg(argc, argv);
    ft_create_prechain();
    pipe(pipe_fd);
    n1 = fork();
    n2 = -1;
    if (n1 != 0)
    {
        n2 = fork();
        if (n2 == 0)
        {
            close(pipe_fd[0]);
            dup2(g_da.fd_1, STDIN_FILENO);
            dup2(pipe_fd[1], STDOUT_FILENO);
            close(pipe_fd[1]);
            ft_exec_part_one(env);
            return (1);
        }
        else
        {
            close(pipe_fd[0]);
            close(pipe_fd[1]);
            waitpid(-1, NULL, 0);
            waitpid(-1, NULL, 0);
            return(1);
        }
    }
    else 
    {
            close(pipe_fd[1]);
            dup2(g_da.fd_2, STDOUT_FILENO);
            dup2(pipe_fd[0], STDIN_FILENO);
            close(pipe_fd[0]);
            ft_exec_part_two(env);
            return(1);
    }
    return (0);
}