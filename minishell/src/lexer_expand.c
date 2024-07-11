/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:55:21 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/07 18:17:48 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char    *get_exit_code(void) //TEST
{
    // while (++i < data->cmd.n)
	// 	waitpid(data->pid[i], status, 0);
	// return(ft_itoa(WEXITSTATUS(status)));
    return (ft_itoa(-1));
}

static char    *expand_value(char *to_expand)
{
    return(ft_strdup(getenv(to_expand)));
}

static void    ft_expand(t_token **token, char *to_expand)
{
    char    *expanded_value;

    expanded_value = 0;
    if (!to_expand)
        return ; //CHECK HOW TO PROTECT MALLOC HERE
    if (*to_expand == '?')
        expanded_value = get_exit_code();
    else
        expanded_value = expand_value(to_expand);
    free(to_expand);
    if ((*token)->value)
        (*token)->value = ft_strjoin_memory((*token)->value, expanded_value);
    else
    {    
        (*token)->value = ft_strdup(expanded_value);
        free(expanded_value);
    }
}

int 	handle_expansion(t_token **token, char *line, int i, int *j)
{
    int     start;
    int     k;       

    start = i + (*j) + 1;
    k = 0;
    if (line[start] == '?')
    {
        k += 1;
        ft_expand(token, ft_substr(line, start, k));
    }
	else if (ft_isalpha(line[start]))
	{
        while (ft_isalnum(line[start + k]))
            k++;
        ft_expand(token, ft_substr(line, start, k));
    }
    (*j) += k;
    return (*j);
}
