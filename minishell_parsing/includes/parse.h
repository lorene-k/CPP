/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:04:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/16 15:00:34 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

/* ------------  LIBRARIES  ------------------------------------------------ */
# include <curses.h>
# include <fcntl.h>
# include <term.h>

/* ------------  MACROS ---------------------------------------------------- */
# define HEREDOC ".heredoc_tmp"
# define UNEXISTING_FILE ": No such file or directory"
# define BAD_ACCESS ": Permission denied"
# define INV_COMMAND ": command not found"
# define INV_TOKEN "syntax error near unexpected token `newline'"
# define MALLOC_ERR "memory can't be allocated"

/* ------------  STRUCTS  -------------------------------------------------- */
typedef enum e_type
{
	T_CHAR,
	T_STRING,
	T_KEYWORD,
	T_INT,
	T_DOUBLE,
	T_REDIRECT,
	T_PIPE,
	T_UNSPEC_OP,
	T_UNSPEC_PUNC
}						t_type;

typedef struct s_token
{
	char				*value;
	t_type				type;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct s_data	t_data;
typedef struct s_cmd	t_cmd;
typedef struct s_file	t_file;

/* ------------  FUNCTIONS  ------------------------------------------------ */
/* PARSER */
int						parse_infile(t_token **token, t_cmd *cmd, t_data *d);
int						handle_redirect(t_token **token, t_cmd *cmd, t_data *d);
int						get_cmd(t_token **token, t_cmd *cmd, t_data *d);
void					parser(t_token *token, t_data *data);

/* LEXER */
int						check_quotes(char *line, int start, int k, t_data *d);
int						check_operator(char *line, int i, int *j);
int						check_digit(char *line, int i, int *j);

void					check_type(t_token **token);
void					handle_unclosed_quote(char quote, t_token **token,
							t_data *d);
int						get_quoted_value(t_data *d, int i, int *j,
							t_token **token);

int						handle_expansion(t_token **token, t_data *d, int i,
							int *j);
void					check_expansion(t_token **token, t_data *d);

int						get_punctuation(t_token **token, t_data *d, int *i);
void					get_type(t_token *token, int type);
int						get_value(t_token *token, char *line, int *i, int type);

t_token					*lexer(t_token *token, char *line, t_data *data);
void					parse_input(t_data *data, char *line);

#endif //PARSE_H