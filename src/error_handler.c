/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:47:15 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/23 14:28:42 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	err(void)
{
	perror("Error\n");
	exit(EXIT_FAILURE);
}

void	malloc_err(void)
{
	perror("Error: Malloc failed to allocate memory.\n");
}
