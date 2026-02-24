/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:41:47 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/09/19 14:45:22 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bitsperpixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			set_distribution(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}

int	psychedelic_color(int iter, int mode)
{
	if (mode == 0)
		return (((iter * 5) % 256) << 16 | ((iter * 7) % 256) << 8 | ((iter
					* 11) % 256));
	else if (mode == 1)
		return (((iter * 2) % 256) << 16 | ((iter * 13) % 256) << 8 | ((255
					- iter * 3) % 256));
	else if (mode == 2)
		return (((iter * 5) % 256) << 16 | ((255 - iter * 4)
				% 256) << 8 | ((iter * 3) % 256));
	else
		return (0x000000);
}
