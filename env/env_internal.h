/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:48:45 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/02 17:48:03 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_INTERNAL_H
# define ENV_INTERNAL_H

# include "processes.h"
# include "env.h"
# include "utils.h"
# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>

/*******************************************************************************
 * EXIT.C 
 */
void	exit_builtin(t_process *p);

/*******************************************************************************
 * ENVIRON.C
 * create or duplicate environ according to the process status (child or parent)
 */
t_env	*ft_get_environ(void);
void	ft_dup_environ(t_process *p);
char	***choose_env(t_process *p);

/*******************************************************************************
 * ENV.C 
 */
void	ft_env(t_process *p);

/*******************************************************************************
 * EXPORT.C 
 */
void	ft_export(t_process *p);
void	modify_var_in_env(char ***env, char *var_name, char *new_value);
void	ft_add_to_env(char ***env, char *var_name, char *var_value);
void	ft_print_sorted_env(int std_out, int std_err, char **env);

/******************************************************************************
 * UNSET.C 
 */
void	ft_unset(t_process *p);
void	ft_remove_var(char ***env, char *var);

/*******************************************************************************
 * ECHO.C 
 */
void	ft_echo(t_process *p);
int		ft_count_args(char **args);

/*******************************************************************************
 * PWD.C 
 */
void	ft_pwd(t_process *p);
void	set_pwd(char *pwd, char ***env);
void	set_old_pwd(char *pwd, char ***env);
char	*get_pwd(void);

/*******************************************************************************
 * CD.C 
 */
int		ft_change_dir(int std_err, char *dirname);
int		ft_cd_home(t_process *p);
int		ft_cd_oldpath(t_process *p);
void	ft_cd(t_process *p);

/*******************************************************************************
 * PARSE_CMD_DOLLAR.C 
 */
char	*ft_get_expanded_cmd(char *cmd);
void	keep_invalid_dollar(char *str, int *i, int *j, char *to_keep);
void	to_expand_dollar(char *str, int *i, char *to_expand, int *j);

/*******************************************************************************
 * EXPAND_PARSER.C 
 */
char	*parse_dollar(char *str, int i, int j, char *full);
void	to_keep_simple_quote(char *str, int *i, int *j, char *to_keep);
void	to_keep_double_quote(char *str, int *i, char *to_keep, int *k);
void	to_keep_no_doll(char *str, int *i, char *to_keep, int *j);
int		*get_dble_option(void);

/*******************************************************************************
 * HEREDOC_EXPANSION.C 
 */
char	*parse_dollar_line(char *str, int i, int j, char *full);
void	keep_invalid_dollar_line(char *str, int *i, int *k, char *to_keep);
char	*get_expanded_line(char *line);

/*******************************************************************************
 * DOLLAR_UTILS.C 
 */
int		get_dollar_len(char *str, int start);
int		count_dollar(char *str, int size);
int		count_dollar_protect(char *s);
int		ft_str_has_char(char *str, char c);
int		ft_is_valid_var_char(char c);

/*******************************************************************************
 * EXPAND_UTILS.C 
 */
char	*ft_expand(char *str, int j, int i);
char	*substitute_not_in_env(char *str);
char	*ft_accumulate(char *full, char *to_expand, char *to_keep, int *k);
int		check_var_name(char *str);

/*******************************************************************************
 * FT_SPLIT_SPACE_PROTECT.C 
 */
char	**split_protect_quoted(char *str, char c);

/*******************************************************************************
 * SPLIT_PROTECT_UTILS.C 
 */
int		count_words_protected(char *str, char c, int count, int i);

/*******************************************************************************
 * VAR_UTILS.C 
 */
int		parse_var_name(char *var_name);
char	*get_var_name(int std_err, char *var);
char	*get_var_value(char *var);

/*******************************************************************************
 * ENV_UTILS.C 
 */
int		is_var_in_env(char **env, char *var);
void	ft_print_env(char **env, int std_out);
char	*ft_getenv(char *name, t_process *p);
int		search_in_env_global(char *str);
char	*get_value_from_global(char *var_name);

#endif
