/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:07:52 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:03:54 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	x;

	x = 0;
	if (n > 9)
	{
		x += ft_putunbr_fd(n / 10, fd);
		x += ft_putunbr_fd(n % 10, fd);
	}
	else
		x += ft_putchar_fd(n + '0', fd);
	return (x);
}
