/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:04:10 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:08:27 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		x;
	const char	*srctemp;
	char		*desttemp;

	if (!dest && !src)
		return (NULL);
	x = 0;
	srctemp = (const char *)src;
	desttemp = (char *)dest;
	while (x < n)
	{
		desttemp[x] = srctemp[x];
		x++;
	}
	return ((void *)desttemp);
}
