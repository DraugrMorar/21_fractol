/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:08:42 by dmorar            #+#    #+#             */
/*   Updated: 2018/12/13 16:04:54 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *st;

	st = (unsigned char *)s;
	while (n--)
	{
		if (*st == (unsigned char)c)
			return (st);
		st++;
	}
	return (NULL);
}
