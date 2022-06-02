/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:43:47 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/21 15:04:01 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

void	exit_builtin(t_process *p)
{
	int	count;

	count = ft_count_args(p->args);
	if (p->proc_count <= 1)
		ft_putendl_fd("exit", p->std_out);
	if (count > 2)
		p->res = ft_printerr(p->std_err, p->cmd, NULL,
				"too many arguments");
	else if (count == 2)
	{
		if (is_full_digit(p->args[1]))
			ft_atoi(p->args[1], &p->res);
		else
			ft_printerr(p->std_err, p->cmd, p->args[1],
				" numeric argument required");
	}
	rl_clear_history();
	ft_exit(NULL, p->res, 1);
}
