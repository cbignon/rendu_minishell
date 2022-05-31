/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:45:34 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:03:54 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	x;

	x = 0;
	while ((unsigned)s1[x] == (unsigned)s2[x] && ((unsigned)s1[x] != '\0'
			|| (unsigned)s2[x] != '\0'))
		x++;
	x--;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0)
		return (0);
	while ((unsigned)s1[x] == (unsigned)s2[x] && ((unsigned)s1[x] != '\0'
			|| (unsigned)s2[x] != '\0') && x < n)
	{
		if (x == n - 1)
			return (0);
		x++;
	}
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
