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

void free_cmd_tokens(char    **cmd_array)
{
    int i = 0;
                int nb_words = 0;
            while(cmd_array[nb_words] != NULL)
            {
                nb_words++;
            }
    while(i < nb_words )
    {
        free(cmd_array[i]);
                i++;
    }
    free(cmd_array);

}


void free_create_commands(t_infos **infos)
{
    if (*infos != NULL)
    {

        if ((*infos)->cmd != NULL)
        {
            int i = 0;
            // while (i < (*infos)->cmd_nb)
            while ((*infos)->cmd[i] != NULL)
            {
                // Supprime les arguments de la commande
                free_split_new((*infos)->cmd[i]->args);


                // Supprime le path de la commande
                if ((*infos)->cmd[i]->path != NULL)
                    free((*infos)->cmd[i]->path);

                // Supprime le infile outfile
                if ((*infos)->cmd[i]->infile != NULL)
                    free((*infos)->cmd[i]->infile);
                if ((*infos)->cmd[i]->outfile != NULL)
                    free((*infos)->cmd[i]->outfile);

                // Supprime la chaine HEREDOC
                if ((*infos)->cmd[i]->heredoc != NULL)
                    free((*infos)->cmd[i]->heredoc);
                if ((*infos)->cmd[i]->heredoc_file_name != NULL)
                    free((*infos)->cmd[i]->heredoc_file_name);



                free((*infos)->cmd[i]);
                i++;

            }






            free((*infos)->cmd);

            // FAIRE APPEL A LA FUTURE FONCTION : free_all_cmds()
        }
    }
}
