/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 08:29:23 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/25 08:25:41 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef WIDTH
#  define WIDTH 800
# endif
# ifndef HEIGHT
#  define HEIGHT 800
# endif
# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 100
# endif

typedef struct s_img
{
	mlx_t			*mlx_handle;
	mlx_image_t		*mlx_img;
}	t_img;

typedef struct s_colors
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	base_r;
	uint32_t	base_g;
	uint32_t	base_b;
	uint32_t	*palette;
}	t_colors;

typedef struct s_fractol
{
	char			*window_title;
	t_img			img;
	t_colors		colors;
	uint32_t		*framebuffer;
	int				fbuf_index;
	uint32_t		pixel_color;
	int				input;
	char			**av;
	int				x;
	int				y;
	int				n;
	double			zi;
	double			zr;
	double			zi2;
	double			zr2;
	double			ci;
	double			cr;
	double			ci2;
	double			cr2;
	double			pi;
	double			pr;
	double			pi2;
	double			pr2;
	double			max_i;
	double			max_r;
	double			min_i;
	double			min_r;
	double			x_ratio;
	double			y_ratio;
	double			zoom_factor;
}	t_fractol;

void	how_to(void);
void	window_init(t_fractol *f);
int		validate_input(int ac, char **av);
void	fractol_init(t_fractol *f, int input, char **av);
void	fractol_render(t_fractol *f);
void	scroll_listener(double xdelta, double ydelta, void *param);
void	keyboard_listener(mlx_key_data_t key, void *param);
void	calculate_zoom(t_fractol *f, int x, int y, double zoom_factor);
void	calculate_move(t_fractol *f, double distance, char direction);
int		get_color(t_fractol *f);
void	set_colors(t_colors *c);
void	randomize_colors(t_fractol *f);
void	reset_palette(t_colors *c);
void	err(void);
void	malloc_err(void);
void	exit_mlx(t_fractol *f);
void	exit_failure(t_fractol *f);
#endif
