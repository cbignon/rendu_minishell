/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:46:27 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 15:58:46 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!s2[0])
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		while (s1[i] == s2[j] && s1[i] != '\0'
			&& s2[j] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0' && i - j < len)
			return ((char *)s1 + (i - j));
		i -= j;
		i++;
	}
	return (NULL);
}
