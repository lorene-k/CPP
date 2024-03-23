/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:33:37 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/23 15:26:03 by lkhalifa         ###   ########.fr       */
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

void update_game(t_game *game, t_point target_pos, int x, int y)
{
    if (game->map[target_pos.x][target_pos.y] != '1')
    {
        if (game->map[target_pos.x][target_pos.y] == '0') //floor
        {
            game->map[x][y] = '0';
            game->map[target_pos.x][target_pos.y] = 'P';
        }
        else if (game->map[target_pos.x][target_pos.y]  == 'C') //coll
        {
            game->lay->coll -= 1;
            game->map[x][y] = '0';
            game->map[target_pos.x][target_pos.y] = 'P';
        }
        else if (game->map[target_pos.x][target_pos.y]  == 'N') //enem
        {
            ft_printf("You have lost the game :(\n");
            clear_game(game);
        }
        else if (game->map[target_pos.x][target_pos.y]  == 'E') //exit
        {
            if (game->lay->coll == 0)
            {    
                game->map[target_pos.x][target_pos.y] = '0';
                game->map[x][y] = '0';
                ft_printf("You have won the game in %d moves!\n", game->moves);
                clear_game(game);
            }
        }
        game->moves++;
    }
}
