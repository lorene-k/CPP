/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:16:40 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/13 16:36:57 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		g_sig_id = 128 + SIGINT;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	signal_handler_execution(int signo)
{
	if (signo == SIGINT)
	{
		ft_putendl_fd("DANS EXECUTION SIG", 1);
		g_sig_id = 128 + SIGINT;
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

// A la fin du heredoc et au debut du programme
void	signals_init(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

// Avant exec
void	signals_init_execution(void)
{
	signal(SIGINT, signal_handler_execution);
	signal(SIGQUIT, SIG_IGN);
}
