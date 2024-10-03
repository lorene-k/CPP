/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:57:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/03 18:09:23 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//check pos of angle on unit circle to adjust step
static int unit_circle(float angle, char c)
{
    if (c == 'x' && (angle > 0 && angle < M_PI))
        return (1);
    if (c == 'y' && (angle > (M_PI / 2) && angle < (3 * M_PI / 2)))
        return (1);
    return (0);
}

//get horizontal intersection
static float get_h_inter(t_game *game, float angle)
{
    float x_inter;
    float y_inter;
    float x_step;
    float y_step;
    // int pix;

    y_inter = floor(game->p_y / T_SIZE) * T_SIZE; //floor = rounded to nearest int
    x_inter = game->p_x + (y_inter - game->p_y) / tan(angle);
    y_step = T_SIZE;
    x_step = T_SIZE / tan(angle);
    // pix = check_inter //ensure that the intersection is inside a map grid
    if (x_step > 0 && unit_circle(angle, 'y') || x_step < 0 && unit_circle(angle, 'y'))
        x_step *= -1;
    // while (!wall_hit())
    {
        x_inter += x_step;
        y_inter += y_step;
    }
    return (sqrt(pow(x_inter - game->p_x, 2) + pow(y_inter - game->p_y, 2)));
}

    // - adjust steps according to player pos/angle (depending if facing down/right, down/left, up/left) <<

    // - To ensure that the intersection is inside a map grid, we will add a pixel every time we check for a wall hit
    //     > use pixel variable <<
    
    // - check if wall hit <<


double norm_angle(double x)
{
    x = fmod(x, 2 * M_PI);
    if (x < 0)
        x += 2 * M_PI;
    return (x);
}

void    cast_rays(t_game *game)
{
    int     i;
    double  h_inter;
    double  v_inter;

    i = -1;
    game->ray->angle = game->ply->angle - (game->ply->fov_rd / 2);
    while (++i < S_W)
    {
        game->ray->flg = 0;
        h_inter = get_h_inter(game, norm_angle(game->ray->angle));
        v_inter = get_v_inter(game, norm_angle(game->ray->angle));
        if (v_inter <= h_inter)
            game->ray->dist = v_inter;
        else
        {
            game->ray->dist = h_inter;
            game->ray->flg = 1;
        }
        // render(game);
        game->ray->angle += game->ply->fov_rd / S_W;
    }
}

// increment will be equal to the sum of the current angle and the field of view divided by the S_W

/*
0. CHECK UNIT CIRCLE
To rotate a point (x,y)(x,y) around the origin by an angle θθ, the new coordinates (x′,y′)(x′,y′) are computed using:
x′=x⋅cos⁡(θ)−y⋅sin⁡(θ)
x′=x⋅cos(θ)−y⋅sin(θ)
y′=x⋅sin⁡(θ)+y⋅cos⁡(θ)
y′=x⋅sin(θ)+y⋅cos(θ)

1. FIND ANGLE FOR FIRST RAY - OK
    - PA(p_x, p_y); angle; fov
    - angle = (PA/2) - (fov/2)

2. LOOP FOR EACH RAY - OK
    - fov = 60
    - cast S_W rays
    - i++ = curr (angle + fov) / S_W

3. GET HORIZONTAL INTERSECTION
    - calculate x & y pos for 1st intersection - OK
    - then, calculate x_step & y_step - OK
        > y_step = tile_size - OK
        > tile_size / tan(ray_angle) - OK

    - intersection points = (x_inter, y_inter) + use steps to move to next point - OK
        > y_inter = (p_y/tile_size) * tile_size - OK
        > x_inter= p_x + (y_inter - p_y) / tan(ray_angle) - OK

    - adjust steps according to player pos/angle (depending if facing down/right, down/left, up/left) <<

    - To ensure that the intersection is inside a map grid, we will add a pixel every time we check for a wall hit
        > use pixel variable - OK
    
    - then we just keep incrementing the intersection position by the steps and check if it hits the wall - OK

    - if wall : calculate the distance from the play_pos to intersect_pos - OK
        > find hypotenuse c :  c = sqrt(a^2 + b^2)
*/
