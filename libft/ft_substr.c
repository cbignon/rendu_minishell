/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:13:40 by atron             #+#    #+#             */
/*   Updated: 2021/05/06 15:59:50 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	return (ft_strndup(&(s[start]), len));
}

char	*ft_substr_cu(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *)s))
		return (ft_strdup_cu(""));
	return (ft_strndup_cu(&(s[start]), len));
}
