#include "minishell.h"

void free_and_show_error(t_infos **infos)
{
    ft_putendl_fd("Erreur", 2);
    free_infos(infos);
    // free(input);
    exit(1); // A voir si c'est pas 127
}
