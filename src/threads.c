/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:23:04 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/01 16:32:25 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	changefrl(t_lst *f)
{
	if (f->i == 10)
	{
		f->k = 0;
		f->i = 5;
	}
	else if (f->i == 5)
		f->i = 11;
	else if (f->i == 11)
		f->i = 6;
	else if (f->i == 6)
		f->i = 10;
}

int		changex_y(t_fl *f, int n, t_lst *o)
{
	f->arr = (int*)malloc(((WID * WID) / R) * sizeof(int));
	f->i = 0;
	f->fzm = o->zm;
	f->fmx = o->maxx;
	f->fmy = o->maxy;
	if (o->i == 5)
	{
		f->c_re = o->j_re;
		f->c_im = o->j_im;
		if (o->k == 1)
		{
			f->c_re = o->js_re;
			f->c_im = o->js_im;
		}
	}
	f->cc = o->cc;
	f->max_i = o->iter;
	f->y = WID / R * n;
	return (1);
}

int		intjoin(t_fl *tr, int k, t_lst *f)
{
	int		i;

	i = 0;
	while (i < (WID * WID / R))
	{
		f->img_data[k] = tr->arr[i];
		k++;
		i++;
	}
	free(tr->arr);
	return (k);
}

int		makethreads(t_lst *f)
{
	int		rc;
	int		k;
	int		n;

	n = 0;
	k = 0;
	while (n < R)
	{
		changex_y(&f->trd_arg[n], n, f);
		if (f->i == 10)
			rc = pthread_create(&f->trd[n], NULL, mandelbrot, &f->trd_arg[n]);
		if (f->i == 5)
			rc = pthread_create(&f->trd[n], NULL, julia, &f->trd_arg[n]);
		if (f->i == 11)
			rc = pthread_create(&f->trd[n], NULL, burningship, &f->trd_arg[n]);
		if (f->i == 6)
			rc = pthread_create(&f->trd[n], NULL, spider, &f->trd_arg[n]);
		n++;
	}
	while (n--)
		pthread_join(f->trd[n], NULL);
	n = -1;
	while (n++ < (R - 1))
		k = intjoin(&f->trd_arg[n], k, f);
	return (1);
}
