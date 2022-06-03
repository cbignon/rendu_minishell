/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:56:56 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/03 13:01:11 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

char	**ft_get_path(char **env)
{
	char	**tab_path;
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_start_with(env[i], "PATH="))
			path = ft_substr_cu(env[i], (ft_strclen(env[i], '=') + 1),
					ft_strlen(env[i]));
		i++;
	}
	if (!path)
		return (NULL);
	tab_path = ft_split(path, ':');
	return (tab_path);
}

char	*find_in_path(char **path, char *cmd)
{
	int				i;
	DIR				*dp;
	struct dirent	*dirp;

	i = 0;
	if (!path)
		return (NULL);
	dp = NULL;
	while (path[i])
	{
		while (!dp && path[i++])
			dp = opendir(path[i]);
		dirp = readdir(dp);
		while (dirp)
		{
			if (ft_str_equ(dirp->d_name, cmd) == 1)
				return (get_full_binpath(path[i], dp, dirp));
			dirp = readdir(dp);
		}
		closedir(dp);
		i++;
		if (path[i])
			dp = opendir(path[i]);
	}
	return (NULL);
}
