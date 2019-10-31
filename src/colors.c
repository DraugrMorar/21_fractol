/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:29:41 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/01 13:30:03 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		color(t_fl *f)
{
	int red;
	int blue;
	int green;

	red = 5 * f->i;
	blue = 2 * f->i;
	green = 10 * f->i;
	return ((red << 16) | (green << 8) | blue);
}

int		color2(t_fl *f)
{
	int red;
	int blue;
	int green;

	if (f->i < f->max_i / 3)
	{
		red = 2 * f->i;
		blue = 7 * f->i;
		green = 3 * f->i;
		return ((red << 16) | (green << 8) | blue);
	}
	if (f->i > f->max_i / 3 && f->i < 2 * f->max_i / 3)
	{
		red = 7 * f->i;
		blue = 3 * f->i;
		green = 2 * f->i;
		return ((red << 16) | (green << 8) | blue);
	}
	red = 3 * f->i;
	blue = 2 * f->i;
	green = 7 * f->i;
	return ((red << 16) | (green << 8) | blue);
}

int		color3(t_fl *f)
{
	int red;
	int blue;
	int green;

	red = 255 - 5 * f->i;
	blue = 255 - 2 * f->i;
	green = 255 - 10 * f->i;
	return ((red << 16) | (green << 8) | blue);
}
