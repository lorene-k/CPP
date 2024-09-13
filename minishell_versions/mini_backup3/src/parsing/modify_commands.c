#include "minishell.h"


// Renvoi les nouveaux arguments restants suite a la suppression de deux tokens dans un tableau
char    **create_new_args(t_infos **infos, int old_nb_indexes, t_cmd *actual_cmd)
{
                char **new_args;
                int j;
                int i;
                new_args = malloc(sizeof(char *) * (old_nb_indexes - 2));
                if (!new_args)// ajjoute
                    free_and_show_error(infos); // ajoute
                i = 0;
                j = 0;
                while(i < old_nb_indexes - 1)
                {
                    if (actual_cmd->args[i] !=  NULL)
                        new_args[j++] = strdup(actual_cmd->args[i]);
                    i++;
                }
                new_args[j] = NULL;
    return (new_args);
}



// Supprime les arguments < file, << EOF, > file et >> file dans la liste des args de la commande (ATTENTION :  supprime une paire < infile a la fois)
// par ex : cat < infile > outfile se transforme en : cat > outfile
void delete_first_in_out_in_args(t_infos **infos, t_cmd *actual_cmd)
{
    char *actual_token;
    int     arg_id;
    int i;
    char **new_args;

    arg_id = 0;
         while(actual_cmd->args[arg_id] != NULL)
         {
            actual_token = actual_cmd->args[arg_id];
            if(ft_strcmp(actual_token, "<") == 0 || ft_strcmp(actual_token, "<<") == 0 || ft_strcmp(actual_token, ">") == 0 || ft_strcmp(actual_token, ">>") == 0)
            {
                free_two_tokens(actual_token, actual_cmd->args[arg_id + 1], actual_cmd, arg_id);
                new_args = create_new_args(infos, actual_cmd->args_indexes, actual_cmd);
                free_cmd_args(actual_cmd); 
                actual_cmd->args = new_args;
                i = 0;
                while(actual_cmd->args[i] != NULL)
                    i++;
                actual_cmd->args_indexes = i + 1;
                return ;
            }
            arg_id++;
         }
}

// Vérifie si le token est un < << > ou >> et met a jour la commande, renvoi 1 si contient 0 sinon
int check_token_and_assign(t_infos **infos, char   *actual_token, char *next_token, t_cmd *cmd)
{
            if(ft_strcmp(actual_token, "<") == 0)
            {
                cmd->infile = strdup(next_token);
                if (!cmd->infile)
                    free_and_show_error(infos);
                cmd->intype = FILE_REAL;
                return (1);
            }
            if(ft_strcmp(actual_token, "<<") == 0)
            {
                if (cmd->heredoc != NULL)
                    free(cmd->heredoc);
                cmd->heredoc = strdup(next_token);
                if (!cmd->heredoc)
                    free_and_show_error(infos);
                cmd->intype = HEREDOC;
                return (1);
            }
            if(ft_strcmp(actual_token, ">") == 0)
            {
                cmd->outfile = strdup(next_token);
                if (!cmd->outfile)
                    free_and_show_error(infos);
                cmd->outtype = TRUNC;
                return (1);

            }
            if(ft_strcmp(actual_token, ">>") == 0)
            {
                cmd->outfile = strdup(next_token);
                if (!cmd->outfile)
                    free_and_show_error(infos);
                cmd->outtype = APPEND;
                return (1);
            }
    return (0);
}

// Supprime les < > << >> et le nom qui suit en boucle, puis l'associe a la commande (grace a une fonction) // < infile
// void remove_one_inout_and_set_inout(t_infos **infos, t_cmd *cmd)
// {
//     int arg_id;
//     char *actual_token;
//     char *next_token;

//     arg_id = 0;
//     cmd->can_access_file = 1;
//          while(arg_id < cmd->args_indexes - 2)
//         {
//             actual_token = cmd->args[arg_id]; // < << > >>
//             next_token = cmd->args[arg_id + 1]; // file.txt 
//             if (check_token_and_assign(infos, actual_token, next_token, cmd) == 1)
//             {
//                 if (cmd->can_access_file == 1 && ft_strcmp(actual_token, "<") == 0 && access(next_token, F_OK | R_OK) == 0) // A FAIRE : chosiir le bon flag en fonction de < ou > par ex
//                 {
//                     ft_putendl_fd("\nACCESS OK", 1);
//                     cmd->can_access_file = 1;
//                 }
//                 else if (ft_strcmp(actual_token, "<") == 0 && access(next_token, F_OK | R_OK) != 0)
//                 {
//                     ft_putendl_fd("\nACCESS NOT OK !!!", 1);
//                     cmd->can_access_file = 0;
//                 }
//                 delete_first_in_out_in_args(infos, cmd);
//                 break;
//             }
//             arg_id++;
//         }
//     return ;
// }

// Retourne 1 si la commande a pour token au moins un < << > ou >>
int contains_in_out(t_cmd *cmd)
{
    int i;

    i = 0;
    while (cmd->args[i] != NULL)
    {
        if(ft_strcmp(cmd->args[i], "<") == 0 || ft_strcmp(cmd->args[i], "<<") == 0 || ft_strcmp(cmd->args[i], ">") == 0 || ft_strcmp(cmd->args[i], ">>") == 0)
            return (1);
        i++;
    }
    return (0);
}

// Associe les intype outtype, infile et outfile dans les commandes en se servant des arguments de la commande
int set_infile_outfile(t_infos **infos)
{
    int i = 0;
    t_cmd *actual_cmd;
    while (i < (*infos)->cmd_nb)
    {
        actual_cmd = (*infos)->cmd[i];
        actual_cmd->can_access_file = 1;

        while(contains_in_out(actual_cmd))
        {
            remove_one_inout_and_set_inout(infos, actual_cmd); // << EOF > toto < toto, // < < > < < < > <> >> >> > > >ad [> >>] lkdhla
            if ((*infos)->sigint_heredoc == 1)// AJOUTE PAR MOI
                return (-1);
            if (!actual_cmd->can_access_file)
                break;
        }
        i++;
    }
    return (0);
}

