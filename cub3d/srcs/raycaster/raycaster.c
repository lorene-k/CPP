/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:57:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/04 17:09:27 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// Adjust intersection check by 1 pixel according to angle
// to avoid missing walls that align exactly on the boundaries of grid cells
static int	check_inter(float angle, float *inter, float *step, int h)
{
	if (h)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += T_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > (M_PI / 2) && angle < (3 * M_PI / 2)))
		{
			*inter += T_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

static int	wall_hit(float x, float y, t_game *game)
{
	int	x_pos;
	int	y_pos;

	x_pos = floor(x / T_SIZE);
	y_pos = floor(y / T_SIZE);
	if (x < 0 || y < 0 || x_pos > game->w_map || y_pos > game->h_map)
		return (1);
	if (game->map[y_pos] && x_pos < ft_strlen(game->map[y_pos])
		&& game->map[y_pos][x_pos] == '1')
		return (1);
	return (0);
}

static float    get_v_inter(t_game *game, float angle)
{
    float	x_inter;
	float	y_inter;
	float	x_step;
	float	y_step;
	int		pix;

    x_inter = floor(game->p_y / T_SIZE) * T_SIZE;
	y_inter = game->p_x + (y_inter - game->p_y) / tan(angle);
    x_step = T_SIZE;
	y_step = T_SIZE / tan(angle);
    pix = check_inter(angle, &x_inter, &x_step, 0);
    if ((y_step > 0 && unit_circle(angle, 'h'))
        || (y_step < 0 && !unit_circle(angle, 'h')))
        y_step *= -1;
    while (!wall_hit(x_inter - pix, y_inter, game))
    {
        x_inter += x_step;
		y_inter += y_step;
    }
    return (sqrt(pow(x_inter - game->p_x, 2) + pow(y_inter - game->p_y, 2)));
}

// Get horizontal intersection
static float	get_h_inter(t_game *game, float angle)
{
	float	x_inter;
	float	y_inter;
	float	x_step;
	float	y_step;
	int		pix;

	y_inter = floor(game->p_y / T_SIZE) * T_SIZE;
	x_inter = game->p_x + (y_inter - game->p_y) / tan(angle);
	y_step = T_SIZE;
	x_step = T_SIZE / tan(angle);
	pix = check_inter(angle, &y_inter, &y_step, 1);
	if ((x_step > 0 && unit_circle(angle, 'y'))
        || (x_step < 0 && unit_circle(angle, 'y')))
		x_step *= -1;
	while (!wall_hit(x_inter, y_inter - pix, game))
	{
		x_inter += x_step;
		y_inter += y_step;
	}
	return (sqrt(pow(x_inter - game->p_x, 2) + pow(y_inter - game->p_y, 2)));
}

void	cast_rays(t_game *game)
{
	int		i;
	double	h_inter;
	double	v_inter;

	i = -1;
	game->ray->angle = game->ply->angle - (game->ply->fov_rd / 2);
	while (++i < S_W)
	{
		game->ray->h_flg = 0;
		h_inter = get_h_inter(game, norm_angle(game->ray->angle));
		v_inter = get_v_inter(game, norm_angle(game->ray->angle));
		if (v_inter <= h_inter)
			game->ray->dist = v_inter;
		else
		{
			game->ray->dist = h_inter;
			game->ray->h_flg = 1;
		}
		// render(game);
		game->ray->angle += game->ply->fov_rd / S_W;
	}
}
