/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:39:54 by dmorar            #+#    #+#             */
/*   Updated: 2018/12/11 17:53:57 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (alst == 0 || del == 0)
		return ;
	while ((*alst)->next != 0)
	{
		tmp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		(*alst) = tmp;
	}
	del((*alst)->next, (*alst)->content_size);
	free(*alst);
	*alst = 0;
}
