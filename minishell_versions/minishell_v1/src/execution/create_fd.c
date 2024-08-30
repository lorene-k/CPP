#include "minishell.h"



void create_pipes(t_infos **infos)
{
    int i;
    int z;
    
    i = 0;
    (*infos)->tube = malloc(sizeof(int) * (*infos)->pipes_nb * 2);
    if (!(*infos)->tube)
        protect_memory(*infos, 0, 0);
    while (i < (*infos)->pipes_nb * 2)
    {
        if (pipe((*infos)->tube + (i)) < 0)
        {
            print_cmd_error("pipe: failed creating pipe", *infos, 1);
            free_infos_error(*infos);
            exit (1);
        }
        i += 2;
    }


    i = 0;
    z = 0;
    while (i < (*infos)->cmd_nb)
    {
        if ((*infos)->cmd[i]->outtype == PIPE)
        {
            (*infos)->cmd[i]->fd_out = (*infos)->tube[(z * 2) + 1];
            (*infos)->cmd[i + 1]->fd_in = (*infos)->tube[z * 2];
            z++;
        }
        i++;
    }
}

void create_normal(t_infos *infos)
{
    int i;
    
    i = 0;
    while (i < infos->cmd_nb)
    {
        if (infos->cmd[i]->outtype == NORMAL)
        {
            infos->cmd[i]->fd_out = 1;
        }
        if (infos->cmd[i]->intype == NORMAL)
        {
            infos->cmd[i]->fd_in = 0;
        }
        i++;
    }

    
}

void create_file(t_infos **infos)
{
    int i;
    
    i = 0;
    while (i < (*infos)->cmd_nb)
    {
        if ((*infos)->cmd[i]->outtype == TRUNC)
        {
            (*infos)->cmd[i]->fd_out = open((*infos)->cmd[i]->outfile , O_CREAT | O_RDWR | O_TRUNC, 0644);
            if ((*infos)->cmd[i]->fd_out < 0)
            {
                perror("minishell: ");
                //handle exit code
            }
        }
        if ((*infos)->cmd[i]->intype == FILE_REAL)
        {
            
            (*infos)->cmd[i]->fd_in = open((*infos)->cmd[i]->infile, O_RDONLY);;
            if ((*infos)->cmd[i]->fd_in < 0)
            {
                 perror("minishell: ");
                //handle exit code
            }
        }
        i++;
    }
}

char *create_filename_heredoc(t_infos **infos, int id)
{
    char *id_str;
    char *file_name;
    int i;

    i = 0;
    id_str = ft_itoa(id);
    file_name = ft_calloc(ft_strlen(id_str) + 4 + 1, sizeof(char));
    if (!file_name)
        protect_memory(*infos, 0, 0);
    while(i < ft_strlen(id_str))
    {
        file_name[i] = id_str[i];
        i++;
    }
    file_name[i++] = '.';
    file_name[i++] = 't';
    file_name[i++] = 'm';
    file_name[i++] = 'p';
    file_name[i] = '\0';
    return (file_name);
}

// CECI est une solution temporaire
void create_heredoc(t_infos **infos)
{
    int i;
    int file;
    char *buf;
    char    *tmp;

    i = 0;
    tmp = NULL;

    signals_init_heredoc();
    
    // // A FAIRE 
        // modifie la structure pour stocker le signal actuel
        (*infos)->sig_id_heredoc = sig_id;
        // REmet a zero le signal la variable globale : sig_id = 0 (il faudra remettre comme avant le signal a la fin du heredoc) 
        sig_id = 0;
    while (i < (*infos)->cmd_nb)
    {
        if ((*infos)->cmd[i]->intype ==  HEREDOC)
        {

            // A FAIRE : creer fichier heredoc unique pour chaque heredoc
            //(*infos)->
            //(*infos)->cmd[i] = ft_calloc();
            (*infos)->cmd[i]->heredoc_file_name = create_filename_heredoc(infos, i);
            ft_putendl_fd("file name : ", 1);
            ft_putendl_fd((*infos)->cmd[i]->heredoc_file_name, 1);

            file = open((*infos)->cmd[i]->heredoc_file_name , O_TRUNC | O_CREAT | O_RDWR, 0000644);
            if (file < 0)
            {
                perror("minishell: heredoc: ");
                //handle exit code
            }
            while(1) // test en cours signal
            {

                // POUR TEST UNIQUEMENT, LE CTRL D NE MARCHE PAS ICI ET LE SIGINT NE MARCHE PAS
                // buf = ft_calloc(sizeof(char), 512);
                // read(0, buf, 511);
                // (*ft_strchr(buf, '\n')) = '\0';

                // POUR VRAI PUSH
                buf = readline("heredoc>"); // Enlever le commentaire pour leval


                if(!buf)
                {
                    //sig_id = (*infos)->sig_id_heredoc;
                    ft_putendl_fd("here-document delimited by end-of-file (wanted `EOF')", 2);
                    break;
                }
                if (sig_id == 128 + SIGINT)
                {
                    //ft_putendl_fd("CTRL C", 2);
                    free(buf);
                    break;
                }
                if (ft_strcmp(buf, (*infos)->cmd[i]->heredoc) == 0)
                {
                    
                    free(buf);
                    break;
                }


                tmp = replace_str_var_heredoc(*infos, buf);
                if (!tmp)
                {    
                    free(buf);
                    close(file);
                    protect_memory(*infos, tmp, 0); //check leaks
                }
                write(file, tmp, ft_strlen(tmp));
                write(file, "\n", 1);
                free(tmp);
                free(buf);

            }
            close(file);
            
            //if (sig_id == 1)
            //    return ;
            
            (*infos)->cmd[i]->fd_in = open((*infos)->cmd[i]->heredoc_file_name, O_RDONLY);
            if ((*infos)->cmd[i]->fd_in < 0)
            {
                perror("minishell: "); //CHECK
                free_infos_error(*infos);
                exit(1);
            }
        }
        i++;
    }
    signals_init();
}



// ERREUR NE MARCHE PAS A CORRIGER
void create_append(t_infos **infos)
{
    int i;
    
    i = 0;
    while (i < (*infos)->cmd_nb)
    {
        if ((*infos)->cmd[i]->outtype == APPEND)
        {

            (*infos)->cmd[i]->fd_out = open((*infos)->cmd[i]->outfile , O_CREAT | O_RDWR | O_APPEND, 0644);
            if ((*infos)->cmd[i]->fd_out < 0)
            {
                // close ((*infos)->cmd[i]->heredoc_file_name); //CHECK THIS
                perror("minishell: "); //CHECK
                free_infos_error(*infos);
                exit(1);

            }
        }
        i++;
    }
}



void create_all_fd(t_infos **infos)
{
    create_pipes(infos);
    create_normal(*infos);
    create_file(infos);
    create_heredoc(infos);
    create_append(infos);
    show_fd(*infos); // Tests uniquement, pour afficher
}
