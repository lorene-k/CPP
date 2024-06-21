/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:33:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/21 17:25:02 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static void     lexer(t_token *token, char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (i = 0)
            init_token();
        //addtokentolist
        while (ft_isspace(line[i]))
            i++;
        if (line[i] == '#') //HANDLE COMMENTS
            break ;
        if (ft_isalnum(line[i]))
            ft_getconstant(token, line, &i);
        if (ft_isspecchar(line[i]))
            ft_getspecchar(line[i]);
        // if (!(ft_isascii(line))) //CHECK OTHER ASCII CHARS
        //     ft_getnonascii(line[i]);
    }
}

void    parse_input(t_data *data, char *line)
{
    t_token token;
    

    lexer(&token, line); //CREATE TOKENS
    (void)data;
    // parser(&token, data); //PARSE TOKENS
}
