/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:51:15 by jvigneau          #+#    #+#             */
/*   Updated: 2021/09/28 10:46:31 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ecrire une fct qui reproduit la fct strdup a lidentique
//allocates assez de memoire pour une copie de la srt1, 
//la copiue et retourne un pointeur to it

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*final;

	final = malloc((ft_strlen(s1) + 1));
	if (!final)
		return (NULL);
	ft_bzero(final, (ft_strlen(s1) + 1));
	return (ft_memcpy(final, s1, (ft_strlen(s1))));
}
