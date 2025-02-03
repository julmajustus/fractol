/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:17:18 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/25 08:36:06 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll_listener(double xdelta, double ydelta, void *param)
{
	t_fractol	*f;
	int32_t		mouse_x;
	int32_t		mouse_y;

	(void)xdelta;
	f = (t_fractol *)param;
	mlx_get_mouse_pos(f->img.mlx_handle, &mouse_x, &mouse_y);
	if (ydelta < 0)
		calculate_zoom(f, mouse_x, mouse_y, f->zoom_factor);
	else if (ydelta > 0)
		calculate_zoom(f, mouse_x, mouse_y, 1 / f->zoom_factor);
	fractol_render(f);
}
