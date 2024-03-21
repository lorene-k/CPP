/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:37:03 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/21 17:55:29 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clear_game(t_game *game)
{
	clear_map(game->map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.play);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.coll);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_game *game)
{

	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->win);
		clear_game(game);
		return (0);
	}
	// if (keysym == XK_w)

	// if (keysym == XK_d)

	// if (keysym == XK_a)

	// if (keysym == XK_s)

	return (0);
}

// void	display_img(t_game *game, int x, int y)
// {
// 	if (game->map[x][y] == '1')
// 		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, game->img.width * x, game->img.width * y);
// 	if (game->map[x][y] == 'C')
// 		mlx_put_image_to_window(game->mlx, game->win, game->img.coll, game->img.width * x, game->img.width * y);
// 	if (game->map[x][y] == 'E')
// 		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, game->img.width * x, game->img.width * y);
// 	if (game->map[x][y] == 'P')
// 	{	
// 		mlx_put_image_to_window(game->mlx, game->win, game->img.play, game->img.width * x, game->img.width * y);
// 		game->pos.x = x;
// 		game->pos.y = y;
// 	}
// }

// int	render_map(t_game *game)
// {
// 	int x;
// 	int	y;

// 	x = 0;
// 	while (game->map[x])
// 	{
// 		y = 0;
// 		while (game->map[x][y] != '\n')
// 		{
// 			display_img(game, x, y);
// 			y++;
// 		}
// 		x++;
// 	}
// 	return (0);
// }

void	display_all(t_game game)
{
	game.win = mlx_new_window(game.mlx, HEIGHT, WIDTH, "SO_LONG");
	// game.win = 0; // TEST HERE >> CHECK LEAKS
	if (!game.win)
	{
		perror("Error\n");
		clear_game(&game);
	}

	// mlx_loop_hook(game.mlx, &render_map, &game);
	
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &clear_game, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, &on_keypress, &game);
	mlx_loop(game.mlx);
}

void	init_game(char **map, t_lay *lay)
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
	if (!game.mlx)
		print_error("MLX initialization failed.", game.map, 0);
	init_img(&game);

	display_all(game);
}

// void	init_game(char **map, t_lay *lay)
// {
// 	t_game	game;
// 	t_point	size;

// 	size.x = lay->row;
// 	size.y = lay->col;
// 	game.map = copy_map(map, size);
// 	if (!(game.map))
// 		print_error("Memory allocation failed", map, 0);
// 	clear_map(map);
// 	game.lay = lay;
// 	game.mlx = mlx_init();
// 	if (!game.mlx)
// 		print_error("MLX initialization failed.", game.map, 0);
// 	// game.img = init_img(game);
// 	// display_all(game);
// 	game.win = mlx_new_window(game.mlx, HEIGHT, WIDTH, "SO_LONG");
// 	// game.win = 0; // TEST HERE >> CHECK LEAKS
// 	if (!game.win)
// 	{
// 		perror("Error\n");
// 		clear_game(&game);
// 	}

// 	// mlx_loop_hook(game.mlx, &render_map, &game);
	
// 	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &clear_game, &game);
// 	mlx_hook(game.win, KeyRelease, KeyReleaseMask, &on_keypress, &game);
// 	mlx_loop(game.mlx);
// }

// - update_status
// (check next dir/legal moves, collectibles, victory)
// + update score 