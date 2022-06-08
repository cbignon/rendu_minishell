/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:35:07 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 16:03:54 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_count(int n, size_t *size)
{
	if (n < 0)
	{
		(*size)++;
		ft_num_count(-n, size);
	}
	else if (n > 9)
	{
		ft_num_count(n / 10, size);
		ft_num_count(n % 10, size);
	}
	else
		(*size)++;
	return (*size);
}

static char	*ft_num_str(int n, char *str, size_t *index)
{
	if (n < 0)
	{
		str[*index] = '-';
		(*index)++;
		ft_num_str(-n, str, index);
	}
	else if (n > 9)
	{
		ft_num_str(n / 10, str, index);
		(*index)++;
		ft_num_str(n % 10, str, index);
	}
	else
		str[*index] = '0' + n;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	size_t	index;

	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648\0");
		return (str);
	}
	else
	{
		size = 0;
		index = 0;
		ft_num_count(n, &size);
		str = (char *)malloc(sizeof(char) * (size + 1));
		if (!str)
			return (NULL);
		ft_num_str(n, str, &index);
		str[index + 1] = '\0';
	}
	return (str);
}

char	*ft_itoa_cu(int n)
{
	char	*str;
	size_t	size;
	size_t	index;

	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648\0");
		return (str);
	}
	else
	{
		size = 0;
		index = 0;
		ft_num_count(n, &size);
		str = (char *)malloc_verify(sizeof(char) * (size + 1));
		if (!str)
			return (NULL);
		ft_num_str(n, str, &index);
		str[index + 1] = '\0';
	}
	return (str);
}
