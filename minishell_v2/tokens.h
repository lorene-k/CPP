/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:34:11 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/22 16:54:45 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H

# define TEST_H

typedef struct s_infos	t_infos;

typedef struct s_token
{
	char				*value;
	size_t				len;
	int					s_quote;
	int					error;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

/* TOKEN UTILS */
void					clear_tokens(t_token **start);
t_token					*get_first_node(t_token *token);
int						add_token_node(t_token **current);
void					clear_tab(char **tab);

/* TOKEN OPERATORS */
int						ft_solo_operator(char *line, int i);
int						ft_multi_operator(char *line, int i);
int						ft_isoperator(char *line, int i);
int						ft_isquote(char c);

/* TOKENS */
void					get_token_value(char *line, int *i, t_token **token);
char					**tokenize(char *line, t_infos *infos);

#endif //PARSE_H