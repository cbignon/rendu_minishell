/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:15:11 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 15:58:46 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;

	if (!src)
		return (NULL);
	len = ft_strlen((char *)src);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, len + 1);
	return (dest);
}

char	*ft_strdup_cu(const char *src)
{
	size_t	len;
	char	*dest;

	if (!src)
		return (NULL);
	len = ft_strlen((char *)src);
	dest = (char *)malloc_verify((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, len + 1);
	return (dest);
}
