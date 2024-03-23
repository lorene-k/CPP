/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:33:37 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/23 21:00:26 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(t_game *game)
{
    t_point target_pos;

    target_pos.x = game->play_pos.x - 1;
    target_pos.y = game->play_pos.y;
    update_game(game, target_pos, game->play_pos.x, game->play_pos.y);
}

void    move_down(t_game *game)
{
    t_point target_pos;

    target_pos.x = game->play_pos.x + 1;
    target_pos.y = game->play_pos.y;
    update_game(game, target_pos, game->play_pos.x, game->play_pos.y);
}

void    move_left(t_game *game)
{
    t_point target_pos;

    target_pos.x = game->play_pos.x;
    target_pos.y = game->play_pos.y - 1;
    update_game(game, target_pos, game->play_pos.x, game->play_pos.y);
}

void    move_right(t_game *game)
{
    t_point target_pos;

    target_pos.x = game->play_pos.x;
    target_pos.y = game->play_pos.y + 1;
    update_game(game, target_pos, game->play_pos.x, game->play_pos.y);
}

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