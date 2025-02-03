/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:43:08 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/23 21:51:21 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_border_values(t_fractol *f, int input)
{
	if (input == 2)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = 2.0;
	}
	else
	{
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}

static void	init_colors(t_fractol *f)
{
	f->colors.r = 0;
	f->colors.g = 0;
	f->colors.b = 0;
	f->colors.base_r = 9;
	f->colors.base_g = 15;
	f->colors.base_b = 8;
	f->colors.palette = malloc(sizeof(uint32_t) * (MAX_ITERATIONS + 1));
	if (!f->colors.palette)
	{
		malloc_err();
		mlx_terminate(f->img.mlx_handle);
		exit(EXIT_FAILURE);
	}
	set_colors(&f->colors);
}

static void	set_julia_constants(t_fractol *f, char **av)
{
	if (!av[2] || !av[3] || !*av[2] || !*av[3])
	{
		ft_putstr_fd("Empty argument.\n", 2);
		exit_failure(f);
	}
	else
	{
		f->cr = ft_atof(av[2]);
		if (f->cr > 2.0 || f->cr < -2.0)
		{
			ft_putstr_fd(av[2], 2);
			ft_putstr_fd(" is invalid argument.\n", 2);
			exit_failure(f);
		}
		f->ci = ft_atof(av[3]);
		if (f->ci > 2.0 || f->ci < -2.0)
		{
			ft_putstr_fd(av[3], 2);
			ft_putstr_fd(" is invalid argument.\n", 2);
			exit_failure(f);
		}
	}
}

static void	init_framebuffer(t_fractol *f)
{
	int	i;

	i = 0;
	f->framebuffer = malloc(WIDTH * HEIGHT * sizeof(uint32_t));
	if (!f->framebuffer)
	{
		malloc_err();
		exit(EXIT_FAILURE);
	}
	while (i < WIDTH * HEIGHT)
	{
		f->framebuffer[i] = 0x000001FF;
		i++;
	}
}

void	fractol_init(t_fractol *f, int input, char **av)
{
	init_colors(f);
	init_framebuffer(f);
	f->input = input;
	f->av = av;
	f->zoom_factor = 0.89;
	set_border_values(f, input);
	if (input == 2)
		set_julia_constants(f, av);
}
