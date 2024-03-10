/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:06:10 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/09 10:21:24 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_map(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	tab = 0;
}

int	print_error(char *msg, char **map, char *str)
{
	if (map)
		clear_map(map);
	if (str)
		free(str);
	ft_printf("Error\n%s\n", msg);
	exit(0);
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

int	check_char(char *charset, char *str, t_lay *lay)
{
	int i;

	i = 0;
	while (i < (lay->col - 1))
	{
		if (!is_in_charset(charset, str[i]))
			return (0);
		i++;
	}
	if (str[lay->col] != '\n')
		return (0);
	return (1);
}