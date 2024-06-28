/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:04:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/28 17:52:47 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

/* ------------  MACROS ---------------------------------------------------- */
# define UNKNOWN_ERR 666
# define UNDEFINED_ERR 999

# define CHAR 1
# define STRING 2
# define KEYWORD 3
# define INT 4
# define DOUBLE 5
# define QUOTE 6
# define D_QUOTE 7
# define DOLLAR 8
# define Q_MARK 9
# define REDIRECT 10
# define UNSPEC_OP 11
# define UNSPEC_PUNC 12
# define NON_ASCII 13

/* ------------  LIBRARIES  ------------------------------------------------ */
# include "minishell.h"

# include <curses.h>
# include <term.h>

/* ------------  STRUCTS  -------------------------------------------------- */
typedef struct s_token
{
	char			*value;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

/* ------------  FUNCTIONS  ------------------------------------------------ */
void	clear_tokens(t_token **start);
t_token *get_first(t_token *token);
void	add_token(t_token **current);

void    get_type(t_token *token, int type);
void    get_value(t_token *token, char *line, int *i, int type);
t_token	*lexer(t_token *token, char *line);
void    parse_input(t_data *data, char *line);

#endif //PARSE_H