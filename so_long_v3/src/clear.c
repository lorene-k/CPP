/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:47:30 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/23 16:07:50 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_map(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	tab = 0;
}

void	tmp_clear(t_game *game)
{
	ft_printf("Error\nFile can't be opened.");
	clear_map(game->map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

int	clear_game(t_game *game)
{
	clear_map(game->map);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.play);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.coll);
	mlx_destroy_image(game->mlx, game->img.enem);
	mlx_destroy_image(game->mlx, game->img.exit_open);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
