/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:43:08 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/24 11:13:34 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_init(t_fractol *f)
{
	f->img.mlx_handle = mlx_init(WIDTH, HEIGHT, f->window_title, false);
	if (!f->img.mlx_handle)
		err();
	f->img.mlx_img = mlx_new_image(f->img.mlx_handle, WIDTH, HEIGHT);
	if (!f->img.mlx_img)
	{
		mlx_terminate(f->img.mlx_handle);
		err();
	}
}
