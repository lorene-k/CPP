/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CHECK_check_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:39:30 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/14 17:31:13 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **copy_map(char **map, t_point size)
{
    int     i;
    char    **cpy;

    i = 0;
    cpy = malloc(sizeof(char *) * (size.x + 1));
    if (!cpy)
        print_error("Memory allocation failed.", map, 0);
    cpy[size.x] = 0;
    while (i < size.x)
    {
        cpy[i] = ft_strdup((const char *)map[i]);
        if (!cpy[i])
        {
            clear_map(cpy);
            print_error("Memory allocation failed.", map, 0);
        }
        i++;
    }
    return (cpy);
}

char    **flood_fill(char **map, t_point size, t_point cur)
{
    if (cur.x < 0 || cur.x >= size.x ||  cur.y < 0 || cur.y >= size.y || map[cur.x][cur.y] == 'F')
        return (map);
    
    map[cur.x][cur.y] = 'F';

    if (map[cur.x - 1][cur.y] == '0' || map[cur.x - 1][cur.y] == 'P' || map[cur.x - 1][cur.y] == 'C'
        || map[cur.x - 1][cur.y] == 'E')
        flood_fill(map, size, (t_point){cur.x - 1, cur.y});
    if (map[cur.x + 1][cur.y] == '0' || map[cur.x + 1][cur.y] == 'P' || map[cur.x + 1][cur.y] == 'C'
        || map[cur.x - 1][cur.y] == 'E')
        flood_fill(map, size, (t_point){cur.x + 1, cur.y});
    if (map[cur.x][cur.y - 1] == '0' || map[cur.x][cur.y - 1] == 'P' || map[cur.x][cur.y - 1] == 'C'
        || map[cur.x - 1][cur.y] == 'E')
        flood_fill(map, size, (t_point){cur.x, cur.y - 1});
    if (map[cur.x][cur.y + 1] == '0' || map[cur.x][cur.y + 1] == 'P' || map[cur.x][cur.y + 1] == 'C'
        || map[cur.x - 1][cur.y] == 'E')
        flood_fill(map, size, (t_point){cur.x, cur.y + 1});
    return (map);
}

/* check filled path */ // if exit = wall : check si un char F est present pres de exit
void fill_path(char **map, t_point size, t_point start)
{
    char **cpy;
    int i;
    int j;

    i = 0;
    j = 0;
    cpy = copy_map(map, size);
    flood_fill(cpy, size, start);
    while (map[i])
	    printf("%s", map[i++]);
    printf("\n");
    while (cpy[j])
	    printf("%s", cpy[j++]);
    printf("\n");
    i = 0;
    while (i < size.x)
    {
        j = 0;
        while (j < size.y)
        {
            if (cpy[i][j] == 'C' || cpy[i][j] == 'E' || cpy[i][j] == 'P')
            {
                clear_map(cpy);
                print_error("Invalid path.", map, 0);
            }
            j++;
        }
        i++;
    }
    clear_map(cpy);
}

/* get start & size */
void    check_path(char **map, t_lay *lay)
{
    t_point size;
    t_point start;
    int i;
    int j;
    
    i = 0;
    j = 0;
    size.x = lay->row;
    size.y = lay->col;
    while (map[i][j] != 'P' && i < size.x)
    {
        j = 0;
        while (j < size.y)
        {
            if (map[i][j] == 'P')
            {
                start.x = i;
                start.y = j;
                fill_path(map, size, start);
                return ;
            }
            j++;
        }
        i++;
    }
}
