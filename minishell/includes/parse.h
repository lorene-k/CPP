/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:04:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/27 17:22:21 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

/* ------------  MACROS ---------------------------------------------------- */
# define UNKNOWN_ERR 666
# define UNDEFINED_ERR 999

# define CHAR 1
# define KEYWORD 2
# define STRING 3 
# define INT 4
# define DOUBLE 5
# define QUOTE 6
# define D_QUOTE 7
# define DOLLAR 8
# define REDIRECT 9
# define UNSPEC_OP 10
# define UNSPEC_PUNC 11

/* ------------  LIBRARIES  ------------------------------------------------ */
# include "minishell.h"

# include <curses.h>
# include <term.h>

/* ------------  STRUCTS  -------------------------------------------------- */

/* ------------  FUNCTIONS  ------------------------------------------------ */
void	clear_tokens(t_token **start);
void	add_token(t_token **start);

void    get_type(t_token *token, int type);
void    get_value(t_token *token, char *line, int *i, int type);
void     lexer(t_data *data, t_token *token, char *line);
void    parse_input(t_data *data, char *line);

#endif //PARSE_H