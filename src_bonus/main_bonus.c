/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 08:30:10 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/25 08:46:38 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int ac, char **av)
{
	t_fractol	f;
	int			input;

	input = validate_input(ac, av);
	if (input >= 1)
	{
		f.window_title = av[1];
		window_init(&f);
		fractol_init(&f, input, av);
		fractol_render(&f);
		mlx_scroll_hook(f.img.mlx_handle, &scroll_listener, &f);
		mlx_key_hook(f.img.mlx_handle, &keyboard_listener, &f);
		mlx_loop(f.img.mlx_handle);
		exit_mlx(&f);
	}
	else
	{
		ft_putstr_fd("Invalid arguments\n", 2);
		how_to();
		return (1);
	}
	return (0);
}
