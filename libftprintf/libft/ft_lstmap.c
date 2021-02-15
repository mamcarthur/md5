/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 22:14:39 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:23:01 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newmover;
	t_list	*newlist;

	newmover = f(lst);
	if (!newmover)
		return (NULL);
	newlist = newmover;
	while (lst->next)
	{
		lst = lst->next;
		newmover->next = f(lst);
		if (!newmover->next)
			return (NULL);
		newmover = newmover->next;
	}
	return (newlist);
}
