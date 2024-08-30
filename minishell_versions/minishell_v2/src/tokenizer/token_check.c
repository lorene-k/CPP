/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:28:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/23 13:35:26 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*print_memory_error(t_infos *infos, char **tab, t_token *token)
{
	clear_tab(tab);
	clear_tokens(&token);
	ft_putstr_fd("minishell: ", 2);
	ft_putendl_fd(MALLOC_ERR, 2);
	infos->return_code = 1;
	return (NULL);
}

int	print_parse_error(t_infos *infos, int code, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putendl_fd(msg, 2);
	infos->return_code = code;
	return (code);
}


// A REVOIR, FAUX NE MARCHE PAS AVEC : << EOF cat | << EOF cat
static int	check_syntax(t_token *curr, t_infos *infos)
{
	if (ft_isoperator(curr->value, 0) && (!curr->next
			|| ft_isoperator(curr->next->value, 0)
			|| curr->next->value[0] == '&' || curr->next->value[0] == '!'
			|| curr->next->value[0] == ';' || curr->next->value[0] == '}'))
		return (print_parse_error(infos, 2, SYNTAX_ERR));
	return (0);
}


/// FAUX A REFAIRE
int	check_invalid_tokens(t_token *token, t_infos *infos)
{
	// t_token	*curr;

	// curr = token;
	// while (curr)
	// {
	// 	if (check_syntax(curr, infos))
	// 		return (clear_tokens(&token), 1);
	// 	curr = curr->next;
	// }
	return (0);
}
