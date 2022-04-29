/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:22:02 by jvigneau          #+#    #+#             */
/*   Updated: 2021/10/05 16:03:00 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui reproduit a lidentique la fct strchr
// return la str s a partir du char c recherche

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{	
	int	i;

	i = ft_strlen(s);
	if (c == '\0')
	{
		while (--i >= 0)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == ((char)c))
			return ((char *)s);
		s++;
	}
	return (NULL);
}
