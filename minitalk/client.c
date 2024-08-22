/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:22:52 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/21 16:31:13 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft_src/libft.h"

static int received_flg = 0;

static void sig_handler(int signum)
{
    static int  i = 0;

    received_flg = 1;
    if (signum == SIGUSR2)
        i++;
    else if (signum == SIGUSR1)
        ft_putnbr_fd(i / 8, 1);
}

static int ft_char_to_bin(char c, int pid)
{
    int i;
    int bit_index;

    bit_index = 8;
    while (--bit_index >= 0)
    {
        i = 0;
        if ((c >> bit_index) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        while (!received_flg)
        {
            if (i == 50)
                exit(1);
            i++;
            usleep(100);
        }
        received_flg = 0;
    }
    return (0);
}

int main(int ac, char **av)
{

    struct sigaction    sa;
    int                 i;
    int                 pid;
    
    if (ac != 3) // should also check if valid pid
        return (ft_putstr_fd("Error : wrong number of arguments.\n", 1), 1);
    i = -1;
    pid = ft_atoi(av[1]);
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = sig_handler;
    if (sigaction(SIGUSR1, &sa, NULL) == -1
        || sigaction(SIGUSR2, &sa, NULL) == -1)
        return (1);
    while (av[2][++i])
        ft_char_to_bin(av[2][i], pid);
    ft_char_to_bin('\0', pid);
    return (0);
}
