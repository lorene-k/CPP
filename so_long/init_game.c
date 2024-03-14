/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:37:03 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/14 17:40:04 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_game(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!(data.mlx))
		return (1);
	data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "Game window");
	if (!data.win)
		return (mlx_destroy_display(data.mlx), free(data.mlx), 1);
	
	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	
	mlx_loop_hook(data.mlx, show_enemies, &data);//for enemies
	mlx_key_hook(data.win, handle_input, &data); //&handle_input maybe?
                                                                                        
	// mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	// mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	mlx_loop(data.mlx);
	return (0);
}

void	init_game(char **map, t_lay lay)
{
	t_game	g;

	g.lay_bak = lay;
	g.n_collect_bak = lay.n_collect;
	g.map_bak = ft_dup_matrix(map);
	g.id = mlx_init();
	g.w_id = mlx_new_window(g.id, lay.n_col * SIZE, \
		lay.n_row * SIZE + 80, "Pac-Man");
	ft_newgame(&g, map, &lay);
}