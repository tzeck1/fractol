/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:00:37 by tzeck             #+#    #+#             */
/*   Updated: 2022/01/09 17:28:32 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	check_input(char *input)
{
	if (ft_strcmp(input, "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(input, "Julia") == 0)
		return (1);
	else
		return (0);
}

static void	print_help(void)
{
	ft_putstr_fd("Wrong Input!\n", 1);
	ft_putstr_fd("You can choose between: <Mandelbrot>, <Julia> and <TBD>\n", 1);
	exit(0);
}

static void	set_fractal(t_data *data, char *input)
{
	data->iter = 21;
	data->min = set_complex(-2.0, -2.0);
	data->max = set_complex(2.0, 2.0);
	if (WIN_HEIGHT > WIN_WIDTH)
	{
		data->max.real = 2.0;
		data->max.imag = data->min.imag
			+ (data->max.real - data->min.real) * WIN_HEIGHT / WIN_WIDTH;
	}
	else
	{
		data->max.imag = 2.0;
		data->max.real = data->min.real
			+ (data->max.imag - data->min.imag) * WIN_WIDTH / WIN_HEIGHT;
	}
	data->color_shift = 1;
	data->bright_shift = 0;
	data->k = set_complex(-0.4, 0.6);
	set_formular(data, input);
}

static void	set_data(t_data *data, char *input)
{
	//initiate mlx stuff (ref 42docs)
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, input);
	data->image.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.img, &(data->image.bits_per_pixel),
			&(data->image.line_lenght), &(data->image.endian));
	// give fractal default values
	set_fractal(data, input);
	// set_iter(data, input);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*input;

	input = argv[1];
	data = malloc(sizeof(t_data));
	if (argc != 2 || check_input(input) == 0)
		print_help();
	else
	{
		set_data(data, input);
		draw_fractal(data);
		mlx_loop(data->mlx);
	}
	return (0);
}
