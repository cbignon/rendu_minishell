/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:26:05 by atron             #+#    #+#             */
/*   Updated: 2022/06/13 10:01:22 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **src, unsigned int src_size, unsigned int dest_size)
{
	char	*dest;

	if (!src || !*src)
		return (NULL);
	dest = (char *)malloc(dest_size);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, (const char *) *src, src_size);
	ft_free((void **)src, 0);
	*src = dest;
	return (dest);
}

void	*ft_realloc_cu(void **src, unsigned int src_size,
	unsigned int dest_size)
{
	char	*dest;

	if (!src || !*src)
		return (NULL);
	dest = (char *)malloc_verify(dest_size);
	ft_strlcpy(dest, (const char *) *src, src_size);
	gc_delone((void **)src, 0);
	*src = dest;
	return (dest);
}
