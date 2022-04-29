/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:57:28 by jvigneau          #+#    #+#             */
/*   Updated: 2021/10/01 10:43:01 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui concatene deux str en param 
// et retourne la nouvelle str concatener

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*final;
	size_t	longueur1;
	size_t	longueur2;

	if (!(s1) || (!(s2)))
		return (NULL);
	longueur1 = ft_strlen(s1);
	longueur2 = ft_strlen(s2);
	final = ft_calloc(longueur1 + longueur2 + 1, sizeof(char));
	if (!(final))
		return (NULL);
	ft_memcpy(final, s1, longueur1);
	ft_memcpy(&final[longueur1], s2, longueur2);
	return (final);
}
