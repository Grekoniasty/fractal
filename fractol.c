/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:43:49 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/09/19 15:14:27 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	generate_all(t_fractal *fractal)
{
	fractal_init(fractal);
	fractal_render(fractal);
	mlx_loop(fractal->mlx_connection);
	if (fractal->julia != NULL)
		free(fractal->julia);
	return ;
}

int	main(int ac, char **av)
{
	t_fractal	fractal;
	int			x;

	x = 0;
	if ((ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10)) || (ac == 4
			&& !ft_strncmp(av[1], "Julia", 5)))
	{
		fractal.name = av[1];
		fractal.julia = NULL;
		if (!ft_strncmp(av[1], "Julia", 5))
		{
			x = create_julia(&fractal, av);
			if (x < 0)
			{
				free(fractal.julia);
				return (-1);
			}
		}
		generate_all(&fractal);
	}
	else
		return (write(2, "INVALID INPUT!\n", 15), -1);
	return (0);
}
