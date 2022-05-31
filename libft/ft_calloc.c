/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:08:34 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:27:27 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_init(size_t nmemb, int c, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, c, nmemb * size);
	return (ptr);
}

void	*ft_calloc_init_cu(size_t nmemb, int c, size_t size)
{
	void	*ptr;

	ptr = gc_malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, c, nmemb * size);
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	*ft_calloc_cu(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = gc_malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
