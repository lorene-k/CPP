/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:21:50 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/20 17:04:25 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;

	l_len = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	if (len == 0 && !big)
		return ((char *)little);
	while (*big && *little && len && l_len <= len)
	{
		if (ft_strncmp(big, little, l_len) == 0)
			return ((char *)big + (int)l_len);
		big++;
		len--;
	}
	return (NULL);
}

//l.27 modified for minishell : "+ l_len" added