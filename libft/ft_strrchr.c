/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:57:11 by dmorar            #+#    #+#             */
/*   Updated: 2018/12/13 16:15:13 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;

	s2 = 0;
	while (*s)
	{
		if (*s == (char)c)
			s2 = (char *)s;
		s++;
	}
	if (*s == (char)c)
		s2 = (char *)s;
	if (s2 == 0)
		return (NULL);
	else
		return (s2);
}
