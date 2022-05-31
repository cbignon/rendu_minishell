/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:46:49 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:03:54 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	x;

	x = -1;
	if (c == '\0')
		return ((char *)(s + ft_strlen((char *)s)));
	while (s[++x] != '\0')
		if ((unsigned char)s[x] == c)
			return ((char *)&(s[x]));
	return (NULL);
}
