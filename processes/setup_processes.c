/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:03:40 by atron             #+#    #+#             */
/*   Updated: 2022/06/10 14:22:26 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes_internal.h"

char	**add_to_tab(char **tab_1, char	**tab_2)
{
	char	**res;
	int		size;
	int		index_1;
	int		index_2;

	res = NULL;
	size = ft_tablen(tab_1) + ft_tablen(tab_2) + 1;
	res = (char **)gc_malloc(sizeof(char *) * size);
	index_1 = -1;
	if (tab_1)
	{
		while (++index_1 < ft_tablen(tab_1))
			res[index_1] = tab_1[index_1];
	}
	index_2 = -1;
	if (tab_2)
	{
		while (++index_2 < ft_tablen(tab_2))
			res[index_1] = tab_2[index_2];
	}
	ft_tabfree_cu((void ***)&tab_1, ft_tablen(tab_1), 0);
	ft_tabfree_cu((void ***)&tab_2, ft_tablen(tab_2), 0);
	return (res);
}

char	**expand_args(char **args)
{
	char	**res;
	char	**temp_tab;
	char	*temp_str;
	int		index;

	index = 0;
	res = NULL;
	while (args && args[index])
	{
		if (is_redir(args[index]))
			index += 2;
		temp_str = ft_get_expanded_cmd(args[index]);
		gc_delone((void **)&args[index], 0);
		temp_tab = ft_split_args(temp_str);
		gc_delone((void **)&temp_str, 0);
		res = add_to_tab(res, temp_tab);
		gc_delone((void **)&args, 0);
		index++;
	}
	return (res);
}

t_process	setup_process(char *cmd)
{
	t_process	process;
	char		**args;

	args = ft_split_args(cmd);
	process.args = NULL;
	process.cmd = NULL;
	if (!cmd)
		return (process);
	process.args = get_real_args(args);
	process.cmd = ft_strdup_cu((const char *)process.args[0]);
	process.redir = get_redirections(args, 0, 0);
	process.pid = 0;
	process.std_in = 0;
	process.std_out = 1;
	process.std_err = 2;
	process.env = NULL;
	process.res = 0;
	process.val = TRUE;
	return (process);
}

t_process	*setup_processes(char *cmd)
{
	int			process_count;
	t_process	*processes;
	int			index;
	char		**commands;
	char		*tmp;

	index = 0;
	commands = ft_split_protec(cmd, '|');
	process_count = ft_tablen(commands);
	processes = *get_processes(process_count);
	if (!processes)
		return (NULL);
	while (commands[index])
	{
		tmp = ft_get_expanded_cmd(commands[index]);
		processes[index] = setup_process(tmp);
		processes[index].proc_count = process_count;
		processes[index].proc_index = index;
		index++;
	}
	processes[index].val = FALSE;
	return (processes);
}
