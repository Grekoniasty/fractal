/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:42:38 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/09/19 14:09:12 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char	*skip_whitespace_and_parse_sign(char *str, int *sign)
{
	*sign = 1;
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (str);
}

static void	validate_input(char *str, t_fractal *fractal)
{
	if (*str == ' ' || *str == '\t')
	{
		if (fractal && fractal->julia)
			free(fractal->julia);
		exit(1);
	}
	if (!(*str >= '0' && *str <= '9') && *str != '-' && *str != '+')
	{
		if (fractal && fractal->julia)
			free(fractal->julia);
		exit(1);
	}
}

static char	*parse_integer_part(char *str, double *result)
{
	*result = 0.0;
	while (*str >= '0' && *str <= '9')
	{
		*result = *result * 10 + (*str - '0');
		str++;
	}
	return (str);
}

static double	parse_fraction_and_finalize(char *str, double result, int sign,
		t_fractal *fractal)
{
	double	frac;
	double	divisor;

	frac = 0.0;
	divisor = 1.0;
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			frac = frac * 10 + (*str - '0');
			divisor *= 10;
			str++;
		}
	}
	if (*str != '\0' && *str != '\n')
	{
		if (fractal && fractal->julia)
			free(fractal->julia);
		exit(1);
	}
	return (sign * (result + frac / divisor));
}

double	ft_atodb(char *str, t_fractal *fractal)
{
	double	result;
	int		sign;

	validate_input(str, fractal);
	str = skip_whitespace_and_parse_sign(str, &sign);
	validate_input(str, fractal);
	str = parse_integer_part(str, &result);
	return (parse_fraction_and_finalize(str, result, sign, fractal));
}
