#include "minishell.h"



// Retourne 1 si la chaine de caractère contient au moins une variable d'environnement non traitée ($var)
int contains_env_var(char  *str)
{
    int i;
    int len;
    char *var_key;
    int z;
    int len_var_key;

    z = 0;
    i = 0;
    len = ft_strlen(str);
    len_var_key = 0;
    while (i < len)
    {
        if (str[i] == '$' && i + 1 < len && (ft_isalpha(str[i + 1])))
            return (1);
        i++;
    }  
    return (0);
}

// Retourne 1 si la chaine de caractère contient au moins un $? non traitée ($var)
int contains_return_code_var(char  *str)
{
    int i;
    int len;
    char *var_key;
    int z;
    int len_var_key;

    z = 0;
    i = 0;
    len = ft_strlen(str);
    len_var_key = 0;
    while (i < len)
    {
        if (str[i] == '$' && i + 1 < len && (str[i + 1] == '?'))
            return (1);
        i++;
    }  
    return (0);
}
