/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:36:20 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:08:10 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				x;
	const unsigned char	*srctemp;
	unsigned char		*desttemp;

	x = 0;
	srctemp = (const unsigned char *)src;
	desttemp = (unsigned char *)dest;
	if (!dest && !src && n)
		return (dest);
	if (n == 0)
		return (NULL);
	while (x < n)
	{
		desttemp[x] = srctemp[x];
		if (srctemp[x] == (unsigned char)c)
			return ((void *)&(desttemp[x + 1]));
		x++;
	}
	return (NULL);
}
