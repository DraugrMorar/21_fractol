/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:47:09 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/01 14:59:42 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <pthread.h>
# include "./libft/libft.h"
# define R 12
# define WID 1200

typedef struct	s_fl
{
	double		t_im;
	double		t_re;
	int			y;
	int			*arr;
	double		c_im;
	double		c_re;
	int			max_i;
	int			i;
	int			color;
	double		fzm;
	double		fmx;
	double		fmy;
	int			cc;
}				t_fl;
typedef struct	s_lst
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			bpp;
	int			line_size;
	int			endian;
	t_fl		*trd_arg;
	pthread_t	*trd;
	double		zm;
	double		maxx;
	double		maxy;
	int			i;
	double		j_im;
	double		j_re;
	double		js_im;
	double		js_re;
	int			cc;
	int			iter;
	int			k;
}				t_lst;
int				main(int argc, char **argv);
void			drawanth(char *i);
int				mouse_release(int button, int x, int y, t_lst *fcl);
int				key_release(int key, t_lst *fdf);
int				closemap(void *fctl);
int				makethreads(t_lst *f);
int				color2(t_fl *f);
int				color(t_fl *f);
int				color3(t_fl *f);
void			*julia(void *f);
void			julia2(t_fl *f, int x, int y);
void			*burningship(void *fl);
void			burningship2(t_fl *f, int x, int y);
void			*mandelbrot(void *fl);
void			mandelbrot2(t_fl *f, int x, int y);
int				changex_y(t_fl *f, int n, t_lst *o);
int				intjoin(t_fl *tr, int k, t_lst *f);
int				mouse_move(int x, int y, t_lst *fcl);
void			stopjulia(t_lst *f);
void			spider2(t_fl *f, int x, int y);
void			*spider(void *fl);
void			changefrl(t_lst *f);
#endif
