/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:04:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/29 16:25:02 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

/* ------------  LIBRARIES  ------------------------------------------------ */
# include <curses.h>
# include <term.h>
# include <fcntl.h>

/* ------------  MACROS ---------------------------------------------------- */
# define UNKNOWN_ERR 666
# define UNDEFINED_ERR 999

# define HEREDOC ".heredoc_tmp"
# define UNEXISTING_FILE ": No such file or directory"
# define BAD_ACCESS ": Permission denied"
# define INV_COMMAND ": command not found"
# define REDIRECT_ERR "syntax error near unexpected token `newline'" //change "newline" according to following token
# define MALLOC_ERR "memory can't be allocated"

/* ------------  STRUCTS  -------------------------------------------------- */
typedef enum {
	CHAR,
	STRING,
	KEYWORD,
	INT,
	DOUBLE,
	REDIRECT,
	PIPE,
	UNSPEC_OP,
	UNSPEC_PUNC
}	token_type;

typedef struct s_token
{
	char				*value;
	token_type			type;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct s_data	t_data;
typedef struct s_cmd	t_cmd;

/* ------------  FUNCTIONS  ------------------------------------------------ */
/* STRUCTS */
void					add_cmd(t_cmd **current);
void					clear_tokens(t_token **start);
t_cmd					*get_first_cmd(t_cmd *last);
t_token					*get_first_token(t_token *last);
void					add_token(t_token **current);

/* PARSER */
int					    handle_redirect(t_token **token, t_cmd *cmd, t_data *data);
void					get_cmd(t_token **token, t_cmd *cmd, t_data *data);
int						parser(t_token *token, t_data *data);

/* LEXER */
int						check_quotes(char *line, int start, int k);
int						check_operator(char *line, int i, int *j);
int						check_digit(char *line, int i, int *j);

void					check_type(t_token **token);
void					handle_unclosed_quote(char quote, t_token **token);
int						get_quoted_value(char *line, int i, int *j,
							t_token **token);

int						handle_expansion(t_token **token, char *line, int i,
							int *j);
void					check_expansion(t_token **token, char *tmp);

int						get_punctuation(t_token **token, char *line, int *i);
void					get_type(t_token *token, int type);
int						get_value(t_token *token, char *line, int *i, int type);

t_token					*lexer(t_token *token, char *line);
void					parse_input(t_data *data, char *line);

#endif //PARSE_H