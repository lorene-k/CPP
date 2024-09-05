#include "minishell.h"

int ft_pwd(t_infos *infos, t_cmd *cmd)
{
    char buffer[1024];

    (void) cmd;
    (void) infos;

    if(!getcwd(buffer, 1024))
    {
        ft_putstr_fd("getcwd : failed to allocate buffer", 2);
        exit (1);
    }
    else
    {
        ft_putendl_fd(buffer,1);
        return (0);
    }
}