/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_extend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:33:04 by atron             #+#    #+#             */
/*   Updated: 2021/05/19 19:44:21 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_extend(char *str, int dest_size)
{
	char	*dest;
	int		str_size;

	if (!str)
		return (NULL);
	str_size = ft_strlen(str);
	if (dest_size < str_size)
		return (NULL);
	dest = (char *)malloc(sizeof(*dest) * dest_size + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, str, str_size);
	while (str_size < dest_size)
		dest[str_size++] = ' ';
	dest[str_size] = '\0';
	return (dest);
}

char	*ft_str_extend_cu(char *str, int dest_size,
	t_gc **gc)
{
	char	*dest;
	int		str_size;

	if (!str)
		return (NULL);
	str_size = ft_strlen(str);
	if (dest_size < str_size)
		return (NULL);
	dest = (char *)malloc_verify(sizeof(*dest) * dest_size + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, str, str_size);
	while (str_size < dest_size)
		dest[str_size++] = ' ';
	dest[str_size] = '\0';
	return (dest);
}
