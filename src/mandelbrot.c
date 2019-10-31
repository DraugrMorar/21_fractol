/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:44:34 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/01 12:38:08 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot2(t_fl *f, int x, int y)
{
	double	xtemp;

	f->i = 0;
	f->c_re = 0;
	f->c_im = 0;
	while ((f->c_re * f->c_re + f->c_im * f->c_im) <= 4 && f->i < f->max_i)
	{
		xtemp = (f->c_re * f->c_re - f->c_im * f->c_im) + f->t_re;
		f->c_im = 2 * f->c_re * f->c_im + f->t_im;
		f->c_re = xtemp;
		f->i++;
	}
	if (f->i >= f->max_i)
		f->arr[x + y * WID] = 0;
	else
	{
		if (f->cc == 1)
			f->color = color(f);
		if (f->cc == 2)
			f->color = color2(f);
		if (f->cc == 3)
			f->color = color3(f);
		f->arr[x + y * WID] = f->color;
	}
}

void	*mandelbrot(void *fl)
{
	t_fl	*f;
	int		x;
	int		y;

	f = (t_fl *)fl;
	y = 0;
	while (y < WID / R)
	{
		x = -1;
		f->t_im = (f->y - WID / 2.0) * 4.0 / WID / f->fzm + f->fmy;
		while (++x < WID)
		{
			f->t_re = (x - WID / 2.0) * 4.0 / WID / f->fzm + f->fmx;
			mandelbrot2(f, x, y);
		}
		f->y++;
		y++;
	}
	return (NULL);
}
