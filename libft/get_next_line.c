/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:14:41 by dmorar            #+#    #+#             */
/*   Updated: 2019/02/26 15:55:06 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*change_line_str(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[0][i] != '\n' && str[0][i] != '\0')
		i++;
	*line = ft_strsub(*str, 0, i);
	tmp = *str;
	*str = ft_strsub(*str, i + 1, ft_strlen(*str) - i);
	free(tmp);
	if (*str[0] == '\0')
	{
		free(*str);
		*str = NULL;
	}
	return (*str);
}

int				get_next_line(const int fd, char **line)
{
	int			res;
	char		buf[BUFF_SIZE + 1];
	static char	*str[1];
	char		*tmp;

	if (fd < 0 || line == NULL || read(fd, buf, 0))
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	while ((ft_strchr(str[fd], '\n') == NULL) &&
			(res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[res] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], buf);
		free(tmp);
	}
	if (ft_strlen(str[fd]))
	{
		str[fd] = change_line_str(&str[fd], line);
		return (1);
	}
	return (0);
}
