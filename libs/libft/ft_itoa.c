/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:04:26 by jvigneau          #+#    #+#             */
/*   Updated: 2021/10/07 13:20:58 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui retourne une str de char representant lint en param
// negatif doivent etre pris en compte

#include "libft.h"

static int	nb_digits(int n)
{
	int	res;

	res = 1;
	if (n < 0)
		res += 1;
	while (n >= 10 || n <= -10)
	{
		n = (n / 10);
		res += 1;
	}
	return (res);
}

static	char	*reverse(char *final, int sign)
{
	size_t	n;
	char	temp;

	n = 0;
	while (n < ft_strlen(final) / 2)
	{
		temp = final[n];
		final[n] = final[ft_strlen(final) - n - 1];
		final[ft_strlen(final) - n - 1] = temp;
		n++;
	}
	if (sign == -1)
		final = final - 1;
	return (final);
}

char	*ft_itoa(int n)
{
	char	*final;
	int		i;

	i = 0;
	final = ft_calloc(nb_digits(n) + 1, sizeof(char));
	if (!final)
		return (NULL);
	final[0] = '0';
	if (n < 0)
	{
		final[i++] = '-';
		final[i++] = 48 - n % 10;
		n = n / -10;
	}
	while (n != 0)
	{
		final[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	if (final[0] == '-')
		reverse(final + 1, -1);
	else
		reverse(final, 1);
	return (final);
}
