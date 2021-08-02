#include "pipex.h"

void ft_create_path(t_cmd cmd)
{
    char *pre_chain;

    pre_chain = ft_strdup("/bin/");
    cmd.path = ft_strjoin(pre_chain, cmd.chain[0]);
    free(pre_chain);
}

void ft_exec_part_one(char **env)
{
    char **essai;
    essai = malloc(sizeof(char **) * 2);
    essai[0] = ft_strdup("-l");
    essai[1] = NULL;
    ft_create_path(g_da.cmd_one);
    
    printf("%s",g_da.cmd_one.path);

    execve(g_da.cmd_one.path,essai,env);
}