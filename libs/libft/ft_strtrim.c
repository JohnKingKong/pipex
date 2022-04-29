/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:25:51 by jvigneau          #+#    #+#             */
/*   Updated: 2021/10/06 18:05:22 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui retourne une copie de s1, sans les chars specifies
// dans set au debut et a la fin

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		j;

	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	j = ft_strlen(s1);
	while (j && ft_strchr(set, s1[j]))
		j--;
	return (ft_substr((char *)s1, 0, j + 1));
}
