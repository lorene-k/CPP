/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:47:30 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/23 20:15:10 by lkhalifa         ###   ########.fr       */
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

void	clear_images(t_game *game)
{
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->img.play)
		mlx_destroy_image(game->mlx, game->img.play);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.coll)
		mlx_destroy_image(game->mlx, game->img.coll);
	if (game->img.enem)
		mlx_destroy_image(game->mlx, game->img.enem);
	if (game->img.exit_open)
		mlx_destroy_image(game->mlx, game->img.exit_open);
	ft_printf("Error\nFile can't be opened.");
	clear_map(game->map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}