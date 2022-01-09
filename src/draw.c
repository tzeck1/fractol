/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:07:56 by tom               #+#    #+#             */
/*   Updated: 2022/01/09 16:47:11 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fractal(t_data *data)
{
	int	x;
	int	y;
	int	color;

	data->factor = set_complex((data->max.real - data->min.real) / WIN_WIDTH, (data->max.imag - data->min.imag) / WIN_HEIGHT);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		data->c.imag = data->max.imag - y * data->factor.imag;
		x = 0;
		while (x < WIN_WIDTH)
		{
			data->c.real = data->min.real + x * data->factor.real;
			color = get_color(data->formula(data), data);
			// printf("color: %x\n", color);
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
}