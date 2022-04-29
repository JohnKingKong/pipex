/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:57:57 by jvigneau          #+#    #+#             */
/*   Updated: 2021/09/29 10:45:01 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui reproduit a lidentique la fct memchr
// cherche la 1ere occurence du unsigned char c dans la string s
// retourne ladresse du byte pointer par le pointeur final de la string s

#include "libft.h" 

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	const char		*src;
	size_t			i;

	a = (unsigned char)c;
	i = 0;
	src = ((const char *)s);
	while (n-- > 0)
	{
		if ((unsigned char)src[i] == a)
			return ((void *)&src[i]);
		i++;
	}
	return (NULL);
}
