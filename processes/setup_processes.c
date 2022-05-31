/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:03:40 by atron             #+#    #+#             */
/*   Updated: 2022/05/11 15:35:31 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes_internal.h"

t_redirect_type	get_redirect_type(char *str)
{
	t_redirect_type	type;
	int				index;
	int				len;
	int				char_count;

	len = ft_strlen(str);
	char_count = get_trailing_count(str);
	index = len - 1;
	type = NONE;
	if (str[index] == '<' && char_count == 2)
		type = STDIN_HEREDOC;
	else if (str[index] == '<' && char_count == 1)
		type = STDIN_ALL;
	else if (str[index] == '>' && char_count == 1)
		type = STDOUT_OVERWRITE;
	else if (str[index] == '>' && char_count == 2)
		type = STDOUT_APPEND;
	return (type);
}

void	setup_num(t_redirect redir, char **args, int index_2)
{
	if (redir.type == STDIN_ALL
		|| redir.type == STDIN_HEREDOC)
		ft_atoi(args[index_2], &redir.from_fd);
	else
		ft_atoi(args[index_2], &redir.to_fd);
}

t_redirect	*get_redirections(char **args, int index_1, int index_2)
{
	t_redirect	*redir;
	int			size;

	size = get_redir_count(args);
	redir = (t_redirect *)malloc_verify(sizeof(t_redirect) * (size + 1));
	while (index_1 < size && args[index_2])
	{
		if (!is_redir(args[index_2]))
		{
			index_2++;
			continue ;
		}
		redir[index_1].type = get_redirect_type(args[index_2]);
		redir[index_1].file = args[index_2 + 1];
		redir[index_1].to_fd = 1;
		redir[index_1].from_fd = 0;
		if (ft_isdigit((int)args[index_2][0]))
			setup_num(redir[index_1], args, index_2);
		if (args[index_2] && args[index_2 + 1])
			index_2 += 2;
		index_1++;
	}
	redir[index_1].type = NONE;
	return (redir);
}

/******************************************************************************/

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
	//printf("args: %p\n", args);
	//args = expand_args(args);
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
	commands = ft_split(cmd, '|');
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
