/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:01:01 by dmorar            #+#    #+#             */
/*   Updated: 2018/12/13 15:56:59 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *new_ptr;
	t_list *res;

	new_list = NULL;
	new_ptr = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		res = f(lst);
		if (new_ptr && (new_ptr->next =
		ft_lstnew(res->content, res->content_size)))
			new_ptr = new_ptr->next;
		else if (!new_ptr && (new_ptr =
		ft_lstnew(res->content, res->content_size)))
			new_list = new_ptr;
		else
			ft_lstdel(&new_list, &ft_bzero);
		lst = lst->next;
	}
	return (new_list);
}
