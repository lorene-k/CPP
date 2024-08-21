/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.C                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:34:24 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/21 16:29:05 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft_src/libft.h"

static void    ft_bin_to_char(int signum, char *c)
{
    if (signum == SIGUSR1)
        *c = (*c << 1) | 1; // append 1 to least significant bit
    else if (signum == SIGUSR2)
        *c <<= 1;           // append 0 to least significant bit
}

static void    sig_handler(int signum, siginfo_t *info, void *context)
{
    static int  pid = 0;
    static int  i = 0;
    static char c = 0;

    (void)context;
    if (pid == 0)
        pid = info->si_pid;
    ft_bin_to_char(signum, &c);
    if (++i == 8)
    {
        i = 0;
        if (!c)
        {
            kill(pid, SIGUSR1);
            pid = 0;
            return ;
        }
        ft_putchar_fd(c, 1);
        c = 0;
    }
    kill(pid, SIGUSR2);
}

static void ft_print_pid(void)
{
    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd('\n', 1);
}

int main(void)
{
    struct sigaction    sa;
    
    ft_print_pid();
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_SIGINFO;
    sa.sa_sigaction = sig_handler;
    if (sigaction(SIGUSR1, &sa, NULL) == -1
        || sigaction(SIGUSR2, &sa, NULL) == -1)
        return (1);
    while (1)
        pause();
    return (0);
}