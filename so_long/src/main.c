/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:51:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/07 17:06:54 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(void)
// {
// 	t_data	data;


// 	data.mlx = mlx_init();
// 	if (!(data.mlx))
// 		return (1);
// 	data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "Game window");
// 	if (!data.win)
// 		return (mlx_destroy_display(data.mlx), free(data.mlx), 1);
	
// 	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
// 	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
// 	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	
// 	mlx_loop_hook(data.mlx, show_enemies, &data);//for enemies
// 	mlx_key_hook(data.win, handle_input, &data); //&handle_input maybe?
                                                                                        
// 	// mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
// 	// mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

// 	mlx_loop(data.mlx);
// 	return (0);
// }


int	main(int ac, char **av)
{
	char	**map;
	t_lay	layout;

	layout = init_lay();
	map = check_args(ac, av, &layout);
	// init_game(map, layout);
	return (0);
}