#include "minishell.h"

// Renvoi les nouveaux arguments apres suppression de deux tokens dans tableau
char	**create_new_args(t_infos **infos, int old_nb_indexes,
		t_cmd *actual_cmd)
{
	char	**new_args;
	int		j;
	int		i;

	new_args = malloc(sizeof(char *) * (old_nb_indexes - 2));
	if (!new_args) // ajjoute
		protect_memory(*infos, NULL, NULL);
	i = 0;
	j = 0;
	while (i < old_nb_indexes - 1)
	{
		if (actual_cmd->args[i] != NULL)
			new_args[j++] = strdup(actual_cmd->args[i]);
		i++;
	}
	new_args[j] = NULL;
	return (new_args);
}

// Renvoi 1 si le token est < << > ou >>
int	is_valid_token(char *actual_token)
{
	if (ft_strcmp(actual_token, "<") == 0 || ft_strcmp(actual_token, "<<") == 0
		|| ft_strcmp(actual_token, ">") == 0 || ft_strcmp(actual_token,
			">>") == 0)
		return (1);
	else
		return (0);
}

// Supprime les arguments < file, << EOF, > file et >> file
void	delete_first_in_out_in_args(t_infos **infos, t_cmd *actual_cmd)
{
	char	*actual_token;
	int		arg_id;
	int		i;
	char	**new_args;

	arg_id = 0;
	while (actual_cmd->args[arg_id] != NULL)
	{
		actual_token = actual_cmd->args[arg_id];
		if (is_valid_token(actual_token) == 1)
		{
			free_two_tokens(actual_token, actual_cmd->args[arg_id + 1],
					actual_cmd, arg_id);
			new_args = create_new_args(infos, actual_cmd->args_indexes,
					actual_cmd);
			free_cmd_args(actual_cmd);
			actual_cmd->args = new_args;
			i = 0;
			while (actual_cmd->args[i] != NULL)
				i++;
			actual_cmd->args_indexes = i + 1;
			return ;
		}
		arg_id++;
	}
}

// Associe le infile et intype en fonction du token
int	assign_infile_intype(t_infos **infos, char *actual_token, char *next_token,
		t_cmd *cmd)
{
	if (ft_strcmp(actual_token, "<") == 0)
	{
		cmd->infile = ft_strdup(next_token);
		if (!cmd->infile)
			protect_memory(*infos, NULL, NULL);
		cmd->intype = FILE_REAL;
		return (1);
	}
	if (ft_strcmp(actual_token, "<<") == 0)
	{
		if (cmd->heredoc != NULL)
			free(cmd->heredoc);
		cmd->heredoc = ft_strdup(next_token);
		if (!cmd->heredoc)
			protect_memory(*infos, NULL, NULL);
		cmd->intype = HEREDOC;
		return (1);
	}
	return (0);
}

// Associe le infile et intype en fonction du token
int	assign_outfile_outtype(t_infos **infos, char *actual_token,
		char *next_token, t_cmd *cmd)
{
	if (ft_strcmp(actual_token, ">") == 0)
	{
		cmd->outfile = ft_strdup(next_token);
		if (!cmd->outfile)
			protect_memory(*infos, NULL, NULL);
		cmd->outtype = TRUNC;
		return (1);
	}
	if (ft_strcmp(actual_token, ">>") == 0)
	{
		cmd->outfile = ft_strdup(next_token);
		if (!cmd->outfile)
			protect_memory(*infos, NULL, NULL);
		cmd->outtype = APPEND;
		return (1);
	}
	return (0);
}

// Vérifie si le token est un < << > ou >> et met a jour la commande
int	check_token_and_assign(t_infos **infos, char *actual_token,
		char *next_token, t_cmd *cmd)
{
	if (assign_infile_intype(infos, actual_token, next_token, cmd) == 1)
		return (1);
	if (assign_outfile_outtype(infos, actual_token, next_token, cmd) == 1)
		return (1);
	return (0);
}

// Retourne 1 si la commande a pour token au moins un < << > ou >>
int	contains_in_out(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i] != NULL)
	{
		if (ft_strcmp(cmd->args[i], "<") == 0 || ft_strcmp(cmd->args[i],
				"<<") == 0 || ft_strcmp(cmd->args[i], ">") == 0
			|| ft_strcmp(cmd->args[i], ">>") == 0)
			return (1);
		i++;
	}
	return (0);
}

// Associe les intype outtype, infile et outfile dans les commandes
int	set_infile_outfile(t_infos **infos)
{
	int		i;
	t_cmd	*actual_cmd;

	i = 0;
	while (i < (*infos)->cmd_nb)
	{
		actual_cmd = (*infos)->cmd[i];
		actual_cmd->can_access_file = 1;
		while (contains_in_out(actual_cmd))
		{
			remove_one_inout_and_set_inout(infos, actual_cmd);
			if ((*infos)->sigint_heredoc == 1)
				return (-1);
			if (!actual_cmd->can_access_file)
				break ;
		}
		i++;
	}
	return (0);
}
