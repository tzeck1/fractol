/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:05:58 by tom               #+#    #+#             */
/*   Updated: 2022/01/12 18:46:45 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* puts colored pixel on the image */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image.addr + (y * data->image.line_lenght
			+ x * (data->image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* sets values for t_complex */
t_complex	set_complex(double re, double im)
{
	t_complex	complex;

	complex.real = re;
	complex.imag = im;
	return (complex);
}

/* sets function for fractal */
void	set_formular(t_data *data, char *input)
{
	if (ft_strcmp(input, "Mandelbrot") == 0)
		data->formula = &set_mandel;
	else if (ft_strcmp(input, "Julia") == 0)
		data->formula = &set_julia;
}
