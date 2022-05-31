/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:14:57 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 15:58:46 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	x;
	size_t	y;

	if (!dest || !src)
		return (0);
	x = 0;
	y = ft_strlen((char *)src);
	if (size == 0)
		return (y);
	while ((x < size - 1) && (src[x] != '\0'))
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (y);
}
