/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:04:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/21 17:02:31 by lkhalifa         ###   ########.fr       */
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
# define UNSPEC_CHAR 11

/* ------------  LIBRARIES  ------------------------------------------------ */
# include "../includes/minishell.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <curses.h>
# include <term.h>

/* ------------  FUNCTIONS  ------------------------------------------------ */
void    parse_input(t_data *data, char *line);

#endif //PARSE_H