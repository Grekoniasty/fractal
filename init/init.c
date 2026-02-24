/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:43:39 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/09/19 15:14:09 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	free_and_return(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	free(fractal->mlx_connection);
	write(2, "Malloc Error\n", 13);
	return ;
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_defintion = 17;
	fractal->zoom = 1.0;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->color_mode = 0;
}

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
	{
		write(2, "Malloc Error\n", 13);
		return ;
	}
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		free_and_return(fractal);
		return ;
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		free_and_return(fractal);
		return ;
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bitsperpixel, &fractal->img.line_len,
			&fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}

int	create_julia(t_fractal *fractal, char **av)
{
	double	x;
	double	y;

	if (av[2][0] == ' ' || av[2][0] == '\t' || av[3][0] == ' '
		|| av[3][0] == '\t')
	{
		write(2, "Error: No leading whitespace allowed\n", 38);
		return (-1);
	}
	x = ft_atodb(av[2], fractal);
	y = ft_atodb(av[3], fractal);
	fractal->julia = malloc(sizeof(t_julia));
	if (fractal->julia == NULL)
	{
		write(2, "Malloc Error\n", 13);
		return (-1);
	}
	fractal->julia->julia_x = ft_atodb(av[2], fractal);
	fractal->julia->julia_y = ft_atodb(av[3], fractal);
	return (0);
}
