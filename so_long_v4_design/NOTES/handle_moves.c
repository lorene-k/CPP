/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:09:58 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/21 17:13:41 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

CHECK COLLECTIBLES


// void	render_top(t_data *data)
// {
// 	int		pos_x;
// 	int		pos_y;

// 	pos_x = data->pos.x / data->img.height;
// 	pos_y = data->pos.y / data->img.width;
// 	if (data->map[pos_y - 1][pos_x] != data->content.wall)
// 	{
// 		if (!(data->map[pos_y - 1][pos_x] == data->content.exit))
// 		{
// 			data->map[pos_y - 1][pos_x] = data->content.player;
// 			data->map[pos_y][pos_x] = data->content.space;
// 			data->count += 1;
// 			printf("count: %d\n", data->count);
// 		}
// 		else
// 		{
// 			if (chk_collect(data) == 0)
// 			{
// 				printf("Felicitation vous avez gagne en : %d coup !\n",
// 					data->count);
// 				end(data);
// 			}
// 		}
// 	}
// }

// void	render_right(t_data *data)
// {
// 	int		pos_x;
// 	int		pos_y;

// 	pos_x = data->pos.x / data->img.height;
// 	pos_y = data->pos.y / data->img.width;
// 	if (data->map[pos_y][pos_x + 1] != data->content.wall)
// 	{
// 		if (!(data->map[pos_y][pos_x + 1] == data->content.exit))
// 		{
// 			data->map[pos_y][pos_x + 1] = data->content.player;
// 			data->map[pos_y][pos_x] = data->content.space;
// 			data->count += 1;
// 			printf("count: %d\n", data->count);
// 		}
// 		else
// 		{
// 			if (chk_collect(data) == 0)
// 			{
// 				printf("Felicitation vous avez gagne en : %d coup !\n",
// 					data->count);
// 				end(data);
// 			}
// 		}
// 	}
// }

// void	render_left(t_data *data)
// {
// 	int		pos_x;
// 	int		pos_y;

// 	pos_x = data->pos.x / data->img.height;
// 	pos_y = data->pos.y / data->img.width;
// 	if (data->map[pos_y][pos_x - 1] != data->content.wall)
// 	{
// 		if (!(data->map[pos_y][pos_x - 1] == data->content.exit))
// 		{
// 			data->map[pos_y][pos_x - 1] = data->content.player;
// 			data->map[pos_y][pos_x] = data->content.space;
// 			data->count += 1;
// 			printf("count: %d\n", data->count);
// 		}
// 		else
// 		{
// 			if (chk_collect(data) == 0)
// 			{
// 				printf("Felicitation vous avez gagne en : %d coup !\n",
// 					data->count);
// 				end(data);
// 			}
// 		}
// 	}
// }

// void	render_down(t_data *data)
// {
// 	int		pos_x;
// 	int		pos_y;

// 	pos_x = data->pos.x / data->img.height;
// 	pos_y = data->pos.y / data->img.width;
// 	if (data->map[pos_y + 1][pos_x] != data->content.wall)
// 	{
// 		if (!(data->map[pos_y + 1][pos_x] == data->content.exit))
// 		{
// 			data->map[pos_y + 1][pos_x] = data->content.player;
// 			data->map[pos_y][pos_x] = data->content.space;
// 			data->count += 1;
// 			printf("count: %d\n", data->count);
// 		}
// 		else
// 		{
// 			if (chk_collect(data) == 0)
// 			{
// 				printf("Felicitation vous avez gagne en : %d coup !\n",
// 					data->count);
// 				end(data);
// 			}
// 		}
// 	}
// }