/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:59:43 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/25 08:28:02 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	set_gradient(t_colors *c, int step, int total_steps)
{
	double	ratio;

	ratio = (double)step / (double)total_steps;
	c->r = (c->base_r * (1 - ratio) * ratio * ratio * ratio * 255);
	c->g = (c->base_g * (1 - ratio) * (1 - ratio) * ratio * ratio * 255);
	c->b = (c->base_b * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255);
}

static void	set_background(t_colors *c, int *i)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = 0;
	g = 0;
	b = 0;
	while (*i < MAX_ITERATIONS / 10)
	{
		r += 4;
		g += 4;
		b += 4;
		c->palette[*i] = (r << 24) | (g << 16) | (b << 8) | 255;
		*i += 1;
	}
}

void	set_colors(t_colors *c)
{
	int	i;

	i = 0;
	set_background(c, &i);
	while (i < MAX_ITERATIONS)
	{
		if (i <= MAX_ITERATIONS / 3)
		{
			set_gradient(c, i, MAX_ITERATIONS / 3);
		}
		else if (i <= MAX_ITERATIONS / 2)
		{
			set_gradient(c, i - (MAX_ITERATIONS / 3), MAX_ITERATIONS / 6);
		}
		else
		{
			set_gradient(c, i - (MAX_ITERATIONS / 2), MAX_ITERATIONS / 2);
		}
		c->palette[i++] = (c->r << 24) | (c->g << 16) | (c->b << 8) | 255;
	}
}

int	get_color(t_fractol *f)
{
	if (f->n == MAX_ITERATIONS)
		return (0 << 24 | 0 << 16 | 0 << 8 | 255);
	return (f->colors.palette[f->n]);
}
