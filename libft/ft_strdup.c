/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:35:48 by dmorar            #+#    #+#             */
/*   Updated: 2018/12/13 16:13:19 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		len;
	char	*copy;

	len = 0;
	while (src[len] != '\0')
		len++;
	copy = (char*)malloc(sizeof(*src) * (len + 1));
	if (copy == NULL)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		copy[len] = src[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}
