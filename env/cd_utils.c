/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:43:00 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/03 14:02:53 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

t_bool	find_in_cdpath(char *path, char *name)
{
	DIR				*dir;
	struct dirent	*info;

	dir = opendir(path);
	if (!dir)
		return (FALSE);
	info = readdir(dir);
	while (info)
	{
		if (ft_str_equ(info->d_name, name))
		{
			closedir(dir);
			return (TRUE);
		}
		info = readdir(dir);
	}
	return (FALSE);
}

t_bool	is_absolute(const char *path)
{
	if (!path || path[0] != '/')
		return (FALSE);
	return (TRUE);
}

char	**get_relative(char *path)
{
	char	**res;
	char	**tmp;

	tmp = ft_split(path, '/');
	if (!tmp)
		return (NULL);
	res = malloc_verify(3 * sizeof(*res));
	res[2] = NULL;
	if (!ft_str_equ(tmp[0], "."))
		res[1] = ft_strdup_cu(tmp[0]);
	else if (tmp[1])
	{
		res[1] = ft_strdup_cu(tmp[1]);
		res[0] = ft_strdup_cu(path + 2);
	}
	return (res);
}
