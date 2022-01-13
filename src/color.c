/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:24:51 by tom               #+#    #+#             */
/*   Updated: 2022/01/13 19:15:18 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* calculates color for pixel based on how many iterations it took to escape*/
int	get_color(unsigned int iteration, t_data *data)
{
	double	t;
	int		color;

	if (iteration == data->iter)
		return (0);
	t = (double)iteration / data->iter;
	color = (unsigned char)(t / ((data->color_shift + 0) % 3 + 1) * 255);
	color <<= 8;
	color += (unsigned char)(t / ((data->color_shift + 1) % 3 + 1) * 255);
	color <<= 8;
	color += (unsigned char)(t / ((data->color_shift + 2) % 3 + 1) * 255);
	return (color);
}
