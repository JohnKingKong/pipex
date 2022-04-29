/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:55:31 by jvigneau          #+#    #+#             */
/*   Updated: 2022/04/20 11:24:16 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char *av[], char *env[])
{
	t_vars	pipex;

	pipex.ac = ac;
	pipex.av = av;
	pipex.env = env;
	if (check_args(&pipex) == false)
	{
		print_err(&pipex);
		return (1);
	}
	if (open_in(&pipex) == false)
	{
		print_err(&pipex);
		return (1);
	}
	start_me_up(&pipex);
	return (0);
}

void	start_me_up(t_vars *pipex)
{
	pid_t	pid1;
	int		i;

	i = 5;
	while (ft_strncmp(*pipex->env, "PATH=", 5))
		pipex->env++;
	pipe(pipex->pip);
	pid1 = fork();
	if (pid1 == 0)
		first_child(pipex);
	close(pipex->pip[1]);
	close(pipex->fdin);
	start_last_child(pipex);
	close(pipex->pip[0]);
}

void	first_child(t_vars *pipex)
{
	char	**cmd;
	char	*path;

	close(pipex->pip[0]);
	cmd = ft_split(pipex->av[2], ' ');
	path = check_path(cmd, pipex);
	dup2(pipex->fdin, STDIN_FILENO);
	close(pipex->fdin);
	dup2(pipex->pip[1], STDOUT_FILENO);
	close(pipex->pip[1]);
	execve(path, cmd, NULL);
	ft_free_list((void *)cmd);
}

void	start_last_child(t_vars *pipex)
{
	pid_t	pid2;
	int		temp;

	pid2 = fork();
	if (pid2 == 0)
		last_child(pipex);
	close(pipex->fdout);
	waitpid(pid2, &temp, 0);
}

void	last_child(t_vars *pipex)
{
	char	**cmd;
	char	*path;

	close(pipex->pip[1]);
	cmd = ft_split(pipex->av[3], ' ');
	path = check_path(cmd, pipex);
	dup2(pipex->pip[0], STDIN_FILENO);
	close(pipex->pip[0]);
	dup2(pipex->fdout, STDOUT_FILENO);
	execve(path, cmd, NULL);
	ft_free_list((void *)(cmd));
}
