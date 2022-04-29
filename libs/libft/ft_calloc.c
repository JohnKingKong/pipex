/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:18:53 by jvigneau          #+#    #+#             */
/*   Updated: 2021/10/01 15:14:20 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui reproduit a lidentique la fct calloc
// allocate la memoire necessaires, en attribuant des 0 dans les bytes

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*fin;

	fin = malloc(count * size);
	if (fin)
		ft_bzero(fin, (count * size));
	return (fin);
}
