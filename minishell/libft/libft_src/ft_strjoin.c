/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:58:18 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/05 16:01:16 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	t_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (t_len + 1));
	if (!str)
		return (NULL);
	str[0] = 0;
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, (t_len + 1));
	str[t_len] = '\0';
	return (str);
}

char	*ft_strjoin_memory(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	t_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	t_len = len1 + len2;
	str = malloc(sizeof(char) * (t_len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, (len1));
	ft_memcpy((str + len1), s2, (len2 + 1));
	str[len1 + len2] = '\0';
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (str);
}