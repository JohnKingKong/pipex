/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:00:02 by jvigneau          #+#    #+#             */
/*   Updated: 2021/10/05 16:29:25 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui retourne un tableau de chaines de char obtenu
// en separant s a laide de c comme delimitateur

#include "libft.h"

static int	check_nb_tabs(const char *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (s == 0)
		return (0);
	while (*s)
	{
		if (*s != c && k == 0)
		{
			i++;
			k = 1;
		}
		else if (*s == c)
			k = 0;
		s++;
	}
	return (i);
}

static char	*malloc_mot(const char *s, int start, int finish)
{
	char	*mot;
	int		i;

	i = 0;
	mot = ft_calloc((finish - start + 1), sizeof(char));
	if (!mot)
		return (NULL);
	while (start < finish)
		mot[i++] = s[start++];
	mot[i] = '\0';
	return (mot);
}

static char	**split(const char *s, char c, char **tabs)
{
	int		i;
	size_t	k;
	size_t	l;

	i = -1;
	k = 0;
	l = 0;
	while (s[k] && s[k] == c)
		k++;
	while (k <= ft_strlen(s))
	{
		if (s[k] != c && i < 0)
			i = k;
		else if ((s[k] == c || k == ft_strlen(s)) && i >= 0)
		{
			tabs[l++] = malloc_mot(s, i, k);
			i = -1;
		}
		k++;
	}
	tabs[l] = 0;
	return (tabs);
}

char	**ft_split(const char *s, char c)
{
	char	**tabs;

	tabs = malloc((check_nb_tabs(s, c) + 1) * sizeof(char *));
	if (s == 0)
	{
		*tabs = 0;
		return (tabs);
	}
	if (!tabs)
		return (NULL);
	return (split(s, c, tabs));
}
