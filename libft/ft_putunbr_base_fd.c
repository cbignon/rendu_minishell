/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:08:18 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:09:17 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_base_fd(unsigned int n, char *base, int fd)
{
	int				x;
	unsigned int	size;

	x = 0;
	size = ft_strlen(base);
	if (n > size - 1)
	{
		x += ft_putunbr_base_fd(n / size, base, fd);
		x += ft_putunbr_base_fd(n % size, base, fd);
	}
	else
		x += ft_putchar_fd(*(base + n), fd);
	return (x);
}
