#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}


// Prend le nom de la commande en parametre et retourne 1 si c'est une commande builtin
int is_builtin(char *str)
{
    if(!ft_strcmp(str, "echo"))
        return (1);
    if(!ft_strcmp(str, "cd"))
        return (1);
    if(!ft_strcmp(str, "pwd"))
        return (1);
    if(!ft_strcmp(str, "export"))
        return (1);
    if(!ft_strcmp(str, "unset"))
        return (1);
    if(!ft_strcmp(str, "env"))
        return (1);
    if(!ft_strcmp(str, "exit"))
        return (1);
    return (0);
}