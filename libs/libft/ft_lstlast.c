/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:26:56 by jvigneau          #+#    #+#             */
/*   Updated: 2021/10/06 18:21:11 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ecrire une fct qui renvoie le dernier element de la liste

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			if (lst->next == NULL)
				return (lst);
			lst = lst->next;
		}
	}
	return (lst);
}
