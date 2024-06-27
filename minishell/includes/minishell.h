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
typedef struct s_file
{
	char			*name;
	int				in;
	int				out;
	int				append;
	int 			heredoc; // not necessary
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
	int				status; //exit status
	int				pipes;
	char			*line;
	char			*epath;
	int				quit;
	t_cmd			*cmd;
}					t_data;

/* ------------  FUNCTIONS  ------------------------------------------------ */
/* UTILS */
void				clear_nodes(void **start, size_t n_size);
void				clear_parser(t_data *data, char *line, t_token *token);
void				*get_first_node(t_token *token, t_cmd *cmd, t_file *file);
void				add_node(t_token **token, t_cmd **cmd, t_file **file);
int					protect_memory(char **array);
int					print_error(char *msg, char *str, int code);

/* EXEC */
void	exec(t_data *data);

/* LOOP */
void				run_loop(void);


#endif //MINISHELL_H
