/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:44:21 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/02 13:14:56 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "processes.h"
# include "struct_env.h"

char	*ft_getenv(char *name, t_process *p);
t_env	*ft_get_environ(void);
void	exit_builtin(t_process *p);
void	ft_export(t_process *p);
void	ft_unset(t_process *p);
void	ft_env(t_process *p);
void	ft_pwd(t_process *p);
void	ft_cd(t_process *p);
void	ft_echo(t_process *p);
char	*ft_get_expanded_cmd(char *cmd);
char	***choose_env(t_process *p);
char	*get_pwd(void);
char	*skip_quotes(char *str, int index);
int		is_var_in_env(char **env, char *var);
void	modify_var_in_env(char ***env, char *var_name, char *new_value);
void	ft_add_to_env(char ***env, char *var_name, char *var_value);
void	ft_dup_environ(t_process *p);
int		ft_str_has_char(char *str, char c);
char	*get_pwd(void);
char	*get_expanded_line(char *line);
int		is_quoted(char *str);

#endif
