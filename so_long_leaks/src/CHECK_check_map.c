

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:48:52 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/02/11 18:39:17 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map_error(t_check err_check, char **map)
{
	if (err_check.inv_row)
		print_error("Map is not rectangular.", map, 0);
	if (err_check.inv_coll)
		print_error("Invalid number of collectibles.", map, 0);
	if (err_check.inv_exit)
		print_error("Invalid number of exits.", map, 0);
	if (err_check.inv_play)
		print_error("Invalid number of players.", map, 0);
	if (err_check.inv_walls)
		print_error("Map is not surrounded by walls.", map, 0);
	if (err_check.inv_char)
		print_error("Invalid character(s).", map, 0);
}

/* Check if valid map */
void    check_layout(t_check *err_check, t_lay *lay, char **map)
{
	int i;

	i = 0;
	lay->col = ft_strlen(map[0]) - 1;
	if (count_chars(map[0], '1') != lay->col
		|| count_chars(map[lay->row - 1], '1') != lay->col)
		err_check->inv_walls = 1;
	while (i < lay->row)
	{
		if (lay->col < 3 || (int)ft_strlen(map[i]) - 1 != lay->col)
			err_check->inv_row = 1;
		if ((map[i][0] != '1') || (map[i][lay->col - 1] != '1'))
			err_check->inv_walls = 1;
		lay->coll += count_chars(map[i], 'C');
		lay->exit += count_chars(map[i], 'E');
		lay->play += count_chars(map[i], 'P');
		err_check->inv_exit = lay->exit != 1;
		err_check->inv_play = lay->play != 1;
		err_check->inv_coll = lay->coll < 1;
		if (!check_char("01CEP", map[i], lay))
			err_check->inv_char = 1;
		i++;
	}
}

/* concatenate map in a string */
char    *get_layout(int fd, char *map_str, t_lay *lay)
{
    char *curr_line;

    curr_line = 0;
    while (1)
    {
        curr_line = get_next_line(fd); // LEAK HERE
        if (!curr_line)
			break ;
		if (!map_str)
			map_str = ft_strdup(curr_line);
		else
			map_str = ft_strjoin(map_str, curr_line); //check if joined successful or protect it
		if (!map_str)
			return(free(curr_line), NULL);
		lay->row++;
		free(curr_line);
    }
	return (map_str);
}

/* check layout - create map */
char	**check_map(int fd, t_lay *lay)
{
	char	*map_str;
	char	**map;
	t_check	err_check;

	map = 0;
	map_str = 0;
	err_check = init_check();
	map_str = get_layout(fd, map_str, lay);
	if (!map_str)
		print_error("Memory allocation failed.", 0, 0);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		print_error("Memory allocation failed.", 0, 0);
	check_layout(&err_check, lay, map);
	print_map_error(err_check, map);
	check_path(map, lay);
	return (map);
}

/* check .ber - args - fd */
char    **check_args(int ac, char **av, t_lay *lay)
{
	int fd;
	
    if (ac != 2)
		print_error("Invalid number of arguments.", 0, 0);
	if (ft_strcmp_sl(av[1], ".ber") != 0)
		print_error("Invalid file.", 0, 0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_error("File can't be opened.", 0, 0);
	return (check_map(fd, lay));
}

/*
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position.

ERRORS : 
- duplicate E or P - OK
- absence of : E, P, C, 1, 0 - OK for : E P C 1
- square map - OK
- walls : char == 1 for (1, y) ; (x, 1) ; (size, y) ; (size ; x) - OK
- valid path : flood_fill <<< checks for 0
*/