/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:20:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/07 10:08:43 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*str;

	if (!src)
		return (NULL);
	src_len = ft_strlen(src);
	str = malloc(sizeof(char) * src_len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, src, src_len + 1);
	str[src_len] = '\0';
	return (str);
}
