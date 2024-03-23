/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:51:00 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/23 20:25:09 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lay	init_lay(void)
{
	t_lay	lay;

	lay.row = 0;
	lay.col = 0;
	lay.exit = 0;
	lay.coll = 0;
	lay.play = 0;
	return (lay);
}

t_check	init_check(void)
{
	t_check	check;

	check.inv_char = 0;
	check.inv_coll = 0;
	check.inv_exit = 0;
	check.inv_play = 0;
	check.inv_row = 0;
	check.inv_walls = 0;
	return (check);
}

void	init_img(t_game *game)
{
	game->img.width = 32;
	game->img.height = 32;

	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./imgs/wall.xpm", &game->img.width, &game->img.height);
	game->img.coll = mlx_xpm_file_to_image(game->mlx, "./imgs/coll.xpm", &game->img.width, &game->img.height);
	game->img.play = mlx_xpm_file_to_image(game->mlx, "./imgs/play.xpm", &game->img.width, &game->img.height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "./imgs/exit.xpm", &game->img.width, &game->img.height);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "./imgs/floor.xpm", &game->img.width, &game->img.height);
	game->img.enem = mlx_xpm_file_to_image(game->mlx, "./imgs/enem.xpm", &game->img.width, &game->img.height);
	game->img.exit_open = mlx_xpm_file_to_image(game->mlx, "./imgs/exit_open.xpm", &game->img.width, &game->img.height);
	if (!game->img.wall || !game->img.coll || !game->img.play || !game->img.exit || !game->img.floor || !game->img.enem || !game->img.exit_open)
		clear_images(game);
}