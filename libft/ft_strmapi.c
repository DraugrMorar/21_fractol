/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:11:32 by dmorar            #+#    #+#             */
/*   Updated: 2018/12/13 16:14:14 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	size_t			len;
	size_t			i;
	unsigned int	b;

	i = 0;
	b = 0;
	if (s == 0)
		return (NULL);
	len = ft_strlen(s);
	new = ft_strnew(len);
	if (new == 0)
		return (NULL);
	while (len > i)
	{
		new[i] = f(b, s[i]);
		i++;
		b++;
	}
	new[i] = '\0';
	return (new);
}
