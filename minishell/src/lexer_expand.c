/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:55:21 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/16 22:25:30 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char    *get_exit_code(void) //TEST + MERGE WITH EXEC ?
{
    // while (++i < data->cmd.n)
	// 	waitpid(data->pid[i], status, 0);
	// return(ft_itoa(WEXITSTATUS(status)));
    return (ft_itoa(-1));
}

static char    *expand_value(char *to_expand)
{
    char    *exp_value;

    exp_value = ft_strdup(getenv(to_expand));
    if (!exp_value)
        return (ft_strjoin("$", to_expand));
    return(exp_value);
}

static void    ft_expand(t_token **token, char *to_expand)
{
    char    *expanded_value;

    expanded_value = 0;
    if (!to_expand)
        return ; // PROTECT MALLOC
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

int 	handle_expansion(t_token **token, char *line, int i, int *j) //HANDLE QUOTES AS LAST CHAR
{
    int     start;
    int     k;
    int     is_str;

    start = i + (*j) + 1;
    k = 0;
    is_str = 0;
    if (line[start] == '?')
        k += 1;
	else if (ft_isalpha(line[start]))
	{
        while (ft_isalnum(line[start + k]))
            k++;
    }
    if (!check_quotes(line, start, k))//HANDLE QUOTES
            ft_expand(token, ft_substr(line, start, k));
        else
            is_str = 1;
    if (is_str)
        k = handle_non_expansion(token, line, start - 1);
    check_type(token);
    (*j) += k;
    return (*j);
}

void    check_expansion(t_token **token, char *tmp) // IF IN QUOTES
{
    int    i;
    int    expansion;
 
    i = 0;
    expansion = 0;
    while (tmp[i] && tmp[i])
    {
        if (tmp[i] == '$' && (tmp[i + 1] == '?' || ft_isalpha(tmp[i + 1])))
        {
            if (i && !expansion) //retrieve input before expansion
                (*token)->value = ft_strjoin((*token)->value, ft_substr(tmp, 0, i)); // get first part of quoted str (before expansion)
            else if (i && expansion)
                (*token)->value = ft_strjoin_memory((*token)->value, ft_substr(tmp, expansion + 1, i - expansion - 1));
            expansion = handle_expansion(token, tmp, 0, &i);
        }
        else
            i++;
    }
    if (expansion && (i != expansion + 1) && i != 1) // handle expansion in the middle of quoted str  (expansion at end of quoted str handled in expand)
        (*token)->value = ft_strjoin_memory((*token)->value, ft_substr(tmp, expansion + 1, i - expansion - 1));
    else if (!expansion && i != 1) // handle no expansion
        (*token)->value = ft_strjoin_memory((*token)->value, tmp);
}
