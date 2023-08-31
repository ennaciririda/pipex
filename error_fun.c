/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:06:54 by rennacir          #+#    #+#             */
/*   Updated: 2023/02/20 19:30:13 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str)
{
	perror(str);
	exit(1);
}

void	check_fork(int id)
{
	if (id < 0)
	{
		perror("Error : fork");
		exit(1);
	}
}

void	check_pipe(int pipe)
{
	if (pipe < 0)
	{
		perror("Error : pipe");
		exit(1);
	}
}

void	pipex_help(char **av, char **env)
{
	int		fds[2];
	int		pid;
	char	*tmpc;
	char	**p;

	check_pipe(pipe(fds));
	pid = fork();
	check_fork(pid);
	if (pid == 0)
	{
		p = child_process(fds[0], fds[1], av);
		tmpc = get_path(env, av, p[0], 2);
		execve(tmpc, p, env);
	}
	else
	{
		pid = fork();
		check_fork(pid);
		if (pid == 0)
		{
			p = parent_process(fds[0], fds[1], av);
			tmpc = get_path(env, av, p[0], 3);
			execve(tmpc, p, env);
		}
	}
}
