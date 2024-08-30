/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:09:13 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/04 15:31:36 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	while (i-- > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	return (0);
}

int		ft_strrchr_index(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (s[i] == (char)c)
		return ((int)i);
	while (i-- > 0)
	{
		if (s[i] == (char)c)
			return ((int)i);
	}
	return (0);
}