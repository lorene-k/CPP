/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:04:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/20 17:56:57 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

/* ------------  MACROS ---------------------------------------------------- */
# define UKNOWN_ERR 666
# define UNDEFINED_ERR 666

/* ------------  LIBRARIES  ------------------------------------------------ */
# include "../includes/minishell.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <curses.h>
# include <term.h>

/* ------------  FUNCTIONS  ------------------------------------------------ */
void    parse_input(t_data *data, char *line);

#endif //PARSE_H