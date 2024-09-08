#include "minishell.h"



// Renvoi le nombre de commandes totales
int commands_nb(char    **cmd_array)
{
    int i = 0;
    int nb = 0;
            while (cmd_array[i] != NULL)
            {
                if (cmd_array[i + 1] == NULL)
                {
                    nb++;
                }
                else if (ft_strcmp(cmd_array[i], "|") == 0)
                {
                    nb++;
                }
                i++;
            }
    return (nb);
}


// malloc le cmd, puis y insère les arguments de la commande, retourne la commande cmd créée
t_cmd *alloc_cmd_and_put_args(int args_nb, char **cmd_array, int last_index, t_infos **infos)
{
    t_cmd *cmd;
    int i;
    int z;
    cmd = NULL;
    cmd = ft_calloc(sizeof(t_cmd), 1);
    if (!cmd)
        return (NULL);
    cmd->args = ft_calloc(sizeof(char *), (args_nb + 1));
    if (!cmd->args)
        return (free(cmd), NULL);
    cmd->args_indexes = (args_nb + 1);
    z = 0;
    while(z < (args_nb))
    {
        cmd->args[z] = ft_strdup(cmd_array[last_index + z]);
        if (!cmd->args[z])
        {   
            i = 0;
            while (i < z)
            {
                free(cmd->args[i]);
                i++;
            }
            return (free(cmd), NULL);
        }
        z++;
    }
    cmd->args[z] = NULL;

    return (cmd);
}

// déclare un tableau contenant les commandes ainsi que son nb de commandes a partir des tokens
int create_infos_array(t_infos **infos, char    **cmd_array)
{

    (*infos)->cmd_nb = commands_nb(cmd_array);
    t_cmd **tab = ft_calloc(commands_nb(cmd_array) + 1, (sizeof(t_cmd *)));
    if (!tab)
        return (-1);
    (*infos)->cmd = tab;
    return (0);
}


// Crée les commandes en parsant le tableau contenant tous les mots (tokens) dans un tableau
int create_commands(char    **cmd_array, t_infos **infos)
{
            int i = 0;
            int args_nb;
            int nb_words;

            args_nb = 0;
            i = 0;
            nb_words = 0;
            if (create_infos_array(infos, cmd_array) == -1)
            {
                return (-1);
            }
            while(cmd_array[nb_words] != NULL)
                nb_words++;
            int last_index = 0;
            int id_cmd = 0;
            while (i < nb_words)
            {
                if(ft_strcmp(cmd_array[i], "|") != 0)
                    args_nb++;
                if ( ft_strcmp(cmd_array[i], "|") == 0 || i + 1 == nb_words)
                {
                    (*infos)->cmd[id_cmd] = alloc_cmd_and_put_args(args_nb, cmd_array, last_index, infos);
                    if ( (*infos)->cmd[id_cmd] == NULL)
                        return (-1);
                    args_nb = 0;
                    last_index = i + 1;
                    id_cmd++;
                }
                      i++;
            }
    return (0);
}

// Initalise les valeurs de toutes les commandes par une valeur par defaut
void set_default_cmd_values(t_infos **infos)
{
    int i;

    i = 0;
    t_cmd   *actual_cmd;
    while (i < (*infos)->cmd_nb)
    {
        actual_cmd = (*infos)->cmd[i];
        actual_cmd->intype = NORMAL;
        actual_cmd->outtype = NORMAL;
        i++;
    }
}
