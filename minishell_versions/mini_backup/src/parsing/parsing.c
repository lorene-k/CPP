/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:09:02 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/15 16:22:10 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Modifie la structure infos deja initialisee
static void	update_infos(t_infos **infos, char *str, char **envp)
{
	char	*path;

	if (*infos != NULL)
	{
		(*infos)->pipes_nb = count_pipes_new(str);
		(*infos)->input = str;
	}
}

// Modifie tous les arguments de toutes les commandes
static void	modify_all_cmd_args(t_infos **infos)
{
	int		i;
	t_cmd	*actual_cmd;

	i = 0;
	while (i < (*infos)->cmd_nb)
	{
		actual_cmd = (*infos)->cmd[i];
		if (modify_args_cmd(actual_cmd, *infos) == -1)
			protect_memory(*infos, NULL, NULL);
		i++;
	}
}

// Crée les tokens a partir de l'input puis crée les structures cmd
static void	create_cmds(char *str, t_infos **infos)
{
	char	**cmd_tokens;

	cmd_tokens = generate_tokens_array(str, *infos);
	if (!cmd_tokens)
		free_infos_error(*infos);
	if (create_commands(cmd_tokens, infos) == -1)
	{
		free_cmd_tokens(cmd_tokens);
		free_infos_error(*infos);
	}
	else
		free_cmd_tokens(cmd_tokens);
	modify_all_cmd_args(infos);
}

// Renvoie 1 si toutes les commandes sont empty
int all_cmds_empty(t_infos *infos)
{
	int i;
	int empty;

	i = 0;
	empty = 0;
	while (i < infos->cmd_nb)
	{
		if (infos->cmd[i]->args[0] == NULL)
		{
			// commande a detruire
			empty++;
		}
		i++;
	}
	if(empty == infos->cmd_nb)
	{
		g_sig_id = 0;
		return (1);
	}
	else
		return (0);
}

// Assigne un flag is_empty = 1 aux commandes vides
int set_empty_cmds(t_infos *infos)
{
	int i;

	i = 0;
	while (i < infos->cmd_nb)
	{
		if (infos->cmd[i]->args[0] == NULL)
		{
			infos->cmd[i]->is_empty = 1;
		}
		else
		{
			infos->cmd[i]->is_empty = 0;
		}
		i++;
	}
	return (0);
}


// Modifie les commandes
static int	modify_cmds(t_infos **infos, char **envp)
{
	set_default_cmd_values(infos);
	set_infile_outfile(infos);
	if ((*infos)->sigint_heredoc == 1)
		return (-1);
	set_in_out_pipes_and_normal(infos);
	if (all_cmds_empty(*infos))
		return (-1);
	set_empty_cmds(*infos);
	set_all_cmd_path(infos, envp);
	return (0);
}

// Initialise la structure infos
int	parse(char *str, t_infos **infos, char **envp)
{
	if (ft_strlen(str) == 0)
	{
		free(str);
		return (0);
	}
	if (!(*infos))
		create_infos(infos, str, envp);
	else
		update_infos(infos, str, envp);
	(*infos)->sigint_heredoc = 0;
	create_cmds(str, infos);
	if (modify_cmds(infos, envp) == -1)
	{
		free_infos_while(infos);
		return (0);
	}
	return (1);
}
