/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imounjed <imounjed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:07:54 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/20 14:11:07 by imounjed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_sig_id = 0;

// char	*get_input_test(t_infos **infos)
// {
// 	char	*input;
// 	int		i;

// 	i = 0;
// 	input = ft_calloc(sizeof(char), 512);
// 	if (!input)
// 		exit(1);
// 	ft_putstr_fd("\033[1;32mminishell TEST$\033[0m ", 1);
// 	if ((i = read(0, input, 511)) == 0)
// 	{
// 		free_infos(infos);
// 		ft_putendl_fd("\nexit", 1);
// 		free(input);
// 		exit(0);
// 	}
// 	else if (i < 0)
// 	{
// 		free(input);
// 		exit(1);
// 	}
// 	(*ft_strchr(input, '\n')) = '\0';
// 	return (input);
// }

char	*get_input(t_infos **infos)
{
	char	*input;

	input = readline("\033[1;32mminishell$\033[0m ");
	if (!input)
	{
		free_infos(infos);
		ft_putendl_fd("exit", 1);
		exit(0);
	}
	add_history(input);
	return (input);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_infos	*infos;

	infos = NULL;
	(void)argc;
	(void)argv;
	while (1)
	{
		signals_init();
		input = get_input(&infos);
		if (parse(input, &infos, envp) != 0)
		{
			create_all_fd(&infos);
			execute(&infos);
			free_infos_while(&infos);
		}
	}
	return (0);
}
