/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:51:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/02/09 16:16:24 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	on_destroy(t_data *data)
// {
// 	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 	mlx_destroy_display(data->mlx_ptr);
// 	free(data->mlx_ptr);
// 	exit(0);
// 	return (0);
// }

// int	on_keypress(int keysym, t_data *data)
// {
// 	(void)data;
// 	printf("Pressed key: %d\\n", keysym);
// 	return (0);
// }

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("Pressed key : %d\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("Pressed key : %d\n", keysym);
	return (0);
}

int	show_enemies(t_data *data)
{
	/*triggered constantly, not by event*/
}

int	main(void)
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
	
	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop_hook(data.mlx, show_enemies, &data);//for enemies
		// mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	// mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy,
	// 		&data);
	
	mlx_loop(data.mlx);
	return (0);
}
