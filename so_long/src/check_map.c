/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:25:52 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/29 12:47:19 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_layout(char *line, t_check *err_check, t_lay *lay, int is_wall)
{
	if (!lay->col)
		lay->col = ft_strlen(line) - 1;
	if (lay->col && ((lay->col != (int)ft_strlen(line) - 1 && ft_strchr(line,
					'\n')) || (lay->col != (int)ft_strlen(line)
				&& !ft_strchr(line, '\n'))))
		err_check->inv_row = 1;
	if (!err_check->inv_row && (line[0] != '1' || line[lay->col - 1] != '1'
			|| (is_wall && count_chars(line, '1') != lay->col)))
		err_check->inv_walls = 1;
	lay->coll += count_chars(line, 'C');
	lay->exit += count_chars(line, 'E');
	lay->play += count_chars(line, 'P');
	err_check->inv_exit = lay->exit != 1;
	err_check->inv_play = lay->play != 1;
	err_check->inv_coll = lay->coll < 1;
	while (line && *line)
	{
		if (!ft_strchr_sl("01CEPN", *line))
			err_check->inv_char = 1;
		line++;
	}
}

void	get_line(char **line, char **p_line, char ***map_str)
{
	if (*p_line)
		free(*p_line);
	*p_line = ft_strdup(*line);
	free(*line);
	*line = NULL;
	if (!**map_str)
		**map_str = ft_strdup(*p_line);
	else
		**map_str = ft_strjoin_gnl(**map_str, *p_line);
}

int	get_layout(int fd, t_check *err_check, t_lay *lay, char **map_str)
{
	char	*curr_line;
	char	*prev_line;

	curr_line = 0;
	prev_line = 0;
	while (1)
	{
		curr_line = get_next_line(fd);
		if (!curr_line)
		{
			if (!lay->col)
			{
				free(prev_line);
				print_error("Map is empty.", 0, *map_str);
			}
			check_layout(prev_line, err_check, lay, 1);
			free(prev_line);
			return (1);
		}
		get_line(&curr_line, &prev_line, &map_str);
		if (!*map_str)
			return (free(prev_line), 0);
		check_layout(prev_line, err_check, lay, !lay->col);
		lay->row++;
	}
}

char	**check_map(int fd, t_lay *lay)
{
	char	*map_str;
	char	**map;
	t_check	err_check;

	map = 0;
	map_str = 0;
	err_check = init_check();
	if (!get_layout(fd, &err_check, lay, &map_str))
		print_error("Memory allocation failed.", 0, map_str);
	print_map_error(err_check, map_str, lay);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		print_error("Memory allocation failed.", map, map_str);
	check_path(map, lay);
	return (map);
}

char	**check_args(int ac, char **av, t_lay *lay)
{
	int	fd;

	if (ac != 2)
		print_error("Invalid number of arguments.", 0, 0);
	if (ft_strcmp_sl(av[1], ".ber") != 0)
		print_error("Invalid file.", 0, 0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_error("File can't be opened.", 0, 0);
	return (check_map(fd, lay));
}
