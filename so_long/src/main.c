/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:51:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/15 16:29:45 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	t_lay	lay;

	lay = init_lay();
	map = check_args(ac, av, &lay);
	// if (map)
	// 	printf("PARSING OK\n\n");
	if (init_game(map, &lay))
		print_error("MLX problem.", map, 0);
	return (0);
}