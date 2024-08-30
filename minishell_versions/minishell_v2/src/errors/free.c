#include "minishell.h"

// free tous les arguments de la commande et la commande
void    free_cmd_args(t_cmd *cmd)
{
    int id = 0;
                while (id < cmd->args_indexes)
                {       
                    if (cmd->args[id] != NULL)
                    {
                        free(cmd->args[id]);
                    }
                    id++;
                }
                free(cmd->args);
                cmd->args = NULL;
                cmd->args_indexes = 0;
}


void free_two_tokens(char *actual_token, char *next_token,t_cmd *actual_cmd, int arg_id)
{
                free(actual_token);
                free(next_token);
                actual_cmd->args[arg_id] = NULL;
                actual_cmd->args[arg_id + 1] = NULL;
}



// Appelé pour free tout ce qui a été créé pendant la phase de parsing
void free_parsing(t_infos **infos, char *input)
{
    int i = 0;
    int arg_id = 0;
    t_cmd *actual_cmd;

    if (*infos == NULL)
        return ;
        while (i < (*infos)->cmd_nb)
        {
            actual_cmd = (*infos)->cmd[i];
            free_cmd_args(actual_cmd);
            if (actual_cmd->intype != NORMAL && actual_cmd->intype != PIPE && actual_cmd->intype != HEREDOC)
                free(actual_cmd->infile);
            if (actual_cmd->outtype != NORMAL && actual_cmd->outtype != PIPE)
                free(actual_cmd->outfile);
            if (actual_cmd->heredoc != NULL)
                free(actual_cmd->heredoc);


            if (actual_cmd->path != NULL)
                free(actual_cmd->path);



            // A AJOUTER APRES : !!!!!!!!!!!!!!!!!!!!!!!!  A FAIRE : créer plusieurs fichiers si plusieurs heredoc
            // if (actual_cmd->intype == HEREDOC)
                // unlink(actual_cmd->infile);

            // if (actual_cmd->path != NULL)
            //     free(actual_cmd->path);     
            
            
            
            
            free(actual_cmd);
            i++;
        }

    free((*infos)->cmd);
}


void free_and_show_error_parsing(t_infos **infos, char *input)
{
    free_parsing(infos, input);
    free(*infos);
    free(input);
    ft_putstr_fd("Error malloc", 1);
}


static void free_split(char **split)
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




/// A AJOUTER A LA FIN DU PROJET : suppression des fichiers si intype == HEREDOC
// free tout a la fin du programme
void free_all(t_infos **infos, char *input)
{

    // On free d'abotd le contenu dans toutes les commandes
    free_parsing(infos, input);
    free_split((*infos)->paths);

    // Puis on free tout ce qu'il ya dans infos

    /// ATTENTION! !!!! ERREUR DANS CES LIGNES
    if ((*infos)->tube != NULL)
       free((*infos)->tube);
    if ((*infos)->pid != NULL)
       free((*infos)->pid);

    free(*infos);
    // free(input);
}


void free_new(t_infos **infos, char *input)
{
    free(input);

}


// A FAIRE
// void free_after_execution(t_infos *infos)
// {

// }