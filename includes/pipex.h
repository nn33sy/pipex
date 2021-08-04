#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern FILE *stderr;
extern FILE *stdin;
extern FILE *stdout;

typedef struct s_cmd
{
    char **chain;
    char *path;
    char **arg;

}t_cmd;

typedef struct s_data{
    t_cmd cmd_one;
    t_cmd cmd_two;
    char *file_one;
    char *file_two;
    int fd_1;
    int fd_2;
    char **pre_chain;
    char **env;
}t_data;

t_data g_da;
void ft_error_parsing(void);
void ft_clean_cmd(char **argv);
void ft_handle_nb_arg(int argc, char **argv);
void ft_exec_part_one(char **env);
char *ft_search_path(char *var);
void ft_exec_part_two(char **env);
#endif