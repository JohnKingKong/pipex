/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:49:23 by jvigneau          #+#    #+#             */
/*   Updated: 2022/04/20 11:23:30 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	print_err(t_vars *pipex)
{
	printf("\n\nERROR!!\n\n%s\n\n", pipex->errorlog);
	write(STDERR_FILENO, &pipex->err_no, 1);
}
