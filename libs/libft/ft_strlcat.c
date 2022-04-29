/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 21:52:52 by jvigneau          #+#    #+#             */
/*   Updated: 2021/10/07 13:23:22 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui reproduit a lidentique la fct strlcpy

#include "libft.h" 

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(dest);
	if (size <= 0)
		return (ft_strlen(src));
	k = j;
	if (size < k)
		return (size + (ft_strlen(src)));
	while (src[i] && size > j + 1)
		dest[j++] = src[i++];
	dest[j] = '\0';
	while (src[i])
		i++;
	return (k + i);
}
