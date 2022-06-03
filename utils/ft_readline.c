/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:10:12 by atron             #+#    #+#             */
/*   Updated: 2022/06/02 15:01:05 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils_internal.h"
#include <readline/readline.h>
#include <errno.h>

char	*clean_line(char *line)
{
	int		size;
	char	*res;

	size = ft_strclen(line, '\n');
	res = malloc_verify((size + 1) * sizeof(*line));
	//printf("res: %p\n", res);
	ft_memcpy(res, line, size);
	res[size] = '\0';
	gc_delone((void **)&line, 0);
	return (res);
}

char	*ft_readline(char *prompt)
{
	char	*line;
	//int		len;

	line = NULL;
	ft_putstr_fd(prompt, 1);
	if (get_next_line(0, &line) == -1 && errno != EINTR)
		ft_printerr(2, NULL, NULL, "read stdin");
	if (!line)
		return (NULL);
	if (!*line)
	{
		ft_putchar_fd('\n', 1);
		return (NULL);
	}
	line = clean_line(line);
	//len = ft_strlen(line);
	//line = (char *)move_to_gc((void **)&line, len + 1);
	//if (!line)
	//	ft_exit("Read error!!!", 3, 2);
	//line[len] = 0;
	return (line);
}
