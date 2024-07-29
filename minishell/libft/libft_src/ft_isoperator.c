/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoperator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:51:24 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/28 12:01:27 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_isoperator_char(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%'
        || c == '=' || c == '|' || c == '^'
        || c == '<' || c == '>')
        return (1);
    return (0);
}

int     ft_isoperator(char *line, int i)
{
    if ((line[i] && ft_isoperator_char(line[i]))
        && (!line[i + 1] || line[i] == line[i + 1]
        || ft_isspace(line[i + 1])))
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