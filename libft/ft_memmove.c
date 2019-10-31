/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:42:21 by dmorar            #+#    #+#             */
/*   Updated: 2018/12/20 20:15:18 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*sorc;

	dest = (char *)dst;
	sorc = (const char *)src;
	if (dst == src)
		return (NULL);
	if (dst < src)
	{
		while (len--)
		{
			*dest = *sorc;
			dest++;
			sorc++;
		}
	}
	else
	{
		while (len--)
			dest[len] = sorc[len];
	}
	return (dst);
}
