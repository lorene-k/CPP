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
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft_src/libft.h"
# include "parse.h"
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/* ------------  STRUCTS  -------------------------------------------------- */
// typedef struct s_env
// {
// 	char			*name;
// 	char			*value;
// 	struct t_env	*next;
// }					t_env; // ??

typedef struct s_cmd
{
	char	**paths;
	char	**args;
	char	*c_path;
}			t_cmd;

typedef struct s_data
{
	int		in;
	int		out;
	int		cmd_n;
	int		**fd;
	int		status;
	int		pipes;
	int		here_doc;
	char	**envp;
	char	*limiter;
	int		in_err;
	int		out_err;
	pid_t	*pid;
	t_cmd	*cmd;
	// t_env			*env;
}			t_data;

/* ------------  FUNCTIONS  ------------------------------------------------ */
void		run_loop(t_data *data);
void		clear_all(void);

#endif //MINISHELL_H
