/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:08:41 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/23 22:12:04 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	draw_julia(t_fractol *f)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		f->pi2 = f->pi * f->pi;
		f->pr2 = f->pr * f->pr;
		if ((f->pi2 + f->pr2) > 4.0)
			break ;
		tmp = 2 * f->pr * f->pi + f->ci;
		f->pr = f->pr2 - f->pi2 + f->cr;
		f->pi = tmp;
		n++;
	}
	return (n);
}

static int	draw_mandelbrot(t_fractol *f)
{
	int		n;
	double	tmp;

	n = 0;
	f->zi = 0;
	f->zr = 0;
	while (n < MAX_ITERATIONS)
	{
		f->zr2 = f->zr * f->zr;
		f->zi2 = f->zi * f->zi;
		if ((f->zr2 + f->zi2) > 4.0)
			break ;
		tmp = 2 * f->zr * f->zi + f->pi;
		f->zr = f->zr2 - f->zi2 + f->pr;
		f->zi = tmp;
		n++;
	}
	return (n);
}

static void	draw_fractol(t_fractol *f)
{
	if (f->input == 1)
		f->n = draw_mandelbrot(f);
	else if (f->input == 2)
		f->n = draw_julia(f);
	else if (f->input == 3)
		f->n = draw_multibrot(f);
}

void	fractol_render(t_fractol *f)
{
	mlx_image_to_window(f->img.mlx_handle, f->img.mlx_img, 0, 0);
	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			f->fbuf_index = f->y * WIDTH + f->x;
			f->pr = f->min_r + ((double)f->x * (f->max_r - f->min_r)) / WIDTH;
			f->pi = f->max_i + (double)f->y * (f->min_i - f->max_i) / HEIGHT;
			draw_fractol(f);
			f->pixel_color = get_color(f);
			if (f->framebuffer[f->fbuf_index] != f->pixel_color)
			{
				f->framebuffer[f->fbuf_index] = f->pixel_color;
				mlx_put_pixel(f->img.mlx_img, f->x, f->y, f->pixel_color);
			}
			f->y++;
		}
		f->x++;
	}
}
