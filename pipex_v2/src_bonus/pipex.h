/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:22:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/12 13:28:07 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# define CMD_FAILURE 127

# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/libft_src/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	int		n;
	char **paths; //malloc here - OK
	char **args;  //malloc here
	char	*c_path;
}			t_cmd;

typedef struct s_data
{
	int		i;
	int		in;
	int		out;
	int **fd; //malloc here
	pid_t	pid;
	int		pipes;
	char *epath; //malloc here
	t_cmd	cmd;
	int		here_doc;
	char	*limiter;
}			t_data;

/* CLEAR */
void		close_pipes(t_data *data);
void		close_files(t_data *data);
void		clear_all(t_data *data);

/* ERROR */
void		put_child_error(char *msg, t_data *data, int exit_code);
void		print_error(char *msg, int exit_code, t_data *data);
void		check_error(t_data *data, char *file);

/* GET CMDS */
int			check_access(char *cmd_path, t_data *data);
char		*get_c_path(char **paths, char *cmd, t_data *data);
char		*ft_getenv(char **envp);
void		get_cmds(int ac, t_data *data, char **envp);

/* GET FILES */
void		get_out(char *out, t_data *data);
void		get_in(char *in, t_data *data);
void		check_heredoc(int ac, char **av, t_data *data);
void		get_files(int ac, char **av, t_data *data);

/* HEREDOC BONUS */
void		end_heredoc(int fd, char *line, t_data *data);
void		get_line(int fd, char *line);
void		get_heredoc(t_data *data);

/* INIT DATA */
void		get_pipes(t_data *data);
void		get_fd(t_data *data);
void		init_all(t_data *data);
t_data		init_data(int ac, char **av, char **envp);

/* PROCESS */
void		parent(t_data *data, char **av, char **envp);
void		ft_exec(t_data *data, char **envp, char *cmd);
void		redirect(int input, int ouput);
void		child(t_data *data, char **av, char **envp);

#endif // PIPEX_H