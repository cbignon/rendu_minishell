/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:34:59 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/03 14:13:40 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"
#include "core_internal.h"
#include "env.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

t_bool	g_int = FALSE;

char	*read_heredoc(t_redirect_type *val)
{
	char	*line;

	line = ft_readline(">");
	if (!line && errno == EINTR)
	{
		*val = 4;
		g_int = TRUE;
		return (NULL);
	}
	else if (!line)
	{
		ft_printerr(2, "warning", "here-document", " waited 'delim'");
		return (NULL);
	}
	return (line);
}

void	create_heredoc(t_process *p, int index, int heredoc_nb)
{
	char	*nb;
	char	*file1;
	char	*file2;
	char	*dir;

	nb = ft_itoa_cu(p->proc_index);
	file1 = ft_strjoin_cu(p->cmd, nb);
	gc_delone((void **)&nb, 0);
	nb = ft_itoa_cu(heredoc_nb);
	file2 = ft_strjoin_cu(file1, nb);
	gc_delone((void **)&file1, 0);
	gc_delone((void **)&nb, 0);
	dir = get_pwd();
	file1 = ft_strjoin_cu(dir, "/");
	p->redir[index].file = ft_strjoin_cu(file1, file2);
	gc_delone((void **)&file1, 0);
	gc_delone((void **)&file2, 0);
	gc_delone((void **)&dir, 0);
}

void	setup_heredocs(t_process *processes)
{
	int	index;

	index = 0;
	while (processes[index].val)
	{
		setup_heredoc(&processes[index]);
		index++;
	}
}

void	setup_heredoc(t_process *p)
{
	int		index;
	int		heredoc_nb;
	char	*file;
	char	*delim;
	int		fd;

	index = 0;
	heredoc_nb = 0;
	while (p->redir[index].type != NONE)
	{
		if (p->redir[index].type == STDIN_HEREDOC)
		{
			delim = p->redir[index].file;
			p->redir[index].quotes = is_quoted(delim);
			delim = skip_quotes(delim, 0);
			create_heredoc(p, index, heredoc_nb);
			fd = open(p->redir[index].file, O_CREAT | O_RDWR | O_TRUNC, 0777);
			file = get_stdin(delim, &p->redir[index].type, p->redir[index].quotes);
			ft_putstr_fd(file, fd);
			close(fd);
			gc_delone((void **)&delim, 0);
			heredoc_nb++;
		}
		index++;
	}
}
