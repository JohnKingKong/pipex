/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:28:20 by jvigneau          #+#    #+#             */
/*   Updated: 2021/09/29 13:31:43 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui reproduit a lidentique la fct memmove
// copie len bytes de la str src dans la str dst 

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (((char *)src == NULL) && (const char *)dst == NULL)
		return (NULL);
	if (dst > src)
	{
		while (len-- > 0)
			((char *)dst)[len] = ((char *)src)[len];
	}
	else
	{
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}
