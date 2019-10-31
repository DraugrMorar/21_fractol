/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spider.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:54:47 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/01 14:32:31 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	spider2(t_fl *f, int x, int y)
{
	double	temp;

	f->i = 0;
	while ((f->c_re * f->c_re + f->c_im * f->c_im) < 16 && f->i < f->max_i)
	{
		temp = f->t_re * f->t_re - f->t_im * f->t_im + f->c_re;
		f->t_im = 2 * f->t_re * f->t_im + f->c_im;
		f->t_re = temp;
		f->c_re = f->c_re / 2 + f->t_re;
		f->c_im = f->c_im / 2 + f->t_im;
		f->i++;
	}
	if (f->i == f->max_i)
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

void	*spider(void *fl)
{
	int		x;
	int		y;
	t_fl	*f;

	f = (t_fl *)fl;
	y = 0;
	while (y < WID / R)
	{
		x = -1;
		while (++x < WID)
		{
			f->t_re = (x - WID / 2.0) * 4.0 / WID / f->fzm + f->fmx;
			f->t_im = (f->y - WID / 2.0) * 4.0 / WID / f->fzm + f->fmy;
			f->c_re = f->t_re;
			f->c_im = f->t_im;
			spider2(f, x, y);
		}
		f->y++;
		y++;
	}
	return (NULL);
}
