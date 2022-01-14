/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:24:47 by tom               #+#    #+#             */
/*   Updated: 2022/01/14 18:52:32 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* if 'esc' is pressed */
int	exit_win(t_data	*data)
{
	free(data);
	mlx_destroy_image(data->mlx, data->image.img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	key_press(int key, t_data *data)
{
	(void)data;
	if (key == 53)
		exit_win(data);
	return (0);
}

static double	interpolation_of(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

int	zoom(int button, int x, int y, t_data *data)
{
	t_complex	mouse;
	double		zoom;

	if (button == 4 || button == 5)
	{
		mouse = set_complex(
				(double)x / (WIN_WIDTH / (data->max.real - data->min.real))
				+ data->min.real,
				(double)y / (WIN_HEIGHT / (data->max.imag - data->min.imag))
				* -1 + data->max.imag);
		if (button == 4)
			zoom = 0.90;
		else
			zoom = 1.10;
		data->min.real = interpolation_of(mouse.real, data->min.real, zoom);
		data->min.imag = interpolation_of(mouse.imag, data->min.imag, zoom);
		data->max.real = interpolation_of(mouse.real, data->max.real, zoom);
		data->max.imag = interpolation_of(mouse.imag, data->max.imag, zoom);
		draw_fractal(data);
	}
	return (0);
}

int	julia_motion(int x, int y, t_data *data)
{
	data->k = set_complex(4 * ((double)x / WIN_WIDTH - 0.5),
			4 * ((double)(WIN_HEIGHT - y) / WIN_HEIGHT - 0.5));
	draw_fractal(data);
	return (0);
}
