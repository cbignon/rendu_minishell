/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_equ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:19:36 by cbignon           #+#    #+#             */
/*   Updated: 2022/02/11 16:51:33 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

int	ft_str_equ(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
