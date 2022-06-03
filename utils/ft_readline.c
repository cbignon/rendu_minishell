/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:10:12 by atron             #+#    #+#             */
/*   Updated: 2022/06/03 14:20:58 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils_internal.h"
#include <readline/readline.h>
#include <errno.h>

extern t_bool	g_int;

char	*clean_line(char *line)
{
	int		size;
	char	*res;

	size = ft_strclen(line, '\n');
	res = malloc_verify((size + 1) * sizeof(*line));
	ft_memcpy(res, line, size);
	res[size] = '\0';
	gc_delone((void **)&line, 0);
	return (res);
}

char	*ft_readline(char *prompt)
{
	char	*line;
	int		gnl_res;

	if (g_int)
		return (NULL);
	line = NULL;
	ft_putstr_fd(prompt, 1);
	gnl_res = get_next_line(0, &line);
	if (gnl_res == -1 && errno != EINTR)
		ft_printerr(2, NULL, NULL, "read stdin");
	if (!line)
		return (NULL);
	if (!*line)
	{
		ft_putchar_fd('\n', 1);
		return (NULL);
	}
	line = clean_line(line);
	return (line);
}
