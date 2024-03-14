/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:22:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/14 03:35:05 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# define WIDTH 800
# define HEIGHT 600

# include "../minilibx_linux/mlx.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/libft_src/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* CHECK LAYOUT */
typedef struct s_lay
{
	int		row;
	int		col;
	int		exit;
	int		coll;
	int		play;
}			t_lay;

/* CHECK VALID MAP */
typedef struct s_check
{
	int		inv_char;
	int		inv_walls;
	int		inv_play;
	int		inv_exit;
	int		inv_coll;
	int		inv_row;
}			t_check;

/* GET COORDINATES */
typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

/* IMG STRUCT */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

// typedef struct s_play
// {
// 	int pos_x;
// 	int pos_y;

// } t_play;

/*
typedef struct s_data
{
	void *mlx; // MLX pointer
	void *win; // MLX window pointer
	t_img	img;
	// void *textures[5];	// MLX image pointers (on the stack)
	// t_map *map;        // Map pointer (contains map details
			- preferably kept on the stack)
}			t_data;
*/
/* SUPPORT */

/* CHECK MAP */
int			get_layout(int fd, t_check *err_check, t_lay *lay, char **map_str);
void		check_layout(char *line, t_check *err_check, t_lay *lay,
				int is_wall);
void		check_layout(char *line, t_check *err_check, t_lay *lay,
				int is_wall);
void		print_map_error(t_check err_check, char *map_str);
char		**check_map(int fd, t_lay *lay);
char		**check_args(int ac, char **av, t_lay *lay);

/* CHECK PATH */
char		**copy_map(char **map, t_point size);
char		**flood_fill(char **map, t_point size, t_point cur);
void		fill_path(char **map, t_point size, t_point start);
void		check_path(char **map, t_lay *lay);

/* UTILS CHECK */
void		clear_map(char **tab);
int			print_error(char *msg, char **map, char *str);
int			ft_strcmp_sl(char *s1, char *s2);
int			count_chars(char *str, char c);
int			ft_strchr_sl(char *s, char c);

/* INIT STRUCTS */
t_lay		init_lay(void);
t_check		init_check(void);

#endif // SO_LONG_H