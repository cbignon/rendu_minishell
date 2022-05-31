/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:10:12 by atron             #+#    #+#             */
/*   Updated: 2022/04/28 12:37:00 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readline(char *prompt)
{
	char	*line;
	int		len;

	line = NULL;
	ft_putstr_fd(prompt, 1);
	get_next_line(0, &line);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	line = (char *)move_to_gc((void **)&line, len + 1);
	if (!line)
		ft_exit("Read error!!!", 3, 2);
	line[len] = 0;
	return (line);
}
