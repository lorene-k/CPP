/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:22:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/24 11:35:14 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00

# include "../mlx_linux/mlx.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/libft_src/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_lay
{
	int		row;
	int		col;
	int		exit;
	int		coll;
	int		play;
}			t_lay;

typedef struct s_check
{
	int		inv_char;
	int		inv_walls;
	int		inv_play;
	int		inv_exit;
	int		inv_coll;
	int		inv_row;
	int		last_line;
}			t_check;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_img
{
	int		width;
	int		height;
	void	*wall;
	void	*coll;
	void	*play;
	void	*exit;
	void	*exit_open;
	void	*floor;
	void	*enem;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_lay	*lay;
	char	**map;
	int		moves;
	t_point	play_pos;
}			t_game;

/* CHECK MAP */
void		check_layout(char *line, t_check *err_check, t_lay *lay,
				int is_wall);
void		check_last_line(char *line, t_check *err_check, t_lay *lay);
int			get_layout(int fd, t_check *err_check, t_lay *lay, char **map_str);
char		**check_map(int fd, t_lay *lay);
char		**check_args(int ac, char **av, t_lay *lay);

/* CHECK PATH */
char		**copy_map(char **map, t_point size);
char		**flood_fill(char **map, t_point size, t_point cur);
int			is_inv_exit(char **cpy, int i, int j);
void		fill_path(char **map, t_point size, t_point start);
void		check_path(char **map, t_lay *lay);

/* CLEAR */
void		clear_map(char **tab);
int			clear_game(t_game *game);
void		clear_images(t_game *game);

/* HANDLE MOVES */
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
int			on_keypress(int keysym, t_game *game);

/* INIT GAME */
void		display_img(t_game *game, int x, int y);
int			render_map(t_game *game);
void		display_all(t_game game);
void		init_game(char **map, t_lay *lay);

/* INIT STRUCTS */
t_lay		init_lay(void);
t_check		init_check(void);
void		init_img(t_game *game);

/* UPDATE */
void		update_moves(t_game *game, t_point target_pos);
void		update_pos(char *x, char *y, char a, char b);
void		update_game(t_game *game, t_point target_pos, int x, int y);

/* UTILS CHECK */
void		print_map_error(t_check err_check, char *map_str, t_lay *lay);
int			print_error(char *msg, char **map, char *str);
int			ft_strcmp_sl(char *s1, char *s2);
int			count_chars(char *str, char c);
int			ft_strchr_sl(char *s, char c);

#endif // SO_LONG_H