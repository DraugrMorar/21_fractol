/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:42:53 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/01 14:58:05 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia2(t_fl *f, int x, int y)
{
	double	xtemp;

	f->t_im = (f->y - WID / 2.0) * 4.0 / WID / f->fzm + f->fmy;
	f->t_re = (x - WID / 2.0) * 4.0 / WID / f->fzm + f->fmx;
	f->i = 0;
	while ((f->t_re * f->t_re + f->t_im * f->t_im) < 4 && f->i < f->max_i)
	{
		xtemp = f->t_re * f->t_re - f->t_im * f->t_im;
		f->t_im = 2 * f->t_re * f->t_im + f->c_im;
		f->t_re = xtemp + f->c_re;
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

void	*julia(void *fl)
{
	t_fl	*f;
	int		x;
	int		y;

	f = (t_fl *)fl;
	y = 0;
	while (y < WID / R)
	{
		x = 0;
		while (x < WID)
		{
			julia2(f, x, y);
			x++;
		}
		y++;
		f->y++;
	}
	return (NULL);
}

int		mouse_move(int x, int y, t_lst *fcl)
{
	fcl->j_re = (x - WID / 2.0) * 4.0 / WID;
	fcl->j_im = (y - WID / 2.0) * 4.0 / WID;
	mlx_clear_window(fcl->mlx_ptr, fcl->win_ptr);
	ft_bzero(fcl->img_data, WID * WID * 4);
	makethreads(fcl);
	mlx_put_image_to_window(fcl->mlx_ptr, fcl->win_ptr, fcl->img_ptr, 0, 0);
	return (0);
}

void	stopjulia(t_lst *f)
{
	if (f->k == 1)
		f->k = 0;
	else
	{
		f->js_re = f->j_re;
		f->js_im = f->j_im;
		f->k = 1;
	}
}
