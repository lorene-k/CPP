/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:04:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/16 22:18:00 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

/* ------------  LIBRARIES  ------------------------------------------------ */
# include <curses.h>
# include <term.h>

/* ------------  MACROS ---------------------------------------------------- */
# define UNKNOWN_ERR 666
# define UNDEFINED_ERR 999

# define CHAR 1
# define STRING 2
# define KEYWORD 3
# define INT 4
# define DOUBLE 5
# define REDIRECT 6
# define UNSPEC_OP 7
# define UNSPEC_PUNC 8
# define NON_ASCII 9

/* ------------  STRUCTS  -------------------------------------------------- */
typedef struct s_token
{
	char			*value;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_data t_data;

/* ------------  FUNCTIONS  ------------------------------------------------ */
void	clear_tokens(t_token **start);
t_token *get_first(t_token *token);
void	add_token(t_token **current);

int		check_quotes(char *line, int start, int k);
int 	check_operator(char *line, int i, int *j);
int		check_digit(char *line, int i, int *j);

void    check_type(t_token **token);
void    handle_unclosed_quote(char quote, t_token **token);
int		get_quoted_value(char *line, int i, int *j, t_token **token);

int 	handle_expansion(t_token **token, char *line, int i, int *j);
void    check_expansion(t_token **token, char *tmp);

int		get_punctuation(t_token **token, char *line, int *i);
void    get_type(t_token *token, int type);
int    	get_value(t_token *token, char *line, int *i, int type);

t_token	*lexer(t_token *token, char *line);
void    parse_input(t_data *data, char *line);

#endif //PARSE_H