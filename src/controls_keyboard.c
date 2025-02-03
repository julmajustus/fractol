/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:17:18 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/25 08:35:05 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	keys_movement(mlx_key_data_t key, t_fractol *f)
{
	if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
		calculate_move(f, 0.08, 'U');
	else if (key.key == MLX_KEY_S && key.action == MLX_PRESS)
		calculate_move(f, 0.08, 'D');
	else if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
		calculate_move(f, 0.08, 'L');
	else if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
		calculate_move(f, 0.08, 'R');
	else
		return ;
	fractol_render(f);
}

static void	keys_utils(mlx_key_data_t key, t_fractol *f)
{
	if (key.key == MLX_KEY_ESCAPE)
	{
		exit_mlx(f);
		return ;
	}
	else if (key.key == MLX_KEY_SPACE && key.action == MLX_PRESS)
		randomize_colors(f);
	else if (key.key == MLX_KEY_R && key.action == MLX_PRESS)
		reset_palette(&f->colors);
	else
		return ;
	fractol_render(f);
}

static void	keys_julia_controls(mlx_key_data_t key, t_fractol *f)
{
	if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
	{
		f->cr += 0.02;
		f->ci += 0.02;
	}
	else if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
	{
		f->cr -= 0.02;
		f->ci -= 0.02;
	}
	else if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		f->cr += 0.001;
	else if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		f->cr -= 0.001;
	else
		return ;
	fractol_render(f);
}

void	keyboard_listener(mlx_key_data_t key, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	keys_movement(key, f);
	keys_utils(key, f);
	if (f->input == 2)
		keys_julia_controls(key, f);
}
