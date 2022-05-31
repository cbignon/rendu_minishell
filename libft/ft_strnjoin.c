/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrona <atron@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:27:57 by atrona            #+#    #+#             */
/*   Updated: 2021/10/18 13:27:57 by atrona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, unsigned int s1_size,
			char const *s2, unsigned int s2_size)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	i = s1_size + s2_size + 1;
	str = (char *)malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < s1_size)
		str[i++] = s1[j++];
	j = 0;
	while (j < s2_size)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
