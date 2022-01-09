/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:50:05 by tom               #+#    #+#             */
/*   Updated: 2022/01/09 16:57:03 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int set_mandel(t_data *data)
{
	unsigned int	iteration;
	t_complex		z;
	t_complex		tmp_z;

	iteration = 0;
	z = set_complex(data->c.real, data->c.imag);
	tmp_z = set_complex(z.real * z.real, z.imag * z.imag);
	while (tmp_z.real + tmp_z.imag < 4
		&& iteration < data->iter)
	{
		z.imag = z.real * z.imag;
		z.imag += z.imag;
		z.imag += data->c.imag;
		z.real = tmp_z.real - tmp_z.imag + data->c.real;
		tmp_z = set_complex(z.real * z.real, z.imag * z.imag);
		iteration++;
	}
	return (iteration);
}

unsigned int	set_julia(t_data *data)
{
	unsigned int	iteration;
	t_complex		z;
	t_complex		tmp_z;

	iteration = 0;
	z = set_complex(data->c.real, data->c.imag);
	tmp_z = set_complex(z.real * z.real, z.imag * z.imag);
	while (tmp_z.real + tmp_z.imag <= 4
		&& iteration < data->iter)
	{
		z.imag = z.real * z.imag;
		z.imag += z.imag;
		z.imag += data->k.imag;
		z.real = tmp_z.real - tmp_z.imag + data->k.real;
		tmp_z = set_complex(z.real * z.real, z.imag * z.imag);
		iteration++;
	}
	return (iteration);
}