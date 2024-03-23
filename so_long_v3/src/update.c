/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:54:51 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/23 21:09:27 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    update_moves(t_game *game, t_point target_pos)
{
    if (game->map[target_pos.x][target_pos.y] != 'E')
        game->moves += 1;
}

void    update_pos(char *x, char *y, char a, char b)
{
    *x = a;
    *y = b;
}

void update_game(t_game *game, t_point target_pos, int x, int y)
{
    if (game->map[target_pos.x][target_pos.y] != '1')
    {
        if (game->map[target_pos.x][target_pos.y] == '0') //floor
            update_pos(&(game->map[x][y]), &(game->map[target_pos.x][target_pos.y]), '0', 'P');
        else if (game->map[target_pos.x][target_pos.y]  == 'C') //coll
        {
            game->lay->coll -= 1;
            update_pos(&(game->map[x][y]), &(game->map[target_pos.x][target_pos.y]), '0', 'P');
        }
        else if (game->map[target_pos.x][target_pos.y]  == 'N') //enem
        {
            ft_printf("\033[31mLOSER\nYou have lost the game :(\n\033[0m");
            clear_game(game);
        }
        else if (game->map[target_pos.x][target_pos.y]  == 'E') //exit
        {
            if (game->lay->coll == 0)
            {    
                update_pos(&(game->map[x][y]), &(game->map[target_pos.x][target_pos.y]), '0', '0');
                ft_printf("\033[32mVICTORY\nYou have won the game in %d moves!\n\033[0m", game->moves);
                clear_game(game);
            }
        }
        update_moves(game, target_pos);
    }
}