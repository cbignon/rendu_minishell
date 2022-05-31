/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:36:26 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:08:17 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				x;
	const unsigned char	*srctemp;

	x = 0;
	srctemp = (const unsigned char *)s;
	while (x < n)
	{
		if (srctemp[x] == (unsigned char)c)
			return ((void *)&(srctemp[x]));
		x++;
	}
	return (NULL);
}
