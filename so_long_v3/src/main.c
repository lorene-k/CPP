/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:51:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/23 20:33:54 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	t_lay	lay;

	lay = init_lay();
	map = check_args(ac, av, &lay);
	init_game(map, &lay);
	return (0);
}