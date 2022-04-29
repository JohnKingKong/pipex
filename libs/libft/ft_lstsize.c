/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:26:08 by jvigneau          #+#    #+#             */
/*   Updated: 2021/10/06 14:25:41 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui compte le nb delement de la liste

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (lst == NULL)
		return (0);
	lst = lst->next;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
