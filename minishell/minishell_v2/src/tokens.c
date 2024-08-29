/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:48:26 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/22 17:21:48 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

static char	*store_token(t_token *curr, t_token **token)
{
	char	*str;

	str = malloc(sizeof(char) * curr->len + 1);
	if (!str)
		return (clear_tokens(token), NULL);
	str[0] = '\0';
	ft_strlcpy(str, curr->value, curr->len + 1);
	return (str);
}

static char	**token_to_str(t_token **token, int n_nodes)
{
	int		i;
	char	**token_tab;
	t_token	*curr;

	i = -1;
	curr = *token;
	token_tab = malloc(sizeof(char *) * (n_nodes + 1));
	if (!token_tab)
		return (clear_tab(token_tab), NULL);
	token_tab[n_nodes] = NULL;
	while (++i < n_nodes)
	{
		token_tab[i] = store_token(curr, token);
		if (!token_tab[i])
			return (clear_tab(token_tab), NULL);
		curr = curr->next;
	}
	clear_tokens(token);
	return (token_tab);
}

static int	ft_strchr_index(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((int)i);
		i++;
	}
	if (*s == (char)c)
		return ((int)i);
	return (-1);
}

static int	check_expansion(t_token **token, t_infos **infos)
{
	int		i;
	char	*tmp;

	i = ft_strchr_index((*token)->value, '$');
	tmp = ft_strdup((*token)->value);
	if (!(*token)->s_quote && i != -1 && (*token)->value[i + 1]
		&& ft_isalpha((*token)->value[i + 1]))
	{	
		free((*token)->value);
		(*token)->value = NULL;
		(*token)->value = replace_str_var(infos, tmp);
	}
	free(tmp);
}

static t_token	*create_tokens(char *line, t_infos **infos, int *n_nodes)
{
	int		i;
	t_token	*token;

	i = 0;
	token = NULL;
	(void)infos;
	while (i < (int)ft_strlen(line))
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i] == '#') // maybe useless
			break ;
		*n_nodes += add_token_node(&token);
		if (!token)
			return (clear_tokens(&token), NULL);
		get_token_value(line, &i, &token);
		if (token->error)
			return (clear_tokens(&token), NULL);
		token->len = ft_strlen(token->value);
		check_expansion(&token, infos);
	}
	return (get_first_node(token));
}

char	**generate_tokens_array(char *line, t_infos **infos)
{
	int		n_nodes;
	t_token	*token;

	n_nodes = 0;
	token = 0;
	token = create_tokens(line, infos, &n_nodes);
	if (!token)
		return (NULL);
	return (token_to_str(&token, n_nodes));
}

// #include <stdio.h>
// int	main(void)
// {
// 	char **token_tab;
// 	int i = 0;

// 	// char *line = ft_strdup("TOKEN1 hello\"this \'is \'a token\" break \'another \"token\'");
// 	char *line = ft_strdup("cat >in | cat>out 9709 DLSL[D O]");

// 	printf("LINE = %s\nEOL\n\n", line);

// 	token_tab = generate_tokens_array(line, 0);
// 	if (!token_tab)
// 		return (free(line), 1);
// 	while (token_tab[i])
// 	{
// 		printf("TOKEN %d = %s\n", i, token_tab[i]); //TEST
// 		i++;
// 	}
// 	clear_tab(token_tab);
// 	free(line);
// 	return (0);
// }