/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:21:31 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/05 18:52:31 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *remove_quotes(char *str)
{
    int     i;
    int     j;
    char    *new_str;
    char    curr_quote;

    i = 0;
    j = 0;
    curr_quote = '\0';
    new_str = NULL;
    while (str[i])
    {
        if (ft_isquote(str[i]) && curr_quote == '\0')
        {
            curr_quote = str[i];
            if (new_str)
                new_str = ft_strjoin_mem(new_str, ft_substr(str, j, i - j));
            else
                new_str = ft_substr(str, j, i - j);
            j = i + 1;
        }
        else if (str[i] == curr_quote)
        {
            curr_quote = '\0';
            new_str = ft_strjoin_mem(new_str, ft_substr(str, j, i - j));
            j = i + 1;
        }
        i++;
    }
    if (!new_str)
        new_str = ft_strdup(str);
    else if (str[j])
        new_str = ft_strjoin_mem(new_str, ft_substr(str, j, i - j));
    // free(str);
    return (new_str);
}
