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

    // AJOUTE RECEMMENT
    i = 0;
    while (infos->new_envp[i]!=NULL)
    {
        if (ft_strcmp(infos->new_envp[i], key) == 0)
        {
            return (1);
        }
        i++;
    }

    return (0);
}


// Retourne 1 si dans la table KEY=qulequecose OU KEY= ou KEY="", sinon renvoi 0
int env_contains_value_on_table(t_infos *infos, char *key)
{
    char *temp_key;
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


// Ajoute ou remplace une variable d'environnement, si value == NULL alors variable sans contenu
int add_env_var(t_infos *infos, char *key, char *value)
{
    int i;
    char *temp_key;
    int len;
    char    *temp_str;

    i = 0;
    char    *new_str;


    // pour test
    // value = NULL;


    // On crée la ligne a ajouter a la table si value != NULL
    // Dans ce cas : new_str = KEY=QUELQUECHOSE
    if (value != NULL || (value == NULL && env_var_exists(infos, key) == 1 && env_contains_value_on_table(infos, key) == 1))
    {
        temp_str = ft_strjoin(key, "=");
        if (!temp_str)
            return (-1);
        new_str = ft_strjoin(temp_str, value); // Leak a revoir !!!!!!!!!!!!!!
        free(temp_str);
        if(!new_str)
            return (-1);

    }
    // 

    // On crée la ligne a ajouter a la table si (value == NULL ET si la key n'existe pas deja dans la table) OU (value == NULL ET si elle existe dans la table mais n'a pas de valeur)
    // (elle contient seulement la KEY, par ex : PATH)
    // on l'appelle new_str aussi
    // Dans ce cas : new_str = KEY
    if (env_var_exists(infos, key) == 1 && (value == NULL && env_contains_value_on_table(infos, key) == 0)
        || (value == NULL && env_var_exists(infos, key) == 0))
    {
        // printf("value vide");
        new_str = ft_strdup(key);

    }


    // FAIT PLUS HAUT !!
    // On crée la ligne a ajouter a la table si (value == NULL ET si la key existe deja dans la table est a une valeur)
    // Dans ce cas : new_str = KEY=""
    // if (value == NULL && env_var_exists(infos, key) == 1 && env_contains_value_on_table(infos, key) == 1)



    // On regarde ensuite avec une itération si la variable est présente dans la table
        // Si oui : alors on remplace le contenu de la ligne par la nouvelle string : new_str
        // Si non : voir en bas



    // Si env var exist :
        // Si elle a une valeur associée (KEY= ou KEY="quelquechose" ou KEY="")
            // alors on remplace la ligne avec la nouvelle (new_str)


    if (env_var_exists(infos, key) == 1)
    {
        if (env_contains_value_on_table(infos, key) == 1)
        {
            // On supprime lancienne ligne (si KEY=VALUE) et on la remplace
            temp_key = ft_strjoin(key, "=");
            if (!temp_key)
                return (free(new_str), -1);
            len = ft_strlen(key);
        }
        else
        {
            temp_key = ft_strdup(key);
            len = ft_strlen(temp_key);
        }

        // On supprime lancienne ligne (si KEY=VALUE) et on la remplace
        temp_key = ft_strjoin(key, "=");
        if (!temp_key)
            return (free(new_str), -1);
        len = ft_strlen(key);
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

    }


                temp_key = ft_strdup(key);
            if (!temp_key)
                return (free(new_str), -1);
            len = ft_strlen(key);


    // On supprime lancienne ligne (si KEY=VALUE) et on la remplace
    // temp_key = ft_strjoin(key, "=");
    // if (!temp_key)
    //     return (free(new_str), -1);
    // len = ft_strlen(key);
    while (infos->new_envp[i]!=NULL)
    {
        // if (ft_strncmp(infos->new_envp[i], temp_key, len) == 0)
        // {
        //     free(infos->new_envp[i]);
        //     infos->new_envp[i] = strdup(new_str); // A VOIR
        //     if(!infos->new_envp[i])
        //         return (free(new_str), free(temp_key), -1);
        //     free(temp_key);
        //     free(new_str);
        //     return (0);
        // }
        i++;
    }


    // // On supprime lancienne ligne (si KEY (sans value)) et on la remplace
    // while (infos->new_envp[i]!=NULL)
    // {
    //     if (ft_strcmp(infos->new_envp[i], key) == 0)
    //     {
    //         free(infos->new_envp[i]);
    //         infos->new_envp[i] = strdup(new_str); // A VOIR
    //         if(!infos->new_envp[i])
    //             return (free(new_str), free(temp_key), -1);
    //         free(temp_key);
    //         free(new_str);
    //         return (0);
    //     }
    //     i++;
    // }

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


    if(env_contains_value_on_table(infos, key) == 1)
    {
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
    }
    else
    {
        temp_key = ft_strdup(key);
        if (!temp_key)
            return (free(new_envp), -1);
        i = 0;
        z = 0;
        while (infos->new_envp[i]!=NULL)
        {
            if (ft_strcmp(infos->new_envp[i], temp_key) == 0)
                free(infos->new_envp[i]);
            else
                new_envp[z++] = infos->new_envp[i];
            i++;
        }
        new_envp[z] = NULL;
        free(infos->new_envp);   // A FAIRE : free tout le contenu de chaque strng
        free(temp_key);
    }


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


    // AJOUTE RECEMMENT
    i = 0;
    while (infos->new_envp[i]!=NULL)
    {
        if (ft_strncmp(infos->new_envp[i], key, ft_strlen(key)) == 0)
        {
            return (ft_strdup(""));
        }
        i++;
    }




    return (NULL);
}