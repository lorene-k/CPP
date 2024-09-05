/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:13:02 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/05 17:55:06 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int exp_check(char *str, int i)
{
    int		j;
    int     opened_quote;
	char	curr_quote;

    curr_quote = '\0';
	opened_quote = 0;
    j = 0;
    while (str[j] && j != i)
    {
        if (ft_isquote(str[j]))
        {
            curr_quote = str[j];
            opened_quote = 1;
        }
        else if (str[j] == curr_quote)
        {
            curr_quote = '\0';
            opened_quote = 0;
        }
        j++;
    }
    if (curr_quote == '\'')
        return (0);
    return (1);
}
