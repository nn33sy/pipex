#include "pipex.h"

void ft_create_path(t_cmd *cmd, char *pre_chain)
{
    cmd->path = ft_strjoin(pre_chain, cmd->chain[0]);
}

void ft_exec_part_one(char **env)
{
    int i;

    i = 0;
    if (ft_strncmp(g_da.cmd_one.chain[0], "./", 2) == 0)
        execve(g_da.cmd_one.chain[0], &g_da.cmd_one.chain[0],env);
    else
    {
    while (g_da.pre_chain[i] != 0)
    {
        ft_create_path(&g_da.cmd_one, g_da.pre_chain[i]);
        if (execve(g_da.cmd_one.path, &g_da.cmd_one.chain[0],env) != -1)
            break;
        i++;
        free(g_da.cmd_one.path);
    }
    }
}
void ft_exec_part_two(char **env)
{
    int i;

    i = 0;
    if (ft_strncmp(g_da.cmd_two.chain[0], "./", 2) == 0)
        execve(g_da.cmd_two.chain[0], &g_da.cmd_two.chain[0],env);
    else
    {
    while (g_da.pre_chain[i] != 0)
    {
        ft_create_path(&g_da.cmd_two, g_da.pre_chain[i]);
        if (execve(g_da.cmd_two.path, &g_da.cmd_two.chain[0],env) != -1)
            break;
        i++;
        free(g_da.cmd_two.path);
    }
    }
}