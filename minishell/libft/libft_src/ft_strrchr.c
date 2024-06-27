/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:09:13 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/27 12:45:57 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, char c)
{
	size_t	i;

	i = ft_strlen(s);
	if (s[i] == c)
		return ((char *)&s[i]);
	while (i-- > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	return (0);
}

// CHANGED FOR MINISHELL (before : cost char *s, int c)