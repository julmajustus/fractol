/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_multibrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:02:20 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/23 14:25:20 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	calculate_simple_multibrot(t_fractol *f)
{
	double	tmp;

	if (f->d == 2)
	{
		tmp = 2 * f->zr * f->zi + f->pi;
		f->zr = f->zr2 - f->zi2 + f->pr;
		f->zi = tmp;
	}
	else if (f->d == 3)
	{
		tmp = f->zr * (f->zr2 - 3 * f->zi2) + f->pr;
		f->zi = f->zi * (3 * f->zr2 - f->zi2) + f->pi;
		f->zr = tmp;
	}
	else if (f->d == 4)
	{
		tmp = f->zr2 * f->zr2 - 6 * f->zr2 * f->zi2 + f->zi2 * f->zi2 + f->pr;
		f->zi = 4 * f->zr * f->zi * (f->zr2 - f->zi2) + f->pi;
		f->zr = tmp;
	}
}

static void	calculate_complex_multibrot(t_fractol *f)
{
	double complex	z;
	double complex	c;

	z = f->zr + f->zi * I;
	c = f->pr + f->pi * I;
	z = cpow(z, f->d) + c;
	f->zr = creal(z);
	f->zi = cimag(z);
}

int	draw_multibrot(t_fractol *f)
{
	int		n;

	n = 0;
	f->zi = 0;
	f->zr = 0;
	while (n < MAX_ITERATIONS)
	{
		f->zr2 = f->zr * f->zr;
		f->zi2 = f->zi * f->zi;
		if (f->zr2 + f->zi2 > 4.0)
			break ;
		if (f->d == 2 || f->d == 3 || f->d == 4)
			calculate_simple_multibrot(f);
		else
			calculate_complex_multibrot(f);
		n++;
	}
	return (n);
}
