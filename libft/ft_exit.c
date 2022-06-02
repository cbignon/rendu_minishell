/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:54:25 by atron             #+#    #+#             */
/*   Updated: 2022/06/01 09:57:24 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

void	ft_exit(char *message, int return_value, int fd)
{
	if (message)
		ft_putendl_fd(message, fd);
	//rl_clear_history();
	exit(gc_clear(return_value));
}
