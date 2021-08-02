#include "pipex.h"


int main(int argc, char *argv[], char *env[])
{
    (void)env;
    ft_handle_nb_arg(argc, argv);
    ft_exec_part_one(env);
}