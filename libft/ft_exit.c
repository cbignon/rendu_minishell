/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:54:25 by atron             #+#    #+#             */
/*   Updated: 2022/04/20 16:14:45 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

void	ft_exit(char *message, int return_value, int fd)
{
	if (message)
		ft_putendl_fd(message, fd);
	exit(gc_clear(return_value));
}
