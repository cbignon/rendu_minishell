/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putullnbr_base_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:28:49 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:09:47 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putullnbr_base_fd(uint64_t n, char *base, int fd)
{
	int			x;
	uint64_t	size;

	x = 0;
	size = ft_strlen(base);
	if (n > size - 1)
	{
		x += ft_putullnbr_base_fd(n / size, base, fd);
		x += ft_putullnbr_base_fd(n % size, base, fd);
	}
	else
		x += ft_putchar_fd(*(base + n), fd);
	return (x);
}
