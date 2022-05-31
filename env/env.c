/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:00:56 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/22 17:08:58 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

void	ft_env(t_process *p)
{
	char	***env;

	if (p->args[1])
	{
		ft_printerr(p->std_err, p->cmd, p->args[1], "Too many args");
		p->res = 1;
		return ;
	}
	env = choose_env(p);
	ft_print_env(*env, p->std_out);
}
