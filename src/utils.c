/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:05:58 by tom               #+#    #+#             */
/*   Updated: 2022/01/09 17:18:29 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image.addr + (y * data->image.line_lenght + x * (data->image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_complex	set_complex(double re, double im)
{
	t_complex	complex;

	complex.real = re;
	complex.imag = im;
	return (complex);
}

int	nikitos_blue(unsigned int iteration, t_data *data)
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

int	get_color(unsigned int iteration, t_data *data)
{
	if (data->color_shift != 0)
		return (nikitos_blue(iteration, data));
	return (0);
}

void	set_formular(t_data *data, char *input)
{
	if (ft_strcmp(input, "Mandelbrot") == 0)
		data->formula = &set_mandel;
	else if (ft_strcmp(input, "Julia") == 0)
		data->formula = &set_julia;
}
