/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:33:26 by rennacir          #+#    #+#             */
/*   Updated: 2023/02/21 15:55:03 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	free_all(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		l;
	int		i;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	l = ft_strlen(s1);
	if (!str)
		return (NULL);
	i = -1;
	while (i++ <= l)
		str[i] = s1[i];
	i = 0;
	while (l < len)
		str[l++] = s2[i++];
	str[len] = '\0';
	return (str);
}

int	ft_strncmp(const char *first, const char *second, size_t n)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *)first;
	s = (unsigned char *)second;
	i = 0;
	while ((f[i] || s[i]) && i < n)
	{
		if (f[i] != s[i])
			return (f[i] - s[i]);
			i++;
	}
	return (0);
}

int	ft_strcmp(const char *first, const char *second)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *)first;
	s = (unsigned char *)second;
	i = 0;
	while ((f[i] || s[i]))
	{
		if (f[i] != s[i])
			return (f[i] - s[i]);
			i++;
	}
	return (0);
}

char	*part_of_path(char **env, char *cmd)
{
	char	**paths;
	int		i;
	char	*tmpc;
	char	*var;

	i = -1;
	while (env[++i])
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			paths = ft_split(env[i], ':');
	i = 0;
	while (paths[i])
	{
		var = ft_strjoin(paths[i], "/");
		tmpc = ft_strjoin(var, cmd);
		free(var);
		if (access(tmpc, F_OK) == 0)
			break ;
		free(tmpc);
		tmpc = NULL;
		i++;
	}
	free_all(paths);
	return (tmpc);
}
