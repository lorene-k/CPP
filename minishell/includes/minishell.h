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
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>

# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft_src/libft.h"

/* ------------  STRUCTS  -------------------------------------------------- */
typedef struct s_token
{
	char	*str;
    int		type;
	struct t_token	*next;
	struct t_token	*prev;
}			t_token;

typedef struct s_error
{
	char	*msg;
	int		err_code;
	struct t_error	*next;
	struct t_error	*prev;
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
	char	*epath; //linked list for path?
	pid_t	*pid;
    t_token	*token;
	t_cmd	*cmd;
	t_error	*error;
}			t_data;

/* ------------  FUNCTIONS  ------------------------------------------------ */
void run_loop(t_data *data);
void    clear_line(t_data *data);

#endif //MINISHELL_H
