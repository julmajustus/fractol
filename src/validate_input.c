/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:21:24 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/23 14:29:33 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_argument(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
			i++;
		if (str[i] == '.' && (ft_isdigit(str[i - 1]) && ft_isdigit(str[i + 1])))
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_input(int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		return (1);
	else if ((ac == 4) && !ft_strncmp(av[1], "julia", 5))
	{
		if (!check_argument(av[2]))
			return (0);
		if (!check_argument(av[3]))
			return (0);
		return (2);
	}
	return (0);
}
