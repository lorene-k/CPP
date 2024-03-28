/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:54:51 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/28 15:24:32 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_moves(t_game *game, t_point target_pos)
{
	if (game->map[target_pos.x][target_pos.y] != 'E')
		game->moves += 1;
	else if (game->map[target_pos.x][target_pos.y] == 'E'
			&& game->lay->coll == 0)
		game->moves += 1;
}

void	update_pos(char *x, char *y, char a, char b)
{
	*x = a;
	*y = b;
}

void	end_game(t_game *game, int outcome)
{
	if (outcome == 1)
	{
		ft_printf("\033[32mVICTORY\n");
		ft_printf("You have won the game in %d moves!\n\033[0m", game->moves);
	}
	else if (outcome == 0)
		ft_printf("\033[31mLOSER\nYou have lost the game :(\n\033[0m");
	clear_game(game);
}

void	update_game(t_game *game, t_point tp, int x, int y)
{
	if (game->map[tp.x][tp.y] != '1')
	{
		if (game->map[tp.x][tp.y] == '0')
			update_pos(&(game->map[x][y]), &(game->map[tp.x][tp.y]), '0', 'P');
		else if (game->map[tp.x][tp.y] == 'C')
		{
			game->lay->coll -= 1;
			update_pos(&(game->map[x][y]), &(game->map[tp.x][tp.y]), '0', 'P');
		}
		else if (game->map[tp.x][tp.y] == 'N')
			end_game(game, 0);
		else if (game->map[tp.x][tp.y] == 'E')
		{
			if (game->lay->coll == 0)
				end_game(game, 1);
		}
		update_moves(game, tp);
		ft_printf("Moves : %d\n", game->moves);
		render_map(game);
	}
}
