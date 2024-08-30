/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:34:11 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/25 17:19:06 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H

# define TOKENS_H

/* ------------  MACROS ---------------------------------------------------- */
# define SYNTAX_ERR "syntax error near unexpected token"
# define MALLOC_ERR "memory can't be allocated"
# define QUOTE_ERR "parsing error: unclosed quote"
# define TOKEN_ERR "parsing error: value not handled"

# define EXIT_ARG_ERR "exit: too many arguments"
# define EXIT_NUM_ERR ": numeric argument required"

/* ------------  STRUCTS  -------------------------------------------------- */
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

/* ------------  FUNCTIONS  ------------------------------------------------ */
/* ERRORS */
int						print_cmd_error(char *msg, t_infos *infos, int code);
int						protect_memory(t_infos *infos, char *str, char **tab);

/* SIGNALS */
void					sigquit_handler(int signum);
void					sigint_handler_nodisplay(int signum);
void					sigint_handler_nonl(int signum);
void					sigint_handler(int signum);
void					sig_init(void);

/* CHECK */
void					*print_memory_error(t_infos *infos, char **tab,
							t_token *token);
int						print_parse_error(t_infos *infos, int code, char *msg);
int						check_invalid_tokens(t_token *token, t_infos *infos);

/* OPERATORS */
int						ft_solo_operator(char *line, int i);
int						ft_multi_operator(char *line, int i);
int						ft_isoperator(char *line, int i);
int						ft_isquote(char c);

/* UTILS */
void					clear_tokens(t_token **start);
t_token					*get_first_node(t_token *token);
int						add_token_node(t_token **current, t_infos *infos);
void					clear_tab(char **tab);

/* TOKENS */
int						ft_strchr_index(const char *s, int c);
void					get_token_value(char *line, int *i, t_token **token,
							t_infos *infos);
char					**generate_tokens_array(char *line, t_infos *infos);

#endif //TOKENS_H