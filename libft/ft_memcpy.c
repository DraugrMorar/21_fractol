/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:19:19 by dmorar            #+#    #+#             */
/*   Updated: 2018/12/23 20:21:18 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dest;
	unsigned char *sorc;

	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	if (dst == src)
		return (dst);
	while (n--)
	{
		*dest = *sorc;
		dest++;
		sorc++;
	}
	return (dst);
}
