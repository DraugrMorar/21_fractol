/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:59:39 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/01 16:32:13 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		key_release(int key, t_lst *f)
{
	if (key == 53)
		exit(0);
	if (key == 8 || key == 49 || (key == 36 && f->i == 5) || key == 76)
	{
		if (key == 8)
		{
			if (f->cc == 3)
				f->cc = 1;
			else
				f->cc += 1;
		}
		if (key == 49)
			if (f->iter < 1000)
				f->iter += 10;
		if (key == 36 && f->i == 5)
			stopjulia(f);
		if (key == 76)
			changefrl(f);
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		ft_bzero(f->img_data, WID * WID * 4);
		makethreads(f);
		mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
	}
	return (0);
}

int		closemap(void *fctl)
{
	(void)fctl;
	exit(0);
	return (0);
}

int		mouse_release(int button, int x, int y, t_lst *fcl)
{
	if (button == 1)
	{
		fcl->maxx += ((x - WID / 2.0) * 4.0 / WID / fcl->zm);
		fcl->maxy += ((y - WID / 2.0) * 4.0 / WID / fcl->zm);
	}
	if (button == 5)
		fcl->zm *= 1.25;
	if (button == 4)
		if (fcl->zm / 1.5 >= 0)
			fcl->zm /= 1.5;
	mlx_clear_window(fcl->mlx_ptr, fcl->win_ptr);
	ft_bzero(fcl->img_data, WID * WID * 4);
	makethreads(fcl);
	mlx_put_image_to_window(fcl->mlx_ptr, fcl->win_ptr, fcl->img_ptr, 0, 0);
	return (0);
}

void	drawanth(char *i)
{
	t_lst *fctl;

	fctl = (t_lst *)malloc(sizeof(t_lst));
	fctl->mlx_ptr = mlx_init();
	fctl->win_ptr = mlx_new_window(fctl->mlx_ptr, WID, WID, "FRACTOL");
	fctl->i = ft_strlen(i);
	fctl->img_ptr = mlx_new_image(fctl->mlx_ptr, WID, WID);
	fctl->img_data = (int*)mlx_get_data_addr(fctl->img_ptr, &fctl->bpp,
	&fctl->line_size, &fctl->endian);
	fctl->maxx = 0;
	fctl->maxy = 0;
	fctl->zm = 1;
	fctl->cc = 1;
	fctl->iter = 100;
	fctl->trd = (pthread_t *)malloc(sizeof(pthread_t) * R);
	fctl->trd_arg = (t_fl*)malloc(R * sizeof(t_fl));
	makethreads(fctl);
	mlx_put_image_to_window(fctl->mlx_ptr, fctl->win_ptr, fctl->img_ptr, 0, 0);
	mlx_hook(fctl->win_ptr, 2, 0, key_release, fctl);
	mlx_hook(fctl->win_ptr, 17, 0, closemap, fctl);
	mlx_mouse_hook(fctl->win_ptr, mouse_release, fctl);
	mlx_hook(fctl->win_ptr, 6, 0, mouse_move, fctl);
	mlx_loop(fctl->mlx_ptr);
}

int		main(int argc, char **argv)
{
	char	*i;

	if (argc != 2)
	{
		ft_putstr("usage : fractol [fractals]\nfractals:\n - -> Mandelbrot\n");
		ft_putstr(" - -> Julia\n - -> BurningShip\n - -> Spider\n");
		exit(0);
	}
	if (ft_strcmp(argv[1], "Mandelbrot") != 0 && ft_strcmp(argv[1], "Julia") !=
	0 && ft_strcmp(argv[1], "BurningShip") != 0 && ft_strcmp(argv[1], "Spider"))
	{
		ft_putstr("usage : fractol [fractals]\nfractals:\n - -> Mandelbrot\n");
		ft_putstr(" - -> Julia\n - -> BurningShip\n - -> Spider\n");
		exit(0);
	}
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		i = "Mandelbrot";
	if (ft_strcmp(argv[1], "Julia") == 0)
		i = "Julia";
	if (ft_strcmp(argv[1], "BurningShip") == 0)
		i = "BurningShip";
	if (ft_strcmp(argv[1], "Spider") == 0)
		i = "Spider";
	drawanth(i);
	return (0);
}
