/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:14:16 by atron             #+#    #+#             */
/*   Updated: 2022/06/10 14:23:59 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESSES_H
# define PROCESSES_H

# include <sys/types.h>
# include "struct_env.h"
# include "libft.h"

typedef enum e_redirect_type
{
	STDOUT_OVERWRITE,
	STDOUT_APPEND,
	STDIN_ALL,
	STDIN_HEREDOC,
	STOPPED_HEREDOC,
	NONE = -1
}	t_redirect_type;

typedef struct s_redirect
{
	t_redirect_type	type;
	int				from_fd;
	int				to_fd;
	char			*file;
	t_bool			quotes;
}	t_redirect;

typedef struct s_process
{
	int			proc_count;
	int			proc_index;
	t_env		*env;
	pid_t		pid;
	char		*cmd;
	char		**args;
	int			std_in;
	int			std_out;
	int			std_err;
	int			pipe_in[2];
	int			pipe_out[2];
	t_redirect	*redir;
	int			res;
	t_bool		val;
}	t_process;

t_process	*setup_processes(char *cmd);
t_process	**get_processes(int size);
t_redirect	*get_redirections(char **args, int index_1, int index_2);
void		clean_processes(void);
t_process	*find_process(t_process *p, pid_t pid);
void		wait_processes(t_process *processes);
void		run_processes(t_process *processes);
char		**ft_split_protec(char const *s, char c);

#endif
