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
    if (!new)
        protect_memory(infos, 0, 0);
    i = 0;
    while (infos->new_envp[i]!=NULL)
    {
        new[i] = infos->new_envp[i];
        i++;
    }
    return (new);
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

        ft_putendl_fd(env[i++], 1);
    }
    free(env);
}

// Parse la commande puis ajoute la variable d'environnement a info
void add_var(t_infos *infos, t_cmd *cmd)
{
    char *var_content;
    char *var_key;
    int i;

    i = 0;
    var_content = ft_strchr(cmd->args[1], '=') + 1;

    var_content = replace_str_var(infos, var_content);
    
    while (cmd->args[1][i] != '=')
        i++;
    var_key = malloc(sizeof(char) * (i + 1));
    if (!var_key)
        protect_memory(infos, var_content, 0);
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
int ft_export(t_infos *infos, t_cmd *cmd)
{

    char *path;

    if (cmd->args[1] == NULL)
    {
        print_sorted_export_env(infos);
        return (0);
    }
    else if (cmd->args_indexes == 3)
    {
        add_var(infos, cmd);

    if ((infos)->paths != NULL)
            free_split_new((infos)->paths);
    path = get_env_var((infos), "PATH");
    if (!path)
        return(0);
	(infos)->paths = ft_split(path, ':');
    free(path);

        print_sorted_export_env(infos); // Pour tests
    }


    // int i;
    // int contains_n;
    // (void) infos;

    // i = 1;
    // contains_n = 0;
    // if (cmd->args_indexes > 2 && ft_strcmp(cmd->args[1], "-n") == 0)
    //     contains_n = 1;
    // i += contains_n;
    // while (i < cmd->args_indexes - 1)
    // {
    //         ft_putstr_fd(cmd->args[i], 1);
    //         if (i + 1 < cmd->args_indexes - 1)
    //             ft_putstr_fd(" ", 1);
    //     i++;
    // }
    // if (contains_n == 0)
    //     ft_putstr_fd("\n", 1);


    return (0);
}