/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setlogic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:13:15 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/09/19 15:03:06 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_iteration(t_complex z, t_complex c, t_fractal *fractal)
{
	int	i;

	i = 0;
	while (i < fractal->iterations_defintion)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imaginary
				* z.imaginary) > fractal->escape_value)
			return (i);
		++i;
	}
	return (-1);
}

void	handle_mandelbrot_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			iterations;
	int			color;

	z.real = 0.0;
	z.imaginary = 0.0;
	c.real = (scale(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.imaginary = (scale(y, -2, 2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	iterations = fractal_iteration(z, c, fractal);
	if (iterations == -1)
		my_pixel_put(x, y, &fractal->img, LIGHT_GREY);
	else
	{
		color = psychedelic_color(iterations, fractal->color_mode);
		my_pixel_put(x, y, &fractal->img, color);
	}
}

void	handle_julia_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			iterations;
	int			color;

	z.real = (scale(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.imaginary = (scale(y, -2, 2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	c.real = fractal->julia->julia_x;
	c.imaginary = fractal->julia->julia_y;
	iterations = fractal_iteration(z, c, fractal);
	if (iterations == -1)
		my_pixel_put(x, y, &fractal->img, LIGHT_GREY);
	else
	{
		color = psychedelic_color(iterations, fractal->color_mode);
		my_pixel_put(x, y, &fractal->img, color);
	}
}

void	set_distribution(int x, int y, t_fractal *fractal)
{
	if (fractal->julia == NULL)
		handle_mandelbrot_pixel(x, y, fractal);
	else
		handle_julia_pixel(x, y, fractal);
}
