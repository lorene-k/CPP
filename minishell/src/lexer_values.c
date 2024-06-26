/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:03:44 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/23 18:33:32 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static void    get_punctuation_value(t_token *token, char *line, int *i)
{
    token->value = line[*i];
    *i += 1;
}

static void   get_operator_value(t_token *token, char *line, int *i)
{
    if ((line[*i] == '!' && line[*i + 1] == '=') || (line[*i] == line[*i + 1])
        && line[*i] == '*' && line[*i] == '&' && line[*i] == '|'
        && line[*i] == '>' && line[*i] == '<')
    {
        token->value = ft_substr(line, *i, 2);
        *i += 2;
    }
    else
        token->value = line[*i];
    *i += 1;
}

static void    get_digit_value(t_token *token, char *line, int *i)
{
    int j;

    j = 0;
    while (ft_isdigit(line[*i + j]))
        j++;
    if (line[*i + j] == '.')
    {
        j++;
        while (ft_isdigit(line[*i + j]))
            j++;
    }
    token->value = ft_substr(line, *i, j);
    *i += j;
}

static void    get_alpha_value(t_token *token, char *line, int *i)
{
    int j;

    j = 0;
    while (ft_isalpha(line[*i + j]))
        j++;
    token->value = ft_substr(line, *i, j);
    *i += j;
}

void    get_value(t_token *token, char *line, int *i, int type)
{
    if (type == 1)
        get_alpha_value(token, line, i);
    if (type == 2)
        get_digit_value(token, line, i);
    if (type == 3)
        get_operator_value(token, line, i);
    if (type == 4)
        get_punctuation_value(token, line, i);
}

/*
TYPES :
- alpha
- digit
- operator 
- punctuation 
*/
