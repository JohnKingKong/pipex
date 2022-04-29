/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:26:09 by jvigneau          #+#    #+#             */
/*   Updated: 2021/09/25 12:51:20 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui reproduit a lidentique la fct bzeo
// remplace une str s par des \0 jusqua size__t n

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = -1;
	if (n == 0)
		return ;
	while (n > 0)
	{
		((char *)s)[++i] = 0;
		n--;
	}
	return ;
}
