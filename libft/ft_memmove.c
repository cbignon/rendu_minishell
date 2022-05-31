/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:36:48 by atron             #+#    #+#             */
/*   Updated: 2021/05/07 13:31:01 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		x;
	char		*desttemp;
	char		*srctemp;

	if (!dest && !src)
		return (NULL);
	x = 0;
	desttemp = (char *)dest;
	srctemp = (char *)src;
	while (x < n)
	{
		desttemp[x] = srctemp[x];
		x++;
	}
	return ((void *)desttemp);
}
