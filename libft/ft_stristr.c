/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stristr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:54:15 by atron             #+#    #+#             */
/*   Updated: 2021/06/09 15:42:30 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stristr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!s2[0])
		return (-1);
	i = 0;
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		while (s1[i] == s2[j] && s1[i] != '\0'
			&& s2[j] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0' && i - j < len)
			return (i);
		i -= j;
		i++;
	}
	return (-1);
}
