/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:03:38 by atron             #+#    #+#             */
/*   Updated: 2022/04/28 11:12:57 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t len)
{
	char	*dest;

	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, len + 1);
	return (dest);
}

char	*ft_strndup_cu(const char *src, size_t len)
{
	char	*dest;

	dest = (char *)gc_malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, len + 1);
	return (dest);
}
