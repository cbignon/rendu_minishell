/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:22:53 by atron             #+#    #+#             */
/*   Updated: 2022/06/13 10:04:07 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

const char	*get_prompt(void)
{
	char	*pwd;
	char	*title;
	char	*prompt;

	pwd = get_pwd();
	title = ft_strdup_cu("\001\e[1m\e[92m\002minishell:");
	if (pwd)
		prompt = ft_strjoin_cu(title, pwd);
	else
		prompt = title;
	prompt = ft_strjoin_cu(prompt, "> \001\e[0m\002");
	gc_delone((void **)&pwd, 0);
	gc_delone((void **)&title, 0);
	return (prompt);
}
