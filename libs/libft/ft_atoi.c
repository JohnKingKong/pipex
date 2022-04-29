/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:56:20 by jvigneau          #+#    #+#             */
/*   Updated: 2021/10/11 11:18:22 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui reproduit a lidentique la fct atoi
// change un char ascii en integer

#include "libft.h"

static int	check_spaces(const char *str)
{
	int	p;

	p = 0;
	while (str[p] == 32 || (str[p] >= 9 && str[p] <= 13))
		p++;
	return (p);
}

static int	check_long(const char *str)
{
	int	k;
	int	n;

	k = 0;
	n = -1;
	k = check_spaces(str);
	if ((str[k] == '-') || (str[k] == '+'))
	{
		if (str[k] == '-')
			n = 0;
		k++;
	}
	while (ft_isdigit(str[k]))
		k++;
	if (k >= 20)
		return (n);
	return (2);
}

int	ft_atoi(const char	*str)
{
	int	negative;
	int	final;
	int	i;

	negative = 1;
	final = 0;
	i = 0;
	if (check_long(str) != 2)
		return (check_long(str));
	i = check_spaces(str);
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i++] == '-')
			negative = -1;
	}
	while (ft_isdigit(str[i]))
		final = ((final * 10) + (str[i++] - 48));
	return (final * negative);
}
