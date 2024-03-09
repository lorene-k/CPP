

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

void	print_map_error(t_check err_check, char *map_str)
{
	if (err_check.inv_row)
		print_error("Map is not rectangular.", 0, map_str);
	if (err_check.inv_coll)
		print_error("Invalid number of collectibles.", 0, map_str);
	if (err_check.inv_exit)
		print_error("Invalid number of exits.", 0, map_str);
	if (err_check.inv_play)
		print_error("Invalid number of players.", 0, map_str);
	if (err_check.inv_walls)
		print_error("Map is not surrounded by walls.", 0, map_str);
	if (err_check.inv_char)
		print_error("Invalid character(s).", 0, map_str);
}

void    check_layout(char *line, t_check *err_check, t_lay *lay, int is_wall)
{
    if (!lay->col) // get first row length
        lay->col = ft_strlen(line) - 1;
    if (lay->col > 0 && line[lay->col - 1] != '1') //check rectangle map
		err_check->inv_row = 1;
	if ((line[0] != '1') || (line[lay->col - 1] != '1') //checks walls
		|| (is_wall && count_chars(line, '1') != lay->col))
		err_check->inv_walls = 1;
	lay->coll += count_chars(line, 'C');
	lay->exit += count_chars(line, 'E');
	lay->play += count_chars(line, 'P');
	err_check->inv_exit = lay->exit != 1; //check exit
	err_check->inv_play = lay->play != 1; //check player
	err_check->inv_coll = lay->coll < 1; //check collectibles
	while (line && *line)
	{
		if (!ft_strchr_sl("01CEP", *line))
			err_check->inv_char = 1;
		line++;
	}
}

int    get_layout(int fd, t_check *err_check, t_lay *lay, char **map_str)
{
    char *curr_line;
    char *prev_line;

    curr_line = 0;
    prev_line = 0;
    while (1)
    {
        curr_line = get_next_line(fd); // LEAK HERE
        if (!curr_line)
        {
            if (!lay->col)
				print_error("Map is empty.", 0, *map_str);
            else
                check_layout(prev_line, err_check, lay, 1);
            free(prev_line);
            return (1);
        }
		if (prev_line)
        	free(prev_line);
		prev_line = ft_strdup(curr_line);
		free(curr_line);
		if (!prev_line)
			return (0);
        check_layout(prev_line, err_check, lay, !lay->row);
		if (!map_str)
			*map_str = ft_strdup(prev_line);
		else
			*map_str = ft_strjoin(*map_str, prev_line);
		if (!map_str)
			return(free(prev_line), 0);
		lay->row++;
    }
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
	if (!get_layout(fd, &err_check, lay, &map_str))
		print_error("Memory allocation failed.", 0, map_str);
	print_map_error(err_check, map_str);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		print_error("Memory allocation failed.", map, 0);
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