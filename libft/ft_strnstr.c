/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:27:02 by dmorar            #+#    #+#             */
/*   Updated: 2018/12/13 16:15:00 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	int i;
	int j;
	int m;

	i = 0;
	while (str1[i] && n > 0)
	{
		m = n;
		j = 0;
		while (str2[j] == str1[i + j] && m--)
		{
			if (str2[j + 1] == '\0')
				return ((char *)str1 + i);
			j++;
		}
		i++;
		n--;
	}
	if (str2[0] == '\0')
		return ((char *)str1);
	return (NULL);
}
