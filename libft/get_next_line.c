/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:36:10 by atron             #+#    #+#             */
/*   Updated: 2021/06/09 15:52:10 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_def.h"

static int	check_endl(char *line, int size)
{
	int	x;

	if (!line)
		return (3);
	x = 0;
	while (x < size)
	{
		if (line[x] == '\n')
			return (1);
		else if (line[x] == '\0')
			return (2);
		x++;
	}
	return (0);
}

static char	*accumulate(char *s1, char *s2)
{
	char	*result;
	size_t	size;

	if (!s2)
		return (s1);
	if (s1)
		size = ft_strclen(s1, 0) + BUFFER_SIZE + 1;
	else
		size = BUFFER_SIZE + 1;
	result = (char *)ft_calloc_init_cu(size, 0, sizeof(char));
	if (!result)
		return (NULL);
	if (s1)
	{
		ft_memcpy((void *)result, (void *)s1, ft_strclen(s1, 0));
		ft_memcpy((void *)(result + ft_strclen(s1, 0)), s2, BUFFER_SIZE);
	}
	else
		ft_memcpy((void *)result, (void *)s2, BUFFER_SIZE);
	gc_delone((void **)&s1, 0);
	result[size - 1] = '\0';
	return (result);
}

static char	*get_save(char *s1, size_t len)
{
	char	*temp;
	char	*result;

	temp = s1 + ft_strclen(s1, '\n') + 1;
	result = (char *)ft_calloc_init_cu(len + 1, 0, sizeof(char));
	if (!(ft_memcpy(result, temp, len)))
		return (NULL);
	result[len] = '\0';
	gc_delone((void **)&s1, 0);
	return (result);
}

static int	verifyandsave(char **save, char **line)
{
	size_t		size;
	int			res;

	res = check_endl(*save, ft_strclen(*save, 0) + 1);
	size = ft_strclen(*save, '\n') + 1;
	*line = (char *)ft_calloc_init_cu(size + 1, 0, sizeof(char));
	if (!*line)
		return (-1);
	ft_memcpy(*line, *save, size);
	*save = get_save(*save, ft_strclen(*save, 0) - (size - 1));
	if (!*save)
	{
		gc_delone((void **)line, 0);
		return (gc_delone((void **)save, -1));
	}
	(*line)[size] = '\0';
	if (res == 2)
		return (gc_delone((void **)save, 0));
	else if (res == 3)
		return (-1);
	else
		return (1);
}

int	get_next_line(char fd, char **line)
{
	char			*rd;
	static char		*save;

	rd = (char *)ft_calloc_init_cu(BUFFER_SIZE, 1, sizeof(char));
	if (!line || !rd || fd == -1 || BUFFER_SIZE <= 0)
		return (-1);
	while (!check_endl(rd, BUFFER_SIZE))
	{
		ft_memset(rd, 0, BUFFER_SIZE);
		if ((read(fd, (void *)rd, BUFFER_SIZE)) == -1)
			return (gc_delone((void **)&rd, -1));
		save = accumulate(save, rd);
		if (!save)
			return (-1);
	}
	gc_delone((void **)&rd, 0);
	if (save)
		return (verifyandsave(&save, line));
	return (-1);
}
