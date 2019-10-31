/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:27:48 by dmorar            #+#    #+#             */
/*   Updated: 2018/12/13 16:04:40 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	char		*dest;
	const char	*sorc;

	dest = dst;
	sorc = src;
	while (n--)
	{
		*dest = *sorc;
		dest++;
		if (*sorc == (char)c)
			return (dest++);
		sorc++;
	}
	return (NULL);
}
