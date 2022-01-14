/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:00:37 by tzeck             #+#    #+#             */
/*   Updated: 2022/01/14 18:52:18 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* checks input for 'Mandelbrot' or 'Julia' */
static int	check_input(char *input)
{
	if (ft_strcmp(input, "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(input, "Julia") == 0)
		return (1);
	else
		return (0);
}

/* prints available input arguments */
static void	print_help(void)
{
	ft_putstr_fd("Wrong Input!\n", 1);
	ft_putstr_fd("You can choose between: <Mandelbrot> and <Julia>\n", 1);
	exit(0);
}

/* sets basic values for fractal based on how big the window is */
static void	set_fractal(t_data *data, char *input)
{
	data->iter = 50;
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
	data->color_shift = 6;
	data->k = set_complex(-0.4, 0.6);
	set_formular(data, input);
}

/* sets basic values for struct t_data, calls control hooks*/
static void	set_data(t_data *data, char *input)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, input);
	data->image.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&(data->image.bits_per_pixel),
			&(data->image.line_lenght), &(data->image.endian));
	set_fractal(data, input);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 17, 0, exit_win, data);
	mlx_mouse_hook(data->win, zoom, data);
	if (!ft_strcmp(input, "Julia"))
		mlx_hook(data->win, 6, 1L << 6, julia_motion, data);
}

/* looks for input errors, initiates fractal or prints input-help*/
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
	exit_win(data);
	return (0);
}
