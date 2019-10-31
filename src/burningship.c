/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:18:46 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/01 14:31:24 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	burningship2(t_fl *f, int x, int y)
{
	double	temp;

	f->i = 0;
	f->c_re = f->t_re;
	f->c_im = f->t_im;
	while ((f->c_re * f->c_re + f->c_im * f->c_im) <= 4 && f->i < f->max_i)
	{
		temp = (f->c_re * f->c_re - f->c_im * f->c_im) + f->t_re;
		f->c_im = fabs(2 * f->c_re * f->c_im) + f->t_im;
		f->c_re = fabs(temp);
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

void	*burningship(void *fl)
{
	int		x;
	int		y;
	t_fl	*fctl;

	fctl = (t_fl *)fl;
	y = 0;
	while (y < WID / R)
	{
		x = -1;
		fctl->t_im = (fctl->y - WID / 2.0) * 4.0 / WID / fctl->fzm + fctl->fmy;
		while (++x < WID)
		{
			fctl->t_re = (x - WID / 2.0) * 4.0 / WID / fctl->fzm + fctl->fmx;
			burningship2(fctl, x, y);
		}
		fctl->y++;
		y++;
	}
	return (NULL);
}
