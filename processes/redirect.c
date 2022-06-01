/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:12:19 by atron             #+#    #+#             */
/*   Updated: 2022/06/01 10:16:13 by atron            ###   ########.fr       */
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
