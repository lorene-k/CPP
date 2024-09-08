#include "minishell.h"


static void free_split_new(char **split)
{
    int i;
    i = 0;
    while(split[i] != NULL)
    {
        free(split[i]);
        i++;
    }
    free(split);
}


char **dup_env(t_infos *infos)
{
    int i;
    char **new;

    i = 0;
    while (infos->new_envp[i]!=NULL)
        i++;
    new = calloc(sizeof(char *), (i + 1));
    i = 0;
    while (infos->new_envp[i]!=NULL)
    {
        new[i] = infos->new_envp[i];
        i++;
    }
    return (new);
}

// Affiche une ligne de la table des variables d'environnement en ajoutant des ""
void show_one_line_export(char *str)
{
    char *right;
    int len;
    int i;

    i = 0;
    len = ft_strlen(str);
    if(ft_strchr(str, '=') == NULL)
    {
        ft_putendl_fd(str, 1);
        return ;
    }

    while(i < len)
    {
        write(1, &str[i], 1);
        if(str[i] == '=')
            break;
        i++;
    }
    write(1, "\"" ,1);
    if(i < len)
        ft_putstr_fd(ft_strchr(str, '=') + 1, 1);
    write(1, "\"\n" ,2);


}

// Affiche la liste des variables d'environnement dans l'ordre croissant
void print_sorted_export_env(t_infos *infos)
{
    int i;
    char **env;
    int sorted;
    char *tmp;

    env = dup_env(infos);
    i = 0;
    sorted = 0;
    while (env[i]!=NULL && sorted == 0)
    {
        i = 0;
        sorted = 1;
        while (env[i + 1] != NULL)
        {
            if (env[i + 1] != NULL && ft_strcmp(env[i], env[i + 1]) > 0)
            {
                tmp = env[i];
                env[i] = env[i + 1];
                env[i + 1] = tmp;
                sorted = 0;
            }
            i++;
        }
    }
    i = 0;
    while (env[i]!=NULL)
    {
        ft_putstr_fd("declare -x ", 1);


        // MISE EN PLACE DES GUILLEMETS ("") TEST EN COURS : A FAIRE

        show_one_line_export(env[i++]);
        // ft_putendl_fd(env[i++], 1);

        //ft_putendl_fd(env[i++], 1);
    }
    free(env);
}

// Parse la commande puis ajoute la variable d'environnement a info
// void add_var(t_infos *infos, t_cmd *cmd)
// {
//     char *var_content;
//     char *var_key;
//     int i;

//     i = 0;

//     //var_content = ft_strchr(cmd->args[1], '=') + 1;
//     //var_content = replace_str_var(infos, var_content);
    
//     var_content = replace_str_var(infos, cmd->args[4]); // EN COURS
    
//     while (cmd->args[1][i] != '=')
//         i++;
//     var_key = malloc(sizeof(char) * (i + 1));
//     i = 0;
//     while (cmd->args[1][i] != '=')
//     {
//         var_key[i] = cmd->args[1][i];
//         i++;
//     }
//     var_key[i] = '\0';
//     if (!ft_isalpha(var_key[0]) && !(var_key[0] == '_'))
//         return (ft_putstr_fd("Non valid variable name\n", 2), free(var_key));
//     add_env_var(infos, var_key, var_content);
//     free(var_key);

//     free(var_content);
// }


void add_var_new(t_infos *infos, char *str)
{
    char *var_content;
    char *var_key;
    int i;

    // Dans ce cas, la variable a ajouter na pas de valeur
    if(ft_strchr(str, '=') == NULL)
        add_env_var(infos, str, NULL);
    else
    {
        i = 0;
        var_content = ft_strchr(str, '=') + 1;
        var_content = replace_str_var(infos, var_content); // A MODIFIE
        while (str[i] != '=')
            i++;
        var_key = malloc(sizeof(char) * (i + 1));
        i = 0;
        while (str[i] != '=')
        {
            var_key[i] = str[i];
            i++;
        }
        var_key[i] = '\0';
        if (!ft_isalpha(var_key[0]) && !(var_key[0] == '_'))
            return (ft_putstr_fd("Non valid variable name\n", 2), free(var_key));
        add_env_var(infos, var_key, var_content);
        free(var_key);
        free(var_content);
    }
}

// L'ancienne fonction 
void add_var(t_infos *infos, t_cmd *cmd)
{
    char *var_content;
    char *var_key;
    int i;

    i = 0;



    var_content = ft_strchr(cmd->args[1], '=') + 1;
    var_content = replace_str_var(infos, var_content); // A MODIFIE
    
    
    while (cmd->args[1][i] != '=')
        i++;
    var_key = malloc(sizeof(char) * (i + 1));
    i = 0;
    while (cmd->args[1][i] != '=')
    {
        var_key[i] = cmd->args[1][i];
        i++;
    }
    var_key[i] = '\0';
    if (!ft_isalpha(var_key[0]) && !(var_key[0] == '_'))
        return (ft_putstr_fd("Non valid variable name\n", 2), free(var_key));
    add_env_var(infos, var_key, var_content);
    free(var_key);

    free(var_content);
}

// A FAIRE : mettre guillemets "" pour le contenu d'une variable d'env lorsque export sans arguments !!!!
// A FAIRE : faire en sorte que export AAA="Le contenu" fonctionne bien avec les guillemets
// int ft_export(t_infos *infos, t_cmd *cmd)
// {

//     char *path;


//         ft_putendl_fd("AVANT EXPORT", 1);

//     if (cmd->args[1] == NULL)
//     {
//         print_sorted_export_env(infos);
//         return (0);
//     }
//     else if (cmd->args_indexes == 4)
//     {

//         ft_putendl_fd("AVANT ADDVAR", 1);
//         add_var(infos, cmd);
//         ft_putendl_fd("APRES ADDVAR", 1);

//     if ((infos)->paths != NULL)
//             free_split_new((infos)->paths);
//     path = get_env_var((infos), "PATH");
//     if (!path)
//         free_and_show_error(&infos);
// 	(infos)->paths = ft_split(path, ':');
//     free(path);

//         print_sorted_export_env(infos); // Pour tests
//     }



//     return (0);
// }

int update_path(t_infos *infos)
{

        char *path;

        if (env_var_exists(infos, "PATH") == 1)
        {
            if ((infos)->paths != NULL)
                free_split_new((infos)->paths);

            path = get_env_var((infos), "PATH");
            if (!path)
                free_infos_error(infos);
            (infos)->paths = ft_split(path, ':');
            free(path);
        }
        else
        {
            if ((infos)->paths != NULL)
                free_split_new((infos)->paths);
            infos->paths = NULL;
        }
    return (0);
}




// L'ancienne fonction
int ft_export(t_infos *infos, t_cmd *cmd)
{
        char *path;


    if (cmd->args[1] == NULL)
    {
        print_sorted_export_env(infos);
        return (0);
    }
    else if (cmd->args_indexes >= 3)
    {

        // ft_putendl_fd("AVANT ADDVAR", 1);
        // add_var(infos, cmd);
        // add_var_new(infos, cmd->args[1]);
        // ft_putendl_fd("APRES ADDVAR", 1);

        int i = 1;
        while (i < cmd->args_indexes - 1)
        {
            add_var_new(infos, cmd->args[i]);
            i++;
        }


        update_path(infos);

        // if ((infos)->paths != NULL)
        //         free_split_new((infos)->paths);

        // if (env_var_exists(infos, "PATH") == 1)
        // {
            
        // }


        // path = get_env_var((infos), "PATH");
        // if (!path)
        //     free_and_show_error(&infos);
        // (infos)->paths = ft_split(path, ':');
        // free(path);

        print_sorted_export_env(infos); // Pour tests
    }



    return (0);
}