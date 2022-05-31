/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:46:41 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:38:31 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, char const *set)
{
	size_t	x;

	x = 0;
	while (set[x])
	{
		if (set[x] == c)
			return (1);
		x++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	x;
	int		size;
	char	*start;
	char	*end;

	if (!s1 || !set)
		return (NULL);
	x = 0;
	while (check(s1[x], set))
		x++;
	if (!s1[x])
		return (ft_strdup(""));
	start = (char *)&(s1[x]);
	x = ft_strlen((char *)s1) - 1;
	while (check(s1[x], set))
		x--;
	end = (char *)&(s1[x]);
	size = (int64_t)end - (int64_t)start + 1;
	if (size < 0)
		size = 0;
	return (ft_strndup((char *)start, (size_t)size));
}

char	*ft_strtrim_cu(char const *s1, char const *set)
{
	size_t	x;
	int		size;
	char	*start;
	char	*end;

	if (!s1 || !set)
		return (NULL);
	x = 0;
	while (check(s1[x], set))
		x++;
	if (!s1[x])
		return (ft_strdup_cu(""));
	start = (char *)&(s1[x]);
	x = ft_strlen((char *)s1) - 1;
	while (check(s1[x], set))
		x--;
	end = (char *)&(s1[x]);
	size = (int64_t)end - (int64_t)start + 1;
	if (size < 0)
		size = 0;
	return (ft_strndup_cu((char *)start, (size_t)size));
}
