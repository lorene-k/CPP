/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:37:03 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/28 17:47:31 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_img(t_game *g, int x, int y)
{
	int	w;
	int	h;

	w = g->img.w;
	h = g->img.h;
	if (g->map[x][y] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * y, h * x);
	if (g->map[x][y] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->img.floor, w * y, h * x);
	if (g->map[x][y] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img.coll, w * y, h * x);
	if (g->map[x][y] == 'E' && g->lay->coll > 0)
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w * y, h * x);
	if (g->map[x][y] == 'E' && g->lay->coll == 0)
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit_open, w * y, h * x);
	if (g->map[x][y] == 'N')
		mlx_put_image_to_window(g->mlx, g->win, g->img.enem, w * y, h * x);
	if (g->map[x][y] == 'P')
	{	
		mlx_put_image_to_window(g->mlx, g->win, g->img.play, w * y, h * x);
		g->play_pos.x = x;
		g->play_pos.y = y;
	}
}

int	render_map(t_game *game)
{
	int		x;
	int		y;
	char	*moves;

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
	mlx_string_put(game->mlx, game->win, 14, 20, BLACK, moves);
	free(moves);
	return (0);
}

void	display_all(t_game game)
{
	int	w;
	int	h;

	w = game.lay->col * game.img.w;
	h = game.lay->row * game.img.h;
	game.win = mlx_new_window(game.mlx, w, h, "SO_LONG");
	if (!game.win)
		clear_images(&game, 0);
	render_map(&game);
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
