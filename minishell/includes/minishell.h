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

typedef struct s_file
{
	char			*name;
	int				in;
	int				out;
	int				append;
	int 			heredoc;
	char			*limiter;
	int				fd_in;
	int				fd_out;
	struct s_file	*next;
	struct s_file	*prev;
}					t_file;

typedef struct s_cmd
{
	char			*name;
	char			**args;
	char			**paths;
	char			*c_path;
	int				builtin;
	t_file			*file;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct s_data
{
	int				cmd_n;
	int				**fd;
	int status; //exit status
	int				pipes;
	char			*epath;
	pid_t			*pid;
	t_cmd			*cmd;
	// t_env			*env;
}					t_data;

/* ------------  FUNCTIONS  ------------------------------------------------ */
/* ERRORS */
int					protect_memory(char **array);
int					print_error(char *msg, char *str, int code);
void				print_file_error(char *file, char *str, int file_err);
void				check_error(char *file, int n, t_data *data);

void				clear_files(t_file **start);
void				clear_cmds(t_cmd **start);
void				clear_all(t_data *data);

void				run_loop(void);

#endif //MINISHELL_H
