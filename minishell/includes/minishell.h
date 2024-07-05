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
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../libft/libft_src/libft.h"
# include "parse.h"

/* ------------  STRUCTS  -------------------------------------------------- */
typedef struct s_env
{
	char			*name;
	char			*value;
	struct t_env	*next;
}					t_env;

typedef struct s_cmd
{
	int				n;
	char			**paths;
	char			**args;
	char			*c_path;
}					t_cmd;

typedef struct s_data
{
	int				cmd_n;
	int				in;
	int				out;
	int				**fd;
	int				status;
	int				pipes;
	char			*epath;
	pid_t			*pid;
	t_cmd			*cmd;
	t_env			*env;
}					t_data;

/* ------------  FUNCTIONS  ------------------------------------------------ */
void				run_loop(t_data *data);
void				clear_all(void);

#endif //MINISHELL_H
