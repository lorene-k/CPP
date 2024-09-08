#include "minishell.h"
///////////////////// NON TESTE POUR LE MOMENT
// A FAIRE :

// deplacer les blocs darguments dans le tableau
int resize_args_cmd(t_cmd *cmd, int new_args_indexes)
{

    int i;
    int z;
    char **new_args;
    int initial_args_indexes;
    
    initial_args_indexes = cmd->args_indexes;
    i = 0;
    z = 0;

    // On cree un nouveau tableau args
    new_args = ft_calloc(sizeof(char *), (new_args_indexes));

    while (i < initial_args_indexes)
    {
        if (cmd->args[i] != NULL)
        {
            new_args[z] = cmd->args[i];
            z++;
        }            
        i++;
    }
    new_args[new_args_indexes - 1] = NULL;

    // Boucle while jusqua que i < initial_args_indexes
        // Si le pointeur de cmd->args[i] != NULL
            // args[z] = cmd->args[i];
            // i++;
            // z++;
        // Sinon on ignore le bloc
            //i++;

    // args[new_args_indexes - 1] = NULL;

    // On free tous les anciens args dans un while
    // On free(cmd->args);

    cmd->args = new_args;
    cmd->args_indexes = new_args_indexes;
    return (0);
}


// Fait lexpansion des arguments dans la commande et supprime certains arguments dont le contenu de la variable $ABC est vide, enfin supprime les "" et ''
int modify_args_cmd(t_cmd *cmd, t_infos *infos)
{
    int i;
    int new_args_indexes;
    char *actual_arg;

    i = 0;
    new_args_indexes = cmd->args_indexes;

    while (i < cmd->args_indexes - 1)
    {
        actual_arg = replace_str_var_new(infos, cmd->args[i]);
        ft_putendl_fd("tooo : ",1);
        ft_putendl_fd(actual_arg,1);
        free(cmd->args[i]);
        cmd->args[i] = actual_arg;
        if (ft_strcmp(actual_arg, "") == 0)
        {
            free(cmd->args[i]);
            cmd->args[i] = NULL;
            new_args_indexes--;
        }
        else
        {
            actual_arg = remove_quotes(cmd->args[i]);
            free(cmd->args[i]);
            cmd->args[i] = actual_arg;
        }
        i++;
    }

    resize_args_cmd(cmd, new_args_indexes);

// Boucle while jusqua la fin des args
    // On fait lexpansion sur un arg
    // Si le nouveau argument != "" (nest pas vide) :
        // nouveau argument = remove_quotes(char *str)
        // on free lancien argument de la cmd et on lui associe le nouvel argument
    // Sinon :
        // On free l'ancien argument dans cmd
        // On met le pointeur dans le tableau de l'argument a NULL
        // new_args_indexes--;

// Apres le while
        // On fait appel a une fonction pour deplacer les blocs darguments dans le tableau : resize_args_cmd
        // cmd->args_indexes = new_args_indexes;

    return (0);
}