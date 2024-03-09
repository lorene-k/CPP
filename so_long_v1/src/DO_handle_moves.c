/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:23:27 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/02/09 16:25:41 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Closes windows & frees data when ESCAPE is pressed */
// int	handle_input(int keysym, t_data *data)
// {
// 	if (keysym == XK_Escape)
// 	{
// 		printf("Pressed key : %d\n", keysym);
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		mlx_destroy_display(data->mlx_ptr);
// 		free(data->mlx_ptr);
// 		exit(1);
// 	}
// 	printf("Pressed key : %d\n", keysym);
// 	return (0);
// }