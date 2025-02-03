/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize_colors_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:38:51 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/25 08:28:28 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	shift_colors(t_colors *c, int seed)
{
	int	prime1;
	int	prime2;
	int	prime3;

	prime1 = 199;
	prime2 = 263;
	prime3 = 307;
	c->base_r = ft_abs((c->g + seed * prime1) % 9);
	c->base_g = ft_abs((c->b + seed * prime2) % 15);
	c->base_b = ft_abs((c->r + seed * prime3) % 8);
}

void	reset_palette(t_colors *c)
{
	int	i;
	int	brt;

	i = 0;
	brt = 0;
	while (i <= MAX_ITERATIONS)
	{
		brt = (i * 255) / MAX_ITERATIONS;
		c->palette[i++] = (brt << 24) | (brt << 16) | (brt << 8) | 255;
	}
}

void	randomize_colors(t_fractol *f)
{
	double	time;

	time = mlx_get_time();
	shift_colors(&f->colors, (int)time);
	set_colors(&f->colors);
}
