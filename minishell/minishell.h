/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:22:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/13 12:35:17 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

/* ------------  LIBRARIES  ------------------------------------------------ */
# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/* ------------  MACROS  --------------------------------------------------- */

/* ------------  STRUCTS  -------------------------------------------------- */
typedef struct s_token
{
	char	*lexeme;
	t_token	*next;
	t_token	*prev;
}			t_token;

typedef struct s_error
{
	char	*msg;
	int		err_code;
	t_error	*next;
	t_error	*prev;
}			t_error;

typedef struct s_cmd
{
	int		n;
	char	**paths;
	char	**args;
	char	*c_path;
}			t_cmd;

typedef struct s_data
{
	int		in;
	int		out;
	int		**fd;
	int		status;
	int		pipes;
	char	*epath;
	pid_t	*pid;
	t_cmd	*cmd;
	t_error	*error;
}			t_data;

/* ------------  FUNCTIONS  ------------------------------------------------ */

#endif //MINISHELL_H
