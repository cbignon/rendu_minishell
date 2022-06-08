/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:42:01 by atron             #+#    #+#             */
/*   Updated: 2021/05/11 11:27:46 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	str = (char *)malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_free_cu(char const *s1, char const *s2,
	int (del)(void **, int))
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	str = (char *)malloc_verify(sizeof(char) * i);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	del((void **)&s1, 0);
	del((void **)&s2, 0);
	return (str);
}

char	*ft_strjoin_cu(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	str = (char *)malloc_verify(sizeof(char) * i);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_tabjoin(char **tab, unsigned int tab_size, unsigned int str_size)
{
	char			*str;
	unsigned char	x;
	unsigned char	y;
	unsigned char	z;

	x = 0;
	z = 0;
	str = (char *)malloc(tab_size * str_size * sizeof(unsigned char) + 1);
	if (!str)
		return (NULL);
	while (x < str_size)
	{
		y = 0;
		while (y < str_size)
			str[z++] = tab[x][y++];
		x++;
	}
	str[z] = '\0';
	return (str);
}

char	*ft_tabjoin_cu(char **tab, unsigned int tab_size, unsigned int str_size)
{
	char			*str;
	unsigned char	x;
	unsigned char	y;
	unsigned char	z;

	x = 0;
	z = 0;
	str = (char *)malloc_verify(tab_size * str_size * sizeof(unsigned char) + 1);
	if (!str)
		return (NULL);
	while (x < str_size)
	{
		y = 0;
		while (y < str_size)
			str[z++] = tab[x][y++];
		x++;
	}
	str[z] = '\0';
	return (str);
}
