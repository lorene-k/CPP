/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:22:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/29 14:34:56 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H

/* ------------  MACROS  --------------------------------------------------- */
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00

/* ------------  LIBRARIES  ------------------------------------------------ */
# include "libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft_src/libft.h"
# include "../mlx_linux/mlx.h"

# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/time.h>
# include <unistd.h>

/* ------------  STRUCTS  -------------------------------------------------- */
// typedef struct s_lay
// {
// 	int		row;
// 	int		col;
// 	int		exit;
// 	int		coll;
// 	int		play;
// }			t_lay;

// typedef struct s_check
// {
// 	int		inv_char;
// 	int		inv_walls;
// 	int		inv_play;
// 	int		inv_exit;
// 	int		inv_coll;
// 	int		inv_row;
// 	int		last_line;
// }			t_check;

// typedef struct s_point
// {
// 	int		x;
// 	int		y;
// }			t_point;

// typedef struct s_img
// {
// 	int		w;
// 	int		h;
// 	void	*wall;
// 	void	*coll;
// 	void	*play;
// 	void	*exit;
// 	void	*exit_open;
// 	void	*floor;
// 	void	*enem;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }			t_img;

// typedef struct s_game
// {
// 	void	*mlx;
// 	void	*win;
// 	t_img	img;
// 	t_lay	*lay;
// 	char	**map;
// 	int		moves;
// 	t_point	play_pos;
// }			t_game;

/* ------------  FUNCTIONS  ------------------------------------------------ */


#endif //CUB_H
