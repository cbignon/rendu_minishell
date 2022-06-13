/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:44:05 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/13 09:31:41 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"
#include "env.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

static void	formatting_line(char **out, char **line)
{
	if (!*out)
	{
		*out = *line;
		*out = ft_strjoin_free_cu(*out, "\n", gc_delone);
	}
	else
	{
		*out = ft_strjoin_free_cu(*out, *line, gc_delone);
		*out = ft_strjoin_free_cu(*out, "\n", gc_delone);
	}
}

char	*get_stdin(char *delim, int *val, t_bool quoted)
{
	char	*out;
	char	*line;

	out = NULL;
	line = NULL;
	while (TRUE)
	{
		line = read_heredoc(val);
		if (!line)
			return (NULL);
		if (!quoted)
			line = get_expanded_line(line);
		if (ft_str_equ(delim, line))
		{
			gc_delone((void **)&line, 0);
			break ;
		}
		formatting_line(&out, &line);
	}
	return (out);
}

int	setup_options(t_process *p, int *index, int *fd, int *stdfd)
{
	int	options;

	options = 0;
	if (p->redir[*index].type == STDOUT_APPEND)
		options |= O_CREAT | O_APPEND | O_WRONLY;
	else if (p->redir[*index].type == STDOUT_OVERWRITE)
		options |= O_CREAT | O_TRUNC | O_WRONLY;
	else if (p->redir[*index].type == STDIN_ALL
		|| p->redir[*index].type == STDIN_HEREDOC)
		options |= O_RDONLY;
	*fd = open(p->redir[*index].file, options, 0777);
	if (p->redir[*index].type == STDOUT_APPEND
		|| p->redir[*index].type == STDOUT_OVERWRITE)
		*stdfd = p->redir[*index].to_fd;
	else if (p->redir[*index].type == STDIN_ALL
		|| p->redir[*index].type == STDIN_HEREDOC)
		*stdfd = p->redir[*index].from_fd;
	return (options);
}

static void	setup_std(t_redirect *redir, t_process *p, int fd)
{
	if (redir->type == STDOUT_APPEND || redir->type == STDOUT_OVERWRITE)
		p->std_out = fd;
	else if (redir->type == STDIN_ALL || redir->type == STDIN_HEREDOC)
		p->std_in = fd;
	close(fd);
}

void	setup_redirect(t_process *p)
{
	int	fd;
	int	index;
	int	stdfd;

	index = 0;
	while (p->redir[index].type != NONE)
	{
		setup_options(p, &index, &fd, &stdfd);
		if (!ft_is_builtin(p->cmd) || p->proc_count > 1)
		{
			if (fd == -1 && errno == 13)
				ft_exit(NULL, ft_printerr(2, p->redir->file, NULL,
						"Permission denied"), 2);
			else if (fd == -1)
				ft_exit(NULL, ft_printerr(2, p->redir->file, NULL,
						"No such file or Directory"), 2);
			dup2(fd, stdfd);
			close(fd);
		}
		else if (ft_is_builtin(p->cmd) || p->proc_count == 1)
			p->std_out = fd;
		else
			setup_std(&p->redir[index], p, fd);
		index++;
	}
}
