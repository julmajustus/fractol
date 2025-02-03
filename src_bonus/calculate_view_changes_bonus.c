/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_view_changes_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:14:13 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/23 14:25:05 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	calculate_move(t_fractol *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
}

void	calculate_zoom(t_fractol *f, int x, int y, double zoom_factor)
{
	double	x_center;
	double	y_center;
	double	new_width;
	double	new_height;

	f->x_ratio = (double)x / WIDTH;
	f->y_ratio = (double)(HEIGHT - y) / HEIGHT;
	x_center = f->min_r + f->x_ratio * (f->max_r - f->min_r);
	y_center = f->min_i + f->y_ratio * (f->max_i - f->min_i);
	new_width = (f->max_r - f->min_r) / zoom_factor;
	new_height = (f->max_i - f->min_i) / zoom_factor;
	f->min_r = x_center - f->x_ratio * new_width;
	f->max_r = f->min_r + new_width;
	f->min_i = y_center - f->y_ratio * new_height;
	f->max_i = f->min_i + new_height;
}
