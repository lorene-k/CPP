/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoperator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:51:24 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/09 17:07:40 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_isoperator_char(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%'
        || c == '=' || c == '|' || c == '^')
        return (1);
    return (0);
}

static int ft_isredirect_char(char c)
{
    if (c == '<' || c == '>')
        return (1);
    return (0);
}

int     ft_solo_operator(char *line, int i)
{
    if ((line[i] && ft_isoperator_char(line[i]))
        && (!line[i + 1] || ft_isspace(line[i + 1])))
        return (1);
    if ((line[i] && ft_isredirect_char(line[i]))
        && (!line[i + 1] || ft_isalnum(line[i + 1])
        || ft_isspace(line[i + 1])))
        return (1);
    return (0);
}

int     ft_multi_operator(char *line, int i)
{
    if ((line[i] && ft_isoperator_char(line[i])
        && line[i + 1] && line[i + 1] == line[i])
        && (!line[i + 2] || ft_isspace(line[i + 2])))
        return (1);
    if ((line[i] && ft_isredirect_char(line[i])
        && line[i + 1] && line[i + 1] == line[i])
        && (!line[i + 2] || ft_isalnum(line[i + 2])
        || ft_isspace(line[i + 2])))
        return (1);
    return (0);
}

int     ft_issign(char c)
{
    if (c == '+' || c == '-')
        return (1);
    else
        return (0);
}