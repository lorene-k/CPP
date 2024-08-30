/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:23:20 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/30 20:17:55 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/minishell.h"

// void    sig_handler(int sig, siginfo_t *info, void *context)
// {
//     (void)context;
//     (void)info;
//     if (sig == SIGINT) // CTRL+C : reset prompt
//         return ;
//     if (sig = SIGQUIT) // CTRL+\ : do nothing + generate core dump if in child process
//         return ;
    
// }

// void    init_sa(struct sigaction sa)
// {
//     sigemptyset(&sa.sa_mask);
//     sa.sa_flags = SA_RESTART | SA_SIGINFO;
//     sa.sa_sigaction = sig_handler;
//     sigaction(SIGINT, &sa, NULL);
//     sigaction(SIGQUIT, &sa, NULL);
// }