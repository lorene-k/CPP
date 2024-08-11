/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:44:58 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/11 17:44:24 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char *prompt_str(char *user, char *cwd)
{
    size_t	user_cwd_len;
    char	*user_cwd;

	// printf("user : %s\ncwd : %s\n", user, cwd);
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

static char	*display_prompt(void) //CHECK_ERR
{
    char    *user_cwd;
	char	*short_cwd;
	char	*user;
	char	cwd[1024];

	user = getenv("USER");
	if (!user)
		exit(UNKNOWN_ERR);
	if (!getcwd(cwd, sizeof(cwd)))
	{
		if (errno == ERANGE)
		{
			perror("getcwd");
			exit(1); // DON'T EXIT PROG >> use return
		}
		exit(2);
	}
    short_cwd = ft_strnstr(cwd, user, ft_strlen(cwd));
	user_cwd = prompt_str(user, short_cwd);
    return (user_cwd);
}

//LEAKS IN READLINE
static void	get_input(char **line)
{
	char	*user_cwd;

	user_cwd = display_prompt();
	*line = readline(user_cwd); // MALLOC (free in parse)
	if (!*line)
	{
		if (EOF) //CHECK_SIGNAL (CTRL + D)
            exit(0);
        exit(1);
	}
	add_history(*line); //MALLOC - OK
	free(user_cwd);
}

void	run_loop()
{
	char	*line;
	t_data	data;
	
	line = NULL;
	while (1)
	{
		get_input(&line);
		parse_input(&data, line);
		// exec(data);
		// sig_handler(data);
		clear_nodes((void *)&(data.cmd), sizeof(t_cmd));
	}
	clear_history(); //change to rl_clear_history
}
