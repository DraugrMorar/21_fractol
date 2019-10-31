/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:39:15 by dmorar            #+#    #+#             */
/*   Updated: 2018/12/13 16:28:37 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	len;
	size_t	i;

	if (s == 0)
		return (0);
	len = ft_strlen(s);
	i = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == 0)
		return (0);
	while (len > i)
	{
		new[i] = f(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
