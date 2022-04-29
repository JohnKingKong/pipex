/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:54:50 by jvigneau          #+#    #+#             */
/*   Updated: 2022/04/20 10:55:47 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libs/libft/libft.h"

typedef struct s_vars
{
	int		ac;
	char	**av;
	char	**env;
	int		fdin;
	int		fdout;
	int		pip[2];
	char	*errorlog;
	char	*path;
	int		err_no;
}			t_vars;

int		check_args(t_vars *pipex);
int		open_in(t_vars *pipex);
void	start_me_up(t_vars *pipex);
void	first_child(t_vars *pipex);
char	*check_cmd(char **cmd, char **path_split, t_vars *pipex);
void	last_child(t_vars *pipex);
void	start_last_child(t_vars *pipex);
char	*check_path(char **cmd, t_vars *pipex);
void	not_found(char *flags, char **cmd, char **path_split, t_vars *pipex);
void	print_err(t_vars *pipex);

#endif