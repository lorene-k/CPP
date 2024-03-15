/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:37:03 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/15 17:37:35 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_game *game)
{
	clear_map(game->map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	on_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->win);
		on_destroy(game);
	}
	// if (keysym == )
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*to_fill;

	to_fill = img->addr + (y * img->line_length + x * (img->bits_per_pixel
				/ 8));
	*(unsigned int *)to_fill = color;
}

int	display_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	my_mlx_pixel_put(&(game->img), 10, 10, RED);
	// my_mlx_pixel_put(&(game->img), 20, 20, WHITE);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int	init_game(char **map, t_lay *lay)
{
	t_game	game;
	t_point	size;

	size.x = lay->row;
	size.y = lay->col;
	game.map = copy_map(map, size);
	if (!(game.map))
		print_error("Memory allocation failed", map, 0);
	clear_map(map);
	game.lay = lay;
	game.mlx = mlx_init();
	if (!(game.mlx))
		return (1);
	game.win = mlx_new_window(game.mlx, HEIGHT, WIDTH, "Game");
	if (!game.win)
		return (mlx_destroy_display(game.mlx), free(game.mlx), 1);
	mlx_loop_hook(game.mlx, &display_image, &game); // FRAME RENDERING
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, &on_keypress, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &on_destroy, &game);
	mlx_loop(game.mlx);
	return (0);
}
