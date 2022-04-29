/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:27:43 by jvigneau          #+#    #+#             */
/*   Updated: 2021/10/07 12:52:27 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrire une fct qui itere sur la lst et applique f au contenu de chq elelemnt
// retourne une new_lst resultant des applications de f
// del existe si necessaire

#include "libft.h"

static t_list	*realmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*next_new;

	next_new = ft_lstnew(f(lst->content));
	if (!next_new)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_lst = next_new;
	lst = lst->next;
	while (lst)
	{
		next_new = ft_lstnew(f(lst->content));
		if (!next_new)
		{
			ft_lstclear(&next_new, del);
			ft_lstclear(&lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, next_new);
	}
	return (new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	if (!lst || !f)
		return (NULL);
	return (realmap(lst, f, del));
}
