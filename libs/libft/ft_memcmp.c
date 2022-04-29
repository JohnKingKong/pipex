/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:23:09 by jvigneau          #+#    #+#             */
/*   Updated: 2021/10/01 16:22:47 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui reproduit t char lidentique la fct memcmp
// retourne 0 si les deux string s1 et s2 sont identiques, sinon
// retourne la difference entre les deux premieres bytes differentes

#include "libft.h" 

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sa;
	const unsigned char	*sb;
	int					i;

	sa = (const unsigned char *)s1;
	sb = (const unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (sa[i] != sb[i])
			return (sa[i] - sb[i]);
		i++;
		n--;
	}
	return (0);
}
