#include "pipex.h"
void ft_error_parsing(void)
{
    printf("ERROR PARSING");
    exit(EXIT_FAILURE);
}

void ft_clean_cmd(char **argv)
{
    g_da.cmd_one.chain = ft_split_space(argv[2]);
    g_da.cmd_two.chain = ft_split_space(argv[3]);
}

void ft_handle_file(char **argv)
{
    g_da.fd_1 = open(argv[1],O_RDONLY);
    if (g_da.fd_1 == -1)
        ft_error_parsing();
    g_da.fd_2 = open(argv[4],O_RDONLY);
    if (g_da.fd_2 == -1)
        ft_error_parsing();
    g_da.file_one = ft_strdup(argv[1]);
    g_da.file_two = ft_strdup(argv[4]);
}

void ft_handle_nb_arg(int argc, char **argv)
{
    if (argc != 5)
        ft_error_parsing();
    ft_handle_file(argv);
    ft_clean_cmd(argv);
    printf("PARSING OK\n");
}