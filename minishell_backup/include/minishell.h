#ifndef MINISHELL_H
# define MINISHELL_H

#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft.h"

#include "tokens.h"

typedef enum e_in_out_type {
    PIPE = 0,
    FILE_REAL = 1,
    NORMAL = 2,
    HEREDOC = 3,
    APPEND = 4,
    TRUNC = 5
} t_in_out_type;

typedef struct s_cmd
{
    char    **args; // tableau qui contient le nom de la commande et les arguments
    char    *infile;
    char    *outfile;
    int     fd_out;
    int     fd_in;
    int args_indexes; // nombre d'indexs (cases) dans le malloc (derniere case NULL comprise), si 0 1 2 alors args_index = 3

    char    *heredoc; // la chaine de caractere pour arreter le heredoc

    t_in_out_type intype;
    t_in_out_type outtype;

    char    *path; // Chemin A CODER (a partir de la variable env)

    int builtin;

    // AJOUTE RECEMMENT

    int can_access_file; // 1 si la commande a reussi a ouvrir les fichiers SINON 0
    // int can_access_file_name; // 1 si la commande a reussi a ouvrir les fichiers SINON 0
    int cmd_not_found; // AJOUTE RECEMMENT SI LA COMMANDE NEST PAS TROUVEE
    char *heredoc_file_name;

    struct s_cmd *next;
    struct s_cmd *previous;
} t_cmd;


extern int sig_id;

typedef struct s_infos
{
    int pipes_nb;
    int *tube;
    // char **envp;
    char **paths;
    t_cmd   **cmd; // tableau qui contient toutes les commandes
    int     cmd_nb; // contient le nombre de commandes pour le tableau cmd (sans prendre en compte la derniere case NULL, donc en réalité si cmd_nb = 2 alors il y a 3 cases : les deux valeurs puis le NULL)
    int     *pid;
    // int     actual_pipe_id;
    int return_code;


        int sig_id_heredoc; // test

    char    **new_envp; // Contient le tableau de  toutes les variables denvironnement
    char    *input; //// AJOUTE



    	int				printed_error;
}   t_infos;

// FREE
void free_infos_error(t_infos *infos);
void free_infos(t_infos **infos);
void free_create_commands(t_infos **infos);
void free_infos_while(t_infos **infos);

// ENV
void init_env_var(t_infos *infos, char **envp);
char *get_env_var(t_infos *infos, char *key);
void set_infos_path(t_infos *infos);
void add_env_var(t_infos *infos, char *key, char *value);
char *replace_str_var(t_infos *infos, char *str);
void remove_env_var(t_infos *infos, char *key);
int env_var_exists(t_infos *infos, char *key);
char *replace_str_var_heredoc(t_infos *infos, char *str);


// ERRORS AND FREE
void    free_cmd_args(t_cmd *cmd);
void free_all(t_infos **infos, char *input);
void free_cmd_tokens(char    **cmd_array);
void free_two_tokens(char *actual_token, char *next_token,t_cmd *actual_cmd, int arg_id);
void free_new(t_infos **infos, char *input);

// Show (parsing.h)
// void show_cmd_args(t_cmd *cmd);

// Lexing
// t_token *generate_tokens(char *str);
char **generate_tokens_array_new(char *str);



// PARSING
int parse(char  *str, t_infos **infos, char **envp);
int exec_command(char **tmp, t_infos *infos);

/// PARSING/show
void show_cmd(t_infos **infos);
void show_cmd_in_out(t_infos **infos);
void show_cmd_args(t_cmd *cmd);
void    show_fd(t_infos *infos);

/// PARSING/create_commands
void create_commands(char    **cmd_array, t_infos **infos);
void set_default_cmd_values(t_infos **infos);

/// PARSING/modify_commands
// void set_infile_outfile(t_infos **infos);
void set_infile_outfile(t_infos **infos);

/// PARSING/modify_commands2
void set_in_out_pipes_and_normal(t_infos **infos);
int set_all_cmd_path(t_infos **infos, char **envp);


// SIGNALS
void signals_init();
void signals_init_heredoc();
void signals_init_execution();

// Execution
void create_pipes(t_infos **infos);
void create_all_fd(t_infos **infos);
void execute_all_cmds(t_infos **infos);
void execute(t_infos **infos);

// Builtin
int is_builtin(char *str);
int ft_pwd(t_infos *infos, t_cmd *cmd);
int	ft_strcmp(char *s1, char *s2);
int ft_echo(t_infos *infos, t_cmd *cmd);
int ft_env(t_infos *infos, t_cmd *cmd);
int ft_export(t_infos *infos, t_cmd *cmd);
int ft_unset(t_infos *infos, t_cmd *cmd);
int ft_cd(t_infos *infos, t_cmd *cmd);
int ft_exit(t_infos *infos, t_cmd *cmd);

#endif