#include "fractol.h"

void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->image.addr + (y * fractal->image.line_length + x
			* (fractal->image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int	close_win(void *param)
{
	(void)param;
	exit(0);
}