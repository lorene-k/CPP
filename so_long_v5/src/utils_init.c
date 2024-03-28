/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:51:00 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/28 16:43:13 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *msg, char **map, char *str)
{
	if (map)
		clear_map(map);
	if (str)
		free(str);
	str = NULL;
	ft_printf("Error\n%s\n", msg);
	exit(1);
}

t_lay	init_lay(void)
{
	t_lay	lay;

	lay.row = 0;
	lay.col = 0;
	lay.exit = 0;
	lay.coll = 0;
	lay.play = 0;
	return (lay);
}

t_check	init_check(void)
{
	t_check	check;

	check.inv_char = 0;
	check.inv_coll = 0;
	check.inv_exit = 0;
	check.inv_play = 0;
	check.inv_row = 0;
	check.inv_walls = 0;
	check.last_line = 0;
	return (check);
}

void	*put_img(t_game *g, char *path)
{
	return (mlx_xpm_file_to_image(g->mlx, path, &g->img.w, &g->img.h));
}

void	init_img(t_game *g)
{
	g->img.w = 32;
	g->img.h = 32;
	g->img.wall = put_img(g, "./imgs/wall.xpm");
	g->img.coll = put_img(g, "./imgs/coll.xpm");
	g->img.play = put_img(g, "./imgs/play.xpm");
	g->img.exit = put_img(g, "./imgs/exit.xpm");
	g->img.floor = put_img(g, "./imgs/floor.xpm");
	g->img.enem = put_img(g, "./imgs/enem.xpm");
	g->img.exit_open = put_img(g, "./imgs/exit_open.xpm");
	if (!g->img.wall || !g->img.coll || !g->img.play || !g->img.exit
		|| !g->img.floor || !g->img.enem || !g->img.exit_open)
		clear_images(g);
}
