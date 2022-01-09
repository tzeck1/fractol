/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:47:19 by tzeck             #+#    #+#             */
/*   Updated: 2022/01/09 17:04:22 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <errno.h>
#include <stdio.h>

# define WIN_WIDTH		700
# define WIN_HEIGHT		700

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_image;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_image			image;
	unsigned int	iter;
	t_complex		min;
	t_complex		max;
	t_complex	factor;
	t_complex		k;
	t_complex		c;
	// char			julia_block;
	unsigned int	((*formula)(struct	s_data *data));
	unsigned char	color_shift;
	double			bright_shift;
}	t_data;

t_complex	set_complex(double re, double im);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_fractal(t_data *data);
void	set_formular(t_data *data, char *input);
int	get_color(unsigned int iteration, t_data *data);
unsigned int set_mandel(t_data *data);
unsigned int	set_julia(t_data *data);

#endif
