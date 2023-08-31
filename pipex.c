/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:54:02 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/31 21:51:02 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env, char**av, char *cmd, int j)
{
	char	*tmpc;
	int		i;

	i = -1;
	tmpc = NULL;
	if (av[j][0] == '/')
		tmpc = av[j];
	else if (av[j][0] == '.')
		tmpc = av[j] + 2;
	else
	{
		tmpc = part_of_path(env, cmd);
	}
	return (tmpc);
}

char	**child_process(int p0, int p2, char **av)
{
	char	**p;
	int		in_fd;

	in_fd = open(av[1], O_RDONLY);
	if (in_fd < 0)
		error("Error: infile descriptor");
	dup2(p2, 1);
	dup2(in_fd, 0);
	close(p2);
	close(p0);
	p = ft_split(av[2], ' ');
	return (p);
}

char	**parent_process( int p0, int p2, char **av)
{
	char	**p;
	int		out_fd;

	out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out_fd < 0)
		error("Error: outfile descriptor");
	dup2(p0, 0);
	dup2(out_fd, 1);
	close(p0);
	close(p2);
	p = ft_split(av[3], ' ');
	return (p);
}

void	pipex(int ac, char **av, char **env)
{
	if (ac == 5)
	{
		pipex_help(av, env);
	}
	else
		error("Error: number of argc must be 5");
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	if (!env)
		error("Error: there is no envirenment");
	pipex(ac, av, env);
	return (0);
}
