/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:23:12 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/25 08:44:59 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	how_to(void)
{
	ft_putstr_fd("\nCorrect input for fractol is:\n", 2);
	ft_putstr_fd("  ./fractol mandelbrot\n", 2);
	ft_putstr_fd("  ./fractol julia x.x x.x\n", 2);
	ft_putstr_fd("    (x.x values should be between -2.0 and 2.0)\n", 2);
	ft_putstr_fd("  ./fractol multibrot\n", 2);
	ft_putstr_fd("\nControls:\n", 2);
	ft_putstr_fd("  General:\n", 2);
	ft_putstr_fd("    ESC      - Exit program\n", 2);
	ft_putstr_fd("    WASD     - Move the view inside window\n", 2);
	ft_putstr_fd("    Mouse    - Scroll to zoom in/out\n", 2);
	ft_putstr_fd("    R        - Reset colorset to black/white\n", 2);
	ft_putstr_fd("    Space    - Randomize colorset\n", 2);
	ft_putstr_fd("\n  Julia set controls:\n", 2);
	ft_putstr_fd("    UP/DOWN  - Increase/decrease constants\n", 2);
	ft_putstr_fd("    LEFT/RIGHT - Finer increase/decrease constants\n", 2);
	ft_putstr_fd("\n  Multibrot controls:\n", 2);
	ft_putstr_fd("    E/Q      - Increase/decrease degree\n", 2);
}

void	exit_mlx(t_fractol *f)
{
	if (f->colors.palette)
		free(f->colors.palette);
	if (f->framebuffer)
		free(f->framebuffer);
	mlx_terminate(f->img.mlx_handle);
	exit(EXIT_SUCCESS);
}

void	exit_failure(t_fractol *f)
{
	if (f->colors.palette)
		free(f->colors.palette);
	if (f->framebuffer)
		free(f->framebuffer);
	mlx_terminate(f->img.mlx_handle);
	how_to();
	exit(EXIT_FAILURE);
}
