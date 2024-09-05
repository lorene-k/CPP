#include "minishell.h"

// Derniere etape du parsing : on indique si la commande utilise entrée et sortie standard ou pipes
void set_in_out_pipes_and_normal(t_infos **infos)
{
    int i = 0;
    int arg_id = 0;
    t_cmd *actual_cmd;

    if((*infos)->pipes_nb >= 1)
    {

        while (i < (*infos)->cmd_nb)
        {
            actual_cmd = (*infos)->cmd[i];
            if (actual_cmd->outtype == NORMAL && i + 1 < (*infos)->cmd_nb )
            {
                if ((*infos)->cmd[i + 1]->intype == NORMAL)
                {
                    actual_cmd->outtype = PIPE;
                    (*infos)->cmd[i + 1]->intype = PIPE;
                }
                else if (((*infos)->cmd[i + 1]->intype == HEREDOC) || ((*infos)->cmd[i + 1]->intype == FILE_REAL)) // AJOUTE PAR MOI A LA FIN AU MAROC
                {
                    actual_cmd->outtype = PIPE;
                }
            }
            i++;
        }
    }
}

/////// A FAIRE FREE
// Retourne le chemin d'une commande a partir de son nom (ex: echo retourne /bin/echo), ./programme retounre ./programme
static char	*command_path_parsing(t_infos **infos, char *cmd)
{
	char	*temp;
	char	*actual_command;
	char    **all_paths;
    
    all_paths = (*infos)->paths;


    if (all_paths) // ajoute
        write(1, "TOO", 3); // ajoute


    if (env_var_exists(*infos, "PATH") == 0) // A FINIR POUR FUNCHECK
        return (NULL);

    if(!all_paths) // ajoute
        return (NULL); // ajoute


    if ((ft_strlen(cmd) > 2 && cmd[0] == '.' && cmd[1] == '/')
        ||  (ft_strlen(cmd) > 1 && cmd[0] == '/' )
        ||  (ft_strlen(cmd) > 2 && ft_strchr(cmd, '/') != NULL ))
    {
        if (access(cmd, F_OK) == 0)
            return (cmd);
    }
	while (*all_paths)
	{
		temp = ft_strjoin(*all_paths, "/");
        if (!temp)
            return(free_infos_error(*infos), NULL);
		actual_command = ft_strjoin(temp, cmd);
        free(temp);
        if (!actual_command)
            return(free_infos_error(*infos), NULL);
		if (access(actual_command, F_OK) == 0)
			return (actual_command);
		free(actual_command);
		all_paths++;
	}
	return (NULL);
}

static void rename_one_cmd(t_cmd *cmd, t_infos **infos)
{
    char *temp;

    if (ft_strchr(cmd->args[0], '/'))
    {
        temp = ft_strdup(ft_strrchr(cmd->args[0], '/') + 1);
        if (!temp)
            protect_memory(*infos, 0, 0);
        cmd->args[0] = temp;
    }
}

int set_all_cmd_path(t_infos **infos, char **envp)
{
    t_cmd *actual_cmd;
    int i;

    i = 0;
        while (i < (*infos)->cmd_nb)
        {
            actual_cmd = (*infos)->cmd[i];
            if (!is_builtin(actual_cmd->args[0]))
            {
                actual_cmd->path = command_path_parsing(infos, actual_cmd->args[0]);
                if (!(actual_cmd->path))
                {
                    // ft_putstr_fd(actual_cmd->args[0], 2);
                    //ft_putendl_fd("COMMAND NOT FOUND IN MODIFY_COMMANDS2", 2);
                    //(*infos)->return_code = 127;


                    actual_cmd->cmd_not_found = 1;
                   //sig_id = 127;


                    // pour test
                    // A FAIRE : ajouter une variable dans la structure commande indiquer que la commande n'a pas ete executee,
                    // lors de lexecution on check cette var et on affiche un msg derreur
                    //free_and_show_error(infos);

                    //return (1);
                }
                rename_one_cmd(actual_cmd, infos);
            }
            i++;
        }
        return ((*infos)->return_code);
}
