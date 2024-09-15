/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_create_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:54:59 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/12 16:01:00 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd_tokens(char **cmd_array)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (cmd_array[nb_words] != NULL)
	{
		nb_words++;
	}
	while (i < nb_words)
	{
		free(cmd_array[i]);
		i++;
	}
	free(cmd_array);
}

static void	clear_files(t_infos ***infos, int i)
{
	if ((**infos)->cmd[i]->infile != NULL)
		free((**infos)->cmd[i]->infile);
	if ((**infos)->cmd[i]->outfile != NULL)
		free((**infos)->cmd[i]->outfile);
	if ((**infos)->cmd[i]->heredoc != NULL)
	{
		free((**infos)->cmd[i]->heredoc);
		(**infos)->cmd[i]->heredoc = NULL;
	}
	if ((**infos)->cmd[i]->heredoc_file_name != NULL)
	{
		unlink((**infos)->cmd[i]->heredoc_file_name);
		free((**infos)->cmd[i]->heredoc_file_name);
		(**infos)->cmd[i]->heredoc_file_name = NULL;
	}
}

void	free_create_commands(t_infos **infos)
{
	int	i;

	if (*infos != NULL)
	{
		if ((*infos)->cmd != NULL)
		{
			i = 0;
			while ((*infos)->cmd[i] != NULL)
			{
				clear_tab((*infos)->cmd[i]->args);
				if ((*infos)->cmd[i]->path != NULL)
					free((*infos)->cmd[i]->path);
				clear_files(&infos, i);
				free((*infos)->cmd[i]);
				i++;
			}
			free((*infos)->cmd);
		}
	}
}

// void free_create_commands(t_infos **infos)
// {
//     if (*infos != NULL)
//     {

//         if ((*infos)->cmd != NULL)
//         {
//             int i = 0;
//             while ((*infos)->cmd[i] != NULL)
//             {
//                 clear_tab((*infos)->cmd[i]->args);
//                 if ((*infos)->cmd[i]->path != NULL)
//                     free((*infos)->cmd[i]->path);
//                 if ((*infos)->cmd[i]->infile != NULL)
//                     free((*infos)->cmd[i]->infile);
//                 if ((*infos)->cmd[i]->outfile != NULL)
//                     free((*infos)->cmd[i]->outfile);
//                 if ((*infos)->cmd[i]->heredoc != NULL)
//                 {
//                     free((*infos)->cmd[i]->heredoc);
//                     (*infos)->cmd[i]->heredoc = NULL;
//                 }
//                 if ((*infos)->cmd[i]->heredoc_file_name != NULL)
//                 {
//                     unlink((*infos)->cmd[i]->heredoc_file_name);
//                     free((*infos)->cmd[i]->heredoc_file_name);
//                     (*infos)->cmd[i]->heredoc_file_name = NULL;
//                 }
//                 free((*infos)->cmd[i]);
//                 i++;
//             }
//             free((*infos)->cmd);
//         }
//     }
// }
