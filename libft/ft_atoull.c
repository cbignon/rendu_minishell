/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:07:14 by atron             #+#    #+#             */
/*   Updated: 2021/11/22 11:36:59 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"

uint64_t	ft_atoull(char *str)
{
	int			x;
	uint64_t	r;

	x = 0;
	r = 0;
	while (str[x] >= '0' && str[x] <= '9')
		r = r * 10 + str[x++] - '0';
	return (r);
}
