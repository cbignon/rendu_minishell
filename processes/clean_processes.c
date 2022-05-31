/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:52:10 by atron             #+#    #+#             */
/*   Updated: 2022/04/28 10:42:14 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes_internal.h"

void	clean_env(t_env **env)
{
	if (!*env)
		return ;
	ft_tabfree_cu((void ***)&(*env)->gl_env, ft_tablen((*env)->gl_env), 0);
	gc_delone((void **)env, 0);
}

void	clean_redirs(t_redirect *redirs)
{
	int	index;

	index = 0;
	while (redirs[index].type != NONE)
	{
		if (redirs[index].type == STDIN_HEREDOC)
			unlink(redirs[index].file);
		index++;
	}
}

void	clean_process(t_process *p)
{
	clean_env(&p->env);
	gc_delone((void **)&p->cmd, 0);
	ft_tabfree_cu((void ***)&p->args, ft_tablen(p->args), 0);
	clean_redirs(p->redir);
	gc_delone((void **)&p->redir, 0);
}

void	clean_processes(void)
{
	int			index;
	t_process	**p;

	p = get_processes(0);
	index = 0;
	if (!*p)
		return ;
	while ((*p)[index].val)
	{
		clean_process(&(*p)[index]);
		index++;
	}
	gc_delone((void **)p, 0);
}
