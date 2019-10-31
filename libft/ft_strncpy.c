/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:37:58 by dmorar            #+#    #+#             */
/*   Updated: 2018/12/06 18:54:38 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (len)
	{
		if (src[i] != '\0')
			dst[i] = src[i];
		else
		{
			while (len)
			{
				dst[i] = '\0';
				i++;
				len--;
			}
			return (dst);
		}
		len--;
		i++;
	}
	return (dst);
}
