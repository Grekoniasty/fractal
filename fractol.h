/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:11:42 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/09/19 15:26:56 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000
# define LIGHT_GREY 0x424242

typedef struct s_img
{
	void			*img_ptr;
	char			*pixels_ptr;
	int				bitsperpixel;
	int				endian;
	int				line_len;
}					t_img;

typedef struct s_complex
{
	double			real;
	double			imaginary;
}					t_complex;

typedef struct s_julia
{
	double			julia_y;
	double			julia_x;
}					t_julia;

typedef struct s_fractal
{
	char			*name;
	void			*mlx_connection;
	void			*mlx_window;
	t_img			img;
	double			escape_value;
	int				iterations_defintion;
	double			shift_x;
	double			shift_y;
	double			zoom;
	unsigned int	color_mode;
	t_julia			*julia;
}					t_fractal;

int					ft_strncmp(char *s1, char *s2, size_t n);
double				scale(double unscaled_num, double new_min, double new_max,
						double old_max);
void				fractal_render(t_fractal *fractal);
void				fractal_init(t_fractal *fractal);
t_complex			sum_complex(t_complex z1, t_complex z2);
t_complex			square_complex(t_complex z);
int					key_handler(int keysym, t_fractal *fractal);
int					close_handler(t_fractal *fractal);
int					mouse_handler(int button, int x, int y, t_fractal *fractal);
double				ft_atodb(char *str, t_fractal *fractal);
int					psychedelic_color(int iterations, int mode);
void				set_distribution(int x, int y, t_fractal *fractal);
int					fractal_iteration(t_complex z, t_complex c,
						t_fractal *fractal);
void				handle_mandelbrot_pixel(int x, int y, t_fractal *fractal);
void				handle_julia_pixel(int x, int y, t_fractal *fractal);
void				my_pixel_put(int x, int y, t_img *img, int color);
void				fractal_render(t_fractal *fractal);
double				ft_atodb(char *str, t_fractal *fractal);
int					create_julia(t_fractal *fractal, char **av);

#endif
