/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:49:41 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/12 17:42:07 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_infos_exit(t_infos *infos)
{
	if (infos != NULL)
	{
		free_create_commands(&infos);
		if ((infos)->new_envp != NULL)
			clear_tab((infos)->new_envp);
		if ((infos)->paths != NULL)
			clear_tab((infos)->paths);
		if ((infos)->pid != NULL)
			free((infos)->pid);
		if ((infos)->input != NULL)
			free((infos)->input);
		if ((infos)->tube != NULL)
			free((infos)->tube);
		free(infos);
	}
}

// APPELE LORS D'ERREUR MALLOC
void	free_infos_error(t_infos *infos)
{
	if (infos != NULL)
	{
		if ((infos)->new_envp != NULL)
			clear_tab((infos)->new_envp);
		if ((infos)->paths != NULL)
			clear_tab((infos)->paths);
		if ((infos)->pid != NULL)
			free((infos)->pid);
		if ((infos)->input != NULL)
			free((infos)->input);
		if ((infos)->tube != NULL)
			free((infos)->tube);
		free(infos);
	}
	exit(123);
}

// APPELE LORSQU'ON QUITTE MINISHELL (ctrl D)
void	free_infos(t_infos **infos)
{
	if (*infos != NULL)
	{
		if ((*infos)->new_envp != NULL)
			clear_tab((*infos)->new_envp);
		if ((*infos)->paths != NULL)
			clear_tab((*infos)->paths);
		if ((*infos)->pid != NULL)
			free((*infos)->pid);
		if ((*infos)->input != NULL)
			free((*infos)->input);
		if ((*infos)->tube != NULL)
			free((*infos)->tube);
		free(*infos);
		*infos = NULL;
	}
}

// APPELE LORSQU'UNE COMMANDE NA PAS ETE TROUVEE (s'execute dans le child)
void	free_infos_child(t_infos **infos)
{
	if (*infos != NULL)
	{
		if ((*infos)->new_envp != NULL)
			clear_tab((*infos)->new_envp);
		if ((*infos)->paths != NULL)
			clear_tab((*infos)->paths);
		if ((*infos)->pid != NULL)
			free((*infos)->pid);
		if ((*infos)->input != NULL)
			free((*infos)->input);
		if ((*infos)->tube != NULL)
			free((*infos)->tube);
		free_create_commands(infos);
		free(*infos);
		*infos = NULL;
	}
}

// APPELE LORSQU'ON ARRIVE A LA FIN DU WHILE DANS LE MAIN
void	free_infos_while(t_infos **infos)
{
	if (*infos != NULL)
	{
		if ((*infos)->pid != NULL)
		{
			free((*infos)->pid);
			(*infos)->pid = NULL;
		}
		if ((*infos)->input != NULL)
		{
			free((*infos)->input);
			(*infos)->input = NULL;
		}
		if ((*infos)->tube != NULL)
		{
			free((*infos)->tube);
			(*infos)->tube = NULL;
		}
		free_create_commands(infos);
	}
}
