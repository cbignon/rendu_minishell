/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:43:47 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:07:45 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

t_bool	is_full_digit(char *str)
{
	int	x;

	x = 0;
	if (str[x] == '-')
		x++;
	while (str[x])
		if (!ft_isdigit(str[x++]))
			return (FALSE);
	return (TRUE);
}
