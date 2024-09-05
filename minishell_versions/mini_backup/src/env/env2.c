#include "minishell.h"

// Renvoi 1 si la variable d'environnement existe dans la table sinon renvoi 0
int env_var_exists(t_infos *infos, char *key)
{
    char    *temp_key;
    int len;
    int i;

    temp_key = ft_strjoin(key, "=");
    if(!temp_key)
        return (-1);
    len = ft_strlen(temp_key);
    i = 0;
    while (infos->new_envp[i]!=NULL)
    {
        if (ft_strncmp(infos->new_envp[i], temp_key, len) == 0)
        {
            // free(new_str);
            free(temp_key);
            return (1);
        }
        i++;
    }
    free(temp_key);
    return (0);
}


int add_env_var(t_infos *infos, char *key, char *value)
{
    int i;
    char *temp_key;
    int len;
    char    *temp_str;

    i = 0;
    char    *new_str;


    temp_str = ft_strjoin(key, "=");
    if (!temp_str)
        return (-1);
    new_str = ft_strjoin(temp_str, value); // Leak a revoir !!!!!!!!!!!!!!
    free(temp_str);
    if(!new_str)
        return (-1);

    temp_key = ft_strjoin(key, "=");
    if (!temp_key)
        return (free(new_str), -1);
    len = ft_strlen(temp_key);
    while (infos->new_envp[i]!=NULL)
    {
        if (ft_strncmp(infos->new_envp[i], temp_key, len) == 0)
        {
            free(infos->new_envp[i]);
            infos->new_envp[i] = strdup(new_str); // A VOIR
            if(!infos->new_envp[i])
                return (free(new_str), free(temp_key), -1);
            free(temp_key);
            free(new_str);
            return (0);
        }
        i++;
    }
    // Si la valeur n'existe pas :/ A FINIR !!!!!
    int z = 0;
    char **new_envp = malloc(sizeof(char *) * (i + 2));
    if (!new_envp)
        return (free(temp_key), free(new_str), -1);
    while (z < i)
    {
        new_envp[z] = infos->new_envp[z];
        z++;
    }
    new_envp[z] = strdup(new_str);
    if (!new_envp[z])
        return (free(new_str), free(temp_key), -1);
            free(new_str);
            free(temp_key);
    z++;
    new_envp[z] = NULL;    
    free(infos->new_envp); // test
    infos->new_envp = new_envp;     
    return (0);
}


// A FINIR POUR FUNCHECK
// Supprime une variable d'environnement
int remove_env_var(t_infos *infos, char *key)
{
    int i;
    char *temp_key;
    int len;
    char    **new_envp;
    int z;
    int exist;


    len = 0;
    exist = env_var_exists(infos, key);
    if (exist == 0)
        return (0);
    else if (exist == -1)
        return (-1);
    while (infos->new_envp[len]!=NULL)
        len++;
    new_envp = malloc(sizeof(char *) * (len));
    if (!new_envp)
        return (-1);
    temp_key = ft_strjoin(key, "=");
    if (!temp_key)
        return (free(new_envp), -1);
    i = 0;
    z = 0;
    while (infos->new_envp[i]!=NULL)
    {
        if (ft_strncmp(infos->new_envp[i], temp_key, ft_strlen(temp_key)) == 0)
            free(infos->new_envp[i]);
        else
            new_envp[z++] = infos->new_envp[i];
        i++;
    }
    new_envp[z] = NULL;
    free(infos->new_envp);   // A FAIRE : free tout le contenu de chaque strng
    free(temp_key);
    infos->new_envp = new_envp;
    return (0);
}


// Retourne la valeur d'une variable d'environnement
char *get_env_var(t_infos *infos, char *key)
{
    int i;
    char *temp_key;
    int len;
    
    i = 0;

    // if(!env_var_exists(infos, key))
    //     return (NULL);

    temp_key = ft_strjoin(key, "=");
    if (!temp_key)
        return (NULL);
    len = ft_strlen(temp_key);
    while (infos->new_envp[i]!=NULL)
    {
        // printf("%s \n", infos->new_envp[i]);
        if (ft_strncmp(infos->new_envp[i], temp_key, len) == 0)
        {
            // write(1, "M", 1);
            // ft_substr(infos->new_envp[i], len, ft_strlen(infos->new_envp[i]));
            free(temp_key);
            return (ft_substr(infos->new_envp[i], len, ft_strlen(infos->new_envp[i])));
        }
        i++;
    }

    free(temp_key);
    return (NULL);
}