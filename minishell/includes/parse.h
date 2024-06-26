/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:04:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/23 18:36:25 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

/* ------------  MACROS ---------------------------------------------------- */
# define UKNOWN_ERR 666
# define UNDEFINED_ERR 999

# define CHAR 1
# define STRING 2
# define KEYWORD 3 
# define INT 4
# define FLOAT 5
# define QUOTE 6
# define D_QUOTES 7
# define DOLLAR 8
# define REDIRECT 9
# define APPEND 10
# define UNSPEC_OP 11
# define UNSPEC_PUNCT 12

/* ------------  LIBRARIES  ------------------------------------------------ */
# include "../includes/minishell.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <curses.h>
# include <term.h>

/* ------------  FUNCTIONS  ------------------------------------------------ */
void    get_type(t_token *token, int type);
void    get_value(t_token *token, char *line, int *i, int type);
void    lexer(t_token *token, char *line);
void    parse_input(t_data *data, char *line);

#endif //PARSE_H