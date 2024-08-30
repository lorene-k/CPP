/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:44:58 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/30 20:16:51 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*prompt_str(char *user, char *cwd)
{
	size_t	user_cwd_len;
	char	*user_cwd;

	// printf("user : %s\ncwd : %s\n", user, cwd); //TEST
	user_cwd_len = ft_strlen(user) + ft_strlen(cwd) + 5;
	user_cwd = malloc(sizeof(char) * user_cwd_len);
	if (!user_cwd)
		return (NULL);
	ft_strlcpy(user_cwd, user, ft_strlen(user) + 1);
	ft_strlcat(user_cwd, ":~", ft_strlen(user) + 3);
	ft_strlcat(user_cwd, cwd, ft_strlen(user) + ft_strlen(cwd) + 3);
	ft_strlcat(user_cwd, "$ ", ft_strlen(user) + ft_strlen(cwd) + 5);
	return (user_cwd);
}

static char	*display_prompt(void)
{
	char	*user_cwd;
	char	*short_cwd;
	char	*user;
	char	cwd[1024];

	user = getenv("USER");
	if (!user)
		return (perror("getenv"), NULL);
	if (!getcwd(cwd, sizeof(cwd)))
	{
		if (errno == ERANGE)
			return (perror("getenv"), NULL); // check error management here
		return (NULL);
	}
	short_cwd = ft_strnstr(cwd, user, ft_strlen(cwd));
	user_cwd = prompt_str(user, short_cwd);
	return (user_cwd);
}

//LEAKS IN READLINE
static int	get_input(char **line, t_data *data)
{
	char	*user_cwd;

	user_cwd = display_prompt();
	if (!user_cwd)
		user_cwd = ft_strdup("minishell$ ");
	*line = readline(user_cwd);
	if (!(*line) || !(**line))
	{
		free(user_cwd);
		if (EOF) //CHECK_SIGNAL (CTRL + D)
		{	
			data->quit = 1;
			return (0);
		}
		return (1);
	}
	if (*line && **line)
		add_history(*line);
	free(user_cwd);
	return (0);
}

void	run_loop(void)
{
	char	*line;
	t_data	data;

	line = NULL;
	data.status = 0;
	// init_sa(sa); // added for signals
	while (1)
	{
		if (get_input(&line, &data))
			break ;
		parse_input(&data, line);
		// if (!data.status)
		// exec(&data);
		if (data.cmd)
			clear_nodes((void *)&(data.cmd), sizeof(t_cmd));
		if (data.quit)
			break ;
		pause();
	}
}
