/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:49:19 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/09/19 15:05:30 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	if (fractal->julia)
		free(fractal->julia);
	exit(0);
}

static void	change_color(t_fractal *fractal)
{
	fractal->color_mode = (fractal->color_mode + 1) % 3;
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Up)
		fractal->shift_y -= 0.25 * fractal->zoom;
	else if (keysym == XK_Down)
		fractal->shift_y += 0.25 * fractal->zoom;
	else if (keysym == XK_Left)
		fractal->shift_x -= 0.25 * fractal->zoom;
	else if (keysym == XK_Right)
		fractal->shift_x += 0.25 * fractal->zoom;
	else if (keysym == XK_KP_Add)
		fractal->iterations_defintion += 5;
	else if (keysym == XK_KP_Subtract)
		fractal->iterations_defintion -= 5;
	else if (keysym == XK_c)
		change_color(fractal);
	else
		return (0);
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	int	temp;

	if (button == Button5)
	{
		fractal->zoom *= 0.80;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 1.20;
	}
	temp = x;
	temp = y;
	fractal_render(fractal);
	return (0);
}
