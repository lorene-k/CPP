/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:06:10 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/29 12:32:34 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map_error(t_check err_check, char *map_str, t_lay *lay)
{
	if (lay->row > 40 || lay->col > 70)
		print_error("Invalid map size.", 0, map_str);
	if (err_check.inv_row)
		print_error("Map is not rectangular.", 0, map_str);
	if (err_check.inv_coll)
		print_error("Invalid number of collectibles.", 0, map_str);
	if (err_check.inv_exit)
		print_error("Invalid number of exits.", 0, map_str);
	if (err_check.inv_play)
		print_error("Invalid number of players.", 0, map_str);
	if (err_check.inv_walls)
		print_error("Invalid walls.", 0, map_str);
	if (err_check.inv_char)
		print_error("Invalid character(s).", 0, map_str);
}

int	ft_strcmp_sl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	int		res;

	i = 0;
	j = 0;
	res = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	while ((j > 0) && (i > 0) && (res == 0))
		res = (unsigned char)s1[--i] - (unsigned char)s2[--j];
	if (i == 0)
		return (1);
	return (res);
}

int	count_chars(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int	ft_strchr_sl(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	if (c == '\n')
		return (1);
	return (0);
}
