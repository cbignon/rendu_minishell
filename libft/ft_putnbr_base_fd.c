/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:07:52 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:03:54 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_fd(int n, char *base, int fd)
{
	int	x;
	int	size;

	x = 0;
	size = ft_strlen(base);
	if (n == -2147483648)
	{
		x += ft_putchar_fd('-', fd);
		x += ft_putstr_fd("2147483648", fd);
		return (x);
	}
	if (n < 0)
	{
		x += ft_putchar_fd('-', fd);
		x += ft_putnbr_base_fd(-n, base, fd);
	}
	else if (n > size - 1)
	{
		x += ft_putnbr_base_fd(n / size, base, fd);
		x += ft_putnbr_base_fd(n % size, base, fd);
	}
	else
		x += ft_putchar_fd(*(base + n), fd);
	return (x);
}
