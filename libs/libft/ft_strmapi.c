/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:42:35 by jvigneau          #+#    #+#             */
/*   Updated: 2021/10/01 10:51:57 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui passe la str s en param et lui applique la fct f 
// en iteration pour retourner une nouvelle str resultant des differentes
// applications de f

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*final;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	final = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!final)
		return (NULL);
	while (s[i])
	{
		final[i] = (f(i, s[i]));
		i++;
	}
	return (final);
}
