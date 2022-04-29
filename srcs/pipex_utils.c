/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:37:57 by jvigneau          #+#    #+#             */
/*   Updated: 2022/04/20 10:54:50 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*check_path(char **cmd, t_vars *pipex)
{
	char	**path_split;
	char	*temp;

	path_split = ft_split((*pipex->env + 5), ':');
	temp = check_cmd(cmd, path_split, pipex);
	free(path_split);
	return (temp);
}

char	*check_cmd(char **cmd, char **path_split, t_vars *pipex)
{
	int		i;
	int		yes_or_no;
	char	*path;
	char	*flags;

	i = 0;
	yes_or_no = -1;
	flags = ft_strjoin("/", cmd[0]);
	while (yes_or_no == -1 && path_split[i])
	{
		path = ft_strjoin(path_split[i], flags);
		yes_or_no = access(path, F_OK);
		if (yes_or_no == -1)
		{
			free(path);
			free(path_split[i]);
		}
		i++;
	}
	if (yes_or_no == -1)
	{
		free(path_split[i]);
		not_found(flags, cmd, path_split, pipex);
	}
	return (path);
}

void	not_found(char *flags, char **cmd, char **path_split, t_vars *pipex)
{
	int	i;

	i = 1;
	ft_putstr_fd("zsh: command not found: ", 1);
	while (flags[i])
		ft_putchar_fd(flags[i++], 1);
	ft_putchar_fd('\n', 1);
	free(flags);
	free(path_split);
	ft_free_list((void *)cmd);
	close(pipex->fdout);
	close(pipex->fdin);
	close(pipex->pip[0]);
	close(pipex->pip[1]);
	exit (1);
}

int	check_args(t_vars *pipex)
{
	if (pipex->ac != 5)
	{
		if (pipex->ac > 5)
			pipex->errorlog = "Error, too many arguments!";
		else
			pipex->errorlog = "Error, not enough arguments";
		pipex->err_no = 1;
		return (false);
	}
	return (true);
}

int	open_in(t_vars *pipex)
{
	pipex->fdin = open(pipex->av[1], O_RDONLY, 0777);
	if (pipex->fdin == -1)
	{
		pipex->errorlog = "Could not open the in file descriptor!\n";
		pipex->err_no = 1;
		return (false);
	}
	pipex->fdout = open(pipex->av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (pipex->fdout == -1)
	{
		pipex->errorlog = "Could not open the out file descriptor!\n";
		pipex->err_no = 1;
		return (false);
	}
	return (true);
}
