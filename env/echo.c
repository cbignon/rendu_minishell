/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:48:32 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/01 15:38:03 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

int	ft_count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	ft_echo(t_process *p)
{
	int		i;
	int		count;
	int		option;

	i = 1;
	option = 0;
	count = ft_count_args(p->args);
	printf("count =%d\n", count);
	while (i < count)
	{
		if (i == 1 && ft_str_equ(p->args[i], "-n"))
		{
			option = 1;
			i++;
		}
		if (p->args[i])
			ft_putstr_fd(p->args[i], p->std_out);
		if (i < (count - 1))
			ft_putchar_fd(' ', p->std_out);
		i++;
	}
	if (option == 0)
		ft_putchar_fd('\n', p->std_out);
}
