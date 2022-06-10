/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:51:36 by atron             #+#    #+#             */
/*   Updated: 2021/06/02 14:37:57 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	x;

	if (!s)
		return (-1);
	x = ft_strlen(s);
	if (write(fd, s, x) == -1)
		ft_putendl_fd("Bad file descriptor!", 2);
	return (x);
}
