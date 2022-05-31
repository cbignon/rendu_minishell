/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:46:40 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 15:58:46 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	x;

	destlen = ft_strlen(dest);
	srclen = ft_strlen((char *)src);
	x = 0;
	if (size <= destlen)
		return (size + srclen);
	else
	{
		while (src[x] && destlen + x < size - 1)
		{
			dest[destlen + x] = src[x];
			x++;
		}
	}
	dest[destlen + x] = '\0';
	return (srclen + destlen);
}
