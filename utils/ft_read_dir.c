/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 09:33:11 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/22 16:05:38 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

int	count_files_in_dir(char *dir_name)
{
	DIR				*dp;
	struct dirent	*dirp;
	int				count;

	dp = opendir(dir_name);
	count = 0;
	if (dp != NULL)
	{
		dirp = readdir(dp);
		while (dirp != NULL)
		{
			count++;
			dirp = readdir(dp);
		}
		closedir(dp);
		return (count);
	}
	return (count);
}

char	**ft_read_dir(char *dir_name)
{
	DIR				*dp;
	struct dirent	*dirp;
	char			**files_list;
	int				i;

	if (!dir_name || !ft_is_dir(dir_name))
		return (NULL);
	dp = NULL;
	i = -1;
	dp = opendir(dir_name);
	files_list = NULL;
	files_list = (char **)malloc_verify(sizeof(char *)
			* (count_files_in_dir(dir_name) + 1));
	dirp = readdir(dp);
	while (dirp != NULL)
	{
		files_list[++i] = ft_strdup_cu(dirp->d_name);
		dirp = readdir(dp);
	}
	files_list[++i] = NULL;
	closedir(dp);
	return (files_list);
}

int	ft_is_dir(char *name)
{
	DIR	*dp;

	dp = NULL;
	dp = opendir(name);
	if (dp != NULL)
	{
		closedir(dp);
		return (1);
	}
	else
		return (0);
}
