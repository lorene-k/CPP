/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:44:58 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/20 17:54:19 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parse.h"

static char *prompt_str(char *user, char *cwd)
{
    size_t     user_cwd_len;
    char    *user_cwd;

    user_cwd_len = ft_strlen(user) + ft_strlen(cwd) + 4;
    user_cwd = malloc(sizeof(char) * user_cwd_len);
    if (!user_cwd)
        return (NULL);
    ft_strlcpy(user_cwd, user, ft_strlen(user) + 1);
    ft_strlcat(user_cwd, ":~", ft_strlen(user) + 3);
    ft_strlcat(user_cwd, cwd, ft_strlen(cwd) + 1);
    ft_strlcat(user_cwd, "$ ", ft_strlen(cwd) + 3);
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
		exit(UKNOWN_ERR);
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

static void	scan(char *line)
{
	char	*user_cwd;

	user_cwd = display_prompt(); // MALLOC - OK
	line = readline(user_cwd); // MALLOC (free in parse)
	if (!line)
	{
		// if (EOF) //CHECK_SIGNAL (CTRL + D)
        //     exit(0);
        // exit(1);
	}
	add_history(line); //MALLOC - OK
	free(user_cwd);
	// free(line);
}

void	run_loop(t_data *data)
{
	char *line;
	
	line = NULL;
	while (1)
	{
		scan(line);
		parse(data, line);
		// exec(data);
		// clear_stuff();
		// sig_handler(data);
	}
}

/*
DISPLAY 
user:path$

LEAKS IN READLINE 
*/