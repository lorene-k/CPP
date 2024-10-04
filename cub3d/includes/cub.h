/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:22:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/04 17:10:02 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H

/* ------------  MACROS  --------------------------------------------------- */
# define S_W 1900
# define S_H 1000
# define T_SIZE 30 //tile size
# define FOV 60
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4

/* ------------  LIBRARIES  ------------------------------------------------ */
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft_src/libft.h"
# include "../mlx_linux/mlx.h"
# include "../libft/ft_printf/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* ------------  STRUCTS  -------------------------------------------------- */
typedef struct s_player
{
	int         x; // in px
	int         y; // in px
	double		angle;
	float		fov_rd;
	int         rot; // rotation flag
	int         l_r; // left right flag
	int         u_d; // up down flag
}				t_player;

typedef struct s_ray
{
	double		angle;
	double		dist;
	int			h_flg;
}				t_ray;

typedef struct s_game
{
	char		**map;
	int			p_x;
	int			p_y;
	int			w_map;
	int			h_map;
	mlx_image_t	*img;
	mlx_t		*mlx_p;
	t_ray		*ray;
	t_player	*ply;
}				t_game;

/* ------------  FUNCTIONS  ------------------------------------------------ */
/* RAYCASTER */
void    cast_rays(t_mlx *mlx);
int		unit_circle(float angle, char c);
double  norm_angle(double x);

#endif //CUB_H