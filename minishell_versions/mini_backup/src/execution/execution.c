#include "minishell.h"




// Execute un builtin et assigne la valeur de retour dans la variable return_code de infos
int execute_one_builtin(t_infos *infos, int id)
{
    int fds[2];

        fds[0] = dup(0);
        fds[1] = dup(1);
        dup2(infos->cmd[id]->fd_out, 1);
        dup2(infos->cmd[id]->fd_in, 0);
        if(!ft_strcmp(infos->cmd[id]->args[0], "echo"))
             (infos->return_code = ft_echo(infos, infos->cmd[id]));
        if(!ft_strcmp(infos->cmd[id]->args[0], "pwd"))
             (infos->return_code = ft_pwd(infos, infos->cmd[id]));
        if(!ft_strcmp(infos->cmd[id]->args[0], "env"))
             (infos->return_code = ft_env(infos, infos->cmd[id]));
        if(!ft_strcmp(infos->cmd[id]->args[0], "export"))
             (infos->return_code = ft_export(infos, infos->cmd[id]));
        if(!ft_strcmp(infos->cmd[id]->args[0], "unset"))
             (infos->return_code = ft_unset(infos, infos->cmd[id]));
        if(!ft_strcmp(infos->cmd[id]->args[0], "cd"))
             (infos->return_code = ft_cd(infos, infos->cmd[id]));
        if(!ft_strcmp(infos->cmd[id]->args[0], "exit"))
             (infos->return_code = ft_exit(infos, infos->cmd[id]));
        dup2(fds[1], 1);
        dup2(fds[0], 0);
        sig_id = infos->return_code;
        return (infos->return_code);
}


// Ferme tous les descripteurs de fichiers associés a un pipe
void close_all_pipe(t_infos *infos)
{
    int i;
    i = 0;
    while (i < infos->pipes_nb)
    {
        close(infos->tube[i * 2]);
        close(infos->tube[(i * 2 + 1)]);
        i++;
    }

}

// Execute la commande si elle est builtin
void    exec_child_builtin()
{
    // exit(nom_de_la_fonction());
}


// Crée le processus puis execute la commande
void child(t_infos **infos, t_cmd *cmd, int id, int actual_pipe_id)
{

    char    *cmd_path;
    int return_code;

    (*infos)->pid[id] = fork();
    if((*infos)->pid[id] == 0)
    {

        if (!cmd->can_access_file)
            ft_putendl_fd("Error : No such file or directory (fork)", 2);
        if (cmd->cmd_not_found == 1)
        {
            ft_putstr_fd(cmd->args[0], 2);
            ft_putendl_fd(" : Command not found", 2);
            close_all_pipe(*infos);
            free_infos_child(infos);
            exit(127);
        }

        dup2(cmd->fd_out, 1);
        dup2(cmd->fd_in, 0);
        close_all_pipe(*infos);

        if(is_builtin(cmd->args[0]))
        {
            return_code = execute_one_builtin(*infos, id);
            // free_infos(infos);
            free_infos_child(infos);
            // ft_putendl_fd("TEEEEEEST BUILTIN", 1);
            exit(return_code);
        }
        else
        {
            if (cmd->can_access_file && cmd->cmd_not_found != 1)
                execve(cmd->path, cmd->args, (*infos)->new_envp);
            else
                exit(1);
        }
    }
    else if ((*infos)->pid[id] < 0)
    {
        free_infos_error(*infos);;
        perror("erreur lors de la creation du processus fils");
    }

}

// Attend la fin de tous les processus fils
void wait_all_cmds(t_infos *infos)
{
    int i;
    int status;

    i = 0;
    status = -1;
    while (i < infos->cmd_nb)
    {
        waitpid(infos->pid[i], &status, 0);
        i++;
        //ft_putendl_fd("DANS LA BOUCLE", 1);
    }

    if (sig_id == 128 + SIGINT)
    {
        printf("\nERREUR : Le code de retour de la derniere commande est : %d\n", 128 + SIGINT);
        infos->return_code = 128 + SIGINT;
        sig_id = 128 + SIGINT;
    }
    else
    {
        printf("\nLe code de retour de la derniere commande est : %d\n", WEXITSTATUS(status));
        infos->return_code = WEXITSTATUS(status);
        sig_id = WEXITSTATUS(status);

    }
}

// Ferme les descripteurs de fichier APPEND TRUNC ET HEREDOC
void close_other_fd(t_infos *infos)
{
    int i;
    i = 0;
    while (i < infos->cmd_nb)
    {
        if (infos->cmd[i]->intype == FILE_REAL || infos->cmd[i]->intype == HEREDOC)
            close(infos->cmd[i]->fd_in);
        if (infos->cmd[i]->outtype == APPEND || infos->cmd[i]->outtype == HEREDOC)
            close(infos->cmd[i]->fd_out);
        i++;
    }
}

// Execute toutes les commandes (avec pipes ou non)
void execute_all_cmds(t_infos **infos)
{
    int i;
    int actual_pipe_id;

    i = 0;
    actual_pipe_id = 0;
    (*infos)->pid = malloc(sizeof(int) * (*infos)->cmd_nb);
    if (!(*infos)->pid)
        free_infos_error(*infos);
    while (i < (*infos)->cmd_nb)
    {
        if ((*infos)->cmd[i]->outtype == PIPE)
            child(infos, (*infos)->cmd[i], i, actual_pipe_id);
        else if ((*infos)->cmd[i]->intype == PIPE)
        {
            child(infos, (*infos)->cmd[i], i, actual_pipe_id);
            actual_pipe_id++;
        }
        else 
            child(infos, (*infos)->cmd[i], i, actual_pipe_id);
        i++;
    }
}

// Lance l'execution d'une ou plusieurs commanes (builtin ou non)
void execute(t_infos **infos)
{
    // Si ctrl + C alors nexecute pas la commande
    if (sig_id == 128 + SIGINT)
        return ;

    signals_init_execution();

    if ((*infos)->cmd_nb == 1 && is_builtin((*infos)->cmd[0]->args[0]))
    {
        execute_one_builtin(*infos, 0);
        return ;
    }
    else
    {
        execute_all_cmds(infos);
        close_all_pipe(*infos);
        wait_all_cmds(*infos);
        close_other_fd(*infos);
    }

    signals_init();

    //write(1, "V", 1);
    // sig_id = 999;
}