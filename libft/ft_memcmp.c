/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:09:13 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:03:54 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0)
		return (0);
	while ((((unsigned char *)s1)[x] == ((unsigned char *)s2)[x]) && x < n - 1)
		x++;
	return ((int)(((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]));
}
