/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:37:03 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/23 16:04:02 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int keysym, t_game *game)
{

	if (keysym == XK_Escape)
		clear_game(game);
	if (keysym == XK_w)
		move_up(game);
	if (keysym == XK_s)
		move_down(game);
	if (keysym == XK_a)
		move_left(game);		
	if (keysym == XK_d)
		move_right(game);
	return (0);
}

void	display_img(t_game *game, int x, int y) //y = height
{
	if (game->map[x][y] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall,  game->img.width * y, game->img.height * x);
	if (game->map[x][y] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor,  game->img.width * y, game->img.height * x);
	if (game->map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.coll, game->img.width * y, game->img.height * x);
	if (game->map[x][y] == 'E' && game->lay->coll > 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, game->img.width * y, game->img.height * x);
	if (game->map[x][y] == 'E' && game->lay->coll == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit_open, game->img.width * y, game->img.height * x);
	if (game->map[x][y] == 'N')
		mlx_put_image_to_window(game->mlx, game->win, game->img.enem, game->img.width * y, game->img.height * x);
	if (game->map[x][y] == 'P')
	{	
		mlx_put_image_to_window(game->mlx, game->win, game->img.play, game->img.width * y, game->img.height * x);
		game->play_pos.x = x;
		game->play_pos.y = y;
	}
}

int	render_map(t_game *game)
{
	int x;
	int	y;
	char *moves;

	x = 0;
	moves = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			display_img(game, x, y);
			y++;
		}
		x++;
	}
	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 14, 20, BLACK, moves); //check coordinates
	free(moves);
	return (0);
}

void	display_all(t_game game)
{
	game.win = mlx_new_window(game.mlx, (game.lay->col * game.img.width), (game.lay->row * game.img.height), "SO_LONG");
	// game.win = 0; // TEST HERE >> CHECK LEAKS
	if (!game.win)
	{
		perror("Error\n");
		clear_game(&game);
	}
	mlx_loop_hook(game.mlx, &render_map, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &clear_game, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &on_keypress, &game);
	mlx_loop(game.mlx);
}

void	init_game(char **map, t_lay *lay)
{
	t_game	game;
	t_point	size;

	size.x = lay->row;
	size.y = lay->col;
	game.moves = 0;
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
