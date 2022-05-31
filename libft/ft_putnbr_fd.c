/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:00:18 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:03:54 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	x;

	x = 0;
	if (n == -2147483648)
	{
		x += ft_putchar_fd('-', fd);
		x += ft_putstr_fd("2147483648", fd);
		return (x);
	}
	if (n < 0)
	{
		x += ft_putchar_fd('-', fd);
		x += ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		x += ft_putnbr_fd(n / 10, fd);
		x += ft_putnbr_fd(n % 10, fd);
	}
	else
		x += ft_putchar_fd(n + '0', fd);
	return (x);
}
