/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:22:53 by atron             #+#    #+#             */
/*   Updated: 2022/04/29 14:15:18 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

const char	*get_prompt(void)
{
	char	*pwd;
	char	*prompt;

	pwd = get_pwd();
	prompt = ft_strjoin_cu("\001\e[1m\e[92m\002minishell:", pwd);
	verify_ptr(prompt);
	prompt = ft_strjoin_cu(prompt, "> \001\e[0m\002");
	verify_ptr(prompt);
	gc_delone((void **)&pwd, 0);
	return (prompt);
}
