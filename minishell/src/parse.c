/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:33:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/20 18:23:02 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static void     ft_getword(t_token *token, char *line, int *i)
{
    
}

static void     ft_getnum(t_token *token, char *line, int *i)
{
    
}

static void     ft_getchar(t_token *token, char *line, int *i)
{
    
}

static void     lexer(t_token *token, char *line)
{
    int i;

    i = 0;
    while (line)
    {
        while (ft_isspace(line[i]))
            i++;
        if (ft_isalpha(line[i]))
            ft_getword(token, line, &i);
        if (ft_isdigit(line[i]))
            ft_getnum(token, line, &i);
        if (ft_isascii(line[i]))
            ft_getchar(token, line, &i);
        if (!(ft_isalpha(line) || ft_isdigit(line[i]) || ft_isascii(line[i])))
            i++; // WHAT TO DO IF NOT ASCII CHARS ???
    }
}

void    parse_input(t_data *data, char *line)
{
    t_token token;
    
    lexer(&token, line);
    (void)data;
    // parser(data);
}