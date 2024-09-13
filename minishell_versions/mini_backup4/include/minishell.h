/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:40:31 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/13 17:41:15 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ------------  LIBRARIES  ------------------------------------------------ */
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#include "libft.h"
#include "tokens.h"

/* ------------  STRUCTS  -------------------------------------------------- */
extern int g_sig_id;

typedef enum        e_in_out_type
{
    PIPE = 0,
    FILE_REAL = 1,
    NORMAL = 2,
    HEREDOC = 3,
    APPEND = 4,
    TRUNC = 5
}                   t_in_out_type;

typedef struct      s_cmd
{
    char            **args;
    char            *infile;
    char            *outfile;
    int             fd_out;
    int             fd_in;
    int             args_indexes;
    char            *heredoc;
    t_in_out_type   intype;
    t_in_out_type   outtype;
    char            *path;
    int             builtin;
    int             can_access_file;
    int             cmd_not_found;
    char            *heredoc_file_name;
    struct s_cmd    *next;
    struct s_cmd    *previous;
}                   t_cmd;

typedef struct      s_infos
{
    int             pipes_nb;
    int             *tube;
    char            **paths;
    t_cmd           **cmd;
    int             cmd_nb;
    int             *pid;
    int             return_code;
    int             g_sig_id_heredoc; // test
    char            **new_envp;
    char            *input;
    int				printed_error;
    int             sigint_heredoc; // 1 si Ctrl + C dans heredoc, 0 sinon
}                   t_infos;

/* ------------  FUNCTIONS  ------------------------------------------------ */
/* FREE */
void    free_infos_exit(t_infos *infos);
void    free_infos(t_infos **infos);
void    free_create_commands(t_infos **infos);
void    free_infos_while(t_infos **infos);
void    free_infos_error(t_infos *infos);
void    free_infos_child(t_infos **infos);

/* ENV */
int     env_contains_value_on_table(t_infos *infos, char *key);
void    init_env_var(t_infos *infos, char **envp);
void    set_infos_path(t_infos *infos);
char    *replace_str_var(t_infos *infos, char *str);
int     env_var_exists(t_infos *infos, char *key);
char    *replace_str_var_heredoc(t_infos *infos, char *str);

/* ERRORS */
void	print_file_error(t_cmd *cmd, char *file);
void    free_cmd_args(t_cmd *cmd);
void    free_all(t_infos **infos, char *input);
void    free_cmd_tokens(char    **cmd_array);
void    free_two_tokens(char *actual_token, char *next_token,t_cmd *actual_cmd, int arg_id);
void    free_new(t_infos **infos, char *input);

/* PARSING */
void    delete_first_in_out_in_args(t_infos **infos, t_cmd *actual_cmd);
int     check_token_and_assign(t_infos **infos, char   *actual_token, char *next_token, t_cmd *cmd);
void    remove_one_inout_and_set_inout(t_infos **infos, t_cmd *cmd);
int     get_cmd_id(t_infos *infos, t_cmd *cmd);
void	handle_heredoc(t_cmd *cmd, int i, t_infos *infos, int cmd_id);
int     count_pipes_new(char *s);
void    create_infos(t_infos **infos, char *str, char **envp);
int     parse(char  *str, t_infos **infos, char **envp);
int     exec_command(char **tmp, t_infos *infos);

// TESTS
void    show_cmd(t_infos **infos);
void    show_cmd_in_out(t_infos **infos);
void    show_cmd_args(t_cmd *cmd);
void    show_fd(t_infos *infos);

// CREATE CMDS
t_cmd	*get_cmd(int args_n, char **cmd_array, int last_index, t_infos **infos);
int     create_commands(char    **cmd_array, t_infos **infos);
void    set_default_cmd_values(t_infos **infos);

// MODIFY CMDS
int     set_infile_outfile(t_infos **infos);

// MODIFY CMDS 2
void    set_in_out_pipes_and_normal(t_infos **infos);
int     set_all_cmd_path(t_infos **infos, char **envp);

/* SIGNALS */
void    signals_init();
void    signals_init_heredoc();
void    signals_init_execution();

/* EXECUTION */
int     select_builtin(t_infos **infos, int id);
int     execute_one_builtin(t_infos *infos, int id);
void    close_all_pipe(t_infos *infos);
void	child(t_infos **infos, t_cmd *cmd, int id, int actual_pipe_id);
void    create_pipes(t_infos **infos);
void    create_all_fd(t_infos **infos);
void    execute(t_infos **infos);

/* BUILTINS */
int     update_path(t_infos *infos);
int     check_builtin_error(t_cmd *cmd, char *cmd_name);
int     is_builtin(char *str);
int     ft_pwd(t_infos *infos, t_cmd *cmd);
int     ft_strcmp(char *s1, char *s2);
int     ft_echo(t_infos *infos, t_cmd *cmd);
int     ft_env(t_infos *infos, t_cmd *cmd);
int     ft_export(t_infos *infos, t_cmd *cmd);
int     ft_unset(t_infos *infos, t_cmd *cmd);
int     ft_cd(t_infos *infos, t_cmd *cmd);
int     ft_exit(t_infos *infos, t_cmd *cmd);

/* AJOUTS branche env */
int     env_var_exists(t_infos *infos, char *key);
int     add_env_var(t_infos *infos, char *key, char *value);
int     remove_env_var(t_infos *infos, char *key);
char    *get_env_var(t_infos *infos, char *key);
int     contains_env_var(char  *str);
int     contains_return_code_var(char  *str);

char    *replace_str_var_one_new(t_infos *infos, char *str, int heredoc, int *cursor);
char    *replace_str_var_new(t_infos *infos, char *str);
char    *replace_one_var_on_str_from_new(t_infos *infos, char *str, char *key, int i);
char    *replace_str_var_heredoc_new(t_infos *infos, char *str);

/* AJOUTS 8 septembre 17 h 36 */
int     exp_check(char *str, int i);
char    *remove_quotes(char *str);
int     modify_args_cmd(t_cmd *cmd, t_infos *infos);

#endif //MINISHELL_H