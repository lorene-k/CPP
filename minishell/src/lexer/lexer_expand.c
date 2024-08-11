/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:55:21 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/11 13:54:24 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void    ft_expand(t_token **token, char *to_expand, t_data *d)
{
    char    *expanded_value;

    expanded_value = 0;
    if (!to_expand)
        return ; // PROTECT MALLOC
    if (*to_expand == '?')
        expanded_value = ft_strdup(ft_itoa(d->status)); //get data here
    else
        expanded_value = ft_strdup(getenv(to_expand));
    free(to_expand);
    if ((*token)->value && expanded_value) // pb here if exp = $?
        (*token)->value = ft_strjoin_memory((*token)->value, expanded_value);
    else if (expanded_value)
    {    
        (*token)->value = ft_strdup(expanded_value);
        free(expanded_value);
    }
}

static int handle_non_expansion(t_token **token, char *line, int i)
{
    int j;

    j = 0;
    while (line[i + j] && !ft_isspace(line[i + j]))
        j++;
    if ((*token)->value)
        (*token)->value = ft_strjoin_memory((*token)->value, ft_substr(line, i, j));
    else
        (*token)->value = ft_substr(line, i, j);
    return (j);
}

//EXPAND VARIABLES + HANDLE EXP AT END OF QUOTED STR
int 	handle_expansion(t_token **token, t_data *d, int i, int *j)
{
    int     start;
    int     k;
    int     is_str;

    start = i + (*j) + 1;
    k = 0;
    is_str = 0;
    if (d->line[start] == '?')
        k += 1;
	else if (ft_isalpha(d->line[start]))
	{
        while (ft_isalnum(d->line[start + k]))
            k++;
    }
    if (!check_quotes(d->line, start, k))
            ft_expand(token, ft_substr(d->line, start, k), d);
        else
            is_str = 1;
    if (is_str)
        k = handle_non_expansion(token, d->line, start - 1);
    if ((*token)->value)
        check_type(token);
    (*j) += k;
    return (*j);
}

 // HANDLE EXPANSION IF IN QUOTES
void    check_expansion(t_token **token, t_data *d)
{
    int    i;
    int    expansion;
 
    i = 0;
    expansion = 0;
    while (d->tmp[i] && d->tmp[i])
    {
        if (d->tmp[i] == '$' && (d->tmp[i + 1] == '?' || ft_isalpha(d->tmp[i + 1])))
        {
            if (i && !expansion) //retrieve input before expansion
                (*token)->value = ft_strjoin((*token)->value, ft_substr(d->tmp, 0, i)); // get first part of quoted str (before expansion)
            else if (i && expansion)
                (*token)->value = ft_strjoin_memory((*token)->value, ft_substr(d->tmp, expansion + 1, i - expansion - 1));
            expansion = handle_expansion(token, d, 0, &i);
        }
        else
            i++;
    }
    if (expansion && (i != expansion + 1) && i != 1) // handle expansion in the middle of quoted str  (expansion at end of quoted str handled in expand)
        (*token)->value = ft_strjoin_memory((*token)->value, ft_substr(d->tmp, expansion + 1, i - expansion - 1));
    else if (!expansion && i != 1) // handle no expansion
        (*token)->value = ft_strjoin_memory((*token)->value, d->tmp);
}
