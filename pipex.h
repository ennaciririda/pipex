/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:56:22 by rennacir          #+#    #+#             */
/*   Updated: 2023/02/21 16:01:46 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<stdio.h>
# include<sys/types.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<string.h>

int		ft_strncmp(const char *first, const char *second, size_t n);
void	pipex(int ac, char **av, char **env);
char	*get_path(char **env, char**av, char *cmd, int j);
char	**child_process(int p1, int p2, char **av);
char	**parent_process( int p1, int p2, char **av);
char	*part_of_path(char **env, char *cmd);
void	pipex_help(char **av, char **env);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_strlen(char *s);
void	free_all(char **paths);
void	error(char *str);
void	check_fork(int id);
void	check_pipe(int pipe);
#endif